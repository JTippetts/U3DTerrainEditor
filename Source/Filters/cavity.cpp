#include "cavity.h"
#include "../../ThirdParty/accidental-noise-library/anl.h"

CavityFilter::CavityFilter(Context *context,TerrainContext *tc, WaypointGroupUI *wg) : FilterBase(context, tc, wg)
{
	name_="Cavity Map";
	description_="Set cavities to a specified terrain texture.";
	options_=
	{
		{"Layer", {"Layer 0", "Layer 1", "Layer 2", "Layer 3", "Layer 4", "Layer 5", "Layer 6", "Layer 7"}},
		{"Sample radius: ", 0.01f},
		{"Min scale: ", 0.0f},
		{"Max scale: ", 1.0f},
		{"Replace value? ", false},
		{"Use Mask 0? ", false},
		{"Invert Mask 0? ", false},
		{"Use Mask 1? ", false},
		{"Invert Mask 1? ", false},
		{"Use Mask 2? ", false},
		{"Invert Mask 2? ", false}
	};
}

void CavityFilter::Execute()
{
	CArray2Dd arr;
	terrainContext_->GetCavityMap(arr, options_[1].value_, 0, 0, 1, 2);
	arr.scaleToRange(options_[2].value_, options_[3].value_);
	const String &sel=options_[0].listSelection_;
	unsigned int which=0;
	if(sel=="Layer 1") which=1;
	else if(sel=="Layer 2") which=2;
	else if(sel=="Layer 3") which=3;
	else if(sel=="Layer 4") which=4;
	else if(sel=="Layer 5") which=5;
	else if(sel=="Layer 6") which=6;
	else if(sel=="Layer 7") which=7;
	
	MaskSettings ms(options_[5].flag_, options_[6].flag_, options_[7].flag_, options_[8].flag_, options_[9].flag_, options_[10].flag_);
	if(options_[4].flag_)
	{
		terrainContext_->SetLayerBuffer(arr, which, ms);
	}
	else
	{
		terrainContext_->SetLayerBufferMax(arr, which, ms);
	}
}
