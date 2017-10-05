
#define ANL_IMPLEMENTATION
#include "TerrainEdit.h"

#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Scene/Node.h>
#include <Urho3D/Graphics/Material.h>
#include <algorithm>
#include <cmath>
#include <Urho3D/IO/Log.h>
#include <Urho3D/Resource/Image.h>
#include <Urho3D/IO/Deserializer.h>
#include <Urho3D/IO/File.h>
#include <Urho3D/Scene/Scene.h>
#include "Spline.h"
#include <iostream>

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

float CalcSmooth(Image *height, float *kernel, int kernelsize, int terrainx, int terrainz)
{
	float sum=0.0f;
	float weight=0.0f;
	int ox=terrainx-int(kernelsize/2);
	int oz=terrainz-int(kernelsize/2);
	
	for(int x=0; x<kernelsize; ++x)
	{
		for(int z=0; z<kernelsize; ++z)
		{
			int nx=x+ox;
			int nz=z+oz;
			if(x>=0 && x<height->GetWidth() && z>=0 && z<height->GetHeight())
			{
				float hval=GetHeightValue(height,nx,nz);
				sum+=hval*kernel[z*kernelsize+x];
				weight+=kernel[z*kernelsize+x];
			}
		}
	}
	if(weight>0) return sum/weight;
	else return 0.0f;
}

TerrainEdit::TerrainEdit() : terrainNode_(0), terrain_(0), material_(0), use16bit_(true), triplanar_(true), smoothing_(false), normalmapping_(true){}

bool TerrainEdit::Initialize(Scene *scene, int tw, int th, int bw, int bh, Vector3 spacing, bool use16bit)
{
	if(terrainNode_) terrainNode_->Remove();
	terrainNode_=scene->CreateChild("Terrain");
	terrain_=terrainNode_->CreateComponent<Terrain>();
	terrain_->SetPatchSize(64);
	terrain_->SetSpacing(spacing);
	terrain_->SetSmoothing(true);
	
	hmap_=new Image(scene->GetContext());
	blend0_=new Image(scene->GetContext());
	blend1_=new Image(scene->GetContext());
	mask_=new Image(scene->GetContext());
	
	blend0_->SetSize(bw,bh,4);
	blend1_->SetSize(bw,bh,4);
	mask_->SetSize(bw,bh,3);
	
	use16bit_=true;
	
	hmap_->SetSize(tw, th, use16bit ? 3 : 1);
	terrain_->SetHeightMap(hmap_);
	terrain_->SetCastShadows(true);
	material_=scene->GetSubsystem<ResourceCache>()->GetResource<Material>("Materials/TerrainEdit8TriplanarBump.xml");
	blendtex0_=new Texture2D(scene->GetContext());
	blendtex1_=new Texture2D(scene->GetContext());
	masktex_=new Texture2D(scene->GetContext());
	
	mask_->Clear(Color(1.0f,1.0f,1.0f));	
	blend0_->Clear(Color(1.0f,0.0f,0.0f,0.0f));
	blend1_->Clear(Color(0,0,0,0));
	
	blendtex0_->SetData(blend0_, false);
	blendtex1_->SetData(blend1_, false);
	masktex_->SetData(mask_, false);
	
	material_->SetTexture(TU_DIFFUSE, blendtex0_);
	material_->SetTexture(TU_NORMAL, blendtex1_);
	material_->SetTexture(TU_ENVIRONMENT, masktex_);
	terrain_->SetMaterial(material_);
	SetBlendMaskSize(bw,bh);
	SetMaterialSettings(true, false, true);
	
	return true;
}

void TerrainEdit::SetTerrainSpacing(Vector3 spacing)
{
	if(!terrain_) return;
	
	terrain_->SetSpacing(spacing);
}

void TerrainEdit::SetTerrainSize(int w, int h, Vector3 spacing, bool use16bit)
{
	if(!terrain_) return;
	hmap_->SetSize(w, h, use16bit ? 3 : 1);
	hmap_->Clear(Color(0,0,0));
	terrain_->SetHeightMap(hmap_);
	terrain_->SetSpacing(spacing);
}

void TerrainEdit::SetBlendMaskSize(int w, int h)
{
	if(!material_ || !blendtex0_ || !blendtex1_ || !masktex_) return;
	
	blend0_->SetSize(w,h,4);
	blend1_->SetSize(w,h,4);
	mask_->SetSize(w,h,3);
	
	blend0_->Clear(Color(1,0,0,0));
	blend1_->Clear(Color(0,0,0,0));
	mask_->Clear(Color(1,1,1));
	
	blendtex0_->SetData(blend0_, false);
	blendtex1_->SetData(blend1_, false);
	masktex_->SetData(mask_, false);
}

Vector2 TerrainEdit::WorldToNormalized(Vector3 world)
{
	if(!terrain_) return Vector2(0,0);
	Vector3 spacing=terrain_->GetSpacing();
	int patchSize=terrain_->GetPatchSize();
	IntVector2 numPatches=IntVector2((hmap_->GetWidth()-1) / patchSize, (hmap_->GetHeight()-1) / patchSize);
	Vector2 patchWorldSize=Vector2(spacing.x_*(float)(patchSize*numPatches.x_), spacing.z_*(float)(patchSize*numPatches.y_));
	Vector2 patchWorldOrigin=Vector2(-0.5f * patchWorldSize.x_, -0.5f * patchWorldSize.y_);
	return Vector2((world.x_-patchWorldOrigin.x_)/patchWorldSize.x_, (world.z_-patchWorldOrigin.y_)/patchWorldSize.y_);
}

Vector3 TerrainEdit::NormalizedToWorld(Vector2 normalized)
{
	if(!terrain_) return Vector2(0,0);
	Vector3 spacing=terrain_->GetSpacing();
	int patchSize=terrain_->GetPatchSize();
	IntVector2 numPatches=IntVector2((hmap_->GetWidth()-1) / patchSize, (hmap_->GetHeight()-1) / patchSize);
	Vector2 patchWorldSize=Vector2(spacing.x_*(float)(patchSize*numPatches.x_), spacing.z_*(float)(patchSize*numPatches.y_));
	Vector2 patchWorldOrigin=Vector2(-0.5f * patchWorldSize.x_, -0.5f * patchWorldSize.y_);
	return Vector3(patchWorldOrigin.x_+normalized.x_*patchWorldSize.x_, 0, patchWorldOrigin.y_+normalized.y_*patchWorldSize.y_);
}

void TerrainEdit::SetHeightValue(int x, int y, float val)
{
	if(hmap_->GetComponents()==1) hmap_->SetPixel(x,y,Color(val,0,0));
	else
	{
		float expht=std::floor(val*255.0f);
		float rm=val*255.0f-expht;
		hmap_->SetPixel(x,y,Color(expht/255.0f, rm, 0));
	}
}

float TerrainEdit::GetHeightValue(int x, int y)
{
	if(hmap_->GetComponents()==1) return hmap_->GetPixel(x,y).r_;
	else
	{
		Color c=hmap_->GetPixel(x,y);
		return c.r_+c.g_/255.0f;
	}
}

float TerrainEdit::GetHeightValue(Vector3 worldpos)
{
	if(!terrain_) return 0.0f;
	IntVector2 htm=terrain_->WorldToHeightMap(worldpos);
	Color c=hmap_->GetPixelBilinear((float)htm.x_ / (float)hmap_->GetWidth(), (float)htm.y_ / (float)hmap_->GetHeight());
	if(hmap_->GetComponents()==1) return c.r_;
	else return c.r_+c.g_/255.0f;
}

void TerrainEdit::SetHeightBuffer(CArray2Dd &buffer, MaskSettings &masksettings)
{
	if(!terrain_) return;
	
	if(buffer.width()!=hmap_->GetWidth() || buffer.height()!=hmap_->GetHeight()) return;
	int w=buffer.width();
	int h=buffer.height();
	
	for(int x=0; x<=w; ++x)
	{
		for(int y=0; y<=h; ++y)
		{
			float nx=(float)x/(float)(w);
			float ny=(float)y/(float)(h);
			
			double v=buffer.get(x,y);
			Color mask=mask_->GetPixelBilinear(nx,ny);
			float oldheight=GetHeightValue(x,y);
			float maskval=1.0f;
			
			if(masksettings.usemask0)
			{
				float mval=mask.r_;
				if(masksettings.invertmask0) mval=1.0-mval;
				maskval*=mval;
			}
			if(masksettings.usemask1)
			{
				float mval=mask.g_;
				if(masksettings.invertmask1) mval=1.0-mval;
				maskval*=mval;
			}
			if(masksettings.usemask2)
			{
				float mval=mask.b_;
				if(masksettings.invertmask2) mval=1.0-mval;
				maskval*=mval;
			}
			
			v=oldheight+maskval*(v-oldheight);
			SetHeightValue(x,y,v);
		}
	}
	terrain_->SetHeightMap(hmap_);
}

