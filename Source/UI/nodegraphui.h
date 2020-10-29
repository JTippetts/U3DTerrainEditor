#pragma once

// NodeGraphUI

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
#include <vector>

#include "../NodeGraphLink.h"
#include "../../ThirdParty/accidental-noise-library/anl.h"

using namespace anl;

using namespace Urho3D;

class NodeTypeDesc;

struct NodeGroup
{
	String name_;
	SharedPtr<Window> pane_;
	SharedPtr<NodeGraphLinkPane> linkPane_;
	SharedPtr<Texture2D> previewTex_, histoTex_;
	SharedPtr<UIElement> output_;
	SharedPtr<Image> previewImage_, histoImage_;
	std::vector<SharedPtr<UIElement>> nodes_;
};

class TerrainContext;
class NodeGraphUI : public Object
{
	URHO3D_OBJECT(NodeGraphUI, Object);
	public:
	NodeGraphUI(Context *context);
	
	void Construct(TerrainContext *tc);
	void SetVisible(bool vis);
	bool IsVisible(){if(element_) return element_->IsVisible(); return false;}
	
	protected:
	
	TerrainContext *terrainContext_;
	
	SharedPtr<UIElement> element_;
	SharedPtr<UIElement> createMenu_;
	SharedPtr<NodeGraphLinkDest> cursorTarget_;
	SharedPtr<UIElement> nodeGroupsList_;
	SharedPtr<Window> newNodeGroupDlg_;
	
	
	unsigned int nodeGroupCounter_;
	std::vector<NodeGroup> nodeGroups_;
	NodeGroup *selectedNodeGroup_;
	NodeGraphLink *link_;
	
	SharedPtr<Text> CreateAccelKeyText(int accelKey=0);
	SharedPtr<Menu> CreateMenuItem(const String &title, int accelKey=0);
	SharedPtr<Window> CreatePopup(Menu *baseMenu);
	SharedPtr<Menu> CreateMenu(const String &title);
	SharedPtr<UIElement> CreateNodeCreateMenu(UIElement *parent);
	
	void HideGroup();
	NodeGroup *CreateNodeGroup(const String &name);
	void ActivateGroup(NodeGroup *grp);
	void SubscribeLinkPoints(UIElement *e, int numinputs);
	void RemoveLinkPoints(UIElement *e);
	SharedPtr<UIElement> CreateNodeType(UIElement *parent, const String &type);
	SharedPtr<UIElement> BuildNode(NodeGroup *grp, const String &type);
	NodeTypeDesc *GetNodeTypeDesc(const String &type);
	UIElement *GetSourceFromNode(UIElement *node, const String &inputname);
	//CInstructionIndex InstanceFunction(CKernel &kernel, NodeTypeDesc *desc, std::vector<CInstructionIndex> &params);
	//void BuildANLFunction(CKernel &kernel, UIElement *output);
	void BuildANLFunction2(CKernel &kernel, UIElement *output);
	
	void HandleMenuSelected(StringHash eventType, VariantMap &eventData);
	void HandleNewGroup(StringHash eventType, VariantMap &eventData);
	void HandleNewGroupAccept(StringHash eventType, VariantMap &eventData);
	void HandleNewGroupCancel(StringHash eventType, VariantMap &eventData);
	void HandleEditGroup(StringHash eventType, VariantMap &eventData);
	void HandleDeleteGroup(StringHash eventType, VariantMap &eventData);
	void HandleGroupSelected(StringHash eventType, VariantMap &eventData);
	void HandleGenerate(StringHash eventType, VariantMap &eventData);
	void HandleExecute(StringHash eventType, VariantMap &eventData);
	void HandleStore(StringHash eventType, VariantMap &eventData);
	void HandleInputDragBegin(StringHash eventType, VariantMap &eventData);
	void HandleOutputDragBegin(StringHash eventType, VariantMap &eventData);
	void HandleDragEnd(StringHash eventType, VariantMap &eventData);
	void HandleUpdate(StringHash eventType, VariantMap &eventData);
	void HandleCloseNode(StringHash eventType, VariantMap &eventData);
};
