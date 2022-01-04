#ifndef CATMULL_ROM_SPLINE_H
#define CATMULL_ROM_SPLINE_H


#include <Urho3D/Math/Vector3.h>

#include <algorithm>

using namespace Urho3D;

template <class T> class CRSpline
{
public:
    CRSpline() {}
    ~CRSpline() {}

    void Push(T p)
    {
        points_.push_back(p);
    }

    T Solve(float t)
    {
        // Which segment?
        int psize=points_.size();
        float segsize=1.0f/(float)(psize-1);
        int segment=(int)(t/segsize);
        float segt=t/segsize-(float)segment;

        Vector3 p0=points_[GetIndex(segment-1)];
        Vector3 p1=points_[GetIndex(segment)];
        Vector3 p2=points_[GetIndex(segment+1)];
        Vector3 p3=points_[GetIndex(segment+2)];

        return ((p1*2.0f) + (p2-p0)*segt + (p0*2.0f - p1*5.0f + p2*4.0f - p3) * segt*segt + (p1*3.0f - p2*3.0f + p3 - p0) * segt*segt*segt)*0.5f;
    }

	T Tangent(float t)
	{
		 // Which segment?
        int psize=points_.size();
        float segsize=1.0f/(float)(psize-1);
        int segment=(int)(t/segsize);
        float segt=t/segsize-(float)segment;

        Vector3 p0=points_[GetIndex(segment-1)];
        Vector3 p1=points_[GetIndex(segment)];
        Vector3 p2=points_[GetIndex(segment+1)];
        Vector3 p3=points_[GetIndex(segment+2)];

		return ((p2-p0) + (p0*2.0f - p1*5.0f + p2*4.0f - p3)*segt*2.0 + (p1*3.0f - p2*3.0f + p3 - p0)*segt*segt*3.0f)*0.5f;
	}

	void PointTangent(T &point, T &tangent, float t)
	{
		int psize=points_.size();
        float segsize=1.0f/(float)(psize-1);
        int segment=(int)(t/segsize);
        float segt=t/segsize-(float)segment;

        Vector3 p0=points_[GetIndex(segment-1)];
        Vector3 p1=points_[GetIndex(segment)];
        Vector3 p2=points_[GetIndex(segment+1)];
        Vector3 p3=points_[GetIndex(segment+2)];

		point=((p1*2.0f) + (p2-p0)*segt + (p0*2.0f - p1*5.0f + p2*4.0f - p3) * segt*segt + (p1*3.0f - p2*3.0f + p3 - p0) * segt*segt*segt)*0.5f;
		tangent=((p2-p0) + (p0*2.0f - p1*5.0f + p2*4.0f - p3)*segt*2.0 + (p1*3.0f - p2*3.0f + p3 - p0)*segt*segt*3.0f)*0.5f;
	}

    void Solve(ea::vector<T> &out, int divsperseg, float mergedistance=0.0f)
    {
        int divs=divsperseg*(points_.size()-1);
        float inc=1.0f / (float)(divs-1);
        float t=0.0f;

        out.clear();
        for(int c=0; c<divs; ++c)
        {
            T res=Solve(t);
            if (out.size()>0)
            {
                T d=res-out[out.size()-1];
                if(d.Length() > mergedistance) out.push_back(res);
            }
            else out.push_back(res);
            t+=inc;
        }
    }

	void Solve(ea::vector<T> &points, ea::vector<T> &tangents, int divsperseg, float mergedistance=0.0f)
	{
		int divs=divsperseg*(points_.size()-1);
        float inc=1.0f / (float)(divs-1);
        float t=0.0f;

        points.clear();
		tangents.clear();
        for(int c=0; c<divs; ++c)
        {
            T point,tang;
			PointTangent(point,tang,t);
            if (points.size()>0)
            {
                T d=point-points[points.size()-1];
                if(d.Length() > mergedistance)
				{
					points.push_back(point);
					tangents.push_back(tang);
				}
            }
            else
			{
				points.push_back(point);
				tangents.push(tang);
			}
            t+=inc;
        }
	}

	void Solve(ea::vector<T> &points, ea::vector<T> &tangents, ea::vector<float> &distances, int divsperseg, float mergedistance=0.0f)
	{
		int divs=divsperseg*(points_.size()-1);
        float inc=1.0f / (float)(divs-1);
        float t=0.0f;
		float dist=0.0f;

        points.clear();
		tangents.clear();
		distances.clear();

        for(int c=0; c<divs; ++c)
        {
            T point,tang;
			PointTangent(point,tang,t);
            if (points.size()>0)
            {
                T d=point-points[points.size()-1];
                if(d.Length() > mergedistance)
				{
					points.push_back(point);
					tangents.push_back(tang);
				}
            }
            else
			{
				points.push_back(point);
				tangents.push_back(tang);
			}
            t+=inc;
        }

		for(unsigned int c=0; c<points.size(); ++c)
		{
			if(c==0) distances.push_back(dist);
			else
			{
				T vec=points[c]-points[c-1];
				dist += vec.Length();
				distances.push_back(dist);
			}
		}
	}

    void Clear()
    {
        points_.clear();
    }

    int NumPoints()
    {
        return points_.size();
    }

private:
    ea::vector<T> points_;

    int GetIndex(int which)
    {
        return std::max(0, std::min((int)points_.size()-1, which));
    }
};

void BuildQuadStripA(ea::vector<Vector3> &points, ea::vector<Vector3> &out, float width, Vector3 up=Vector3(0,0,-1));
void BuildQuadStripVaryingA(ea::vector<Vector3> &points, ea::vector<Vector3> &out, float swidth, float ewidth, Vector3 up=Vector3(0,0,-1));
void BuildQuadStripB(ea::vector<Vector3> &points, ea::vector<Vector3> &tangents, ea::vector<float> &distances, ea::vector<Vector3> &outpoints, ea::vector<float> &outdistances, float width, Vector3 up);

#endif
