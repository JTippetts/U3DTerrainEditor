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

	self.splinegroups=scene_:CreateScriptObject("SplineUI")
	self.splinegroups:Deactivate()

	self.blendbrush:Deactivate()
	self.maskbrush:Deactivate()
	self.smoothbrush:Deactivate()
	self.heightbrush:Deactivate()

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
		self.nodegraph:HideGroup()
	end

	if input:GetKeyPress(KEY_O) then
		self:SaveArea("test")
	end

	if input:GetKeyPress(KEY_I) then
		self:LoadArea("test")
	end
end

function TerrainEditUI:UncheckToolbar(except)
	if except~="TerrainSettings" then self.toolbar:GetChild("TerrainSettings",true).checked=false saveloadui:Deactivate() end
	if except~="EditHeight" then self.toolbar:GetChild("EditHeight",true).checked=false self.heightbrush:Deactivate() end
	if except~="SmoothHeight" then self.toolbar:GetChild("SmoothHeight",true).checked=false self.smoothbrush:Deactivate() end
	if except~="EditLayer" then self.toolbar:GetChild("EditLayer",true).checked=false self.blendbrush:Deactivate() end
	if except~="EditMask" then self.toolbar:GetChild("EditMask",true).checked=false self.maskbrush:Deactivate() end
	if except~="EditNoiseGraphs" then self.toolbar:GetChild("EditNoiseGraphs",true).checked=false self.nodegraph:Deactivate() end
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
			self.nodegraph:Activate()
		else
			self.nodegraph:Deactivate()
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

function TerrainEditUI:SaveArea(dirname)
	local fullpath=fileSystem:GetProgramDir().."Save/"..dirname

	if not fileSystem:DirExists(fullpath) then
		fileSystem:CreateDir(fullpath)
	end

	--Save Terrain
	TerrainState:SaveHeightMap(fullpath.."/elev.png")
	TerrainState:SaveTerrainNormalMap(fullpath.."/normal.png")
	TerrainState:SaveBlend0(fullpath.."/blend0.png")
	TerrainState:SaveBlend1(fullpath.."/blend1.png")
	TerrainState:SaveMask(fullpath.."/mask.png")

	--Save data
	self.splinegroups:Save(fullpath)
	self.blendbrush:Save(fullpath)
	saveloadui:Save(fullpath)
	--self.doodads:Save(fullpath)
	self.nodegraph:Save(fullpath)
end

function TerrainEditUI:LoadArea(dirname)
	-- TODO: Clear all data before loading to avoid duplicate data groups
	local fullpath=fileSystem:GetProgramDir().."Save/"..dirname

	if not fileSystem:DirExists(fullpath) then return end

	TerrainState:LoadHeightMap(fullpath.."/elev.png")
	TerrainState:LoadBlend0(fullpath.."/blend0.png")
	TerrainState:LoadBlend1(fullpath.."/blend1.png")
	TerrainState:LoadMask(fullpath.."/mask.png")

	-- Load data
	loader={}
	--dofile(fullpath.."/doodads.lua")
	--self.doodads:Load(loader)
	dofile(fullpath.."/lighting.lua")
	saveloadui:Load(loader)
	dofile(fullpath.."/textures.lua")
	self.blendbrush:Load(loader)
	dofile(fullpath.."/splines.lua")
	self.splinegroups:Load(loader)
	dofile(fullpath.."/nodegroups.lua")
	self.nodegraph:Load(loader)

end
