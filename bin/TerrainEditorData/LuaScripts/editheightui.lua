-- Elevation Height Editing Brush
require 'LuaScripts/editingbrush'

EditHeightUI=ScriptObject()

function EditHeightUI:Start()
	self.panel=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TerrainEditHeightBrush.xml"))
	
	self:SubscribeToEvent("Pressed", "EditHeightUI:HandleButtonPress")
	self:SubscribeToEvent("SliderChanged", "EditHeightUI:HandleSliderChanged")
	
	self.panel.style=uiStyle
	ui.root:AddChild(self.panel)
	self.active=true
	
	self.brushpreview=Image(context)
	self.brushpreview:SetSize(64,64,3)
	self.brushtex=Texture2D:new(context)
	--self.brushtex:SetSize(0,0,0,TEXTURE_DYNAMIC)
	self.panel:GetChild("BrushPreview",true).texture=self.brushtex
	
	self.power,self.max,self.radius,self.hardness,self.usemask=self:GetBrushSettings()
	self:GenerateBrushPreview()
	
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
	self.cursor:Show()
end

function EditHeightUI:GetBrushSettings()
	local power,max,radius,hardness=0,0,5,0.9
	local usemask0, usemask1, usemask2=false,false,false
	
	local slider
	slider=self.panel:GetChild("PowerSlider", true)
	if slider then power=(slider.value/slider.range)*4 end
	
	slider=self.panel:GetChild("MaxSlider", true)
	if slider then max=(slider.value/slider.range) end
	
	slider=self.panel:GetChild("RadiusSlider", true)
	if slider then radius=math.floor((slider.value/slider.range)*30) end
	
	slider=self.panel:GetChild("HardnessSlider", true)
	if slider then hardness=(slider.value/slider.range) end
	
	local button=self.panel:GetChild("Mask0Check", true)
	if button then usemask0=button.checked end
	
	button=self.panel:GetChild("Mask1Check", true)
	if button then usemask1=button.checked end
	
	button=self.panel:GetChild("Mask2Check", true)
	if button then usemask2=button.checked end
	
	return power,max,radius,math.min(1,hardness),usemask0, usemask1, usemask2
end

function EditHeightUI:GenerateBrushPreview()
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

function EditHeightUI:GetBrushPreview()
	return self.brushtex
end


function EditHeightUI:Activate()
	self.panel.visible=true
	self.active=true
	self:GenerateBrushPreview(self.hardness)
	self.cursor:BuildCursorMesh(self.radius)
	self.cursor:Show()
	self.cursor:SetBrushPreview(self.brushtex)
end

function EditHeightUI:Deactivate()
	self.panel.visible=false
	self.active=false
	self.cursor:Hide()
end

function EditHeightUI:SetHeight(ht)
	local slider=self.panel:GetChild("MaxSlider", true)
	if slider then slider.value=ht*slider.range end
	self:GenerateBrushPreview()
end

function EditHeightUI:HandleButtonPress(eventType, eventData)

end

function EditHeightUI:HandleSliderChanged(eventType, eventData)
	local which=eventData["Element"]:GetPtr("UIElement")
	if which==nil then return end
	
	self.power, self.max, self.radius, self.hardness, self.usemask0, self.usemask1, self.usemask2=self:GetBrushSettings(self.panel)
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

function EditHeightUI:Update(dt)
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
		self.power, self.max, self.radius, self.hardness, self.usemask0, self.usemask1, self.usemask2=self:GetBrushSettings()
		
		if input:GetMouseButtonDown(MOUSEB_LEFT) and ui:GetElementAt(mousepos.x, mousepos.y)==nil then
			if input:GetQualifierDown(QUAL_CTRL) then
				local norm=WorldToNormalized(TerrainState.hmap,TerrainState.terrain,ground)
				local col=TerrainState.hmap:GetPixelBilinear(norm.x,1-norm.y)
				local ht=0
				if TerrainState.hmap.components==1 then ht=col.r
				else ht=col.r+col.g/256.0
				end
				print(ht)
				
				self:SetHeight(ht)
			else
				local gx,gz=ground.x,ground.z
				ApplyHeightBrush(TerrainState.terrain,TerrainState.hmap,TerrainState.mask,gx,gz,self.radius, self.max, self.power, self.hardness, self.usemask0, self.usemask1, self.usemask2, dt) TerrainState.terrain:ApplyHeightMap()
			end
		end
	end
	
	self.cursor:SetBrushCursorHeight()
end
