return
{
	name="Perlin Fractal Terrain Types",
	description="Create a mottled dirt/grass terrain.",
	options=
	{
		{name="Frequency", type="value", value=8},
		{name="Num Octaves", type="value", value=6},
		{name="Gain", type="value", value=0.8},
		{name="Seed", type="value", value=12345},
		{name="Use Mask?", type="flag", value=false},
		{name="Invert Mask?", type="flag", value=false},
	},
	
	execute=function(self)
		local frequency=self.options[1].value
		local octaves=self.options[2].value
		local gn=self.options[3].value
		local seed=self.options[4].value
		local usemask=self.options[5].value
		local invertmask=self.options[6].value
		
		local k=CKernel()
		
		local point5=k:constant(0.5)
		local fbm=k:simplefBm(3, 3, octaves, frequency, seed, true)
		local scale=k:multiply(fbm,point5)
		local offset=k:add(scale,point5)
		local gainval=k:constant(gn)
		local gain=k:gain(gainval,offset)
		
		local buffer=RasterBuffer(blend1:GetWidth(), blend1:GetHeight())
		RenderANLKernelToBuffer(buffer,k,0,1)
		BlendColorWithRasterizedBuffer(blend1, buffer, Color(0,1,0,0), mask, usemask, invertmask)
		
		blendtex1:SetData(blend1,false)
		
	end,
}