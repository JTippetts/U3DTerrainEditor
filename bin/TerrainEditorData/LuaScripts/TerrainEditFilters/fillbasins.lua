return
{
	name="Fill Basins",
	description="Fill basins on heightmap",
	options=
	{
		{name="Max delta", type="value", value=0.00001},
		{name="Use Mask 0?", type="flag", value=false},
		{name="Invert Mask 0?", type="flag", value=false},
		{name="Use Mask 1?", type="flag", value=false},
		{name="Invert Mask 1?", type="flag", value=false},
		{name="Use Mask 2?", type="flag", value=false},
		{name="Invert Mask 2?", type="flag", value=false},
	},

	execute=function(self)
		local ops=GetOptions(self.options)
		local E=ops["Max delta"]

		local arr=CArray2Dd()
		TerrainState:GetHeightMap(arr)

		FillBasins(arr,E)

		local ms=MaskSettings(ops["Use Mask 0?"], ops["Invert Mask 0?"], ops["Use Mask 1?"], ops["Invert Mask 1?"], ops["Use Mask 2?"], ops["Invert Mask 2?"])
		TerrainState:SetHeightBuffer(arr,ms)
	end
}
