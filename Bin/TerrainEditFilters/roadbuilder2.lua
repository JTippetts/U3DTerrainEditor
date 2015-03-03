-- New road builder

return
{
	name="Road Builder v2.0",
	description="Construct a road from the current list of waypoints.",
	options=
	{
		{name="Bed width", type="value", value=16},
		{name="Bed Hardness", type="value", value=0.5},
		{name="Paving Width", type="value", value=6},
		{name="Paving Hardness", type="value", value=0.5},
		{name="Paving Layer", type="value", value=2},
		{name="Segment steps", type="value", value=10},
	},
	
	execute=function(self)
		local bedwidth=self.options[1].value
		local bedhardness=self.options[2].value
		local pavingwidth=self.options[3].value
		local pavinghardness=self.options[4].value
		local pavinglayer=self.options[5].value
		local segments=self.options[6].value
		
		local buffer=RasterBuffer(hmap:GetWidth(), hmap:GetHeight())
		local blend=RasterBuffer(hmap:GetWidth(), hmap:GetHeight())
		blend:fill(0)
		
		local c
		
		local plist=RasterVertexList()
		for _,c in ipairs(waypoints) do
			local pos=c.position
			local norm=WorldToNormalized(hmap,terrain,pos)
			local hx=math.floor(norm.x*hmap:GetWidth())
			local hy=math.floor(norm.y*hmap:GetHeight())
			local ht=GetHeightValue(hmap,hx,(hmap:GetHeight()-1)-hy)
			plist:push_back(RasterVertex(hx,hy,ht))
		end
		
		local curve=RasterVertexList()
		TessellateLineList(plist, curve, segments)
		
		-- Build road bed quadlist and rasterize
		local quad=RasterVertexList()
		BuildQuadStrip(curve, quad, bedwidth)
		RasterizeQuadStrip(buffer, quad)
		
		-- Iterate roadbed quadlist and set alternate verts to 0 and 1, rasterize to blend and apply the paving modifier
		for c=0,quad:size()-1,1 do
			local v=quad:at(c)
			v.val_=c % 2
		end
		RasterizeQuadStrip(blend, quad)
		ApplyBedFunction(blend, bedhardness, true)
		
		BlendHeightWithRasterizedBuffer(hmap, buffer, blend)
		terrain:ApplyHeightMap()
		
		quad=RasterVertexList()
		BuildQuadStrip(curve, quad, pavingwidth)
		blend:fill(0)
		local color
		if pavinglayer==0 then color=Color(1,0,0,0)
		elseif pavinglayer==1 then color=Color(0,1,0,0)
		elseif pavinglayer==2 then color=Color(0,0,1,0)
		else color=Color(0,0,0,1)
		end
		
		for c=0,quad:size()-1,1 do
			local v=quad:at(c)
			v.val_=c % 2
		end
		RasterizeQuadStrip(blend, quad)
		ApplyBedFunction(blend, pavinghardness, true)
		--BlendColorWithRasterizedBuffer(blend1, blend, color)	
		BlendRasterizedBuffer8Max(blend1,blend2,blend,pavinglayer,mask,usemask,invertmask)	
		blendtex1:SetData(blend1, false)
		blendtex2:Setdata(blend2, false)
	end,
}