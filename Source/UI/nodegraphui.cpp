#include "nodegraphui.h"

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

#include <vector>
#include <algorithm>
#include "../terraincontext.h"

#include "nodedescriptors.h"

NodeGraphUI::NodeGraphUI(Context *context) : Object(context),
	createMenu_(nullptr),
	nodeGroupCounter_(0),
	selectedNodeGroup_(nullptr),
	link_(nullptr)
{
}

void NodeGraphUI::Construct(TerrainContext *tc)
{
	terrainContext_=tc;

	auto cache=GetSubsystem<ResourceCache>();
	XMLFile *style=cache->GetResource<XMLFile>("UI/DefaultStyle.xml");
	auto ui=GetSubsystem<UI>();
	auto graphics=GetSubsystem<Graphics>();

	element_=ui->GetRoot()->CreateChild<UIElement>();
	Text *closetext=element_->CreateChild<Text>();
	closetext->SetStyle("Text", style);
	closetext->SetFontSize(20);
	closetext->SetText("Press 'M' to close window.");
	element_->SetVisible(false);

	createMenu_=CreateNodeCreateMenu(ui->GetRoot()->GetChild("OnTop", true));
	createMenu_->SetBringToFront(true);
	createMenu_->SetVisible(false);

	cursorTarget_=SharedPtr<NodeGraphLinkDest>(new NodeGraphLinkDest(context_));
	nodeGroupsList_=ui->LoadLayout(cache->GetResource<XMLFile>("UI/NoiseNodeGroups.xml"), style);
	ui->GetRoot()->GetChild("Base",true)->AddChild(nodeGroupsList_);

	SubscribeToEvent(nodeGroupsList_->GetChild("New", true), StringHash("Pressed"), URHO3D_HANDLER(NodeGraphUI, HandleNewGroup));
	SubscribeToEvent(nodeGroupsList_->GetChild("Edit", true), StringHash("Pressed"), URHO3D_HANDLER(NodeGraphUI, HandleEditGroup));
	SubscribeToEvent(nodeGroupsList_->GetChild("Delete", true), StringHash("Pressed"), URHO3D_HANDLER(NodeGraphUI, HandleDeleteGroup));

	SubscribeToEvent(nodeGroupsList_->GetChild("List", true), StringHash("ItemSelected"), URHO3D_HANDLER(NodeGraphUI, HandleGroupSelected));
	nodeGroupsList_->SetPosition(IntVector2(0,graphics->GetHeight()-nodeGroupsList_->GetHeight()));
	nodeGroupsList_->SetVisible(false);

	element_->SetSize(IntVector2(graphics->GetWidth()-nodeGroupsList_->GetWidth(), graphics->GetHeight()-64));
	createMenu_->SetPosition(IntVector2(0,64));
	element_->SetPosition(IntVector2(nodeGroupsList_->GetWidth(), 64));

	SubscribeToEvent(StringHash("Update"), URHO3D_HANDLER(NodeGraphUI, HandleUpdate));
}

void NodeGraphUI::SetVisible(bool vis)
{
	if(vis)
	{
		nodeGroupsList_->SetVisible(true);
	}
	else
	{
		nodeGroupsList_->SetVisible(false);
		createMenu_->SetVisible(false);
		if(selectedNodeGroup_)
		{
			HideGroup();
		}
	}
}

SharedPtr<Text> NodeGraphUI::CreateAccelKeyText(int accelKey)
{
	auto cache=GetSubsystem<ResourceCache>();
	XMLFile *style=cache->GetResource<XMLFile>("UI/DefaultStyle.xml");

	SharedPtr<Text> accelKeyText=SharedPtr<Text>(new Text(context_));
	accelKeyText->SetStyle("EditorMenuText", style);
	accelKeyText->SetTextAlignment(HA_RIGHT);

	String text;
	if(accelKey==KEY_DELETE) text="Del";
	else if(accelKey==KEY_SPACE) text="Space";
	else if(accelKey==KEY_F1) text="F1";
	else if(accelKey==KEY_F2) text="F2";
	else if(accelKey==KEY_F3) text="F3";
	else if(accelKey==KEY_F4) text="F4";
	else if(accelKey==KEY_F5) text="F5";
	else if(accelKey==KEY_F6) text="F6";
	else if(accelKey==KEY_F7) text="F7";
	else if(accelKey==KEY_F8) text="F8";
	else if(accelKey==KEY_F9) text="F9";
	else if(accelKey==KEY_F10) text="F10";
	else if(accelKey==KEY_F11) text="F11";
	else if(accelKey==KEY_F12) text="F12";
	else if(accelKey==-1) text=">";
	else if(accelKey!=0) text.AppendUTF8(accelKey);
	accelKeyText->SetText(text);
	return accelKeyText;
}

