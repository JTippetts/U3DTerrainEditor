#pragma once

#include "filterbase.h"

class ErosionFilter : public FilterBase
{
	URHO3D_OBJECT(ErosionFilter, FilterBase);
	public:
	ErosionFilter(Context *context,TerrainContext *tc, WaypointGroupUI *wg);
	
	virtual void Execute() override;
};
