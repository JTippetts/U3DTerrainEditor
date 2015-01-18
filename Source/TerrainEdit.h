// Terrain Edit Component

#include <Urho3D/Scene/LogicComponent.h>
#include <Urho3D/Scene/Node.h>
#include <Urho3D/Core/Context.h>
#include <Urho3D/Core/Object.h>
#include <Urho3D/Graphics/Terrain.h>
#include <Urho3D/Resource/Image.h>
#include <Urho3D/Graphics/Texture2D.h>

using namespace Urho3D;

class URHO3D_API TerrainEdit : public LogicComponent
{
	OBJECT(TerrainEdit);
	public:
	TerrainEdit(Context *context);
	~TerrainEdit();
	
	
	
	private:
	
}
