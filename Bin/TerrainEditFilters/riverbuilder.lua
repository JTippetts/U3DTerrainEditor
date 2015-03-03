-- New road builder

return
{
	name="River Builder v1.0",
	description="Construct a river from the current list of waypoints.",
	options=
	{
		{name="Starting Bed width", type="value", value=2},
		{name="Ending Bed Width", type="value", value=64},
		{name="Bed Hardness", type="value", value=0.125},
		{name="Paving Width", type="value", value=70},
		{name="Paving Hardness", type="value", value=0.125},
		{name="Paving Layer", type="value", value=2},
		{name="Segment steps", type="value", value=10},
		{name="Start Depth", type="value", value=0.1},
		{name="End Depth", type="value", value=0.2},
	},
	
	execute=function(self)
		local startbedwidth=self.options[1].value
		local endbedwidth=self.options[2].value
		local bedhardness=self.options[3].value
		local pavingwidth=self.options[4].value
		local pavinghardness=self.options[5].value
		local pavinglayer=self.options[6].value
		local segments=self.options[7].value
		local startdepth=self.options[8].value
		local enddepth=self.options[9].value
		
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
		
		-- Iterate the points from start to finish and set height
		local lastht=curve:at(0).val_
		for c=0,curve:size()-1,1 do
			local v=curve:at(c)
			v.val_=math.min(lastht, v.val_)
			lastht=v.val_
		end
		
		for c=0,curve:size()-1,1 do
			local v=curve:at(c)
			local t=c/(curve:size()-1)
			local deep=startdepth+t*(enddepth-startdepth)
			v.val_=math.max(0, v.val_-deep)
		end
		
		-- Build road bed quadlist and rasterize
		local quad=RasterVertexList()
		BuildQuadStripVarying(curve, quad, startbedwidth, endbedwidth)
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
		BuildQuadStripVarying(curve, quad, startbedwidth, endbedwidth)
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
		BlendRasterizedBuffer8(blend1,blend2,blend,pavinglayer,mask,usemask,invertmask)
		blendtex1:SetData(blend1,false)
		blendtex2:SetData(blend2,false)
	end,
}