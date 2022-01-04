#include "waypointgroupui.h"

#include <Urho3D/Graphics/Model.h>
#include <Urho3D/Graphics/StaticModel.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Math/Random.h>
#include <Urho3D/Math/BoundingBox.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/UI/Text.h>
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

#include <Urho3D/IO/Log.h>


#include "../rasterization.h"
#include "../terraincontext.h"
#include "../Components/editingcamera.h"

#include "../jsonutilities.h"

WaypointGroup::WaypointGroup(Context *context) : Object(context),
	terrainContext_(nullptr),
	visible_(false),
	ribbon_(nullptr),
	ribbonMat_(nullptr)
{
}

void WaypointGroup::Construct(Scene *scene, TerrainContext *tc)
{
	scene_=scene;
	terrainContext_=tc;
	
	auto rndColorComp=[&]()->float
	{
		return ((float)Rand() / 32767.f)*0.75f+0.25f;
	};
	
	auto cache=GetSubsystem<ResourceCache>();
	ribbonNode_=scene->CreateChild();
	ribbon_=ribbonNode_->CreateComponent<CustomGeometry>();
	ribbonColor_=Color(rndColorComp(), rndColorComp(), rndColorComp(), 0.5f);
	ribbonMat_=cache->GetResource<Material>("Materials/WaypointPreview.xml");
	knotMat_=cache->GetResource<Material>("Materials/Flag.xml");
}

void WaypointGroup::SetVisible(bool v)
{
	visible_=v;
	if(v)
	{
		if(ribbonNode_) ribbonNode_->SetEnabled(true);
		for(auto & c : knots_) c->SetEnabled(true);
		if(ribbonMat_) ribbonMat_->SetShaderParameter("MatDiffColor", Variant(ribbonColor_));
		if(knotMat_) knotMat_->SetShaderParameter("MatDiffColor", Variant(ribbonColor_));
	}
	else
	{
		if(ribbonNode_) ribbonNode_->SetEnabled(false);
		for(auto &c : knots_) c->SetEnabled(false);
	}
}

bool WaypointGroup::IsVisible()
{
	return visible_;
}

void WaypointGroup::AddKnot(const Vector3 &pos)
{
	auto cache=GetSubsystem<ResourceCache>();
	
	Node *knot=scene_->CreateChild();
	StaticModel *model=knot->CreateComponent<StaticModel>();
	model->SetModel(cache->GetResource<Model>("Models/Flag.mdl"));
	model->SetMaterial(knotMat_);
	model->SetCastShadows(true);
	
	float ht=terrainContext_->GetHeight(pos);
	knot->SetPosition(Vector3(pos.x_, ht, pos.z_));
	knot->SetScale(Vector3(0.0625,0.0625,0.0625));
	knots_.push_back(knot);
}

void WaypointGroup::RemoveLastKnot()
{
	if(knots_.size()>0)
	{
		Node *knot=knots_[knots_.size()-1];
		knot->Remove();
		knots_.pop_back();
	}
}

void WaypointGroup::UpdateKnotHeights()
{
	for(auto &c : knots_)
	{
		Vector3 pos=c->GetPosition();
		float ht=terrainContext_->GetHeight(pos);
		c->SetPosition(Vector3(pos.x_, ht, pos.z_));
	}
}

std::vector<Vector3> WaypointGroup::GetKnots()
{
	std::vector<Vector3> knots;
	for(auto &c : knots_)
	{
		knots.push_back(c->GetPosition());
	}
	return knots;
}

