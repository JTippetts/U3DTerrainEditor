#include "Spline.h"

void BuildQuadStripB(Vector<Vector3> &points, Vector<Vector3> &tangents, Vector<float> &distances, Vector<Vector3> &outpoints, Vector<float> &outdistances, float width, Vector3 up)
{
	outpoints.Clear();
	outdistances.Clear();
	
	if(points.Size()<2) return;
	
	Vector3 p0=points[0];
    Vector3 tang=tangents[0];
	tang.Normalize();
	Vector3 right=tang.CrossProduct(up);
	right.Normalize();
	
	Vector3 pf=p0-tang*width*0.5f;
	outpoints.Push(pf+right*width*0.5f);
	outpoints.Push(pf-right*width*0.5f);
	outdistances.Push(distances[0]);
	
	// Now, push first quad
	Vector3 p1=points[1];
	outpoints.Push(p0+right*width*0.5f);
	outpoints.Push(p0-right*width*0.5f);
	outdistances.Push(distances[0]);
	outdistances.Push(distances[0]);
	outpoints.Push(p1+right*width*0.5f);
	outpoints.Push(p1-right*width*0.5f);
	outdistances.Push(distances[1]);
	outdistances.Push(distances[1]);
	
	for(unsigned int c=1; c<points.Size()-1; ++c)
    {
        // Generate first set of points in quad.
        p0=points[c];
        p1=points[c+1];
        tang=tangents[c];
		tang.Normalize();
        right=tang.CrossProduct(up);
        right.Normalize();

        Vector3 rp0=p0+right*width*0.5f;
        Vector3 lp0=p0-right*width*0.5f;

        // Average the previous points and the new points.
        Vector3 avgr=(rp0 + outpoints[outpoints.Size()-2]) * 0.5f;
        Vector3 avgl=(lp0 + outpoints[outpoints.Size()-1]) * 0.5f;

        // Push the averages out to length
        Vector3 ra=avgr-p0;
        Vector3 la=avgl-p0;
        ra.Normalize();
        la.Normalize();

        outpoints[outpoints.Size()-2]=p0+ra*width*0.5f;
        outpoints[outpoints.Size()-1]=p0+la*width*0.5f;

        // Now push second set of points
        outpoints.Push(p1+right*width*0.5f);
        outpoints.Push(p1-right*width*0.5f);
		outdistances.Push(distances[c]);
		outdistances.Push(distances[c]);
    }

    // Push two verts beyond end point
    pf=p1+tang*width*0.5f;
    outpoints.Push(pf+right*width*0.5f);
    outpoints.Push(pf-right*width*0.5f);
	outdistances.Push(distances[distances.Size()-1]);
	outdistances.Push(distances[distances.Size()-1]);
}
void BuildQuadStripA(Vector<Vector3> &points, Vector<Vector3> &out, float width, Vector3 up)
{
    out.Clear();

    if(points.Size()<2) return;  // Need at least 2 points

    // Push end quad and first quad
    Vector3 p0=points[0];
    Vector3 p1=points[1];
    Vector3 forward=p1-p0;
    Vector3 forwardnorm=forward;
    forwardnorm.Normalize();
    Vector3 right=forward.CrossProduct(up);
    Vector3 rightnorm=right;
    rightnorm.Normalize();

    // First, push 2 verts behind start point
    Vector3 pf=p0-forwardnorm*width*0.5f;

    out.Push(pf+rightnorm*width*0.5f);
    out.Push(pf-rightnorm*width*0.5f);

    // Now, push first quad

    out.Push(p0+rightnorm*width*0.5f);
    out.Push(p0-rightnorm*width*0.5f);
    out.Push(p1+rightnorm*width*0.5f);
    out.Push(p1-rightnorm*width*0.5f);

    for(unsigned int c=1; c<points.Size()-1; ++c)
    {
        // Generate first set of points in quad.
        p0=points[c];
        p1=points[c+1];
        forward=p1-p0;
        right=forward.CrossProduct(up);
        rightnorm=right;
        rightnorm.Normalize();

        Vector3 rp0=p0+rightnorm*width*0.5f;
        Vector3 lp0=p0-rightnorm*width*0.5f;

        // Average the previous points and the new points.
        Vector3 avgr=(rp0 + out[out.Size()-2]) * 0.5f;
        Vector3 avgl=(lp0 + out[out.Size()-1]) * 0.5f;

        // Push the averages out to length
        Vector3 ra=avgr-p0;
        Vector3 la=avgl-p0;
        ra.Normalize();
        la.Normalize();

        out[out.Size()-2]=p0+ra*width*0.5f;
        out[out.Size()-1]=p0+la*width*0.5f;

        // Now push second set of points
        out.Push(p1+rightnorm*width*0.5f);
        out.Push(p1-rightnorm*width*0.5f);
    }

    // Push two verts beyond end point
    forwardnorm=forward;
    forwardnorm.Normalize();
    pf=p1+forwardnorm*width*0.5f;
    out.Push(pf+rightnorm*width*0.5f);
    out.Push(pf-rightnorm*width*0.5f);
}

void BuildQuadStripVaryingA(Vector<Vector3> &points, Vector<Vector3> &out, float swidth, float ewidth, Vector3 up)
{
    out.Clear();

    if(points.Size()<2) return;  // Need at least 2 points

    // Push end quad and first quad
    Vector3 p0=points[0];
    Vector3 p1=points[1];
    Vector3 forward=p1-p0;
    Vector3 forwardnorm=forward;
    forwardnorm.Normalize();
    Vector3 right=forward.CrossProduct(up);
    Vector3 rightnorm=right;
    rightnorm.Normalize();

    // First, push 2 verts behind start point
    Vector3 pf=p0-forwardnorm*swidth*0.5f;

    out.Push(pf+rightnorm*swidth*0.5f);
    out.Push(pf-rightnorm*swidth*0.5f);

    // Now, push first quad

    out.Push(p0+rightnorm*swidth*0.5f);
    out.Push(p0-rightnorm*swidth*0.5f);
    out.Push(p1+rightnorm*swidth*0.5f);
    out.Push(p1-rightnorm*swidth*0.5f);

    for(unsigned int c=1; c<points.Size()-1; ++c)
    {
        // Generate first set of points in quad.
        float wt=(float)c / (float)points.Size();
        float width=swidth + wt*(ewidth-swidth);
        p0=points[c];
        p1=points[c+1];
        forward=p1-p0;
        right=forward.CrossProduct(up);
        rightnorm=right;
        rightnorm.Normalize();

        Vector3 rp0=p0+rightnorm*width*0.5f;
        Vector3 lp0=p0-rightnorm*width*0.5f;

        // Average the previous points and the new points.
        Vector3 avgr=(rp0 + out[out.Size()-2]) * 0.5f;
        Vector3 avgl=(lp0 + out[out.Size()-1]) * 0.5f;

        // Push the averages out to length
        Vector3 ra=avgr-p0;
        Vector3 la=avgl-p0;
        ra.Normalize();
        la.Normalize();

        out[out.Size()-2]=p0+ra*width*0.5f;
        out[out.Size()-1]=p0+la*width*0.5f;

        // Now push second set of points
        out.Push(p1+rightnorm*width*0.5f);
        out.Push(p1-rightnorm*width*0.5f);
    }

    // Push two verts beyond end point
    forwardnorm=forward;
    forwardnorm.Normalize();
    pf=p1+forwardnorm*ewidth*0.5f;
    out.Push(pf+rightnorm*ewidth*0.5f);
    out.Push(pf-rightnorm*ewidth*0.5f);
}
