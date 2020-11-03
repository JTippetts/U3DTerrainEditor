#pragma once

// FilterBase
// Abstract base class for filters.
#include <Urho3D/Core/Object.h>
#include <Urho3D/Core/Context.h>
#include <Urho3D/UI/UIElement.h>

#include <vector>

#include "../UI/waypointgroupui.h"
#include "../terraincontext.h"

using namespace Urho3D;

enum OptionTypes
{
	OT_VALUE,
	OT_FLAG,
	OT_STRING,
	OT_LIST,
	OT_SPLINE
};

class TerrainContext;
class WaypointGroupUI;
struct FilterOption
{
	unsigned int type_;
	String name_;
	float value_;
	bool flag_;
	String string_;
	std::vector<String> listEntries_;
	String listSelection_;
	std::vector<Vector3> splineKnots_;
	
	FilterOption() : type_(OT_VALUE), value_(0){}
	FilterOption(const String &name, unsigned int type) : type_(type), name_(name), value_(0), flag_(false){}
	FilterOption(const String &name, float value) : type_(OT_VALUE), name_(name), value_(value){}
	FilterOption(const String &name, bool flag) : type_(OT_FLAG), name_(name), flag_(flag){}
	FilterOption(const String &name, const String &s) : type_(OT_STRING), name_(name), string_(s){}
	FilterOption(const String &name, const std::vector<String> &s) : type_(OT_LIST), name_(name), listEntries_(s){}
};

class FilterBase : public Object
{
	URHO3D_OBJECT(FilterBase, Object);
	public:
	FilterBase(Context *context,TerrainContext *tc, WaypointGroupUI *wg);
	
	void Select(UIElement *optionwindow);
	virtual void Execute()=0;
	const String &GetName(){return name_;}
	const String &GetDescription(){return description_;}
	void GatherOptions();
	
	protected:
	TerrainContext *terrainContext_;
	WaypointGroupUI *waypointGroups_;
	
	std::vector<FilterOption> options_;
	UIElement *optionwindow_;
	String name_, description_;
	
	void BuildOption(FilterOption &option);
	void BuildOptionList();
};
