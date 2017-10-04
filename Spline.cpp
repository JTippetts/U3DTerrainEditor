#include "Spline.h"

void BuildQuadStrip(Vector<Vector3> &points, Vector<Vector3> &out, float width, Vector3 up=Vector3(0,0,1))
{
	out.Clear();
	
	if(points.Size()<2) return;  // Need at least 2 points
	
	// Push first quad
	Vector3 p0=points[0];
	Vector3 p1=points[1];
	Vector3 forward=p1-p0;
	Vector3 right=forward.CrossProduct(up);
	Vector3 rightnorm=right.Normalize();
	out.Push(p0+rightnorm*width*0.5f);
	out.Push(p0-rightnorm*width*0.5f);
	out.Push(p1+rightnorm*width*0.5f);
	out.Push(p1-rightnorm*width*0.5f);
	
	for(int c=1; c<points.size()-1; ++c)
	{
		// Generate first set of points in quad.
		p0=points[c];
		p1=points[c+1];
		forward=p1-p0;
		right=forward.CrossProduct(up);
		rightnorm=right.Normalize();
		
		Vector3 rp0=p0+rightnorm*width*0.5f;
		Vector3 lp0=p0-rightnorm*width*0.5f;
		
		// Average the previous points and the new points.
		Vector3 avgr=(rp0 + out[out.Size()-2]) * 0.5f;
		Vector3 avgl=(lp0 + out[out.Size()-1]) * 0.5f;
		
		// Push the averages out to length
		Vector3 ra=avgr-p0;
		Vector3 la=avgl=p0;
		ra.Normalize()
		la.Normalize()
		
		out[out.Size()-2]=ra*width*0.5f;
		out[out.Size()-1]=la*width*0.5f;
		
		// Now push second set of points
		out.Push(p1+rightnorm*width*0.5f);
		out.Push(p1-rightnorm*width*0.5f);
	}
}
