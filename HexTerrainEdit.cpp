#include "HexTerrainEdit.h"



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
#include <Urho3D/Container/Vector.h>
#include "Spline.h"
#include <iostream>



HexTerrainEdit::HexTerrainEdit()
{
}
	
void HexTerrainEdit::ResizeTerrain(int tw, int th, bool use16bit)
{
}
bool HexTerrainEdit::Initialize(Scene *scene, int tw, int th, int bw, int bh, Vector3 spacing, bool use16bit)
{
}
void HexTerrainEdit::SetTerrainSize(int w, int h, Vector3 spacing, bool use16bit)
{
}
void HexTerrainEdit::SetBlendMaskSize(int w, int h)
{
}
void HexTerrainEdit::SetTerrainSpacing(Vector3 spacing)
{
}
Vector2 HexTerrainEdit::WorldToNormalized(Vector3 world)
{
}
Vector3 HexTerrainEdit::NormalizedToWorld(Vector2 normalized)
{
}
IntVector2 HexTerrainEdit::WorldToTerrain(Vector3 world)
{
}
IntVector2 HexTerrainEdit::WorldToBlend(Vector3 world)
{
}
Vector3 HexTerrainEdit::TerrainToWorld(IntVector2 terrain)
{
}
Vector3 HexTerrainEdit::BlendToWorld(IntVector2 blend)
{
}
Vector2 HexTerrainEdit::TerrainToNormalized(IntVector2 terrain)
{
}
Vector2 HexTerrainEdit::BlendToNormalized(IntVector2 blend)
{
}
IntVector2 HexTerrainEdit::NormalizedToBlend(Vector2 norm)
{
}
IntVector2 HexTerrainEdit::NormalizedToTerrain(Vector2 norm)
{
}

void HexTerrainEdit::SetHeightValue(int x, int y, float val)
{
}
float HexTerrainEdit::GetHeightValue(int x, int y)
{
}

float HexTerrainEdit::GetHeightValueFromNormalized(Vector2 nrm)
{
}

float HexTerrainEdit::GetHeightValue(Vector3 worldpos)
{
}

void HexTerrainEdit::GetHeightMap(CArray2Dd &buffer)
{
}

void HexTerrainEdit::SetHeightBuffer(CArray2Dd &buffer, MaskSettings &masksettings)
{
}
void HexTerrainEdit::SetLayerBuffer(CArray2Dd &buffer, int layer, MaskSettings &masksettings)
{
}
void HexTerrainEdit::SetLayerBufferMax(CArray2Dd &buffer, int layer, MaskSettings &masksettings)
{
}
void HexTerrainEdit::BlendHeightBuffer(CArray2Dd &buffer, CArray2Dd &blend, MaskSettings &masksettings)
{
}

void HexTerrainEdit::SetMaskBuffer(CArray2Dd &buffer, int which)
{
}

void HexTerrainEdit::ApplyHeightBrush(float x, float z, float dt, BrushSettings &brush, MaskSettings &masksettings)
{
}
void HexTerrainEdit::ApplyBlendBrush(float x, float z, int layer, float dt, BrushSettings &brush, MaskSettings &masksettings)
{
}
void HexTerrainEdit::ApplyMaskBrush(float x, float z, int which, float dt, BrushSettings &brush, MaskSettings &masksettings)
{
}
void HexTerrainEdit::ApplySmoothBrush(float x, float z, float dt, BrushSettings &brush, MaskSettings &masksettings)
{
}

void HexTerrainEdit::SetBrushCursorHeight(CustomGeometry *brush, float groundx, float groundz)
{
}

void HexTerrainEdit::InvertMask(int which)
{
}
void HexTerrainEdit::ClearMask(int which)
{
}
void HexTerrainEdit::ClearAllMasks()
{
}

void HexTerrainEdit::InvertLayer(int which)
{
}
void HexTerrainEdit::ClearLayer(int which)
{
}
void HexTerrainEdit::ClearAllLayers()
{
}

void HexTerrainEdit::InvertHeight()
{
}
void HexTerrainEdit::ClearHeight()
{
}

void HexTerrainEdit::SetMaterialSettings(bool triplanar, bool smoothing, bool normalmapping, bool reduce)
{
}

void HexTerrainEdit::SaveHeightMap(const String &filename)
{
}
void HexTerrainEdit::SaveBlend0(const String &filename)
{
}
void HexTerrainEdit::SaveBlend1(const String &filename)
{
}
void HexTerrainEdit::SaveMask(const String &filename)
{
}

void HexTerrainEdit::LoadHeightMap(const String &filename)
{
}
void HexTerrainEdit::LoadBlend0(const String &filename)
{
}
void HexTerrainEdit::LoadBlend1(const String &filename)
{
}
void HexTerrainEdit::LoadMask(const String &filename)
{
}

void HexTerrainEdit::GetSteepness(CArray2Dd &buffer, float threshold, float fade)
{
}
void HexTerrainEdit::GetCavityMap(CArray2Dd &buffer, float sampleradius, float scale, float bias, float intensity, unsigned int iterations)
{
}
	
Vector3 HexTerrainEdit::GetTerrainSpacing()
{
}
void HexTerrainEdit::SaveTerrainNormalMap(const String &filename)
{
}
	
float HexTerrainEdit::DoAmbientOcclusion(Vector2 tcoord, Vector2 uv, Vector3 p, Vector3 cnorm, float scale, float bias, float intensity)
{
}