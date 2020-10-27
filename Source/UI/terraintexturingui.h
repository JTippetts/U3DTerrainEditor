#pragma once

// TerrainTexturingUI
// UI for handling terrain texturing

#include <Urho3D/Core/Context.h>
#include <Urho3D/Core/Object.h>
#include <Urho3D/UI/UIElement.h>
#include <Urho3D/Resource/Image.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <Urho3D/UI/FileSelector.h>
#include <vector>

#include "../terraincontext.h"

using namespace Urho3D;

class TerrainMaterialBuilder;
class AlphaBrushSelectorUI;
class EditingCamera;
class TerrainTexturingUI : public Object
{
	URHO3D_OBJECT(TerrainTexturingUI, Object);
	public:
	TerrainTexturingUI(Context *context);
	
	void Construct(TerrainContext *tc, TerrainMaterialBuilder *tmb, AlphaBrushSelectorUI *abs, EditingCamera *camera);
	void SetVisible(bool v);
	bool IsVisible(){if(element_) return element_->IsVisible(); return false;}
	
	protected:
	TerrainContext *terrainContext_;
	TerrainMaterialBuilder *materialBuilder_;
	AlphaBrushSelectorUI *alphaSelector_;
	EditingCamera *camera_;
	SharedPtr<UIElement> element_;
	SharedPtr<UIElement> editLayerElement_;
	
	BrushSettings brushSettings_;
	MaskSettings maskSettings_;
	Image brushPreview_;
	SharedPtr<Texture2D> brushPreviewTex_;
	
	SharedPtr<Texture2D> editLayerDiffTex_;
	SharedPtr<Texture2D> editLayerNormalTex_;
	
	std::vector<float> layerScales_;
	std::vector<String> diffuseLayerNames_;
	std::vector<String> normalLayerNames_;
	std::vector<SharedPtr<Texture2D>> layerThumbnailTex_;
	std::vector<SharedPtr<Image>> diffThumbnailImages_;
	std::vector<SharedPtr<Image>> normalThumbnailImages_;
	
	SharedPtr<FileSelector> fileSelector_;
	unsigned int selectedLayer_;
	unsigned int editingLayer_;
	bool diffuseSelected_, normalSelected_;
	String selectedDiffImageName_, selectedNormalImageName_;
	Image *selectedDiffImage_, *selectedNormalImage_;
	Image selectedDiffImageThumb_, selectedNormalImageThumb_;
	
	void HandleSliderChanged(StringHash eventType, VariantMap &eventData);
	void HandleUpdate(StringHash eventType, VariantMap &eventData);
	void HandleEditLayerApply(StringHash eventType, VariantMap &eventData);
	void HandleEditLayerCancel(StringHash eventType, VariantMap &eventData);
	void HandleMaterialSettingToggled(StringHash eventType, VariantMap &eventData);
	void HandleClearLayer(StringHash eventType, VariantMap &eventData);
	void HandleClearAllLayers(StringHash eventType, VariantMap &eventData);
	void HandleEditLayerButton(StringHash eventType, VariantMap &eventData);
	void HandleTextureButton(StringHash eventType, VariantMap &eventData);
	void HandlePickDiffuse(StringHash eventType, VariantMap &eventData);
	void HandlePickNormal(StringHash eventType, VariantMap &eventData);
	void HandleSelectDiffuseFile(StringHash eventType, VariantMap &eventData);
	void HandleSelectNormalFile(StringHash eventType, VariantMap &eventData);
	
	void GenerateBrushPreview();
	void SetBrushUIFields();
	void GetBrushUIFields();
	void SetBrushMax(float ht);
	
	void GenerateThumbnailImage(Image &out, const Image &in);
	void SelectLayer(unsigned int which);
	void InitializeTextures();
	void SetLayerScales();
	
	SharedPtr<FileSelector> CreateFileSelector(const String &title, const String &oktext, const String &canceltext, const String &initialPath, const Vector<String> &filters, unsigned int initialFilter);
	String GetFilenameFromPath(const String &path);
};