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

#include "ThirdParty/ANL/VM/vm.h"
#include "ThirdParty/ANL/VM/instruction.h"
#include "ThirdParty/ANL/VM/kernel.h"
#include "ThirdParty/ANL/VM/coordinate.h"

using namespace Urho3D;
using namespace anl;
	
	Vector2 WorldToNormalized(Image *height, Terrain *terrain, Vector3 world);
	Vector3 NormalizedToWorld(Image *height, Terrain *terrain, Vector2 normalized);
	
	void SetHeightValue(Image *height, int x, int y, float val);
	float GetHeightValue(Image *height, int x, int y);
	
	void ApplyHeightBrush(Terrain *terrain, Image *height, Image *mask, float x, float z, float radius, float max, float power, float hardness, bool usemask, float dt);
	void ApplyBlendBrush(Terrain *terrain, Image *height, Image *blend, Image *mask, float x, float z, float radius, float mx, float power, float hardness, int layer, bool usemask, float dt);
	void ApplyBlendBrush8(Terrain *terrain, Image *height, Image *blend0, Image *blend1, Image *mask, float x, float z, float radius, float mx, float power, float hardness, int layer, bool usemask, float dt);
	void ApplyMaskBrush(Terrain *terrain, Image *height, Image *mask, float x, float z, float radius, float mx, float power, float hardness, float dt);
	void ApplySmoothBrush(Terrain *terrain, Image *height, Image *mask, float x, float z, float radius, float max, float power, float hardness, bool usemask, float dt);
	
	void SetBrushCursorHeight(Terrain *terrain, CustomGeometry *brush, float groundx, float groundz);
	
	void InvertMask(Image *mask);
	void RenderANLKernelToHeight(Image *height, Image *mask, CKernel *kernel, double lowRange=0, double highRange=1, bool useMask=false, bool invertMask=false);

#endif
