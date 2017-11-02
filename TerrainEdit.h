// C++ Implementation of Terrain Editing Component

#ifndef TERRAINEDIT_H
#define TERRAINEDIT_H

#include <Urho3D/Urho3D.h>

#include <Urho3D/Container/ArrayPtr.h>
#include <Urho3D/Graphics/Terrain.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <Urho3D/Resource/Image.h>
#include <Urho3D/Container/Str.h>
#include <Urho3D/Graphics/CustomGeometry.h>

#include "ThirdParty/accidental-noise-library/anl.h"


using namespace Urho3D;
using namespace anl;

struct BrushSettings
{
    float radius, max, power, hardness;

    BrushSettings() : radius(0), max(0), power(0), hardness(0) {}
    BrushSettings(float r, float mx, float p, float h) :
        radius(r), max(mx), power(p), hardness(h) {}
};

struct MaskSettings
{
    bool usemask0, usemask1, usemask2;
    bool invertmask0, invertmask1, invertmask2;

    MaskSettings() : usemask0(false), usemask1(false), usemask2(false), invertmask0(false), invertmask1(false), invertmask2(false) {}
    MaskSettings(bool um0, bool im0, bool um1, bool im1, bool um2, bool im2) : usemask0(um0), usemask1(um1), usemask2(um2), invertmask0(im0),
        invertmask1(im1), invertmask2(im2) {}

};

class TerrainEdit// : public Object
{
    //URHO3D_OBJECT(TerrainEdit, Object);
public:
    //TerrainEdit(Context *context);
    TerrainEdit();

    bool Initialize(Scene *scene, int tw, int th, int bw, int bh, Vector3 spacing, bool use16bit=true);
    void SetTerrainSize(int w, int h, Vector3 spacing, bool use16bit=true);
    void SetBlendMaskSize(int w, int h);
    void SetTerrainSpacing(Vector3 spacing);

    Vector2 WorldToNormalized(Vector3 world);
    Vector3 NormalizedToWorld(Vector2 normalized);
    IntVector2 WorldToTerrain(Vector3 world);
    IntVector2 WorldToBlend(Vector3 world);
    Vector3 TerrainToWorld(IntVector2 terrain);
    Vector3 BlendToWorld(IntVector2 blend);
    Vector2 TerrainToNormalized(IntVector2 terrain);
    Vector2 BlendToNormalized(IntVector2 blend);
    IntVector2 NormalizedToBlend(Vector2 norm);
    IntVector2 NormalizedToTerrain(Vector2 norm);

    void SetHeightValue(int x, int y, float val);
    float GetHeightValue(int x, int y);
	float GetHeightValueFromNormalized(Vector2 nrm);

    int GetTerrainWidth()
    {
        if (hmap_) return hmap_->GetWidth();
        return 0;
    }
    int GetTerrainHeight()
    {
        if (hmap_) return hmap_->GetHeight();
        return 0;
    }
    int GetBlendWidth()
    {
        if (blend0_) return blend0_->GetWidth();
        return 0;
    }
    int GetBlendHeight()
    {
        if (blend0_) return blend0_->GetHeight();
        return 0;
    }

    float GetHeightValue(Vector3 worldpos);
	void GetHeightMap(CArray2Dd &buffer);

    void SetHeightBuffer(CArray2Dd &buffer, MaskSettings &masksettings);
    void SetLayerBuffer(CArray2Dd &buffer, int layer, MaskSettings &masksettings);
    void SetLayerBufferMax(CArray2Dd &buffer, int layer, MaskSettings &masksettings);
    void BlendHeightBuffer(CArray2Dd &buffer, CArray2Dd &blend, MaskSettings &masksettings);
	void SetMaskBuffer(CArray2Dd &buffer, int which);

    void ApplyHeightBrush(float x, float z, float dt, BrushSettings &brush, MaskSettings &masksettings);
    void ApplyBlendBrush(float x, float z, int layer, float dt, BrushSettings &brush, MaskSettings &masksettings);
    void ApplyMaskBrush(float x, float z, int which, float dt, BrushSettings &brush, MaskSettings &masksettings);
    void ApplySmoothBrush(float x, float z, float dt, BrushSettings &brush, MaskSettings &masksettings);

