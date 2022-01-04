#include "terrainsettingsui.h"

#include <Urho3D/UI/Text.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Resource/XMLFile.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/UI/Menu.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/UI/UIElement.h>
#include <Urho3D/UI/Window.h>
#include <Urho3D/UI/ListView.h>
#include <Urho3D/UI/DropDownList.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/UI/BorderImage.h>
#include <Urho3D/UI/Font.h>
#include <Urho3D/UI/LineEdit.h>
#include <Urho3D/IO/Log.h>
#include <Urho3D/UI/CheckBox.h>
#include <Urho3D/UI/Button.h>
#include <Urho3D/UI/Slider.h>
#include <Urho3D/IO/FileSystem.h>
#include <Urho3D/Resource/JSONFile.h>
#include <Urho3D/Resource/JSONValue.h>

#include "../terraincontext.h"
#include "nodegraphui.h"
#include "waypointgroupui.h"
#include "../Components/editingcamera.h"
#include "terraintexturingui.h"
#include "editmaskui.h"

#include "../jsonutilities.h"

TerrainSettingsUI::TerrainSettingsUI(Context *context) : Object(context),
	scene_(nullptr),
	terrainContext_(nullptr),
	nodeGraph_(nullptr),
	waypointGroups_(nullptr),
	editMask_(nullptr),
	terrainTexturing_(nullptr),
	mainChooser_(context),
	backChooser_(context),
	ambientChooser_(context),
	fogChooser_(context),
	mainLightNode_(nullptr),
	backLightNode_(nullptr),
	zoneNode_(nullptr),
	mainLight_(nullptr),
	backLight_(nullptr),
	zone_(nullptr)
{
}

