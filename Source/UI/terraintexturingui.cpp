#include "terraintexturingui.h"
#include "alphabrushselectorui.h"
#include "../terrainmaterialbuilder.h"
#include "../Components/editingcamera.h"

#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Resource/XMLFile.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <Urho3D/UI/UIElement.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/UI/BorderImage.h>
#include <Urho3D/UI/Text.h>
#include <Urho3D/UI/Slider.h>
#include <Urho3D/UI/CheckBox.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/UI/LineEdit.h>
#include <Urho3D/Core/StringUtils.h>
#include <Urho3D/IO/Log.h>

#include "../format.h"

void CopyImage(Image &in, Image &out)
{
	out.SetSize(in.GetWidth(), in.GetHeight(), in.GetComponents());
	out.SetData(in.GetData());
}

TerrainTexturingUI::TerrainTexturingUI(Context *context) : Object(context),
	terrainContext_(nullptr),
	materialBuilder_(nullptr),
	alphaSelector_(nullptr),
	camera_(nullptr),
	brushSettings_{0.5f, 0.5f, 1.0f, 0.0f},
	brushPreview_(context),
	layerScales_{1,1,1,1,1,1,1,1},
	selectedLayer_(0),
	diffuseSelected_(false), normalSelected_(false),
	selectedDiffImageThumb_(context), selectedNormalImageThumb_(context)
{
}

void TerrainTexturingUI::Construct(TerrainContext *tc, TerrainMaterialBuilder *tmb, AlphaBrushSelectorUI *abs, EditingCamera *camera)
{
	terrainContext_=tc;
	materialBuilder_=tmb;
	alphaSelector_=abs;
	camera_=camera;

	auto cache=GetSubsystem<ResourceCache>();
	auto graphics=GetSubsystem<Graphics>();
	auto ui=GetSubsystem<UI>();

	XMLFile *style=cache->GetResource<XMLFile>("UI/DefaultStyle.xml");

	element_=ui->LoadLayout(cache->GetResource<XMLFile>("UI/TerrainEditBlendBrush.xml"), style);
	if(element_)
	{
		ui->GetRoot()->GetChild("Base",true)->AddChild(element_);
		brushPreview_.SetSize(64,64,3);
		brushPreviewTex_=SharedPtr<Texture2D>(new Texture2D(context_));
		element_->GetChildDynamicCast<BorderImage>("BrushPreview", true)->SetTexture(brushPreviewTex_);
		GenerateBrushPreview();
		SetBrushUIFields();

		SubscribeToEvent(element_->GetChild("PowerSlider", true), StringHash("SliderChanged"), URHO3D_HANDLER(TerrainTexturingUI, HandleSliderChanged));
		SubscribeToEvent(element_->GetChild("RadiusSlider", true), StringHash("SliderChanged"), URHO3D_HANDLER(TerrainTexturingUI, HandleSliderChanged));
		SubscribeToEvent(element_->GetChild("MaxSlider", true), StringHash("SliderChanged"), URHO3D_HANDLER(TerrainTexturingUI, HandleSliderChanged));
		SubscribeToEvent(element_->GetChild("HardnessSlider", true), StringHash("SliderChanged"), URHO3D_HANDLER(TerrainTexturingUI, HandleSliderChanged));



		SubscribeToEvent(element_->GetChild("TriplanarCheck", true), StringHash("Toggled"), URHO3D_HANDLER(TerrainTexturingUI, HandleMaterialSettingToggled));
		SubscribeToEvent(element_->GetChild("SmoothCheck", true), StringHash("Toggled"), URHO3D_HANDLER(TerrainTexturingUI, HandleMaterialSettingToggled));
		SubscribeToEvent(element_->GetChild("NormalMapCheck", true), StringHash("Toggled"), URHO3D_HANDLER(TerrainTexturingUI, HandleMaterialSettingToggled));
		SubscribeToEvent(element_->GetChild("ReduceCheck", true), StringHash("Toggled"), URHO3D_HANDLER(TerrainTexturingUI, HandleMaterialSettingToggled));
		SubscribeToEvent(element_->GetChild("ClearLayer",true), StringHash("Pressed"), URHO3D_HANDLER(TerrainTexturingUI, HandleClearLayer));
		SubscribeToEvent(element_->GetChild("ClearAllLayers",true), StringHash("Pressed"), URHO3D_HANDLER(TerrainTexturingUI, HandleClearAllLayers));

		for(unsigned int c=0; c<8; ++c)
		{
			SubscribeToEvent(element_->GetChild(String("EditTerrain")+String(c), true), StringHash("Pressed"), URHO3D_HANDLER(TerrainTexturingUI, HandleEditLayerButton));
			SubscribeToEvent(element_->GetChild(String("Terrain")+String(c), true), StringHash("Pressed"), URHO3D_HANDLER(TerrainTexturingUI, HandleTextureButton));
		}
	}

	editLayerElement_=ui->LoadLayout(cache->GetResource<XMLFile>("UI/TerrainLayerSettings.xml"), style);
	editLayerElement_->SetVisible(false);
	ui->GetRoot()->GetChild("Base",true)->AddChild(editLayerElement_);

	SubscribeToEvent(editLayerElement_->GetChild("Apply", true), StringHash("Pressed"), URHO3D_HANDLER(TerrainTexturingUI, HandleEditLayerApply));
	SubscribeToEvent(editLayerElement_->GetChild("Cancel", true), StringHash("Pressed"), URHO3D_HANDLER(TerrainTexturingUI, HandleEditLayerCancel));
	SubscribeToEvent(editLayerElement_->GetChild("DiffusePick", true), StringHash("Pressed"), URHO3D_HANDLER(TerrainTexturingUI, HandlePickDiffuse));
	SubscribeToEvent(editLayerElement_->GetChild("NormalPick", true), StringHash("Pressed"), URHO3D_HANDLER(TerrainTexturingUI, HandlePickNormal));

	SubscribeToEvent(StringHash("Update"), URHO3D_HANDLER(TerrainTexturingUI, HandleUpdate));

	InitializeTextures();
	SetLayerScales();
	SelectLayer(0);
}

