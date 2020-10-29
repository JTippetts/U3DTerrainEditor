#include "terraincontext.h"
#include "Components/editingcamera.h"
#include <Urho3D/IO/Log.h>
#include <Urho3D/Resource/ResourceCache.h>

void BalanceColors(Color &col0, Color &col1, int layer)
{
    // Balance colors around the given channel
    if(layer==0)
    {
        col0.r_=std::min(1.0f,col0.r_);
        float others=col0.g_+col0.b_+col0.a_+col1.r_+col1.g_+col1.b_+col1.a_;
        col0.g_=(col0.g_/others)*(1.0f-col0.r_);
        col0.b_=(col0.b_/others)*(1.0f-col0.r_);
        col0.a_=(col0.a_/others)*(1.0f-col0.r_);
        col1.r_=(col1.r_/others)*(1.0f-col0.r_);
        col1.g_=(col1.g_/others)*(1.0f-col0.r_);
        col1.b_=(col1.b_/others)*(1.0f-col0.r_);
        col1.a_=(col1.a_/others)*(1.0f-col0.r_);
    }
    else if(layer==1)
    {
        col0.g_=std::min(1.0f,col0.g_);
        float others=col0.r_+col0.b_+col0.a_+col1.r_+col1.g_+col1.b_+col1.a_;
        col0.r_=(col0.r_/others)*(1.0f-col0.g_);
        col0.b_=(col0.b_/others)*(1.0f-col0.g_);
        col0.a_=(col0.a_/others)*(1.0f-col0.g_);
        col1.r_=(col1.r_/others)*(1.0f-col0.g_);
        col1.g_=(col1.g_/others)*(1.0f-col0.g_);
        col1.b_=(col1.b_/others)*(1.0f-col0.g_);
        col1.a_=(col1.a_/others)*(1.0f-col0.g_);
    }
    else if(layer==2)
    {
        col0.b_=std::min(1.0f,col0.b_);
        float others=col0.r_+col0.g_+col0.a_+col1.r_+col1.g_+col1.b_+col1.a_;
        col0.r_=(col0.r_/others)*(1.0f-col0.b_);
        col0.g_=(col0.g_/others)*(1.0f-col0.b_);
        col0.a_=(col0.a_/others)*(1.0f-col0.b_);
        col1.r_=(col1.r_/others)*(1.0f-col0.b_);
        col1.g_=(col1.g_/others)*(1.0f-col0.b_);
        col1.b_=(col1.b_/others)*(1.0f-col0.b_);
        col1.a_=(col1.a_/others)*(1.0f-col0.b_);
    }
    else if(layer==3)
    {
        col0.a_=std::min(1.0f,col0.a_);
        float others=col0.r_+col0.g_+col0.b_+col1.r_+col1.g_+col1.b_+col1.a_;
        col0.r_=(col0.r_/others)*(1.0f-col0.a_);
        col0.g_=(col0.g_/others)*(1.0f-col0.a_);
        col0.b_=(col0.b_/others)*(1.0f-col0.a_);
        col1.r_=(col1.r_/others)*(1.0f-col0.a_);
        col1.g_=(col1.g_/others)*(1.0f-col0.a_);
        col1.b_=(col1.b_/others)*(1.0f-col0.a_);
        col1.a_=(col1.a_/others)*(1.0f-col0.a_);
    }
    else if(layer==4)
    {
        col1.r_=std::min(1.0f,col1.r_);
        float others=col1.g_+col1.b_+col1.a_+col0.r_+col0.g_+col0.b_+col0.a_;
        col1.g_=(col1.g_/others)*(1.0f-col1.r_);
        col1.b_=(col1.b_/others)*(1.0f-col1.r_);
        col1.a_=(col1.a_/others)*(1.0f-col1.r_);
        col0.r_=(col0.r_/others)*(1.0f-col1.r_);
        col0.g_=(col0.g_/others)*(1.0f-col1.r_);
        col0.b_=(col0.b_/others)*(1.0f-col1.r_);
        col0.a_=(col0.a_/others)*(1.0f-col1.r_);
    }
    else if(layer==5)
    {
        col1.g_=std::min(1.0f,col1.g_);
        float others=col1.r_+col1.b_+col1.a_+col0.r_+col0.g_+col0.b_+col0.a_;
        col1.r_=(col1.r_/others)*(1.0f-col1.g_);
        col1.b_=(col1.b_/others)*(1.0f-col1.g_);
        col1.a_=(col1.a_/others)*(1.0f-col1.g_);
        col0.r_=(col0.r_/others)*(1.0f-col1.g_);
        col0.g_=(col0.g_/others)*(1.0f-col1.g_);
        col0.b_=(col0.b_/others)*(1.0f-col1.g_);
        col0.a_=(col0.a_/others)*(1.0f-col1.g_);
    }
    else if(layer==6)
    {
        col1.b_=std::min(1.0f,col1.b_);
        float others=col1.r_+col1.g_+col1.a_+col0.r_+col0.g_+col0.b_+col0.a_;
        col1.r_=(col1.r_/others)*(1.0f-col1.b_);
        col1.g_=(col1.g_/others)*(1.0f-col1.b_);
        col1.a_=(col1.a_/others)*(1.0f-col1.b_);
        col0.r_=(col0.r_/others)*(1.0f-col1.b_);
        col0.g_=(col0.g_/others)*(1.0f-col1.b_);
        col0.b_=(col0.b_/others)*(1.0f-col1.b_);
        col0.a_=(col0.a_/others)*(1.0f-col1.b_);
    }
    else
    {
        col1.a_=std::min(1.0f,col1.a_);
        float others=col1.r_+col1.g_+col1.b_+col0.r_+col0.g_+col0.b_+col0.a_;
        col1.r_=(col1.r_/others)*(1.0f-col1.a_);
        col1.g_=(col1.g_/others)*(1.0f-col1.a_);
        col1.b_=(col1.b_/others)*(1.0f-col1.a_);
        col0.r_=(col0.r_/others)*(1.0f-col1.a_);
        col0.g_=(col0.g_/others)*(1.0f-col1.a_);
        col0.b_=(col0.b_/others)*(1.0f-col1.a_);
        col0.a_=(col0.a_/others)*(1.0f-col1.a_);
    }
}

