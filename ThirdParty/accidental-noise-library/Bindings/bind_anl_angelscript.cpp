// AngelScript bindings

#include "angelscript.h"

#include "../anl.h"

#ifdef ANL_ANGELSCRIPT_BINDSTDSTRING
	#include "../../angelscript/sdk/add_on/scriptstdstring/scriptstdstring.h"
#else
	// Include String type here and typedef to String if needed
	#include "Urho3D/Container/Str.h"
	using namespace Urho3D;
#endif



namespace anl
{

static void ConstructCInstructionIndexCopy(CInstructionIndex &i, CInstructionIndex *c)
{
	new(c) CInstructionIndex(i);
}

static void DestructCInstructionIndex(CInstructionIndex *c)
{
	c->~CInstructionIndex();
}

static void ConstructSRGBA(SRGBA *c)
{
	new(c) SRGBA();
}

static void ConstructSRGBACopy(const SRGBA &s, SRGBA *c)
{
	new(c) SRGBA(s);
}

static void ConstructSRGBAFloats(float r, float g, float b, float a, SRGBA *c)
{
	new(c) SRGBA(r,g,b,a);
}


static void ConstructCKernel(CKernel *k)
{
	new(k) CKernel();
}

static void DestructCKernel(CKernel *k)
{
	k->~CKernel();
}

static CKernel & AssignCKernel(CKernel &k, CKernel *i)
{
	(*i)=k;
	return *i;
}

#ifndef ANL_ANGELSCRIPT_BINDSTDSTRING
	static void CKernelSetVar(String s, double v, CKernel *k)
	{
		k->setVar(std::string(s.CString()), v);
	}
	
