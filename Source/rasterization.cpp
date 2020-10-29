#include "rasterization.h"
#include "Spline.h"

void TessellateLineList(RasterVertexList *in, RasterVertexList *out, int steps)
{
    CRSpline<Vector3> ll;
    for(unsigned int c=0; c<in->size(); ++c)
    {
        ll.Push(Vector3((*in)[c].x_, (*in)[c].y_, (*in)[c].val_));
    }

    Vector<Vector3> lo;
    ll.Solve(lo, steps*(ll.NumPoints()-1), 0.1);

    for(unsigned int c=0; c<lo.Size(); ++c)
    {
        out->push_back(RasterVertex(lo[c].x_, lo[c].y_, lo[c].z_));
    }
}

void BuildQuadStrip(RasterVertexList *in, RasterVertexList *out, float width)
{
    Vector<Vector3> points;
    for(unsigned int c=0; c<in->size(); ++c) points.Push(Vector3((*in)[c].x_, (*in)[c].y_, (*in)[c].val_));

    Vector<Vector3> quads;
    BuildQuadStripA(points, quads, width);

    out->resize(0);

    for(unsigned int c=0; c<quads.Size(); ++c) out->push_back(RasterVertex(quads[c].x_, quads[c].y_, quads[c].z_));
}

void BuildQuadStripVarying(RasterVertexList *in, RasterVertexList *out, float startwidth, float endwidth)
{
    Vector<Vector3> points;
    for(unsigned int c=0; c<in->size(); ++c) points.Push(Vector3((*in)[c].x_, (*in)[c].y_, (*in)[c].val_));

    Vector<Vector3> quads;
    BuildQuadStripVaryingA(points, quads, startwidth, endwidth);

    out->resize(0);

    for(unsigned int c=0; c<quads.Size(); ++c) out->push_back(RasterVertex(quads[c].x_, quads[c].y_, quads[c].z_));
}