SharedPtr<Menu> NodeGraphUI::CreateMenuItem(const String &title, int accelKey)
{
	auto cache=GetSubsystem<ResourceCache>();
	XMLFile *style=cache->GetResource<XMLFile>("UI/DefaultStyle.xml");

	SharedPtr<Menu> menu=SharedPtr<Menu>(new Menu(context_));
	menu->SetStyleAuto(style);
	menu->SetLayout(LM_HORIZONTAL, 0, IntRect(8,2,8,2));
	Text *text=menu->CreateChild<Text>("Text");
	text->SetStyle("EditorMenuText", style);
	text->SetText(title);

	if(accelKey != 0)
	{
		UIElement *spacer=menu->CreateChild<UIElement>();
		spacer->SetMinWidth(text->GetIndentSpacing());
		spacer->SetHeight(text->GetHeight());
		menu->AddChild(CreateAccelKeyText(accelKey));
	}

	return menu;
}

SharedPtr<Window> NodeGraphUI::CreatePopup(Menu *baseMenu)
{
	auto cache=GetSubsystem<ResourceCache>();
	XMLFile *style=cache->GetResource<XMLFile>("UI/DefaultStyle.xml");

	SharedPtr<Window> popup(new Window(context_));
	popup->SetStyleAuto(style);
	popup->SetLayout(LM_VERTICAL, 1, IntRect(2,6,2,6));
	baseMenu->SetPopup(popup);
	baseMenu->SetPopupOffset(IntVector2(baseMenu->GetWidth(), 0));
	return popup;
}

SharedPtr<Menu> NodeGraphUI::CreateMenu(const String &title)
{
	auto menu=CreateMenuItem(title);
	CreatePopup(menu);
	return menu;
}

SharedPtr<UIElement> NodeGraphUI::CreateNodeCreateMenu(UIElement *parent)
{
	auto cache=GetSubsystem<ResourceCache>();
	XMLFile *style=cache->GetResource<XMLFile>("UI/DefaultStyle.xml");
	auto ui=GetSubsystem<UI>();

	SharedPtr<UIElement> menu=ui->LoadLayout(cache->GetResource<XMLFile>("UI/CreateNodeButton.xml"), style);
	Menu *mn=menu->GetChildDynamicCast<Menu>("Menu", true);

	SharedPtr<Window> pop=CreatePopup(mn);

	struct NodeCategory
	{
		String name_;
		std::vector<String> entries_;
	};

	std::vector<NodeCategory> nodecategories
	{
		{
			"combine",
			{
				"add",
				"subtract",
				"multiply",
				"divide",
				"pow",
				"minimum",
				"maximum",
				"bias",
				"gain",
				"mix",
				"dx",
				"dy",
				"fractal"
			}
		},
		{
			"scalarmath",
			{
				"abs",
				"sin",
				"cos",
				"tan",
				"asin",
				"acos",
				"atan",
				"sigmoid",
				"randomize"
			}
		},
		{
			"step",
			{
				"step",
				"linearStep",
				"smoothStep",
				"smootherStep",
				"tiers",
				"smoothTiers",
				"curveSection",
			}
		},
		{
			"basis",
			{
				"constant",
				"seed",
				"valueBasis",
				"gradientBasis",
				"simplexBasis",
				"cellularBasis",
				"x",
				"y",
				"radial",
				"seeder"
			}
		},
		{
			"transform",
			{
				"scaleDomain",
				"scaleX",
				"scaleY",
				"translateDomain",
				"translateX",
				"translateY",
				"rotateDomain"
			}
		},
		{
			"color",
			{
				"combineRGBA",
				"combineHSVA"
			}
		}
	};

	for(auto &nc : nodecategories)
	{
		String i=nc.name_;
		const std::vector<String> &c=nc.entries_;
		SharedPtr<Menu> mi=CreateMenuItem(i, -1);
		pop->AddChild(mi);

		SharedPtr<Window> childpop=CreatePopup(mi);
		for(auto &f : c)
		{
			SharedPtr<Menu> ni=CreateMenuItem(f,0);
			childpop->AddChild(ni);
			SubscribeToEvent(ni, StringHash("MenuSelected"), URHO3D_HANDLER(NodeGraphUI, HandleMenuSelected));
		}
	}

	parent->AddChild(menu);
	return menu;
}