TerrainContext::TerrainContext(Context *context) : Object(context),
	terrainNode_(nullptr),
	terrain_(nullptr),
	terrainMaterial_(nullptr),
	waterNode_(nullptr),
	water_(nullptr),
	waterMaterial_(nullptr),
	terrainMap_(context), waterMap_(context), blend0_(context), blend1_(context), mask_(context), waterDepth_(context),
	materialdirty_(true),
	watermaterialdirty_(true),
	terraindirty_(false), waterdirty_(false),
	spacing_(1.0f, 0.25f, 1.0f),
	camera_(nullptr)
{
}

void TerrainContext::Construct(Scene *scene, EditingCamera *camera)
{
	auto cache=GetSubsystem<ResourceCache>();
	
	camera_=camera;
	if(!terrainNode_) terrainNode_=scene->CreateChild("TerrainNode");
	if(!waterNode_) waterNode_=scene->CreateChild("WaterNode");
	waterNode_->SetPosition(Vector3(0,-0.1f,0));
	
	if(!terrain_)
	{
		terrain_=terrainNode_->CreateComponent<Terrain>();
		terrain_->SetCastShadows(true);
		terrain_->SetSpacing(spacing_);
	}
	if(!water_)
	{
		water_=waterNode_->CreateComponent<Terrain>();
		water_->SetSpacing(spacing_);
	}
	
	if(!blend0Tex_) blend0Tex_=SharedPtr<Texture2D>(new Texture2D(context_));
	if(!blend1Tex_) blend1Tex_=SharedPtr<Texture2D>(new Texture2D(context_));
	if(!maskTex_) maskTex_=SharedPtr<Texture2D>(new Texture2D(context_));
	if(!waterDepthTex_) waterDepthTex_=SharedPtr<Texture2D>(new Texture2D(context_));
	
	Material *watermat=cache->GetResource<Material>("Materials/FlowWater.xml");
	watermat->SetTexture(TU_SPECULAR, waterDepthTex_);
	water_->SetMaterial(watermat);
	
	blend0Tex_->SetNumLevels(1);
	blend1Tex_->SetNumLevels(1);
	maskTex_->SetNumLevels(1);
	waterDepthTex_->SetNumLevels(1);
	
	SubscribeToEvent(StringHash("BeginFrame"), URHO3D_HANDLER(TerrainContext, HandleBeginFrame)); // Update materials and textures here
}

void TerrainContext::SetSpacing(const Vector3 &s)
{
	spacing_=s;
	if(terrain_) terrain_->SetSpacing(s);
	if(water_) water_->SetSpacing(s);
}

Vector2 TerrainContext::WorldToNormalized(Vector3 world)
{
    if(!terrain_) return Vector2(0,0);
    Vector3 spacing=terrain_->GetSpacing();
    int patchSize=terrain_->GetPatchSize();
    IntVector2 numPatches=IntVector2((terrainMap_.GetWidth()-1) / patchSize, (terrainMap_.GetHeight()-1) / patchSize);
    Vector2 patchWorldSize=Vector2(spacing.x_*(float)(patchSize*numPatches.x_), spacing.z_*(float)(patchSize*numPatches.y_));
    Vector2 patchWorldOrigin=Vector2(-0.5f * patchWorldSize.x_, -0.5f * patchWorldSize.y_);
    return Vector2((world.x_-patchWorldOrigin.x_)/patchWorldSize.x_, (world.z_-patchWorldOrigin.y_)/patchWorldSize.y_);
}

Vector3 TerrainContext::NormalizedToWorld(Vector2 normalized)
{
    if(!terrain_) return Vector3(0,0,0);
    Vector3 spacing=terrain_->GetSpacing();
    int patchSize=terrain_->GetPatchSize();
    IntVector2 numPatches=IntVector2((terrainMap_.GetWidth()-1) / patchSize, (terrainMap_.GetHeight()-1) / patchSize);
    Vector2 patchWorldSize=Vector2(spacing.x_*(float)(patchSize*numPatches.x_), spacing.z_*(float)(patchSize*numPatches.y_));
    Vector2 patchWorldOrigin=Vector2(-0.5f * patchWorldSize.x_, -0.5f * patchWorldSize.y_);
    return Vector3(patchWorldOrigin.x_+normalized.x_*patchWorldSize.x_, 0, patchWorldOrigin.y_+normalized.y_*patchWorldSize.y_);
}

void TerrainContext::SetHeightMapSize(const IntVector2 &size)
{
	if(!terrain_ || !water_) return;
	
	terrainMap_.SetSize(size.x_, size.y_, 3);
	waterMap_.SetSize(size.x_, size.y_, 3);
	
	terrainMap_.Clear(Color(0,0,0));
	waterMap_.Clear(Color(0,0,0));
	
	waterDepth_.SetSize(size.x_, size.y_, 1);
	waterDepth_.Clear(Color(0,0,0));
	waterDepthTex_->SetData(&waterDepth_, false);
	
	terrain_->SetHeightMap(&terrainMap_);
	water_->SetHeightMap(&waterMap_);
	
	// Calculate map area
	Vector3 spacing=terrain_->GetSpacing();
    int patchSize=terrain_->GetPatchSize();
    IntVector2 numPatches=IntVector2((terrainMap_.GetWidth()-1) / patchSize, (terrainMap_.GetHeight()-1) / patchSize);
    Vector2 patchWorldSize=Vector2(spacing.x_*(float)(patchSize*numPatches.x_), spacing.z_*(float)(patchSize*numPatches.y_));
    Vector2 patchWorldOrigin=Vector2(-0.5f * patchWorldSize.x_, -0.5f * patchWorldSize.y_);
	
	if(camera_)
	{
		camera_->SetCameraBounds(patchWorldOrigin, patchWorldOrigin+patchWorldSize);
	}
}

