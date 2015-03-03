return
{
	name="Clear Terrain",
	description="Clear terrain to a specified detail layer.",
	options=
	{
		{name="Layer", type="value", value=0},
	},
	execute=function(self)
		local layer=self.options[1].value
		if layer==0 then
			blend1:Clear(Color(1,0,0,0))
			blend2:Clear(Color(0,0,0,0))
		elseif layer==1 then
			blend1:Clear(Color(0,1,0,0))
			blend2:Clear(Color(0,0,0,0))
		elseif layer==2 then
			blend1:Clear(Color(0,0,1,0))
			blend2:Clear(Color(0,0,0,0))
		elseif layer==3 then
			blend1:Clear(Color(0,0,0,1))
			blend2:Clear(Color(0,0,0,0))
		elseif layer==4 then
			blend1:Clear(Color(0,0,0,0))
			blend2:Clear(Color(1,0,0,0))
		elseif layer==5 then
			blend1:Clear(Color(0,0,0,0))
			blend2:Clear(Color(0,1,0,0))
		elseif layer==6 then
			blend1:Clear(Color(0,0,0,0))
			blend2:Clear(Color(0,0,1,0))
		else
			blend1:Clear(Color(0,0,0,0))
			blend2:Clear(Color(0,0,0,1))
		end
		blendtex1:SetData(blend1, false)
		blendtex2:SetData(blend2, false)
	end
}