#include "registercomponents.h"

#include "Components/editingcamera.h"

void RegisterComponents(Context *context)
{
	context->RegisterFactory<EditingCamera>();
}
