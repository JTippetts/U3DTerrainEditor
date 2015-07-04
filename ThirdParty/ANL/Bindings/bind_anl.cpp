/*
** Lua binding: bind_anl
*/

#include "tolua.h"

#ifndef __cplusplus
#include <stdlib.h>
#endif
#ifdef __cplusplus
 extern "C" int tolua_bnd_takeownership (lua_State* L); // from tolua_map.c
#else
 int tolua_bnd_takeownership (lua_State* L); /* from tolua_map.c */
#endif
#include <string.h>

/* Exported function */
TOLUA_API int tolua_bind_anl_open (lua_State* tolua_S);
LUALIB_API int luaopen_bind_anl (lua_State* tolua_S);

#include "./ThirdParty/ANL/VM/vm.h"
#include "./ThirdParty/ANL/VM/instruction.h"
#include "./ThirdParty/ANL/VM/kernel.h"
#include "./ThirdParty/ANL/VM/coordinate.h"
#include "./ThirdParty/ANL/VM/random_gen.h"
#include "./ThirdParty/ANL/Imaging/imaging.h"
using namespace anl;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_SRGBA (lua_State* tolua_S)
{
 SRGBA* self = (SRGBA*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_CArray3Drgba (lua_State* tolua_S)
{
 CArray3Drgba* self = (CArray3Drgba*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_CVec3i (lua_State* tolua_S)
{
 CVec3i* self = (CVec3i*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_CVec2i (lua_State* tolua_S)
{
 CVec2i* self = (CVec2i*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_CKernel (lua_State* tolua_S)
{
 CKernel* self = (CKernel*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_CMWC4096 (lua_State* tolua_S)
{
 CMWC4096* self = (CMWC4096*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_MWC256 (lua_State* tolua_S)
{
 MWC256* self = (MWC256*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_SVMOutput (lua_State* tolua_S)
{
 SVMOutput* self = (SVMOutput*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_SMappingRanges (lua_State* tolua_S)
{
 SMappingRanges* self = (SMappingRanges*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_CArray2Drgba (lua_State* tolua_S)
{
 CArray2Drgba* self = (CArray2Drgba*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_CInstructionIndex (lua_State* tolua_S)
{
 CInstructionIndex* self = (CInstructionIndex*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_CArray2Dd (lua_State* tolua_S)
{
 CArray2Dd* self = (CArray2Dd*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_CVec4i (lua_State* tolua_S)
{
 CVec4i* self = (CVec4i*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_CArray3Dd (lua_State* tolua_S)
{
 CArray3Dd* self = (CArray3Dd*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_CNoiseExecutor (lua_State* tolua_S)
{
 CNoiseExecutor* self = (CNoiseExecutor*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_KISS (lua_State* tolua_S)
{
 KISS* self = (KISS*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_Xorshift (lua_State* tolua_S)
{
 Xorshift* self = (Xorshift*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_LCG (lua_State* tolua_S)
{
 LCG* self = (LCG*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_anl_SRGBA (lua_State* tolua_S)
{
 anl::SRGBA* self = (anl::SRGBA*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_CVec2f (lua_State* tolua_S)
{
 CVec2f* self = (CVec2f*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}

static int tolua_collect_CVec3f (lua_State* tolua_S)
{
 CVec3f* self = (CVec3f*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"anl::SMappingRanges");
 tolua_usertype(tolua_S,"CBasePRNG");
 tolua_usertype(tolua_S,"Xorshift");
 tolua_usertype(tolua_S,"CArray3Drgba");
 tolua_usertype(tolua_S,"CCoordinate");
 tolua_usertype(tolua_S,"CVec3i");
 tolua_usertype(tolua_S,"CVec2i");
 tolua_usertype(tolua_S,"CKernel");
 tolua_usertype(tolua_S,"MWC256");
 tolua_usertype(tolua_S,"CMWC4096");
 tolua_usertype(tolua_S,"CNoiseExecutor");
 tolua_usertype(tolua_S,"CArray2Drgba");
 tolua_usertype(tolua_S,"SVMOutput");
 tolua_usertype(tolua_S,"CArray2Dd");
 tolua_usertype(tolua_S,"SMappingRanges");
 tolua_usertype(tolua_S,"CInstructionIndex");
 tolua_usertype(tolua_S,"InstructionListType");
 tolua_usertype(tolua_S,"CVec4i");
 tolua_usertype(tolua_S,"CArray3Dd");
 tolua_usertype(tolua_S,"SRGBA");
 tolua_usertype(tolua_S,"KISS");
 tolua_usertype(tolua_S,"LCG");
 tolua_usertype(tolua_S,"CInstructionListType");
 tolua_usertype(tolua_S,"anl::SRGBA");
 tolua_usertype(tolua_S,"CVec2f");
 tolua_usertype(tolua_S,"CVec3f");
}

/* function: highresTime */
static int tolua_bind_anl_highresTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  double tolua_ret = (double)  highresTime();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'highresTime'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  CVec2f */
static int tolua_bind_anl_CVec2f_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec2f",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  CVec2f* tolua_ret = (CVec2f*)  new CVec2f();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec2f");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  CVec2f */
static int tolua_bind_anl_CVec2f_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CVec2f",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CVec2f* self = (CVec2f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  CVec2f */
static int tolua_bind_anl_CVec2f_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec2f",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  int a = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  CVec2f* tolua_ret = (CVec2f*)  new CVec2f(a);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec2f");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CVec2f_new00(tolua_S);
}

/* method: new of class  CVec2f */
static int tolua_bind_anl_CVec2f_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec2f",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float a = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  CVec2f* tolua_ret = (CVec2f*)  new CVec2f(a);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec2f");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CVec2f_new01(tolua_S);
}

/* method: new of class  CVec2f */
static int tolua_bind_anl_CVec2f_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec2f",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"const CVec2f",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const CVec2f* tvec = ((const CVec2f*)  tolua_tousertype(tolua_S,2,0));
 {
  CVec2f* tolua_ret = (CVec2f*)  new CVec2f(*tvec);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec2f");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CVec2f_new02(tolua_S);
}

/* method: new of class  CVec2f */
static int tolua_bind_anl_CVec2f_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec2f",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const float t1 = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float t2 = ((const float)  tolua_tonumber(tolua_S,3,0));
 {
  CVec2f* tolua_ret = (CVec2f*)  new CVec2f(t1,t2);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec2f");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CVec2f_new03(tolua_S);
}

/* method: dotprod of class  CVec2f */
static int tolua_bind_anl_CVec2f_dotprod00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CVec2f",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"const CVec2f",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CVec2f* self = (CVec2f*)  tolua_tousertype(tolua_S,1,0);
  const CVec2f* tvec = ((const CVec2f*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dotprod'",NULL);
#endif
 {
  const float tolua_ret = (const float)  self->dotprod(*tvec);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dotprod'.",&tolua_err);
 return 0;
#endif
}

/* method: length of class  CVec2f */
static int tolua_bind_anl_CVec2f_length00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CVec2f",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CVec2f* self = (CVec2f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length'",NULL);
#endif
 {
  const float tolua_ret = (const float)  self->length();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length'.",&tolua_err);
 return 0;
#endif
}

/* method: normalize of class  CVec2f */
static int tolua_bind_anl_CVec2f_normalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CVec2f",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CVec2f* self = (CVec2f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'",NULL);
#endif
 {
  self->normalize();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}

/* method: set of class  CVec2f */
static int tolua_bind_anl_CVec2f_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CVec2f",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CVec2f* self = (CVec2f*)  tolua_tousertype(tolua_S,1,0);
  float v1 = ((float)  tolua_tonumber(tolua_S,2,0));
  float v2 = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
#endif
 {
  self->set(v1,v2);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}

/* get function: x of class  CVec2f */
static int tolua_get_CVec2f_CVec2f_x(lua_State* tolua_S)
{
  CVec2f* self = (CVec2f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}

/* set function: x of class  CVec2f */
static int tolua_set_CVec2f_CVec2f_x(lua_State* tolua_S)
{
  CVec2f* self = (CVec2f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((tolua_property float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: y of class  CVec2f */
static int tolua_get_CVec2f_CVec2f_y(lua_State* tolua_S)
{
  CVec2f* self = (CVec2f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}

/* set function: y of class  CVec2f */
static int tolua_set_CVec2f_CVec2f_y(lua_State* tolua_S)
{
  CVec2f* self = (CVec2f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((tolua_property float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: new of class  CVec3f */
static int tolua_bind_anl_CVec3f_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec3f",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  CVec3f* tolua_ret = (CVec3f*)  new CVec3f();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec3f");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  CVec3f */
static int tolua_bind_anl_CVec3f_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CVec3f",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CVec3f* self = (CVec3f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  CVec3f */
static int tolua_bind_anl_CVec3f_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec3f",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  int a = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  CVec3f* tolua_ret = (CVec3f*)  new CVec3f(a);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec3f");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CVec3f_new00(tolua_S);
}

/* method: new of class  CVec3f */
static int tolua_bind_anl_CVec3f_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec3f",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  float a = ((float)  tolua_tonumber(tolua_S,2,0));
 {
  CVec3f* tolua_ret = (CVec3f*)  new CVec3f(a);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec3f");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CVec3f_new01(tolua_S);
}

/* method: new of class  CVec3f */
static int tolua_bind_anl_CVec3f_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec3f",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"const CVec3f",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const CVec3f* tvec = ((const CVec3f*)  tolua_tousertype(tolua_S,2,0));
 {
  CVec3f* tolua_ret = (CVec3f*)  new CVec3f(*tvec);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec3f");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CVec3f_new02(tolua_S);
}

/* method: new of class  CVec3f */
static int tolua_bind_anl_CVec3f_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec3f",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const float t1 = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float t2 = ((const float)  tolua_tonumber(tolua_S,3,0));
  const float t3 = ((const float)  tolua_tonumber(tolua_S,4,0));
 {
  CVec3f* tolua_ret = (CVec3f*)  new CVec3f(t1,t2,t3);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec3f");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CVec3f_new03(tolua_S);
}

/* method: dotprod of class  CVec3f */
static int tolua_bind_anl_CVec3f_dotprod00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CVec3f",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"const CVec3f",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CVec3f* self = (CVec3f*)  tolua_tousertype(tolua_S,1,0);
  const CVec3f* tvec = ((const CVec3f*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dotprod'",NULL);
#endif
 {
  const float tolua_ret = (const float)  self->dotprod(*tvec);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dotprod'.",&tolua_err);
 return 0;
#endif
}

/* method: length of class  CVec3f */
static int tolua_bind_anl_CVec3f_length00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CVec3f",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CVec3f* self = (CVec3f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length'",NULL);
#endif
 {
  const float tolua_ret = (const float)  self->length();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length'.",&tolua_err);
 return 0;
#endif
}

/* method: normalize of class  CVec3f */
static int tolua_bind_anl_CVec3f_normalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CVec3f",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CVec3f* self = (CVec3f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'",NULL);
#endif
 {
  self->normalize();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}

/* method: set of class  CVec3f */
static int tolua_bind_anl_CVec3f_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CVec3f",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CVec3f* self = (CVec3f*)  tolua_tousertype(tolua_S,1,0);
  float v1 = ((float)  tolua_tonumber(tolua_S,2,0));
  float v2 = ((float)  tolua_tonumber(tolua_S,3,0));
  float v3 = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
#endif
 {
  self->set(v1,v2,v3);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}

/* get function: x of class  CVec3f */
static int tolua_get_CVec3f_CVec3f_x(lua_State* tolua_S)
{
  CVec3f* self = (CVec3f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}

/* set function: x of class  CVec3f */
static int tolua_set_CVec3f_CVec3f_x(lua_State* tolua_S)
{
  CVec3f* self = (CVec3f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((tolua_property float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: y of class  CVec3f */
static int tolua_get_CVec3f_CVec3f_y(lua_State* tolua_S)
{
  CVec3f* self = (CVec3f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}

/* set function: y of class  CVec3f */
static int tolua_set_CVec3f_CVec3f_y(lua_State* tolua_S)
{
  CVec3f* self = (CVec3f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((tolua_property float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: z of class  CVec3f */
static int tolua_get_CVec3f_CVec3f_z(lua_State* tolua_S)
{
  CVec3f* self = (CVec3f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}

/* set function: z of class  CVec3f */
static int tolua_set_CVec3f_CVec3f_z(lua_State* tolua_S)
{
  CVec3f* self = (CVec3f*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z = ((tolua_property float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: new of class  CVec2i */
static int tolua_bind_anl_CVec2i_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec2i",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  CVec2i* tolua_ret = (CVec2i*)  new CVec2i();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec2i");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  CVec2i */
static int tolua_bind_anl_CVec2i_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec2i",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  int a = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  CVec2i* tolua_ret = (CVec2i*)  new CVec2i(a);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec2i");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CVec2i_new00(tolua_S);
}

/* method: new of class  CVec2i */
static int tolua_bind_anl_CVec2i_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec2i",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"const CVec2i",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const CVec2i* tvec = ((const CVec2i*)  tolua_tousertype(tolua_S,2,0));
 {
  CVec2i* tolua_ret = (CVec2i*)  new CVec2i(*tvec);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec2i");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CVec2i_new01(tolua_S);
}

/* method: new of class  CVec2i */
static int tolua_bind_anl_CVec2i_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec2i",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const int t1 = ((const int)  tolua_tonumber(tolua_S,2,0));
  const int t2 = ((const int)  tolua_tonumber(tolua_S,3,0));
 {
  CVec2i* tolua_ret = (CVec2i*)  new CVec2i(t1,t2);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec2i");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CVec2i_new02(tolua_S);
}

/* method: delete of class  CVec2i */
static int tolua_bind_anl_CVec2i_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CVec2i",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CVec2i* self = (CVec2i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: x of class  CVec2i */
static int tolua_get_CVec2i_CVec2i_x(lua_State* tolua_S)
{
  CVec2i* self = (CVec2i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}

/* set function: x of class  CVec2i */
static int tolua_set_CVec2i_CVec2i_x(lua_State* tolua_S)
{
  CVec2i* self = (CVec2i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((tolua_property int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: y of class  CVec2i */
static int tolua_get_CVec2i_CVec2i_y(lua_State* tolua_S)
{
  CVec2i* self = (CVec2i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}

/* set function: y of class  CVec2i */
static int tolua_set_CVec2i_CVec2i_y(lua_State* tolua_S)
{
  CVec2i* self = (CVec2i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((tolua_property int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: new of class  CVec3i */
static int tolua_bind_anl_CVec3i_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec3i",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  CVec3i* tolua_ret = (CVec3i*)  new CVec3i();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec3i");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  CVec3i */
static int tolua_bind_anl_CVec3i_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec3i",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  int a = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  CVec3i* tolua_ret = (CVec3i*)  new CVec3i(a);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec3i");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CVec3i_new00(tolua_S);
}

/* method: new of class  CVec3i */
static int tolua_bind_anl_CVec3i_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec3i",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"const CVec3i",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const CVec3i* tvec = ((const CVec3i*)  tolua_tousertype(tolua_S,2,0));
 {
  CVec3i* tolua_ret = (CVec3i*)  new CVec3i(*tvec);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec3i");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CVec3i_new01(tolua_S);
}

/* method: new of class  CVec3i */
static int tolua_bind_anl_CVec3i_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec3i",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const int t1 = ((const int)  tolua_tonumber(tolua_S,2,0));
  const int t2 = ((const int)  tolua_tonumber(tolua_S,3,0));
  const int t3 = ((const int)  tolua_tonumber(tolua_S,4,0));
 {
  CVec3i* tolua_ret = (CVec3i*)  new CVec3i(t1,t2,t3);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec3i");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CVec3i_new02(tolua_S);
}

/* method: delete of class  CVec3i */
static int tolua_bind_anl_CVec3i_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CVec3i",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CVec3i* self = (CVec3i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: x of class  CVec3i */
static int tolua_get_CVec3i_CVec3i_x(lua_State* tolua_S)
{
  CVec3i* self = (CVec3i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}

/* set function: x of class  CVec3i */
static int tolua_set_CVec3i_CVec3i_x(lua_State* tolua_S)
{
  CVec3i* self = (CVec3i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((tolua_property int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: y of class  CVec3i */
static int tolua_get_CVec3i_CVec3i_y(lua_State* tolua_S)
{
  CVec3i* self = (CVec3i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}

/* set function: y of class  CVec3i */
static int tolua_set_CVec3i_CVec3i_y(lua_State* tolua_S)
{
  CVec3i* self = (CVec3i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((tolua_property int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: z of class  CVec3i */
static int tolua_get_CVec3i_CVec3i_z(lua_State* tolua_S)
{
  CVec3i* self = (CVec3i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}

/* set function: z of class  CVec3i */
static int tolua_set_CVec3i_CVec3i_z(lua_State* tolua_S)
{
  CVec3i* self = (CVec3i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z = ((tolua_property int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: new of class  CVec4i */
static int tolua_bind_anl_CVec4i_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec4i",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  CVec4i* tolua_ret = (CVec4i*)  new CVec4i();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec4i");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  CVec4i */
static int tolua_bind_anl_CVec4i_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec4i",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  int a = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  CVec4i* tolua_ret = (CVec4i*)  new CVec4i(a);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec4i");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CVec4i_new00(tolua_S);
}

/* method: new of class  CVec4i */
static int tolua_bind_anl_CVec4i_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec4i",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"const CVec4i",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const CVec4i* tvec = ((const CVec4i*)  tolua_tousertype(tolua_S,2,0));
 {
  CVec4i* tolua_ret = (CVec4i*)  new CVec4i(*tvec);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec4i");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CVec4i_new01(tolua_S);
}

/* method: new of class  CVec4i */
static int tolua_bind_anl_CVec4i_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CVec4i",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const int t1 = ((const int)  tolua_tonumber(tolua_S,2,0));
  const int t2 = ((const int)  tolua_tonumber(tolua_S,3,0));
  const int t3 = ((const int)  tolua_tonumber(tolua_S,4,0));
  const int t4 = ((const int)  tolua_tonumber(tolua_S,5,0));
 {
  CVec4i* tolua_ret = (CVec4i*)  new CVec4i(t1,t2,t3,t4);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CVec4i");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CVec4i_new02(tolua_S);
}

/* method: delete of class  CVec4i */
static int tolua_bind_anl_CVec4i_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CVec4i",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CVec4i* self = (CVec4i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: x of class  CVec4i */
static int tolua_get_CVec4i_CVec4i_x(lua_State* tolua_S)
{
  CVec4i* self = (CVec4i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}

/* set function: x of class  CVec4i */
static int tolua_set_CVec4i_CVec4i_x(lua_State* tolua_S)
{
  CVec4i* self = (CVec4i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((tolua_property int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: y of class  CVec4i */
static int tolua_get_CVec4i_CVec4i_y(lua_State* tolua_S)
{
  CVec4i* self = (CVec4i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}

/* set function: y of class  CVec4i */
static int tolua_set_CVec4i_CVec4i_y(lua_State* tolua_S)
{
  CVec4i* self = (CVec4i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((tolua_property int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: z of class  CVec4i */
static int tolua_get_CVec4i_CVec4i_z(lua_State* tolua_S)
{
  CVec4i* self = (CVec4i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}

/* set function: z of class  CVec4i */
static int tolua_set_CVec4i_CVec4i_z(lua_State* tolua_S)
{
  CVec4i* self = (CVec4i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z = ((tolua_property int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: w of class  CVec4i */
static int tolua_get_CVec4i_CVec4i_w(lua_State* tolua_S)
{
  CVec4i* self = (CVec4i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->w);
 return 1;
}

/* set function: w of class  CVec4i */
static int tolua_set_CVec4i_CVec4i_w(lua_State* tolua_S)
{
  CVec4i* self = (CVec4i*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->w = ((tolua_property int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: get of class  CBasePRNG */
static int tolua_bind_anl_CBasePRNG_get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CBasePRNG",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CBasePRNG* self = (CBasePRNG*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'",NULL);
#endif
 {
  unsigned int tolua_ret = (unsigned int)  self->get();
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

/* method: setSeed of class  CBasePRNG */
static int tolua_bind_anl_CBasePRNG_setSeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CBasePRNG",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CBasePRNG* self = (CBasePRNG*)  tolua_tousertype(tolua_S,1,0);
  unsigned int s = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSeed'",NULL);
#endif
 {
  self->setSeed(s);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSeed'.",&tolua_err);
 return 0;
#endif
}

/* method: setSeedTime of class  CBasePRNG */
static int tolua_bind_anl_CBasePRNG_setSeedTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CBasePRNG",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CBasePRNG* self = (CBasePRNG*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSeedTime'",NULL);
#endif
 {
  self->setSeedTime();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSeedTime'.",&tolua_err);
 return 0;
#endif
}

/* method: getTarget of class  CBasePRNG */
static int tolua_bind_anl_CBasePRNG_getTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CBasePRNG",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CBasePRNG* self = (CBasePRNG*)  tolua_tousertype(tolua_S,1,0);
  unsigned int t = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTarget'",NULL);
#endif
 {
  unsigned int tolua_ret = (unsigned int)  self->getTarget(t);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTarget'.",&tolua_err);
 return 0;
#endif
}

/* method: getRange of class  CBasePRNG */
static int tolua_bind_anl_CBasePRNG_getRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CBasePRNG",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CBasePRNG* self = (CBasePRNG*)  tolua_tousertype(tolua_S,1,0);
  unsigned int low = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int high = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRange'",NULL);
#endif
 {
  unsigned int tolua_ret = (unsigned int)  self->getRange(low,high);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRange'.",&tolua_err);
 return 0;
#endif
}

/* method: get01 of class  CBasePRNG */
static int tolua_bind_anl_CBasePRNG_get0100(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CBasePRNG",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CBasePRNG* self = (CBasePRNG*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get01'",NULL);
#endif
 {
  double tolua_ret = (double)  self->get01();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get01'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  LCG */
static int tolua_bind_anl_LCG_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"LCG",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  LCG* tolua_ret = (LCG*)  new LCG();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"LCG");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  LCG */
static int tolua_bind_anl_LCG_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LCG",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LCG* self = (LCG*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Xorshift */
static int tolua_bind_anl_Xorshift_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Xorshift",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Xorshift* tolua_ret = (Xorshift*)  new Xorshift();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Xorshift");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  Xorshift */
static int tolua_bind_anl_Xorshift_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Xorshift",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Xorshift* self = (Xorshift*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  MWC256 */
static int tolua_bind_anl_MWC256_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"MWC256",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  MWC256* tolua_ret = (MWC256*)  new MWC256();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"MWC256");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  MWC256 */
static int tolua_bind_anl_MWC256_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"MWC256",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  MWC256* self = (MWC256*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  CMWC4096 */
static int tolua_bind_anl_CMWC4096_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CMWC4096",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  CMWC4096* tolua_ret = (CMWC4096*)  new CMWC4096();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CMWC4096");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  CMWC4096 */
static int tolua_bind_anl_CMWC4096_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CMWC4096",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CMWC4096* self = (CMWC4096*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  KISS */
static int tolua_bind_anl_KISS_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"KISS",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  KISS* tolua_ret = (KISS*)  new KISS();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"KISS");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  KISS */
static int tolua_bind_anl_KISS_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"KISS",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  KISS* self = (KISS*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  CCoordinate */
static int tolua_bind_anl_CCoordinate_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CCoordinate",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  CCoordinate* tolua_ret = (CCoordinate*)  new CCoordinate();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCoordinate");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  CCoordinate */
static int tolua_bind_anl_CCoordinate_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CCoordinate",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
 {
  CCoordinate* tolua_ret = (CCoordinate*)  new CCoordinate(x,y);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCoordinate");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_new00(tolua_S);
}

/* method: new of class  CCoordinate */
static int tolua_bind_anl_CCoordinate_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CCoordinate",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  double z = ((double)  tolua_tonumber(tolua_S,4,0));
 {
  CCoordinate* tolua_ret = (CCoordinate*)  new CCoordinate(x,y,z);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCoordinate");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_new01(tolua_S);
}

/* method: new of class  CCoordinate */
static int tolua_bind_anl_CCoordinate_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CCoordinate",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  double z = ((double)  tolua_tonumber(tolua_S,4,0));
  double w = ((double)  tolua_tonumber(tolua_S,5,0));
 {
  CCoordinate* tolua_ret = (CCoordinate*)  new CCoordinate(x,y,z,w);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCoordinate");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_new02(tolua_S);
}

/* method: new of class  CCoordinate */
static int tolua_bind_anl_CCoordinate_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CCoordinate",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,7,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  double z = ((double)  tolua_tonumber(tolua_S,4,0));
  double w = ((double)  tolua_tonumber(tolua_S,5,0));
  double u = ((double)  tolua_tonumber(tolua_S,6,0));
  double v = ((double)  tolua_tonumber(tolua_S,7,0));
 {
  CCoordinate* tolua_ret = (CCoordinate*)  new CCoordinate(x,y,z,w,u,v);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCoordinate");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_new03(tolua_S);
}

/* method: new of class  CCoordinate */
static int tolua_bind_anl_CCoordinate_new05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CCoordinate",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"const CCoordinate",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const CCoordinate* c = ((const CCoordinate*)  tolua_tousertype(tolua_S,2,0));
 {
  CCoordinate* tolua_ret = (CCoordinate*)  new CCoordinate(*c);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCoordinate");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_new04(tolua_S);
}

/* method: set of class  CCoordinate */
static int tolua_bind_anl_CCoordinate_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CCoordinate",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CCoordinate* self = (CCoordinate*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
#endif
 {
  self->set(x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}

/* method: set of class  CCoordinate */
static int tolua_bind_anl_CCoordinate_set01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CCoordinate",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CCoordinate* self = (CCoordinate*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  double z = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
#endif
 {
  self->set(x,y,z);
 }
 }
 return 0;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_set00(tolua_S);
}

/* method: set of class  CCoordinate */
static int tolua_bind_anl_CCoordinate_set02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CCoordinate",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CCoordinate* self = (CCoordinate*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  double z = ((double)  tolua_tonumber(tolua_S,4,0));
  double w = ((double)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
#endif
 {
  self->set(x,y,z,w);
 }
 }
 return 0;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_set01(tolua_S);
}

/* method: set of class  CCoordinate */
static int tolua_bind_anl_CCoordinate_set03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CCoordinate",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,7,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CCoordinate* self = (CCoordinate*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  double z = ((double)  tolua_tonumber(tolua_S,4,0));
  double w = ((double)  tolua_tonumber(tolua_S,5,0));
  double u = ((double)  tolua_tonumber(tolua_S,6,0));
  double v = ((double)  tolua_tonumber(tolua_S,7,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
#endif
 {
  self->set(x,y,z,w,u,v);
 }
 }
 return 0;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_set02(tolua_S);
}

/* method: new of class  CKernel */
static int tolua_bind_anl_CKernel_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  CKernel* tolua_ret = (CKernel*)  new CKernel();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CKernel");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  CKernel */
static int tolua_bind_anl_CKernel_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: constant of class  CKernel */
static int tolua_bind_anl_CKernel_constant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  double val = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'constant'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->constant(val);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'constant'.",&tolua_err);
 return 0;
#endif
}

/* method: valueBasis of class  CKernel */
static int tolua_bind_anl_CKernel_valueBasis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex interpindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  unsigned int seed = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'valueBasis'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->valueBasis(interpindex,seed);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'valueBasis'.",&tolua_err);
 return 0;
#endif
}

/* method: gradientBasis of class  CKernel */
static int tolua_bind_anl_CKernel_gradientBasis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex interpindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  unsigned int seed = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'gradientBasis'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->gradientBasis(interpindex,seed);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'gradientBasis'.",&tolua_err);
 return 0;
#endif
}

/* method: simplexBasis of class  CKernel */
static int tolua_bind_anl_CKernel_simplexBasis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  unsigned int seed = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'simplexBasis'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->simplexBasis(seed);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'simplexBasis'.",&tolua_err);
 return 0;
#endif
}

/* method: cellularBasis of class  CKernel */
static int tolua_bind_anl_CKernel_cellularBasis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,6,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,7,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,8,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,9,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,10,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,11,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,12,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex f1 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex f2 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex f3 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex f4 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
  CInstructionIndex d1 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,6,0));
  CInstructionIndex d2 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,7,0));
  CInstructionIndex d3 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,8,0));
  CInstructionIndex d4 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,9,0));
  CInstructionIndex dist = *((CInstructionIndex*)  tolua_tousertype(tolua_S,10,0));
  unsigned int seed = ((unsigned int)  tolua_tonumber(tolua_S,11,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cellularBasis'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->cellularBasis(f1,f2,f3,f4,d1,d2,d3,d4,dist,seed);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cellularBasis'.",&tolua_err);
 return 0;
#endif
}

/* method: add of class  CKernel */
static int tolua_bind_anl_CKernel_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex s1index = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex s2index = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->add(s1index,s2index);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}

/* method: subtract of class  CKernel */
static int tolua_bind_anl_CKernel_subtract00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex s1 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex s2 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'subtract'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->subtract(s1,s2);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'subtract'.",&tolua_err);
 return 0;
#endif
}

/* method: multiply of class  CKernel */
static int tolua_bind_anl_CKernel_multiply00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex s1index = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex s2index = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'multiply'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->multiply(s1index,s2index);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'multiply'.",&tolua_err);
 return 0;
#endif
}

/* method: divide of class  CKernel */
static int tolua_bind_anl_CKernel_divide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex s1 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex s2 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'divide'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->divide(s1,s2);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'divide'.",&tolua_err);
 return 0;
#endif
}

/* method: maximum of class  CKernel */
static int tolua_bind_anl_CKernel_maximum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex s1index = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex s2index = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'maximum'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->maximum(s1index,s2index);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maximum'.",&tolua_err);
 return 0;
#endif
}

/* method: minimum of class  CKernel */
static int tolua_bind_anl_CKernel_minimum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex s1index = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex s2index = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'minimum'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->minimum(s1index,s2index);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'minimum'.",&tolua_err);
 return 0;
#endif
}

/* method: abs of class  CKernel */
static int tolua_bind_anl_CKernel_abs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex sindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'abs'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->abs(sindex);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'abs'.",&tolua_err);
 return 0;
#endif
}

/* method: pow of class  CKernel */
static int tolua_bind_anl_CKernel_pow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex s1 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex s2 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pow'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->pow(s1,s2);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pow'.",&tolua_err);
 return 0;
#endif
}

/* method: bias of class  CKernel */
static int tolua_bind_anl_CKernel_bias00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex s1 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex s2 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'bias'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->bias(s1,s2);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bias'.",&tolua_err);
 return 0;
#endif
}

/* method: gain of class  CKernel */
static int tolua_bind_anl_CKernel_gain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex s1 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex s2 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'gain'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->gain(s1,s2);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'gain'.",&tolua_err);
 return 0;
#endif
}

/* method: scaleDomain of class  CKernel */
static int tolua_bind_anl_CKernel_scaleDomain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex srcindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex xindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex yindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleDomain'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->scaleDomain(srcindex,xindex,yindex);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scaleDomain'.",&tolua_err);
 return 0;
#endif
}

/* method: scaleDomain of class  CKernel */
static int tolua_bind_anl_CKernel_scaleDomain01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex srcindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex xindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex yindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex zindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleDomain'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->scaleDomain(srcindex,xindex,yindex,zindex);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CKernel_scaleDomain00(tolua_S);
}

/* method: scaleDomain of class  CKernel */
static int tolua_bind_anl_CKernel_scaleDomain02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,6,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex srcindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex xindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex yindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex zindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
  CInstructionIndex windex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleDomain'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->scaleDomain(srcindex,xindex,yindex,zindex,windex);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CKernel_scaleDomain01(tolua_S);
}

/* method: scaleDomain of class  CKernel */
static int tolua_bind_anl_CKernel_scaleDomain03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,6,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,7,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,8,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex srcindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex xindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex yindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex zindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
  CInstructionIndex windex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,6,0));
  CInstructionIndex uindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,7,0));
  CInstructionIndex vindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,8,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleDomain'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->scaleDomain(srcindex,xindex,yindex,zindex,windex,uindex,vindex);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CKernel_scaleDomain02(tolua_S);
}

/* method: scaleX of class  CKernel */
static int tolua_bind_anl_CKernel_scaleX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex scale = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleX'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->scaleX(src,scale);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scaleX'.",&tolua_err);
 return 0;
#endif
}

/* method: scaleY of class  CKernel */
static int tolua_bind_anl_CKernel_scaleY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex scale = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleY'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->scaleY(src,scale);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scaleY'.",&tolua_err);
 return 0;
#endif
}

/* method: scaleZ of class  CKernel */
static int tolua_bind_anl_CKernel_scaleZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex scale = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleZ'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->scaleZ(src,scale);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scaleZ'.",&tolua_err);
 return 0;
#endif
}

/* method: scaleW of class  CKernel */
static int tolua_bind_anl_CKernel_scaleW00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex scale = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleW'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->scaleW(src,scale);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scaleW'.",&tolua_err);
 return 0;
#endif
}

/* method: scaleU of class  CKernel */
static int tolua_bind_anl_CKernel_scaleU00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex scale = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleU'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->scaleU(src,scale);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scaleU'.",&tolua_err);
 return 0;
#endif
}

/* method: scaleV of class  CKernel */
static int tolua_bind_anl_CKernel_scaleV00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex scale = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleV'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->scaleV(src,scale);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scaleV'.",&tolua_err);
 return 0;
#endif
}

/* method: translateDomain of class  CKernel */
static int tolua_bind_anl_CKernel_translateDomain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex srcindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex xindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex yindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateDomain'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->translateDomain(srcindex,xindex,yindex);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'translateDomain'.",&tolua_err);
 return 0;
#endif
}

/* method: translateDomain of class  CKernel */
static int tolua_bind_anl_CKernel_translateDomain01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex srcindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex xindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex yindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex zindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateDomain'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->translateDomain(srcindex,xindex,yindex,zindex);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CKernel_translateDomain00(tolua_S);
}

/* method: translateDomain of class  CKernel */
static int tolua_bind_anl_CKernel_translateDomain02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,6,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex srcindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex xindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex yindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex zindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
  CInstructionIndex windex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateDomain'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->translateDomain(srcindex,xindex,yindex,zindex,windex);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CKernel_translateDomain01(tolua_S);
}

/* method: translateDomain of class  CKernel */
static int tolua_bind_anl_CKernel_translateDomain03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,6,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,7,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,8,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex srcindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex xindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex yindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex zindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
  CInstructionIndex windex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,6,0));
  CInstructionIndex uindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,7,0));
  CInstructionIndex vindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,8,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateDomain'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->translateDomain(srcindex,xindex,yindex,zindex,windex,uindex,vindex);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CKernel_translateDomain02(tolua_S);
}

/* method: translateX of class  CKernel */
static int tolua_bind_anl_CKernel_translateX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex trans = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateX'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->translateX(src,trans);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'translateX'.",&tolua_err);
 return 0;
#endif
}

/* method: translateY of class  CKernel */
static int tolua_bind_anl_CKernel_translateY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex trans = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateY'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->translateY(src,trans);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'translateY'.",&tolua_err);
 return 0;
#endif
}

/* method: translateZ of class  CKernel */
static int tolua_bind_anl_CKernel_translateZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex trans = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateZ'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->translateZ(src,trans);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'translateZ'.",&tolua_err);
 return 0;
#endif
}

/* method: translateW of class  CKernel */
static int tolua_bind_anl_CKernel_translateW00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex trans = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateW'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->translateW(src,trans);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'translateW'.",&tolua_err);
 return 0;
#endif
}

/* method: translateU of class  CKernel */
static int tolua_bind_anl_CKernel_translateU00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex trans = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateU'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->translateU(src,trans);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'translateU'.",&tolua_err);
 return 0;
#endif
}

/* method: translateV of class  CKernel */
static int tolua_bind_anl_CKernel_translateV00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex trans = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateV'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->translateV(src,trans);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'translateV'.",&tolua_err);
 return 0;
#endif
}

/* method: rotateDomain of class  CKernel */
static int tolua_bind_anl_CKernel_rotateDomain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,6,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex angle = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex ax = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex ay = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
  CInstructionIndex az = *((CInstructionIndex*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateDomain'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->rotateDomain(src,angle,ax,ay,az);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateDomain'.",&tolua_err);
 return 0;
#endif
}

/* method: addSequence of class  CKernel */
static int tolua_bind_anl_CKernel_addSequence00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex baseindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  unsigned int number = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int stride = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addSequence'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->addSequence(baseindex,number,stride);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addSequence'.",&tolua_err);
 return 0;
#endif
}

/* method: multiplySequence of class  CKernel */
static int tolua_bind_anl_CKernel_multiplySequence00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex baseindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  unsigned int number = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int stride = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'multiplySequence'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->multiplySequence(baseindex,number,stride);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'multiplySequence'.",&tolua_err);
 return 0;
#endif
}

/* method: maxSequence of class  CKernel */
static int tolua_bind_anl_CKernel_maxSequence00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex baseindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  unsigned int number = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int stride = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'maxSequence'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->maxSequence(baseindex,number,stride);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'maxSequence'.",&tolua_err);
 return 0;
#endif
}

/* method: minSequence of class  CKernel */
static int tolua_bind_anl_CKernel_minSequence00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex baseindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  unsigned int number = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int stride = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'minSequence'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->minSequence(baseindex,number,stride);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'minSequence'.",&tolua_err);
 return 0;
#endif
}

/* method: blend of class  CKernel */
static int tolua_bind_anl_CKernel_blend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex low = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex high = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex control = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'blend'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->blend(low,high,control);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'blend'.",&tolua_err);
 return 0;
#endif
}

/* method: select of class  CKernel */
static int tolua_bind_anl_CKernel_select00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,6,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex low = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex high = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex control = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex threshold = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
  CInstructionIndex falloff = *((CInstructionIndex*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'select'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->select(low,high,control,threshold,falloff);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'select'.",&tolua_err);
 return 0;
#endif
}

/* method: clamp of class  CKernel */
static int tolua_bind_anl_CKernel_clamp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex low = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex high = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clamp'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->clamp(src,low,high);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clamp'.",&tolua_err);
 return 0;
#endif
}

/* method: cos of class  CKernel */
static int tolua_bind_anl_CKernel_cos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cos'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->cos(src);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cos'.",&tolua_err);
 return 0;
#endif
}

/* method: sin of class  CKernel */
static int tolua_bind_anl_CKernel_sin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sin'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->sin(src);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sin'.",&tolua_err);
 return 0;
#endif
}

/* method: tan of class  CKernel */
static int tolua_bind_anl_CKernel_tan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'tan'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->tan(src);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tan'.",&tolua_err);
 return 0;
#endif
}

/* method: acos of class  CKernel */
static int tolua_bind_anl_CKernel_acos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'acos'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->acos(src);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'acos'.",&tolua_err);
 return 0;
#endif
}

/* method: asin of class  CKernel */
static int tolua_bind_anl_CKernel_asin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'asin'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->asin(src);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'asin'.",&tolua_err);
 return 0;
#endif
}

/* method: atan of class  CKernel */
static int tolua_bind_anl_CKernel_atan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'atan'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->atan(src);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'atan'.",&tolua_err);
 return 0;
#endif
}

/* method: tiers of class  CKernel */
static int tolua_bind_anl_CKernel_tiers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex numtiers = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'tiers'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->tiers(src,numtiers);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'tiers'.",&tolua_err);
 return 0;
#endif
}

/* method: smoothTiers of class  CKernel */
static int tolua_bind_anl_CKernel_smoothTiers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex numtiers = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'smoothTiers'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->smoothTiers(src,numtiers);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'smoothTiers'.",&tolua_err);
 return 0;
#endif
}

/* method: x of class  CKernel */
static int tolua_bind_anl_CKernel_x00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'x'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->x();
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'x'.",&tolua_err);
 return 0;
#endif
}

/* method: y of class  CKernel */
static int tolua_bind_anl_CKernel_y00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'y'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->y();
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'y'.",&tolua_err);
 return 0;
#endif
}

/* method: z of class  CKernel */
static int tolua_bind_anl_CKernel_z00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'z'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->z();
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'z'.",&tolua_err);
 return 0;
#endif
}

/* method: w of class  CKernel */
static int tolua_bind_anl_CKernel_w00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'w'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->w();
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'w'.",&tolua_err);
 return 0;
#endif
}

/* method: u of class  CKernel */
static int tolua_bind_anl_CKernel_u00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'u'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->u();
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'u'.",&tolua_err);
 return 0;
#endif
}

/* method: v of class  CKernel */
static int tolua_bind_anl_CKernel_v00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'v'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->v();
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'v'.",&tolua_err);
 return 0;
#endif
}

/* method: radial of class  CKernel */
static int tolua_bind_anl_CKernel_radial00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'radial'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->radial();
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'radial'.",&tolua_err);
 return 0;
#endif
}

/* method: hexTile of class  CKernel */
static int tolua_bind_anl_CKernel_hexTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  unsigned int seed = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hexTile'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->hexTile(seed);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hexTile'.",&tolua_err);
 return 0;
#endif
}

/* method: hexBump of class  CKernel */
static int tolua_bind_anl_CKernel_hexBump00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hexBump'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->hexBump();
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hexBump'.",&tolua_err);
 return 0;
#endif
}

/* method: combineRGBA of class  CKernel */
static int tolua_bind_anl_CKernel_combineRGBA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex r = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex g = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex b = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex a = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'combineRGBA'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->combineRGBA(r,g,b,a);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'combineRGBA'.",&tolua_err);
 return 0;
#endif
}

/* method: scaleOffset of class  CKernel */
static int tolua_bind_anl_CKernel_scaleOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  double scale = ((double)  tolua_tonumber(tolua_S,3,0));
  double offset = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleOffset'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->scaleOffset(src,scale,offset);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scaleOffset'.",&tolua_err);
 return 0;
#endif
}

/* method: simpleFractalLayer of class  CKernel */
static int tolua_bind_anl_CKernel_simpleFractalLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isboolean(tolua_S,7,1,&tolua_err) || 
 !tolua_isnumber(tolua_S,8,1,&tolua_err) || 
 !tolua_isnumber(tolua_S,9,1,&tolua_err) || 
 !tolua_isnumber(tolua_S,10,1,&tolua_err) || 
 !tolua_isnumber(tolua_S,11,1,&tolua_err) || 
 !tolua_isnoobj(tolua_S,12,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  unsigned int basistype = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  CInstructionIndex interptypeindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  double layerscale = ((double)  tolua_tonumber(tolua_S,4,0));
  double layerfreq = ((double)  tolua_tonumber(tolua_S,5,0));
  unsigned int seed = ((unsigned int)  tolua_tonumber(tolua_S,6,0));
  bool rot = ((bool)  tolua_toboolean(tolua_S,7,true));
  double angle = ((double)  tolua_tonumber(tolua_S,8,0.5));
  double ax = ((double)  tolua_tonumber(tolua_S,9,0));
  double ay = ((double)  tolua_tonumber(tolua_S,10,0));
  double az = ((double)  tolua_tonumber(tolua_S,11,1));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'simpleFractalLayer'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->simpleFractalLayer(basistype,interptypeindex,layerscale,layerfreq,seed,rot,angle,ax,ay,az);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'simpleFractalLayer'.",&tolua_err);
 return 0;
#endif
}

/* method: simpleRidgedLayer of class  CKernel */
static int tolua_bind_anl_CKernel_simpleRidgedLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isboolean(tolua_S,7,1,&tolua_err) || 
 !tolua_isnumber(tolua_S,8,1,&tolua_err) || 
 !tolua_isnumber(tolua_S,9,1,&tolua_err) || 
 !tolua_isnumber(tolua_S,10,1,&tolua_err) || 
 !tolua_isnumber(tolua_S,11,1,&tolua_err) || 
 !tolua_isnoobj(tolua_S,12,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  unsigned int basistype = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  CInstructionIndex interptypeindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  double layerscale = ((double)  tolua_tonumber(tolua_S,4,0));
  double layerfreq = ((double)  tolua_tonumber(tolua_S,5,0));
  unsigned int seed = ((unsigned int)  tolua_tonumber(tolua_S,6,0));
  bool rot = ((bool)  tolua_toboolean(tolua_S,7,true));
  double angle = ((double)  tolua_tonumber(tolua_S,8,0.5));
  double ax = ((double)  tolua_tonumber(tolua_S,9,0));
  double ay = ((double)  tolua_tonumber(tolua_S,10,0));
  double az = ((double)  tolua_tonumber(tolua_S,11,1));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'simpleRidgedLayer'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->simpleRidgedLayer(basistype,interptypeindex,layerscale,layerfreq,seed,rot,angle,ax,ay,az);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'simpleRidgedLayer'.",&tolua_err);
 return 0;
#endif
}

/* method: simplefBm of class  CKernel */
static int tolua_bind_anl_CKernel_simplefBm00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isboolean(tolua_S,7,1,&tolua_err) || 
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  unsigned int basistype = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int interptype = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int numoctaves = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  double frequency = ((double)  tolua_tonumber(tolua_S,5,0));
  unsigned int seed = ((unsigned int)  tolua_tonumber(tolua_S,6,0));
  bool rot = ((bool)  tolua_toboolean(tolua_S,7,true));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'simplefBm'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->simplefBm(basistype,interptype,numoctaves,frequency,seed,rot);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'simplefBm'.",&tolua_err);
 return 0;
#endif
}

/* method: simpleRidgedMultifractal of class  CKernel */
static int tolua_bind_anl_CKernel_simpleRidgedMultifractal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isboolean(tolua_S,7,1,&tolua_err) || 
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  unsigned int basistype = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int interptype = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int numoctaves = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  double frequency = ((double)  tolua_tonumber(tolua_S,5,0));
  unsigned int seed = ((unsigned int)  tolua_tonumber(tolua_S,6,0));
  bool rot = ((bool)  tolua_toboolean(tolua_S,7,true));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'simpleRidgedMultifractal'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->simpleRidgedMultifractal(basistype,interptype,numoctaves,frequency,seed,rot);
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'simpleRidgedMultifractal'.",&tolua_err);
 return 0;
#endif
}

/* method: getKernel of class  CKernel */
static int tolua_bind_anl_CKernel_getKernel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getKernel'",NULL);
#endif
 {
  InstructionListType* tolua_ret = (InstructionListType*)  self->getKernel();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"InstructionListType");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getKernel'.",&tolua_err);
 return 0;
#endif
}

/* method: lastIndex of class  CKernel */
static int tolua_bind_anl_CKernel_lastIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lastIndex'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->lastIndex();
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lastIndex'.",&tolua_err);
 return 0;
#endif
}

/* method: nextIndex of class  CKernel */
static int tolua_bind_anl_CKernel_nextIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'nextIndex'",NULL);
#endif
 {
  CInstructionIndex tolua_ret =  self->nextIndex();
 {
#ifdef __cplusplus
 void* tolua_obj = new CInstructionIndex(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_CInstructionIndex),"CInstructionIndex");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"CInstructionIndex");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'nextIndex'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  SRGBA */
static int tolua_bind_anl_SRGBA_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SRGBA",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  SRGBA* tolua_ret = (SRGBA*)  new SRGBA();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"SRGBA");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  SRGBA */
static int tolua_bind_anl_SRGBA_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SRGBA",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  int a = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  SRGBA* tolua_ret = (SRGBA*)  new SRGBA(a);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"SRGBA");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_SRGBA_new00(tolua_S);
}

/* method: new of class  SRGBA */
static int tolua_bind_anl_SRGBA_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SRGBA",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"const SRGBA",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const SRGBA* tvec = ((const SRGBA*)  tolua_tousertype(tolua_S,2,0));
 {
  SRGBA* tolua_ret = (SRGBA*)  new SRGBA(*tvec);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"SRGBA");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_SRGBA_new01(tolua_S);
}

/* method: new of class  SRGBA */
static int tolua_bind_anl_SRGBA_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SRGBA",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const float t1 = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float t2 = ((const float)  tolua_tonumber(tolua_S,3,0));
  const float t3 = ((const float)  tolua_tonumber(tolua_S,4,0));
  const float t4 = ((const float)  tolua_tonumber(tolua_S,5,0));
 {
  SRGBA* tolua_ret = (SRGBA*)  new SRGBA(t1,t2,t3,t4);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"SRGBA");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_SRGBA_new02(tolua_S);
}

/* method: delete of class  SRGBA */
static int tolua_bind_anl_SRGBA_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SRGBA",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SRGBA* self = (SRGBA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: r of class  SRGBA */
static int tolua_get_SRGBA_SRGBA_r(lua_State* tolua_S)
{
  SRGBA* self = (SRGBA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->r);
 return 1;
}

/* set function: r of class  SRGBA */
static int tolua_set_SRGBA_SRGBA_r(lua_State* tolua_S)
{
  SRGBA* self = (SRGBA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->r = ((float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: g of class  SRGBA */
static int tolua_get_SRGBA_SRGBA_g(lua_State* tolua_S)
{
  SRGBA* self = (SRGBA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->g);
 return 1;
}

/* set function: g of class  SRGBA */
static int tolua_set_SRGBA_SRGBA_g(lua_State* tolua_S)
{
  SRGBA* self = (SRGBA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->g = ((float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: b of class  SRGBA */
static int tolua_get_SRGBA_SRGBA_b(lua_State* tolua_S)
{
  SRGBA* self = (SRGBA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->b);
 return 1;
}

/* set function: b of class  SRGBA */
static int tolua_set_SRGBA_SRGBA_b(lua_State* tolua_S)
{
  SRGBA* self = (SRGBA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->b = ((float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: a of class  SRGBA */
static int tolua_get_SRGBA_SRGBA_a(lua_State* tolua_S)
{
  SRGBA* self = (SRGBA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->a);
 return 1;
}

/* set function: a of class  SRGBA */
static int tolua_set_SRGBA_SRGBA_a(lua_State* tolua_S)
{
  SRGBA* self = (SRGBA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->a = ((float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: outfloat_ of class  SVMOutput */
static int tolua_get_SVMOutput_SVMOutput_outfloat_(lua_State* tolua_S)
{
  SVMOutput* self = (SVMOutput*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'outfloat_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->outfloat_);
 return 1;
}

/* set function: outfloat_ of class  SVMOutput */
static int tolua_set_SVMOutput_SVMOutput_outfloat_(lua_State* tolua_S)
{
  SVMOutput* self = (SVMOutput*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'outfloat_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->outfloat_ = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: outrgba_ of class  SVMOutput */
static int tolua_get_SVMOutput_SVMOutput_outrgba_(lua_State* tolua_S)
{
  SVMOutput* self = (SVMOutput*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'outrgba_'",NULL);
#endif
 tolua_pushusertype(tolua_S,(void*)&self->outrgba_,"SRGBA");
 return 1;
}

/* set function: outrgba_ of class  SVMOutput */
static int tolua_set_SVMOutput_SVMOutput_outrgba_(lua_State* tolua_S)
{
  SVMOutput* self = (SVMOutput*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'outrgba_'",NULL);
 if (!tolua_isusertype(tolua_S,2,"SRGBA",0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->outrgba_ = *((SRGBA*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* method: new of class  SVMOutput */
static int tolua_bind_anl_SVMOutput_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SVMOutput",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  SVMOutput* tolua_ret = (SVMOutput*)  new SVMOutput();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"SVMOutput");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  SVMOutput */
static int tolua_bind_anl_SVMOutput_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SVMOutput",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SVMOutput* self = (SVMOutput*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  CNoiseExecutor */
static int tolua_bind_anl_CNoiseExecutor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CNoiseExecutor",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CKernel",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* kernel = ((CKernel*)  tolua_tousertype(tolua_S,2,0));
 {
  CNoiseExecutor* tolua_ret = (CNoiseExecutor*)  new CNoiseExecutor(kernel);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CNoiseExecutor");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  CNoiseExecutor */
static int tolua_bind_anl_CNoiseExecutor_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CNoiseExecutor",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CNoiseExecutor* self = (CNoiseExecutor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: evaluate of class  CNoiseExecutor */
static int tolua_bind_anl_CNoiseExecutor_evaluate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CNoiseExecutor",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CCoordinate",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CNoiseExecutor* self = (CNoiseExecutor*)  tolua_tousertype(tolua_S,1,0);
  CCoordinate* coord = ((CCoordinate*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'evaluate'",NULL);
#endif
 {
  SVMOutput tolua_ret =  self->evaluate(*coord);
 {
#ifdef __cplusplus
 void* tolua_obj = new SVMOutput(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_SVMOutput),"SVMOutput");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(SVMOutput));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"SVMOutput");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'evaluate'.",&tolua_err);
 return 0;
#endif
}

/* method: evaluateAt of class  CNoiseExecutor */
static int tolua_bind_anl_CNoiseExecutor_evaluateAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CNoiseExecutor",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CCoordinate",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CNoiseExecutor* self = (CNoiseExecutor*)  tolua_tousertype(tolua_S,1,0);
  CCoordinate* coord = ((CCoordinate*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex index = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'evaluateAt'",NULL);
#endif
 {
  SVMOutput tolua_ret =  self->evaluateAt(*coord,index);
 {
#ifdef __cplusplus
 void* tolua_obj = new SVMOutput(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_SVMOutput),"SVMOutput");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(SVMOutput));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"SVMOutput");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'evaluateAt'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  SMappingRanges */
static int tolua_bind_anl_SMappingRanges_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SMappingRanges",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  SMappingRanges* tolua_ret = (SMappingRanges*)  new SMappingRanges();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"SMappingRanges");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  SMappingRanges */
static int tolua_bind_anl_SMappingRanges_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SMappingRanges",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"SMappingRanges",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  SMappingRanges* rhs = ((SMappingRanges*)  tolua_tousertype(tolua_S,2,0));
 {
  SMappingRanges* tolua_ret = (SMappingRanges*)  new SMappingRanges(*rhs);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"SMappingRanges");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_SMappingRanges_new00(tolua_S);
}

/* method: new of class  SMappingRanges */
static int tolua_bind_anl_SMappingRanges_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SMappingRanges",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"const anl::SMappingRanges",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const anl::SMappingRanges* rhs = ((const anl::SMappingRanges*)  tolua_tousertype(tolua_S,2,0));
 {
  SMappingRanges* tolua_ret = (SMappingRanges*)  new SMappingRanges(*rhs);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"SMappingRanges");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_SMappingRanges_new01(tolua_S);
}

/* method: new of class  SMappingRanges */
static int tolua_bind_anl_SMappingRanges_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SMappingRanges",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,1,&tolua_err) || 
 !tolua_isnumber(tolua_S,7,1,&tolua_err) || 
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  double x0 = ((double)  tolua_tonumber(tolua_S,2,0));
  double x1 = ((double)  tolua_tonumber(tolua_S,3,0));
  double y0 = ((double)  tolua_tonumber(tolua_S,4,0));
  double y1 = ((double)  tolua_tonumber(tolua_S,5,0));
  double z0 = ((double)  tolua_tonumber(tolua_S,6,0.0));
  double z1 = ((double)  tolua_tonumber(tolua_S,7,1.0));
 {
  SMappingRanges* tolua_ret = (SMappingRanges*)  new SMappingRanges(x0,x1,y0,y1,z0,z1);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"SMappingRanges");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_SMappingRanges_new02(tolua_S);
}

/* method: delete of class  SMappingRanges */
static int tolua_bind_anl_SMappingRanges_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"SMappingRanges",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: mapx0 of class  SMappingRanges */
static int tolua_get_SMappingRanges_SMappingRanges_mapx0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapx0'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->mapx0);
 return 1;
}

/* set function: mapx0 of class  SMappingRanges */
static int tolua_set_SMappingRanges_SMappingRanges_mapx0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapx0'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mapx0 = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: mapy0 of class  SMappingRanges */
static int tolua_get_SMappingRanges_SMappingRanges_mapy0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapy0'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->mapy0);
 return 1;
}

/* set function: mapy0 of class  SMappingRanges */
static int tolua_set_SMappingRanges_SMappingRanges_mapy0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapy0'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mapy0 = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: mapz0 of class  SMappingRanges */
static int tolua_get_SMappingRanges_SMappingRanges_mapz0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapz0'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->mapz0);
 return 1;
}

/* set function: mapz0 of class  SMappingRanges */
static int tolua_set_SMappingRanges_SMappingRanges_mapz0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapz0'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mapz0 = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: mapx1 of class  SMappingRanges */
static int tolua_get_SMappingRanges_SMappingRanges_mapx1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapx1'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->mapx1);
 return 1;
}

/* set function: mapx1 of class  SMappingRanges */
static int tolua_set_SMappingRanges_SMappingRanges_mapx1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapx1'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mapx1 = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: mapy1 of class  SMappingRanges */
static int tolua_get_SMappingRanges_SMappingRanges_mapy1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapy1'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->mapy1);
 return 1;
}

/* set function: mapy1 of class  SMappingRanges */
static int tolua_set_SMappingRanges_SMappingRanges_mapy1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapy1'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mapy1 = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: mapz1 of class  SMappingRanges */
static int tolua_get_SMappingRanges_SMappingRanges_mapz1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapz1'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->mapz1);
 return 1;
}

/* set function: mapz1 of class  SMappingRanges */
static int tolua_set_SMappingRanges_SMappingRanges_mapz1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapz1'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mapz1 = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: loopx0 of class  SMappingRanges */
static int tolua_get_SMappingRanges_SMappingRanges_loopx0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopx0'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->loopx0);
 return 1;
}

/* set function: loopx0 of class  SMappingRanges */
static int tolua_set_SMappingRanges_SMappingRanges_loopx0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopx0'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->loopx0 = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: loopy0 of class  SMappingRanges */
static int tolua_get_SMappingRanges_SMappingRanges_loopy0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopy0'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->loopy0);
 return 1;
}

/* set function: loopy0 of class  SMappingRanges */
static int tolua_set_SMappingRanges_SMappingRanges_loopy0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopy0'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->loopy0 = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: loopz0 of class  SMappingRanges */
static int tolua_get_SMappingRanges_SMappingRanges_loopz0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopz0'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->loopz0);
 return 1;
}

/* set function: loopz0 of class  SMappingRanges */
static int tolua_set_SMappingRanges_SMappingRanges_loopz0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopz0'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->loopz0 = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: loopx1 of class  SMappingRanges */
static int tolua_get_SMappingRanges_SMappingRanges_loopx1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopx1'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->loopx1);
 return 1;
}

/* set function: loopx1 of class  SMappingRanges */
static int tolua_set_SMappingRanges_SMappingRanges_loopx1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopx1'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->loopx1 = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: loopy1 of class  SMappingRanges */
static int tolua_get_SMappingRanges_SMappingRanges_loopy1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopy1'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->loopy1);
 return 1;
}

/* set function: loopy1 of class  SMappingRanges */
static int tolua_set_SMappingRanges_SMappingRanges_loopy1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopy1'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->loopy1 = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: loopz1 of class  SMappingRanges */
static int tolua_get_SMappingRanges_SMappingRanges_loopz1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopz1'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->loopz1);
 return 1;
}

/* set function: loopz1 of class  SMappingRanges */
static int tolua_set_SMappingRanges_SMappingRanges_loopz1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopz1'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->loopz1 = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: new of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
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
  CArray2Dd* tolua_ret = (CArray2Dd*)  new CArray2Dd(w,h);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray2Dd");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
 {
  CArray2Dd* tolua_ret = (CArray2Dd*)  new CArray2Dd();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray2Dd");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CArray2Dd_new00(tolua_S);
}

/* method: delete of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: resize of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_resize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  int w = ((int)  tolua_tonumber(tolua_S,2,0));
  int h = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resize'",NULL);
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

/* method: destroy of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroy'",NULL);
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

/* method: width of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_width00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'width'",NULL);
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

/* method: height of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_height00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'height'",NULL);
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

/* method: set of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  double v = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
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

/* method: get of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'",NULL);
#endif
 {
  double tolua_ret = (double)  self->get(x,y);
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

/* method: get of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_get01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'",NULL);
#endif
 {
  double tolua_ret = (double)  self->get(x,y);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CArray2Dd_get00(tolua_S);
}

/* method: getIndexed of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_getIndexed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  unsigned c = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIndexed'",NULL);
#endif
 {
  double tolua_ret = (double)  self->getIndexed(c);
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

/* method: getBilinear of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_getBilinear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBilinear'",NULL);
#endif
 {
  double tolua_ret = (double)  self->getBilinear(x,y);
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

/* method: fill of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_fill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  float v = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fill'",NULL);
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

/* method: copyFrom of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_copyFrom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  CArray2Dd* b = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copyFrom'",NULL);
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

/* method: addArray of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_addArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  CArray2Dd* b = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addArray'",NULL);
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

/* method: subtractArray of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_subtractArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  CArray2Dd* b = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'subtractArray'",NULL);
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

/* method: multiplyArray of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_multiplyArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  CArray2Dd* b = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'multiplyArray'",NULL);
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

/* method: copyFromSub of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_copyFromSub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  CArray2Dd* b = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copyFromSub'",NULL);
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

/* method: addArraySub of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_addArraySub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  CArray2Dd* b = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addArraySub'",NULL);
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

/* method: subtractArraySub of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_subtractArraySub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  CArray2Dd* b = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'subtractArraySub'",NULL);
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

/* method: multiplyArraySub of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_multiplyArraySub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  CArray2Dd* b = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'multiplyArraySub'",NULL);
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

/* method: scale of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'",NULL);
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

/* method: getMax of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_getMax00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMax'",NULL);
#endif
 {
  double tolua_ret = (double)  self->getMax();
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

/* method: getMin of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_getMin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMin'",NULL);
#endif
 {
  double tolua_ret = (double)  self->getMin();
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

/* method: scaleToRange of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_scaleToRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  float low = ((float)  tolua_tonumber(tolua_S,2,0));
  float high = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleToRange'",NULL);
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

/* method: wrapCoords of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_wrapCoords00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wrapCoords'",NULL);
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

/* method: offset of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_offset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  int ox = ((int)  tolua_tonumber(tolua_S,2,0));
  int oy = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'offset'",NULL);
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

/* method: flipVertical of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_flipVertical00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'flipVertical'",NULL);
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

/* method: flipHorizontal of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_flipHorizontal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'flipHorizontal'",NULL);
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

/* method: blur of class  CArray2Dd */
static int tolua_bind_anl_CArray2Dd_blur00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isboolean(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  int blurwidth = ((int)  tolua_tonumber(tolua_S,2,0));
  int blurheight = ((int)  tolua_tonumber(tolua_S,3,0));
  bool seamless = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'blur'",NULL);
#endif
 {
  self->blur(blurwidth,blurheight,seamless);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'blur'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
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
  CArray2Drgba* tolua_ret = (CArray2Drgba*)  new CArray2Drgba(w,h);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray2Drgba");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
 {
  CArray2Drgba* tolua_ret = (CArray2Drgba*)  new CArray2Drgba();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray2Drgba");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CArray2Drgba_new00(tolua_S);
}

/* method: delete of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: resize of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_resize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  int w = ((int)  tolua_tonumber(tolua_S,2,0));
  int h = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resize'",NULL);
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

/* method: destroy of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroy'",NULL);
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

/* method: width of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_width00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'width'",NULL);
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

/* method: height of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_height00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'height'",NULL);
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

/* method: set of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"SRGBA",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  SRGBA v = *((SRGBA*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
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

/* method: get of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'",NULL);
#endif
 {
  SRGBA tolua_ret =  self->get(x,y);
 {
#ifdef __cplusplus
 void* tolua_obj = new SRGBA(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_SRGBA),"SRGBA");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(SRGBA));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"SRGBA");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get'.",&tolua_err);
 return 0;
#endif
}

/* method: get of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_get01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'",NULL);
#endif
 {
  SRGBA tolua_ret =  self->get(x,y);
 {
#ifdef __cplusplus
 void* tolua_obj = new SRGBA(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_SRGBA),"SRGBA");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(SRGBA));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"SRGBA");
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CArray2Drgba_get00(tolua_S);
}

/* method: getIndexed of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_getIndexed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  unsigned c = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIndexed'",NULL);
#endif
 {
  SRGBA tolua_ret =  self->getIndexed(c);
 {
#ifdef __cplusplus
 void* tolua_obj = new SRGBA(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_SRGBA),"SRGBA");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(SRGBA));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"SRGBA");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIndexed'.",&tolua_err);
 return 0;
#endif
}

/* method: getBilinear of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_getBilinear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBilinear'",NULL);
#endif
 {
  SRGBA tolua_ret =  self->getBilinear(x,y);
 {
#ifdef __cplusplus
 void* tolua_obj = new SRGBA(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_SRGBA),"SRGBA");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(SRGBA));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"SRGBA");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBilinear'.",&tolua_err);
 return 0;
#endif
}

/* method: fill of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_fill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"SRGBA",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  SRGBA v = *((SRGBA*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fill'",NULL);
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

/* method: copyFrom of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_copyFrom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  CArray2Drgba* b = ((CArray2Drgba*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copyFrom'",NULL);
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

/* method: addArray of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_addArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  CArray2Drgba* b = ((CArray2Drgba*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addArray'",NULL);
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

/* method: subtractArray of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_subtractArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  CArray2Drgba* b = ((CArray2Drgba*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'subtractArray'",NULL);
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

/* method: multiplyArray of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_multiplyArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  CArray2Drgba* b = ((CArray2Drgba*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'multiplyArray'",NULL);
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

/* method: copyFromSub of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_copyFromSub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  CArray2Drgba* b = ((CArray2Drgba*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copyFromSub'",NULL);
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

/* method: addArraySub of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_addArraySub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  CArray2Drgba* b = ((CArray2Drgba*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addArraySub'",NULL);
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

/* method: subtractArraySub of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_subtractArraySub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  CArray2Drgba* b = ((CArray2Drgba*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'subtractArraySub'",NULL);
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

/* method: multiplyArraySub of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_multiplyArraySub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  CArray2Drgba* b = ((CArray2Drgba*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'multiplyArraySub'",NULL);
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

/* method: scale of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"SRGBA",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  SRGBA s = *((SRGBA*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'",NULL);
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

/* method: wrapCoords of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_wrapCoords00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'wrapCoords'",NULL);
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

/* method: offset of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_offset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  int ox = ((int)  tolua_tonumber(tolua_S,2,0));
  int oy = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'offset'",NULL);
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

/* method: flipVertical of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_flipVertical00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'flipVertical'",NULL);
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

/* method: flipHorizontal of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_flipHorizontal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'flipHorizontal'",NULL);
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

/* method: blur of class  CArray2Drgba */
static int tolua_bind_anl_CArray2Drgba_blur00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isboolean(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  int blurwidth = ((int)  tolua_tonumber(tolua_S,2,0));
  int blurheight = ((int)  tolua_tonumber(tolua_S,3,0));
  bool seamless = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'blur'",NULL);
#endif
 {
  self->blur(blurwidth,blurheight,seamless);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'blur'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  CArray3Dd */
static int tolua_bind_anl_CArray3Dd_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CArray3Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  CArray3Dd* tolua_ret = (CArray3Dd*)  new CArray3Dd();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray3Dd");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  CArray3Dd */
static int tolua_bind_anl_CArray3Dd_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CArray3Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  int w = ((int)  tolua_tonumber(tolua_S,2,0));
  int h = ((int)  tolua_tonumber(tolua_S,3,0));
  int d = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  CArray3Dd* tolua_ret = (CArray3Dd*)  new CArray3Dd(w,h,d);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray3Dd");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CArray3Dd_new00(tolua_S);
}

/* method: delete of class  CArray3Dd */
static int tolua_bind_anl_CArray3Dd_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray3Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray3Dd* self = (CArray3Dd*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: width of class  CArray3Dd */
static int tolua_bind_anl_CArray3Dd_width00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray3Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray3Dd* self = (CArray3Dd*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'width'",NULL);
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

/* method: height of class  CArray3Dd */
static int tolua_bind_anl_CArray3Dd_height00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray3Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray3Dd* self = (CArray3Dd*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'height'",NULL);
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

/* method: depth of class  CArray3Dd */
static int tolua_bind_anl_CArray3Dd_depth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray3Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray3Dd* self = (CArray3Dd*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'depth'",NULL);
#endif
 {
  int tolua_ret = (int)  self->depth();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'depth'.",&tolua_err);
 return 0;
#endif
}

/* method: set of class  CArray3Dd */
static int tolua_bind_anl_CArray3Dd_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray3Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray3Dd* self = (CArray3Dd*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int z = ((int)  tolua_tonumber(tolua_S,4,0));
  double v = ((double)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
#endif
 {
  self->set(x,y,z,v);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}

/* method: get of class  CArray3Dd */
static int tolua_bind_anl_CArray3Dd_get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray3Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray3Dd* self = (CArray3Dd*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int z = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'",NULL);
#endif
 {
  double tolua_ret = (double)  self->get(x,y,z);
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

/* method: resize of class  CArray3Dd */
static int tolua_bind_anl_CArray3Dd_resize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray3Dd",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray3Dd* self = (CArray3Dd*)  tolua_tousertype(tolua_S,1,0);
  int w = ((int)  tolua_tonumber(tolua_S,2,0));
  int h = ((int)  tolua_tonumber(tolua_S,3,0));
  int d = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resize'",NULL);
#endif
 {
  self->resize(w,h,d);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resize'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  CArray3Drgba */
static int tolua_bind_anl_CArray3Drgba_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CArray3Drgba",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  CArray3Drgba* tolua_ret = (CArray3Drgba*)  new CArray3Drgba();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray3Drgba");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  CArray3Drgba */
static int tolua_bind_anl_CArray3Drgba_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CArray3Drgba",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  int w = ((int)  tolua_tonumber(tolua_S,2,0));
  int h = ((int)  tolua_tonumber(tolua_S,3,0));
  int d = ((int)  tolua_tonumber(tolua_S,4,0));
 {
  CArray3Drgba* tolua_ret = (CArray3Drgba*)  new CArray3Drgba(w,h,d);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray3Drgba");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CArray3Drgba_new00(tolua_S);
}

/* method: delete of class  CArray3Drgba */
static int tolua_bind_anl_CArray3Drgba_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray3Drgba",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray3Drgba* self = (CArray3Drgba*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 tolua_release(tolua_S,self);
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: width of class  CArray3Drgba */
static int tolua_bind_anl_CArray3Drgba_width00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray3Drgba",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray3Drgba* self = (CArray3Drgba*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'width'",NULL);
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

/* method: height of class  CArray3Drgba */
static int tolua_bind_anl_CArray3Drgba_height00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray3Drgba",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray3Drgba* self = (CArray3Drgba*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'height'",NULL);
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

/* method: depth of class  CArray3Drgba */
static int tolua_bind_anl_CArray3Drgba_depth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray3Drgba",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray3Drgba* self = (CArray3Drgba*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'depth'",NULL);
#endif
 {
  int tolua_ret = (int)  self->depth();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'depth'.",&tolua_err);
 return 0;
#endif
}

/* method: resize of class  CArray3Drgba */
static int tolua_bind_anl_CArray3Drgba_resize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray3Drgba",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray3Drgba* self = (CArray3Drgba*)  tolua_tousertype(tolua_S,1,0);
  int w = ((int)  tolua_tonumber(tolua_S,2,0));
  int h = ((int)  tolua_tonumber(tolua_S,3,0));
  int d = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resize'",NULL);
#endif
 {
  self->resize(w,h,d);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resize'.",&tolua_err);
 return 0;
#endif
}

/* method: set of class  CArray3Drgba */
static int tolua_bind_anl_CArray3Drgba_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray3Drgba",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isusertype(tolua_S,5,"SRGBA",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray3Drgba* self = (CArray3Drgba*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int z = ((int)  tolua_tonumber(tolua_S,4,0));
  SRGBA v = *((SRGBA*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
#endif
 {
  self->set(x,y,z,v);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}

/* method: get of class  CArray3Drgba */
static int tolua_bind_anl_CArray3Drgba_get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray3Drgba",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray3Drgba* self = (CArray3Drgba*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int z = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'",NULL);
#endif
 {
  anl::SRGBA tolua_ret =  self->get(x,y,z);
 {
#ifdef __cplusplus
 void* tolua_obj = new anl::SRGBA(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_anl_SRGBA),"anl::SRGBA");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(anl::SRGBA));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"anl::SRGBA");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get'.",&tolua_err);
 return 0;
#endif
}

/* function: map2D */
static int tolua_bind_anl_map2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"SMappingRanges",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int seamlessmode = ((int)  tolua_tonumber(tolua_S,1,0));
  CArray2Dd* a = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
  CKernel* k = ((CKernel*)  tolua_tousertype(tolua_S,3,0));
  SMappingRanges ranges = *((SMappingRanges*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex index = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
  double z = ((double)  tolua_tonumber(tolua_S,6,0));
 {
  map2D(seamlessmode,*a,*k,ranges,index,z);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'map2D'.",&tolua_err);
 return 0;
#endif
}

/* function: map2DNoZ */
static int tolua_bind_anl_map2DNoZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"SMappingRanges",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int seamlessmode = ((int)  tolua_tonumber(tolua_S,1,0));
  CArray2Dd* a = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
  CKernel* k = ((CKernel*)  tolua_tousertype(tolua_S,3,0));
  SMappingRanges ranges = *((SMappingRanges*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex index = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
 {
  map2DNoZ(seamlessmode,*a,*k,ranges,index);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'map2DNoZ'.",&tolua_err);
 return 0;
#endif
}

/* function: map3D */
static int tolua_bind_anl_map3D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray3Dd",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"SMappingRanges",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int seamlessmode = ((int)  tolua_tonumber(tolua_S,1,0));
  CArray3Dd* a = ((CArray3Dd*)  tolua_tousertype(tolua_S,2,0));
  CKernel* k = ((CKernel*)  tolua_tousertype(tolua_S,3,0));
  SMappingRanges ranges = *((SMappingRanges*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex index = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
 {
  map3D(seamlessmode,*a,*k,ranges,index);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'map3D'.",&tolua_err);
 return 0;
#endif
}

/* function: mapRGBA2D */
static int tolua_bind_anl_mapRGBA2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"SMappingRanges",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,6,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int seamlessmode = ((int)  tolua_tonumber(tolua_S,1,0));
  CArray2Drgba* a = ((CArray2Drgba*)  tolua_tousertype(tolua_S,2,0));
  CKernel* k = ((CKernel*)  tolua_tousertype(tolua_S,3,0));
  SMappingRanges ranges = *((SMappingRanges*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex index = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
  double z = ((double)  tolua_tonumber(tolua_S,6,0));
 {
  mapRGBA2D(seamlessmode,*a,*k,ranges,index,z);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mapRGBA2D'.",&tolua_err);
 return 0;
#endif
}

/* function: mapRGBA2DNoZ */
static int tolua_bind_anl_mapRGBA2DNoZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"SMappingRanges",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int seamlessmode = ((int)  tolua_tonumber(tolua_S,1,0));
  CArray2Drgba* a = ((CArray2Drgba*)  tolua_tousertype(tolua_S,2,0));
  CKernel* k = ((CKernel*)  tolua_tousertype(tolua_S,3,0));
  SMappingRanges ranges = *((SMappingRanges*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex index = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
 {
  mapRGBA2DNoZ(seamlessmode,*a,*k,ranges,index);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mapRGBA2DNoZ'.",&tolua_err);
 return 0;
#endif
}

/* function: mapRGBA3D */
static int tolua_bind_anl_mapRGBA3D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray3Drgba",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"SMappingRanges",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int seamlessmode = ((int)  tolua_tonumber(tolua_S,1,0));
  CArray3Drgba* a = ((CArray3Drgba*)  tolua_tousertype(tolua_S,2,0));
  CKernel* k = ((CKernel*)  tolua_tousertype(tolua_S,3,0));
  SMappingRanges ranges = *((SMappingRanges*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex index = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
 {
  mapRGBA3D(seamlessmode,*a,*k,ranges,index);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mapRGBA3D'.",&tolua_err);
 return 0;
#endif
}

/* function: saveDoubleArray */
static int tolua_bind_anl_saveDoubleArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,1,0));
  CArray2Dd* array = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
 {
  saveDoubleArray(filename,array);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'saveDoubleArray'.",&tolua_err);
 return 0;
#endif
}

/* function: saveRGBAArray */
static int tolua_bind_anl_saveRGBAArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,1,0));
  CArray2Drgba* array = ((CArray2Drgba*)  tolua_tousertype(tolua_S,2,0));
 {
  saveRGBAArray(filename,array);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'saveRGBAArray'.",&tolua_err);
 return 0;
#endif
}

/* function: loadDoubleArray */
static int tolua_bind_anl_loadDoubleArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,1,0));
  CArray2Dd* array = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
 {
  loadDoubleArray(filename,array);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadDoubleArray'.",&tolua_err);
 return 0;
#endif
}

/* function: loadRGBAArray */
static int tolua_bind_anl_loadRGBAArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isstring(tolua_S,1,0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Drgba",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,1,0));
  CArray2Drgba* array = ((CArray2Drgba*)  tolua_tousertype(tolua_S,2,0));
 {
  loadRGBAArray(filename,array);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadRGBAArray'.",&tolua_err);
 return 0;
#endif
}

/* function: map2DThread */
static int tolua_bind_anl_map2DThread00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"SMappingRanges",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int seamlessmode = ((int)  tolua_tonumber(tolua_S,1,0));
  CArray2Dd* a = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
  CKernel* k = ((CKernel*)  tolua_tousertype(tolua_S,3,0));
  SMappingRanges ranges = *((SMappingRanges*)  tolua_tousertype(tolua_S,4,0));
  double z = ((double)  tolua_tonumber(tolua_S,5,0));
 {
  map2DThread(seamlessmode,*a,*k,ranges,z);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'map2DThread'.",&tolua_err);
 return 0;
#endif
}

/* function: map2DNoThread */
static int tolua_bind_anl_map2DNoThread00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,3,"CKernel",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,4,"SMappingRanges",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  int seamlessmode = ((int)  tolua_tonumber(tolua_S,1,0));
  CArray2Dd* a = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
  CKernel* k = ((CKernel*)  tolua_tousertype(tolua_S,3,0));
  SMappingRanges ranges = *((SMappingRanges*)  tolua_tousertype(tolua_S,4,0));
  double z = ((double)  tolua_tonumber(tolua_S,5,0));
 {
  map2DNoThread(seamlessmode,*a,*k,ranges,z);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'map2DNoThread'.",&tolua_err);
 return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_bind_anl (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_function(tolua_S,"highresTime",tolua_bind_anl_highresTime00);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"CVec2f","CVec2f","",tolua_collect_CVec2f);
#else
 tolua_cclass(tolua_S,"CVec2f","CVec2f","",NULL);
#endif
 tolua_beginmodule(tolua_S,"CVec2f");
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec2f_new00);
 tolua_function(tolua_S,"delete",tolua_bind_anl_CVec2f_delete00);
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec2f_new01);
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec2f_new02);
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec2f_new03);
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec2f_new04);
 tolua_function(tolua_S,"dotprod",tolua_bind_anl_CVec2f_dotprod00);
 tolua_function(tolua_S,"length",tolua_bind_anl_CVec2f_length00);
 tolua_function(tolua_S,"normalize",tolua_bind_anl_CVec2f_normalize00);
 tolua_function(tolua_S,"set",tolua_bind_anl_CVec2f_set00);
 tolua_variable(tolua_S,"x",tolua_get_CVec2f_CVec2f_x,tolua_set_CVec2f_CVec2f_x);
 tolua_variable(tolua_S,"y",tolua_get_CVec2f_CVec2f_y,tolua_set_CVec2f_CVec2f_y);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"CVec3f","CVec3f","",tolua_collect_CVec3f);
#else
 tolua_cclass(tolua_S,"CVec3f","CVec3f","",NULL);
#endif
 tolua_beginmodule(tolua_S,"CVec3f");
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec3f_new00);
 tolua_function(tolua_S,"delete",tolua_bind_anl_CVec3f_delete00);
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec3f_new01);
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec3f_new02);
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec3f_new03);
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec3f_new04);
 tolua_function(tolua_S,"dotprod",tolua_bind_anl_CVec3f_dotprod00);
 tolua_function(tolua_S,"length",tolua_bind_anl_CVec3f_length00);
 tolua_function(tolua_S,"normalize",tolua_bind_anl_CVec3f_normalize00);
 tolua_function(tolua_S,"set",tolua_bind_anl_CVec3f_set00);
 tolua_variable(tolua_S,"x",tolua_get_CVec3f_CVec3f_x,tolua_set_CVec3f_CVec3f_x);
 tolua_variable(tolua_S,"y",tolua_get_CVec3f_CVec3f_y,tolua_set_CVec3f_CVec3f_y);
 tolua_variable(tolua_S,"z",tolua_get_CVec3f_CVec3f_z,tolua_set_CVec3f_CVec3f_z);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"CVec2i","CVec2i","",tolua_collect_CVec2i);
#else
 tolua_cclass(tolua_S,"CVec2i","CVec2i","",NULL);
#endif
 tolua_beginmodule(tolua_S,"CVec2i");
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec2i_new00);
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec2i_new01);
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec2i_new02);
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec2i_new03);
 tolua_function(tolua_S,"delete",tolua_bind_anl_CVec2i_delete00);
 tolua_variable(tolua_S,"x",tolua_get_CVec2i_CVec2i_x,tolua_set_CVec2i_CVec2i_x);
 tolua_variable(tolua_S,"y",tolua_get_CVec2i_CVec2i_y,tolua_set_CVec2i_CVec2i_y);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"CVec3i","CVec3i","",tolua_collect_CVec3i);
#else
 tolua_cclass(tolua_S,"CVec3i","CVec3i","",NULL);
#endif
 tolua_beginmodule(tolua_S,"CVec3i");
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec3i_new00);
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec3i_new01);
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec3i_new02);
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec3i_new03);
 tolua_function(tolua_S,"delete",tolua_bind_anl_CVec3i_delete00);
 tolua_variable(tolua_S,"x",tolua_get_CVec3i_CVec3i_x,tolua_set_CVec3i_CVec3i_x);
 tolua_variable(tolua_S,"y",tolua_get_CVec3i_CVec3i_y,tolua_set_CVec3i_CVec3i_y);
 tolua_variable(tolua_S,"z",tolua_get_CVec3i_CVec3i_z,tolua_set_CVec3i_CVec3i_z);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"CVec4i","CVec4i","",tolua_collect_CVec4i);
#else
 tolua_cclass(tolua_S,"CVec4i","CVec4i","",NULL);
#endif
 tolua_beginmodule(tolua_S,"CVec4i");
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec4i_new00);
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec4i_new01);
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec4i_new02);
 tolua_function(tolua_S,"new",tolua_bind_anl_CVec4i_new03);
 tolua_function(tolua_S,"delete",tolua_bind_anl_CVec4i_delete00);
 tolua_variable(tolua_S,"x",tolua_get_CVec4i_CVec4i_x,tolua_set_CVec4i_CVec4i_x);
 tolua_variable(tolua_S,"y",tolua_get_CVec4i_CVec4i_y,tolua_set_CVec4i_CVec4i_y);
 tolua_variable(tolua_S,"z",tolua_get_CVec4i_CVec4i_z,tolua_set_CVec4i_CVec4i_z);
 tolua_variable(tolua_S,"w",tolua_get_CVec4i_CVec4i_w,tolua_set_CVec4i_CVec4i_w);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"CBasePRNG","CBasePRNG","",NULL);
 tolua_beginmodule(tolua_S,"CBasePRNG");
 tolua_function(tolua_S,"get",tolua_bind_anl_CBasePRNG_get00);
 tolua_function(tolua_S,"setSeed",tolua_bind_anl_CBasePRNG_setSeed00);
 tolua_function(tolua_S,"setSeedTime",tolua_bind_anl_CBasePRNG_setSeedTime00);
 tolua_function(tolua_S,"getTarget",tolua_bind_anl_CBasePRNG_getTarget00);
 tolua_function(tolua_S,"getRange",tolua_bind_anl_CBasePRNG_getRange00);
 tolua_function(tolua_S,"get01",tolua_bind_anl_CBasePRNG_get0100);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"LCG","LCG","CBasePRNG",tolua_collect_LCG);
#else
 tolua_cclass(tolua_S,"LCG","LCG","CBasePRNG",NULL);
#endif
 tolua_beginmodule(tolua_S,"LCG");
 tolua_function(tolua_S,"new",tolua_bind_anl_LCG_new00);
 tolua_function(tolua_S,"delete",tolua_bind_anl_LCG_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"Xorshift","Xorshift","CBasePRNG",tolua_collect_Xorshift);
#else
 tolua_cclass(tolua_S,"Xorshift","Xorshift","CBasePRNG",NULL);
#endif
 tolua_beginmodule(tolua_S,"Xorshift");
 tolua_function(tolua_S,"new",tolua_bind_anl_Xorshift_new00);
 tolua_function(tolua_S,"delete",tolua_bind_anl_Xorshift_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"MWC256","MWC256","CBasePRNG",tolua_collect_MWC256);
#else
 tolua_cclass(tolua_S,"MWC256","MWC256","CBasePRNG",NULL);
#endif
 tolua_beginmodule(tolua_S,"MWC256");
 tolua_function(tolua_S,"new",tolua_bind_anl_MWC256_new00);
 tolua_function(tolua_S,"delete",tolua_bind_anl_MWC256_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"CMWC4096","CMWC4096","CBasePRNG",tolua_collect_CMWC4096);
#else
 tolua_cclass(tolua_S,"CMWC4096","CMWC4096","CBasePRNG",NULL);
#endif
 tolua_beginmodule(tolua_S,"CMWC4096");
 tolua_function(tolua_S,"new",tolua_bind_anl_CMWC4096_new00);
 tolua_function(tolua_S,"delete",tolua_bind_anl_CMWC4096_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"KISS","KISS","CBasePRNG",tolua_collect_KISS);
#else
 tolua_cclass(tolua_S,"KISS","KISS","CBasePRNG",NULL);
#endif
 tolua_beginmodule(tolua_S,"KISS");
 tolua_function(tolua_S,"new",tolua_bind_anl_KISS_new00);
 tolua_function(tolua_S,"delete",tolua_bind_anl_KISS_delete00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"CCoordinate","CCoordinate","",NULL);
 tolua_beginmodule(tolua_S,"CCoordinate");
 tolua_function(tolua_S,"new",tolua_bind_anl_CCoordinate_new00);
 tolua_function(tolua_S,"new",tolua_bind_anl_CCoordinate_new01);
 tolua_function(tolua_S,"new",tolua_bind_anl_CCoordinate_new02);
 tolua_function(tolua_S,"new",tolua_bind_anl_CCoordinate_new03);
 tolua_function(tolua_S,"new",tolua_bind_anl_CCoordinate_new04);
 tolua_function(tolua_S,"new",tolua_bind_anl_CCoordinate_new05);
 tolua_function(tolua_S,"set",tolua_bind_anl_CCoordinate_set00);
 tolua_function(tolua_S,"set",tolua_bind_anl_CCoordinate_set01);
 tolua_function(tolua_S,"set",tolua_bind_anl_CCoordinate_set02);
 tolua_function(tolua_S,"set",tolua_bind_anl_CCoordinate_set03);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"CInstructionIndex","CInstructionIndex","",tolua_collect_CInstructionIndex);
#else
 tolua_cclass(tolua_S,"CInstructionIndex","CInstructionIndex","",NULL);
#endif
 tolua_beginmodule(tolua_S,"CInstructionIndex");
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"CInstructionListType","CInstructionListType","",NULL);
 tolua_beginmodule(tolua_S,"CInstructionListType");
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"CKernel","CKernel","",tolua_collect_CKernel);
#else
 tolua_cclass(tolua_S,"CKernel","CKernel","",NULL);
#endif
 tolua_beginmodule(tolua_S,"CKernel");
 tolua_function(tolua_S,"new",tolua_bind_anl_CKernel_new00);
 tolua_function(tolua_S,"delete",tolua_bind_anl_CKernel_delete00);
 tolua_function(tolua_S,"constant",tolua_bind_anl_CKernel_constant00);
 tolua_function(tolua_S,"valueBasis",tolua_bind_anl_CKernel_valueBasis00);
 tolua_function(tolua_S,"gradientBasis",tolua_bind_anl_CKernel_gradientBasis00);
 tolua_function(tolua_S,"simplexBasis",tolua_bind_anl_CKernel_simplexBasis00);
 tolua_function(tolua_S,"cellularBasis",tolua_bind_anl_CKernel_cellularBasis00);
 tolua_function(tolua_S,"add",tolua_bind_anl_CKernel_add00);
 tolua_function(tolua_S,"subtract",tolua_bind_anl_CKernel_subtract00);
 tolua_function(tolua_S,"multiply",tolua_bind_anl_CKernel_multiply00);
 tolua_function(tolua_S,"divide",tolua_bind_anl_CKernel_divide00);
 tolua_function(tolua_S,"maximum",tolua_bind_anl_CKernel_maximum00);
 tolua_function(tolua_S,"minimum",tolua_bind_anl_CKernel_minimum00);
 tolua_function(tolua_S,"abs",tolua_bind_anl_CKernel_abs00);
 tolua_function(tolua_S,"pow",tolua_bind_anl_CKernel_pow00);
 tolua_function(tolua_S,"bias",tolua_bind_anl_CKernel_bias00);
 tolua_function(tolua_S,"gain",tolua_bind_anl_CKernel_gain00);
 tolua_function(tolua_S,"scaleDomain",tolua_bind_anl_CKernel_scaleDomain00);
 tolua_function(tolua_S,"scaleDomain",tolua_bind_anl_CKernel_scaleDomain01);
 tolua_function(tolua_S,"scaleDomain",tolua_bind_anl_CKernel_scaleDomain02);
 tolua_function(tolua_S,"scaleDomain",tolua_bind_anl_CKernel_scaleDomain03);
 tolua_function(tolua_S,"scaleX",tolua_bind_anl_CKernel_scaleX00);
 tolua_function(tolua_S,"scaleY",tolua_bind_anl_CKernel_scaleY00);
 tolua_function(tolua_S,"scaleZ",tolua_bind_anl_CKernel_scaleZ00);
 tolua_function(tolua_S,"scaleW",tolua_bind_anl_CKernel_scaleW00);
 tolua_function(tolua_S,"scaleU",tolua_bind_anl_CKernel_scaleU00);
 tolua_function(tolua_S,"scaleV",tolua_bind_anl_CKernel_scaleV00);
 tolua_function(tolua_S,"translateDomain",tolua_bind_anl_CKernel_translateDomain00);
 tolua_function(tolua_S,"translateDomain",tolua_bind_anl_CKernel_translateDomain01);
 tolua_function(tolua_S,"translateDomain",tolua_bind_anl_CKernel_translateDomain02);
 tolua_function(tolua_S,"translateDomain",tolua_bind_anl_CKernel_translateDomain03);
 tolua_function(tolua_S,"translateX",tolua_bind_anl_CKernel_translateX00);
 tolua_function(tolua_S,"translateY",tolua_bind_anl_CKernel_translateY00);
 tolua_function(tolua_S,"translateZ",tolua_bind_anl_CKernel_translateZ00);
 tolua_function(tolua_S,"translateW",tolua_bind_anl_CKernel_translateW00);
 tolua_function(tolua_S,"translateU",tolua_bind_anl_CKernel_translateU00);
 tolua_function(tolua_S,"translateV",tolua_bind_anl_CKernel_translateV00);
 tolua_function(tolua_S,"rotateDomain",tolua_bind_anl_CKernel_rotateDomain00);
 tolua_function(tolua_S,"addSequence",tolua_bind_anl_CKernel_addSequence00);
 tolua_function(tolua_S,"multiplySequence",tolua_bind_anl_CKernel_multiplySequence00);
 tolua_function(tolua_S,"maxSequence",tolua_bind_anl_CKernel_maxSequence00);
 tolua_function(tolua_S,"minSequence",tolua_bind_anl_CKernel_minSequence00);
 tolua_function(tolua_S,"blend",tolua_bind_anl_CKernel_blend00);
 tolua_function(tolua_S,"select",tolua_bind_anl_CKernel_select00);
 tolua_function(tolua_S,"clamp",tolua_bind_anl_CKernel_clamp00);
 tolua_function(tolua_S,"cos",tolua_bind_anl_CKernel_cos00);
 tolua_function(tolua_S,"sin",tolua_bind_anl_CKernel_sin00);
 tolua_function(tolua_S,"tan",tolua_bind_anl_CKernel_tan00);
 tolua_function(tolua_S,"acos",tolua_bind_anl_CKernel_acos00);
 tolua_function(tolua_S,"asin",tolua_bind_anl_CKernel_asin00);
 tolua_function(tolua_S,"atan",tolua_bind_anl_CKernel_atan00);
 tolua_function(tolua_S,"tiers",tolua_bind_anl_CKernel_tiers00);
 tolua_function(tolua_S,"smoothTiers",tolua_bind_anl_CKernel_smoothTiers00);
 tolua_function(tolua_S,"x",tolua_bind_anl_CKernel_x00);
 tolua_function(tolua_S,"y",tolua_bind_anl_CKernel_y00);
 tolua_function(tolua_S,"z",tolua_bind_anl_CKernel_z00);
 tolua_function(tolua_S,"w",tolua_bind_anl_CKernel_w00);
 tolua_function(tolua_S,"u",tolua_bind_anl_CKernel_u00);
 tolua_function(tolua_S,"v",tolua_bind_anl_CKernel_v00);
 tolua_function(tolua_S,"radial",tolua_bind_anl_CKernel_radial00);
 tolua_function(tolua_S,"hexTile",tolua_bind_anl_CKernel_hexTile00);
 tolua_function(tolua_S,"hexBump",tolua_bind_anl_CKernel_hexBump00);
 tolua_function(tolua_S,"combineRGBA",tolua_bind_anl_CKernel_combineRGBA00);
 tolua_function(tolua_S,"scaleOffset",tolua_bind_anl_CKernel_scaleOffset00);
 tolua_function(tolua_S,"simpleFractalLayer",tolua_bind_anl_CKernel_simpleFractalLayer00);
 tolua_function(tolua_S,"simpleRidgedLayer",tolua_bind_anl_CKernel_simpleRidgedLayer00);
 tolua_function(tolua_S,"simplefBm",tolua_bind_anl_CKernel_simplefBm00);
 tolua_function(tolua_S,"simpleRidgedMultifractal",tolua_bind_anl_CKernel_simpleRidgedMultifractal00);
 tolua_function(tolua_S,"getKernel",tolua_bind_anl_CKernel_getKernel00);
 tolua_function(tolua_S,"lastIndex",tolua_bind_anl_CKernel_lastIndex00);
 tolua_function(tolua_S,"nextIndex",tolua_bind_anl_CKernel_nextIndex00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"SRGBA","SRGBA","",tolua_collect_SRGBA);
#else
 tolua_cclass(tolua_S,"SRGBA","SRGBA","",NULL);
#endif
 tolua_beginmodule(tolua_S,"SRGBA");
 tolua_function(tolua_S,"new",tolua_bind_anl_SRGBA_new00);
 tolua_function(tolua_S,"new",tolua_bind_anl_SRGBA_new01);
 tolua_function(tolua_S,"new",tolua_bind_anl_SRGBA_new02);
 tolua_function(tolua_S,"new",tolua_bind_anl_SRGBA_new03);
 tolua_function(tolua_S,"delete",tolua_bind_anl_SRGBA_delete00);
 tolua_variable(tolua_S,"r",tolua_get_SRGBA_SRGBA_r,tolua_set_SRGBA_SRGBA_r);
 tolua_variable(tolua_S,"g",tolua_get_SRGBA_SRGBA_g,tolua_set_SRGBA_SRGBA_g);
 tolua_variable(tolua_S,"b",tolua_get_SRGBA_SRGBA_b,tolua_set_SRGBA_SRGBA_b);
 tolua_variable(tolua_S,"a",tolua_get_SRGBA_SRGBA_a,tolua_set_SRGBA_SRGBA_a);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"SVMOutput","SVMOutput","",tolua_collect_SVMOutput);
#else
 tolua_cclass(tolua_S,"SVMOutput","SVMOutput","",NULL);
#endif
 tolua_beginmodule(tolua_S,"SVMOutput");
 tolua_variable(tolua_S,"outfloat_",tolua_get_SVMOutput_SVMOutput_outfloat_,tolua_set_SVMOutput_SVMOutput_outfloat_);
 tolua_variable(tolua_S,"outrgba_",tolua_get_SVMOutput_SVMOutput_outrgba_,tolua_set_SVMOutput_SVMOutput_outrgba_);
 tolua_function(tolua_S,"new",tolua_bind_anl_SVMOutput_new00);
 tolua_function(tolua_S,"delete",tolua_bind_anl_SVMOutput_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"CNoiseExecutor","CNoiseExecutor","",tolua_collect_CNoiseExecutor);
#else
 tolua_cclass(tolua_S,"CNoiseExecutor","CNoiseExecutor","",NULL);
#endif
 tolua_beginmodule(tolua_S,"CNoiseExecutor");
 tolua_function(tolua_S,"new",tolua_bind_anl_CNoiseExecutor_new00);
 tolua_function(tolua_S,"delete",tolua_bind_anl_CNoiseExecutor_delete00);
 tolua_function(tolua_S,"evaluate",tolua_bind_anl_CNoiseExecutor_evaluate00);
 tolua_function(tolua_S,"evaluateAt",tolua_bind_anl_CNoiseExecutor_evaluateAt00);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"SEAMLESS_NONE",SEAMLESS_NONE);
 tolua_constant(tolua_S,"SEAMLESS_X",SEAMLESS_X);
 tolua_constant(tolua_S,"SEAMLESS_Y",SEAMLESS_Y);
 tolua_constant(tolua_S,"SEAMLESS_Z",SEAMLESS_Z);
 tolua_constant(tolua_S,"SEAMLESS_XY",SEAMLESS_XY);
 tolua_constant(tolua_S,"SEAMLESS_XZ",SEAMLESS_XZ);
 tolua_constant(tolua_S,"SEAMLESS_YZ",SEAMLESS_YZ);
 tolua_constant(tolua_S,"SEAMLESS_XYZ",SEAMLESS_XYZ);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"SMappingRanges","SMappingRanges","",tolua_collect_SMappingRanges);
#else
 tolua_cclass(tolua_S,"SMappingRanges","SMappingRanges","",NULL);
#endif
 tolua_beginmodule(tolua_S,"SMappingRanges");
 tolua_function(tolua_S,"new",tolua_bind_anl_SMappingRanges_new00);
 tolua_function(tolua_S,"new",tolua_bind_anl_SMappingRanges_new01);
 tolua_function(tolua_S,"new",tolua_bind_anl_SMappingRanges_new02);
 tolua_function(tolua_S,"new",tolua_bind_anl_SMappingRanges_new03);
 tolua_function(tolua_S,"delete",tolua_bind_anl_SMappingRanges_delete00);
 tolua_variable(tolua_S,"mapx0",tolua_get_SMappingRanges_SMappingRanges_mapx0,tolua_set_SMappingRanges_SMappingRanges_mapx0);
 tolua_variable(tolua_S,"mapy0",tolua_get_SMappingRanges_SMappingRanges_mapy0,tolua_set_SMappingRanges_SMappingRanges_mapy0);
 tolua_variable(tolua_S,"mapz0",tolua_get_SMappingRanges_SMappingRanges_mapz0,tolua_set_SMappingRanges_SMappingRanges_mapz0);
 tolua_variable(tolua_S,"mapx1",tolua_get_SMappingRanges_SMappingRanges_mapx1,tolua_set_SMappingRanges_SMappingRanges_mapx1);
 tolua_variable(tolua_S,"mapy1",tolua_get_SMappingRanges_SMappingRanges_mapy1,tolua_set_SMappingRanges_SMappingRanges_mapy1);
 tolua_variable(tolua_S,"mapz1",tolua_get_SMappingRanges_SMappingRanges_mapz1,tolua_set_SMappingRanges_SMappingRanges_mapz1);
 tolua_variable(tolua_S,"loopx0",tolua_get_SMappingRanges_SMappingRanges_loopx0,tolua_set_SMappingRanges_SMappingRanges_loopx0);
 tolua_variable(tolua_S,"loopy0",tolua_get_SMappingRanges_SMappingRanges_loopy0,tolua_set_SMappingRanges_SMappingRanges_loopy0);
 tolua_variable(tolua_S,"loopz0",tolua_get_SMappingRanges_SMappingRanges_loopz0,tolua_set_SMappingRanges_SMappingRanges_loopz0);
 tolua_variable(tolua_S,"loopx1",tolua_get_SMappingRanges_SMappingRanges_loopx1,tolua_set_SMappingRanges_SMappingRanges_loopx1);
 tolua_variable(tolua_S,"loopy1",tolua_get_SMappingRanges_SMappingRanges_loopy1,tolua_set_SMappingRanges_SMappingRanges_loopy1);
 tolua_variable(tolua_S,"loopz1",tolua_get_SMappingRanges_SMappingRanges_loopz1,tolua_set_SMappingRanges_SMappingRanges_loopz1);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"CArray2Dd","CArray2Dd","",tolua_collect_CArray2Dd);
