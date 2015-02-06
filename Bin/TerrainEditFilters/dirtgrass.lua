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
	},
	
	execute=function(self)
		print(collectgarbage("count"))
		collectgarbage("restart")
		local hw,hh=blend1:GetWidth(),blend1:GetHeight()
		local x,y
		
		local k=CKernel()
		
		local point5=k:constant(0.5)
		local fbm=k:simplefBm(3, 3, self.options[2].value, self.options[1].value, self.options[4].value, true)
		local scale=k:multiply(fbm,point5)
		local offset=k:add(scale,point5)
		local gainval=k:constant(self.options[3].value)
		local gain=k:gain(gainval,offset)
		
		local vm=CNoiseExecutor(k:getKernel())
		
		local c1=Color(1,0,0,0)
		local c2=Color(0,1,0,0)
		local c3=Color(0,0,0,0)
		local coord=CCoordinate(0,0,0)
		
		for x=0,hw-1,1 do
			for y=0,hh-1,1 do
				local nx=x/hw
				local ny=y/hh
				coord:set(nx,ny,0)
				local val=vm:evaluate(coord).outfloat_
				local col=c1:Lerp(c2, val)
				if self.options[5].value==true then
				
					local oldblend=blend1:GetPixel(x,y)
					local maskval=mask:GetPixelBilinear(nx,ny).r
					local newpix=oldblend1:Lerp(col,maskval)
					blend1:SetPixel(x,y,newpix)
				else
					blend1:SetPixel(x,y,col)
				end
				
			end
			collectgarbage()
		end
		
		blendtex1:SetData(blend1,false)
		print(collectgarbage("count"))
		collectgarbage()
		collectgarbage()
		collectgarbage()
		print(collectgarbage("count"))
	end,
}