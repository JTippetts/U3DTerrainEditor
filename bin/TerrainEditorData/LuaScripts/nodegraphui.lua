-- Node-graph UI
-- Instance data
-- Consists of opcodes. 
-- If opcode=="Parameter" then get the specified input parameter.
-- If opcode=="Function" then instantiate the given ANL function, with the specified array indices

-- Testing
nodetypes=
{
	Constant=
	{
		inputs=
		{
		},
		instance={{op="Function", func="constant"}}
	},
	Seed=
	{
		inputs=
		{
		},
		instance={{op="Function", func="seed"}}
	},
	Add=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "Value", 0.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="add", indices={1,2}}}
	},
	Subtract=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "Value", 0.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="subtract", indices={1,2}}}
	},
	Multiply=
	{
		inputs=
		{
			{"value", "Value", 1.0},
			{"value", "Value", 1.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="multiply", indices={1,2}}}
	},
	Divide=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "Value", 1.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="divide", indices={1,2}}}
	},
	Pow=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "Value", 1.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="pow", indices={1,2}}}
	},
	Minimum=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "Value", 0.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="minimum", indices={1,2}}}
	},
	Maximum=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "Value", 0.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="maximum", indices={1,2}}}
	},
	Bias=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "Bias", 0.5},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="bias", indices={1,2}}}
	},
	Gain=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "Gain", 0.5},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="gain", indices={1,2}}}
	},
	Step=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "Threshold", 0.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="step", indices={1,2}}}
	},
	LinearStep=
	{
		inputs=
		{
			{"value", "Low", 0.0},
			{"value", "High", 1.0},
			{"value", "Control", 0.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Parameter", param=3}, {op="Function", func="linearStep", indices={1,2,3}}}
	},
	SmoothStep=
	{
		inputs=
		{
			{"value", "Low", 0.0},
			{"value", "High", 1.0},
			{"value", "Control", 0.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Parameter", param=3}, {op="Function", func="smoothStep", indices={1,2,3}}}
	},
	SmootherStep=
	{
		inputs=
		{
			{"value", "Low", 0.0},
			{"value", "High", 1.0},
			{"value", "Control", 0.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Parameter", param=3}, {op="Function", func="smootherStep", indices={1,2,3}}}
	},
	Abs=
	{
		inputs=
		{
			{"value","Value",0.0}
		},
		instance={{op="Parameter", param=1}, {op="Function", func="abs", indices={1}}}
	},
	Sin=
	{
		inputs=
		{
			{"value","Value",0.0}
		},
		instance={{op="Parameter", param=1}, {op="Function", func="sin", indices={1}}}
	},
	Cos=
	{
		inputs=
		{
			{"value","Value",0.0}
		},
		instance={{op="Parameter", param=1}, {op="Function", func="cos", indices={1}}}
	},
	Tan=
	{
		inputs=
		{
			{"value","Value",0.0}
		},
		instance={{op="Parameter", param=1}, {op="Function", func="tan", indices={1}}}
	},
	ASin=
	{
		inputs=
		{
			{"value","Value",0.0}
		},
		instance={{op="Parameter", param=1}, {op="Function", func="asin", indices={1}}}
	},
	ACos=
	{
		inputs=
		{
			{"value","Value",0.0}
		},
		instance={{op="Parameter", param=1}, {op="Function", func="acos", indices={1}}}
	},
	ATan=
	{
		inputs=
		{
			{"value","Value",0.0}
		},
		instance={{op="Parameter", param=1}, {op="Function", func="atan", indices={1}}}
	},
	X=
	{
		inputs=
		{
		},
		instance={{op="Function", func="x", indices={}}}
	},
	Y=
	{
		inputs=
		{
		},
		instance={{op="Function", func="y", indices={}}}
	},
	dX=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "Spacing", 0.01},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="dX", indices={1,2}}}
	},
	dY=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "Spacing", 0.01},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="dY", indices={1,2}}}
	},
	Tiers=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "NumTiers", 1.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="tiers", indices={1,2}}}
	},
	SmoothTiers=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "NumTiers", 1.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="smoothTiers", indices={1,2}}}
	},
	TranslateDomain=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "Amount", 0.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="translateDomain", indices={1,2}}}
	},
	TranslateX=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "Amount", 0.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="translateX", indices={1,2}}}
	},
	TranslateY=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "Amount", 1.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="translateY", indices={1,2}}}
	},
	ScaleDomain=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "Amount", 1.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="scaleDomain", indices={1,2}}}
	},
	ScaleX=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "Amount", 1.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="scaleX", indices={1,2}}}
	},
	ScaleY=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "Amount", 1.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="scaleY", indices={1,2}}}
	},
	RotateDomain=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "Angle", 1.0},
			{"value", "AxisX", 0.0},
			{"value", "AxisY", 0.0},
			{"value", "Axisz", 1.0}
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Parameter", param=3}, {op="Parameter", param=4}, {op="Parameter", param=5},
				{op="Function", func="rotateDomain", indices={1,2,3,4,5}}}
	},
	Mix=
	{
		inputs=
		{
			{"value", "Control", 0.5},
			{"value", "Low", 0.0},
			{"value", "High", 1.0}
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Parameter", param=3}, {op="Function", func="mix", indices={1,2,3}}}
	},
	Seeder=
	{
		inputs=
		{
			{"value", "Input", 0.0},
			{"seed", "Seed", 45678},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="seeder", indices={1,2}}}
	},
	Sigmoid=
	{
		inputs=
		{
			{"value", "Value", 0.0},
			{"value", "Center", 0.0},
			{"value", "Ramp", 1.0}
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Parameter", param=3}, {op="Function", func="sigmoid", indices={1,2,3}}}
	},
	Randomize=
	{
		inputs=
		{
			{"seed", "Seed", 17892},
			{"value", "Low", 0.0},
			{"value", "High", 1.0}
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Parameter", param=3}, {op="Function", func="randomize", indices={1,2,3}}}
	},
	Fractal=
	{
		inputs=
		{
			{"seed", "Seed", 17892},
			{"value", "Layer", 0.0},
			{"value", "Persistence", 0.5},
			{"value", "Lacunarity", 2.0},
			{"value", "Octaves", 8},
			{"value", "Frequency", 1.0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Parameter", param=3}, {op="Parameter", param=4}, {op="Parameter", param=5},
				{op="Parameter", param=6}, {op="Function", func="fractal", indices={1,2,3,4,5,6}}}
	},
	CellularBasis=
	{
		inputs=
		{
			{"seed", "Seed", 91234},
			{"value", "F1", -1.0},
			{"value", "F2", 1.0},
			{"value", "F3", 0.0},
			{"value", "F4", 0.0},
			{"value", "D1", 0.0},
			{"value", "D2", 0.0},
			{"value", "D3", 0.0},
			{"value", "D4", 0.0},
			{"value", "Distance Func", 0},
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Parameter", param=3}, {op="Parameter", param=4}, {op="Parameter", param=5},
				{op="Parameter", param=6}, {op="Parameter", param=7}, {op="Parameter", param=8}, {op="Parameter", param=9}, {op="Parameter", param=10},
				{op="Function", func="fractal", indices={1,2,3,4,5,6,7,8,9,10}}}
	},
	ValueBasis=
	{
		inputs=
		{
			{"seed", "Seed", 147234},
			{"value", "Interpolation", 3}
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="valueBasis", indices={1,2}}}
	},
	GradientBasis=
	{
		inputs=
		{
			{"seed", "Seed", 148234},
			{"value", "Interpolation", 3}
		},
		instance={{op="Parameter", param=1}, {op="Parameter", param=2}, {op="Function", func="gradientBasis", indices={1,2}}}
	},
	SimplexBasis=
	{
		inputs=
		{
			{"seed", "Seed", 7120345}
		},
		instance={{op="Parameter", param=1}, {op="Function", func="simplexBasis", indices={1}}}
	},
	Radial=
	{
		inputs=
		{
		},
		instance={{op="Function", func="radial", indices={}}}
	}
	
}

function InstanceFunction(k, desc, params)
	local ins=desc.instance
	if not ins then return end
	
	local n={}
	local c
	for _,c in ipairs(ins) do
		if c.op=="Parameter" then
			table.insert(n, params[c.param])
		elseif c.op=="Function" then
			local indices=c.indices
			
			print("Function name: "..c.func)
			
			if c.func=="add" then
				table.insert(n, k:add(n[indices[1]], n[indices[2]]))
			elseif c.func=="subtract" then
				table.insert(n, k:subtract(n[indices[1]], n[indices[2]]))
			elseif c.func=="multiply" then
				table.insert(n, k:multiply(n[indices[1]], n[indices[2]]))
			elseif c.func=="divide" then
				table.insert(n, k:divide(n[indices[1]], n[indices[2]]))
			elseif c.func=="subtract" then
				table.insert(n, k:subtract(n[indices[1]], n[indices[2]]))
			elseif c.func=="minimum" then
				table.insert(n, k:minimum(n[indices[1]], n[indices[2]]))
			elseif c.func=="maximum" then
				table.insert(n, k:maximum(n[indices[1]], n[indices[2]]))
			elseif c.func=="bias" then
				table.insert(n, k:bias(n[indices[1]], n[indices[2]]))
			elseif c.func=="gain" then
				table.insert(n, k:gain(n[indices[1]], n[indices[2]]))
			elseif c.func=="step" then
				table.insert(n, k:step(n[indices[1]], n[indices[2]]))
			elseif c.func=="linearStep" then
				table.insert(n, k:linearStep(n[indices[1]], n[indices[2]], n[indices[3]]))
			elseif c.func=="smoothStep" then
				table.insert(n, k:smoothStep(n[indices[1]], n[indices[2]], n[indices[3]]))
			elseif c.func=="smootherStep" then
				table.insert(n, k:smootherStep(n[indices[1]], n[indices[2]], n[indices[3]]))
			elseif c.func=="abs" then
				table.insert(n, k:abs(n[indices[1]]))
			elseif c.func=="sin" then
				table.insert(n, k:sin(n[indices[1]]))
			elseif c.func=="cos" then
				table.insert(n, k:cos(n[indices[1]]))
			elseif c.func=="tan" then
				table.insert(n, k:tan(n[indices[1]]))
			elseif c.func=="asin" then
				table.insert(n, k:asin(n[indices[1]]))
			elseif c.func=="acos" then
				table.insert(n, k:acos(n[indices[1]]))
			elseif c.func=="atan" then
				table.insert(n, k:atan(n[indices[1]]))
			elseif c.func=="x" then
				table.insert(n, k:x())
			elseif c.func=="y" then
				table.insert(n, k:y())
			elseif c.func=="radial" then
				table.insert(n, k:radial())
			elseif c.func=="dX" then
				table.insert(n, k:dx(n[indices[1]], n[indices[2]]))
			elseif c.func=="dY" then
				table.insert(n, k:dy(n[indices[1]], n[indices[2]]))
			elseif c.func=="smoothTiers" then
				table.insert(n, k:smoothTiers(n[indices[1]], n[indices[2]]))
			elseif c.func=="tiers" then
				table.insert(n, k:tiers(n[indices[1]], n[indices[2]]))
			elseif c.func=="translateDomain" then
				table.insert(n, k:translateDomain(n[indices[1]], n[indices[2]]))
			elseif c.func=="translateX" then
				table.insert(n, k:translateX(n[indices[1]], n[indices[2]]))
			elseif c.func=="translateY" then
				table.insert(n, k:translateY(n[indices[1]], n[indices[2]]))
			elseif c.func=="scaleDomain" then
				table.insert(n, k:scaleDomain(n[indices[1]], n[indices[2]]))
			elseif c.func=="scaleX" then
				table.insert(n, k:scaleX(n[indices[1]], n[indices[2]]))
			elseif c.func=="scaleY" then
				table.insert(n, k:scaleY(n[indices[1]], n[indices[2]]))
			elseif c.func=="rotateDomain" then
				table.insert(n, k:rotateDomain(n[indices[1]], n[indices[2]], n[indices[3]], n[indices[4]], n[indices[5]]))
			elseif c.func=="mix" then
				table.insert(n, k:mix(n[indices[1]], n[indices[2]], n[indices[3]]))
			elseif c.func=="seeder" then
				table.insert(n, k:seeder(n[indices[1]], n[indices[2]]))
			elseif c.func=="sigmoid" then
				table.insert(n, k:sigmoid(n[indices[1]], n[indices[2]], n[indices[3]]))
			elseif c.func=="randomize" then
				table.insert(n, k:randomize(n[indices[1]], n[indices[2]], n[indices[3]]))
			elseif c.func=="fractal" then
				table.insert(n, k:fractal(n[indices[1]], n[indices[2]], n[indices[3]], n[indices[4]], n[indices[5]], n[indices[6]]))
			elseif c.func=="cellularBasis" then
				table.insert(n, k:cellularBasis(n[indices[1]], n[indices[2]], n[indices[3]], n[indices[4]], n[indices[5]], n[indices[6]], n[indices[7]], n[indices[8]], n[indices[9]], n[indices[10]]))
			elseif c.func=="valueBasis" then
				print("hihihih")
				table.insert(n, k:valueBasis(n[indices[1]], n[indices[2]]))
			elseif c.func=="gradientBasis" then
				table.insert(n, k:gradientBasis(n[indices[1]], n[indices[2]]))
			elseif c.func=="simplexBasis" then
				table.insert(n, k:simplexBasis(n[indices[1]]))
			else
				print("wut")
			end
		end
	end
	print(k:lastIndex())
	return k:lastIndex()
end

nodecategories=
{
	{
		categoryname="Constants",
		nodetypes=
		{
			{
				name="Constant",
				valuename="Constant",
				inputs={}
			},
			{
				name="Seed",
				valuename="Seed",
				inputs={}
			}
		}
	},
	
	{
		categoryname="Arithmetic",
		nodetypes=
		{
			{
				name="Add",
				inputs=
				{
					{"value", "Value", 0.0},
					{"value", "Value", 0.0},
				}
			},
			{
				name="Subtract",
				inputs=
				{
					{"value", "Value", 0.0},
					{"value", "Value", 0.0},
				}
			},
			{
				name="Multiply",
				inputs=
				{
					{"value", "Value", 0.0},
					{"value", "Value", 1.0},
				}
			},
			{
				name="Divide",
				inputs=
				{
					{"value", "Value", 0.0},
					{"value", "Value", 1.0},
				}
			},
			{
				name="Pow",
				inputs=
				{
					{"value", "Value", 0.0},
					{"value", "Value", 1.0},
				}
			},
			{
				name="Minimum",
				inputs=
				{
					{"value", "Value", 0.0},
					{"value", "Value", 0.0},
				}
			},
			{
				name="Maximum",
				inputs=
				{
					{"value", "Value", 0.0},
					{"value", "Value", 0.0},
				}
			},
			{
				name="Bias",
				inputs=
				{
					{"value", "Value", 0.0},
					{"value", "Value", 0.5},
				}
			},
			{
				name="Gain",
				inputs=
				{
					{"value", "Value", 0.0},
					{"value", "Value", 0.5},
				}
			},
			{
				name="Step",
				inputs=
				{
					{"value", "Value", 0.0},
					{"value", "Value", 0.0},
				}
			},
		}
	},

	{
		categoryname="Basis Functions",
		nodetypes=
		{
			{
				name="Gradient Basis",
				inputs=
				{
					{"value", "Interp Function", 3},
					{"seed", "Seed", 12345}
				}
			},
		}
	},
}

function CreateMenuItem(title)
	local menu=Menu:new(title)
	menu:SetAutoStyle(cache:GetResource("XMLFile", "UI/DefaultStyle.xml"))
	menu:SetLayout(LM_HORIZONTAL, 0, IntRect(8,2,8,2))
	
	local text=menu:CreateChild("Text")
	text:SetStyle("EditorMenuText", cache:GetResource("XMLFile", "UI/DefaultStyle.xml"))
	text.text=title
	
	return menu
end

function CreatePopup(baseMenu)
	local popup=Window:new()
	popup:SetStyleAuto(cache:GetResource("XMLFile", "UI/DefaultStyle.xml"))
	popup:SetLayout(LM_VERTICAL, 1, IntRect(2,6,2,6))
	baseMenu.popup=popup
	baseMenu.popupOffset = IntBector2(0,baseMenu.height)
	return popup
end

function CreateMenu(title)
	local menu=CreateMenuItem(title)
	local text=menu.children[1]
	menu.maxWidth=text.width+20
	CreatePopup(menu)
	return menu
end


function CreateNodeCreateMenu(parent)
	local menu=ui:LoadLayout(cache:GetResource("XMLFile", "UI/CreateNodeMenu.xml"))
	
end

function CreateNodeType(parent, type)
	if type=="Seed" then
		local node=ui:LoadLayout(cache:GetResource("XMLFile", "UI/SeedNode.xml"))
		parent:AddChild(node)
		return node
	elseif type=="Constant" then
		local node=ui:LoadLayout(cache:GetResource("XMLFIle", "UI/ConstantNode.xml"))
		parent:AddChild(node)
		return node
	end
	
	local d=nodetypes[type]
	if not d then return end
	
	local node=ui:LoadLayout(cache:GetResource("XMLFile", "UI/NodeTemplate.xml"))
	node.name=type
	parent:AddChild(node)
	node:GetChild("Title",true).text=type
	
	local c
	local inputs=node:GetChild("Inputs", true)
	
	for c=1,#d.inputs,1 do
		local input=inputs:CreateChild("UIElement")
		input.name=d.inputs[c][1]
		input:SetLayout(LM_HORIZONTAL)
		local e=input:CreateChild("NodeGraphLinkDest")
		e.name="Input"..(c-1)
		e:SetMinSize(12,12)
		e:SetMaxSize(12,12)
		e:SetImageRect(IntRect(16,0,32,16))
		e.texture=cache:GetResource("Texture2D", "Textures/UI.png")
		
		e=input:CreateChild("LineEdit")
		e.name="Value"..(c-1)
		e:SetStyleAuto(cache:GetResource("XMLFile", "UI/DefaultStyle.xml"))
		e:GetTextElement().fontSize=9
		e:SetText(d.inputs[c][3])
		e:SetMinSize(40,12)
		e:SetMaxSize(40,12)
		
		e=input:CreateChild("Text")
		e:SetStyleAuto(cache:GetResource("XMLFile", "UI/DefaultStyle.xml"))
		e.fontSize=9
		e.text=tostring(d.inputs[c][2])
	end
	return node
	
end

function GetSourceFromNode(node, inputname)
	local c=node:GetChild(inputname,true)
	if c then
		local link=c:GetLink()
		if link then
			local src=link:GetSource()
			if src then
				return src:GetRoot()
			end
		end
	end
	return false
end


function PackNodeGraph(output)
	local nodes={}
	local kernelindices={}
	local isvisited=function(n)
		local c
		for _,c in ipairs(nodes) do
			if c==n then return true end
		end
		return false
	end
	
	local nodeindex=function(n)
		local i,c
		for i,c in ipairs(nodes) do
			if c==n then return i end
		end
		return false
	end
	
	function InstanceANLFunction(kernel, n)
		local GetValue=function(n,which)
			local s=GetSourceFromNode(n,"Input"..which)
			local s1
			if s then s1=kernelindices[nodeindex(s)]
			else local c=tonumber(n:GetChild("Value"..which,true).text) or 1.0 s1=kernel:constant(c) print("Value: "..c) end
			return s1
		end
		
		local GetSeed=function(n,which)
			local s=GetSourceFromNode(n,"Input"..which)
			local s1
			if s then s1=kernelindices[nodeindex(s)]
			else local c=tonumber(n:GetChild("Value"..which,true).text) or 12345 s1=kernel:seed(c) print("Seed: "..c) end
			return s1
		end
		
		local desc=nodetypes[n.name]
		if not desc then return end
		local numinputs=#desc.inputs
		local c
		local params={}
		for c=1,numinputs,1 do
			table.insert(params, GetValue(n,c-1))
		end

		
		if n.name=="Output" then
			local s1
			local s1=GetValue(n,0)
			return s1
		else
			print("Instance function "..n.name)
			return InstanceFunction(kernel, desc, params)
		end
		--[[
		elseif n.name=="Arithmetic" then
			local s1,s2=GetValue(n,0),GetValue(n,1)
			local op=n:GetChild("TypeList",true).selection
			if op==0 then return kernel:multiply(s1,s2)
			elseif op==1 then return kernel:add(s1,s2)
			elseif op==2 then return kernel:subtract(s1,s2)
			elseif op==3 then return kernel:divide(s1,s2)
			elseif op==4 then return kernel:pow(s1,s2)
			elseif op==5 then return kernel:minimum(s1,s2)
			elseif op==6 then return kernel:maximum(s1,s2)
			elseif op==7 then return kernel:bias(s1,s2)
			elseif op==8 then return kernel:gain(s1,s2)
			elseif op==9 then return kernel:step(s2,s1)
			end
		elseif n.name=="TranslateDomain" then
			local s1,s2=GetValue(n,0),GetValue(n,1)
			local op=n:GetChild("TypeList",true).selection
			if op==0 then return kernel:translateDomain(s1,s2)
			elseif op==1 then return kernel:translateX(s1,s2)
			elseif op==2 then return kernel:translateY(s1,s2)
			elseif op==3 then return kernel:translateZ(s1,s2)
			elseif op==4 then return kernel:translateW(s1,s2)
			elseif op==5 then return kernel:translateU(s1,s2)
			elseif op==6 then return kernel:translateV(s1,s2)
			end
		elseif n.name=="ScaleDomain" then
			local s1,s2=GetValue(n,0),GetValue(n,1)
			local op=n:GetChild("TypeList",true).selection
			if op==0 then return kernel:scaleDomain(s1,s2)
			elseif op==1 then return kernel:scaleX(s1,s2)
			elseif op==2 then return kernel:scaleY(s1,s2)
			elseif op==3 then return kernel:scaleZ(s1,s2)
			elseif op==4 then return kernel:scaleW(s1,s2)
			elseif op==5 then return kernel:scaleU(s1,s2)
			elseif op==6 then return kernel:scaleV(s1,s2)
			end
		elseif n.name=="Tiers" then
			local s1,s2=GetValue(n,0),GetValue(n,1)
			local smooth=n:GetChild("SmoothCheck",true).checked
			if smooth then
				return kernel:smoothTiers(s1,s2)
			else
				return kernel:tiers(s1,s2)
			end
		elseif n.name=="ValueBasis" then
			local s1,s2=GetValue(n,0),GetSeed(n,1)
			
			return kernel:valueBasis(s1,s2)
		elseif n.name=="SimplexBasis" then
			local s1=GetSeed(n,0)
			
			return kernel:simplexBasis(s1)
		elseif n.name=="GradientBasis" then
			local s1,s2=GetValue(n,0),GetSeed(n,1)
			
			return kernel:gradientBasis(s1,s2)
		elseif n.name=="ScalarMath" then
			local s1=GetValue(n,0)
			local op=n:GetChild("TypeList",true).selection
			if op==0 then return kernel:abs(s1)
			elseif op==1 then return kernel:cos(s1)
			elseif op==2 then return kernel:sin(s1)
			elseif op==3 then return kernel:tan(s1)
			elseif op==4 then return kernel:acos(s1)
			elseif op==5 then return kernel:asin(s1)
			elseif op==6 then return kernel:atan(s1)
			end
		elseif n.name=="CoordinateSource" then
			local op=n:GetChild("TypeList",true).selection
			if op==0 then return kernel:x()
			elseif op==1 then return kernel:y()
			elseif op==2 then return kernel:z()
			elseif op==3 then return kernel:w()
			elseif op==4 then return kernel:u()
			elseif op==5 then return kernel:v()
			elseif op==6 then return kernel:radial()
			end
		elseif n.name=="Constant" then
			local val=tonumber(n:GetChild("Value",true).text)
			return kernel:constant(val)
		elseif n.name=="Seed" then
			local val=tonumber(n:GetChild("Value",true).text)
			return kernel:seed(val)
		elseif n.name=="Derivative" then
			local s1,s2=GetValue(n,0),GetValue(n,1)
			local op=n:GetChild("TypeList",true).selection
			if op==0 then return kernel:dx(s1,s2)
			elseif op==1 then return kernel:dy(s1,s2)
			elseif op==2 then return kernel:dz(s1,s2)
			elseif op==3 then return kernel:dw(s1,s2)
			elseif op==4 then return kernel:du(s1,s2)
			elseif op==5 then return kernel:dv(s1,s2)
			end
		elseif n.name=="Fractal" then
			local s1,s2,s3,s4,s5,s6=GetSeed(n,0),GetValue(n,1),GetValue(n,2),GetValue(n,3),GetValue(n,4),GetValue(n,5)
			
			return kernel:fractal(s1,s2,s3,s4,s5,s6)
		elseif n.name=="RotateDomain" then
			local s1,s2,s3,s4,s5=GetValue(n,0),GetValue(n,1),GetValue(n,2),GetValue(n,3),GetValue(n,4)
			return kernel:rotateDomain(s1,s2,s3,s4,s5)
		elseif n.name=="Randomize" then
			local s1,s2,s3=GetSeed(n,0),GetValue(n,1),GetValue(n,2)
			return kernel:randomize(s1,s2,s3)
		elseif n.name=="SmoothStep" then
			local s1,s2,s3=GetValue(n,0),GetValue(n,1),GetValue(n,2)
			local op=n:GetChild("TypeList",true).selection
			if op==0 then return kernel:linearStep(s2,s3,s1)
			elseif op==1 then return kernel:smoothStep(s2,s3,s1)
			elseif op==2 then return kernel:smootherStep(s2,s3,s1)
			end
		elseif n.name=="Mix" then
			local s1,s2,s3=GetValue(n,0),GetValue(n,1),GetValue(n,2)
			return kernel:mix(s2,s3,s1)
		elseif n.name=="Expression" then
			local eb=CExpressionBuilder(kernel)
			local exp=n:GetChild("Value",true).text
			eb:eval(exp)
			return kernel:lastIndex()
		elseif n.name=="Seeder" then
			--local val=tonumber(n:GetChild("Seed",true).text)
			local s1,s2=GetSeed(n,0),GetValue(n,1)
			return kernel:seeder(s1,s2)
		elseif n.name=="Cellular" then
			local s1,s2,s3,s4,s5,s6,s7,s8,s9,s10=GetSeed(n,0),GetValue(n,1),GetValue(n,2),GetValue(n,3),GetValue(n,4),GetValue(n,5),GetValue(n,6),GetValue(n,7),GetValue(n,8),GetValue(n,9)
			return kernel:cellularBasis(s2,s3,s4,s5,s6,s7,s8,s9,s10,s1)
		elseif n.name=="Sigmoid" then
			local s1,s2,s3=GetValue(n,0),GetValue(n,1),GetValue(n,2)
			return kernel:sigmoid(s1,s2,s3)
		end]]
	end
	
	local kernel=CKernel()
	
	
	
	worker=function(n)
		local visitnode=function(n,numparms)
			local s,c
			for c=0,numparms-1,1 do
				s=GetSourceFromNode(n,"Input"..c)
				if s and not isvisited(s) then worker(s) end
			end
		end
		
		if n.name~="Output" then
			local desc=nodetypes[n.name]
			if not desc then print(n.name.." Doesn't exist") return false end
		
			local numinputs=#desc.inputs
			if numinputs>0 then
				visitnode(n, numinputs)
			end
		else
			visitnode(n,1)
		end
		
		--[[
		if n.name=="Arithmetic" or n.name=="Derivative" or n.name=="Tiers" or n.name=="ValueBasis" or n.name=="GradientBasis" or n.name=="TranslateDomain" or n.name=="ScaleDomain" or
			n.name=="Seeder" then
			visitnode(n,2)
		elseif n.name=="ScalarMath" or n.name=="Output" or n.name=="SimplexBasis" then
			visitnode(n,1)
		elseif n.name=="RotateDomain" then
			visitnode(n,5)
		elseif n.name=="Fractal" then
			visitnode(n,6)
		elseif n.name=="Randomize" or n.name=="SmoothStep" or n.name=="Mix" then
			visitnode(n,3)
		elseif n.name=="Cellular" then
			visitnode(n,10)
		elseif n.name=="Sigmoid" then
			visitnode(n,3)
		end
		]]
		table.insert(nodes,n)
		local ind=InstanceANLFunction(kernel, n)
		print("ind: "..type(ind))
		table.insert(kernelindices, ind)
	end
	print("Packing node graph.")
	
	worker(output)
	local c
	for _,c in ipairs(nodes) do print(c.name) end
	return kernel
end

NodeGraphUI=ScriptObject()

function NodeGraphUI:Start()
	self.createnodemenu=ui:LoadLayout(cache:GetResource("XMLFile", "UI/CreateNodeMenu.xml"))
	--self.pane:AddChild(self.createnodemenu)
	
	self.pane=ui.root:CreateChild("UIElement")
	self.pane:SetSize(graphics.width, graphics.height)
	
	--[[self:SubscribeToEvent(self.createnodemenu:GetChild("Arithmetic", true), "Pressed", "NodeGraphUI:HandleCreateNode")
	self:SubscribeToEvent(self.createnodemenu:GetChild("ScalarMath", true), "Pressed", "NodeGraphUI:HandleCreateNode")
	self:SubscribeToEvent(self.createnodemenu:GetChild("Constant", true), "Pressed", "NodeGraphUI:HandleCreateNode")
	self:SubscribeToEvent(self.createnodemenu:GetChild("Seed", true), "Pressed", "NodeGraphUI:HandleCreateNode")
	self:SubscribeToEvent(self.createnodemenu:GetChild("CoordSource", true), "Pressed", "NodeGraphUI:HandleCreateNode")
	self:SubscribeToEvent(self.createnodemenu:GetChild("Derivative", true), "Pressed", "NodeGraphUI:HandleCreateNode")
	self:SubscribeToEvent(self.createnodemenu:GetChild("Tiers", true), "Pressed", "NodeGraphUI:HandleCreateNode")
	self:SubscribeToEvent(self.createnodemenu:GetChild("ValueBasis", true), "Pressed", "NodeGraphUI:HandleCreateNode")
	self:SubscribeToEvent(self.createnodemenu:GetChild("GradientBasis", true), "Pressed", "NodeGraphUI:HandleCreateNode")
	self:SubscribeToEvent(self.createnodemenu:GetChild("SimplexBasis", true), "Pressed", "NodeGraphUI:HandleCreateNode")
	self:SubscribeToEvent(self.createnodemenu:GetChild("TranslateDomain", true), "Pressed", "NodeGraphUI:HandleCreateNode")
	self:SubscribeToEvent(self.createnodemenu:GetChild("ScaleDomain", true), "Pressed", "NodeGraphUI:HandleCreateNode")
	self:SubscribeToEvent(self.createnodemenu:GetChild("Fractal", true), "Pressed", "NodeGraphUI:HandleCreateNode")
	self:SubscribeToEvent(self.createnodemenu:GetChild("RotateDomain", true), "Pressed", "NodeGraphUI:HandleCreateNode")
	self:SubscribeToEvent(self.createnodemenu:GetChild("Randomize", true), "Pressed", "NodeGraphUI:HandleCreateNode")
	self:SubscribeToEvent(self.createnodemenu:GetChild("SmoothStep", true), "Pressed", "NodeGraphUI:HandleCreateNode")
	self:SubscribeToEvent(self.createnodemenu:GetChild("Mix", true), "Pressed", "NodeGraphUI:HandleCreateNode")
	self:SubscribeToEvent(self.createnodemenu:GetChild("Expression", true), "Pressed", "NodeGraphUI:HandleCreateNode")
	self:SubscribeToEvent(self.createnodemenu:GetChild("Seeder", true), "Pressed", "NodeGraphUI:HandleCreateNode")
	self:SubscribeToEvent(self.createnodemenu:GetChild("Cellular", true), "Pressed", "NodeGraphUI:HandleCreateNode") 
	self:SubscribeToEvent(self.createnodemenu:GetChild("Sigmoid", true), "Pressed", "NodeGraphUI:HandleCreateNode")]]
	
	local tp
	for tp,_ in pairs(nodetypes) do
		self:SubscribeToEvent(self.createnodemenu:GetChild(tp,true),"Pressed", "NodeGraphUI:HandleCreateNode")
	end
	
	self.createnodemenu.visible=false
	
	local cnmclose=self.createnodemenu:GetChild("Close", true)
	self:SubscribeToEvent(cnmclose, "Pressed", "NodeGraphUI:HandleCloseCreateNodeMenu")
	
	self.nodegroup=nil
	self.cursortarget=cursor:CreateChild("NodeGraphLinkDest")
	
end

function NodeGraphUI:CreateNodeGroup()
	local nodegroup=
	{
		nodes={}
	}
	nodegroup.pane=self.pane:CreateChild("Window")
	nodegroup.pane.size=IntVector2(graphics.width*2, graphics.height*2)
	nodegroup.pane.position=IntVector2(-graphics.width/2, -graphics.height/2)
	nodegroup.pane:SetImageRect(IntRect(208,0,223,15))
	nodegroup.pane:SetImageBorder(IntRect(4,4,4,4))
	nodegroup.pane:SetTexture(cache:GetResource("Texture2D", "Textures/UI.png"))
	nodegroup.pane.opacity=0.75
	nodegroup.pane.bringToFront=true
	nodegroup.pane.movable=true
	nodegroup.pane.clipChildren=false
	nodegroup.pane:SetDefaultStyle(cache:GetResource("XMLFile", "UI/NodeStyle.xml"))
	
	nodegroup.linkpane=nodegroup.pane:CreateChild("NodeGraphLinkPane")
	nodegroup.linkpane.size=IntVector2(graphics.width*2, graphics.height*2)
	nodegroup.linkpane.visible=true
	nodegroup.linkpane.texture=cache:GetResource("Texture2D", "Data/Textures/UI.png")
	
	nodegroup.previewtex=Texture2D:new()
	nodegroup.previewimg=Image()
	nodegroup.previewimg:SetSize(256,256,3)
	nodegroup.previewimg:Clear(Color(0,0,0))
	nodegroup.previewtex:SetData(nodegroup.previewimg,false)
	
	nodegroup.output=self:OutputNode(nodegroup)
	nodegroup.output.position=IntVector2(-nodegroup.pane.position.x + graphics.width-nodegroup.output.width, -nodegroup.pane.position.y + graphics.height/4)
	
	nodegroup.output:GetChild("Preview",true).texture=nodegroup.previewtex
	
	list=nodegroup.output:GetChild("TargetList",true)
	local smtypes=
	{
		"Terrain",
		"Layer 1",
		"Layer 2",
		"Layer 3",
		"Layer 4",
		"Layer 5",
		"Layer 6",
		"Layer 7",
		"Layer 8",
		"Mask 1",
		"Mask 2",
		"Mask 3"
	}
	
	local c
	for _,c in ipairs(smtypes) do
		local t=Text:new(context)
		t:SetFont(cache:GetResource("Font", "Fonts/Anonymous Pro.ttf"), 9)
		t.text=c
		t.color=Color(1,1,1)
		t.minSize=IntVector2(0,16)
		list:AddItem(t)
	end
	list.selection=0
	
	nodegroup.pane:AddChild(self.createnodemenu)
	
	self:SubscribeToEvent(nodegroup.output:GetChild("Generate",true),"Pressed","NodeGraphUI:HandleGenerate")
	self:SubscribeToEvent(nodegroup.output:GetChild("Execute",true),"Pressed","NodeGraphUI:HandleExecute")
	nodegroup.pane.visible=false
	return nodegroup
end

function NodeGraphUI:Activate(nodegroup)
	if self.nodegroup then
		nodegroup.pane.visible=false
		nodegroup.pane.focus=false
		
	end
	self.nodegroup=nodegroup
	nodegroup.pane.visible=true
	nodegroup.pane.focus=true
	nodegroup.pane:AddChild(self.createnodemenu)
	self.createnodemenu.visible=true
	self.createnodemenu.position=IntVector2(-self.nodegroup.pane.position.x,-self.nodegroup.pane.position.y+graphics.height-self.createnodemenu.height)
	
	self.closetext=self.pane:CreateChild("Text")
	self.closetext:SetStyle("Text", cache:GetResource("XMLFile","UI/DefaultStyle.xml"))
	self.closetext:SetFontSize(20)
	self.closetext.text="Press 'M' to close window."
end

function NodeGraphUI:Deactivate()
	if self.nodegroup then
		self.nodegroup.pane.visible=false
		self.nodegroup.pane.focus=false
		if self.closetext then self.closetext:Remove() self.closetext=nil end
	end
end


function NodeGraphUI:HandleCloseCreateNodeMenu(eventType, eventData)
	self.createnodemenu.visible=false
end

function NodeGraphUI:HandleCreateNode(eventType, eventData)
	if not self.nodegroup then return end
	local e=eventData["Element"]:GetPtr("UIElement")
	if not e then return end
	local n
	--[[if e.name=="Arithmetic" then n=self:ArithmeticNode(self.nodegroup)
	elseif e.name=="ScalarMath" then n=self:ScalarMathNode(self.nodegroup)
	elseif e.name=="Constant" then n=self:ConstantNode(self.nodegroup)
	elseif e.name=="Seed" then n=self:SeedNode(self.nodegroup)
	elseif e.name=="CoordSource" then n=self:CoordinateSourceNode(self.nodegroup)
	elseif e.name=="Derivative" then n=self:DerivativeNode(self.nodegroup)
	elseif e.name=="Tiers" then n=self:TiersNode(self.nodegroup)
	elseif e.name=="ValueBasis" then n=self:ValueBasisNode(self.nodegroup)
	elseif e.name=="GradientBasis" then n=self:GradientBasisNode(self.nodegroup)
	elseif e.name=="SimplexBasis" then n=self:SimplexBasisNode(self.nodegroup)
	elseif e.name=="TranslateDomain" then n=self:TranslateDomainNode(self.nodegroup)
	elseif e.name=="ScaleDomain" then n=self:ScaleDomainNode(self.nodegroup)
	elseif e.name=="Fractal" then n=self:FractalNode(self.nodegroup)
	elseif e.name=="RotateDomain" then n=self:RotateDomainNode(self.nodegroup)
	elseif e.name=="Randomize" then n=self:RandomizeNode(self.nodegroup)
	elseif e.name=="SmoothStep" then n=self:SmoothStepNode(self.nodegroup)
	elseif e.name=="Mix" then n=self:MixNode(self.nodegroup)
	elseif e.name=="Expression" then n=self:ExpressionNode(self.nodegroup)
	elseif e.name=="Seeder" then n=self:SeederNode(self.nodegroup)
	elseif e.name=="Cellular" then n=self:CellularNode(self.nodegroup)
	elseif e.name=="Sigmoid" then n=self:SigmoidNode(self.nodegroup)
	end]]
	n=self:BuildNode(self.nodegroup, e.name)
	if not n then return end
	
	n.position=IntVector2(-self.nodegroup.pane.position.x + graphics.width/2, -self.nodegroup.pane.position.y + graphics.height/2)
	table.insert(self.nodegroup.nodes, n)
end

function NodeGraphUI:SubscribeLinkPoints(e,numinputs)
	local output=e:GetChild("Output0", true)
	if(output) then
		self:SubscribeToEvent(output, "DragBegin", "NodeGraphUI:HandleOutputDragBegin")
		self:SubscribeToEvent(output, "DragEnd", "NodeGraphUI:HandleDragEnd")
		output:SetRoot(e)
	end
	
	local c
	for c=0,numinputs-1,1 do
		local input=e:GetChild("Input"..c, true)
		if(input) then
			self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
			self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
		end
	end
end

function NodeGraphUI:OutputNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/OutputNode.xml"))
	e.visible=true
	self:SubscribeLinkPoints(e,1)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:BuildNode(nodegroup, type)
	local e=CreateNodeType(nodegroup.pane, type)
	local d=nodetypes[type]
	if not d then return end
	
	if e then
		self:SubscribeLinkPoints(e,#d.inputs)
	end
	
	return e
end

function NodeGraphUI:ScalarMathNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/ScalarMathNode.xml"))
	
	e.visible=true
	
	local list=e:GetChild("TypeList", true)
	list.resizePopup=true
	
	local smtypes=
	{
		"Abs",
		"Cos",
		"Sin",
		"Tan",
		"ACos",
		"ASin",
		"ATan"
	}
	
	list:SetAlignment(HA_LEFT, VA_CENTER)
	list.minSize=IntVector2(0,16)
	local c
	for _,c in ipairs(smtypes) do
		local t=Text:new(context)
		t:SetFont(cache:GetResource("Font", "Fonts/Anonymous Pro.ttf"), 9)
		t.text=c
		t.color=Color(1,1,1)
		t.minSize=IntVector2(0,16)
		list:AddItem(t)
	end
	list.selection=0
	
	self:SubscribeLinkPoints(e,1)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:SeederNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/SeederNode.xml"))
	e.visible=true
	self:SubscribeLinkPoints(e,2)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:SigmoidNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/SigmoidNode.xml"))
	e.visible=true
	self:SubscribeLinkPoints(e,3)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:ArithmeticNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/ArithmeticNode.xml"))
	
	e.visible=true
	
	
	local list=e:GetChild("TypeList", true)
	list.resizePopup=true
	
	local smtypes=
	{
		"Multiply",
		"Add",
		"Subtract",
		"Divide",
		"Pow",
		"Min",
		"Max",
		"Bias",
		"Gain",
		"Step"
	}
	
	list:SetAlignment(HA_LEFT, VA_CENTER)
	list.minSize=IntVector2(0,16)
	local c
	for _,c in ipairs(smtypes) do
		local t=Text:new(context)
		t:SetFont(cache:GetResource("Font", "Fonts/Anonymous Pro.ttf"), 9)
		t.text=c
		t.color=Color(1,1,1)
		t.minSize=IntVector2(0,16)
		list:AddItem(t)
	end
	list.selection=0
	
	self:SubscribeLinkPoints(e,2)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:RotateDomainNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/RotateDomainNode.xml"))
	
	e.visible=true
	self:SubscribeLinkPoints(e,5)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:RandomizeNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/RandomizeNode.xml"))
	
	e.visible=true
	self:SubscribeLinkPoints(e,3)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:SmoothStepNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/SmoothStepNode.xml"))
	
	e.visible=true
	local list=e:GetChild("TypeList", true)
	list.resizePopup=true
	
	local smtypes=
	{
		"Linear",
		"Smooth",
		"Smoother"
	}
	
	list:SetAlignment(HA_LEFT, VA_CENTER)
	list.minSize=IntVector2(0,16)
	local c
	for _,c in ipairs(smtypes) do
		local t=Text:new(context)
		t:SetFont(cache:GetResource("Font", "Fonts/Anonymous Pro.ttf"), 9)
		t.text=c
		t.color=Color(1,1,1)
		t.minSize=IntVector2(0,16)
		list:AddItem(t)
	end
	list.selection=0
	
	self:SubscribeLinkPoints(e,3)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:MixNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/MixNode.xml"))
	
	e.visible=true
	self:SubscribeLinkPoints(e,3)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:FractalNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/FractalNode.xml"))
	
	e.visible=true
	self:SubscribeLinkPoints(e,6)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:CellularNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/CellularNode.xml"))
	
	e.visible=true
	self:SubscribeLinkPoints(e,10)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:TranslateDomainNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TranslateDomainNode.xml"))
	
	e.visible=true
	local list=e:GetChild("TypeList", true)
	list.resizePopup=true
	
	local smtypes=
	{
		"All",
		"X",
		"Y",
		"Z",
		"W",
		"U",
		"V",
	}
	
	list:SetAlignment(HA_LEFT, VA_CENTER)
	list.minSize=IntVector2(0,16)
	local c
	for _,c in ipairs(smtypes) do
		local t=Text:new(context)
		t:SetFont(cache:GetResource("Font", "Fonts/Anonymous Pro.ttf"), 9)
		t.text=c
		t.color=Color(1,1,1)
		t.minSize=IntVector2(0,16)
		list:AddItem(t)
	end
	list.selection=0
	
	self:SubscribeLinkPoints(e,2)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:ScaleDomainNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/ScaleDomainNode.xml"))
	
	e.visible=true
	local list=e:GetChild("TypeList", true)
	list.resizePopup=true
	
	local smtypes=
	{
		"All",
		"X",
		"Y",
		"Z",
		"W",
		"U",
		"V"
	}
	
	list:SetAlignment(HA_LEFT, VA_CENTER)
	list.minSize=IntVector2(0,16)
	local c
	for _,c in ipairs(smtypes) do
		local t=Text:new(context)
		t:SetFont(cache:GetResource("Font", "Fonts/Anonymous Pro.ttf"), 9)
		t.text=c
		t.color=Color(1,1,1)
		t.minSize=IntVector2(0,16)
		list:AddItem(t)
	end
	list.selection=0
	
	self:SubscribeLinkPoints(e,2)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:DerivativeNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/DerivativeNode.xml"))
	
	e.visible=true
	local list=e:GetChild("TypeList", true)
	list.resizePopup=true
	
	local smtypes=
	{
		"dX",
		"dY",
		"dZ",
		"dW",
		"dU",
		"dV"
	}
	
	list:SetAlignment(HA_LEFT, VA_CENTER)
	list.minSize=IntVector2(0,16)
	local c
	for _,c in ipairs(smtypes) do
		local t=Text:new(context)
		t:SetFont(cache:GetResource("Font", "Fonts/Anonymous Pro.ttf"), 9)
		t.text=c
		t.color=Color(1,1,1)
		t.minSize=IntVector2(0,16)
		list:AddItem(t)
	end
	list.selection=0
	
	self:SubscribeLinkPoints(e,2)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:TiersNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TiersNode.xml"))
	
	e.visible=true
	self:SubscribeLinkPoints(e,2)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:ValueBasisNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/ValueBasisNode.xml"))
	
	e.visible=true
	self:SubscribeLinkPoints(e,2)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:GradientBasisNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/GradientBasisNode.xml"))
	
	e.visible=true
	self:SubscribeLinkPoints(e,2)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:SimplexBasisNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/SimplexBasisNode.xml"))
	
	e.visible=true
	self:SubscribeLinkPoints(e,1)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:CoordinateSourceNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/CoordinateSourceNode.xml"))
	
	e.visible=true
	local list=e:GetChild("TypeList", true)
	list.resizePopup=true
	
	local smtypes=
	{
		"X",
		"Y",
		"Z",
		"W",
		"U",
		"V",
		"Radial",
	}
	
	list:SetAlignment(HA_LEFT, VA_CENTER)
	list.minSize=IntVector2(0,16)
	local c
	for _,c in ipairs(smtypes) do
		local t=Text:new(context)
		t:SetFont(cache:GetResource("Font", "Fonts/Anonymous Pro.ttf"), 9)
		t.text=c
		t.color=Color(1,1,1)
		t.minSize=IntVector2(0,16)
		list:AddItem(t)
	end
	list.selection=0
	
	self:SubscribeLinkPoints(e,0)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:ConstantNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/ConstantNode.xml"))
	
	e.visible=true
	self:SubscribeLinkPoints(e,0)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:ExpressionNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/ExpressionNode.xml"))
	
	e.visible=true
	self:SubscribeLinkPoints(e,0)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:SeedNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/SeedNode.xml"))
	
	e.visible=true
	self:SubscribeLinkPoints(e,0)
	
	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:HandleOutputDragBegin(eventType, eventData)
	if not self.nodegroup then return end
	local element=eventData["Element"]:GetPtr("NodeGraphLinkSource")
	self.link=self.nodegroup.linkpane:CreateLink(element,self.cursortarget)
	self.link:SetImageRect(IntRect(193,81,207,95))
	
end

function NodeGraphUI:HandleDragEnd(eventType, eventData)
	if not self.link then return end
	if not self.nodegroup then return end
	
	local at=ui:GetElementAt(cursor.position)
	if at then
		if string.sub(at.name, 1, 5)=="Input" then
			local thislink=at:GetLink()
			if thislink then
				at:ClearLink()
				local src=thislink:GetSource()
				if src then src:RemoveLink(thislink) end
				self.nodegroup.linkpane:RemoveLink(thislink)
			end
			self.link:SetTarget(at)
			return
		end
	end
	
	-- Destroy the link if not dropped on a valid target
	print("Destroy the link")
	local source=self.link:GetSource()
	if(source) then source:RemoveLink(self.link) end
	self.nodegroup.linkpane:RemoveLink(self.link)
	self.link=nil
end

function NodeGraphUI:HandleInputDragBegin(eventType, eventData)
	local element=eventData["Element"]:GetPtr("NodeGraphLinkDest")
	if element then
		local link=element:GetLink()
		if link then
			self.link=link
			link:SetTarget(self.cursortarget)
			element:ClearLink()
		else
			self.link=nil
		end
	end
end

function NodeGraphUI:HandleGenerate(eventType, eventData)
	if not self.nodegroup then return end
	local kernel=PackNodeGraph(self.nodegroup.output)
	RenderANLKernelToImage(self.nodegroup.previewimg,kernel,0,1)
	self.nodegroup.previewtex:SetData(self.nodegroup.previewimg)
end

function NodeGraphUI:HandleExecute(eventType, eventData)
	if not self.nodegroup then return end
	
	local target=self.nodegroup.output:GetChild("TargetList",true).selection
	
	local um1,im1=self.nodegroup.output:GetChild("UseMask1",true).checked,self.nodegroup.output:GetChild("InvertMask1",true).checked
	local um2,im2=self.nodegroup.output:GetChild("UseMask2",true).checked,self.nodegroup.output:GetChild("InvertMask2",true).checked
	local um3,im3=self.nodegroup.output:GetChild("UseMask3",true).checked,self.nodegroup.output:GetChild("InvertMask3",true).checked
	local ms=MaskSettings(um1,im1,um2,im2,um3,im3)
	
	local low=tonumber(self.nodegroup.output:GetChild("Low",true).text) or 0.0
	local high=tonumber(self.nodegroup.output:GetChild("High",true).text) or 1.0
	
	if target==0 then
		-- Map terrain
		if not self.nodegroup then return end
		local kernel=PackNodeGraph(self.nodegroup.output)
		local arr=CArray2Dd(TerrainState:GetTerrainWidth(), TerrainState:GetTerrainHeight())
		map2DNoZ(SEAMLESS_NONE,arr,kernel,SMappingRanges(0,1,0,1,0,1), kernel:lastIndex())
		arr:scaleToRange(low,high)
		TerrainState:SetHeightBuffer(arr,ms)
		--self.nodemapping.visible=false
		saveDoubleArray("map.png",arr)
		return
	elseif target>=1 and target<=8 then
		if not self.nodegroup then return end
		local kernel=PackNodeGraph(self.nodegroup.output)
		local arr=CArray2Dd(TerrainState:GetBlendWidth(), TerrainState:GetBlendHeight())
		map2DNoZ(SEAMLESS_NONE,arr,kernel,SMappingRanges(0,1,0,1,0,1), kernel:lastIndex())
		arr:scaleToRange(low,high)
		TerrainState:SetLayerBuffer(arr,target-1,ms)
		--self.nodemapping.visible=false
		return
	elseif target>=9 and target<=11 then
		if not self.nodegroup then return end
		local kernel=PackNodeGraph(self.nodegroup.output)
		local arr=CArray2Dd(TerrainState:GetTerrainWidth(), TerrainState:GetTerrainHeight())
		map2DNoZ(SEAMLESS_NONE,arr,kernel,SMappingRanges(0,1,0,1,0,1), kernel:lastIndex())
		arr:scaleToRange(low,high)
		print("Setting to mask "..target-9)
		TerrainState:SetMaskBuffer(arr,target-9)
		--self.nodemapping.visible=false
	end
end
