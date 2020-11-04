#pragma once

#include "filterbase.h"

class RoadBuilderFilter : public FilterBase
{
	URHO3D_OBJECT(RoadBuilderFilter, FilterBase);
	public:
	RoadBuilderFilter(Context *context,TerrainContext *tc, WaypointGroupUI *wg);
	
	virtual void Execute() override;
};
