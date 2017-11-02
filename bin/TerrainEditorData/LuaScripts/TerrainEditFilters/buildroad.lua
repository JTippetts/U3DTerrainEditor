return
{
	name="Build Road",
	description="Construct a road from the current list of waypoints.",
	options=
	{
		{name="Paving Width", type="value", value=5},
		{name="Segment steps", type="value", value=10},
		{name="Length scale", type="value", value=0.1},
	},
	
	execute=function(self)
		--print("1")
		local ops=GetOptions(self.options)
		
		local pavingwidth=ops["Paving Width"]
		local segments=ops["Segment steps"]
		local scale=ops["Length scale"]
		
		local plist=RasterVertexList()
		for _,c in ipairs(waypoints) do
			local pos=c.position
			plist:push_back(RasterVertex(pos.x,pos.y,pos.z))
		end
		
		local n=scene_:CreateChild()
		local cg=n:CreateComponent("CustomGeometry")
		BuildQuadStripRoad(plist, segments, pavingwidth, scale, cg)
		n:SetPosition(Vector3(0,0.1,0))
		cg:SetMaterial(cache:GetResource("Material", "Materials/road.xml"))
	end,
}