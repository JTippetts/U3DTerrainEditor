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
	
	worker=function(n)
		if n.name=="Arithmetic" or n.name=="Derivative" then
			local s=GetSourceFromNode(n,"Input0")
			if s and not isvisited(s) then worker(s) end
			s=GetSourceFromNode(n,"Input1")
			if s and not isvisited(s) then worker(s) end
		elseif n.name=="ScalarMath" or n.name=="Output" then
			local s=GetSourceFromNode(n,"Input0")
			if s and not isvisited(s) then worker(s) end
		end
		table.insert(nodes,n)
	end
	print("Packing node graph.")
	worker(output)
	return nodes
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
		"Max"
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
		local nodes=PackNodeGraph(self.nodegroup.output)
		if nodes then
			local c
			for _,c in ipairs(nodes) do print(c.name) end
		end
	end
end