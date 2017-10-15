return
{
	name="Clear Terrain",
	description="Clear terrain to a specified detail layer.",
	options=
	{
		{name="Layer", type="value", value=0},
	},
	execute=function(self)
		local ops=GetOptions(self.options)
		
		local layer=ops["Layer"]
		if layer==0 then
			TerrainState.blend1:Clear(Color(1,0,0,0))
			TerrainState.blend2:Clear(Color(0,0,0,0))
		elseif layer==1 then
			TerrainState.blend1:Clear(Color(0,1,0,0))
			TerrainState.blend2:Clear(Color(0,0,0,0))
		elseif layer==2 then
			TerrainState.blend1:Clear(Color(0,0,1,0))
			TerrainState.blend2:Clear(Color(0,0,0,0))
		elseif layer==3 then
			TerrainState.blend1:Clear(Color(0,0,0,1))
			TerrainState.blend2:Clear(Color(0,0,0,0))
		elseif layer==4 then
			TerrainState.blend1:Clear(Color(0,0,0,0))
			TerrainState.blend2:Clear(Color(1,0,0,0))
		elseif layer==5 then
			TerrainState.blend1:Clear(Color(0,0,0,0))
			TerrainState.blend2:Clear(Color(0,1,0,0))
		elseif layer==6 then
			TerrainState.blend1:Clear(Color(0,0,0,0))
			TerrainState.blend2:Clear(Color(0,0,1,0))
		else
			TerrainState.blend1:Clear(Color(0,0,0,0))
			TerrainState.blend2:Clear(Color(0,0,0,1))
		end
		TerrainState.blendtex1:SetData(TerrainState.blend1, false)
		TerrainState.blendtex2:SetData(TerrainState.blend2, false)
	end
}