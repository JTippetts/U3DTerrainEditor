#include "riverbuilder.h"
#include "../rasterization.h"

RiverBuilderFilter::RiverBuilderFilter(Context *context,TerrainContext *tc, WaypointGroupUI *wg) : FilterBase(context, tc, wg)
{
	name_="River Builder";
	description_="Construct a river bed along a spline strip.";
	options_=
	{
		{"Spline: ", (unsigned int)OT_SPLINE},
		{"Starting bed width: ", 32.0f},
		{"Ending bed width: ", 64.f},
		{"Starting depth: ", 0.1f},
		{"Ending depth: ", 0.2f},
		{"Bed hardness: ", 0.5f},
		{"Paving hardness: ", 0.5f},
		{"Segment steps: ", 10.f},
		{"Paving layer: ", {"Layer 0", "Layer 1", "Layer 2", "Layer 3", "Layer 4", "Layer 5", "Layer 6", "Layer 7"}},
		{"Use Mask 0? ", false},
		{"Invert Mask 0? ", false},
		{"Use Mask 1? ", false},
		{"Invert Mask 1? ", false},
		{"Use Mask 2? ", false},
		{"Invert Mask 2? ", false}
	};
}

void RiverBuilderFilter::Execute()
{
	float startingbedwidth=options_[1].value_;
	float endingbedwidth=options_[2].value_;
	float startingdepth=options_[3].value_;
	float endingdepth=options_[4].value_;
	float bedhardness=options_[5].value_;
	float pavinghardness=options_[6].value_;
	int segments=(int)options_[7].value_;

	const ea::string &sel=options_[8].listSelection_;
	unsigned int which=0;
	if(sel=="Layer 1") which=1;
	else if(sel=="Layer 2") which=2;
	else if(sel=="Layer 3") which=3;
	else if(sel=="Layer 4") which=4;
	else if(sel=="Layer 5") which=5;
	else if(sel=="Layer 6") which=6;
	else if(sel=="Layer 7") which=7;

	MaskSettings ms(options_[9].flag_, options_[10].flag_, options_[11].flag_, options_[12].flag_, options_[13].flag_, options_[14].flag_);

	IntVector2 tsize=terrainContext_->GetTerrainMapSize();
	CArray2Dd buffer(tsize.x_, tsize.y_);
	CArray2Dd blend(tsize.x_, tsize.y_);
	blend.fill(0);

	std::vector<Vector3> &knots=options_[0].splineKnots_;
	RasterVertexList plist;
	for(auto k : knots)
	{
		Vector2 norm=terrainContext_->WorldToNormalized(k);
		int hx=std::floor(norm.x_ * (float)tsize.x_);
		int hy=std::floor(norm.y_ * (float)tsize.y_);
		float ht=terrainContext_->GetHeightValue(hx, (tsize.y_-1)-hy);
		plist.push_back(RasterVertex(hx, hy, ht));
	}

	RasterVertexList curve;
	TessellateLineList(&plist, &curve, segments);

	if(curve.size()==0) return;
	float lastht=curve[0].val_;
	for(unsigned int c=0; c<curve.size(); ++c)
	{
		auto &v=curve[c];
		v.val_=std::min(lastht, v.val_);
		lastht=v.val_;
	}

	for(unsigned int c=0; c<curve.size(); ++c)
	{
		auto &v=curve[c];
		float t=(float)c/(float)(curve.size()-1);
		float deep=startingdepth+t*(endingdepth-startingdepth);
		v.val_=std::max(0.0f, v.val_-deep);
	}

	RasterVertexList quad;
	BuildQuadStripVarying(&curve, &quad, startingbedwidth, endingbedwidth);
	RasterizeQuadStrip(&buffer, &quad);

	for(unsigned int c=0; c<quad.size(); ++c)
	{
		RasterVertex &v=quad[c];
		v.val_=c % 2;
	}
	RasterizeQuadStrip(&blend, &quad);
	ApplyBedFunction(&blend, bedhardness, true);
	terrainContext_->BlendHeightBuffer(buffer, blend, ms);

	quad.clear();
	BuildQuadStripVarying(&curve, &quad, startingbedwidth, endingbedwidth);
	blend.fill(0);

	for(unsigned int c=0; c<quad.size(); ++c)
	{
		RasterVertex &v=quad[c];
		v.val_=c%2;
	}
	RasterizeQuadStrip(&blend, &quad);
	ApplyBedFunction(&blend, pavinghardness, true);
	terrainContext_->SetLayerBufferMax(blend, which, ms);
}
