-- Test filter
return
{
	name="Cliffify",
	description="Set terrain to cliff (Blend layer 4) depending on slope of terrain at point.",
	
	options=
	{
		{name="Steepness threshold", type="value", value=0.7},
		{name="Fade", type="value", value=0.4},
		{name="Cliff Layer", type="value", value=1},
		{name="Use Mask?", type="flag", value=false},
		{name="Invert Mask?", type="flag", value=false},
	},
	
	execute=function(self)
		local ops=GetOptions(self.options)
		local bw,bh=TerrainState.blend1:GetWidth(), TerrainState.blend1:GetHeight()
		
		local halffade=ops["Fade"]*0.5
		local fade=ops["Fade"]
		local thresh=ops["Steepness threshold"]
		local layer=ops["Cliff Layer"]
		local usemask=ops["Use Mask?"]
		local invertmask=ops["Invert Mask?"]
		
		SteepnessTerrain(TerrainState.blend1, TerrainState.blend2, TerrainState.hmap, TerrainState.terrain, mask, thresh, fade, layer, usemask, invertmask)
		TerrainState.blendtex1:SetData(TerrainState.blend1,false)
		TerrainState.blendtex2:SetData(TerrainState.blend2,false)
	end,
}