void TerrainTexturingUI::InitializeTextures()
{
	if(!materialBuilder_ || !element_) return;
	auto cache=GetSubsystem<ResourceCache>();

	std::vector<String> diffuse{
		"Textures/pebbles.png",
		"Textures/sand.png",
		"Textures/tiletexturegrass.png",
		"Textures/tg1.png",
		"Textures/pebbles3.png",
		"Textures/cliff.png",
		"Textures/rockface1.png",
		"Textures/cliff2.png",
	};

	std::vector<String> normal{
		"Textures/pebbles_normal.png",
		"Textures/sand_normal.png",
		"Textures/tiletexturegrass_normal.png",
		"Textures/tg1_normal.png",
		"Textures/pebbles3_normal.png",
		"Textures/cliff_normal.png",
		"Textures/rockface1_normal.png",
		"Textures/cliff2_normal.png",
	};

	diffuseLayerNames_=diffuse;
	normalLayerNames_=normal;

	for(unsigned int c=0; c<8; ++c)
	{
		Image *i=cache->GetResource<Image>(diffuse[c]);
		SharedPtr<Image> thumb=SharedPtr<Image>(new Image(context_));

		GenerateThumbnailImage(*thumb, *i);
		diffThumbnailImages_.push_back(thumb);

		materialBuilder_->SetDiffuseTexture(c, *i);
		SharedPtr<Texture2D> tex=SharedPtr<Texture2D>(new Texture2D(context_));
		tex->SetData(thumb, false);
		layerThumbnailTex_.push_back(tex);

		element_->GetChildDynamicCast<Button>(String("Terrain")+String(c), true)->SetTexture(tex);

		i=cache->GetResource<Image>(normal[c]);
		thumb=SharedPtr<Image>(new Image(context_));
		GenerateThumbnailImage(*thumb, *i);
		normalThumbnailImages_.push_back(thumb);
		materialBuilder_->SetNormalTexture(c, *i);
	}

	// Create textures for the preview thumbnails in the editing box
	editLayerDiffTex_=SharedPtr<Texture2D>(new Texture2D(context_));
	editLayerNormalTex_=SharedPtr<Texture2D>(new Texture2D(context_));

	editLayerElement_->GetChildDynamicCast<BorderImage>("DiffuseThumb", true)->SetTexture(editLayerDiffTex_);
	editLayerElement_->GetChildDynamicCast<BorderImage>("NormalThumb", true)->SetTexture(editLayerNormalTex_);
}

