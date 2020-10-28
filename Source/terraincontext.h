#pragma once

#include <Urho3D/Core/Object.h>
#include <Urho3D/Core/Context.h>
#include <Urho3D/Graphics/Terrain.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Resource/Image.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <Urho3D/Scene/Node.h>
#include <Urho3D/Scene/Scene.h>

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
	
	void SetSpacing(const Vector3 &spacing);
	
	Vector2 WorldToNormalized(Vector3 world);
    Vector3 NormalizedToWorld(Vector2 normalized);
	
	Material *GetTerrainMaterial(){return terrainMaterial_;}
	Image *GetHeightMap(){return &terrainMap_;}
	Image *GetWaterHeightMap(){return &waterMap_;}
	void SetTerrainDirty(){terraindirty_=true;}
	void SetWaterDirty(){waterdirty_=true;}
	
	float GetHeightValue(Vector3 worldpos);
	float GetHeight(Vector3 worldpos);
	float GetHeightValue(int x, int y);
	void SetHeightValue(int x, int y, float val);
	float GetWaterValue(Vector3 worldpos);
	float GetWaterValue(int x, int y);
	void SetWaterValue(int x, int y, float val);
	
	void InvertMask(int which);
    void ClearMask(int which);
    void ClearAllMasks();
	
	void ApplyHeightAlpha(float x, float z, float dt, BrushSettings &brush, MaskSettings &masksettings, Image &alpha, float angle);
	void ApplyBlendAlpha(float x, float z, int layer, float dt, BrushSettings &brush, MaskSettings &masksettings, Image &alpha, float angle);
	void ApplyWaterBrush(float x, float z, float dt, BrushSettings &brush, MaskSettings &masksettings);
	void ApplySmoothBrush(float x, float z, float dt, BrushSettings &brush, MaskSettings &masksettings);
	void ApplyMaskBrushAlpha(float x, float z, int which, float dt, BrushSettings &brush, MaskSettings &masksettings, Image &alpha, float angle);
	
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
};