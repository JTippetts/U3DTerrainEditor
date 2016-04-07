-- Terrain Editor UI

TerrainEditUI=ScriptObject()

uiStyle = cache:GetResource("XMLFile", "UI/DefaultStyle.xml")
ui.root.defaultStyle = uiStyle;
iconStyle = cache:GetResource("XMLFile", "UI/EditorIcons.xml");

function CreateCursor()
    local cursor = Cursor:new("Cursor")
    --cursor.defaultStyle=uiStyle
	--cursor.style=AUTO_STYLE
	cursor:SetStyleAuto(uiStyle)
    cursor:SetPosition(graphics.width / 2, graphics.height / 2)
    ui.cursor = cursor
	cursor.visible=true

end

function TerrainEditUI:Start()
	self.heightbrush=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TerrainEditHeightBrush.xml"))
	self.blendbrush=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TerrainEditBlendBrush.xml"))
	self.maskbrush=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TerrainEditMaskBrush.xml"))
	self.smoothbrush=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TerrainEditSmoothBrush.xml"))
	self.newterrain=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TerrainEditNewTerrain.xml"))
	self.toolbar=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TerrainEditToolbar.xml"))
	
	
	self.heightbrush.style=uiStyle
	self.blendbrush.style=uiStyle
	self.maskbrush.style=uiStyle
	self.newterrain.style=uiStyle
	self.toolbar.style=uiStyle
	self.smoothbrush.style=uiStyle
	
	self.brushpreview=Image(context)
	self.brushpreview:SetSize(64,64,3)
	self.brushtex=Texture2D:new(context)
	self.brushtex:SetSize(0,0,0,TEXTURE_DYNAMIC)
	
	self.heightbrush:GetChild("BrushPreview",true).texture=self.brushtex
	self.blendbrush:GetChild("BrushPreview",true).texture=self.brushtex
	self.maskbrush:GetChild("BrushPreview",true).texture=self.brushtex
	self.smoothbrush:GetChild("BrushPreview",true).texture=self.brushtex
	
	ui.root:AddChild(self.heightbrush)
	ui.root:AddChild(self.blendbrush)
	ui.root:AddChild(self.maskbrush)
	ui.root:AddChild(self.smoothbrush)
	ui.root:AddChild(self.newterrain)
	ui.root:AddChild(self.toolbar)
	
	
	self.mode=0
	self.blendbrush.visible=false
	self.maskbrush.visible=false
	self.newterrain.visible=false
	self.smoothbrush.visible=false
	self.toolbar.visible=true
	
	
	self:SubscribeToEvent("Pressed", "TerrainEditUI:HandleButtonPress")
	self:SubscribeToEvent("SliderChanged", "TerrainEditUI:HandleSliderChanged")
	
	self.brushcursornode=scene_:CreateChild()
	self.brushcursor=self.brushcursornode:CreateComponent("CustomGeometry")
	self.brushcursor:SetNumGeometries(1)
	self.brushmat=cache:GetResource("Material", "Materials/TerrainBrush.xml")
	self.brushmat:SetTexture(0, self.brushtex)
	self.brushcursor:SetMaterial(self.brushmat)
	
	self.waypointpreview=scene_:CreateComponent("CustomGeometry")
	self.waypointpreview:SetNumGeometries(1)
	self.waypointpreviewmaterial=cache:GetResource("Material", "Materials/WaypointPreview.xml")
	self.waypointpreview:SetMaterial(self.waypointpreviewmaterial)
	
	self.mode=0
	self:ActivateHeightBrush()
	
	self.counter=0
	-- Waypoints
	waypoints={}
end

