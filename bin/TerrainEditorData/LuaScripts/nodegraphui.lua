-- Node-graph UI

function GetSourceFromNode(node, inputname)
	local c=node:GetChild(inputname,true)
	if c then
		local link=c:GetLink()
		if link then
			local src=link:GetSource()
			if src then
				print("Got root")
				return src:GetRoot()
			end
		end
	end
	print("Couldn't get source from node.")
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
		if n.name=="Output" then
			local s1,s2
			local s=GetSourceFromNode(n,"Input0")
			if s then
				s1=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value0",true).text)
				s1=kernel:constant(c)
			end
			return s1
			--local low=tonumber(n:GetChild("Low").text)
			--local high=tonumber(n:GetChild("High").text)
		elseif n.name=="Arithmetic" then
			local s1,s2
			local s=GetSourceFromNode(n,"Input0")
			if s then
				s1=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value0",true).text)
				s1=kernel:constant(c)
			end
			s=GetSourceFromNode(n, "Input1")
			if s then
				s2=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value1",true).text)
				s2=kernel:constant(c)
			end
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
			end
		elseif n.name=="TranslateDomain" then
			local s1,s2
			local s=GetSourceFromNode(n,"Input0")
			if s then
				s1=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value0",true).text)
				s1=kernel:constant(c)
			end
			s=GetSourceFromNode(n, "Input1")
			if s then
				s2=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value1",true).text)
				s2=kernel:constant(c)
			end
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
			local s1,s2
			local s=GetSourceFromNode(n,"Input0")
			if s then
				s1=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value0",true).text)
				s1=kernel:constant(c)
			end
			s=GetSourceFromNode(n, "Input1")
			if s then
				s2=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value1",true).text)
				s2=kernel:constant(c)
			end
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
			local s1,s2
			local s=GetSourceFromNode(n,"Input0")
			if s then
				s1=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value0",true).text)
				s1=kernel:constant(c)
			end
			s=GetSourceFromNode(n, "Input1")
			if s then
				s2=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value1",true).text)
				--print("hi")
				s2=kernel:constant(c)
			end
			print(s1,s2)
			local smooth=n:GetChild("SmoothCheck",true).checked
			if smooth then
				return kernel:smoothTiers(s1,s2)
			else
				return kernel:tiers(s1,s2)
			end
		elseif n.name=="ValueBasis" then
			local s1,s2
			local s=GetSourceFromNode(n,"Input0")
			if s then
				s1=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value0",true).text)
				s1=kernel:constant(c)
			end
			s=GetSourceFromNode(n, "Input1")
			if s then
				s2=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value1",true).text)
				--print("hi")
				s2=kernel:seed(c)
			end
			return kernel:valueBasis(s1,s2)
		elseif n.name=="SimplexBasis" then
			local s1,s2
			local s=GetSourceFromNode(n,"Input0")
			if s then
				s1=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value0",true).text)
				s1=kernel:constant(c)
			end
			
			return kernel:simplexBasis(s1)
		elseif n.name=="GradientBasis" then
			local s1,s2
			local s=GetSourceFromNode(n,"Input0")
			if s then
				s1=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value0",true).text)
				s1=kernel:constant(c)
			end
			s=GetSourceFromNode(n, "Input1")
			if s then
				s2=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value1",true).text)
				--print("hi")
				s2=kernel:seed(c)
			end
			return kernel:gradientBasis(s1,s2)
		elseif n.name=="ScalarMath" then
			local s1,s2
			local s=GetSourceFromNode(n,"Input0")
			if s then
				s1=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value0",true).text)
				s1=kernel:constant(c)
			end
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
			end
		elseif n.name=="Constant" then
			local val=tonumber(n:GetChild("Value",true).text)
			return kernel:constant(val)
		elseif n.name=="Seed" then
			local val=tonumber(n:GetChild("Value",true).text)
			return kernel:seed(val)
		elseif n.name=="Derivative" then
			local s1,s2
			local s=GetSourceFromNode(n,"Input0")
			if s then
				s1=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value0",true).text)
				s1=kernel:constant(c)
			end
			s=GetSourceFromNode(n, "Input1")
			if s then
				s2=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value1",true).text)
				s2=kernel:constant(c)
			end
			local op=n:GetChild("TypeList",true).selection
			if op==0 then return kernel:dx(s1,s2)
			elseif op==1 then return kernel:dy(s1,s2)
			elseif op==2 then return kernel:dz(s1,s2)
			elseif op==3 then return kernel:dw(s1,s2)
			elseif op==4 then return kernel:du(s1,s2)
			elseif op==5 then return kernel:dv(s1,s2)
			end
		elseif n.name=="Fractal" then
			local s1,s2,s3,s4,s5
			local s=GetSourceFromNode(n,"Input0")
			if s then
				s1=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value0",true).text) or 1.0
				s1=kernel:constant(c)
			end
			s=GetSourceFromNode(n, "Input1")
			if s then
				s2=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value1",true).text) or 1.0
				s2=kernel:constant(c)
			end
			s=GetSourceFromNode(n, "Input2")
			if s then
				s3=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value2",true).text) or 1.0
				s3=kernel:constant(c)
			end
			s=GetSourceFromNode(n, "Input3")
			if s then
				s4=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value3",true).text) or 1.0
				s4=kernel:constant(c)
			end
			s=GetSourceFromNode(n, "Input4")
			if s then
				s5=kernelindices[nodeindex(s)]
			else
				local c=tonumber(n:GetChild("Value4",true).text) or 1.0
				s5=kernel:constant(c)
			end
			local seed=tonumber(n:GetChild("Seed", true).text)
			
			return kernel:fractal(seed,s1,s2,s3,s4,s5)
			
		end
	end
	
	local kernel=CKernel()
	
	worker=function(n)
		if n.name=="Arithmetic" or n.name=="Derivative" or n.name=="Tiers" or n.name=="ValueBasis" or n.name=="GradientBasis" or n.name=="TranslateDomain" or n.name=="ScaleDomain" then
			local s=GetSourceFromNode(n,"Input0")
			if s and not isvisited(s) then worker(s) end
			s=GetSourceFromNode(n,"Input1")
			if s and not isvisited(s) then worker(s) end
		elseif n.name=="ScalarMath" or n.name=="Output" or n.name=="SimplexBasis" then
			local s=GetSourceFromNode(n,"Input0")
			if s and not isvisited(s) then worker(s) end
		elseif n.name=="Fractal" then
			local s=GetSourceFromNode(n,"Input0")
			if s and not isvisited(s) then worker(s) end
			s=GetSourceFromNode(n,"Input1")
			if s and not isvisited(s) then worker(s) end
			s=GetSourceFromNode(n,"Input2")
			if s and not isvisited(s) then worker(s) end
			s=GetSourceFromNode(n,"Input3")
			if s and not isvisited(s) then worker(s) end
			s=GetSourceFromNode(n,"Input4")
			if s and not isvisited(s) then worker(s) end
		end
		table.insert(nodes,n)
		table.insert(kernelindices, InstanceANLFunction(kernel, n))
	end
	print("Packing node graph.")
	
	worker(output)
	local c
	for _,c in ipairs(nodes) do print(c.name) end
	return kernel
