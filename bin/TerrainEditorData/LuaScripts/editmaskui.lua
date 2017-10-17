-- Smooth brush

EditMaskUI=ScriptObject()

function EditMaskUI:Start()
	self.panel=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TerrainEditMaskBrush.xml"))
	
	self.panel.style=uiStyle
	ui.root:AddChild(self.panel)
	self.panel.visible=false
	self.active=false
	
	self.brushpreview=Image(context)
	self.brushpreview:SetSize(64,64,3)
	self.brushtex=Texture2D:new(context)
	--self.brushtex:SetSize(0,0,0,TEXTURE_DYNAMIC)
	self.panel:GetChild("BrushPreview",true).texture=self.brushtex
	
	--self:SubscribeToEvent("Pressed", "EditMaskUI:HandleButtonPress")
	self:SubscribeToEvent("SliderChanged", "EditMaskUI:HandleSliderChanged")
	self:SubscribeToEvent(self.panel:GetChild("ClearMask",true), "Pressed", "EditMaskUI:HandleClearMask")
	
	
	self.power,self.max,self.radius,self.hardness,self.usemask=self:GetBrushSettings()
	
	local text=self.panel:GetChild("PowerText", true)
	if text then text.text=string.format("%.1f", self.power) end
	text=self.panel:GetChild("RadiusText", true)
	if text then text.text=tostring(math.floor(self.radius)) end
	text=self.panel:GetChild("MaxText", true)
	if text then text.text=string.format("%.1f", self.max) end
	text=self.panel:GetChild("HardnessText", true)
	if text then text.text=string.format("%.2f", self.hardness) end
	
	self.cursor=EditingBrush(scene_)
	self.cursor:BuildCursorMesh(self.radius)
	self.cursor:SetBrushPreview(self.brushtex)
	self.cursor:Hide()
end

function EditMaskUI:GetBrushSettings()
	local power,max,radius,hardness=0,0,5,0.9
	local usemask=false
	
	local slider
	slider=self.panel:GetChild("PowerSlider", true)
	if slider then power=(slider.value/slider.range)*4 end
	
	slider=self.panel:GetChild("MaxSlider", true)
	if slider then max=(slider.value/slider.range) end
	
	slider=self.panel:GetChild("RadiusSlider", true)
	if slider then radius=math.floor((slider.value/slider.range)*30) end
	
	slider=self.panel:GetChild("HardnessSlider", true)
	if slider then hardness=(slider.value/slider.range) end
	
	local button=self.panel:GetChild("MaskCheck", true)
	if button then usemask=button.checked end
	
	return power,max,radius,math.min(1,hardness),usemask
end

function EditMaskUI:GenerateBrushPreview()
	local hardness=0.5
	local slider=self.panel:GetChild("HardnessSlider", true)
	if slider then hardness=(slider.value/slider.range) end
	
	local w,h=self.brushpreview:GetWidth(), self.brushpreview:GetHeight()
	local rad=w/2
	local x,y
	for x=0,w-1,1 do
		for y=0,h-1,1 do
			local dx=x-w/2
			local dy=y-h/2
			local d=math.sqrt(dx*dx+dy*dy)
			--local i=(rad-d)/rad
			local i=(d-rad)/(hardness*rad-rad)
			i=math.max(0, math.min(1,i))
				
			self.brushpreview:SetPixel(x,y,Color(i*0.5,i*0.5,i*0.6))
		end
	end
	
	self.brushtex:SetData(self.brushpreview, false)
end

function EditMaskUI:GetBrushPreview()
	return self.brushtex
end

function EditMaskUI:Activate(which)
	self.panel.visible=true
	self.active=true
	self:GenerateBrushPreview(self.hardness)
	self.cursor:BuildCursorMesh(self.radius)
	self.cursor:Show()
	self.cursor:SetBrushPreview(self.brushtex)
	self.which=math.max(0, math.min(2,which))
	local name=self.panel:GetChild("MaskName", true)
	if name then name.text = "Edit Mask "..self.which end
	self.panel:SetPosition(IntVector2(0,graphics.height-self.panel.height))
end

function EditMaskUI:Deactivate()
	self.panel.visible=false
	self.active=false
	self.cursor:Hide()
end

function EditMaskUI:HandleClearMask(eventType, eventData)
	TerrainState:ClearMask(self.which)
end

function EditMaskUI:HandleSliderChanged(eventType, eventData)
	local which=eventData["Element"]:GetPtr("UIElement")
	if which==nil then return end
	
	self.power, self.max, self.radius, self.hardness, self.usemask=self:GetBrushSettings(self.panel)
	--self:BuildCursorMesh(self.radius)
	
	if which==self.panel:GetChild("PowerSlider", true) then
		local text=self.panel:GetChild("PowerText", true)
		if text then text.text=string.format("%.2f", self.power) end
	elseif which==self.panel:GetChild("RadiusSlider", true) then
		local text=self.panel:GetChild("RadiusText", true)
		if text then text.text=tostring(math.floor(self.radius)) end
		self.cursor:BuildCursorMesh(self.radius)
	elseif which==self.panel:GetChild("MaxSlider", true) then
		local text=self.panel:GetChild("MaxText", true)
		if text then text.text=string.format("%.2f", self.max) end
	elseif which==self.panel:GetChild("HardnessSlider", true) then
		local text=self.panel:GetChild("HardnessText", true)
		if text then text.text=string.format("%.3f", self.hardness) end
		self:GenerateBrushPreview(self.hardness)
	end
end

function EditMaskUI:Update(dt)
	if not self.active then return end
	
	
	local mousepos
	if input.mouseVisible then
		mousepos=input:GetMousePosition()
	else
		mousepos=ui:GetCursorPosition()
	end
	
	local ground=cam:GetScreenGround(mousepos.x, mousepos.y)
	
	if ground then 
		local world=Vector3(ground.x,0,ground.z)
		self.cursor:SetPosition(world)
		self.power, self.max, self.radius, self.hardness, self.usemask=self:GetBrushSettings()
		local bs=BrushSettings(self.radius, self.max, self.power, self.hardness)
		local ms=MaskSettings()
		
		if input:GetMouseButtonDown(MOUSEB_LEFT) and ui:GetElementAt(mousepos.x, mousepos.y)==nil then
			local gx,gz=ground.x,ground.z
			--ApplyMaskBrush(TerrainState.terrain,TerrainState.hmap,TerrainState.mask,gx,gz,self.radius,self.max,self.power,self.hardness,dt,self.which) TerrainState.masktex:SetData(TerrainState.mask)
			TerrainState:ApplyMaskBrush(gx,gz,self.which,dt,bs,ms)
		end
	end
	
	self.cursor:SetBrushCursorHeight()
end
