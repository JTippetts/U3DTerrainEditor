#pragma once

#include "filterbase.h"

class RiverBuilderFilter : public FilterBase
{
	URHO3D_OBJECT(RiverBuilderFilter, FilterBase);
	public:
	RiverBuilderFilter(Context *context,TerrainContext *tc, WaypointGroupUI *wg);
	
	virtual void Execute() override;
};
