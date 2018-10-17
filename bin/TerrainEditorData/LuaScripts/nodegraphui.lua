-- Node-graph UI
-- Instance data
-- Consists of opcodes.
-- If opcode=="Parameter" then get the specified input parameter.
-- If opcode=="Function" then instantiate the given ANL function, with the specified array indices
require 'LuaScripts/tableshow'
require 'LuaScripts/anlnodes'


function CreateAccelKeyText(accelKey, accelQual)
	local accelKeyText = Text:new()
	accelKeyText:SetStyle("EditorMenuText", cache:GetResource("XMLFile", "UI/DefaultStyle.xml"))
	accelKeyText.textAlignment = HA_RIGHT

	local text
	if accelKey == KEY_DELETE then text = "Del"
	elseif accelKey == KEY_SPACE then text = "Space"
	elseif accelKey == KEY_F1 then text = "F1"
	elseif accelKey == KEY_F2 then text = "F2"
	elseif accelKey == KEY_F3 then text = "F3"
	elseif accelKey == KEY_F4 then text = "F4"
	elseif accelKey == KEY_F5 then text = "F5"
	elseif accelKey == KEY_F6 then text = "F6"
	elseif accelKey == KEY_F7 then text = "F7"
	elseif accelKey == KEY_F8 then text = "F8"
	elseif accelKey == KEY_F9 then text = "F9"
	elseif accelKey == KEY_F10 then text = "F10"
	elseif accelKey == KEY_F11 then text = "F11"
	elseif accelKey == KEY_F12 then text = "F12"
	elseif accelKey == -1 then text = ">"
	else text:AppendUTF8(accelKey)
	end
	accelKeyText.text=text
	return accelKeyText
end

function CreateMenuItem(title, accelKey)
	local menu=Menu:new(title)
	menu:SetStyleAuto(cache:GetResource("XMLFile", "UI/DefaultStyle.xml"))
	menu:SetLayout(LM_HORIZONTAL, 0, IntRect(8,2,8,2))

	local text=menu:CreateChild("Text", "Text")
	text:SetStyle("EditorMenuText", cache:GetResource("XMLFile", "UI/DefaultStyle.xml"))
	text.text=title

	if accelKey ~= 0 then
		local spacer=UIElement:new()
		spacer.minWidth = text.indentSpacing
		spacer.height = text.height
		menu:AddChild(spacer)
		menu:AddChild(CreateAccelKeyText(accelKey, nil))
	end

	return menu
end

function CreatePopup(baseMenu)
	local popup=Window:new()
	popup:SetStyleAuto(cache:GetResource("XMLFile", "UI/DefaultStyle.xml"))
	popup:SetLayout(LM_VERTICAL, 1, IntRect(2,6,2,6))
	baseMenu.popup=popup
	baseMenu.popupOffset = IntVector2(baseMenu.width,0)
	return popup
end

function CreateMenu(title)
	local menu=CreateMenuItem(title)

	CreatePopup(menu)
	return menu
end

NodeGraphUI=ScriptObject()

