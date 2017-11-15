/*
** Lua binding: bind_anl
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int tolua_bind_anl_open (lua_State* tolua_S);

#include "../anl.h"
using namespace anl;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_CNoiseExecutor (lua_State* tolua_S)
{
 CNoiseExecutor* self = (CNoiseExecutor*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_SMappingRanges (lua_State* tolua_S)
{
 SMappingRanges* self = (SMappingRanges*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_CArray3Drgba (lua_State* tolua_S)
{
 CArray3Drgba* self = (CArray3Drgba*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_SVMOutput (lua_State* tolua_S)
{
 SVMOutput* self = (SVMOutput*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_KISS (lua_State* tolua_S)
{
 KISS* self = (KISS*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_CArray2Drgba (lua_State* tolua_S)
{
 CArray2Drgba* self = (CArray2Drgba*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_CArray2Dd (lua_State* tolua_S)
{
 CArray2Dd* self = (CArray2Dd*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_MWC256 (lua_State* tolua_S)
{
 MWC256* self = (MWC256*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_CMWC4096 (lua_State* tolua_S)
{
 CMWC4096* self = (CMWC4096*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_CArray3Dd (lua_State* tolua_S)
{
 CArray3Dd* self = (CArray3Dd*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_LCG (lua_State* tolua_S)
{
 LCG* self = (LCG*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_CCoordinate (lua_State* tolua_S)
{
 CCoordinate* self = (CCoordinate*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_Xorshift (lua_State* tolua_S)
{
 Xorshift* self = (Xorshift*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_CExpressionBuilder (lua_State* tolua_S)
{
 CExpressionBuilder* self = (CExpressionBuilder*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_SRGBA (lua_State* tolua_S)
{
 SRGBA* self = (SRGBA*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_anl__SRGBA (lua_State* tolua_S)
{
 anl::SRGBA* self = (anl::SRGBA*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_CInstructionIndex (lua_State* tolua_S)
{
 CInstructionIndex* self = (CInstructionIndex*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}

static int tolua_collect_CKernel (lua_State* tolua_S)
{
 CKernel* self = (CKernel*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CInstructionListType");
 tolua_usertype(tolua_S,"CNoiseExecutor");
 tolua_usertype(tolua_S,"SMappingRanges");
 tolua_usertype(tolua_S,"CArray3Drgba");
 tolua_usertype(tolua_S,"SVMOutput");
 tolua_usertype(tolua_S,"KISS");
 tolua_usertype(tolua_S,"InstructionListType");
 tolua_usertype(tolua_S,"CArray2Dd");
 tolua_usertype(tolua_S,"MWC256");
 tolua_usertype(tolua_S,"CMWC4096");
 tolua_usertype(tolua_S,"CBasePRNG");
 tolua_usertype(tolua_S,"CArray3Dd");
 tolua_usertype(tolua_S,"CInstructionIndex");
 tolua_usertype(tolua_S,"CCoordinate");
 tolua_usertype(tolua_S,"CArray2Drgba");
 tolua_usertype(tolua_S,"CExpressionBuilder");
 tolua_usertype(tolua_S,"Xorshift");
 tolua_usertype(tolua_S,"anl::SMappingRanges");
 tolua_usertype(tolua_S,"SRGBA");
 tolua_usertype(tolua_S,"anl::SRGBA");
 tolua_usertype(tolua_S,"LCG");
 tolua_usertype(tolua_S,"CKernel");
}

/* function: highresTime */
#ifndef TOLUA_DISABLE_tolua_bind_anl_highresTime00
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
#endif //#ifndef TOLUA_DISABLE

/* method: get of class  CBasePRNG */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CBasePRNG_get00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: setSeed of class  CBasePRNG */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CBasePRNG_setSeed00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSeed'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: setSeedTime of class  CBasePRNG */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CBasePRNG_setSeedTime00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSeedTime'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: getTarget of class  CBasePRNG */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CBasePRNG_getTarget00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTarget'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: getRange of class  CBasePRNG */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CBasePRNG_getRange00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRange'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: get01 of class  CBasePRNG */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CBasePRNG_get0100
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get01'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  LCG */
#ifndef TOLUA_DISABLE_tolua_bind_anl_LCG_new00
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
  LCG* tolua_ret = (LCG*)  Mtolua_new((LCG)());
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
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  LCG */
#ifndef TOLUA_DISABLE_tolua_bind_anl_LCG_new00_local
static int tolua_bind_anl_LCG_new00_local(lua_State* tolua_S)
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
  LCG* tolua_ret = (LCG*)  Mtolua_new((LCG)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"LCG");
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

/* method: delete of class  LCG */
#ifndef TOLUA_DISABLE_tolua_bind_anl_LCG_delete00
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

