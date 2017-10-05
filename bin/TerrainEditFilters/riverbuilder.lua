-- New road builder

return
{
	name="River Builder v1.0",
	description="Construct a river from the current list of waypoints.",
	options=
	{
		{name="Starting Bed width", type="value", value=64},
		{name="Ending Bed Width", type="value", value=92},
		{name="Bed Hardness", type="value", value=0.125},
		{name="Paving Hardness", type="value", value=0.125},
		{name="Paving Layer", type="value", value=2},
		{name="Segment steps", type="value", value=10},
		{name="Start Depth", type="value", value=0.1},
		{name="End Depth", type="value", value=0.2},
		{name="Use Mask 0?", type="flag", value=false},
		{name="Invert Mask 0?", type="flag", value=false},
		{name="Use Mask 1?", type="flag", value=false},
		{name="Invert Mask 1?", type="flag", value=false},
		{name="Use Mask 2?", type="flag", value=false},
		{name="Invert Mask 2?", type="flag", value=false},
	},
	
	execute=function(self)
		local ops=GetOptions(self.options)
		local startbedwidth=self.options[1].value
		local endbedwidth=self.options[2].value
		local bedhardness=self.options[3].value
		local pavinghardness=self.options[4].value
		local pavinglayer=self.options[5].value
		local segments=self.options[6].value
		local startdepth=self.options[7].value
		local enddepth=self.options[8].value
		
		local ms=MaskSettings(ops["Use Mask 0?"], ops["Invert Mask 0?"], ops["Use Mask 1?"], ops["Invert Mask 1?"], ops["Use Mask 2?"], ops["Invert Mask 2?"])
		
		local buffer=CArray2Dd(TerrainState:GetTerrainWidth(), TerrainState:GetTerrainHeight())
		local blend=CArray2Dd(TerrainState:GetTerrainWidth(), TerrainState:GetTerrainHeight())
		blend:fill(0)
		
		local c
		
		local plist=RasterVertexList()
		for _,c in ipairs(waypoints) do
			local pos=c.position
			local norm=TerrainState:WorldToNormalized(pos)
			local hx=math.floor(norm.x*TerrainState:GetTerrainWidth())
			local hy=math.floor(norm.y*TerrainState:GetTerrainHeight())
			local ht=TerrainState:GetHeightValue(hx,(TerrainState:GetTerrainHeight()-1)-hy)
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
		
		TerrainState:BlendHeightBuffer(buffer,blend,ms)
		
		quad=RasterVertexList()
		BuildQuadStripVarying(curve, quad, startbedwidth, endbedwidth)
		blend:fill(0)
		
		for c=0,quad:size()-1,1 do
			local v=quad:at(c)
			v.val_=c % 2
		end
		RasterizeQuadStrip(blend, quad)
		ApplyBedFunction(blend, pavinghardness, true)
		TerrainState:SetLayerBufferMax(blend,pavinglayer,ms)
		--BlendColorWithRasterizedBuffer(blend1, blend, color)
		--BlendRasterizedBuffer8Max(TerrainState.blend1,TerrainState.blend2,blend,pavinglayer,mask,usemask,invertmask)
		--TerrainState.blendtex1:SetData(TerrainState.blend1,false)
		--TerrainState.blendtex2:SetData(TerrainState.blend2,false)
	end,
}