function NodeGraphUI:Start()
	--self.createnodemenu=ui:LoadLayout(cache:GetResource("XMLFile", "UI/CreateNodeMenu.xml"))
	--self.pane:AddChild(self.createnodemenu)

	self.pane=ui.root:CreateChild("UIElement")
	self.pane:SetSize(graphics.width, graphics.height)
	self.closetext=self.pane:CreateChild("Text")
	self.closetext:SetStyle("Text", cache:GetResource("XMLFile","UI/DefaultStyle.xml"))
	self.closetext:SetFontSize(20)
	self.closetext.text="Press 'M' to close window."
	self.pane.visible=false


	self.testmenu=self:CreateNodeCreateMenu(self.pane)
	self.testmenu:SetPosition(100,100)
	self.testmenu.visible=false


	self.nodegroup=nil
	self.cursortarget=cursor:CreateChild("NodeGraphLinkDest")

	self.nodegroups={}

	self.nodegroupslist=ui:LoadLayout(cache:GetResource("XMLFile", "UI/NoiseNodeGroups.xml"))
	local list=self.nodegroupslist:GetChild("List",true)
	ui.root:AddChild(self.nodegroupslist)
	list:SetStyle("ListView", cache:GetResource("XMLFile", "UI/DefaultStyle.xml"))
	list.highlightMode=HM_ALWAYS
	self:SubscribeToEvent(self.nodegroupslist:GetChild("New", true), "Pressed", "NodeGraphUI:HandleNewGroup")
	self:SubscribeToEvent(self.nodegroupslist:GetChild("Open", true), "Pressed", "NodeGraphUI:HandleOpenGroup")
	self:SubscribeToEvent(self.nodegroupslist:GetChild("Delete", true), "Pressed", "NodeGraphUI:HandleDeleteGroup")
	self:SubscribeToEvent(self.nodegroupslist:GetChild("Edit", true), "Pressed", "NodeGraphUI:HandleEditGroup")
	self:SubscribeToEvent(self.nodegroupslist:GetChild("Map", true), "Pressed", "NodeGraphUI:HandleMapGroup")

	self.nodegroupslist:SetPosition(IntVector2(graphics.width-self.nodegroupslist.width, graphics.height-self.nodegroupslist.height))
	self.nodegroupslist.visible=false

	self.nodegroupcounter=0

end

function NodeGraphUI:Activate()
	self.nodegroupslist.visible=true
end

function NodeGraphUI:Deactivate()
	self.nodegroupslist.visible=false
	if self.nodegroup then
		self.nodegroup.pane.visible=false
		self.nodegroup.pane.focus=false
		if self.closetext then self.closetext:Remove() self.closetext=nil end
	end
end

function NodeGraphUI:Clear()
	local list=self.nodegroupslist:GetChild("List",true)
	list:RemoveAllItems()

	local g
	for _,g in ipairs(self.nodegroups) do
		g.pane:Remove()
		--g.previewtex:delete()
		--g.histotex:delete()
	end
	self.nodegroup=nil
	self.nodegroups={}
	self.nodegroupcounter=0
end

