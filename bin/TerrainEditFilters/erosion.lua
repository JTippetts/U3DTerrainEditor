return
{
	name="Erosion",
	description="Erode heightmap.",
	options=
	{
		{name="Power", type="value", value=0.3},
		{name="Use Mask 0?", type="flag", value=false},
		{name="Invert Mask 0?", type="flag", value=false},
		{name="Use Mask 1?", type="flag", value=false},
		{name="Invert Mask 1?", type="flag", value=false},
		{name="Use Mask 2?", type="flag", value=false},
		{name="Invert Mask 2?", type="flag", value=false},
		
	},
	
	execute=function(self)
		local ops=GetOptions(self.options)
		local power=ops["Power"]
		local ms=MaskSettings(ops["Use Mask 0?"], ops["Invert Mask 0?"], ops["Use Mask 1?"], ops["Invert Mask 1?"], ops["Use Mask 2?"], ops["Invert Mask 2?"])
		local layername=ops["Layer"]
		
		local arr=CArray2Dd()
		TerrainState:GetHeightMap(arr)
		simpleErode(arr,0,power)
		TerrainState:SetHeightBuffer(arr,ms)
	end
}