#else
 tolua_cclass(tolua_S,"CArray2Dd","CArray2Dd","",NULL);
#endif
 tolua_beginmodule(tolua_S,"CArray2Dd");
 tolua_function(tolua_S,"new",tolua_bind_anl_CArray2Dd_new00);
 tolua_function(tolua_S,"new",tolua_bind_anl_CArray2Dd_new01);
 tolua_function(tolua_S,"delete",tolua_bind_anl_CArray2Dd_delete00);
 tolua_function(tolua_S,"resize",tolua_bind_anl_CArray2Dd_resize00);
 tolua_function(tolua_S,"destroy",tolua_bind_anl_CArray2Dd_destroy00);
 tolua_function(tolua_S,"width",tolua_bind_anl_CArray2Dd_width00);
 tolua_function(tolua_S,"height",tolua_bind_anl_CArray2Dd_height00);
 tolua_function(tolua_S,"set",tolua_bind_anl_CArray2Dd_set00);
 tolua_function(tolua_S,"get",tolua_bind_anl_CArray2Dd_get00);
 tolua_function(tolua_S,"get",tolua_bind_anl_CArray2Dd_get01);
 tolua_function(tolua_S,"getIndexed",tolua_bind_anl_CArray2Dd_getIndexed00);
 tolua_function(tolua_S,"getBilinear",tolua_bind_anl_CArray2Dd_getBilinear00);
 tolua_function(tolua_S,"fill",tolua_bind_anl_CArray2Dd_fill00);
 tolua_function(tolua_S,"copyFrom",tolua_bind_anl_CArray2Dd_copyFrom00);
 tolua_function(tolua_S,"addArray",tolua_bind_anl_CArray2Dd_addArray00);
 tolua_function(tolua_S,"subtractArray",tolua_bind_anl_CArray2Dd_subtractArray00);
 tolua_function(tolua_S,"multiplyArray",tolua_bind_anl_CArray2Dd_multiplyArray00);
 tolua_function(tolua_S,"copyFromSub",tolua_bind_anl_CArray2Dd_copyFromSub00);
 tolua_function(tolua_S,"addArraySub",tolua_bind_anl_CArray2Dd_addArraySub00);
 tolua_function(tolua_S,"subtractArraySub",tolua_bind_anl_CArray2Dd_subtractArraySub00);
 tolua_function(tolua_S,"multiplyArraySub",tolua_bind_anl_CArray2Dd_multiplyArraySub00);
 tolua_function(tolua_S,"scale",tolua_bind_anl_CArray2Dd_scale00);
 tolua_function(tolua_S,"getMax",tolua_bind_anl_CArray2Dd_getMax00);
 tolua_function(tolua_S,"getMin",tolua_bind_anl_CArray2Dd_getMin00);
 tolua_function(tolua_S,"scaleToRange",tolua_bind_anl_CArray2Dd_scaleToRange00);
 tolua_function(tolua_S,"wrapCoords",tolua_bind_anl_CArray2Dd_wrapCoords00);
 tolua_function(tolua_S,"offset",tolua_bind_anl_CArray2Dd_offset00);
 tolua_function(tolua_S,"flipVertical",tolua_bind_anl_CArray2Dd_flipVertical00);
 tolua_function(tolua_S,"flipHorizontal",tolua_bind_anl_CArray2Dd_flipHorizontal00);
 tolua_function(tolua_S,"blur",tolua_bind_anl_CArray2Dd_blur00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"CArray2Drgba","CArray2Drgba","",tolua_collect_CArray2Drgba);