void NodeGraphUI::SubscribeLinkPoints(UIElement *e, int numinputs)
{
	NodeGraphLinkSource *output=e->GetChildDynamicCast<NodeGraphLinkSource>("Output0", true);
	if(output)
	{
		SubscribeToEvent(output, StringHash("DragBegin"), URHO3D_HANDLER(NodeGraphUI, HandleOutputDragBegin));
		SubscribeToEvent(output, StringHash("DragEnd"), URHO3D_HANDLER(NodeGraphUI, HandleDragEnd));
		output->SetRoot(e);
	}

	for(int c=0; c<numinputs; ++c)
	{
		NodeGraphLinkDest *input=e->GetChildDynamicCast<NodeGraphLinkDest>(String("Input")+String(c), true);
		if(input)
		{
			SubscribeToEvent(input, StringHash("DragBegin"), URHO3D_HANDLER(NodeGraphUI, HandleInputDragBegin));
			SubscribeToEvent(input, StringHash("DragEnd"), URHO3D_HANDLER(NodeGraphUI, HandleDragEnd));
			input->SetRoot(e);
		}
	}
}

void NodeGraphUI::RemoveLinkPoints(UIElement *e)
{
	if(!selectedNodeGroup_) return;

	// Count inputs
	int numinputs=0;
	UIElement *inputs=e->GetChild("Inputs", true);
	if(inputs)
	{
		const Vector<SharedPtr<UIElement>> &children=inputs->GetChildren();
		for(int c=0; c<children.Size(); ++c)
		{
			NodeGraphLinkDest *input=children[c]->GetChildDynamicCast<NodeGraphLinkDest>(0);
			if(input)
			{
				auto link=input->GetLink();
				if(link)
				{
					selectedNodeGroup_->linkPane_->RemoveLink(link);
				}
			}
		}
	}

	NodeGraphLinkSource *output=e->GetChildDynamicCast<NodeGraphLinkSource>("Output0", true);
	if(output)
	{
		int numlinks=output->GetNumLinks();
		for(int c=0; c<numlinks; ++c)
		{
			auto link=output->GetLink(c);
			if(link)
			{
				selectedNodeGroup_->linkPane_->RemoveLink(link);
			}
		}
	}
}

void NodeGraphUI::HideGroup()
{
	if(selectedNodeGroup_)
	{
		selectedNodeGroup_->pane_->SetVisible(false);
		selectedNodeGroup_->pane_->SetFocus(false);
	}
	element_->SetVisible(false);
}

void NodeGraphUI::ActivateGroup(NodeGroup *grp)
{
	if(selectedNodeGroup_)
	{
		selectedNodeGroup_->pane_->SetVisible(false);
		selectedNodeGroup_->pane_->SetFocus(false);
	}
	selectedNodeGroup_=grp;
	if(grp)
	{
		grp->pane_->SetVisible(true);
		//grp->pane_->SetFocus(true);
		element_->SetVisible(true);
		createMenu_->SetVisible(true);
		createMenu_->SetFocus(true);
	}
}

