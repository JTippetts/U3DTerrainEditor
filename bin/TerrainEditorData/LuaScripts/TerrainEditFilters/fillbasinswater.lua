return
{
	name="Fill Basins With Water",
	description="Fill basins on heightmap with water",
	options=
	{
		{name="Max delta", type="value", value=0.000001},
		{name="Offset Water Surface", type="value", value=0.002},
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
		local off=ops["Offset Water Surface"]

		local arr=CArray2Dd()
		TerrainState:GetHeightMap(arr)

		FillBasins(arr,E)

		local x,y
		for x=0,arr:width()-1,1 do
			for y=0,arr:height()-1,1 do
				arr:set(x,y,arr:get(x,y)-off)
			end
		end

		local ms=MaskSettings(ops["Use Mask 0?"], ops["Invert Mask 0?"], ops["Use Mask 1?"], ops["Invert Mask 1?"], ops["Use Mask 2?"], ops["Invert Mask 2?"])
		TerrainState:SetWaterBuffer(arr,ms,0)
	end
}
