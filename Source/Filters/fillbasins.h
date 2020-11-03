#pragma once

#include "filterbase.h"

class FillBasinsFilter : public FilterBase
{
	URHO3D_OBJECT(FillBasinsFilter, FilterBase);
	public:
	FillBasinsFilter(Context *context,TerrainContext *tc, WaypointGroupUI *wg);
	
	virtual void Execute() override;
};
