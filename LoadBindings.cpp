#include "LoadBindings.h"

#ifdef URHO3D_ANGELSCRIPT
namespace anl
{
void RegisterANL(asIScriptEngine *as);
};

void LoadScriptBindings(asIScriptEngine* engine)
{
	anl::RegisterANL(engine);
}

#endif

#ifdef URHO3D_LUA

int  tolua_bind_anl_open (lua_State* tolua_S);
int  tolua_BindTerrainEdit_open (lua_State* tolua_S);

void LoadLuaBindings(lua_State *l)
{
	tolua_bind_anl_open(l);
	tolua_BindTerrainEdit_open(l);
}
#endif
