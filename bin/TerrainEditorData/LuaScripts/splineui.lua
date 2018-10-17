-- Spline UI
require "LuaScripts/Class"

Spline=class(function(self)
	self.node=scene_:CreateChild()
	self.model=self.node:CreateComponent("CustomGeometry")
	self.knots={}
	self.colorbuf=Variant()
	local vb=VectorBuffer()
	local col=Color(g_rnd:get01()*0.5+0.5, g_rnd:get01()*0.5+0.5, g_rnd:get01()*0.5+0.5)
	vb:WriteFloat(col.r)
	vb:WriteFloat(col.g)
	vb:WriteFloat(col.b)
	vb:WriteFloat(0.5)
	self.colorbuf:Set(vb)
	self.color=col

	self.dirty=false

	self.ribbonmat=cache:GetResource("Material", "Materials/WaypointPreview.xml")--:Clone()
	self.ribbonmat:SetShaderParameter("MatDiffColor", self.colorbuf)
	self.flagmat=cache:GetResource("Material", "Materials/Flag.xml")--:Clone()
	self.flagmat:SetShaderParameter("MatSpecColor", self.colorbuf)
end)

function Spline:Show()
	self.node:SetEnabled(true)
	local c
	for _,c in ipairs(self.knots) do
		c:SetEnabled(true)
	end
	self.ribbonmat:SetShaderParameter("MatDiffColor", self.colorbuf)
end

function Spline:Hide()
	self.node:SetEnabled(false)
	local c
	for _,c in ipairs(self.knots) do
		c:SetEnabled(false)
	end
end

function Spline:AddKnot(worldpos)
	local waynode=scene_:CreateChild()
	local model=waynode:CreateComponent("StaticModel")
	model.material=self.flagmat --:Clone()
	model.model=cache:GetResource("Model", "Models/Flag.mdl")
	model.castShadows=false
	local ht=TerrainState:GetTerrain():GetHeight(Vector3(groundx,0,groundz))
	--local ht=TerrainState:GetHeightValue(worldpos)
	waynode.position=Vector3(worldpos.x, ht, worldpos.z)
	waynode.scale=Vector3(0.25,0.25,0.25)
	table.insert(self.knots, waynode)
	self.dirty=true
end

