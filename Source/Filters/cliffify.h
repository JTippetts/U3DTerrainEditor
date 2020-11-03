#pragma once

#include "filterbase.h"

class CliffifyFilter : public FilterBase
{
	URHO3D_OBJECT(CliffifyFilter, FilterBase);
	public:
	CliffifyFilter(Context *context,TerrainContext *tc, WaypointGroupUI *wg);
	
	virtual void Execute() override;
};
