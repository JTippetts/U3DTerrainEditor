return
{
	name="Generic Perlin Terrain",
	description="Create a mottled dirt/grass terrain.",
	options=
	{
		{name="Frequency", type="value", value=8},
		{name="Num Octaves", type="value", value=6},
		{name="Gain", type="value", value=0.8},
		{name="Seed", type="value", value=12345},
		{name="Use Mask?", type="flag", value=false},
	},
	
	execute=function(self)
		local hw,hh=blend:GetWidth(),blend:GetHeight()
		local x,y
		
		local k=CKernel()
		
		local point5=k:constant(0.5)
		local fbm=k:simplefBm(3, 3, self.options[2].value, self.options[1].value, self.options[4].value, true)
		local scale=k:multiply(fbm,point5)
		local offset=k:add(scale,point5)
		local gainval=k:constant(self.options[3].value)
		local gain=k:gain(gainval,offset)
		
		local vm=CNoiseExecutor(k:getKernel())
		
		for x=0,hw-1,1 do
			for y=0,hh-1,1 do
				local nx=x/hw
				local ny=y/hh
				local val=vm:evaluate(CCoordinate(nx,ny,0)).outfloat_
				local col=Color(1,0,0,0):Lerp(Color(0,1,0,0), val)
				if self.options[5].value==true then
				
					local oldblend=blend:GetPixel(x,y)
					local maskval=1-mask:GetPixelBilinear(nx,ny).r
					local newpix=oldblend:Lerp(col,maskval)
					if maskval>0 then print(newpix.r,newpix.g,newpix.b,newpix.a) end
					blend:SetPixel(x,y,newpix)
				else
					blend:SetPixel(x,y,col)
				end
				
			end
		end
		
		blendtex:SetData(blend)
	end,
}