return
{
	name="Generic Perlin Terrain",
	description="Generate a mountainous terrain using generic Perlin noise.",
	options=
	{
		{name="Frequency", type="value", value=8},
		{name="Num Octaves", type="value", value=4},
		{name="Amplitude", type="value", value=1},
		{name="Gain", type="value", value=0.8},
		{name="Seed", type="value", value=12345},
		{name="Tiers", type="flag", value=false},
		{name="Number of tiers", type="value", value=5},
		{name="Use Mask?", type="flag", value=false},
		{name="Invert Mask?", type="flag", value=false},
	},
	
	execute=function(self)
		local hw,hh=hmap:GetWidth(),hmap:GetHeight()
		local x,y
		
		local k=CKernel()
		
		local point5=k:constant(0.5)
		local fbm=k:simplefBm(3, 3, self.options[2].value, self.options[1].value, self.options[5].value, true)
		local scale=k:multiply(fbm,point5)
		local offset=k:add(scale,point5)
		
		local last=k:lastIndex()
		local gainval=k:constant(self.options[4].value)
		local gain=k:gain(gainval,last)
		
		if self.options[6].value==true then
			local numtiers=k:constant(math.floor(self.options[7].value))
			local tiers=k:smoothTiers(gain,numtiers)
		end
		
		RenderANLKernelToHeight(hmap, mask, k, 0, 1, self.options[8].value, self.options[9].value)
		hmap:SavePNG("terrain.png")
		
		terrain:ApplyHeightMap()
	end,
}