void WaypointGroup::BuildRibbon()
{
	if(knots_.size()<2)
	{
		ribbon_->Clear();
		ribbon_->Commit();
		return;
	}
	
	RasterVertexList plist;
	for(auto &c : knots_)
	{
		Vector3 pos=c->GetPosition();
		float ht=terrainContext_->GetHeight(pos);
		plist.push_back(RasterVertex(pos.x_, pos.z_, ht));
	}
	
	RasterVertexList curve;
	TessellateLineList(&plist, &curve, 3);
	
	RasterVertexList quad;
	BuildQuadStrip(&curve, &quad, 0.5);
	
	ribbon_->Clear();
	ribbon_->SetNumGeometries(1);
	ribbon_->BeginGeometry(0, TRIANGLE_LIST);
	ribbon_->SetDynamic(true);
	
	auto buildVertex=[](const RasterVertex &rv)->Vector3
	{
		return Vector3(rv.x_, rv.val_, rv.y_);
	};
	
	//BoundingBox bbox;
	
	for(unsigned int c=0; c<quad.size()-4; c+=2)
	{
		const std::vector<unsigned int> inds{0,1,2,1,2,3};
		for(auto d : inds)
		{
			Vector3 v=buildVertex(quad[c+d]);
			ribbon_->DefineVertex(v);
			//bbox.Merge(v);
		}
	}
	
	ribbon_->Commit();
	ribbon_->SetMaterial(ribbonMat_);
	//ribbon_->SetWorldBoundingBox(bbox);
}

// WaypointGroupUI

WaypointGroupUI::WaypointGroupUI(Context *context) : Object(context),
	scene_(nullptr),
	terrainContext_(nullptr),
	camera_(nullptr),
	selectedGroup_(nullptr)
{
}

void WaypointGroupUI::Construct(Scene *scene, TerrainContext *tc, EditingCamera *cam)
{
	scene_=scene;
	terrainContext_=tc;
	camera_=cam;
	
	auto ui=GetSubsystem<UI>();
	auto cache=GetSubsystem<ResourceCache>();
	auto graphics=GetSubsystem<Graphics>();
	
	XMLFile *style=cache->GetResource<XMLFile>("UI/DefaultStyle.xml");
	
	element_=ui->LoadLayout(cache->GetResource<XMLFile>("UI/SplineGroups.xml"), style);
	element_->SetVisible(false);
	element_->SetPosition(IntVector2(0, graphics->GetHeight()-element_->GetHeight()));
	ui->GetRoot()->GetChild("Base", true)->AddChild(element_);
	
	
	SubscribeToEvent(element_->GetChild("New", true), StringHash("Pressed"), URHO3D_HANDLER(WaypointGroupUI, HandleNewGroup));
	SubscribeToEvent(element_->GetChild("Delete", true), StringHash("Pressed"), URHO3D_HANDLER(WaypointGroupUI, HandleDeleteGroup));
	SubscribeToEvent(element_->GetChild("List", true), StringHash("ItemSelected"), URHO3D_HANDLER(WaypointGroupUI, HandleGroupSelected));
	
	SubscribeToEvent(StringHash("Update"), URHO3D_HANDLER(WaypointGroupUI, HandleUpdate));
}

void WaypointGroupUI::Save(JSONObject &json)
{
	//JSONObject settings;
	JSONArray jgroups;
	for(auto & g : groups_)
	{
		JSONObject jgrp;
		jgrp["Name"]=g->name_;
		
		JSONArray jknots;
		const std::vector<Vector3> knots=g->GetKnots();
		for(auto k : knots)
		{
			jknots.Push(JSONFromVector3(k));
		}
		jgrp["Knots"]=jknots;
		
		jgroups.Push(jgrp);
	}
	
	//settings["Groups"]=jgroups;
	json["WaypointGroups"]=jgroups;
}

void WaypointGroupUI::Load(const JSONObject &json)
{
	// Delete groups
	
	Clear();
	
	if(json["WaypointGroups"] && json["WaypointGroups"]->IsArray())
	{
		const JSONArray &jgroups=json["WaypointGroups"]->GetArray();
		for(unsigned int c=0; c<jgroups.Size(); ++c)
		{
			const JSONObject &jgrp=jgroups[c].GetObject();
			
			SharedPtr<WaypointGroup> grp=CreateWaypointGroup(jgrp["Name"]->GetString());
			if(grp)
			{
				grp->name_=jgrp["Name"]->GetString();
				if(jgrp["Knots"] && jgrp["Knots"]->IsArray())
				{
					const JSONArray &jknots=jgrp["Knots"]->GetArray();
					for(unsigned int d=0; d<jknots.Size(); ++d)
					{
						grp->AddKnot(Vector3FromJSON(jknots[d]));
					}
				}
				grp->BuildRibbon();
				grp->SetVisible(false);
			}
		}
	}
}

