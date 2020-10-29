#pragma once

#include <Urho3D/Core/Context.h>
#include <vector>

using namespace Urho3D;

//using ANLInstanceFunctype=std::function<CInstructionIndex(CKernel &, const std::vector<CInstructionIndex> &)>();
using ANLInstanceFuncType=CInstructionIndex (*)(CKernel &, const std::vector<CInstructionIndex> &);

struct InputsDesc
{
	String type_;
	String name_;
	double value_;
	
	InputsDesc() : value_(0.0){}
	InputsDesc(const String &type, const String &name, double value) : type_(type), name_(name), value_(value){}
};

struct IndicesInputsDesc
{
	bool used_;
	unsigned int index_;
	IndicesInputsDesc() : used_(false), index_(0){}
	IndicesInputsDesc(bool used, unsigned int index) : used_(used), index_(index){}
};

struct ValueInputsDesc
{
	bool used_;
	double value_;
	ValueInputsDesc() : used_(false), value_(0.0){}
	ValueInputsDesc(bool used, double value=0) : used_(used), value_(value){}
};

struct InstanceDesc
{
	String op_;
	unsigned int param_;
	String func_;
	std::vector<IndicesInputsDesc> indices_;
	std::vector<ValueInputsDesc> constants_;
	std::vector<ValueInputsDesc> seeds_;
	
	InstanceDesc(const String &op, unsigned int param) : op_(op), param_(param){}
	InstanceDesc(const String &op, const String &func, const std::vector<IndicesInputsDesc> &ind, const std::vector<ValueInputsDesc> &constants, const std::vector<ValueInputsDesc> &seeds) : op_(op), func_(func), indices_(ind), constants_(constants), seeds_(seeds){}
};

struct NodeTypeDesc
{
	String name_;
	std::vector<InputsDesc> inputs_;
	//std::vector<InstanceDesc> instance_;
	ANLInstanceFuncType instance_;
};

