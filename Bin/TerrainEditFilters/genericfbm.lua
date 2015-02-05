return
{
	name="Generic Perlin Terrain",
	description="Generate a mountainous terrain using generic Perlin noise.",
	options=
	{
		{name="Frequency", type="value", value=8},
		{name="Num Octaves", type="value", value=4},
		{name="Ridged?", type="flag", value=false},
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
		local fbm
		if self.options[3].value==false then
			fbm=k:simplefBm(3, 3, self.options[2].value, self.options[1].value, self.options[6].value, true)
			local scale=k:multiply(fbm,point5)
			local offset=k:add(scale,point5)
		else 
			fbm=k:simpleRidgedMultifractal(3, 3, self.options[2].value, self.options[1].value, self.options[6].value, true)
			local scale=k:multiply(fbm,point5)
			local offset=k:add(scale,point5)
		end
		local last=k:lastIndex()
		--local gainval=k:constant(self.options[5].value)
		--local gain=k:gain(gainval,last)
		
		if self.options[7].value==true then
			local numtiers=k:constant(math.floor(self.options[8].value))
			local tiers=k:smoothTiers(last,numtiers)
		end
		
		local vm=CNoiseExecutor(k:getKernel())
		local low=100000
		local hi=-100000
		
		--[[for x=0,hw-1,1 do
			for y=0,hh-1,1 do
				local nx=x/hw
				local ny=y/hh
				local val=vm:evaluate(CCoordinate(nx,ny,0)).outfloat_*self.options[4].value
				if val<low then low=val end
				if val>hi then hi=val end
				if self.options[9].value==true then
					local oldheight=GetHeightValue(hmap,x,y)
					local maskval=mask:GetPixelBilinear(nx,ny).r
					if self.options[10].value==true then maskval=1-maskval end
					val=oldheight+maskval*(val-oldheight)
				end
				SetHeightValue(hmap,x,y,val)
				
			end
			collectgarbage()
		end
		
		print("Low: "..low..", hi: "..hi)]]
		RenderANLKernelToHeight(hmap, mask, k, 0, 1, self.options[9].value, self.options[10].value)
		
		terrain:ApplyHeightMap()
	end,
}