#include "cliffify.h"
#include "../../ThirdParty/accidental-noise-library/anl.h"

CliffifyFilter::CliffifyFilter(Context *context,TerrainContext *tc, WaypointGroupUI *wg) : FilterBase(context, tc, wg)
{
	name_="Cliffify";
	description_="Set cliffs to a specified terrain texture.";
	options_=
	{
		{"Layer", {"Layer 0", "Layer 1", "Layer 2", "Layer 3", "Layer 4", "Layer 5", "Layer 6", "Layer 7"}},
		{"Steepness: ", 0.7f},
		{"Fade: ", 0.4f},
		{"Replace value? ", false},
		{"Use Mask 0? ", false},
		{"Invert Mask 0? ", false},
		{"Use Mask 1? ", false},
		{"Invert Mask 1? ", false},
		{"Use Mask 2? ", false},
		{"Invert Mask 2? ", false}
	};
}

void CliffifyFilter::Execute()
{
	CArray2Dd arr;

	const ea::string &sel=options_[0].listSelection_;
	unsigned int which=0;
	if(sel=="Layer 1") which=1;
	else if(sel=="Layer 2") which=2;
	else if(sel=="Layer 3") which=3;
	else if(sel=="Layer 4") which=4;
	else if(sel=="Layer 5") which=5;
	else if(sel=="Layer 6") which=6;
	else if(sel=="Layer 7") which=7;

	MaskSettings ms(options_[4].flag_, options_[5].flag_, options_[6].flag_, options_[7].flag_, options_[8].flag_, options_[9].flag_);

	float fade=options_[2].value_;
	float threshold=options_[1].value_;

	terrainContext_->GetSteepness(arr, threshold, fade);

	if(options_[3].flag_)
	{
		terrainContext_->SetLayerBuffer(arr, which, ms);
	}
	else
	{
		terrainContext_->SetLayerBufferMax(arr, which, ms);
	}
}
