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
    cursor = Cursor:new("Cursor")
    --cursor.defaultStyle=uiStyle
	--cursor.style=AUTO_STYLE
	cursor:SetStyleAuto(uiStyle)
    cursor:SetPosition(graphics.width / 2, graphics.height / 2)
    ui.cursor = cursor
	cursor.visible=true

end

function TerrainEditUI:BuildUI()
	self.heightbrush=scene_:CreateScriptObject("EditHeightUI")
	self.smoothbrush=scene_:CreateScriptObject("SmoothHeightUI")
	self.maskbrush=scene_:CreateScriptObject("EditMaskUI")
	self.newterrain=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TerrainEditNewTerrain.xml"))
	self.toolbar=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TerrainMainToolbar.xml"))
	self.blendbrush=scene_:CreateScriptObject("TerrainSelectUI")
	
	self.nodegraph=scene_:CreateScriptObject("NodeGraphUI")
	--self.nodegroup=self.nodegraph:CreateNodeGroup()
	self.nodegraph:Deactivate()
	
	self.nodegroups={}
	
	self.nodegroupslist=ui:LoadLayout(cache:GetResource("XMLFile", "UI/NoiseNodeGroups.xml"))
	local list=self.nodegroupslist:GetChild("List",true)
	ui.root:AddChild(self.nodegroupslist)
	list:SetStyle("ListView", cache:GetResource("XMLFile", "UI/DefaultStyle.xml"))
	list.highlightMode=HM_ALWAYS
	self:SubscribeToEvent(self.nodegroupslist:GetChild("New", true), "Pressed", "TerrainEditUI:HandleNewGroup")
	self:SubscribeToEvent(self.nodegroupslist:GetChild("Open", true), "Pressed", "TerrainEditUI:HandleOpenGroup")
	self:SubscribeToEvent(self.nodegroupslist:GetChild("Delete", true), "Pressed", "TerrainEditUI:HandleDeleteGroup")
	self:SubscribeToEvent(self.nodegroupslist:GetChild("Edit", true), "Pressed", "TerrainEditUI:HandleEditGroup")
	self:SubscribeToEvent(self.nodegroupslist:GetChild("Map", true), "Pressed", "TerrainEditUI:HandleMapGroup")
	
	self.nodegroupslist:SetPosition(IntVector2(graphics.width-self.nodegroupslist.width, graphics.height-self.nodegroupslist.height))
	
	self.nodemapping=ui:LoadLayout(cache:GetResource("XMLFile", "UI/MapNodeWindow.xml"))
	ui.root:AddChild(self.nodemapping)
	list=self.nodemapping:GetChild("TargetList",true)
	local smtypes=
	{
		"Terrain",
		"Layer 1",
		"Layer 2",
		"Layer 3",
		"Layer 4",
		"Layer 5",
		"Layer 6",
		"Layer 7",
		"Layer 8",
		"Mask 1",
		"Mask 2",
		"Mask 3"
	}
	
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
	self:SubscribeToEvent(self.nodemapping:GetChild("Go",true), "Pressed", "TerrainEditUI:HandleMakeItHappen")
	self:SubscribeToEvent(self.nodemapping:GetChild("Close",true),"Pressed","TerrainEditUI:HandleCloseMapping")
	self.nodemapping.visible=false
	
	
	self.blendbrush:Deactivate()
	self.maskbrush:Deactivate()
	self.smoothbrush:Deactivate()
	self.heightbrush:Deactivate()
	
	self.nodegroupslist.visible=false
	
	self.newterrain.style=uiStyle
	self.toolbar.style=uiStyle
	
	ui.root:AddChild(self.newterrain)
	ui.root:AddChild(self.toolbar)
	
	
	self.newterrain.visible=false
	self.toolbar.visible=true
	
	
	self:SubscribeToEvent("Pressed", "TerrainEditUI:HandleButtonPress")
	
	self:SubscribeToEvent(self.toolbar:GetChild("TerrainSettings",true), "Toggled", "TerrainEditUI:HandleToggled")
	self:SubscribeToEvent(self.toolbar:GetChild("EditHeight",true), "Toggled", "TerrainEditUI:HandleToggled")
	self:SubscribeToEvent(self.toolbar:GetChild("SmoothHeight",true), "Toggled", "TerrainEditUI:HandleToggled")
	self:SubscribeToEvent(self.toolbar:GetChild("EditLayer",true), "Toggled", "TerrainEditUI:HandleToggled")
	self:SubscribeToEvent(self.toolbar:GetChild("EditMask",true), "Toggled", "TerrainEditUI:HandleToggled")
	self:SubscribeToEvent(self.toolbar:GetChild("EditNoiseGraphs",true), "Toggled", "TerrainEditUI:HandleToggled")
	self:SubscribeToEvent(self.toolbar:GetChild("EditWaypoints",true), "Toggled", "TerrainEditUI:HandleToggled")
	self:SubscribeToEvent(self.toolbar:GetChild("Filters",true), "Toggled", "TerrainEditUI:HandleToggled")


	self.waypointpreview=scene_:CreateComponent("CustomGeometry")
	self.waypointpreview:SetNumGeometries(1)
	self.waypointpreviewmaterial=cache:GetResource("Material", "Materials/WaypointPreview.xml")
	self.waypointpreview:SetMaterial(self.waypointpreviewmaterial)
	
	--self:ActivateHeightBrush()
	
	self.counter=0
	-- Waypoints
	waypoints={}
	
	self.nodegroupcounter=0
