#include <AngelScript/angelscript.h>

#include "./ThirdParty/ANL/VM/vm.h"
#include "./ThirdParty/ANL/VM/instruction.h"
#include "./ThirdParty/ANL/VM/kernel.h"
#include "./ThirdParty/ANL/VM/coordinate.h"
#include "./ThirdParty/ANL/VM/random_gen.h"

using namespace anl;
	static void ConstructCoordinate(CCoordinate *c)
	{
		new(c) CCoordinate();
	}
	
	static void ConstructCoordinate2(double x, double y, CCoordinate *c)
	{
		new(c) CCoordinate(x,y);
	}
	
	static void ConstructCoordinate3(double x, double y, double z, CCoordinate *c)
	{
		new(c) CCoordinate(x,y,z);
	}
	
	static void ConstructCoordinate4(double x, double y, double z, double w, CCoordinate *c)
	{
		new(c) CCoordinate(x,y,z,w);
	}
	
	static void ConstructCoordinate6(double x, double y, double z, double w, double u, double v, CCoordinate *c)
	{
		new(c) CCoordinate(x,y,z,w,u,v);
	}
	
	static void ConstructCoordinateCopy(const CCoordinate &copy, CCoordinate *c)
	{
		new(c) CCoordinate(copy);
	}
	
	static void SetCoordinate2(double x, double y, CCoordinate *c)
	{
		c->set(x,y);
	}
	
	static void SetCoordinate3(double x, double y, double z, CCoordinate *c)
	{
		c->set(x,y,z);
	}
	
	static void SetCoordinate4(double x, double y, double z, double w, CCoordinate *c)
	{
		c->set(x,y,z,w);
	}
	
	static void SetCoordinate6(double x, double y, double z, double w, double u, double v, CCoordinate *c)
	{
		c->set(x,y,z,w,u,v);
	}
	
	void RegisterANL(asIScriptEngine* engine)
	{
		engine->RegisterObjectType("CCoordinate", sizeof(CCoordinate), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CDAK);
		engine->RegisterObjectBehaviour("CCoordinate", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(ConstructCoordinate), asCALL_CDECL_OBJLAST);
		engine->RegisterObjectBehaviour("CCoordinate", asBEHAVE_CONSTRUCT, "void f(double, double)", asFUNCTION(ConstructCoordinate2), asCALL_CDECL_OBJLAST);
		engine->RegisterObjectBehaviour("CCoordinate", asBEHAVE_CONSTRUCT, "void f(double, double, double)", asFUNCTION(ConstructCoordinate3), asCALL_CDECL_OBJLAST);
		engine->RegisterObjectBehaviour("CCoordinate", asBEHAVE_CONSTRUCT, "void f(double, double, double, double)", asFUNCTION(ConstructCoordinate4), asCALL_CDECL_OBJLAST);
		engine->RegisterObjectBehaviour("CCoordinate", asBEHAVE_CONSTRUCT, "void f(double, double, double, double, double, double)", asFUNCTION(ConstructCoordinate6), asCALL_CDECL_OBJLAST);
		engine->RegisterObjectBehaviour("CCoordinate", asBEHAVE_CONSTRUCT, "void f(const CCoordinate&in)", asFUNCTION(ConstructCoordinateCopy), asCALL_CDECL_OBJLAST);
		engine->RegisterObjectMethod("CCoordinate", "void set(double, double)", asFUNCTION(SetCoordinate2), asCALL_CDECL_OBJLAST);
		engine->RegisterObjectMethod("CCoordinate", "void set(double, double, double)", asFUNCTION(SetCoordinate3), asCALL_CDECL_OBJLAST);
		engine->RegisterObjectMethod("CCoordinate", "void set(double, double, double, double)", asFUNCTION(SetCoordinate4), asCALL_CDECL_OBJLAST);
		engine->RegisterObjectMethod("CCoordinate", "void set(double, double, double, double, double, double)", asFUNCTION(SetCoordinate6), asCALL_CDECL_OBJLAST);
		
	}