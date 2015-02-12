-- New road builder

return
{
	name="Test Raster",
	Description="Test Raster",
	options=
	{
	},
	
	execute=function(self)
		local buffer=RasterBuffer(hmap:GetWidth(), hmap:GetHeight())
		local blend=RasterBuffer(hmap:GetWidth(), hmap:GetHeight())
		blend:fill(1)
		local c
		
		local plist=RasterVertexList()
		for _,c in ipairs(waypoints) do
			local pos=c.position
			local norm=WorldToNormalized(hmap,terrain,pos)
			local hx=math.floor(norm.x*hmap:GetWidth())
			local hy=math.floor(norm.y*hmap:GetHeight())
			local ht=GetHeightValue(hmap,hx,hy)
			plist:push_back(RasterVertex(hx,hy,1))
		end
		
		local curve=RasterVertexList()
		TessellateLineList(plist, curve, 10)
		local quad=RasterVertexList()
		BuildQuadStrip(curve, quad, 10)
		
		RasterizeQuadStrip(buffer, quad)
		--BlendHeightWithRasterizedBuffer(hmap, buffer, blend)
		--terrain:ApplyHeightMap()
		BlendColorWithRasterizedBuffer(blend1, buffer, Color(0,1,0,0))
		
		
		
		blendtex1:SetData(blend1)
	end,
}