void WaypointGroupUI::Clear()
{
	ListView *nlist=element_->GetChildDynamicCast<ListView>("List", true);
	nlist->RemoveAllItems();
	
	selectedGroup_=nullptr;
	groups_.clear();
}

void WaypointGroupUI::SetVisible(bool v)
{
	if(element_) element_->SetVisible(v);
	if(!v)
	{
		if(selectedGroup_)
		{
			selectedGroup_->SetVisible(false);
		}
	}
	else
	{
		if(selectedGroup_)
		{
			selectedGroup_->SetVisible(true);
			selectedGroup_->UpdateKnotHeights();
			selectedGroup_->BuildRibbon();
		}
	}
}

bool WaypointGroupUI::IsVisible()
{
	return element_->IsVisible();
}

std::vector<String> WaypointGroupUI::GetGroupNames()
{
	std::vector<String> names;
	for(auto &g : groups_)
	{
		names.push_back(g->name_);
	}
	return names;
}

std::vector<Vector3> WaypointGroupUI::GetGroupKnots(const String &group)
{
	for(auto &g : groups_)
	{
		if(g->name_==group)
		{
			return g->GetKnots();
		}
	}
	
	return std::vector<Vector3>();
}

WaypointGroup *WaypointGroupUI::GetGroup(const String &name)
{
	for(auto &g : groups_)
	{
		if(g->name_==name) return g;
	}
	return nullptr;
}

SharedPtr<WaypointGroup> WaypointGroupUI::CreateWaypointGroup(const String &name)
{
	auto cache=GetSubsystem<ResourceCache>();
	SharedPtr<WaypointGroup> grp(new WaypointGroup(context_));
	
	grp->Construct(scene_, terrainContext_);
	grp->SetVisible(false);
	
	
	ListView *nlist=element_->GetChildDynamicCast<ListView>("List", true);
	unsigned int sel=nlist->GetSelection();

	SharedPtr<Text> t(new Text(context_));
	t->SetStyle("FileSelectorListText", cache->GetResource<XMLFile>("UI/DefaultStyle.xml"));
	t->SetText(name);
	nlist->AddItem(t);
	nlist->SetSelection(nlist->GetNumItems()-1);
	grp->name_=name;
	groups_.push_back(grp);
	return grp;
}

void WaypointGroupUI::HideGroup()
{
	if(selectedGroup_) selectedGroup_->SetVisible(false);
}

void WaypointGroupUI::ActivateGroup(WaypointGroup * grp)
{
	if(selectedGroup_)
	{
		selectedGroup_->SetVisible(false);
	}
	selectedGroup_=grp;
	if(selectedGroup_)
	{
		selectedGroup_->SetVisible(true);
	}
}

void WaypointGroupUI::HandleNewGroup(StringHash eventType, VariantMap &eventData)
{
	auto cache=GetSubsystem<ResourceCache>();
	XMLFile *style=cache->GetResource<XMLFile>("UI/DefaultStyle.xml");
	auto ui=GetSubsystem<UI>();
	auto graphics=GetSubsystem<Graphics>();

	newGroupDlg_=DynamicCast<Window>(ui->LoadLayout(cache->GetResource<XMLFile>("UI/NewNodeGroupDlg.xml"), style));
	ui->GetRoot()->GetChild("Base",true)->AddChild(newGroupDlg_);
	newGroupDlg_->SetModal(true);

	SubscribeToEvent(newGroupDlg_->GetChild("OK", true), StringHash("Pressed"), URHO3D_HANDLER(WaypointGroupUI, HandleNewGroupAccept));
	SubscribeToEvent(newGroupDlg_->GetChild("Close", true), StringHash("Pressed"), URHO3D_HANDLER(WaypointGroupUI, HandleNewGroupCancel));
	SubscribeToEvent(newGroupDlg_->GetChild("Cancel", true), StringHash("Pressed"), URHO3D_HANDLER(WaypointGroupUI, HandleNewGroupCancel));

	newGroupDlg_->SetPosition(IntVector2(graphics->GetWidth()/2-newGroupDlg_->GetWidth()/2, graphics->GetHeight()/2-newGroupDlg_->GetHeight()/2));
	ui->SetFocusElement(newGroupDlg_->GetChild("GroupName", true), false);
}

