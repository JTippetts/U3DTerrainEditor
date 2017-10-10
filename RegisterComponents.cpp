#include <Urho3D/Urho3D.h>
#include "RegisterComponents.h"
#include "NodeGraphLink.h"

void RegisterCustomComponents(Context *context)
{
    NodeGraphLinkPane::RegisterObject(context);
    NodeGraphLink::RegisterObject(context);
    NodeGraphLinkSource::RegisterObject(context);
    NodeGraphLinkDest::RegisterObject(context);
}
