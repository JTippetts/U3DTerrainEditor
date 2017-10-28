return
{
	name="Flow",
	description="Calculate water flow.",
	options=
	{
		{name="Layer", type="list", value="Layer 2", list={"Layer 1","Layer 2","Layer 3","Layer 4","Layer 5","Layer 6","Layer 7","Layer 8","Mask 1","Mask 2","Mask 3"}},
		{name="Bias", type="value", value=0.7},
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
		local b=ops["Bias"]
		local layername=ops["Layer"]
		local which=-1
		if layername=="Layer 1" then which=0
		elseif layername=="Layer 2" then which=1
		elseif layername=="Layer 3" then which=2
		elseif layername=="Layer 4" then which=3
		elseif layername=="Layer 5" then which=4
		elseif layername=="Layer 6" then which=5
		elseif layername=="Layer 7" then which=6
		elseif layername=="Layer 8" then which=7
		end
		
		local ms=MaskSettings(ops["Use Mask 0?"], ops["Invert Mask 0?"], ops["Use Mask 1?"], ops["Invert Mask 1?"], ops["Use Mask 2?"], ops["Invert Mask 2?"])
		
		local buf=CArray2Dd()
		
		local arr=CArray2Dd()
		TerrainState:GetHeightMap(arr)
		waterFlow(arr,buf,0)
		buf:scaleToRange(0,1)
		buf:bias(b)
		
		if which==-1 then
			if layername=="Mask 1" then
				TerrainState:SetMaskBuffer(buf, 0)
			elseif layername=="Mask 2" then
				TerrainState:SetMaskBuffer(buf, 1)
			elseif layername=="Mask 3" then
				TerrainState:SetMaskBuffer(buf, 2)
			end
		else
			if ops["Replace value?"] then
				TerrainState:SetLayerBuffer(buf,which,ms)
			else
				TerrainState:SetLayerBufferMax(buf,which,ms)
			end
		end
	end
}