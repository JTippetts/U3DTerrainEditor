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
}

void TerrainEditor::Start()
{
	auto input=GetSubsystem<Input>();
    RegisterComponents(context_);
	
	input->SetMouseVisible(true);
}

void TerrainEditor::Stop()
{

}