void TerrainTexturingUI::SetVisible(bool v)
{
	if(element_) element_->SetVisible(v);
	if(alphaSelector_) alphaSelector_->SetVisible(v);

	if(!v) materialBuilder_->SetEditingCursor(-100000, -100000, brushSettings_.radius_*100.0f, brushSettings_.hardness_, camera_->GetYaw());
}

void TerrainTexturingUI::HandleSliderChanged(StringHash eventType, VariantMap &eventData)
{
	GetBrushUIFields();

	Slider *slider;

	slider=element_->GetChildDynamicCast<Slider>("PowerSlider", true);
	slider->SetValue(brushSettings_.power_ * slider->GetRange());
	element_->GetChildDynamicCast<Text>("PowerText", true)->SetText("%.2f"_fmt(brushSettings_.power_));

	slider=element_->GetChildDynamicCast<Slider>("RadiusSlider", true);
	slider->SetValue(brushSettings_.radius_ * slider->GetRange());
	element_->GetChildDynamicCast<Text>("RadiusText", true)->SetText("%.2f"_fmt(brushSettings_.radius_));

	slider=element_->GetChildDynamicCast<Slider>("MaxSlider", true);
	slider->SetValue(brushSettings_.max_ * slider->GetRange());
	element_->GetChildDynamicCast<Text>("MaxText", true)->SetText("%.2f"_fmt(brushSettings_.max_));

	slider=element_->GetChildDynamicCast<Slider>("HardnessSlider", true);
	slider->SetValue(brushSettings_.hardness_ * slider->GetRange());
	element_->GetChildDynamicCast<Text>("HardnessText", true)->SetText("%.2f"_fmt(brushSettings_.hardness_));

	GenerateBrushPreview();
}

void TerrainTexturingUI::GenerateBrushPreview()
{
	unsigned int w=brushPreview_.GetWidth();
	unsigned int h=brushPreview_.GetHeight();

	float rad=(float)w*0.5f;
	float hardness=std::min(0.99f, brushSettings_.hardness_);

	for(unsigned int y=0; y<h; ++y)
	{
		for(unsigned int x=0; x<w; ++x)
		{
			float dx=(float)x - (float)w*0.5f;
			float dy=(float)y - (float)h*0.5f;
			float d=std::sqrt(dx*dx+dy*dy);
			float i=(d-rad)/(hardness*rad-rad);
			brushPreview_.SetPixel(x,y,Color(i*0.5f, i*0.5f, i*0.5f));

		}
	}

	brushPreviewTex_->SetData(&brushPreview_, false);
}

void TerrainTexturingUI::SetBrushUIFields()
{
	if(!element_) return;

	Slider *slider;

	slider=element_->GetChildDynamicCast<Slider>("PowerSlider", true);
	slider->SetValue(brushSettings_.power_ * slider->GetRange());
	element_->GetChildDynamicCast<Text>("PowerText", true)->SetText("%.2f"_fmt(brushSettings_.power_));

	slider=element_->GetChildDynamicCast<Slider>("RadiusSlider", true);
	slider->SetValue(brushSettings_.radius_ * slider->GetRange());
	element_->GetChildDynamicCast<Text>("RadiusText", true)->SetText("%.2f"_fmt(brushSettings_.radius_));

	slider=element_->GetChildDynamicCast<Slider>("MaxSlider", true);
	slider->SetValue(brushSettings_.max_ * slider->GetRange());
	element_->GetChildDynamicCast<Text>("MaxText", true)->SetText("%.2f"_fmt(brushSettings_.max_));

	slider=element_->GetChildDynamicCast<Slider>("HardnessSlider", true);
	slider->SetValue(brushSettings_.hardness_ * slider->GetRange());
	element_->GetChildDynamicCast<Text>("HardnessText", true)->SetText("%.2f"_fmt(brushSettings_.hardness_));


	CheckBox *button;
	button=element_->GetChildDynamicCast<CheckBox>("Mask0Check", true);
	button->SetChecked(maskSettings_.usemask0_);
	button=element_->GetChildDynamicCast<CheckBox>("Mask1Check", true);
	button->SetChecked(maskSettings_.usemask1_);
	button=element_->GetChildDynamicCast<CheckBox>("Mask2Check", true);
	button->SetChecked(maskSettings_.usemask2_);
}