NodeGroup *NodeGraphUI::CreateNodeGroup(const String &name)
{
	auto cache=GetSubsystem<ResourceCache>();
	XMLFile *style=cache->GetResource<XMLFile>("UI/NodeStyle.xml");
	auto ui=GetSubsystem<UI>();
	auto graphics=GetSubsystem<Graphics>();

	NodeGroup grp;

	grp.pane_=ui->GetRoot()->GetChild("Base",true)->CreateChild<Window>();
	grp.pane_->SetSize(IntVector2(graphics->GetWidth()*2, graphics->GetHeight()*2));
	grp.pane_->SetPosition(IntVector2(-graphics->GetWidth()/2-128, -graphics->GetHeight()/2));
	grp.pane_->SetImageRect(IntRect(208,0,223,15));
	grp.pane_->SetImageBorder(IntRect(4,4,4,4));
	grp.pane_->SetTexture(cache->GetResource<Texture2D>("Textures/UI_modified.png"));
	grp.pane_->SetOpacity(0.75f);
	//grp.pane_->SetBringToFront(true);
	grp.pane_->SetMovable(true);
	grp.pane_->SetClipChildren(false);
	grp.pane_->SetDefaultStyle(style);

	grp.linkPane_=grp.pane_->CreateChild<NodeGraphLinkPane>();
	grp.linkPane_->SetSize(IntVector2(graphics->GetWidth()*2, graphics->GetHeight()*2));
	grp.linkPane_->SetVisible(true);
	grp.linkPane_->SetTexture(cache->GetResource<Texture2D>("Textures/UI_modified.png"));

	grp.previewTex_=SharedPtr<Texture2D>(new Texture2D(context_));
	grp.previewImage_=SharedPtr<Image>(new Image(context_));
	grp.previewImage_->SetSize(256,256,3);
	grp.previewImage_->Clear(Color(0,0,0));
	grp.previewTex_->SetData(grp.previewImage_, false);

	grp.histoTex_=SharedPtr<Texture2D>(new Texture2D(context_));
	grp.histoImage_=SharedPtr<Image>(new Image(context_));
	grp.histoImage_->SetSize(256,256,3);
	grp.histoImage_->Clear(Color(0,0,0));
	grp.histoTex_->SetData(grp.histoImage_, false);

	grp.output_=ui->LoadLayout(cache->GetResource<XMLFile>("UI/OutputNode.xml"), cache->GetResource<XMLFile>("UI/DefaultStyle.xml"));
	grp.output_->SetVisible(true);
	SubscribeLinkPoints(grp.output_,1);
	grp.pane_->AddChild(grp.output_);
	grp.output_->GetChildDynamicCast<BorderImage>("Preview", true)->SetTexture(grp.previewTex_);
	grp.output_->GetChildDynamicCast<BorderImage>("Histogram", true)->SetTexture(grp.histoTex_);
	grp.output_->SetPosition(IntVector2(-grp.pane_->GetPosition().x_ + graphics->GetWidth()-grp.output_->GetWidth(), -grp.pane_->GetPosition().y_ + graphics->GetHeight()/4));

	std::vector<String> smtypes
	{
		"Terrain",
		"Layer 1",
		"Layer 2",
		"Layer 3",
		"Layer 4",
		"Layer 5",
		"Layer 6",
		"Layer 7",
		"Layer 8",
		"Mask 1",
		"Mask 2",
		"Mask 3",
		"Water"
	};

	DropDownList *list=grp.output_->GetChildDynamicCast<DropDownList>("TargetList", true);
	for(auto &c : smtypes)
	{
		SharedPtr<Text> t(new Text(context_));
		t->SetFont(cache->GetResource<Font>("Fonts/Anonymous Pro.ttf"), 9);
		t->SetText(c);
		t->SetMinSize(IntVector2(0,16));
		list->AddItem(t);
	}
	list->SetSelection(0);

	list=grp.output_->GetChildDynamicCast<DropDownList>("BlendOpList", true);
	std::vector<String> bops
	{
		"Replace",
		"Add",
		"Subtract",
		"Multiply",
		"Min",
		"Max"
	};

	for(auto &c : bops)
	{
		SharedPtr<Text> t(new Text(context_));
		t->SetFont(cache->GetResource<Font>("Fonts/Anonymous Pro.ttf"), 9);
		t->SetText(c);
		t->SetMinSize(IntVector2(0,16));
		list->AddItem(t);
	}
	list->SetSelection(0);

	SubscribeToEvent(grp.output_->GetChild("Generate", true), StringHash("Pressed"), URHO3D_HANDLER(NodeGraphUI, HandleGenerate));
	SubscribeToEvent(grp.output_->GetChild("Execute", true), StringHash("Pressed"), URHO3D_HANDLER(NodeGraphUI, HandleExecute));
	SubscribeToEvent(grp.output_->GetChild("Store", true), StringHash("Pressed"), URHO3D_HANDLER(NodeGraphUI, HandleStore));
	grp.pane_->SetVisible(false);

	ListView *nlist=nodeGroupsList_->GetChildDynamicCast<ListView>("List", true);
	unsigned int sel=nlist->GetSelection();

	SharedPtr<Text> t(new Text(context_));
	t->SetStyle("FileSelectorListText", cache->GetResource<XMLFile>("UI/DefaultStyle.xml"));
	t->SetText(name);
	nlist->AddItem(t);
	nlist->SetSelection(nlist->GetNumItems()-1);
	grp.name_=name;
	nodeGroups_.push_back(grp);
	return &nodeGroups_[nodeGroups_.size()-1];
}

