require 'LuaScripts/rasterization'
require 'LuaScripts/linelistcurve'
  


return
{
	name="Road Builder",
	Description="Convert the waypoint list to a road.",
	options=
	{
		{name="Bed width", type="value", value=4},
		{name="Bed Hardness", type="value", value=0.5},
		{name="Paving Width", type="value", value=2},
		{name="Paving Hardness", type="value", value=0.3},
		{name="Paving Layer", type="value", value=2},
		{name="Segment steps", type="value", value=10},
	},
	
	execute=function(self)
		-- tesselate the waypoints list
		local plist={}
		local c
		for _,c in ipairs(waypoints) do table.insert(plist, {x=c.position.x, y=c.position.y, z=c.position.z}) end
		local curve=tesselate_curve(plist, self.options[6].value)
		if not curve then print("Need at least 4 waypoints for a road.") return end
		
		local quad=build_quad_strip(curve, self.options[1].value)
		if not quad then return end
		
		-- Iterate quadlist and rasterize quads into the mask.
		-- Rasterize elevation into mask.g and blend into mask.b
		
		local spacing=terrain:GetSpacing()
		
		function roadbase(c)
			local hard=math.max(0,math.min(1,self.options[2].value))
			
			c=math.abs(c*2-1)
			return math.max(0,math.min(1,(c-1)/(hard-1)))
		end
		
		function pavingbase(c)
			local hard=math.max(0,math.min(1,self.options[4].value))
			
			c=math.abs(c*2-1)
			return math.max(0,math.min(1,(c-1)/(hard-1)))
		end
		
		local q
		print("Num quad points: "..#quad.."  Num points in plist: "..#curve)
		
		-- Clear green and blue channels
		local x,y
		for x=0,mask:GetWidth()-1,1 do
			for y=0,mask:GetHeight()-1,1 do
				local c=mask:GetPixel(x,y)
				mask:SetPixel(x,y,Color(c.r,0,0))
			end
			collectgarbage()
		end
		
		-- Lay down road elevations in green channel
		for q=1,#quad-3,2 do
			local p1=quad[q]
			local p2=quad[q+1]
			local p3=quad[q+2]
			local p4=quad[q+3]
			
			--Convert world coordinates to normalized, then map to buffer space
			local n1=WorldToNormalized(hmap,terrain,Vector3(p1.x,0,p1.z))
			local n2=WorldToNormalized(hmap,terrain,Vector3(p2.x,0,p2.z))
			local n3=WorldToNormalized(hmap,terrain,Vector3(p3.x,0,p3.z))
			local n4=WorldToNormalized(hmap,terrain,Vector3(p4.x,0,p4.z))
			
			local val1=GetHeightValue(hmap, math.floor(n1.x*hmap:GetWidth()), math.floor(n1.y*hmap:GetHeight()))
			local val2=GetHeightValue(hmap, math.floor(n3.x*hmap:GetWidth()), math.floor(n3.y*hmap:GetHeight()))
			
			local v1={x=math.floor(n1.x*mask:GetWidth()), y=p1.y/spacing.y, val=(p1.y/spacing.y)/255, z=math.floor((1-n1.y)*mask:GetHeight())}
			local v2={x=math.floor(n2.x*mask:GetWidth()), y=p2.y/spacing.y, val=(p2.y/spacing.y)/255, z=math.floor((1-n2.y)*mask:GetHeight())}
			local v3={x=math.floor(n3.x*mask:GetWidth()), y=p3.y/spacing.y, val=(p3.y/spacing.y)/255, z=math.floor((1-n3.y)*mask:GetHeight())}
			local v4={x=math.floor(n4.x*mask:GetWidth()), y=p4.y/spacing.y, val=(p4.y/spacing.y)/255, z=math.floor((1-n4.y)*mask:GetHeight())}
			--print(v1.val, v3.val)
			
			rasterizeFace(v1,v2,v3,mask,2)
			rasterizeFace(v2,v3,v4,mask,2)
			
		end
		collectgarbage()
		
		-- Lay down mask in blue channel
		for q=1,#quad-3,2 do
			local p1=quad[q]
			local p2=quad[q+1]
			local p3=quad[q+2]
			local p4=quad[q+3]
			
			--Convert world coordinates to normalized, then map to buffer space
			local n1=WorldToNormalized(hmap,terrain,Vector3(p1.x,0,p1.z))
			local n2=WorldToNormalized(hmap,terrain,Vector3(p2.x,0,p2.z))
			local n3=WorldToNormalized(hmap,terrain,Vector3(p3.x,0,p3.z))
			local n4=WorldToNormalized(hmap,terrain,Vector3(p4.x,0,p4.z))
			
			local v1={x=math.floor(n1.x*mask:GetWidth()), y=p1.y/spacing.y, val=1, z=math.floor((1-n1.y)*mask:GetHeight())}
			local v2={x=math.floor(n2.x*mask:GetWidth()), y=p2.y/spacing.y, val=0, z=math.floor((1-n2.y)*mask:GetHeight())}
			local v3={x=math.floor(n3.x*mask:GetWidth()), y=p3.y/spacing.y, val=1, z=math.floor((1-n3.y)*mask:GetHeight())}
			local v4={x=math.floor(n4.x*mask:GetWidth()), y=p4.y/spacing.y, val=0, z=math.floor((1-n4.y)*mask:GetHeight())}
			
			rasterizeFace(v1,v2,v3,mask,3,roadbase)
			rasterizeFace(v2,v3,v4,mask,3,roadbase)
			
		end
		collectgarbage()
		--mask:SavePNG("mask.png")
		
		-- Apply road bed
		
		for x=0,hmap:GetWidth()-1,1 do
			for y=0,hmap:GetHeight()-1,1 do
				local nx,ny=x/hmap:GetWidth(), y/hmap:GetHeight()
				local c=mask:GetPixelBilinear(nx,ny)
				local ht=GetHeightValue(hmap,x,y)
				SetHeightValue(hmap,x,y,ht+c.b*(c.g-ht))
			end
			collectgarbage()
		end
		
		for x=0,mask:GetWidth()-1,1 do
			for y=0,mask:GetHeight()-1,1 do
				local c=mask:GetPixel(x,y)
				mask:SetPixel(x,y,Color(c.r,0,0))
			end
			collectgarbage()
		end
		
		-- Lay down paving blend
		quad=build_quad_strip(curve, self.options[3].value)
		for q=1,#quad-3,2 do
			local p1=quad[q]
			local p2=quad[q+1]
			local p3=quad[q+2]
			local p4=quad[q+3]
			
			--Convert world coordinates to normalized, then map to buffer space
			local n1=WorldToNormalized(hmap,terrain,Vector3(p1.x,0,p1.z))
			local n2=WorldToNormalized(hmap,terrain,Vector3(p2.x,0,p2.z))
			local n3=WorldToNormalized(hmap,terrain,Vector3(p3.x,0,p3.z))
			local n4=WorldToNormalized(hmap,terrain,Vector3(p4.x,0,p4.z))
			
			local v1={x=math.floor(n1.x*mask:GetWidth()), y=p1.y/spacing.y, val=1, z=math.floor((1-n1.y)*mask:GetHeight())}
			local v2={x=math.floor(n2.x*mask:GetWidth()), y=p2.y/spacing.y, val=0, z=math.floor((1-n2.y)*mask:GetHeight())}
			local v3={x=math.floor(n3.x*mask:GetWidth()), y=p3.y/spacing.y, val=1, z=math.floor((1-n3.y)*mask:GetHeight())}
			local v4={x=math.floor(n4.x*mask:GetWidth()), y=p4.y/spacing.y, val=0, z=math.floor((1-n4.y)*mask:GetHeight())}
			
			rasterizeFace(v1,v2,v3,mask,3,pavingbase)
			rasterizeFace(v2,v3,v4,mask,3,pavingbase)
			
		end
		collectgarbage()
		
		for x=0,blend1:GetWidth()-1,1 do
			for y=0,blend1:GetHeight()-1,1 do
				local nx=x/blend1:GetWidth()
				local ny=y/blend1:GetHeight()
				local m=mask:GetPixelBilinear(nx,ny)
				local c=blend1:GetPixel(x,y)
				local pavecolor
				if self.options[5].value==0 then
					pavecolor=Color(1,0,0,0)
				elseif self.options[5].value==1 then
					pavecolor=Color(0,1,0,0)
				elseif self.options[5].value==2 then
					pavecolor=Color(0,0,1,0)
				else
					pavecolor=Color(0,0,0,1)
				end
				local newcol=c:Lerp(pavecolor,m.b)
				blend1:SetPixel(x,y,newcol)
			end
			collectgarbage()
		end
		
		terrain:ApplyHeightMap()
		blendtex1:SetData(blend1, false)
		--masktex:SetData(mask)
		
	end
}