void TerrainSettingsUI::Construct(Scene *scene, EditingCamera *cam, TerrainContext *tc, TerrainTexturingUI *tt, EditMaskUI *em, NodeGraphUI *ng, WaypointGroupUI *wg)
{
	scene_=scene;
	camera_=cam;
	terrainContext_=tc;
	nodeGraph_=ng;
	waypointGroups_=wg;
	editMask_=em;
	terrainTexturing_=tt;

	auto ui=GetSubsystem<UI>();
	auto cache=GetSubsystem<ResourceCache>();
	auto graphics=GetSubsystem<Graphics>();

	element_=ui->LoadLayout(cache->GetResource<XMLFile>("UI/TerrainSettings.xml"), cache->GetResource<XMLFile>("UI/DefaultStyle.xml"));
	element_->SetVisible(false);
	ui->GetRoot()->GetChild("Base", true)->AddChild(element_);
	element_->SetPosition(IntVector2(0, graphics->GetHeight()-element_->GetHeight()));

	mainLightNode_=scene->CreateChild();
	backLightNode_=scene->CreateChild();
	zoneNode_=scene->CreateChild();

	mainLight_=mainLightNode_->CreateComponent<Light>();
	mainLight_->SetLightType(LIGHT_DIRECTIONAL);
	mainLight_->SetCastShadows(true);
	mainLightNode_->SetDirection(Vector3(1.5,-3.5,-1.5));

	backLight_=backLightNode_->CreateComponent<Light>();
	backLight_->SetLightType(LIGHT_DIRECTIONAL);
	backLightNode_->SetDirection(Vector3(-1.5,-3.5,1.5));

	zone_=zoneNode_->CreateComponent<Zone>();

	Color mainColor(1,0.8,0.8);
	Color backColor(0.5,0.5,0.6);
	Color ambientColor(0.5,0.5,0.6);
	Color fogColor(1,1,1);

	mainLight_->SetColor(mainColor);
	mainChooser_.SetColor(mainColor);
	backLight_->SetColor(backColor);
	backChooser_.SetColor(backColor);
	zone_->SetAmbientColor(ambientColor);
	ambientChooser_.SetColor(ambientColor);
	zone_->SetFogColor(fogColor);
	fogChooser_.SetColor(fogColor);

	Button *mainLightButton=element_->GetChildDynamicCast<Button>("MainLight", true);
	Button *backLightButton=element_->GetChildDynamicCast<Button>("BackLight", true);
	Button *ambientLightButton=element_->GetChildDynamicCast<Button>("Ambient", true);
	Button *fogLightButton=element_->GetChildDynamicCast<Button>("Fog", true);

	mainLightButton->SetHoverOffset(IntVector2(0,0));
	mainLightButton->SetPressedOffset(IntVector2(0,0));
	mainLightButton->SetBorder(IntRect(0,0,0,0));
	backLightButton->SetHoverOffset(IntVector2(0,0));
	backLightButton->SetPressedOffset(IntVector2(0,0));
	backLightButton->SetBorder(IntRect(0,0,0,0));
	fogLightButton->SetHoverOffset(IntVector2(0,0));
	fogLightButton->SetPressedOffset(IntVector2(0,0));
	fogLightButton->SetBorder(IntRect(0,0,0,0));
	ambientLightButton->SetHoverOffset(IntVector2(0,0));
	ambientLightButton->SetPressedOffset(IntVector2(0,0));
	ambientLightButton->SetBorder(IntRect(0,0,0,0));

	mainLightButton->SetColor(mainColor);
	backLightButton->SetColor(backColor);
	ambientLightButton->SetColor(ambientColor);
	fogLightButton->SetColor(fogColor);

	zone_->SetBoundingBox(terrainContext_->GetBoundingBox());

	SubscribeToEvent(element_->GetChild("SaveProject",true), StringHash("Pressed"), URHO3D_HANDLER(TerrainSettingsUI, HandleSaveProject));
	SubscribeToEvent(element_->GetChild("LoadProject",true), StringHash("Pressed"), URHO3D_HANDLER(TerrainSettingsUI, HandleLoadProject));
	SubscribeToEvent(element_->GetChild("ClearProject",true), StringHash("Pressed"), URHO3D_HANDLER(TerrainSettingsUI, HandleClearProject));

	SubscribeToEvent(mainLightButton, StringHash("Pressed"), URHO3D_HANDLER(TerrainSettingsUI, HandleShowColorChooser));
	SubscribeToEvent(backLightButton, StringHash("Pressed"), URHO3D_HANDLER(TerrainSettingsUI, HandleShowColorChooser));
	SubscribeToEvent(ambientLightButton, StringHash("Pressed"), URHO3D_HANDLER(TerrainSettingsUI, HandleShowColorChooser));
	SubscribeToEvent(fogLightButton, StringHash("Pressed"), URHO3D_HANDLER(TerrainSettingsUI, HandleShowColorChooser));

	SubscribeToEvent(mainChooser_.GetCloseButton(), StringHash("Pressed"), URHO3D_HANDLER(TerrainSettingsUI, HandleHideColorChooser));
	SubscribeToEvent(backChooser_.GetCloseButton(), StringHash("Pressed"), URHO3D_HANDLER(TerrainSettingsUI, HandleHideColorChooser));
	SubscribeToEvent(ambientChooser_.GetCloseButton(), StringHash("Pressed"), URHO3D_HANDLER(TerrainSettingsUI, HandleHideColorChooser));
	SubscribeToEvent(fogChooser_.GetCloseButton(), StringHash("Pressed"), URHO3D_HANDLER(TerrainSettingsUI, HandleHideColorChooser));

	SubscribeToEvent(element_->GetChild("PickPath", true), StringHash("Pressed"), URHO3D_HANDLER(TerrainSettingsUI, HandlePickPath));

	SubscribeToEvent(element_->GetChild("ApplyTerrainSettings", true), StringHash("Pressed"), URHO3D_HANDLER(TerrainSettingsUI, HandleApplyTerrainSettings));

	element_->GetChildDynamicCast<LineEdit>("ProjectPath", true)->SetText(GetSubsystem<FileSystem>()->GetUserDocumentsDir());

	SubscribeToEvent(StringHash("Update"), URHO3D_HANDLER(TerrainSettingsUI, HandleUpdate));
}

void TerrainSettingsUI::SetVisible(bool vis)
{
	if(element_) element_->SetVisible(vis);
}

void TerrainSettingsUI::HandleSaveProject(StringHash eventType, VariantMap &eventData)
{
	ea::string path=element_->GetChildDynamicCast<LineEdit>("ProjectPath", true)->GetText();
	ea::string dirname=element_->GetChildDynamicCast<LineEdit>("ProjectName", true)->GetText();
	if(path[path.length()-1] != '/') path=path+"/";
	ea::string fullpath=path+dirname;

	auto fs=GetSubsystem<FileSystem>();
	if(!fs->DirExists(fullpath))
	{
		fs->CreateDir(fullpath);
	}

	//terrainContext_->Save(fullpath);
	Save(fullpath);
}

void TerrainSettingsUI::HandleLoadProject(StringHash eventType, VariantMap &eventData)
{
	ea::string path=element_->GetChildDynamicCast<LineEdit>("ProjectPath", true)->GetText();
	ea::string dirname=element_->GetChildDynamicCast<LineEdit>("ProjectName", true)->GetText();
	if(path[path.length()-1] != '/') path=path+"/";
	ea::string fullpath=path+dirname;

	auto fs=GetSubsystem<FileSystem>();
	if(!fs->DirExists(fullpath)) return;

	//terrainContext_->Load(fullpath);
	Load(fullpath);
}

void TerrainSettingsUI::HandleClearProject(StringHash eventType, VariantMap &eventData)
{
	terrainContext_->Clear();

	waypointGroups_->Clear();
	nodeGraph_->Clear();
}