SharedPtr<UIElement> NodeGraphUI::CreateNodeType(UIElement *parent, const String &type)
{
	auto ui=GetSubsystem<UI>();
	auto cache=GetSubsystem<ResourceCache>();
	XMLFile *style=cache->GetResource<XMLFile>("UI/DefaultStyle.xml");
	
	if(type=="seed")
	{
		SharedPtr<UIElement> n=ui->LoadLayout(cache->GetResource<XMLFile>("UI/SeedNode.xml"),style);
		parent->AddChild(n);
		return n;
	}
	else if(type=="constant")
	{
		SharedPtr<UIElement> n=ui->LoadLayout(cache->GetResource<XMLFile>("UI/ConstantNode.xml"),style);
		parent->AddChild(n);
		return n;
	}
	
	NodeTypeDesc *d=GetNodeTypeDesc(type);
	if(!d) return SharedPtr<UIElement>();
	
	SharedPtr<UIElement> node=ui->LoadLayout(cache->GetResource<XMLFile>("UI/NodeTemplate.xml"),style);
	node->SetName(type);
	parent->AddChild(node);
	node->GetChildDynamicCast<Text>("Title", true)->SetText(type);
	UIElement *inputs=node->GetChild("Inputs", true);
	
	for(unsigned int c=0; c<d->inputs_.size(); ++c)
	{
		UIElement *input=inputs->CreateChild<UIElement>(d->inputs_[c].type_);
		input->SetLayout(LM_HORIZONTAL);
		NodeGraphLinkDest *e=input->CreateChild<NodeGraphLinkDest>(String("Input")+String(c));
		e->SetMinSize(IntVector2(12,12));
		e->SetMaxSize(IntVector2(12,12));
		e->SetImageRect(IntRect(16,0,32,16));
		e->SetTexture(cache->GetResource<Texture2D>("Textures/UI_modified.png"));
		
		LineEdit *le=input->CreateChild<LineEdit>(String("Value")+String(c));
		le->SetStyleAuto(style);
		le->GetTextElement()->SetFontSize(9);
		le->SetText(String(d->inputs_[c].value_));
		le->SetMinSize(IntVector2(40,12));
		le->SetMaxSize(IntVector2(40,12));
		
		Text *t=input->CreateChild<Text>();
		t->SetStyleAuto(style);
		t->SetFontSize(9);
		t->SetText(d->inputs_[c].name_);
	}
	return node;
}

SharedPtr<UIElement> NodeGraphUI::BuildNode(NodeGroup *grp, const String &type)
{
	auto e=CreateNodeType(grp->pane_, type);
	NodeTypeDesc *d=GetNodeTypeDesc(type);
	if(!d) return SharedPtr<UIElement>();
	
	if(e)
	{
		SubscribeLinkPoints(e, d->inputs_.size());
	}
	SubscribeToEvent(e->GetChild("Close", true), StringHash("Pressed"), URHO3D_HANDLER(NodeGraphUI, HandleCloseNode));
	return e;
}

NodeTypeDesc *NodeGraphUI::GetNodeTypeDesc(const String &type)
{
	for(unsigned int c=0; c<g_nodeTypes.size(); ++c)
	{
		if(g_nodeTypes[c].name_==type) return &g_nodeTypes[c];
	}
	return nullptr;
}

