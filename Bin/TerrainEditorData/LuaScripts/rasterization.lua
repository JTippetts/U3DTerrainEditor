function orient2d(a,b,c)
	return (b.x-a.x)*(c.z-a.z) - (b.z-a.z)*(c.x-a.x)
end

function rasterizeFace(v0,v1,v2,img,channel,valmod)
	local minx=math.min(v0.x,v1.x,v2.x)
	local maxx=math.max(v0.x,v1.x,v2.x)
	local minz=math.min(v0.z,v1.z,v2.z)
	local maxz=math.max(v0.z,v1.z,v2.z)
	
	minx=math.floor(math.max(minx,0))
	maxx=math.floor(math.min(maxx,img:GetWidth()-1))
	minz=math.floor(math.max(minz,0))
	maxz=math.floor(math.min(maxz,img:GetHeight()-1))
	
	local p={x=0,y=0,z=0,val=0}
	local u,v
	
	for z=minz,maxz,1 do
		for x=minx,maxx,1 do
			p.x=x
			p.z=z
			
			local w0=orient2d(v1,v2,p)
			local w1=orient2d(v2,v0,p)
			local w2=orient2d(v0,v1,p)
			local sum=w0+w1+w2
			w0=w0/sum
			w1=w1/sum
			w2=w2/sum
			
			
			if w0>=0 and w1>=0 and w2>=0 then
				p.val=(w0*v0.val + w1*v1.val + w2*v2.val)
				if valmod then p.val=valmod(p.val) end
				--print(p.val)
				local col=img:GetPixel(p.x,p.z)
				if channel==1 then
					img:SetPixel(p.x,p.z,Color(p.val,col.g,col.b))
				elseif channel==2 then
					img:SetPixel(p.x,p.z,Color(col.r,p.val,col.b))
				else
					img:SetPixel(p.x,p.z,Color(col.r,col.g,p.val))
				end
			end
			
			
		end
	end
end