function TerrainEditUI:UpdateWaypointVis()
	--print("1")
	self.waypointpreview:Clear()
	self.waypointpreview.occludee=false
	self.waypointpreview:SetNumGeometries(1)
	local c
	local spacing=terrain:GetSpacing()
	local plist=RasterVertexList()
	for _,c in ipairs(waypoints) do
		local pos=c.position
		local norm=WorldToNormalized(hmap,terrain,pos)
		local hx=math.floor(norm.x*hmap:GetWidth())
		local hy=math.floor(norm.y*hmap:GetHeight())
		local ht=GetHeightValue(hmap,hx,(hmap:GetHeight()-1)-hy)
		plist:push_back(RasterVertex(hx,hy,ht))
	end
	
	if plist:size()<4 then return end
	--print("Num waypoints: "..plist:size())
	local curve=RasterVertexList()
	TessellateLineList(plist, curve, 10)
	--print("Num curve points: "..curve:size())
	local quad=RasterVertexList()
	BuildQuadStrip(curve, quad, 8)
	--print("Num quad points: "..quad:size())
	
	self.waypointpreview:BeginGeometry(0,TRIANGLE_LIST)
	self.waypointpreview:SetDynamic(true)
	
	function buildVertex(rv)
		local nx=rv.x_/hmap:GetWidth()
		local ny=rv.y_/hmap:GetHeight()
		local v=NormalizedToWorld(hmap,terrain,Vector2(nx,ny))
		v.y=(rv.val_*255)*spacing.y
		return v
	end
	
	for c=0,quad:size()-4,2 do
		self.waypointpreview:DefineVertex(buildVertex(quad:at(c)))
		self.waypointpreview:DefineVertex(buildVertex(quad:at(c+1)))
		self.waypointpreview:DefineVertex(buildVertex(quad:at(c+2)))
		
		self.waypointpreview:DefineVertex(buildVertex(quad:at(c+1)))
		self.waypointpreview:DefineVertex(buildVertex(quad:at(c+2)))
		self.waypointpreview:DefineVertex(buildVertex(quad:at(c+3)))
		--print("hi")
		
	end
	
	self.waypointpreview:Commit()
	self.waypointpreview:SetMaterial(self.waypointpreviewmaterial)
	local bbox=self.waypointpreview.worldBoundingBox
	bbox:Define(Vector3(-1000,-1000,-1000), Vector3(1000,1000,1000))
end

function TerrainEditUI:LoadThumbnails(thumblist)
	local i
	for i=0,7,1 do
		local name="Terrain"..i
		local button=self.blendbrush:GetChild(name,true)
		if button then
			button.texture=cache:GetResource("Texture2D", thumblist[i+1])
		end
	end
	
end

function TerrainEditUI:AddWaypoint(groundx, groundz)
	local waynode=scene_:CreateChild()
	local model=waynode:CreateComponent("StaticModel")
	model.material=cache:GetResource("Material", "Materials/Flag.xml")
	model.model=cache:GetResource("Model", "Models/Flag.mdl")
	model.castShadows=false
	local ht=terrain:GetHeight(Vector3(groundx,0,groundz))
	waynode.position=Vector3(groundx, ht, groundz)
	waynode.scale=Vector3(0.25,0.25,0.25)
	table.insert(waypoints, waynode)
	self:UpdateWaypointVis()
end

function TerrainEditUI:GetBrushSettings(brush)
	local power,max,radius,hardness=0,0,5,0.9
	local usemask=false
	
	local slider
	slider=brush:GetChild("PowerSlider", true)
	if slider then power=(slider.value/slider.range)*4 end
	
	slider=brush:GetChild("MaxSlider", true)
	if slider then max=(slider.value/slider.range) end
	
	slider=brush:GetChild("RadiusSlider", true)
	if slider then radius=math.floor((slider.value/slider.range)*30) end
	
	slider=brush:GetChild("HardnessSlider", true)
	if slider then hardness=(slider.value/slider.range) end
	
	local button=brush:GetChild("MaskCheck", true)
	if button then usemask=button.checked end
	
	return power,max,radius,math.min(1,hardness),usemask
end

function TerrainEditUI:BuildCursorMesh(radius)
	self.brushcursor:BeginGeometry(0,TRIANGLE_LIST)
	self.brushcursor:SetDynamic(true)
	--self.brushcursor:SetMaterial(0, self.brushmat)
	
	local spacing=terrain:GetSpacing()
	local spacingx=spacing.x
	local spacingz=spacing.z
	local meshsize=math.floor(radius)*2+2
	local originx=(-meshsize)*spacingx*0.5
	local originz=(-meshsize)*spacingx*0.5
	
	local uvspacing=1/(meshsize-1)
	
	local x,z
	for x=0,meshsize-2,1 do
		for z=0,meshsize-2,1 do
			self.brushcursor:DefineVertex(Vector3(originx+x*spacingx, 0, originz+z*spacingz))
			self.brushcursor:DefineTexCoord(Vector2(x*uvspacing, z*uvspacing))
			
			self.brushcursor:DefineVertex(Vector3(originx+(x+1)*spacingx, 0, originz+(z+1)*spacingz))
			self.brushcursor:DefineTexCoord(Vector2((x+1)*uvspacing, (z+1)*uvspacing))
			
			self.brushcursor:DefineVertex(Vector3(originx+x*spacingx, 0, originz+(z+1)*spacingz))
			self.brushcursor:DefineTexCoord(Vector2(x*uvspacing, (z+1)*uvspacing))
			
			self.brushcursor:DefineVertex(Vector3(originx+x*spacingx, 0, originz+z*spacingz))
			self.brushcursor:DefineTexCoord(Vector2(x*uvspacing, z*uvspacing))
			
			self.brushcursor:DefineVertex(Vector3(originx+(x+1)*spacingx, 0, originz+z*spacingz))
			self.brushcursor:DefineTexCoord(Vector2((x+1)*uvspacing, z*uvspacing))
			
			self.brushcursor:DefineVertex(Vector3(originx+(x+1)*spacingx, 0, originz+(z+1)*spacingz))
			self.brushcursor:DefineTexCoord(Vector2((x+1)*uvspacing, (z+1)*uvspacing))
		end
	end
	
	self.brushcursor:Commit()
	
	self.brushcursor:SetMaterial(0, self.brushmat)