void NodeGraphUI::HandleMenuSelected(StringHash eventType, VariantMap &eventData)
{
	auto graphics=GetSubsystem<Graphics>();
	Menu *menu=static_cast<Menu *>(eventData["Element"].GetPtr());
	if(!menu) return;
	
	Text *text=menu->GetChildDynamicCast<Text>("Text", true);
	if(text)
	{
		createMenu_->GetChildDynamicCast<Menu>("Menu", true)->ShowPopup(false);
		if(!selectedNodeGroup_) return;
		
		SharedPtr<UIElement> n=BuildNode(selectedNodeGroup_, text->GetText());
		if(!n) return;
		
		n->SetPosition(IntVector2(-selectedNodeGroup_->pane_->GetPosition().x_ + graphics->GetWidth()/2, -selectedNodeGroup_->pane_->GetPosition().y_ + graphics->GetHeight()/2));
		selectedNodeGroup_->nodes_.push_back(n);
	}
}

void NodeGraphUI::HandleNewGroup(StringHash eventType, VariantMap &eventData)
{
	auto cache=GetSubsystem<ResourceCache>();
	XMLFile *style=cache->GetResource<XMLFile>("UI/DefaultStyle.xml");
	auto ui=GetSubsystem<UI>();
	auto graphics=GetSubsystem<Graphics>();

	newNodeGroupDlg_=DynamicCast<Window>(ui->LoadLayout(cache->GetResource<XMLFile>("UI/NewNodeGroupDlg.xml"), style));
	ui->GetRoot()->GetChild("Base",true)->AddChild(newNodeGroupDlg_);
	newNodeGroupDlg_->SetModal(true);

	SubscribeToEvent(newNodeGroupDlg_->GetChild("OK", true), StringHash("Pressed"), URHO3D_HANDLER(NodeGraphUI, HandleNewGroupAccept));
	SubscribeToEvent(newNodeGroupDlg_->GetChild("Close", true), StringHash("Pressed"), URHO3D_HANDLER(NodeGraphUI, HandleNewGroupCancel));
	SubscribeToEvent(newNodeGroupDlg_->GetChild("Cancel", true), StringHash("Pressed"), URHO3D_HANDLER(NodeGraphUI, HandleNewGroupCancel));

	newNodeGroupDlg_->SetPosition(IntVector2(graphics->GetWidth()/2-newNodeGroupDlg_->GetWidth()/2, graphics->GetHeight()/2-newNodeGroupDlg_->GetHeight()/2));
	ui->SetFocusElement(newNodeGroupDlg_->GetChild("GroupName", true), false);
}

void NodeGraphUI::HandleNewGroupAccept(StringHash eventType, VariantMap &eventData)
{
	NodeGroup *g;
	String name=newNodeGroupDlg_->GetChildDynamicCast<LineEdit>("GroupName", true)->GetText();
	for(unsigned int c=0; c<nodeGroups_.size(); ++c)
	{
		NodeGroup *g=&nodeGroups_[c];
		if(g->name_==name)
		{
			newNodeGroupDlg_->GetChildDynamicCast<Text>("Status",true)->SetText("Group already exists!");
			return;
		}
	}

	if(name=="")
	{
		newNodeGroupDlg_->GetChildDynamicCast<Text>("Status",true)->SetText("Please enter a name for the group.");
		return;
	}

	HideGroup();
	selectedNodeGroup_=CreateNodeGroup(name);
	ActivateGroup(selectedNodeGroup_);

	newNodeGroupDlg_->Remove();
	newNodeGroupDlg_.Reset();

}

void NodeGraphUI::HandleNewGroupCancel(StringHash eventType, VariantMap &eventData)
{
	if(newNodeGroupDlg_)
	{
		newNodeGroupDlg_->Remove();
		newNodeGroupDlg_.Reset();
	}
}

void NodeGraphUI::HandleEditGroup(StringHash eventType, VariantMap &eventData)
{
	if(!nodeGroupsList_) return;

	int which=nodeGroupsList_->GetChildDynamicCast<ListView>("List", true)->GetSelection();
	if(which==-1) return;
	if(which>=nodeGroups_.size()) return;
	NodeGroup *grp=&nodeGroups_[which];
	ActivateGroup(grp);
}

void NodeGraphUI::HandleDeleteGroup(StringHash eventType, VariantMap &eventData)
{
}

