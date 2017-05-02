-- Terrain Editor UI

require 'LuaScripts/terrainselectui'
require 'LuaScripts/editheightui'
require 'LuaScripts/smoothheightui'
require 'LuaScripts/editmaskui'

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

function TerrainEditUI:BuildUI()
	self.heightbrush=scene_:CreateScriptObject("EditHeightUI")
	self.blendbrush=scene_:CreateScriptObject("TerrainSelectUI")
	self.smoothbrush=scene_:CreateScriptObject("SmoothHeightUI")
	self.maskbrush=scene_:CreateScriptObject("EditMaskUI")
	self.newterrain=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TerrainEditNewTerrain.xml"))
	self.toolbar=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TerrainEditToolbar.xml"))
	
	
	self.blendbrush:Deactivate()
	self.maskbrush:Deactivate()
	self.smoothbrush:Deactivate()
	
	self.newterrain.style=uiStyle
	self.toolbar.style=uiStyle
	
	ui.root:AddChild(self.newterrain)
	ui.root:AddChild(self.toolbar)
	
	
	self.newterrain.visible=false
	self.toolbar.visible=true
	
	
	self:SubscribeToEvent("Pressed", "TerrainEditUI:HandleButtonPress")


	self.waypointpreview=scene_:CreateComponent("CustomGeometry")
	self.waypointpreview:SetNumGeometries(1)
	self.waypointpreviewmaterial=cache:GetResource("Material", "Materials/WaypointPreview.xml")
	self.waypointpreview:SetMaterial(self.waypointpreviewmaterial)
	
	self:ActivateHeightBrush()
	
	
	self.counter=0
	-- Waypoints
	waypoints={}
end

function TerrainEditUI:Start()
	
end

function TerrainEditUI:NewTerrain(width, height, blendwidth, blendheight, triplanar, smoothing)
	if TerrainState.terrainNode then TerrainState.terrainNode:Remove() end
	
	TerrainState.terrainNode=scene_:CreateChild()
	TerrainState.terrain=TerrainState.terrainNode:CreateComponent("Terrain")
	TerrainState.terrain.patchSize=64
	TerrainState.terrain.spacing=Vector3(1,0.5,1)
	TerrainState.terrain.smoothing=false
	
	if TerrainState.hmap then TerrainState.hmap:delete() end
	TerrainState.hmap=Image:new(context)
	TerrainState.hmap:SetSize(width, height, 3)
	TerrainState.hmap:Clear(Color(0,0,0))
	TerrainState.terrain.heightMap=TerrainState.hmap
	TerrainState.terrain.castShadows=true
	
	self:SetMaterial(blendwidth, blendheight, triplanar, smoothing)
end

function TerrainEditUI:SetMaterial(blendwidth, blendheight, triplanar, smoothing)
	if triplanar then
		if smoothing then
			TerrainState.terrainMaterial=cache:GetResource("Material", "Materials/TerrainEdit8TriplanarSmooth.xml")
		else
			TerrainState.terrainMaterial=cache:GetResource("Material", "Materials/TerrainEdit8Triplanar.xml")
		end
	else
		if smoothing then
			TerrainState.terrainMaterial=cache:GetResource("Material", "Materials/TerrainEdit8Smooth.xml")
		else
			TerrainState.terrainMaterial=cache:GetResource("Material", "Materials/TerrainEdit8.xml")
		end
	end
	
	if TerrainState.blendtex1 then TerrainState.blendtex1:delete() end
	if TerrainState.blendtex2 then TerrainState.blendtex2:delete() end
	if TerrainState.blend1 then TerrainState.blend1:delete() end
	if TerrainState.blend2 then TerrainState.blend2:delete() end
	
	TerrainState.blend1=Image:new(context)
	TerrainState.blend1:SetSize(blendwidth, blendheight, 4)
	TerrainState.blend2=Image:new(context)
	TerrainState.blend2:SetSize(blendwidth, blendheight, 4)
	TerrainState.blendtex1=Texture2D:new(context)
	TerrainState.blendtex2=Texture2D:new(context)
	TerrainState.blend1:Clear(Color(1,0,0,0))
	TerrainState.blend2:Clear(Color(0,0,0,0))
	TerrainState.blendtex1:SetData(TerrainState.blend1, false)
	TerrainState.blendtex2:SetData(TerrainState.blend2, false)
	
	if TerrainState.masktex then TerrainState.masktex:delete() end
	if TerrainState.mask then TerrainState.mask:delete() end
	
	TerrainState.mask=Image:new(context)
	TerrainState.mask:SetSize(blendwidth, blendheight, 3)
	TerrainState.masktex=Texture2D:new(context)
	TerrainState.mask:Clear(Color(1,1,1))
	TerrainState.masktex:SetData(TerrainState.mask, false)
	
	if TerrainState.terrainMaterial then
		TerrainState.terrainMaterial:SetTexture(0, TerrainState.blendtex1)
		TerrainState.terrainMaterial:SetTexture(1, TerrainState.blendtex2)
		TerrainState.terrainMaterial:SetTexture(4, TerrainState.masktex)
		
		if TerrainState.terrain then
			TerrainState.terrain.material=TerrainState.terrainMaterial
		end
	end
