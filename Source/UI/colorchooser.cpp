#include "colorchooser.h"

#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Resource/XMLFile.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/UI/Slider.h>
#include <Urho3D/UI/BorderImage.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/UI/Button.h>
#include <Urho3D/Graphics/Graphics.h>

#include <cmath>

Color hsv2rgb(float h, float s, float v)
{
	if(h>=360.0f) h=0;
	else h=h/60.0f;
	
	float fract=h-std::floor(h);
	float p=v*(1.f-s);
	float q=v*(1.f-s*fract);
	float t=v*(1.f-s*(1.f-fract));
	
	if(h>=0 && h<1) return Color(v, t, p);
	else if(h>=1 && h<2) return Color(q,v,p);
	else if(h>=2 && h<3) return Color(p,v,t);
	else if(h>=3 && h<4) return Color(p,q,v);
	else if(h>=4 && h<5) return Color(t,p,v);
	else if(h>=5 && h<6) return Color(v,p,q);
	else return Color(0,0,0);
}

Color rgb2hsv(const Color &col)
{
	float fmax=std::max(std::max(col.r_, col.g_), col.b_);
	float fmin=std::min(std::min(col.r_, col.g_), col.b_);
	float fdelta=fmax-fmin;
	
	float h,s,v;
	if(fdelta>0)
	{
		if(fmax==col.r_) h=60.f*(std::fmod(((col.g_-col.b_) / fdelta), 6.f));
		else if(fmax==col.g_) h=60.f*(((col.b_-col.r_)/fdelta)+2.f);
		else h=60.f*(((col.r_-col.g_)/fdelta)+4.f);
		
		if(fmax>0) s=fdelta/fmax;
		else s=0.0;
		
		v=fmax;
	}
	else
	{
		h=0;
		s=0;
		v=fmax;
	}
	
	if(h<0) h+=360.f;
	return Color(h,s,v);
}

ColorChooser::ColorChooser(Context *context) : Object(context)
{
	auto cache=GetSubsystem<ResourceCache>();
	auto ui=GetSubsystem<UI>();
	
	element_=ui->LoadLayout(cache->GetResource<XMLFile>("UI/ColorChooser.xml"), cache->GetResource<XMLFile>("UI/DefaultStyle.xml"));
	ui->GetRoot()->GetChild("Base", true)->AddChild(element_);
	SetColor(Color(1,1,1));
	SetBrightness(0.5f);
	SetVisible(false);
	
	SubscribeToEvent(StringHash("Update"), URHO3D_HANDLER(ColorChooser, HandleUpdate));
}

Button *ColorChooser::GetCloseButton()
{
	if(element_) return element_->GetChildDynamicCast<Button>("Close", true);
	return nullptr;
}

Color ColorChooser::GetColor()
{
	return color_;
}

float ColorChooser::GetBrightness()
{
	return brightness_;
}

void ColorChooser::SetColor(const Color &col)
{
	Color hsv=rgb2hsv(col);
	float h=hsv.r_;
	float s=hsv.g_;
	float v=hsv.b_;
	element_->GetChildDynamicCast<Slider>("Value", true)->SetValue(std::floor((1.f-v)*127));
	float angle=h/360.0f;
	angle=angle*2.f-1.f;
	angle*=3.14159265f;
	float dx=std::cos(angle);
	float dy=std::sin(angle);
	int newx=std::floor(64.f+dx*s*64.f)-4;
	int newy=std::floor(64.f+dy*s*64.f)-4;
	element_->GetChildDynamicCast<BorderImage>("Cursor", true)->SetPosition(IntVector2(newx,newy));
	color_=col;
	SetBrightness(0.5f);
}

void ColorChooser::SetBrightness(float b)
{
	brightness_=b;
	element_->GetChildDynamicCast<Slider>("Brightness", true)->SetValue((int)(b*255.f));
}

void ColorChooser::SetVisible(bool vis)
{
	element_->SetVisible(vis);
	
	if(vis)
	{
		auto graphics=GetSubsystem<Graphics>();
		element_->SetPosition(IntVector2(graphics->GetWidth()/2-element_->GetWidth()/2, graphics->GetHeight()/2-element_->GetHeight()/2));
	}
}

bool ColorChooser::IsVisible()
{
	return element_->IsVisible();
}

void ColorChooser::CalcColor()
{
	IntVector2 cursorpos=element_->GetChildDynamicCast<BorderImage>("Cursor", true)->GetPosition();
	int cx=cursorpos.x_+4;
	int cy=cursorpos.y_+4;
	
	float dx=((float)cx-64.f)/64.f;
	float dy=((float)cy-64.f)/64.f;
	float len=std::sqrt(dx*dx+dy*dy);
	float angle=std::atan2(dy,dx);
	angle=angle/3.14159265f;
	angle=(angle*0.5f)+0.5f;
	if(len>1.f) len=1.f;
	
	Slider *value=element_->GetChildDynamicCast<Slider>("Value", true);
	float v=1.f-(value->GetValue() / value->GetRange());
	color_ = hsv2rgb(angle*360.f, len, v);
	Slider *brightness=element_->GetChildDynamicCast<Slider>("Brightness", true);
	float bright=1.f-(brightness->GetValue()/brightness->GetRange());
	bright=bright+1.f;
	color_ = color_ * bright;
	element_->GetChildDynamicCast<BorderImage>("Swatch", true)->SetColor(color_);
}

void ColorChooser::HandleUpdate(StringHash eventType, VariantMap &eventData)
{
	if(!element_->IsVisible()) return;
	
	auto input=GetSubsystem<Input>();
	
	if(input->GetMouseButtonDown(MOUSEB_LEFT))
	{
		IntVector2 sp=input->GetMousePosition();
		if(element_->GetChild("ColorWheel", true)->IsInside(sp, true))
		{
			IntVector2 ep=element_->GetChildDynamicCast<BorderImage>("ColorWheel", true)->ScreenToElement(sp);
			float dx=(((float)ep.x_)-64.f);
			float dy=(((float)ep.y_)-64.f);
			float len=std::sqrt(dx*dx+dy*dy);
			dx/=len;
			dy/=len;
			len=std::min(64.f,len);
			int newx=(int)(64 + dx*len);
			int newy=(int)(64 + dy*len);
			element_->GetChild("Cursor", true)->SetPosition(IntVector2(newx-4, newy-4));
		}
	}
	
	CalcColor();
}
