#define ANL_IMPLEMENTATION
#define ANL_LONG_PERIOD_HASHING

#include "nodegraphui.h"
#include "../anlutilities.h"

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

#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>

#include "../terraincontext.h"

#include "nodedescriptors.h"
#include "../format.h"
#include "../filesaveload.h"
#include "../jsonutilities.h"

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
	SubscribeToEvent(nodeGroupsList_->GetChild("Map", true), StringHash("Pressed"), URHO3D_HANDLER(NodeGraphUI, HandleMapGroup));

	SubscribeToEvent(nodeGroupsList_->GetChild("List", true), StringHash("ItemSelected"), URHO3D_HANDLER(NodeGraphUI, HandleGroupSelected));
	nodeGroupsList_->SetPosition(IntVector2(0,graphics->GetHeight()-nodeGroupsList_->GetHeight()));
	nodeGroupsList_->SetVisible(false);

	element_->SetSize(IntVector2(graphics->GetWidth()-nodeGroupsList_->GetWidth(), graphics->GetHeight()-64));
	createMenu_->SetPosition(IntVector2(0,64));
	element_->SetPosition(IntVector2(nodeGroupsList_->GetWidth(), 64));

	SubscribeToEvent(StringHash("Update"), URHO3D_HANDLER(NodeGraphUI, HandleUpdate));
}

void NodeGraphUI::Save(JSONObject &json)
{
	auto graphics=GetSubsystem<Graphics>();
	
	JSONObject settings;
	
	auto FindSourceIndex=[&](const NodeGroup &group, NodeGraphLinkSource *e)->unsigned int
	{
		UIElement *s=e->GetRoot();
		
		for(unsigned int c=0; c<group.nodes_.size(); ++c)
		{
			if(s==group.nodes_[c]) return c;
		}
		return 0;
	};
	
	JSONArray grouparr;
	for(auto &g : nodeGroups_)
	{
		JSONObject jgrp;
		jgrp["Name"]=g.name_;
		JSONArray jnodes;
		for(auto &n : g.nodes_)
		{
			// Store Type, Position, and Input Value constants.
			JSONObject jnd;
			IntVector2 cpos(-g.pane_->GetPosition().x_ + graphics->GetWidth()/2, -g.pane_->GetPosition().y_ + graphics->GetHeight()/2);
			jnd["Position"]=JSONFromIntVector2(n->GetPosition());
			jnd["Type"]=n->GetName();
			
			JSONArray jcons;
			UIElement *inputs=n->GetChild("Inputs", true);
			if(inputs)
			{
				const Vector<SharedPtr<UIElement>> &children=inputs->GetChildren();
				for(int c=0; c<children.Size(); ++c)
				{
					LineEdit *val=children[c]->GetChildDynamicCast<LineEdit>(1);
					if(val)
					{
						jcons.Push(JSONValue(val->GetText()));
					}
				}
			}
			jnd["InputValues"]=jcons;
			jnodes.Push(jnd);
		}
		jgrp["Nodes"]=jnodes;
		
		// Save links
		JSONArray jlinks;
		//for(auto &n : g.nodes_)
		for(unsigned int nd=0; nd<g.nodes_.size(); ++nd)
		{
			UIElement *n=g.nodes_[nd];
			UIElement *inputs=n->GetChild("Inputs", true);
			if(inputs)
			{
				const Vector<SharedPtr<UIElement>> &children=inputs->GetChildren();
				for(int c=0; c<children.Size(); ++c)
				{
					NodeGraphLinkDest *input=children[c]->GetChildDynamicCast<NodeGraphLinkDest>(0);
					if(input)
					{
						NodeGraphLink *lnk=input->GetLink();
						if(lnk)
						{
							NodeGraphLinkSource *src=lnk->GetSource();
							if(src)
							{
								JSONObject jlnk;
								jlnk["DestNodeIndex"]=nd;
								jlnk["DestNodeValueIndex"]=c;
								jlnk["SourceNodeIndex"]=FindSourceIndex(g, src);
								jlinks.Push(jlnk);
							}
						}
					}
				}
			}
		}
		
		jgrp["Links"]=jlinks;
		
		JSONObject outputlink;
		NodeGraphLinkDest *op=g.output_->GetChildDynamicCast<NodeGraphLinkDest>("Input0", true);
		if(op)
		{
			NodeGraphLink *lnk=op->GetLink();
			if(lnk)
			{
				NodeGraphLinkSource *src=lnk->GetSource();
				if(src)
				{
					outputlink["SourceNodeIndex"]=FindSourceIndex(g, src);
				}
			}
			else URHO3D_LOGINFO("No link on output node.");
		}
		else URHO3D_LOGINFO("Could not obtain input for output node.");
		
		jgrp["OutputLink"]=outputlink;
		grouparr.Push(jgrp);
	}
	
	settings["Groups"]=grouparr;
	
	json["NodeGroups"]=settings;
}

