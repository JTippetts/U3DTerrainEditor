return
{
	name="Generate Noise Blend Layer",
	description="Use a fractal layer to apply a terrain detail type, from one of a set of noise functions.",
	options=
	{
		{name="Layer", type="value", value=2},
		{name="Noise function", type="list", value="ridged", list={"simplefBm","ridged"}},
		{name="Min scale", type="value", value=0},
		{name="Max scale", type="value", value=1},
		{name="Use Mask?", type="flag", value=false},
		{name="Invert Mask?", type="flag", value=false},
		{name="Frequency", type="value", value=16},
		{name="Detail", type="value", value=10},
		{name="Bias", type="value", value=0.5},
		{name="Gain", type="value", value=0.5},
		{name="Random seed", type="value", value=43234},
	},
	
	execute=function(self)
		local ops=GetOptions(self.options)
		
		local k=noisekernels[ops["Noise function"]](ops)
		if k then
			local hw,hh=hmap:GetWidth(),hmap:GetHeight()
			local buffer=CArray2Dd(hw,hh)
			
			map2D(SEAMLESS_NONE, buffer, k, SMappingRanges(0,1,0,1,0,1), 0, k:lastIndex())
			buffer:scaleToRange(ops["Min scale"], ops["Max scale"])
			
			
			local x,y
			for x=0,hw-1,1 do
				for y=0,hh-1,1 do
					buffer:set(x,y, bias(ops["Bias"], gain(ops["Gain"], buffer:get(x,y))))
				end
			end
			
			BlendRasterizedBuffer8(blend1,blend2,buffer,ops["Layer"],mask,ops["Use Mask?"],ops["Invert Mask?"])
		
		
			blendtex1:SetData(blend1,false)
			blendtex2:SetData(blend2,false)
		end
	end,
}