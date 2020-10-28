#include "registercomponents.h"

#include "Components/editingcamera.h"
#include "NodeGraphLink.h"

void RegisterComponents(Context *context)
{
	context->RegisterFactory<EditingCamera>();
	
	NodeGraphLink::RegisterObject(context);
	NodeGraphLinkSource::RegisterObject(context);
	NodeGraphLinkDest::RegisterObject(context);
	NodeGraphLinkPane::RegisterObject(context);
}
