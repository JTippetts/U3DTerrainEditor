#pragma once

// Main Toolbar
#include <Urho3D/Core/Context.h>
#include <Urho3D/Core/Object.h>
#include <Urho3D/UI/UIElement.h>
#include <Urho3D/Resource/Image.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <Urho3D/UI/FileSelector.h>
#include <vector>

class EditHeightUI;
class TerrainTexturingUI;
class EditWaterUI;
class SmoothHeightUI;
class EditMaskUI;
class NodeGraphUI;
class WaypointGroupUI;
class TerrainSettingsUI;
class FiltersUI;

using namespace Urho3D;

class MainToolbarUI : public Object
{
	URHO3D_OBJECT(MainToolbarUI, Object);
	public:
	MainToolbarUI(Context *context);

	void Construct(EditHeightUI *eh, TerrainTexturingUI *tt, EditWaterUI *ew, SmoothHeightUI *sh, EditMaskUI *em, NodeGraphUI *ng, WaypointGroupUI *wp, TerrainSettingsUI *ts, FiltersUI *f);
	void SetVisible(bool v);
	bool IsVisible(){if(element_) return element_->IsVisible(); return false;}

	protected:
	EditHeightUI *editHeightUI_;
	TerrainTexturingUI *terrainTexturingUI_;
	EditWaterUI *editWater_;
	SmoothHeightUI *smoothHeight_;
	EditMaskUI *editMask_;
	NodeGraphUI *nodeGraph_;
	WaypointGroupUI *waypointGroups_;
	TerrainSettingsUI *terrainSettings_;
	FiltersUI *filters_;

	SharedPtr<UIElement> element_;

	void HandleToggled(StringHash eventType, VariantMap &eventData);

	void UncheckToolbar(const ea::string &except);
};
