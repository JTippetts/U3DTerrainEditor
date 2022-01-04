#include "fillbasins.h"
#include "../../ThirdParty/accidental-noise-library/anl.h"

#include <Urho3D/IO/Log.h>

FillBasinsFilter::FillBasinsFilter(Context *context,TerrainContext *tc, WaypointGroupUI *wg) : FilterBase(context, tc, wg)
{
	name_="Fill Basins";
	description_="Fill basins, and either set as terrain, water, mask or layer.";
	options_=
	{
		{"Layer", {"Terrain", "Water", "Mask0", "Mask1", "Mask2", "Layer 0", "Layer 1", "Layer 2", "Layer 3", "Layer 4", "Layer 5", "Layer 6", "Layer 7"}},
		{"Max delta: ", 0.0005f},
		{"Offset water surface: ", 0.002f},
		{"Use Mask 0? ", false},
		{"Invert Mask 0? ", false},
		{"Use Mask 1? ", false},
		{"Invert Mask 1? ", false},
		{"Use Mask 2? ", false},
		{"Invert Mask 2? ", false}
	};
}

void FillBasinsFilter::Execute()
{
	CArray2Dd arr;
	const ea::string &sel=options_[0].listSelection_;
	MaskSettings ms(options_[3].flag_, options_[4].flag_, options_[5].flag_, options_[6].flag_, options_[7].flag_, options_[8].flag_);

	float E=options_[1].value_;
	terrainContext_->GetHeightMap(arr);
	terrainContext_->FillBasins(arr, E);

	if(sel=="Terrain")
	{
		terrainContext_->SetHeightBuffer(arr, ms, 0);
	}
	else if(sel=="Water")
	{
		float off=options_[2].value_;
		CArray2Dd ter;
		terrainContext_->GetHeightMap(ter);
		arr.subtractArray(&ter);
		CArray2Dd buf(arr.width(), arr.height());

		auto neighborIsNonZero=[](CArray2Dd &a, int x, int y)->bool
		{
			for(int j=-1; j<=1; ++j)
			{
				for(int i=-1; i<=1; ++i)
				{
					int nx=x+i;
					int ny=y+j;
					if(nx>=0 && ny>=0 && nx<a.width() && ny<a.height())
					{
						if(a.get(nx,ny)>0) return true;
					}
				}
			}
			return false;
		};

		for(int y=0; y<arr.height(); ++y)
		{
			for(int x=0; x<arr.width(); ++x)
			{
				float msk=arr.get(x,y);
				if(msk>0.0f) msk=1.0f;
				buf.set(x,y,msk);
			}
		}

		CArray2Dd buf2(arr.width(), arr.height());
		for(int y=0; y<arr.height(); ++y)
		{
			for(int x=0; x<arr.width(); ++x)
			{
				//URHO3D_LOGINFO(ea::string("x: ")+String(x) + " y: " + String(y) + " w: " + String(buf.width()) + " h: " + String(buf.height()));
				float msk=buf.get(x,y);
				if(neighborIsNonZero(buf, x, y)) msk=1.0f;
				buf2.set(x,y,msk);
			}
		}


		for(int y=0; y<arr.height(); ++y)
		{
			for(int x=0; x<arr.width(); ++x)
			{
				float msk=buf2.get(x,y);
				arr.set(x,y,arr.get(x,y)+msk*ter.get(x,y)-off);
			}
		}
		terrainContext_->SetWaterBuffer(arr, ms, 0);
	}
	else if(sel=="Mask0" || sel=="Mask1" || sel=="Mask2")
	{
		CArray2Dd ter;
		terrainContext_->GetHeightMap(ter);
		arr.subtractArray(&ter);

		arr.scaleToRange(0,1);
		if(sel=="Mask0") terrainContext_->SetMaskBuffer(arr,0);
		else if(sel=="Mask1") terrainContext_->SetMaskBuffer(arr,1);
		else terrainContext_->SetMaskBuffer(arr, 2);
	}
	else if(sel=="Layer 0" || sel=="Layer 1" || sel=="Layer 2" || sel=="Layer 3" || sel=="Layer 4" || sel=="Layer 5" || sel=="Layer 6" || sel=="Layer 7")
	{
		unsigned int which=0;
		if(sel=="Layer 1") which=1;
		else if(sel=="Layer 2") which=2;
		else if(sel=="Layer 3") which=3;
		else if(sel=="Layer 4") which=4;
		else if(sel=="Layer 5") which=5;
		else if(sel=="Layer 6") which=6;
		else if(sel=="Layer 7") which=7;

		CArray2Dd ter;
		terrainContext_->GetHeightMap(ter);
		arr.subtractArray(&ter);

		arr.scaleToRange(0,1);
		terrainContext_->SetLayerBuffer(arr, which, ms);
	}
}
