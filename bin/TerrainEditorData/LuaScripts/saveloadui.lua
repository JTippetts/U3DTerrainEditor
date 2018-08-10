SaveLoadUI=ScriptObject()
imageFilters={"*.png"}

function SaveLoadUI:Start()
	--self.menu=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TerrainEditSaveLoadMenu.xml"))
	self.menu=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TerrainSettings.xml"))
	self.menu.style=uiStyle
	self.menu.visible=true
	
	ui.root:AddChild(self.menu)
	
	self:SubscribeToEvent("SaveHeightmap", "SaveLoadUI:SaveHeightmap")
	self:SubscribeToEvent("SaveBlend1", "SaveLoadUI:SaveBlend1")
	self:SubscribeToEvent("SaveBlend2", "SaveLoadUI:SaveBlend2")
	self:SubscribeToEvent("LoadHeightmap", "SaveLoadUI:LoadHeightmap")
	self:SubscribeToEvent("LoadBlend1", "SaveLoadUI:LoadBlend1")
	self:SubscribeToEvent("LoadBlend2", "SaveLoadUI:LoadBlend2")
	
	self:SubscribeToEvent(self.menu:GetChild("SaveTerrain",true), "Pressed", "SaveLoadUI:SaveHeightmap")
	self:SubscribeToEvent(self.menu:GetChild("SaveBlend0",true), "Pressed", "SaveLoadUI:SaveBlend1")
	self:SubscribeToEvent(self.menu:GetChild("SaveBlend1",true), "Pressed", "SaveLoadUI:SaveBlend2")
	self:SubscribeToEvent(self.menu:GetChild("LoadTerrain",true), "Pressed", "SaveLoadUI:LoadHeightmap")
	self:SubscribeToEvent(self.menu:GetChild("LoadBlend0",true), "Pressed", "SaveLoadUI:LoadBlend1")
	self:SubscribeToEvent(self.menu:GetChild("LoadBlend1",true), "Pressed", "SaveLoadUI:LoadBlend2")
	
	self:SubscribeToEvent(self.menu:GetChild("ClearTerrain",true), "Pressed", "SaveLoadUI:ClearTerrain")
	
	self:SubscribeToEvent(self.menu:GetChild("ApplyTerrainSpacing",true), "Pressed", "SaveLoadUI:HandleApplyTerrainSpacing")
	self:SubscribeToEvent(self.menu:GetChild("ApplyTerrainHeight",true), "Pressed", "SaveLoadUI:HandleApplyTerrainHeight")
	self:SubscribeToEvent(self.menu:GetChild("ApplyTerrainSize", true), "Pressed", "SaveLoadUI:HandleApplyTerrainSize")
	
	self:SubscribeToEvent(self.menu:GetChild("ExportNormals",true), "Pressed", "SaveLoadUI:SaveNormalmap")
	
	local sp=TerrainState:GetTerrainSpacing()
	self.menu:GetChild("TerrainSpacing",true).text=tostring(sp.x)
	self.menu:GetChild("TerrainHeight",true).text=tostring(sp.y)
	
	self.mainlight=self.menu:GetChild("MainLight",true)
	self.backlight=self.menu:GetChild("BackLight",true)
	self.ambfog=self.menu:GetChild("AmbFog",true)
	
	self.mainlight.hoverOffset=IntVector2(0,0)
	self.mainlight.pressedOffset=IntVector2(0,0)
	self.mainlight.border=IntRect(0,0,0,0)
	
	self.backlight.hoverOffset=IntVector2(0,0)
	self.backlight.pressedOffset=IntVector2(0,0)
	self.backlight.border=IntRect(0,0,0,0)
	
	self.ambfog.hoverOffset=IntVector2(0,0)
	self.ambfog.pressedOffset=IntVector2(0,0)
	self.ambfog.border=IntRect(0,0,0,0)
	
	self.mainchooser=scene_:CreateScriptObject("ColorChooser")
	self.mainchooser:Hide()
	self.backchooser=scene_:CreateScriptObject("ColorChooser")
	self.backchooser:Hide()
	self.ambfogchooser=scene_:CreateScriptObject("ColorChooser")
	self.ambfogchooser:Hide()
	
	self:SubscribeToEvent(self.mainlight, "Pressed", "SaveLoadUI:ShowColorChooser")
	self:SubscribeToEvent(self.backlight, "Pressed", "SaveLoadUI:ShowColorChooser")
	self:SubscribeToEvent(self.ambfog, "Pressed", "SaveLoadUI:ShowColorChooser")
	self:SubscribeToEvent(self.mainchooser.close, "Pressed", "SaveLoadUI:HideColorChooser")
	self:SubscribeToEvent(self.backchooser.close, "Pressed", "SaveLoadUI:HideColorChooser")
	self:SubscribeToEvent(self.ambfogchooser.close, "Pressed", "SaveLoadUI:HideColorChooser")
	
	self.mainchooser:SetColor(mainlight.color)
	self.backchooser:SetColor(backlight.color)
	self.ambfogchooser:SetColor(zone.fogColor)
