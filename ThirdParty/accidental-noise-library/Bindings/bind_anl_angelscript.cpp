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
#endif


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

static void DestructCArray2Dd(CArray2Dd *a)
{
	a->~CArray2Dd();
}

static void ConstructCArray2DdSize(int w, int h, CArray2Dd *a)
{
	new(a) CArray2Dd(w,h);
}

static void ConstructCArray2Drgba(CArray2Drgba *a)
{
	new(a) CArray2Drgba();
}

static void DestructCArray2Drgba(CArray2Drgba *a)
{
	a->~CArray2Drgba();
}

static void ConstructCArray2DrgbaSize(int w, int h, CArray2Drgba *a)
{
	new(a) CArray2Drgba(w,h);
}

static void ConstructCArray3Dd(CArray3Dd *a)
{
	new(a) CArray3Dd();
}

static void DestructCArray3Dd(CArray3Dd *a)
{
	a->~CArray3Dd();
}

static void ConstructCArray3DdSize(int w, int h, int d, CArray3Dd *a)
{
	new(a) CArray3Dd(w,h,d);
}

static void ConstructCArray3Drgba(CArray3Drgba *a)
{
	new(a) CArray3Drgba();
}

static void DestructCArray3Drgba(CArray3Drgba *a)
{
	a->~CArray3Drgba();
}

static void ConstructCArray3DrgbaSize(int w, int h, int d, CArray3Drgba *a)
{
	new(a) CArray3Drgba(w,h,d);
}

#ifdef ANL_ANGELSCRIPT_BINDSTDSTRING
	static void saveDoubleArrayString(std::string filename, CArray2Dd &a)
	{
		saveDoubleArray(filename,&a);
	}
	static void saveRGBAArrayString(std::string filename, CArray2Drgba &a)
	{
		saveRGBAArray(filename,&a);
	}
	static void loadDoubleArrayString(std::string filename, CArray2Dd &a)
	{
		loadDoubleArray(filename,&a);
	}
	static void loadRGBAArrayString(std::string filename, CArray2Drgba &a)
	{
		loadRGBAArray(filename,&a);
	}
	
	static void saveHeightmapString(std::string filename, CArray2Dd &a)
	{
		saveHeightmap(filename, &a);
	}
	
#else
	static void saveDoubleArrayString(String filename, CArray2Dd &a)
	{
		std::string s(filename.CString());
		saveDoubleArray(s,&a);
	}
	static void saveRGBAArrayString(String filename, CArray2Drgba &a)
	{
		std::string s(filename.CString());
		saveRGBAArray(s,&a);
	}
	static void loadDoubleArrayString(String filename, CArray2Dd &a)
	{
		std::string s(filename.CString());
		loadDoubleArray(s,&a);
	}
	static void loadRGBAArrayString(String filename, CArray2Drgba &a)
	{
		std::string s(filename.CString());
		loadRGBAArray(s,&a);
	}
	static void saveHeightmapString(String filename, CArray2Dd &a)
	{
		std::string s(filename.CString());
		saveHeightmap(s,&a);
	}
#endif

static void CArray2DdCopyFrom(CArray2Dd &b, CArray2Dd *d)
{
	d->copyFrom(&b);
}
static void CArray2DdAddArray(CArray2Dd &b, CArray2Dd *d)
{
	d->addArray(&b);
}
static void CArray2DdSubtractArray(CArray2Dd &b, CArray2Dd *d)
{
	d->subtractArray(&b);
}
static void CArray2DdMultiplyArray(CArray2Dd &b, CArray2Dd *d)
{
	d->multiplyArray(&b);
}
static void CArray2DdCopyFromSub(CArray2Dd &b, int x, int y, CArray2Dd *d)
{
	d->copyFromSub(&b,x,y);
}
static void CArray2DdAddArraySub(CArray2Dd &b, int x, int y, CArray2Dd *d)
{
	d->addArraySub(&b,x,y);
}
static void CArray2DdSubtractArraySub(CArray2Dd &b, int x, int y, CArray2Dd *d)
{
	d->subtractArraySub(&b,x,y);
}
static void CArray2DdMultiplyArraySub(CArray2Dd &b, int x, int y, CArray2Dd *d)
{
	d->multiplyArraySub(&b,x,y);
}
static void CArray2DdScaleTo(CArray2Dd &b, CArray2Dd *d)
{
	d->scaleTo(&b);
}
static void CArray2DdAddFilter(CArray2Dd &b, CArray2Dd *d)
{
	d->addFilter(&b);
}
static void CArray2DdSubtractFilter(CArray2Dd &b, CArray2Dd *d)
{
	d->subtractFilter(&b);
}



