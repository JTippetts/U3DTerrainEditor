/*
** Lua binding: BindTerrainEdit
** Generated automatically by tolua++-1.0.93 on 02/11/15 23:02:45.
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
using namespace anl;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_RasterVertexList (lua_State* tolua_S)
{
 RasterVertexList* self = (RasterVertexList*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_RasterVertex (lua_State* tolua_S)
{
 RasterVertex* self = (RasterVertex*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Vector2 (lua_State* tolua_S)
{
 Vector2* self = (Vector2*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_RasterBuffer (lua_State* tolua_S)
{
 RasterBuffer* self = (RasterBuffer*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Vector3 (lua_State* tolua_S)
{
 Vector3* self = (Vector3*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"RasterVertexList");
 tolua_usertype(tolua_S,"RasterVertex");
 tolua_usertype(tolua_S,"CustomGeometry");
 tolua_usertype(tolua_S,"Color");
 tolua_usertype(tolua_S,"Image");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"RasterBuffer");
 tolua_usertype(tolua_S,"CKernel");
 tolua_usertype(tolua_S,"Terrain");
 tolua_usertype(tolua_S,"Vector3");
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

/* function: ApplyBlendBrush8 */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_ApplyBlendBrush800
static int tolua_BindTerrainEdit_ApplyBlendBrush800(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Terrain",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"Image",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,12,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,13,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,14,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,15,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Terrain* terrain = ((Terrain*)  tolua_tousertype(tolua_S,1,0));
  Image* height = ((Image*)  tolua_tousertype(tolua_S,2,0));
  Image* blend0 = ((Image*)  tolua_tousertype(tolua_S,3,0));
  Image* blend1 = ((Image*)  tolua_tousertype(tolua_S,4,0));
  Image* mask = ((Image*)  tolua_tousertype(tolua_S,5,0));
  float x = ((float)  tolua_tonumber(tolua_S,6,0));
  float z = ((float)  tolua_tonumber(tolua_S,7,0));
  float radius = ((float)  tolua_tonumber(tolua_S,8,0));
  float mx = ((float)  tolua_tonumber(tolua_S,9,0));
  float power = ((float)  tolua_tonumber(tolua_S,10,0));
  float hardness = ((float)  tolua_tonumber(tolua_S,11,0));
  int layer = ((int)  tolua_tonumber(tolua_S,12,0));
  bool usemask = ((bool)  tolua_toboolean(tolua_S,13,0));
  float dt = ((float)  tolua_tonumber(tolua_S,14,0));
  {
   ApplyBlendBrush8(terrain,height,blend0,blend1,mask,x,z,radius,mx,power,hardness,layer,usemask,dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyBlendBrush8'.",&tolua_err);
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

/* function: ApplySpeckleBrush */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_ApplySpeckleBrush00
static int tolua_BindTerrainEdit_ApplySpeckleBrush00(lua_State* tolua_S)
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
     (tolua_isvaluenil(tolua_S,11,&tolua_err) || !tolua_isusertype(tolua_S,11,"Color",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,12,&tolua_err) || !tolua_isusertype(tolua_S,12,"Color",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,13,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,14,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,15,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Terrain* terrain = ((Terrain*)  tolua_tousertype(tolua_S,1,0));
  Image* height = ((Image*)  tolua_tousertype(tolua_S,2,0));
  Image* color = ((Image*)  tolua_tousertype(tolua_S,3,0));
  Image* mask = ((Image*)  tolua_tousertype(tolua_S,4,0));
  float x = ((float)  tolua_tonumber(tolua_S,5,0));
  float z = ((float)  tolua_tonumber(tolua_S,6,0));
  float radius = ((float)  tolua_tonumber(tolua_S,7,0));
  float mx = ((float)  tolua_tonumber(tolua_S,8,0));
  float power = ((float)  tolua_tonumber(tolua_S,9,0));
  float hardness = ((float)  tolua_tonumber(tolua_S,10,0));
  Color c1 = *((Color*)  tolua_tousertype(tolua_S,11,0));
  Color c2 = *((Color*)  tolua_tousertype(tolua_S,12,0));
  bool usemask = ((bool)  tolua_toboolean(tolua_S,13,0));
  float dt = ((float)  tolua_tonumber(tolua_S,14,0));
  {
   ApplySpeckleBrush(terrain,height,color,mask,x,z,radius,mx,power,hardness,c1,c2,usemask,dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplySpeckleBrush'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: SetBrushCursorHeight */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_SetBrushCursorHeight00
static int tolua_BindTerrainEdit_SetBrushCursorHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Terrain",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CustomGeometry",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Terrain* terrain = ((Terrain*)  tolua_tousertype(tolua_S,1,0));
  CustomGeometry* brush = ((CustomGeometry*)  tolua_tousertype(tolua_S,2,0));
  float groundx = ((float)  tolua_tonumber(tolua_S,3,0));
  float groundz = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   SetBrushCursorHeight(terrain,brush,groundx,groundz);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBrushCursorHeight'.",&tolua_err);
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

/* function: RenderANLKernelToHeight */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RenderANLKernelToHeight00
static int tolua_BindTerrainEdit_RenderANLKernelToHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CKernel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* height = ((Image*)  tolua_tousertype(tolua_S,1,0));
  Image* mask = ((Image*)  tolua_tousertype(tolua_S,2,0));
  CKernel* kernel = ((CKernel*)  tolua_tousertype(tolua_S,3,0));
  double lowRange = ((double)  tolua_tonumber(tolua_S,4,0));
  double highRange = ((double)  tolua_tonumber(tolua_S,5,1));
  bool useMask = ((bool)  tolua_toboolean(tolua_S,6,false));
  bool invertMask = ((bool)  tolua_toboolean(tolua_S,7,false));
  {
   RenderANLKernelToHeight(height,mask,kernel,lowRange,highRange,useMask,invertMask);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RenderANLKernelToHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x_ of class  RasterVertex */
#ifndef TOLUA_DISABLE_tolua_get_RasterVertex_x_
static int tolua_get_RasterVertex_x_(lua_State* tolua_S)
{
  RasterVertex* self = (RasterVertex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x_'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x_ of class  RasterVertex */
#ifndef TOLUA_DISABLE_tolua_set_RasterVertex_x_
static int tolua_set_RasterVertex_x_(lua_State* tolua_S)
{
  RasterVertex* self = (RasterVertex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x_'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y_ of class  RasterVertex */
#ifndef TOLUA_DISABLE_tolua_get_RasterVertex_y_
static int tolua_get_RasterVertex_y_(lua_State* tolua_S)
{
  RasterVertex* self = (RasterVertex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y_'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y_ of class  RasterVertex */
#ifndef TOLUA_DISABLE_tolua_set_RasterVertex_y_
static int tolua_set_RasterVertex_y_(lua_State* tolua_S)
{
  RasterVertex* self = (RasterVertex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y_'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: val_ of class  RasterVertex */
#ifndef TOLUA_DISABLE_tolua_get_RasterVertex_val_
static int tolua_get_RasterVertex_val_(lua_State* tolua_S)
{
  RasterVertex* self = (RasterVertex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'val_'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->val_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: val_ of class  RasterVertex */
#ifndef TOLUA_DISABLE_tolua_set_RasterVertex_val_
static int tolua_set_RasterVertex_val_(lua_State* tolua_S)
{
  RasterVertex* self = (RasterVertex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'val_'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->val_ = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  RasterVertex */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertex_new00
static int tolua_BindTerrainEdit_RasterVertex_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RasterVertex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   RasterVertex* tolua_ret = (RasterVertex*)  Mtolua_new((RasterVertex)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RasterVertex");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  RasterVertex */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertex_new00_local
static int tolua_BindTerrainEdit_RasterVertex_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RasterVertex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   RasterVertex* tolua_ret = (RasterVertex*)  Mtolua_new((RasterVertex)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RasterVertex");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  RasterVertex */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertex_new01
static int tolua_BindTerrainEdit_RasterVertex_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RasterVertex",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float val = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   RasterVertex* tolua_ret = (RasterVertex*)  Mtolua_new((RasterVertex)(x,y,val));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RasterVertex");
  }
 }
 return 1;
tolua_lerror:
 return tolua_BindTerrainEdit_RasterVertex_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  RasterVertex */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertex_new01_local
static int tolua_BindTerrainEdit_RasterVertex_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RasterVertex",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float val = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   RasterVertex* tolua_ret = (RasterVertex*)  Mtolua_new((RasterVertex)(x,y,val));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RasterVertex");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_BindTerrainEdit_RasterVertex_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  RasterVertex */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertex_new02
static int tolua_BindTerrainEdit_RasterVertex_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RasterVertex",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const RasterVertex",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const RasterVertex* rhs = ((const RasterVertex*)  tolua_tousertype(tolua_S,2,0));
  {
   RasterVertex* tolua_ret = (RasterVertex*)  Mtolua_new((RasterVertex)(*rhs));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RasterVertex");
  }
 }
 return 1;
tolua_lerror:
 return tolua_BindTerrainEdit_RasterVertex_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  RasterVertex */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertex_new02_local
static int tolua_BindTerrainEdit_RasterVertex_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RasterVertex",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const RasterVertex",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const RasterVertex* rhs = ((const RasterVertex*)  tolua_tousertype(tolua_S,2,0));
  {
   RasterVertex* tolua_ret = (RasterVertex*)  Mtolua_new((RasterVertex)(*rhs));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RasterVertex");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_BindTerrainEdit_RasterVertex_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  RasterVertex */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertex_delete00
static int tolua_BindTerrainEdit_RasterVertex_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterVertex",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterVertex* self = (RasterVertex*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_new00
static int tolua_BindTerrainEdit_RasterVertexList_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   RasterVertexList* tolua_ret = (RasterVertexList*)  Mtolua_new((RasterVertexList)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RasterVertexList");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_new00_local
static int tolua_BindTerrainEdit_RasterVertexList_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   RasterVertexList* tolua_ret = (RasterVertexList*)  Mtolua_new((RasterVertexList)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RasterVertexList");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_new01
static int tolua_BindTerrainEdit_RasterVertexList_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"RasterVertex",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int size = ((int)  tolua_tonumber(tolua_S,2,0));
  RasterVertex value = *((RasterVertex*)  tolua_tousertype(tolua_S,3,0));
  {
   RasterVertexList* tolua_ret = (RasterVertexList*)  Mtolua_new((RasterVertexList)(size,value));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RasterVertexList");
  }
 }
 return 1;
tolua_lerror:
 return tolua_BindTerrainEdit_RasterVertexList_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_new01_local
static int tolua_BindTerrainEdit_RasterVertexList_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"RasterVertex",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int size = ((int)  tolua_tonumber(tolua_S,2,0));
  RasterVertex value = *((RasterVertex*)  tolua_tousertype(tolua_S,3,0));
  {
   RasterVertexList* tolua_ret = (RasterVertexList*)  Mtolua_new((RasterVertexList)(size,value));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RasterVertexList");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_BindTerrainEdit_RasterVertexList_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_new02
static int tolua_BindTerrainEdit_RasterVertexList_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int size = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   RasterVertexList* tolua_ret = (RasterVertexList*)  Mtolua_new((RasterVertexList)(size));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RasterVertexList");
  }
 }
 return 1;
tolua_lerror:
 return tolua_BindTerrainEdit_RasterVertexList_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_new02_local
static int tolua_BindTerrainEdit_RasterVertexList_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int size = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   RasterVertexList* tolua_ret = (RasterVertexList*)  Mtolua_new((RasterVertexList)(size));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RasterVertexList");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_BindTerrainEdit_RasterVertexList_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_new03
static int tolua_BindTerrainEdit_RasterVertexList_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const RasterVertexList",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const RasterVertexList* a = ((const RasterVertexList*)  tolua_tousertype(tolua_S,2,0));
  {
   RasterVertexList* tolua_ret = (RasterVertexList*)  Mtolua_new((RasterVertexList)(*a));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RasterVertexList");
  }
 }
 return 1;
tolua_lerror:
 return tolua_BindTerrainEdit_RasterVertexList_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_new03_local
static int tolua_BindTerrainEdit_RasterVertexList_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const RasterVertexList",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const RasterVertexList* a = ((const RasterVertexList*)  tolua_tousertype(tolua_S,2,0));
  {
   RasterVertexList* tolua_ret = (RasterVertexList*)  Mtolua_new((RasterVertexList)(*a));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RasterVertexList");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_BindTerrainEdit_RasterVertexList_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_delete00
static int tolua_BindTerrainEdit_RasterVertexList_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterVertexList* self = (RasterVertexList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: size of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_size00
static int tolua_BindTerrainEdit_RasterVertexList_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterVertexList* self = (RasterVertexList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'size'", NULL);
#endif
  {
   int tolua_ret = (int)  self->size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: capacity of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_capacity00
static int tolua_BindTerrainEdit_RasterVertexList_capacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterVertexList* self = (RasterVertexList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'capacity'", NULL);
#endif
  {
   int tolua_ret = (int)  self->capacity();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'capacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: bytes of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_bytes00
static int tolua_BindTerrainEdit_RasterVertexList_bytes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterVertexList* self = (RasterVertexList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'bytes'", NULL);
#endif
  {
   int tolua_ret = (int)  self->bytes();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bytes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fill of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_fill00
static int tolua_BindTerrainEdit_RasterVertexList_fill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"RasterVertex",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterVertexList* self = (RasterVertexList*)  tolua_tousertype(tolua_S,1,0);
  RasterVertex val = *((RasterVertex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fill'", NULL);
#endif
  {
   self->fill(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: swap of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_swap00
static int tolua_BindTerrainEdit_RasterVertexList_swap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"RasterVertexList",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterVertexList* self = (RasterVertexList*)  tolua_tousertype(tolua_S,1,0);
  RasterVertexList* a = ((RasterVertexList*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'swap'", NULL);
#endif
  {
   self->swap(*a);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'swap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: at of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_at00
static int tolua_BindTerrainEdit_RasterVertexList_at00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterVertexList* self = (RasterVertexList*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'at'", NULL);
#endif
  {
   RasterVertex& tolua_ret = (RasterVertex&)  self->at(i);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"RasterVertex");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'at'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resize of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_resize00
static int tolua_BindTerrainEdit_RasterVertexList_resize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterVertexList* self = (RasterVertexList*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resize'", NULL);
#endif
  {
   self->resize(width);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reserve of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_reserve00
static int tolua_BindTerrainEdit_RasterVertexList_reserve00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterVertexList* self = (RasterVertexList*)  tolua_tousertype(tolua_S,1,0);
  int cap = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reserve'", NULL);
#endif
  {
   self->reserve(cap);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reserve'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: empty of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_empty00
static int tolua_BindTerrainEdit_RasterVertexList_empty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterVertexList* self = (RasterVertexList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'empty'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->empty();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'empty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: push_back of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_push_back00
static int tolua_BindTerrainEdit_RasterVertexList_push_back00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const RasterVertex",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterVertexList* self = (RasterVertexList*)  tolua_tousertype(tolua_S,1,0);
  const RasterVertex* value = ((const RasterVertex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'push_back'", NULL);
#endif
  {
   self->push_back(*value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'push_back'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: front of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_front00
static int tolua_BindTerrainEdit_RasterVertexList_front00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const RasterVertexList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const RasterVertexList* self = (const RasterVertexList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'front'", NULL);
#endif
  {
   const RasterVertex& tolua_ret = (const RasterVertex&)  self->front();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const RasterVertex");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'front'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: back of class  RasterVertexList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterVertexList_back00
static int tolua_BindTerrainEdit_RasterVertexList_back00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const RasterVertexList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const RasterVertexList* self = (const RasterVertexList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'back'", NULL);
#endif
  {
   const RasterVertex& tolua_ret = (const RasterVertex&)  self->back();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const RasterVertex");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'back'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_new00
static int tolua_BindTerrainEdit_RasterBuffer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int w = ((int)  tolua_tonumber(tolua_S,2,0));
  int h = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   RasterBuffer* tolua_ret = (RasterBuffer*)  Mtolua_new((RasterBuffer)(w,h));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RasterBuffer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_new00_local
static int tolua_BindTerrainEdit_RasterBuffer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int w = ((int)  tolua_tonumber(tolua_S,2,0));
  int h = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   RasterBuffer* tolua_ret = (RasterBuffer*)  Mtolua_new((RasterBuffer)(w,h));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RasterBuffer");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_new01
static int tolua_BindTerrainEdit_RasterBuffer_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   RasterBuffer* tolua_ret = (RasterBuffer*)  Mtolua_new((RasterBuffer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RasterBuffer");
  }
 }
 return 1;
tolua_lerror:
 return tolua_BindTerrainEdit_RasterBuffer_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_new01_local
static int tolua_BindTerrainEdit_RasterBuffer_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   RasterBuffer* tolua_ret = (RasterBuffer*)  Mtolua_new((RasterBuffer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RasterBuffer");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_BindTerrainEdit_RasterBuffer_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_delete00
static int tolua_BindTerrainEdit_RasterBuffer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resize of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_resize00
static int tolua_BindTerrainEdit_RasterBuffer_resize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  int w = ((int)  tolua_tonumber(tolua_S,2,0));
  int h = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resize'", NULL);
#endif
  {
   self->resize(w,h);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroy of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_destroy00
static int tolua_BindTerrainEdit_RasterBuffer_destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroy'", NULL);
#endif
  {
   self->destroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: width of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_width00
static int tolua_BindTerrainEdit_RasterBuffer_width00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'width'", NULL);
#endif
  {
   int tolua_ret = (int)  self->width();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'width'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: height of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_height00
static int tolua_BindTerrainEdit_RasterBuffer_height00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'height'", NULL);
#endif
  {
   int tolua_ret = (int)  self->height();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'height'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_set00
static int tolua_BindTerrainEdit_RasterBuffer_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  float v = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(x,y,v);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_get00
static int tolua_BindTerrainEdit_RasterBuffer_get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'", NULL);
#endif
  {
   float tolua_ret = (float)  self->get(x,y);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRef of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_getRef00
static int tolua_BindTerrainEdit_RasterBuffer_getRef00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRef'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getRef(x,y);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRef'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBilinear of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_getBilinear00
static int tolua_BindTerrainEdit_RasterBuffer_getBilinear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBilinear'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getBilinear(x,y);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBilinear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getIndexed of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_getIndexed00
static int tolua_BindTerrainEdit_RasterBuffer_getIndexed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  int c = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIndexed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getIndexed(c);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIndexed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setIndexed of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_setIndexed00
static int tolua_BindTerrainEdit_RasterBuffer_setIndexed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  int c = ((int)  tolua_tonumber(tolua_S,2,0));
  float v = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIndexed'", NULL);
#endif
  {
   self->setIndexed(c,v);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIndexed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fill of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_fill00
static int tolua_BindTerrainEdit_RasterBuffer_fill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  float v = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fill'", NULL);
#endif
  {
   self->fill(v);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copyFrom of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_copyFrom00
static int tolua_BindTerrainEdit_RasterBuffer_copyFrom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  RasterBuffer* b = ((RasterBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copyFrom'", NULL);
#endif
  {
   self->copyFrom(b);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copyFrom'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copyFromSub of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_copyFromSub00
static int tolua_BindTerrainEdit_RasterBuffer_copyFromSub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  RasterBuffer* b = ((RasterBuffer*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copyFromSub'", NULL);
#endif
  {
   self->copyFromSub(b,x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copyFromSub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addArray of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_addArray00
static int tolua_BindTerrainEdit_RasterBuffer_addArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  RasterBuffer* b = ((RasterBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addArray'", NULL);
#endif
  {
   self->addArray(b);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addArraySub of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_addArraySub00
static int tolua_BindTerrainEdit_RasterBuffer_addArraySub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  RasterBuffer* b = ((RasterBuffer*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addArraySub'", NULL);
#endif
  {
   self->addArraySub(b,x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addArraySub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: subtractArray of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_subtractArray00
static int tolua_BindTerrainEdit_RasterBuffer_subtractArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  RasterBuffer* b = ((RasterBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'subtractArray'", NULL);
#endif
  {
   self->subtractArray(b);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'subtractArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: subtractArraySub of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_subtractArraySub00
static int tolua_BindTerrainEdit_RasterBuffer_subtractArraySub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  RasterBuffer* b = ((RasterBuffer*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'subtractArraySub'", NULL);
#endif
  {
   self->subtractArraySub(b,x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'subtractArraySub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: multiplyArray of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_multiplyArray00
static int tolua_BindTerrainEdit_RasterBuffer_multiplyArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  RasterBuffer* b = ((RasterBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'multiplyArray'", NULL);
#endif
  {
   self->multiplyArray(b);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'multiplyArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: multiplyArraySub of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_multiplyArraySub00
static int tolua_BindTerrainEdit_RasterBuffer_multiplyArraySub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  RasterBuffer* b = ((RasterBuffer*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'multiplyArraySub'", NULL);
#endif
  {
   self->multiplyArraySub(b,x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'multiplyArraySub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_scale00
static int tolua_BindTerrainEdit_RasterBuffer_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: blendFromArrays of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_blendFromArrays00
static int tolua_BindTerrainEdit_RasterBuffer_blendFromArrays00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  RasterBuffer* b1 = ((RasterBuffer*)  tolua_tousertype(tolua_S,2,0));
  RasterBuffer* b2 = ((RasterBuffer*)  tolua_tousertype(tolua_S,3,0));
  RasterBuffer* b3 = ((RasterBuffer*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'blendFromArrays'", NULL);
#endif
  {
   self->blendFromArrays(b1,b2,b3);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'blendFromArrays'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: selectFromArrays of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_selectFromArrays00
static int tolua_BindTerrainEdit_RasterBuffer_selectFromArrays00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  RasterBuffer* b1 = ((RasterBuffer*)  tolua_tousertype(tolua_S,2,0));
  RasterBuffer* b2 = ((RasterBuffer*)  tolua_tousertype(tolua_S,3,0));
  RasterBuffer* b3 = ((RasterBuffer*)  tolua_tousertype(tolua_S,4,0));
  float threshold = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'selectFromArrays'", NULL);
#endif
  {
   self->selectFromArrays(b1,b2,b3,threshold);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'selectFromArrays'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMax of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_getMax00
static int tolua_BindTerrainEdit_RasterBuffer_getMax00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMax'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getMax();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMax'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMin of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_getMin00
static int tolua_BindTerrainEdit_RasterBuffer_getMin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMin'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getMin();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scaleToRange of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_scaleToRange00
static int tolua_BindTerrainEdit_RasterBuffer_scaleToRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  float low = ((float)  tolua_tonumber(tolua_S,2,0));
  float high = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleToRange'", NULL);
#endif
  {
   self->scaleToRange(low,high);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scaleToRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wrapCoords of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_wrapCoords00
static int tolua_BindTerrainEdit_RasterBuffer_wrapCoords00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wrapCoords'", NULL);
#endif
  {
   self->wrapCoords(x,y);
   tolua_pushnumber(tolua_S,(lua_Number)x);
   tolua_pushnumber(tolua_S,(lua_Number)y);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'wrapCoords'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: offset of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_offset00
static int tolua_BindTerrainEdit_RasterBuffer_offset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  int ox = ((int)  tolua_tonumber(tolua_S,2,0));
  int oy = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'offset'", NULL);
#endif
  {
   self->offset(ox,oy);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'offset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: flipVertical of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_flipVertical00
static int tolua_BindTerrainEdit_RasterBuffer_flipVertical00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'flipVertical'", NULL);
#endif
  {
   self->flipVertical();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'flipVertical'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: flipHorizontal of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_flipHorizontal00
static int tolua_BindTerrainEdit_RasterBuffer_flipHorizontal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'flipHorizontal'", NULL);
#endif
  {
   self->flipHorizontal();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'flipHorizontal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scaleTo of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_scaleTo00
static int tolua_BindTerrainEdit_RasterBuffer_scaleTo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  RasterBuffer* dst = ((RasterBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleTo'", NULL);
#endif
  {
   self->scaleTo(dst);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scaleTo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: blur of class  RasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterBuffer_blur00
static int tolua_BindTerrainEdit_RasterBuffer_blur00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* self = (RasterBuffer*)  tolua_tousertype(tolua_S,1,0);
  float blur_size = ((float)  tolua_tonumber(tolua_S,2,0));
  bool seamless = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'blur'", NULL);
#endif
  {
   self->blur(blur_size,seamless);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'blur'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: RasterizeTriangle */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterizeTriangle00
static int tolua_BindTerrainEdit_RasterizeTriangle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"RasterVertex",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"RasterVertex",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"RasterVertex",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* buffer = ((RasterBuffer*)  tolua_tousertype(tolua_S,1,0));
  RasterVertex v1 = *((RasterVertex*)  tolua_tousertype(tolua_S,2,0));
  RasterVertex v2 = *((RasterVertex*)  tolua_tousertype(tolua_S,3,0));
  RasterVertex v3 = *((RasterVertex*)  tolua_tousertype(tolua_S,4,0));
  {
   RasterizeTriangle(buffer,v1,v2,v3);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RasterizeTriangle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: RasterizeQuadStrip */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterizeQuadStrip00
static int tolua_BindTerrainEdit_RasterizeQuadStrip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RasterVertexList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* buffer = ((RasterBuffer*)  tolua_tousertype(tolua_S,1,0));
  RasterVertexList* strip = ((RasterVertexList*)  tolua_tousertype(tolua_S,2,0));
  {
   RasterizeQuadStrip(buffer,strip);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RasterizeQuadStrip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: BlendHeightWithRasterizedBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_BlendHeightWithRasterizedBuffer00
static int tolua_BindTerrainEdit_BlendHeightWithRasterizedBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"Image",1,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* height = ((Image*)  tolua_tousertype(tolua_S,1,0));
  RasterBuffer* buffer = ((RasterBuffer*)  tolua_tousertype(tolua_S,2,0));
  RasterBuffer* blend = ((RasterBuffer*)  tolua_tousertype(tolua_S,3,0));
  Image* mask = ((Image*)  tolua_tousertype(tolua_S,4,0));
  bool useMask = ((bool)  tolua_toboolean(tolua_S,5,false));
  bool invertMask = ((bool)  tolua_toboolean(tolua_S,6,false));
  {
   BlendHeightWithRasterizedBuffer(height,buffer,blend,mask,useMask,invertMask);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BlendHeightWithRasterizedBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: BlendColorWithRasterizedBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_BlendColorWithRasterizedBuffer00
static int tolua_BindTerrainEdit_BlendColorWithRasterizedBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RasterBuffer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Color",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,4,"Image",1,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* img = ((Image*)  tolua_tousertype(tolua_S,1,0));
  RasterBuffer* buffer = ((RasterBuffer*)  tolua_tousertype(tolua_S,2,0));
  Color endColor = *((Color*)  tolua_tousertype(tolua_S,3,0));
  Image* mask = ((Image*)  tolua_tousertype(tolua_S,4,0));
  bool useMask = ((bool)  tolua_toboolean(tolua_S,5,false));
  bool invertMask = ((bool)  tolua_toboolean(tolua_S,6,false));
  {
   BlendColorWithRasterizedBuffer(img,buffer,endColor,mask,useMask,invertMask);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BlendColorWithRasterizedBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: TessellateLineList */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TessellateLineList00
static int tolua_BindTerrainEdit_TessellateLineList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RasterVertexList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterVertexList* in = ((RasterVertexList*)  tolua_tousertype(tolua_S,1,0));
  RasterVertexList* out = ((RasterVertexList*)  tolua_tousertype(tolua_S,2,0));
  int steps = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   TessellateLineList(in,out,steps);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TessellateLineList'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ApplyBedFunction */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_ApplyBedFunction00
static int tolua_BindTerrainEdit_ApplyBedFunction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* buffer = ((RasterBuffer*)  tolua_tousertype(tolua_S,1,0));
  float hardness = ((float)  tolua_tonumber(tolua_S,2,0));
  bool quintic = ((bool)  tolua_toboolean(tolua_S,3,0));
  {
   ApplyBedFunction(buffer,hardness,quintic);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplyBedFunction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: BuildQuadStrip */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_BuildQuadStrip00
static int tolua_BindTerrainEdit_BuildQuadStrip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RasterVertexList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterVertexList* in = ((RasterVertexList*)  tolua_tousertype(tolua_S,1,0));
  RasterVertexList* out = ((RasterVertexList*)  tolua_tousertype(tolua_S,2,0));
  float width = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   BuildQuadStrip(in,out,width);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BuildQuadStrip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: BuildQuadStripVarying */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_BuildQuadStripVarying00
static int tolua_BindTerrainEdit_BuildQuadStripVarying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterVertexList",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RasterVertexList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterVertexList* in = ((RasterVertexList*)  tolua_tousertype(tolua_S,1,0));
  RasterVertexList* out = ((RasterVertexList*)  tolua_tousertype(tolua_S,2,0));
  float startwidth = ((float)  tolua_tonumber(tolua_S,3,0));
  float endwidth = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   BuildQuadStripVarying(in,out,startwidth,endwidth);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BuildQuadStripVarying'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: RenderANLKernelToBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RenderANLKernelToBuffer00
static int tolua_BindTerrainEdit_RenderANLKernelToBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CKernel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RasterBuffer* buffer = ((RasterBuffer*)  tolua_tousertype(tolua_S,1,0));
  CKernel* kernel = ((CKernel*)  tolua_tousertype(tolua_S,2,0));
  float lowrange = ((float)  tolua_tonumber(tolua_S,3,0));
  float highrange = ((float)  tolua_tonumber(tolua_S,4,1));
  {
   RenderANLKernelToBuffer(buffer,kernel,lowrange,highrange);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RenderANLKernelToBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: SetHeightFromRasterBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_SetHeightFromRasterBuffer00
static int tolua_BindTerrainEdit_SetHeightFromRasterBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RasterBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Image",1,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* height = ((Image*)  tolua_tousertype(tolua_S,1,0));
  RasterBuffer* buffer = ((RasterBuffer*)  tolua_tousertype(tolua_S,2,0));
  Image* mask = ((Image*)  tolua_tousertype(tolua_S,3,0));
  bool useMask = ((bool)  tolua_toboolean(tolua_S,4,false));
  bool invertMask = ((bool)  tolua_toboolean(tolua_S,5,false));
  {
   SetHeightFromRasterBuffer(height,buffer,mask,useMask,invertMask);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHeightFromRasterBuffer'.",&tolua_err);
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
  tolua_function(tolua_S,"ApplyBlendBrush8",tolua_BindTerrainEdit_ApplyBlendBrush800);
  tolua_function(tolua_S,"ApplyMaskBrush",tolua_BindTerrainEdit_ApplyMaskBrush00);
  tolua_function(tolua_S,"ApplySmoothBrush",tolua_BindTerrainEdit_ApplySmoothBrush00);
  tolua_function(tolua_S,"ApplySpeckleBrush",tolua_BindTerrainEdit_ApplySpeckleBrush00);
  tolua_function(tolua_S,"SetBrushCursorHeight",tolua_BindTerrainEdit_SetBrushCursorHeight00);
  tolua_function(tolua_S,"InvertMask",tolua_BindTerrainEdit_InvertMask00);
  tolua_function(tolua_S,"RenderANLKernelToHeight",tolua_BindTerrainEdit_RenderANLKernelToHeight00);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"RasterVertex","RasterVertex","",tolua_collect_RasterVertex);
  #else
  tolua_cclass(tolua_S,"RasterVertex","RasterVertex","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"RasterVertex");
   tolua_variable(tolua_S,"x_",tolua_get_RasterVertex_x_,tolua_set_RasterVertex_x_);
   tolua_variable(tolua_S,"y_",tolua_get_RasterVertex_y_,tolua_set_RasterVertex_y_);
   tolua_variable(tolua_S,"val_",tolua_get_RasterVertex_val_,tolua_set_RasterVertex_val_);
   tolua_function(tolua_S,"new",tolua_BindTerrainEdit_RasterVertex_new00);
   tolua_function(tolua_S,"new_local",tolua_BindTerrainEdit_RasterVertex_new00_local);
   tolua_function(tolua_S,".call",tolua_BindTerrainEdit_RasterVertex_new00_local);
   tolua_function(tolua_S,"new",tolua_BindTerrainEdit_RasterVertex_new01);
   tolua_function(tolua_S,"new_local",tolua_BindTerrainEdit_RasterVertex_new01_local);
   tolua_function(tolua_S,".call",tolua_BindTerrainEdit_RasterVertex_new01_local);
   tolua_function(tolua_S,"new",tolua_BindTerrainEdit_RasterVertex_new02);
   tolua_function(tolua_S,"new_local",tolua_BindTerrainEdit_RasterVertex_new02_local);
   tolua_function(tolua_S,".call",tolua_BindTerrainEdit_RasterVertex_new02_local);
   tolua_function(tolua_S,"delete",tolua_BindTerrainEdit_RasterVertex_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"RasterVertexList","RasterVertexList","",tolua_collect_RasterVertexList);
  #else
  tolua_cclass(tolua_S,"RasterVertexList","RasterVertexList","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"RasterVertexList");
   tolua_function(tolua_S,"new",tolua_BindTerrainEdit_RasterVertexList_new00);
   tolua_function(tolua_S,"new_local",tolua_BindTerrainEdit_RasterVertexList_new00_local);
   tolua_function(tolua_S,".call",tolua_BindTerrainEdit_RasterVertexList_new00_local);
   tolua_function(tolua_S,"new",tolua_BindTerrainEdit_RasterVertexList_new01);
   tolua_function(tolua_S,"new_local",tolua_BindTerrainEdit_RasterVertexList_new01_local);
   tolua_function(tolua_S,".call",tolua_BindTerrainEdit_RasterVertexList_new01_local);
   tolua_function(tolua_S,"new",tolua_BindTerrainEdit_RasterVertexList_new02);
   tolua_function(tolua_S,"new_local",tolua_BindTerrainEdit_RasterVertexList_new02_local);
   tolua_function(tolua_S,".call",tolua_BindTerrainEdit_RasterVertexList_new02_local);
   tolua_function(tolua_S,"new",tolua_BindTerrainEdit_RasterVertexList_new03);
   tolua_function(tolua_S,"new_local",tolua_BindTerrainEdit_RasterVertexList_new03_local);
   tolua_function(tolua_S,".call",tolua_BindTerrainEdit_RasterVertexList_new03_local);
   tolua_function(tolua_S,"delete",tolua_BindTerrainEdit_RasterVertexList_delete00);
   tolua_function(tolua_S,"size",tolua_BindTerrainEdit_RasterVertexList_size00);
   tolua_function(tolua_S,"capacity",tolua_BindTerrainEdit_RasterVertexList_capacity00);
   tolua_function(tolua_S,"bytes",tolua_BindTerrainEdit_RasterVertexList_bytes00);
   tolua_function(tolua_S,"fill",tolua_BindTerrainEdit_RasterVertexList_fill00);
   tolua_function(tolua_S,"swap",tolua_BindTerrainEdit_RasterVertexList_swap00);
   tolua_function(tolua_S,"at",tolua_BindTerrainEdit_RasterVertexList_at00);
   tolua_function(tolua_S,"resize",tolua_BindTerrainEdit_RasterVertexList_resize00);
   tolua_function(tolua_S,"reserve",tolua_BindTerrainEdit_RasterVertexList_reserve00);
   tolua_function(tolua_S,"empty",tolua_BindTerrainEdit_RasterVertexList_empty00);
   tolua_function(tolua_S,"push_back",tolua_BindTerrainEdit_RasterVertexList_push_back00);
   tolua_function(tolua_S,"front",tolua_BindTerrainEdit_RasterVertexList_front00);
   tolua_function(tolua_S,"back",tolua_BindTerrainEdit_RasterVertexList_back00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"RasterBuffer","RasterBuffer","",tolua_collect_RasterBuffer);
  #else
  tolua_cclass(tolua_S,"RasterBuffer","RasterBuffer","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"RasterBuffer");
   tolua_function(tolua_S,"new",tolua_BindTerrainEdit_RasterBuffer_new00);
   tolua_function(tolua_S,"new_local",tolua_BindTerrainEdit_RasterBuffer_new00_local);
   tolua_function(tolua_S,".call",tolua_BindTerrainEdit_RasterBuffer_new00_local);
   tolua_function(tolua_S,"new",tolua_BindTerrainEdit_RasterBuffer_new01);
   tolua_function(tolua_S,"new_local",tolua_BindTerrainEdit_RasterBuffer_new01_local);
   tolua_function(tolua_S,".call",tolua_BindTerrainEdit_RasterBuffer_new01_local);
   tolua_function(tolua_S,"delete",tolua_BindTerrainEdit_RasterBuffer_delete00);
   tolua_function(tolua_S,"resize",tolua_BindTerrainEdit_RasterBuffer_resize00);
   tolua_function(tolua_S,"destroy",tolua_BindTerrainEdit_RasterBuffer_destroy00);
   tolua_function(tolua_S,"width",tolua_BindTerrainEdit_RasterBuffer_width00);
   tolua_function(tolua_S,"height",tolua_BindTerrainEdit_RasterBuffer_height00);
   tolua_function(tolua_S,"set",tolua_BindTerrainEdit_RasterBuffer_set00);
   tolua_function(tolua_S,"get",tolua_BindTerrainEdit_RasterBuffer_get00);
   tolua_function(tolua_S,"getRef",tolua_BindTerrainEdit_RasterBuffer_getRef00);
   tolua_function(tolua_S,"getBilinear",tolua_BindTerrainEdit_RasterBuffer_getBilinear00);
   tolua_function(tolua_S,"getIndexed",tolua_BindTerrainEdit_RasterBuffer_getIndexed00);
   tolua_function(tolua_S,"setIndexed",tolua_BindTerrainEdit_RasterBuffer_setIndexed00);
   tolua_function(tolua_S,"fill",tolua_BindTerrainEdit_RasterBuffer_fill00);
   tolua_function(tolua_S,"copyFrom",tolua_BindTerrainEdit_RasterBuffer_copyFrom00);
   tolua_function(tolua_S,"copyFromSub",tolua_BindTerrainEdit_RasterBuffer_copyFromSub00);
   tolua_function(tolua_S,"addArray",tolua_BindTerrainEdit_RasterBuffer_addArray00);
   tolua_function(tolua_S,"addArraySub",tolua_BindTerrainEdit_RasterBuffer_addArraySub00);
   tolua_function(tolua_S,"subtractArray",tolua_BindTerrainEdit_RasterBuffer_subtractArray00);
   tolua_function(tolua_S,"subtractArraySub",tolua_BindTerrainEdit_RasterBuffer_subtractArraySub00);
   tolua_function(tolua_S,"multiplyArray",tolua_BindTerrainEdit_RasterBuffer_multiplyArray00);
   tolua_function(tolua_S,"multiplyArraySub",tolua_BindTerrainEdit_RasterBuffer_multiplyArraySub00);
   tolua_function(tolua_S,"scale",tolua_BindTerrainEdit_RasterBuffer_scale00);
   tolua_function(tolua_S,"blendFromArrays",tolua_BindTerrainEdit_RasterBuffer_blendFromArrays00);
   tolua_function(tolua_S,"selectFromArrays",tolua_BindTerrainEdit_RasterBuffer_selectFromArrays00);
   tolua_function(tolua_S,"getMax",tolua_BindTerrainEdit_RasterBuffer_getMax00);
   tolua_function(tolua_S,"getMin",tolua_BindTerrainEdit_RasterBuffer_getMin00);
   tolua_function(tolua_S,"scaleToRange",tolua_BindTerrainEdit_RasterBuffer_scaleToRange00);
   tolua_function(tolua_S,"wrapCoords",tolua_BindTerrainEdit_RasterBuffer_wrapCoords00);
   tolua_function(tolua_S,"offset",tolua_BindTerrainEdit_RasterBuffer_offset00);
   tolua_function(tolua_S,"flipVertical",tolua_BindTerrainEdit_RasterBuffer_flipVertical00);
   tolua_function(tolua_S,"flipHorizontal",tolua_BindTerrainEdit_RasterBuffer_flipHorizontal00);
   tolua_function(tolua_S,"scaleTo",tolua_BindTerrainEdit_RasterBuffer_scaleTo00);
   tolua_function(tolua_S,"blur",tolua_BindTerrainEdit_RasterBuffer_blur00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"RasterizeTriangle",tolua_BindTerrainEdit_RasterizeTriangle00);
  tolua_function(tolua_S,"RasterizeQuadStrip",tolua_BindTerrainEdit_RasterizeQuadStrip00);
  tolua_function(tolua_S,"BlendHeightWithRasterizedBuffer",tolua_BindTerrainEdit_BlendHeightWithRasterizedBuffer00);
  tolua_function(tolua_S,"BlendColorWithRasterizedBuffer",tolua_BindTerrainEdit_BlendColorWithRasterizedBuffer00);
  tolua_function(tolua_S,"TessellateLineList",tolua_BindTerrainEdit_TessellateLineList00);
  tolua_function(tolua_S,"ApplyBedFunction",tolua_BindTerrainEdit_ApplyBedFunction00);
  tolua_function(tolua_S,"BuildQuadStrip",tolua_BindTerrainEdit_BuildQuadStrip00);
  tolua_function(tolua_S,"BuildQuadStripVarying",tolua_BindTerrainEdit_BuildQuadStripVarying00);
  tolua_function(tolua_S,"RenderANLKernelToBuffer",tolua_BindTerrainEdit_RenderANLKernelToBuffer00);
  tolua_function(tolua_S,"SetHeightFromRasterBuffer",tolua_BindTerrainEdit_SetHeightFromRasterBuffer00);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_BindTerrainEdit (lua_State* tolua_S) {
 return tolua_BindTerrainEdit_open(tolua_S);
};
#endif

