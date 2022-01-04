#include "rasterization.h"
#include "Spline.h"

void TessellateLineList(RasterVertexList *in, RasterVertexList *out, int steps)
{
    CRSpline<Vector3> ll;
    for(unsigned int c=0; c<in->size(); ++c)
    {
        ll.Push(Vector3((*in)[c].x_, (*in)[c].y_, (*in)[c].val_));
    }

    ea::vector<Vector3> lo;
    ll.Solve(lo, steps*(ll.NumPoints()-1), 0.1);

    for(unsigned int c=0; c<lo.size(); ++c)
    {
        out->push_back(RasterVertex(lo[c].x_, lo[c].y_, lo[c].z_));
    }
}

void BuildQuadStrip(RasterVertexList *in, RasterVertexList *out, float width)
{
    ea::vector<Vector3> points;
    for(unsigned int c=0; c<in->size(); ++c) points.push_back(Vector3((*in)[c].x_, (*in)[c].y_, (*in)[c].val_));

    ea::vector<Vector3> quads;
    BuildQuadStripA(points, quads, width);

    out->resize(0);

    for(unsigned int c=0; c<quads.size(); ++c) out->push_back(RasterVertex(quads[c].x_, quads[c].y_, quads[c].z_));
}

void BuildQuadStripVarying(RasterVertexList *in, RasterVertexList *out, float startwidth, float endwidth)
{
    ea::vector<Vector3> points;
    for(unsigned int c=0; c<in->size(); ++c) points.push_back(Vector3((*in)[c].x_, (*in)[c].y_, (*in)[c].val_));

    ea::vector<Vector3> quads;
    BuildQuadStripVaryingA(points, quads, startwidth, endwidth);

    out->resize(0);

    for(unsigned int c=0; c<quads.size(); ++c) out->push_back(RasterVertex(quads[c].x_, quads[c].y_, quads[c].z_));
}

float Orient2D(RasterVertex &a, RasterVertex &b, RasterVertex &c)
{
    return (float)(b.x_-a.x_)*(float)(c.y_-a.y_) - (float)(b.y_-a.y_)*(float)(c.x_-a.x_);
}


void RasterizeTriangle(CArray2Dd *buffer, RasterVertex v0, RasterVertex v1, RasterVertex v2)
{
    int minx=(int)std::min(v0.x_, std::min(v1.x_, v2.x_));
    int maxx= (int)std::max(v0.x_, std::max(v1.x_, v2.x_));
    int miny= (int)std::min(v0.y_, std::min(v1.y_, v2.y_));
    int maxy= (int)std::max(v0.y_, std::max(v1.y_, v2.y_));

    minx= (int)std::max(0,minx);
    miny= (int)std::max(0,miny);
    maxx= (int)std::min(maxx, buffer->width()-1)+1;
    maxy= (int)std::min(maxy, buffer->height()-1)+1;

    RasterVertex p(0,0,0);
    for(int y=miny; y<=maxy; ++y)
    {
        for(int x=minx; x<=maxx; ++x)
        {
            p.x_=(float)x;
            p.y_=(float)y;
            float w0=Orient2D(v1,v2,p);
            float w1=Orient2D(v2,v0,p);
            float w2=Orient2D(v0,v1,p);
            float sum=w0+w1+w2;
            w0/=sum;
            w1/=sum;
            w2/=sum;

            if(w0>=0 && w1>=0 && w2>=0)
            {
                float newval=(w0*v0.val_ + w1*v1.val_ +w2*v2.val_);
                buffer->set(x,(buffer->height()-1)-y,newval);
            }
        }
    }
}

void RasterizeQuadStrip(CArray2Dd *buffer, RasterVertexList *strip)
{
    for(unsigned int c=0; c<=strip->size()-4; c+=2)
    {
        RasterizeTriangle(buffer, (*strip)[c], (*strip)[c+1], (*strip)[c+2]);
        RasterizeTriangle(buffer, (*strip)[c+1], (*strip)[c+2], (*strip)[c+3]);
    }
}

void ApplyBedFunction(CArray2Dd *buffer, float hardness, bool quintic)
{
    for(int x=0; x<buffer->width(); ++x)
    {
        for(int y=0; y<buffer->height(); ++y)
        {
            float v=(float)buffer->get(x,y);
            float h=std::max(0.0f, std::min(0.9999f,hardness));
            v=std::abs(v*2.0f-1.0f);
            v=std::max(0.0f, std::min(1.0f, (v-1.0f)/(h-1.0f)));
            if(quintic) v=v*v*v*(v*(v*6.0f-15.0f)+10.0f);
            buffer->set(x,y,v);
        }
    }
}

