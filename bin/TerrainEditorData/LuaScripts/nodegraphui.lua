-- Node-graph UI

NodeGraphUI=ScriptObject()

function NodeGraphUI:Start()
	self.pane=ui.root:CreateChild("Window")
	self.pane.size=IntVector2(graphics.width, graphics.height)
	self.pane:SetImageRect(IntRect(208,0,223,15))
	self.pane:SetImageBorder(IntRect(4,4,4,4))
	self.pane:SetTexture(cache:GetResource("Texture2D", "Textures/UI.png"))
	self.pane.bringToFront=true
	
	self.testthing=self:ScalarMathNode()
	self.testthing.visible=true
	self.testthing.position=IntVector2(graphics.width/2, graphics.height/2)
	
	self.testthing2=self:ScalarMathNode()
	self.testthing2.visible=true
	self.testthing.position=IntVector2(graphics.width/2+100, graphics.height/2)
end

function NodeGraphUI:Activate()
	self.pane.visible=true
	self.pane.focus=true
end

function NodeGraphUI:Deactivate()
	self.pane.visible=false
	self.pane.focus=false
end

function NodeGraphUI:ScalarMathNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/ScalarMathNode.xml"))
	self.pane:AddChild(e)
	e.visible=true
	self.pane.clipChildren=false
	
	local list=e:GetChild("TypeList", true)
	list.resizePopup=true
	
	local smtypes=
	{
		"Abs",
		"Multiply",
		"Add",
		"Subtract",
		"Divide",
		"Cos",
		"Sin",
		"Pow",
		"Exp"
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
	
	self:SubscribeToEvent(output, "DragBegin", "NodeGraphUI:HandleDragBegin")
	self:SubscribeToEvent(output, "DragEnd", "NodeGraphUI:HandleDragEnd")
	self:SubscribeToEvent(output, "DragMove", "NodeGraphUI:HandleDragMove")
	self:SubscribeToEvent(output, "DragCancel", "NodeGraphUI:HandleDragCancel")
	
	return e
end

function NodeGraphUI:HandleDragBegin(eventType, eventData)
	local element=eventData["Element"]:GetPtr("UIElement")
	self.link=element:GetChild("Link", true)
	
	self.link:SetTarget(cursor)
	--print("Begin drag "..element.name)
end

function NodeGraphUI:HandleDragEnd(eventType, eventData)
	local element=eventData["Element"]:GetPtr("UIElement")
	
	local at=ui:GetElementAt(cursor.position)
	if at then
		print("Element: "..at.name)
		print(string.sub(at.name,1,5))
		if string.sub(at.name, 1, 5)=="Input" then self.link:SetTarget(at) else self.link:ClearTarget() end
	else print("No element there.")
		self.link:ClearTarget()
	end
	
	--self.link:ClearTarget()
	self.link=nil
	--print("End drag "..element.name)
end

function NodeGraphUI:HandleDragMove(eventType, eventData)
	local element=eventData["Element"]:GetPtr("UIElement")
	
	--print("Move drag "..element.name)
end

function NodeGraphUI:HandleDragCancel(eventType, eventData)
	local element=eventData["Element"]:GetPtr("UIElement")
	
	--print("End drag "..element.name)
end