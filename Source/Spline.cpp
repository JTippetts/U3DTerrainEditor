#include "Spline.h"

void BuildQuadStripB(ea::vector<Vector3> &points, ea::vector<Vector3> &tangents, ea::vector<float> &distances, ea::vector<Vector3> &outpoints, ea::vector<float> &outdistances, float width, Vector3 up)
{
	outpoints.clear();
	outdistances.clear();

	if(points.size()<2) return;

	Vector3 p0=points[0];
    Vector3 tang=tangents[0];
	tang.Normalize();
	Vector3 right=tang.CrossProduct(up);
	right.Normalize();

	Vector3 pf=p0-tang*width*0.5f;
	outpoints.push_back(pf+right*width*0.5f);
	outpoints.push_back(pf-right*width*0.5f);
	outdistances.push_back(distances[0]);

	// Now, push first quad
	Vector3 p1=points[1];
	outpoints.push_back(p0+right*width*0.5f);
	outpoints.push_back(p0-right*width*0.5f);
	outdistances.push_back(distances[0]);
	outdistances.push_back(distances[0]);
	outpoints.push_back(p1+right*width*0.5f);
	outpoints.push_back(p1-right*width*0.5f);
	outdistances.push_back(distances[1]);
	outdistances.push_back(distances[1]);

	for(unsigned int c=1; c<points.size()-1; ++c)
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
        Vector3 avgr=(rp0 + outpoints[outpoints.size()-2]) * 0.5f;
        Vector3 avgl=(lp0 + outpoints[outpoints.size()-1]) * 0.5f;

        // Push the averages out to length
        Vector3 ra=avgr-p0;
        Vector3 la=avgl-p0;
        ra.Normalize();
        la.Normalize();

        outpoints[outpoints.size()-2]=p0+ra*width*0.5f;
        outpoints[outpoints.size()-1]=p0+la*width*0.5f;

        // Now push second set of points
        outpoints.push_back(p1+right*width*0.5f);
        outpoints.push_back(p1-right*width*0.5f);
		outdistances.push_back(distances[c]);
		outdistances.push_back(distances[c]);
    }

    // Push two verts beyond end point
    pf=p1+tang*width*0.5f;
    outpoints.push_back(pf+right*width*0.5f);
    outpoints.push_back(pf-right*width*0.5f);
	outdistances.push_back(distances[distances.size()-1]);
	outdistances.push_back(distances[distances.size()-1]);
}
void BuildQuadStripA(ea::vector<Vector3> &points, ea::vector<Vector3> &out, float width, Vector3 up)
{
    out.clear();

    if(points.size()<2) return;  // Need at least 2 points

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

    out.push_back(pf+rightnorm*width*0.5f);
    out.push_back(pf-rightnorm*width*0.5f);

    // Now, push first quad

    out.push_back(p0+rightnorm*width*0.5f);
    out.push_back(p0-rightnorm*width*0.5f);
    out.push_back(p1+rightnorm*width*0.5f);
    out.push_back(p1-rightnorm*width*0.5f);

    for(unsigned int c=1; c<points.size()-1; ++c)
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
        Vector3 avgr=(rp0 + out[out.size()-2]) * 0.5f;
        Vector3 avgl=(lp0 + out[out.size()-1]) * 0.5f;

        // Push the averages out to length
        Vector3 ra=avgr-p0;
        Vector3 la=avgl-p0;
        ra.Normalize();
        la.Normalize();

        out[out.size()-2]=p0+ra*width*0.5f;
        out[out.size()-1]=p0+la*width*0.5f;

        // Now push second set of points
        out.push_back(p1+rightnorm*width*0.5f);
        out.push_back(p1-rightnorm*width*0.5f);
    }

    // Push two verts beyond end point
    forwardnorm=forward;
    forwardnorm.Normalize();
    pf=p1+forwardnorm*width*0.5f;
    out.push_back(pf+rightnorm*width*0.5f);
    out.push_back(pf-rightnorm*width*0.5f);
}

void BuildQuadStripVaryingA(ea::vector<Vector3> &points, ea::vector<Vector3> &out, float swidth, float ewidth, Vector3 up)
{
    out.clear();

    if(points.size()<2) return;  // Need at least 2 points

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

    out.push_back(pf+rightnorm*swidth*0.5f);
    out.push_back(pf-rightnorm*swidth*0.5f);

    // Now, push first quad

    out.push_back(p0+rightnorm*swidth*0.5f);
    out.push_back(p0-rightnorm*swidth*0.5f);
    out.push_back(p1+rightnorm*swidth*0.5f);
    out.push_back(p1-rightnorm*swidth*0.5f);

    for(unsigned int c=1; c<points.size()-1; ++c)
    {
        // Generate first set of points in quad.
        float wt=(float)c / (float)points.size();
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
        Vector3 avgr=(rp0 + out[out.size()-2]) * 0.5f;
        Vector3 avgl=(lp0 + out[out.size()-1]) * 0.5f;

        // Push the averages out to length
        Vector3 ra=avgr-p0;
        Vector3 la=avgl-p0;
        ra.Normalize();
        la.Normalize();

        out[out.size()-2]=p0+ra*width*0.5f;
        out[out.size()-1]=p0+la*width*0.5f;

        // Now push second set of points
        out.push_back(p1+rightnorm*width*0.5f);
        out.push_back(p1-rightnorm*width*0.5f);
    }

    // Push two verts beyond end point
    forwardnorm=forward;
    forwardnorm.Normalize();
    pf=p1+forwardnorm*ewidth*0.5f;
    out.push_back(pf+rightnorm*ewidth*0.5f);
    out.push_back(pf-rightnorm*ewidth*0.5f);
}