void TerrainContext::SetBlendMapSize(const IntVector2 &size)
{
	if(!blend0Tex_ || !blend1Tex_) return;
	
	blend0_.SetSize(size.x_, size.y_, 4);
	blend1_.SetSize(size.x_, size.y_, 4);
	blend0_.Clear(Color(1,0,0,0));
	blend1_.Clear(Color(0,0,0,0));
	
	blend0Tex_->SetData(&blend0_, false);
	blend1Tex_->SetData(&blend1_, false);
	
	materialdirty_=true;
}

void TerrainContext::SetMaskSize(const IntVector2 &size)
{
	if(!maskTex_) return;
	
	mask_.SetSize(size.x_, size.y_, 3);
	mask_.Clear(Color(1,1,1));
	
	maskTex_->SetData(&mask_, false);
	materialdirty_=true;
}

void TerrainContext::SetTerrainMaterial(Material *m)
{
	terrainMaterial_ = m;
	materialdirty_=true;
}

void TerrainContext::SetWaterMaterial(Material *m, bool usewaterdepth)
{
	waterMaterial_=m;
	if(usewaterdepth)
	{
		waterMaterial_->SetTexture(TU_SPECULAR, waterDepthTex_);
	}
	watermaterialdirty_=true;
}

void TerrainContext::HandleBeginFrame(StringHash eventType, VariantMap &eventData)
{
	if(terrainMaterial_ && materialdirty_)
	{
		terrainMaterial_->SetTexture(TU_DIFFUSE, blend0Tex_);
		terrainMaterial_->SetTexture(TU_NORMAL, blend1Tex_);
		terrainMaterial_->SetTexture(TU_ENVIRONMENT, maskTex_);
		if(terrain_) terrain_->SetMaterial(terrainMaterial_);
		materialdirty_=false;
	}
	
	if(waterMaterial_ && watermaterialdirty_)
	{
		// nothing for now, do I even need this?
		if(water_) water_->SetMaterial(waterMaterial_);
		watermaterialdirty_=false;
	}
}

void TerrainContext::ClearHeightMap()
{
	terrainMap_.Clear(Color(0,0,0));
	if(terrain_) terrain_->SetHeightMap(&terrainMap_);
	
	// Clear water map as well
	waterMap_.Clear(Color(0,0,0));
	if(water_) water_->SetHeightMap(&waterMap_);
}

void TerrainContext::ClearBlendMaps()
{
	if(!blend0Tex_ || !blend1Tex_) return;
	
	blend0_.Clear(Color(1,0,0,0));
	blend1_.Clear(Color(0,0,0,0));
	blend0Tex_->SetData(&blend0_, false);
	blend1Tex_->SetData(&blend1_, false);
}

void TerrainContext::ClearMask()
{
	if(!maskTex_) return;
	mask_.Clear(Color(1,1,1));
	maskTex_->SetData(&mask_, false);
}

void TerrainContext::ClearWaterMap()
{
	waterMap_.Clear(Color(0,0,0));
	if(water_) water_->SetHeightMap(&waterMap_);
}

void TerrainContext::Clear()
{
	ClearHeightMap();
	ClearBlendMaps();
	ClearMask();
}

float TerrainContext::GetHeightValue(Vector3 worldpos)
{
    if(!terrain_) return 0.0f;
    IntVector2 htm=terrain_->WorldToHeightMap(worldpos);
    Color c=terrainMap_.GetPixelBilinear((float)htm.x_ / (float)terrainMap_.GetWidth(), (float)htm.y_ / (float)terrainMap_.GetHeight());
    if(terrainMap_.GetComponents()==1) return c.r_;
    else return c.r_+c.g_/255.0f;
}

float TerrainContext::GetHeight(Vector3 worldpos)
{
	if(!terrain_) return 0.0f;
	
	return terrain_->GetHeight(worldpos);
}

float TerrainContext::GetHeightValue(int x, int y)
{
	if(terrainMap_.GetComponents()==1) return terrainMap_.GetPixel(x,y).r_;
    else
    {
        Color c=terrainMap_.GetPixel(x,y);
        return c.r_+c.g_/255.0f;
    }
}

float TerrainContext::GetWaterValue(Vector3 worldpos)
{
    if(!water_) return 0.0f;
    IntVector2 htm=water_->WorldToHeightMap(worldpos);
    Color c=waterMap_.GetPixelBilinear((float)htm.x_ / (float)waterMap_.GetWidth(), (float)htm.y_ / (float)waterMap_.GetHeight());
    if(waterMap_.GetComponents()==1) return c.r_;
    else return c.r_+c.g_/255.0f;
}

void TerrainContext::SetHeightValue(int x, int y, float val)
{
	if(terrainMap_.GetComponents()==1) terrainMap_.SetPixel(x,y,Color(val,0,0));
    else
    {
        float expht=std::floor(val*255.0f);
        float rm=val*255.0f-expht;
        terrainMap_.SetPixel(x,y,Color(expht/255.0f, rm, 0));
    }
}

float TerrainContext::GetWaterValue(int x, int y)
{
	if(waterMap_.GetComponents()==1) return waterMap_.GetPixel(x,y).r_;
    else
    {
        Color c=waterMap_.GetPixel(x,y);
        return c.r_+c.g_/255.0f;
    }
}

void TerrainContext::SetWaterValue(int x, int y, float val)
{
	if(waterMap_.GetComponents()==1) waterMap_.SetPixel(x,y,Color(val,0,0));
    else
    {
        float expht=std::floor(val*255.0f);
        float rm=val*255.0f-expht;
        waterMap_.SetPixel(x,y,Color(expht/255.0f, rm, 0));
    }
}

