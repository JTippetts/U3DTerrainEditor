/*
** Lua binding: BindTerrainEdit
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int tolua_BindTerrainEdit_open (lua_State* tolua_S);

#include <Urho3D/LuaScript/ToluaUtils.h>
#include "TerrainEdit.h"
#include "NodeGraphLink.h"
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

static int tolua_collect_TerrainEdit (lua_State* tolua_S)
{
 TerrainEdit* self = (TerrainEdit*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_RasterVertex (lua_State* tolua_S)
{
 RasterVertex* self = (RasterVertex*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_BrushSettings (lua_State* tolua_S)
{
 BrushSettings* self = (BrushSettings*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_IntVector2 (lua_State* tolua_S)
{
 IntVector2* self = (IntVector2*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

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

static int tolua_collect_MaskSettings (lua_State* tolua_S)
{
 MaskSettings* self = (MaskSettings*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"RasterVertexList");
 tolua_usertype(tolua_S,"UIElement");
 tolua_usertype(tolua_S,"CustomGeometry");
 tolua_usertype(tolua_S,"Color");
 tolua_usertype(tolua_S,"MaskSettings");
 tolua_usertype(tolua_S,"Image");
 tolua_usertype(tolua_S,"BrushSettings");
 tolua_usertype(tolua_S,"Button");
 tolua_usertype(tolua_S,"Material");
 tolua_usertype(tolua_S,"CArray2Dd");
 tolua_usertype(tolua_S,"Vector3");
 tolua_usertype(tolua_S,"BorderImage");
 tolua_usertype(tolua_S,"Scene");
 tolua_usertype(tolua_S,"NodeGraphLinkPane");
 tolua_usertype(tolua_S,"Terrain");
 tolua_usertype(tolua_S,"IntRect");
 tolua_usertype(tolua_S,"Context");
 tolua_usertype(tolua_S,"NodeGraphLink");
 tolua_usertype(tolua_S,"NodeGraphLinkDest");
 tolua_usertype(tolua_S,"NodeGraphLinkSource");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"RasterVertex");
 tolua_usertype(tolua_S,"TerrainEdit");
 tolua_usertype(tolua_S,"CKernel");
 tolua_usertype(tolua_S,"IntVector2");
}

/* get function: radius of class  BrushSettings */
#ifndef TOLUA_DISABLE_tolua_get_BrushSettings_radius
static int tolua_get_BrushSettings_radius(lua_State* tolua_S)
{
  BrushSettings* self = (BrushSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'radius'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->radius);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: radius of class  BrushSettings */
#ifndef TOLUA_DISABLE_tolua_set_BrushSettings_radius
static int tolua_set_BrushSettings_radius(lua_State* tolua_S)
{
  BrushSettings* self = (BrushSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'radius'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->radius = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: max of class  BrushSettings */
#ifndef TOLUA_DISABLE_tolua_get_BrushSettings_max
static int tolua_get_BrushSettings_max(lua_State* tolua_S)
{
  BrushSettings* self = (BrushSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'max'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->max);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: max of class  BrushSettings */
#ifndef TOLUA_DISABLE_tolua_set_BrushSettings_max
static int tolua_set_BrushSettings_max(lua_State* tolua_S)
{
  BrushSettings* self = (BrushSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'max'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->max = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: power of class  BrushSettings */
#ifndef TOLUA_DISABLE_tolua_get_BrushSettings_power
static int tolua_get_BrushSettings_power(lua_State* tolua_S)
{
  BrushSettings* self = (BrushSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'power'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->power);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: power of class  BrushSettings */
#ifndef TOLUA_DISABLE_tolua_set_BrushSettings_power
static int tolua_set_BrushSettings_power(lua_State* tolua_S)
{
  BrushSettings* self = (BrushSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'power'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->power = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: hardness of class  BrushSettings */
#ifndef TOLUA_DISABLE_tolua_get_BrushSettings_hardness
static int tolua_get_BrushSettings_hardness(lua_State* tolua_S)
{
  BrushSettings* self = (BrushSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hardness'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->hardness);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: hardness of class  BrushSettings */
#ifndef TOLUA_DISABLE_tolua_set_BrushSettings_hardness
static int tolua_set_BrushSettings_hardness(lua_State* tolua_S)
{
  BrushSettings* self = (BrushSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'hardness'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->hardness = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  BrushSettings */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_BrushSettings_new00
static int tolua_BindTerrainEdit_BrushSettings_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BrushSettings",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  BrushSettings* tolua_ret = (BrushSettings*)  Mtolua_new((BrushSettings)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BrushSettings");
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

/* method: new_local of class  BrushSettings */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_BrushSettings_new00_local
static int tolua_BindTerrainEdit_BrushSettings_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BrushSettings",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  BrushSettings* tolua_ret = (BrushSettings*)  Mtolua_new((BrushSettings)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BrushSettings");
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

/* method: new of class  BrushSettings */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_BrushSettings_new01
static int tolua_BindTerrainEdit_BrushSettings_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BrushSettings",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
  float mx = ((float)  tolua_tonumber(tolua_S,3,0));
  float p = ((float)  tolua_tonumber(tolua_S,4,0));
  float h = ((float)  tolua_tonumber(tolua_S,5,0));
 {
  BrushSettings* tolua_ret = (BrushSettings*)  Mtolua_new((BrushSettings)(r,mx,p,h));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BrushSettings");
 }
 }
 return 1;
tolua_lerror:
 return tolua_BindTerrainEdit_BrushSettings_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  BrushSettings */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_BrushSettings_new01_local
static int tolua_BindTerrainEdit_BrushSettings_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BrushSettings",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
  float mx = ((float)  tolua_tonumber(tolua_S,3,0));
  float p = ((float)  tolua_tonumber(tolua_S,4,0));
  float h = ((float)  tolua_tonumber(tolua_S,5,0));
 {
  BrushSettings* tolua_ret = (BrushSettings*)  Mtolua_new((BrushSettings)(r,mx,p,h));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"BrushSettings");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_BindTerrainEdit_BrushSettings_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* get function: usemask0 of class  MaskSettings */
#ifndef TOLUA_DISABLE_tolua_get_MaskSettings_usemask0
static int tolua_get_MaskSettings_usemask0(lua_State* tolua_S)
{
  MaskSettings* self = (MaskSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'usemask0'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->usemask0);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: usemask0 of class  MaskSettings */
#ifndef TOLUA_DISABLE_tolua_set_MaskSettings_usemask0
static int tolua_set_MaskSettings_usemask0(lua_State* tolua_S)
{
  MaskSettings* self = (MaskSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'usemask0'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->usemask0 = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: usemask1 of class  MaskSettings */
#ifndef TOLUA_DISABLE_tolua_get_MaskSettings_usemask1
static int tolua_get_MaskSettings_usemask1(lua_State* tolua_S)
{
  MaskSettings* self = (MaskSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'usemask1'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->usemask1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: usemask1 of class  MaskSettings */
#ifndef TOLUA_DISABLE_tolua_set_MaskSettings_usemask1
static int tolua_set_MaskSettings_usemask1(lua_State* tolua_S)
{
  MaskSettings* self = (MaskSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'usemask1'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->usemask1 = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: usemask2 of class  MaskSettings */
#ifndef TOLUA_DISABLE_tolua_get_MaskSettings_usemask2
static int tolua_get_MaskSettings_usemask2(lua_State* tolua_S)
{
  MaskSettings* self = (MaskSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'usemask2'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->usemask2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: usemask2 of class  MaskSettings */
#ifndef TOLUA_DISABLE_tolua_set_MaskSettings_usemask2
static int tolua_set_MaskSettings_usemask2(lua_State* tolua_S)
{
  MaskSettings* self = (MaskSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'usemask2'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->usemask2 = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: invertmask0 of class  MaskSettings */
#ifndef TOLUA_DISABLE_tolua_get_MaskSettings_invertmask0
static int tolua_get_MaskSettings_invertmask0(lua_State* tolua_S)
{
  MaskSettings* self = (MaskSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'invertmask0'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->invertmask0);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: invertmask0 of class  MaskSettings */
#ifndef TOLUA_DISABLE_tolua_set_MaskSettings_invertmask0
static int tolua_set_MaskSettings_invertmask0(lua_State* tolua_S)
{
  MaskSettings* self = (MaskSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'invertmask0'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->invertmask0 = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: invertmask1 of class  MaskSettings */
#ifndef TOLUA_DISABLE_tolua_get_MaskSettings_invertmask1
static int tolua_get_MaskSettings_invertmask1(lua_State* tolua_S)
{
  MaskSettings* self = (MaskSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'invertmask1'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->invertmask1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: invertmask1 of class  MaskSettings */
#ifndef TOLUA_DISABLE_tolua_set_MaskSettings_invertmask1
static int tolua_set_MaskSettings_invertmask1(lua_State* tolua_S)
{
  MaskSettings* self = (MaskSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'invertmask1'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->invertmask1 = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: invertmask2 of class  MaskSettings */
#ifndef TOLUA_DISABLE_tolua_get_MaskSettings_invertmask2
static int tolua_get_MaskSettings_invertmask2(lua_State* tolua_S)
{
  MaskSettings* self = (MaskSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'invertmask2'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->invertmask2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: invertmask2 of class  MaskSettings */
#ifndef TOLUA_DISABLE_tolua_set_MaskSettings_invertmask2
static int tolua_set_MaskSettings_invertmask2(lua_State* tolua_S)
{
  MaskSettings* self = (MaskSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'invertmask2'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->invertmask2 = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  MaskSettings */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_MaskSettings_new00
static int tolua_BindTerrainEdit_MaskSettings_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"MaskSettings",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  MaskSettings* tolua_ret = (MaskSettings*)  Mtolua_new((MaskSettings)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"MaskSettings");
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

/* method: new_local of class  MaskSettings */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_MaskSettings_new00_local
static int tolua_BindTerrainEdit_MaskSettings_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"MaskSettings",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  MaskSettings* tolua_ret = (MaskSettings*)  Mtolua_new((MaskSettings)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"MaskSettings");
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

/* method: new of class  MaskSettings */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_MaskSettings_new01
static int tolua_BindTerrainEdit_MaskSettings_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"MaskSettings",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,6,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  bool um0 = ((bool)  tolua_toboolean(tolua_S,2,0));
  bool im0 = ((bool)  tolua_toboolean(tolua_S,3,0));
  bool um1 = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool im1 = ((bool)  tolua_toboolean(tolua_S,5,0));
  bool um2 = ((bool)  tolua_toboolean(tolua_S,6,0));
  bool im2 = ((bool)  tolua_toboolean(tolua_S,7,0));
 {
  MaskSettings* tolua_ret = (MaskSettings*)  Mtolua_new((MaskSettings)(um0,im0,um1,im1,um2,im2));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"MaskSettings");
 }
 }
 return 1;
tolua_lerror:
 return tolua_BindTerrainEdit_MaskSettings_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  MaskSettings */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_MaskSettings_new01_local
static int tolua_BindTerrainEdit_MaskSettings_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"MaskSettings",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,6,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  bool um0 = ((bool)  tolua_toboolean(tolua_S,2,0));
  bool im0 = ((bool)  tolua_toboolean(tolua_S,3,0));
  bool um1 = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool im1 = ((bool)  tolua_toboolean(tolua_S,5,0));
  bool um2 = ((bool)  tolua_toboolean(tolua_S,6,0));
  bool im2 = ((bool)  tolua_toboolean(tolua_S,7,0));
 {
  MaskSettings* tolua_ret = (MaskSettings*)  Mtolua_new((MaskSettings)(um0,im0,um1,im1,um2,im2));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"MaskSettings");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_BindTerrainEdit_MaskSettings_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_new00
static int tolua_BindTerrainEdit_TerrainEdit_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  TerrainEdit* tolua_ret = (TerrainEdit*)  Mtolua_new((TerrainEdit)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"TerrainEdit");
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

/* method: new_local of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_new00_local
static int tolua_BindTerrainEdit_TerrainEdit_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  TerrainEdit* tolua_ret = (TerrainEdit*)  Mtolua_new((TerrainEdit)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"TerrainEdit");
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

/* method: delete of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_delete00
static int tolua_BindTerrainEdit_TerrainEdit_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Initialize of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_Initialize00
static int tolua_BindTerrainEdit_TerrainEdit_Initialize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_isusertype(tolua_S,7,"Vector3",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,8,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
  int tw = ((int)  tolua_tonumber(tolua_S,3,0));
  int th = ((int)  tolua_tonumber(tolua_S,4,0));
  int bw = ((int)  tolua_tonumber(tolua_S,5,0));
  int bh = ((int)  tolua_tonumber(tolua_S,6,0));
  Vector3 spacing = *((Vector3*)  tolua_tousertype(tolua_S,7,0));
  bool use16bit = ((bool)  tolua_toboolean(tolua_S,8,true));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Initialize'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->Initialize(scene,tw,th,bw,bh,spacing,use16bit);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Initialize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTerrainSize of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_SetTerrainSize00
static int tolua_BindTerrainEdit_TerrainEdit_SetTerrainSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"Vector3",0,&tolua_err)) ||
 !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  int w = ((int)  tolua_tonumber(tolua_S,2,0));
  int h = ((int)  tolua_tonumber(tolua_S,3,0));
  Vector3 spacing = *((Vector3*)  tolua_tousertype(tolua_S,4,0));
  bool use16bit = ((bool)  tolua_toboolean(tolua_S,5,true));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTerrainSize'", NULL);
#endif
 {
  self->SetTerrainSize(w,h,spacing,use16bit);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTerrainSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBlendMaskSize of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_SetBlendMaskSize00
static int tolua_BindTerrainEdit_TerrainEdit_SetBlendMaskSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  int w = ((int)  tolua_tonumber(tolua_S,2,0));
  int h = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBlendMaskSize'", NULL);
#endif
 {
  self->SetBlendMaskSize(w,h);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBlendMaskSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTerrainSpacing of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_SetTerrainSpacing00
static int tolua_BindTerrainEdit_TerrainEdit_SetTerrainSpacing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  Vector3 spacing = *((Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTerrainSpacing'", NULL);
#endif
 {
  self->SetTerrainSpacing(spacing);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTerrainSpacing'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WorldToNormalized of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_WorldToNormalized00
static int tolua_BindTerrainEdit_TerrainEdit_WorldToNormalized00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  Vector3 world = *((Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WorldToNormalized'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->WorldToNormalized(world);
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

/* method: NormalizedToWorld of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_NormalizedToWorld00
static int tolua_BindTerrainEdit_TerrainEdit_NormalizedToWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  Vector2 normalized = *((Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NormalizedToWorld'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->NormalizedToWorld(normalized);
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

/* method: WorldToTerrain of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_WorldToTerrain00
static int tolua_BindTerrainEdit_TerrainEdit_WorldToTerrain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  Vector3 world = *((Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WorldToTerrain'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->WorldToTerrain(world);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WorldToTerrain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: WorldToBlend of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_WorldToBlend00
static int tolua_BindTerrainEdit_TerrainEdit_WorldToBlend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  Vector3 world = *((Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'WorldToBlend'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->WorldToBlend(world);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'WorldToBlend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: TerrainToWorld of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_TerrainToWorld00
static int tolua_BindTerrainEdit_TerrainEdit_TerrainToWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  IntVector2 terrain = *((IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TerrainToWorld'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->TerrainToWorld(terrain);
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
 tolua_error(tolua_S,"#ferror in function 'TerrainToWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BlendToWorld of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_BlendToWorld00
static int tolua_BindTerrainEdit_TerrainEdit_BlendToWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  IntVector2 blend = *((IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BlendToWorld'", NULL);
#endif
 {
  Vector3 tolua_ret = (Vector3)  self->BlendToWorld(blend);
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
 tolua_error(tolua_S,"#ferror in function 'BlendToWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: TerrainToNormalized of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_TerrainToNormalized00
static int tolua_BindTerrainEdit_TerrainEdit_TerrainToNormalized00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  IntVector2 terrain = *((IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TerrainToNormalized'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->TerrainToNormalized(terrain);
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
 tolua_error(tolua_S,"#ferror in function 'TerrainToNormalized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BlendToNormalized of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_BlendToNormalized00
static int tolua_BindTerrainEdit_TerrainEdit_BlendToNormalized00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntVector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  IntVector2 blend = *((IntVector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BlendToNormalized'", NULL);
#endif
 {
  Vector2 tolua_ret = (Vector2)  self->BlendToNormalized(blend);
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
 tolua_error(tolua_S,"#ferror in function 'BlendToNormalized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: NormalizedToBlend of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_NormalizedToBlend00
static int tolua_BindTerrainEdit_TerrainEdit_NormalizedToBlend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  Vector2 norm = *((Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NormalizedToBlend'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->NormalizedToBlend(norm);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'NormalizedToBlend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: NormalizedToTerrain of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_NormalizedToTerrain00
static int tolua_BindTerrainEdit_TerrainEdit_NormalizedToTerrain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  Vector2 norm = *((Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NormalizedToTerrain'", NULL);
#endif
 {
  IntVector2 tolua_ret = (IntVector2)  self->NormalizedToTerrain(norm);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((IntVector2)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(IntVector2));
  tolua_pushusertype(tolua_S,tolua_obj,"IntVector2");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'NormalizedToTerrain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHeightValue of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_SetHeightValue00
static int tolua_BindTerrainEdit_TerrainEdit_SetHeightValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  float val = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHeightValue'", NULL);
#endif
 {
  self->SetHeightValue(x,y,val);
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

/* method: GetHeightValue of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_GetHeightValue00
static int tolua_BindTerrainEdit_TerrainEdit_GetHeightValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHeightValue'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetHeightValue(x,y);
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

/* method: GetHeightValue of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_GetHeightValue01
static int tolua_BindTerrainEdit_TerrainEdit_GetHeightValue01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  Vector3 worldpos = *((Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHeightValue'", NULL);
#endif
 {
  float tolua_ret = (float)  self->GetHeightValue(worldpos);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_BindTerrainEdit_TerrainEdit_GetHeightValue00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTerrainWidth of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_GetTerrainWidth00
static int tolua_BindTerrainEdit_TerrainEdit_GetTerrainWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTerrainWidth'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetTerrainWidth();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTerrainWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTerrainHeight of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_GetTerrainHeight00
static int tolua_BindTerrainEdit_TerrainEdit_GetTerrainHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTerrainHeight'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetTerrainHeight();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTerrainHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBlendWidth of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_GetBlendWidth00
static int tolua_BindTerrainEdit_TerrainEdit_GetBlendWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBlendWidth'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetBlendWidth();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBlendWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBlendHeight of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_GetBlendHeight00
static int tolua_BindTerrainEdit_TerrainEdit_GetBlendHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBlendHeight'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetBlendHeight();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBlendHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHeightBuffer of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_SetHeightBuffer00
static int tolua_BindTerrainEdit_TerrainEdit_SetHeightBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"MaskSettings",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  CArray2Dd* buffer = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
  MaskSettings* masksettings = ((MaskSettings*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHeightBuffer'", NULL);
#endif
 {
  self->SetHeightBuffer(*buffer,*masksettings);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHeightBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLayerBuffer of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_SetLayerBuffer00
static int tolua_BindTerrainEdit_TerrainEdit_SetLayerBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"MaskSettings",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  CArray2Dd* buffer = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
  int layer = ((int)  tolua_tonumber(tolua_S,3,0));
  MaskSettings* masksettings = ((MaskSettings*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLayerBuffer'", NULL);
#endif
 {
  self->SetLayerBuffer(*buffer,layer,*masksettings);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLayerBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLayerBufferMax of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_SetLayerBufferMax00
static int tolua_BindTerrainEdit_TerrainEdit_SetLayerBufferMax00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"MaskSettings",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  CArray2Dd* buffer = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
  int layer = ((int)  tolua_tonumber(tolua_S,3,0));
  MaskSettings* masksettings = ((MaskSettings*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLayerBufferMax'", NULL);
#endif
 {
  self->SetLayerBufferMax(*buffer,layer,*masksettings);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLayerBufferMax'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BlendHeightBuffer of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_BlendHeightBuffer00
static int tolua_BindTerrainEdit_TerrainEdit_BlendHeightBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CArray2Dd",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"MaskSettings",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  CArray2Dd* buffer = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
  CArray2Dd* blend = ((CArray2Dd*)  tolua_tousertype(tolua_S,3,0));
  MaskSettings* masksettings = ((MaskSettings*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BlendHeightBuffer'", NULL);
#endif
 {
  self->BlendHeightBuffer(*buffer,*blend,*masksettings);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BlendHeightBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ApplyHeightBrush of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_ApplyHeightBrush00
static int tolua_BindTerrainEdit_TerrainEdit_ApplyHeightBrush00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"BrushSettings",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"MaskSettings",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float z = ((float)  tolua_tonumber(tolua_S,3,0));
  float dt = ((float)  tolua_tonumber(tolua_S,4,0));
  BrushSettings* brush = ((BrushSettings*)  tolua_tousertype(tolua_S,5,0));
  MaskSettings* masksettings = ((MaskSettings*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyHeightBrush'", NULL);
#endif
 {
  self->ApplyHeightBrush(x,z,dt,*brush,*masksettings);
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

/* method: ApplyBlendBrush of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_ApplyBlendBrush00
static int tolua_BindTerrainEdit_TerrainEdit_ApplyBlendBrush00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"BrushSettings",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_isusertype(tolua_S,7,"MaskSettings",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float z = ((float)  tolua_tonumber(tolua_S,3,0));
  int layer = ((int)  tolua_tonumber(tolua_S,4,0));
  float dt = ((float)  tolua_tonumber(tolua_S,5,0));
  BrushSettings* brush = ((BrushSettings*)  tolua_tousertype(tolua_S,6,0));
  MaskSettings* masksettings = ((MaskSettings*)  tolua_tousertype(tolua_S,7,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyBlendBrush'", NULL);
#endif
 {
  self->ApplyBlendBrush(x,z,layer,dt,*brush,*masksettings);
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

/* method: ApplyMaskBrush of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_ApplyMaskBrush00
static int tolua_BindTerrainEdit_TerrainEdit_ApplyMaskBrush00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"BrushSettings",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_isusertype(tolua_S,7,"MaskSettings",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float z = ((float)  tolua_tonumber(tolua_S,3,0));
  int which = ((int)  tolua_tonumber(tolua_S,4,0));
  float dt = ((float)  tolua_tonumber(tolua_S,5,0));
  BrushSettings* brush = ((BrushSettings*)  tolua_tousertype(tolua_S,6,0));
  MaskSettings* masksettings = ((MaskSettings*)  tolua_tousertype(tolua_S,7,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplyMaskBrush'", NULL);
#endif
 {
  self->ApplyMaskBrush(x,z,which,dt,*brush,*masksettings);
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

/* method: ApplySmoothBrush of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_ApplySmoothBrush00
static int tolua_BindTerrainEdit_TerrainEdit_ApplySmoothBrush00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"BrushSettings",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"MaskSettings",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float z = ((float)  tolua_tonumber(tolua_S,3,0));
  float dt = ((float)  tolua_tonumber(tolua_S,4,0));
  BrushSettings* brush = ((BrushSettings*)  tolua_tousertype(tolua_S,5,0));
  MaskSettings* masksettings = ((MaskSettings*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ApplySmoothBrush'", NULL);
#endif
 {
  self->ApplySmoothBrush(x,z,dt,*brush,*masksettings);
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

/* method: SetBrushCursorHeight of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_SetBrushCursorHeight00
static int tolua_BindTerrainEdit_TerrainEdit_SetBrushCursorHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CustomGeometry",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  CustomGeometry* brush = ((CustomGeometry*)  tolua_tousertype(tolua_S,2,0));
  float groundx = ((float)  tolua_tonumber(tolua_S,3,0));
  float groundz = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBrushCursorHeight'", NULL);
#endif
 {
  self->SetBrushCursorHeight(brush,groundx,groundz);
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

/* method: InvertMask of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_InvertMask00
static int tolua_BindTerrainEdit_TerrainEdit_InvertMask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  int which = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InvertMask'", NULL);
#endif
 {
  self->InvertMask(which);
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

/* method: ClearMask of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_ClearMask00
static int tolua_BindTerrainEdit_TerrainEdit_ClearMask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  int which = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearMask'", NULL);
#endif
 {
  self->ClearMask(which);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearMask'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearAllMasks of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_ClearAllMasks00
static int tolua_BindTerrainEdit_TerrainEdit_ClearAllMasks00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearAllMasks'", NULL);
#endif
 {
  self->ClearAllMasks();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearAllMasks'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InvertLayer of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_InvertLayer00
static int tolua_BindTerrainEdit_TerrainEdit_InvertLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  int which = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InvertLayer'", NULL);
#endif
 {
  self->InvertLayer(which);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InvertLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearLayer of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_ClearLayer00
static int tolua_BindTerrainEdit_TerrainEdit_ClearLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  int which = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearLayer'", NULL);
#endif
 {
  self->ClearLayer(which);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearAllLayers of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_ClearAllLayers00
static int tolua_BindTerrainEdit_TerrainEdit_ClearAllLayers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearAllLayers'", NULL);
#endif
 {
  self->ClearAllLayers();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearAllLayers'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InvertHeight of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_InvertHeight00
static int tolua_BindTerrainEdit_TerrainEdit_InvertHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InvertHeight'", NULL);
#endif
 {
  self->InvertHeight();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InvertHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearHeight of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_ClearHeight00
static int tolua_BindTerrainEdit_TerrainEdit_ClearHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearHeight'", NULL);
#endif
 {
  self->ClearHeight();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaterial of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_GetMaterial00
static int tolua_BindTerrainEdit_TerrainEdit_GetMaterial00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaterial'", NULL);
#endif
 {
  Material* tolua_ret = (Material*)  self->GetMaterial();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Material");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaterial'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTerrain of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_GetTerrain00
static int tolua_BindTerrainEdit_TerrainEdit_GetTerrain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTerrain'", NULL);
#endif
 {
  Terrain* tolua_ret = (Terrain*)  self->GetTerrain();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Terrain");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTerrain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaterialSettings of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_SetMaterialSettings00
static int tolua_BindTerrainEdit_TerrainEdit_SetMaterialSettings00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  bool triplanar = ((bool)  tolua_toboolean(tolua_S,2,0));
  bool smoothing = ((bool)  tolua_toboolean(tolua_S,3,0));
  bool normalmapping = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaterialSettings'", NULL);
#endif
 {
  self->SetMaterialSettings(triplanar,smoothing,normalmapping);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaterialSettings'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SaveHeightMap of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_SaveHeightMap00
static int tolua_BindTerrainEdit_TerrainEdit_SaveHeightMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  const String filename = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SaveHeightMap'", NULL);
#endif
 {
  self->SaveHeightMap(filename);
 tolua_pushurho3dstring(tolua_S,(const char*)filename);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveHeightMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SaveBlend0 of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_SaveBlend000
static int tolua_BindTerrainEdit_TerrainEdit_SaveBlend000(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  const String filename = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SaveBlend0'", NULL);
#endif
 {
  self->SaveBlend0(filename);
 tolua_pushurho3dstring(tolua_S,(const char*)filename);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveBlend0'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SaveBlend1 of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_SaveBlend100
static int tolua_BindTerrainEdit_TerrainEdit_SaveBlend100(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  const String filename = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SaveBlend1'", NULL);
#endif
 {
  self->SaveBlend1(filename);
 tolua_pushurho3dstring(tolua_S,(const char*)filename);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveBlend1'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SaveMask of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_SaveMask00
static int tolua_BindTerrainEdit_TerrainEdit_SaveMask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  const String filename = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SaveMask'", NULL);
#endif
 {
  self->SaveMask(filename);
 tolua_pushurho3dstring(tolua_S,(const char*)filename);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveMask'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadHeightMap of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_LoadHeightMap00
static int tolua_BindTerrainEdit_TerrainEdit_LoadHeightMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  const String filename = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadHeightMap'", NULL);
#endif
 {
  self->LoadHeightMap(filename);
 tolua_pushurho3dstring(tolua_S,(const char*)filename);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadHeightMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadBlend0 of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_LoadBlend000
static int tolua_BindTerrainEdit_TerrainEdit_LoadBlend000(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  const String filename = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadBlend0'", NULL);
#endif
 {
  self->LoadBlend0(filename);
 tolua_pushurho3dstring(tolua_S,(const char*)filename);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadBlend0'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadBlend1 of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_LoadBlend100
static int tolua_BindTerrainEdit_TerrainEdit_LoadBlend100(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  const String filename = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadBlend1'", NULL);
#endif
 {
  self->LoadBlend1(filename);
 tolua_pushurho3dstring(tolua_S,(const char*)filename);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadBlend1'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadMask of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_LoadMask00
static int tolua_BindTerrainEdit_TerrainEdit_LoadMask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  const String filename = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadMask'", NULL);
#endif
 {
  self->LoadMask(filename);
 tolua_pushurho3dstring(tolua_S,(const char*)filename);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadMask'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSteepness of class  TerrainEdit */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_TerrainEdit_GetSteepness00
static int tolua_BindTerrainEdit_TerrainEdit_GetSteepness00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"TerrainEdit",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  TerrainEdit* self = (TerrainEdit*)  tolua_tousertype(tolua_S,1,0);
  CArray2Dd* buffer = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
  float threshold = ((float)  tolua_tonumber(tolua_S,3,0));
  float fade = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSteepness'", NULL);
#endif
 {
  self->GetSteepness(*buffer,threshold,fade);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSteepness'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

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
 !tolua_isboolean(tolua_S,11,0,&tolua_err) ||
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
  Image* mask = ((Image*)  tolua_tousertype(tolua_S,3,0));
  float x = ((float)  tolua_tonumber(tolua_S,4,0));
  float z = ((float)  tolua_tonumber(tolua_S,5,0));
  float radius = ((float)  tolua_tonumber(tolua_S,6,0));
  float max = ((float)  tolua_tonumber(tolua_S,7,0));
  float power = ((float)  tolua_tonumber(tolua_S,8,0));
  float hardness = ((float)  tolua_tonumber(tolua_S,9,0));
  bool usemask0 = ((bool)  tolua_toboolean(tolua_S,10,0));
  bool usemask1 = ((bool)  tolua_toboolean(tolua_S,11,0));
  bool usemask2 = ((bool)  tolua_toboolean(tolua_S,12,0));
  float dt = ((float)  tolua_tonumber(tolua_S,13,0));
 {
  ApplyHeightBrush(terrain,height,mask,x,z,radius,max,power,hardness,usemask0,usemask1,usemask2,dt);
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
 !tolua_isboolean(tolua_S,13,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,14,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,15,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,16,&tolua_err)
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
  bool usemask0 = ((bool)  tolua_toboolean(tolua_S,12,0));
  bool usemask1 = ((bool)  tolua_toboolean(tolua_S,13,0));
  bool usemask2 = ((bool)  tolua_toboolean(tolua_S,14,0));
  float dt = ((float)  tolua_tonumber(tolua_S,15,0));
 {
  ApplyBlendBrush(terrain,height,blend,mask,x,z,radius,mx,power,hardness,layer,usemask0,usemask1,usemask2,dt);
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
 !tolua_isboolean(tolua_S,14,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,15,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,16,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,17,&tolua_err)
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
  bool usemask0 = ((bool)  tolua_toboolean(tolua_S,13,0));
  bool usemask1 = ((bool)  tolua_toboolean(tolua_S,14,0));
  bool usemask2 = ((bool)  tolua_toboolean(tolua_S,15,0));
  float dt = ((float)  tolua_tonumber(tolua_S,16,0));
 {
  ApplyBlendBrush8(terrain,height,blend0,blend1,mask,x,z,radius,mx,power,hardness,layer,usemask0,usemask1,usemask2,dt);
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
  float mx = ((float)  tolua_tonumber(tolua_S,7,0));
  float power = ((float)  tolua_tonumber(tolua_S,8,0));
  float hardness = ((float)  tolua_tonumber(tolua_S,9,0));
  float dt = ((float)  tolua_tonumber(tolua_S,10,0));
  int which = ((int)  tolua_tonumber(tolua_S,11,0));
 {
  ApplyMaskBrush(terrain,height,mask,x,z,radius,mx,power,hardness,dt,which);
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
 !tolua_isboolean(tolua_S,11,0,&tolua_err) ||
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
  Image* mask = ((Image*)  tolua_tousertype(tolua_S,3,0));
  float x = ((float)  tolua_tonumber(tolua_S,4,0));
  float z = ((float)  tolua_tonumber(tolua_S,5,0));
  float radius = ((float)  tolua_tonumber(tolua_S,6,0));
  float max = ((float)  tolua_tonumber(tolua_S,7,0));
  float power = ((float)  tolua_tonumber(tolua_S,8,0));
  float hardness = ((float)  tolua_tonumber(tolua_S,9,0));
  bool usemask0 = ((bool)  tolua_toboolean(tolua_S,10,0));
  bool usemask1 = ((bool)  tolua_toboolean(tolua_S,11,0));
  bool usemask2 = ((bool)  tolua_toboolean(tolua_S,12,0));
  float dt = ((float)  tolua_tonumber(tolua_S,13,0));
 {
  ApplySmoothBrush(terrain,height,mask,x,z,radius,max,power,hardness,usemask0,usemask1,usemask2,dt);
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

/* function: RasterizeTriangle */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RasterizeTriangle00
static int tolua_BindTerrainEdit_RasterizeTriangle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"RasterVertex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"RasterVertex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"RasterVertex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* buffer = ((CArray2Dd*)  tolua_tousertype(tolua_S,1,0));
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
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"RasterVertexList",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* buffer = ((CArray2Dd*)  tolua_tousertype(tolua_S,1,0));
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
 !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"CArray2Dd",0,&tolua_err) ||
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
  CArray2Dd* buffer = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
  CArray2Dd* blend = ((CArray2Dd*)  tolua_tousertype(tolua_S,3,0));
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
 !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err) ||
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
  CArray2Dd* buffer = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
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

/* function: BlendRasterizedBuffer8 */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_BlendRasterizedBuffer800
static int tolua_BindTerrainEdit_BlendRasterizedBuffer800(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"CArray2Dd",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,5,"Image",1,&tolua_err) ||
 !tolua_isboolean(tolua_S,6,1,&tolua_err) ||
 !tolua_isboolean(tolua_S,7,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Image* img = ((Image*)  tolua_tousertype(tolua_S,1,0));
  Image* other = ((Image*)  tolua_tousertype(tolua_S,2,0));
  CArray2Dd* buffer = ((CArray2Dd*)  tolua_tousertype(tolua_S,3,0));
  int layer = ((int)  tolua_tonumber(tolua_S,4,0));
  Image* mask = ((Image*)  tolua_tousertype(tolua_S,5,0));
  bool useMask = ((bool)  tolua_toboolean(tolua_S,6,false));
  bool invertMask = ((bool)  tolua_toboolean(tolua_S,7,false));
 {
  BlendRasterizedBuffer8(img,other,buffer,layer,mask,useMask,invertMask);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BlendRasterizedBuffer8'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: BlendRasterizedBuffer8Max */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_BlendRasterizedBuffer8Max00
static int tolua_BindTerrainEdit_BlendRasterizedBuffer8Max00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"CArray2Dd",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isusertype(tolua_S,5,"Image",1,&tolua_err) ||
 !tolua_isboolean(tolua_S,6,1,&tolua_err) ||
 !tolua_isboolean(tolua_S,7,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Image* img = ((Image*)  tolua_tousertype(tolua_S,1,0));
  Image* other = ((Image*)  tolua_tousertype(tolua_S,2,0));
  CArray2Dd* buffer = ((CArray2Dd*)  tolua_tousertype(tolua_S,3,0));
  int layer = ((int)  tolua_tonumber(tolua_S,4,0));
  Image* mask = ((Image*)  tolua_tousertype(tolua_S,5,0));
  bool useMask = ((bool)  tolua_toboolean(tolua_S,6,false));
  bool invertMask = ((bool)  tolua_toboolean(tolua_S,7,false));
 {
  BlendRasterizedBuffer8Max(img,other,buffer,layer,mask,useMask,invertMask);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BlendRasterizedBuffer8Max'.",&tolua_err);
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
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* buffer = ((CArray2Dd*)  tolua_tousertype(tolua_S,1,0));
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
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CKernel",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* buffer = ((CArray2Dd*)  tolua_tousertype(tolua_S,1,0));
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

/* function: RenderANLKernelToImage */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_RenderANLKernelToImage00
static int tolua_BindTerrainEdit_RenderANLKernelToImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CKernel",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Image* buffer = ((Image*)  tolua_tousertype(tolua_S,1,0));
  CKernel* kernel = ((CKernel*)  tolua_tousertype(tolua_S,2,0));
  float lowrange = ((float)  tolua_tonumber(tolua_S,3,0));
  float highrange = ((float)  tolua_tonumber(tolua_S,4,0));
 {
  RenderANLKernelToImage(buffer,kernel,lowrange,highrange);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RenderANLKernelToImage'.",&tolua_err);
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
 !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err) ||
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
  CArray2Dd* buffer = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
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

/* function: CopyImageInto */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_CopyImageInto00
static int tolua_BindTerrainEdit_CopyImageInto00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Image* dest = ((Image*)  tolua_tousertype(tolua_S,1,0));
  Image* src = ((Image*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  CopyImageInto(dest,src,x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CopyImageInto'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: IsPowerOfTwo */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_IsPowerOfTwo00
static int tolua_BindTerrainEdit_IsPowerOfTwo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int n = ((int)  tolua_tonumber(tolua_S,1,0));
 {
  bool tolua_ret = (bool)  IsPowerOfTwo(n);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsPowerOfTwo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetNextImageLevel */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_GetNextImageLevel00
static int tolua_BindTerrainEdit_GetNextImageLevel00(lua_State* tolua_S)
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
  Image* i = ((Image*)  tolua_tousertype(tolua_S,1,0));
 {
  Image* tolua_ret = (Image*)  GetNextImageLevel(i);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Image");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNextImageLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: ExtractLayerToBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_ExtractLayerToBuffer00
static int tolua_BindTerrainEdit_ExtractLayerToBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"CArray2Dd",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Image* blend1 = ((Image*)  tolua_tousertype(tolua_S,1,0));
  Image* blend2 = ((Image*)  tolua_tousertype(tolua_S,2,0));
  CArray2Dd* buffer = ((CArray2Dd*)  tolua_tousertype(tolua_S,3,0));
  int layer = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  ExtractLayerToBuffer(blend1,blend2,buffer,layer);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ExtractLayerToBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetLayerBlend */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_GetLayerBlend00
static int tolua_BindTerrainEdit_GetLayerBlend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Image* blend1 = ((Image*)  tolua_tousertype(tolua_S,1,0));
  Image* blend2 = ((Image*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
  int layer = ((int)  tolua_tonumber(tolua_S,5,0));
 {
  float tolua_ret = (float)  GetLayerBlend(blend1,blend2,x,y,layer);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLayerBlend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: SetLayerBlend */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_SetLayerBlend00
static int tolua_BindTerrainEdit_SetLayerBlend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Image* blend1 = ((Image*)  tolua_tousertype(tolua_S,1,0));
  Image* blend2 = ((Image*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
  int layer = ((int)  tolua_tonumber(tolua_S,5,0));
  float v = ((float)  tolua_tonumber(tolua_S,6,0));
 {
  SetLayerBlend(blend1,blend2,x,y,layer,v);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLayerBlend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: LoadImage */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_LoadImage00
static int tolua_BindTerrainEdit_LoadImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Context",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
 !tolua_isstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Context* c = ((Context*)  tolua_tousertype(tolua_S,1,0));
  Image* i = ((Image*)  tolua_tousertype(tolua_S,2,0));
  const char* fname = ((const char*)  tolua_tostring(tolua_S,3,0));
 {
  bool tolua_ret = (bool)  LoadImage(c,i,fname);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadImage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: DistortBuffer */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_DistortBuffer00
static int tolua_BindTerrainEdit_DistortBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"CArray2Dd",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* buffer = ((CArray2Dd*)  tolua_tousertype(tolua_S,1,0));
  CArray2Dd* xd = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
  CArray2Dd* yd = ((CArray2Dd*)  tolua_tousertype(tolua_S,3,0));
  double power = ((double)  tolua_tonumber(tolua_S,4,0));
 {
  DistortBuffer(buffer,xd,yd,power);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DistortBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: SteepnessTerrain */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_SteepnessTerrain00
static int tolua_BindTerrainEdit_SteepnessTerrain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"Image",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,4,"Terrain",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,5,"Image",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,9,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,10,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,11,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Image* blend0 = ((Image*)  tolua_tousertype(tolua_S,1,0));
  Image* blend1 = ((Image*)  tolua_tousertype(tolua_S,2,0));
  Image* hmap = ((Image*)  tolua_tousertype(tolua_S,3,0));
  Terrain* terrain = ((Terrain*)  tolua_tousertype(tolua_S,4,0));
  Image* mask = ((Image*)  tolua_tousertype(tolua_S,5,0));
  float threshold = ((float)  tolua_tonumber(tolua_S,6,0));
  float fade = ((float)  tolua_tonumber(tolua_S,7,0));
  unsigned int layer = ((unsigned int)  tolua_tonumber(tolua_S,8,0));
  bool usemask = ((bool)  tolua_toboolean(tolua_S,9,0));
  bool invertmask = ((bool)  tolua_toboolean(tolua_S,10,0));
 {
  SteepnessTerrain(blend0,blend1,hmap,terrain,mask,threshold,fade,layer,usemask,invertmask);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SteepnessTerrain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddLink of class  NodeGraphLinkSource */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLinkSource_AddLink00
static int tolua_BindTerrainEdit_NodeGraphLinkSource_AddLink00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLinkSource",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"NodeGraphLink",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NodeGraphLinkSource* self = (NodeGraphLinkSource*)  tolua_tousertype(tolua_S,1,0);
  NodeGraphLink* link = ((NodeGraphLink*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddLink'", NULL);
#endif
 {
  self->AddLink(link);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddLink'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveLink of class  NodeGraphLinkSource */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLinkSource_RemoveLink00
static int tolua_BindTerrainEdit_NodeGraphLinkSource_RemoveLink00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLinkSource",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"NodeGraphLinkDest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NodeGraphLinkSource* self = (NodeGraphLinkSource*)  tolua_tousertype(tolua_S,1,0);
  NodeGraphLinkDest* target = ((NodeGraphLinkDest*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveLink'", NULL);
#endif
 {
  self->RemoveLink(target);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveLink'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveLink of class  NodeGraphLinkSource */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLinkSource_RemoveLink01
static int tolua_BindTerrainEdit_NodeGraphLinkSource_RemoveLink01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLinkSource",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"NodeGraphLink",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  NodeGraphLinkSource* self = (NodeGraphLinkSource*)  tolua_tousertype(tolua_S,1,0);
  NodeGraphLink* link = ((NodeGraphLink*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveLink'", NULL);
#endif
 {
  self->RemoveLink(link);
 }
 }
 return 0;
tolua_lerror:
 return tolua_BindTerrainEdit_NodeGraphLinkSource_RemoveLink00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumLinks of class  NodeGraphLinkSource */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLinkSource_GetNumLinks00
static int tolua_BindTerrainEdit_NodeGraphLinkSource_GetNumLinks00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLinkSource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NodeGraphLinkSource* self = (NodeGraphLinkSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumLinks'", NULL);
#endif
 {
  int tolua_ret = (int)  self->GetNumLinks();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumLinks'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLink of class  NodeGraphLinkSource */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLinkSource_GetLink00
static int tolua_BindTerrainEdit_NodeGraphLinkSource_GetLink00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLinkSource",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NodeGraphLinkSource* self = (NodeGraphLinkSource*)  tolua_tousertype(tolua_S,1,0);
  int which = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLink'", NULL);
#endif
 {
  NodeGraphLink* tolua_ret = (NodeGraphLink*)  self->GetLink(which);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"NodeGraphLink");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLink'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLink of class  NodeGraphLinkSource */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLinkSource_GetLink01
static int tolua_BindTerrainEdit_NodeGraphLinkSource_GetLink01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLinkSource",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"NodeGraphLinkDest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  NodeGraphLinkSource* self = (NodeGraphLinkSource*)  tolua_tousertype(tolua_S,1,0);
  NodeGraphLinkDest* target = ((NodeGraphLinkDest*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLink'", NULL);
#endif
 {
  NodeGraphLink* tolua_ret = (NodeGraphLink*)  self->GetLink(target);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"NodeGraphLink");
 }
 }
 return 1;
tolua_lerror:
 return tolua_BindTerrainEdit_NodeGraphLinkSource_GetLink00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRoot of class  NodeGraphLinkSource */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLinkSource_SetRoot00
static int tolua_BindTerrainEdit_NodeGraphLinkSource_SetRoot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLinkSource",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"UIElement",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NodeGraphLinkSource* self = (NodeGraphLinkSource*)  tolua_tousertype(tolua_S,1,0);
  UIElement* root = ((UIElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRoot'", NULL);
#endif
 {
  self->SetRoot(root);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRoot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearRoot of class  NodeGraphLinkSource */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLinkSource_ClearRoot00
static int tolua_BindTerrainEdit_NodeGraphLinkSource_ClearRoot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLinkSource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NodeGraphLinkSource* self = (NodeGraphLinkSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearRoot'", NULL);
#endif
 {
  self->ClearRoot();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearRoot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRoot of class  NodeGraphLinkSource */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLinkSource_GetRoot00
static int tolua_BindTerrainEdit_NodeGraphLinkSource_GetRoot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLinkSource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NodeGraphLinkSource* self = (NodeGraphLinkSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRoot'", NULL);
#endif
 {
  UIElement* tolua_ret = (UIElement*)  self->GetRoot();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIElement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRoot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLink of class  NodeGraphLinkDest */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLinkDest_SetLink00
static int tolua_BindTerrainEdit_NodeGraphLinkDest_SetLink00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLinkDest",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"NodeGraphLink",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NodeGraphLinkDest* self = (NodeGraphLinkDest*)  tolua_tousertype(tolua_S,1,0);
  NodeGraphLink* link = ((NodeGraphLink*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLink'", NULL);
#endif
 {
  self->SetLink(link);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLink'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearLink of class  NodeGraphLinkDest */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLinkDest_ClearLink00
static int tolua_BindTerrainEdit_NodeGraphLinkDest_ClearLink00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLinkDest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NodeGraphLinkDest* self = (NodeGraphLinkDest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearLink'", NULL);
#endif
 {
  self->ClearLink();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearLink'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLink of class  NodeGraphLinkDest */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLinkDest_GetLink00
static int tolua_BindTerrainEdit_NodeGraphLinkDest_GetLink00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLinkDest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NodeGraphLinkDest* self = (NodeGraphLinkDest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLink'", NULL);
#endif
 {
  NodeGraphLink* tolua_ret = (NodeGraphLink*)  self->GetLink();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"NodeGraphLink");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLink'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSource of class  NodeGraphLink */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLink_SetSource00
static int tolua_BindTerrainEdit_NodeGraphLink_SetSource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLink",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"NodeGraphLinkSource",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NodeGraphLink* self = (NodeGraphLink*)  tolua_tousertype(tolua_S,1,0);
  NodeGraphLinkSource* src = ((NodeGraphLinkSource*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSource'", NULL);
#endif
 {
  self->SetSource(src);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSource'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearSource of class  NodeGraphLink */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLink_ClearSource00
static int tolua_BindTerrainEdit_NodeGraphLink_ClearSource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLink",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NodeGraphLink* self = (NodeGraphLink*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearSource'", NULL);
#endif
 {
  self->ClearSource();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearSource'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTarget of class  NodeGraphLink */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLink_SetTarget00
static int tolua_BindTerrainEdit_NodeGraphLink_SetTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLink",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"NodeGraphLinkDest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NodeGraphLink* self = (NodeGraphLink*)  tolua_tousertype(tolua_S,1,0);
  NodeGraphLinkDest* dest = ((NodeGraphLinkDest*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTarget'", NULL);
#endif
 {
  self->SetTarget(dest);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearTarget of class  NodeGraphLink */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLink_ClearTarget00
static int tolua_BindTerrainEdit_NodeGraphLink_ClearTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLink",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NodeGraphLink* self = (NodeGraphLink*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearTarget'", NULL);
#endif
 {
  self->ClearTarget();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSource of class  NodeGraphLink */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLink_GetSource00
static int tolua_BindTerrainEdit_NodeGraphLink_GetSource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLink",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NodeGraphLink* self = (NodeGraphLink*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSource'", NULL);
#endif
 {
  NodeGraphLinkSource* tolua_ret = (NodeGraphLinkSource*)  self->GetSource();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"NodeGraphLinkSource");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSource'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTarget of class  NodeGraphLink */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLink_GetTarget00
static int tolua_BindTerrainEdit_NodeGraphLink_GetTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLink",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NodeGraphLink* self = (NodeGraphLink*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTarget'", NULL);
#endif
 {
  NodeGraphLinkDest* tolua_ret = (NodeGraphLinkDest*)  self->GetTarget();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"NodeGraphLinkDest");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetImageRect of class  NodeGraphLink */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLink_SetImageRect00
static int tolua_BindTerrainEdit_NodeGraphLink_SetImageRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLink",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"IntRect",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NodeGraphLink* self = (NodeGraphLink*)  tolua_tousertype(tolua_S,1,0);
  IntRect* rect = ((IntRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetImageRect'", NULL);
#endif
 {
  self->SetImageRect(*rect);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetImageRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateLink of class  NodeGraphLinkPane */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLinkPane_CreateLink00
static int tolua_BindTerrainEdit_NodeGraphLinkPane_CreateLink00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLinkPane",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"NodeGraphLinkSource",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,3,"NodeGraphLinkDest",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NodeGraphLinkPane* self = (NodeGraphLinkPane*)  tolua_tousertype(tolua_S,1,0);
  NodeGraphLinkSource* source = ((NodeGraphLinkSource*)  tolua_tousertype(tolua_S,2,0));
  NodeGraphLinkDest* target = ((NodeGraphLinkDest*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateLink'", NULL);
#endif
 {
  NodeGraphLink* tolua_ret = (NodeGraphLink*)  self->CreateLink(source,target);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"NodeGraphLink");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateLink'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveLink of class  NodeGraphLinkPane */
#ifndef TOLUA_DISABLE_tolua_BindTerrainEdit_NodeGraphLinkPane_RemoveLink00
static int tolua_BindTerrainEdit_NodeGraphLinkPane_RemoveLink00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NodeGraphLinkPane",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"NodeGraphLink",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NodeGraphLinkPane* self = (NodeGraphLinkPane*)  tolua_tousertype(tolua_S,1,0);
  NodeGraphLink* link = ((NodeGraphLink*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveLink'", NULL);
#endif
 {
  self->RemoveLink(link);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveLink'.",&tolua_err);
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
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"BrushSettings","BrushSettings","",tolua_collect_BrushSettings);
 #else
 tolua_cclass(tolua_S,"BrushSettings","BrushSettings","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"BrushSettings");
  tolua_variable(tolua_S,"radius",tolua_get_BrushSettings_radius,tolua_set_BrushSettings_radius);
  tolua_variable(tolua_S,"max",tolua_get_BrushSettings_max,tolua_set_BrushSettings_max);
  tolua_variable(tolua_S,"power",tolua_get_BrushSettings_power,tolua_set_BrushSettings_power);
  tolua_variable(tolua_S,"hardness",tolua_get_BrushSettings_hardness,tolua_set_BrushSettings_hardness);
  tolua_function(tolua_S,"new",tolua_BindTerrainEdit_BrushSettings_new00);
  tolua_function(tolua_S,"new_local",tolua_BindTerrainEdit_BrushSettings_new00_local);
  tolua_function(tolua_S,".call",tolua_BindTerrainEdit_BrushSettings_new00_local);
  tolua_function(tolua_S,"new",tolua_BindTerrainEdit_BrushSettings_new01);
  tolua_function(tolua_S,"new_local",tolua_BindTerrainEdit_BrushSettings_new01_local);
  tolua_function(tolua_S,".call",tolua_BindTerrainEdit_BrushSettings_new01_local);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"MaskSettings","MaskSettings","",tolua_collect_MaskSettings);
 #else
 tolua_cclass(tolua_S,"MaskSettings","MaskSettings","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"MaskSettings");
  tolua_variable(tolua_S,"usemask0",tolua_get_MaskSettings_usemask0,tolua_set_MaskSettings_usemask0);
  tolua_variable(tolua_S,"usemask1",tolua_get_MaskSettings_usemask1,tolua_set_MaskSettings_usemask1);
  tolua_variable(tolua_S,"usemask2",tolua_get_MaskSettings_usemask2,tolua_set_MaskSettings_usemask2);
  tolua_variable(tolua_S,"invertmask0",tolua_get_MaskSettings_invertmask0,tolua_set_MaskSettings_invertmask0);
  tolua_variable(tolua_S,"invertmask1",tolua_get_MaskSettings_invertmask1,tolua_set_MaskSettings_invertmask1);
  tolua_variable(tolua_S,"invertmask2",tolua_get_MaskSettings_invertmask2,tolua_set_MaskSettings_invertmask2);
  tolua_function(tolua_S,"new",tolua_BindTerrainEdit_MaskSettings_new00);
  tolua_function(tolua_S,"new_local",tolua_BindTerrainEdit_MaskSettings_new00_local);
  tolua_function(tolua_S,".call",tolua_BindTerrainEdit_MaskSettings_new00_local);
  tolua_function(tolua_S,"new",tolua_BindTerrainEdit_MaskSettings_new01);
  tolua_function(tolua_S,"new_local",tolua_BindTerrainEdit_MaskSettings_new01_local);
  tolua_function(tolua_S,".call",tolua_BindTerrainEdit_MaskSettings_new01_local);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"TerrainEdit","TerrainEdit","",tolua_collect_TerrainEdit);
 #else
 tolua_cclass(tolua_S,"TerrainEdit","TerrainEdit","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"TerrainEdit");
  tolua_function(tolua_S,"new",tolua_BindTerrainEdit_TerrainEdit_new00);
  tolua_function(tolua_S,"new_local",tolua_BindTerrainEdit_TerrainEdit_new00_local);
  tolua_function(tolua_S,".call",tolua_BindTerrainEdit_TerrainEdit_new00_local);
  tolua_function(tolua_S,"delete",tolua_BindTerrainEdit_TerrainEdit_delete00);
  tolua_function(tolua_S,"Initialize",tolua_BindTerrainEdit_TerrainEdit_Initialize00);
  tolua_function(tolua_S,"SetTerrainSize",tolua_BindTerrainEdit_TerrainEdit_SetTerrainSize00);
  tolua_function(tolua_S,"SetBlendMaskSize",tolua_BindTerrainEdit_TerrainEdit_SetBlendMaskSize00);
  tolua_function(tolua_S,"SetTerrainSpacing",tolua_BindTerrainEdit_TerrainEdit_SetTerrainSpacing00);
  tolua_function(tolua_S,"WorldToNormalized",tolua_BindTerrainEdit_TerrainEdit_WorldToNormalized00);
  tolua_function(tolua_S,"NormalizedToWorld",tolua_BindTerrainEdit_TerrainEdit_NormalizedToWorld00);
  tolua_function(tolua_S,"WorldToTerrain",tolua_BindTerrainEdit_TerrainEdit_WorldToTerrain00);
  tolua_function(tolua_S,"WorldToBlend",tolua_BindTerrainEdit_TerrainEdit_WorldToBlend00);
  tolua_function(tolua_S,"TerrainToWorld",tolua_BindTerrainEdit_TerrainEdit_TerrainToWorld00);
  tolua_function(tolua_S,"BlendToWorld",tolua_BindTerrainEdit_TerrainEdit_BlendToWorld00);
  tolua_function(tolua_S,"TerrainToNormalized",tolua_BindTerrainEdit_TerrainEdit_TerrainToNormalized00);
  tolua_function(tolua_S,"BlendToNormalized",tolua_BindTerrainEdit_TerrainEdit_BlendToNormalized00);
  tolua_function(tolua_S,"NormalizedToBlend",tolua_BindTerrainEdit_TerrainEdit_NormalizedToBlend00);
  tolua_function(tolua_S,"NormalizedToTerrain",tolua_BindTerrainEdit_TerrainEdit_NormalizedToTerrain00);
  tolua_function(tolua_S,"SetHeightValue",tolua_BindTerrainEdit_TerrainEdit_SetHeightValue00);
  tolua_function(tolua_S,"GetHeightValue",tolua_BindTerrainEdit_TerrainEdit_GetHeightValue00);
  tolua_function(tolua_S,"GetHeightValue",tolua_BindTerrainEdit_TerrainEdit_GetHeightValue01);
  tolua_function(tolua_S,"GetTerrainWidth",tolua_BindTerrainEdit_TerrainEdit_GetTerrainWidth00);
  tolua_function(tolua_S,"GetTerrainHeight",tolua_BindTerrainEdit_TerrainEdit_GetTerrainHeight00);
  tolua_function(tolua_S,"GetBlendWidth",tolua_BindTerrainEdit_TerrainEdit_GetBlendWidth00);
  tolua_function(tolua_S,"GetBlendHeight",tolua_BindTerrainEdit_TerrainEdit_GetBlendHeight00);
  tolua_function(tolua_S,"SetHeightBuffer",tolua_BindTerrainEdit_TerrainEdit_SetHeightBuffer00);
  tolua_function(tolua_S,"SetLayerBuffer",tolua_BindTerrainEdit_TerrainEdit_SetLayerBuffer00);
  tolua_function(tolua_S,"SetLayerBufferMax",tolua_BindTerrainEdit_TerrainEdit_SetLayerBufferMax00);
  tolua_function(tolua_S,"BlendHeightBuffer",tolua_BindTerrainEdit_TerrainEdit_BlendHeightBuffer00);
  tolua_function(tolua_S,"ApplyHeightBrush",tolua_BindTerrainEdit_TerrainEdit_ApplyHeightBrush00);
  tolua_function(tolua_S,"ApplyBlendBrush",tolua_BindTerrainEdit_TerrainEdit_ApplyBlendBrush00);
  tolua_function(tolua_S,"ApplyMaskBrush",tolua_BindTerrainEdit_TerrainEdit_ApplyMaskBrush00);
  tolua_function(tolua_S,"ApplySmoothBrush",tolua_BindTerrainEdit_TerrainEdit_ApplySmoothBrush00);
  tolua_function(tolua_S,"SetBrushCursorHeight",tolua_BindTerrainEdit_TerrainEdit_SetBrushCursorHeight00);
  tolua_function(tolua_S,"InvertMask",tolua_BindTerrainEdit_TerrainEdit_InvertMask00);
  tolua_function(tolua_S,"ClearMask",tolua_BindTerrainEdit_TerrainEdit_ClearMask00);
  tolua_function(tolua_S,"ClearAllMasks",tolua_BindTerrainEdit_TerrainEdit_ClearAllMasks00);
  tolua_function(tolua_S,"InvertLayer",tolua_BindTerrainEdit_TerrainEdit_InvertLayer00);
  tolua_function(tolua_S,"ClearLayer",tolua_BindTerrainEdit_TerrainEdit_ClearLayer00);
  tolua_function(tolua_S,"ClearAllLayers",tolua_BindTerrainEdit_TerrainEdit_ClearAllLayers00);
  tolua_function(tolua_S,"InvertHeight",tolua_BindTerrainEdit_TerrainEdit_InvertHeight00);
  tolua_function(tolua_S,"ClearHeight",tolua_BindTerrainEdit_TerrainEdit_ClearHeight00);
  tolua_function(tolua_S,"GetMaterial",tolua_BindTerrainEdit_TerrainEdit_GetMaterial00);
  tolua_function(tolua_S,"GetTerrain",tolua_BindTerrainEdit_TerrainEdit_GetTerrain00);
  tolua_function(tolua_S,"SetMaterialSettings",tolua_BindTerrainEdit_TerrainEdit_SetMaterialSettings00);
  tolua_function(tolua_S,"SaveHeightMap",tolua_BindTerrainEdit_TerrainEdit_SaveHeightMap00);
  tolua_function(tolua_S,"SaveBlend0",tolua_BindTerrainEdit_TerrainEdit_SaveBlend000);
  tolua_function(tolua_S,"SaveBlend1",tolua_BindTerrainEdit_TerrainEdit_SaveBlend100);
  tolua_function(tolua_S,"SaveMask",tolua_BindTerrainEdit_TerrainEdit_SaveMask00);
  tolua_function(tolua_S,"LoadHeightMap",tolua_BindTerrainEdit_TerrainEdit_LoadHeightMap00);
  tolua_function(tolua_S,"LoadBlend0",tolua_BindTerrainEdit_TerrainEdit_LoadBlend000);
  tolua_function(tolua_S,"LoadBlend1",tolua_BindTerrainEdit_TerrainEdit_LoadBlend100);
  tolua_function(tolua_S,"LoadMask",tolua_BindTerrainEdit_TerrainEdit_LoadMask00);
  tolua_function(tolua_S,"GetSteepness",tolua_BindTerrainEdit_TerrainEdit_GetSteepness00);
 tolua_endmodule(tolua_S);
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
 tolua_function(tolua_S,"RasterizeTriangle",tolua_BindTerrainEdit_RasterizeTriangle00);
 tolua_function(tolua_S,"RasterizeQuadStrip",tolua_BindTerrainEdit_RasterizeQuadStrip00);
 tolua_function(tolua_S,"BlendHeightWithRasterizedBuffer",tolua_BindTerrainEdit_BlendHeightWithRasterizedBuffer00);
 tolua_function(tolua_S,"BlendColorWithRasterizedBuffer",tolua_BindTerrainEdit_BlendColorWithRasterizedBuffer00);
 tolua_function(tolua_S,"BlendRasterizedBuffer8",tolua_BindTerrainEdit_BlendRasterizedBuffer800);
 tolua_function(tolua_S,"BlendRasterizedBuffer8Max",tolua_BindTerrainEdit_BlendRasterizedBuffer8Max00);
 tolua_function(tolua_S,"TessellateLineList",tolua_BindTerrainEdit_TessellateLineList00);
 tolua_function(tolua_S,"ApplyBedFunction",tolua_BindTerrainEdit_ApplyBedFunction00);
 tolua_function(tolua_S,"BuildQuadStrip",tolua_BindTerrainEdit_BuildQuadStrip00);
 tolua_function(tolua_S,"BuildQuadStripVarying",tolua_BindTerrainEdit_BuildQuadStripVarying00);
 tolua_function(tolua_S,"RenderANLKernelToBuffer",tolua_BindTerrainEdit_RenderANLKernelToBuffer00);
 tolua_function(tolua_S,"RenderANLKernelToImage",tolua_BindTerrainEdit_RenderANLKernelToImage00);
 tolua_function(tolua_S,"SetHeightFromRasterBuffer",tolua_BindTerrainEdit_SetHeightFromRasterBuffer00);
 tolua_function(tolua_S,"CopyImageInto",tolua_BindTerrainEdit_CopyImageInto00);
 tolua_function(tolua_S,"IsPowerOfTwo",tolua_BindTerrainEdit_IsPowerOfTwo00);
 tolua_function(tolua_S,"GetNextImageLevel",tolua_BindTerrainEdit_GetNextImageLevel00);
 tolua_function(tolua_S,"ExtractLayerToBuffer",tolua_BindTerrainEdit_ExtractLayerToBuffer00);
 tolua_function(tolua_S,"GetLayerBlend",tolua_BindTerrainEdit_GetLayerBlend00);
 tolua_function(tolua_S,"SetLayerBlend",tolua_BindTerrainEdit_SetLayerBlend00);
 tolua_function(tolua_S,"LoadImage",tolua_BindTerrainEdit_LoadImage00);
 tolua_function(tolua_S,"DistortBuffer",tolua_BindTerrainEdit_DistortBuffer00);
 tolua_function(tolua_S,"SteepnessTerrain",tolua_BindTerrainEdit_SteepnessTerrain00);
 tolua_cclass(tolua_S,"NodeGraphLinkSource","NodeGraphLinkSource","Button",NULL);
 tolua_beginmodule(tolua_S,"NodeGraphLinkSource");
  tolua_function(tolua_S,"AddLink",tolua_BindTerrainEdit_NodeGraphLinkSource_AddLink00);
  tolua_function(tolua_S,"RemoveLink",tolua_BindTerrainEdit_NodeGraphLinkSource_RemoveLink00);
  tolua_function(tolua_S,"RemoveLink",tolua_BindTerrainEdit_NodeGraphLinkSource_RemoveLink01);
  tolua_function(tolua_S,"GetNumLinks",tolua_BindTerrainEdit_NodeGraphLinkSource_GetNumLinks00);
  tolua_function(tolua_S,"GetLink",tolua_BindTerrainEdit_NodeGraphLinkSource_GetLink00);
  tolua_function(tolua_S,"GetLink",tolua_BindTerrainEdit_NodeGraphLinkSource_GetLink01);
  tolua_function(tolua_S,"SetRoot",tolua_BindTerrainEdit_NodeGraphLinkSource_SetRoot00);
  tolua_function(tolua_S,"ClearRoot",tolua_BindTerrainEdit_NodeGraphLinkSource_ClearRoot00);
  tolua_function(tolua_S,"GetRoot",tolua_BindTerrainEdit_NodeGraphLinkSource_GetRoot00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"NodeGraphLinkDest","NodeGraphLinkDest","Button",NULL);
 tolua_beginmodule(tolua_S,"NodeGraphLinkDest");
  tolua_function(tolua_S,"SetLink",tolua_BindTerrainEdit_NodeGraphLinkDest_SetLink00);
  tolua_function(tolua_S,"ClearLink",tolua_BindTerrainEdit_NodeGraphLinkDest_ClearLink00);
  tolua_function(tolua_S,"GetLink",tolua_BindTerrainEdit_NodeGraphLinkDest_GetLink00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"NodeGraphLink","NodeGraphLink","Object",NULL);
 tolua_beginmodule(tolua_S,"NodeGraphLink");
  tolua_function(tolua_S,"SetSource",tolua_BindTerrainEdit_NodeGraphLink_SetSource00);
  tolua_function(tolua_S,"ClearSource",tolua_BindTerrainEdit_NodeGraphLink_ClearSource00);
  tolua_function(tolua_S,"SetTarget",tolua_BindTerrainEdit_NodeGraphLink_SetTarget00);
  tolua_function(tolua_S,"ClearTarget",tolua_BindTerrainEdit_NodeGraphLink_ClearTarget00);
  tolua_function(tolua_S,"GetSource",tolua_BindTerrainEdit_NodeGraphLink_GetSource00);
  tolua_function(tolua_S,"GetTarget",tolua_BindTerrainEdit_NodeGraphLink_GetTarget00);
  tolua_function(tolua_S,"SetImageRect",tolua_BindTerrainEdit_NodeGraphLink_SetImageRect00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"NodeGraphLinkPane","NodeGraphLinkPane","BorderImage",NULL);
 tolua_beginmodule(tolua_S,"NodeGraphLinkPane");
  tolua_function(tolua_S,"CreateLink",tolua_BindTerrainEdit_NodeGraphLinkPane_CreateLink00);
  tolua_function(tolua_S,"RemoveLink",tolua_BindTerrainEdit_NodeGraphLinkPane_RemoveLink00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_BindTerrainEdit (lua_State* tolua_S) {
 return tolua_BindTerrainEdit_open(tolua_S);
};
#endif