end

function SaveLoadUI:ShowColorChooser(eventType, eventData)
	local element=eventData["Element"]:GetPtr("UIElement")
	if element==self.mainlight then
		self.backchooser:Hide()
		self.ambfogchooser:Hide()
		self.mainchooser:Show()
	elseif element==self.backlight then
		self.mainchooser:Hide()
		self.ambfogchooser:Hide()
		self.backchooser:Show()
	elseif element==self.ambfog then
		self.mainchooser:Hide()
		self.backchooser:Hide()
		self.ambfogchooser:Show()
	end
end

function SaveLoadUI:HideColorChooser(eventType, eventData)
	local element=eventData["Element"]:GetPtr("UIElement")
	if element==self.mainchooser.close then
		self.mainchooser:Hide()
	elseif element==self.backchooser.close then
		self.backchooser:Hide()
	elseif element==self.ambfogchooser.close then
		self.ambfogchooser:Hide()
	end
end

function CenterDialog(element)
    local size = element:GetSize()
    element:SetPosition((graphics.width - size.x) / 2, (graphics.height - size.y) / 2)
end


function ExtractFilename(eventData, forSave)
    local fileName=""

    -- Check for OK
    if eventData["OK"]:GetBool() then
        local filter = eventData["Filter"]:GetString();
        fileName = eventData["FileName"]:GetString();
        -- Add default extension for saving if not specified
        if (GetExtension(fileName)=="" and forSave==true and filter ~= "*.*")
		then
            fileName = fileName..string.sub(filter,2)
		end
    end
    return fileName
end

function SaveLoadUI:ClearTerrain(eventType, eventData)
	TerrainState:ClearTerrain()
end

function SaveLoadUI:HandleApplyTerrainSpacing(eventType,eventData)
	local v=tonumber(self.menu:GetChild("TerrainSpacing",true).text)
	local sp=TerrainState:GetTerrainSpacing()
	sp.x=v
	sp.z=v
	TerrainState:SetTerrainSpacing(sp)
end

function SaveLoadUI:HandleApplyTerrainHeight(eventType,eventData)
	local v=tonumber(self.menu:GetChild("TerrainHeight",true).text)
	local sp=TerrainState:GetTerrainSpacing()
	sp.y=v
	TerrainState:SetTerrainSpacing(sp)
end

function SaveLoadUI:HandleApplyTerrainSize(eventType, eventData)
	local v=tonumber(self.menu:GetChild("TerrainSize",true).text)
	TerrainState:ResizeTerrain(v,v,true)
end

function SaveLoadUI:CreateFileSelector(title, ok, cancel, initialPath, filters, initialFilter, autoLocalizeTitle)
	if autoLocalizeTitle==nil then autoLocalizeTitle=true end
	
	if self.fileSelector then
		self:UnsubscribeFromEvent(self.fileSelector, "FileSelected")
	end
	
	self.fileSelector=FileSelector()
	self.fileSelector.defaultStyle=uiStyle
	self.fileSelector.title=title
	self.fileSelector.titleText.autoLocalizable=autoLocalizeTitle
	self.fileSelector.path=initialPath
	self.fileSelector:SetButtonTexts(ok, cancel)
	self.fileSelector:SetFilters(filters, initialFilter)
	CenterDialog(self.fileSelector.window)
	self.fileSelector.visible=true
end

function SaveLoadUI:CloseFileSelector()
	if self.fileSelector then
		self:UnsubscribeFromEvent(self.fileSelector, "FileSelected")
	end
	
	self.fileSelector=nil
end

function SaveLoadUI:SaveNormalmap(eventType, eventData)
	self:CreateFileSelector("Save Normalmap", "Save", "Cancel", fileSystem:GetProgramDir().."TerrainEditorData/Save", imageFilters, 0, false)
	self:SubscribeToEvent(self.fileSelector, "FileSelected", "SaveLoadUI:HandleSaveNormalmap")
end

function SaveLoadUI:SaveHeightmap(eventType, eventData)
	self:CreateFileSelector("Save Heightmap", "Save", "Cancel", fileSystem:GetProgramDir().."TerrainEditorData/Save", imageFilters, 0, false)
	self:SubscribeToEvent(self.fileSelector, "FileSelected", "SaveLoadUI:HandleSaveHeightmap")
end