float TerrainContext::GetHeightValueFromNormalized(Vector2 nrm)
{
	if(terrainMap_.GetComponents()==1) return terrainMap_.GetPixelBilinear(nrm.x_, nrm.y_).r_;
	else
	{
		Color c=terrainMap_.GetPixelBilinear(nrm.x_,nrm.y_);
		return c.r_+c.g_/255.0f;
	}
}

float TerrainContext::GetWaterValueFromNormalized(Vector2 nrm)
{
	if(waterMap_.GetComponents()==1) return waterMap_.GetPixelBilinear(nrm.x_, nrm.y_).r_;
	else
	{
		Color c=waterMap_.GetPixelBilinear(nrm.x_,nrm.y_);
		return c.r_+c.g_/255.0f;
	}
}

void TerrainContext::BuildWaterDepthTexture()
{
	for(unsigned int x=0; x<waterDepth_.GetWidth(); ++x)
	{
		for(unsigned int y=0; y<waterDepth_.GetHeight(); ++y)
		{
			float nx=(float)x/(float)(waterDepth_.GetWidth());
			float ny=(float)y/(float)(waterDepth_.GetHeight());
			Vector2 nrm(nx,ny);
			float ht=GetHeightValueFromNormalized(nrm);
			float wat=GetWaterValueFromNormalized(nrm);
			float v=std::max(0.0f, std::min(1.0f, (wat-ht)*16.0f));
			waterDepth_.SetPixel(x,y,Color(v,0,0));
		}
	}
	waterDepthTex_->SetData(&waterDepth_,false);
}


void TerrainContext::InvertMask(int which)
{
	for(int x=0; x<mask_.GetWidth(); ++x)
	{
		for(int y=0; y<mask_.GetHeight(); ++y)
		{
			Color m=mask_.GetPixel(x,y);
			switch(which)
			{
				case 0: m.r_=1.0f-m.r_; break;
				case 1: m.g_=1.0f-m.g_; break;
				case 2: m.b_=1.0f-m.b_; break;
				default: break;
			}
			mask_.SetPixel(x,y,m);
		}
	}
	maskTex_->SetData(&mask_, false);
}

void TerrainContext::ClearMask(int which)
{
	for(int x=0; x<mask_.GetWidth(); ++x)
	{
		for(int y=0; y<mask_.GetHeight(); ++y)
		{
			Color m=mask_.GetPixel(x,y);
			switch(which)
			{
				case 0: m.r_=1.0; break;
				case 1: m.g_=1.0; break;
				case 2: m.b_=1.0; break;
				default: break;
			}
			mask_.SetPixel(x,y,m);
		}
	}
	maskTex_->SetData(&mask_, false);
}

void TerrainContext::ClearAllMasks()
{
	mask_.Clear(Color(1,1,1));
	maskTex_->SetData(&mask_, false);
}

void TerrainContext::ApplyHeightAlpha(float x, float z, float dt, BrushSettings &brush, MaskSettings &masksettings, Image &alpha, float angle)
{
	if(!terrain_) return;
	
	Vector3 world=Vector3(x,0,z);
    IntVector2 ht=terrain_->WorldToHeightMap(world);
	
	float radius=brush.radius_*100.0f;
    int sz=(int)radius+1;
    int comp=terrainMap_.GetComponents();
	
	for(int hx=ht.x_-sz; hx<=ht.x_+sz; ++hx)
    {
        for(int hz=ht.y_-sz; hz<=ht.y_+sz; ++hz)
        {
            if(hx>=0 && hx<terrainMap_.GetWidth() && hz>=0 && hz<terrainMap_.GetHeight())
            {
                float dx=(float)(hx-ht.x_);
                float dz=(float)(hz-ht.y_);
                float d=std::sqrt(dx*dx+dz*dz);
                float i=((d-radius)/(brush.hardness_*radius-radius));
                i=std::max(0.0f, std::min(1.0f, i));
                i=(float)std::sin(i*1.57079633);

				float anx=dx/radius;
				float any=dz/radius;
				float alphanx = anx*std::cos(angle) - any*std::sin(angle);
				float alphany = any*std::cos(angle) + anx*std::sin(angle);
				alphanx=alphanx*0.5+0.5;
				alphany=alphany*0.5+0.5;
				alphanx=std::max(0.0f, std::min(1.0f, alphanx));
				alphany=std::max(0.0f, std::min(1.0f, alphany));
				float alphapower=alpha.GetPixelBilinear(alphanx,alphany).r_;
				
                i=i*dt*brush.power_*alphapower*10.0f;
				
				if(masksettings.usemask0_ || masksettings.usemask1_ || masksettings.usemask2_)
				{
					Color mask=mask_.GetPixelBilinear((float)(hx)/(float)(terrainMap_.GetWidth()), (float)(hz)/(float)(terrainMap_.GetHeight()));
				
					if(masksettings.usemask0_)
					{
						float m=mask.r_;
						if(masksettings.invert0_) m=1.0f-m;
						i=i*m;
					}
					if(masksettings.usemask1_)
					{
						float m=mask.g_;
						if(masksettings.invert1_) m=1.0f-m;
						i=i*m;
					}
					if(masksettings.usemask2_)
					{
						float m=mask.b_;
						if(masksettings.invert2_) m=1.0f-m;
						i=i*m;
					}
				}
                float hval=GetHeightValue(hx,hz);
                float newhval=hval+(brush.max_-hval)*i;
                SetHeightValue(hx,hz,newhval);

				float wt=GetWaterValue(hx,hz);
				float v=std::max(0.0f, std::min(1.0f, (wt-newhval)*16.0f));
				waterDepth_.SetPixel(hx,hz,Color(v,0,0));

            }
        }
    }

    terrain_->ApplyHeightMap();
	waterDepthTex_->SetData(&waterDepth_,false);
}