void TerrainSettingsUI::HandleApplyTerrainSettings(StringHash eventType, VariantMap &eventData)
{
	if(!terrainContext_ || !element_) return;

	int size=ToInt(element_->GetChildDynamicCast<LineEdit>("TerrainSize", true)->GetText());
	int layersize=ToInt(element_->GetChildDynamicCast<LineEdit>("LayerSize", true)->GetText());
	float spacing=ToFloat(element_->GetChildDynamicCast<LineEdit>("TerrainSpacing", true)->GetText());
	float height=ToFloat(element_->GetChildDynamicCast<LineEdit>("TerrainHeight", true)->GetText());

	Vector3 space(spacing,height,spacing);
	terrainContext_->SetSpacing(space);
	terrainContext_->SetHeightMapSize(IntVector2(size,size));
	terrainContext_->SetBlendMapSize(IntVector2(layersize,layersize));
	terrainContext_->SetMaskSize(IntVector2(layersize,layersize));
}

void TerrainSettingsUI::HandleShowColorChooser(StringHash eventType, VariantMap &eventData)
{
	UIElement *element=static_cast<UIElement *>(eventData["Element"].GetPtr());
	backChooser_.SetVisible(false);
	mainChooser_.SetVisible(false);
	ambientChooser_.SetVisible(false);
	fogChooser_.SetVisible(false);

	if(element==element_->GetChildDynamicCast<Button>("MainLight", true)) mainChooser_.SetVisible(true);
	else if(element==element_->GetChildDynamicCast<Button>("BackLight", true)) backChooser_.SetVisible(true);
	else if(element==element_->GetChildDynamicCast<Button>("Ambient", true)) ambientChooser_.SetVisible(true);
	else if(element==element_->GetChildDynamicCast<Button>("Fog", true)) fogChooser_.SetVisible(true);
}

void TerrainSettingsUI::HandleHideColorChooser(StringHash eventType, VariantMap &eventData)
{
	backChooser_.SetVisible(false);
	mainChooser_.SetVisible(false);
	ambientChooser_.SetVisible(false);
	fogChooser_.SetVisible(false);
}

void TerrainSettingsUI::HandleUpdate(StringHash eventType, VariantMap &eventData)
{
	Button *mainLightButton=element_->GetChildDynamicCast<Button>("MainLight", true);
	Button *backLightButton=element_->GetChildDynamicCast<Button>("BackLight", true);
	Button *ambientLightButton=element_->GetChildDynamicCast<Button>("Ambient", true);
	Button *fogLightButton=element_->GetChildDynamicCast<Button>("Fog", true);

	mainLight_->SetColor(mainChooser_.GetColor());
	mainLightButton->SetColor(mainChooser_.GetColor());

	backLight_->SetColor(backChooser_.GetColor());
	backLightButton->SetColor(backChooser_.GetColor());

	ambientLightButton->SetColor(ambientChooser_.GetColor());
	fogLightButton->SetColor(fogChooser_.GetColor());

	Slider *nearfog=element_->GetChildDynamicCast<Slider>("NearFog", true);
	Slider *farfog=element_->GetChildDynamicCast<Slider>("FarFog", true);

	float nr=nearfog->GetValue()/ nearfog->GetRange();
	float fr=farfog->GetValue()/farfog->GetRange();

	float fogstart=nr*1024.f;
	float fogend=fogstart+fr*512.f;
	zone_->SetFogStart(fogstart);
	zone_->SetFogEnd(fogend);

	zone_->SetAmbientColor(ambientChooser_.GetColor());
	zone_->SetFogColor(fogChooser_.GetColor());

	camera_->SetFarClip(fogend);
}

void TerrainSettingsUI::HandlePickPath(StringHash eventType, VariantMap &eventData)
{
	ea::string curpath=element_->GetChildDynamicCast<LineEdit>("ProjectPath", true)->GetText();
	fileSelector_=CreateFileSelector("Select Project Path", "Ok", "Cancel", curpath);
	SubscribeToEvent(fileSelector_, StringHash("FileSelected"), URHO3D_HANDLER(TerrainSettingsUI, HandlePickPathConfirm));
}

void TerrainSettingsUI::HandlePickPathConfirm(StringHash eventType, VariantMap &eventData)
{
	if(eventData["OK"].GetBool())
	{
		ea::string filename=eventData["FileName"].GetString();
		ea::string fsfilename=fileSelector_->GetFileName();
		element_->GetChildDynamicCast<LineEdit>("ProjectPath", true)->SetText(filename);
	}
	fileSelector_.Reset();
}

