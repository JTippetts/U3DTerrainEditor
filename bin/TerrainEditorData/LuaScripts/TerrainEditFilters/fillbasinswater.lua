return
{
	name="Fill Basins With Water",
	description="Fill basins on heightmap with water",
	options=
	{
		{name="Max delta", type="value", value=0.0005},
		{name="Offset Water Surface", type="value", value=0.002},
		{name="Use Mask 0?", type="flag", value=false},
		{name="Invert Mask 0?", type="flag", value=false},
		{name="Use Mask 1?", type="flag", value=false},
		{name="Invert Mask 1?", type="flag", value=false},
		{name="Use Mask 2?", type="flag", value=false},
		{name="Invert Mask 2?", type="flag", value=false},
	},

	execute=function(self)
		local ops=GetOptions(self.options)
		local E=ops["Max delta"]
		local off=ops["Offset Water Surface"]

		local arr=CArray2Dd()
		TerrainState:GetHeightMap(arr)

		FillBasins(arr,E)

		local ter=CArray2Dd()
		TerrainState:GetHeightMap(ter)
		arr:subtractArray(ter)

		local buf=CArray2Dd(arr:width(), arr:height())


		local x,y

		local neighborIsNonZero=function(x,y)
			local i,j

			for i=-1,1,1 do
				for j=-1,1,1 do
					local nx=x+i
					local ny=y+j
					if nx>=0 and ny>=0 and nx<buf:width() and ny<buf:height() and nx~=x and ny~=y then
						if buf:get(nx,ny)>0 then return true end
					end
				end
			end
			return false
		end

		for x=0,arr:width()-1,1 do
			for y=0,arr:height()-1,1 do
				local msk=arr:get(x,y)
				if msk>0 then msk=1 end
				buf:set(x,y,msk)
			end
		end

		local buf2=CArray2Dd(arr:width(), arr:height())

		for x=0,arr:width()-1,1 do
			for y=0,arr:height()-1,1 do
				local msk=buf:get(x,y)
				if neighborIsNonZero(x,y) then msk=1 end
				buf2:set(x,y,msk)
			end
		end

		buf2:blur(0.005,false)

		for x=0,arr:width()-1,1 do
			for y=0,arr:height()-1,1 do
				local msk=buf2:get(x,y)

				arr:set(x,y,arr:get(x,y)+msk*ter:get(x,y)-off)
			end
		end

		local ms=MaskSettings(ops["Use Mask 0?"], ops["Invert Mask 0?"], ops["Use Mask 1?"], ops["Invert Mask 1?"], ops["Use Mask 2?"], ops["Invert Mask 2?"])
		TerrainState:SetWaterBuffer(arr,ms,0)
	end
}