	static CInstructionIndex CKernelGetVar(String s, CKernel *k)
	{
		return k->getVar(std::string(s.CString()));
	}
#endif

static void ConstructCNoiseExecutor(CKernel &k, CNoiseExecutor *vm)
{
	new(vm) CNoiseExecutor(k);
}

static void DestructCNoiseExecutor(CNoiseExecutor *vm)
{
	vm->~CNoiseExecutor();
}


static void ConstructCExpressionBuilder(CKernel &k, CExpressionBuilder *eb)
{
	new(eb) CExpressionBuilder(k);
}

static void DestructCExpressionBuilder(CExpressionBuilder *eb)
{
	eb->~CExpressionBuilder();
}

#ifndef ANL_ANGELSCRIPT_BINDSTDSTRING
static CInstructionIndex CExpressionBuilderEval(String s, CExpressionBuilder *eb)
{
	std::string st(s.CString());
	return eb->eval(st);
}

static CInstructionIndex CExpressionBuilderEvalAndStore(String s, CExpressionBuilder *eb)
{
	std::string st(s.CString());
	return eb->evalAndStore(st);
}

static void CExpressionBuilderStoreVar(String s, CInstructionIndex i, CExpressionBuilder *eb)
{
	std::string st(s.CString());
	eb->storeVar(st, i);
}

static CInstructionIndex CExpressionBuilderEvalAndStoreVar(String s, String e, CExpressionBuilder *eb)
{
	std::string st(s.CString()), et(e.CString());
	return eb->evalAndStoreVar(st,et);
}

static CInstructionIndex CExpressionBuilderRetrieveVar(String s, CExpressionBuilder *eb)
{
	std::string st(s.CString());
	return eb->retrieveVar(st);
}

static void ConstructSMappingRanges(SMappingRanges *s)
{
	new(s) SMappingRanges();
}

static void ConstructSMappingRangesCopy(const SMappingRanges &r, SMappingRanges *s)
{
	new(s) SMappingRanges(r);
}

static void ConstructSMappingRangesXY(double x0, double x1, double y0, double y1, SMappingRanges *s)
{
	new(s) SMappingRanges(x0,x1,y0,y1);
}

static void ConstructSMappingRangesXYZ(double x0, double x1, double y0, double y1, double z0, double z1, SMappingRanges *s)
{
	new(s) SMappingRanges(x0,x1,y0,y1,z0,z1);
}

static void ConstructCArray2Dd(CArray2Dd *a)
{
	new(a) CArray2Dd();
}

static void ConstructCArray2DdSize(int w, int h, CArray2Dd *a)
{
	new(a) CArray2Dd(w,h);
}

static void ConstructCArray2Drgba(CArray2Drgba *a)
{
	new(a) CArray2Drgba();
}

static void ConstructCArray2DrgbaSize(int w, int h, CArray2Drgba *a)
{
	new(a) CArray2Drgba(w,h);
}
#endif


void RegisterANL(asIScriptEngine *as)
{
	#ifdef ANL_ANGELSCRIPT_BINDSTDSTRING
	RegisterStdString(as);
	#endif
	as->SetDefaultNamespace("anl");
	//as->SetDefaultNamespace("std");
	as->RegisterEnum("InterpolationTypes");
	as->RegisterEnumValue("InterpolationTypes", "INTERP_NONE", INTERP_NONE);
	as->RegisterEnumValue("InterpolationTypes", "INTERP_LINEAR", INTERP_LINEAR);
	as->RegisterEnumValue("InterpolationTypes", "INTERP_HERMITE", INTERP_HERMITE);
	as->RegisterEnumValue("InterpolationTypes", "INTERP_QUINTIC", INTERP_QUINTIC);
	
	as->RegisterEnum("DistanceTypes");
	as->RegisterEnumValue("DistanceTypes", "DISTANCE_EUCLID", DISTANCE_EUCLID);
	as->RegisterEnumValue("DistanceTypes", "DISTANCE_MANHATTAN", DISTANCE_MANHATTAN);
	as->RegisterEnumValue("DistanceTypes", "DISTANCE_LEASTAXIS", DISTANCE_LEASTAXIS);
	as->RegisterEnumValue("DistanceTypes", "DISTANCE_GREATESTAXIS", DISTANCE_GREATESTAXIS);
	
	as->RegisterEnum("BasisTypes");
	as->RegisterEnumValue("BasisTypes", "BASIS_VALUE", BASIS_VALUE);
	as->RegisterEnumValue("BasisTypes", "BASIS_GRADIENT", BASIS_GRADIENT);
	as->RegisterEnumValue("BasisTypes", "BASIS_SIMPLEX", BASIS_SIMPLEX);
	
	as->RegisterEnum("MappingModes");
	as->RegisterEnumValue("MappingModes", "SEAMLESS_NONE", SEAMLESS_NONE);
	as->RegisterEnumValue("MappingModes", "SEAMLESS_X", SEAMLESS_X);
	as->RegisterEnumValue("MappingModes", "SEAMLESS_Y", SEAMLESS_Y);
	as->RegisterEnumValue("MappingModes", "SEAMLESS_Z", SEAMLESS_Z);
	as->RegisterEnumValue("MappingModes", "SEAMLESS_XY", SEAMLESS_XY);
	as->RegisterEnumValue("MappingModes", "SEAMLESS_XZ", SEAMLESS_XZ);
	as->RegisterEnumValue("MappingModes", "SEAMLESS_YZ", SEAMLESS_YZ);
	as->RegisterEnumValue("MappingModes", "SEAMLESS_XYZ", SEAMLESS_XYZ);
	
	as->RegisterObjectType("CInstructionIndex", sizeof(CInstructionIndex), asOBJ_VALUE | asOBJ_APP_CLASS | asOBJ_APP_CLASS_COPY_CONSTRUCTOR | asOBJ_APP_CLASS_DESTRUCTOR);
	
	// CInstructionIndex
	
	//as->RegisterObjectBehaviour("CInstructionIndex", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(ConstructCInstructionIndex), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("CInstructionIndex", asBEHAVE_CONSTRUCT, "void f(const CInstructionIndex &)", asFUNCTION(ConstructCInstructionIndexCopy), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("CInstructionIndex", asBEHAVE_DESTRUCT, "void f()", asFUNCTION(DestructCInstructionIndex), asCALL_CDECL_OBJLAST);
	
	
	// SRGBA
	as->RegisterObjectType("SRGBA", sizeof(SRGBA), asOBJ_VALUE | asOBJ_APP_CLASS | asOBJ_POD | asOBJ_APP_CLASS_COPY_CONSTRUCTOR);
	as->RegisterObjectBehaviour("SRGBA", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(ConstructSRGBA), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("SRGBA", asBEHAVE_CONSTRUCT, "void f(const SRGBA &)", asFUNCTION(ConstructSRGBACopy), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("SRGBA", asBEHAVE_CONSTRUCT, "void f(float,float,float,float)", asFUNCTION(ConstructSRGBAFloats), asCALL_CDECL_OBJLAST);
	as->RegisterObjectProperty("SRGBA", "float r", offsetof(SRGBA, r));
	as->RegisterObjectProperty("SRGBA", "float g", offsetof(SRGBA, g));
	as->RegisterObjectProperty("SRGBA", "float b", offsetof(SRGBA, b));
	as->RegisterObjectProperty("SRGBA", "float a", offsetof(SRGBA, a));
	
	// SMappingRanges
	as->RegisterObjectType("SMappingRanges", sizeof(SMappingRanges), asOBJ_VALUE | asOBJ_APP_CLASS | asOBJ_POD | asOBJ_APP_CLASS_COPY_CONSTRUCTOR);
	as->RegisterObjectBehaviour("SMappingRanges", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(ConstructSMappingRanges), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("SMappingRanges", asBEHAVE_CONSTRUCT, "void f(const SMappingRanges&)", asFUNCTION(ConstructSMappingRangesCopy), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("SMappingRanges", asBEHAVE_CONSTRUCT, "void f(double,double,double,double)", asFUNCTION(ConstructSMappingRangesXY), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("SMappingRanges", asBEHAVE_CONSTRUCT, "void f(double,double,double,double,double,double)", asFUNCTION(ConstructSMappingRangesXYZ), asCALL_CDECL_OBJLAST);
	as->RegisterObjectProperty("SMappingRanges", "double mapx0", offsetof(SMappingRanges, mapx0));
	as->RegisterObjectProperty("SMappingRanges", "double mapy0", offsetof(SMappingRanges, mapy0));
	as->RegisterObjectProperty("SMappingRanges", "double mapz0", offsetof(SMappingRanges, mapz0));
	as->RegisterObjectProperty("SMappingRanges", "double mapx1", offsetof(SMappingRanges, mapx1));
	as->RegisterObjectProperty("SMappingRanges", "double mapy1", offsetof(SMappingRanges, mapy1));
	as->RegisterObjectProperty("SMappingRanges", "double mapz1", offsetof(SMappingRanges, mapz1));
	
	as->RegisterObjectProperty("SMappingRanges", "double loopx0", offsetof(SMappingRanges, loopx0));
	as->RegisterObjectProperty("SMappingRanges", "double loopy0", offsetof(SMappingRanges, loopy0));
	as->RegisterObjectProperty("SMappingRanges", "double loopz0", offsetof(SMappingRanges, loopz0));
	as->RegisterObjectProperty("SMappingRanges", "double loopx1", offsetof(SMappingRanges, loopx1));
	as->RegisterObjectProperty("SMappingRanges", "double loopy1", offsetof(SMappingRanges, loopy1));
	as->RegisterObjectProperty("SMappingRanges", "double loopz1", offsetof(SMappingRanges, loopz1));
	
	
	// CArray2Dd
	as->RegisterObjectType("CArray2Dd", sizeof(CArray2Dd), asOBJ_VALUE | asOBJ_APP_CLASS);
	as->RegisterObjectBehaviour("CArray2Dd", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(ConstructCArray2Dd), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("CArray2Dd", asBEHAVE_CONSTRUCT, "void f(int,int)", asFUNCTION(ConstructCArray2DdSize), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Dd", "void resize(int,int)", asMETHOD(CArray2Dd,resize), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "int width()", asMETHOD(CArray2Dd,width), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "int height()", asMETHOD(CArray2Dd,height), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void set(int,int,double)", asMETHOD(CArray2Dd,set), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "double get(int,int)", asMETHODPR(CArray2Dd,get,(int,int),double), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "double get(float,float)", asMETHODPR(CArray2Dd,get,(float,float),double), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "double getIndexed(int)", asMETHOD(CArray2Dd,getIndexed), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void fill(double)", asMETHOD(CArray2Dd,fill), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void copyFrom(CArray2Dd *)", asMETHOD(CArray2Dd,copyFrom), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void addArray(CArray2Dd *)", asMETHOD(CArray2Dd,addArray), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void subtractArray(CArray2Dd *)", asMETHOD(CArray2Dd,subtractArray), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void multiplyArray(CArray2Dd *)", asMETHOD(CArray2Dd,multiplyArray), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void copyFromSub(CArray2Dd *, int, int)", asMETHOD(CArray2Dd,copyFromSub), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void addArraySub(CArray2Dd *, int, int)", asMETHOD(CArray2Dd,addArraySub), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void subtractArraySub(CArray2Dd *, int, int)", asMETHOD(CArray2Dd,subtractArraySub), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void multiplyArraySub(CArray2Dd *, int, int)", asMETHOD(CArray2Dd,multiplyArraySub), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void scale(float)", asMETHOD(CArray2Dd,scale), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "double getMax()", asMETHOD(CArray2Dd,getMax), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "double getMin()", asMETHOD(CArray2Dd,getMin), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void scaleToRange(float, float)", asMETHOD(CArray2Dd,scaleToRange), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void offset(int,int)", asMETHOD(CArray2Dd,offset), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void flipVertical()", asMETHOD(CArray2Dd,flipVertical), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void flipHorizontal()", asMETHOD(CArray2Dd,flipHorizontal), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void blur(float,bool)", asMETHOD(CArray2Dd,blur), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void subtractFilter(CArray2Dd *)", asMETHOD(CArray2Dd,subtractFilter), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void addFilter(CArray2Dd *)", asMETHOD(CArray2Dd,addFilter), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void scaleTo(CArray2Dd *)", asMETHOD(CArray2Dd,scaleTo), asCALL_THISCALL);
	
	as->RegisterObjectType("CArray2Drgba", sizeof(CArray2Drgba), asOBJ_VALUE | asOBJ_APP_CLASS);
	as->RegisterObjectBehaviour("CArray2Drgba", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(ConstructCArray2Drgba), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("CArray2Drgba", asBEHAVE_CONSTRUCT, "void f(int,int)", asFUNCTION(ConstructCArray2DrgbaSize), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Drgba", "void resize(int,int)", asMETHOD(CArray2Drgba,resize), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "int width()", asMETHOD(CArray2Drgba,width), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "int height()", asMETHOD(CArray2Drgba,height), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void set(int,int,SRGBA)", asMETHOD(CArray2Drgba,set), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "SRGBA get(int,int)", asMETHODPR(CArray2Drgba,get,(int,int),SRGBA), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "SRGBA get(float,float)", asMETHODPR(CArray2Drgba,get,(float,float),SRGBA), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "SRGBA getIndexed(int)", asMETHOD(CArray2Drgba,getIndexed), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void fill(SRGBA)", asMETHOD(CArray2Drgba,fill), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void copyFrom(CArray2Drgba *)", asMETHOD(CArray2Drgba,copyFrom), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void addArray(CArray2Drgba *)", asMETHOD(CArray2Drgba,addArray), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void subtractArray(CArray2Drgba *)", asMETHOD(CArray2Drgba,subtractArray), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void multiplyArray(CArray2Drgba *)", asMETHOD(CArray2Drgba,multiplyArray), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void copyFromSub(CArray2Drgba *, int, int)", asMETHOD(CArray2Drgba,copyFromSub), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void addArraySub(CArray2Drgba *, int, int)", asMETHOD(CArray2Drgba,addArraySub), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void subtractArraySub(CArray2Drgba *, int, int)", asMETHOD(CArray2Drgba,subtractArraySub), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void multiplyArraySub(CArray2Drgba *, int, int)", asMETHOD(CArray2Drgba,multiplyArraySub), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void scale(SRGBA)", asMETHOD(CArray2Drgba,scale), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void offset(int,int)", asMETHOD(CArray2Drgba,offset), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void flipVertical()", asMETHOD(CArray2Drgba,flipVertical), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void flipHorizontal()", asMETHOD(CArray2Drgba,flipHorizontal), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void blur(float,bool)", asMETHOD(CArray2Drgba,blur), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void scaleTo(CArray2Drgba *)", asMETHOD(CArray2Drgba,scaleTo), asCALL_THISCALL);
	
	
	// CKernel
	
	as->RegisterObjectType("CKernel", sizeof(CKernel), asOBJ_APP_CLASS  | asOBJ_VALUE | asOBJ_APP_CLASS_CONSTRUCTOR);
	as->RegisterObjectBehaviour("CKernel", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(ConstructCKernel), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("CKernel", asBEHAVE_DESTRUCT, "void f()", asFUNCTION(DestructCKernel), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CKernel", "CKernel &opAssign(const CKernel&in)", asMETHOD(CKernel,operator =), asCALL_THISCALL);
    
	as->RegisterObjectMethod("CKernel", "CInstructionIndex pi()", asMETHOD(CKernel, pi), asCALL_THISCALL);
	
	#ifdef ANL_ANGLESCRIPT_BINDSTDSTRING
		as->RegisterObjectMethod("CKernel", "void setVar(std::string, double)", asMETHOD(CKernel, setVar), asCALL_THISCALL);
		as->RegisterObjectMethod("CKernel", "CInstructionIndex getVar(std::string)", asMETHOD(CKernel, getVar), asCALL_THISCALL);
	#else
		as->RegisterObjectMethod("CKernel", "void setVar(String, double)", asFUNCTION(CKernelSetVar), asCALL_CDECL_OBJLAST);
		as->RegisterObjectMethod("CKernel", "CInstructionIndex getVar(String)", asFUNCTION(CKernelGetVar), asCALL_CDECL_OBJLAST);
	#endif
	
	// CNoiseExecutor
	
	as->RegisterObjectType("CNoiseExecutor", sizeof(CNoiseExecutor), asOBJ_APP_CLASS | asOBJ_VALUE);
	as->RegisterObjectBehaviour("CNoiseExecutor", asBEHAVE_CONSTRUCT, "void f(CKernel &i)", asFUNCTION(ConstructCNoiseExecutor), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("CNoiseExecutor", asBEHAVE_DESTRUCT, "void f()", asFUNCTION(DestructCNoiseExecutor), asCALL_CDECL_OBJLAST);
	//as->RegisterObjectMethod("CNoiseExecutor", "CNoiseExecutor &opAssign(const CNoiseExecutor&in)", asMETHOD(CNoiseExecutor,operator =), asCALL_THISCALL);
	
	as->RegisterObjectMethod("CNoiseExecutor", "double evaluateScalar(double,double,CInstructionIndex)", asMETHODPR(CNoiseExecutor,evaluateScalar,(double,double,CInstructionIndex),double), asCALL_THISCALL);
	as->RegisterObjectMethod("CNoiseExecutor", "double evaluateScalar(double,double,double,CInstructionIndex)", asMETHODPR(CNoiseExecutor,evaluateScalar,(double,double,double,CInstructionIndex),double), asCALL_THISCALL);
	as->RegisterObjectMethod("CNoiseExecutor", "double evaluateScalar(double,double,double,double,CInstructionIndex)", asMETHODPR(CNoiseExecutor,evaluateScalar,(double,double,double,double,CInstructionIndex),double), asCALL_THISCALL);
	as->RegisterObjectMethod("CNoiseExecutor", "double evaluateScalar(double,double,double,double,double,double,CInstructionIndex)", asMETHODPR(CNoiseExecutor,evaluateScalar,(double,double,double,double,double,double,CInstructionIndex),double), asCALL_THISCALL);
	
	as->RegisterObjectMethod("CNoiseExecutor", "SRGBA evaluateColor(double,double,CInstructionIndex)", asMETHODPR(CNoiseExecutor,evaluateColor,(double,double,CInstructionIndex),SRGBA), asCALL_THISCALL);
	as->RegisterObjectMethod("CNoiseExecutor", "SRGBA evaluateColor(double,double,double,CInstructionIndex)", asMETHODPR(CNoiseExecutor,evaluateColor,(double,double,double,CInstructionIndex),SRGBA), asCALL_THISCALL);
	as->RegisterObjectMethod("CNoiseExecutor", "SRGBA evaluateColor(double,double,double,double,CInstructionIndex)", asMETHODPR(CNoiseExecutor,evaluateColor,(double,double,double,double,CInstructionIndex),SRGBA), asCALL_THISCALL);
	as->RegisterObjectMethod("CNoiseExecutor", "SRGBA evaluateColor(double,double,double,double,double,double,CInstructionIndex)", asMETHODPR(CNoiseExecutor,evaluateColor,(double,double,double,double,double,double,CInstructionIndex),SRGBA), asCALL_THISCALL);
	
	// Expression builder
	as->RegisterObjectType("CExpressionBuilder", sizeof(CExpressionBuilder), asOBJ_APP_CLASS | asOBJ_VALUE);
	as->RegisterObjectBehaviour("CExpressionBuilder", asBEHAVE_CONSTRUCT, "void f(CKernel &i)", asFUNCTION(ConstructCExpressionBuilder), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("CExpressionBuilder", asBEHAVE_DESTRUCT, "void f()", asFUNCTION(DestructCExpressionBuilder), asCALL_CDECL_OBJLAST);
	
	#ifdef ANL_ANGLESCRIPT_BINDSTDSTRING
		as->RegisterObjectMethod("CExpressionBuilder", "CInstructionIndex eval(std::string &)", asMETHOD(CExpressionBuilder, eval), asCALL_THISCALL);
		as->RegisterObjectMethod("CExpressionBuilder", "CInstructionIndex evalAndStore(const std::string &)", asMETHOD(CExpressionBuilder, evalAndStore), asCALL_THISCALL);
		as->RegisterObjectMethod("CExpressionBuilder", "CInstructionIndex evalAndStoreVar(const std::string&, const std::string &)", asMETHOD(CExpressionBuilder, evalAndStoreVar), asCALL_THISCALL);
		as->RegisterObjectMethod("CExpressionBuilder", "void storeVar(std::string, CInstructionIndex)", asMETHOD(CExpressionBuilder,storeVar), asCALL_THISCALL);
		as->RegisterObjectMethod("CExpressionBuilder", "CInstructionIndex retreiveVar(const std::string &)", asMETHOD(CExpressionBuilder, retreiveVar), asCALL_THISCALL);
	#else
		as->RegisterObjectMethod("CExpressionBuilder", "CInstructionIndex eval(String)", asFUNCTION(CExpressionBuilderEval), asCALL_CDECL_OBJLAST);
		as->RegisterObjectMethod("CExpressionBuilder", "CInstructionIndex evalAndStore(String)", asFUNCTION(CExpressionBuilderEvalAndStore), asCALL_CDECL_OBJLAST);
		as->RegisterObjectMethod("CExpressionBuilder", "CInstructionIndex evalAndStoreVar(String, String)", asFUNCTION(CExpressionBuilderEvalAndStoreVar), asCALL_CDECL_OBJLAST);
		as->RegisterObjectMethod("CExpressionBuilder", "void storeVar(String, CInstructionIndex)", asFUNCTION(CExpressionBuilderStoreVar), asCALL_CDECL_OBJLAST);
		as->RegisterObjectMethod("CExpressionBuilder", "CInstructionIndex retrieveVar(String)", asFUNCTION(CExpressionBuilderRetrieveVar), asCALL_CDECL_OBJLAST);
	#endif
	
	as->RegisterObjectMethod("CExpressionBuilder", "void store(CInstructionIndex)", asMETHOD(CExpressionBuilder,store), asCALL_THISCALL);
	as->RegisterObjectMethod("CExpressionBuilder", "void setRandomSeed(int)", asMETHOD(CExpressionBuilder,setRandomSeed), asCALL_THISCALL);
	
}


};