function NodeGraphUI:Save(fullpath)
	local groups={}

	print("Saving "..#self.nodegroups.." node groups.")

	function FindLinkIndex(group, target)
		local c
		for c=1,#group.nodes,1 do
			if group.nodes[c]==target then return c end
		end
		return 0
	end

	local c
	for _,c in ipairs(self.nodegroups) do
		local group={}
		group.name=c.name
		group.nodes={}

		local n
		print("Saving "..#c.nodes.." nodes")
		for _,n in ipairs(c.nodes) do
			local pos=n.position
			local nd=
			{
				type=n.name,
				pos={pos.x,pos.y},
				links={},
				inputs={}
			}

			if n.name=="constant" or n.name=="seed" then
				nd.value=n:GetChild("Value",true):GetText()
				nd.title=n:GetChild("Title",true):GetText()
			end


			local inputs=n:GetChild("Inputs",true)
			local numparams=inputs:GetNumChildren()
			local ip
			for ip=1,numparams,1 do
				local v=n:GetChild("Value"..tostring(ip-1),true)

				if v then table.insert(nd.inputs, v.text) end
			end

			local output=n:GetChild("Output0",true)
			if output then
				local numlinks=output:GetNumLinks()
				local l
				print("numlinks: "..numlinks)
				for l=0,numlinks-1,1 do
					local link=output:GetLink(l)
					if(link) then
						local target=link:GetTarget()
						if target then
							local targetroot=target:GetRoot()
							if targetroot then
								local targetindex=FindLinkIndex(c,targetroot)
								table.insert(nd.links, {targetindex,target.name})
								-- A 0 index should mean output node.
							end
						end
					end

				end
			end


			table.insert(group.nodes, nd)
		end
		table.insert(groups, group)
	end

	local str=table.show(groups, "loader.nodegroups")
	local f=io.open(fullpath.."/nodegroups.lua", "w")
	f:write(str)
	f:close()

	local f=io.open(fullpath.."/nodegroups.json", "w")
	if f then
		LuaToJSON(groups, f)
		f:close()
	else print("Couldn't open node groups file.")
	end
end

function NodeGraphUI:Load(loader)
	if not loader or not loader.nodegroups then return end

	self:Clear()
	local g
	for _,g in ipairs(loader.nodegroups) do
		local group=self:CreateNodeGroup()
		local n
		for _,n in ipairs(g.nodes) do
			local node=self:BuildNode(group, n.type)
			table.insert(group.nodes, node)
			if node then
				node:SetPosition(IntVector2(n.pos[1],n.pos[2]))
				if n.type=="constant" or n.type=="seed" then
					node:GetChild("Value",true):SetText(n.value)
					node:GetChild("Title",true):SetText(n.title)
				end

				local cp,ip
				for cp,ip in ipairs(n.inputs) do
					local np=node:GetChild("Value"..(cp-1),true)
					if np then
						np.text=ip
					end
				end
			end
		end

		-- Build links
		local i
		for i,n in ipairs(g.nodes) do
			local lnk
			local node=group.nodes[i]
			for _,lnk in ipairs(n.links) do
				local targetnode
				if lnk[1]==0 then targetnode=group.output
				else targetnode=group.nodes[lnk[1]]
				end
				if targetnode then
					local link=group.linkpane:CreateLink(node:GetChild("Output0",true),targetnode:GetChild(lnk[2],true))
					link:SetImageRect(IntRect(193,81,207,95))
				end
			end
		end
	end
end

function NodeGraphUI:HandleNewGroup(eventType, eventData)
	local newgroup=self:CreateNodeGroup()
end

function NodeGraphUI:HandleOpenGroup(eventType, eventData)

end

function NodeGraphUI:HandleDeleteGroup(eventType, eventData)

end

function NodeGraphUI:HandleEditGroup(eventType, eventData)
	local which=self.nodegroupslist:GetChild("List",true).selection
	if which==-1 then return end
	self.nodegroup=self.nodegroups[which+1]
	if not self.nodegroup then print("wut: "..which..","..self.nodegroupslist:GetChild("List",true):GetNumItems()..","..#self.nodegroups) return end
	self:ActivateGroup(self.nodegroup)
end

function NodeGraphUI:HandleMapGroup(eventType, eventData)
	local which=self.nodegroupslist:GetChild("List",true).selection
	if which==-1 then return end

	self.currentnodegroup=which
	self.nodegroup=self.nodegroups[self.currentnodegroup+1]
	self.nodemapping.visible=true
end

function NodeGraphUI:CreateNodeCreateMenu(parent)
	local menu=ui:LoadLayout(cache:GetResource("XMLFile", "UI/CreateNodeButton.xml"))
	local mn=menu:GetChild("Menu",true)

	local pop=CreatePopup(mn)
	local i,c
	for i,c in pairs(nodecategories) do
		local mi=CreateMenuItem(i,-1)
		pop:AddChild(mi)

		local childpop=CreatePopup(mi)
		local e,f
		for e,f in ipairs(c) do
			local ni=CreateMenuItem(f,0)
			childpop:AddChild(ni)
			--self:SubscribeToEvent(ni, "MenuSelected", "NodeGraphUI:HandleMenuSelected")
		end
	end

	self:SubscribeToEvent("MenuSelected", "NodeGraphUI:HandleMenuSelected")

	parent:AddChild(menu)
	return menu

end

function NodeGraphUI:CreateNodeGroup()
	local nodegroup=
	{
		nodes={}
	}
	nodegroup.pane=self.pane:CreateChild("Window")
	nodegroup.pane.size=IntVector2(graphics.width*2, graphics.height*2)
	nodegroup.pane.position=IntVector2(-graphics.width/2, -graphics.height/2)
	nodegroup.pane:SetImageRect(IntRect(208,0,223,15))
	nodegroup.pane:SetImageBorder(IntRect(4,4,4,4))
	nodegroup.pane:SetTexture(cache:GetResource("Texture2D", "Textures/UI_modified.png"))
	nodegroup.pane.opacity=0.75
	nodegroup.pane.bringToFront=true
	nodegroup.pane.movable=true
	nodegroup.pane.clipChildren=false
	nodegroup.pane:SetDefaultStyle(cache:GetResource("XMLFile", "UI/NodeStyle.xml"))

	nodegroup.linkpane=nodegroup.pane:CreateChild("NodeGraphLinkPane")
	nodegroup.linkpane.size=IntVector2(graphics.width*2, graphics.height*2)
	nodegroup.linkpane.visible=true
	nodegroup.linkpane.texture=cache:GetResource("Texture2D", "Data/Textures/UI_modified.png")

	nodegroup.previewtex=Texture2D:new()
	nodegroup.previewimg=Image()
	nodegroup.previewimg:SetSize(256,256,3)
	nodegroup.previewimg:Clear(Color(0,0,0))
	nodegroup.previewtex:SetData(nodegroup.previewimg,false)

	nodegroup.histotex=Texture2D:new()
	nodegroup.histoimg=Image()
	nodegroup.histoimg:SetSize(256,64,3)
	nodegroup.histoimg:Clear(Color(0,0,0))
	nodegroup.histotex:SetData(nodegroup.histoimg,false)

	nodegroup.output=self:OutputNode(nodegroup)
	nodegroup.output.position=IntVector2(-nodegroup.pane.position.x + graphics.width-nodegroup.output.width, -nodegroup.pane.position.y + graphics.height/4)

	nodegroup.output:GetChild("Preview",true).texture=nodegroup.previewtex
	nodegroup.output:GetChild("Histogram",true).texture=nodegroup.histotex

	local list=nodegroup.output:GetChild("TargetList",true)
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
		"Mask 3",
		"Water"
	}

	local c
	for _,c in ipairs(smtypes) do
		local t=Text:new(context)
		t:SetFont(cache:GetResource("Font", "Fonts/Anonymous Pro.ttf"), 9)
		t.text=c
		t.color=Color(1,1,1)
		t.minSize=IntVector2(0,16)
		list:AddItem(t)
	end
	list.selection=0

	list=nodegroup.output:GetChild("BlendOpList",true)
	local bops=
	{
		"Replace",
		"Add",
		"Subtract",
		"Multiply",
		"Min",
		"Max",
	}
	for _,c in ipairs(bops) do
		local t=Text:new(context)
		t:SetFont(cache:GetResource("Font", "Fonts/Anonymous Pro.ttf"), 9)
		t.text=c
		t.color=Color(1,1,1)
		t.minSize=IntVector2(0,16)
		list:AddItem(t)
	end
	list.selection=0

	--nodegroup.pane:AddChild(self.createnodemenu)

	self:SubscribeToEvent(nodegroup.output:GetChild("Generate",true),"Pressed","NodeGraphUI:HandleGenerate")
	self:SubscribeToEvent(nodegroup.output:GetChild("Execute",true),"Pressed","NodeGraphUI:HandleExecute")
	self:SubscribeToEvent(nodegroup.output:GetChild("Store",true),"Pressed","NodeGraphUI:HandleStore")
	nodegroup.pane.visible=false

	local name="Group "..self.nodegroupcounter
	self.nodegroupcounter=self.nodegroupcounter+1
	local nlist=self.nodegroupslist:GetChild("List",true)
	local sel=nlist.selection

	local t=Text:new()
	t:SetStyle("FileSelectorListText", cache:GetResource("XMLFile","UI/DefaultStyle.xml"))
	t.text=name
	nlist:AddItem(t)
	nlist.selection=nlist:GetNumItems()-1
	table.insert(self.nodegroups, nodegroup)
	nodegroup.name=name

	self.nodegroup=nodegroup

	return nodegroup
end

function NodeGraphUI:HideGroup()
	if self.nodegroup then
		self.nodegroup.pane.visible=false
		self.nodegroup.pane.focus=false
	end
	self.pane.visible=false
end


function NodeGraphUI:ActivateGroup(nodegroup)
	if self.nodegroup then
		nodegroup.pane.visible=false
		nodegroup.pane.focus=false

	end
	self.nodegroup=nodegroup
	nodegroup.pane.visible=true
	nodegroup.pane.focus=true
	self.pane.visible=true
	--nodegroup.pane:AddChild(self.createnodemenu)
	--self.createnodemenu.visible=true
	--self.createnodemenu.position=IntVector2(-self.nodegroup.pane.position.x,-self.nodegroup.pane.position.y+graphics.height-self.createnodemenu.height)

	self.testmenu.visible=true
	nodegroup.pane:AddChild(self.testmenu)
	--nodegroup.pane:AddChild(self.closetext)
	self.testmenu.position=IntVector2(-self.nodegroup.pane.position.x+100, -self.nodegroup.pane.position.y+100)
end

function NodeGraphUI:HandleCloseCreateNodeMenu(eventType, eventData)
	--self.createnodemenu.visible=false
end

function NodeGraphUI:HandleCreateNode(eventType, eventData)
	if not self.nodegroup then return end
	local e=eventData["Element"]:GetPtr("UIElement")
	if not e then return end
	local n

	n=self:BuildNode(self.nodegroup, e.name)
	if not n then return end

	n.position=IntVector2(-self.nodegroup.pane.position.x + graphics.width/2, -self.nodegroup.pane.position.y + graphics.height/2)
	table.insert(self.nodegroup.nodes, n)
	return n
end

function NodeGraphUI:SubscribeLinkPoints(e,numinputs)
	local output=e:GetChild("Output0", true)
	if(output) then
		self:SubscribeToEvent(output, "DragBegin", "NodeGraphUI:HandleOutputDragBegin")
		self:SubscribeToEvent(output, "DragEnd", "NodeGraphUI:HandleDragEnd")
		output:SetRoot(e)
	end

	local c
	for c=0,numinputs-1,1 do
		local input=e:GetChild("Input"..c, true)
		if(input) then
			self:SubscribeToEvent(input, "DragBegin", "NodeGraphUI:HandleInputDragBegin")
			self:SubscribeToEvent(input, "DragEnd", "NodeGraphUI:HandleDragEnd")
			input:SetRoot(e)
		end
	end
end

function NodeGraphUI:RemoveLinkPoints(e)
	local d=GetNodeTypeDesc(e.name)--nodetypes[type]
	if not d then return end

	local numinputs=#d.inputs

	local c
	for c=0,numinputs-1,1 do
		local input=e:GetChild("Input"..c, true)
		if(input) then
			local link=input:GetLink()
			if link then
				print("clearing link")
				--input:ClearLink()
				--local src=link:GetSource()
				--if src then src:RemoveLink(link) end
				self.nodegroup.linkpane:RemoveLink(link)
			end
		end
	end

	local output=e:GetChild("Output0", true)

	if output then
		local numlinks=output:GetNumLinks()
		print("numlinks: "..numlinks)
		for c=0,numlinks-1,1 do
			local link=output:GetLink(c)
			if link then
				self.nodegroup.linkpane:RemoveLink(link)
			end
		end
	end

end

function NodeGraphUI:OutputNode(nodegroup)
	local e=ui:LoadLayout(cache:GetResource("XMLFile", "UI/OutputNode.xml"))
	e.visible=true
	self:SubscribeLinkPoints(e,1)

	nodegroup.pane:AddChild(e)
	return e
end

function NodeGraphUI:BuildNode(nodegroup, type)
	local e=CreateNodeType(nodegroup.pane, type)
	local d=GetNodeTypeDesc(type) --nodetypes[type]
	if not d then return end

	if e then
		self:SubscribeLinkPoints(e,#d.inputs)
	end
	self:SubscribeToEvent(e:GetChild("Close",true), "Pressed", "NodeGraphUI:HandleCloseNode")
	return e
end



function NodeGraphUI:HandleOutputDragBegin(eventType, eventData)
	if not self.nodegroup then return end
	local element=eventData["Element"]:GetPtr("NodeGraphLinkSource")
	self.link=self.nodegroup.linkpane:CreateLink(element,self.cursortarget)
	self.link:SetImageRect(IntRect(193,81,207,95))

end

function NodeGraphUI:HandleDragEnd(eventType, eventData)
	if not self.link then return end
	if not self.nodegroup then return end

	local at=ui:GetElementAt(cursor.position)
	if at then
		if string.sub(at.name, 1, 5)=="Input" then
			local thislink=at:GetLink()
			if thislink then
				--at:ClearLink()
				--local src=thislink:GetSource()
				--if src then src:RemoveLink(thislink) end
				self.nodegroup.linkpane:RemoveLink(thislink)
			end
			self.link:SetTarget(at)
			return
		end
	end

	-- Destroy the link if not dropped on a valid target
	--local source=self.link:GetSource()
	--if(source) then source:RemoveLink(self.link) end
	self.nodegroup.linkpane:RemoveLink(self.link)
	self.link=nil
end

function NodeGraphUI:HandleInputDragBegin(eventType, eventData)
	local element=eventData["Element"]:GetPtr("NodeGraphLinkDest")
	if element then
		local link=element:GetLink()
		if link then
			self.link=link
			link:SetTarget(self.cursortarget)
			element:ClearLink()
		else
			self.link=nil
		end
	end
end

function NodeGraphUI:HandleGenerate(eventType, eventData)
	if not self.nodegroup then return end
	local kernel=BuildANLFunction(self.nodegroup.output)
	local minmax=RenderANLKernelToImage(self.nodegroup.previewimg,kernel,0,1,self.nodegroup.histoimg,SEAMLESS_NONE,false,0.0,1.0,1.0,true)
	self.nodegroup.previewtex:SetData(self.nodegroup.previewimg)
	self.nodegroup.output:GetChild("LowValue",true).text=string.format("%.4f",minmax.x)
	self.nodegroup.output:GetChild("HighValue",true).text=string.format("%.4f",minmax.y)
	self.nodegroup.histotex:SetData(self.nodegroup.histoimg,false)
end

function NodeGraphUI:HandleStore(eventType, eventData)
	local st,nodefunc=CreateLibraryDesc(self.nodegroup.output)
	local name=self.nodegroup.output:GetChild("StoreName",true).text
	print(st)
	local dothing=table.show(nodefunc, "nodetypes.user."..name)
	print(dothing)
	local chunk=loadstring(dothing)
	chunk()
	local ct
	local found=false
	for _,ct in pairs(nodecategories.user) do
		if ct==name then found=true end
	end
	if not found then
		table.insert(nodecategories.user, name)
	end
	self.testmenu:Remove()
	self.testmenu=nil
	self.testmenu=self:CreateNodeCreateMenu(self.pane)
	self.testmenu:SetPosition(100,100)
end

function NodeGraphUI:HandleExecute(eventType, eventData)
	if not self.nodegroup then return end

	local target=self.nodegroup.output:GetChild("TargetList",true).selection
	local blendop=self.nodegroup.output:GetChild("BlendOpList",true).selection

	local um1,im1=self.nodegroup.output:GetChild("UseMask1",true).checked,self.nodegroup.output:GetChild("InvertMask1",true).checked
	local um2,im2=self.nodegroup.output:GetChild("UseMask2",true).checked,self.nodegroup.output:GetChild("InvertMask2",true).checked
	local um3,im3=self.nodegroup.output:GetChild("UseMask3",true).checked,self.nodegroup.output:GetChild("InvertMask3",true).checked
	local ms=MaskSettings(um1,im1,um2,im2,um3,im3)

	local low=tonumber(self.nodegroup.output:GetChild("Low",true).text) or 0.0
	local high=tonumber(self.nodegroup.output:GetChild("High",true).text) or 1.0

	local rescale=self.nodegroup.output:GetChild("Rescale",true).checked

	if target==0 then
		-- Map terrain
		if not self.nodegroup then return end
		local kernel=BuildANLFunction(self.nodegroup.output)
		local arr=CArray2Dd(TerrainState:GetTerrainWidth(), TerrainState:GetTerrainHeight())
		map2DNoZ(SEAMLESS_NONE,arr,kernel,SMappingRanges(0,1,0,1,0,1), kernel:lastIndex())
		if rescale then arr:scaleToRange(low,high) end
		TerrainState:SetHeightBuffer(arr,ms,blendop)
		--self.nodemapping.visible=false
		saveDoubleArray("map.png",arr)
		return
	elseif target>=1 and target<=8 then
		if not self.nodegroup then return end
		local kernel=BuildANLFunction(self.nodegroup.output)
		local arr=CArray2Dd(TerrainState:GetBlendWidth(), TerrainState:GetBlendHeight())
		map2DNoZ(SEAMLESS_NONE,arr,kernel,SMappingRanges(0,1,0,1,0,1), kernel:lastIndex())
		if rescale then arr:scaleToRange(low,high) end
		TerrainState:SetLayerBuffer(arr,target-1,ms)
		--self.nodemapping.visible=false
		return
	elseif target>=9 and target<=11 then
		if not self.nodegroup then return end
		local kernel=BuildANLFunction(self.nodegroup.output)
		local arr=CArray2Dd(TerrainState:GetTerrainWidth(), TerrainState:GetTerrainHeight())
		map2DNoZ(SEAMLESS_NONE,arr,kernel,SMappingRanges(0,1,0,1,0,1), kernel:lastIndex())
		if rescale then arr:scaleToRange(low,high) end
		print("Setting to mask "..target-9)
		TerrainState:SetMaskBuffer(arr,target-9)
	elseif target==12 then
		if not self.nodegroup then return end
		local kernel=BuildANLFunction(self.nodegroup.output)
		local arr=CArray2Dd(TerrainState:GetTerrainWidth(), TerrainState:GetTerrainHeight())
		map2DNoZ(SEAMLESS_NONE,arr,kernel,SMappingRanges(0,1,0,1,0,1), kernel:lastIndex())
		if rescale then arr:scaleToRange(low,high) end
		TerrainState:SetWaterBuffer(arr,ms)
	end
end

function NodeGraphUI:HandleCloseNode(eventType, eventData)
	print("Close node")
	local e=eventData["Element"]:GetPtr("UIElement").parent.parent

	if e then self:RemoveLinkPoints(e) end

	local c,i, index
	for c,i in ipairs(self.nodegroup.nodes) do
		if i==e then index=c end
	end

	if index then table.remove(self.nodegroup.nodes, index) end

	e:Remove()
end

function NodeGraphUI:HandleMenuSelected(eventType, eventData)
	local menu = eventData["Element"]:GetPtr("Menu")
	if not menu then print("no menu") return end

	local t=menu:GetChild("Text",true)
	if t then
		print(t.text)
		self.testmenu:GetChild("Menu",true).showPopup=false

		if not self.nodegroup then return end
		local n

		n=self:BuildNode(self.nodegroup, t.text)
		if not n then return end

		n.position=IntVector2(-self.nodegroup.pane.position.x + graphics.width/2, -self.nodegroup.pane.position.y + graphics.height/2)
		table.insert(self.nodegroup.nodes, n)
	else
		print("no text")
	end


	--self:HandlePopup(menu)

end