void WaypointGroupUI::HandleNewGroupAccept(StringHash eventType, VariantMap &eventData)
{
	String name=newGroupDlg_->GetChildDynamicCast<LineEdit>("GroupName", true)->GetText();
	for(unsigned int c=0; c<groups_.size(); ++c)
	{
		WaypointGroup* g=groups_[c];
		if(g->name_==name)
		{
			newGroupDlg_->GetChildDynamicCast<Text>("Status",true)->SetText("Group already exists!");
			return;
		}
	}

	if(name=="")
	{
		newGroupDlg_->GetChildDynamicCast<Text>("Status",true)->SetText("Please enter a name for the group.");
		return;
	}

	HideGroup();
	SharedPtr<WaypointGroup> grp=CreateWaypointGroup(name);
	selectedGroup_=grp;
	ActivateGroup(selectedGroup_);
	
	ListView *nlist=element_->GetChildDynamicCast<ListView>("List", true);
	nlist->SetSelection(nlist->GetNumItems()-1);

	newGroupDlg_->Remove();
	newGroupDlg_.Reset();

}

void WaypointGroupUI::HandleNewGroupCancel(StringHash eventType, VariantMap &eventData)
{
	if(newGroupDlg_)
	{
		newGroupDlg_->Remove();
		newGroupDlg_.Reset();
	}
}

void WaypointGroupUI::HandleEditGroup(StringHash eventType, VariantMap &eventData)
{
	if(!element_) return;

	int which=element_->GetChildDynamicCast<ListView>("List", true)->GetSelection();
	if(which==-1) return;
	if(which>=groups_.size()) return;
	WaypointGroup *grp=groups_[which];
	ActivateGroup(grp);
}

void WaypointGroupUI::HandleDeleteGroup(StringHash eventType, VariantMap &eventData)
{
	if(!element_) return;

	int which=element_->GetChildDynamicCast<ListView>("List", true)->GetSelection();
	if(which==-1) return;
	if(which>=groups_.size()) return;
	
	WaypointGroup* grp=groups_[which];
	
	HideGroup();
	selectedGroup_=nullptr;
	
	std::swap(groups_[which], groups_[groups_.size()-1]);
	groups_.pop_back();
	
	ListView *nlist=element_->GetChildDynamicCast<ListView>("List", true);
	nlist->RemoveItem(which);
	if(which>=nlist->GetNumItems()) nlist->SetSelection(nlist->GetNumItems()-1);
	else nlist->SetSelection(which);
	return;
}

void WaypointGroupUI::HandleGroupSelected(StringHash eventType, VariantMap &eventData)
{

	int which=element_->GetChildDynamicCast<ListView>("List", true)->GetSelection();
	if(which==-1) return;
	if(which>=groups_.size()) return;
	WaypointGroup* grp=groups_[which];
	ActivateGroup(grp);
	
	
	ListView *list=element_->GetChildDynamicCast<ListView>("List", true);
	unsigned int num=list->GetNumItems();
	unsigned int sel=list->GetSelection();
	for(unsigned int c=0; c<num; ++c)
	{
		UIElement *i=list->GetItem(c);
		if(c==sel) i->SetColor(Color(1,1,1));
		else i->SetColor(Color(0.5,0.5,0.5));
	}
}

void WaypointGroupUI::HandleUpdate(StringHash eventType, VariantMap &eventData)
{
	if(!element_ || !element_->IsVisible()) return;
	
	auto input=GetSubsystem<Input>();
	if(input->GetKeyPress(KEY_E))
	{
		if(selectedGroup_)
		{
			IntVector2 mousepos=input->GetMousePosition();
			Vector3 ground;
			bool s=camera_->PickGround(ground, mousepos);
			if(s)
			{
				selectedGroup_->AddKnot(ground);
				selectedGroup_->UpdateKnotHeights();
				selectedGroup_->BuildRibbon();
			}
		}
	}
	else if(input->GetKeyPress(KEY_Q))
	{
		if(selectedGroup_)
		{
			selectedGroup_->RemoveLastKnot();
			selectedGroup_->UpdateKnotHeights();
			selectedGroup_->BuildRibbon();
		}
	}
}