void TerrainContext::ApplyBlendAlpha(float x, float z, int layer, float dt, BrushSettings &brush, MaskSettings &masksettings, Image &alpha, float angle)
{
	if(!terrain_) return;

    Vector2 normalized=WorldToNormalized(Vector3(x,0,z));
    float ratio=((float)blend0_.GetWidth()/(float)terrainMap_.GetWidth());
    int ix=(int)(normalized.x_*(float)(blend0_.GetWidth()-1));
    int iy=(int)(normalized.y_*(float)(blend0_.GetHeight()-1));
    iy=blend0_.GetHeight()-iy;
    float rad=brush.radius_*ratio*100.0f;
    int sz=(int)rad+1;

    for(int hx=ix-sz; hx<=ix+sz; ++hx)
    {
        for(int hz=iy-sz; hz<=iy+sz; ++hz)
        {
            if(hx>=0 && hx<blend0_.GetWidth() && hz>=0 && hz<blend0_.GetHeight())
            {
                float dx=(float)hx-(float)ix;
                float dz=(float)hz-(float)iy;
                float d=std::sqrt(dx*dx+dz*dz);
                float i=((d-rad)/(brush.hardness_*rad-rad));
                i=std::max(0.0f, std::min(1.0f, i));

				float anx=dx/rad;
				float any=dz/rad;
				float alphanx = anx*std::cos(angle) - any*std::sin(angle);
				float alphany = any*std::cos(angle) + anx*std::sin(angle);
				alphanx=alphanx*0.5+0.5;
				alphany=alphany*0.5+0.5;
				alphanx=std::max(0.0f, std::min(1.0f, alphanx));
				alphany=std::max(0.0f, std::min(1.0f, alphany));
				float alphapower=alpha.GetPixelBilinear(alphanx,alphany).r_;

                i=i*dt*brush.power_*10.0f*alphapower;
                if(masksettings.usemask0_)
                {
                    float m=mask_.GetPixelBilinear((float)(hx)/(float)(blend0_.GetWidth()), (float)(hz)/(float)(blend0_.GetHeight())).r_;
                    if(masksettings.invert0_) m=1.0f-m;
                    i=i*m;
                }
                if(masksettings.usemask1_)
                {
                    float m=mask_.GetPixelBilinear((float)(hx)/(float)(blend0_.GetWidth()), (float)(hz)/(float)(blend0_.GetHeight())).g_;
                    if(masksettings.invert1_) m=1.0f-m;
                    i=i*m;
                }
                if(masksettings.usemask2_)
                {
                    float m=mask_.GetPixelBilinear((float)(hx)/(float)(blend0_.GetWidth()), (float)(hz)/(float)(blend0_.GetHeight())).b_;
                    if(masksettings.invert2_) m=1.0f-m;
                    i=i*m;
                }
                Color col0=blend0_.GetPixel(hx,hz);
                Color col1=blend1_.GetPixel(hx,hz);
                if(layer==0)
                {
                    col0.r_=col0.r_+i*(brush.max_-col0.r_);
                }
                else if(layer==1)
                {
                    col0.g_=col0.g_+i*(brush.max_-col0.g_);
                }
                else if(layer==2)
                {
                    col0.b_=col0.b_+i*(brush.max_-col0.b_);
                }
                else if(layer==3)
                {
                    col0.a_=col0.a_+i*(brush.max_-col0.a_);
                }
                else if(layer==4)
                {
                    col1.r_=col1.r_+i*(brush.max_-col1.r_);
                }
                else if(layer==5)
                {
                    col1.g_=col1.g_+i*(brush.max_-col1.g_);
                }
                else if(layer==6)
                {
                    col1.b_=col1.b_+i*(brush.max_-col1.b_);
                }
                else
                {
                    col1.a_=col1.a_+i*(brush.max_-col1.a_);
                }
                BalanceColors(col0, col1, layer);
                blend0_.SetPixel(hx,hz,col0);
                blend1_.SetPixel(hx,hz,col1);
            }
        }
    }

    blend0Tex_->SetData(&blend0_, false);
    blend1Tex_->SetData(&blend1_, false);
}

void TerrainContext::ApplyWaterBrush(float x, float z, float dt, BrushSettings &brush, MaskSettings &masksettings)
{
    if(!water_) return;

    Vector3 world=Vector3(x,0,z);
    IntVector2 ht=water_->WorldToHeightMap(world);
	
	float rad=brush.radius_*100.0f;
    int sz=(int)rad+1;
    int comp=waterMap_.GetComponents();
    for(int hx=ht.x_-sz; hx<=ht.x_+sz; ++hx)
    {
        for(int hz=ht.y_-sz; hz<=ht.y_+sz; ++hz)
        {
            if(hx>=0 && hx<waterMap_.GetWidth() && hz>=0 && hz<waterMap_.GetHeight())
            {
                float dx=(float)(hx-ht.x_);
                float dz=(float)(hz-ht.y_);
                float d=std::sqrt(dx*dx+dz*dz);
                float i=((d-rad)/(brush.hardness_*rad-rad));
                i=std::max(0.0f, std::min(1.0f, i));
                i=(float)std::sin(i*1.57079633);
                i=i*dt*brush.power_*10.0f;
                if(masksettings.usemask0_)
                {
                    float m=mask_.GetPixelBilinear((float)(hx)/(float)(waterMap_.GetWidth()), (float)(hz)/(float)(waterMap_.GetHeight())).r_;
                    if(masksettings.invert0_) m=1.0f-m;
                    i=i*m;
                }
                if(masksettings.usemask1_)
                {
                    float m=mask_.GetPixelBilinear((float)(hx)/(float)(waterMap_.GetWidth()), (float)(hz)/(float)(waterMap_.GetHeight())).g_;
                    if(masksettings.invert1_) m=1.0f-m;
                    i=i*m;
                }
                if(masksettings.usemask2_)
                {
                    float m=mask_.GetPixelBilinear((float)(hx)/(float)(waterMap_.GetWidth()), (float)(hz)/(float)(waterMap_.GetHeight())).b_;
                    if(masksettings.invert1_) m=1.0f-m;
                    i=i*m;
                }
                float hval=GetWaterValue(hx,hz);
                float newhval=hval+(brush.max_-hval)*i;
                SetWaterValue(hx,hz,newhval);

				float ht=GetHeightValue(hx,hz);
				float v=std::max(0.0f, std::min(1.0f, (newhval-ht)*16.0f));
				waterDepth_.SetPixel(hx,hz,Color(v,0,0));

            }
        }
    }

    water_->ApplyHeightMap();
	waterDepthTex_->SetData(&waterDepth_,false);
}

