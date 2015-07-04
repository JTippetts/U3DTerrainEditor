#include "imaging.h"

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <thread>
#include <chrono>

#include "stb_image.h"
#include "stb_image_write.h"

namespace anl
{
    void saveDoubleArray(const char *filename, TArray2D<double> *array)
	{
		if(!array) return;
		int width=array->width();
		int height=array->height();
		std::string fname(filename);

		unsigned char *data=new unsigned char[width*height*4];
		for(int x=0; x<width; ++x)
		{
			for(int y=0; y<height; ++y)
			{
				unsigned char *c=&data[y*width*4+x*4];
				double v=array->get(x,y);
				c[0]=c[1]=c[2]=(unsigned char)(v*255.0);
				c[3]=255;
			}
		}

		std::string ext=fname.substr(fname.size()-3, std::string::npos);
		struct convert {
			void operator()(char& c) { c = toupper((unsigned char)c); }
		};

		std::for_each(ext.begin(), ext.end(), convert());

		if(ext=="TGA")
		{
			stbi_write_tga(filename, width, height, 4, data);
		}
		else
		{
			stbi_write_png(filename, width, height, 4, data, width*4);
		}


		delete[] data;
	}


	void saveRGBAArray(const char *filename, TArray2D<anl::SRGBA> *array)
	{
		if(!array) return;
		int width=array->width();
		int height=array->height();
		std::string fname(filename);

		unsigned char *data=new unsigned char[width*height*4];
		for(int x=0; x<width; ++x)
		{
			for(int y=0; y<height; ++y)
			{
				unsigned char *c=&data[y*width*4+x*4];
				SRGBA color=array->get(x,y);
				c[0]=(unsigned char)(color.r*255.0);
				c[1]=(unsigned char)(color.g*255.0);
				c[2]=(unsigned char)(color.b*255.0);
				c[3]=(unsigned char)(color.a*255.0);
			}
		}

		std::string ext=fname.substr(fname.size()-3, std::string::npos);
		struct convert {
			void operator()(char& c) { c = toupper((unsigned char)c); }
		};

		std::for_each(ext.begin(), ext.end(), convert());

		if(ext=="TGA")
		{
			stbi_write_tga(filename, width, height, 4, data);
		}
		else
		{
			stbi_write_png(filename, width, height, 4, data, width*4);
		}
		delete[] data;
	}
	
	void loadDoubleArray(const char *filename, TArray2D<double> *array)
        {
                if(!array) return;
                int w,h,n;
                unsigned char *data=stbi_load(filename, &w, &h, &n, 4);
                if(!data) return;
                
                array->resize(w,h);
                for(int x=0; x<w; ++x)
                {
                        for(int y=0; y<h; ++y)
                        {
                                unsigned char *a=&data[y*w*4+x*4];
                                array->set(x,y,(double)(a[0])/255.0);
                        }
                }
                
                stbi_image_free(data);
        }
        
        void loadRGBAArray(const char *filename, TArray2D<anl::SRGBA> *array)
        {
		std::cout << "1" << std::endl;
		std::cout << "1.1" << std::endl;
                if(!array)
				{
					std::cout << "Array is 0" << std::endl; return;
				}
				std::cout << "1.5" << std::endl;
                int w,h,n;
                unsigned char *data=stbi_load(filename, &w, &h, &n, 4);
                if(!data)
				{
					std::cout << "data is 0" << std::endl; return;
				}
				std::cout << "2" << std::endl;
                
                array->resize(w,h);
                for(int x=0; x<w; ++x)
                {
                        for(int y=0; y<h; ++y)
                        {
                                unsigned char *a=&data[y*w*4+x*4];
                                SRGBA color((float)a[0]/255.0, (float)a[1]/255.0, (float)a[2]/255.0, (float)a[3]/255.0);
                                array->set(x,y,color);
                        }
                }
                std::cout << "3" << std::endl;
                stbi_image_free(data);
        }
	
