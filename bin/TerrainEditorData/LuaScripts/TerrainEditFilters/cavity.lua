return
{
	name="Cavity Map to Layer",
	description="Generate a cavity map of the terrain, and use it to set the values of a terrain layer.",
	options=
	{
		{name="Layer", type="list", value="Layer 2", list={"Layer 1","Layer 2","Layer 3","Layer 4","Layer 5","Layer 6","Layer 7","Layer 8"}},
		{name="Sample radius", type="value", value=0.01},
		{name="Min scale", type="value", value=0},
		{name="Max scale", type="value", value=1},
		{name="Replace value?", type="flag", value=false},
		{name="Use Mask 0?", type="flag", value=false},
		{name="Invert Mask 0?", type="flag", value=false},
		{name="Use Mask 1?", type="flag", value=false},
		{name="Invert Mask 1?", type="flag", value=false},
		{name="Use Mask 2?", type="flag", value=false},
		{name="Invert Mask 2?", type="flag", value=false},

	},

	execute=function(self)
		local ops=GetOptions(self.options)
		local radius=ops["Sample radius"]
		local low=ops["Min scale"]
		local high=ops["Max scale"]
		local ms=MaskSettings(ops["Use Mask 0?"], ops["Invert Mask 0?"], ops["Use Mask 1?"], ops["Invert Mask 1?"], ops["Use Mask 2?"], ops["Invert Mask 2?"])
		local layername=ops["Layer"]

		local arr=CArray2Dd()
		TerrainState:GetCavityMap(arr,radius,0.0,0.0,1.0,2)
		arr:scaleToRange(low,high)
		local which=0
		if layername=="Layer 1" then which=0
		elseif layername=="Layer 2" then which=1
		elseif layername=="Layer 3" then which=2
		elseif layername=="Layer 4" then which=3
		elseif layername=="Layer 5" then which=4
		elseif layername=="Layer 6" then which=5
		elseif layername=="Layer 7" then which=6
		elseif layername=="Layer 8" then which=7
		end
		if(ops["Replace value?"]) then
			TerrainState:SetLayerBuffer(arr,which,ms)
		else
			TerrainState:SetLayerBufferMax(arr,which,ms)
		end
	end
}