void TerrainTexturingUI::GetBrushUIFields()
{
	if(!element_) return;

	Slider *slider;

	slider=element_->GetChildDynamicCast<Slider>("PowerSlider", true);
	brushSettings_.power_ = slider->GetValue() / slider->GetRange();
	slider=element_->GetChildDynamicCast<Slider>("RadiusSlider", true);
	brushSettings_.radius_ = slider->GetValue() / slider->GetRange();
	slider=element_->GetChildDynamicCast<Slider>("MaxSlider", true);
	brushSettings_.max_ = slider->GetValue() / slider->GetRange();
	slider=element_->GetChildDynamicCast<Slider>("HardnessSlider", true);
	brushSettings_.hardness_ = std::min(0.99f, slider->GetValue() / slider->GetRange());

	CheckBox *button;
	button=element_->GetChildDynamicCast<CheckBox>("Mask0Check", true);
	maskSettings_.usemask0_=button->IsChecked();
	button=element_->GetChildDynamicCast<CheckBox>("Mask1Check", true);
	maskSettings_.usemask1_=button->IsChecked();
	button=element_->GetChildDynamicCast<CheckBox>("Mask2Check", true);
	maskSettings_.usemask2_=button->IsChecked();
}

void TerrainTexturingUI::SelectLayer(unsigned int which)
{
	selectedLayer_=std::min(7U, which);
	element_->GetChildDynamicCast<BorderImage>("SelectedLayer", true)->SetTexture(layerThumbnailTex_[which]);
}

void TerrainTexturingUI::HandleUpdate(StringHash eventType, VariantMap &eventData)
{
	float dt=eventData["TimeStep"].GetFloat();
	if(!element_ || !element_->IsVisible()) return;

	auto input=GetSubsystem<Input>();
	auto ui=GetSubsystem<UI>();

	IntVector2 mousepos=input->GetMousePosition();

	Vector3 ground;
	bool s=camera_->GetMouseGround(ground);
	if(s)
	{
		materialBuilder_->SetEditingCursor(ground.x_, ground.z_, brushSettings_.radius_*100.0f, brushSettings_.hardness_, camera_->GetYaw());

		if(input->GetMouseButtonDown(MOUSEB_LEFT) && !ui->GetElementAt(mousepos.x_, mousepos.y_))
		{
			GetBrushUIFields();
			terrainContext_->ApplyBlendAlpha(ground.x_, ground.z_, selectedLayer_, dt, brushSettings_, maskSettings_, *(alphaSelector_->GetAlphaBrush()), -camera_->GetYaw()*3.14159265f/180.0f);
		}
	}
}

void TerrainTexturingUI::HandleEditLayerApply(StringHash eventType, VariantMap &eventData)
{
	if(diffuseSelected_)
	{
		diffuseLayerNames_[editingLayer_]=selectedDiffImageName_;
		materialBuilder_->SetDiffuseTexture(editingLayer_, *selectedDiffImage_);
		CopyImage(selectedDiffImageThumb_, *diffThumbnailImages_[editingLayer_]);
		layerThumbnailTex_[editingLayer_]->SetData(diffThumbnailImages_[editingLayer_], false);

		selectedDiffImageName_="";
		selectedDiffImage_=nullptr;
		diffuseSelected_=false;
	}

	if(normalSelected_)
	{
		normalLayerNames_[editingLayer_]=selectedNormalImageName_;
		materialBuilder_->SetNormalTexture(editingLayer_, *selectedNormalImage_);
		CopyImage(selectedNormalImageThumb_, *normalThumbnailImages_[editingLayer_]);

		selectedNormalImageName_="";
		selectedNormalImage_=nullptr;
		normalSelected_=false;
	}

	layerScales_[editingLayer_]=ToFloat(editLayerElement_->GetChildDynamicCast<LineEdit>("LayerScale", true)->GetText());
	SetLayerScales();
	editLayerElement_->SetVisible(false);
}