void NodeGraphUI::Load(const JSONObject &json)
{
	auto ui=GetSubsystem<UI>();
	auto graphics=GetSubsystem<Graphics>();
	// Remove groups
	Clear();
	
	if(json["NodeGroups"] && json["NodeGroups"]->IsObject())
	{
		const JSONObject &settings=json["NodeGroups"]->GetObject();
		if(settings["Groups"] && settings["Groups"]->IsArray())
		{
			const JSONArray &grouparr=settings["Groups"]->GetArray();
			for(unsigned int c=0; c<grouparr.Size(); ++c)
			{
				if(grouparr[c].IsObject())
				{
					const JSONObject &jgrp=grouparr[c].GetObject();
					const String &groupname=jgrp["Name"]->GetString();
					NodeGroup *group=CreateNodeGroup(groupname);
					if(group)
					{
						if(jgrp["Nodes"] && jgrp["Nodes"]->IsArray())
						{
							const JSONArray &jnodes=jgrp["Nodes"]->GetArray();
							for(unsigned int d=0; d<jnodes.Size(); ++d)
							{
								const JSONObject &jnd=jnodes[d].GetObject();
								IntVector2 pos=IntVector2FromJSON(*jnd["Position"]);
								const String &type=jnd["Type"]->GetString();
								
								SharedPtr<UIElement> node=BuildNode(group, type);
								if(node)
								{
									group->nodes_.push_back(node);
									node->SetPosition(pos);
									URHO3D_LOGINFO(String("pos: ") + String(pos.x_) + ", " + String(pos.y_));
									//IntVector2 cpos(-group->pane_->GetPosition().x_ + graphics->GetWidth()/2, -group->pane_->GetPosition().y_ + graphics->GetHeight()/2);
									//node->SetPosition(pos+cpos);
									const JSONArray &jcons=jnd["InputValues"]->GetArray();
									for(unsigned int e=0; e<jcons.Size(); ++e)
									{
										LineEdit *val=node->GetChildDynamicCast<LineEdit>(String("Value")+String(e), true);
										if(val)
										{
											val->SetText(String(jcons[e].GetString()));
										}
										else URHO3D_LOGINFO(String("Could not obtain input ") + String(e));
									}
								}
								else URHO3D_LOGINFO(String("Could not create node of type ")+type);
							}
						}
						else URHO3D_LOGINFO("Nodes is not an array.");
						
						// Load links
						if(jgrp["Links"] && jgrp["Links"]->IsArray())
						{
							const JSONArray &jlinks=jgrp["Links"]->GetArray();
							for(unsigned int d=0; d<jlinks.Size(); ++d)
							{
								const JSONObject &jlnk=jlinks[d].GetObject();
								int dest=jlnk["DestNodeIndex"]->GetInt();
								int src=jlnk["SourceNodeIndex"]->GetInt();
								int destval=jlnk["DestNodeValueIndex"]->GetInt();
								
								if(dest>=0 && dest<group->nodes_.size() && src>=0 && src<group->nodes_.size())
								{
									UIElement *srce=group->nodes_[src];
									UIElement *dste=group->nodes_[dest];
									
									if(srce && dste)
									{
										NodeGraphLinkSource *ngls=srce->GetChildDynamicCast<NodeGraphLinkSource>("Output0", true);
										if(ngls)
										{
											NodeGraphLinkDest *ngld=dste->GetChildDynamicCast<NodeGraphLinkDest>(String("Input")+String(destval), true);
											if(ngld)
											{
												NodeGraphLink *link=group->linkPane_->CreateLink(ngls, ngld);
												link->SetImageRect(IntRect(193,81,207,95));
											}
											else
											{
												URHO3D_LOGINFO(String("Could not obtain source input ") + String(destval) + " of node type " + dste->GetName());
												URHO3D_LOGINFO(String("node has ") + String(dste->GetChild("Inputs", true)->GetNumChildren()) + " children. Their names are:");
												for(unsigned int m=0; m<dste->GetChild("Inputs", true)->GetNumChildren(); ++m)
												{
													URHO3D_LOGINFO(dste->GetChild("Inputs", true)->GetChild(m)->GetChild(0)->GetName());
												}
											}
										}
										else URHO3D_LOGINFO("Could not get Output0");
									}
								}
								else URHO3D_LOGINFO(String("node index out of bounds.") + String(src) + " " + String(dest));
							}
						}
						else URHO3D_LOGINFO("No links array.");
						
						// Load output link
						if(jgrp["OutputLink"] && jgrp["OutputLink"]->IsObject())
						{
							const JSONObject &jlink=jgrp["OutputLink"]->GetObject();
							int src=jlink["SourceNodeIndex"]->GetInt();
							if(src>=0 && src<group->nodes_.size())
							{
								UIElement *srce=group->nodes_[src];
								if(srce)
								{
									NodeGraphLinkSource *ngls=srce->GetChildDynamicCast<NodeGraphLinkSource>("Output0", true);
									if(ngls)
									{
										NodeGraphLinkDest *ngld=group->output_->GetChildDynamicCast<NodeGraphLinkDest>(String("Input0"), true);
										if(ngld)
										{
											NodeGraphLink *link=group->linkPane_->CreateLink(ngls, ngld);
											link->SetImageRect(IntRect(193,81,207,95));
										}
									}
								}
								else URHO3D_LOGINFO("Could not get output linked source.");
							}
						}
						else URHO3D_LOGINFO("No output link setting.");
					}
					else URHO3D_LOGINFO("Could not create group.");
				}
				else URHO3D_LOGINFO("Group def is not an object.");
			}
		}
		else URHO3D_LOGINFO("Groups is not an array.");
	}
	else URHO3D_LOGINFO("NodeGroups is not an object.");
	
}

