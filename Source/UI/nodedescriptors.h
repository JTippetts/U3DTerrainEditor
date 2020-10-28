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

struct InstanceDesc
{
	String op_;
	unsigned int param_;
	String func_;
	std::vector<unsigned int> indices_;
	
	InstanceDesc(const String &op, unsigned int param) : op_(op), param_(param){}
	InstanceDesc(const String &op, const String &func, const std::vector<unsigned int> &ind) : op_(op), func_(func), indices_(ind){}
};

struct ValueInputsDesc
{
	bool used_;
	double value_;
	ValueInputsDesc() : used_(false), value_(0.0){}
	ValueInputsDesc(bool used, double value=0) : used_(used), value_(value){}
};

struct NodeTypeDesc
{
	String name_;
	std::vector<InputsDesc> inputs_;
	std::vector<InstanceDesc> instance_;
	std::vector<ValueInputsDesc> constants_;
	std::vector<ValueInputsDesc> seeds_;
};

std::vector<NodeTypeDesc> g_nodeTypes=
{
	{
		/*name_*/"constant",
		/*inputs_*/{
		},
		/*instance_*/{
			{"Function", "constant", {}}
		},
		/*constants_*/{
		},
		/*seeds_*/{
		}
	},
	
	{
		"seed",
		{
		},
		{
			{"Function", "seed", {}}
		},
		{
		},
		{
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
			{"Function", "add", {0,1}}
		},
		{
		},
		{
		}
	}
};