void TerrainTexturingUI::HandleEditLayerCancel(StringHash eventType, VariantMap &eventData)
{
	if(editLayerElement_) editLayerElement_->SetVisible(false);
	diffuseSelected_=false;
	normalSelected_=false;
}

void TerrainTexturingUI::HandleMaterialSettingToggled(StringHash eventType, VariantMap &eventData)
{
	if(!element_ || !materialBuilder_) return;

	bool triplanar=element_->GetChildDynamicCast<CheckBox>("TriplanarCheck", true)->IsChecked();
	bool smooth=element_->GetChildDynamicCast<CheckBox>("SmoothCheck", true)->IsChecked();
	bool bump=element_->GetChildDynamicCast<CheckBox>("NormalMapCheck", true)->IsChecked();
	bool reduce=element_->GetChildDynamicCast<CheckBox>("ReduceCheck", true)->IsChecked();

	materialBuilder_->SetUseTriplanar(triplanar);
	materialBuilder_->SetUseSmooth(smooth);
	materialBuilder_->SetUseBump(bump);
	materialBuilder_->SetUseReduceTiling(reduce);
}

void TerrainTexturingUI::HandleClearLayer(StringHash eventType, VariantMap &eventData)
{
}

void TerrainTexturingUI::HandleClearAllLayers(StringHash eventType, VariantMap &eventData)
{
}

void TerrainTexturingUI::HandleEditLayerButton(StringHash eventType, VariantMap &eventData)
{
	if(!element_ || !editLayerElement_) return;
	UIElement *elem=static_cast<UIElement *>(eventData["Element"].GetPtr());

	String name=elem->GetName();

	if(name=="EditTerrain0") editingLayer_=0;
	else if(name=="EditTerrain1") editingLayer_=1;
	else if(name=="EditTerrain2") editingLayer_=2;
	else if(name=="EditTerrain3") editingLayer_=3;
	else if(name=="EditTerrain4") editingLayer_=4;
	else if(name=="EditTerrain5") editingLayer_=5;
	else if(name=="EditTerrain6") editingLayer_=6;
	else if(name=="EditTerrain7") editingLayer_=7;
	else return;

	editLayerElement_->SetVisible(true);
	editLayerDiffTex_->SetData(diffThumbnailImages_[editingLayer_], false);
	editLayerNormalTex_->SetData(normalThumbnailImages_[editingLayer_], false);
	editLayerElement_->GetChildDynamicCast<LineEdit>("DiffuseName", true)->SetText(diffuseLayerNames_[editingLayer_]);
	editLayerElement_->GetChildDynamicCast<LineEdit>("NormalName", true)->SetText(normalLayerNames_[editingLayer_]);
	editLayerElement_->GetChildDynamicCast<LineEdit>("LayerScale", true)->SetText(String(layerScales_[editingLayer_]));;
}

void TerrainTexturingUI::HandleTextureButton(StringHash eventType, VariantMap &eventData)
{
	UIElement *elem=static_cast<UIElement *>(eventData["Element"].GetPtr());
	String name=elem->GetName();
	if(name=="Terrain0") SelectLayer(0);
	else if(name=="Terrain1") SelectLayer(1);
	else if(name=="Terrain2") SelectLayer(2);
	else if(name=="Terrain3") SelectLayer(3);
	else if(name=="Terrain4") SelectLayer(4);
	else if(name=="Terrain5") SelectLayer(5);
	else if(name=="Terrain6") SelectLayer(6);
	else if(name=="Terrain7") SelectLayer(7);
}

void TerrainTexturingUI::HandlePickDiffuse(StringHash eventType, VariantMap &eventData)
{
	fileSelector_=CreateFileSelector("Select Diffuse Texture", "Ok", "Cancel", "", {"*.png", "*.dds"}, 0);
	SubscribeToEvent(fileSelector_, StringHash("FileSelected"), URHO3D_HANDLER(TerrainTexturingUI, HandleSelectDiffuseFile));
}

void TerrainTexturingUI::HandlePickNormal(StringHash eventType, VariantMap &eventData)
{
	fileSelector_=CreateFileSelector("Select Normal Texture", "Ok", "Cancel", "", {"*.png", "*.dds"}, 0);
	SubscribeToEvent(fileSelector_, StringHash("FileSelected"), URHO3D_HANDLER(TerrainTexturingUI, HandleSelectNormalFile));
}