float TerrainContext::CalcSmooth(Image *height, float *kernel, int kernelsize, int terrainx, int terrainz)
{
    float sum=0.0f;
    float weight=0.0f;
    int ox=terrainx-int(kernelsize/2);
    int oz=terrainz-int(kernelsize/2);
	unsigned int comp=height->GetComponents();

    for(int x=0; x<kernelsize; ++x)
    {
        for(int z=0; z<kernelsize; ++z)
        {
            int nx=x+ox;
            int nz=z+oz;
            if(x>=0 && x<height->GetWidth() && z>=0 && z<height->GetHeight())
            {
				Color c=height->GetPixel(nx,nz);
                float hval=(comp==1) ? c.r_ : c.r_+c.g_/255.0f;//GetHeightValue(height,nx,nz);
                sum+=hval*kernel[z*kernelsize+x];
                weight+=kernel[z*kernelsize+x];
            }
        }
    }
    if(weight>0) return sum/weight;
    else return 0.0f;
}

void TerrainContext::ApplySmoothBrush(float x, float z, float dt, BrushSettings &brush, MaskSettings &masksettings)
{
    static float kernel[81]=
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0.0058874471228999, 0.012503642863169, 0.014925760324933, 0.012503642863169, 0.0058874471228999, 0, 0,
        0, 0.0058874471228999, 0.017486615939231, 0.026328026597312, 0.029851520649865, 0.026328026597312, 0.017486615939231, 0.0058874471228999, 0,
        0, 0.012503642863169, 0.026328026597312, 0.038594828619481, 0.044777280974798, 0.038594828619481, 0.026328026597312, 0.012503642863169, 0,
        0, 0.014925760324933, 0.029851520649865, 0.044777280974798, 0.059703041299731, 0.044777280974798, 0.029851520649865, 0.014925760324933, 0,
        0, 0.012503642863169, 0.026328026597312, 0.038594828619481, 0.044777280974798, 0.038594828619481, 0.026328026597312, 0.012503642863169, 0,
        0, 0.0058874471228999, 0.017486615939231, 0.026328026597312, 0.029851520649865, 0.026328026597312, 0.017486615939231, 0.0058874471228999, 0,
        0, 0, 0.0058874471228999, 0.012503642863169, 0.014925760324933, 0.012503642863169, 0.0058874471228999, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    if(!terrain_) return;

    Vector3 world=Vector3(x,0,z);
    IntVector2 ht=terrain_->WorldToHeightMap(world);
	
	float rad=brush.radius_*100.0f;
    int sz=(int)rad+1;
    int comp=terrainMap_.GetComponents();
    for(int hx=ht.x_-sz; hx<=ht.x_+sz; ++hx)
    {
        for(int hz=ht.y_-sz; hz<=ht.y_+sz; ++hz)
        {
            if(hx>=0 && hx<terrainMap_.GetWidth() && hz>=0 && hz<terrainMap_.GetHeight())
            {
                float dx=(float)(hx-ht.x_);
                float dz=(float)(hz-ht.y_);
                float d=std::sqrt(dx*dx+dz*dz);
                float i=((d-rad)/(brush.hardness_*rad-rad));
                i=std::max(0.0f, std::min(1.0f, i));
                i=i*dt*brush.power_*10.0f;
                if(masksettings.usemask0_)
                {
                    float m=mask_.GetPixelBilinear((float)(hx)/(float)(terrainMap_.GetWidth()), (float)(hz)/(float)(terrainMap_.GetHeight())).r_;
                    if(masksettings.invert0_) m=1.0f-m;
                    i=i*m;
                }
                if(masksettings.usemask1_)
                {
                    float m=mask_.GetPixelBilinear((float)(hx)/(float)(terrainMap_.GetWidth()), (float)(hz)/(float)(terrainMap_.GetHeight())).g_;
                    if(masksettings.invert1_) m=1.0f-m;
                    i=i*m;
                }
                if(masksettings.usemask2_)
                {
                    float m=mask_.GetPixelBilinear((float)(hx)/(float)(terrainMap_.GetWidth()), (float)(hz)/(float)(terrainMap_.GetHeight())).b_;
                    if(masksettings.invert2_) m=1.0f-m;
                    i=i*m;
                }
                float hval=GetHeightValue(hx,hz);
                float smooth=CalcSmooth(&terrainMap_,kernel,9,hx,hz);
                float newhval=hval+(smooth-hval)*i;
                SetHeightValue(hx,hz,newhval);
            }
        }
    }
    terrain_->ApplyHeightMap();
}

