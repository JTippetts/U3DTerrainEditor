#include <Urho3D/Urho3D.h>
#include "RegisterComponents.h"
#include "NodeGraphLink.h"

void RegisterCustomComponents(Context *context)
{
	NodeGraphLink::RegisterObject(context);
}
