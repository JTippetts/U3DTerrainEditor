#include "../ThirdParty/accidental-noise-library/anl.h"
#include <Urho3D/Resource/Image.h>
#include <Urho3D/Core/Context.h>
#include <Urho3D/IO/Log.h>

using namespace anl;
using namespace Urho3D;

// ANL Utilities
Vector2 RenderANLKernelToImage(Image *buffer, CKernel *kernel, float lowrange, float highrange, Image *histogram,int seamlessmode, bool usez, float z, float scalex, float scaley, bool rescale)
{
	#define th(x) //Log::Write(LOG_INFO, String((x)));
    if(!buffer) return Vector2();
    CArray2Dd img;

    int w=buffer->GetWidth();
    int h=buffer->GetHeight();
    img.resize(w,h);
	th(1);

	if (!usez)
		map2DNoZ(seamlessmode, img, *kernel, SMappingRanges(0,scalex,0,scaley,0,1), kernel->lastIndex());
	else
		map2D(seamlessmode, img, *kernel, SMappingRanges(0,scalex,0,scaley,0,1), z, kernel->lastIndex());
	float low=(float)img.getMin(),high=(float)img.getMax();
	th(2);
	if(histogram)
	{
		const int numdivs=histogram->GetWidth();
		//int counts[numdivs];
		Vector<int> counts(numdivs);
		for(int c=0; c<numdivs; ++c) counts[c]=0;
		th(1.5);
		th(w);
		th(h);
		th(numdivs);
		th(low);
		th(high);
		for(int x=0; x<w; ++x)
		{
			for(int y=0; y<h; ++y)
			{
				float v=(float)img.get(x,y);
				v=(v-low) / (high - low);
				int c = (int)(v * (float)(numdivs-1));
				c=std::min(numdivs-1, std::max(0, c));
				counts[c]++;
			}
		}
		th(1.6);
		int mincount=w*h+10;
		int maxcount = 0;
		for(int c=0; c<numdivs; ++c)
		{
			if(counts[c]>maxcount) maxcount=c;
			if(counts[c]<mincount) mincount=c;
		}

		th(1.7)
		histogram->Clear(Color(0,0,0));
		for(int x=0; x<histogram->GetWidth(); ++x)
		{
			float cv=(float)(counts[x]);
			cv=(cv - (float)mincount) / ((float)(maxcount) - (float)(mincount));
			for(int y=0; y<(int)(cv * (histogram->GetHeight())); ++y)
			{
				histogram->SetPixel(x,histogram->GetHeight()-y,Color(1,1,1));
			}
		}
	}
	th(3);
    if(rescale) img.scaleToRange(lowrange, highrange);
    for(int x=0; x<w; ++x)
    {
        for(int y=0; y<h; ++y)
        {
            float v=(float)img.get(x,y);
            buffer->SetPixel(x,y,Color(v,v,v,1));
        }
    }
	th(4);
	return Vector2(low,high);
}