void TerrainContext::ApplyMaskBrushAlpha(float x, float z, int which, float dt, BrushSettings &brush, MaskSettings &masksettings, Image &alpha, float angle)
{
    if(!terrain_) return;

    Vector2 normalized=WorldToNormalized(Vector3(x,0,z));
    float ratio=((float)mask_.GetWidth()/(float)terrainMap_.GetWidth());
    int ix=(int)(normalized.x_*(float)(mask_.GetWidth()-1));
    int iy=(int)(normalized.y_*(float)(mask_.GetHeight()-1));
    iy=mask_.GetHeight()-iy;
    float rad=brush.radius_*ratio*100.0f;
    int sz=(int)rad+1;

    for(int hx=ix-sz; hx<=ix+sz; ++hx)
    {
        for(int hz=iy-sz; hz<=iy+sz; ++hz)
        {
            if(hx>=0 && hx<mask_.GetWidth() && hz>=0 && hz<mask_.GetHeight())
            {
                float dx=(float)hx-(float)ix;
                float dz=(float)hz-(float)iy;
                float d=std::sqrt(dx*dx+dz*dz);
                float i=((d-rad)/(brush.hardness_*rad-rad));
                i=std::max(0.0f, std::min(1.0f, i));
				float anx=dx/rad;
				float any=dz/rad;

				float alphanx = anx*std::cos(angle) - any*std::sin(angle);
				float alphany = any*std::cos(angle) + anx*std::sin(angle);

				alphanx=alphanx*0.5+0.5;
				alphany=alphany*0.5+0.5;
				alphanx=std::max(0.0f, std::min(1.0f, alphanx));
				alphany=std::max(0.0f, std::min(1.0f, alphany));
				float alphapower=alpha.GetPixelBilinear(alphanx,alphany).r_;

                i=i*dt*brush.power_*alphapower*10.0f;

                Color col=mask_.GetPixel(hx,hz);
                if(which==0)
                    col.r_=col.r_+i*((1.0f-brush.max_)-col.r_);
                else if(which==1)
                    col.g_=col.g_+i*((1.0f-brush.max_)-col.g_);
                else
                    col.b_=col.b_+i*((1.0f-brush.max_)-col.b_);
                mask_.SetPixel(hx,hz,col);
            }
        }
    }

    maskTex_->SetData(&mask_, false);
}

void TerrainContext::SetHeightBuffer(CArray2Dd &buffer, MaskSettings &masksettings, int blendop)
{
    if(!terrain_) return;

    int w=terrainMap_.GetWidth();
    int h=terrainMap_.GetHeight();

    for(int x=0; x<=w; ++x)
    {
        for(int y=0; y<=h; ++y)
        {
            float nx=(float)x/(float)(w);
            float ny=(float)y/(float)(h);

            float v=buffer.getBilinear(nx,ny);
            Color mask=mask_.GetPixelBilinear(nx,ny);
            float oldheight=GetHeightValue(x,y);
            float maskval=1.0f;

            if(masksettings.usemask0_)
            {
                float mval=mask.r_;
                if(masksettings.invert0_) mval=1.0f-mval;
                maskval*=mval;
            }
            if(masksettings.usemask1_)
            {
                float mval=mask.g_;
                if(masksettings.invert1_) mval=1.0f-mval;
                maskval*=mval;
            }
            if(masksettings.usemask2_)
            {
                float mval=mask.b_;
                if(masksettings.invert2_) mval=1.0f-mval;
                maskval*=mval;
            }

			float newval=0.0f;

			switch(blendop)
			{
				case HeightReplace: newval=v; break;
				case HeightAdd: newval=oldheight+v; break;
				case HeightSubtract: newval=oldheight-v; break;
				case HeightMultiply: newval=oldheight*v; break;
				case HeightMin: newval=std::min(v, oldheight); break;
				case HeightMax: newval=std::max(v, oldheight); break;
				default: newval=v; break;
			}

            v=oldheight+maskval*(newval-oldheight);
            SetHeightValue(x,y,(float)v);
        }
    }
    terrain_->ApplyHeightMap();
	BuildWaterDepthTexture();
}

void TerrainContext::SetMaskBuffer(CArray2Dd &buffer, int which)
{
	int w=mask_.GetWidth();
	int h=mask_.GetHeight();
	for(int x=0; x<w; ++x)
	{
		for(int y=0; y<h; ++y)
		{
			float nx=(float)x/(float)(w);
            float ny=(float)y/(float)(h);

            double v=buffer.getBilinear(nx,ny);
            Color mask=mask_.GetPixel(x,y);
			switch(which)
			{
				case 0: mask.r_ = 1.0f-(float)v; break;
				case 1: mask.g_ = 1.0f- (float)v; break;
				case 2: mask.b_ = 1.0f- (float)v; break;
				default: break;
			}
			mask_.SetPixel(x,y,mask);
		}
	}
	maskTex_->SetData(&mask_,false);
}

void TerrainContext::SetLayerBuffer(CArray2Dd &buffer, int layer, MaskSettings &masksettings)
{
    if(!terrain_) return;

    //if(buffer.width()!=blend0_.GetWidth() || buffer.height()!=blend0_.GetHeight()) return;
    int w=blend0_.GetWidth();
    int h=blend0_.GetHeight();

    for(int x=0; x<w; ++x)
    {
        for(int y=0; y<h; ++y)
        {
            float nx=(float)x/(float)(w);
            float ny=(float)y/(float)(h);

            float i=(float)buffer.getBilinear(nx,ny);
            i=std::max(0.0f, std::min(1.0f, i));
            Color mask=mask_.GetPixelBilinear(nx,ny);

            if(masksettings.usemask0_)
            {
                float m=mask.r_;
                if(masksettings.invert0_) m=1.0f-m;
                i*=m;
            }
            if(masksettings.usemask1_)
            {
                float m=mask.g_;
                if(masksettings.invert1_) m=1.0f-m;
                i*=m;
            }
            if(masksettings.usemask2_)
            {
                float m=mask.b_;
                if(masksettings.invert2_) m=1.0f-m;
                i*=m;
            }
            Color col0=blend0_.GetPixel(x,y);
            Color col1=blend1_.GetPixel(x,y);
            if(layer==0)
            {
                col0.r_=i;
            }
            else if(layer==1)
            {
                col0.g_=i;
            }
            else if(layer==2)
            {
                col0.b_=i;
            }
            else if(layer==3)
            {
                col0.a_=i;
            }
            else if(layer==4)
            {
                col1.r_=i;
            }
            else if(layer==5)
            {
                col1.g_=i;
            }
            else if(layer==6)
            {
                col1.b_=i;
            }
            else if(layer==7)
            {
                col1.a_=i;
            }
            BalanceColors(col0, col1, layer);
            blend0_.SetPixel(x,y,col0);
            blend1_.SetPixel(x,y,col1);
        }
    }
    blend0Tex_->SetData(&blend0_, false);
    blend1Tex_->SetData(&blend1_, false);
}

