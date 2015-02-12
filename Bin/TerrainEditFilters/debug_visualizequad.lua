-- Visualize a quadstrip

return
{
	name="Visualize Quad Strip (Debug)",
	description="Visualize  a quadstrip for debugging purposes.",
	options=
	{
		{name="Starting width", type="value", value=16},
		{name="Ending width", type="value", value=16},
		{name="Show as points", type="flag", value=true},
		{name="Segments", type="value", value=10},
	},
	
	execute=function(self)
		local startwidth=self.options[1].value
		local endwidth=self.options[2].value
		local showpoints=self.options[3].value
		local segments=self.options[4].value
		
		local blend=RasterBuffer(hmap:GetWidth(), hmap:GetHeight())
		blend:fill(0)
		
		local c
		
		local plist=RasterVertexList()
		for _,c in ipairs(waypoints) do
			local pos=c.position
			local norm=WorldToNormalized(hmap,terrain,pos)
			local hx=math.floor(norm.x*hmap:GetWidth())
			local hy=math.floor(norm.y*hmap:GetHeight())
			plist:push_back(RasterVertex(hx,hy,1))
		end
		
		local curve=RasterVertexList()
		TessellateLineList(plist, curve, segments)
		local quad=RasterVertexList()
		BuildQuadStripVarying(curve, quad, startwidth, endwidth)
		
		function doLine(v1,v2,steps,color)
			local c
			for c=0,steps-1,1 do
				local t=c/(steps-1)
				local nx=(v1.x_+t*(v2.x_-v1.x_))/hmap:GetWidth()
				local ny=(v1.y_+t*(v2.y_-v1.y_))/hmap:GetHeight()
				local hx=math.floor(nx*blend1:GetWidth())
				local hy=math.floor(ny*blend1:GetHeight())
				
				--local x,y
				--for x=hx-1,hx+1,1 do
					--for y=hy-1,hy+1,1 do
						blend1:SetPixel(hx,blend1:GetHeight()-1-hy,color)
					--end
				--end
			end
		end
		
		RasterizeQuadStrip(blend, quad)
		BlendColorWithRasterizedBuffer(blend1, blend, Color(0,0,1,0))
		
			for c=0,quad:size()-1,2 do
				print(c)
				local v1=quad:at(c)
				local v2=quad:at(c+1)
				doLine(v1,v2,30,Color(0,1,0,0))
			end
			
			for c=0,curve:size()-1,2 do
				local v1=curve:at(c)
				local v2=curve:at(c+1)
				doLine(v1,v2,30,Color(0,1,0,0))
			end
		blendtex1:SetData(blend1)
		
	end,
}