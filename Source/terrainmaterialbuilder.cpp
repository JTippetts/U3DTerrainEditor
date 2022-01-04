#include "terrainmaterialbuilder.h"

#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/IO/Log.h>
#include <Urho3D/Graphics/Graphics.h>

#include "terraincontext.h"

TerrainMaterialBuilder::TerrainMaterialBuilder(Context *context) : Object(context),
	terraincontext_(nullptr),
	triplanar_(true), smooth_(false), bump_(true), reduce_(false),
	alpha_(nullptr),
	material_(nullptr),
	cursorx_(-100000), cursory_(-100000), cursorradius_(0.01), cursorhardness_(0.1), cursorangle_(0),
	layerScales_{1,1,1,1,1,1,1,1},
	dirty_(true)
{
}

void TerrainMaterialBuilder::Construct(TerrainContext *tc)
{
	SetTerrainContext(tc);

	diffuseTextures_ = SharedPtr<Texture2DArray>(new Texture2DArray(context_));
	normalTextures_ = SharedPtr<Texture2DArray>(new Texture2DArray(context_));

	diffuseTextures_->SetLayers(8);
	normalTextures_->SetLayers(8);

	SubscribeToEvent(StringHash("EndFrame"), URHO3D_HANDLER(TerrainMaterialBuilder, HandleEndFrame));
}

void TerrainMaterialBuilder::SetDiffuseTexture(unsigned int which, Image &image)
{
	if(!diffuseTextures_) return;
	if(which>=diffuseTextures_->GetLayers()) return;

	diffuseTextures_->SetData(which, &image);
}

void TerrainMaterialBuilder::SetNormalTexture(unsigned int which, Image &image)
{
	if(!normalTextures_) return;
	if(which>=normalTextures_->GetLayers()) return;

	normalTextures_->SetData(which, &image);
}

void TerrainMaterialBuilder::SetDiffuseTextureNames(const std::vector<ea::string> &filenames)
{
	if(!diffuseTextures_) return;
	auto cache=GetSubsystem<ResourceCache>();

	diffuseTextures_->SetLayers(filenames.size());

	for(unsigned int c=0; c<filenames.size(); ++c)
	{
		diffuseTextures_->SetData(c, cache->GetResource<Image>(filenames[c]));
	}
}

void TerrainMaterialBuilder::SetNormalTextureNames(const std::vector<ea::string> &filenames)
{
	if(!normalTextures_) return;
	auto cache=GetSubsystem<ResourceCache>();

	normalTextures_->SetLayers(filenames.size());

	for(unsigned int c=0; c<filenames.size(); ++c)
	{
		normalTextures_->SetData(c, cache->GetResource<Image>(filenames[c]));
	}
}

void TerrainMaterialBuilder::SetLayerScale(unsigned int which, float scale)
{
	if(which>=layerScales_.size()) return;

	layerScales_[which]=scale;
	dirty_=true;
}

void TerrainMaterialBuilder::SetLayerScales(const std::vector<float> &scales)
{
	layerScales_=scales;
	dirty_=true;
}

void TerrainMaterialBuilder::SetEditingCursor(float x, float y, float radius, float hardness, float angle)
{
	cursorx_=x;
	cursory_=y;
	cursorradius_=radius;
	cursorhardness_=hardness;
	cursorangle_=angle;

	//static VectorBuffer buf;
	//buf.Clear();
	//buf.WriteFloat(x);
	//buf.WriteFloat(y);
	//buf.WriteFloat(radius);
	//buf.WriteFloat(hardness);
	Vector4 buf(x,y,radius,hardness);

	Variant v(buf);
	if(material_)
	{
		material_->SetShaderParameter("Cursor", v);
		material_->SetShaderParameter("Angle", Variant(-angle*3.14159265f/180.0f));
	}
}

void TerrainMaterialBuilder::HandleEndFrame(StringHash eventType, VariantMap &eventData)
{
	if(!dirty_) return;

	// Reload material
	auto cache=GetSubsystem<ResourceCache>();
	auto graphics=GetSubsystem<Graphics>();

	ea::string matname="Materials/TerrainEdit8";
	if(triplanar_) matname+="Triplanar";
	if(smooth_) matname+="Smooth";
	if(bump_) matname+="Bump";
	if(reduce_) matname+="Reduce";
	matname+=".xml";

	material_=cache->GetResource<Material>(matname);
	if(!material_) return;

	// Upload layer scales
	/*static VectorBuffer buf;
	buf.Clear();
	bool isD3D11=graphics->GetApiName()=="D3D11" ? true : false;
	for(unsigned int c=0; c<layerScales_.size(); ++c)
	{
		buf.WriteFloat(layerScales_[c]);
		if(isD3D11)
		{
			buf.WriteFloat(0.0f);
			buf.WriteFloat(0.0f);
			buf.WriteFloat(0.0f);
		}
	}
	material_->SetShaderParameter("LayerScaling", Variant(buf));*/

	Vector4 ls1(layerScales_[0], layerScales_[1], layerScales_[2], layerScales_[3]);
	Vector4 ls2(layerScales_[4], layerScales_[5], layerScales_[6], layerScales_[7]);
	material_->SetShaderParameter("LayerScaling1", Variant(ls1));
	material_->SetShaderParameter("LayerScaling2", Variant(ls2));

	material_->SetTexture(TU_SPECULAR, diffuseTextures_);
	material_->SetTexture(TU_EMISSIVE, normalTextures_);
	material_->SetTexture(TU_VOLUMEMAP, alpha_);
	SetEditingCursor(cursorx_, cursory_, cursorradius_, cursorhardness_, cursorangle_);

	material_->SetShaderParameter("MatSpecColor", Variant(Color(0,0,0,16)));

	if(terraincontext_) terraincontext_->SetTerrainMaterial(material_);
	dirty_=false;
}