	struct SChunk
	{
		int seamlessmode;
		double *a;
		int awidth, aheight;
		int chunkheight, chunkyoffset;
		CKernel *kernel;
		SMappingRanges ranges;
		double z;
	};
	
	void map2DChunk(SChunk chunk)
	{
		static double pi2=3.141592*2.0;
		CNoiseExecutor m(chunk.kernel);
		SMappingRanges ranges=chunk.ranges;
		double z=chunk.z;
		
		for(int x=0; x<chunk.awidth; ++x)
		{
			for(int y=0; y<chunk.chunkheight; ++y)
			{
				int realy=y+chunk.chunkyoffset;
				int index=y*chunk.awidth+x;
				double p=(double) x/ (double)(chunk.awidth-1);
				double q=(double) realy/(double)(chunk.aheight-1);
				double r;
                double nx,ny,nz,nw,nu,nv,val=0.0;
                double dx, dy, dz;
                switch(chunk.seamlessmode)
                {
                    case SEAMLESS_NONE:
                    {
                        nx=ranges.mapx0 + p*(ranges.mapx1-ranges.mapx0);
                        ny=ranges.mapy0 + q*(ranges.mapy1-ranges.mapy0);
                        nz=z;
						CCoordinate coord(nx,ny,nz);
                        val=m.evaluate(coord).outfloat_;
                    } break;
                    case SEAMLESS_X:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.mapy0 + q*dy;
                        nw=z;
                        CCoordinate coord(nx,ny,nz,nw);
                        val=m.evaluate(coord).outfloat_;
                    } break;
                    case SEAMLESS_Y:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.mapx0 + p*dx;
                        ny=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nz=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        nw=z;
                        CCoordinate coord(nx,ny,nz,nw);
                        val=m.evaluate(coord).outfloat_;
                    } break;
                    case SEAMLESS_Z:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        nx=ranges.mapx0 + p*dx;
                        ny=ranges.mapy0 + p*dx;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        nz=ranges.loopz0 + cos(zval*pi2) * dz/pi2;
                        nw=ranges.loopz0 + sin(zval*pi2) * dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw);
                        val=m.evaluate(coord).outfloat_;
                    } break;
                    case SEAMLESS_XY:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nw=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        nu=z;
						CCoordinate coord(nx,ny,nz,nw,nu,0);
                        val=m.evaluate(coord).outfloat_;
           
                    } break;
                    case SEAMLESS_XZ:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapx1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) *dx/pi2;
                        nz=ranges.mapy0 + q*dy;
                        nw=ranges.loopz0 + cos(zval*pi2)*dz/pi2;
                        nu=ranges.loopz0 + sin(zval*pi2)*dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw,nu,0);
                        val=m.evaluate(coord).outfloat_;
                    } break;
                    case SEAMLESS_YZ:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.mapx0+p*dx;
                        ny=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nz=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        nw=ranges.loopz0 + cos(zval*pi2) * dz/pi2;
                        nu=ranges.loopz0 + sin(zval*pi2) * dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw,nu,0);
                        val=m.evaluate(coord).outfloat_;
                    } break;
                    case SEAMLESS_XYZ:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                        nz=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                        nw=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                        nu=ranges.loopz0 + cos(zval*pi2)*dz/pi2;
                        nv=ranges.loopz0 + sin(zval*pi2)*dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw,nu,nv);
                        val=m.evaluate(coord).outfloat_;
                    } break;

                    default: break;
                }
                //a.set(x,y,val);
				chunk.a[index]=val;
			}
		}
	}
	
	void map2DNoThread(int seamlessmode, CArray2Dd &a, CKernel &k, SMappingRanges ranges, double z)
	{
		SChunk chunk;
		chunk.seamlessmode=seamlessmode;
		chunk.a=a.getData();
		chunk.awidth=a.width();
		chunk.aheight=a.height();
		chunk.chunkheight=a.height();
		chunk.chunkyoffset=0;
		chunk.kernel=&k;
		chunk.ranges=ranges;
		chunk.z=z;
		
		map2DChunk(chunk);
	}
	
	
	void map2DThread(int seamlessmode, CArray2Dd &a, CKernel &k, SMappingRanges ranges, double z)
	{
		unsigned threadcount=std::thread::hardware_concurrency();
		std::cout << "Thread count: "<<threadcount<<std::endl;
		
		int chunksize=std::floor(a.height() / threadcount);
		
		std::vector<std::thread> threads;
		
		
		for(unsigned int thread=0; thread<threadcount; ++thread)
		{
			SChunk chunk;
			chunk.seamlessmode=seamlessmode;
			double *arr=a.getData();
			int offsety=thread*chunksize;
			chunk.a=&arr[offsety*a.width()];
			chunk.awidth=a.width();
			chunk.aheight=a.height();
			chunk.chunkheight=thread==threadcount-1 ? a.height()-thread*chunksize : chunksize;
			std::cout << "Chunk size:" << chunk.chunkheight << std::endl;
			chunk.chunkyoffset=offsety;
			chunk.kernel=&k;
			chunk.ranges=ranges;
			chunk.z=z;
			std::cout << "Construct thread " << thread <<std::endl;
			threads.push_back(std::thread(map2DChunk, chunk));
		}
		
		std::cout << "Join threads" << std::endl;
		for(unsigned int c=0; c<threads.size(); ++c)
		{
			std::cout << "Thread: " << c << std::endl;
			threads[c].join();
		}
	}
	
	double highresTime()
	{
		using namespace std::chrono;
		high_resolution_clock::time_point t=high_resolution_clock::now();
		high_resolution_clock::duration d=t.time_since_epoch();
		return (double)d.count() * (double)high_resolution_clock::period::num / (double)high_resolution_clock::period::den;
	}
	
	void map2D(int seamlessmode, CArray2Dd &a, CKernel &k, SMappingRanges ranges, CInstructionIndex index, double z)
   {
        int w=a.width();
        int h=a.height();
        static double pi2=3.141592*2.0;
		CNoiseExecutor m(&k);

        int x,y;
        for(x=0; x<w; ++x)
        {
            for(y=0; y<h; ++y)
            {
                double p=(double)x / (double)(w-1);
                double q=(double)y / (double)(h-1);
                double r;
                double nx,ny,nz,nw,nu,nv,val=0.0;
                double dx, dy, dz;
                switch(seamlessmode)
                {
                    case SEAMLESS_NONE:
                    {
                        nx=ranges.mapx0 + p*(ranges.mapx1-ranges.mapx0);
                        ny=ranges.mapy0 + q*(ranges.mapy1-ranges.mapy0);
                        nz=z;
						CCoordinate coord(nx,ny,nz);
                        val=m.evaluateAt(coord,index).outfloat_;
                    } break;
                    case SEAMLESS_X:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.mapy0 + q*dy;
                        nw=z;
                        CCoordinate coord(nx,ny,nz,nw);
                        val=m.evaluateAt(coord,index).outfloat_;
                    } break;
                    case SEAMLESS_Y:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.mapx0 + p*dx;
                        ny=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nz=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        nw=z;
                        CCoordinate coord(nx,ny,nz,nw);
                        val=m.evaluateAt(coord,index).outfloat_;
                    } break;
                    case SEAMLESS_Z:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        nx=ranges.mapx0 + p*dx;
                        ny=ranges.mapy0 + p*dx;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        nz=ranges.loopz0 + cos(zval*pi2) * dz/pi2;
                        nw=ranges.loopz0 + sin(zval*pi2) * dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw);
                        val=m.evaluateAt(coord,index).outfloat_;
                    } break;
                    case SEAMLESS_XY:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nw=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        nu=z;
						CCoordinate coord(nx,ny,nz,nw,nu,0);
                        val=m.evaluateAt(coord,index).outfloat_;
           
                    } break;
                    case SEAMLESS_XZ:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapx1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) *dx/pi2;
                        nz=ranges.mapy0 + q*dy;
                        nw=ranges.loopz0 + cos(zval*pi2)*dz/pi2;
                        nu=ranges.loopz0 + sin(zval*pi2)*dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw,nu,0);
                        val=m.evaluateAt(coord,index).outfloat_;
                    } break;
                    case SEAMLESS_YZ:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.mapx0+p*dx;
                        ny=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nz=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        nw=ranges.loopz0 + cos(zval*pi2) * dz/pi2;
                        nu=ranges.loopz0 + sin(zval*pi2) * dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw,nu,0);
                        val=m.evaluateAt(coord,index).outfloat_;
                    } break;
                    case SEAMLESS_XYZ:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                        nz=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                        nw=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                        nu=ranges.loopz0 + cos(zval*pi2)*dz/pi2;
                        nv=ranges.loopz0 + sin(zval*pi2)*dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw,nu,nv);
                        val=m.evaluateAt(coord,index).outfloat_;
                    } break;

                    default: break;
                }
                a.set(x,y,val);
            }
        }
   }

   void map2DNoZ(int seamlessmode, CArray2Dd &a, CKernel &k, SMappingRanges ranges, CInstructionIndex index)
   {
        int w=a.width();
        int h=a.height();
        static double pi2=3.141592*2.0;
		CNoiseExecutor m(&k);

        int x,y;
        for(x=0; x<w; ++x)
        {
            for(y=0; y<h; ++y)
            {
                double p=(double)x / (double)w;
                double q=(double)y / (double)h;
                double nx,ny,nz,nw,val=0.0;
                double dx, dy;
                switch(seamlessmode)
                {
                    case SEAMLESS_NONE:
                    {
                        nx=ranges.mapx0 + p*(ranges.mapx1-ranges.mapx0);
                        ny=ranges.mapy0 + q*(ranges.mapy1-ranges.mapy0);
						CCoordinate coord(nx,ny);
                        val=m.evaluateAt(coord,index).outfloat_;
                    } break;
                    case SEAMLESS_X:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.mapy0 + q*dy;
                        CCoordinate coord(nx,ny,nz);
                        val=m.evaluateAt(coord,index).outfloat_;
                    } break;
                    case SEAMLESS_Y:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.mapx0 + p*dx;
                        ny=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nz=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        CCoordinate coord(nx,ny,nz);
                        val=m.evaluateAt(coord,index).outfloat_;
                    } break;

                    case SEAMLESS_XY:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nw=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        CCoordinate coord(nx,ny,nz,nw);
                        val=m.evaluateAt(coord,index).outfloat_;
                    } break;
                    default: break;
                }
                a.set(x,y,val);
            }
        }
   }

    void map3D(int seamlessmode, CArray3Dd &a, CKernel &k, SMappingRanges ranges, CInstructionIndex index)
    {
        int w=a.width();
        int h=a.height();
        int d=a.depth();
		CNoiseExecutor m(&k);

        int x,y,z;
        static double pi2=3.14159265 * 2.0;
        for(x=0; x<w; ++x)
        {
            for(y=0; y<h; ++y)
            {
                for(z=0; z<d; ++z)
                {
                    double p=(double)x/(double)w;
                    double q=(double)y/(double)h;
                    double r=(double)z/(double)d;
                    double nx,ny,nz,nw,nu,nv;
                    double dx,dy,dz;
                    double val=0.0;

                    switch(seamlessmode)
                    {
                        case SEAMLESS_NONE:
                        {
                            dx=ranges.mapx1-ranges.mapx0;
                            dy=ranges.mapy1-ranges.mapy0;
                            dz=ranges.mapz1-ranges.mapz0;
                            nx=ranges.mapx0 + p*dx;
                            ny=ranges.mapy0 + q*dy;
                            nz=ranges.mapz0 + r*dz;
                            CCoordinate coord(nx,ny,nz);
							val=m.evaluateAt(coord,index).outfloat_;
                        } break;
                        case SEAMLESS_X:
                        {
                            dx=ranges.loopx1-ranges.loopx0;
                            dy=ranges.mapy1-ranges.mapy0;
                            dz=ranges.mapz1-ranges.mapz0;
                            p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                            nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                            ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                            nz=ranges.mapy0 + q*dy;
                            nw=ranges.mapz0 + d*dz;
                            CCoordinate coord(nx,ny,nz,nw);
							val=m.evaluateAt(coord,index).outfloat_;
                        }
                        case SEAMLESS_Y:
                        {
                            dx=ranges.mapx1-ranges.mapx0;
                            dy=ranges.loopy1-ranges.loopy0;
                            dz=ranges.mapz1-ranges.mapz0;
                            q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                            nx=ranges.mapx0 + p*dx;
                            ny=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                            nz=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                            nw=ranges.mapz0 + r*dz;
                            CCoordinate coord(nx,ny,nz,nw);
							val=m.evaluateAt(coord,index).outfloat_;
                        } break;
                        case SEAMLESS_Z:
                        {
                            dx=ranges.mapx1-ranges.mapx0;
                            dy=ranges.mapy1-ranges.mapy0;
                            dz=ranges.loopz1-ranges.loopz0;
                            r=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                            nx=ranges.mapx0 + p*dx;
                            ny=ranges.mapy0 + q*dy;
                            nz=ranges.loopz0 + cos(r*pi2)*dz/pi2;
                            nw=ranges.loopz0 + sin(r*pi2)*dz/pi2;
                            CCoordinate coord(nx,ny,nz,nw);
							val=m.evaluateAt(coord,index).outfloat_;
                        } break;
                        case SEAMLESS_XY:
                        {
                            dx=ranges.loopx1-ranges.loopx0;
                            dy=ranges.loopy1-ranges.loopy0;
                            dz=ranges.mapz1-ranges.mapz0;
                            p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                            q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                            nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                            ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                            nz=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                            nw=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                            nu=ranges.mapz0 + r*dz;
                            CCoordinate coord(nx,ny,nz,nw,nu,0);
							val=m.evaluateAt(coord,index).outfloat_;
                        } break;
                        case SEAMLESS_XZ:
                        {
                            dx=ranges.loopx1-ranges.loopx0;
                            dy=ranges.mapy1-ranges.mapy0;
                            dz=ranges.loopz1-ranges.loopz0;
                            p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                            r=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                            nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                            ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                            nz=ranges.mapy0 + q*dy;
                            nw=ranges.loopz0 + cos(r*pi2)*dz/pi2;
                            nu=ranges.loopz0 + sin(r*pi2)*dz/pi2;
                            CCoordinate coord(nx,ny,nz,nw,nu,0);
							val=m.evaluateAt(coord,index).outfloat_;
                        } break;
                        case SEAMLESS_YZ:
                        {
                            dx=ranges.mapx1-ranges.mapx0;
                            dy=ranges.loopy1-ranges.loopy0;
                            dz=ranges.loopz1-ranges.loopz0;
                            q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                            r=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                            nx=ranges.mapx0 + p*dx;
                            ny=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                            nz=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                            nw=ranges.loopz0 + cos(r*pi2)*dz/pi2;
                            nu=ranges.loopz0 + sin(r*pi2)*dz/pi2;
                            CCoordinate coord(nx,ny,nz,nw,nu,0);
							val=m.evaluateAt(coord,index).outfloat_;
                        } break;
                        case SEAMLESS_XYZ:
                        {
                            dx=ranges.loopx1-ranges.loopx0;
                            dy=ranges.loopy1-ranges.loopy0;
                            dz=ranges.loopz1-ranges.loopz0;
                            p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                            q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                            r=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                            nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                            ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                            nz=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                            nw=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                            nu=ranges.loopz0 + cos(r*pi2)*dz/pi2;
                            nv=ranges.loopz0 + sin(r*pi2)*dz/pi2;
                            CCoordinate coord(nx,ny,nz,nw,nu,nv);
							val=m.evaluateAt(coord,index).outfloat_;
                        } break;
                        default: break;
                    }
                    a.set(x,y,z,val);
                }
            }
        }
    }




    void mapRGBA2D(int seamlessmode, CArray2Drgba &a, CKernel &k, SMappingRanges ranges, CInstructionIndex index, double z)
   {
        int w=a.width();
        int h=a.height();
        static double pi2=3.141592*2.0;
		CNoiseExecutor m(&k);

        int x,y;
        for(x=0; x<w; ++x)
        {
            for(y=0; y<h; ++y)
            {
                double p=(double)x / (double)w;
                double q=(double)y / (double)h;
                double r;
                double nx,ny,nz,nw,nu,nv=0.0;
                SRGBA val;
                double dx, dy, dz;
                switch(seamlessmode)
                {
                    case SEAMLESS_NONE:
                    {
                        nx=ranges.mapx0 + p*(ranges.mapx1-ranges.mapx0);
                        ny=ranges.mapy0 + q*(ranges.mapy1-ranges.mapy0);
                        nz=z;
                        CCoordinate coord(nx,ny,nz);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;
                    case SEAMLESS_X:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.mapy0 + q*dy;
                        nw=z;
                        CCoordinate coord(nx,ny,nz,nw);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;
                    case SEAMLESS_Y:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.mapx0 + p*dx;
                        ny=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nz=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        nw=z;
                        CCoordinate coord(nx,ny,nz,nw);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;
                    case SEAMLESS_Z:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        nx=ranges.mapx0 + p*dx;
                        ny=ranges.mapy0 + p*dx;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        nz=ranges.loopz0 + cos(zval*pi2) * dz/pi2;
                        nw=ranges.loopz0 + sin(zval*pi2) * dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;
                    case SEAMLESS_XY:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nw=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        nu=z;
                        CCoordinate coord(nx,ny,nz,nw,nu,0);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;
                    case SEAMLESS_XZ:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapx1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) *dx/pi2;
                        nz=ranges.mapy0 + q*dy;
                        nw=ranges.loopz0 + cos(zval*pi2)*dz/pi2;
                        nu=ranges.loopz0 + sin(zval*pi2)*dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw,nu,0);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;
                    case SEAMLESS_YZ:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.mapx0+p*dx;
                        ny=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nz=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        nw=ranges.loopz0 + cos(zval*pi2) * dz/pi2;
                        nu=ranges.loopz0 + sin(zval*pi2) * dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw,nu,0);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;
                    case SEAMLESS_XYZ:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        dz=ranges.loopz1-ranges.loopz0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        r=(z-ranges.mapz0)/(ranges.mapz1-ranges.mapz0);
                        double zval=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                        nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                        nz=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                        nw=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                        nu=ranges.loopz0 + cos(zval*pi2)*dz/pi2;
                        nv=ranges.loopz0 + sin(zval*pi2)*dz/pi2;
                        CCoordinate coord(nx,ny,nz,nw,nu,nv);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;

                    default: break;
                }
                a.set(x,y,val);
            }
        }
   }

   void mapRGBA2DNoZ(int seamlessmode, CArray2Drgba &a, CKernel &k, SMappingRanges ranges, CInstructionIndex index)
   {
        int w=a.width();
        int h=a.height();
        static double pi2=3.141592*2.0;
		CNoiseExecutor m(&k);

        int x,y;
        for(x=0; x<w; ++x)
        {
            for(y=0; y<h; ++y)
            {
                double p=(double)x / (double)w;
                double q=(double)y / (double)h;
                double nx,ny,nz,nw=0.0;
                SRGBA val;
                double dx, dy;
                switch(seamlessmode)
                {
                    case SEAMLESS_NONE:
                    {
                        nx=ranges.mapx0 + p*(ranges.mapx1-ranges.mapx0);
                        ny=ranges.mapy0 + q*(ranges.mapy1-ranges.mapy0);
                        CCoordinate coord(nx,ny);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;
                    case SEAMLESS_X:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.mapy1-ranges.mapy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.mapy0 + q*dy;
                        CCoordinate coord(nx,ny,nz);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;
                    case SEAMLESS_Y:
                    {
                        dx=ranges.mapx1-ranges.mapx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.mapx0 + p*dx;
                        ny=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nz=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        CCoordinate coord(nx,ny,nz);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;

                    case SEAMLESS_XY:
                    {
                        dx=ranges.loopx1-ranges.loopx0;
                        dy=ranges.loopy1-ranges.loopy0;
                        p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                        q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                        nx=ranges.loopx0 + cos(p*pi2) * dx/pi2;
                        ny=ranges.loopx0 + sin(p*pi2) * dx/pi2;
                        nz=ranges.loopy0 + cos(q*pi2) * dy/pi2;
                        nw=ranges.loopy0 + sin(q*pi2) * dy/pi2;
                        CCoordinate coord(nx,ny,nz,nw);
						val=m.evaluateAt(coord,index).outrgba_;
                    } break;
                    default: break;
                }
                a.set(x,y,val);
            }
        }
   }

    void mapRGBA3D(int seamlessmode, CArray3Drgba &a, CKernel &k, SMappingRanges ranges, CInstructionIndex index)
    {
        int w=a.width();
        int h=a.height();
        int d=a.depth();
		CNoiseExecutor m(&k);

        int x,y,z;
        static double pi2=3.14159265 * 2.0;
        for(x=0; x<w; ++x)
        {
            for(y=0; y<h; ++y)
            {
                for(z=0; z<d; ++z)
                {
                    double p=(double)x/(double)w;
                    double q=(double)y/(double)h;
                    double r=(double)z/(double)d;
                    double nx,ny,nz,nw,nu,nv;
                    double dx,dy,dz;
                    SRGBA val;

                    switch(seamlessmode)
                    {
                        case SEAMLESS_NONE:
                        {
                            dx=ranges.mapx1-ranges.mapx0;
                            dy=ranges.mapy1-ranges.mapy0;
                            dz=ranges.mapz1-ranges.mapz0;
                            nx=ranges.mapx0 + p*dx;
                            ny=ranges.mapy0 + q*dy;
                            nz=ranges.mapz0 + r*dz;
                            CCoordinate coord(nx,ny,nz);
							val=m.evaluateAt(coord,index).outrgba_;
                        } break;
                        case SEAMLESS_X:
                        {
                            dx=ranges.loopx1-ranges.loopx0;
                            dy=ranges.mapy1-ranges.mapy0;
                            dz=ranges.mapz1-ranges.mapz0;
                            p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                            nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                            ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                            nz=ranges.mapy0 + q*dy;
                            nw=ranges.mapz0 + d*dz;
                            CCoordinate coord(nx,ny,nz,nw);
							val=m.evaluateAt(coord,index).outrgba_;
                        }
                        case SEAMLESS_Y:
                        {
                            dx=ranges.mapx1-ranges.mapx0;
                            dy=ranges.loopy1-ranges.loopy0;
                            dz=ranges.mapz1-ranges.mapz0;
                            q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                            nx=ranges.mapx0 + p*dx;
                            ny=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                            nz=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                            nw=ranges.mapz0 + r*dz;
                            CCoordinate coord(nx,ny,nz,nw);
							val=m.evaluateAt(coord,index).outrgba_;
                        } break;
                        case SEAMLESS_Z:
                        {
                            dx=ranges.mapx1-ranges.mapx0;
                            dy=ranges.mapy1-ranges.mapy0;
                            dz=ranges.loopz1-ranges.loopz0;
                            r=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                            nx=ranges.mapx0 + p*dx;
                            ny=ranges.mapy0 + q*dy;
                            nz=ranges.loopz0 + cos(r*pi2)*dz/pi2;
                            nw=ranges.loopz0 + sin(r*pi2)*dz/pi2;
                            CCoordinate coord(nx,ny,nz,nw);
							val=m.evaluateAt(coord,index).outrgba_;
                        } break;
                        case SEAMLESS_XY:
                        {
                            dx=ranges.loopx1-ranges.loopx0;
                            dy=ranges.loopy1-ranges.loopy0;
                            dz=ranges.mapz1-ranges.mapz0;
                            p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                            q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                            nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                            ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                            nz=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                            nw=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                            nu=ranges.mapz0 + r*dz;
                            CCoordinate coord(nx,ny,nz,nw,nu,0);
							val=m.evaluateAt(coord,index).outrgba_;
                        } break;
                        case SEAMLESS_XZ:
                        {
                            dx=ranges.loopx1-ranges.loopx0;
                            dy=ranges.mapy1-ranges.mapy0;
                            dz=ranges.loopz1-ranges.loopz0;
                            p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                            r=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                            nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                            ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                            nz=ranges.mapy0 + q*dy;
                            nw=ranges.loopz0 + cos(r*pi2)*dz/pi2;
                            nu=ranges.loopz0 + sin(r*pi2)*dz/pi2;
                            CCoordinate coord(nx,ny,nz,nw,nu,0);
							val=m.evaluateAt(coord,index).outrgba_;
                        } break;
                        case SEAMLESS_YZ:
                        {
                            dx=ranges.mapx1-ranges.mapx0;
                            dy=ranges.loopy1-ranges.loopy0;
                            dz=ranges.loopz1-ranges.loopz0;
                            q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                            r=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                            nx=ranges.mapx0 + p*dx;
                            ny=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                            nz=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                            nw=ranges.loopz0 + cos(r*pi2)*dz/pi2;
                            nu=ranges.loopz0 + sin(r*pi2)*dz/pi2;
                            CCoordinate coord(nx,ny,nz,nw,nu,0);
							val=m.evaluateAt(coord,index).outrgba_;
                        } break;
                        case SEAMLESS_XYZ:
                        {
                            dx=ranges.loopx1-ranges.loopx0;
                            dy=ranges.loopy1-ranges.loopy0;
                            dz=ranges.loopz1-ranges.loopz0;
                            p=p*(ranges.mapx1-ranges.mapx0)/(ranges.loopx1-ranges.loopx0);
                            q=q*(ranges.mapy1-ranges.mapy0)/(ranges.loopy1-ranges.loopy0);
                            r=r*(ranges.mapz1-ranges.mapz0)/(ranges.loopz1-ranges.loopz0);
                            nx=ranges.loopx0 + cos(p*pi2)*dx/pi2;
                            ny=ranges.loopx0 + sin(p*pi2)*dx/pi2;
                            nz=ranges.loopy0 + cos(q*pi2)*dy/pi2;
                            nw=ranges.loopy0 + sin(q*pi2)*dy/pi2;
                            nu=ranges.loopz0 + cos(r*pi2)*dz/pi2;
                            nv=ranges.loopz0 + sin(r*pi2)*dz/pi2;
                            CCoordinate coord(nx,ny,nz,nw,nu,nv);
							val=m.evaluateAt(coord,index).outrgba_;
                        } break;
                        default: break;
                    }
                    a.set(x,y,z,val);
                }
            }
        }
    }
};