#else
 tolua_cclass(tolua_S,"CArray2Drgba","CArray2Drgba","",NULL);
#endif
 tolua_beginmodule(tolua_S,"CArray2Drgba");
 tolua_function(tolua_S,"new",tolua_bind_anl_CArray2Drgba_new00);
 tolua_function(tolua_S,"new",tolua_bind_anl_CArray2Drgba_new01);
 tolua_function(tolua_S,"delete",tolua_bind_anl_CArray2Drgba_delete00);
 tolua_function(tolua_S,"resize",tolua_bind_anl_CArray2Drgba_resize00);
 tolua_function(tolua_S,"destroy",tolua_bind_anl_CArray2Drgba_destroy00);
 tolua_function(tolua_S,"width",tolua_bind_anl_CArray2Drgba_width00);
 tolua_function(tolua_S,"height",tolua_bind_anl_CArray2Drgba_height00);
 tolua_function(tolua_S,"set",tolua_bind_anl_CArray2Drgba_set00);
 tolua_function(tolua_S,"get",tolua_bind_anl_CArray2Drgba_get00);
 tolua_function(tolua_S,"get",tolua_bind_anl_CArray2Drgba_get01);
 tolua_function(tolua_S,"getIndexed",tolua_bind_anl_CArray2Drgba_getIndexed00);
 tolua_function(tolua_S,"getBilinear",tolua_bind_anl_CArray2Drgba_getBilinear00);
 tolua_function(tolua_S,"fill",tolua_bind_anl_CArray2Drgba_fill00);
 tolua_function(tolua_S,"copyFrom",tolua_bind_anl_CArray2Drgba_copyFrom00);
 tolua_function(tolua_S,"addArray",tolua_bind_anl_CArray2Drgba_addArray00);
 tolua_function(tolua_S,"subtractArray",tolua_bind_anl_CArray2Drgba_subtractArray00);
 tolua_function(tolua_S,"multiplyArray",tolua_bind_anl_CArray2Drgba_multiplyArray00);
 tolua_function(tolua_S,"copyFromSub",tolua_bind_anl_CArray2Drgba_copyFromSub00);
 tolua_function(tolua_S,"addArraySub",tolua_bind_anl_CArray2Drgba_addArraySub00);
 tolua_function(tolua_S,"subtractArraySub",tolua_bind_anl_CArray2Drgba_subtractArraySub00);
 tolua_function(tolua_S,"multiplyArraySub",tolua_bind_anl_CArray2Drgba_multiplyArraySub00);
 tolua_function(tolua_S,"scale",tolua_bind_anl_CArray2Drgba_scale00);
 tolua_function(tolua_S,"wrapCoords",tolua_bind_anl_CArray2Drgba_wrapCoords00);
 tolua_function(tolua_S,"offset",tolua_bind_anl_CArray2Drgba_offset00);
 tolua_function(tolua_S,"flipVertical",tolua_bind_anl_CArray2Drgba_flipVertical00);
 tolua_function(tolua_S,"flipHorizontal",tolua_bind_anl_CArray2Drgba_flipHorizontal00);
 tolua_function(tolua_S,"blur",tolua_bind_anl_CArray2Drgba_blur00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"CArray3Dd","CArray3Dd","",tolua_collect_CArray3Dd);
