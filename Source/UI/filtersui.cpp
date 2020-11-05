#include "filtersui.h"
#include "../terraincontext.h"
#include "waypointgroupui.h"

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
#include <Urho3D/UI/Button.h>
#include <Urho3D/UI/Slider.h>
#include <Urho3D/IO/FileSystem.h>

#include "../Filters/cavity.h"
#include "../Filters/erosion.h"
#include "../Filters/cliffify.h"
#include "../Filters/fillbasins.h"
#include "../Filters/roadbuilder.h"
#include "../Filters/riverbuilder.h"

FiltersUI::FiltersUI(Context *context) : Object(context),
	selectedFilter_(nullptr)
{
}

void FiltersUI::Construct(TerrainContext *tc, WaypointGroupUI *wg)
{
	terrainContext_=tc;
	waypointGroups_=wg;
	
	auto ui=GetSubsystem<UI>();
	auto cache=GetSubsystem<ResourceCache>();
	auto graphics=GetSubsystem<Graphics>();
	
	element_=ui->LoadLayout(cache->GetResource<XMLFile>("UI/TerrainEditFilters.xml"), cache->GetResource<XMLFile>("UI/DefaultStyle.xml"));
	ui->GetRoot()->GetChild("Base", true)->AddChild(element_);
	element_->SetVisible(false);
	
	SharedPtr<UIElement> content(new UIElement(context_));
	content->SetStyleAuto(cache->GetResource<XMLFile>("UI/DefaultStyle.xml"));
	content->SetLayoutMode(LM_VERTICAL);
	optionswindow_=content;
	element_->GetChildDynamicCast<ScrollView>("OptionsWindow", true)->SetContentElement(content);
	optionswindow_->SetMinWidth(element_->GetChildDynamicCast<ScrollView>("OptionsWindow", true)->GetWidth()-16);
	
	SubscribeToEvent(element_->GetChild("ExecuteButton", true), StringHash("Pressed"), URHO3D_HANDLER(FiltersUI, HandleExecuteButton));
	SubscribeToEvent(element_->GetChild("List", true), StringHash("ItemSelected"), URHO3D_HANDLER(FiltersUI, HandleItemSelected));
	
	element_->SetPosition(IntVector2(graphics->GetWidth()/2-element_->GetWidth()/2, graphics->GetHeight()/2-element_->GetHeight()/2));
	
	
	// Add filters here
	AddFilter<ErosionFilter>();
	AddFilter<CavityFilter>();
	AddFilter<CliffifyFilter>();
	AddFilter<FillBasinsFilter>();
	AddFilter<RoadBuilderFilter>();
	AddFilter<RiverBuilderFilter>();
	
	BuildFilterList();
}

void FiltersUI::SetVisible(bool vis)
{
	if(element_) element_->SetVisible(vis);
	if(vis)
	{
		if(selectedFilter_) selectedFilter_->RebuildSplineLists();
	}
}

void FiltersUI::BuildFilterList()
{
	ListView *lv=element_->GetChildDynamicCast<ListView>("List", true);
	if(!lv) return;
	
	auto cache=GetSubsystem<ResourceCache>();
	auto style=cache->GetResource<XMLFile>("UI/DefaultStyle.xml");
	
	lv->RemoveAllItems();
	
	for(auto & f : filters_)
	{
		SharedPtr<Text> t(new Text(context_));
		t->SetStyle("EditorEnumAttributeText", style);
		t->SetText(f->GetName());
		lv->AddItem(t);
	}
}

void FiltersUI::HandleExecuteButton(StringHash eventType, VariantMap &eventData)
{
	if(selectedFilter_)
	{
		selectedFilter_->GatherOptions();
		selectedFilter_->Execute();
	}
}

void FiltersUI::HandleCloseButton(StringHash eventType, VariantMap &eventData)
{
	element_->SetVisible(false);
}

void FiltersUI::HandleItemSelected(StringHash eventType, VariantMap &eventData)
{
	optionswindow_->RemoveAllChildren();
	ListView *lv=element_->GetChildDynamicCast<ListView>("List", true);
	if(!lv) return;
	unsigned int selected=eventData["Selection"].GetInt();
	if(selected<0 || selected>=lv->GetNumItems()) return;
	
	FilterBase *f=filters_[selected];
	selectedFilter_=f;
	if(!f) return;
	Text *desc=element_->GetChildDynamicCast<Text>("FilterDescription", true);
	desc->SetText(f->GetDescription());
	f->Select(optionswindow_);
}

