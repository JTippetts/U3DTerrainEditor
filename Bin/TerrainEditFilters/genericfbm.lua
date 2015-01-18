return
{
	name="Generic Perlin Terrain",
	description="Generate a mountainous terrain using generic Perlin noise.",
	options=
	{
	},
	
	execute=function(self)
		local hw,hh=hmap:GetWidth(),hmap:GetHeight()
		local x,y
		
		local k=CKernel()
		
		local point5=k:constant(0.5)
		local fbm=k:simplefBm(3, 3, 3, 6, 12345, true)
		local scale=k:multiply(fbm,point5)
		local offset=k:add(scale,point5)
		local gainval=k:constant(0.8)
		local gain=k:gain(gainval,offset)
		
		local vm=CNoiseExecutor(k:getKernel())
		
		for x=0,hw-1,1 do
			for y=0,hh-1,1 do
				local nx=x/hw
				local ny=y/hh
				local val=vm:evaluate(CCoordinate(nx,ny,0)).outfloat_
				SetHeightValue(x,y,val)
				
			end
		end
		
		terrain:ApplyHeightMap()
	end,
}