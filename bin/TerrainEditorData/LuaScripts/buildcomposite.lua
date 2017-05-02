-- Composite texture packing
-- Manually build mip levels of composite textures from a list of filenames

function log2(n)
	return math.log(n) / math.log(2)
end

function BuildCompositeTexture(filenames)
	if #filenames ~= 4 then print("Must specify 4 tile textures") return end
	
	local tex=Image:new(context)
	local ttex=tex
	
	-- Load the textures
	local i,f
	local textures={}
	for i,f in ipairs(filenames) do
		print("Loading "..f.."...")
		textures[i]=cache:GetResource("Image", f)
	end
	
	local tilewidth=textures[1]:GetWidth()
	local tileheight=textures[1]:GetHeight()
	
	if tilewidth~=tileheight then print("Tile textures must be square.") return end
	
	if textures[2]:GetWidth()~=tilewidth or textures[3]:GetWidth()~=tilewidth or textures[4]:GetWidth()~=tilewidth or
		textures[2]:GetHeight()~=tileheight or textures[3]:GetHeight()~=tileheight or textures[4]:GetHeight() ~= tileheight then
		print("Tile textures must all be same size.")
		local c
		for c=1,4,1 do
			print("Image "..c..": "..textures[2]:GetWidth()..","..textures[2]:GetHeight())
		end
		print("tilewidth: "..tilewidth..", tileheight: "..tileheight)
		return
	end
	
	if not IsPowerOfTwo(tilewidth) then
		print("Tile textures must be power-of-2 sized.")
		return
	end
	
	local numlevels=math.floor(log2(tilewidth))
	-- The last level (1x1) is skipped for a 2x2 tile composite
	print("Number of levels: "..(numlevels))
	print("Tile size (top level): "..tilewidth)
	
	local tilesize=tilewidth
	tex:SetSize(2*tilesize, 2*tilesize,4)
	local t1,t2,t3,t4=textures[1],textures[2],textures[3],textures[4]
	
	for i=0,numlevels,1 do
		-- Copy current textures into top level
		CopyImageInto(ttex, t1, 0, 0)
		CopyImageInto(ttex, t2, tilesize, 0)
		CopyImageInto(ttex, t3, 0,tilesize)
		CopyImageInto(ttex, t4, tilesize, tilesize)
		
		ttex=GetNextImageLevel(ttex)
		t1=GetNextImageLevel(t1)
		t2=GetNextImageLevel(t2)
		t3=GetNextImageLevel(t3)
		t4=GetNextImageLevel(t4)
		tilesize=tilesize/2
		
	end
	
	return tex
end