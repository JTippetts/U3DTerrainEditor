/*
** Lua binding: bind_anl
** Generated automatically by tolua++-1.0.93 on 01/17/15 16:27:34.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_bind_anl_open (lua_State* tolua_S);

#include "./ThirdParty/ANL/VM/vm.h"
#include "./ThirdParty/ANL/VM/instruction.h"
#include "./ThirdParty/ANL/VM/kernel.h"
#include "./ThirdParty/ANL/VM/coordinate.h"
#include "./ThirdParty/ANL/VM/random_gen.h"
using namespace anl;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_CCoordinate (lua_State* tolua_S)
{
 CCoordinate* self = (CCoordinate*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CNoiseExecutor (lua_State* tolua_S)
{
 CNoiseExecutor* self = (CNoiseExecutor*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_LCG (lua_State* tolua_S)
{
 LCG* self = (LCG*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_SVMOutput (lua_State* tolua_S)
{
 SVMOutput* self = (SVMOutput*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_SRGBA (lua_State* tolua_S)
{
 SRGBA* self = (SRGBA*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Xorshift (lua_State* tolua_S)
{
 Xorshift* self = (Xorshift*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CKernel (lua_State* tolua_S)
{
 CKernel* self = (CKernel*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_KISS (lua_State* tolua_S)
{
 KISS* self = (KISS*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CMWC4096 (lua_State* tolua_S)
{
 CMWC4096* self = (CMWC4096*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CInstructionIndex (lua_State* tolua_S)
{
 CInstructionIndex* self = (CInstructionIndex*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_MWC256 (lua_State* tolua_S)
{
 MWC256* self = (MWC256*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CCoordinate");
 tolua_usertype(tolua_S,"CBasePRNG");
 tolua_usertype(tolua_S,"CInstructionListType");
 tolua_usertype(tolua_S,"CNoiseExecutor");
 tolua_usertype(tolua_S,"LCG");
 tolua_usertype(tolua_S,"SVMOutput");
 tolua_usertype(tolua_S,"SRGBA");
 tolua_usertype(tolua_S,"CInstructionIndex");
 tolua_usertype(tolua_S,"Xorshift");
 tolua_usertype(tolua_S,"CKernel");
 tolua_usertype(tolua_S,"KISS");
 tolua_usertype(tolua_S,"InstructionListType");
 tolua_usertype(tolua_S,"CMWC4096");
 tolua_usertype(tolua_S,"MWC256");
}

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

/* method: valueBasis of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_valueBasis00
static int tolua_bind_anl_CKernel_valueBasis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CKernel",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CInstructionIndex",0,&tolua_err)) ||
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
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err)) ||
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleDomain'", NULL);
#endif
  {
   CInstructionIndex tolua_ret = (CInstructionIndex)  self->scaleDomain(srcindex,xindex,yindex);
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

/* method: scaleDomain of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_scaleDomain01
static int tolua_bind_anl_CKernel_scaleDomain01(lua_State* tolua_S)
{
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
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex srcindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex xindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex yindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex zindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleDomain'", NULL);
#endif
  {
   CInstructionIndex tolua_ret = (CInstructionIndex)  self->scaleDomain(srcindex,xindex,yindex,zindex);
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
 return tolua_bind_anl_CKernel_scaleDomain00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: scaleDomain of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_scaleDomain02
static int tolua_bind_anl_CKernel_scaleDomain02(lua_State* tolua_S)
{
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
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex srcindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex xindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex yindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex zindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
  CInstructionIndex windex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleDomain'", NULL);
#endif
  {
   CInstructionIndex tolua_ret = (CInstructionIndex)  self->scaleDomain(srcindex,xindex,yindex,zindex,windex);
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
 return tolua_bind_anl_CKernel_scaleDomain01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: scaleDomain of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_scaleDomain03
static int tolua_bind_anl_CKernel_scaleDomain03(lua_State* tolua_S)
{
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scaleDomain'", NULL);
#endif
  {
   CInstructionIndex tolua_ret = (CInstructionIndex)  self->scaleDomain(srcindex,xindex,yindex,zindex,windex,uindex,vindex);
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
 return tolua_bind_anl_CKernel_scaleDomain02(tolua_S);
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
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CInstructionIndex",0,&tolua_err)) ||
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateDomain'", NULL);
#endif
  {
   CInstructionIndex tolua_ret = (CInstructionIndex)  self->translateDomain(srcindex,xindex,yindex);
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

/* method: translateDomain of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_translateDomain01
static int tolua_bind_anl_CKernel_translateDomain01(lua_State* tolua_S)
{
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
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex srcindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex xindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex yindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex zindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateDomain'", NULL);
#endif
  {
   CInstructionIndex tolua_ret = (CInstructionIndex)  self->translateDomain(srcindex,xindex,yindex,zindex);
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
 return tolua_bind_anl_CKernel_translateDomain00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: translateDomain of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_translateDomain02
static int tolua_bind_anl_CKernel_translateDomain02(lua_State* tolua_S)
{
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
 {
  CKernel* self = (CKernel*)  tolua_tousertype(tolua_S,1,0);
  CInstructionIndex srcindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,2,0));
  CInstructionIndex xindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,3,0));
  CInstructionIndex yindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,4,0));
  CInstructionIndex zindex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,5,0));
  CInstructionIndex windex = *((CInstructionIndex*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateDomain'", NULL);
#endif
  {
   CInstructionIndex tolua_ret = (CInstructionIndex)  self->translateDomain(srcindex,xindex,yindex,zindex,windex);
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
 return tolua_bind_anl_CKernel_translateDomain01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: translateDomain of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_translateDomain03
static int tolua_bind_anl_CKernel_translateDomain03(lua_State* tolua_S)
{
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translateDomain'", NULL);
#endif
  {
   CInstructionIndex tolua_ret = (CInstructionIndex)  self->translateDomain(srcindex,xindex,yindex,zindex,windex,uindex,vindex);
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
 return tolua_bind_anl_CKernel_translateDomain02(tolua_S);
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

/* method: blend of class  CKernel */
#ifndef TOLUA_DISABLE_tolua_bind_anl_CKernel_blend00
static int tolua_bind_anl_CKernel_blend00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'blend'", NULL);
#endif
  {
   CInstructionIndex tolua_ret = (CInstructionIndex)  self->blend(low,high,control);
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
 tolua_error(tolua_S,"#ferror in function 'blend'.",&tolua_err);
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

/* method: new of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SRGBA_new00
static int tolua_bind_anl_SRGBA_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
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
#endif
 {
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
  float g = ((float)  tolua_tonumber(tolua_S,3,0));
  float b = ((float)  tolua_tonumber(tolua_S,4,0));
  float a = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   SRGBA* tolua_ret = (SRGBA*)  Mtolua_new((SRGBA)(r,g,b,a));
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
  float r = ((float)  tolua_tonumber(tolua_S,2,0));
  float g = ((float)  tolua_tonumber(tolua_S,3,0));
  float b = ((float)  tolua_tonumber(tolua_S,4,0));
  float a = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   SRGBA* tolua_ret = (SRGBA*)  Mtolua_new((SRGBA)(r,g,b,a));
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
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   SRGBA* tolua_ret = (SRGBA*)  Mtolua_new((SRGBA)());
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
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   SRGBA* tolua_ret = (SRGBA*)  Mtolua_new((SRGBA)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SRGBA");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_bind_anl_SRGBA_new00_local(tolua_S);
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

/* method: x of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SRGBA_x00
static int tolua_bind_anl_SRGBA_x00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'x'", NULL);
#endif
  {
   float tolua_ret = (float)  self->x();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: y of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SRGBA_y00
static int tolua_bind_anl_SRGBA_y00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'y'", NULL);
#endif
  {
   float tolua_ret = (float)  self->y();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: z of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SRGBA_z00
static int tolua_bind_anl_SRGBA_z00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'z'", NULL);
#endif
  {
   float tolua_ret = (float)  self->z();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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

/* method: w of class  SRGBA */
#ifndef TOLUA_DISABLE_tolua_bind_anl_SRGBA_w00
static int tolua_bind_anl_SRGBA_w00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'w'", NULL);
#endif
  {
   float tolua_ret = (float)  self->w();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
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
     !tolua_isusertype(tolua_S,2,"InstructionListType",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  InstructionListType* kernel = ((InstructionListType*)  tolua_tousertype(tolua_S,2,0));
  {
   CNoiseExecutor* tolua_ret = (CNoiseExecutor*)  Mtolua_new((CNoiseExecutor)(kernel));
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
     !tolua_isusertype(tolua_S,2,"InstructionListType",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  InstructionListType* kernel = ((InstructionListType*)  tolua_tousertype(tolua_S,2,0));
  {
   CNoiseExecutor* tolua_ret = (CNoiseExecutor*)  Mtolua_new((CNoiseExecutor)(kernel));
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

/* Open function */
TOLUA_API int tolua_bind_anl_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
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
   tolua_function(tolua_S,"x",tolua_bind_anl_CKernel_x00);
   tolua_function(tolua_S,"y",tolua_bind_anl_CKernel_y00);
   tolua_function(tolua_S,"z",tolua_bind_anl_CKernel_z00);
   tolua_function(tolua_S,"w",tolua_bind_anl_CKernel_w00);
   tolua_function(tolua_S,"u",tolua_bind_anl_CKernel_u00);
   tolua_function(tolua_S,"v",tolua_bind_anl_CKernel_v00);
   tolua_function(tolua_S,"radial",tolua_bind_anl_CKernel_radial00);
   tolua_function(tolua_S,"combineRGBA",tolua_bind_anl_CKernel_combineRGBA00);
   tolua_function(tolua_S,"scaleOffset",tolua_bind_anl_CKernel_scaleOffset00);
   tolua_function(tolua_S,"simpleFractalLayer",tolua_bind_anl_CKernel_simpleFractalLayer00);
   tolua_function(tolua_S,"simplefBm",tolua_bind_anl_CKernel_simplefBm00);
   tolua_function(tolua_S,"getKernel",tolua_bind_anl_CKernel_getKernel00);
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
   tolua_function(tolua_S,"delete",tolua_bind_anl_SRGBA_delete00);
   tolua_function(tolua_S,"x",tolua_bind_anl_SRGBA_x00);
   tolua_function(tolua_S,"y",tolua_bind_anl_SRGBA_y00);
   tolua_function(tolua_S,"z",tolua_bind_anl_SRGBA_z00);
   tolua_function(tolua_S,"w",tolua_bind_anl_SRGBA_w00);
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
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_bind_anl (lua_State* tolua_S) {
 return tolua_bind_anl_open(tolua_S);
};
#endif

