#include "filterbase.h"

#include <Urho3D/UI/LineEdit.h>
#include <Urho3D/UI/CheckBox.h>
#include <Urho3D/UI/DropDownList.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Resource/XMLFile.h>
#include <Urho3D/Core/StringUtils.h>

FilterBase::FilterBase(Context *context, TerrainContext *tc, WaypointGroupUI *wg) : Object(context),
	terrainContext_(tc),
	waypointGroups_(wg),
	optionwindow_(nullptr)
{
	// In derived, build options vector in constructor
}

void FilterBase::Select(UIElement *optionwindow)
{
	optionwindow_=optionwindow;
	if(optionwindow_)
	{
		optionwindow_->RemoveAllChildren();
		BuildOptionList();
	}
}

void FilterBase::BuildOption(FilterOption &option)
{
	if(!optionwindow_) return;
	auto cache=GetSubsystem<ResourceCache>();
	auto style=cache->GetResource<XMLFile>("UI/DefaultStyle.xml");
	
	UIElement *window=optionwindow_->CreateChild<UIElement>();
	window->SetStyleAuto(style);
	window->SetDefaultStyle(style);
	window->SetLayoutMode(LM_HORIZONTAL);
	window->SetLayoutBorder(IntRect(5,5,5,5));
	Text *title=window->CreateChild<Text>();
	title->SetStyleAuto(style);
	title->SetText(option.name_);
	
	switch(option.type_)
	{
		case OT_VALUE:
		{
			LineEdit *edit=window->CreateChild<LineEdit>();
			edit->SetName(option.name_);
			edit->SetStyleAuto(style);
			edit->SetText(String(option.value_));
		} break;
		case OT_FLAG:
		{
			CheckBox *check=window->CreateChild<CheckBox>();
			check->SetName(option.name_);
			check->SetStyleAuto(style);
			check->SetChecked(option.flag_);
		} break;
		case OT_STRING:
		{
			LineEdit *edit=window->CreateChild<LineEdit>();
			edit->SetName(option.name_);
			edit->SetStyleAuto(style);
			edit->SetText(option.string_);
		} break;
		case OT_LIST:
		{
			DropDownList *dlist=window->CreateChild<DropDownList>();
			dlist->SetStyleAuto(style);
			dlist->SetAlignment(HA_LEFT, VA_CENTER);
			dlist->SetName(option.name_);
			dlist->SetResizePopup(true);
			for(unsigned int i=0; i<option.listEntries_.size(); ++i)
			{
				SharedPtr<Text> t=SharedPtr<Text>(new Text(context_));
				t->SetStyleAuto(style);
				t->SetText(option.listEntries_[i]);
				t->SetName(option.listEntries_[i]);
				dlist->AddItem(t);
			}
		} break;
		case OT_SPLINE:
		{
			DropDownList *dlist=window->CreateChild<DropDownList>();
			dlist->SetStyleAuto(style);
			dlist->SetAlignment(HA_LEFT, VA_CENTER);
			dlist->SetName(option.name_);
			dlist->SetResizePopup(true);
			
			std::vector<String> splines=waypointGroups_->GetGroupNames();
			if(splines.size()==0)
			{
				SharedPtr<Text> t(new Text(context_));
				t->SetStyleAuto(style);
				t->SetText("None");
				t->SetName("None");
				dlist->AddItem(t);
			}
			else
			{
				for(auto &i : splines)
				{
					SharedPtr<Text> t(new Text(context_));
					t->SetStyleAuto(style);
					t->SetText(i);
					t->SetName(i);
					dlist->AddItem(t);
				}
			}
		} break;
		
		default: break;
	};
	
	window->SetWidth(optionwindow_->GetWidth());
}

void FilterBase::BuildOptionList()
{
	for(auto &option : options_)
	{
		BuildOption(option);
	}
}

void FilterBase::GatherOptions()
{
	if(!optionwindow_) return;
	
	for(unsigned int c=0; c<options_.size(); ++c)
	{
		FilterOption &option=options_[c];
		
		switch(option.type_)
		{
			case OT_VALUE:
			{
				LineEdit *edit=optionwindow_->GetChildDynamicCast<LineEdit>(option.name_, true);
				if(edit) option.value_=ToFloat(edit->GetText());
			} break;
			case OT_FLAG:
			{
				CheckBox *check=optionwindow_->GetChildDynamicCast<CheckBox>(option.name_, true);
				if(check) option.flag_=check->IsChecked();
			} break;
			case OT_STRING:
			{
				LineEdit *edit=optionwindow_->GetChildDynamicCast<LineEdit>(option.name_, true);
				if(edit) option.string_=edit->GetText();
			} break;
			case OT_LIST:
			{
				DropDownList *dlist=optionwindow_->GetChildDynamicCast<DropDownList>(option.name_, true);
				if(dlist)
				{
					UIElement *sel=dlist->GetSelectedItem();
					if(sel) option.listSelection_=sel->GetName();
				}
			} break;
			case OT_SPLINE:
			{
				DropDownList *dlist=optionwindow_->GetChildDynamicCast<DropDownList>(option.name_, true);
				if(dlist)
				{
					UIElement *sel=dlist->GetSelectedItem();
					if(sel)
					{
						option.splineKnots_=waypointGroups_->GetGroupKnots(sel->GetName());
					}
				}
			} break;
			default: break;
		};
	}
}
