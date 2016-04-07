-- Terrain Brush select panel

TerrainSelectUI=ScriptObject()

function TerrainSelectUI:Start()
	self.panel=ui:LoadLayout(cache:GetResource("XMLFile", "UI/TerrainBrushSelect.xml"))
	self.panel.style=uiStyle
	ui.root:AddChild(self.panel)
	--self.panel.visible=false
end

function TerrainSelectUI:LoadThumbnails(thumblist)
	local i
	for i=0,7,1 do
		local name="Terrain"..i
		local button=self.panel:GetChild(name,true)
		if button then
			button.texture=cache:GetResource("Texture2D", thumblist[i+1])
		end
	end
	
end


function TerrainSelectUI:HandleActivate(eventType, eventData)
	self.panel.visible=true
end

function TerrainSelectUI:HandleDeactivate(eventType, eventData)
	self.panel.visible=false
end