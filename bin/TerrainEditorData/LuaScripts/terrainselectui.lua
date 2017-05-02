-- Terrain Brush select panel
require 'LuaScripts/editingbrush'

TerrainSelectUI=ScriptObject()

function TerrainSelectUI:Start()
	self.panel=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TerrainEditBlendBrush.xml"))
	self.panel.style=uiStyle
	ui.root:AddChild(self.panel)
	self.panel.visible=false
	
	self.layer=1
	self.active=false
	
	self.brushpreview=Image(context)
	self.brushpreview:SetSize(64,64,3)
	self.brushtex=Texture2D:new(context)
	--self.brushtex:SetSize(0,0,0,TEXTURE_DYNAMIC)
	self.panel:GetChild("BrushPreview",true).texture=self.brushtex
	
	self:SubscribeToEvent("Pressed", "TerrainSelectUI:HandleButtonPress")
	self:SubscribeToEvent("SliderChanged", "TerrainSelectUI:HandleSliderChanged")
	
	
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

function TerrainSelectUI:LoadThumbnails(thumblist)
	local i
	for i=0,7,1 do
		local name="Terrain"..i
		local button=self.panel:GetChild(name,true)
		if button then
			button.texture=cache:GetResource("Texture2D", thumblist[i+1])
		end
	end
	
end

function TerrainSelectUI:GetBrushSettings()
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

function TerrainSelectUI:GenerateBrushPreview()
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

function TerrainSelectUI:GetBrushPreview()
	return self.brushtex
end

function TerrainSelectUI:Activate()
	self.panel.visible=true
	self.active=true
	self:GenerateBrushPreview(self.hardness)
	self.cursor:BuildCursorMesh(self.radius)
	self.cursor:Show()
	self.cursor:SetBrushPreview(self.brushtex)
end

function TerrainSelectUI:Deactivate()
	self.panel.visible=false
	self.active=false
	self.cursor:Hide()
end

function TerrainSelectUI:ChangeLayer(which)
	local prev=self.panel:GetChild("SelectedLayer", true)
	if prev then
		local whichbutton="Terrain"..(which-1)
		local b=self.panel:GetChild(whichbutton, true)
		if b then
			prev.texture=b.texture
		end
	end
end

function TerrainSelectUI:SwitchLayer(which)
	self:ChangeLayer(which)
	self.layer=which
end

function TerrainSelectUI:HandleButtonPress(eventType, eventData)
	local which=eventData["Element"]:GetPtr("UIElement")
	local name=which:GetName()
	if name=="Terrain0" then
		self:SwitchLayer(1)
	elseif  name=="Terrain1" then
		self:SwitchLayer(2)
	elseif name=="Terrain2" then
		self:SwitchLayer(3)
	elseif name=="Terrain3" then
		self:SwitchLayer(4)
	elseif name=="Terrain4" then
		self:SwitchLayer(5)
	elseif name=="Terrain5" then
		self:SwitchLayer(6)
	elseif name=="Terrain6" then
		self:SwitchLayer(7)
	elseif name=="Terrain7"  then
		self:SwitchLayer(8)
	end
	
end

function TerrainSelectUI:HandleSliderChanged(eventType, eventData)
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

function TerrainSelectUI:Update(dt)
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
		
		if input:GetMouseButtonDown(MOUSEB_LEFT) and ui:GetElementAt(mousepos.x, mousepos.y)==nil then
			local gx,gz=ground.x,ground.z
			ApplyBlendBrush8(TerrainState.terrain,TerrainState.hmap,TerrainState.blend1,TerrainState.blend2,TerrainState.mask,gx,gz,self.radius,self.max,self.power,self.hardness,self.layer-1,self.usemask,dt)TerrainState. blendtex1:SetData(TerrainState.blend1) TerrainState.blendtex2:SetData(TerrainState.blend2)
		end
	end
	
	self.cursor:SetBrushCursorHeight()
end
