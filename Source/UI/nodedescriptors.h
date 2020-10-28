#pragma once

#include <Urho3D/Core/Context.h>
#include <vector>

using namespace Urho3D;

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
	std::vector<InstanceDesc> instance_;
};

std::vector<NodeTypeDesc> g_nodeTypes=
{
	{
		/*name_*/"constant",
		/*inputs_*/{
		},
		/*instance_*/{
			{"Function", "constant", {},{},{}}
		}
	},
	
	{
		"seed",
		{
		},
		{
			{"Function", "seed", {},{},{}}
		}
	},
	
	{
		"add",
		{
			{"value", "Value", 0.0},
			{"value", "Value", 0.0}
		},
		{
			{"Parameter", 0},
			{"Parameter", 1},
			{"Function", "add", {{true,0},{true,1}},{},{}}
		}
	}
};