static void CArray2DrgbaCopyFrom(CArray2Drgba &b, CArray2Drgba *d)
{
	d->copyFrom(&b);
}
static void CArray2DrgbaAddArray(CArray2Drgba &b, CArray2Drgba *d)
{
	d->addArray(&b);
}
static void CArray2DrgbaSubtractArray(CArray2Drgba &b, CArray2Drgba *d)
{
	d->subtractArray(&b);
}
static void CArray2DrgbaMultiplyArray(CArray2Drgba &b, CArray2Drgba *d)
{
	d->multiplyArray(&b);
}
static void CArray2DrgbaCopyFromSub(CArray2Drgba &b, int x, int y, CArray2Drgba *d)
{
	d->copyFromSub(&b,x,y);
}
static void CArray2DrgbaAddArraySub(CArray2Drgba &b, int x, int y, CArray2Drgba *d)
{
	d->addArraySub(&b,x,y);
}
static void CArray2DrgbaSubtractArraySub(CArray2Drgba &b, int x, int y, CArray2Drgba *d)
{
	d->subtractArraySub(&b,x,y);
}
static void CArray2DrgbaMultiplyArraySub(CArray2Drgba &b, int x, int y, CArray2Drgba *d)
{
	d->multiplyArraySub(&b,x,y);
}
static void CArray2DrgbaScaleTo(CArray2Drgba &b, CArray2Drgba *d)
{
	d->scaleTo(&b);
}

static void CalcNormalMap(CArray2Dd &map, CArray2Drgba &bump, float spacing, bool normalize, bool wrap)
{
	calcNormalMap(&map, &bump, spacing, normalize, wrap);
}

