return
{
	name="Incise Flow",
	description="Calculate water flow, and inset terrain.",
	options=
	{
		{name="Bias", type="value", value=0.87},
		{name="Power", type="value", value=0.1},
		{name="Blur Size", type="value", value=0.005},
		{name="Use Mask 0?", type="flag", value=false},
		{name="Invert Mask 0?", type="flag", value=false},
		{name="Use Mask 1?", type="flag", value=false},
		{name="Invert Mask 1?", type="flag", value=false},
		{name="Use Mask 2?", type="flag", value=false},
		{name="Invert Mask 2?", type="flag", value=false},

	},

	execute=function(self)
		local ops=GetOptions(self.options)
		local b=ops["Bias"]

		local ms=MaskSettings(ops["Use Mask 0?"], ops["Invert Mask 0?"], ops["Use Mask 1?"], ops["Invert Mask 1?"], ops["Use Mask 2?"], ops["Invert Mask 2?"])

		local buf=CArray2Dd()

		local arr=CArray2Dd()
		TerrainState:GetHeightMap(arr)
		waterFlow(arr,buf,0)
		buf:scaleToRange(0,1)
		saveDoubleArray("incise1.png",buf)
		buf:bias(b)
		saveDoubleArray("incise2.png",buf)
		buf:blur(ops["Blur Size"], false)

		saveDoubleArray("incise3.png", buf)

		buf:scale(ops["Power"])

		TerrainState:SetHeightBuffer(buf,ms,2)
	end
}