function SaveLoadUI:SaveBlend1(eventType, eventData)
	self:CreateFileSelector("Save Blendmap 1", "Save", "Cancel", fileSystem:GetProgramDir().."TerrainEditorData/Save", imageFilters, 0, false)
	self:SubscribeToEvent(self.fileSelector, "FileSelected", "SaveLoadUI:HandleSaveBlend1")
end

function SaveLoadUI:SaveBlend2(eventType, eventData)
	self:CreateFileSelector("Save Blendmap 2", "Save", "Cancel", fileSystem:GetProgramDir().."TerrainEditorData/Save", imageFilters, 0, false)
	self:SubscribeToEvent(self.fileSelector, "FileSelected", "SaveLoadUI:HandleSaveBlend2")
end

function SaveLoadUI:LoadHeightmap(eventType, eventData)
	self:CreateFileSelector("Load Heightmap", "Load", "Cancel", fileSystem:GetProgramDir().."TerrainEditorData/Save", imageFilters, 0, false)
	self:SubscribeToEvent(self.fileSelector, "FileSelected", "SaveLoadUI:HandleLoadHeightmap")
end

function SaveLoadUI:LoadBlend1(eventType, eventData)
	self:CreateFileSelector("Load Blend 1", "Load", "Cancel", fileSystem:GetProgramDir().."TerrainEditorData/Save", imageFilters, 0, false)
	self:SubscribeToEvent(self.fileSelector, "FileSelected", "SaveLoadUI:HandleLoadBlend1")
end

function SaveLoadUI:LoadBlend2(eventType, eventData)
	self:CreateFileSelector("Load Blend 2", "Load", "Cancel", fileSystem:GetProgramDir().."TerrainEditorData/Save", imageFilters, 0, false)
	self:SubscribeToEvent(self.fileSelector, "FileSelected", "SaveLoadUI:HandleLoadBlend2")
end

function SaveLoadUI:Activate()
	self.menu.visible=true
	self.menu:SetPosition(IntVector2(0,graphics.height-self.menu.height))
end

function SaveLoadUI:Deactivate()
	self.menu.visible=false
end

function SaveLoadUI:HandleSaveNormalmap(eventType, eventData)
	local fname=ExtractFilename(eventData, true)
	if fname~="" then
		print("Save at "..fname)
		
		TerrainState:SaveTerrainNormalMap(fname)
	end
	self:CloseFileSelector()
end

function SaveLoadUI:HandleSaveHeightmap(eventType, eventData)
	local fname=ExtractFilename(eventData, true)
	if fname~="" then
		print("Save at "..fname)
		--TerrainState.hmap:SavePNG(fname)
		TerrainState:SaveHeightMap(fname)
	end
	self:CloseFileSelector()
end

function SaveLoadUI:HandleSaveBlend1(eventType, eventData)
	local fname=ExtractFilename(eventData, true)
	if fname~="" then
		print("Save at "..fname)
		--TerrainState.blend1:SavePNG(fname)
		TerrainState:SaveBlend0(fname)
	end
	self:CloseFileSelector()
end

function SaveLoadUI:HandleSaveBlend2(eventType, eventData)
	local fname=ExtractFilename(eventData, true)
	if fname~="" then
		print("Save at "..fname)
		--TerrainState.blend2:SavePNG(fname)
		TerrainState:SaveBlend1(fname)
	end
	self:CloseFileSelector()
end

function SaveLoadUI:HandleLoadHeightmap(eventType, eventData)
	local fname=ExtractFilename(eventData, true)
	if fname~="" then
		--LoadImage(context, TerrainState.hmap, fname)
		--TerrainState.terrain:SetHeightMap(TerrainState.hmap)
		TerrainState:LoadHeightMap(fname)
	end
	self:CloseFileSelector()
end

function SaveLoadUI:HandleLoadBlend1(eventType, eventData)
	local fname=ExtractFilename(eventData, true)
	if fname~="" then
		--LoadImage(context, TerrainState.blend1, fname)
		--TerrainState.blendtex1:SetData(TerrainState.blend1, false)
		TerrainState:LoadBlend0(fname)
	end
	self:CloseFileSelector()
end

function SaveLoadUI:HandleLoadBlend2(eventType, eventData)
	local fname=ExtractFilename(eventData, true)
	if fname~="" then
		--LoadImage(context, TerrainState.blend2, fname)
		--TerrainState.blendtex2:SetData(TerrainState.blend2, false)
		TerrainState:LoadBlend1(fname)
	end
	self:CloseFileSelector()
end

function SaveLoadUI:Update(dt)
	mainlight.color=self.mainchooser.color
	backlight.color=self.backchooser.color
	zone.ambientColor=self.ambfogchooser.color
	zone.fogColor=self.ambfogchooser.color
	
	self.mainlight.color=mainlight.color
	self.backlight.color=backlight.color
	self.ambfog.color=zone.fogColor
end