end

NodeGraphUI=ScriptObject()

function NodeGraphUI:Start()
	self.pane=ui.root:CreateChild("Window")
	self.pane.size=IntVector2(graphics.width*2, graphics.height*2)
	self.pane.position=IntVector2(-graphics.width/2, -graphics.height/2)
	self.pane:SetImageRect(IntRect(208,0,223,15))
	self.pane:SetImageBorder(IntRect(4,4,4,4))
	self.pane:SetTexture(cache:GetResource("Texture2D", "Textures/UI.png"))
	self.pane.opacity=0.85
	self.pane.bringToFront=true
	self.pane.movable=true
	
	self.linkpane=self.pane:CreateChild("NodeGraphLinkPane")
	self.linkpane.size=IntVector2(graphics.width*2, graphics.height*2)
	self.linkpane.visible=true
	self.linkpane.texture=cache:GetResource("Texture2D", "Data/Textures/UI.png")
	
	
	self.createnodemenu=ui:LoadLayout(cache:GetResource("XMLFile", "UI/CreateNodeMenu.xml"))
	self.pane:AddChild(self.createnodemenu)
	self:SubscribeToEvent(self.createnodemenu:GetChild("Arithmetic", true), "Pressed", "NodeGraphUI:HandleCreateNode")
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
	self.createnodemenu.visible=false
	
	local cnmclose=self.createnodemenu:GetChild("Close", true)
	self:SubscribeToEvent(cnmclose, "Pressed", "NodeGraphUI:HandleCloseCreateNodeMenu")
	self:SubscribeToEvent("KeyDown", "NodeGraphUI:HandleKeyDown")
	
	self.nodegroup=
	{
		output=self:OutputNode(),
		nodes=
		{
		}
	}
	self.nodegroup.output.position=IntVector2(graphics.width, graphics.height)
	self.cursortarget=cursor:CreateChild("NodeGraphLinkDest")
