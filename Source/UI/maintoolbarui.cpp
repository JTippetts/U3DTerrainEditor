#include "maintoolbarui.h"
#include "terraintexturingui.h"
#include "editheightui.h"
#include "editwaterui.h"
#include "smoothheightui.h"
#include "editmaskui.h"
#include "nodegraphui.h"
#include "waypointgroupui.h"
#include "terrainsettingsui.h"
#include "filtersui.h"

#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Resource/XMLFile.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <Urho3D/UI/UIElement.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/UI/BorderImage.h>
#include <Urho3D/UI/Text.h>
#include <Urho3D/UI/Slider.h>
#include <Urho3D/UI/CheckBox.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/UI/LineEdit.h>
#include <Urho3D/Core/StringUtils.h>
#include <Urho3D/IO/Log.h>

#include "../format.h"

MainToolbarUI::MainToolbarUI(Context *context) : Object(context),
	editHeightUI_(nullptr),
	terrainTexturingUI_(nullptr)
{
}

void MainToolbarUI::Construct(EditHeightUI *eh, TerrainTexturingUI *tt, EditWaterUI *ew, SmoothHeightUI *sh, EditMaskUI *em, NodeGraphUI *ng, WaypointGroupUI *wp, TerrainSettingsUI *ts, FiltersUI *f)
{
	editHeightUI_=eh;
	terrainTexturingUI_=tt;
	editWater_=ew;
	smoothHeight_=sh;
	editMask_=em;
	nodeGraph_=ng;
	waypointGroups_=wp;
	terrainSettings_=ts;
	filters_=f;

	auto cache=GetSubsystem<ResourceCache>();
	auto ui=GetSubsystem<UI>();
	auto graphics=GetSubsystem<Graphics>();

	element_=ui->LoadLayout(cache->GetResource<XMLFile>("UI/TerrainMainToolbar.xml"));
	if(element_)
	{
		ui->GetRoot()->GetChild("Base",true)->AddChild(element_);
		SubscribeToEvent(element_->GetChild("TerrainSettings",true), StringHash("Toggled"), URHO3D_HANDLER(MainToolbarUI, HandleToggled));
		SubscribeToEvent(element_->GetChild("EditHeight",true), StringHash("Toggled"), URHO3D_HANDLER(MainToolbarUI, HandleToggled));
		SubscribeToEvent(element_->GetChild("EditWater",true), StringHash("Toggled"), URHO3D_HANDLER(MainToolbarUI, HandleToggled));
		SubscribeToEvent(element_->GetChild("SmoothHeight",true), StringHash("Toggled"), URHO3D_HANDLER(MainToolbarUI, HandleToggled));
		SubscribeToEvent(element_->GetChild("EditLayer",true), StringHash("Toggled"), URHO3D_HANDLER(MainToolbarUI, HandleToggled));
		SubscribeToEvent(element_->GetChild("EditMask",true), StringHash("Toggled"), URHO3D_HANDLER(MainToolbarUI, HandleToggled));
		SubscribeToEvent(element_->GetChild("EditNoiseGraphs",true), StringHash("Toggled"), URHO3D_HANDLER(MainToolbarUI, HandleToggled));
		SubscribeToEvent(element_->GetChild("EditWaypoints",true), StringHash("Toggled"), URHO3D_HANDLER(MainToolbarUI, HandleToggled));
		SubscribeToEvent(element_->GetChild("Filters",true), StringHash("Toggled"), URHO3D_HANDLER(MainToolbarUI, HandleToggled));
		SubscribeToEvent(element_->GetChild("Help",true), StringHash("Toggled"), URHO3D_HANDLER(MainToolbarUI, HandleToggled));
	}
}

void MainToolbarUI::SetVisible(bool v)
{
	if(element_) element_->SetVisible(v);
}