void TerrainEdit::SetLayerBuffer(CArray2Dd &buffer, int layer, MaskSettings &masksettings)
{
	if(!terrain_) return;
	
	if(buffer.width()!=blend0_->GetWidth() || buffer.height()!=blend0_->GetHeight()) return;
	int w=buffer.width();
	int h=buffer.height();
	
	for(int x=0; x<=w; ++x)
	{
		for(int y=0; y<=h; ++y)
		{
			float nx=(float)x/(float)(w);
			float ny=(float)y/(float)(h);
			
			float i=buffer.getBilinear(nx,ny);
			i=std::max(0.0f, std::min(1.0f, i));
			Color mask=mask_->GetPixelBilinear(nx,ny);
			
			if(masksettings.usemask0)
			{
				float m=mask.r_;
				if(masksettings.invertmask0) m=1.0f-m;
				i*=m;
			}
			if(masksettings.usemask1)
			{
				float m=mask.g_;
				if(masksettings.invertmask1) m=1.0f-m;
				i*=m;
			}
			if(masksettings.usemask2)
			{
				float m=mask.b_;
				if(masksettings.invertmask2) m=1.0f-m;
				i*=m;
			}
			Color col0=blend0_->GetPixel(x,y);
			Color col1=blend1_->GetPixel(x,y);
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
			blend0_->SetPixel(x,y,col0);
			blend1_->SetPixel(x,y,col1);
		}
	}
	blendtex0_->SetData(blend0_, false);
	blendtex1_->SetData(blend1_, false);
}

void TerrainEdit::SetLayerBufferMax(CArray2Dd &buffer, int layer, MaskSettings &masksettings)
{
	if(!terrain_) return;
	
	if(buffer.width()!=blend0_->GetWidth() || buffer.height()!=blend0_->GetHeight()) return;
	int w=buffer.width();
	int h=buffer.height();
	
	for(int x=0; x<=w; ++x)
	{
		for(int y=0; y<=h; ++y)
		{
			float nx=(float)x/(float)(w);
			float ny=(float)y/(float)(h);
			
			float i=buffer.getBilinear(nx,ny);
			i=std::max(0.0f, std::min(1.0f, i));
			Color mask=mask_->GetPixelBilinear(nx,ny);
			
			if(masksettings.usemask0)
			{
				float m=mask.r_;
				if(masksettings.invertmask0) m=1.0f-m;
				i*=m;
			}
			if(masksettings.usemask1)
			{
				float m=mask.g_;
				if(masksettings.invertmask1) m=1.0f-m;
				i*=m;
			}
			if(masksettings.usemask2)
			{
				float m=mask.b_;
				if(masksettings.invertmask2) m=1.0f-m;
				i*=m;
			}
			Color col0=blend0_->GetPixel(x,y);
			Color col1=blend1_->GetPixel(x,y);
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
			blend0_->SetPixel(x,y,col0);
			blend1_->SetPixel(x,y,col1);
		}
	}
	blendtex0_->SetData(blend0_, false);
	blendtex1_->SetData(blend1_, false);
}

void TerrainEdit::BlendHeightBuffer(CArray2Dd &buffer, CArray2Dd &blend, MaskSettings &masksettings)
{
}
	
void TerrainEdit::ApplyHeightBrush(float x, float z, float dt, BrushSettings &brush, MaskSettings &masksettings)
{
	if(!terrain_) return;
	
	Vector3 world=Vector3(x,0,z);
	IntVector2 ht=terrain_->WorldToHeightMap(world);
	
	int sz=brush.radius+1;
	int comp=hmap_->GetComponents();
	for(int hx=ht.x_-sz; hx<=ht.x_+sz; ++hx)
	{
		for(int hz=ht.y_-sz; hz<=ht.y_+sz; ++hz)
		{
			if(hx>=0 && hx<hmap_->GetWidth() && hz>=0 && hz<hmap_->GetHeight())
			{
				float dx=(float)(hx-ht.x_);
				float dz=(float)(hz-ht.y_);
				float d=std::sqrt(dx*dx+dz*dz);
				float i=((d-brush.radius)/(brush.hardness*brush.radius-brush.radius));
				i=std::max(0.0f, std::min(1.0f, i));
				i=std::sin(i*1.57079633);
				i=i*dt*brush.power;
				if(masksettings.usemask0)
				{
					float m=mask_->GetPixelBilinear((float)(hx)/(float)(hmap_->GetWidth()), (float)(hz)/(float)(hmap_->GetHeight())).r_;
					if(masksettings.invertmask0) m=1.0f-m;
					i=i*m;
				}
				if(masksettings.usemask1)
				{
					float m=mask_->GetPixelBilinear((float)(hx)/(float)(hmap_->GetWidth()), (float)(hz)/(float)(hmap_->GetHeight())).g_;
					if(masksettings.invertmask1) m=1.0f-m;
					i=i*m;
				}
				if(masksettings.usemask2)
				{
					float m=mask_->GetPixelBilinear((float)(hx)/(float)(hmap_->GetWidth()), (float)(hz)/(float)(hmap_->GetHeight())).b_;
					if(masksettings.invertmask2) m=1.0f-m;
					i=i*m;
				}
				float hval=GetHeightValue(hx,hz);
				float newhval=hval+(brush.max-hval)*i;
				SetHeightValue(hx,hz,newhval);
				
			}
		}
	}
	
	terrain_->SetHeightMap(hmap_);
}

void TerrainEdit::ApplyBlendBrush(float x, float z, int layer, float dt, BrushSettings &brush, MaskSettings &masksettings)
{
	if(!terrain_) return;
	
	Vector2 normalized=WorldToNormalized(Vector3(x,0,z));
	float ratio=((float)blend0_->GetWidth()/(float)hmap_->GetWidth());
	int ix=(normalized.x_*(float)(blend0_->GetWidth()-1));
	int iy=(normalized.y_*(float)(blend0_->GetHeight()-1));
	iy=blend0_->GetHeight()-iy;
	float rad=brush.radius*ratio;
	int sz=rad+1;
	
	for(int hx=ix-sz; hx<=ix+sz; ++hx)
	{
		for(int hz=iy-sz; hz<=iy+sz; ++hz)
		{
			if(hx>=0 && hx<blend0_->GetWidth() && hz>=0 && hz<blend0_->GetHeight())
			{
				float dx=(float)hx-(float)ix;
				float dz=(float)hz-(float)iy;
				float d=std::sqrt(dx*dx+dz*dz);
				float i=((d-rad)/(brush.hardness*rad-rad));
				i=std::max(0.0f, std::min(1.0f, i));
				i=i*dt*brush.power;
				if(masksettings.usemask0)
				{
					float m=mask_->GetPixelBilinear((float)(hx)/(float)(blend0_->GetWidth()), (float)(hz)/(float)(blend0_->GetHeight())).r_;
					if(masksettings.invertmask0) m=1.0f-m;
					i=i*m;
				}
				if(masksettings.usemask1)
				{
					float m=mask_->GetPixelBilinear((float)(hx)/(float)(blend0_->GetWidth()), (float)(hz)/(float)(blend0_->GetHeight())).g_;
					if(masksettings.invertmask1) m=1.0f-m;
					i=i*m;
				}
				if(masksettings.usemask2)
				{
					float m=mask_->GetPixelBilinear((float)(hx)/(float)(blend0_->GetWidth()), (float)(hz)/(float)(blend0_->GetHeight())).b_;
					if(masksettings.invertmask2) m=1.0f-m;
					i=i*m;
				}
				Color col0=blend0_->GetPixel(hx,hz);
				Color col1=blend1_->GetPixel(hx,hz);
				if(layer==0)
				{
					col0.r_=col0.r_+i*(1.0f-col0.r_);
				}
				else if(layer==1)
				{
					col0.g_=col0.g_+i*(1.0f-col0.g_);
				}
				else if(layer==2)
				{
					col0.b_=col0.b_+i*(1.0f-col0.b_);
				}
				else if(layer==3)
				{
					col0.a_=col0.a_+i*(1.0f-col0.a_);
				}
				else if(layer==4)
				{
					col1.r_=col1.r_+i*(1.0f-col1.r_);
				}
				else if(layer==5)
				{
					col1.g_=col1.g_+i*(1.0f-col1.g_);
				}
				else if(layer==6)
				{
					col1.b_=col1.b_+i*(1.0f-col1.b_);
				}
				else
				{
					col1.a_=col1.a_+i*(1.0f-col1.a_);
				}
				BalanceColors(col0, col1, layer);
				blend0_->SetPixel(hx,hz,col0);
				blend1_->SetPixel(hx,hz,col1);
				//LOGINFO(String(col.r_)+String(",")+String(col.g_));
			}
		}
	}
	
	blendtex0_->SetData(blend0_, false);
	blendtex1_->SetData(blend1_, false);
}