end

function NodeGraphUI:Activate()
	self.pane.visible=true
	self.pane.focus=true
end

function NodeGraphUI:Deactivate()
	self.pane.visible=false
	self.pane.focus=false
end

function NodeGraphUI:HandleCloseCreateNodeMenu(eventType, eventData)
	self.createnodemenu.visible=false
end

function NodeGraphUI:HandleCreateNode(eventType, eventData)
	local e=eventData["Element"]:GetPtr("UIElement")
	if not e then return end
		
	if e.name=="Arithmetic" then
		local n=self:ArithmeticNode()
		n.position=IntVector2(-self.pane.position.x + graphics.width/2, -self.pane.position.y + graphics.height/2)
		table.insert(self.nodegroup.nodes, n)
	elseif e.name=="ScalarMath" then
		local n=self:ScalarMathNode()
		n.position=IntVector2(-self.pane.position.x + graphics.width/2, -self.pane.position.y + graphics.height/2)
		table.insert(self.nodegroup.nodes, n)
	elseif e.name=="Constant" then
		local n=self:ConstantNode()
		n.position=IntVector2(-self.pane.position.x + graphics.width/2, -self.pane.position.y + graphics.height/2)
		table.insert(self.nodegroup.nodes, n)
	elseif e.name=="Seed" then
		local n=self:SeedNode()
		n.position=IntVector2(-self.pane.position.x + graphics.width/2, -self.pane.position.y + graphics.height/2)
		table.insert(self.nodegroup.nodes, n)
	elseif e.name=="CoordSource" then
		local n=self:CoordinateSourceNode()
		n.position=IntVector2(-self.pane.position.x + graphics.width/2, -self.pane.position.y + graphics.height/2)
		table.insert(self.nodegroup.nodes, n)
	elseif e.name=="Derivative" then
		local n=self:DerivativeNode()
		n.position=IntVector2(-self.pane.position.x + graphics.width/2, -self.pane.position.y + graphics.height/2)
		table.insert(self.nodegroup.nodes, n)
	elseif e.name=="Tiers" then
		local n=self:TiersNode()
		n.position=IntVector2(-self.pane.position.x + graphics.width/2, -self.pane.position.y + graphics.height/2)
		table.insert(self.nodegroup.nodes, n)
	elseif e.name=="ValueBasis" then
		local n=self:ValueBasisNode()
		n.position=IntVector2(-self.pane.position.x + graphics.width/2, -self.pane.position.y + graphics.height/2)
		table.insert(self.nodegroup.nodes, n)
	elseif e.name=="GradientBasis" then
		local n=self:GradientBasisNode()
		n.position=IntVector2(-self.pane.position.x + graphics.width/2, -self.pane.position.y + graphics.height/2)
		table.insert(self.nodegroup.nodes, n)
	elseif e.name=="SimplexBasis" then
		local n=self:SimplexBasisNode()
		n.position=IntVector2(-self.pane.position.x + graphics.width/2, -self.pane.position.y + graphics.height/2)
		table.insert(self.nodegroup.nodes, n)
	elseif e.name=="TranslateDomain" then
		local n=self:TranslateDomainNode()
		n.position=IntVector2(-self.pane.position.x + graphics.width/2, -self.pane.position.y + graphics.height/2)
		table.insert(self.nodegroup.nodes, n)
	elseif e.name=="ScaleDomain" then
		local n=self:ScaleDomainNode()
		n.position=IntVector2(-self.pane.position.x + graphics.width/2, -self.pane.position.y + graphics.height/2)
		table.insert(self.nodegroup.nodes, n)
	elseif e.name=="Fractal" then
		local n=self:FractalNode()
		n.position=IntVector2(-self.pane.position.x + graphics.width/2, -self.pane.position.y + graphics.height/2)
		table.insert(self.nodegroup.nodes, n)
	end
