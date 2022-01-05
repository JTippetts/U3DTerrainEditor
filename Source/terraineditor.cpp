//
// Copyright (c) 2008-2020 Joshua Tippetts.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Engine/EngineDefs.h>
#include <Urho3D/IO/FileSystem.h>
#include <Urho3D/IO/Log.h>
#include <Urho3D/Core/Main.h>
#include <Urho3D/Core/ProcessUtils.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Resource/ResourceEvents.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/Graphics/Model.h>
#include <Urho3D/Graphics/StaticModel.h>
#include <Urho3D/Graphics/Zone.h>
#include <Urho3D/Graphics/Light.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Graphics/Texture2DArray.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/UI/UI.h>

#include "registercomponents.h"
#include "terraineditor.h"

#include "Urho3D/DebugNew.h"

URHO3D_DEFINE_APPLICATION_MAIN(TerrainEditor);

TerrainEditor::TerrainEditor(Context* context) :
    Application(context),
	camera_(nullptr)
{
}

void TerrainEditor::Setup()
{
    engineParameters_[EP_WINDOW_TITLE] = GetTypeName();
    engineParameters_[EP_LOG_NAME]     = GetTypeName() + ".log";
    engineParameters_[EP_FULL_SCREEN]  = false;
	engineParameters_[EP_WINDOW_RESIZABLE]=true;
    engineParameters_[EP_HEADLESS]     = false;
    engineParameters_[EP_SOUND]        = false;
	engineParameters_[EP_LOG_LEVEL]     = LOG_DEBUG;
	engineParameters_[EP_WINDOW_WIDTH] = 1024;
	engineParameters_[EP_WINDOW_HEIGHT] = 768;
	engineParameters_[EP_WINDOW_MAXIMIZE] = true;
}

void TerrainEditor::Start()
{
	auto input=GetSubsystem<Input>();
	auto cache=GetSubsystem<ResourceCache>();
	auto graphics=GetSubsystem<Graphics>();
	auto ui=GetSubsystem<UI>();
	
	// Create some layers
	ui->GetRoot()->CreateChild<UIElement>("Base")->SetSize(IntVector2(graphics->GetWidth(), graphics->GetHeight()));
	ui->GetRoot()->CreateChild<UIElement>("OnTop")->SetSize(IntVector2(graphics->GetWidth(), graphics->GetHeight()));
	
    RegisterComponents(context_);
	
	input->SetMouseVisible(true);
	
	scene_=SharedPtr<Scene>(new Scene(context_));
	scene_->CreateComponent<Octree>();
	
	// Setup camera
	Node *camnode=scene_->CreateChild();
	camera_=camnode->CreateComponent<EditingCamera>();
	camnode->SetPosition(Vector3(0,0,0));
	camera_->SetCameraBounds(Vector2(-200,-200), Vector2(200,200));
	camera_->SetScrollSpeed(32.0f);
	camera_->SetMaxFollow(600.f);
	
	terrainContext_=SharedPtr<TerrainContext>(new TerrainContext(context_));
	terrainContext_->Construct(scene_, camera_);
	terrainContext_->SetHeightMapSize(IntVector2(1025,1025));
	terrainContext_->SetBlendMapSize(IntVector2(2048,2048));
	terrainContext_->SetMaskSize(IntVector2(2048,2048));
	
	materialBuilder_=SharedPtr<TerrainMaterialBuilder>(new TerrainMaterialBuilder(context_));
	materialBuilder_->Construct(terrainContext_);
	
	alphaSelector_=SharedPtr<AlphaBrushSelectorUI>(new AlphaBrushSelectorUI(context_));
	alphaSelector_->Construct(materialBuilder_);
	
	editHeight_=SharedPtr<EditHeightUI>(new EditHeightUI(context_));
	editHeight_->Construct(terrainContext_, materialBuilder_, alphaSelector_, camera_);
	editHeight_->SetVisible(false);
	
	editWater_=SharedPtr<EditWaterUI>(new EditWaterUI(context_));
	editWater_->Construct(terrainContext_, materialBuilder_, camera_);
	editWater_->SetVisible(false);
	
	terrainTexturing_=SharedPtr<TerrainTexturingUI>(new TerrainTexturingUI(context_));
	terrainTexturing_->Construct(terrainContext_, materialBuilder_, alphaSelector_, camera_);
	terrainTexturing_->SetVisible(false);
	
	smoothHeight_=SharedPtr<SmoothHeightUI>(new SmoothHeightUI(context_));
	smoothHeight_->Construct(terrainContext_, materialBuilder_, alphaSelector_, camera_);
	smoothHeight_->SetVisible(false);
	
	editMask_=SharedPtr<EditMaskUI>(new EditMaskUI(context_));
	editMask_->Construct(terrainContext_, materialBuilder_, alphaSelector_, camera_);
	editMask_->SetVisible(false);
	
	nodeGraph_=SharedPtr<NodeGraphUI>(new NodeGraphUI(context_));
	nodeGraph_->Construct(terrainContext_);
	nodeGraph_->SetVisible(false);
	
	waypointGroups_=SharedPtr<WaypointGroupUI>(new WaypointGroupUI(context_));
	waypointGroups_->Construct(scene_, terrainContext_, camera_);
	waypointGroups_->SetVisible(false);
	
	terrainSettings_=SharedPtr<TerrainSettingsUI>(new TerrainSettingsUI(context_));
	terrainSettings_->Construct(scene_, camera_, terrainContext_, terrainTexturing_, editMask_, nodeGraph_, waypointGroups_);
	terrainSettings_->SetVisible(false);
	
	filters_=SharedPtr<FiltersUI>(new FiltersUI(context_));
	filters_->Construct(terrainContext_, waypointGroups_);
	filters_->SetVisible(false);
	
	mainToolbar_=SharedPtr<MainToolbarUI>(new MainToolbarUI(context_));
	mainToolbar_->Construct(editHeight_, terrainTexturing_, editWater_, smoothHeight_, editMask_, nodeGraph_, waypointGroups_, terrainSettings_, filters_);
	mainToolbar_->SetVisible(true);
	
	camera_->SetTerrainContext(terrainContext_);
	
	SubscribeToEvent(StringHash("Update"), URHO3D_HANDLER(TerrainEditor, HandleUpdate));
}

void TerrainEditor::Stop()
{
	terrainContext_.Reset();
}

void TerrainEditor::HandleUpdate(StringHash eventType, VariantMap &eventData)
{
	float dt=eventData["TimeStep"].GetFloat();
}