    void SetBrushCursorHeight(CustomGeometry *brush, float groundx, float groundz);

    void InvertMask(int which);
    void ClearMask(int which);
    void ClearAllMasks();

    void InvertLayer(int which);
    void ClearLayer(int which);
    void ClearAllLayers();

    void InvertHeight();
    void ClearHeight();

    Material *GetMaterial()
    {
        return material_;
    }
    Terrain *GetTerrain()
    {
        return terrain_;
    }
    void SetMaterialSettings(bool triplanar, bool smoothing, bool normalmapping, bool reduce);

    void SaveHeightMap(const String &filename);
    void SaveBlend0(const String &filename);
    void SaveBlend1(const String &filename);
    void SaveMask(const String &filename);

    void LoadHeightMap(const String &filename);
    void LoadBlend0(const String &filename);
    void LoadBlend1(const String &filename);
    void LoadMask(const String &filename);

    void GetSteepness(CArray2Dd &buffer, float threshold, float fade);
	void GetCavityMap(CArray2Dd &buffer, float sampleradius, float scale, float bias, float intensity, unsigned int iterations);
	
	Vector3 GetTerrainSpacing();
	void SaveTerrainNormalMap(const String &filename);

protected:
    Node *terrainNode_;
    Terrain *terrain_;
    Material *material_;

    Image *hmap_, *blend0_, *blend1_, *mask_;
    SharedPtr<Texture2D> blendtex0_, blendtex1_, masktex_;

    bool use16bit_;
    bool triplanar_, smoothing_, normalmapping_;
	
	float DoAmbientOcclusion(Vector2 tcoord, Vector2 uv, Vector3 p, Vector3 cnorm, float scale, float bias, float intensity);
};

Vector2 WorldToNormalized(Image *height, Terrain *terrain, Vector3 world);
Vector3 NormalizedToWorld(Image *height, Terrain *terrain, Vector2 normalized);

void SetHeightValue(Image *height, int x, int y, float val);
float GetHeightValue(Image *height, int x, int y);

void ApplyHeightBrush(Terrain *terrain, Image *height, Image *mask, float x, float z, float radius, float max, float power, float hardness, bool usemask0, bool usemask1, bool usemask2, float dt);
void ApplyBlendBrush(Terrain *terrain, Image *height, Image *blend, Image *mask, float x, float z, float radius, float mx, float power, float hardness, int layer, bool usemask0, bool usemask1, bool usemask2, float dt);
void ApplyBlendBrush8(Terrain *terrain, Image *height, Image *blend0, Image *blend1, Image *mask, float x, float z, float radius, float mx, float power, float hardness, int layer, bool usemask0, bool usemask1, bool usemask2, float dt);
void ApplyMaskBrush(Terrain *terrain, Image *height, Image *mask, float x, float z, float radius, float mx, float power, float hardness, float dt, int which);
void ApplySmoothBrush(Terrain *terrain, Image *height, Image *mask, float x, float z, float radius, float max, float power, float hardness, bool usemask0, bool usemask1, bool usemask2, float dt);
void ApplySpeckleBrush(Terrain *terrain, Image *height, Image *color, Image *mask, float x, float z, float radius, float mx, float power, float hardness, Color c1, Color c2, bool usemask, float dt);

void SetBrushCursorHeight(Terrain *terrain, CustomGeometry *brush, float groundx, float groundz);

void InvertMask(Image *mask);
void RenderANLKernelToHeight(Image *height, Image *mask, CKernel *kernel, double lowRange=0, double highRange=1, bool useMask=false, bool invertMask=false);

struct RasterVertex
{
    float x_, y_;
    float val_;