end


function TerrainEditUI:Start()
	
end

function TerrainEditUI:HandleNewGroup(eventType, eventData)
	local newgroup=self.nodegraph:CreateNodeGroup()
	local name="Group "..self.nodegroupcounter
	self.nodegroupcounter=self.nodegroupcounter+1
	local list=self.nodegroupslist:GetChild("List",true)
	local sel=list.selection
	
	local t=Text:new()
	t:SetStyle("FileSelectorListText", cache:GetResource("XMLFile","UI/DefaultStyle.xml"))
	t.text=name
	list:AddItem(t)
	list.selection=list:GetNumItems()-1
	table.insert(self.nodegroups, newgroup)
	
end

function TerrainEditUI:HandleOpenGroup(eventType, eventData)

end

function TerrainEditUI:HandleDeleteGroup(eventType, eventData)

end

function TerrainEditUI:HandleEditGroup(eventType, eventData)
	local which=self.nodegroupslist:GetChild("List",true).selection
	if which==-1 then return end
	self.nodegroup=self.nodegroups[which+1]
	if not self.nodegroup then return end
	self.nodegraph:Activate(self.nodegroup)
end

function TerrainEditUI:HandleMapGroup(eventType, eventData)
	local which=self.nodegroupslist:GetChild("List",true).selection
	if which==-1 then return end
	
	self.currentnodegroup=which
	self.nodegroup=self.nodegroups[self.currentnodegroup+1]
	self.nodemapping.visible=true
end

function TerrainEditUI:HandleMakeItHappen(eventType, eventData)
	if not self.currentnodegroup then return end
	self.nodegroup=self.nodegroups[self.currentnodegroup+1]
	
	local target=self.nodemapping:GetChild("TargetList",true).selection
	
	local um1,im1=self.nodemapping:GetChild("UseMask1",true).checked,self.nodemapping:GetChild("InvertMask1",true).checked
	local um2,im2=self.nodemapping:GetChild("UseMask2",true).checked,self.nodemapping:GetChild("InvertMask2",true).checked
	local um3,im3=self.nodemapping:GetChild("UseMask3",true).checked,self.nodemapping:GetChild("InvertMask3",true).checked
	local ms=MaskSettings(um1,im1,um2,im2,um3,im3)
	
	local low=tonumber(self.nodemapping:GetChild("Low",true).text) or 0.0
	local high=tonumber(self.nodemapping:GetChild("High",true).text) or 1.0
	
	if target==0 then
		-- Map terrain
		if not self.nodegroup then return end
		local kernel=PackNodeGraph(self.nodegroup.output)
		local arr=CArray2Dd(TerrainState:GetTerrainWidth(), TerrainState:GetTerrainHeight())
		map2DNoZ(SEAMLESS_NONE,arr,kernel,SMappingRanges(0,1,0,1,0,1), kernel:lastIndex())
		arr:scaleToRange(low,high)
		TerrainState:SetHeightBuffer(arr,ms)
		self.nodemapping.visible=false
		saveDoubleArray("map.png",arr)
		return
	elseif target>=1 and target<=8 then
		if not self.nodegroup then return end
		local kernel=PackNodeGraph(self.nodegroup.output)
		local arr=CArray2Dd(TerrainState:GetBlendWidth(), TerrainState:GetBlendHeight())
		map2DNoZ(SEAMLESS_NONE,arr,kernel,SMappingRanges(0,1,0,1,0,1), kernel:lastIndex())
		arr:scaleToRange(low,high)
		TerrainState:SetLayerBuffer(arr,target-1,ms)
		self.nodemapping.visible=false
		return
	elseif target>=9 and target<=11 then
		if not self.nodegroup then return end
		local kernel=PackNodeGraph(self.nodegroup.output)
		local arr=CArray2Dd(TerrainState:GetTerrainWidth(), TerrainState:GetTerrainHeight())
		map2DNoZ(SEAMLESS_NONE,arr,kernel,SMappingRanges(0,1,0,1,0,1), kernel:lastIndex())
		arr:scaleToRange(low,high)
		print("Setting to mask "..target-9)
		TerrainState:SetMaskBuffer(arr,target-9)
		self.nodemapping.visible=false
	end
