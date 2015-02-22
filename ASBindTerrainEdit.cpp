#include <AngelScript/angelscript.h>

#include "TerrainEdit.h"

void ConstructRasterVertex(RasterVertex *rv)
{
	new(rv) RasterVertex();
}

void ConstructRasterVertexInit(float x, float y, float val, RasterVertex *rv)
{
	new(rv) RasterVertex(x,y,val);
}

void ConstructRasterVertexCopy(const RasterVertex &rhs, RasterVertex *rv)
{
	new(rv) RasterVertex(rhs);
}

void ConstructRasterBuffer(RasterBuffer *rb)
{
	new(rb) RasterBuffer();
}

void ConstructRasterBufferInit(int w, int h, RasterBuffer *rb)
{
	new(rb) RasterBuffer(w,h);
}

float RasterBufferGet(int x, int y, RasterBuffer *rb)
{
	return rb->get(x,y);
}

void RegisterTerrainEdit(asIScriptEngine* engine)
{
	engine->RegisterObjectType("RasterVertex", sizeof(RasterVertex), asOBJ_VALUE | asOBJ_POD | asOBJ_APP_CLASS_CDAK);
	engine->RegisterObjectBehaviour("RasterVertex", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(ConstructRasterVertex), asCALL_CDECL_OBJLAST);
	engine->RegisterObjectBehaviour("RasterVertex", asBEHAVE_CONSTRUCT, "void f(float, float, float)", asFUNCTION(ConstructRasterVertexInit), asCALL_CDECL_OBJLAST);
	engine->RegisterObjectBehaviour("RasterVertex", asBEHAVE_CONSTRUCT, "void f(const RasterVertex&in)", asFUNCTION(ConstructRasterVertexCopy), asCALL_CDECL_OBJLAST);
	engine->RegisterObjectProperty("RasterVertex", "float x", offsetof(RasterVertex, x_));
	engine->RegisterObjectProperty("RasterVertex", "float y", offsetof(RasterVertex, y_));
	engine->RegisterObjectProperty("RasterVertex", "float val", offsetof(RasterVertex, val_));
	
	engine->RegisterObjectType("RasterBuffer", sizeof(RasterBuffer), asOBJ_VALUE | asOBJ_APP_CLASS_CD);
	engine->RegisterObjectBehaviour("RasterBuffer", asBEHAVE_CONSTRUCT, "void f()", asFUNCTION(ConstructRasterBuffer), asCALL_CDECL_OBJLAST);
	engine->RegisterObjectBehaviour("RasterBuffer", asBEHAVE_CONSTRUCT, "void f(int, int)", asFUNCTION(ConstructRasterBufferInit), asCALL_CDECL_OBJLAST);
	engine->RegisterObjectMethod("RasterBuffer", "void resize(int, int)", asMETHOD(RasterBuffer, resize), asCALL_THISCALL);
	engine->RegisterObjectMethod("RasterBuffer", "void destroy()", asMETHOD(RasterBuffer, destroy), asCALL_THISCALL);
	engine->RegisterObjectMethod("RasterBuffer", "int width()", asMETHOD(RasterBuffer, width), asCALL_THISCALL);
	engine->RegisterObjectMethod("RasterBuffer", "int height()", asMETHOD(RasterBuffer, height), asCALL_THISCALL);
	engine->RegisterObjectMethod("RasterBuffer", "float get(int, int)", asFUNCTION(RasterBufferGet), asCALL_CDECL_OBJLAST);
	engine->RegisterObjectMethod("RasterBuffer", "void set(int, int, float)", asMETHOD(RasterBuffer, set), asCALL_THISCALL);
	engine->RegisterObjectMethod("RasterBuffer", "float &getRef(int, int)", asMETHOD(RasterBuffer, getRef), asCALL_THISCALL);
	engine->RegisterObjectMethod("RasterBuffer", "float getBilinear(float, float)", asMETHOD(RasterBuffer, getBilinear), asCALL_THISCALL);
	engine->RegisterObjectMethod("RasterBuffer", "float getIndexed(int)", asMETHOD(RasterBuffer, getIndexed), asCALL_THISCALL);
	engine->RegisterObjectMethod("RasterBuffer", "void setIndexed(int, float)", asMETHOD(RasterBuffer, setIndexed), asCALL_THISCALL);
	engine->RegisterObjectMethod("RasterBuffer", "void fill(float)", asMETHOD(RasterBuffer, fill), asCALL_THISCALL);
	engine->RegisterObjectMethod("RasterBuffer", "void scale(float)", asMETHOD(RasterBuffer, scale), asCALL_THISCALL);
	engine->RegisterObjectMethod("RasterBuffer", "float getMax()", asMETHOD(RasterBuffer, getMax), asCALL_THISCALL);
	engine->RegisterObjectMethod("RasterBuffer", "float getMin()", asMETHOD(RasterBuffer, getMin), asCALL_THISCALL);
	engine->RegisterObjectMethod("RasterBuffer", "void scaleToRange(float, float)", asMETHOD(RasterBuffer, scaleToRange), asCALL_THISCALL);
	engine->RegisterObjectMethod("RasterBuffer", "void blur(float, bool)", asMETHOD(RasterBuffer, blur), asCALL_THISCALL);
}