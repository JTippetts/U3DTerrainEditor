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
		{name="Use Mask 0?", type="flag", value=false},
		{name="Invert Mask 0?", type="flag", value=false},
		{name="Use Mask 1?", type="flag", value=false},
		{name="Invert Mask 1?", type="flag", value=false},
		{name="Use Mask 2?", type="flag", value=false},
		{name="Invert Mask 2?", type="flag", value=false},
	},
	
	execute=function(self)
		local ops=GetOptions(self.options)
		local bw,bh=TerrainState:GetBlendWidth(), TerrainState:GetBlendHeight()
		
		local halffade=ops["Fade"]*0.5
		local fade=ops["Fade"]
		local thresh=ops["Steepness threshold"]
		local layer=ops["Cliff Layer"]
		local ms=MaskSettings(ops["Use Mask 0?"], ops["Invert Mask 0?"], ops["Use Mask 1?"], ops["Invert Mask 1?"], ops["Use Mask 2?"], ops["Invert Mask 2?"])
		
		local buf=CArray2Dd()
		TerrainState:GetSteepness(buf,thresh,fade)
		TerrainState:SetLayerBuffer(buf,layer,ms)
		--SteepnessTerrain(TerrainState.blend1, TerrainState.blend2, TerrainState.hmap, TerrainState.terrain, mask, thresh, fade, layer, usemask, invertmask)
		--TerrainState.blendtex1:SetData(TerrainState.blend1,false)
		--TerrainState.blendtex2:SetData(TerrainState.blend2,false)
	end,
}