end

function TerrainEditUI:HandleCloseMapping(eventType, eventData)
	self.nodemapping.visible=false
end

function TerrainEditUI:NewTerrain(width, height, blendwidth, blendheight, triplanar, smoothing, normalmapping)
	print("setting up new terrain.")
	TerrainState:Initialize(scene_,width,height,blendwidth,blendheight,Vector3(1,0.5,1),true)
	print("terrain set up")
end

function TerrainEditUI:SetMaterial(blendwidth, blendheight, triplanar, smoothing, normalmapping)
	
end

function TerrainEditUI:UpdateWaypointVis()
	--print("1")
	self.waypointpreview:Clear()
	self.waypointpreview.occludee=false
	self.waypointpreview:SetNumGeometries(1)
	local c
	--print("1")
	local spacing=TerrainState:GetTerrain():GetSpacing()
	local plist=RasterVertexList()
	--print("2")
	for _,c in ipairs(waypoints) do
		local pos=c.position
		--local norm=WorldToNormalized(TerrainState.hmap,TerrainState.terrain,pos)
		--local norm=TerrainState:WorldToNormalized(pos)
		--local hx=math.floor(norm.x*TerrainState.hmap:GetWidth())
		--local hy=math.floor(norm.y*TerrainState.hmap:GetHeight())
		--local ht=GetHeightValue(TerrainState.hmap,hx,(TerrainState.hmap:GetHeight()-1)-hy)
		
		local norm=TerrainState:WorldToNormalized(pos)
		local hx=math.floor(norm.x*TerrainState:GetTerrainWidth())
		local hy=math.floor(norm.y*TerrainState:GetTerrainHeight())
		local ht=TerrainState:GetHeightValue(hx,(TerrainState:GetTerrainHeight()-1)-hy)
		plist:push_back(RasterVertex(hx, hy, ht))
	end
	--print("3")
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
		--local nx=rv.x_/TerrainState.hmap:GetWidth()
		--local ny=rv.y_/TerrainState.hmap:GetHeight()
		--local v=TerrainState:NormalizedToWorld(Vector2(nx,ny))
		--v.y=(rv.val_*255)*spacing.y
		--local v=TerrainState:GetTerrain():HeightMapToWorld(IntVector2(rv.x_, rv.y_))
		
		local nx=rv.x_/TerrainState:GetTerrainWidth()
		local ny=rv.y_/TerrainState:GetTerrainHeight()
		local v=TerrainState:NormalizedToWorld(Vector2(nx,ny))
		v.y=(rv.val_*255)*spacing.y
		return v
	end
	
	--print("build geom")
	for c=0,quad:size()-4,2 do
		self.waypointpreview:DefineVertex(buildVertex(quad:at(c)))
		self.waypointpreview:DefineVertex(buildVertex(quad:at(c+1)))
		self.waypointpreview:DefineVertex(buildVertex(quad:at(c+2)))
		
		self.waypointpreview:DefineVertex(buildVertex(quad:at(c+1)))
		self.waypointpreview:DefineVertex(buildVertex(quad:at(c+2)))
		self.waypointpreview:DefineVertex(buildVertex(quad:at(c+3)))
		--print("hi")
		
	end
	--print("end")
	self.waypointpreview:Commit()
	self.waypointpreview:SetMaterial(self.waypointpreviewmaterial)
	local bbox=self.waypointpreview.worldBoundingBox
	bbox:Define(Vector3(-1000,-1000,-1000), Vector3(1000,1000,1000))
end

function TerrainEditUI:AddWaypoint(groundx, groundz)
	local waynode=scene_:CreateChild()
	local model=waynode:CreateComponent("StaticModel")
	model.material=cache:GetResource("Material", "Materials/Flag.xml")
	model.model=cache:GetResource("Model", "Models/Flag.mdl")
	model.castShadows=false
	local ht=TerrainState:GetTerrain():GetHeight(Vector3(groundx,0,groundz))
	waynode.position=Vector3(groundx, ht, groundz)
	waynode.scale=Vector3(0.25,0.25,0.25)
	table.insert(waypoints, waynode)
	print("uwv")
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

