#pragma once

// Terrain Height Edit UI

#include <Urho3D/Core/Context.h>
#include <Urho3D/Core/Object.h>
#include <Urho3D/UI/UIElement.h>
#include <Urho3D/Resource/Image.h>
#include <Urho3D/Graphics/Texture2D.h>

#include "../terraincontext.h"

class TerrainMaterialBuilder;
class AlphaBrushSelectorUI;
class EditingCamera;
using namespace Urho3D;

class EditMaskUI : public Object
{
	URHO3D_OBJECT(EditMaskUI, Object);
	public:
	EditMaskUI(Context *context);
	
	void Construct(TerrainContext *tc, TerrainMaterialBuilder *tmb, AlphaBrushSelectorUI *abs, EditingCamera *camera);
	void SetVisible(bool v);
	bool IsVisible(){if(element_) return element_->IsVisible(); return false;}
	
	
	protected:
	TerrainContext *terrainContext_;
	TerrainMaterialBuilder *materialBuilder_;
	AlphaBrushSelectorUI *alphaSelector_;
	EditingCamera *camera_;
	SharedPtr<UIElement> element_;
	
	BrushSettings brushSettings_;
	MaskSettings maskSettings_;
	Image brushPreview_;
	SharedPtr<Texture2D> brushPreviewTex_;
	
	void HandleSliderChanged(StringHash eventType, VariantMap &eventData);
	void HandleUpdate(StringHash eventType, VariantMap &eventData);
	void HandleClearMask(StringHash eventType, VariantMap &eventData);
	void GenerateBrushPreview();
	void SetBrushUIFields();
	void GetBrushUIFields();
	void SetBrushMax(float ht);
};
