#include "kernel.h"
#include "random_gen.h"
#include <cmath>
#include <iostream>

namespace anl
{

CInstructionIndex CKernel::constant(double val)
{
    anl::SInstruction i;
    i.outfloat_=val;
    i.opcode_=anl::OP_Constant;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::valueBasis(CInstructionIndex interpindex, unsigned int seed)
{
    anl::SInstruction i;

    i.opcode_=anl::OP_ValueBasis;
    i.sources_[0]=interpindex.index_;
    i.seed_=seed;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::gradientBasis(CInstructionIndex interp, unsigned int seed)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_GradientBasis;
    i.sources_[0]=interp.index_;
    i.seed_=seed;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::simplexBasis(unsigned int seed)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_SimplexBasis;
    i.seed_=seed;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::cellularBasis(CInstructionIndex f1, CInstructionIndex f2, CInstructionIndex f3, CInstructionIndex f4, CInstructionIndex d1, CInstructionIndex d2, CInstructionIndex d3, CInstructionIndex d4, CInstructionIndex dist, unsigned int seed)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_CellularBasis;
    i.seed_=seed;
    i.sources_[0]=dist.index_;
    i.sources_[1]=f1.index_;
    i.sources_[2]=f2.index_;
    i.sources_[3]=f3.index_;
    i.sources_[4]=f4.index_;
    i.sources_[5]=d1.index_;
    i.sources_[6]=d2.index_;
    i.sources_[7]=d3.index_;
    i.sources_[8]=d4.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::add(CInstructionIndex s1, CInstructionIndex s2)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Add;
    i.sources_[0]=s1.index_;
    i.sources_[1]=s2.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::subtract(CInstructionIndex s1, CInstructionIndex s2)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Subtract;
    i.sources_[0]=s1.index_;
    i.sources_[1]=s2.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::multiply(CInstructionIndex s1, CInstructionIndex s2)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Multiply;
    i.sources_[0]=s1.index_;
    i.sources_[1]=s2.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::divide(CInstructionIndex s1, CInstructionIndex s2)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Divide;
    i.sources_[0]=s1.index_;
    i.sources_[1]=s2.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::maximum(CInstructionIndex s1index, CInstructionIndex s2index)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Max;
    i.sources_[0]=s1index.index_;
    i.sources_[1]=s2index.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::minimum(CInstructionIndex s1index, CInstructionIndex s2index)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Min;
    i.sources_[0]=s1index.index_;
    i.sources_[1]=s2index.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::abs(CInstructionIndex sindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Abs;
    i.sources_[0]=sindex.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::pow(CInstructionIndex s1, CInstructionIndex s2)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Pow;
    i.sources_[0]=s1.index_;
    i.sources_[1]=s2.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::bias(CInstructionIndex s1, CInstructionIndex s2)
{
	anl::SInstruction i;
	i.opcode_=anl::OP_Bias;
	i.sources_[0]=s1.index_;
	i.sources_[1]=s2.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::gain(CInstructionIndex s1, CInstructionIndex s2)
{
	anl::SInstruction i;
	i.opcode_=anl::OP_Gain;
	i.sources_[0]=s1.index_;
	i.sources_[1]=s2.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::cos(CInstructionIndex sindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Cos;
    i.sources_[0]=sindex.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::sin(CInstructionIndex sindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Sin;
    i.sources_[0]=sindex.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::tan(CInstructionIndex sindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Tan;
    i.sources_[0]=sindex.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::acos(CInstructionIndex sindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ACos;
    i.sources_[0]=sindex.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::asin(CInstructionIndex sindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ASin;
    i.sources_[0]=sindex.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::atan(CInstructionIndex sindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ATan;
    i.sources_[0]=sindex.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::tiers(CInstructionIndex s1, CInstructionIndex s2)
{
	anl::SInstruction i;
	i.opcode_=anl::OP_Tiers;
	i.sources_[0]=s1.index_;
	i.sources_[1]=s2.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::smoothTiers(CInstructionIndex s1, CInstructionIndex s2)
{
	anl::SInstruction i;
	i.opcode_=anl::OP_SmoothTiers;
	i.sources_[0]=s1.index_;
	i.sources_[1]=s2.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::scaleDomain(CInstructionIndex srcindex, CInstructionIndex xindex, CInstructionIndex yindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleDomain;
    i.sources_[0]=srcindex.index_;
    i.sources_[1]=xindex.index_;
    i.sources_[2]=yindex.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::scaleDomain(CInstructionIndex srcindex, CInstructionIndex xindex, CInstructionIndex yindex, CInstructionIndex zindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleDomain;
    i.sources_[0]=srcindex.index_;
    i.sources_[1]=xindex.index_;
    i.sources_[2]=yindex.index_;
    i.sources_[3]=zindex.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::scaleDomain(CInstructionIndex srcindex, CInstructionIndex xindex, CInstructionIndex yindex, CInstructionIndex zindex, CInstructionIndex windex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleDomain;
    i.sources_[0]=srcindex.index_;
    i.sources_[1]=xindex.index_;
    i.sources_[2]=yindex.index_;
    i.sources_[3]=zindex.index_;
    i.sources_[4]=windex.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::scaleDomain(CInstructionIndex srcindex, CInstructionIndex xindex, CInstructionIndex yindex, CInstructionIndex zindex, CInstructionIndex windex, CInstructionIndex uindex, CInstructionIndex vindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleDomain;
    i.sources_[0]=srcindex.index_;
    i.sources_[1]=xindex.index_;
    i.sources_[2]=yindex.index_;
    i.sources_[3]=zindex.index_;
    i.sources_[4]=windex.index_;
    i.sources_[5]=uindex.index_;
    i.sources_[6]=vindex.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::scaleX(CInstructionIndex src, CInstructionIndex scale)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleX;
    i.sources_[0]=src.index_;
    i.sources_[1]=scale.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::scaleY(CInstructionIndex src, CInstructionIndex scale)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleY;
    i.sources_[0]=src.index_;
    i.sources_[1]=scale.index_;
    kernel_.push_back(i);
    return lastIndex();
}
CInstructionIndex CKernel::scaleZ(CInstructionIndex src, CInstructionIndex scale)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleZ;
    i.sources_[0]=src.index_;
    i.sources_[1]=scale.index_;
    kernel_.push_back(i);
    return lastIndex();
}
CInstructionIndex CKernel::scaleW(CInstructionIndex src, CInstructionIndex scale)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleW;
    i.sources_[0]=src.index_;
    i.sources_[1]=scale.index_;
    kernel_.push_back(i);
    return lastIndex();
}
CInstructionIndex CKernel::scaleU(CInstructionIndex src, CInstructionIndex scale)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleU;
    i.sources_[0]=src.index_;
    i.sources_[1]=scale.index_;
    kernel_.push_back(i);
    return lastIndex();
}
CInstructionIndex CKernel::scaleV(CInstructionIndex src, CInstructionIndex scale)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleV;
    i.sources_[0]=src.index_;
    i.sources_[1]=scale.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::translateDomain(CInstructionIndex srcindex, CInstructionIndex xindex, CInstructionIndex yindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateDomain;
    i.sources_[0]=srcindex.index_;
    i.sources_[1]=xindex.index_;
    i.sources_[2]=yindex.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::translateDomain(CInstructionIndex srcindex, CInstructionIndex xindex, CInstructionIndex yindex, CInstructionIndex zindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateDomain;
    i.sources_[0]=srcindex.index_;
    i.sources_[1]=xindex.index_;
    i.sources_[2]=yindex.index_;
    i.sources_[3]=zindex.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::translateDomain(CInstructionIndex srcindex, CInstructionIndex xindex, CInstructionIndex yindex, CInstructionIndex zindex, CInstructionIndex windex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateDomain;
    i.sources_[0]=srcindex.index_;
    i.sources_[1]=xindex.index_;
    i.sources_[2]=yindex.index_;
    i.sources_[3]=zindex.index_;
    i.sources_[4]=windex.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::translateDomain(CInstructionIndex srcindex, CInstructionIndex xindex, CInstructionIndex yindex, CInstructionIndex zindex, CInstructionIndex windex, CInstructionIndex uindex, CInstructionIndex vindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateDomain;
    i.sources_[0]=srcindex.index_;
    i.sources_[1]=xindex.index_;
    i.sources_[2]=yindex.index_;
    i.sources_[3]=zindex.index_;
    i.sources_[4]=windex.index_;
    i.sources_[5]=uindex.index_;
    i.sources_[6]=vindex.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::translateX(CInstructionIndex src, CInstructionIndex trans)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateX;
    i.sources_[0]=src.index_;
    i.sources_[1]=trans.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::translateY(CInstructionIndex src, CInstructionIndex trans)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateY;
    i.sources_[0]=src.index_;
    i.sources_[1]=trans.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::translateZ(CInstructionIndex src, CInstructionIndex trans)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateZ;
    i.sources_[0]=src.index_;
    i.sources_[1]=trans.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::translateW(CInstructionIndex src, CInstructionIndex trans)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateW;
    i.sources_[0]=src.index_;
    i.sources_[1]=trans.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::translateU(CInstructionIndex src, CInstructionIndex trans)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateU;
    i.sources_[0]=src.index_;
    i.sources_[1]=trans.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::translateV(CInstructionIndex src, CInstructionIndex trans)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateV;
    i.sources_[0]=src.index_;
    i.sources_[1]=trans.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::rotateDomain(CInstructionIndex src, CInstructionIndex angle, CInstructionIndex ax, CInstructionIndex ay, CInstructionIndex az)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_RotateDomain;
    i.sources_[0]=src.index_;
    i.sources_[1]=angle.index_;
    i.sources_[2]=ax.index_;
    i.sources_[3]=ay.index_;
    i.sources_[4]=az.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::addSequence(CInstructionIndex baseindex, unsigned int number, unsigned int stride)
{
    if(number<=1) return lastIndex();

    CInstructionIndex s1=baseindex;
    CInstructionIndex s2=baseindex+stride;
	CInstructionIndex addstart=add(s1,s2);

    if(number==2)
    {
        return lastIndex();
    }

    s1=addstart;
    s2+=stride;
    for(unsigned int c=0; c<number-2; ++c)
    {
        add(s1,s2);
		++s1;
        s2+=stride;
    }

    return lastIndex();
}

CInstructionIndex CKernel::multiplySequence(CInstructionIndex baseindex, unsigned int number, unsigned int stride)
{
    if(number<=1) return lastIndex();

    CInstructionIndex s1=baseindex;
    CInstructionIndex s2=baseindex+stride;

    CInstructionIndex addstart=multiply(s1,s2);

    if(number==2)
    {
        return lastIndex();
    }

    s1=addstart;
    s2+=stride;
    for(unsigned int c=0; c<number-2; ++c)
    {
        multiply(s1,s2);
        ++s1;
        s2+=stride;
    }

    return lastIndex();
}

CInstructionIndex CKernel::maxSequence(CInstructionIndex baseindex, unsigned int number, unsigned int stride)
{
    if(number<=1) return lastIndex();

    CInstructionIndex s1=baseindex;
    CInstructionIndex s2=baseindex+stride;

    CInstructionIndex addstart=maximum(s1,s2);

    if(number==2)
    {
        return lastIndex();
    }

    s1=addstart;
    s2+=stride;
    for(unsigned int c=0; c<number-2; ++c)
    {
        maximum(s1,s2);
        ++s1;
        s2+=stride;
    }

    return lastIndex();
}

CInstructionIndex CKernel::minSequence(CInstructionIndex baseindex, unsigned int number, unsigned int stride)
{
    if(number<=1) return lastIndex();

    CInstructionIndex s1=baseindex;
    CInstructionIndex s2=baseindex+stride;

    CInstructionIndex addstart=minimum(s1,s2);

    if(number==2)
    {
        return lastIndex();
    }

    s1=addstart;
    s2+=stride;
    for(unsigned int c=0; c<number-2; ++c)
    {
        minimum(s1,s2);
        ++s1;
        s2+=stride;
    }

    return lastIndex();
}

CInstructionIndex CKernel::blend(CInstructionIndex low, CInstructionIndex high, CInstructionIndex control)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Blend;
    i.sources_[0]=low.index_;
    i.sources_[1]=high.index_;
    i.sources_[2]=control.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::select(CInstructionIndex low, CInstructionIndex high, CInstructionIndex control, CInstructionIndex threshold, CInstructionIndex falloff)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Select;
    i.sources_[0]=low.index_;
    i.sources_[1]=high.index_;
    i.sources_[2]=control.index_;
    i.sources_[3]=threshold.index_;
    i.sources_[4]=falloff.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::simpleFractalLayer(unsigned int basistype, CInstructionIndex interpindex, double layerscale, double layerfreq, unsigned int seed, bool rot,
            double angle, double ax, double ay, double az)
{
    CInstructionIndex base=nextIndex();
    switch(basistype)
    {
    case anl::OP_ValueBasis:
        valueBasis(interpindex, seed);
        break;
    case anl::OP_GradientBasis:
        gradientBasis(interpindex, seed);
        break;
    case anl::OP_SimplexBasis:
        simplexBasis(seed);
        break;
    default:
        gradientBasis(interpindex, seed);
        break;
    }
    constant(layerscale);
    multiply(base,base+1);
    constant(layerfreq);
    CInstructionIndex sd=scaleDomain(base+2, lastIndex(), lastIndex(), lastIndex(), lastIndex(), lastIndex(), lastIndex());
    if(rot)
    {
		double len=std::sqrt(ax*ax+ay*ay+az*az);
        constant(angle);
        constant(ax/len);
        constant(ay/len);
        constant(az/len);
        rotateDomain(sd, sd+1, sd+2, sd+3, sd+4);
    }
    return lastIndex();
}

CInstructionIndex CKernel::simpleRidgedLayer(unsigned int basistype, CInstructionIndex interpindex, double layerscale, double layerfreq, unsigned int seed, bool rot,
            double angle, double ax, double ay, double az)
{
    CInstructionIndex base=nextIndex();
    switch(basistype)
    {
    case anl::OP_ValueBasis:
        valueBasis(interpindex, seed);
        break;
    case anl::OP_GradientBasis:
        gradientBasis(interpindex, seed);
        break;
    case anl::OP_SimplexBasis:
        simplexBasis(seed);
        break;
    default:
        gradientBasis(interpindex, seed);
        break;
    }
	base=abs(base);
	constant(1.0);
	base=subtract(lastIndex(), base);
    constant(layerscale);
    multiply(base,base+1);
    constant(layerfreq);
    CInstructionIndex sd=scaleDomain(base+2, lastIndex(), lastIndex(), lastIndex(), lastIndex(), lastIndex(), lastIndex());
    if(rot)
    {
		double len=std::sqrt(ax*ax+ay*ay+az*az);
        constant(angle);
        constant(ax/len);
        constant(ay/len);
        constant(az/len);
        rotateDomain(sd, sd+1, sd+2, sd+3, sd+4);
    }
    return lastIndex();
}

CInstructionIndex CKernel::simpleRidgedMultifractal(unsigned int basistype, unsigned int interptype, unsigned int numoctaves, double frequency, unsigned int seed, bool rot)
{
    if(numoctaves<1) return 0;
	
	CInstructionIndex interpindex=constant(interptype);
	KISS rnd;
	rnd.setSeed(seed);
	simpleRidgedLayer(basistype, interpindex, 1.0, 1.0*frequency, seed+10,rot,
                               rnd.get01()*3.14159265*2.0, rnd.get01(), rnd.get01(), rnd.get01());
	CInstructionIndex lastlayer=lastIndex();
	
	for(int c=0; c<numoctaves-1; ++c)
	{
		CInstructionIndex nextlayer=simpleRidgedLayer(basistype, interpindex, 1.0/std::pow(2.0, (double)(c)), std::pow(2.0, (double)(c))*frequency, seed+10+c*1000,rot,
                               rnd.get01()*3.14159265*2.0, rnd.get01(), rnd.get01(), rnd.get01());
		lastlayer=add(lastlayer,nextlayer);
	}
	return lastIndex();
}

CInstructionIndex CKernel::simplefBm(unsigned int basistype, unsigned int interptype, unsigned int numoctaves, double frequency, unsigned int seed, bool rot)
{
    if(numoctaves<1) return 0;
	
	CInstructionIndex interpindex=constant(interptype);
	KISS rnd;
	rnd.setSeed(seed);
	simpleFractalLayer(basistype, interpindex, 1.0, 1.0*frequency, seed+10,rot,
                               rnd.get01()*3.14159265*2.0, rnd.get01(), rnd.get01(), rnd.get01());
	CInstructionIndex lastlayer=lastIndex();
	
	for(int c=0; c<numoctaves-1; ++c)
	{
		CInstructionIndex nextlayer=simpleFractalLayer(basistype, interpindex, 1.0/std::pow(2.0, (double)(c)), std::pow(2.0, (double)(c))*frequency, seed+10+c*1000,rot,
                               rnd.get01()*3.14159265*2.0, rnd.get01(), rnd.get01(), rnd.get01());
		lastlayer=add(lastlayer,nextlayer);
	}
	return lastIndex();
}

CInstructionIndex CKernel::x()
{
    anl::SInstruction i;
    i.opcode_=anl::OP_X;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::y()
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Y;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::z()
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Z;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::w()
{
    anl::SInstruction i;
    i.opcode_=anl::OP_W;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::u()
{
    anl::SInstruction i;
    i.opcode_=anl::OP_U;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::v()
{
    anl::SInstruction i;
    i.opcode_=anl::OP_V;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::scaleOffset(CInstructionIndex src, double scale, double offset)
{
    CInstructionIndex c=constant(scale);
    CInstructionIndex o=constant(offset);
    CInstructionIndex m=multiply(src,c);
    add(m,o);
    return lastIndex();
}

CInstructionIndex CKernel::radial()
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Radial;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::clamp(CInstructionIndex src, CInstructionIndex low, CInstructionIndex high)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Clamp;
    i.sources_[0]=src.index_;
    i.sources_[1]=low.index_;
    i.sources_[2]=high.index_;
    kernel_.push_back(i);
    return lastIndex();
}

CInstructionIndex CKernel::combineRGBA(CInstructionIndex r, CInstructionIndex g, CInstructionIndex b, CInstructionIndex a)
{
	anl::SInstruction i;
	i.opcode_=anl::OP_CombineRGBA;
	i.sources_[0]=r.index_;
	i.sources_[1]=g.index_;
	i.sources_[2]=b.index_;
	i.sources_[3]=a.index_;
	kernel_.push_back(i);
	return lastIndex();
}

CInstructionIndex CKernel::hexTile(unsigned int seed)
{
	anl::SInstruction i;
	i.opcode_=anl::OP_HexTile;
	i.seed_=seed;
	kernel_.push_back(i);
	return lastIndex();
}

CInstructionIndex CKernel::hexBump()
{
	anl::SInstruction i;
	i.opcode_=anl::OP_HexBump;
	kernel_.push_back(i);
	return lastIndex();
}
};