function TerrainEditUI:ActivateMaskBrush(which)
	self.heightbrush:Deactivate()
	self.blendbrush:Deactivate()
	self.maskbrush:Activate(which)
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
	
	if input:GetKeyPress(KEY_E) then
		local mouseground=cam:PickGround(mousepos.x, mousepos.y)
		self:AddWaypoint(mouseground.x, mouseground.z)
		
	elseif input:GetKeyPress(KEY_Q) then
		if(#waypoints>0) then
			waypoints[#waypoints]:Remove()
			table.remove(waypoints)
		end
		self:UpdateWaypointVis()
	elseif input:GetKeyPress(KEY_N) then
		--self.nodegraph:Activate(self.nodegroup)
	elseif input:GetKeyPress(KEY_M) then
		self.nodegraph:Deactivate()
	end
	
	local c
	for _,c in ipairs(waypoints) do
		local ht=TerrainState:GetTerrain():GetHeight(Vector3(c.position.x,0,c.position.z))
		c.position=Vector3(c.position.x,ht,c.position.z)
	end
	self:UpdateWaypointVis()
end

function TerrainEditUI:UncheckToolbar(except)
	if except~="TerrainSettings" then self.toolbar:GetChild("TerrainSettings",true).checked=false saveloadui:Deactivate() end
	if except~="EditHeight" then self.toolbar:GetChild("EditHeight",true).checked=false self.heightbrush:Deactivate() end
	if except~="SmoothHeight" then self.toolbar:GetChild("SmoothHeight",true).checked=false self.smoothbrush:Deactivate() end
	if except~="EditLayer" then self.toolbar:GetChild("EditLayer",true).checked=false self.blendbrush:Deactivate() end
	if except~="EditMask" then self.toolbar:GetChild("EditMask",true).checked=false self.maskbrush:Deactivate() end
	if except~="EditNoiseGraphs" then self.toolbar:GetChild("EditNoiseGraphs",true).checked=false self.nodegroupslist.visible=false end
	if except~="EditWaypoints" then self.toolbar:GetChild("EditWaypoints",true).checked=false end
	if except~="Filters" then self.toolbar:GetChild("Filters",true).checked=false filterui:Deactivate() end
end

function TerrainEditUI:HandleToggled(eventType,eventData)
	local e=eventData["Element"]:GetPtr("UIElement")
	local name=e:GetName()
	if eventData["State"]:GetBool() then
		self:UncheckToolbar(name)
	end
	
	if name=="TerrainSettings" then
		if eventData["State"]:GetBool() then
			saveloadui:Activate()
		else
			saveloadui:Deactivate()
		end
	elseif name=="EditHeight" then
		if eventData["State"]:GetBool() then
			self.heightbrush:Activate()
		else self.heightbrush:Deactivate()
		end
	elseif name=="SmoothHeight" then
		if eventData["State"]:GetBool() then
			self.smoothbrush:Activate()
		else
			self.smoothbrush:Deactivate()
		end
	elseif name=="EditLayer" then
		if eventData["State"]:GetBool() then
			self.blendbrush:Activate()
		else
			self.blendbrush:Deactivate()
		end
	elseif name=="EditMask" then
		if eventData["State"]:GetBool() then
			self.maskbrush:Activate(0)
		else
			self.maskbrush:Deactivate()
		end
	elseif name=="EditNoiseGraphs" then
		if eventData["State"]:GetBool() then
			self.nodegroupslist.visible=true
		else
			self.nodegroupslist.visible=false
		end
	elseif name=="EditWaypoints" then
		-- TODO
	elseif name=="Filters" then
		if eventData["State"]:GetBool() then
			filterui:Activate()
		else
			filterui:Deactivate()
		end
		
	end
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
	elseif name=="Mask0Button" then
		self:ActivateMaskBrush(0)
	elseif name=="Mask1Button" then
		self:ActivateMaskBrush(1)
	elseif name=="Mask2Button" then
		self:ActivateMaskBrush(2)
	elseif name=="ClearMask" then
		--TerrainState.mask:Clear(Color(1,1,1))
		--TerrainState.masktex:SetData(TerrainState.mask)
		TerrainState:ClearAllMasks()
	elseif name=="FilterButton" then
		filterui:Activate()
	end
end

