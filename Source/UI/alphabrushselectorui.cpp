#include "alphabrushselectorui.h"

#include <Urho3D/UI/UI.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Resource/XMLFile.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/IO/FileSystem.h>
#include <Urho3D/UI/ScrollView.h>
#include <Urho3D/IO/Log.h>
#include <Urho3D/UI/Window.h>

#include "../terrainmaterialbuilder.h"

AlphaBrushSelectorUI::AlphaBrushSelectorUI(Context *context) : Object(context),
	materialBuilder_(nullptr),
	selected_(nullptr)
{
}

void AlphaBrushSelectorUI::Construct(TerrainMaterialBuilder *tmb)
{
	auto ui=GetSubsystem<UI>();
	auto cache=GetSubsystem<ResourceCache>();
	auto graphics=GetSubsystem<Graphics>();

	materialBuilder_=tmb;

	XMLFile *style=cache->GetResource<XMLFile>("UI/DefaultStyle.xml");

	element_=ui->LoadLayout(cache->GetResource<XMLFile>("UI/AlphaList.xml"),style);
	if(!element_) return;
	element_->SetPosition(IntVector2(0, graphics->GetHeight()-element_->GetHeight()));
	//element_->SetVisible(false);
	ui->GetRoot()->GetChild("Base",true)->AddChild(element_);
	contentelement_=ui->LoadLayout(cache->GetResource<XMLFile>("UI/AlphaListElement.xml"),style);
	PopulateList();
	element_->GetChildDynamicCast<ScrollView>("AlphaList", true)->SetContentElement(contentelement_);
}

void AlphaBrushSelectorUI::PopulateList()
{
	auto fileSystem=GetSubsystem<FileSystem>();
	auto cache=GetSubsystem<ResourceCache>();
	auto ui=GetSubsystem<UI>();

	XMLFile *style=cache->GetResource<XMLFile>("UI/DefaultStyle.xml");

	Vector<String> files;
	fileSystem->ScanDir(files, fileSystem->GetProgramDir() + "Data/Alphas", "*.png", SCAN_FILES, false);

	// Insert blank first in list
	Texture2D *thumbtex=cache->GetResource<Texture2D>("Data/Alphas/blank.png");
	SharedPtr<UIElement> elem=ui->LoadLayout(cache->GetResource<XMLFile>("UI/AlphaEntry.xml"),style);
	Button *thumb=elem->GetChildDynamicCast<Button>("Thumb", true);
	thumb->SetTexture(thumbtex);
	thumb->SetImageRect(IntRect(0,0,thumbtex->GetWidth()-1,thumbtex->GetHeight()-1));
	contentelement_->AddChild(elem);
	SubscribeToEvent(thumb, StringHash("Pressed"), URHO3D_HANDLER(AlphaBrushSelectorUI, HandleAlphaSelected));
	alphas_.push_back({"blank.png", "Data/Alphas/blank.png", elem, thumb, thumbtex, cache->GetResource<Image>(String("Data/Alphas/blank.png"))});

	// Insert remaining alphas
	for(int c=0; c<files.Size(); ++c)
	{
		String &file=files[c];
		if(file!="blank.png")
		{
			thumbtex=cache->GetResource<Texture2D>(String("Data/Alphas/")+file);
			elem=ui->LoadLayout(cache->GetResource<XMLFile>("UI/AlphaEntry.xml"),style);
			thumb=elem->GetChildDynamicCast<Button>("Thumb", true);
			thumb->SetTexture(thumbtex);
			thumb->SetImageRect(IntRect(0,0,thumbtex->GetWidth()-1,thumbtex->GetHeight()-1));
			contentelement_->AddChild(elem);
			SubscribeToEvent(thumb, StringHash("Pressed"), URHO3D_HANDLER(AlphaBrushSelectorUI, HandleAlphaSelected));
			alphas_.push_back({file, String("Data/Alphas/")+file, elem, thumb, thumbtex, cache->GetResource<Image>(String("Data/Alphas/")+file)});
		}
	}

	if(alphas_.size()>0)
	{
		SetSelected(&alphas_[0]);
	}
}

void AlphaBrushSelectorUI::SetSelected(AlphaEntry *e)
{
	if(selected_ && selected_->element_)
	{
		DynamicCast<Window>(selected_->element_)->SetImageRect(IntRect(48,0,64,16));
	}
	selected_=e;
	if(e && e->element_)
	{
		DynamicCast<Window>(e->element_)->SetImageRect(IntRect(160,64,176,80));
	}

	if(materialBuilder_ && selected_)
	{
		materialBuilder_->SetAlphaTexture(selected_->tex_);
	}
}

void AlphaBrushSelectorUI::HandleAlphaSelected(StringHash eventType, VariantMap &eventData)
{
	UIElement *elem=static_cast<UIElement *>(eventData["Element"].GetPtr());
	for(unsigned int c=0; c<alphas_.size(); ++c)
	{
		if(elem==alphas_[c].thumb_)
		{
			SetSelected(&alphas_[c]);
		}
	}
}
