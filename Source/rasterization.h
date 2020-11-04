#pragma once

// Rasterization

#include <vector>
#include "../ThirdParty/accidental-noise-library/anl.h"
using namespace anl;

struct RasterVertex
{
    float x_, y_;
    float val_;

    RasterVertex() : x_(0), y_(0), val_(0) {}
    RasterVertex(float x, float y, float val): x_(x), y_(y), val_(val) {}
    RasterVertex(const RasterVertex &rhs) : x_(rhs.x_), y_(rhs.y_), val_(rhs.val_) {}
    ~RasterVertex() {}

    void operator=(const RasterVertex &rhs)
    {
        x_=rhs.x_;
        y_=rhs.y_;
        val_=rhs.val_;
    }

    RasterVertex operator-(const RasterVertex &rhs)
    {
        RasterVertex v;
        v.x_=x_-rhs.x_;
        v.y_=y_-rhs.y_;
        v.val_=val_-rhs.val_;
        return v;
    }

    RasterVertex operator+(const RasterVertex &rhs)
    {
        RasterVertex v;
        v.x_=x_+rhs.x_;
        v.y_=y_+rhs.y_;
        v.val_=val_+rhs.val_;
        return v;
    }

    RasterVertex operator*(const RasterVertex &rhs)
    {
        RasterVertex v;
        v.x_=x_*rhs.x_;
        v.y_=y_*rhs.y_;
        v.val_=val_*rhs.val_;
        return v;
    }

    RasterVertex operator*(float t)
    {
        RasterVertex v;
        v.x_=x_*t;
        v.y_=y_*t;
        v.val_=val_*t;
        return v;
    }

};

typedef std::vector<RasterVertex> RasterVertexList;


void TessellateLineList(RasterVertexList *in, RasterVertexList *out, int steps);
void BuildQuadStrip(RasterVertexList *in, RasterVertexList *out, float width);
void BuildQuadStripVarying(RasterVertexList *in, RasterVertexList *out, float startwidth, float endwidth);
void RasterizeQuadStrip(CArray2Dd *buffer, RasterVertexList *strip);
void RasterizeTriangle(CArray2Dd *buffer, RasterVertex v0, RasterVertex v1, RasterVertex v2);
void ApplyBedFunction(CArray2Dd *buffer, float hardness, bool quintic);