void TerrainSettingsUI::Save(const ea::string &fullpath)
{
	terrainContext_->Save(fullpath);
	JSONFile jfile(context_);

	JSONObject json;

	// Save settings
	terrainTexturing_->Save(json);
	nodeGraph_->Save(json);
	waypointGroups_->Save(json);

	JSONObject lighting;

	lighting["MainLightColor"]=JSONFromColor(mainLight_->GetColor());
	lighting["BackLightColor"]=JSONFromColor(backLight_->GetColor());
	lighting["AmbientColor"]=JSONFromColor(zone_->GetAmbientColor());
	lighting["FogColor"]=JSONFromColor(zone_->GetFogColor());
	lighting["FogNear"]=JSONValue(zone_->GetFogStart());
	lighting["FogFar"]=JSONValue(zone_->GetFogEnd());

	json["LightingSettings"]=lighting;

	json["TerrainSpacing"]=JSONFromVector3(terrainContext_->GetSpacing());

	File settings(context_);
	if(settings.Open(fullpath+"/settings.json", FILE_WRITE))
	{
		jfile.GetRoot()=json;
		jfile.Save(settings);
	}
	settings.Close();
}

void TerrainSettingsUI::Load(const ea::string &fullpath)
{
	auto cache=GetSubsystem<ResourceCache>();

	terrainContext_->Load(fullpath);

	JSONFile jfile(context_);

	File settings(context_);
	if(settings.Open(fullpath+"/settings.json", FILE_READ))
	{
		jfile.Load(settings);

		const JSONValue &json=jfile.GetRoot().GetObject();

		terrainTexturing_->Load(json);
		nodeGraph_->Load(json);
		waypointGroups_->Load(json);

		if(json["LightingSettings"].IsObject())
		{
			const JSONValue &lighting=json["LightingSettings"];
			Color mlc=(lighting["MainLightColor"].IsObject()) ? ColorFromJSON(lighting["MainLightColor"]) : mainLight_->GetColor();
			Color blc=(lighting["BackLightColor"].IsObject()) ? ColorFromJSON(lighting["BackLightColor"]) : backLight_->GetColor();
			Color ac=(lighting["AmbientColor"].IsObject()) ? ColorFromJSON(lighting["AmbientColor"]) : zone_->GetAmbientColor();
			Color fc=(lighting["FogColor"].IsObject()) ? ColorFromJSON(lighting["FogColor"]) : zone_->GetFogColor();
			float fn=(lighting["FogNear"].IsNumber()) ? lighting["FogNear"].GetFloat() : zone_->GetFogStart();
			float ff=(lighting["FogFar"].IsNumber()) ? lighting["FogFar"].GetFloat() : zone_->GetFogEnd();

			mainLight_->SetColor(mlc);
			backLight_->SetColor(blc);
			zone_->SetAmbientColor(ac);
			zone_->SetFogColor(fc);
			zone_->SetFogStart(fn);
			zone_->SetFogEnd(ff);
			camera_->SetFarClip(ff);

			Button *mainLightButton=element_->GetChildDynamicCast<Button>("MainLight", true);
			Button *backLightButton=element_->GetChildDynamicCast<Button>("BackLight", true);
			Button *ambientLightButton=element_->GetChildDynamicCast<Button>("Ambient", true);
			Button *fogLightButton=element_->GetChildDynamicCast<Button>("Fog", true);

			mainLightButton->SetColor(mlc);
			backLightButton->SetColor(blc);
			ambientLightButton->SetColor(ac);
			fogLightButton->SetColor(fc);

			mainChooser_.SetColor(mlc);
			backChooser_.SetColor(blc);
			ambientChooser_.SetColor(ac);
			fogChooser_.SetColor(fc);

			Slider *nearfog=element_->GetChildDynamicCast<Slider>("NearFog", true);
			Slider *farfog=element_->GetChildDynamicCast<Slider>("FarFog", true);

			nearfog->SetValue((fn/1024.f)*nearfog->GetRange());
			farfog->SetValue((ff/512.f)*farfog->GetRange());
		}
		if(json["TerrainSpacing"].IsArray())
		{
			Vector3 spc=Vector3FromJSON(json["TerrainSpacing"].GetArray());
			terrainContext_->SetSpacing(spc);
		}
	}
}

SharedPtr<FileSelector> TerrainSettingsUI::CreateFileSelector(const ea::string &title, const ea::string &oktext, const ea::string &canceltext, const ea::string &initialPath)
{
	auto cache=GetSubsystem<ResourceCache>();
	XMLFile *style=cache->GetResource<XMLFile>("UI/DefaultStyle.xml");

	SharedPtr<FileSelector> fs=SharedPtr<FileSelector>(new FileSelector(context_));
	fs->SetDefaultStyle(style);
	fs->SetTitle(title);
	fs->SetPath(initialPath);
	fs->SetButtonTexts(oktext, canceltext);
	fs->SetDirectoryMode(true);
	return fs;
}
