-- Island generation filter

function doIsland()
	local hw,hh=hmap:GetWidth(), hmap:GetHeight()
	local bw,bh=blend:GetWidth(), blend:GetHeight()
	
	local comp=hmap:GetComponents()
	
	local k=CKernel()
	
	local radial=k:radial()
	local rad=k:constant(0.35)
	local negrad=k:constant(-0.5)
	local sub=k:subtract(rad,radial)
	local div=k:divide(sub,rad)
	local trans=k:translateDomain(div,negrad,negrad)
	
	
	local vm=CNoiseExecutor(k:getKernel())
	
	
	local x,y
	for x=0,hw-1,1 do
		for y=0,hh-1,1 do
			local newhval=vm:evaluate(CCoordinate(x/(hw-1), y/(hh-1))).outfloat_
			
			--newhval=math.max(0, math.min(1, newhval))
			
			local newcolor
			if comp==1 then
				newcolor=Color(newhval,newhval,newhval)
			else
				local r,g=HtToRG(newhval)
				newcolor=Color(r,g,0)
			end
			hmap:SetPixel(x,y,newcolor)
		end
	end
	
	terrain:ApplyHeightMap()
	
	function lerpColors(c1, c2, i)
		return Color(c1.r+i*(c2.r-c1.r), c1.g+i*(c2.g-c1.g), c1.b+i*(c2.b-c1.b))
	end
	
	local dirt=Color(1,0,0)
	local grass=Color(0,1,0)
	local stone=Color(0,0,1)
	
	for x=0,bw-1,1 do
		for y=0,bh-1,1 do
			local j=x/(bw)
			local k=y/bh
			
			local ht=ColorToHeight(hmap:GetPixelBilinear(j,k))
			local newcol
			if ht<0.5 then
				newcol=dirt:Lerp(grass, (ht/0.5))
			else
				newcol=grass:Lerp(stone, (ht-0.5)/0.5)
			end
			blend:SetPixel(x,y,newcol)
		end
	end
	blendtex:SetData(blend)
end