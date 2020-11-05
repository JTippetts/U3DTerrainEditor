#include "editheightui.h"

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
#include <Urho3D/IO/Log.h>

#include "../format.h"


EditHeightUI::EditHeightUI(Context *context) : Object(context),
	terrainContext_(nullptr),
	materialBuilder_(nullptr),
	alphaSelector_(nullptr),
	camera_(nullptr),
	brushSettings_{0.5f, 0.5f, 1.0f, 0.0f},
	brushPreview_(context)
{
}

void EditHeightUI::Construct(TerrainContext *tc, TerrainMaterialBuilder *tmb, AlphaBrushSelectorUI *abs, EditingCamera *camera)
{
	terrainContext_=tc;
	materialBuilder_=tmb;
	alphaSelector_=abs;
	camera_=camera;

	auto cache=GetSubsystem<ResourceCache>();
	auto graphics=GetSubsystem<Graphics>();
	auto ui=GetSubsystem<UI>();

	XMLFile *style=cache->GetResource<XMLFile>("UI/DefaultStyle.xml");

	element_=ui->LoadLayout(cache->GetResource<XMLFile>("UI/TerrainEditHeightBrush.xml"), style);
	if(element_)
	{
		ui->GetRoot()->GetChild("Base",true)->AddChild(element_);
		brushPreview_.SetSize(64,64,3);
		brushPreviewTex_=SharedPtr<Texture2D>(new Texture2D(context_));
		element_->GetChildDynamicCast<BorderImage>("BrushPreview", true)->SetTexture(brushPreviewTex_);
		GenerateBrushPreview();
		SetBrushUIFields();
		
		element_->SetPosition(IntVector2(104, graphics->GetHeight()-element_->GetHeight()));

		SubscribeToEvent(element_->GetChild("PowerSlider", true), StringHash("SliderChanged"), URHO3D_HANDLER(EditHeightUI, HandleSliderChanged));
		SubscribeToEvent(element_->GetChild("RadiusSlider", true), StringHash("SliderChanged"), URHO3D_HANDLER(EditHeightUI, HandleSliderChanged));
		SubscribeToEvent(element_->GetChild("MaxSlider", true), StringHash("SliderChanged"), URHO3D_HANDLER(EditHeightUI, HandleSliderChanged));
		SubscribeToEvent(element_->GetChild("HardnessSlider", true), StringHash("SliderChanged"), URHO3D_HANDLER(EditHeightUI, HandleSliderChanged));
	}

	SubscribeToEvent(StringHash("Update"), URHO3D_HANDLER(EditHeightUI, HandleUpdate));
}

void EditHeightUI::SetVisible(bool v)
{
	if(element_) element_->SetVisible(v);
	if(alphaSelector_) alphaSelector_->SetVisible(v);

	if(!v) materialBuilder_->SetEditingCursor(-100000, -100000, brushSettings_.radius_*100.0f, brushSettings_.hardness_, camera_->GetYaw());
}

void EditHeightUI::HandleSliderChanged(StringHash eventType, VariantMap &eventData)
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

void EditHeightUI::GenerateBrushPreview()
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

void EditHeightUI::SetBrushUIFields()
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

void EditHeightUI::GetBrushUIFields()
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

void EditHeightUI::HandleUpdate(StringHash eventType, VariantMap &eventData)
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
			if(input->GetQualifierDown(QUAL_CTRL))
			{
				float ht=terrainContext_->GetHeightValue(ground);
				SetBrushMax(ht);
			}
			else
			{
				GetBrushUIFields();
				terrainContext_->ApplyHeightAlpha(ground.x_, ground.z_, dt, brushSettings_, maskSettings_, *(alphaSelector_->GetAlphaBrush()), -camera_->GetYaw()*3.14159265f/180.0f);
			}
		}
	}
}

void EditHeightUI::SetBrushMax(float ht)
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
