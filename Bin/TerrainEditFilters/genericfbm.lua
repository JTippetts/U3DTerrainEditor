return
{
	name="Generic Perlin Terrain",
	description="Generate a mountainous terrain using generic Perlin noise.",
	options=
	{
		{name="Frequency", type="value", value=7},
		{name="Num Octaves", type="value", value=5},
		{name="Amplitude", type="value", value=1},
		{name="Gain", type="value", value=0.8},
		{name="Seed", type="value", value=12345},
		{name="Tiers", type="flag", value=false},
		{name="Number of tiers", type="value", value=5},
		{name="Use Mask?", type="flag", value=false},
		{name="Invert Mask?", type="flag", value=false},
		{name="Ridged?", type="flag", value=false},
	},
	
	execute=function(self)
		local hw,hh=hmap:GetWidth(),hmap:GetHeight()
		local x,y
		
		local k=CKernel()
		
		local point5=k:constant(0.5)
		local point75=k:constant(0.75)
		local point25=k:constant(0.25)
		local gainval=k:constant(self.options[4].value)
		local fbm
		if self.options[10].value==false then
			fbm=k:simplefBm(3, 3, self.options[2].value, self.options[1].value, self.options[5].value, true)
		else
			fbm=k:simpleRidgedMultifractal(3, 3, self.options[2].value, self.options[1].value, self.options[5].value, true)
		end
		local scale=k:multiply(fbm,point5)
		local offset=k:add(scale,point5)
		
		local last=k:lastIndex()
		
		if self.options[10].value==false then
			fbm=k:simplefBm(3, 3, self.options[2].value, self.options[1].value, self.options[5].value+10, true)
		else
			fbm=k:simpleRidgedMultifractal(3, 3, self.options[2].value, self.options[1].value, self.options[5].value+10, true)
		end
		scale=k:multiply(fbm,point5)
		offset=k:add(scale,point5)
		
		last=k:multiply(k:lastIndex(), last)
		
		
		if self.options[6].value==true then
			local numtiers=k:constant(math.floor(self.options[7].value))
			local tiers=k:smoothTiers(last,numtiers)
		end
		
		--RenderANLKernelToHeight(hmap, mask, k, 0, 1, self.options[8].value, self.options[9].value)
		local buffer=RasterBuffer(hmap:GetWidth(), hmap:GetHeight())
		RenderANLKernelToBuffer(buffer,k,0.1,1)
		SetHeightFromRasterBuffer(hmap,buffer,mask,self.options[8].value, self.options[9].value)
		--hmap:SavePNG("terrain.png")
		
		terrain:ApplyHeightMap()
	end,
}