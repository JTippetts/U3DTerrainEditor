#pragma once

#include <Urho3D/Core/Object.h>
#include <Urho3D/Core/Context.h>
#include <Urho3D/Graphics/Terrain.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Resource/Image.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <Urho3D/Scene/Node.h>
#include <Urho3D/Scene/Scene.h>

#include "../ThirdParty/accidental-noise-library/anl.h"
using namespace anl;
using namespace Urho3D;

struct BrushSettings
{
	float radius_, max_, power_, hardness_;
	
	BrushSettings() : radius_(0.01), max_(0), power_(0), hardness_(0.01){}
	BrushSettings(float r, float m, float p, float h) : radius_(r), max_(m), power_(p), hardness_(h){}
};

struct MaskSettings
{
	bool usemask0_, usemask1_, usemask2_;
	bool invert0_, invert1_, invert2_;
	
	MaskSettings() : usemask0_(false), usemask1_(false), usemask2_(false), invert0_(false), invert1_(false), invert2_(false){}
	MaskSettings(bool um1, bool im1, bool um2, bool im2, bool um3, bool im3) : usemask0_(um1), invert0_(im1), usemask1_(um2), invert1_(im2), usemask2_(um3), invert2_(im3){}
};

enum
{
	HeightReplace,
	HeightAdd,
	HeightSubtract,
	HeightMultiply,
	HeightMin,
	HeightMax
};

// Terrain context

class EditingCamera;
class TerrainContext : public Object
{
	URHO3D_OBJECT(TerrainContext, Object);
	public:
	TerrainContext(Context *context);
	
	void Construct(Scene *scene, EditingCamera *camera);
	void SetHeightMapSize(const IntVector2 &size);
	void SetBlendMapSize(const IntVector2 &size);
	void SetMaskSize(const IntVector2 &size);
	void SetTerrainMaterial(Material *m);
	void SetWaterMaterial(Material *m, bool usewaterdepth);
	
	void ClearHeightMap();
	void ClearBlendMaps();
	void ClearMask();
	void ClearWaterMap();
	void Clear();
	void Save(const String &path);
	void Load(const String &path);
	
	void SetSpacing(const Vector3 &spacing);
	
	Vector2 WorldToNormalized(Vector3 world);
    Vector3 NormalizedToWorld(Vector2 normalized);
	IntVector2 NormalizedToTerrain(Vector2 norm);
	
	Material *GetTerrainMaterial(){return terrainMaterial_;}
	Image *GetHeightMap(){return &terrainMap_;}
	void GetHeightMap(CArray2Dd &buffer);
	Image *GetWaterHeightMap(){return &waterMap_;}
	void SetTerrainDirty(){terraindirty_=true;}
	void SetWaterDirty(){waterdirty_=true;}
	
	BoundingBox GetBoundingBox();
	
	float GetHeightValue(Vector3 worldpos);
	float GetHeight(Vector3 worldpos);
	float GetHeightValue(int x, int y);
	void SetHeightValue(int x, int y, float val);
	float GetWaterValue(Vector3 worldpos);
	float GetWaterValue(int x, int y);
	void SetWaterValue(int x, int y, float val);
	float GetHeightValueFromNormalized(Vector2 nrm);
	float GetWaterValueFromNormalized(Vector2 nrm);
	
	void InvertMask(int which);
    void ClearMask(int which);
    void ClearAllMasks();
	void BuildWaterDepthTexture();
	
	void ApplyHeightAlpha(float x, float z, float dt, BrushSettings &brush, MaskSettings &masksettings, Image &alpha, float angle);
	void ApplyBlendAlpha(float x, float z, int layer, float dt, BrushSettings &brush, MaskSettings &masksettings, Image &alpha, float angle);
	void ApplyWaterBrush(float x, float z, float dt, BrushSettings &brush, MaskSettings &masksettings);
	void ApplySmoothBrush(float x, float z, float dt, BrushSettings &brush, MaskSettings &masksettings);
	void ApplyMaskBrushAlpha(float x, float z, int which, float dt, BrushSettings &brush, MaskSettings &masksettings, Image &alpha, float angle);
	
	void SetHeightBuffer(CArray2Dd &buffer, MaskSettings &masksettings, int blendop);
	void SetWaterBuffer(CArray2Dd &buffer, MaskSettings &masksettings, int blendop);
    void SetLayerBuffer(CArray2Dd &buffer, int layer, MaskSettings &masksettings);
    void SetLayerBufferMax(CArray2Dd &buffer, int layer, MaskSettings &masksettings);
    void BlendHeightBuffer(CArray2Dd &buffer, CArray2Dd &blend, MaskSettings &masksettings);
	void SetMaskBuffer(CArray2Dd &buffer, int which);
	
	IntVector2 GetTerrainMapSize(){return IntVector2(terrainMap_.GetWidth(), terrainMap_.GetHeight());}
	IntVector2 GetBlendMapSize(){return IntVector2(blend0_.GetWidth(), blend0_.GetHeight());}
	void GetSteepness(CArray2Dd &buffer, float threshold, float fade);
	void GetCavityMap(CArray2Dd &buffer, float sampleradius, float scale, float bias, float intensity, unsigned int iterations);
	void FillBasins(CArray2Dd &arr, float E);
	
	protected:
	// Terrain
	Node *terrainNode_;
	Terrain *terrain_;
	Material *terrainMaterial_;
	
	// Water
	Node *waterNode_;
	Terrain *water_;
	Material *waterMaterial_;
	
	bool materialdirty_, watermaterialdirty_;
	bool terraindirty_, waterdirty_;
	
	Vector3 spacing_;
	// Images
	Image terrainMap_, waterMap_, blend0_, blend1_, mask_, waterDepth_;
	SharedPtr<Texture2D> blend0Tex_, blend1Tex_, maskTex_, waterDepthTex_;
	EditingCamera *camera_;
	
	void HandleBeginFrame(StringHash eventType, VariantMap &eventData);
	float CalcSmooth(Image *height, float *kernel, int kernelsize, int terrainx, int terrainz);
	bool LoadImage(const String &filename, Image &img);
	float DoAmbientOcclusion(Vector2 tcoord, Vector2 uv, Vector3 p, Vector3 cnorm, float scale, float bias, float intensity);
};