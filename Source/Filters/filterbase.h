#pragma once

// FilterBase
// Abstract base class for filters.
#include <Urho3D/Core/Object.h>
#include <Urho3D/Core/Context.h>
#include <Urho3D/UI/UIElement.h>
#include <Urho3D/UI/DropDownList.h>

#include <vector>

#include "../UI/waypointgroupui.h"
#include "../terraincontext.h"
#include "../../ThirdParty/accidental-noise-library/anl.h"

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
	ea::string name_;
	float value_;
	bool flag_;
	ea::string string_;
	std::vector<ea::string> listEntries_;
	ea::string listSelection_;
	std::vector<Vector3> splineKnots_;

	DropDownList *splinelist_;

	FilterOption() : type_(OT_VALUE), value_(0), splinelist_(nullptr){}
	FilterOption(const ea::string &name, unsigned int type) : type_(type), name_(name), value_(0), flag_(false), splinelist_(nullptr){}
	FilterOption(const ea::string &name, float value) : type_(OT_VALUE), name_(name), value_(value), splinelist_(nullptr){}
	FilterOption(const ea::string &name, bool flag) : type_(OT_FLAG), name_(name), flag_(flag), splinelist_(nullptr){}
	FilterOption(const ea::string &name, const ea::string &s) : type_(OT_STRING), name_(name), string_(s), splinelist_(nullptr){}
	FilterOption(const ea::string &name, const std::vector<ea::string> &s) : type_(OT_LIST), name_(name), listEntries_(s), splinelist_(nullptr){}
};

class FilterBase : public Object
{
	URHO3D_OBJECT(FilterBase, Object);
	public:
	FilterBase(Context *context,TerrainContext *tc, WaypointGroupUI *wg);

	void Select(UIElement *optionwindow);
	virtual void Execute()=0;
	const ea::string &GetName(){return name_;}
	const ea::string &GetDescription(){return description_;}
	void RebuildSplineLists();
	void GatherOptions();

	protected:
	TerrainContext *terrainContext_;
	WaypointGroupUI *waypointGroups_;

	std::vector<FilterOption> options_;
	UIElement *optionwindow_;
	ea::string name_, description_;

	void BuildOption(FilterOption &option);
	void BuildOptionList();
};
