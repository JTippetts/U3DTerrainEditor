#pragma once

// Color Chooser UI

#include <Urho3D/Core/Context.h>
#include <Urho3D/Core/Object.h>
#include <Urho3D/UI/UIElement.h>
#include <Urho3D/UI/Button.h>


using namespace Urho3D;

class ColorChooser : public Object
{
	URHO3D_OBJECT(ColorChooser, Object);
	public:
	ColorChooser(Context *context);
	
	Color GetColor();
	float GetBrightness();
	void SetColor(const Color &col);
	void SetBrightness(float b);
	
	void SetVisible(bool vis);
	bool IsVisible();
	
	Button *GetCloseButton();
	
	protected:
	SharedPtr<UIElement> element_;
	Color color_;
	float brightness_;
	
	void CalcColor();
	void HandleUpdate(StringHash eventType, VariantMap &eventData);
};