void NodeGraphUI::Clear()
{
	ListView *nlist=nodeGroupsList_->GetChildDynamicCast<ListView>("List", true);
	nlist->RemoveAllItems();
	nodeGroups_.clear();
	selectedNodeGroup_=nullptr;
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
				"rotateDomain",
				"distort"
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
	if(!nodeGroupsList_) return;

	int which=nodeGroupsList_->GetChildDynamicCast<ListView>("List", true)->GetSelection();
	if(which==-1) return;
	if(which>=nodeGroups_.size()) return;
	
	NodeGroup *grp=&nodeGroups_[which];
	
	HideGroup();
	selectedNodeGroup_=nullptr;
	
	for(auto it=nodeGroups_.begin(); it!=nodeGroups_.end(); ++it)
	{
		if(&(*it)==grp)
		{
			nodeGroups_.erase(it);
			ListView *nlist=nodeGroupsList_->GetChildDynamicCast<ListView>("List", true);
			nlist->RemoveItem(which);
			if(which>=nlist->GetNumItems()) nlist->SetSelection(nlist->GetNumItems()-1);
			return;
		}
	}
}

void NodeGraphUI::HandleGroupSelected(StringHash eventType, VariantMap &eventData)
{
	ListView *list=nodeGroupsList_->GetChildDynamicCast<ListView>("List", true);
	unsigned int num=list->GetNumItems();
	unsigned int sel=list->GetSelection();
	for(unsigned int c=0; c<num; ++c)
	{
		UIElement *i=list->GetItem(c);
		if(c==sel) i->SetColor(Color(1,1,1));
		else i->SetColor(Color(0.5,0.5,0.5));
	}
}

