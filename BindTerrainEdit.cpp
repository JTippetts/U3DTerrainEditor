/*
** Lua binding: BindTerrainEdit
** Generated automatically by tolua++-1.0.93 on 01/23/15 19:00:24.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_BindTerrainEdit_open (lua_State* tolua_S);

#include "TerrainEdit.h"
using namespace Urho3D;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Vector3 (lua_State* tolua_S)
{
 Vector3* self = (Vector3*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Vector2 (lua_State* tolua_S)
{
 Vector2* self = (Vector2*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Terrain");
 tolua_usertype(tolua_S,"Image");
 tolua_usertype(tolua_S,"Vector3");
 tolua_usertype(tolua_S,"Vector2");
}

/* function: WorldToNormalized */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_WorldToNormalized00
static int tolua_BindTerrainEdit_WorldToNormalized00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Terrain",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* height = ((Image*)  tolua_tousertype(tolua_S,1,0));
  Terrain* terrain = ((Terrain*)  tolua_tousertype(tolua_S,2,0));
  Vector3 world = *((Vector3*)  tolua_tousertype(tolua_S,3,0));
  {
   Vector2 tolua_ret = (Vector2)  WorldToNormalized(height,terrain,world);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WorldToNormalized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: NormalizedToWorld */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NormalizedToWorld00
static int tolua_BindTerrainEdit_NormalizedToWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Terrain",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* height = ((Image*)  tolua_tousertype(tolua_S,1,0));
  Terrain* terrain = ((Terrain*)  tolua_tousertype(tolua_S,2,0));
  Vector2 normalized = *((Vector2*)  tolua_tousertype(tolua_S,3,0));
  {
   Vector3 tolua_ret = (Vector3)  NormalizedToWorld(height,terrain,normalized);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'NormalizedToWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: SetHeightValue */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_SetHeightValue00
static int tolua_BindTerrainEdit_SetHeightValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* height = ((Image*)  tolua_tousertype(tolua_S,1,0));
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  float val = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   SetHeightValue(height,x,y,val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHeightValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetHeightValue */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_GetHeightValue00
static int tolua_BindTerrainEdit_GetHeightValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* height = ((Image*)  tolua_tousertype(tolua_S,1,0));
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   float tolua_ret = (float)  GetHeightValue(height,x,y);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHeightValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ApplyHeightBrush */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_ApplyHeightBrush00
static int tolua_BindTerrainEdit_ApplyHeightBrush00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Terrain",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Image",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,10,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,12,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Terrain* terrain = ((Terrain*)  tolua_tousertype(tolua_S,1,0));
  Image* height = ((Image*)  tolua_tousertype(tolua_S,2,0));
  Image* mask = ((Image*)  tolua_tousertype(tolua_S,3,0));
  float x = ((float)  tolua_tonumber(tolua_S,4,0));
  float z = ((float)  tolua_tonumber(tolua_S,5,0));
  float radius = ((float)  tolua_tonumber(tolua_S,6,0));
  float max = ((float)  tolua_tonumber(tolua_S,7,0));
  float power = ((float)  tolua_tonumber(tolua_S,8,0));
  float hardness = ((float)  tolua_tonumber(tolua_S,9,0));
  bool usemask = ((bool)  tolua_toboolean(tolua_S,10,0));
  float dt = ((float)  tolua_tonumber(tolua_S,11,0));
  {
   ApplyHeightBrush(terrain,height,mask,x,z,radius,max,power,hardness,usemask,dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyHeightBrush'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ApplyBlendBrush */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_ApplyBlendBrush00
static int tolua_BindTerrainEdit_ApplyBlendBrush00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Terrain",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"Image",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,12,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,13,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,14,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Terrain* terrain = ((Terrain*)  tolua_tousertype(tolua_S,1,0));
  Image* height = ((Image*)  tolua_tousertype(tolua_S,2,0));
  Image* blend = ((Image*)  tolua_tousertype(tolua_S,3,0));
  Image* mask = ((Image*)  tolua_tousertype(tolua_S,4,0));
  float x = ((float)  tolua_tonumber(tolua_S,5,0));
  float z = ((float)  tolua_tonumber(tolua_S,6,0));
  float radius = ((float)  tolua_tonumber(tolua_S,7,0));
  float mx = ((float)  tolua_tonumber(tolua_S,8,0));
  float power = ((float)  tolua_tonumber(tolua_S,9,0));
  float hardness = ((float)  tolua_tonumber(tolua_S,10,0));
  int layer = ((int)  tolua_tonumber(tolua_S,11,0));
  bool usemask = ((bool)  tolua_toboolean(tolua_S,12,0));
  float dt = ((float)  tolua_tonumber(tolua_S,13,0));
  {
   ApplyBlendBrush(terrain,height,blend,mask,x,z,radius,mx,power,hardness,layer,usemask,dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyBlendBrush'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ApplyMaskBrush */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_ApplyMaskBrush00
static int tolua_BindTerrainEdit_ApplyMaskBrush00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Terrain",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Image",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,11,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Terrain* terrain = ((Terrain*)  tolua_tousertype(tolua_S,1,0));
  Image* height = ((Image*)  tolua_tousertype(tolua_S,2,0));
  Image* mask = ((Image*)  tolua_tousertype(tolua_S,3,0));
  float x = ((float)  tolua_tonumber(tolua_S,4,0));
  float z = ((float)  tolua_tonumber(tolua_S,5,0));
  float radius = ((float)  tolua_tonumber(tolua_S,6,0));
  float mx = ((float)  tolua_tonumber(tolua_S,7,0));
  float power = ((float)  tolua_tonumber(tolua_S,8,0));
  float hardness = ((float)  tolua_tonumber(tolua_S,9,0));
  float dt = ((float)  tolua_tonumber(tolua_S,10,0));
  {
   ApplyMaskBrush(terrain,height,mask,x,z,radius,mx,power,hardness,dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyMaskBrush'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ApplySmoothBrush */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_ApplySmoothBrush00
static int tolua_BindTerrainEdit_ApplySmoothBrush00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Terrain",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Image",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,10,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,12,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Terrain* terrain = ((Terrain*)  tolua_tousertype(tolua_S,1,0));
  Image* height = ((Image*)  tolua_tousertype(tolua_S,2,0));
  Image* mask = ((Image*)  tolua_tousertype(tolua_S,3,0));
  float x = ((float)  tolua_tonumber(tolua_S,4,0));
  float z = ((float)  tolua_tonumber(tolua_S,5,0));
  float radius = ((float)  tolua_tonumber(tolua_S,6,0));
  float max = ((float)  tolua_tonumber(tolua_S,7,0));
  float power = ((float)  tolua_tonumber(tolua_S,8,0));
  float hardness = ((float)  tolua_tonumber(tolua_S,9,0));
  bool usemask = ((bool)  tolua_toboolean(tolua_S,10,0));
  float dt = ((float)  tolua_tonumber(tolua_S,11,0));
  {
   ApplySmoothBrush(terrain,height,mask,x,z,radius,max,power,hardness,usemask,dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplySmoothBrush'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: InvertMask */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_InvertMask00
static int tolua_BindTerrainEdit_InvertMask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* mask = ((Image*)  tolua_tousertype(tolua_S,1,0));
  {
   InvertMask(mask);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InvertMask'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_BindTerrainEdit_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_function(tolua_S,"WorldToNormalized",tolua_BindTerrainEdit_WorldToNormalized00);
  tolua_function(tolua_S,"NormalizedToWorld",tolua_BindTerrainEdit_NormalizedToWorld00);
  tolua_function(tolua_S,"SetHeightValue",tolua_BindTerrainEdit_SetHeightValue00);
  tolua_function(tolua_S,"GetHeightValue",tolua_BindTerrainEdit_GetHeightValue00);
  tolua_function(tolua_S,"ApplyHeightBrush",tolua_BindTerrainEdit_ApplyHeightBrush00);
  tolua_function(tolua_S,"ApplyBlendBrush",tolua_BindTerrainEdit_ApplyBlendBrush00);
  tolua_function(tolua_S,"ApplyMaskBrush",tolua_BindTerrainEdit_ApplyMaskBrush00);
  tolua_function(tolua_S,"ApplySmoothBrush",tolua_BindTerrainEdit_ApplySmoothBrush00);
  tolua_function(tolua_S,"InvertMask",tolua_BindTerrainEdit_InvertMask00);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_BindTerrainEdit (lua_State* tolua_S) {
 return tolua_BindTerrainEdit_open(tolua_S);
};
#endif

