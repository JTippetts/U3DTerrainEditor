// Load bindings

#ifdef URHO3D_ANGELSCRIPT

#endif

#ifdef URHO3D_LUA
#include <lua.h>
void LoadLuaBindings(lua_State *l);
#endif