void MainToolbarUI::HandleToggled(StringHash eventType, VariantMap &eventData)
{
	UIElement *e=static_cast<UIElement *>(eventData["Element"].GetPtr());
	String name=e->GetName();
	bool state=eventData["State"].GetBool();

	if(state)
	{
		UncheckToolbar(name);
	}

	if(name=="EditHeight")
	{
		if(state)
		{
			editHeightUI_->SetVisible(true);
			// cam->SetTrackSurface(false);
		}
		else
		{
			editHeightUI_->SetVisible(false);
			// cam->SetTrackSurface(true);
		}
	}
	else if(name=="EditLayer")
	{
		terrainTexturingUI_->SetVisible(state);
	}
	else if(name=="EditWater")
	{
		editWater_->SetVisible(state);
	}
	else if(name=="SmoothHeight")
	{
		smoothHeight_->SetVisible(state);
	}
	else if(name=="EditMask")
	{
		editMask_->SetVisible(state);
	}
	else if(name=="EditNoiseGraphs")
	{
		nodeGraph_->SetVisible(state);
	}
	else if(name=="EditWaypoints")
	{
		waypointGroups_->SetVisible(state);
	}
	else if(name=="TerrainSettings")
	{
		terrainSettings_->SetVisible(state);
	}
	else if(name=="Filters")
	{
		filters_->SetVisible(state);
	}

/*
local e=eventData["Element"]:GetPtr("UIElement")
	local name=e:GetName()
	if eventData["State"]:GetBool() then
		self:UncheckToolbar(name)
	end

	if name=="TerrainSettings" then
		if eventData["State"]:GetBool() then
			saveloadui:Activate()
		else
			saveloadui:Deactivate()
		end
	elseif name=="EditHeight" then
		if eventData["State"]:GetBool() then
			self.heightbrush:Activate()
			cam.tracksurface=false   -- Deactivate camera surface tracking while editing height
		else
			self.heightbrush:Deactivate()
			cam.tracksurface=true
		end
	elseif name=="EditWater" then
		if eventData["State"]:GetBool() then
			self.waterbrush:Activate()
		else
			self.waterbrush:Deactivate()
		end
	elseif name=="SmoothHeight" then
		if eventData["State"]:GetBool() then
			self.smoothbrush:Activate()
		else
			self.smoothbrush:Deactivate()
		end
	elseif name=="EditLayer" then
		if eventData["State"]:GetBool() then
			self.blendbrush:Activate()
		else
			self.blendbrush:Deactivate()
		end
	elseif name=="EditMask" then
		if eventData["State"]:GetBool() then
			self.maskbrush:Activate(0)
		else
			self.maskbrush:Deactivate()
		end
	elseif name=="EditNoiseGraphs" then
		if eventData["State"]:GetBool() then
			self.nodegraph:Activate()
		else
			self.nodegraph:Deactivate()
		end
	elseif name=="EditWaypoints" then
		if eventData["State"]:GetBool() then
			self.splinegroups:Activate()
		else
			self.splinegroups:Deactivate()
		end
	elseif name=="Filters" then
		if eventData["State"]:GetBool() then
			filterui:Activate()
		else
			filterui:Deactivate()
		end
	elseif name=="Help" then

	end*/
}

void MainToolbarUI::UncheckToolbar(const String &except)
{
	if(except!="EditHeight")
	{
		element_->GetChildDynamicCast<CheckBox>("EditHeight", true)->SetChecked(false);
		editHeightUI_->SetVisible(false);
	}
	if(except!="EditLayer")
	{
		element_->GetChildDynamicCast<CheckBox>("EditLayer", true)->SetChecked(false);
		terrainTexturingUI_->SetVisible(false);
	}
	if(except!="TerrainSettings")
	{
		element_->GetChildDynamicCast<CheckBox>("TerrainSettings", true)->SetChecked(false);
	}
	if(except!="EditWater")
	{
		element_->GetChildDynamicCast<CheckBox>("EditWater", true)->SetChecked(false);
	}
	if(except!="SmoothHeight")
	{
		element_->GetChildDynamicCast<CheckBox>("SmoothHeight", true)->SetChecked(false);
	}
	if(except!="EditMask")
	{
		element_->GetChildDynamicCast<CheckBox>("EditMask", true)->SetChecked(false);
	}
	if(except!="EditNoiseGraphs")
	{
		element_->GetChildDynamicCast<CheckBox>("EditNoiseGraphs", true)->SetChecked(false);
	}
	if(except!="EditWaypoints")
	{
		element_->GetChildDynamicCast<CheckBox>("EditWaypoints", true)->SetChecked(false);
	}
	if(except!="Filters")
	{
		element_->GetChildDynamicCast<CheckBox>("Filters", true)->SetChecked(false);
	}
	if(except!="Help")
	{
		element_->GetChildDynamicCast<CheckBox>("Help", true)->SetChecked(false);
	}

	/*
	if except~="TerrainSettings" then self.toolbar:GetChild("TerrainSettings",true).checked=false saveloadui:Deactivate() end
	if except~="EditHeight" then self.toolbar:GetChild("EditHeight",true).checked=false self.heightbrush:Deactivate() end
	if except~="EditWater" then self.toolbar:GetChild("EditWater",true).checked=false self.waterbrush:Deactivate() end
	if except~="SmoothHeight" then self.toolbar:GetChild("SmoothHeight",true).checked=false self.smoothbrush:Deactivate() end
	if except~="EditLayer" then self.toolbar:GetChild("EditLayer",true).checked=false self.blendbrush:Deactivate() end
	if except~="EditMask" then self.toolbar:GetChild("EditMask",true).checked=false self.maskbrush:Deactivate() end
	if except~="EditNoiseGraphs" then self.toolbar:GetChild("EditNoiseGraphs",true).checked=false self.nodegraph:Deactivate() end
	if except~="EditWaypoints" then self.toolbar:GetChild("EditWaypoints",true).checked=false self.splinegroups:Deactivate() end
	if except~="Filters" then self.toolbar:GetChild("Filters",true).checked=false filterui:Deactivate() end
	if except~="Help" then self.toolbar:GetChild("Help",true).checked=false end*/
}
