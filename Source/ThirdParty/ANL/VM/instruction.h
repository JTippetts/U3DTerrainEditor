#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "types.h"
#include <vector>

const int MaxSourceCount=10;

namespace anl
{
    enum EOpcodes
    {
        OP_NOP,
        OP_Constant,
        OP_ValueBasis,
        OP_GradientBasis,
        OP_SimplexBasis,
        OP_CellularBasis,
        OP_Add,
        OP_Subtract,
        OP_Multiply,
        OP_Divide,
        OP_ScaleDomain,
        OP_ScaleX,
        OP_ScaleY,
        OP_ScaleZ,
        OP_ScaleW,
        OP_ScaleU,
        OP_ScaleV,
        OP_TranslateDomain,
        OP_TranslateX,
        OP_TranslateY,
        OP_TranslateZ,
        OP_TranslateW,
        OP_TranslateU,
        OP_TranslateV,
        OP_RotateDomain,
        OP_Blend,
        OP_Select,
        OP_Min,
        OP_Max,
        OP_Abs,
        OP_Pow,
        OP_Clamp,
        OP_Radial,
        OP_Sin,
        OP_Cos,
        OP_Tan,
        OP_ASin,
        OP_ACos,
        OP_ATan,

        OP_X,
        OP_Y,
        OP_Z,
        OP_W,
        OP_U,
        OP_V,

		// RGBA operations
		OP_ExtractRed,
		OP_ExtractGreen,
		OP_ExtractBlue,
		OP_ExtractAlpha,
		OP_Grayscale,
		OP_CombineRGBA
    };

    struct SInstruction
    {
        // Out fields
        double outfloat_;
        RGBA outrgba_;

        // Source input indices
        unsigned int sources_[MaxSourceCount];

        // Instruction opcode
        unsigned int opcode_;
        unsigned int seed_;

        SInstruction()
        {
            for(unsigned int c=0; c<MaxSourceCount; ++c) sources_[c]=1000000;
            outfloat_=0;
            opcode_=0;
            seed_=12345;
        }
    };

	class CKernel;
	class CNoiseExecutor;
	class CInstructionIndex
	{
		public:
		CInstructionIndex(const CInstructionIndex &c)
		{
			index_=c.index_;
		}

		CInstructionIndex operator +(const CInstructionIndex &c)
		{
			return CInstructionIndex(index_+c.index_);
		}

		CInstructionIndex &operator +=(const CInstructionIndex &c)
		{
			index_+=c.index_;
			return *this;
		}

		CInstructionIndex operator -(const CInstructionIndex &c)
		{
			return CInstructionIndex(index_-c.index_);
		}

		CInstructionIndex &operator -=(const CInstructionIndex &c)
		{
			index_-=c.index_;
			return *this;
		}

		CInstructionIndex operator +(const unsigned int c)
		{
			return CInstructionIndex(index_+c);
		}

		CInstructionIndex &operator +=(const unsigned int c)
		{
			index_+=c;
			return *this;
		}

		CInstructionIndex operator -(const unsigned int c)
		{
			return CInstructionIndex(index_-c);
		}

		CInstructionIndex &operator -=(const unsigned int c)
		{
			index_-=c;
			return *this;
		}

		CInstructionIndex &operator++()
		{
			index_++;
			return *this;
		}

		CInstructionIndex operator++(int)
		{
			index_++;
			return *this;
		}

		CInstructionIndex &operator=(unsigned int c)
		{
			index_=c;
			return *this;
		}

		CInstructionIndex &operator=(const CInstructionIndex &c)
		{
			index_=c.index_;
			return *this;
		}


		private:
		CInstructionIndex()
		{
			index_=0;
		}

		CInstructionIndex(unsigned int i)
		{
			index_=i;
		}

		unsigned int index_;
		friend class CKernel;
		friend class CNoiseExecutor;
	};
};

#endif