static void CalcBumpMap(CArray2Dd &map, CArray2Dd &bump, float lx, float ly, float lz, float spacing, bool wrap)
{
	float light[3]={lx,ly,lz};
	calcBumpMap(&map, &bump, light, spacing, wrap);
}


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
	as->RegisterObjectBehaviour("CArray2Dd", asBEHAVE_DESTRUCT, "void f()", asFUNCTION(DestructCArray2Dd), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Dd", "void resize(int,int)", asMETHOD(CArray2Dd,resize), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "int width()", asMETHOD(CArray2Dd,width), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "int height()", asMETHOD(CArray2Dd,height), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void set(int,int,double)", asMETHOD(CArray2Dd,set), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "double get(int,int)", asMETHODPR(CArray2Dd,get,(int,int),double), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "double get(float,float)", asMETHODPR(CArray2Dd,get,(float,float),double), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "double getIndexed(int)", asMETHOD(CArray2Dd,getIndexed), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void fill(double)", asMETHOD(CArray2Dd,fill), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void copyFrom(CArray2Dd &)", asFUNCTION(CArray2DdCopyFrom), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Dd", "void addArray(CArray2Dd &)", asFUNCTION(CArray2DdAddArray), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Dd", "void subtractArray(CArray2Dd &)", asFUNCTION(CArray2DdSubtractArray), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Dd", "void multiplyArray(CArray2Dd &)", asFUNCTION(CArray2DdMultiplyArray), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Dd", "void copyFromSub(CArray2Dd &, int, int)", asFUNCTION(CArray2DdCopyFromSub), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Dd", "void addArraySub(CArray2Dd &, int, int)", asFUNCTION(CArray2DdAddArraySub), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Dd", "void subtractArraySub(CArray2Dd &, int, int)", asFUNCTION(CArray2DdSubtractArraySub), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Dd", "void multiplyArraySub(CArray2Dd &, int, int)", asFUNCTION(CArray2DdMultiplyArraySub), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Dd", "void scale(float)", asMETHOD(CArray2Dd,scale), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "double getMax()", asMETHOD(CArray2Dd,getMax), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "double getMin()", asMETHOD(CArray2Dd,getMin), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void scaleToRange(double,double)", asMETHOD(CArray2Dd,scaleToRange), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void offset(int,int)", asMETHOD(CArray2Dd,offset), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void flipVertical()", asMETHOD(CArray2Dd,flipVertical), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void flipHorizontal()", asMETHOD(CArray2Dd,flipHorizontal), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void blur(float,bool)", asMETHOD(CArray2Dd,blur), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Dd", "void subtractFilter(CArray2Dd &)", asFUNCTION(CArray2DdSubtractFilter), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Dd", "void addFilter(CArray2Dd &)", asFUNCTION(CArray2DdAddFilter), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Dd", "void scaleTo(CArray2Dd &)", asFUNCTION(CArray2DdScaleTo), asCALL_CDECL_OBJLAST);
	
	as->RegisterObjectType("CArray2Drgba", sizeof(CArray2Drgba), asOBJ_VALUE | asOBJ_APP_CLASS);
	as->RegisterObjectBehaviour("CArray2Drgba", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(ConstructCArray2Drgba), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("CArray2Drgba", asBEHAVE_CONSTRUCT, "void f(int,int)", asFUNCTION(ConstructCArray2DrgbaSize), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("CArray2Drgba", asBEHAVE_DESTRUCT, "void f()", asFUNCTION(DestructCArray2Drgba), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Drgba", "void resize(int,int)", asMETHOD(CArray2Drgba,resize), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "int width()", asMETHOD(CArray2Drgba,width), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "int height()", asMETHOD(CArray2Drgba,height), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void set(int,int,SRGBA)", asMETHOD(CArray2Drgba,set), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "SRGBA get(int,int)", asMETHODPR(CArray2Drgba,get,(int,int),SRGBA), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "SRGBA get(float,float)", asMETHODPR(CArray2Drgba,get,(float,float),SRGBA), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "SRGBA getIndexed(int)", asMETHOD(CArray2Drgba,getIndexed), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void fill(SRGBA)", asMETHOD(CArray2Drgba,fill), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void copyFrom(CArray2Drgba &)", asFUNCTION(CArray2DrgbaCopyFrom), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Drgba", "void addArray(CArray2Drgba &)", asFUNCTION(CArray2DrgbaAddArray), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Drgba", "void subtractArray(CArray2Drgba &)", asFUNCTION(CArray2DrgbaSubtractArray), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Drgba", "void multiplyArray(CArray2Drgba &)", asFUNCTION(CArray2DrgbaMultiplyArray), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Drgba", "void copyFromSub(CArray2Drgba &, int, int)", asFUNCTION(CArray2DrgbaCopyFromSub), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Drgba", "void addArraySub(CArray2Drgba &, int, int)", asFUNCTION(CArray2DrgbaAddArraySub), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Drgba", "void subtractArraySub(CArray2Drgba &, int, int)", asFUNCTION(CArray2DrgbaSubtractArraySub), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Drgba", "void multiplyArraySub(CArray2Drgba &, int, int)", asFUNCTION(CArray2DrgbaMultiplyArraySub), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray2Drgba", "void scale(SRGBA)", asMETHOD(CArray2Drgba,scale), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void offset(int,int)", asMETHOD(CArray2Drgba,offset), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void flipVertical()", asMETHOD(CArray2Drgba,flipVertical), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void flipHorizontal()", asMETHOD(CArray2Drgba,flipHorizontal), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void blur(float,bool)", asMETHOD(CArray2Drgba,blur), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray2Drgba", "void scaleTo(CArray2Drgba &)", asFUNCTION(CArray2DrgbaScaleTo), asCALL_CDECL_OBJLAST);
	
	// CArray3Dd
	
	as->RegisterObjectType("CArray3Dd", sizeof(CArray3Dd), asOBJ_VALUE | asOBJ_APP_CLASS);
	as->RegisterObjectBehaviour("CArray3Dd", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(ConstructCArray3Dd), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("CArray3Dd", asBEHAVE_CONSTRUCT, "void f(int,int,int)", asFUNCTION(ConstructCArray3DdSize), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("CArray3Dd", asBEHAVE_DESTRUCT, "void f()", asFUNCTION(DestructCArray3Dd), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray3Dd", "int width()", asMETHOD(CArray3Dd,width), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray3Dd", "int height()", asMETHOD(CArray3Dd,height), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray3Dd", "int depth()", asMETHOD(CArray3Dd,depth), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray3Dd", "void resize(int,int,int)", asMETHOD(CArray3Dd,resize), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray3Dd", "void set(int,int,int,double)", asMETHOD(CArray3Dd,set), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray3Dd", "double get(int,int,int)", asMETHOD(CArray3Dd,get), asCALL_THISCALL);
	
	as->RegisterObjectType("CArray3Drgba", sizeof(CArray3Drgba), asOBJ_VALUE | asOBJ_APP_CLASS);
	as->RegisterObjectBehaviour("CArray3Drgba", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(ConstructCArray3Drgba), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("CArray3Drgba", asBEHAVE_CONSTRUCT, "void f(int,int,int)", asFUNCTION(ConstructCArray3DrgbaSize), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("CArray3Drgba", asBEHAVE_DESTRUCT, "void f()", asFUNCTION(DestructCArray3Drgba), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CArray3Drgba", "int width()", asMETHOD(CArray3Drgba,width), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray3Drgba", "int height()", asMETHOD(CArray3Drgba,height), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray3Drgba", "int depth()", asMETHOD(CArray3Drgba,depth), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray3Drgba", "void resize(int,int,int)", asMETHOD(CArray3Drgba,resize), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray3Drgba", "void set(int,int,int,SRGBA)", asMETHOD(CArray3Drgba,set), asCALL_THISCALL);
	as->RegisterObjectMethod("CArray3Drgba", "SRGBA get(int,int,int)", asMETHOD(CArray3Drgba,get), asCALL_THISCALL);
	
	
	// CKernel
	
	as->RegisterObjectType("CKernel", sizeof(CKernel), asOBJ_APP_CLASS  | asOBJ_VALUE | asOBJ_APP_CLASS_CONSTRUCTOR);
	as->RegisterObjectBehaviour("CKernel", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(ConstructCKernel), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("CKernel", asBEHAVE_DESTRUCT, "void f()", asFUNCTION(DestructCKernel), asCALL_CDECL_OBJLAST);
	as->RegisterObjectMethod("CKernel", "CKernel &opAssign(const CKernel&in)", asMETHOD(CKernel,operator =), asCALL_THISCALL);
    
	as->RegisterObjectMethod("CKernel", "CInstructionIndex pi()", asMETHOD(CKernel, pi), asCALL_THISCALL);
	
	#ifdef ANL_ANGELSCRIPT_BINDSTDSTRING
		as->RegisterObjectMethod("CKernel", "void setVar(std::string, double)", asMETHOD(CKernel, setVar), asCALL_THISCALL);
		as->RegisterObjectMethod("CKernel", "CInstructionIndex getVar(std::string)", asMETHOD(CKernel, getVar), asCALL_THISCALL);
	#else
		as->RegisterObjectMethod("CKernel", "void setVar(String, double)", asFUNCTION(CKernelSetVar), asCALL_CDECL_OBJLAST);
		as->RegisterObjectMethod("CKernel", "CInstructionIndex getVar(String)", asFUNCTION(CKernelGetVar), asCALL_CDECL_OBJLAST);
	#endif
	as->RegisterObjectMethod("CKernel", "CInstructionIndex e()", asMETHOD(CKernel, e), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex one()", asMETHOD(CKernel, one), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex zero()", asMETHOD(CKernel, zero), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex point5()", asMETHOD(CKernel, point5), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex sqrt2()", asMETHOD(CKernel, sqrt2), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex constant(double val)", asMETHOD(CKernel, constant), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex seed(int val)", asMETHOD(CKernel, seed), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex valueBasis(CInstructionIndex interpindex, CInstructionIndex seed)", asMETHOD(CKernel, valueBasis), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex gradientBasis(CInstructionIndex interpindex, CInstructionIndex seed)", asMETHOD(CKernel, gradientBasis), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex simplexBasis(CInstructionIndex seed)", asMETHOD(CKernel, simplexBasis), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex cellularBasis(CInstructionIndex f1, CInstructionIndex f2, CInstructionIndex f3, CInstructionIndex f4, CInstructionIndex d1, CInstructionIndex d2, CInstructionIndex d3, CInstructionIndex d4, CInstructionIndex dist, CInstructionIndex seed)", asMETHOD(CKernel, cellularBasis), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex add(CInstructionIndex s1index, CInstructionIndex s2index)", asMETHOD(CKernel, add), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex subtract(CInstructionIndex s1, CInstructionIndex s2)", asMETHOD(CKernel, subtract), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex multiply(CInstructionIndex s1index, CInstructionIndex s2index)", asMETHOD(CKernel, multiply), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex divide(CInstructionIndex s1, CInstructionIndex s2)", asMETHOD(CKernel, divide), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex maximum(CInstructionIndex s1index, CInstructionIndex s2index)", asMETHOD(CKernel, maximum), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex minimum(CInstructionIndex s1index, CInstructionIndex s2index)", asMETHOD(CKernel, minimum), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex abs(CInstructionIndex sindex)", asMETHOD(CKernel, abs), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex pow(CInstructionIndex s1, CInstructionIndex s2)", asMETHOD(CKernel, pow), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex bias(CInstructionIndex s1, CInstructionIndex s2)", asMETHOD(CKernel, bias), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex gain(CInstructionIndex s1, CInstructionIndex s2)", asMETHOD(CKernel, gain), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex scaleDomain(CInstructionIndex srcindex, CInstructionIndex scale)", asMETHOD(CKernel, scaleDomain), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex scaleX(CInstructionIndex src, CInstructionIndex scale)", asMETHOD(CKernel, scaleX), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex scaleY(CInstructionIndex src, CInstructionIndex scale)", asMETHOD(CKernel, scaleY), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex scaleZ(CInstructionIndex src, CInstructionIndex scale)", asMETHOD(CKernel, scaleZ), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex scaleW(CInstructionIndex src, CInstructionIndex scale)", asMETHOD(CKernel, scaleW), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex scaleU(CInstructionIndex src, CInstructionIndex scale)", asMETHOD(CKernel, scaleU), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex scaleV(CInstructionIndex src, CInstructionIndex scale)", asMETHOD(CKernel, scaleV), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex translateDomain(CInstructionIndex srcindex, CInstructionIndex trans)", asMETHOD(CKernel, translateDomain), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex translateX(CInstructionIndex src, CInstructionIndex trans)", asMETHOD(CKernel, translateX), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex translateY(CInstructionIndex src, CInstructionIndex trans)", asMETHOD(CKernel, translateY), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex translateZ(CInstructionIndex src, CInstructionIndex trans)", asMETHOD(CKernel, translateZ), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex translateW(CInstructionIndex src, CInstructionIndex trans)", asMETHOD(CKernel, translateW), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex translateU(CInstructionIndex src, CInstructionIndex trans)", asMETHOD(CKernel, translateU), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex translateV(CInstructionIndex src, CInstructionIndex trans)", asMETHOD(CKernel, translateV), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex rotateDomain(CInstructionIndex src, CInstructionIndex angle, CInstructionIndex ax, CInstructionIndex ay, CInstructionIndex az)", asMETHOD(CKernel, rotateDomain), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex addSequence(CInstructionIndex baseindex, int number, int stride)", asMETHOD(CKernel, addSequence), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex multiplySequence(CInstructionIndex baseindex, int number, int stride)", asMETHOD(CKernel, multiplySequence), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex maxSequence(CInstructionIndex baseindex, int number, int stride)", asMETHOD(CKernel, maxSequence), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex minSequence(CInstructionIndex baseindex, int number, int stride)", asMETHOD(CKernel, minSequence), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex mix(CInstructionIndex low, CInstructionIndex high, CInstructionIndex control)", asMETHOD(CKernel, mix), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex select(CInstructionIndex low, CInstructionIndex high, CInstructionIndex control, CInstructionIndex threshold, CInstructionIndex falloff)", asMETHOD(CKernel, select), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex clamp(CInstructionIndex src, CInstructionIndex low, CInstructionIndex high)", asMETHOD(CKernel, clamp), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex cos(CInstructionIndex src)", asMETHOD(CKernel, cos), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex sin(CInstructionIndex src)", asMETHOD(CKernel, sin), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex tan(CInstructionIndex src)", asMETHOD(CKernel, tan), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex acos(CInstructionIndex src)", asMETHOD(CKernel, acos), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex asin(CInstructionIndex src)", asMETHOD(CKernel, asin), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex atan(CInstructionIndex src)", asMETHOD(CKernel, atan), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex tiers(CInstructionIndex src, CInstructionIndex numtiers)", asMETHOD(CKernel, tiers), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex smoothTiers(CInstructionIndex src, CInstructionIndex numtiers)", asMETHOD(CKernel, smoothTiers), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex x()", asMETHOD(CKernel, x), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex y()", asMETHOD(CKernel, y), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex z()", asMETHOD(CKernel, z), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex w()", asMETHOD(CKernel, w), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex u()", asMETHOD(CKernel, u), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex v()", asMETHOD(CKernel, v), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex dx(CInstructionIndex src, CInstructionIndex spacing)", asMETHOD(CKernel, dx), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex dy(CInstructionIndex src, CInstructionIndex spacing)", asMETHOD(CKernel, dy), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex dz(CInstructionIndex src, CInstructionIndex spacing)", asMETHOD(CKernel, dz), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex dw(CInstructionIndex src, CInstructionIndex spacing)", asMETHOD(CKernel, dw), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex du(CInstructionIndex src, CInstructionIndex spacing)", asMETHOD(CKernel, du), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex dv(CInstructionIndex src, CInstructionIndex spacing)", asMETHOD(CKernel, dv), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex sigmoid(CInstructionIndex src)", asMETHODPR(CKernel, sigmoid,(CInstructionIndex),CInstructionIndex), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex sigmoid(CInstructionIndex src, CInstructionIndex center, CInstructionIndex ramp)", asMETHODPR(CKernel, sigmoid,(CInstructionIndex,CInstructionIndex,CInstructionIndex),CInstructionIndex), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex radial()", asMETHOD(CKernel, radial), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex hexTile(CInstructionIndex seed)", asMETHOD(CKernel, hexTile), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex hexBump()", asMETHOD(CKernel, hexBump), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex color(SRGBA c)", asMETHODPR(CKernel, color,(SRGBA),CInstructionIndex), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex color(float r, float g, float b, float a)", asMETHODPR(CKernel, color,(float,float,float,float),CInstructionIndex), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex combineRGBA(CInstructionIndex r, CInstructionIndex g, CInstructionIndex b, CInstructionIndex a)", asMETHOD(CKernel, combineRGBA), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex scaleOffset(CInstructionIndex src, double scale, double offset)", asMETHOD(CKernel, scaleOffset), asCALL_THISCALL);
	as->RegisterObjectMethod("CKernel", "CInstructionIndex simplefBm(int basistype, int interptype, int numoctaves, double frequency, int seed, bool rot)", asMETHOD(CKernel, simplefBm), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex simpleRidgedMultifractal(int basistype, int interptype, int numoctaves, double frequency, int seed, bool rot)", asMETHOD(CKernel, simpleRidgedMultifractal), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex simpleBillow(int basistype, int interptype, int numoctaves, double frequency, int seed, bool rot)", asMETHOD(CKernel, simpleBillow), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex nextIndex()", asMETHOD(CKernel, nextIndex), asCALL_THISCALL);
    as->RegisterObjectMethod("CKernel", "CInstructionIndex lastIndex()", asMETHOD(CKernel, lastIndex), asCALL_THISCALL);
 
	
	// CNoiseExecutor
	
	as->RegisterObjectType("CNoiseExecutor", sizeof(CNoiseExecutor), asOBJ_APP_CLASS | asOBJ_VALUE);
	as->RegisterObjectBehaviour("CNoiseExecutor", asBEHAVE_CONSTRUCT, "void f(CKernel &i)", asFUNCTION(ConstructCNoiseExecutor), asCALL_CDECL_OBJLAST);
	as->RegisterObjectBehaviour("CNoiseExecutor", asBEHAVE_DESTRUCT, "void f()", asFUNCTION(DestructCNoiseExecutor), asCALL_CDECL_OBJLAST);
	
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
	
	#ifdef ANL_ANGELSCRIPT_BINDSTDSTRING
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
	
	// Mapping
	as->RegisterGlobalFunction("void map2D(int, CArray2Dd &, CKernel &, SMappingRanges, double, CInstructionIndex)", asFUNCTION(map2D), asCALL_CDECL);
	as->RegisterGlobalFunction("void map2DNoZ(int, CArray2Dd &, CKernel &, SMappingRanges, CInstructionIndex)", asFUNCTION(map2DNoZ), asCALL_CDECL);
	as->RegisterGlobalFunction("void map3D(int, CArray3Dd &, CKernel &, SMappingRanges, CInstructionIndex)", asFUNCTION(map3D), asCALL_CDECL);
	
	as->RegisterGlobalFunction("void mapRGBA2D(int, CArray2Drgba &, CKernel &, SMappingRanges, double, CInstructionIndex)", asFUNCTION(mapRGBA2D), asCALL_CDECL);
	as->RegisterGlobalFunction("void mapRGBA2DNoZ(int, CArray2Drgba &, CKernel &, SMappingRanges, CInstructionIndex)", asFUNCTION(mapRGBA2DNoZ), asCALL_CDECL);
	as->RegisterGlobalFunction("void mapRGBA3D(int, CArray3Drgba &, CKernel &, SMappingRanges, CInstructionIndex)", asFUNCTION(mapRGBA3D), asCALL_CDECL);
	
	#ifdef ANL_ANGELSCRIPT_BINDSTDSTRING
		as->RegisterGlobalFunction("void saveDoubleArray(std::string, CArray2Dd &)", asFUNCTION(saveDoubleArrayString), asCALL_CDECL);
		as->RegisterGlobalFunction("void saveRGBAeArray(std::string, CArray2Drgba &)", asFUNCTION(saveRGBAArrayString), asCALL_CDECL);
		as->RegisterGlobalFunction("void loadDoubleArray(std::string, CArray2Dd &)", asFUNCTION(loadDoubleArrayString), asCALL_CDECL);
		as->RegisterGlobalFunction("void loadRGBAArray(std::string, CArray2Drgba &)", asFUNCTION(loadRGBAArrayString), asCALL_CDECL);
		as->RegisterGlobalFunction("void saveHeightmap(std::string, CArray2Dd &)", asFUNCTION(saveHeightmapString), asCALL_CDECL);
	#else
		as->RegisterGlobalFunction("void saveDoubleArray(String, CArray2Dd &)", asFUNCTION(saveDoubleArrayString), asCALL_CDECL);
		as->RegisterGlobalFunction("void saveRGBAeArray(String, CArray2Drgba &)", asFUNCTION(saveRGBAArrayString), asCALL_CDECL);
		as->RegisterGlobalFunction("void loadDoubleArray(String, CArray2Dd &)", asFUNCTION(loadDoubleArrayString), asCALL_CDECL);
		as->RegisterGlobalFunction("void loadRGBAArray(String, CArray2Drgba &)", asFUNCTION(loadRGBAArrayString), asCALL_CDECL);
		as->RegisterGlobalFunction("void saveHeightmap(String, CArray2Dd &)", asFUNCTION(saveHeightmapString), asCALL_CDECL);
	#endif
	
	as->RegisterGlobalFunction("void calcNormalMap(CArray2Dd &, CArray2Drgba &, float, bool, bool)", asFUNCTION(CalcNormalMap), asCALL_CDECL);
	as->RegisterGlobalFunction("void calcBumpMap(CArray2Dd &, CArray2Dd &, float,float,float, float, bool)", asFUNCTION(CalcBumpMap), asCALL_CDECL);
	
}


};