#ifndef HEXTERRAINEDIT_H
#define HEXTERRAINEDIT_H

#include "TerrainEdit.h"


class HexTerrainEdit// : public Object
{
    //URHO3D_OBJECT(TerrainEdit, Object);
public:
    //TerrainEdit(Context *context);
    HexTerrainEdit();
	
	void ResizeTerrain(int tw, int th, bool use16bit);
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

#endif
