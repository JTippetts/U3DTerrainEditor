#pragma once

// Alpha Brush Selector
// UI object for selecting an alpha brush from a list.

#include <Urho3D/Core/Context.h>
#include <Urho3D/Core/Object.h>
#include <Urho3D/UI/UIElement.h>
#include <Urho3D/UI/Button.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <vector>

using namespace Urho3D;

class TerrainMaterialBuilder;
class AlphaBrushSelectorUI : public Object
{
	URHO3D_OBJECT(AlphaBrushSelectorUI, Object);
	public:
	struct AlphaEntry
	{
		ea::string name_;
		ea::string path_;
		SharedPtr<UIElement> element_;
		Button *thumb_;
		Texture2D *tex_;
		Image *image_;
	};

	AlphaBrushSelectorUI(Context *context);

	void Construct(TerrainMaterialBuilder *tmb);
	void SetVisible(bool v){if(element_) element_->SetVisible(v);}
	bool IsVisible(){if(element_) return element_->IsVisible(); return false;}
	Image *GetAlphaBrush(){if(!selected_) return nullptr; return selected_->image_;}
	protected:
	TerrainMaterialBuilder *materialBuilder_;
	SharedPtr<UIElement> element_, contentelement_;
	std::vector<AlphaEntry> alphas_;
	AlphaEntry *selected_;

	void PopulateList();
	void SetSelected(AlphaEntry *e);
	void HandleAlphaSelected(StringHash eventType, VariantMap &eventData);
};