void TerrainEdit::ApplyMaskBrush(float x, float z, int which, float dt, BrushSettings &brush, MaskSettings &masksettings)
{
	if(!terrain_) return;
	
	Vector2 normalized=WorldToNormalized(Vector3(x,0,z));
	float ratio=((float)mask_->GetWidth()/(float)hmap_->GetWidth());
	int ix=(normalized.x_*(float)(mask_->GetWidth()-1));
	int iy=(normalized.y_*(float)(mask_->GetHeight()-1));
	iy=mask_->GetHeight()-iy;
	float rad=brush.radius*ratio;
	int sz=rad+1;
	
	for(int hx=ix-sz; hx<=ix+sz; ++hx)
	{
		for(int hz=iy-sz; hz<=iy+sz; ++hz)
		{
			if(hx>=0 && hx<mask_->GetWidth() && hz>=0 && hz<mask_->GetHeight())
			{
				float dx=(float)hx-(float)ix;
				float dz=(float)hz-(float)iy;
				float d=std::sqrt(dx*dx+dz*dz);
				float i=((d-rad)/(brush.hardness*rad-rad));
				i=std::max(0.0f, std::min(1.0f, i));
				i=i*dt*brush.power;
				
				Color col=mask_->GetPixel(hx,hz);
				if(which==0)
					col.r_=col.r_+i*((1.0f-brush.max)-col.r_);
				else if(which==1)
					col.g_=col.g_+i*((1.0f-brush.max)-col.g_);
				else
					col.b_=col.b_+i*((1.0f-brush.max)-col.b_);
				mask_->SetPixel(hx,hz,col);
			}
		}
	}
	
	masktex_->SetData(mask_, false);
}

void TerrainEdit::ApplySmoothBrush(float x, float z, float dt, BrushSettings &brush, MaskSettings &masksettings)
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
	
	int sz=brush.radius+1;
	int comp=hmap_->GetComponents();
	for(int hx=ht.x_-sz; hx<=ht.x_+sz; ++hx)
	{
		for(int hz=ht.y_-sz; hz<=ht.y_+sz; ++hz)
		{
			if(hx>=0 && hx<hmap_->GetWidth() && hz>=0 && hz<hmap_->GetHeight())
			{
				float dx=(float)(hx-ht.x_);
				float dz=(float)(hz-ht.y_);
				float d=std::sqrt(dx*dx+dz*dz);
				float i=((d-brush.radius)/(brush.hardness*brush.radius-brush.radius));
				i=std::max(0.0f, std::min(1.0f, i));
				i=i*dt*brush.power;
				if(masksettings.usemask0)
				{
					float m=mask_->GetPixelBilinear((float)(hx)/(float)(hmap_->GetWidth()), (float)(hz)/(float)(hmap_->GetHeight())).r_;
					if(masksettings.invertmask0) m=1.0f-m;
					i=i*m;
				}
				if(masksettings.usemask1)
				{
					float m=mask_->GetPixelBilinear((float)(hx)/(float)(hmap_->GetWidth()), (float)(hz)/(float)(hmap_->GetHeight())).g_;
					if(masksettings.invertmask1) m=1.0f-m;
					i=i*m;
				}
				if(masksettings.usemask2)
				{
					float m=mask_->GetPixelBilinear((float)(hx)/(float)(hmap_->GetWidth()), (float)(hz)/(float)(hmap_->GetHeight())).b_;
					if(masksettings.invertmask2) m=1.0f-m;
					i=i*m;
				}
				float hval=GetHeightValue(hx,hz);
				float smooth=CalcSmooth(hmap_,kernel,9,hx,hz);
				float newhval=hval+(smooth-hval)*i;
				SetHeightValue(hx,hz,newhval);
			}
		}
	}
	terrain_->SetHeightMap(hmap_);
}

void TerrainEdit::SetBrushCursorHeight(CustomGeometry *brush, float groundx, float groundz)
{
	int numverts=brush->GetNumVertices(0);
	for(int v=0; v<numverts-1; v++)
	{
		CustomGeometryVertex *vert=brush->GetVertex(0,v);
		float ht=terrain_->GetHeight(Vector3(vert->position_.x_+groundx, 0, vert->position_.z_+groundz));
		vert->position_.y_=ht;
	}
	brush->Commit();
}
	
void TerrainEdit::InvertMask(int which)
{
}

void TerrainEdit::ClearMask(int which)
{
}

void TerrainEdit::ClearAllMasks()
{
}
	
void TerrainEdit::InvertLayer(int which)
{
}

void TerrainEdit::ClearLayer(int which)
{
}

void TerrainEdit::ClearAllLayers()
{
}

void TerrainEdit::InvertHeight()
{
}

void TerrainEdit::ClearHeight()
{
}
	
void TerrainEdit::SetMaterialSettings(bool triplanar, bool smoothing, bool normalmapping)
{
	if(!terrain_) return;
	
	ResourceCache *cache=terrainNode_->GetSubsystem<ResourceCache>();
	if (triplanar) 
		if (smoothing) 
			if (normalmapping) 
				material_=cache->GetResource<Material>("Materials/TerrainEdit8TriplanarSmoothBump.xml");
			else
				material_=cache->GetResource<Material>("Materials/TerrainEdit8TriplanarSmooth.xml");
			
		else
			if (normalmapping) 
				material_=cache->GetResource<Material>("Materials/TerrainEdit8TriplanarBump.xml");
			else
				material_=cache->GetResource<Material>("Materials/TerrainEdit8Triplanar.xml");
			
		
	else
		if (smoothing) 
			if (normalmapping)
				material_=cache->GetResource<Material>("Materials/TerrainEdit8SmoothBump.xml");
			else
				material_=cache->GetResource<Material>("Materials/TerrainEdit8Smooth.xml");
			
		else
			if (normalmapping) 
				material_=cache->GetResource<Material>("Materials/TerrainEdit8Bump.xml");
			else
				material_=cache->GetResource<Material>("Materials/TerrainEdit8.xml");
	terrain_->SetMaterial(material_);
	material_->SetTexture(TU_DIFFUSE, blendtex0_);
	material_->SetTexture(TU_NORMAL, blendtex1_);
	material_->SetTexture(TU_ENVIRONMENT, masktex_);
}

void TerrainEdit::SaveHeightMap(const String &filename)
{
}

void TerrainEdit::SaveBlend0(const String &filename)
{
}

void TerrainEdit::SaveBlend1(const String &filename)
{
}

void TerrainEdit::SaveMask(const String &filename)
{
}

void TerrainEdit::LoadHeightMap(const String &filename)
{
}

void TerrainEdit::LoadBlend0(const String &filename)
{
}

void TerrainEdit::LoadBlend1(const String &filename)
{
}

void TerrainEdit::LoadMask(const String &filename)
{
}




bool LoadImage(Context *c, Image *i, const char *fname)
{
	SharedPtr<File> file(new File(c,fname));
	if(!file) return false;
	
	auto success=i->Load(*(file.Get()));
	return success;
}

Vector2 WorldToNormalized(Image *height, Terrain *terrain, Vector3 world)
{
	if(!terrain || !height) return Vector2(0,0);
	Vector3 spacing=terrain->GetSpacing();
	int patchSize=terrain->GetPatchSize();
	IntVector2 numPatches=IntVector2((height->GetWidth()-1) / patchSize, (height->GetHeight()-1) / patchSize);
	Vector2 patchWorldSize=Vector2(spacing.x_*(float)(patchSize*numPatches.x_), spacing.z_*(float)(patchSize*numPatches.y_));
	Vector2 patchWorldOrigin=Vector2(-0.5f * patchWorldSize.x_, -0.5f * patchWorldSize.y_);
	return Vector2((world.x_-patchWorldOrigin.x_)/patchWorldSize.x_, (world.z_-patchWorldOrigin.y_)/patchWorldSize.y_);
}

Vector3 NormalizedToWorld(Image *height, Terrain *terrain, Vector2 normalized)
{
	if(!terrain || !height) return Vector2(0,0);
	Vector3 spacing=terrain->GetSpacing();
	int patchSize=terrain->GetPatchSize();
	IntVector2 numPatches=IntVector2((height->GetWidth()-1) / patchSize, (height->GetHeight()-1) / patchSize);
	Vector2 patchWorldSize=Vector2(spacing.x_*(float)(patchSize*numPatches.x_), spacing.z_*(float)(patchSize*numPatches.y_));
	Vector2 patchWorldOrigin=Vector2(-0.5f * patchWorldSize.x_, -0.5f * patchWorldSize.y_);
	return Vector3(patchWorldOrigin.x_+normalized.x_*patchWorldSize.x_, 0, patchWorldOrigin.y_+normalized.y_*patchWorldSize.y_);
}

