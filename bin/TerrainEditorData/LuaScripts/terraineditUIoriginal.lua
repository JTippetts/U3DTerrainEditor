-- Terrain Editor UI

require 'LuaScripts/terrainselectui'
require 'LuaScripts/editheightui'
require 'LuaScripts/smoothheightui'
require 'LuaScripts/editmaskui'
require 'LuaScripts/splineui'

TerrainEditUI=ScriptObject()

uiStyle = cache:GetResource("XMLFile", "UI/DefaultStyle.xml")
ui.root.defaultStyle = uiStyle;
iconStyle = cache:GetResource("XMLFile", "UI/EditorIcons.xml");

function CreateCursor()
    cursor = Cursor:new("Cursor")
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
	
	self.splinegroups=scene_:CreateScriptObject("SplineUI")
	self.splinegroups:Deactivate()
	
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
	
	self:SubscribeToEvent(self.toolbar:GetChild("TerrainSettings",true), "Toggled", "TerrainEditUI:HandleToggled")
	self:SubscribeToEvent(self.toolbar:GetChild("EditHeight",true), "Toggled", "TerrainEditUI:HandleToggled")
	self:SubscribeToEvent(self.toolbar:GetChild("SmoothHeight",true), "Toggled", "TerrainEditUI:HandleToggled")
	self:SubscribeToEvent(self.toolbar:GetChild("EditLayer",true), "Toggled", "TerrainEditUI:HandleToggled")
	self:SubscribeToEvent(self.toolbar:GetChild("EditMask",true), "Toggled", "TerrainEditUI:HandleToggled")
	self:SubscribeToEvent(self.toolbar:GetChild("EditNoiseGraphs",true), "Toggled", "TerrainEditUI:HandleToggled")
	self:SubscribeToEvent(self.toolbar:GetChild("EditWaypoints",true), "Toggled", "TerrainEditUI:HandleToggled")
	self:SubscribeToEvent(self.toolbar:GetChild("Filters",true), "Toggled", "TerrainEditUI:HandleToggled")
	self:SubscribeToEvent(self.toolbar:GetChild("Help",true), "Toggled", "TerrainEditUI:HandleToggled")


	self.waypointpreview=scene_:CreateComponent("CustomGeometry")
	self.waypointpreview:SetNumGeometries(1)
	self.waypointpreviewmaterial=cache:GetResource("Material", "Materials/WaypointPreview.xml")
	self.waypointpreview:SetMaterial(self.waypointpreviewmaterial)
	
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
		TerrainState:SetMaskBuffer(arr,target-9)
		self.nodemapping.visible=false
	end
end

function TerrainEditUI:HandleCloseMapping(eventType, eventData)
	self.nodemapping.visible=false
end

function TerrainEditUI:NewTerrain(width, height, blendwidth, blendheight, triplanar, smoothing, normalmapping)
	TerrainState:Initialize(scene_,width,height,blendwidth,blendheight,Vector3(1,0.5,1),true)
end

function TerrainEditUI:SetMaterial(blendwidth, blendheight, triplanar, smoothing, normalmapping)
	
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
	
	
	if input:GetKeyPress(KEY_M) then
		self.nodegraph:Deactivate()
	end
end

function TerrainEditUI:UncheckToolbar(except)
	if except~="TerrainSettings" then self.toolbar:GetChild("TerrainSettings",true).checked=false saveloadui:Deactivate() end
	if except~="EditHeight" then self.toolbar:GetChild("EditHeight",true).checked=false self.heightbrush:Deactivate() end
	if except~="SmoothHeight" then self.toolbar:GetChild("SmoothHeight",true).checked=false self.smoothbrush:Deactivate() end
	if except~="EditLayer" then self.toolbar:GetChild("EditLayer",true).checked=false self.blendbrush:Deactivate() end
	if except~="EditMask" then self.toolbar:GetChild("EditMask",true).checked=false self.maskbrush:Deactivate() end
	if except~="EditNoiseGraphs" then self.toolbar:GetChild("EditNoiseGraphs",true).checked=false self.nodegroupslist.visible=false end
	if except~="EditWaypoints" then self.toolbar:GetChild("EditWaypoints",true).checked=false self.splinegroups:Deactivate() end
	if except~="Filters" then self.toolbar:GetChild("Filters",true).checked=false filterui:Deactivate() end
	if except~="Help" then self.toolbar:GetChild("Help",true).checked=false end
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
			cam.tracksurface=false   -- Deactivate camera surface tracking while editing height
		else
			self.heightbrush:Deactivate()
			cam.tracksurface=true
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
		if eventData["State"]:GetBool() then
			self.splinegroups:Activate()
		else
			self.splinegroups:Deactivate()
		end
	elseif name=="Filters" then
		if eventData["State"]:GetBool() then
			filterui:Activate()
		else
			filterui:Deactivate()
		end
	elseif name=="Help" then
	
	end
end