std::vector<NodeTypeDesc> g_nodeTypes=
{
	{
		"constant",
		{
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return CInstructionIndex();
		}
	},
	
	{
		"seed",
		{
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return CInstructionIndex();
		}
	},
	
	{
		"add",
		{
			{"value", "Value", 0.0},
			{"value", "Value", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.add(params[0], params[1]);
		}
	},
	
	{
		"subtract",
		{
			{"value", "Value", 0.0},
			{"value", "Value", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.subtract(params[0], params[1]);
		}
	},
	
	{
		"multiply",
		{
			{"value", "Value", 0.0},
			{"value", "Value", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.multiply(params[0], params[1]);
		}
	},
	
	{
		"divide",
		{
			{"value", "Value", 0.0},
			{"value", "Value", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.divide(params[0], params[1]);
		}
	},
	
	{
		"pow",
		{
			{"value", "Value", 0.0},
			{"value", "Exponent", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.pow(params[0], params[1]);
		}
	},
	
	{
		"minimum",
		{
			{"value", "Value", 0.0},
			{"value", "Value", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.minimum(params[0], params[1]);
		}
	},
	
	{
		"maximum",
		{
			{"value", "Value", 0.0},
			{"value", "Value", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.maximum(params[0], params[1]);
		}
	},
	
	{
		"bias",
		{
			{"value", "Bias", 0.0},
			{"value", "Value", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.bias(params[0], params[1]);
		}
	},
	
	{
		"gain",
		{
			{"value", "Gain", 0.0},
			{"value", "Value", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.gain(params[0], params[1]);
		}
	},
	
	{
		"scaleDomain",
		{
			{"value", "Value", 0.0},
			{"value", "Scale", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.scaleDomain(params[0], params[1]);
		}
	},
	
	{
		"scaleX",
		{
			{"value", "Value", 0.0},
			{"value", "Scale", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.scaleX(params[0], params[1]);
		}
	},
	
	{
		"scaleY",
		{
			{"value", "Value", 0.0},
			{"value", "Scale", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.scaleY(params[0], params[1]);
		}
	},
	
	{
		"translateDomain",
		{
			{"value", "Value", 0.0},
			{"value", "Translate", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.translateDomain(params[0], params[1]);
		}
	},
	
	{
		"translateX",
		{
			{"value", "Value", 0.0},
			{"value", "Translate", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.translateX(params[0], params[1]);
		}
	},
	{
		"valueBasis",
		{
			{"value", "Interp", 0.0},
			{"seed", "Seed", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.valueBasis(params[0], params[1]);
		}
	},
	
	{
		"gradientBasis",
		{
			{"value", "Interp", 0.0},
			{"value", "Seed", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.gradientBasis(params[0], params[1]);
		}
	},
	
	{
		"simplexBasis",
		{
			{"seed", "Seed", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.simplexBasis(params[0]);
		}
	},
	
	{
		"tiers",
		{
			{"value", "Value", 0.0},
			{"value", "Tiers", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.tiers(params[0], params[1]);
		}
	},
	
	{
		"smoothTiers",
		{
			{"value", "Value", 0.0},
			{"value", "Tiers", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.smoothTiers(params[0], params[1]);
		}
	},
	
	{
		"dx",
		{
			{"value", "Value", 0.0},
			{"value", "Spacing", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.dx(params[0], params[1]);
		}
	},
	
	{
		"dy",
		{
			{"value", "Value", 0.0},
			{"value", "Spacing", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.dy(params[0], params[1]);
		}
	},
	
	{
		"seeder",
		{
			{"value", "Seed", 0.0},
			{"value", "Value", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.seeder(params[0], params[1]);
		}
	},
	
	{
		"step",
		{
			{"value", "Value", 0.0},
			{"value", "Tiers", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.step(params[0], params[1]);
		}
	},
	
	{
		"abs",
		{
			{"value", "Value", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.abs(params[0]);
		}
	},
	
	{
		"sin",
		{
			{"value", "Value", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.sin(params[0]);
		}
	},
	
	{
		"cos",
		{
			{"value", "Value", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.cos(params[0]);
		}
	},
	
	{
		"tan",
		{
			{"value", "Value", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.tan(params[0]);
		}
	},
	
	{
		"asin",
		{
			{"value", "Value", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.asin(params[0]);
		}
	},
	
	{
		"acos",
		{
			{"value", "Value", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.acos(params[0]);
		}
	},
	
	{
		"atan",
		{
			{"value", "Value", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.atan(params[0]);
		}
	},
	
	{
		"sigmoid",
		{
			{"value", "Value", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.sigmoid(params[0]);
		}
	},
	
	{
		"x",
		{
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.x();
		}
	},
	
	{
		"y",
		{
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.y();
		}
	},
	
	{
		"radial",
		{
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.radial();
		}
	},
	
	{
		"mix",
		{
			{"value", "Low", 0.0},
			{"value", "High", 0.0},
			{"value", "Control", 0.0},
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.mix(params[0], params[1], params[2]);
		}
	},
	
	{
		"clamp",
		{
			{"value", "Low", 0.0},
			{"value", "High", 0.0},
			{"value", "Source", 0.0},
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.clamp(params[2], params[0], params[1]);
		}
	},
	
	{
		"linearStep",
		{
			{"value", "Low", 0.0},
			{"value", "High", 0.0},
			{"value", "Control", 0.0},
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.linearStep(params[0], params[1], params[2]);
		}
	},
	
	{
		"smoothStep",
		{
			{"value", "Low", 0.0},
			{"value", "High", 0.0},
			{"value", "Control", 0.0},
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.smoothStep(params[0], params[1], params[2]);
		}
	},
	
	{
		"smootherStep",
		{
			{"value", "Low", 0.0},
			{"value", "High", 0.0},
			{"value", "Control", 0.0},
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.smootherStep(params[0], params[1], params[2]);
		}
	},
	
	{
		"logistic",
		{
			{"value", "Low", 0.0},
			{"value", "High", 0.0},
			{"value", "Control", 0.0},
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.sigmoid(params[0], params[1], params[2]);
		}
	},
	
	{
		"randomize",
		{
			{"value", "Seed", 0.0},
			{"value", "Low", 0.0},
			{"value", "High", 0.0},
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.randomize(params[0], params[1], params[2]);
		}
	},
	
	{
		"fractal",
		{
			{"value", "Seed", 0.0},
			{"value", "Layer", 0.0},
			{"value", "Persistence", 0.5},
			{"value", "Lacunarity", 2.0},
			{"value", "Octaves", 8.0},
			{"value", "Frequency", 8.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.fractal(params[0], params[1], params[2], params[3], params[4], params[5]);
		}
	},
	
	{
		"cellularBasis",
		{
			{"value", "F1", -1.0},
			{"value", "F2", 1.0},
			{"value", "F3", 0.0},
			{"value", "F4", 0.0},
			{"value", "D1", 0.0},
			{"value", "D2", 0.0},
			{"value", "D3", 0.0},
			{"value", "D4", 0.0},
			{"value", "Distance", 0.0},
			{"value", "Seed", 0.0}
		},
		[](CKernel &k, const std::vector<CInstructionIndex> &params)->CInstructionIndex
		{
			return k.cellularBasis(params[0], params[1], params[2], params[3], params[4], params[5], params[6], params[7], params[8], params[9]);
		}
	},
	
	/*
	"combine",
			{
				
				"pow",
				"minimum",
				"maximum",
				"bias",
				"gain",
				"mix",
				"dx",
				"dy",
				"fractal"
			}
		},
		{
			"scalarmath",
			{
				"abs",
				"sin",
				"cos",
				"tan",
				"asin",
				"acos",
				"atan",
				"sigmoid",
				"randomize"
			}
		},
		{
			"step",
			{
				"step",
				"linearStep",
				"smoothStep",
				"smootherStep",
				"tiers",
				"smoothTiers",
				"curveSection",
			}
		},
		{
			"basis",
			{
				"valueBasis",
				"gradientBasis",
				"simplexBasis",
				"cellularBasis",
				"x",
				"y",
				"radial",
				"seeder"
			}
		},
		{
			"transform",
			{
				"scaleDomain",
				"scaleX",
				"scaleY",
				"translateDomain",
				"translateX",
				"translateY",
				"rotateDomain"
			}
		},
		{
			"color",
			{
				"combineRGBA",
				"combineHSVA"*/
};
