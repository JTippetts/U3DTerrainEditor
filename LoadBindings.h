// Load bindings

#ifdef URHO3D_ANGELSCRIPT
#include <angelscript.h>
void LoadScriptBindings(asIScriptEngine* engine);
#endif

#ifdef URHO3D_LUA
#include <lua.h>
void LoadLuaBindings(lua_State *l);
#endif