void SetHeightValue(Image *height, int x, int y, float val)
{
	if(!height) return;
	if(height->GetComponents()==1) height->SetPixel(x,y,Color(val,0,0));
	else
	{
		float expht=std::floor(val*255.0f);
		float rm=val*255.0f-expht;
		height->SetPixel(x,y,Color(expht/255.0f, rm, 0));
	}
}

float GetHeightValue(Image *height, int x, int y)
{
	if(!height) return 0.0f;
	if(height->GetComponents()==1) return height->GetPixel(x,y).r_;
	else
	{
		Color c=height->GetPixel(x,y);
		return c.r_+c.g_/255.0f;
	}
}

	
void ApplyHeightBrush(Terrain *terrain, Image *height, Image *mask, float x, float z, float radius, float max, float power, float hardness, bool usemask0, bool usemask1, bool usemask2, float dt)
{
	if(!terrain || !height || !terrain) return;
	
	Vector3 world=Vector3(x,0,z);
	IntVector2 ht=terrain->WorldToHeightMap(world);
	
	int sz=radius+1;
	int comp=height->GetComponents();
	for(int hx=ht.x_-sz; hx<=ht.x_+sz; ++hx)
	{
		for(int hz=ht.y_-sz; hz<=ht.y_+sz; ++hz)
		{
			if(hx>=0 && hx<height->GetWidth() && hz>=0 && hz<height->GetHeight())
			{
				float dx=(float)(hx-ht.x_);
				float dz=(float)(hz-ht.y_);
				float d=std::sqrt(dx*dx+dz*dz);
				float i=((d-radius)/(hardness*radius-radius));
				i=std::max(0.0f, std::min(1.0f, i));
				i=std::sin(i*1.57079633);
				i=i*dt*power;
				if(usemask0)
				{
					float m=mask->GetPixelBilinear((float)(hx)/(float)(height->GetWidth()), (float)(hz)/(float)(height->GetHeight())).r_;
					i=i*m;
				}
				if(usemask1)
				{
					float m=mask->GetPixelBilinear((float)(hx)/(float)(height->GetWidth()), (float)(hz)/(float)(height->GetHeight())).g_;
					i=i*m;
				}
				if(usemask2)
				{
					float m=mask->GetPixelBilinear((float)(hx)/(float)(height->GetWidth()), (float)(hz)/(float)(height->GetHeight())).b_;
					i=i*m;
				}
				float hval=GetHeightValue(height,hx,hz);
				float newhval=hval+(max-hval)*i;
				SetHeightValue(height,hx,hz,newhval);
				
			}
		}
	}
}

void ApplyBlendBrush(Terrain *terrain, Image *height, Image *blend, Image *mask, float x, float z, float radius, float mx, float power, float hardness, int layer, bool usemask0, bool usemask1, bool usemask2, float dt)
{
	if(!blend || !height || !terrain) return;
	
	Vector2 normalized=WorldToNormalized(height,terrain,Vector3(x,0,z));
	float ratio=((float)blend->GetWidth()/(float)height->GetWidth());
	int ix=(normalized.x_*(float)(blend->GetWidth()-1));
	int iy=(normalized.y_*(float)(blend->GetHeight()-1));
	iy=blend->GetHeight()-iy;
	float rad=radius*ratio;
	int sz=rad+1;
	
	for(int hx=ix-sz; hx<=ix+sz; ++hx)
	{
		for(int hz=iy-sz; hz<=iy+sz; ++hz)
		{
			if(hx>=0 && hx<blend->GetWidth() && hz>=0 && hz<blend->GetHeight())
			{
				float dx=(float)hx-(float)ix;
				float dz=(float)hz-(float)iy;
				float d=std::sqrt(dx*dx+dz*dz);
				float i=((d-rad)/(hardness*rad-rad));
				i=std::max(0.0f, std::min(1.0f, i));
				i=i*dt*power;
				if(usemask0)
				{
					float m=mask->GetPixelBilinear((float)(hx)/(float)(blend->GetWidth()), (float)(hz)/(float)(blend->GetHeight())).r_;
					i=i*m;
				}
				if(usemask1)
				{
					float m=mask->GetPixelBilinear((float)(hx)/(float)(blend->GetWidth()), (float)(hz)/(float)(blend->GetHeight())).g_;
					i=i*m;
				}
				if(usemask2)
				{
					float m=mask->GetPixelBilinear((float)(hx)/(float)(blend->GetWidth()), (float)(hz)/(float)(blend->GetHeight())).b_;
					i=i*m;
				}
				Color col=blend->GetPixel(hx,hz);
				if(layer==1)
				{
					col.r_=col.r_+i*(1.0f-col.r_);
					col.r_=std::min(1.0f,col.r_);
					float others=col.g_+col.b_+col.a_;
					col.g_=(col.g_/others)*(1.0f-col.r_);
					col.b_=(col.b_/others)*(1.0f-col.r_);
					col.a_=(col.a_/others)*(1.0f-col.r_);
				}
				else if(layer==2)
				{
					col.g_=col.g_+i*(1.0f-col.g_);
					col.g_=std::min(1.0f,col.g_);
					float others=col.r_+col.b_+col.a_;
					col.r_=(col.r_/others)*(1.0f-col.g_);
					col.b_=(col.b_/others)*(1.0f-col.g_);
					col.a_=(col.a_/others)*(1.0f-col.g_);
				}
				else if(layer==3)
				{
					col.b_=col.b_+i*(1.0f-col.b_);
					col.b_=std::min(1.0f,col.b_);
					float others=col.r_+col.g_+col.a_;
					col.r_=(col.r_/others)*(1.0f-col.b_);
					col.g_=(col.g_/others)*(1.0f-col.b_);
					col.a_=(col.a_/others)*(1.0f-col.b_);
				}
				else if(layer==4)
				{
					col.a_=col.a_+i*(1.0f-col.a_);
					col.a_=std::min(1.0f,col.a_);
					float others=col.r_+col.g_+col.b_;
					col.r_=(col.r_/others)*(1.0f-col.a_);
					col.g_=(col.g_/others)*(1.0f-col.a_);
					col.b_=(col.b_/others)*(1.0f-col.a_);
				}
				blend->SetPixel(hx,hz,col);
				//LOGINFO(String(col.r_)+String(",")+String(col.g_));
			}
		}
	}
}

void ApplyBlendBrush8(Terrain *terrain, Image *height, Image *blend0, Image *blend1, Image *mask, float x, float z, float radius, float mx, float power, float hardness, int layer, bool usemask0, bool usemask1, bool usemask2, float dt)
{
	if(!blend0 || !blend1 || !height || !terrain) return;
	
	Vector2 normalized=WorldToNormalized(height,terrain,Vector3(x,0,z));
	float ratio=((float)blend0->GetWidth()/(float)height->GetWidth());
	int ix=(normalized.x_*(float)(blend0->GetWidth()-1));
	int iy=(normalized.y_*(float)(blend0->GetHeight()-1));
	iy=blend0->GetHeight()-iy;
	float rad=radius*ratio;
	int sz=rad+1;
	
	for(int hx=ix-sz; hx<=ix+sz; ++hx)
	{
		for(int hz=iy-sz; hz<=iy+sz; ++hz)
		{
			if(hx>=0 && hx<blend0->GetWidth() && hz>=0 && hz<blend0->GetHeight())
			{
				float dx=(float)hx-(float)ix;
				float dz=(float)hz-(float)iy;
				float d=std::sqrt(dx*dx+dz*dz);
				float i=((d-rad)/(hardness*rad-rad));
				i=std::max(0.0f, std::min(1.0f, i));
				i=i*dt*power;
				if(usemask0)
				{
					float m=mask->GetPixelBilinear((float)(hx)/(float)(blend0->GetWidth()), (float)(hz)/(float)(blend0->GetHeight())).r_;
					i=i*m;
				}
				if(usemask1)
				{
					float m=mask->GetPixelBilinear((float)(hx)/(float)(blend0->GetWidth()), (float)(hz)/(float)(blend0->GetHeight())).g_;
					i=i*m;
				}
				if(usemask2)
				{
					float m=mask->GetPixelBilinear((float)(hx)/(float)(blend0->GetWidth()), (float)(hz)/(float)(blend0->GetHeight())).b_;
					i=i*m;
				}
				Color col0=blend0->GetPixel(hx,hz);
				Color col1=blend1->GetPixel(hx,hz);
				if(layer==0)
				{
					col0.r_=col0.r_+i*(1.0f-col0.r_);
				}
				else if(layer==1)
				{
					col0.g_=col0.g_+i*(1.0f-col0.g_);
				}
				else if(layer==2)
				{
					col0.b_=col0.b_+i*(1.0f-col0.b_);
				}
				else if(layer==3)
				{
					col0.a_=col0.a_+i*(1.0f-col0.a_);
				}
				else if(layer==4)
				{
					col1.r_=col1.r_+i*(1.0f-col1.r_);
				}
				else if(layer==5)
				{
					col1.g_=col1.g_+i*(1.0f-col1.g_);
				}
				else if(layer==6)
				{
					col1.b_=col1.b_+i*(1.0f-col1.b_);
				}
				else
				{
					col1.a_=col1.a_+i*(1.0f-col1.a_);
				}
				BalanceColors(col0, col1, layer);
				blend0->SetPixel(hx,hz,col0);
				blend1->SetPixel(hx,hz,col1);
				//LOGINFO(String(col.r_)+String(",")+String(col.g_));
			}
		}
	}
}