end

function TerrainEditUI:SetBrushCursorHeight()
	local mousepos
	if input.mouseVisible then
		mousepos=input:GetMousePosition()
	else
		mousepos=ui:GetCursorPosition()
	end
	
	local ground=cam:GetScreenGround(mousepos.x, mousepos.y)
	
	SetBrushCursorHeight(terrain, self.brushcursor, ground.x, ground.z)
end

function TerrainEditUI:ActivateHeightBrush()
	self.power, self.max, self.radius, self.hardness, self.usemask=self:GetBrushSettings(self.heightbrush)
	
	self:BuildCursorMesh(self.radius)
	self:GenerateBrushPreview(self.hardness)
	self.heightbrush:GetChild("BrushPreview",true):SetTexture(self.brushtex)
	self.heightbrush:GetChild("BrushPreview",true):SetImageRect(IntRect(0,0,63,63))
	self.heightbrush.visible=true
	self.blendbrush.visible=false
	self.maskbrush.visible=false
	self.smoothbrush.visible=false
	
	self.activebrush=self.heightbrush
	
	local text=self.activebrush:GetChild("PowerText", true)
	if text then text.text=string.format("%.1f", self.power) end
	text=self.activebrush:GetChild("RadiusText", true)
	if text then text.text=tostring(math.floor(self.radius)) end
	text=self.activebrush:GetChild("MaxText", true)
	if text then text.text=string.format("%.1f", self.max) end
	text=self.activebrush:GetChild("HardnessText", true)
	if text then text.text=string.format("%.2f", self.hardness) end
	
end

function TerrainEditUI:ActivateBlendBrush()
	self.power, self.max, self.radius, self.hardness, self.usemask=self:GetBrushSettings(self.blendbrush)
	
	self:BuildCursorMesh(self.radius)
	self:GenerateBrushPreview(self.hardness)
	self.blendbrush:GetChild("BrushPreview",true):SetTexture(self.brushtex)
	self.blendbrush:GetChild("BrushPreview",true):SetImageRect(IntRect(0,0,63,63))
	self.heightbrush.visible=false
	self.blendbrush.visible=true
	self.maskbrush.visible=false
	self.smoothbrush.visible=false
	
	local prev=self.blendbrush:GetChild("SelectedLayer", true)
	if prev then
		local whichbutton="Terrain"..(self.mode-1)
		local b=self.blendbrush:GetChild(whichbutton, true)
		if b then
			prev.texture=b.texture
		end
	end
	
	self.activebrush=self.blendbrush
	local text=self.activebrush:GetChild("PowerText", true)
	if text then text.text=string.format("%.1f", self.power) end
	text=self.activebrush:GetChild("RadiusText", true)
	if text then text.text=tostring(math.floor(self.radius)) end
	text=self.activebrush:GetChild("MaxText", true)
	if text then text.text=string.format("%.1f", self.max) end
	text=self.activebrush:GetChild("HardnessText", true)
	if text then text.text=string.format("%.2f", self.hardness) end
end

function TerrainEditUI:ActivateSmoothBrush()
	self.power, self.max, self.radius, self.hardness, self.usemask=self:GetBrushSettings(self.smoothbrush)
	
	self:BuildCursorMesh(self.radius)
	self:GenerateBrushPreview(self.hardness)
	self.blendbrush:GetChild("BrushPreview",true):SetTexture(self.brushtex)
	self.blendbrush:GetChild("BrushPreview",true):SetImageRect(IntRect(0,0,63,63))
	self.heightbrush.visible=false
	self.blendbrush.visible=false
	self.maskbrush.visible=false
	self.smoothbrush.visible=true
	
	self.activebrush=self.smoothbrush
	local text=self.activebrush:GetChild("PowerText", true)
	if text then text.text=string.format("%.1f", self.power) end
	text=self.activebrush:GetChild("RadiusText", true)
	if text then text.text=tostring(math.floor(self.radius)) end
	text=self.activebrush:GetChild("MaxText", true)
	if text then text.text=string.format("%.1f", self.max) end
	text=self.activebrush:GetChild("HardnessText", true)
	if text then text.text=string.format("%.2f", self.hardness) end