void TerrainTexturingUI::HandleSelectDiffuseFile(StringHash eventType, VariantMap &eventData)
{
	auto cache=GetSubsystem<ResourceCache>();

	String name=eventData["FileName"].GetString();
	String fname=GetFilenameFromPath(name);
	Log::Write(LOG_INFO, String("Path: ") + name + " filename: " + fname);
	if(fname=="")
	{
		Log::Write(LOG_INFO, "Bailing out for no filename");
		fileSelector_.Reset();
		return;
	}
	selectedDiffImage_=cache->GetResource<Image>(fname);
	GenerateThumbnailImage(selectedDiffImageThumb_, *selectedDiffImage_);
	selectedDiffImageName_=fname;
	editLayerElement_->GetChildDynamicCast<LineEdit>("DiffuseName", true)->SetText(fname);
	editLayerDiffTex_->SetData(&selectedDiffImageThumb_, false);
	diffuseSelected_=true;
	fileSelector_.Reset();
}

void TerrainTexturingUI::HandleSelectNormalFile(StringHash eventType, VariantMap &eventData)
{
	auto cache=GetSubsystem<ResourceCache>();

	String name=eventData["FileName"].GetString();
	String fname=GetFilenameFromPath(name);
	Log::Write(LOG_INFO, String("Path: ") + name + " filename: " + fname);
	if(fname=="")
	{
		Log::Write(LOG_INFO, "Bailing out for no filename");
		fileSelector_.Reset();
		return;
	}
	selectedNormalImage_=cache->GetResource<Image>(fname);
	GenerateThumbnailImage(selectedNormalImageThumb_, *selectedNormalImage_);
	selectedNormalImageName_=fname;
	editLayerElement_->GetChildDynamicCast<LineEdit>("NormalName", true)->SetText(fname);
	editLayerNormalTex_->SetData(&selectedNormalImageThumb_, false);
	normalSelected_=true;
	fileSelector_.Reset();
}

void TerrainTexturingUI::SetBrushMax(float ht)
{
	if(!element_) return;
	Slider *s=element_->GetChildDynamicCast<Slider>("MaxSlider", true);
	if(s)
	{
		s->SetValue(ht*s->GetRange());
		brushSettings_.max_ = ht;
		SetBrushUIFields();
	}
}

void TerrainTexturingUI::GenerateThumbnailImage(Image &out, const Image &in)
{
	out.SetSize(64,64,3);
	for(unsigned int y=0; y<64; ++y)
	{
		for(unsigned int x=0; x<64; ++x)
		{
			x=std::min(x,(unsigned int)in.GetWidth());
			y=std::min(y,(unsigned int)in.GetHeight());
			out.SetPixel(x,y,in.GetPixel(x,y));
		}
	}
}

void TerrainTexturingUI::SetLayerScales()
{
	if(!materialBuilder_) return;
	materialBuilder_->SetLayerScales(layerScales_);
}


SharedPtr<FileSelector> TerrainTexturingUI::CreateFileSelector(const String &title, const String &oktext, const String &canceltext, const String &initialPath, const Vector<String> &filters, unsigned int initialFilter)
{
	auto cache=GetSubsystem<ResourceCache>();
	XMLFile *style=cache->GetResource<XMLFile>("UI/DefaultStyle.xml");

	SharedPtr<FileSelector> fs=SharedPtr<FileSelector>(new FileSelector(context_));
	fs->SetDefaultStyle(style);
	fs->SetTitle(title);
	fs->SetPath(initialPath);
	fs->SetButtonTexts(oktext, canceltext);
	fs->SetFilters(filters, initialFilter);
	return fs;
}

String TerrainTexturingUI::GetFilenameFromPath(const String &path)
{
	auto cache=GetSubsystem<ResourceCache>();

	const Vector<String> &resourceDirs=cache->GetResourceDirs();
	String pl=path.ToLower();

	for(unsigned int c=0; c<resourceDirs.Size(); ++c)
	{
		String rl=resourceDirs[c].ToLower();
		unsigned idx=pl.Find(rl);
		if(idx!=String::NPOS)
		{
			String sub=path.Substring(idx+resourceDirs[c].Length());
			return sub;
		}
	}

	return String("");
}