void ApplyMaskBrush(Terrain *terrain, Image *height, Image *mask, float x, float z, float radius, float mx, float power, float hardness, float dt, int which)
{
	if(!mask || !height || !terrain) return;
	
	Vector2 normalized=WorldToNormalized(height,terrain,Vector3(x,0,z));
	float ratio=((float)mask->GetWidth()/(float)height->GetWidth());
	int ix=(normalized.x_*(float)(mask->GetWidth()-1));
	int iy=(normalized.y_*(float)(mask->GetHeight()-1));
	iy=mask->GetHeight()-iy;
	float rad=radius*ratio;
	int sz=rad+1;
	
	for(int hx=ix-sz; hx<=ix+sz; ++hx)
	{
		for(int hz=iy-sz; hz<=iy+sz; ++hz)
		{
			if(hx>=0 && hx<mask->GetWidth() && hz>=0 && hz<mask->GetHeight())
			{
				float dx=(float)hx-(float)ix;
				float dz=(float)hz-(float)iy;
				float d=std::sqrt(dx*dx+dz*dz);
				float i=((d-rad)/(hardness*rad-rad));
				i=std::max(0.0f, std::min(1.0f, i));
				i=i*dt*power;
				
				Color col=mask->GetPixel(hx,hz);
				if(which==0)
					col.r_=col.r_+i*((1.0f-mx)-col.r_);
				else if(which==1)
					col.g_=col.g_+i*((1.0f-mx)-col.g_);
				else
					col.b_=col.b_+i*((1.0f-mx)-col.b_);
				mask->SetPixel(hx,hz,col);
				//LOGINFO(String(hx)+String(",")+String(hz)+String(":")+String(col.r_));
			}
		}
	}
}

void ApplySpeckleBrush(Terrain *terrain, Image *height, Image *color, Image *mask, float x, float z, float radius, float mx, float power, float hardness, Color c1, Color c2, bool usemask, float dt)
{
	if(!color  || !height || !terrain) return;
	
	Vector2 normalized=WorldToNormalized(height,terrain,Vector3(x,0,z));
	float ratio=((float)color->GetWidth()/(float)height->GetWidth());
	int ix=(normalized.x_*(float)(color->GetWidth()-1));
	int iy=(normalized.y_*(float)(color->GetHeight()-1));
	iy=color->GetHeight()-iy;
	float rad=radius*ratio;
	int sz=rad+1;
	
	static KISS rnd;
	
	for(int hx=ix-sz; hx<=ix+sz; ++hx)
	{
		for(int hz=iy-sz; hz<=iy+sz; ++hz)
		{
			if(hx>=0 && hx<color->GetWidth() && hz>=0 && hz<color->GetHeight())
			{
				float dx=(float)hx-(float)ix;
				float dz=(float)hz-(float)iy;
				float d=std::sqrt(dx*dx+dz*dz);
				float i=((d-rad)/(hardness*rad-rad));
				i=std::max(0.0f, std::min(1.0f, i));
				i=i*dt*power;
				if(usemask)
				{
					float m=mask->GetPixelBilinear((float)(hx)/(float)(color->GetWidth()), (float)(hz)/(float)(color->GetHeight())).r_;
					i=i*m;
				}
				Color oldcol=color->GetPixel(hx,hz);
				Color newcol=c1.Lerp(c2, (float)rnd.get01());
				Color finalcol=oldcol.Lerp(newcol, i);
				color->SetPixel(hx,hz,finalcol);
			}
		}
	}
}



void ApplySmoothBrush(Terrain *terrain, Image *height, Image *mask, float x, float z, float radius, float max, float power, float hardness, bool usemask0, bool usemask1, bool usemask2, float dt)
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
	
	if(!terrain || !height || !terrain) return;
	
	Vector3 world=Vector3(x,0,z);
	IntVector2 ht=terrain->WorldToHeightMap(world);
	
	int sz=radius+1;
	int comp=height->GetComponents();
	for(int hx=ht.x_-sz; hx<=ht.x_+sz; ++hx)
	{
		for(int hz=ht.y_-sz; hz<=ht.y_+sz; ++hz)
		{
			if(hx>=0 && hx<height->GetWidth() && hz>=0 && hz<height->GetHeight())
			{
				float dx=(float)(hx-ht.x_);
				float dz=(float)(hz-ht.y_);
				float d=std::sqrt(dx*dx+dz*dz);
				float i=((d-radius)/(hardness*radius-radius));
				i=std::max(0.0f, std::min(1.0f, i));
				i=i*dt*power;
				if(usemask0)
				{
					float m=mask->GetPixelBilinear((float)(hx)/(float)(height->GetWidth()), (float)(hz)/(float)(height->GetHeight())).r_;
					i=i*m;
				}
				if(usemask1)
				{
					float m=mask->GetPixelBilinear((float)(hx)/(float)(height->GetWidth()), (float)(hz)/(float)(height->GetHeight())).g_;
					i=i*m;
				}
				if(usemask2)
				{
					float m=mask->GetPixelBilinear((float)(hx)/(float)(height->GetWidth()), (float)(hz)/(float)(height->GetHeight())).b_;
					i=i*m;
				}
				float hval=GetHeightValue(height,hx,hz);
				float smooth=CalcSmooth(height,kernel,9,hx,hz);
				float newhval=hval+(smooth-hval)*i;
				SetHeightValue(height,hx,hz,newhval);
			}
		}
	}
}

void SetBrushCursorHeight(Terrain *terrain, CustomGeometry *brush, float groundx, float groundz)
{
	int numverts=brush->GetNumVertices(0);
	for(int v=0; v<numverts-1; v++)
	{
		CustomGeometryVertex *vert=brush->GetVertex(0,v);
		float ht=terrain->GetHeight(Vector3(vert->position_.x_+groundx, 0, vert->position_.z_+groundz));
		vert->position_.y_=ht;
	}
	brush->Commit();
}

	
void InvertMask(Image *mask)
{
	if(mask)
	{
		for(int x=0; x<mask->GetWidth(); ++x)
		{
			for(int y=0; y<mask->GetHeight(); ++y)
			{
				Color col=mask->GetPixel(x,y);
				mask->SetPixel(x,y,Color(1-col.r_,0,0));
			}
		}
	}
}






void RenderANLKernelToHeight(Image *height, Image *mask, CKernel *kernel, double lowRange, double highRange, bool useMask, bool invertMask)
{
	if(!height) return;
	int w=height->GetWidth()-1;
	int h=height->GetHeight()-1;
	
	CArray2Dd a(height->GetWidth(), height->GetHeight());
	
	map2D(SEAMLESS_NONE, a, *kernel, SMappingRanges(0,1,0,1,0,1), 0, kernel->lastIndex());
	a.scaleToRange(lowRange, highRange);
	
	
	// Map the temporary into the heightmap
	for(int x=0; x<=w; ++x)
	{
		for(int y=0; y<=h; ++y)
		{
			float nx=(float)x/(float)(w);
			float ny=(float)y/(float)(h);
			
			double v=a.get(x,y);
			if(useMask && mask)
			{
				float oldheight=GetHeightValue(height,x,y);
				float maskval=mask->GetPixelBilinear(nx,ny).r_;
				if(invertMask) maskval=1.0-maskval;
				v=oldheight+maskval*(v-oldheight);
			}
			SetHeightValue(height,x,y,v);
		}
	}
}

