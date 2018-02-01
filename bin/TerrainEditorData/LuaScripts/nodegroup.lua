-- Node Group
require 'LuaScripts/Class'

NodeGroup=class(self)
	self.pane=ui.root:CreateChild("Window")
	self.pane.size=IntVector2(graphics.width*2, graphics.height*2)
	self.pane.position=IntVector2(-graphics.width/2, -graphics.height/2)
	self.pane:SetImageRect(IntRect(208,0,223,15))
	self.pane:SetImageBorder(IntRect(4,4,4,4))
	self.pane:SetTexture(cache:GetResource("Texture2D", "Textures/UI_modified.png"))
	self.pane.opacity=0.75
	self.pane.bringToFront=true
	self.pane.movable=true

	self.linkpane=self.pane:CreateChild("NodeGraphLinkPane")
	self.linkpane.size=IntVector2(graphics.width*2, graphics.height*2)
	self.linkpane.visible=true
	self.linkpane.texture=cache:GetResource("Texture2D", "Data/Textures/UI_modified.png")

	self.previewtex=Texture2D:new()
	self.previewimg=Image()
	self.previewimg:SetSize(256,256,3)
	self.previewimg:Clear(Color(0,0,0))
	self.previewtex:SetData(self.previewimg,false)


end

function NodeGraphUI:Activate()
	self.pane.visible=true
	self.pane.focus=true
end

function NodeGraphUI:Deactivate()
	self.pane.visible=false
	self.pane.focus=false
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

function NodeGraphUI:RotateDomainNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/RotateDomainNode.xml"))

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

function NodeGraphUI:RandomizeNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/RandomizeNode.xml"))

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

	self.pane:AddChild(e)
	return e
end

function NodeGraphUI:SmoothStepNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/SmoothStepNode.xml"))

	e.visible=true
	self.pane.clipChildren=false

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
	input=e:GetChild("Input2", true)
	self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
	self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")

	self.pane:AddChild(e)
	return e
end

function NodeGraphUI:MixNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/MixNode.xml"))

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
	input=e:GetChild("Input5", true)
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
		"Radial",
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

function NodeGraphUI:ExpressionNode()
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/ExpressionNode.xml"))

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
