--

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