void RenderANLKernelToBuffer(CArray2Dd *buffer, CKernel *kernel, float lowrange, float highrange)
{
	if(!buffer) return;
	int w=buffer->width()-1;
	int h=buffer->height()-1;
	
	map2D(SEAMLESS_NONE, *buffer, *kernel, SMappingRanges(0,1,0,1,0,1), 0, kernel->lastIndex());
	buffer->scaleToRange(lowrange, highrange);
}

void SetHeightFromRasterBuffer(Image *height, CArray2Dd *buffer, Image *mask, bool useMask, bool invertMask)
{
	int w=height->GetWidth()-1;
	int h=height->GetHeight()-1;
	
	// Map the temporary into the heightmap
	for(int x=0; x<=w; ++x)
	{
		for(int y=0; y<=h; ++y)
		{
			float nx=(float)x/(float)(w);
			float ny=(float)y/(float)(h);
			
			float v=buffer->getBilinear(nx,ny);
			float m=1.0;
			float oldht=GetHeightValue(height,x,y);
			if(useMask && mask)
			{
				float maskval=mask->GetPixelBilinear(nx,ny).r_;
				if(invertMask) maskval=1.0-maskval;
				m=maskval;
			}
			SetHeightValue(height,x,y,oldht+m*(v-oldht));
		}
	}
}

float Orient2D(RasterVertex &a, RasterVertex &b, RasterVertex &c)
{
	return (float)(b.x_-a.x_)*(float)(c.y_-a.y_) - (float)(b.y_-a.y_)*(float)(c.x_-a.x_);
}


void RasterizeTriangle(CArray2Dd *buffer, RasterVertex v0, RasterVertex v1, RasterVertex v2)
{
	int minx=std::min(v0.x_, std::min(v1.x_, v2.x_));
	int maxx=std::max(v0.x_, std::max(v1.x_, v2.x_));
	int miny=std::min(v0.y_, std::min(v1.y_, v2.y_));
	int maxy=std::max(v0.y_, std::max(v1.y_, v2.y_));
	
	minx=std::max(0,minx);
	miny=std::max(0,miny);
	maxx=std::min(maxx, buffer->width()-1)+1;
	maxy=std::min(maxy, buffer->height()-1)+1;
	
	RasterVertex p(0,0,0);
	for(int y=miny; y<=maxy; ++y)
	{
		for(int x=minx; x<=maxx; ++x)
		{
			p.x_=x;
			p.y_=y;
			float w0=Orient2D(v1,v2,p);
			float w1=Orient2D(v2,v0,p);
			float w2=Orient2D(v0,v1,p);
			float sum=w0+w1+w2;
			w0/=sum;
			w1/=sum;
			w2/=sum;
			
			if(w0>=0 && w1>=0 && w2>=0)
			{
				float newval=(w0*v0.val_ + w1*v1.val_ +w2*v2.val_);
				buffer->set(x,(buffer->height()-1)-y,newval);
			}
		}
	}
}

void RasterizeQuadStrip(CArray2Dd *buffer, RasterVertexList *strip)
{
	for(int c=0; c<=strip->size()-4; c+=2)
	{
		RasterizeTriangle(buffer, (*strip)[c], (*strip)[c+1], (*strip)[c+2]);
		RasterizeTriangle(buffer, (*strip)[c+1], (*strip)[c+2], (*strip)[c+3]);
	}
}

void BlendHeightWithRasterizedBuffer(Image *height, CArray2Dd *buffer, CArray2Dd *blend, Image *mask, bool useMask, bool invertMask)
{
	for(int x=0; x<height->GetWidth()-1; ++x)
	{
		for(int y=0; y<height->GetHeight()-1; ++y)
		{
			float nx=(float)x / (float)(height->GetWidth());
			float ny=(float)y / (float)(height->GetHeight());
			
			float v=buffer->getBilinear(nx,ny);
			float bval=blend->getBilinear(nx,ny);
			float ht=GetHeightValue(height, x, y);
			if(useMask)
			{
				Color c=mask->GetPixelBilinear(nx,ny);
				float m=c.r_;
				if(invertMask) m=1.0f-m;
				bval*=m;
			}
			float newht=ht+bval*(v-ht);
			SetHeightValue(height,x,y,newht);
		}
	}
}

void BlendColorWithRasterizedBuffer(Image *img, CArray2Dd *buffer, Color endColor, Image *mask, bool useMask, bool invertMask)
{
	for(int x=0; x<img->GetWidth()-1; ++x)
	{
		for(int y=0; y<img->GetHeight()-1; ++y)
		{
			float nx=(float)x / (float)(img->GetWidth());
			float ny=(float)y / (float)(img->GetHeight());
			
			float bval=buffer->getBilinear(nx,ny);
			bval=std::max(0.0f, std::min(1.0f, bval));
			Color col=img->GetPixel(x,y);
			if(useMask)
			{
				Color c=mask->GetPixelBilinear(nx,ny);
				float m=c.r_;
				if(invertMask) m=1.0f-m;
				bval*=m;
			}
			Color newcol=col.Lerp(endColor, bval);
			img->SetPixel(x,y,newcol);
		}
	}
}

void BlendRasterizedBuffer8(Image *blend0, Image *blend1, CArray2Dd *buffer, int layer, Image *mask, bool useMask, bool invertMask)
{
	for(int x=0; x<blend0->GetWidth()-1; ++x)
	{
		for(int y=0; y<blend0->GetHeight()-1; ++y)
		{
			float nx=(float)x / (float)(blend0->GetWidth());
			float ny=(float)y / (float)(blend0->GetHeight());
			
			float i=buffer->getBilinear(nx,ny);
			i=std::max(0.0f, std::min(1.0f, i));
			if(useMask)
			{
				Color c=mask->GetPixelBilinear(nx,ny);
				float m=c.r_;
				if(invertMask) m=1.0f-m;
				i*=m;
			}
				Color col0=blend0->GetPixel(x,y);
				Color col1=blend1->GetPixel(x,y);
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
				blend0->SetPixel(x,y,col0);
				blend1->SetPixel(x,y,col1);
		}
	}
}

void BlendRasterizedBuffer8Max(Image *blend0, Image *blend1, CArray2Dd *buffer, int layer, Image *mask, bool useMask, bool invertMask)
{
	for(int x=0; x<blend0->GetWidth()-1; ++x)
	{
		for(int y=0; y<blend0->GetHeight()-1; ++y)
		{
			float nx=(float)x / (float)(blend0->GetWidth());
			float ny=(float)y / (float)(blend0->GetHeight());
			
			float i=buffer->getBilinear(nx,ny);
			i=std::max(0.0f, std::min(1.0f, i));
			if(useMask)
			{
				Color c=mask->GetPixelBilinear(nx,ny);
				float m=c.r_;
				if(invertMask) m=1.0f-m;
				i*=m;
			}
				Color col0=blend0->GetPixel(x,y);
				Color col1=blend1->GetPixel(x,y);
				if(layer==0)
				{
					col0.r_=std::max(col0.r_, i);
				}
				else if(layer==1)
				{
					col0.g_=std::max(col0.g_, i);
				}
				else if(layer==2)
				{
					col0.b_=std::max(col0.b_, i);
				}
				else if(layer==3)
				{
					col0.a_=std::max(col0.a_, i);
				}
				else if(layer==4)
				{
					col1.r_=std::max(col1.r_, i);
				}
				else if(layer==5)
				{
					col1.g_=std::max(col1.g_, i);
				}
				else if(layer==6)
				{
					col1.b_=std::max(col1.b_, i);
				}
				else if(layer==7)
				{
					col1.a_=std::max(col1.a_, i);
				}
				BalanceColors(col0, col1, layer);
				blend0->SetPixel(x,y,col0);
				blend1->SetPixel(x,y,col1);
		}
	}
}

RasterVertex CubicInterpolate(RasterVertex &p0, RasterVertex &p1, RasterVertex &p2, RasterVertex &p3, float t)
{
	// Catmull-Rom
	/*
	q(t) = 0.5 *(  	(2 * P1) +
 	(-P0 + P2) * t +
(2*P0 - 5*P1 + 4*P2 - P3) * t2 +
(-P0 + 3*P1- 3*P2 + P3) * t3)
	*/
	
	/*float t3=t*t*t;
	float t2=t*t;
	
	return RasterVertex(
		0.5*((2.0*p1.x_) + (-p0.x_ + p2.x_)*t + (2.0*p0.x_-5.0*p1.x_+4.0*p2.x_-p3.x_)*t2 + (-p0.x_+3.0*p1.x_-3.0*p2.x_+p3.x_)*t3),
		0.5*((2.0*p1.y_) + (-p0.y_ + p2.y_)*t + (2.0*p0.y_-5.0*p1.y_+4.0*p2.y_-p3.y_)*t2 + (-p0.y_+3.0*p1.y_-3.0*p2.y_+p3.y_)*t3),
		0.5*((2.0*p1.val_) + (-p0.val_ + p2.val_)*t + (2.0*p0.val_-5.0*p1.val_+4.0*p2.val_-p3.val_)*t2 + (-p0.val_+3.0*p1.val_-3.0*p2.val_+p3.val_)*t3)
	);*/
	
	return ((p1*2.0f) + (p2-p0)*t + (p0*2.0f - p1*5.0f + p2*4.0f - p3) * t*t + (p1*3.0f - p2*3.0f + p3 - p0) * t*t*t)*0.5f;
}

