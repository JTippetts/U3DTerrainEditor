#include <list>
#include <iostream>
#include <algorithm>

struct SDrop
{
    int x,y;

    SDrop(int X, int Y) : x(X), y(Y) {}
};

void shuffleDirections(SDrop *dirs, anl::CMWC4096 &rnd)
{
    for(int i=0; i<8; ++i)
    {
        int index=rnd.getRange(0,8-i)+i;
        std::swap(dirs[index], dirs[i]);
    }
}

SDrop find_lowest_neighbor(anl::CMWC4096 &rnd, anl::CArray2Dd &map, int x, int y)
{
    int w=map.width(), h=map.height();

    static SDrop dirs[8]=
    {
        {-1,-1},
        {0,-1},
        {1,-1},
        {-1,0},
        {1,0},
        {-1,1},
        {0,1},
        {1,1}

    };

    int minx=x;
    int miny=y;
    double minht=map.get(x,y);

    shuffleDirections(dirs,rnd);

    for(int c=0; c<8; ++c)
    {
        int i=x+dirs[c].x;
        int j=y+dirs[c].y;
        if(i>=0 && i<w && j>=0 && j<h)
        {
            double v=map.get(i,j);
            if(v<minht)
            {
                minht=v;
                minx=i;
                miny=j;
            }
        }
    }

    return SDrop(minx,miny);
}

void simpleErode(anl::CArray2Dd &map, unsigned int numdrops, float power)
{
    anl::CMWC4096 rnd;
    rnd.setSeedTime();

    std::list<SDrop> drops;
    int w=map.width(), h=map.height();

    if(numdrops==0) numdrops=w*h;

    for(unsigned int c=0; c<numdrops; ++c)
    {
        drops.push_back(SDrop(rnd.getRange(0,w-1), rnd.getRange(0,h-1)));
    }

    while(!drops.empty())
    {
        SDrop drop=drops.front();
        drops.pop_front();

        SDrop low=find_lowest_neighbor(rnd, map, drop.x, drop.y);
        if(low.x != drop.x || low.y!=drop.y)
        {
            double ht=map.get(drop.x,drop.y);
            double mn=map.get(low.x,low.y);

            map.set(drop.x,drop.y,ht+power*(mn-ht));
            map.set(low.x,low.y,ht+(1.0-power)*(mn-ht));
            drops.push_back(low);
        }

        //std::cout << "Drops remaining: " << drops.size() << std::endl;
    }
}

void waterFlow(anl::CArray2Dd &map, anl::CArray2Dd &flow, unsigned int numdrops)
{
	anl::CMWC4096 rnd;
    rnd.setSeedTime();

    std::list<SDrop> drops;
    int w=map.width(), h=map.height();

    if(numdrops==0) numdrops=w*h;

    for(unsigned int c=0; c<numdrops; ++c)
    {
        drops.push_back(SDrop(rnd.getRange(0,w-1), rnd.getRange(0,h-1)));
    }
	
	flow.resize(map.width(), map.height());
	flow.fill(0);

    while(!drops.empty())
    {
        SDrop drop=drops.front();
        drops.pop_front();

        SDrop low=find_lowest_neighbor(rnd, map, drop.x, drop.y);
        if(low.x != drop.x || low.y!=drop.y)
        {
            flow.set(low.x,low.y,flow.get(low.x,low.y)+1);
            drops.push_back(low);
        }

        //std::cout << "Drops remaining: " << drops.size() << std::endl;
    }
}
