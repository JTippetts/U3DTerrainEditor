-- Terrain editor height edit brush

TerrainBrush=ScriptObject()

function bias(b,v)
	return math.pow(v, math.log(b)/math.log(0.5))
end

function quintic_blend(t)
    return t*t*t*(t*(t*6-15)+10);
end

function TerrainBrush:Start()
	
end



function TerrainBrush:Update(dt)
	
end



function TerrainBrush:ApplyBrush(terrainx, terrainz, radius, max, power, hardness, mode, usemask, dt)
	if mode==0 then self:ApplyHeight(terrainx, terrainz, radius, max, power, hardness, mode,usemask, dt)
	elseif mode>=1 and mode<=4 then self:ApplyBlend(terrainx, terrainz, radius, max, power, hardness, mode,usemask, dt)
	elseif mode==5 then self:ApplySmooth(terrainx, terrainz, radius, max, power, hardness, mode,usemask, dt)
	else self:ApplyMask(terrainx, terrainz, radius, max,  power, hardness, mode,usemask, dt)
	end
end

function TerrainBrush:ApplyHeight(terrainx, terrainz, radius, max, power, hardness, mode, usemask, dt)
	local world=Vector3(terrainx,0,terrainz)
	local ht=terrain:WorldToHeightMap(world)
	local comp=hmap:GetComponents()
	
	local hx,hz
	local sz=math.floor(radius)+1
	for hx=ht.x-sz,ht.x+sz,1 do
		for hz=ht.y-sz,ht.y+sz,1 do
			if hx>=0 and hx<hmap:GetWidth() and hz>=0 and hz<hmap:GetHeight() then
				local dx=hx-ht.x
				local dz=hz-ht.y
				local d=math.sqrt(dx*dx+dz*dz)
				--local i=((radius-d)/radius)
				local i=((d-radius)/(hardness*radius-radius))
				i=math.max(0,math.min(1,i))
				i=(i*dt*power)
				--i=bias(hardness,i)*dt*power
				
				if usemask then
					local m=mask:GetPixelBilinear(hx/hmap:GetWidth(), hz/hmap:GetHeight()).r
					--print(hx,hmap:GetWidth(),hz,hmap:GetHeight(),hx/hmap:GetWidth(), hz/hmap:GetHeight(),m)
					i=i*(m)
				end
				local color=hmap:GetPixel(hx,hz)
				
				-- Convert heightmap pixel from format
				-- If greyscale, no conversion necessary
				-- If RGB, Red is MSB and Green is LSB
				local hval=0
				if comp==1 then
					hval=color.r
				else
					hval=color.r+color.g/256.0
				end
				local newhval=hval + (max-hval)*i
				
				local newcolor
				if comp==1 then
					newcolor=Color(newhval,newhval,newhval)
				else
					local r,g=HtToRG(newhval)
					newcolor=Color(r,g,0)
				end
				hmap:SetPixel(hx,hz,newcolor)
			end
		end
	end
	
	terrain:ApplyHeightMap()
end

function SetHeightValue(x,y,val)
	local comp=hmap:GetComponents()
	local color
	if comp==1 then
		color=Color(val,val,val)
	else
		local r,g=HtToRG(val)
		color=Color(r,g,0)
	end
	hmap:SetPixel(x,y,color)
end

function GetHeightValue(x,y)
	local comp=hmap:GetComponents()
	local color=hmap:GetPixel(x,y)
	if comp==1 then
		return color.r
	else
		return color.r+color.g/256.0
	end
end

function WorldToNormalized(world)
	local spacing=terrain:GetSpacing()
	local patchSize=terrain:GetPatchSize()
	local numPatches=IntVector2((hmap:GetWidth() - 1) / patchSize, (hmap:GetHeight() - 1) / patchSize);
	local patchWorldSize=Vector2(spacing.x * patchSize*numPatches.x, spacing.z * patchSize*numPatches.y);
	local patchWorldOrigin=Vector2(-0.5 * patchWorldSize.x, -0.5 * patchWorldSize.y)
	--local position = scene:GetWorldTransform():Inverse() * world;
    local xPos = (world.x - patchWorldOrigin.x) 
    local zPos = (world.z - patchWorldOrigin.y)
	
	return Vector2(xPos/patchWorldSize.x, zPos/patchWorldSize.y)
end

