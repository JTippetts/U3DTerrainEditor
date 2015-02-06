require 'LuaScripts/rasterization'
function bias(b,v)
	return math.pow(v, math.log(b)/math.log(0.5))
end

function cubic_interpolate(p0, p1, p2, p3, t)
	local e={x=(p3.x-p2.x)-(p0.x-p1.x), y=(p3.y-p2.y)-(p0.y-p1.y), z=(p3.z-p2.z)-(p0.z-p1.z)}
	local f={x=(p0.x-p1.x)-e.x, y=(p0.y-p1.y)-e.y, z=(p0.z-p1.z)-e.z}
	local g={x=p2.x-p0.x, y=p2.y-p0.y, z=p2.z-p0.z}
	local h=p1
	
	local t3=t*t*t
	local t2=t*t
	
	return {x=e.x*t3+f.x*t2+g.x*t+h.x, y=e.y*t3+f.y*t2+g.y*t+h.y, z=e.z*t3+f.z*t2+g.z*t+h.z}
end

function tesselate_curve(plist, tsteps)

 if #plist<4 then return nil end
 local tinc = 1.0 / tsteps
 local curve = {}

 local A=1
 local B=1
 local C=2
 local D=3

 --while A ~= plist:len() do
 while B ~= C do
  t = 0.0
  for i=1,tsteps,1 do
   pt = cubic_interpolate(plist[A], plist[B], plist[C], plist[D], t)
   table.insert(curve,pt)
   t = t + tinc
  end
  A=B
  B=C
  C=D
  D=D+1
  if D> #plist then D=#plist end
  --print(A..", "..B..", "..C..", "..D)
 end

 return curve
end

-- build_quad_strip()
-- Given a point list (p) and a quadstrip (q), iterate the point-list's line segments and insert points
-- to build the quadstrip.





function normalize_vec(v)
 local len = math.sqrt(v.x*v.x + v.z*v.z)
 v.x=v.x/len
 v.z=v.z/len
end

function dotproduct_vec(v1, v2)
 return (v1.x*v2.x + v1.z*v2.z)
end

function lines_are_parallel(P0, P1, Q0, Q1)
 local vec1 = {x=P1.x-P0.x, z=P1.z-P0.z }
 local vec2 = {x=Q1.x-Q0.x, z=Q1.z-Q0.z }
 local perp=vec1.x*vec2.z - vec1.z*vec2.x
 if math.abs(perp)<0.00000001 then return 1
 else return nil
 end
end

function calculate_line_intersection(P0, P1, Q0, Q1)
 local u = {x=P1.x-P0.x, z=P1.z-P0.z }
 local v = {x=Q1.x-Q0.x, z=Q1.z-Q0.z }
 local w = {x=P0.x-Q0.x, z=P0.z-Q0.z }

 local D = u.x*v.z - u.z*v.x

 local t = (u.x*w.z - u.z*w.x) / D
 local result = { x=Q0.x + t*v.x, z=Q0.z + t*v.z }
 return result
end


function build_quad_strip(p, stripwidth)

 if(not p or #p <=2) then print("not enough points") return end    -- Need at least 2 points in the list
 local q={}
 for index=1, #p, 1 do
  
  if index==1 then
    --print("first point")
    local p2=p[index+1]
    local p1=p[index]
    local line_segment={ x=p2.x-p1.x, y=p1.y, z=p2.z-p1.z}
    normalize_vec(line_segment)
    local perp_vec = {x=-line_segment.z, y=0, z=line_segment.x }
    local new_point = { x=p1.x+0.5*stripwidth*perp_vec.x, y=p1.y, z=p1.z+0.5*stripwidth*perp_vec.z}
    table.insert(q,new_point)
    new_point = { x=p1.x-0.5*stripwidth*perp_vec.x, y=p1.y, z=p1.z-0.5*stripwidth*perp_vec.z}
    table.insert(q,new_point)

  elseif index==#p then
    --print("last point")
    local p2=p[index]
    local p1=p[index-1]
    local line_segment={ x=p2.x-p1.x, y=p1.y, z=p2.z-p1.z}
    normalize_vec(line_segment)
    local perp_vec = {x=-line_segment.z, y=0, z=line_segment.x }
    local new_point = { x=p2.x+0.5*stripwidth*perp_vec.x, y=p2.y, z=p2.z+0.5*stripwidth*perp_vec.z}
    table.insert(q,new_point)
    new_point = { x=p2.x-0.5*stripwidth*perp_vec.x, y=p2.y, z=p2.z-0.5*stripwidth*perp_vec.z}
    table.insert(q,new_point)

  else
    --print("middle point")
    local halfwidth = stripwidth*0.5
    
    -- Generate segment vectors
    local p1=p[index-1]
    local p2=p[index]
    local p3=p[index+1]

    local seg1 = { x=p2.x-p1.x, y=p1.y, z=p2.z-p1.z }
    local seg2 = { x=p3.x-p2.x, y=p1.y, z=p3.z-p2.z }
    normalize_vec(seg1)
    normalize_vec(seg2)

    -- Calculate perp vectors
    local perp1 = {x=-seg1.z, y=0, z=seg1.x}
    local perp2 = {x=-seg2.z, y=0, z=seg2.x}

    --Calculate + points for segments
    local P0 = { x=p1.x+perp1.x*halfwidth, y=0, z=p1.z+perp1.z*halfwidth }
    local P1 = { x=p2.x+perp1.x*halfwidth, y=0, z=p2.z+perp1.z*halfwidth }
    local Q0 = { x=p2.x+perp2.x*halfwidth, y=0, z=p2.z+perp2.z*halfwidth }
    local Q1 = { x=p3.x+perp2.x*halfwidth, y=0, z=p3.z+perp2.z*halfwidth }

    if lines_are_parallel(P0, P1, Q0, Q1) ~= nil then
      -- Lines are parallel
      -- Should be okay to append P1 or Q0
      --print ("parallel lines")
      local new_point = {x=P1.x, y=p2.y, z=P1.z}
      table.insert(q,new_point)
    else
      --print ("non_parallel lines")
      -- Lines are not parallel, calculate the intersection
      local intersect = calculate_line_intersection(P0, P1, Q0, Q1)
      local new_point = {x=intersect.x, y=p2.y, z=intersect.z}
      table.insert(q,new_point)
    end

    -- Repeat process for other side now
    P0 = { x=p1.x-perp1.x*halfwidth, y=0, z=p1.z-perp1.z*halfwidth }
    P1 = { x=p2.x-perp1.x*halfwidth, y=0, z=p2.z-perp1.z*halfwidth }
    Q0 = { x=p2.x-perp2.x*halfwidth, y=0, z=p2.z-perp2.z*halfwidth }
    Q1 = { x=p3.x-perp2.x*halfwidth, y=0, z=p3.z-perp2.z*halfwidth }

    if lines_are_parallel(P0, P1, Q0, Q1) ~= nil then
      -- Lines are parallel
      -- Should be okay to append P1 or Q0
      local new_point = {x=P1.x, y=p2.y, z=P1.z}
      table.insert(q,new_point)
    else
      -- Lines are not parallel, calculate the intersection
      local intersect = calculate_line_intersection(P0, P1, Q0, Q1)
      local new_point = {x=intersect.x, y=p2.y,  z=intersect.z}
      table.insert(q,new_point)
    end

    
  end
 end

 --print("done")
 return q
end
  


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