#else
 tolua_cclass(tolua_S,"CArray3Dd","CArray3Dd","",NULL);
#endif
 tolua_beginmodule(tolua_S,"CArray3Dd");
 tolua_function(tolua_S,"new",tolua_bind_anl_CArray3Dd_new00);
 tolua_function(tolua_S,"new",tolua_bind_anl_CArray3Dd_new01);
 tolua_function(tolua_S,"delete",tolua_bind_anl_CArray3Dd_delete00);
 tolua_function(tolua_S,"width",tolua_bind_anl_CArray3Dd_width00);
 tolua_function(tolua_S,"height",tolua_bind_anl_CArray3Dd_height00);
 tolua_function(tolua_S,"depth",tolua_bind_anl_CArray3Dd_depth00);
 tolua_function(tolua_S,"set",tolua_bind_anl_CArray3Dd_set00);
 tolua_function(tolua_S,"get",tolua_bind_anl_CArray3Dd_get00);
 tolua_function(tolua_S,"resize",tolua_bind_anl_CArray3Dd_resize00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"CArray3Drgba","CArray3Drgba","",tolua_collect_CArray3Drgba);
#else
 tolua_cclass(tolua_S,"CArray3Drgba","CArray3Drgba","",NULL);
#endif
 tolua_beginmodule(tolua_S,"CArray3Drgba");
 tolua_function(tolua_S,"new",tolua_bind_anl_CArray3Drgba_new00);
 tolua_function(tolua_S,"new",tolua_bind_anl_CArray3Drgba_new01);
 tolua_function(tolua_S,"delete",tolua_bind_anl_CArray3Drgba_delete00);
 tolua_function(tolua_S,"width",tolua_bind_anl_CArray3Drgba_width00);
 tolua_function(tolua_S,"height",tolua_bind_anl_CArray3Drgba_height00);
 tolua_function(tolua_S,"depth",tolua_bind_anl_CArray3Drgba_depth00);
 tolua_function(tolua_S,"resize",tolua_bind_anl_CArray3Drgba_resize00);
 tolua_function(tolua_S,"set",tolua_bind_anl_CArray3Drgba_set00);
 tolua_function(tolua_S,"get",tolua_bind_anl_CArray3Drgba_get00);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"map2D",tolua_bind_anl_map2D00);
 tolua_function(tolua_S,"map2DNoZ",tolua_bind_anl_map2DNoZ00);
 tolua_function(tolua_S,"map3D",tolua_bind_anl_map3D00);
 tolua_function(tolua_S,"mapRGBA2D",tolua_bind_anl_mapRGBA2D00);
 tolua_function(tolua_S,"mapRGBA2DNoZ",tolua_bind_anl_mapRGBA2DNoZ00);
 tolua_function(tolua_S,"mapRGBA3D",tolua_bind_anl_mapRGBA3D00);
 tolua_function(tolua_S,"saveDoubleArray",tolua_bind_anl_saveDoubleArray00);
 tolua_function(tolua_S,"saveRGBAArray",tolua_bind_anl_saveRGBAArray00);
 tolua_function(tolua_S,"loadDoubleArray",tolua_bind_anl_loadDoubleArray00);
 tolua_function(tolua_S,"loadRGBAArray",tolua_bind_anl_loadRGBAArray00);
 tolua_function(tolua_S,"map2DThread",tolua_bind_anl_map2DThread00);
 tolua_function(tolua_S,"map2DNoThread",tolua_bind_anl_map2DNoThread00);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_bind_anl_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_bind_anl);
 lua_pushstring(tolua_S, "bind_anl");
 lua_call(tolua_S, 1, 0);
 return 1;
}