function NormalizedToWorld(normalized)
	local spacing=terrain:GetSpacing()
	local patchSize=terrain:GetPatchSize()
	local numPatches=IntVector2((hmap:GetWidth() - 1) / patchSize, (hmap:GetHeight() - 1) / patchSize);
	local patchWorldSize=Vector2(spacing.x * patchSize*numPatches.x, spacing.z * patchSize*numPatches.y);
	local patchWorldOrigin=Vector2(-0.5 * patchWorldSize.x, -0.5 * patchWorldSize.y)
	
	return Vector3(patchWorldOrigin.x+normalized.x*patchWorldSize.x, 0, patchWorldOrigin.y+normalized.y*patchWorldSize.y)
	--local position = scene:GetWorldTransform():Inverse() * world;
end

function TerrainBrush:ApplyBlend(terrainx, terrainz, radius, max, power, hardness, mode,usemask, dt)
	local world=Vector3(terrainx,0,terrainz)
	local normalized=WorldToNormalized(world)
	
	--local ht=terrain:WorldToHeightMap(world)
	
	local ratio=((blend:GetWidth())/(hmap:GetWidth()))
	
	local ix=math.floor(normalized.x*(blend:GetWidth()-1))
	local iy=math.floor(normalized.y*(blend:GetHeight()-1))
	iy=blend:GetHeight()-iy
	radius=radius*ratio
	
	--print(ht.x,ht.y,ix,iy)
	
	local sz=math.floor(radius)+1
	local hx,hz
	for hx=ix-sz,ix+sz,1 do
		for hz=iy-sz,iy+sz,1 do
			if hx>=0 and hx<blend:GetWidth() and hz>=0 and hz<blend:GetHeight() then
				local dx=hx-ix
				local dz=hz-iy
				local d=math.sqrt(dx*dx+dz*dz)
				--local i=((radius-d)/radius)
				local i=((d-radius)/(hardness*radius-radius))
				i=math.max(0,math.min(1,i))
				i=i*dt*power
				--i=bias(hardness,i)*dt*power
				if usemask then
					local m=mask:GetPixelBilinear(hx/hmap:GetWidth(), hz/hmap:GetHeight()).r
					--print(hx,hmap:GetWidth(),hz,hmap:GetHeight(),hx/hmap:GetWidth(), hz/hmap:GetHeight(),m)
					i=i*(m)
				end
				
				local col=blend:GetPixel(hx,hz)
				if mode==1 then
					col.r=col.r+i*(1-col.r)
					col.r=math.min(1,col.r)
					local others=col.g+col.b+col.a
					col.g=(col.g/others)*(1-col.r)
					col.b=(col.b/others)*(1-col.r)
					col.a=(col.a/others)*(1-col.r)
				elseif mode==2 then
					col.g=col.g+i*(1-col.g)
					col.g=math.min(1,col.g)
					local others=col.r+col.b+col.a
					col.r=(col.r/others)*(1-col.g)
					col.b=(col.b/others)*(1-col.g)
					col.a=(col.a/others)*(1-col.g)
				elseif mode==3 then
					col.b=col.b+i*(1-col.b)
					col.b=math.min(1,col.b)
					local others=col.r+col.g+col.a
					col.r=(col.r/others)*(1-col.b)
					col.g=(col.g/others)*(1-col.b)
					col.a=(col.a/others)*(1-col.b)
				else
					col.a=col.a+i*(1-col.a)
					col.a=math.min(1,col.a)
					local others=col.r+col.g+col.b
					col.r=(col.r/others)*(1-col.a)
					col.g=(col.g/others)*(1-col.a)
					col.b=(col.b/others)*(1-col.a)
				end
				blend:SetPixel(hx,hz,col)
			end
		end
	end
	
	blendtex:SetData(blend)
end

function GaussianKernel(size)
	local kernel={}
	local c=size/2
	local total=0
	local x,y
	for x=1,size,1 do
		kernel[x]={}
	end
	
	for x=1,size,1 do
		for y=1,size,1 do
			local dx=(x-c)
			local dy=(y-c)
			local d=math.sqrt(dx*dx+dy*dy)
			local i=(c-d)/c
			i=math.max(0,math.min(1,i))
			kernel[x][y]=i
			total=total+i
		end
	end
	
	for x=1,size,1 do
		for y=1,size,1 do
			kernel[x][y]=kernel[x][y]/total
		end
	end
	return kernel
