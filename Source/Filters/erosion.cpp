#include "erosion.h"

ErosionFilter::ErosionFilter(Context *context,TerrainContext *tc, WaypointGroupUI *wg) : FilterBase(context, tc, wg)
{
	name_="Erosion";
	description_="Erode terrain using a simulated water droplet model.";
	options_=
	{
		{"Power: ", 0.3f},
		{"Iterations: ", 1.0f},
		{"Smoothing Power", 1.f},
		{"Use Mask 0? ", false},
		{"Invert Mask 0? ", false},
		{"Use Mask 1? ", false},
		{"Invert Mask 1? ", false},
		{"Use Mask 2? ", false},
		{"Invert Mask 2? ", false}
	};
}

void ErosionFilter::Execute()
{	
	MaskSettings ms(options_[3].flag_, options_[4].flag_, options_[5].flag_, options_[6].flag_, options_[7].flag_, options_[8].flag_);
	
	float power=options_[0].value_;
	int iterations=(int)options_[1].value_;
	float smoothpower=options_[2].value_;
	
	CArray2Dd arr;
	terrainContext_->GetHeightMap(arr);
	for(int c=0; c<iterations; ++c)
	{
		simpleErode(arr,0,power);
	}
	
	terrainContext_->SetHeightBuffer(arr,ms,0);
	
	if(smoothpower > 0.f)
	{
		terrainContext_->ApplySmoothing(smoothpower, ms);
	}
}