void NodeGraphUI::HandleGenerate(StringHash eventType, VariantMap &eventData)
{
	if(!selectedNodeGroup_) return;
	CKernel kernel;
	BuildANLFunction2(kernel, selectedNodeGroup_->output_);
	Vector2 minmax=RenderANLKernelToImage(selectedNodeGroup_->previewImage_, &kernel, 0, 1, selectedNodeGroup_->histoImage_, SEAMLESS_NONE, false, 0.0, 1.0, 1.0, true);
	selectedNodeGroup_->previewTex_->SetData(selectedNodeGroup_->previewImage_, false);
	selectedNodeGroup_->histoTex_->SetData(selectedNodeGroup_->histoImage_, false);
	selectedNodeGroup_->output_->GetChildDynamicCast<Text>("LowValue", true)->SetText("%.4f"_fmt(minmax.x_));
	selectedNodeGroup_->output_->GetChildDynamicCast<Text>("HighValue", true)->SetText("%.4f"_fmt(minmax.y_));
}

void NodeGraphUI::HandleMapGroup(StringHash eventType, VariantMap &eventData)
{
	HandleExecute(eventType, eventData);
}

void NodeGraphUI::HandleExecute(StringHash eventType, VariantMap &eventData)
{
	if(!selectedNodeGroup_) return;
	
	unsigned int target=selectedNodeGroup_->output_->GetChildDynamicCast<DropDownList>("TargetList", true)->GetSelection();
	unsigned int blendop=selectedNodeGroup_->output_->GetChildDynamicCast<DropDownList>("BlendOpList", true)->GetSelection();
	
	bool um1=selectedNodeGroup_->output_->GetChildDynamicCast<CheckBox>("UseMask1", true)->IsChecked();
	bool im1=selectedNodeGroup_->output_->GetChildDynamicCast<CheckBox>("InvertMask1", true)->IsChecked();
	bool um2=selectedNodeGroup_->output_->GetChildDynamicCast<CheckBox>("UseMask2", true)->IsChecked();
	bool im2=selectedNodeGroup_->output_->GetChildDynamicCast<CheckBox>("InvertMask2", true)->IsChecked();
	bool um3=selectedNodeGroup_->output_->GetChildDynamicCast<CheckBox>("UseMask3", true)->IsChecked();
	bool im3=selectedNodeGroup_->output_->GetChildDynamicCast<CheckBox>("InvertMask3", true)->IsChecked();
	
	float low=ToFloat(selectedNodeGroup_->output_->GetChildDynamicCast<LineEdit>("Low", true)->GetText());
	float high=ToFloat(selectedNodeGroup_->output_->GetChildDynamicCast<LineEdit>("High", true)->GetText());
	bool rescale=selectedNodeGroup_->output_->GetChildDynamicCast<CheckBox>("Rescale", true)->IsChecked();
	
	if(target==0)
	{
		CKernel kernel;
		BuildANLFunction2(kernel, selectedNodeGroup_->output_);
		IntVector2 size=terrainContext_->GetTerrainMapSize();
		CArray2Dd arr(size.x_, size.y_);
		map2DNoZ(SEAMLESS_NONE, arr, kernel, SMappingRanges(0,1,0,1,0,1), kernel.lastIndex());
		if(rescale) arr.scaleToRange(low, high);
		MaskSettings ms{um1,im1,um2,im2,um3,im3};
		terrainContext_->SetHeightBuffer(arr, ms, blendop);
	}
	else if(target>=1 && target<=8)
	{
		CKernel kernel;
		BuildANLFunction2(kernel, selectedNodeGroup_->output_);
		IntVector2 size=terrainContext_->GetTerrainMapSize();
		CArray2Dd arr(size.x_, size.y_);
		map2DNoZ(SEAMLESS_NONE, arr, kernel, SMappingRanges(0,1,0,1,0,1), kernel.lastIndex());
		if(rescale) arr.scaleToRange(low, high);
		MaskSettings ms{um1,im1,um2,im2,um3,im3};
		terrainContext_->SetLayerBuffer(arr, target-1, ms);
	}
	else if(target>=9 && target<=11)
	{
		CKernel kernel;
		BuildANLFunction2(kernel, selectedNodeGroup_->output_);
		IntVector2 size=terrainContext_->GetTerrainMapSize();
		CArray2Dd arr(size.x_, size.y_);
		map2DNoZ(SEAMLESS_NONE, arr, kernel, SMappingRanges(0,1,0,1,0,1), kernel.lastIndex());
		if(rescale) arr.scaleToRange(low, high);
		MaskSettings ms{um1,im1,um2,im2,um3,im3};
		terrainContext_->SetMaskBuffer(arr, target-9);
	}
	else if(target==12)
	{
		CKernel kernel;
		BuildANLFunction2(kernel, selectedNodeGroup_->output_);
		IntVector2 size=terrainContext_->GetTerrainMapSize();
		CArray2Dd arr(size.x_, size.y_);
		map2DNoZ(SEAMLESS_NONE, arr, kernel, SMappingRanges(0,1,0,1,0,1), kernel.lastIndex());
		if(rescale) arr.scaleToRange(low, high);
		MaskSettings ms{um1,im1,um2,im2,um3,im3};
		terrainContext_->SetWaterBuffer(arr, ms, blendop);
	}
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

UIElement *NodeGraphUI::GetSourceFromNode(UIElement *node, const String &inputname)
{
	NodeGraphLinkDest *c=node->GetChildDynamicCast<NodeGraphLinkDest>(inputname,true);
	if(c)
	{
		NodeGraphLink *link=c->GetLink();
		if(link)
		{
			NodeGraphLinkSource *src=link->GetSource();
			if(src) return src->GetRoot();
		}
	}
	return nullptr;
}

void NodeGraphUI::BuildANLFunction2(CKernel &kernel, UIElement *output)
{
	std::unordered_map<UIElement *, CInstructionIndex> indices;
	
	std::function<CInstructionIndex(UIElement *)> buildIndex=[&](UIElement *elem)->CInstructionIndex
	{
		auto it=indices.find(elem);
		if(it != indices.end())
		{
			return it->second;
		}
		
		NodeTypeDesc *desc=GetNodeTypeDesc(elem->GetName());
		unsigned int numinputs=desc->inputs_.size();
		std::vector<CInstructionIndex> params;
		
		for(unsigned int inp=0; inp<numinputs; ++inp)
		{
			UIElement *s=GetSourceFromNode(elem, String("Input")+String(inp));
			if(s)
			{
				params.push_back(buildIndex(s));
			}
			else
			{
				if(desc->inputs_[inp].type_=="value")
				{
					String sc=elem->GetChildDynamicCast<LineEdit>(String("Value")+String(inp), true)->GetText();
					float num=ToFloat(sc);
					params.push_back(kernel.constant(num));
				}
				else
				{
					String sc=elem->GetChildDynamicCast<LineEdit>(String("Value")+String(inp), true)->GetText();
					unsigned int num=ToUInt(sc);
					params.push_back(kernel.seed(num));
				}
			}
		}
		
		// Instance the function
		const String &functype=elem->GetName();
		if(functype=="constant")
		{
			float v=ToFloat(elem->GetChildDynamicCast<LineEdit>("Value", true)->GetText());
			CInstructionIndex index=kernel.constant(v);
			indices[elem]=index;
			return index;
		}
		else if(functype=="seed")
		{
			unsigned int v=ToUInt(elem->GetChildDynamicCast<LineEdit>("Value", true)->GetText());
			CInstructionIndex index=kernel.seed(v);
			indices[elem]=index;
			return index;
		}
		else
		{
			CInstructionIndex index=desc->instance_(kernel,params);
			indices[elem]=index;
			return index;
		}
		
		
		return kernel.zero();
	};
	
	UIElement *e=GetSourceFromNode(output, String("Input0"));
	if(e) buildIndex(e);
}

/*
CInstructionIndex NodeGraphUI::InstanceFunction(CKernel &kernel, NodeTypeDesc *desc, std::vector<CInstructionIndex> &params)
{
	std::vector<CInstructionIndex> n;
	for(auto &c : desc->instance_)
	{
		if(c.op_=="Parameter")
		{
			n.push_back(params[c.param_]);
		}
		else if(c.op_=="Function")
		{
			std::vector<IndicesInputsDesc> &indices=c.indices_;
			std::vector<ValueInputsDesc> &constants=c.constants_;
			std::vector<ValueInputsDesc> &seeds=c.seeds_;
			
			std::vector<CInstructionIndex> inputs;
			NodeTypeDesc *fdesc=GetNodeTypeDesc(c.func_);
			if(!fdesc) return CInstructionIndex(0);  /// TODO: What do I do here?
			for(unsigned int d=0; d<fdesc->inputs_.size(); ++d)
			{
				if(d<indices.size() && indices[d].used_)
				{
					inputs.push_back(n[indices[d].index_]);
				}
				else if(d<constants.size() && constants[d].used_)
				{
					inputs.push_back(kernel.constant(constants[d].value_));
				}
				else if(d<seeds.size() && seeds[d].used_)
				{
					inputs.push_back(kernel.seed((unsigned int)seeds[d].value_));
				}
			}
			
			if(c.func_=="add")
			{
				n.push_back(kernel.add(inputs[0], inputs[1]));
			}
		}
	}
	
	return kernel.lastIndex();*/
/*
function InstanceFunction(k, desc, params)
	local ins=desc.instance
	if not ins then return end

	local n={}
	local c
	for _,c in ipairs(ins) do
		if c.op=="Parameter" then
			table.insert(n, params[c.param])
		elseif c.op=="Function" then
			local indices=c.indices
			local constants=c.constants
			local seeds=c.seeds

			local inputs={}
			local d

			local fdesc=GetNodeTypeDesc(c.func) --nodetypes[c.func]
			print("numinputs for "..c.func..": "..#fdesc.inputs)
			for d=1,#fdesc.inputs,1 do
				if indices[d] ~= "nil" then print("index: "..indices[d]) table.insert(inputs,n[indices[d]])
				elseif constants and constants[d] ~= "nil" then print("constant: "..constants[d]) table.insert(inputs, k:constant(constants[d]))
				elseif seeds and seeds[d] ~= "nil" then print("seed: "..seeds[d]) table.insert(inputs, k:seed(seeds[d]))
				end
			end

			print("Function name: "..c.func)
			if c.func=="add" then
				table.insert(n, k:add(inputs[1],inputs[2]))
			elseif c.func=="subtract" then
				table.insert(n, k:subtract(inputs[1], inputs[2]))
			elseif c.func=="multiply" then
				table.insert(n, k:multiply(inputs[1], inputs[2]))
			elseif c.func=="divide" then
				table.insert(n, k:divide(inputs[1], inputs[2]))
			elseif c.func=="subtract" then
				table.insert(n, k:subtract(inputs[1], inputs[2]))
			elseif c.func=="minimum" then
				table.insert(n, k:minimum(inputs[1], inputs[2]))
			elseif c.func=="maximum" then
				table.insert(n, k:maximum(inputs[1], inputs[2]))
			elseif c.func=="bias" then
				table.insert(n, k:bias(inputs[1], inputs[2]))
			elseif c.func=="gain" then
				table.insert(n, k:gain(inputs[1], inputs[2]))
			elseif c.func=="step" then
				table.insert(n, k:step(inputs[1], inputs[2]))
			elseif c.func=="linearStep" then
				table.insert(n, k:linearStep(inputs[1], inputs[2], inputs[3]))
			elseif c.func=="smoothStep" then
				table.insert(n, k:smoothStep(inputs[1], inputs[2], inputs[3]))
			elseif c.func=="smootherStep" then
				table.insert(n, k:smootherStep(inputs[1], inputs[2], inputs[3]))
			elseif c.func=="curveSection" then
				table.insert(n, k:curveSection(inputs[1], inputs[2], inputs[3], inputs[4], inputs[5], inputs[6]))
			elseif c.func=="abs" then
				table.insert(n, k:abs(inputs[1]))
			elseif c.func=="sin" then
				table.insert(n, k:sin(inputs[1]))
			elseif c.func=="cos" then
				table.insert(n, k:cos(inputs[1]))
			elseif c.func=="tan" then
				table.insert(n, k:tan(inputs[1]))
			elseif c.func=="asin" then
				table.insert(n, k:asin(inputs[1]))
			elseif c.func=="acos" then
				table.insert(n, k:acos(inputs[1]))
			elseif c.func=="atan" then
				table.insert(n, k:atan(inputs[1]))
			elseif c.func=="x" then
				table.insert(n, k:x())
			elseif c.func=="y" then
				table.insert(n, k:y())
			elseif c.func=="radial" then
				table.insert(n, k:radial())
			elseif c.func=="dX" then
				table.insert(n, k:dx(inputs[1], inputs[2]))
			elseif c.func=="dY" then
				table.insert(n, k:dy(inputs[1], inputs[2]))
			elseif c.func=="smoothTiers" then
				table.insert(n, k:smoothTiers(inputs[1], inputs[2]))
			elseif c.func=="tiers" then
				table.insert(n, k:tiers(inputs[1], inputs[2]))
			elseif c.func=="translateDomain" then
				table.insert(n, k:translateDomain(inputs[1], inputs[2]))
			elseif c.func=="translateX" then
				table.insert(n, k:translateX(inputs[1], inputs[2]))
			elseif c.func=="translateY" then
				table.insert(n, k:translateY(inputs[1], inputs[2]))
			elseif c.func=="scaleDomain" then
				table.insert(n, k:scaleDomain(inputs[1], inputs[2]))
			elseif c.func=="scaleX" then
				table.insert(n, k:scaleX(inputs[1], inputs[2]))
			elseif c.func=="scaleY" then
				table.insert(n, k:scaleY(inputs[1], inputs[2]))
			elseif c.func=="rotateDomain" then
				table.insert(n, k:rotateDomain(inputs[1], inputs[2], inputs[3], inputs[4], inputs[5]))
			elseif c.func=="mix" then
				table.insert(n, k:mix(inputs[1], inputs[2], inputs[3]))
			elseif c.func=="seeder" then
				table.insert(n, k:seeder(inputs[1], inputs[2]))
			elseif c.func=="sigmoid" then
				table.insert(n, k:sigmoid(inputs[1], inputs[2], inputs[3]))
			elseif c.func=="randomize" then
				table.insert(n, k:randomize(inputs[1], inputs[2], inputs[3]))
			elseif c.func=="fractal" then
				table.insert(n, k:fractal(inputs[1], inputs[2], inputs[3], inputs[4], inputs[5], inputs[6]))
			elseif c.func=="cellularBasis" then
				table.insert(n, k:cellularBasis(inputs[1], inputs[2], inputs[3], inputs[4], inputs[5], inputs[6], inputs[7], inputs[8], inputs[9], inputs[10]))
			elseif c.func=="valueBasis" then
				table.insert(n, k:valueBasis(inputs[1], inputs[2]))
			elseif c.func=="gradientBasis" then
				table.insert(n, k:gradientBasis(inputs[1], inputs[2]))
			elseif c.func=="simplexBasis" then
				table.insert(n, k:simplexBasis(inputs[1]))
			elseif c.func=="combineRGBA" then
				table.insert(n, k:combineRGBA(inputs[1],inputs[2],inputs[3],inputs[4]))
			elseif c.func=="combineHSVA" then
				table.insert(n, k:combineHSVA(inputs[1],inputs[2],inputs[3],inputs[4]))
			else
				if nodetypes.library[c.func] then
					table.insert(n, InstanceFunction(k, nodetypes.library[c.func], inputs))
				elseif nodetypes.user[c.func] then
					table.insert(n, InstanceFunction(k, nodetypes.user[c.func], inputs))
				else
					print("wut")
				end
			end
		end
	end
	print(k:lastIndex())
	return k:lastIndex()
end*/
/*
}

void NodeGraphUI::BuildANLFunction(CKernel &kernel, UIElement *output)
{
	std::vector<UIElement *> nodes;
	std::vector<CInstructionIndex> kernelindices;
	
	auto isvisited=[&](UIElement *n)->bool
	{
		for(auto c : nodes) if(c==n) return true;
		return false;
	};
	
	auto nodeindex=[&](UIElement *n)->int
	{
		for(int c=0; c<nodes.size(); ++c)
		{
			if(nodes[c]==n) return c;
		}
		return -1;
	};
	
	auto InstanceANLFunction=[&](CKernel &kernel, UIElement *n)->CInstructionIndex
	{
		auto GetValue=[&](UIElement *elem, unsigned int which)->CInstructionIndex
		{
			UIElement *s=GetSourceFromNode(elem, String("Input")+String(which));
			unsigned int s1;
			if(s)
			{
				return kernelindices[nodeindex(s)];
			}
			else
			{
				String sc=elem->GetChildDynamicCast<Text>(String("Value")+String(which), true)->GetText();
				float num=ToFloat(sc);
				kernelindices.push_back(kernel.constant(num));
				return kernel.lastIndex();
			}
		};
		
		auto GetSeed=[&](UIElement *elem, unsigned int which)->CInstructionIndex
		{
			UIElement *s=GetSourceFromNode(elem, String("Input")+String(which));
			unsigned int s1;
			if(s)
			{
				return kernelindices[nodeindex(s)];
			}
			else
			{
				String sc=elem->GetChildDynamicCast<Text>(String("Value")+String(which), true)->GetText();
				float num=ToFloat(sc);
				kernelindices.push_back(kernel.seed(num));
				return kernel.lastIndex();
			}
		};
		
		NodeTypeDesc *desc=GetNodeTypeDesc(n->GetName());
		if(!desc) return 0;
		unsigned int numinputs=desc->inputs_.size();
		std::vector<CInstructionIndex> params;
		for(unsigned int c=0; c<numinputs; ++c)
		{
			if(desc->inputs_[c].type_=="value")
			{
				params.push_back(GetValue(n,c));
			}
			else
			{
				params.push_back(GetSeed(n,c));
			}
		}
		
		if(n->GetName()=="Output")
		{
			return GetValue(n,0);
		}
		else if(n->GetName()=="constant")
		{
			float v=ToFloat(n->GetChildDynamicCast<LineEdit>("Value", true)->GetText());
			kernelindices.push_back(kernel.constant(v));
			return kernel.lastIndex();
		}
		else if(n->GetName()=="seed")
		{
			float v=ToFloat(n->GetChildDynamicCast<LineEdit>("Value", true)->GetText());
			kernelindices.push_back(kernel.seed(v));
			return kernel.lastIndex();
		}
		else
		{
			return InstanceFunction(kernel, desc, params);
		}
	};
	
	std::function<void(UIElement*)> worker;
	worker=[&](UIElement *n)
	{
		auto visitnode=[&](UIElement *nd, unsigned int numparams)
		{
			for(unsigned int c=0; c<numparams; ++c)
			{
				UIElement*s=GetSourceFromNode(nd, String("Input")+String(c));
				if(s && !isvisited(s)) worker(s);
			};
		};
		
		if(n->GetName()!="Output")
		{
			NodeTypeDesc *dsc=GetNodeTypeDesc(n->GetName());
			if(!dsc) return;
			
			unsigned ni=dsc->inputs_.size();
			if(ni>0)
			{
				visitnode(n, ni);
			}
		}
		else
		{
			visitnode(n,1);
		}
		
		nodes.push_back(n);
		CInstructionIndex ind=InstanceANLFunction(kernel, n);
		kernelindices.push_back(ind);
	};
	
	worker(output);
}*/
/*
function BuildANLFunction(output)

	

	worker=function(n)
		local visitnode=function(n,numparms)
			local s,c
			for c=0,numparms-1,1 do
				s=GetSourceFromNode(n,"Input"..c)
				if s and not isvisited(s) then worker(s) end
			end
		end

		if n.name~="Output" then
			local desc=GetNodeTypeDesc(n.name)--nodetypes[n.name]
			if not desc then print(n.name.." Doesn't exist") return false end

			local numinputs=#desc.inputs
			if numinputs>0 then
				visitnode(n, numinputs)
			end
		else
			visitnode(n,1)
		end

		table.insert(nodes,n)
		local ind=InstanceANLFunction(kernel, n)
		table.insert(kernelindices, ind)
	end
	print("Packing node graph.")

	worker(output)
	local c
	for _,c in ipairs(nodes) do print(c.name) end
	return kernel
end
*/