end

kernel=GaussianKernel(7)
kernel9=GaussianKernel(9)


local i,j
s="{"
for i=1,9,1 do
	for j=1,9,1 do
		s=s..tostring(kernel[i][j])
	end
	s=s.."\n"
end
s=s.."};"
print(s)

function TerrainBrush:ApplySmooth(terrainx, terrainz, radius, max, power, hardness, mode,usemask, dt)
	local world=Vector3(terrainx,0,terrainz)
	local ht=terrain:WorldToHeightMap(world)
	local comp=hmap:GetComponents()
	
	function calcSmooth(terrainx, terrainz, kernel)
		local x,z
		local sum=0
		local weight=0
		local size=#kernel
		
		local ox,oz=terrainx-math.ceil(size/2), terrainz-math.ceil(size/2)
		
		for x=1, size, 1 do
			for z=1, size, 1 do
				if x>=0 and x<hmap:GetWidth() and z>=0 and z<hmap:GetHeight() then
					local color=hmap:GetPixel(x+ox,z+oz)
					local hval
					if comp==1 then hval=color.r
					else hval=color.r+color.g/256
					end
					sum=sum+hval*kernel[x][z]
					weight=weight+kernel[x][z]
				end
			end
		end
		
		if weight>0 then
			return sum/weight
		else return 0
		end
	end
	
	
	local hx,hz
	local sz=math.floor(radius)+1
	for hx=ht.x-sz,ht.x+sz,1 do
		for hz=ht.y-sz,ht.y+sz,1 do
			if hx>=0 and hx<hmap:GetWidth() and hz>=0 and hz<hmap:GetHeight() then
				local dx=hx-ht.x
				local dz=hz-ht.y
				local d=math.sqrt(dx*dx+dz*dz)
				--local i=((radius-d)/radius)
				local i=((d-radius)/(hardness*radius-radius))
				i=math.max(0,math.min(1,i))
				i=i*dt*power
				--i=bias(hardness,i)*dt*power
				
				if usemask then
					local m=mask:GetPixelBilinear(hx/hmap:GetWidth(), hz/hmap:GetHeight()).r
					i=i*(m)
				end
				
				local smooth=calcSmooth(hx,hz,kernel)
				local color=hmap:GetPixel(hx,hz)
				
				-- Convert heightmap pixel from format
				-- If greyscale, no conversion necessary
				-- If RGB, Red is MSB and Green is LSB
				local hval=0
				if comp==1 then
					hval=color.r
				else
					hval=color.r+color.g/256.0
				end
				local newhval=hval+(smooth-hval)*i
				local newcolor
				if comp==1 then
					newcolor=Color(newhval,newhval,newhval)
				else
					local r,g=HtToRG(newhval)
					newcolor=Color(r,g,0)
				end
				hmap:SetPixel(hx,hz,newcolor)
			end
		end
	end
	
	terrain:ApplyHeightMap()
end

function TerrainBrush:ApplyMask(terrainx, terrainz, radius, max, power, hardness, mode,usemask, dt)
	local world=Vector3(terrainx,0,terrainz)
	local normalized=WorldToNormalized(world)
	
	local ratio=((mask:GetWidth())/(hmap:GetWidth()))
	
	local ix=math.floor(normalized.x*(mask:GetWidth()-1))
	local iy=math.floor(normalized.y*(mask:GetHeight()-1))
	iy=mask:GetHeight()-iy
	radius=radius*ratio
	
	--print(ht.x,ht.y,ix,iy)
	
	local sz=math.floor(radius)+1
	local hx,hz
	for hx=ix-sz,ix+sz,1 do
		for hz=iy-sz,iy+sz,1 do
			if hx>=0 and hx<mask:GetWidth() and hz>=0 and hz<mask:GetHeight() then
				local dx=hx-ix
				local dz=hz-iy
				local d=math.sqrt(dx*dx+dz*dz)
				--local i=((radius-d)/radius)
				local i=(d-radius)/(hardness*radius-radius)
				i=math.max(0,math.min(1,i))
				i=i*dt*power
				--i=bias(hardness,i)*dt*power
				
				local col=mask:GetPixel(hx,hz)
				col.r=col.r+i*((1-max)-col.r)
				mask:SetPixel(hx,hz,col)
			end
		end
	end
	
	masktex:SetData(mask)
end
