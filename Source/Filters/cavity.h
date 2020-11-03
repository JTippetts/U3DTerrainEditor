#pragma once

#include "filterbase.h"

class CavityFilter : public FilterBase
{
	URHO3D_OBJECT(CavityFilter, FilterBase);
	public:
	CavityFilter(Context *context,TerrainContext *tc, WaypointGroupUI *wg);
	
	virtual void Execute() override;
};
