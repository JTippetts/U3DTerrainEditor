#include "TerrainEdit.h"
#include "ThirdParty/ANL/templates/tarrays.h"
#include "ThirdParty/ANL/VM/random_gen.h"

#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Scene/Node.h>
#include <Urho3D/Graphics/Material.h>
#include <algorithm>
#include <cmath>
#include <Urho3D/IO/Log.h>

	
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

	
void ApplyHeightBrush(Terrain *terrain, Image *height, Image *mask, float x, float z, float radius, float max, float power, float hardness, bool usemask, float dt)
{
	if(!terrain || !height || !terrain) return;
	
	Vector3 world=Vector3(x,0,z);
	IntVector2 ht=terrain->WorldToHeightMap(world);
	
	int sz=(int)radius+1;
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
				if(usemask)
				{
					float m=mask->GetPixelBilinear((float)(hx)/(float)(height->GetWidth()), (float)(hz)/(float)(height->GetHeight())).r_;
					i=i*m;
				}
				float hval=GetHeightValue(height,hx,hz);
				float newhval=hval+(max-hval)*i;
				SetHeightValue(height,hx,hz,newhval);
				
			}
		}
	}
}

void ApplyBlendBrush(Terrain *terrain, Image *height, Image *blend, Image *mask, float x, float z, float radius, float mx, float power, float hardness, int layer, bool usemask, float dt)
{
	if(!blend || !height || !terrain) return;
	
	Vector2 normalized=WorldToNormalized(height,terrain,Vector3(x,0,z));
	float ratio=((float)blend->GetWidth()/(float)height->GetWidth());
	int ix=(int)(normalized.x_*(float)(blend->GetWidth()-1));
	int iy=(int)(normalized.y_*(float)(blend->GetHeight()-1));
	iy=blend->GetHeight()-iy;
	float rad=radius*ratio;
	int sz=(int)rad+1;
	
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
				if(usemask)
				{
					float m=mask->GetPixelBilinear((float)(hx)/(float)(blend->GetWidth()), (float)(hz)/(float)(blend->GetHeight())).r_;
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

void ApplyBlendBrush8(Terrain *terrain, Image *height, Image *blend0, Image *blend1, Image *mask, float x, float z, float radius, float mx, float power, float hardness, int layer, bool usemask, float dt)
{
	if(!blend0 || !blend1 || !height || !terrain) return;
	
	Vector2 normalized=WorldToNormalized(height,terrain,Vector3(x,0,z));
	float ratio=((float)blend0->GetWidth()/(float)height->GetWidth());
	int ix=(int)(normalized.x_*(float)(blend0->GetWidth()-1));
	int iy=(int)(normalized.y_*(float)(blend0->GetHeight()-1));
	iy=blend0->GetHeight()-iy;
	float rad=radius*ratio;
	int sz=(int)rad+1;
	
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
				if(usemask)
				{
					float m=mask->GetPixelBilinear((float)(hx)/(float)(blend0->GetWidth()), (float)(hz)/(float)(blend0->GetHeight())).r_;
					i=i*m;
				}
				Color col0=blend0->GetPixel(hx,hz);
				Color col1=blend1->GetPixel(hx,hz);
				if(layer==1)
				{
					col0.r_=col0.r_+i*(1.0f-col0.r_);
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
				else if(layer==2)
				{
					col0.g_=col0.g_+i*(1.0f-col0.g_);
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
				else if(layer==3)
				{
					col0.b_=col0.b_+i*(1.0f-col0.b_);
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
				else if(layer==4)
				{
					col0.a_=col0.a_+i*(1.0f-col0.a_);
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
				else if(layer==5)
				{
					col1.r_=col1.r_+i*(1.0f-col1.r_);
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
				else if(layer==6)
				{
					col1.g_=col1.g_+i*(1.0f-col1.g_);
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
				else if(layer==7)
				{
					col1.b_=col1.b_+i*(1.0f-col1.b_);
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
				else if(layer==8)
				{
					col1.a_=col1.a_+i*(1.0f-col1.a_);
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
				blend0->SetPixel(hx,hz,col0);
				blend1->SetPixel(hx,hz,col1);
				//LOGINFO(String(col.r_)+String(",")+String(col.g_));
			}
		}
	}
}

void ApplyMaskBrush(Terrain *terrain, Image *height, Image *mask, float x, float z, float radius, float mx, float power, float hardness, float dt)
{
	if(!mask || !height || !terrain) return;
	
	Vector2 normalized=WorldToNormalized(height,terrain,Vector3(x,0,z));
	float ratio=((float)mask->GetWidth()/(float)height->GetWidth());
	int ix=(int)(normalized.x_*(float)(mask->GetWidth()-1));
	int iy=(int)(normalized.y_*(float)(mask->GetHeight()-1));
	iy=mask->GetHeight()-iy;
	float rad=radius*ratio;
	int sz=(int)rad+1;
	
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
				col.r_=col.r_+i*((1.0f-mx)-col.r_);
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
	int ix=(int)(normalized.x_*(float)(color->GetWidth()-1));
	int iy=(int)(normalized.y_*(float)(color->GetHeight()-1));
	iy=color->GetHeight()-iy;
	float rad=radius*ratio;
	int sz=(int)rad+1;
	
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

float CalcSmooth(Image *height, float *kernel, int kernelsize, int terrainx, int terrainz)
{
	float sum=0.0f;
	float weight=0.0f;
	int ox=terrainx-std::ceil(kernelsize/2);
	int oz=terrainz-std::ceil(kernelsize/2);
	
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

void ApplySmoothBrush(Terrain *terrain, Image *height, Image *mask, float x, float z, float radius, float max, float power, float hardness, bool usemask, float dt)
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
	
	int sz=(int)radius+1;
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
				if(usemask)
				{
					float m=mask->GetPixelBilinear((float)(hx)/(float)(height->GetWidth()), (float)(hz)/(float)(height->GetHeight())).r_;
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
	
	CNoiseExecutor vm(kernel->getKernel());
	
	TArray2D<double> a(height->GetWidth(), height->GetHeight());
	double mx=-10000;
	double mn=100000;
	
	// Map the ANL module into a temporary buffer
	for(int x=0; x<=w; ++x)
	{
		for(int y=0; y<=h; ++y)
		{
			float nx=(float)x/(float)(w);
			float ny=(float)y/(float)(h);
			CCoordinate coord(nx,ny,0);
			double val=vm.evaluate(coord).outfloat_;
			a.set(x,y,val);
			if(val>mx) mx=val;
			if(val<mn) mn=val;
		}
	}
	
	// Map the temporary into the heightmap
	for(int x=0; x<=w; ++x)
	{
		for(int y=0; y<=h; ++y)
		{
			float nx=(float)x/(float)(w);
			float ny=(float)y/(float)(h);
			
			double v=(a.get(x,y)-mn)/(mx-mn);
			v=lowRange+v*(highRange-lowRange);
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