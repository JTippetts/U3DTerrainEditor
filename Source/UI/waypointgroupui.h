#pragma once

// Waypoint Group UI

#include <Urho3D/Core/Context.h>
#include <Urho3D/Core/Object.h>
#include <Urho3D/UI/UIElement.h>
#include <Urho3D/Resource/Image.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <Urho3D/UI/Text.h>
#include <Urho3D/UI/Window.h>
#include <Urho3D/UI/Menu.h>
#include <Urho3D/UI/UIElement.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <Urho3D/Graphics/CustomGeometry.h>
#include <Urho3D/Scene/Node.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Graphics/Material.h>
#include <vector>

class TerrainContext;
class EditingCamera;
using namespace Urho3D;

class WaypointGroup : public Object
{
	URHO3D_OBJECT(WaypointGroup, Object);
	public:
	WaypointGroup(Context *context);
	
	void Construct(Scene *scene, TerrainContext *tc);
	void SetVisible(bool v);
	bool IsVisible();
	
	void AddKnot(const Vector3 &pos);
	void RemoveLastKnot();
	void UpdateKnotHeights();
	void BuildRibbon();
	
	String name_;
	
	std::vector<Vector3> GetKnots();
	
	protected:
	Scene *scene_;
	TerrainContext *terrainContext_;
	
	bool visible_;
	Color ribbonColor_;
	std::vector<Node *> knots_;
	Node *ribbonNode_;
	CustomGeometry *ribbon_;
	Material *ribbonMat_, *knotMat_;
};

class WaypointGroupUI : public Object
{
	URHO3D_OBJECT(WaypointGroupUI, Object);
	public:
	WaypointGroupUI(Context *context);
	
	void Construct(Scene *scene, TerrainContext *tc, EditingCamera *cam);
	void SetVisible(bool v);
	bool IsVisible();
	
	std::vector<String> GetGroupNames();
	std::vector<Vector3> GetGroupKnots(const String &group);
	WaypointGroup *GetGroup(const String &name);
	
	void Save(JSONObject &json);
	void Load(const JSONObject &json);
	void Clear();
	
	protected:
	Scene *scene_;
	TerrainContext *terrainContext_;
	EditingCamera *camera_;
	
	SharedPtr<UIElement> element_;
	SharedPtr<Window> newGroupDlg_;
	WaypointGroup *selectedGroup_;
	
	std::vector<SharedPtr<WaypointGroup>> groups_;
	
	void HideGroup();
	void ActivateGroup(WaypointGroup* grp);
	
	SharedPtr<WaypointGroup> CreateWaypointGroup(const String &name);
	
	void HandleNewGroup(StringHash eventType, VariantMap &eventData);
	void HandleNewGroupAccept(StringHash eventType, VariantMap &eventData);
	void HandleNewGroupCancel(StringHash eventType, VariantMap &eventData);
	void HandleEditGroup(StringHash eventType, VariantMap &eventData);
	void HandleDeleteGroup(StringHash eventType, VariantMap &eventData);
	void HandleGroupSelected(StringHash eventType, VariantMap &eventData);
	
	void HandleUpdate(StringHash eventType, VariantMap &eventData);
};
