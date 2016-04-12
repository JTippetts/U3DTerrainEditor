-- Editing brush
require 'LuaScripts/Class'

EditingBrush=class(function(self, scene)
	self.brushcursornode=scene:CreateChild()
	self.brushcursor=self.brushcursornode:CreateComponent("CustomGeometry")
	self.brushcursor:SetNumGeometries(1)
	self.brushmat=cache:GetResource("Material", "Materials/TerrainBrush.xml")
end)

function EditingBrush:BuildCursorMesh(radius)
	if not self.brushcursor then return end
	self.brushcursor:BeginGeometry(0,TRIANGLE_LIST)
	self.brushcursor:SetDynamic(true)
	--self.brushcursor:SetMaterial(0, self.brushmat)
	
	local spacing=terrain:GetSpacing()
	local spacingx=spacing.x
	local spacingz=spacing.z
	local meshsize=math.floor(radius)*2+2
	local originx=(-meshsize)*spacingx*0.5
	local originz=(-meshsize)*spacingx*0.5
	
	local uvspacing=1/(meshsize-1)
	
	local x,z
	for x=0,meshsize-2,1 do
		for z=0,meshsize-2,1 do
			self.brushcursor:DefineVertex(Vector3(originx+x*spacingx, 0, originz+z*spacingz))
			self.brushcursor:DefineTexCoord(Vector2(x*uvspacing, z*uvspacing))
			
			self.brushcursor:DefineVertex(Vector3(originx+(x+1)*spacingx, 0, originz+(z+1)*spacingz))
			self.brushcursor:DefineTexCoord(Vector2((x+1)*uvspacing, (z+1)*uvspacing))
			
			self.brushcursor:DefineVertex(Vector3(originx+x*spacingx, 0, originz+(z+1)*spacingz))
			self.brushcursor:DefineTexCoord(Vector2(x*uvspacing, (z+1)*uvspacing))
			
			self.brushcursor:DefineVertex(Vector3(originx+x*spacingx, 0, originz+z*spacingz))
			self.brushcursor:DefineTexCoord(Vector2(x*uvspacing, z*uvspacing))
			
			self.brushcursor:DefineVertex(Vector3(originx+(x+1)*spacingx, 0, originz+z*spacingz))
			self.brushcursor:DefineTexCoord(Vector2((x+1)*uvspacing, z*uvspacing))
			
			self.brushcursor:DefineVertex(Vector3(originx+(x+1)*spacingx, 0, originz+(z+1)*spacingz))
			self.brushcursor:DefineTexCoord(Vector2((x+1)*uvspacing, (z+1)*uvspacing))
		end
	end
	
	self.brushcursor:Commit()
	
	self.brushcursor:SetMaterial(0, self.brushmat)
end

function EditingBrush:Show()
	if self.brushcursor then self.brushcursor:SetEnabled(true) end
end

function EditingBrush:Hide()
	if self.brushcursor then self.brushcursor:SetEnabled(false) end
end

function EditingBrush:SetBrushCursorHeight()
	if not self.brushcursor then return end
	local mousepos
	if input.mouseVisible then
		mousepos=input:GetMousePosition()
	else
		mousepos=ui:GetCursorPosition()
	end
	
	local ground=cam:GetScreenGround(mousepos.x, mousepos.y)
	
	SetBrushCursorHeight(terrain, self.brushcursor, ground.x, ground.z)
end

function EditingBrush:SetPosition(world)
	if not self.brushcursornode then return end

	self.brushcursornode.position=world
end

function EditingBrush:SetBrushPreview(brushtex)
	if not self.brushmat then return end
	self.brushmat:SetTexture(0, brushtex)
end