end

function NodeGraphUI:HandleKeyDown(eventType, eventData)
	local key = eventData["Key"]:GetInt()

	if key==KEY_SPACE then
		if self.createnodemenu.visible==false then
			self.createnodemenu.visible=true
			self.createnodemenu.position=IntVector2(-self.pane.position.x,-self.pane.position.y+graphics.height/2)
		else
			self.createnodemenu.visible=false
		end
	end
end

function NodeGraphUI:OutputNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/OutputNode.xml"))
	
	e.visible=true
	self.pane.clipChildren=false
	
	local input=e:GetChild("Input0", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	
	self.pane:AddChild(e)
	return e
end

function NodeGraphUI:ScalarMathNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/ScalarMathNode.xml"))
	
	e.visible=true
	self.pane.clipChildren=false
	
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
		t:SetFont(cache:GetResource("Font", "Fonts/Anonymous Pro.ttf"), 11)
		t.text=c
		t.color=Color(1,1,1)
		t.minSize=IntVector2(0,16)
		list:AddItem(t)
	end
	list.selection=0
	
	local output=e:GetChild("Output0", true)
	self:SubscribeToEvent(output, "DragBegin", "NodeGraphUI:HandleOutputDragBegin")
	self:SubscribeToEvent(output, "DragEnd", "NodeGraphUI:HandleDragEnd")
	output:SetRoot(e)
	
	local input=e:GetChild("Input0", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	
	self.pane:AddChild(e)
	return e
end

function NodeGraphUI:ArithmeticNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/ArithmeticNode.xml"))
	
	e.visible=true
	self.pane.clipChildren=false
	
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
	}
	
	list:SetAlignment(HA_LEFT, VA_CENTER)
	list.minSize=IntVector2(0,16)
	local c
	for _,c in ipairs(smtypes) do
		local t=Text:new(context)
		t:SetFont(cache:GetResource("Font", "Fonts/Anonymous Pro.ttf"), 11)
		t.text=c
		t.color=Color(1,1,1)
		t.minSize=IntVector2(0,16)
		list:AddItem(t)
	end
	list.selection=0
	
	local output=e:GetChild("Output0", true)
	
	self:SubscribeToEvent(output, "DragBegin", "NodeGraphUI:HandleOutputDragBegin")
	self:SubscribeToEvent(output, "DragEnd", "NodeGraphUI:HandleDragEnd")
	output:SetRoot(e)
	
	local input=e:GetChild("Input0", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	input=e:GetChild("Input1", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	
	self.pane:AddChild(e)
	return e
end

function NodeGraphUI:FractalNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/FractalNode.xml"))
	
	e.visible=true
	self.pane.clipChildren=false
	
	local output=e:GetChild("Output0", true)
	
	self:SubscribeToEvent(output, "DragBegin", "NodeGraphUI:HandleOutputDragBegin")
	self:SubscribeToEvent(output, "DragEnd", "NodeGraphUI:HandleDragEnd")
	output:SetRoot(e)
	
	local input=e:GetChild("Input0", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	input=e:GetChild("Input1", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	input=e:GetChild("Input2", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	input=e:GetChild("Input3", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	input=e:GetChild("Input4", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	
	self.pane:AddChild(e)
	return e
end

function NodeGraphUI:TranslateDomainNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TranslateDomainNode.xml"))
	
	e.visible=true
	self.pane.clipChildren=false
	
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
		t:SetFont(cache:GetResource("Font", "Fonts/Anonymous Pro.ttf"), 11)
		t.text=c
		t.color=Color(1,1,1)
		t.minSize=IntVector2(0,16)
		list:AddItem(t)
	end
	list.selection=0
	
	local output=e:GetChild("Output0", true)
	
	self:SubscribeToEvent(output, "DragBegin", "NodeGraphUI:HandleOutputDragBegin")
	self:SubscribeToEvent(output, "DragEnd", "NodeGraphUI:HandleDragEnd")
	output:SetRoot(e)
	
	local input=e:GetChild("Input0", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	input=e:GetChild("Input1", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	
	self.pane:AddChild(e)
	return e
end

function NodeGraphUI:ScaleDomainNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/ScaleDomainNode.xml"))
	
	e.visible=true
	self.pane.clipChildren=false
	
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
		t:SetFont(cache:GetResource("Font", "Fonts/Anonymous Pro.ttf"), 11)
		t.text=c
		t.color=Color(1,1,1)
		t.minSize=IntVector2(0,16)
		list:AddItem(t)
	end
	list.selection=0
	
	local output=e:GetChild("Output0", true)
	
	self:SubscribeToEvent(output, "DragBegin", "NodeGraphUI:HandleOutputDragBegin")
	self:SubscribeToEvent(output, "DragEnd", "NodeGraphUI:HandleDragEnd")
	output:SetRoot(e)
	
	local input=e:GetChild("Input0", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	input=e:GetChild("Input1", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	
	self.pane:AddChild(e)
	return e
end

function NodeGraphUI:DerivativeNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/DerivativeNode.xml"))
	
	e.visible=true
	self.pane.clipChildren=false
	
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
		t:SetFont(cache:GetResource("Font", "Fonts/Anonymous Pro.ttf"), 11)
		t.text=c
		t.color=Color(1,1,1)
		t.minSize=IntVector2(0,16)
		list:AddItem(t)
	end
	list.selection=0
	
	local output=e:GetChild("Output0", true)
	
	self:SubscribeToEvent(output, "DragBegin", "NodeGraphUI:HandleOutputDragBegin")
	self:SubscribeToEvent(output, "DragEnd", "NodeGraphUI:HandleDragEnd")
	output:SetRoot(e)
	
	local input=e:GetChild("Input0", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	input=e:GetChild("Input1", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	
	self.pane:AddChild(e)
	return e
end

function NodeGraphUI:TiersNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TiersNode.xml"))
	
	e.visible=true
	self.pane.clipChildren=false
	
	local output=e:GetChild("Output0", true)
	
	self:SubscribeToEvent(output, "DragBegin", "NodeGraphUI:HandleOutputDragBegin")
	self:SubscribeToEvent(output, "DragEnd", "NodeGraphUI:HandleDragEnd")
	output:SetRoot(e)
	
	local input=e:GetChild("Input0", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	input=e:GetChild("Input1", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	
	self.pane:AddChild(e)
	return e
end

function NodeGraphUI:ValueBasisNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/ValueBasisNode.xml"))
	
	e.visible=true
	self.pane.clipChildren=false
	
	local output=e:GetChild("Output0", true)
	
	self:SubscribeToEvent(output, "DragBegin", "NodeGraphUI:HandleOutputDragBegin")
	self:SubscribeToEvent(output, "DragEnd", "NodeGraphUI:HandleDragEnd")
	output:SetRoot(e)
	
	local input=e:GetChild("Input0", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	input=e:GetChild("Input1", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	
	self.pane:AddChild(e)
	return e
end

function NodeGraphUI:GradientBasisNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/GradientBasisNode.xml"))
	
	e.visible=true
	self.pane.clipChildren=false
	
	local output=e:GetChild("Output0", true)
	
	self:SubscribeToEvent(output, "DragBegin", "NodeGraphUI:HandleOutputDragBegin")
	self:SubscribeToEvent(output, "DragEnd", "NodeGraphUI:HandleDragEnd")
	output:SetRoot(e)
	
	local input=e:GetChild("Input0", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	input=e:GetChild("Input1", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	
	self.pane:AddChild(e)
	return e
end

function NodeGraphUI:SimplexBasisNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/SimplexBasisNode.xml"))
	
	e.visible=true
	self.pane.clipChildren=false
	
	local output=e:GetChild("Output0", true)
	
	self:SubscribeToEvent(output, "DragBegin", "NodeGraphUI:HandleOutputDragBegin")
	self:SubscribeToEvent(output, "DragEnd", "NodeGraphUI:HandleDragEnd")
	output:SetRoot(e)
	
	local input=e:GetChild("Input0", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
	
	self.pane:AddChild(e)
	return e
end

function NodeGraphUI:CoordinateSourceNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/CoordinateSourceNode.xml"))
	
	e.visible=true
	self.pane.clipChildren=false
	
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
	}
	
	list:SetAlignment(HA_LEFT, VA_CENTER)
	list.minSize=IntVector2(0,16)
	local c
	for _,c in ipairs(smtypes) do
		local t=Text:new(context)
		t:SetFont(cache:GetResource("Font", "Fonts/Anonymous Pro.ttf"), 11)
		t.text=c
		t.color=Color(1,1,1)
		t.minSize=IntVector2(0,16)
		list:AddItem(t)
	end
	list.selection=0
	
	local output=e:GetChild("Output0", true)
	
	self:SubscribeToEvent(output, "DragBegin", "NodeGraphUI:HandleOutputDragBegin")
	self:SubscribeToEvent(output, "DragEnd", "NodeGraphUI:HandleDragEnd")
	output:SetRoot(e)
	
	self.pane:AddChild(e)
	return e
end

function NodeGraphUI:ConstantNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/ConstantNode.xml"))
	
	e.visible=true
	self.pane.clipChildren=false
	
	local output=e:GetChild("Output0", true)
	
	self:SubscribeToEvent(output, "DragBegin", "NodeGraphUI:HandleOutputDragBegin")
	self:SubscribeToEvent(output, "DragEnd", "NodeGraphUI:HandleDragEnd")
	output:SetRoot(e)
	
	self.pane:AddChild(e)
	return e
end

function NodeGraphUI:SeedNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/SeedNode.xml"))
	
	e.visible=true
	self.pane.clipChildren=false
	
	local output=e:GetChild("Output0", true)
	
	self:SubscribeToEvent(output, "DragBegin", "NodeGraphUI:HandleOutputDragBegin")
	self:SubscribeToEvent(output, "DragEnd", "NodeGraphUI:HandleDragEnd")
	output:SetRoot(e)
	
	self.pane:AddChild(e)
	return e
end

function NodeGraphUI:HandleOutputDragBegin(eventType, eventData)
	print("dragging")
	local element=eventData["Element"]:GetPtr("NodeGraphLinkSource")
	self.link=self.linkpane:CreateLink(element,self.cursortarget)
	self.link:SetImageRect(IntRect(19,19,29,29))
	
end

function NodeGraphUI:HandleDragEnd(eventType, eventData)
	if not self.link then return end
	
	local at=ui:GetElementAt(cursor.position)
	if at then
		if string.sub(at.name, 1, 5)=="Input" then
			--print("Set link target")
			local thislink=at:GetLink()
			if thislink then
				at:ClearLink()
				local src=thislink:GetSource()
				if src then src:RemoveLink(thislink) end
				--thislink:Remove()
				self.linkpane:RemoveLink(thislink)
			end
			self.link:SetTarget(at)
			return
		end
	end
	
	-- Destroy the link if not dropped on a valid target
	print("Destroy the link")
	local source=self.link:GetSource()
	if(source) then source:RemoveLink(self.link) end
	--self.link:Remove()
	self.linkpane:RemoveLink(self.link)
	--self.link:ClearTarget()
	self.link=nil
	--print("End drag "..element.name)
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
	
	--print("Begin drag "..element.name)
end

function NodeGraphUI:Update(dt)
	if input:GetMouseButtonDown(MOUSEB_RIGHT) then
		local mmove=input:GetMouseMove()
		local pos=self.pane.position
		pos.x = pos.x + mmove.x
		pos.y = pos.y + mmove.y
		print(pos.x,pos.y)
		self.pane:SetPosition(pos)
	end
	
	if input:GetKeyPress(KEY_B) then
		local kernel=PackNodeGraph(self.nodegroup.output)
		
		local img=CArray2Dd(256,256)
		map2DNoZ(SEAMLESS_NONE, img, kernel, SMappingRanges(0,10,0,10,0,10), kernel:lastIndex())
		img:scaleToRange(0,1)
		saveDoubleArray("noise.png", img)
	end
end