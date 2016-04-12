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

function TerrainEditUI:Start()
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
	if self.blendbrush then self.blendbrush:LoadThumbnails(thumblist) end
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
		local ht=terrain:GetHeight(Vector3(c.position.x,0,c.position.z))
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
		mask:Clear(Color(1,1,1))
		masktex:SetData(mask)
	end
end

