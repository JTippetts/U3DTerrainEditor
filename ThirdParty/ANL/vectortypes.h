#ifndef COMMON_VECTOR_TYPES
#define COMMON_VECTOR_TYPES

#include "VM/types.h"
#include "templates/tvec2d.h"
#include "templates/tvec3d.h"
#include "templates/tvec4d.h"

namespace anl
{
	//typedef rhs4D<float> SRGBA;
	
	struct SRGBA
	{
		SRGBA() : r(0), g(0), b(0), a(0){}
		SRGBA(int al) : r(a), g(a), b(a), a(al) {}
		SRGBA(const  SRGBA &rhs) : r(rhs.r), g(rhs.g), b(rhs.b), a(rhs.a){}
		SRGBA(const float t1, const float t2, const float t3, const float t4) : r(t1), g(t2), b(t3), a(t4){}
		~SRGBA(){}

    bool operator ==(const SRGBA &rhs) const
    {
        if(r==rhs.r && g==rhs.g && b==rhs.b && a==rhs.a) return true;
        return false;
    };

    bool operator !=(const SRGBA &rhs) const
    {
        if(r==rhs.r && g==rhs.g && b==rhs.b && a==rhs.a) return false;
        return true;
    };

    SRGBA operator +(const SRGBA &rhs) const
    {
        return SRGBA(r+rhs.r, g+rhs.g, b+rhs.b, a+rhs.a);
    };

    SRGBA operator -(const SRGBA &rhs) const
    {
        return SRGBA(r-rhs.r, g-rhs.g, b-rhs.b, a-rhs.a);
    };

    SRGBA operator *(const SRGBA &rhs) const
    {
        return SRGBA(r*rhs.r, g*rhs.g, b*rhs.b, a*rhs.a);
    };

	SRGBA operator *(const double &rhs) const
	{
		return SRGBA(r*rhs, g*rhs, b*rhs, a*rhs);
	}

    SRGBA operator /(const SRGBA &rhs) const
    {
        return SRGBA(r/rhs.r, g/rhs.g, b/rhs.b, a/rhs.a);
    };

	SRGBA operator /(const double &rhs) const
	{
		return SRGBA(r/rhs, g/rhs, b/rhs, a/rhs);
	}

    SRGBA operator -() const
    {
        return SRGBA(-r, -g, -b, -a);
    };

    SRGBA &operator +=(const SRGBA &rhs)
    {
        r += rhs.r;
        g += rhs.g;
        b += rhs.b;
        a += rhs.a;
        return (*this);
    };

    SRGBA &operator -=(const SRGBA &rhs)
    {
        r -= rhs.r;
        g -= rhs.g;
        b -= rhs.b;
        a -= rhs.a;
        return (*this);
    };

    SRGBA &operator *=(const SRGBA &rhs)
    {
        r *= rhs.r;
        g *= rhs.g;
        b *= rhs.b;
        a *= rhs.a;
        return (*this);
    };

    SRGBA &operator /=(const SRGBA &rhs)
    {
        r /= rhs.r;
        g /= rhs.g;
        b /= rhs.b;
        a /= rhs.a;
        return (*this);
    };



    SRGBA operator +(const float &val) const
    {
        return SRGBA(r+val, g+val, b+val, a+val);
    };

    SRGBA operator -(const float &val) const
    {
        return SRGBA(r-val, g-val, b-val, a-val);
    };

    SRGBA operator *(const float &val) const
    {
        return SRGBA(r*val, g*val, b*val, a*val);
    };

    SRGBA operator /(const float &val) const
    {
        return SRGBA(r/val, g/val, b/val, a/val);
    };

    SRGBA &operator +=(const float &val)
    {
        r+=val;
        g+=val;
        b+=val;
        a+=val;
        return (*this);
    };

    SRGBA &operator -=(const float &val)
    {
        r-=val;
        g-=val;
        b-=val;
        a-=val;
        return (*this);
    };

    SRGBA &operator *=(const float &val)
    {
        r*=val;
        g*=val;
        b*=val;
        a*=val;
        return (*this);
    }

    SRGBA &operator /=(const float &val)
    {
        r/=val;
        g/=val;
        b/=val;
        a/=val;
        return (*this);
    };

		float r;
		float g;
		float b;
		float a;
	};
	
		typedef TVec2D<float> CVec2f;
        typedef TVec2D<double> CVec2d;
        typedef TVec3D<float> CVec3f;
        typedef TVec3D<double> CVec3d;
        typedef TVec4D<float> CVec4f;
        typedef TVec4D<double> CVec4d;

        typedef TVec2D<int> CVec2i;
        typedef TVec3D<int> CVec3i;
        typedef TVec4D<int> CVec4i;

        typedef TVec2D<unsigned int> CVec2ui;
        typedef TVec3D<unsigned int> CVec3ui;
        typedef TVec4D<unsigned int> CVec4ui;
};



#endif
