#include "LoadBindings.h"

int  tolua_bind_anl_open (lua_State* tolua_S);

#ifdef URHO3D_ANGELSCRIPT
void LoadScriptBindings(asIScriptEngine* engine)
{
}

#endif

#ifdef URHO3D_LUA
void LoadLuaBindings(lua_State *l)
{
	tolua_bind_anl_open(l);
}
#endif
