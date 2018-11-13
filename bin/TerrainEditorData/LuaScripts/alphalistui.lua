-- Alphas List UI

AlphaListUI = ScriptObject()

function AlphaListUI:Start()
	self.list=ui:LoadLayout(cache:GetResource("XMLFile", "UI/AlphaList.xml"))
	self.list:SetPosition(IntVector2(0, graphics.height-self.list.height))
	self.list.visible=false
	ui.root:AddChild(self.list)

	self.view=self.list:GetChild("AlphaList", true)
	self.viewelem=ui:LoadLayout(cache:GetResource("XMLFile", "UI/AlphaListElement.xml"))
	self.view:SetContentElement(self.viewelem)

	self:PopulateList()
end

function AlphaListUI:Activate()
	self.list.visible=true
end

function AlphaListUI:Deactivate()
	self.list.visible=false
end

function AlphaListUI:PopulateList()
	self.alphas={}
	local alphas=fileSystem:ScanDir(fileSystem:GetProgramDir().."TerrainEditorData/Alphas", "*.png", SCAN_FILES, false)
	if alphas==nil then print("No alphas") return
	else
		-- Do blank first
		local thumbtex=cache:GetResource("Texture2D", "TerrainEditorData/Alphas/blank.png")
		local elem=ui:LoadLayout(cache:GetResource("XMLFile", "UI/AlphaEntry.xml"))
		local thumb=elem:GetChild("Thumb",true)
		thumb.texture=thumbtex
		thumb.imageRect=IntRect(0,0,thumbtex:GetWidth()-1,thumbtex:GetHeight()-1)
		self.viewelem:AddChild(elem)
		self:SubscribeToEvent(thumb, "Pressed", "AlphaListUI:HandleAlphaSelected")
		local a={name="blank.png", element=elem, button=thumb,path="TerrainEditorData/Alphas/blank.png", tex=thumbtex, image=thumbtex:GetImage()}
		table.insert(self.alphas,a)
		local c
		for _,c in ipairs(alphas) do
			print("Alpha name: "..c)
			if c~="blank.png" then
				local thumbtex=cache:GetResource("Texture2D", "TerrainEditorData/Alphas/"..c)
				local elem=ui:LoadLayout(cache:GetResource("XMLFile", "UI/AlphaEntry.xml"))
				local thumb=elem:GetChild("Thumb",true)
				thumb.texture=thumbtex
				thumb.imageRect=IntRect(0,0,thumbtex:GetWidth()-1,thumbtex:GetHeight()-1)
				self.viewelem:AddChild(elem)
				self:SubscribeToEvent(thumb, "Pressed", "AlphaListUI:HandleAlphaSelected")
				local a={name=c, element=elem, button=thumb,path="TerrainEditorData/Alphas/"..c, tex=thumbtex, image=thumbtex:GetImage()}
				table.insert(self.alphas,a)
			end
		end
	end

	-- Select first alpha
	self.selected=self.alphas[1]
	self.selected.element.imageRect=IntRect(160,64,176,80)
	TerrainState:GetMaterial():SetTexture(5,self.selected.tex)
end

function AlphaListUI:HandleAlphaSelected(eventType, eventData)
	local elem=eventData["Element"]:GetPtr("UIElement")

	local c
	for _,c in ipairs(self.alphas) do
		if elem==c.button then
			print("Alpha "..c.name.." selected.")
			if self.selected and self.selected~=c then
				-- Unselect
				self.selected.element.imageRect=IntRect(48,0,64,16)
			end
			self.selected=c
			c.element.imageRect=IntRect(160,64,176,80)
			TerrainState:GetMaterial():SetTexture(5,self.selected.tex)
		end

	end
end

function AlphaListUI:ReApplyAlphaTex()
	if(self.selected) then
		TerrainState:GetMaterial():SetTexture(5,self.selected.tex)
	end
end
