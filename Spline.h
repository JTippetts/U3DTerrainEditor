#ifndef CATMULL_ROM_SPLINE_H
#define CATMULL_ROM_SPLINE_H

#include <Urho3D/Container/Vector.h>

using namespace Urho3D;

template <class T> class CRSpline
{
public:
	CRSpline(){}
	~CRSpline(){}
	
	void Push(T p)
	{
		points_.Push(p);
	}
	
	T Solve(float t)
	{
		// Which segment?
		int psize=points_.Size();
		float segsize=1.0f/(float)(psize-1);
		int segment=(int)(t/segsize);
		float segt=t/segsize-(float)segment;
	
		Vector3 p0=points_[GetIndex(segment-1)];
		Vector3 p1=points_[GetIndex(segment)];
		Vector3 p2=points_[GetIndex(segment+1)];
		Vector3 p3=points_[GetIndex(segment+2)];
	
		return ((p1*2.0f) + (p2-p0)*segt + (p0*2.0f - p1*5.0f + p2*4.0f - p3) * segt*segt + (p1*3.0f - p2*3.0f + p3 - p0) * segt*segt*segt)*0.5f;
	}
	
	void Solve(Vector<T> &out, int divsperseg, float mergedistance=0.0f)
	{
		int divs=divsperseg*(points_.Size()-1);
		float inc=1.0f / (float)(divs-1);
		float t=0.0f;
	
		out.Clear();
		for(int c=0; c<divs; ++c)
		{
			T res=Solve(t);
			if (out.Size()>0)
			{
				T d=res-out[out.Size()-1];
				if(d.Length() > mergedistance) out.Push(res);
			}
			else out.Push(res);
			t+=inc;
		}
	}
	
	void Clear()
	{
		points_.Clear();
	}
	
	int NumPoints()
	{
		return points_.Size();
	}
	
private:
	Vector<T> points_;
	
	int GetIndex(int which)
	{
		return std::max(0, std::min((int)points_.Size()-1, which));
	}
};

void BuildQuadStripA(Vector<Vector3> &points, Vector<Vector3> &out, float width, Vector3 up=Vector3(0,0,-1))
{
	out.Clear();
	
	if(points.Size()<2) return;  // Need at least 2 points
	
	// Push first quad
	Vector3 p0=points[0];
	Vector3 p1=points[1];
	Vector3 forward=p1-p0;
	Vector3 right=forward.CrossProduct(up);
	Vector3 rightnorm=right; rightnorm.Normalize();
	out.Push(p0+rightnorm*width*0.5f);
	out.Push(p0-rightnorm*width*0.5f);
	out.Push(p1+rightnorm*width*0.5f);
	out.Push(p1-rightnorm*width*0.5f);
	
	for(int c=1; c<points.Size()-1; ++c)
	{
		// Generate first set of points in quad.
		p0=points[c];
		p1=points[c+1];
		forward=p1-p0;
		right=forward.CrossProduct(up);
		rightnorm=right; rightnorm.Normalize();
		
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
}


#endif
