#pragma once

// TerrainSettingsUI

#include <Urho3D/Core/Context.h>
#include <Urho3D/Core/Object.h>
#include <Urho3D/UI/UIElement.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/Node.h>
#include <Urho3D/Graphics/Light.h>
#include <Urho3D/Graphics/Zone.h>
#include <Urho3D/UI/FileSelector.h>
#include <Urho3D/Graphics/Material.h>

#include "colorchooser.h"

using namespace Urho3D;

class EditingCamera;
class TerrainContext;
class NodeGraphUI;
class WaypointGroupUI;
class TerrainTexturingUI;
class EditMaskUI;

class TerrainSettingsUI : public Object
{
	URHO3D_OBJECT(TerrainSettingsUI, Object);
	public:
	TerrainSettingsUI(Context *context);

	void Construct(Scene *scene, EditingCamera *cam, TerrainContext *tc, TerrainTexturingUI *tt, EditMaskUI *em, NodeGraphUI *ng, WaypointGroupUI *wg);
	void SetVisible(bool v);
	bool IsVisible(){if(element_) return element_->IsVisible(); return false;}

	protected:
	Scene *scene_;
	EditingCamera *camera_;
	TerrainContext *terrainContext_;
	NodeGraphUI *nodeGraph_;
	WaypointGroupUI *waypointGroups_;
	EditMaskUI *editMask_;
	TerrainTexturingUI *terrainTexturing_;

	SharedPtr<UIElement> element_;
	SharedPtr<FileSelector> fileSelector_;
	ColorChooser mainChooser_, backChooser_, ambientChooser_, fogChooser_;

	Node *mainLightNode_, *backLightNode_, *zoneNode_;
	Light *mainLight_, *backLight_;
	Zone *zone_;
	Material *skyboxmaterial_;
	float timeofday_{0.0f}, cloudtime_{0.f};

	void HandleSaveProject(StringHash eventType, VariantMap &eventData);
	void HandleLoadProject(StringHash eventType, VariantMap &eventData);
	void HandleClearProject(StringHash eventType, VariantMap &eventData);
	void HandleApplyTerrainSettings(StringHash eventType, VariantMap &eventData);
	void HandleShowColorChooser(StringHash eventType, VariantMap &eventData);
	void HandleHideColorChooser(StringHash eventType, VariantMap &eventData);
	void HandleUpdate(StringHash eventType, VariantMap &eventData);
	void HandlePickPath(StringHash eventType, VariantMap &eventData);
	void HandlePickPathConfirm(StringHash eventType, VariantMap &eventData);

	void Save(const ea::string &fullpath);
	void Load(const ea::string &fullpath);

	SharedPtr<FileSelector> CreateFileSelector(const ea::string &title, const ea::string &oktext, const ea::string &canceltext, const ea::string &initialPath);
};
