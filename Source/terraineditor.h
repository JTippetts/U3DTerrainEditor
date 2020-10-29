//
// Copyright (c) 2008-2014 Joshua Tippetts.
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

#pragma once

#include "Urho3D/Engine/Application.h"
#include "Components/editingcamera.h"
#include <Urho3D/Scene/Scene.h>
#include "terraincontext.h"
#include "terrainmaterialbuilder.h"
#include "UI/alphabrushselectorui.h"
#include "UI/editheightui.h"
#include "UI/editwaterui.h"
#include "UI/terraintexturingui.h"
#include "UI/maintoolbarui.h"
#include "UI/smoothheightui.h"
#include "UI/editmaskui.h"
#include "UI/nodegraphui.h"
#include "UI/waypointgroupui.h"

using namespace Urho3D;

/// TerrainEditor application runs a script specified on the command line.
class TerrainEditor : public Application
{
    URHO3D_OBJECT(TerrainEditor,Application);

public:
    /// Construct.
    TerrainEditor(Context* context);

    /// Setup before engine initialization. Verify that a script file has been specified.
    virtual void Setup();
    /// Setup after engine initialization. Load the script and execute its start function.
    virtual void Start();
    /// Cleanup after the main loop. Run the script's stop function if it exists.
    virtual void Stop();

private:
	SharedPtr<Scene> scene_;
	EditingCamera *camera_;
	SharedPtr<TerrainContext> terrainContext_;
	SharedPtr<TerrainMaterialBuilder> materialBuilder_;
	SharedPtr<AlphaBrushSelectorUI> alphaSelector_;
	SharedPtr<EditHeightUI> editHeight_;
	SharedPtr<EditWaterUI> editWater_;
	SharedPtr<TerrainTexturingUI> terrainTexturing_;
	SharedPtr<SmoothHeightUI> smoothHeight_;
	SharedPtr<EditMaskUI> editMask_;
	SharedPtr<NodeGraphUI> nodeGraph_;
	SharedPtr<WaypointGroupUI> waypointGroups_;
	
	SharedPtr<MainToolbarUI> mainToolbar_;
	
	void HandleUpdate(StringHash eventType, VariantMap &eventData);
};
