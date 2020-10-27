#pragma once

// TerrainMaterialBuilder

// Class to manage material settings 
#include <Urho3D/Core/Context.h>
#include <Urho3D/Core/Object.h>
#include <Urho3D/UI/UIElement.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <Urho3D/Graphics/Texture2DArray.h>

#include <vector>

using namespace Urho3D;

class TerrainContext;
class TerrainMaterialBuilder : public Object
{
	URHO3D_OBJECT(TerrainMaterialBuilder, Object);
	public:
	TerrainMaterialBuilder(Context *context);
	
	void Construct(TerrainContext *tc);
	void SetTerrainContext(TerrainContext *tc){terraincontext_=tc; dirty_=true;}
	void SetUseTriplanar(bool b){triplanar_=b; dirty_=true;}
	void SetUseSmooth(bool b){smooth_=b; dirty_=true;}
	void SetUseBump(bool b){bump_=b; dirty_=true;}
	void SetUseReduceTiling(bool b){reduce_=b; dirty_=true;}
	void SetDiffuseTexture(unsigned int which, Image &image);
	void SetNormalTexture(unsigned int which, Image &image);
	void SetDiffuseTextureNames(const std::vector<String> &filenames);
	void SetNormalTextureNames(const std::vector<String> &filenames);
	void SetLayerScale(unsigned int which, float scale);
	void SetLayerScales(const std::vector<float> &scales);
	void SetAlphaTexture(Texture2D *alpha){alpha_=alpha; if(material_) material_->SetTexture(TU_VOLUMEMAP, alpha_);}
	void SetEditingCursor(float x, float y, float radius, float hardness, float angle);
	
	protected:
	TerrainContext *terraincontext_;
	
	bool triplanar_, smooth_, bump_, reduce_;
	Texture2D *alpha_;
	Material *material_;
	
	float cursorx_, cursory_, cursorradius_, cursorhardness_, cursorangle_;
	
	std::vector<float> layerScales_;
	SharedPtr<Texture2DArray> diffuseTextures_;
	SharedPtr<Texture2DArray> normalTextures_;
	
	bool dirty_;
	
	void HandleEndFrame(StringHash eventType, VariantMap &eventData); // Rebuild material at end of frame.
};