end

function TerrainEditUI:UpdateWaypointVis()
	--print("1")
	self.waypointpreview:Clear()
	self.waypointpreview.occludee=false
	self.waypointpreview:SetNumGeometries(1)
	local c
	local spacing=TerrainState.terrain:GetSpacing()
	local plist=RasterVertexList()
	for _,c in ipairs(waypoints) do
		local pos=c.position
		local norm=WorldToNormalized(TerrainState.hmap,TerrainState.terrain,pos)
		local hx=math.floor(norm.x*TerrainState.hmap:GetWidth())
		local hy=math.floor(norm.y*TerrainState.hmap:GetHeight())
		local ht=GetHeightValue(TerrainState.hmap,hx,(TerrainState.hmap:GetHeight()-1)-hy)
		plist:push_back(RasterVertex(hx,hy,ht))
	end
	
	if plist:size()<4 then return end
	--print("Num waypoints: "..plist:size())
	local curve=RasterVertexList()
	TessellateLineList(plist, curve, 10)
	--print("Num curve points: "..curve:size())
	local quad=RasterVertexList()
	BuildQuadStrip(curve, quad, 4)
	--print("Num quad points: "..quad:size())
	
	self.waypointpreview:BeginGeometry(0,TRIANGLE_LIST)
	self.waypointpreview:SetDynamic(true)
	
	function buildVertex(rv)
		local nx=rv.x_/TerrainState.hmap:GetWidth()
		local ny=rv.y_/TerrainState.hmap:GetHeight()
		local v=NormalizedToWorld(TerrainState.hmap,TerrainState.terrain,Vector2(nx,ny))
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
	if self.blendbrush then self.blendbrush:LoadThumbnails(thumblist) end
end

function TerrainEditUI:AddWaypoint(groundx, groundz)
	local waynode=scene_:CreateChild()
	local model=waynode:CreateComponent("StaticModel")
	model.material=cache:GetResource("Material", "Materials/Flag.xml")
	model.model=cache:GetResource("Model", "Models/Flag.mdl")
	model.castShadows=false
	local ht=TerrainState.terrain:GetHeight(Vector3(groundx,0,groundz))
	waynode.position=Vector3(groundx, ht, groundz)
	waynode.scale=Vector3(0.25,0.25,0.25)
	table.insert(waypoints, waynode)
	self:UpdateWaypointVis()
end


function TerrainEditUI:ActivateHeightBrush()
	self.heightbrush:Activate()
	self.blendbrush:Deactivate()
	self.maskbrush:Deactivate()
	self.smoothbrush:Deactivate()
end

function TerrainEditUI:ChangeBlendBrush(layer)

end

function TerrainEditUI:ActivateBlendBrush()
	self.heightbrush:Deactivate()
	self.maskbrush:Deactivate()
	self.smoothbrush:Deactivate()
	self.blendbrush:Activate()
end

function TerrainEditUI:ActivateSmoothBrush()
	self.heightbrush:Deactivate()
	self.blendbrush:Deactivate()
	self.maskbrush:Deactivate()
	self.smoothbrush:Activate()
	
end

function TerrainEditUI:ActivateMaskBrush()
	self.heightbrush:Deactivate()
	self.blendbrush:Deactivate()
	self.maskbrush:Activate()
	self.smoothbrush:Deactivate()
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
	
	if input:GetKeyPress(KEY_W) then
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
		local ht=TerrainState.terrain:GetHeight(Vector3(c.position.x,0,c.position.z))
		c.position=Vector3(c.position.x,ht,c.position.z)
	end
	self:UpdateWaypointVis()
end

function TerrainEditUI:HandleButtonPress(eventType, eventData)
	local which=eventData["Element"]:GetPtr("UIElement")
	local name=which:GetName()
	if name=="HeightButton" then
		self:ActivateHeightBrush()
	elseif name=="SmoothButton" then
		self:ActivateSmoothBrush()
	elseif name=="TerrainButton" then
		self:ActivateBlendBrush()
	elseif name=="MaskButton" then
		self:ActivateMaskBrush()
	elseif name=="ClearMask" then
		TerrainState.mask:Clear(Color(1,1,1))
		TerrainState.masktex:SetData(TerrainState.mask)
	end
end

