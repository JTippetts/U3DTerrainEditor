-- Build ANL function from node graph
-- Node-graph UI
-- Instance data
-- Consists of opcodes.
-- If opcode=="Parameter" then get the specified input parameter.
-- If opcode=="Function" then instantiate the given ANL function, with the specified array indices
require 'LuaScripts/tableshow'

-- Testing
compositenodetypes=
{

}

compositenodecategories=
{
	combine=
	{
		"add",
		"subtract",
		"multiply",
		"divide",
		"pow",
		"minimum",
		"maximum",
		"bias",
		"gain",
		"mix",
	},
	scalarmath=
	{
		"abs",
		"sin",
		"cos",
		"tan",
		"asin",
		"acos",
		"atan",
	},
	step=
	{
		"step",
		"linearStep",
		"smoothStep",
		"smootherStep",
		"tiers",
		"smoothTiers",
	},
	sources=
	{
		"image",
		"nodeGraph",
		"spline",
	},
	filters=
	{
		"erosion",
		"fillBasin",
		"cavity",
		"steepness",
	},
}

function InstanceCompositeFunction(k, desc, params)
	local ins=desc.instance
	if not ins then return end

	local n={}
	local c
	for _,c in ipairs(ins) do
		if c.op=="Parameter" then
			table.insert(n, params[c.param])
		elseif c.op=="Function" then
			local indices=c.indices
			local constants=c.constants
			local seeds=c.seeds

			local inputs={}
			local d

			local fdesc=GetCompositeNodeTypeDesc(c.func) --compositenodetypes[c.func]
			print("numinputs for "..c.func..": "..#fdesc.inputs)
			for d=1,#fdesc.inputs,1 do
				if indices[d] ~= "nil" then print("index: "..indices[d]) table.insert(inputs,n[indices[d]])
				elseif constants and constants[d] ~= "nil" then print("constant: "..constants[d]) table.insert(inputs, k:constant(constants[d]))
				elseif seeds and seeds[d] ~= "nil" then print("seed: "..seeds[d]) table.insert(inputs, k:seed(seeds[d]))
				end
			end

			print("Function name: "..c.func)
			if c.func=="add" then
				table.insert(n, k:add(inputs[1],inputs[2]))
			elseif c.func=="subtract" then
				table.insert(n, k:subtract(inputs[1], inputs[2]))
			elseif c.func=="multiply" then
				table.insert(n, k:multiply(inputs[1], inputs[2]))
			elseif c.func=="divide" then
				table.insert(n, k:divide(inputs[1], inputs[2]))
			elseif c.func=="subtract" then
				table.insert(n, k:subtract(inputs[1], inputs[2]))
			elseif c.func=="minimum" then
				table.insert(n, k:minimum(inputs[1], inputs[2]))
			elseif c.func=="maximum" then
				table.insert(n, k:maximum(inputs[1], inputs[2]))
			elseif c.func=="bias" then
				table.insert(n, k:bias(inputs[1], inputs[2]))
			elseif c.func=="gain" then
				table.insert(n, k:gain(inputs[1], inputs[2]))
			elseif c.func=="step" then
				table.insert(n, k:step(inputs[1], inputs[2]))
			elseif c.func=="linearStep" then
				table.insert(n, k:linearStep(inputs[1], inputs[2], inputs[3]))
			elseif c.func=="smoothStep" then
				table.insert(n, k:smoothStep(inputs[1], inputs[2], inputs[3]))
			elseif c.func=="smootherStep" then
				table.insert(n, k:smootherStep(inputs[1], inputs[2], inputs[3]))
			elseif c.func=="curveSection" then
				table.insert(n, k:curveSection(inputs[1], inputs[2], inputs[3], inputs[4], inputs[5], inputs[6]))
			elseif c.func=="abs" then
				table.insert(n, k:abs(inputs[1]))
			elseif c.func=="sin" then
				table.insert(n, k:sin(inputs[1]))
			elseif c.func=="cos" then
				table.insert(n, k:cos(inputs[1]))
			elseif c.func=="tan" then
				table.insert(n, k:tan(inputs[1]))
			elseif c.func=="asin" then
				table.insert(n, k:asin(inputs[1]))
			elseif c.func=="acos" then
				table.insert(n, k:acos(inputs[1]))
			elseif c.func=="atan" then
				table.insert(n, k:atan(inputs[1]))
			elseif c.func=="x" then
				table.insert(n, k:x())
			elseif c.func=="y" then
				table.insert(n, k:y())
			elseif c.func=="radial" then
				table.insert(n, k:radial())
			elseif c.func=="dX" then
				table.insert(n, k:dx(inputs[1], inputs[2]))
			elseif c.func=="dY" then
				table.insert(n, k:dy(inputs[1], inputs[2]))
			elseif c.func=="smoothTiers" then
				table.insert(n, k:smoothTiers(inputs[1], inputs[2]))
			elseif c.func=="tiers" then
				table.insert(n, k:tiers(inputs[1], inputs[2]))
			elseif c.func=="translateDomain" then
				table.insert(n, k:translateDomain(inputs[1], inputs[2]))
			elseif c.func=="translateX" then
				table.insert(n, k:translateX(inputs[1], inputs[2]))
			elseif c.func=="translateY" then
				table.insert(n, k:translateY(inputs[1], inputs[2]))
			elseif c.func=="scaleDomain" then
				table.insert(n, k:scaleDomain(inputs[1], inputs[2]))
			elseif c.func=="scaleX" then
				table.insert(n, k:scaleX(inputs[1], inputs[2]))
			elseif c.func=="scaleY" then
				table.insert(n, k:scaleY(inputs[1], inputs[2]))
			elseif c.func=="rotateDomain" then
				table.insert(n, k:rotateDomain(inputs[1], inputs[2], inputs[3], inputs[4], inputs[5]))
			elseif c.func=="mix" then
				table.insert(n, k:mix(inputs[1], inputs[2], inputs[3]))
			elseif c.func=="seeder" then
				table.insert(n, k:seeder(inputs[1], inputs[2]))
			elseif c.func=="sigmoid" then
				table.insert(n, k:sigmoid(inputs[1], inputs[2], inputs[3]))
			elseif c.func=="randomize" then
				table.insert(n, k:randomize(inputs[1], inputs[2], inputs[3]))
			elseif c.func=="fractal" then
				table.insert(n, k:fractal(inputs[1], inputs[2], inputs[3], inputs[4], inputs[5], inputs[6]))
			elseif c.func=="cellularBasis" then
				table.insert(n, k:cellularBasis(inputs[1], inputs[2], inputs[3], inputs[4], inputs[5], inputs[6], inputs[7], inputs[8], inputs[9], inputs[10]))
			elseif c.func=="valueBasis" then
				table.insert(n, k:valueBasis(inputs[1], inputs[2]))
			elseif c.func=="gradientBasis" then
				table.insert(n, k:gradientBasis(inputs[1], inputs[2]))
			elseif c.func=="simplexBasis" then
				table.insert(n, k:simplexBasis(inputs[1]))
			elseif c.func=="combineRGBA" then
				table.insert(n, k:combineRGBA(inputs[1],inputs[2],inputs[3],inputs[4]))
			elseif c.func=="combineHSVA" then
				table.insert(n, k:combineHSVA(inputs[1],inputs[2],inputs[3],inputs[4]))
			else
				if compositenodetypes.library[c.func] then
					table.insert(n, InstanceCompositeFunction(k, compositenodetypes.library[c.func], inputs))
				elseif compositenodetypes.user[c.func] then
					table.insert(n, InstanceCompositeFunction(k, compositenodetypes.user[c.func], inputs))
				else
					print("wut")
				end
			end
		end
	end
	print(k:lastIndex())
	return k:lastIndex()
end

function GetCompositeNodeTypeDesc(type)
	if compositenodetypes[type] then return compositenodetypes[type] end
	return nil
end

function CreateCompositeNodeType(parent, type)
	local d=GetCompositeNodeTypeDesc(type)--compositenodetypes[type]
	if not d then return end

	local node

	if type=="image" then
	elseif type=="nodeGraph" then
	elseif type=="spline" then
	else
		node=ui:LoadLayout(cache:GetResource("XMLFile", "UI/CompositeNodeTemplate.xml"))
	end
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
		e.texture=cache:GetResource("Texture2D", "Textures/UI_modified.png")

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

	local options=node:GetChild("Params",true)

	for c=1,#d.options,1 do
		local input=options:CreateChild("UIElement")
		input.name=d.options[c][1]
		input:SetLayout(LM_HORIZONTAL)
		local e=input:CreateChild("LineEdit")
		e.name="Value"..(c-1)
		e:SetStyleAuto(cache:GetResource("XMLFile", "UI/DefaultStyle.xml"))
		e:GetTextElement().fontSize=9
		e:SetText(d.inputs[c][3])
		e:SetMinSize(40,12)
		e:SetMaxSize(40,12)

		e=input:CreateChild("Text")
		e:SetStyleAuto(cache:GetResource("XMLFile", "UI/DefaultStyle.xml"))
		e.fontSize=9
		e.text=tostring(d.options[c][2])
	end

	return node

end

--[[
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
]]

function BuildANLFunction(output)
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

		local desc=GetCompositeNodeTypeDesc(n.name)--compositenodetypes[n.name]
		if not desc then return end
		local numinputs=#desc.inputs
		local c
		local params={}
		for c=1,numinputs,1 do
			if desc.inputs[c][1]=="value" then
				table.insert(params, GetValue(n,c-1))
			else
				table.insert(params, GetSeed(n,c-1))
			end
		end


		if n.name=="Output" then
			local s1
			local s1=GetValue(n,0)
			return s1
		elseif n.name=="constant" then
			local v=tonumber(n:GetChild("Value", true).text)
			return kernel:constant(v)
		elseif n.name=="seed" then
			local v=tonumber(n:GetChild("Value", true).text)
			return kernel:seed(v)
		else
			print("Instance function "..n.name)
			return InstanceCompositeFunction(kernel, desc, params)
		end

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
			local desc=GetCompositeNodeTypeDesc(n.name)--compositenodetypes[n.name]
			if not desc then print(n.name.." Doesn't exist") return false end

			local numinputs=#desc.inputs
			if numinputs>0 then
				visitnode(n, numinputs)
			end
		else
			visitnode(n,1)
		end

		table.insert(nodes,n)
		local ind=InstanceANLFunction(kernel, n)
		table.insert(kernelindices, ind)
	end
	print("Packing node graph.")

	worker(output)
	local c
	for _,c in ipairs(nodes) do print(c.name) end
	return kernel
end
