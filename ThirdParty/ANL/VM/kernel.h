#ifndef KERNEL_H
#define KERNEL_H

#include "instruction.h"
#include "vm.h"
#include <string>
#include <map>

namespace anl
{

    class CKernel
    {
    public:

        CInstructionIndex constant(double val);
        CInstructionIndex valueBasis(CInstructionIndex interpindex, unsigned int seed);
        CInstructionIndex gradientBasis(CInstructionIndex interpindex, unsigned int seed);
        CInstructionIndex simplexBasis(unsigned int seed);
        CInstructionIndex cellularBasis(CInstructionIndex f1, CInstructionIndex f2, CInstructionIndex f3, CInstructionIndex f4, CInstructionIndex d1, CInstructionIndex d2, CInstructionIndex d3, CInstructionIndex d4, CInstructionIndex dist, unsigned int seed);
        CInstructionIndex add(CInstructionIndex s1index, CInstructionIndex s2index);
        CInstructionIndex subtract(CInstructionIndex s1, CInstructionIndex s2);
        CInstructionIndex multiply(CInstructionIndex s1index, CInstructionIndex s2index);
        CInstructionIndex divide(CInstructionIndex s1, CInstructionIndex s2);
        CInstructionIndex maximum(CInstructionIndex s1index, CInstructionIndex s2index);
        CInstructionIndex minimum(CInstructionIndex s1index, CInstructionIndex s2index);
        CInstructionIndex abs(CInstructionIndex sindex);
        CInstructionIndex pow(CInstructionIndex s1, CInstructionIndex s2);
		CInstructionIndex bias(CInstructionIndex s1, CInstructionIndex s2);
		CInstructionIndex gain(CInstructionIndex s1, CInstructionIndex s2);

        CInstructionIndex scaleDomain(CInstructionIndex srcindex, CInstructionIndex xindex, CInstructionIndex yindex);
        CInstructionIndex scaleDomain(CInstructionIndex srcindex, CInstructionIndex xindex, CInstructionIndex yindex, CInstructionIndex zindex);
        CInstructionIndex scaleDomain(CInstructionIndex srcindex, CInstructionIndex xindex, CInstructionIndex yindex, CInstructionIndex zindex, CInstructionIndex windex);
        CInstructionIndex scaleDomain(CInstructionIndex srcindex, CInstructionIndex xindex, CInstructionIndex yindex, CInstructionIndex zindex, CInstructionIndex windex, CInstructionIndex uindex, CInstructionIndex vindex);

        CInstructionIndex scaleX(CInstructionIndex src, CInstructionIndex scale);
        CInstructionIndex scaleY(CInstructionIndex src, CInstructionIndex scale);
        CInstructionIndex scaleZ(CInstructionIndex src, CInstructionIndex scale);
        CInstructionIndex scaleW(CInstructionIndex src, CInstructionIndex scale);
        CInstructionIndex scaleU(CInstructionIndex src, CInstructionIndex scale);
        CInstructionIndex scaleV(CInstructionIndex src, CInstructionIndex scale);

        CInstructionIndex translateDomain(CInstructionIndex srcindex, CInstructionIndex xindex, CInstructionIndex yindex);
        CInstructionIndex translateDomain(CInstructionIndex srcindex, CInstructionIndex xindex, CInstructionIndex yindex, CInstructionIndex zindex);
        CInstructionIndex translateDomain(CInstructionIndex srcindex, CInstructionIndex xindex, CInstructionIndex yindex, CInstructionIndex zindex, CInstructionIndex windex);
        CInstructionIndex translateDomain(CInstructionIndex srcindex, CInstructionIndex xindex, CInstructionIndex yindex, CInstructionIndex zindex, CInstructionIndex windex, CInstructionIndex uindex, CInstructionIndex vindex);

        CInstructionIndex translateX(CInstructionIndex src, CInstructionIndex trans);
        CInstructionIndex translateY(CInstructionIndex src, CInstructionIndex trans);
        CInstructionIndex translateZ(CInstructionIndex src, CInstructionIndex trans);
        CInstructionIndex translateW(CInstructionIndex src, CInstructionIndex trans);
        CInstructionIndex translateU(CInstructionIndex src, CInstructionIndex trans);
        CInstructionIndex translateV(CInstructionIndex src, CInstructionIndex trans);

        CInstructionIndex rotateDomain(CInstructionIndex src, CInstructionIndex angle, CInstructionIndex ax, CInstructionIndex ay, CInstructionIndex az);

        CInstructionIndex addSequence(CInstructionIndex baseindex, unsigned int number, unsigned int stride);
        CInstructionIndex multiplySequence(CInstructionIndex baseindex, unsigned int number, unsigned int stride);
        CInstructionIndex maxSequence(CInstructionIndex baseindex, unsigned int number, unsigned int stride);
        CInstructionIndex minSequence(CInstructionIndex baseindex, unsigned int number, unsigned int stride);
        CInstructionIndex blend(CInstructionIndex low, CInstructionIndex high, CInstructionIndex control);
        CInstructionIndex select(CInstructionIndex low, CInstructionIndex high, CInstructionIndex control, CInstructionIndex threshold, CInstructionIndex falloff);
        CInstructionIndex clamp(CInstructionIndex src, CInstructionIndex low, CInstructionIndex high);

        CInstructionIndex cos(CInstructionIndex src);
        CInstructionIndex sin(CInstructionIndex src);
        CInstructionIndex tan(CInstructionIndex src);
        CInstructionIndex acos(CInstructionIndex src);
        CInstructionIndex asin(CInstructionIndex src);
        CInstructionIndex atan(CInstructionIndex src);

        CInstructionIndex x();
        CInstructionIndex y();
        CInstructionIndex z();
        CInstructionIndex w();
        CInstructionIndex u();
        CInstructionIndex v();

		CInstructionIndex radial();


		CInstructionIndex combineRGBA(CInstructionIndex r, CInstructionIndex g, CInstructionIndex b, CInstructionIndex a);

        CInstructionIndex scaleOffset(CInstructionIndex src, double scale, double offset);

        CInstructionIndex simpleFractalLayer(unsigned int basistype, CInstructionIndex interptypeindex, double layerscale, double layerfreq, unsigned int seed, bool rot=true,
            double angle=0.5, double ax=0, double ay=0, double az=1);
        CInstructionIndex simplefBm(unsigned int basistype, unsigned int interptype, unsigned int numoctaves, double frequency, unsigned int seed, bool rot=true);

        InstructionListType *getKernel(){return &kernel_;}
        CInstructionIndex nextIndex(){return CInstructionIndex(kernel_.size());}
        CInstructionIndex lastIndex(){return CInstructionIndex(kernel_.size()-1);}
    private:
        InstructionListType kernel_;
    };

};

#endif