/* method: new of class  Xorshift */
#ifndef TOLUA_DISABLE_tolua_bind_anl_Xorshift_new00
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
  Xorshift* tolua_ret = (Xorshift*)  Mtolua_new((Xorshift)());
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
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Xorshift */
#ifndef TOLUA_DISABLE_tolua_bind_anl_Xorshift_new00_local
static int tolua_bind_anl_Xorshift_new00_local(lua_State* tolua_S)
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
  Xorshift* tolua_ret = (Xorshift*)  Mtolua_new((Xorshift)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Xorshift");
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

/* method: delete of class  Xorshift */
#ifndef TOLUA_DISABLE_tolua_bind_anl_Xorshift_delete00
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

/* method: new of class  MWC256 */
#ifndef TOLUA_DISABLE_tolua_bind_anl_MWC256_new00
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
  MWC256* tolua_ret = (MWC256*)  Mtolua_new((MWC256)());
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
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  MWC256 */
#ifndef TOLUA_DISABLE_tolua_bind_anl_MWC256_new00_local
static int tolua_bind_anl_MWC256_new00_local(lua_State* tolua_S)
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
  MWC256* tolua_ret = (MWC256*)  Mtolua_new((MWC256)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"MWC256");
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

/* method: delete of class  MWC256 */
#ifndef TOLUA_DISABLE_tolua_bind_anl_MWC256_delete00
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

/* method: new of class  CMWC4096 */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CMWC4096_new00
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
  CMWC4096* tolua_ret = (CMWC4096*)  Mtolua_new((CMWC4096)());
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
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CMWC4096 */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CMWC4096_new00_local
static int tolua_bind_anl_CMWC4096_new00_local(lua_State* tolua_S)
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
  CMWC4096* tolua_ret = (CMWC4096*)  Mtolua_new((CMWC4096)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CMWC4096");
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

/* method: delete of class  CMWC4096 */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CMWC4096_delete00
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

/* method: new of class  KISS */
#ifndef TOLUA_DISABLE_tolua_bind_anl_KISS_new00
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
  KISS* tolua_ret = (KISS*)  Mtolua_new((KISS)());
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
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  KISS */
#ifndef TOLUA_DISABLE_tolua_bind_anl_KISS_new00_local
static int tolua_bind_anl_KISS_new00_local(lua_State* tolua_S)
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
  KISS* tolua_ret = (KISS*)  Mtolua_new((KISS)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"KISS");
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

/* method: delete of class  KISS */
#ifndef TOLUA_DISABLE_tolua_bind_anl_KISS_delete00
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

/* method: new of class  CCoordinate */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CCoordinate_new00
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
  CCoordinate* tolua_ret = (CCoordinate*)  Mtolua_new((CCoordinate)());
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
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCoordinate */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CCoordinate_new00_local
static int tolua_bind_anl_CCoordinate_new00_local(lua_State* tolua_S)
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
  CCoordinate* tolua_ret = (CCoordinate*)  Mtolua_new((CCoordinate)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCoordinate");
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

/* method: new of class  CCoordinate */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CCoordinate_new01
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
  CCoordinate* tolua_ret = (CCoordinate*)  Mtolua_new((CCoordinate)(x,y));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCoordinate");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCoordinate */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CCoordinate_new01_local
static int tolua_bind_anl_CCoordinate_new01_local(lua_State* tolua_S)
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
  CCoordinate* tolua_ret = (CCoordinate*)  Mtolua_new((CCoordinate)(x,y));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCoordinate");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCoordinate */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CCoordinate_new02
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
  CCoordinate* tolua_ret = (CCoordinate*)  Mtolua_new((CCoordinate)(x,y,z));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCoordinate");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCoordinate */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CCoordinate_new02_local
static int tolua_bind_anl_CCoordinate_new02_local(lua_State* tolua_S)
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
  CCoordinate* tolua_ret = (CCoordinate*)  Mtolua_new((CCoordinate)(x,y,z));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCoordinate");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCoordinate */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CCoordinate_new03
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
  CCoordinate* tolua_ret = (CCoordinate*)  Mtolua_new((CCoordinate)(x,y,z,w));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCoordinate");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCoordinate */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CCoordinate_new03_local
static int tolua_bind_anl_CCoordinate_new03_local(lua_State* tolua_S)
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
  CCoordinate* tolua_ret = (CCoordinate*)  Mtolua_new((CCoordinate)(x,y,z,w));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCoordinate");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCoordinate */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CCoordinate_new04
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
  CCoordinate* tolua_ret = (CCoordinate*)  Mtolua_new((CCoordinate)(x,y,z,w,u,v));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCoordinate");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_new03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCoordinate */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CCoordinate_new04_local
static int tolua_bind_anl_CCoordinate_new04_local(lua_State* tolua_S)
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
  CCoordinate* tolua_ret = (CCoordinate*)  Mtolua_new((CCoordinate)(x,y,z,w,u,v));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCoordinate");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_new03_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCoordinate */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CCoordinate_new05
static int tolua_bind_anl_CCoordinate_new05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CCoordinate",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCoordinate",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const CCoordinate* c = ((const CCoordinate*)  tolua_tousertype(tolua_S,2,0));
 {
  CCoordinate* tolua_ret = (CCoordinate*)  Mtolua_new((CCoordinate)(*c));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCoordinate");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_new04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCoordinate */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CCoordinate_new05_local
static int tolua_bind_anl_CCoordinate_new05_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CCoordinate",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCoordinate",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const CCoordinate* c = ((const CCoordinate*)  tolua_tousertype(tolua_S,2,0));
 {
  CCoordinate* tolua_ret = (CCoordinate*)  Mtolua_new((CCoordinate)(*c));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCoordinate");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_new04_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  CCoordinate */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CCoordinate_set00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  CCoordinate */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CCoordinate_set01
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
 {
  self->set(x,y,z);
 }
 }
 return 0;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_set00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  CCoordinate */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CCoordinate_set02
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
 {
  self->set(x,y,z,w);
 }
 }
 return 0;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_set01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  CCoordinate */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CCoordinate_set03
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
 {
  self->set(x,y,z,w,u,v);
 }
 }
 return 0;
tolua_lerror:
 return tolua_bind_anl_CCoordinate_set02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_new00
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
  CKernel* tolua_ret = (CKernel*)  Mtolua_new((CKernel)());
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
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_new00_local
static int tolua_bind_anl_CKernel_new00_local(lua_State* tolua_S)
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
  CKernel* tolua_ret = (CKernel*)  Mtolua_new((CKernel)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CKernel");
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

/* method: delete of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_delete00
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

/* method: pi of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_pi00
static int tolua_bind_anl_CKernel_pi00(lua_State* tolua_S)
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pi'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->pi();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pi'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: e of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_e00
static int tolua_bind_anl_CKernel_e00(lua_State* tolua_S)
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'e'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->e();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'e'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: one of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_one00
static int tolua_bind_anl_CKernel_one00(lua_State* tolua_S)
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'one'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->one();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'one'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: zero of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_zero00
static int tolua_bind_anl_CKernel_zero00(lua_State* tolua_S)
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'zero'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->zero();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'zero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: point5 of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_point500
static int tolua_bind_anl_CKernel_point500(lua_State* tolua_S)
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'point5'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->point5();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'point5'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sqrt2 of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_sqrt200
static int tolua_bind_anl_CKernel_sqrt200(lua_State* tolua_S)
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sqrt2'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->sqrt2();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sqrt2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: constant of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_constant00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'constant'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->constant(val);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: seed of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_seed00
static int tolua_bind_anl_CKernel_seed00(lua_State* tolua_S)
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
  unsigned int val = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'seed'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->seed(val);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'seed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: seeder of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_seeder00
static int tolua_bind_anl_CKernel_seeder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex seed = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'seeder'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->seeder(seed,src);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'seeder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: valueBasis of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_valueBasis00
static int tolua_bind_anl_CKernel_valueBasis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex interpindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex seed = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'valueBasis'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->valueBasis(interpindex,seed);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: gradientBasis of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_gradientBasis00
static int tolua_bind_anl_CKernel_gradientBasis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex interpindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex seed = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'gradientBasis'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->gradientBasis(interpindex,seed);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: simplexBasis of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_simplexBasis00
static int tolua_bind_anl_CKernel_simplexBasis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex seed = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'simplexBasis'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->simplexBasis(seed);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: cellularBasis of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_cellularBasis00
static int tolua_bind_anl_CKernel_cellularBasis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_isusertype(tolua_S,7,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_isusertype(tolua_S,8,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,9,&tolua_err) || !tolua_isusertype(tolua_S,9,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,10,&tolua_err) || !tolua_isusertype(tolua_S,10,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,11,&tolua_err) || !tolua_isusertype(tolua_S,11,"CInstructionIndex",0,&tolua_err)) ||
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
  CInstructionIndex seed = *((CInstructionIndex*)  tolua_tousertype(tolua_S,11,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cellularBasis'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->cellularBasis(f1,f2,f3,f4,d1,d2,d3,d4,dist,seed);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_add00
static int tolua_bind_anl_CKernel_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->add(s1index,s2index);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: subtract of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_subtract00
static int tolua_bind_anl_CKernel_subtract00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'subtract'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->subtract(s1,s2);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: multiply of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_multiply00
static int tolua_bind_anl_CKernel_multiply00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'multiply'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->multiply(s1index,s2index);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: divide of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_divide00
static int tolua_bind_anl_CKernel_divide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'divide'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->divide(s1,s2);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: maximum of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_maximum00
static int tolua_bind_anl_CKernel_maximum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'maximum'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->maximum(s1index,s2index);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: minimum of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_minimum00
static int tolua_bind_anl_CKernel_minimum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'minimum'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->minimum(s1index,s2index);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: abs of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_abs00
static int tolua_bind_anl_CKernel_abs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex sindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'abs'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->abs(sindex);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: pow of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_pow00
static int tolua_bind_anl_CKernel_pow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pow'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->pow(s1,s2);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: bias of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_bias00
static int tolua_bind_anl_CKernel_bias00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'bias'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->bias(s1,s2);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: gain of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_gain00
static int tolua_bind_anl_CKernel_gain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'gain'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->gain(s1,s2);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: scaleDomain of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_scaleDomain00
static int tolua_bind_anl_CKernel_scaleDomain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex srcindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex scale = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleDomain'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->scaleDomain(srcindex,scale);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: scaleX of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_scaleX00
static int tolua_bind_anl_CKernel_scaleX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleX'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->scaleX(src,scale);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: scaleY of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_scaleY00
static int tolua_bind_anl_CKernel_scaleY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleY'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->scaleY(src,scale);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: scaleZ of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_scaleZ00
static int tolua_bind_anl_CKernel_scaleZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleZ'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->scaleZ(src,scale);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: scaleW of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_scaleW00
static int tolua_bind_anl_CKernel_scaleW00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleW'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->scaleW(src,scale);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: scaleU of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_scaleU00
static int tolua_bind_anl_CKernel_scaleU00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleU'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->scaleU(src,scale);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: scaleV of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_scaleV00
static int tolua_bind_anl_CKernel_scaleV00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleV'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->scaleV(src,scale);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: translateDomain of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_translateDomain00
static int tolua_bind_anl_CKernel_translateDomain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex srcindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex trans = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateDomain'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->translateDomain(srcindex,trans);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: translateX of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_translateX00
static int tolua_bind_anl_CKernel_translateX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateX'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->translateX(src,trans);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: translateY of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_translateY00
static int tolua_bind_anl_CKernel_translateY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateY'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->translateY(src,trans);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: translateZ of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_translateZ00
static int tolua_bind_anl_CKernel_translateZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateZ'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->translateZ(src,trans);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: translateW of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_translateW00
static int tolua_bind_anl_CKernel_translateW00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateW'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->translateW(src,trans);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: translateU of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_translateU00
static int tolua_bind_anl_CKernel_translateU00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateU'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->translateU(src,trans);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: translateV of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_translateV00
static int tolua_bind_anl_CKernel_translateV00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateV'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->translateV(src,trans);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: rotateDomain of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_rotateDomain00
static int tolua_bind_anl_CKernel_rotateDomain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateDomain'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->rotateDomain(src,angle,ax,ay,az);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: addSequence of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_addSequence00
static int tolua_bind_anl_CKernel_addSequence00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addSequence'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->addSequence(baseindex,number,stride);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: multiplySequence of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_multiplySequence00
static int tolua_bind_anl_CKernel_multiplySequence00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'multiplySequence'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->multiplySequence(baseindex,number,stride);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: maxSequence of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_maxSequence00
static int tolua_bind_anl_CKernel_maxSequence00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'maxSequence'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->maxSequence(baseindex,number,stride);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: minSequence of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_minSequence00
static int tolua_bind_anl_CKernel_minSequence00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'minSequence'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->minSequence(baseindex,number,stride);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: mix of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_mix00
static int tolua_bind_anl_CKernel_mix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mix'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->mix(low,high,control);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: select of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_select00
static int tolua_bind_anl_CKernel_select00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'select'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->select(low,high,control,threshold,falloff);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: clamp of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_clamp00
static int tolua_bind_anl_CKernel_clamp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clamp'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->clamp(src,low,high);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: cos of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_cos00
static int tolua_bind_anl_CKernel_cos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cos'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->cos(src);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: sin of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_sin00
static int tolua_bind_anl_CKernel_sin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sin'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->sin(src);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: tan of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_tan00
static int tolua_bind_anl_CKernel_tan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'tan'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->tan(src);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: acos of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_acos00
static int tolua_bind_anl_CKernel_acos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'acos'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->acos(src);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: asin of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_asin00
static int tolua_bind_anl_CKernel_asin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'asin'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->asin(src);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: atan of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_atan00
static int tolua_bind_anl_CKernel_atan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'atan'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->atan(src);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: tiers of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_tiers00
static int tolua_bind_anl_CKernel_tiers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'tiers'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->tiers(src,numtiers);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: smoothTiers of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_smoothTiers00
static int tolua_bind_anl_CKernel_smoothTiers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'smoothTiers'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->smoothTiers(src,numtiers);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: x of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_x00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'x'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->x();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: y of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_y00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'y'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->y();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: z of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_z00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'z'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->z();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: w of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_w00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'w'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->w();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: u of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_u00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'u'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->u();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: v of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_v00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'v'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->v();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: dx of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_dx00
static int tolua_bind_anl_CKernel_dx00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex spacing = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dx'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->dx(src,spacing);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dx'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dy of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_dy00
static int tolua_bind_anl_CKernel_dy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex spacing = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dy'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->dy(src,spacing);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dz of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_dz00
static int tolua_bind_anl_CKernel_dz00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex spacing = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dz'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->dz(src,spacing);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dz'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dw of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_dw00
static int tolua_bind_anl_CKernel_dw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex spacing = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dw'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->dw(src,spacing);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: du of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_du00
static int tolua_bind_anl_CKernel_du00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex spacing = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'du'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->du(src,spacing);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'du'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dv of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_dv00
static int tolua_bind_anl_CKernel_dv00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex spacing = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dv'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->dv(src,spacing);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dv'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sigmoid of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_sigmoid00
static int tolua_bind_anl_CKernel_sigmoid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sigmoid'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->sigmoid(src);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sigmoid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sigmoid of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_sigmoid01
static int tolua_bind_anl_CKernel_sigmoid01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex src = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex center = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex ramp = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sigmoid'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->sigmoid(src,center,ramp);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CKernel_sigmoid00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: fractal of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_fractal00
static int tolua_bind_anl_CKernel_fractal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_isusertype(tolua_S,7,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex seed = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex layer = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex persistence = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex lacunarity = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
  CInstructionIndex numoctaves = *((CInstructionIndex*)  tolua_tousertype(tolua_S,6,0));
  CInstructionIndex freq = *((CInstructionIndex*)  tolua_tousertype(tolua_S,7,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fractal'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->fractal(seed,layer,persistence,lacunarity,numoctaves,freq);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fractal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: randomize of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_randomize00
static int tolua_bind_anl_CKernel_randomize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex seed = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex low = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex high = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'randomize'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->randomize(seed,low,high);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'randomize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: step of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_step00
static int tolua_bind_anl_CKernel_step00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex val = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex control = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'step'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->step(val,control);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'step'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: linearStep of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_linearStep00
static int tolua_bind_anl_CKernel_linearStep00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'linearStep'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->linearStep(low,high,control);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'linearStep'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: smoothStep of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_smoothStep00
static int tolua_bind_anl_CKernel_smoothStep00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'smoothStep'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->smoothStep(low,high,control);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'smoothStep'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: smootherStep of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_smootherStep00
static int tolua_bind_anl_CKernel_smootherStep00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'smootherStep'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->smootherStep(low,high,control);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'smootherStep'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: curveSection of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_curveSection00
static int tolua_bind_anl_CKernel_curveSection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_isusertype(tolua_S,7,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex lowv = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex t0 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex t1 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex v0 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
  CInstructionIndex v1 = *((CInstructionIndex*)  tolua_tousertype(tolua_S,6,0));
  CInstructionIndex control = *((CInstructionIndex*)  tolua_tousertype(tolua_S,7,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'curveSection'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->curveSection(lowv,t0,t1,v0,v1,control);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'curveSection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: radial of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_radial00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'radial'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->radial();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: hexTile of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_hexTile00
static int tolua_bind_anl_CKernel_hexTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex seed = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hexTile'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->hexTile(seed);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: hexBump of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_hexBump00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hexBump'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->hexBump();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: color of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_color00
static int tolua_bind_anl_CKernel_color00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"SRGBA",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  SRGBA c = *((SRGBA*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'color'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->color(c);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'color'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: color of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_color01
static int tolua_bind_anl_CKernel_color01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
  float g = ((float)  tolua_tonumber(tolua_S,3,0));
  float b = ((float)  tolua_tonumber(tolua_S,4,0));
  float a = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'color'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->color(r,g,b,a);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CKernel_color00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: combineRGBA of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_combineRGBA00
static int tolua_bind_anl_CKernel_combineRGBA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'combineRGBA'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->combineRGBA(r,g,b,a);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: combineHSVA of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_combineHSVA00
static int tolua_bind_anl_CKernel_combineHSVA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex h = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex s = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex v = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex a = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'combineHSVA'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->combineHSVA(h,s,v,a);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'combineHSVA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scaleOffset of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_scaleOffset00
static int tolua_bind_anl_CKernel_scaleOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleOffset'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->scaleOffset(src,scale,offset);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: simpleFractalLayer of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_simpleFractalLayer00
static int tolua_bind_anl_CKernel_simpleFractalLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'simpleFractalLayer'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->simpleFractalLayer(basistype,interptypeindex,layerscale,layerfreq,seed,rot,angle,ax,ay,az);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: simpleRidgedLayer of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_simpleRidgedLayer00
static int tolua_bind_anl_CKernel_simpleRidgedLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'simpleRidgedLayer'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->simpleRidgedLayer(basistype,interptypeindex,layerscale,layerfreq,seed,rot,angle,ax,ay,az);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: simpleBillowLayer of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_simpleBillowLayer00
static int tolua_bind_anl_CKernel_simpleBillowLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'simpleBillowLayer'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->simpleBillowLayer(basistype,interptypeindex,layerscale,layerfreq,seed,rot,angle,ax,ay,az);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'simpleBillowLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: simplefBm of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_simplefBm00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'simplefBm'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->simplefBm(basistype,interptype,numoctaves,frequency,seed,rot);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: simpleRidgedMultifractal of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_simpleRidgedMultifractal00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'simpleRidgedMultifractal'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->simpleRidgedMultifractal(basistype,interptype,numoctaves,frequency,seed,rot);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: simpleBillow of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_simpleBillow00
static int tolua_bind_anl_CKernel_simpleBillow00(lua_State* tolua_S)
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'simpleBillow'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->simpleBillow(basistype,interptype,numoctaves,frequency,seed,rot);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'simpleBillow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getKernel of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_getKernel00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getKernel'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: lastIndex of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_lastIndex00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lastIndex'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->lastIndex();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: nextIndex of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_nextIndex00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'nextIndex'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->nextIndex();
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: getVar of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_getVar00
static int tolua_bind_anl_CKernel_getVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVar'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->getVar(name);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVar of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_setVar00
static int tolua_bind_anl_CKernel_setVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  double val = ((double)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVar'", NULL);
#endif
 {
  self->setVar(name,val);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SRGBA_new00
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
  SRGBA* tolua_ret = (SRGBA*)  Mtolua_new((SRGBA)());
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
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SRGBA_new00_local
static int tolua_bind_anl_SRGBA_new00_local(lua_State* tolua_S)
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
  SRGBA* tolua_ret = (SRGBA*)  Mtolua_new((SRGBA)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SRGBA");
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

/* method: new of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SRGBA_new01
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
  SRGBA* tolua_ret = (SRGBA*)  Mtolua_new((SRGBA)(a));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SRGBA");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_SRGBA_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SRGBA_new01_local
static int tolua_bind_anl_SRGBA_new01_local(lua_State* tolua_S)
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
  SRGBA* tolua_ret = (SRGBA*)  Mtolua_new((SRGBA)(a));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SRGBA");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_SRGBA_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SRGBA_new02
static int tolua_bind_anl_SRGBA_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SRGBA",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const SRGBA",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const SRGBA* tvec = ((const SRGBA*)  tolua_tousertype(tolua_S,2,0));
 {
  SRGBA* tolua_ret = (SRGBA*)  Mtolua_new((SRGBA)(*tvec));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SRGBA");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_SRGBA_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SRGBA_new02_local
static int tolua_bind_anl_SRGBA_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SRGBA",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const SRGBA",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const SRGBA* tvec = ((const SRGBA*)  tolua_tousertype(tolua_S,2,0));
 {
  SRGBA* tolua_ret = (SRGBA*)  Mtolua_new((SRGBA)(*tvec));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SRGBA");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_SRGBA_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SRGBA_new03
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
  SRGBA* tolua_ret = (SRGBA*)  Mtolua_new((SRGBA)(t1,t2,t3,t4));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SRGBA");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_SRGBA_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SRGBA_new03_local
static int tolua_bind_anl_SRGBA_new03_local(lua_State* tolua_S)
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
  SRGBA* tolua_ret = (SRGBA*)  Mtolua_new((SRGBA)(t1,t2,t3,t4));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SRGBA");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_SRGBA_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SRGBA_delete00
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

/* get function: r of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_get_SRGBA_r
static int tolua_get_SRGBA_r(lua_State* tolua_S)
{
  SRGBA* self = (SRGBA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->r);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: r of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_set_SRGBA_r
static int tolua_set_SRGBA_r(lua_State* tolua_S)
{
  SRGBA* self = (SRGBA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->r = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: g of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_get_SRGBA_g
static int tolua_get_SRGBA_g(lua_State* tolua_S)
{
  SRGBA* self = (SRGBA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->g);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: g of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_set_SRGBA_g
static int tolua_set_SRGBA_g(lua_State* tolua_S)
{
  SRGBA* self = (SRGBA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->g = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: b of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_get_SRGBA_b
static int tolua_get_SRGBA_b(lua_State* tolua_S)
{
  SRGBA* self = (SRGBA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->b);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: b of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_set_SRGBA_b
static int tolua_set_SRGBA_b(lua_State* tolua_S)
{
  SRGBA* self = (SRGBA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->b = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: a of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_get_SRGBA_a
static int tolua_get_SRGBA_a(lua_State* tolua_S)
{
  SRGBA* self = (SRGBA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->a);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: a of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_set_SRGBA_a
static int tolua_set_SRGBA_a(lua_State* tolua_S)
{
  SRGBA* self = (SRGBA*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->a = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: outfloat_ of class  SVMOutput */
#ifndef TOLUA_DISABLE_tolua_get_SVMOutput_outfloat_
static int tolua_get_SVMOutput_outfloat_(lua_State* tolua_S)
{
  SVMOutput* self = (SVMOutput*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'outfloat_'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->outfloat_);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: outfloat_ of class  SVMOutput */
#ifndef TOLUA_DISABLE_tolua_set_SVMOutput_outfloat_
static int tolua_set_SVMOutput_outfloat_(lua_State* tolua_S)
{
  SVMOutput* self = (SVMOutput*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'outfloat_'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->outfloat_ = ((double)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: outrgba_ of class  SVMOutput */
#ifndef TOLUA_DISABLE_tolua_get_SVMOutput_outrgba_
static int tolua_get_SVMOutput_outrgba_(lua_State* tolua_S)
{
  SVMOutput* self = (SVMOutput*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'outrgba_'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&self->outrgba_,"SRGBA");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: outrgba_ of class  SVMOutput */
#ifndef TOLUA_DISABLE_tolua_set_SVMOutput_outrgba_
static int tolua_set_SVMOutput_outrgba_(lua_State* tolua_S)
{
  SVMOutput* self = (SVMOutput*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'outrgba_'",NULL);
 if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"SRGBA",0,&tolua_err)))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->outrgba_ = *((SRGBA*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SVMOutput */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SVMOutput_new00
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
  SVMOutput* tolua_ret = (SVMOutput*)  Mtolua_new((SVMOutput)());
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
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SVMOutput */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SVMOutput_new00_local
static int tolua_bind_anl_SVMOutput_new00_local(lua_State* tolua_S)
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
  SVMOutput* tolua_ret = (SVMOutput*)  Mtolua_new((SVMOutput)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SVMOutput");
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

/* method: delete of class  SVMOutput */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SVMOutput_delete00
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

/* method: new of class  CNoiseExecutor */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CNoiseExecutor_new00
static int tolua_bind_anl_CNoiseExecutor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CNoiseExecutor",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CKernel",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* kernel = ((CKernel*)  tolua_tousertype(tolua_S,2,0));
 {
  CNoiseExecutor* tolua_ret = (CNoiseExecutor*)  Mtolua_new((CNoiseExecutor)(*kernel));
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
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CNoiseExecutor */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CNoiseExecutor_new00_local
static int tolua_bind_anl_CNoiseExecutor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CNoiseExecutor",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CKernel",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* kernel = ((CKernel*)  tolua_tousertype(tolua_S,2,0));
 {
  CNoiseExecutor* tolua_ret = (CNoiseExecutor*)  Mtolua_new((CNoiseExecutor)(*kernel));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CNoiseExecutor");
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

/* method: delete of class  CNoiseExecutor */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CNoiseExecutor_delete00
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

/* method: evaluate of class  CNoiseExecutor */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CNoiseExecutor_evaluate00
static int tolua_bind_anl_CNoiseExecutor_evaluate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CNoiseExecutor",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCoordinate",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CNoiseExecutor* self = (CNoiseExecutor*)  tolua_tousertype(tolua_S,1,0);
  CCoordinate* coord = ((CCoordinate*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'evaluate'", NULL);
#endif
 {
  SVMOutput tolua_ret = (SVMOutput)  self->evaluate(*coord);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((SVMOutput)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"SVMOutput");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(SVMOutput));
  tolua_pushusertype(tolua_S,tolua_obj,"SVMOutput");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: evaluateAt of class  CNoiseExecutor */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CNoiseExecutor_evaluateAt00
static int tolua_bind_anl_CNoiseExecutor_evaluateAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CNoiseExecutor",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCoordinate",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'evaluateAt'", NULL);
#endif
 {
  SVMOutput tolua_ret = (SVMOutput)  self->evaluateAt(*coord,index);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((SVMOutput)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"SVMOutput");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(SVMOutput));
  tolua_pushusertype(tolua_S,tolua_obj,"SVMOutput");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: evaluateScalar of class  CNoiseExecutor */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CNoiseExecutor_evaluateScalar00
static int tolua_bind_anl_CNoiseExecutor_evaluateScalar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CNoiseExecutor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CNoiseExecutor* self = (CNoiseExecutor*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  CInstructionIndex idx = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'evaluateScalar'", NULL);
#endif
 {
  double tolua_ret = (double)  self->evaluateScalar(x,y,idx);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'evaluateScalar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: evaluateScalar of class  CNoiseExecutor */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CNoiseExecutor_evaluateScalar01
static int tolua_bind_anl_CNoiseExecutor_evaluateScalar01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CNoiseExecutor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CNoiseExecutor* self = (CNoiseExecutor*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  double z = ((double)  tolua_tonumber(tolua_S,4,0));
  CInstructionIndex idx = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'evaluateScalar'", NULL);
#endif
 {
  double tolua_ret = (double)  self->evaluateScalar(x,y,z,idx);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CNoiseExecutor_evaluateScalar00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: evaluateScalar of class  CNoiseExecutor */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CNoiseExecutor_evaluateScalar02
static int tolua_bind_anl_CNoiseExecutor_evaluateScalar02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CNoiseExecutor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CNoiseExecutor* self = (CNoiseExecutor*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  double z = ((double)  tolua_tonumber(tolua_S,4,0));
  double w = ((double)  tolua_tonumber(tolua_S,5,0));
  CInstructionIndex idx = *((CInstructionIndex*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'evaluateScalar'", NULL);
#endif
 {
  double tolua_ret = (double)  self->evaluateScalar(x,y,z,w,idx);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CNoiseExecutor_evaluateScalar01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: evaluateScalar of class  CNoiseExecutor */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CNoiseExecutor_evaluateScalar03
static int tolua_bind_anl_CNoiseExecutor_evaluateScalar03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CNoiseExecutor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_isusertype(tolua_S,8,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CNoiseExecutor* self = (CNoiseExecutor*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  double z = ((double)  tolua_tonumber(tolua_S,4,0));
  double w = ((double)  tolua_tonumber(tolua_S,5,0));
  double u = ((double)  tolua_tonumber(tolua_S,6,0));
  double v = ((double)  tolua_tonumber(tolua_S,7,0));
  CInstructionIndex idx = *((CInstructionIndex*)  tolua_tousertype(tolua_S,8,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'evaluateScalar'", NULL);
#endif
 {
  double tolua_ret = (double)  self->evaluateScalar(x,y,z,w,u,v,idx);
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CNoiseExecutor_evaluateScalar02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: evaluateColor of class  CNoiseExecutor */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CNoiseExecutor_evaluateColor00
static int tolua_bind_anl_CNoiseExecutor_evaluateColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CNoiseExecutor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CNoiseExecutor* self = (CNoiseExecutor*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  CInstructionIndex idx = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'evaluateColor'", NULL);
#endif
 {
  SRGBA tolua_ret = (SRGBA)  self->evaluateColor(x,y,idx);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((SRGBA)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"SRGBA");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(SRGBA));
  tolua_pushusertype(tolua_S,tolua_obj,"SRGBA");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'evaluateColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: evaluateColor of class  CNoiseExecutor */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CNoiseExecutor_evaluateColor01
static int tolua_bind_anl_CNoiseExecutor_evaluateColor01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CNoiseExecutor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CNoiseExecutor* self = (CNoiseExecutor*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  double z = ((double)  tolua_tonumber(tolua_S,4,0));
  CInstructionIndex idx = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'evaluateColor'", NULL);
#endif
 {
  SRGBA tolua_ret = (SRGBA)  self->evaluateColor(x,y,z,idx);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((SRGBA)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"SRGBA");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(SRGBA));
  tolua_pushusertype(tolua_S,tolua_obj,"SRGBA");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CNoiseExecutor_evaluateColor00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: evaluateColor of class  CNoiseExecutor */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CNoiseExecutor_evaluateColor02
static int tolua_bind_anl_CNoiseExecutor_evaluateColor02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CNoiseExecutor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CNoiseExecutor* self = (CNoiseExecutor*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  double z = ((double)  tolua_tonumber(tolua_S,4,0));
  double w = ((double)  tolua_tonumber(tolua_S,5,0));
  CInstructionIndex idx = *((CInstructionIndex*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'evaluateColor'", NULL);
#endif
 {
  SRGBA tolua_ret = (SRGBA)  self->evaluateColor(x,y,z,w,idx);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((SRGBA)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"SRGBA");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(SRGBA));
  tolua_pushusertype(tolua_S,tolua_obj,"SRGBA");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CNoiseExecutor_evaluateColor01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: evaluateColor of class  CNoiseExecutor */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CNoiseExecutor_evaluateColor03
static int tolua_bind_anl_CNoiseExecutor_evaluateColor03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CNoiseExecutor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,8,&tolua_err) || !tolua_isusertype(tolua_S,8,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  CNoiseExecutor* self = (CNoiseExecutor*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  double z = ((double)  tolua_tonumber(tolua_S,4,0));
  double w = ((double)  tolua_tonumber(tolua_S,5,0));
  double u = ((double)  tolua_tonumber(tolua_S,6,0));
  double v = ((double)  tolua_tonumber(tolua_S,7,0));
  CInstructionIndex idx = *((CInstructionIndex*)  tolua_tousertype(tolua_S,8,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'evaluateColor'", NULL);
#endif
 {
  SRGBA tolua_ret = (SRGBA)  self->evaluateColor(x,y,z,w,u,v,idx);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((SRGBA)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"SRGBA");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(SRGBA));
  tolua_pushusertype(tolua_S,tolua_obj,"SRGBA");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CNoiseExecutor_evaluateColor02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SMappingRanges_new00
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
  SMappingRanges* tolua_ret = (SMappingRanges*)  Mtolua_new((SMappingRanges)());
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
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SMappingRanges_new00_local
static int tolua_bind_anl_SMappingRanges_new00_local(lua_State* tolua_S)
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
  SMappingRanges* tolua_ret = (SMappingRanges*)  Mtolua_new((SMappingRanges)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SMappingRanges");
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

/* method: new of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SMappingRanges_new01
static int tolua_bind_anl_SMappingRanges_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SMappingRanges",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"SMappingRanges",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  SMappingRanges* rhs = ((SMappingRanges*)  tolua_tousertype(tolua_S,2,0));
 {
  SMappingRanges* tolua_ret = (SMappingRanges*)  Mtolua_new((SMappingRanges)(*rhs));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SMappingRanges");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_SMappingRanges_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SMappingRanges_new01_local
static int tolua_bind_anl_SMappingRanges_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SMappingRanges",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"SMappingRanges",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  SMappingRanges* rhs = ((SMappingRanges*)  tolua_tousertype(tolua_S,2,0));
 {
  SMappingRanges* tolua_ret = (SMappingRanges*)  Mtolua_new((SMappingRanges)(*rhs));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SMappingRanges");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_SMappingRanges_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SMappingRanges_new02
static int tolua_bind_anl_SMappingRanges_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SMappingRanges",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const anl::SMappingRanges",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const anl::SMappingRanges* rhs = ((const anl::SMappingRanges*)  tolua_tousertype(tolua_S,2,0));
 {
  SMappingRanges* tolua_ret = (SMappingRanges*)  Mtolua_new((SMappingRanges)(*rhs));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SMappingRanges");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_SMappingRanges_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SMappingRanges_new02_local
static int tolua_bind_anl_SMappingRanges_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"SMappingRanges",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const anl::SMappingRanges",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const anl::SMappingRanges* rhs = ((const anl::SMappingRanges*)  tolua_tousertype(tolua_S,2,0));
 {
  SMappingRanges* tolua_ret = (SMappingRanges*)  Mtolua_new((SMappingRanges)(*rhs));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SMappingRanges");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_SMappingRanges_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SMappingRanges_new03
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
  SMappingRanges* tolua_ret = (SMappingRanges*)  Mtolua_new((SMappingRanges)(x0,x1,y0,y1,z0,z1));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SMappingRanges");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_SMappingRanges_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SMappingRanges_new03_local
static int tolua_bind_anl_SMappingRanges_new03_local(lua_State* tolua_S)
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
  SMappingRanges* tolua_ret = (SMappingRanges*)  Mtolua_new((SMappingRanges)(x0,x1,y0,y1,z0,z1));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"SMappingRanges");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_SMappingRanges_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SMappingRanges_delete00
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

/* get function: mapx0 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_get_SMappingRanges_mapx0
static int tolua_get_SMappingRanges_mapx0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapx0'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->mapx0);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mapx0 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_set_SMappingRanges_mapx0
static int tolua_set_SMappingRanges_mapx0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapx0'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mapx0 = ((double)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mapy0 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_get_SMappingRanges_mapy0
static int tolua_get_SMappingRanges_mapy0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapy0'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->mapy0);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mapy0 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_set_SMappingRanges_mapy0
static int tolua_set_SMappingRanges_mapy0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapy0'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mapy0 = ((double)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mapz0 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_get_SMappingRanges_mapz0
static int tolua_get_SMappingRanges_mapz0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapz0'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->mapz0);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mapz0 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_set_SMappingRanges_mapz0
static int tolua_set_SMappingRanges_mapz0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapz0'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mapz0 = ((double)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mapx1 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_get_SMappingRanges_mapx1
static int tolua_get_SMappingRanges_mapx1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapx1'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->mapx1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mapx1 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_set_SMappingRanges_mapx1
static int tolua_set_SMappingRanges_mapx1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapx1'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mapx1 = ((double)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mapy1 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_get_SMappingRanges_mapy1
static int tolua_get_SMappingRanges_mapy1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapy1'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->mapy1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mapy1 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_set_SMappingRanges_mapy1
static int tolua_set_SMappingRanges_mapy1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapy1'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mapy1 = ((double)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mapz1 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_get_SMappingRanges_mapz1
static int tolua_get_SMappingRanges_mapz1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapz1'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->mapz1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mapz1 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_set_SMappingRanges_mapz1
static int tolua_set_SMappingRanges_mapz1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mapz1'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mapz1 = ((double)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: loopx0 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_get_SMappingRanges_loopx0
static int tolua_get_SMappingRanges_loopx0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopx0'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->loopx0);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: loopx0 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_set_SMappingRanges_loopx0
static int tolua_set_SMappingRanges_loopx0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopx0'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->loopx0 = ((double)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: loopy0 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_get_SMappingRanges_loopy0
static int tolua_get_SMappingRanges_loopy0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopy0'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->loopy0);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: loopy0 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_set_SMappingRanges_loopy0
static int tolua_set_SMappingRanges_loopy0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopy0'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->loopy0 = ((double)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: loopz0 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_get_SMappingRanges_loopz0
static int tolua_get_SMappingRanges_loopz0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopz0'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->loopz0);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: loopz0 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_set_SMappingRanges_loopz0
static int tolua_set_SMappingRanges_loopz0(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopz0'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->loopz0 = ((double)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: loopx1 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_get_SMappingRanges_loopx1
static int tolua_get_SMappingRanges_loopx1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopx1'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->loopx1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: loopx1 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_set_SMappingRanges_loopx1
static int tolua_set_SMappingRanges_loopx1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopx1'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->loopx1 = ((double)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: loopy1 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_get_SMappingRanges_loopy1
static int tolua_get_SMappingRanges_loopy1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopy1'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->loopy1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: loopy1 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_set_SMappingRanges_loopy1
static int tolua_set_SMappingRanges_loopy1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopy1'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->loopy1 = ((double)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: loopz1 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_get_SMappingRanges_loopz1
static int tolua_get_SMappingRanges_loopz1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopz1'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->loopz1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: loopz1 of class  SMappingRanges */
#ifndef TOLUA_DISABLE_tolua_set_SMappingRanges_loopz1
static int tolua_set_SMappingRanges_loopz1(lua_State* tolua_S)
{
  SMappingRanges* self = (SMappingRanges*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loopz1'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->loopz1 = ((double)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CExpressionBuilder */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CExpressionBuilder_new00
static int tolua_bind_anl_CExpressionBuilder_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CExpressionBuilder",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CKernel",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* kernel = ((CKernel*)  tolua_tousertype(tolua_S,2,0));
 {
  CExpressionBuilder* tolua_ret = (CExpressionBuilder*)  Mtolua_new((CExpressionBuilder)(*kernel));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CExpressionBuilder");
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

/* method: new_local of class  CExpressionBuilder */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CExpressionBuilder_new00_local
static int tolua_bind_anl_CExpressionBuilder_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"CExpressionBuilder",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CKernel",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CKernel* kernel = ((CKernel*)  tolua_tousertype(tolua_S,2,0));
 {
  CExpressionBuilder* tolua_ret = (CExpressionBuilder*)  Mtolua_new((CExpressionBuilder)(*kernel));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CExpressionBuilder");
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

/* method: delete of class  CExpressionBuilder */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CExpressionBuilder_delete00
static int tolua_bind_anl_CExpressionBuilder_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CExpressionBuilder",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CExpressionBuilder* self = (CExpressionBuilder*)  tolua_tousertype(tolua_S,1,0);
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

/* method: eval of class  CExpressionBuilder */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CExpressionBuilder_eval00
static int tolua_bind_anl_CExpressionBuilder_eval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CExpressionBuilder",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CExpressionBuilder* self = (CExpressionBuilder*)  tolua_tousertype(tolua_S,1,0);
  const char* expr = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'eval'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->eval(expr);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'eval'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: evalAndStore of class  CExpressionBuilder */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CExpressionBuilder_evalAndStore00
static int tolua_bind_anl_CExpressionBuilder_evalAndStore00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CExpressionBuilder",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CExpressionBuilder* self = (CExpressionBuilder*)  tolua_tousertype(tolua_S,1,0);
  const char* expr = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'evalAndStore'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->evalAndStore(expr);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'evalAndStore'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: store of class  CExpressionBuilder */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CExpressionBuilder_store00
static int tolua_bind_anl_CExpressionBuilder_store00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CExpressionBuilder",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CExpressionBuilder* self = (CExpressionBuilder*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex i = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'store'", NULL);
#endif
 {
  self->store(i);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'store'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRandomSeed of class  CExpressionBuilder */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CExpressionBuilder_setRandomSeed00
static int tolua_bind_anl_CExpressionBuilder_setRandomSeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CExpressionBuilder",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CExpressionBuilder* self = (CExpressionBuilder*)  tolua_tousertype(tolua_S,1,0);
  unsigned int seed = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRandomSeed'", NULL);
#endif
 {
  self->setRandomSeed(seed);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRandomSeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: storeVar of class  CExpressionBuilder */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CExpressionBuilder_storeVar00
static int tolua_bind_anl_CExpressionBuilder_storeVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CExpressionBuilder",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CInstructionIndex",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CExpressionBuilder* self = (CExpressionBuilder*)  tolua_tousertype(tolua_S,1,0);
  const char* varname = ((const char*)  tolua_tostring(tolua_S,2,0));
  CInstructionIndex i = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'storeVar'", NULL);
#endif
 {
  self->storeVar(varname,i);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'storeVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: evalAndStoreVar of class  CExpressionBuilder */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CExpressionBuilder_evalAndStoreVar00
static int tolua_bind_anl_CExpressionBuilder_evalAndStoreVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CExpressionBuilder",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isstring(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CExpressionBuilder* self = (CExpressionBuilder*)  tolua_tousertype(tolua_S,1,0);
  const char* varname = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* expr = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'evalAndStoreVar'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->evalAndStoreVar(varname,expr);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'evalAndStoreVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: retrieveVar of class  CExpressionBuilder */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CExpressionBuilder_retrieveVar00
static int tolua_bind_anl_CExpressionBuilder_retrieveVar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CExpressionBuilder",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CExpressionBuilder* self = (CExpressionBuilder*)  tolua_tousertype(tolua_S,1,0);
  const char* varname = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'retrieveVar'", NULL);
#endif
 {
  CInstructionIndex tolua_ret = (CInstructionIndex)  self->retrieveVar(varname);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((CInstructionIndex)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CInstructionIndex));
  tolua_pushusertype(tolua_S,tolua_obj,"CInstructionIndex");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'retrieveVar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_new00
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
  CArray2Dd* tolua_ret = (CArray2Dd*)  Mtolua_new((CArray2Dd)(w,h));
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
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_new00_local
static int tolua_bind_anl_CArray2Dd_new00_local(lua_State* tolua_S)
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
  CArray2Dd* tolua_ret = (CArray2Dd*)  Mtolua_new((CArray2Dd)(w,h));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray2Dd");
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

/* method: new of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_new01
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
  CArray2Dd* tolua_ret = (CArray2Dd*)  Mtolua_new((CArray2Dd)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray2Dd");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CArray2Dd_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_new01_local
static int tolua_bind_anl_CArray2Dd_new01_local(lua_State* tolua_S)
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
  CArray2Dd* tolua_ret = (CArray2Dd*)  Mtolua_new((CArray2Dd)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray2Dd");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CArray2Dd_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_delete00
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

/* method: resize of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_resize00
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

/* method: destroy of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_destroy00
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

/* method: width of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_width00
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

/* method: height of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_height00
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

/* method: set of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_set00
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

/* method: get of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_get00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: get of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_get01
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: getIndexed of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_getIndexed00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIndexed'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: fill of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_fill00
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

/* method: copyFrom of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_copyFrom00
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

/* method: addArray of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_addArray00
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

/* method: subtractArray of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_subtractArray00
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

/* method: multiplyArray of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_multiplyArray00
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

/* method: copyFromSub of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_copyFromSub00
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

/* method: addArraySub of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_addArraySub00
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

/* method: subtractArraySub of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_subtractArraySub00
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

/* method: multiplyArraySub of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_multiplyArraySub00
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

/* method: scale of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_scale00
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

/* method: getMax of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_getMax00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMax'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: getMin of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_getMin00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMin'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: scaleToRange of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_scaleToRange00
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

/* method: bias of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_bias00
static int tolua_bind_anl_CArray2Dd_bias00(lua_State* tolua_S)
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
  float b = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'bias'", NULL);
#endif
 {
  self->bias(b);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bias'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: gain of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_gain00
static int tolua_bind_anl_CArray2Dd_gain00(lua_State* tolua_S)
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
  float g = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'gain'", NULL);
#endif
 {
  self->gain(g);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'gain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: wrapCoords of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_wrapCoords00
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

/* method: offset of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_offset00
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

/* method: flipVertical of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_flipVertical00
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

/* method: flipHorizontal of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_flipHorizontal00
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

/* method: blur of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_blur00
static int tolua_bind_anl_CArray2Dd_blur00(lua_State* tolua_S)
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
  CArray2Dd* self = (CArray2Dd*)  tolua_tousertype(tolua_S,1,0);
  float tolua_var_1 = ((float)  tolua_tonumber(tolua_S,2,0));
  bool tolua_var_2 = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'blur'", NULL);
#endif
 {
  self->blur(tolua_var_1,tolua_var_2);
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

/* method: subtractFilter of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_subtractFilter00
static int tolua_bind_anl_CArray2Dd_subtractFilter00(lua_State* tolua_S)
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
  CArray2Dd* fil = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'subtractFilter'", NULL);
#endif
 {
  self->subtractFilter(fil);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'subtractFilter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addFilter of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_addFilter00
static int tolua_bind_anl_CArray2Dd_addFilter00(lua_State* tolua_S)
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
  CArray2Dd* fil = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addFilter'", NULL);
#endif
 {
  self->addFilter(fil);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addFilter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scaleTo of class  CArray2Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Dd_scaleTo00
static int tolua_bind_anl_CArray2Dd_scaleTo00(lua_State* tolua_S)
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
  CArray2Dd* i = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleTo'", NULL);
#endif
 {
  self->scaleTo(i);
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

/* method: new of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_new00
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
  CArray2Drgba* tolua_ret = (CArray2Drgba*)  Mtolua_new((CArray2Drgba)(w,h));
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
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_new00_local
static int tolua_bind_anl_CArray2Drgba_new00_local(lua_State* tolua_S)
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
  CArray2Drgba* tolua_ret = (CArray2Drgba*)  Mtolua_new((CArray2Drgba)(w,h));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray2Drgba");
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

/* method: new of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_new01
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
  CArray2Drgba* tolua_ret = (CArray2Drgba*)  Mtolua_new((CArray2Drgba)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray2Drgba");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CArray2Drgba_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_new01_local
static int tolua_bind_anl_CArray2Drgba_new01_local(lua_State* tolua_S)
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
  CArray2Drgba* tolua_ret = (CArray2Drgba*)  Mtolua_new((CArray2Drgba)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray2Drgba");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CArray2Drgba_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_delete00
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

/* method: resize of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_resize00
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

/* method: destroy of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_destroy00
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

/* method: width of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_width00
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

/* method: height of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_height00
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

/* method: set of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_set00
static int tolua_bind_anl_CArray2Drgba_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"SRGBA",0,&tolua_err)) ||
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

/* method: get of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_get00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'", NULL);
#endif
 {
  SRGBA tolua_ret = (SRGBA)  self->get(x,y);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((SRGBA)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"SRGBA");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(SRGBA));
  tolua_pushusertype(tolua_S,tolua_obj,"SRGBA");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: get of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_get01
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'", NULL);
#endif
 {
  SRGBA tolua_ret = (SRGBA)  self->get(x,y);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((SRGBA)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"SRGBA");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(SRGBA));
  tolua_pushusertype(tolua_S,tolua_obj,"SRGBA");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CArray2Drgba_get00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getIndexed of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_getIndexed00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIndexed'", NULL);
#endif
 {
  SRGBA tolua_ret = (SRGBA)  self->getIndexed(c);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((SRGBA)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"SRGBA");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(SRGBA));
  tolua_pushusertype(tolua_S,tolua_obj,"SRGBA");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* method: fill of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_fill00
static int tolua_bind_anl_CArray2Drgba_fill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"SRGBA",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  SRGBA v = *((SRGBA*)  tolua_tousertype(tolua_S,2,0));
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

/* method: copyFrom of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_copyFrom00
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

/* method: addArray of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_addArray00
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

/* method: subtractArray of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_subtractArray00
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

/* method: multiplyArray of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_multiplyArray00
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

/* method: copyFromSub of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_copyFromSub00
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

/* method: addArraySub of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_addArraySub00
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

/* method: subtractArraySub of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_subtractArraySub00
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

/* method: multiplyArraySub of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_multiplyArraySub00
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

/* method: scale of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_scale00
static int tolua_bind_anl_CArray2Drgba_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"SRGBA",0,&tolua_err)) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  SRGBA s = *((SRGBA*)  tolua_tousertype(tolua_S,2,0));
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

/* method: wrapCoords of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_wrapCoords00
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

/* method: offset of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_offset00
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

/* method: flipVertical of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_flipVertical00
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

/* method: flipHorizontal of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_flipHorizontal00
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

/* method: blur of class  CArray2Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray2Drgba_blur00
static int tolua_bind_anl_CArray2Drgba_blur00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Drgba",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Drgba* self = (CArray2Drgba*)  tolua_tousertype(tolua_S,1,0);
  float tolua_var_3 = ((float)  tolua_tonumber(tolua_S,2,0));
  bool tolua_var_4 = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'blur'", NULL);
#endif
 {
  self->blur(tolua_var_3,tolua_var_4);
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

/* method: new of class  CArray3Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Dd_new00
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
  CArray3Dd* tolua_ret = (CArray3Dd*)  Mtolua_new((CArray3Dd)());
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
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CArray3Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Dd_new00_local
static int tolua_bind_anl_CArray3Dd_new00_local(lua_State* tolua_S)
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
  CArray3Dd* tolua_ret = (CArray3Dd*)  Mtolua_new((CArray3Dd)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray3Dd");
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

/* method: new of class  CArray3Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Dd_new01
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
  CArray3Dd* tolua_ret = (CArray3Dd*)  Mtolua_new((CArray3Dd)(w,h,d));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray3Dd");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CArray3Dd_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CArray3Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Dd_new01_local
static int tolua_bind_anl_CArray3Dd_new01_local(lua_State* tolua_S)
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
  CArray3Dd* tolua_ret = (CArray3Dd*)  Mtolua_new((CArray3Dd)(w,h,d));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray3Dd");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CArray3Dd_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CArray3Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Dd_delete00
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

/* method: width of class  CArray3Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Dd_width00
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

/* method: height of class  CArray3Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Dd_height00
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

/* method: depth of class  CArray3Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Dd_depth00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'depth'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  CArray3Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Dd_set00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: get of class  CArray3Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Dd_get00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: resize of class  CArray3Dd */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Dd_resize00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resize'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CArray3Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Drgba_new00
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
  CArray3Drgba* tolua_ret = (CArray3Drgba*)  Mtolua_new((CArray3Drgba)());
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
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CArray3Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Drgba_new00_local
static int tolua_bind_anl_CArray3Drgba_new00_local(lua_State* tolua_S)
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
  CArray3Drgba* tolua_ret = (CArray3Drgba*)  Mtolua_new((CArray3Drgba)());
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray3Drgba");
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

/* method: new of class  CArray3Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Drgba_new01
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
  CArray3Drgba* tolua_ret = (CArray3Drgba*)  Mtolua_new((CArray3Drgba)(w,h,d));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray3Drgba");
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CArray3Drgba_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CArray3Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Drgba_new01_local
static int tolua_bind_anl_CArray3Drgba_new01_local(lua_State* tolua_S)
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
  CArray3Drgba* tolua_ret = (CArray3Drgba*)  Mtolua_new((CArray3Drgba)(w,h,d));
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"CArray3Drgba");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
 }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_CArray3Drgba_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CArray3Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Drgba_delete00
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

/* method: width of class  CArray3Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Drgba_width00
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

/* method: height of class  CArray3Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Drgba_height00
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

/* method: depth of class  CArray3Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Drgba_depth00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'depth'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: resize of class  CArray3Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Drgba_resize00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resize'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  CArray3Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Drgba_set00
static int tolua_bind_anl_CArray3Drgba_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray3Drgba",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"SRGBA",0,&tolua_err)) ||
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
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
#endif //#ifndef TOLUA_DISABLE

/* method: get of class  CArray3Drgba */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CArray3Drgba_get00
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
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'", NULL);
#endif
 {
  anl::SRGBA tolua_ret = (anl::SRGBA)  self->get(x,y,z);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((anl::SRGBA)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"anl::SRGBA");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(anl::SRGBA));
  tolua_pushusertype(tolua_S,tolua_obj,"anl::SRGBA");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
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
#endif //#ifndef TOLUA_DISABLE

/* function: map2D */
#ifndef TOLUA_DISABLE_tolua_bind_anl_map2D00
static int tolua_bind_anl_map2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CKernel",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"SMappingRanges",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"CInstructionIndex",0,&tolua_err)) ||
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
  double z = ((double)  tolua_tonumber(tolua_S,5,0));
  CInstructionIndex at = *((CInstructionIndex*)  tolua_tousertype(tolua_S,6,0));
 {
  map2D(seamlessmode,*a,*k,ranges,z,at);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'map2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: map2DNoZ */
#ifndef TOLUA_DISABLE_tolua_bind_anl_map2DNoZ00
static int tolua_bind_anl_map2DNoZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CKernel",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"SMappingRanges",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err)) ||
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
  CInstructionIndex at = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
 {
  map2DNoZ(seamlessmode,*a,*k,ranges,at);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'map2DNoZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: map3D */
#ifndef TOLUA_DISABLE_tolua_bind_anl_map3D00
static int tolua_bind_anl_map3D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CArray3Dd",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CKernel",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"SMappingRanges",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err)) ||
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
#endif //#ifndef TOLUA_DISABLE

/* function: mapRGBA2D */
#ifndef TOLUA_DISABLE_tolua_bind_anl_mapRGBA2D00
static int tolua_bind_anl_mapRGBA2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CArray2Drgba",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CKernel",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"SMappingRanges",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"CInstructionIndex",0,&tolua_err)) ||
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
  double z = ((double)  tolua_tonumber(tolua_S,5,0));
  CInstructionIndex at = *((CInstructionIndex*)  tolua_tousertype(tolua_S,6,0));
 {
  mapRGBA2D(seamlessmode,*a,*k,ranges,z,at);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mapRGBA2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: mapRGBA2DNoZ */
#ifndef TOLUA_DISABLE_tolua_bind_anl_mapRGBA2DNoZ00
static int tolua_bind_anl_mapRGBA2DNoZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CArray2Drgba",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CKernel",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"SMappingRanges",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err)) ||
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
  CInstructionIndex at = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
 {
  mapRGBA2DNoZ(seamlessmode,*a,*k,ranges,at);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mapRGBA2DNoZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: mapRGBA3D */
#ifndef TOLUA_DISABLE_tolua_bind_anl_mapRGBA3D00
static int tolua_bind_anl_mapRGBA3D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CArray3Drgba",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CKernel",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"SMappingRanges",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"CInstructionIndex",0,&tolua_err)) ||
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
#endif //#ifndef TOLUA_DISABLE

/* function: saveDoubleArray */
#ifndef TOLUA_DISABLE_tolua_bind_anl_saveDoubleArray00
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
#endif //#ifndef TOLUA_DISABLE

/* function: saveHeightmap */
#ifndef TOLUA_DISABLE_tolua_bind_anl_saveHeightmap00
static int tolua_bind_anl_saveHeightmap00(lua_State* tolua_S)
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
  saveHeightmap(filename,array);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'saveHeightmap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: saveRGBAArray */
#ifndef TOLUA_DISABLE_tolua_bind_anl_saveRGBAArray00
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
#endif //#ifndef TOLUA_DISABLE

/* function: loadDoubleArray */
#ifndef TOLUA_DISABLE_tolua_bind_anl_loadDoubleArray00
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
#endif //#ifndef TOLUA_DISABLE

/* function: loadRGBAArray */
#ifndef TOLUA_DISABLE_tolua_bind_anl_loadRGBAArray00
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
#endif //#ifndef TOLUA_DISABLE

/* function: simpleErode */
#ifndef TOLUA_DISABLE_tolua_bind_anl_simpleErode00
static int tolua_bind_anl_simpleErode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* map = ((CArray2Dd*)  tolua_tousertype(tolua_S,1,0));
  unsigned int numdrops = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  float power = ((float)  tolua_tonumber(tolua_S,3,0));
 {
  simpleErode(*map,numdrops,power);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'simpleErode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: waterFlow */
#ifndef TOLUA_DISABLE_tolua_bind_anl_waterFlow00
static int tolua_bind_anl_waterFlow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err)) ||
 (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err)) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* map = ((CArray2Dd*)  tolua_tousertype(tolua_S,1,0));
  CArray2Dd* flow = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
  unsigned int numdrops = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
 {
  waterFlow(*map,*flow,numdrops);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'waterFlow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: calcNormalMap */
#ifndef TOLUA_DISABLE_tolua_bind_anl_calcNormalMap00
static int tolua_bind_anl_calcNormalMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CArray2Drgba",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* map = ((CArray2Dd*)  tolua_tousertype(tolua_S,1,0));
  CArray2Drgba* bump = ((CArray2Drgba*)  tolua_tousertype(tolua_S,2,0));
  float spacing = ((float)  tolua_tonumber(tolua_S,3,0));
  bool normalize = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool wrap = ((bool)  tolua_toboolean(tolua_S,5,0));
 {
  calcNormalMap(map,bump,spacing,normalize,wrap);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'calcNormalMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: calcBumpMap */
#ifndef TOLUA_DISABLE_tolua_bind_anl_calcBumpMap00
static int tolua_bind_anl_calcBumpMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"CArray2Dd",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"CArray2Dd",0,&tolua_err) ||
 !tolua_istable(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  CArray2Dd* map = ((CArray2Dd*)  tolua_tousertype(tolua_S,1,0));
  CArray2Dd* bump = ((CArray2Dd*)  tolua_tousertype(tolua_S,2,0));
  float light[3];
  float spacing = ((float)  tolua_tonumber(tolua_S,4,0));
  bool wrap = ((bool)  tolua_toboolean(tolua_S,5,0));
 {
#ifndef TOLUA_RELEASE
 if (!tolua_isnumberarray(tolua_S,3,3,0,&tolua_err))
 goto tolua_lerror;
 else
#endif
 {
 int i;
 for(i=0; i<3;i++)
  light[i] = ((float)  tolua_tofieldnumber(tolua_S,3,i+1,0));
 }
 }
 {
  calcBumpMap(map,bump,light,spacing,wrap);
 }
 {
 int i;
 for(i=0; i<3;i++)
 tolua_pushfieldnumber(tolua_S,3,i+1,(lua_Number) light[i]);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'calcBumpMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_bind_anl_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_function(tolua_S,"highresTime",tolua_bind_anl_highresTime00);
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
  tolua_function(tolua_S,"new_local",tolua_bind_anl_LCG_new00_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_LCG_new00_local);
  tolua_function(tolua_S,"delete",tolua_bind_anl_LCG_delete00);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Xorshift","Xorshift","CBasePRNG",tolua_collect_Xorshift);
 #else
 tolua_cclass(tolua_S,"Xorshift","Xorshift","CBasePRNG",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Xorshift");
  tolua_function(tolua_S,"new",tolua_bind_anl_Xorshift_new00);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_Xorshift_new00_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_Xorshift_new00_local);
  tolua_function(tolua_S,"delete",tolua_bind_anl_Xorshift_delete00);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"MWC256","MWC256","CBasePRNG",tolua_collect_MWC256);
 #else
 tolua_cclass(tolua_S,"MWC256","MWC256","CBasePRNG",NULL);
 #endif
 tolua_beginmodule(tolua_S,"MWC256");
  tolua_function(tolua_S,"new",tolua_bind_anl_MWC256_new00);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_MWC256_new00_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_MWC256_new00_local);
  tolua_function(tolua_S,"delete",tolua_bind_anl_MWC256_delete00);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"CMWC4096","CMWC4096","CBasePRNG",tolua_collect_CMWC4096);
 #else
 tolua_cclass(tolua_S,"CMWC4096","CMWC4096","CBasePRNG",NULL);
 #endif
 tolua_beginmodule(tolua_S,"CMWC4096");
  tolua_function(tolua_S,"new",tolua_bind_anl_CMWC4096_new00);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_CMWC4096_new00_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_CMWC4096_new00_local);
  tolua_function(tolua_S,"delete",tolua_bind_anl_CMWC4096_delete00);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"KISS","KISS","CBasePRNG",tolua_collect_KISS);
 #else
 tolua_cclass(tolua_S,"KISS","KISS","CBasePRNG",NULL);
 #endif
 tolua_beginmodule(tolua_S,"KISS");
  tolua_function(tolua_S,"new",tolua_bind_anl_KISS_new00);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_KISS_new00_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_KISS_new00_local);
  tolua_function(tolua_S,"delete",tolua_bind_anl_KISS_delete00);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"INTERP_NONE",INTERP_NONE);
 tolua_constant(tolua_S,"INTERP_LINEAR",INTERP_LINEAR);
 tolua_constant(tolua_S,"INTERP_HERMITE",INTERP_HERMITE);
 tolua_constant(tolua_S,"INTERP_QUINTIC",INTERP_QUINTIC);
 tolua_constant(tolua_S,"DISTANCE_EUCLID",DISTANCE_EUCLID);
 tolua_constant(tolua_S,"DISTANCE_MANHATTAN",DISTANCE_MANHATTAN);
 tolua_constant(tolua_S,"DISTANCE_LEASTAXIS",DISTANCE_LEASTAXIS);
 tolua_constant(tolua_S,"DISTANCE_GREATESTAXIS",DISTANCE_GREATESTAXIS);
 tolua_constant(tolua_S,"BASIS_VALUE",BASIS_VALUE);
 tolua_constant(tolua_S,"BASIS_GRADIENT",BASIS_GRADIENT);
 tolua_constant(tolua_S,"BASIS_SIMPLEX",BASIS_SIMPLEX);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"CCoordinate","CCoordinate","",tolua_collect_CCoordinate);
 #else
 tolua_cclass(tolua_S,"CCoordinate","CCoordinate","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"CCoordinate");
  tolua_function(tolua_S,"new",tolua_bind_anl_CCoordinate_new00);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_CCoordinate_new00_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_CCoordinate_new00_local);
  tolua_function(tolua_S,"new",tolua_bind_anl_CCoordinate_new01);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_CCoordinate_new01_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_CCoordinate_new01_local);
  tolua_function(tolua_S,"new",tolua_bind_anl_CCoordinate_new02);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_CCoordinate_new02_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_CCoordinate_new02_local);
  tolua_function(tolua_S,"new",tolua_bind_anl_CCoordinate_new03);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_CCoordinate_new03_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_CCoordinate_new03_local);
  tolua_function(tolua_S,"new",tolua_bind_anl_CCoordinate_new04);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_CCoordinate_new04_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_CCoordinate_new04_local);
  tolua_function(tolua_S,"new",tolua_bind_anl_CCoordinate_new05);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_CCoordinate_new05_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_CCoordinate_new05_local);
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
  tolua_function(tolua_S,"new_local",tolua_bind_anl_CKernel_new00_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_CKernel_new00_local);
  tolua_function(tolua_S,"delete",tolua_bind_anl_CKernel_delete00);
  tolua_function(tolua_S,"pi",tolua_bind_anl_CKernel_pi00);
  tolua_function(tolua_S,"e",tolua_bind_anl_CKernel_e00);
  tolua_function(tolua_S,"one",tolua_bind_anl_CKernel_one00);
  tolua_function(tolua_S,"zero",tolua_bind_anl_CKernel_zero00);
  tolua_function(tolua_S,"point5",tolua_bind_anl_CKernel_point500);
  tolua_function(tolua_S,"sqrt2",tolua_bind_anl_CKernel_sqrt200);
  tolua_function(tolua_S,"constant",tolua_bind_anl_CKernel_constant00);
  tolua_function(tolua_S,"seed",tolua_bind_anl_CKernel_seed00);
  tolua_function(tolua_S,"seeder",tolua_bind_anl_CKernel_seeder00);
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
  tolua_function(tolua_S,"scaleX",tolua_bind_anl_CKernel_scaleX00);
  tolua_function(tolua_S,"scaleY",tolua_bind_anl_CKernel_scaleY00);
  tolua_function(tolua_S,"scaleZ",tolua_bind_anl_CKernel_scaleZ00);
  tolua_function(tolua_S,"scaleW",tolua_bind_anl_CKernel_scaleW00);
  tolua_function(tolua_S,"scaleU",tolua_bind_anl_CKernel_scaleU00);
  tolua_function(tolua_S,"scaleV",tolua_bind_anl_CKernel_scaleV00);
  tolua_function(tolua_S,"translateDomain",tolua_bind_anl_CKernel_translateDomain00);
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
  tolua_function(tolua_S,"mix",tolua_bind_anl_CKernel_mix00);
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
  tolua_function(tolua_S,"dx",tolua_bind_anl_CKernel_dx00);
  tolua_function(tolua_S,"dy",tolua_bind_anl_CKernel_dy00);
  tolua_function(tolua_S,"dz",tolua_bind_anl_CKernel_dz00);
  tolua_function(tolua_S,"dw",tolua_bind_anl_CKernel_dw00);
  tolua_function(tolua_S,"du",tolua_bind_anl_CKernel_du00);
  tolua_function(tolua_S,"dv",tolua_bind_anl_CKernel_dv00);
  tolua_function(tolua_S,"sigmoid",tolua_bind_anl_CKernel_sigmoid00);
  tolua_function(tolua_S,"sigmoid",tolua_bind_anl_CKernel_sigmoid01);
  tolua_function(tolua_S,"fractal",tolua_bind_anl_CKernel_fractal00);
  tolua_function(tolua_S,"randomize",tolua_bind_anl_CKernel_randomize00);
  tolua_function(tolua_S,"step",tolua_bind_anl_CKernel_step00);
  tolua_function(tolua_S,"linearStep",tolua_bind_anl_CKernel_linearStep00);
  tolua_function(tolua_S,"smoothStep",tolua_bind_anl_CKernel_smoothStep00);
  tolua_function(tolua_S,"smootherStep",tolua_bind_anl_CKernel_smootherStep00);
  tolua_function(tolua_S,"curveSection",tolua_bind_anl_CKernel_curveSection00);
  tolua_function(tolua_S,"radial",tolua_bind_anl_CKernel_radial00);
  tolua_function(tolua_S,"hexTile",tolua_bind_anl_CKernel_hexTile00);
  tolua_function(tolua_S,"hexBump",tolua_bind_anl_CKernel_hexBump00);
  tolua_function(tolua_S,"color",tolua_bind_anl_CKernel_color00);
  tolua_function(tolua_S,"color",tolua_bind_anl_CKernel_color01);
  tolua_function(tolua_S,"combineRGBA",tolua_bind_anl_CKernel_combineRGBA00);
  tolua_function(tolua_S,"combineHSVA",tolua_bind_anl_CKernel_combineHSVA00);
  tolua_function(tolua_S,"scaleOffset",tolua_bind_anl_CKernel_scaleOffset00);
  tolua_function(tolua_S,"simpleFractalLayer",tolua_bind_anl_CKernel_simpleFractalLayer00);
  tolua_function(tolua_S,"simpleRidgedLayer",tolua_bind_anl_CKernel_simpleRidgedLayer00);
  tolua_function(tolua_S,"simpleBillowLayer",tolua_bind_anl_CKernel_simpleBillowLayer00);
  tolua_function(tolua_S,"simplefBm",tolua_bind_anl_CKernel_simplefBm00);
  tolua_function(tolua_S,"simpleRidgedMultifractal",tolua_bind_anl_CKernel_simpleRidgedMultifractal00);
  tolua_function(tolua_S,"simpleBillow",tolua_bind_anl_CKernel_simpleBillow00);
  tolua_function(tolua_S,"getKernel",tolua_bind_anl_CKernel_getKernel00);
  tolua_function(tolua_S,"lastIndex",tolua_bind_anl_CKernel_lastIndex00);
  tolua_function(tolua_S,"nextIndex",tolua_bind_anl_CKernel_nextIndex00);
  tolua_function(tolua_S,"getVar",tolua_bind_anl_CKernel_getVar00);
  tolua_function(tolua_S,"setVar",tolua_bind_anl_CKernel_setVar00);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"SRGBA","SRGBA","",tolua_collect_SRGBA);
 #else
 tolua_cclass(tolua_S,"SRGBA","SRGBA","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"SRGBA");
  tolua_function(tolua_S,"new",tolua_bind_anl_SRGBA_new00);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_SRGBA_new00_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_SRGBA_new00_local);
  tolua_function(tolua_S,"new",tolua_bind_anl_SRGBA_new01);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_SRGBA_new01_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_SRGBA_new01_local);
  tolua_function(tolua_S,"new",tolua_bind_anl_SRGBA_new02);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_SRGBA_new02_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_SRGBA_new02_local);
  tolua_function(tolua_S,"new",tolua_bind_anl_SRGBA_new03);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_SRGBA_new03_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_SRGBA_new03_local);
  tolua_function(tolua_S,"delete",tolua_bind_anl_SRGBA_delete00);
  tolua_variable(tolua_S,"r",tolua_get_SRGBA_r,tolua_set_SRGBA_r);
  tolua_variable(tolua_S,"g",tolua_get_SRGBA_g,tolua_set_SRGBA_g);
  tolua_variable(tolua_S,"b",tolua_get_SRGBA_b,tolua_set_SRGBA_b);
  tolua_variable(tolua_S,"a",tolua_get_SRGBA_a,tolua_set_SRGBA_a);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"SVMOutput","SVMOutput","",tolua_collect_SVMOutput);
 #else
 tolua_cclass(tolua_S,"SVMOutput","SVMOutput","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"SVMOutput");
  tolua_variable(tolua_S,"outfloat_",tolua_get_SVMOutput_outfloat_,tolua_set_SVMOutput_outfloat_);
  tolua_variable(tolua_S,"outrgba_",tolua_get_SVMOutput_outrgba_,tolua_set_SVMOutput_outrgba_);
  tolua_function(tolua_S,"new",tolua_bind_anl_SVMOutput_new00);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_SVMOutput_new00_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_SVMOutput_new00_local);
  tolua_function(tolua_S,"delete",tolua_bind_anl_SVMOutput_delete00);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"CNoiseExecutor","CNoiseExecutor","",tolua_collect_CNoiseExecutor);
 #else
 tolua_cclass(tolua_S,"CNoiseExecutor","CNoiseExecutor","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"CNoiseExecutor");
  tolua_function(tolua_S,"new",tolua_bind_anl_CNoiseExecutor_new00);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_CNoiseExecutor_new00_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_CNoiseExecutor_new00_local);
  tolua_function(tolua_S,"delete",tolua_bind_anl_CNoiseExecutor_delete00);
  tolua_function(tolua_S,"evaluate",tolua_bind_anl_CNoiseExecutor_evaluate00);
  tolua_function(tolua_S,"evaluateAt",tolua_bind_anl_CNoiseExecutor_evaluateAt00);
  tolua_function(tolua_S,"evaluateScalar",tolua_bind_anl_CNoiseExecutor_evaluateScalar00);
  tolua_function(tolua_S,"evaluateScalar",tolua_bind_anl_CNoiseExecutor_evaluateScalar01);
  tolua_function(tolua_S,"evaluateScalar",tolua_bind_anl_CNoiseExecutor_evaluateScalar02);
  tolua_function(tolua_S,"evaluateScalar",tolua_bind_anl_CNoiseExecutor_evaluateScalar03);
  tolua_function(tolua_S,"evaluateColor",tolua_bind_anl_CNoiseExecutor_evaluateColor00);
  tolua_function(tolua_S,"evaluateColor",tolua_bind_anl_CNoiseExecutor_evaluateColor01);
  tolua_function(tolua_S,"evaluateColor",tolua_bind_anl_CNoiseExecutor_evaluateColor02);
  tolua_function(tolua_S,"evaluateColor",tolua_bind_anl_CNoiseExecutor_evaluateColor03);
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
  tolua_function(tolua_S,"new_local",tolua_bind_anl_SMappingRanges_new00_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_SMappingRanges_new00_local);
  tolua_function(tolua_S,"new",tolua_bind_anl_SMappingRanges_new01);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_SMappingRanges_new01_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_SMappingRanges_new01_local);
  tolua_function(tolua_S,"new",tolua_bind_anl_SMappingRanges_new02);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_SMappingRanges_new02_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_SMappingRanges_new02_local);
  tolua_function(tolua_S,"new",tolua_bind_anl_SMappingRanges_new03);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_SMappingRanges_new03_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_SMappingRanges_new03_local);
  tolua_function(tolua_S,"delete",tolua_bind_anl_SMappingRanges_delete00);
  tolua_variable(tolua_S,"mapx0",tolua_get_SMappingRanges_mapx0,tolua_set_SMappingRanges_mapx0);
  tolua_variable(tolua_S,"mapy0",tolua_get_SMappingRanges_mapy0,tolua_set_SMappingRanges_mapy0);
  tolua_variable(tolua_S,"mapz0",tolua_get_SMappingRanges_mapz0,tolua_set_SMappingRanges_mapz0);
  tolua_variable(tolua_S,"mapx1",tolua_get_SMappingRanges_mapx1,tolua_set_SMappingRanges_mapx1);
  tolua_variable(tolua_S,"mapy1",tolua_get_SMappingRanges_mapy1,tolua_set_SMappingRanges_mapy1);
  tolua_variable(tolua_S,"mapz1",tolua_get_SMappingRanges_mapz1,tolua_set_SMappingRanges_mapz1);
  tolua_variable(tolua_S,"loopx0",tolua_get_SMappingRanges_loopx0,tolua_set_SMappingRanges_loopx0);
  tolua_variable(tolua_S,"loopy0",tolua_get_SMappingRanges_loopy0,tolua_set_SMappingRanges_loopy0);
  tolua_variable(tolua_S,"loopz0",tolua_get_SMappingRanges_loopz0,tolua_set_SMappingRanges_loopz0);
  tolua_variable(tolua_S,"loopx1",tolua_get_SMappingRanges_loopx1,tolua_set_SMappingRanges_loopx1);
  tolua_variable(tolua_S,"loopy1",tolua_get_SMappingRanges_loopy1,tolua_set_SMappingRanges_loopy1);
  tolua_variable(tolua_S,"loopz1",tolua_get_SMappingRanges_loopz1,tolua_set_SMappingRanges_loopz1);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"CExpressionBuilder","CExpressionBuilder","",tolua_collect_CExpressionBuilder);
 #else
 tolua_cclass(tolua_S,"CExpressionBuilder","CExpressionBuilder","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"CExpressionBuilder");
  tolua_function(tolua_S,"new",tolua_bind_anl_CExpressionBuilder_new00);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_CExpressionBuilder_new00_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_CExpressionBuilder_new00_local);
  tolua_function(tolua_S,"delete",tolua_bind_anl_CExpressionBuilder_delete00);
  tolua_function(tolua_S,"eval",tolua_bind_anl_CExpressionBuilder_eval00);
  tolua_function(tolua_S,"evalAndStore",tolua_bind_anl_CExpressionBuilder_evalAndStore00);
  tolua_function(tolua_S,"store",tolua_bind_anl_CExpressionBuilder_store00);
  tolua_function(tolua_S,"setRandomSeed",tolua_bind_anl_CExpressionBuilder_setRandomSeed00);
  tolua_function(tolua_S,"storeVar",tolua_bind_anl_CExpressionBuilder_storeVar00);
  tolua_function(tolua_S,"evalAndStoreVar",tolua_bind_anl_CExpressionBuilder_evalAndStoreVar00);
  tolua_function(tolua_S,"retrieveVar",tolua_bind_anl_CExpressionBuilder_retrieveVar00);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"CArray2Dd","CArray2Dd","",tolua_collect_CArray2Dd);
 #else
 tolua_cclass(tolua_S,"CArray2Dd","CArray2Dd","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"CArray2Dd");
  tolua_function(tolua_S,"new",tolua_bind_anl_CArray2Dd_new00);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_CArray2Dd_new00_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_CArray2Dd_new00_local);
  tolua_function(tolua_S,"new",tolua_bind_anl_CArray2Dd_new01);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_CArray2Dd_new01_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_CArray2Dd_new01_local);
  tolua_function(tolua_S,"delete",tolua_bind_anl_CArray2Dd_delete00);
  tolua_function(tolua_S,"resize",tolua_bind_anl_CArray2Dd_resize00);
  tolua_function(tolua_S,"destroy",tolua_bind_anl_CArray2Dd_destroy00);
  tolua_function(tolua_S,"width",tolua_bind_anl_CArray2Dd_width00);
  tolua_function(tolua_S,"height",tolua_bind_anl_CArray2Dd_height00);
  tolua_function(tolua_S,"set",tolua_bind_anl_CArray2Dd_set00);
  tolua_function(tolua_S,"get",tolua_bind_anl_CArray2Dd_get00);
  tolua_function(tolua_S,"get",tolua_bind_anl_CArray2Dd_get01);
  tolua_function(tolua_S,"getIndexed",tolua_bind_anl_CArray2Dd_getIndexed00);
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
  tolua_function(tolua_S,"bias",tolua_bind_anl_CArray2Dd_bias00);
  tolua_function(tolua_S,"gain",tolua_bind_anl_CArray2Dd_gain00);
  tolua_function(tolua_S,"wrapCoords",tolua_bind_anl_CArray2Dd_wrapCoords00);
  tolua_function(tolua_S,"offset",tolua_bind_anl_CArray2Dd_offset00);
  tolua_function(tolua_S,"flipVertical",tolua_bind_anl_CArray2Dd_flipVertical00);
  tolua_function(tolua_S,"flipHorizontal",tolua_bind_anl_CArray2Dd_flipHorizontal00);
  tolua_function(tolua_S,"blur",tolua_bind_anl_CArray2Dd_blur00);
  tolua_function(tolua_S,"subtractFilter",tolua_bind_anl_CArray2Dd_subtractFilter00);
  tolua_function(tolua_S,"addFilter",tolua_bind_anl_CArray2Dd_addFilter00);
  tolua_function(tolua_S,"scaleTo",tolua_bind_anl_CArray2Dd_scaleTo00);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"CArray2Drgba","CArray2Drgba","",tolua_collect_CArray2Drgba);
 #else
 tolua_cclass(tolua_S,"CArray2Drgba","CArray2Drgba","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"CArray2Drgba");
  tolua_function(tolua_S,"new",tolua_bind_anl_CArray2Drgba_new00);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_CArray2Drgba_new00_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_CArray2Drgba_new00_local);
  tolua_function(tolua_S,"new",tolua_bind_anl_CArray2Drgba_new01);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_CArray2Drgba_new01_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_CArray2Drgba_new01_local);
  tolua_function(tolua_S,"delete",tolua_bind_anl_CArray2Drgba_delete00);
  tolua_function(tolua_S,"resize",tolua_bind_anl_CArray2Drgba_resize00);
  tolua_function(tolua_S,"destroy",tolua_bind_anl_CArray2Drgba_destroy00);
  tolua_function(tolua_S,"width",tolua_bind_anl_CArray2Drgba_width00);
  tolua_function(tolua_S,"height",tolua_bind_anl_CArray2Drgba_height00);
  tolua_function(tolua_S,"set",tolua_bind_anl_CArray2Drgba_set00);
  tolua_function(tolua_S,"get",tolua_bind_anl_CArray2Drgba_get00);
  tolua_function(tolua_S,"get",tolua_bind_anl_CArray2Drgba_get01);
  tolua_function(tolua_S,"getIndexed",tolua_bind_anl_CArray2Drgba_getIndexed00);
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
  tolua_function(tolua_S,"new_local",tolua_bind_anl_CArray3Dd_new00_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_CArray3Dd_new00_local);
  tolua_function(tolua_S,"new",tolua_bind_anl_CArray3Dd_new01);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_CArray3Dd_new01_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_CArray3Dd_new01_local);
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
  tolua_function(tolua_S,"new_local",tolua_bind_anl_CArray3Drgba_new00_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_CArray3Drgba_new00_local);
  tolua_function(tolua_S,"new",tolua_bind_anl_CArray3Drgba_new01);
  tolua_function(tolua_S,"new_local",tolua_bind_anl_CArray3Drgba_new01_local);
  tolua_function(tolua_S,".call",tolua_bind_anl_CArray3Drgba_new01_local);
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
 tolua_function(tolua_S,"saveHeightmap",tolua_bind_anl_saveHeightmap00);
 tolua_function(tolua_S,"saveRGBAArray",tolua_bind_anl_saveRGBAArray00);
 tolua_function(tolua_S,"loadDoubleArray",tolua_bind_anl_loadDoubleArray00);
 tolua_function(tolua_S,"loadRGBAArray",tolua_bind_anl_loadRGBAArray00);
 tolua_function(tolua_S,"simpleErode",tolua_bind_anl_simpleErode00);
 tolua_function(tolua_S,"waterFlow",tolua_bind_anl_waterFlow00);
 tolua_function(tolua_S,"calcNormalMap",tolua_bind_anl_calcNormalMap00);
 tolua_function(tolua_S,"calcBumpMap",tolua_bind_anl_calcBumpMap00);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_bind_anl (lua_State* tolua_S) {
 return tolua_bind_anl_open(tolua_S);
};
#endif