void TessellateLineList(RasterVertexList *in, RasterVertexList *out, int steps)
{
	//if(in->size()<4) return;
	
	CRSpline<Vector3> ll;
	for(int c=0; c<in->size(); ++c)
	{
		ll.Push(Vector3((*in)[c].x_, (*in)[c].y_, (*in)[c].val_));
	}
	
	Vector<Vector3> lo;
	ll.Solve(lo, steps*(ll.NumPoints()-1), 0.1);
	
	for(int c=0; c<lo.Size(); ++c)
	{
		out->push_back(RasterVertex(lo[c].x_, lo[c].y_, lo[c].z_));
	}
	
	
	/*float tinc=1.0 / (float)steps;
	out->resize(0);
	
	int A=0, B=0, C=std::min((int)in->size()-1,1), D=std::min((int)in->size()-1,2);
	float t=0.0;
	while(B != C)
	{
		t=0.0;
		for (int i=0; i<(C==D? steps+1 : steps); ++i)
		{
			RasterVertex p=CubicInterpolate((*in)[A], (*in)[B], (*in)[C], (*in)[D], t);
			t+=tinc;
			out->push_back(p);
		}
		A=B;
		B=C;
		C=D;
		D=D+1;
		if(D>in->size()-1) D=in->size()-1;
	}*/
	
	
}

void ApplyBedFunction(CArray2Dd *buffer, float hardness, bool quintic)
{
	for(int x=0; x<buffer->width(); ++x)
	{
		for(int y=0; y<buffer->height(); ++y)
		{
			float v=buffer->get(x,y);
			float h=std::max(0.0f, std::min(1.0f,hardness));
			v=std::abs(v*2.0-1.0);
			v=std::max(0.0, std::min(1.0, (v-1.0)/(h-1.0)));
			if(quintic) v=v*v*v*(v*(v*6.0-15.0)+10.0);
			buffer->set(x,y,v);
		}
	}
}

bool LinesAreParallel(RasterVertex p0, RasterVertex p1, RasterVertex q0, RasterVertex q1)
{
	float px=p1.x_-p0.x_;
	float py=p1.y_-p0.y_;
	float qx=q1.x_-q0.x_;
	float qy=q1.y_-q0.y_;
	
	if(std::abs(px*qy+py*qx)>0.999) return true;
	return false;
}

RasterVertex CalculateLineIntersection(RasterVertex p0, RasterVertex p1, RasterVertex q0, RasterVertex q1)
{
	RasterVertex u(p1.x_-p0.x_, p1.y_-p0.y_, p1.val_-p0.val_);
	RasterVertex v(q1.x_-q0.x_, q1.y_-q0.y_, q1.val_-q0.val_);
	RasterVertex w(p0.x_-q0.x_, p0.y_-q0.y_, p0.val_-q0.val_);
	
	float D=u.x_*v.x_ - u.y_*v.y_;
	float t=(float)(u.x_*w.y_-u.y_*w.x_)/(float)D;
	return RasterVertex((q0.x_ + t* v.x_), (q0.y_+t*v.y_), q0.val_+t*(q1.val_-q0.val_));
}

void BuildQuadStrip(RasterVertexList *in, RasterVertexList *out, float width)
{
	Vector<Vector3> points;
	for(int c=0; c<in->size(); ++c) points.Push(Vector3((*in)[c].x_, (*in)[c].y_, (*in)[c].val_));
	
	Vector<Vector3> quads;
	BuildQuadStripA(points, quads, width);
	
	out->resize(0);
	
	for(int c=0; c<quads.Size(); ++c) out->push_back(RasterVertex(quads[c].x_, quads[c].y_, quads[c].z_));
	/*if(in->size()<3) return;
	out->resize(0);
	
	RasterVertex p2=(*in)[1];
	RasterVertex p1=(*in)[0];
	float lx=(float)(p2.x_-p1.x_);
	float ly=(float)(p2.y_-p1.y_);
	float d=std::sqrt(lx*lx+ly*ly);
	lx/=d;
	ly/=d;
	float plx=-ly;
	float ply=lx;
	RasterVertex v1(p1.x_+0.5*width*plx, p1.y_+0.5*width*ply, p1.val_);
	RasterVertex v2(p1.x_-0.5*width*plx, p1.y_-0.5*width*ply, p1.val_);
	out->push_back(v1);
	out->push_back(v2);
	
	for(int i=1; i<in->size()-1; ++i)
	{
		float halfwidth=width*0.5;
		RasterVertex p1=(*in)[i-1];
		RasterVertex p2=(*in)[i];
		RasterVertex p3=(*in)[i+1];
		
		float l1x=(float)(p2.x_-p1.x_);
		float l1y=(float)(p2.y_-p1.y_);
		float l2x=(float)(p3.x_-p2.x_);
		float l2y=(float)(p3.y_-p2.y_);
		float d1=std::sqrt(l1x*l1x+l1y*l1y);
		float d2=std::sqrt(l2x*l2x+l2y*l2y);
		l1x/=d1;
		l1y/=d1;
		l2x/=d2;
		l2y/=d2;
		
		float pl1x=-l1y;
		float pl1y=l1x;
		float pl2x=-l2y;
		float pl2y=l2x;
		
		RasterVertex P0((p1.x_+pl1x*halfwidth), (p1.y_+pl1y*halfwidth), p1.val_);
		RasterVertex P1((p2.x_+pl1x*halfwidth), (p2.y_+pl1y*halfwidth), p2.val_);
		RasterVertex Q0((p2.x_+pl2x*halfwidth), (p2.y_+pl2y*halfwidth), p2.val_);
		RasterVertex Q1((p3.x_+pl2x*halfwidth), (p3.y_+pl2y*halfwidth), p3.val_);
		
		if(LinesAreParallel(P0,P1,Q0,Q1))
		{
			out->push_back(RasterVertex(P1.x_, P1.y_, p2.val_));
		}
		else
		{
			RasterVertex intersect=CalculateLineIntersection(P0,P1,Q0,Q1);
			intersect.val_=p2.val_;
			out->push_back(intersect);
		}
		
		P0=RasterVertex((p1.x_-pl1x*halfwidth), (p1.y_-pl1y*halfwidth), p1.val_);
		P1=RasterVertex((p2.x_-pl1x*halfwidth), (p2.y_-pl1y*halfwidth), p2.val_);
		Q0=RasterVertex((p2.x_-pl2x*halfwidth), (p2.y_-pl2y*halfwidth), p2.val_);
		Q1=RasterVertex((p3.x_-pl2x*halfwidth), (p3.y_-pl2y*halfwidth), p3.val_);
		
		if(LinesAreParallel(P0,P1,Q0,Q1))
		{
			out->push_back(RasterVertex(P1.x_, P1.y_, p2.val_));
		}
		else
		{
			RasterVertex intersect=CalculateLineIntersection(P0,P1,Q0,Q1);
			intersect.val_=p2.val_;
			out->push_back(intersect);
		}
	}
	
	p2=(*in)[in->size()-1];
	p1=(*in)[in->size()-2];
	lx=(float)(p2.x_-p1.x_);
	ly=(float)(p2.y_-p1.y_);
	d=std::sqrt(lx*lx+ly*ly);
	lx/=d;
	ly/=d;
	plx=-ly;
	ply=lx;
	v1=RasterVertex(p2.x_+0.5*width*plx, p2.y_+0.5*width*ply, p2.val_);
	v2=RasterVertex(p2.x_-0.5*width*plx, p2.y_-0.5*width*ply, p2.val_);
	out->push_back(v1);
	out->push_back(v2);*/
	
}