void TerrainContext::SetLayerBufferMax(CArray2Dd &buffer, int layer, MaskSettings &masksettings)
{
    if(!terrain_) return;

    int w=blend0_.GetWidth();
    int h=blend0_.GetHeight();

    for(int x=0; x<w; ++x)
    {
        for(int y=0; y<h; ++y)
        {
            float nx=(float)x/(float)(w);
            float ny=(float)y/(float)(h);

            float i= (float)buffer.getBilinear(nx,ny);
            i=std::max(0.0f, std::min(1.0f, i));
            Color mask=mask_.GetPixelBilinear(nx,ny);

            if(masksettings.usemask0_)
            {
                float m=mask.r_;
                if(masksettings.invert0_) m=1.0f-m;
                i*=m;
            }
            if(masksettings.usemask1_)
            {
                float m=mask.g_;
                if(masksettings.invert1_) m=1.0f-m;
                i*=m;
            }
            if(masksettings.usemask2_)
            {
                float m=mask.b_;
                if(masksettings.invert2_) m=1.0f-m;
                i*=m;
            }
            Color col0=blend0_.GetPixel(x,y);
            Color col1=blend1_.GetPixel(x,y);
            if(layer==0)
            {
                col0.r_=std::max(col0.r_,i);
            }
            else if(layer==1)
            {
                col0.g_=std::max(col0.g_,i);
            }
            else if(layer==2)
            {
                col0.b_=std::max(col0.b_,i);
            }
            else if(layer==3)
            {
                col0.a_=std::max(col0.a_,i);
            }
            else if(layer==4)
            {
                col1.r_=std::max(col1.r_,i);
            }
            else if(layer==5)
            {
                col1.g_=std::max(col1.g_,i);
            }
            else if(layer==6)
            {
                col1.b_=std::max(col1.b_,i);
            }
            else if(layer==7)
            {
                col1.a_=std::max(col1.a_,i);
            }
            BalanceColors(col0, col1, layer);
            blend0_.SetPixel(x,y,col0);
            blend1_.SetPixel(x,y,col1);
        }
    }
    blend0Tex_->SetData(&blend0_, false);
    blend1Tex_->SetData(&blend1_, false);
}

void TerrainContext::BlendHeightBuffer(CArray2Dd &buffer, CArray2Dd &blend, MaskSettings &masksettings)
{
    for(int x=0; x<terrainMap_.GetWidth()-1; ++x)
    {
        for(int y=0; y<terrainMap_.GetHeight()-1; ++y)
        {
            float nx=(float)x / (float)(terrainMap_.GetWidth());
            float ny=(float)y / (float)(terrainMap_.GetHeight());

            float v=(float)buffer.getBilinear(nx,ny);
            float bval=(float)blend.getBilinear(nx,ny);
            float ht=GetHeightValue(x, y);
            Color mask=mask_.GetPixelBilinear(nx,ny);
            float maskval=1.0f;

            if(masksettings.usemask0_)
            {
                float m=mask.r_;
                if(masksettings.invert0_) m=1.0f-m;
                bval*=m;
            }
            if(masksettings.usemask1_)
            {
                float m=mask.g_;
                if(masksettings.invert1_) m=1.0f-m;
                bval*=m;
            }
            if(masksettings.usemask2_)
            {
                float m=mask.b_;
                if(masksettings.invert2_) m=1.0f-m;
                bval*=m;
            }

            float newht=ht+bval*(v-ht);
            SetHeightValue(x,y,newht);
        }
    }
    terrain_->ApplyHeightMap();
	BuildWaterDepthTexture();
}

void TerrainContext::SetWaterBuffer(CArray2Dd &buffer, MaskSettings &masksettings, int blendop)
{
    if(!water_) return;

	int w=waterMap_.GetWidth();
    int h=waterMap_.GetHeight();

    for(int x=0; x<=w; ++x)
    {
        for(int y=0; y<=h; ++y)
        {
            float nx=(float)x/(float)(w);
            float ny=(float)y/(float)(h);

            float v=buffer.getBilinear(nx,ny);
            Color mask=mask_.GetPixelBilinear(nx,ny);
            float oldheight=GetWaterValue(x,y);
            float maskval=1.0f;

            if(masksettings.usemask0_)
            {
                float mval=mask.r_;
                if(masksettings.invert0_) mval=1.0f-mval;
                maskval*=mval;
            }
            if(masksettings.usemask1_)
            {
                float mval=mask.g_;
                if(masksettings.invert1_) mval=1.0f-mval;
                maskval*=mval;
            }
            if(masksettings.usemask2_)
            {
                float mval=mask.b_;
                if(masksettings.invert2_) mval=1.0f-mval;
                maskval*=mval;
            }

			float newval=0.0f;

			switch(blendop)
			{
				case HeightReplace: newval=v; break;
				case HeightAdd: newval=oldheight+v; break;
				case HeightSubtract: newval=oldheight-v; break;
				case HeightMultiply: newval=oldheight*v; break;
				case HeightMin: newval=std::min(v, oldheight); break;
				case HeightMax: newval=std::max(v, oldheight); break;
				default: newval=v; break;
			}

            v=oldheight+maskval*(newval-oldheight);
            SetWaterValue(x,y,(float)v);
        }
    }
    water_->ApplyHeightMap();
	BuildWaterDepthTexture();
}