end

function TerrainEditUI:ActivateMaskBrush()
	self.power, self.max, self.radius, self.hardness, self.usemask=self:GetBrushSettings(self.maskbrush)
	
	self:BuildCursorMesh(self.radius)
	self:GenerateBrushPreview(self.hardness)
	self.blendbrush:GetChild("BrushPreview",true):SetTexture(self.brushtex)
	self.blendbrush:GetChild("BrushPreview",true):SetImageRect(IntRect(0,0,63,63))
	self.heightbrush.visible=false
	self.blendbrush.visible=false
	self.maskbrush.visible=true
	self.newterrain.visible=false
	self.smoothbrush.visible=false
	
	self.activebrush=self.maskbrush
	local text=self.activebrush:GetChild("PowerText", true)
	if text then text.text=string.format("%.1f", self.power) end
	text=self.activebrush:GetChild("RadiusText", true)
	if text then text.text=tostring(math.floor(self.radius)) end
	text=self.activebrush:GetChild("MaxText", true)
	if text then text.text=string.format("%.1f", self.max) end
	text=self.activebrush:GetChild("HardnessText", true)
	if text then text.text=string.format("%.2f", self.hardness) end
end



function TerrainEditUI:Update(dt)
	self.counter=self.counter+dt
	if self.counter>4 then
		self.counter=self.counter-4
		print("Used mem: "..collectgarbage("count"))
		collectgarbage()
	end
	local mousepos
	if input.mouseVisible then
		mousepos=input:GetMousePosition()
	else
		mousepos=ui:GetCursorPosition()
	end
	
	local ground=cam:GetScreenGround(mousepos.x, mousepos.y)
	
	if ground then 
		local world=Vector3(ground.x,0,ground.z)
		self.brushcursornode:SetPosition(world)
	
		self.power, self.max, self.radius, self.hardness, self.usemask=self:GetBrushSettings(self.activebrush)
	
		self:SetBrushCursorHeight()
	end

	
	if input:GetMouseButtonDown(MOUSEB_LEFT) and ui:GetElementAt(mousepos.x, mousepos.y)==nil then
		-- If CTRL is down and we are in mode==0 then grab the terrain height at the cursor instead
		if self.mode==0 and input:GetQualifierDown(QUAL_CTRL) then
			local ground=cam:PickGround(mousepos.x, mousepos.y)
			if ground~=nil then
				local norm=WorldToNormalized(hmap,terrain,ground)
				local col=hmap:GetPixelBilinear(norm.x,1-norm.y)
				local ht=0
				if hmap.components==1 then ht=col.r
				else ht=col.r+col.g/256.0
				end
				print(ht)
				
				local slider=self.activebrush:GetChild("MaxSlider", true)
				if slider then slider.value=ht*slider.range end
				self.power, self.max, self.radius, self.hardness, self.usemask=self:GetBrushSettings(self.activebrush)
				self:GenerateBrushPreview(self.hardness)
			end
		else
			local ground=cam:GetScreenGround(mousepos.x, mousepos.y)
			if ground~=nil then
				local gx,gz=ground.x,ground.z
			
				if self.mode==0 then ApplyHeightBrush(terrain,hmap,mask,gx,gz,self.radius, self.max, self.power, self.hardness, self.usemask, dt) terrain:ApplyHeightMap()
				elseif self.mode>=1 and self.mode<=8 then ApplyBlendBrush8(terrain,hmap,blend1,blend2,mask,gx,gz,self.radius,self.max,self.power,self.hardness,self.mode-1,self.usemask,dt) blendtex1:SetData(blend1) blendtex2:SetData(blend2)
				elseif self.mode==9 then ApplySmoothBrush(terrain,hmap,mask,gx,gz,self.radius, self.max, self.power, self.hardness, self.usemask, dt) terrain:ApplyHeightMap()
				else ApplyMaskBrush(terrain,hmap,mask,gx,gz,self.radius,self.max,self.power,self.hardness,dt) masktex:SetData(mask)
				end
			end
			
		end
	elseif input:GetKeyPress(KEY_W) then
		local mouseground=cam:PickGround(mousepos.x, mousepos.y)
		self:AddWaypoint(mouseground.x, mouseground.z)
		
	elseif input:GetKeyPress(KEY_Q) then
		if(#waypoints>0) then
			waypoints[#waypoints]:Remove()
			table.remove(waypoints)
		end
		self:UpdateWaypointVis()
	end
	
	local c
	for _,c in ipairs(waypoints) do
		local ht=terrain:GetHeight(Vector3(c.position.x,0,c.position.z))
		c.position=Vector3(c.position.x,ht,c.position.z)
	end
	self:UpdateWaypointVis()
end

function TerrainEditUI:GenerateBrushPreview(sharpness)
	local w,h=self.brushpreview:GetWidth(), self.brushpreview:GetHeight()
	local rad=w/2
	local x,y
	for x=0,w-1,1 do
		for y=0,h-1,1 do
			local dx=x-w/2
			local dy=y-h/2
			local d=math.sqrt(dx*dx+dy*dy)
			--local i=(rad-d)/rad
			local i=(d-rad)/(sharpness*rad-rad)
			i=math.max(0, math.min(1,i))
				
			self.brushpreview:SetPixel(x,y,Color(i*0.5,i*0.5,i*0.6))
		end
	end
	
	self.brushtex:SetData(self.brushpreview, false)
end

function TerrainEditUI:HandleButtonPress(eventType, eventData)
	local which=eventData["Element"]:GetPtr("UIElement")
	local name=which:GetName()
	if name=="HeightButton" then
		self.mode=0		
		self:ActivateHeightBrush()
		
	elseif name=="SmoothButton" then
		self.mode=9
		self:ActivateSmoothBrush()
	
	elseif name=="TerrainButton" then
		if self.lastterrain and (self.lastterrain>=1 and self.lastterrain<=8) then
			self.mode=self.lastterrain
			self:ActivateBlendBrush()
		else
			self.lastterrain=1
			self.mode=1
			self:ActivateBlendBrush()
		end
	
	elseif name=="Terrain0" then
		self.lastterrain=1
		self.mode=1
		self:ActivateBlendBrush()
	
	elseif  name=="Terrain1" then
		self.lastterrain=2
		self.mode=2
		self:ActivateBlendBrush()
	
	elseif name=="Terrain2" then
		self.lastterrain=3
		self.mode=3
		self:ActivateBlendBrush()
	
	elseif name=="Terrain3" then
		self.lastterrain=4
		self.mode=4
		self:ActivateBlendBrush()
	elseif name=="Terrain4" then
		self.lastterrain=5
		self.mode=5
		self:ActivateBlendBrush()
	elseif name=="Terrain5" then
		self.lastterrain=6
		self.mode=6
		self:ActivateBlendBrush()
	elseif name=="Terrain6" then
		self.lastterrain=7
		self.mode=7
		self:ActivateBlendBrush()
	elseif name=="Terrain7"  then
		self.lastterrain=8
		self.mode=8
		self:ActivateBlendBrush()
	elseif name=="MaskButton" then
		self.mode=10
		self:ActivateMaskBrush()
	elseif name=="ClearMask" then
		mask:Clear(Color(1,1,1))
		masktex:SetData(mask)
	end
	
end

function TerrainEditUI:HandleSliderChanged(eventType, eventData)
	local which=eventData["Element"]:GetPtr("UIElement")
	if which==nil then return end
	
	self.power, self.max, self.radius, self.hardness, self.usemask=self:GetBrushSettings(self.activebrush)
	self:BuildCursorMesh(self.radius)
	self:GenerateBrushPreview(self.hardness)
	
	if which==self.activebrush:GetChild("PowerSlider", true) then
		local text=self.activebrush:GetChild("PowerText", true)
		if text then text.text=string.format("%.2f", self.power) end
	elseif which==self.activebrush:GetChild("RadiusSlider", true) then
		local text=self.activebrush:GetChild("RadiusText", true)
		if text then text.text=tostring(math.floor(self.radius)) end
	elseif which==self.activebrush:GetChild("MaxSlider", true) then
		local text=self.activebrush:GetChild("MaxText", true)
		if text then text.text=string.format("%.2f", self.max) end
	elseif which==self.activebrush:GetChild("HardnessSlider", true) then
		local text=self.activebrush:GetChild("HardnessText", true)
		if text then text.text=string.format("%.3f", self.hardness) end
	end
end

