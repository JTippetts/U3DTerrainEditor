#pragma once

// FiltersUI
#include <Urho3D/Core/Context.h>
#include <Urho3D/Core/Object.h>
#include <Urho3D/UI/UIElement.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/Node.h>
#include <Urho3D/Graphics/Light.h>
#include <Urho3D/Graphics/Zone.h>
#include <Urho3D/UI/FileSelector.h>

#include "colorchooser.h"

#include "../Filters/filterbase.h"

using namespace Urho3D;

class EditingCamera;
class TerrainContext;
class NodeGraphUI;
class WaypointGroupUI;
class TerrainTexturingUI;
class EditMaskUI;

class FiltersUI : public Object
{
	URHO3D_OBJECT(FiltersUI, Object);
	public:
	FiltersUI(Context *context);
	
	void Construct(TerrainContext *tc, WaypointGroupUI *wg);
	void SetVisible(bool vis);
	bool IsVisible(){if(element_) return element_->IsVisible(); return false;}
	
	template <class T>
	void AddFilter()
	{
		filters_.push_back(SharedPtr<T>(new T(context_, terrainContext_, waypointGroups_)));
	}
	
	protected:
	TerrainContext *terrainContext_;
	WaypointGroupUI *waypointGroups_;
	
	SharedPtr<UIElement> element_;
	SharedPtr<UIElement> optionswindow_;
	std::vector<SharedPtr<FilterBase>> filters_;
	
	FilterBase *selectedFilter_;
	
	void BuildFilterList();
	void HandleExecuteButton(StringHash eventType, VariantMap &eventData);
	void HandleCloseButton(StringHash eventType, VariantMap &eventData);
	void HandleItemSelected(StringHash eventType, VariantMap &eventData);
};