    RasterVertex() : x_(0), y_(0), val_(0) {}
    RasterVertex(float x, float y, float val): x_(x), y_(y), val_(val) {}
    RasterVertex(const RasterVertex &rhs) : x_(rhs.x_), y_(rhs.y_), val_(rhs.val_) {}
    ~RasterVertex() {}

    void operator=(const RasterVertex &rhs)
    {
        x_=rhs.x_;
        y_=rhs.y_;
        val_=rhs.val_;
    }

    RasterVertex operator-(const RasterVertex &rhs)
    {
        RasterVertex v;
        v.x_=x_-rhs.x_;
        v.y_=y_-rhs.y_;
        v.val_=val_-rhs.val_;
        return v;
    }

    RasterVertex operator+(const RasterVertex &rhs)
    {
        RasterVertex v;
        v.x_=x_+rhs.x_;
        v.y_=y_+rhs.y_;
        v.val_=val_+rhs.val_;
        return v;
    }

    RasterVertex operator*(const RasterVertex &rhs)
    {
        RasterVertex v;
        v.x_=x_*rhs.x_;
        v.y_=y_*rhs.y_;
        v.val_=val_*rhs.val_;
        return v;
    }

    RasterVertex operator*(float t)
    {
        RasterVertex v;
        v.x_=x_*t;
        v.y_=y_*t;
        v.val_=val_*t;
        return v;
    }

};

typedef TArray1D<RasterVertex> RasterVertexList;
//typedef TArray2D<float> CArray2Dd;

void RasterizeTriangle(CArray2Dd *buffer, RasterVertex v1, RasterVertex v2, RasterVertex v3);
void RasterizeQuadStrip(CArray2Dd *buffer, RasterVertexList *strip);
void BlendHeightWithRasterizedBuffer(Image *height, CArray2Dd *buffer, CArray2Dd *blend, Image *mask=0, bool useMask=false, bool invertMask=false);
void BlendColorWithRasterizedBuffer(Image *img, CArray2Dd *buffer, Color endColor, Image *mask=0, bool useMask=false, bool invertMask=false);
void BlendRasterizedBuffer8(Image *img, Image *other, CArray2Dd *buffer, int layer, Image *mask=0, bool useMask=false, bool invertMask=false);
void BlendRasterizedBuffer8Max(Image *img, Image *other, CArray2Dd *buffer, int layer, Image *mask=0, bool useMask=false, bool invertMask=false);
void TessellateLineList(RasterVertexList *in, RasterVertexList *out, int steps);
void ApplyBedFunction(CArray2Dd *buffer, float hardness, bool quintic);
void BuildQuadStrip(RasterVertexList *in, RasterVertexList *out, float width);
void BuildQuadStripVarying(RasterVertexList *in, RasterVertexList *out, float startwidth, float endwidth);
void RenderANLKernelToBuffer(CArray2Dd *buffer, CKernel *kernel, float lowrange=0, float highrange=1);
void RenderANLKernelToImage(Image *buffer, CKernel *kernel, float lowrange=0, float highrange=1);
void SetHeightFromRasterBuffer(Image *height, CArray2Dd *buffer, Image *mask=0, bool useMask=false, bool invertMask=false);

void BuildQuadStripRoad(RasterVertexList *curve, int steps, float width, float lengthscale, CustomGeometry *geom);

void DistortBuffer(CArray2Dd *buffer, CArray2Dd *xd, CArray2Dd *yd, double power);

void CopyImageInto(Image *dest, Image *src, int x, int y);
bool IsPowerOfTwo(int n);
Image* GetNextImageLevel(Image *i);
void ExtractLayerToBuffer(Image *blend1, Image *blend2, CArray2Dd *buffer, int layer);
float GetLayerBlend(Image *blend1, Image *blend2, int x, int y, int layer);
void SetLayerBlend(Image *blend1, Image *blend2, int x, int y, int layer, float v);

bool LoadImage(Context *c, Image *i, const char *fname);

void SteepnessTerrain(Image *blend0, Image *blend1, Image *hmap, Terrain *terrain, Image *mask, float threshold, float fade, unsigned int layer, bool usemask, bool invertmask);

#endif