void BuildQuadStripVarying(RasterVertexList *in, RasterVertexList *out, float startwidth, float endwidth)
{
	if(in->size()<3) return;
	out->resize(0);
	
	float t=0.0f;
	float tinc=1.0f/(float)(in->size()-1);
	
	RasterVertex p2=(*in)[1];
	RasterVertex p1=(*in)[0];
	float lx=(float)(p2.x_-p1.x_);
	float ly=(float)(p2.y_-p1.y_);
	float d=std::sqrt(lx*lx+ly*ly);
	lx/=d;
	ly/=d;
	float plx=-ly;
	float ply=lx;
	float width=startwidth+t*(endwidth-startwidth);
	t+=tinc;
	RasterVertex v1(p1.x_+0.5*width*plx, p1.y_+0.5*width*ply, p1.val_);
	RasterVertex v2(p1.x_-0.5*width*plx, p1.y_-0.5*width*ply, p1.val_);
	out->push_back(v1);
	out->push_back(v2);
	
	for(int i=1; i<in->size()-1; ++i)
	{
		width=startwidth+t*(endwidth-startwidth);
		t+=tinc;
		float halfwidth=width*0.5;
		RasterVertex p1=(*in)[i-1];
		RasterVertex p2=(*in)[i];
		RasterVertex p3=(*in)[i+1];
		
		float l1x=(float)(p2.x_-p1.x_);
		float l1y=(float)(p2.y_-p1.y_);
		float l2x=(float)(p3.x_-p2.x_);
		float l2y=(float)(p3.y_-p2.y_);
		float d1=std::sqrt(l1x*l1x+l1y*l1y);
		float d2=std::sqrt(l2x*l2x+l2y*l2y);
		l1x/=d1;
		l1y/=d1;
		l2x/=d2;
		l2y/=d2;
		
		float pl1x=-l1y;
		float pl1y=l1x;
		float pl2x=-l2y;
		float pl2y=l2x;
		
		RasterVertex P0((p1.x_+pl1x*halfwidth), (p1.y_+pl1y*halfwidth), p1.val_);
		RasterVertex P1((p2.x_+pl1x*halfwidth), (p2.y_+pl1y*halfwidth), p2.val_);
		RasterVertex Q0((p2.x_+pl2x*halfwidth), (p2.y_+pl2y*halfwidth), p2.val_);
		RasterVertex Q1((p3.x_+pl2x*halfwidth), (p3.y_+pl2y*halfwidth), p3.val_);
		
		if(LinesAreParallel(P0,P1,Q0,Q1))
		{
			out->push_back(RasterVertex(P1.x_, P1.y_, p2.val_));
		}
		else
		{
			RasterVertex intersect=CalculateLineIntersection(P0,P1,Q0,Q1);
			intersect.val_=p2.val_;
			out->push_back(intersect);
		}
		
		P0=RasterVertex((p1.x_-pl1x*halfwidth), (p1.y_-pl1y*halfwidth), p1.val_);
		P1=RasterVertex((p2.x_-pl1x*halfwidth), (p2.y_-pl1y*halfwidth), p2.val_);
		Q0=RasterVertex((p2.x_-pl2x*halfwidth), (p2.y_-pl2y*halfwidth), p2.val_);
		Q1=RasterVertex((p3.x_-pl2x*halfwidth), (p3.y_-pl2y*halfwidth), p3.val_);
		
		if(LinesAreParallel(P0,P1,Q0,Q1))
		{
			out->push_back(RasterVertex(P1.x_, P1.y_, p2.val_));
		}
		else
		{
			RasterVertex intersect=CalculateLineIntersection(P0,P1,Q0,Q1);
			intersect.val_=p2.val_;
			out->push_back(intersect);
		}
	}
	
	p2=(*in)[in->size()-1];
	p1=(*in)[in->size()-2];
	lx=(float)(p2.x_-p1.x_);
	ly=(float)(p2.y_-p1.y_);
	d=std::sqrt(lx*lx+ly*ly);
	lx/=d;
	ly/=d;
	plx=-ly;
	ply=lx;
	width=startwidth+t*(endwidth-startwidth);
	t+=tinc;
	v1=RasterVertex(p2.x_+0.5*width*plx, p2.y_+0.5*width*ply, p2.val_);
	v2=RasterVertex(p2.x_-0.5*width*plx, p2.y_-0.5*width*ply, p2.val_);
	out->push_back(v1);
	out->push_back(v2);
}

void CopyImageInto(Image *dest, Image *src, int x, int y)
{
	if(!dest || !src) return;
	
	for(int j=0; j<src->GetHeight(); ++j)
	{
		for(int i=0; i<src->GetWidth(); ++i)
		{
			dest->SetPixel(x+i,  y+j, src->GetPixel(i,j));
		}
	}
}

bool IsPowerOfTwo(int n)
{
	return (n & (n-1))==0;
}

Image* GetNextImageLevel(Image *i)
{
	if(!i) return 0;
	
	return i->GetNextLevel();
}

void ExtractLayerToBuffer(Image *blend1, Image *blend2, CArray2Dd *buffer, int layer)
{
	if((layer>=0 && layer<4) && !blend1) return;
	else if((layer>=4 && layer<8) && !blend2) return;
	else return;
	
	if(buffer->width() != blend1->GetWidth() || buffer->height()!=blend1->GetHeight()) return;
	for(int x=0; x<buffer->width(); ++x)
	{
		for(int y=0; y<buffer->height(); ++y)
		{
			Color c;
			if(layer>=0 && layer<4) c=blend1->GetPixel(x,y);
			else c=blend2->GetPixel(x,y);
			
			float v=0;
			if(layer==0 || layer==4) v=c.r_;
			else if(layer==1 || layer==5) v=c.g_;
			else if(layer==2 || layer==6) v=c.b_;
			else v=c.a_;
			
			buffer->set(x,y,v);
		}
	}
}

float GetLayerBlend(Image *blend1, Image *blend2, int x, int y, int layer)
{
	if(layer<0 || layer>7) return 0.0f;
	
	Color c;
	if(layer<4)
	{
		if(!blend1) return 0.0f;
		c=blend1->GetPixel(x,y);
	}
	else
	{
		if(!blend2) return 0.0f;
		c=blend2->GetPixel(x,y);
	}
	if(layer==0 || layer==4) return c.r_;
	else if(layer==1 || layer==5) return c.g_;
	else if(layer==2 || layer==6) return c.b_;
	else return c.a_;
}

void SetLayerBlend(Image *blend1, Image *blend2, int x, int y, int layer, float v)
{
	if(layer<0 || layer>7) return;
	Color col0, col1;
	
	if(!blend1 || !blend2) return;
	
	col0=blend1->GetPixel(x,y);
	col1=blend2->GetPixel(x,y);
	if(layer==0) col0.r_=v;
	else if(layer==1) col0.g_=v;
	else if(layer==2) col0.b_=v;
	else if(layer==3) col0.a_=v;
	else if(layer==4) col1.r_=v;
	else if(layer==5) col1.g_=v;
	else if(layer==6) col1.b_=v;
	else col1.a_=v;
	BalanceColors(col0, col1, layer);
	blend1->SetPixel(x,y,col0);
	blend2->SetPixel(x,y,col1);
}

void DistortBuffer(CArray2Dd *buffer, CArray2Dd *xd, CArray2Dd *yd, double power)
{
	CArray2Dd tmp(buffer->width(), buffer->height());
	tmp.copyFrom(buffer);
	
	
	int w=buffer->width(), h=buffer->height();
	
	for(int x=0; x<w; ++x)
	{
		for(int y=0; y<h; ++y)
		{
			CCoordinate c((double)x / (double)w, (double)y / (double)h, 0);
			
			int newx=(int)((double)x+power*xd->get(x,y));
			int newy=(int)((double)y+power*yd->get(x,y));
			newx=std::max(0, std::min(w-1, newx));
			newy=std::max(0, std::min(h-1, newy));
			buffer->set(x,y, tmp.get(newx, newy));
		}
	}
}

void SteepnessTerrain(Image *blend0, Image *blend1, Image *hmap, Terrain *terrain, Image *mask, float threshold, float fade, unsigned int layer, bool usemask, bool invertmask)
{
	unsigned int bw=blend0->GetWidth();
	unsigned int bh=blend0->GetHeight();
	float halffade=fade*0.5f;
	
	CArray2Dd buffer(bw,bh);
	
	for(unsigned int y=0; y<bh; ++y)
	{
		for(unsigned int x=0; x<bw; ++x)
		{
			Vector2 nworld=Vector2((float)(x)/(float)(bw-1), (float)(y)/(float)(bh-1));
			Vector3 world=NormalizedToWorld(hmap, terrain, nworld);
			Vector3 normal=terrain->GetNormal(world);
			
			float steep=std::abs(normal.DotProduct(Vector3(0,1,0)));
			float i=(steep-(threshold-halffade))/fade;
			i=std::max(0.0f, std::min(1.0f, i));
			i=1.0f-i;
			buffer.set(x,(bh-1)-y, i);
		}
	}
	BlendRasterizedBuffer8Max(blend0, blend1, &buffer, layer, mask, usemask, invertmask);;
}
