return
{
	name="Generic Perlin Terrain",
	description="Create a mottled dirt/grass terrain.",
	options=
	{
	},
	
	execute=function(self)
		local w,h=blend:GetWidth(),blend:GetHeight()
		local x,y
		
		local k=CKernel()
		
		local point5=k:constant(0.5)
		local fbm=k:simplefBm(3, 3, 6, 8, 12345, true)
		local scale=k:multiply(fbm,point5)
		local offset=k:add(scale,point5)
		local gainval=k:constant(0.8)
		local gain=k:gain(gainval,offset)
		
		local vm=CNoiseExecutor(k:getKernel())
		
		for x=0,w-1,1 do
			for y=0,h-1,1 do
				local nx=x/w
				local ny=y/h
				local val=vm:evaluate(CCoordinate(nx,ny,0)).outfloat_
				local col=Color(1,0,0,0):Lerp(Color(0,1,0,0), val)
				blend:SetPixel(x,y,col)
				
			end
		end
		
		blendtex:SetData(blend)
	end,
}