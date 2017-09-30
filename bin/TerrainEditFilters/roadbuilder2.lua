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
		{name="Distort?", type="flag", value=false},
		{name="Distortion power", type="value", value=4},
	},
	
	execute=function(self)
		local bedwidth=self.options[1].value
		local bedhardness=self.options[2].value
		local pavingwidth=self.options[3].value
		local pavinghardness=self.options[4].value
		local pavinglayer=self.options[5].value
		local segments=self.options[6].value
		local distort=self.options[7].value
		local power=self.options[8].value
		
		local buffer=CArray2Dd(TerrainState.hmap:GetWidth(), TerrainState.hmap:GetHeight())
		local blend=CArray2Dd(TerrainState.hmap:GetWidth(), TerrainState.hmap:GetHeight())
		blend:fill(0)
		
		local c
		
		local plist=RasterVertexList()
		for _,c in ipairs(waypoints) do
			local pos=c.position
			local norm=WorldToNormalized(TerrainState.hmap,TerrainState.terrain,pos)
			local hx=math.floor(norm.x*TerrainState.hmap:GetWidth())
			local hy=math.floor(norm.y*TerrainState.hmap:GetHeight())
			local ht=GetHeightValue(TerrainState.hmap,hx,(TerrainState.hmap:GetHeight()-1)-hy)
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
		
		
		if distort then
			DistortBuffer(blend, xdistort, ydistort, power)
		end
		
		BlendHeightWithRasterizedBuffer(TerrainState.hmap, buffer, blend)
		TerrainState.terrain:ApplyHeightMap()
		
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
		
		if distort then
			DistortBuffer(blend, xdistort, ydistort, power)
		end
	
		BlendRasterizedBuffer8Max(TerrainState.blend1,TerrainState.blend2,blend,pavinglayer,mask,usemask,invertmask)	
		TerrainState.blendtex1:SetData(TerrainState.blend1, false)
		TerrainState.blendtex2:SetData(TerrainState.blend2, false)
	end,
}