void NodeGraphUI::HandleGroupSelected(StringHash eventType, VariantMap &eventData)
{
	if(!nodeGroupsList_) return;

	int which=nodeGroupsList_->GetChildDynamicCast<ListView>("List", true)->GetSelection();
	if(which==-1) return;
	if(which>=nodeGroups_.size()) return;
	NodeGroup *grp=&nodeGroups_[which];
	ActivateGroup(grp);
}

void NodeGraphUI::HandleGenerate(StringHash eventType, VariantMap &eventData)
{
}

void NodeGraphUI::HandleExecute(StringHash eventType, VariantMap &eventData)
{
}

void NodeGraphUI::HandleStore(StringHash eventType, VariantMap &eventData)
{
}

void NodeGraphUI::HandleInputDragBegin(StringHash eventType, VariantMap &eventData)
{
	if(link_)
	{
		// Destroy stale link
		selectedNodeGroup_->linkPane_->RemoveLink(link_);
	}
	
	NodeGraphLinkDest *element=static_cast<NodeGraphLinkDest *>(eventData["Element"].GetPtr());
	if(element)
	{
		NodeGraphLink *link=element->GetLink();
		if(link)
		{
			link_=link;
			link->SetTarget(cursorTarget_);
			element->ClearLink();
		}
	}
}

void NodeGraphUI::HandleOutputDragBegin(StringHash eventType, VariantMap &eventData)
{
	if(link_)
	{
		// Destroy stale link
		selectedNodeGroup_->linkPane_->RemoveLink(link_);
	}
	
	if(!selectedNodeGroup_) return;
	NodeGraphLinkSource *element=static_cast<NodeGraphLinkSource *>(eventData["Element"].GetPtr());
	if(!element) return;
	
	link_=selectedNodeGroup_->linkPane_->CreateLink(element, cursorTarget_);
	link_->SetImageRect(IntRect(193,81,207,95));
}

void NodeGraphUI::HandleDragEnd(StringHash eventType, VariantMap &eventData)
{
	auto ui=GetSubsystem<UI>();
	auto input=GetSubsystem<Input>();
	
	if(!link_) return;
	if(!selectedNodeGroup_) return;
	
	IntVector2 mousepos=input->GetMousePosition();
	UIElement *at=ui->GetElementAt(mousepos);
	if(at)
	{
		String atname=at->GetName();
		if(atname.Substring(0,5)=="Input")
		{
			NodeGraphLinkDest *atld=dynamic_cast<NodeGraphLinkDest *>(at);
			if(!atld)
			{
				selectedNodeGroup_->linkPane_->RemoveLink(link_);
				link_=nullptr;
				return;
			}
			
			NodeGraphLink *thislink=atld->GetLink();
			if(thislink)
			{
				selectedNodeGroup_->linkPane_->RemoveLink(thislink);
			}
			link_->SetTarget(atld);
			link_=nullptr;
			return;
		}
	}
	
	selectedNodeGroup_->linkPane_->RemoveLink(link_);
	link_=nullptr;
}

void NodeGraphUI::HandleUpdate(StringHash eventType, VariantMap &eventData)
{
	if(!element_ || !element_->IsVisible()) return;

	auto input=GetSubsystem<Input>();

	IntVector2 mousepos=input->GetMousePosition();

	if(cursorTarget_) cursorTarget_->SetPosition(mousepos);

	if(input->GetKeyPress(KEY_M))
	{
		HideGroup();
		createMenu_->SetVisible(false);
	}
}
void NodeGraphUI::HandleCloseNode(StringHash eventType, VariantMap &eventData)
{
	if(!selectedNodeGroup_) return;
	
	UIElement *e=static_cast<UIElement *>(eventData["Element"].GetPtr());
	if(!e) return;
	e=e->GetParent()->GetParent(); // Get owning node widget
	if(e)
	{
		RemoveLinkPoints(e);
	}
	
	for(unsigned int c=0; c<selectedNodeGroup_->nodes_.size(); ++c)
	{
		auto i=selectedNodeGroup_->nodes_[c];
		if(i.Get()==e)
		{
			std::swap(selectedNodeGroup_->nodes_[c], selectedNodeGroup_->nodes_[selectedNodeGroup_->nodes_.size()-1]);
			selectedNodeGroup_->nodes_.pop_back();
			e->Remove();
			return;
		}
	}
}
