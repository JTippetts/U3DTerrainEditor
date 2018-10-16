return
{
	name="Basins To Mask",
	description="Calculate a mask from the fill-basins routine.",
	options=
	{
		{name="Max delta", type="value", value=0.000001},
		{name="Which Mask?", type="list", value="Mask 0", list={"Mask 0", "Mask 1", "Mask 2"}},
		{name="Invert Mask?", type="flag", value=false},
		{name="Mask Bias", type="value", value=0.5},
	},

	execute=function(self)
		local ops=GetOptions(self.options)
		local E=ops["Max delta"]
		local which=ops["Which Mask?"]
		local invert=ops["Invert Mask?"]
		local bias=ops["Mask Bias"]

		local arr=CArray2Dd()
		TerrainState:GetHeightMap(arr)
		FillBasins(arr,E)
		local orig=CArray2Dd()
		TerrainState:GetHeightMap(orig)
		arr:subtractArray(orig)
		arr:bias(bias)


		if which=="Mask 0" then
			TerrainState:SetMaskBuffer(arr, 0)
			if invert then TerrainState:InvertMask(0) end
		elseif which=="Mask 1" then
			TerrainState:SetMaskBuffer(arr,1)
			if invert then TerrainState:InvertMask(1) end
		else
			TerrainState:SetMaskBuffer(arr,2)
			if invert then TerrainState:InvertMask(2) end
		end

	end
}