function Spline:RemoveLastKnot()
	if #self.knots>0 then
		self.knots[#self.knots]:Remove()
		table.remove(self.knots)
		self.dirty=true
		--self:BuildRibbon()
	end
end

function Spline:UpdateKnots()
	local c
	for _,c in ipairs(self.knots) do
		--local ht=TerrainState:GetHeightValue(c.position)
		local ht=TerrainState:GetTerrain():GetHeight(c.position)
		if ht ~= c.position.y then self.dirty=true end
		c.position=Vector3(c.position.x, ht, c.position.z)
	end
end

function Spline:BuildRibbon()
	if self.dirty==false then return end
	self.dirty=false
	if #self.knots<2 then self.model:Clear() self.model:Commit() return end
	local c
	local plist=RasterVertexList()

	for _,c in ipairs(self.knots) do
		local pos=c.position
		--local ht=TerrainState:GetHeightValue(pos)
		local ht=TerrainState:GetTerrain():GetHeight(pos)
		plist:push_back(RasterVertex(pos.x, pos.z, ht))
	end

	local curve=RasterVertexList()
	TessellateLineList(plist, curve, 3)
	local quad=RasterVertexList()
	BuildQuadStrip(curve, quad, 0.5)

	self.model:Clear()
	self.model:SetNumGeometries(1)
	self.model:BeginGeometry(0,TRIANGLE_LIST)
	self.model:SetDynamic(true)

	function buildVertex(rv)
		return Vector3(rv.x_,rv.val_,rv.y_)
	end

	local bbox=BoundingBox()

	for c=0,quad:size()-4,2 do
		local d
		local inds={0,1,2,1,2,3}
		for _,d in ipairs(inds) do
			local v=buildVertex(quad:at(c+d))
			self.model:DefineVertex(v)
			bbox:Merge(v)
			--print(v.x,v.y,v.z)
		end
	end

	self.model:Commit()
	self.model:SetMaterial(self.ribbonmat)
	self.model.worldBoundingBox=bbox
	--self.model.worldBoundingBox:Define(Vector3(0,0,0), Vector3(200,200,200)) --=bbox
end

function Spline:Save()
	local knots={}
	local c
	for _,c in ipairs(self.knots) do
		local pos=c:GetPosition()
		table.insert(knots, {pos.x, pos.y, pos.z})
	end
	return knots
end

function Spline:Load(knots)
	self.knots={}
	local c
	for _,c in ipairs(knots) do
		self:AddKnot(Vector3(c[1],c[2],c[3]))
	end
end


SplineUI=ScriptObject()

function SplineUI:Start()
	self.groups={}
	self.currentgroup=nil
	self.active=false
	self.groupcounter=0

	self.menu=ui:LoadLayout(cache:GetResource("XMLFile", "UI/SplineGroups.xml"))
	self.menu:SetPosition(IntVector2(graphics.width-self.menu.width, graphics.height-self.menu.height))
	self.menu.visible=false
	ui.root:AddChild(self.menu)

	self:SubscribeToEvent(self.menu:GetChild("New", true), "Pressed", "SplineUI:HandleNewGroup")
	self:SubscribeToEvent(self.menu:GetChild("Delete", true), "Pressed", "SplineUI:HandleDeleteGroup")
	self:SubscribeToEvent(self.menu:GetChild("List", true), "ItemSelected", "SplineUI:HandleSelectedItem")
end

function SplineUI:Clear()
	local list=self.menu:GetChild("List", true)
	list:RemoveAllItems()
	local g
	for _,g in ipairs(self.groups) do
		g.node:Remove()
	end
	self.groups={}
	self.currentgroup=nil
end

function SplineUI:FindSplineByName(name)
	local c
	for _,c in ipairs(self.groups) do
		print(c.name)
		if c.name==name then print("Found spline: "..c.name) return c end
	end
	return nil
end

function SplineUI:HandleNewGroup(eventType, eventData)
	local newgroup=Spline()
	local name="Spline "..self.groupcounter
	self.groupcounter=self.groupcounter+1
	local list=self.menu:GetChild("List", true)
	local sel=list.selection

	local t=Text:new()
	t:SetStyle("FileSelectorListText", cache:GetResource("XMLFile", "UI/DefaultStyle.xml"))
	t.text=name
	t.color=newgroup.color
	newgroup.name=name
	list:AddItem(t)
	list.selection=list:GetNumItems()-1
	table.insert(self.groups, newgroup)
	self:SelectGroup(list.selection+1)
end

function SplineUI:HandleDeleteGroup(eventType, eventData)
	local which=self.menu:GetChild("List", true).selection
	if which==-1 then return end

	-- TODO
end

function SplineUI:HandleSelectedItem(eventType, eventData)
	local which=self.menu:GetChild("List", true).selection
	if which==-1 then return end
	self:SelectGroup(which+1)
end

function SplineUI:SelectGroup(which)
	if self.currentgroup then
		self.currentgroup:Hide()
	end

	if which <= #self.groups then
		self.currentgroup=self.groups[which]
		self.currentgroup:Show()
		self.currentgroup:UpdateKnots()
		self.currentgroup:BuildRibbon()
	end
end

function SplineUI:Activate()
	if self.currentgroup then
		self.currentgroup:Show()
		self.currentgroup:UpdateKnots()
		self.currentgroup:BuildRibbon()
	end
	self.active=true
	self.menu.visible=true
end

function SplineUI:Deactivate()
	if self.currentgroup then
		self.currentgroup:Hide()
	end
	self.active=false
	self.menu.visible=false
end

function SplineUI:Save(fullpath)
	local data={}
	data.groups={}
	local c
	for _,c in ipairs(self.groups) do
		local group={}
		group.name=c.name
		group.knots=c:Save()
		table.insert(data.groups, group)
	end
	local str=table.show(data, "loader.splines")
	local f=io.open(fullpath.."/splines.lua", "w")
	f:write(str)
	f:close()

	local f=io.open(fullpath.."/splines.json", "w")
	if f then
		LuaToJSON(data, f)
		f:close()
	else print("Couldn't open splines file.")
	end

	--local vm=TableToVM(data)
	--SaveVariantMapJSON(context, fullpath.."/splines.json", vm)
	--local f=File(fullpath.."/splines.lua", FILE_WRITE)
	--f:WriteString(str)
	--f:Close()
end

function SplineUI:Load(loader)
	if not loader or not loader.splines then return end
	local splines=loader.splines

	self:Clear()

	local c
	for _,c in ipairs(splines.groups) do
		local newgroup=self:NewGroup()
		newgroup:Load(c.knots)
	end
end

function SplineUI:FindSplineByName(name)
	local c
	for _,c in ipairs(self.groups) do
		print(c.name)
		if c.name==name then print("Found spline: "..c.name) return c end
	end
	return nil
end

function SplineUI:NewGroup()
	local newgroup=Spline()
	local name="Spline "..self.groupcounter
	self.groupcounter=self.groupcounter+1
	local list=self.menu:GetChild("List", true)
	local sel=list.selection

	local t=Text:new()
	t:SetStyle("FileSelectorListText", cache:GetResource("XMLFile", "UI/DefaultStyle.xml"))
	t.text=name
	t.color=newgroup.color
	newgroup.name=name
	list:AddItem(t)
	list.selection=list:GetNumItems()-1
	table.insert(self.groups, newgroup)
	self:SelectGroup(list.selection+1)
	return newgroup
end

function SplineUI:Update(dt)
	if self.active==false then return end


	if input:GetKeyPress(KEY_E) then
		if self.currentgroup then
			local mousepos
			if input.mouseVisible then
				mousepos=input:GetMousePosition()
			else
				mousepos=ui:GetCursorPosition()
			end
			local mouseground=cam:PickGround(mousepos.x, mousepos.y)
			self.currentgroup:AddKnot(Vector3(mouseground.x, 0, mouseground.z))
		end
	elseif input:GetKeyPress(KEY_Q) then
		if self.currentgroup then
			self.currentgroup:RemoveLastKnot()
		end
	end
	if self.currentgroup then
		self.currentgroup:UpdateKnots()
		self.currentgroup:BuildRibbon()
	end
end
