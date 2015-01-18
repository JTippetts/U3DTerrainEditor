-- Terrain editing prototype
-- Water example.
-- This sample demonstrates:
--     - Creating a large plane to represent a water body for rendering
--     - Setting up a second camera to render reflections on the water surface

require "LuaScripts/Utilities/Sample"
require "LuaScripts/thirdpersoncamera"
require "LuaScripts/terraineditUI"
require "LuaScripts/terraineditheightbrush"

require "LuaScripts/testisland"

function HtToRG(ht)
	local expht=math.floor(ht*255)
	local rm=ht*255-expht
	local r=expht/255
	local g=rm
	return r,g
end

function RGToHt(r,g)
	return r+g/256
end

function ColorToHeight(col)
	return (col.r+col.g/256)
end

blendlayer=1
blendbrush=false

function applyBlendBrush(x,z,layer,radius,power,dt)
	local world=Vector3(x,0,z)
	local ht=terrain:WorldToHeightMap(world)
	local ix=math.floor((ht.x/hmap:GetWidth())*blend:GetWidth())
	local iy=math.floor((ht.y/hmap:GetHeight())*blend:GetHeight())
	
	local sz=math.floor(radius)+1
	local hx,hz
	for hx=ix-sz,ix+sz,1 do
		for hz=iy-sz,iy+sz,1 do
			if hx>=0 and hx<blend:GetWidth() and hz>=0 and hz<blend:GetHeight() then
				local dx=hx-ix
				local dz=hz-iy
				local d=math.sqrt(dx*dx+dz*dz)
				local i=((radius-d)/radius)*dt*power
				i=math.max(0,math.min(1,i))
				
				local col=blend:GetPixel(hx,hz)
				if layer==0 then
					col.r=col.r+i*(1-col.r)
					col.r=math.min(1,col.r)
					local others=col.g+col.b
					col.g=(col.g/others)*(1-col.r)
					col.b=(col.b/others)*(1-col.r)
				elseif layer==1 then
					col.g=col.g+i*(1-col.g)
					col.g=math.min(1,col.g)
					local others=col.r+col.b
					col.r=(col.r/others)*(1-col.g)
					col.b=(col.b/others)*(1-col.g)
				else
					col.b=col.b+i*(1-col.b)
					col.b=math.min(1,col.b)
					local others=col.r+col.g
					col.r=(col.r/others)*(1-col.b)
					col.g=(col.g/others)*(1-col.b)
				end
				blend:SetPixel(hx,hz,col)
			end
		end
	end
	
	blendtex:SetData(blend)
end

function applyHeightBrush(x,z,radius,max,power,dt)
	local world=Vector3(x,0,z)
	local ht=terrain:WorldToHeightMap(world)
	--print("Image coords: "..ht.x..","..ht.y)
	local comp=hmap:GetComponents()
	
	local hx,hz
	local sz=math.floor(radius)+1
	for hx=ht.x-sz,ht.x+sz,1 do
		for hz=ht.y-sz,ht.y+sz,1 do
			if hx>=0 and hx<hmap:GetWidth() and hz>=0 and hz<hmap:GetHeight() then
				local dx=hx-ht.x
				local dz=hz-ht.y
				local d=math.sqrt(dx*dx+dz*dz)
				local i=((radius-d)/radius)*dt*power
				i=math.max(0,math.min(1,i))
				--print(i)
				local color=hmap:GetPixel(hx,hz)
				local hval=0
				if comp==1 then
					hval=color.r
				else
					hval=color.r+color.g/256.0
				end
				--print("Old h: "..hval)
				local newhval=hval + (max-hval)*i
				--print("New h: "..newhval)
				--local newhval=hval+i
				local newcolor
				if comp==1 then
					newcolor=Color(newhval,newhval,newhval)
				else
					local r,g=HtToRG(newhval)
					newcolor=Color(r,g,0)
				end
				hmap:SetPixel(hx,hz,newcolor)
				--print("Old h: "..hval.." New h:"..newhval)
				
			end
		end
	end
	
	terrain:ApplyHeightMap()
	
end

function Start()
    -- Execute the common startup for samples
	--local style = cache:GetResource("XMLFile", "UI/DefaultStyle.xml")
	-- Set the loaded style as default style
    --ui.root.defaultStyle = style
    SampleStart()

    -- Create the scene content
    CreateScene()

    -- Create the UI content
    --CreateInstructions()


    -- Hook up to the frame update event
    SubscribeToEvents()
	
	local dirs=cache.resourceDirs
	if dirs then
		print("Resource dirs:")
		local c
		for c=1,#dirs,1 do
			print(dirs[c])
		end
	end
	
end

function CreateScene()
    scene_ = Scene()
	
	--[[cursor=Cursor:new(context)
	cursor:DefineShape(CS_NORMAL, cache:GetResource("Image", "Textures/buttons.png"), IntRect(960,64,1023,127), IntVector2(20,15))
	cursor:SetStyleAuto(ui.root.defaultStyle)
	ui.cursor=cursor
	ui.cursor.visible=true
	ui.cursor:SetPosition(ui.root.width/2, ui.root.height/2)]]
	CreateCursor()

    -- Create octree, use default volume (-1000, -1000, -1000) to (1000, 1000, 1000)
    scene_:CreateComponent("Octree")

    -- Create a Zone component for ambient lighting & fog control
    local zoneNode = scene_:CreateChild("Zone")
    local zone = zoneNode:CreateComponent("Zone")
    zone.boundingBox = BoundingBox(-1000.0, 1000.0)
    zone.ambientColor = Color(0.3, 0.3, 0.4)
    zone.fogColor = Color(1,1,1)
    zone.fogStart = 300.0
    zone.fogEnd = 325.0

    -- Create a directional light to the world. Enable cascaded shadows on it
    local lightNode = scene_:CreateChild("DirectionalLight")
    lightNode.direction = Vector3(0.6, -1.0, 0.8)
    local light = lightNode:CreateComponent("Light")
    light.lightType = LIGHT_DIRECTIONAL
    light.castShadows = true
    light.shadowBias = BiasParameters(0.00025, 0.5)
    light.shadowCascade = CascadeParameters(10.0, 50.0, 200.0, 0.0, 0.8)
    light.specularIntensity = 0.2;
    -- Apply slightly overbright lighting to match the skybox
    light.color = Color(1, 1, 1);

    -- Create skybox. The Skybox component is used like StaticModel, but it will be always located at the camera, giving the
    -- illusion of the box planes being far away. Use just the ordinary Box model and a suitable material, whose shader will
    -- generate the necessary 3D texture coordinates for cube mapping
    local skyNode = scene_:CreateChild("Sky")
    skyNode:SetScale(500.0) -- The scale actually does not matter
    local skybox = skyNode:CreateComponent("Skybox")
    skybox.model = cache:GetResource("Model", "Models/Box.mdl")
    skybox.material = cache:GetResource("Material", "Materials/Skybox.xml")

    -- Create heightmap terrain
    local terrainNode = scene_:CreateChild("Terrain")
    terrainNode.position = Vector3(0.0, 0.0, 0.0)
    terrain = terrainNode:CreateComponent("Terrain")
    terrain.patchSize = 64
    terrain.spacing = Vector3(0.20, 0.08, 0.20) -- Spacing between vertices and vertical resolution of the height map
    terrain.smoothing = true
	hmap=Image:new(context)
	hmap:SetSize(513,513,3)
    terrain.heightMap = hmap
    terrain.material = cache:GetResource("Material", "Materials/TerrainEdit.xml")
    -- The terrain consists of large triangles, which fits well for occlusion rendering, as a hill can occlude all
    -- terrain patches and other objects behind it
    terrain.occluder = true
	
	mask=Image(context)
	masktex=Texture2D:new(context)
	masktex:SetSize(0,0,0,TEXTURE_DYNAMIC)
	mask:SetSize(1024,1024,1)
	mask:Clear(Color(1,1,1))
	masktex:SetData(mask, false)
	terrain:GetMaterial():SetTexture(12,masktex)
	
	hmap:Clear(Color(0,0,0))
	terrain:SetSmoothing(false)
	print("Components: "..hmap:GetComponents())
	blendtex=Texture2D:new(context)
	blendtex:SetSize(0,0,0,TEXTURE_DYNAMIC)
	terrain:GetMaterial():SetTexture(0,blendtex)
	
	blend=Image(context)
	blend:SetSize(512,512,4)
	blend:Clear(Color(1,0,0,0))
	blendtex:SetData(blend, false)
	--print("Checkpoint")
	
	editbrush=scene_:CreateScriptObject("TerrainBrush")
	terrainui=scene_:CreateScriptObject("TerrainEditUI")
	


   
    -- Create the camera. Set far clip to match the fog. Note: now we actually create the camera node outside
    -- the scene, because we want it to be unaffected by scene load / save
    cameraNode=scene_:CreateChild("Camera")
	cam=cameraNode:CreateScriptObject("ThirdPersonCamera")
	cam.clipcamera=false
	cam.allowspin=true
	cam.allowzoom=true
	cam.allowpitch=true
	cam.maxfollow=100
	cam.follow=100
	cam.clipdist=325
	cam:Finalize()

	projecttozero=true
end

function CreateInstructions()
    -- Construct new Text object, set string to display and font to use
    local instructionText = ui.root:CreateChild("Text")
    instructionText:SetText("Use WASD keys and mouse to move")
    instructionText:SetFont(cache:GetResource("Font", "Fonts/Anonymous Pro.ttf"), 15)
    instructionText.textAlignment = HA_CENTER

    -- Position the text relative to the screen center
    instructionText.horizontalAlignment = HA_CENTER
    instructionText.verticalAlignment = VA_CENTER
    instructionText:SetPosition(0, ui.root.height / 4)
end

function SubscribeToEvents()
    -- Subscribe HandleUpdate() function for processing update events
    SubscribeToEvent("Update", "HandleUpdate")
end

function HandleUpdate(eventType, eventData)
    -- Take the frame time step, which is stored as a float
    local timeStep = eventData:GetFloat("TimeStep")
	
	local mousepos
	if input.mouseVisible then
		mousepos=input:GetMousePosition()
	else
		mousepos=ui:GetCursorPosition()
	end
	
	if input:GetMouseButtonDown(MOUSEB_LEFT) and ui:GetElementAt(mousepos.x, mousepos.y)==nil then
		local ground
		if projecttozero==false then ground=cam:PickGround(mousepos.x, mousepos.y)
		else ground=cam:GetScreenGround(mousepos.x, mousepos.y)
		end
		if ground~=nil then
			local gx,gz=ground.x,ground.z
			--local gx,gz=cam:GetMouseGround()
			--print("Mouse ground: "..gx..","..gz)
			--if blendbrush==false then applyHeightBrush(gx,gz,48,0.5,2,timeStep)
			--else applyBlendBrush(gx,gz,blendlayer,48,2,timeStep)
			--end
			--tbrush:execute(gx,gz,timeStep)
			--editbrush:Execute(gx,gz,timeStep)
			
		end
	end
	
	if input:GetKeyPress(KEY_S) then
		hmap:SavePNG("terrain.png")
	end
	
	if input:GetKeyPress(KEY_D) then
		blend:SavePNG("blend.png")
	end
	
	if input:GetKeyPress(KEY_A) then
		local img=Image(context)
		graphics:TakeScreenShot(img)
		img:SavePNG("screen.png")
	end
	
	if input:GetKeyPress(KEY_I) then
		doIsland()
	end
	
	--if input:GetKeyPress(KEY_R) then blendbrush=false elseif input:GetKeyPress(KEY_T) then blendbrush=true end
	--if input:GetKeyPress(KEY_Q) then blendlayer=0 elseif input:GetKeyPress(KEY_W) then blendlayer=1 elseif input:GetKeyPress(KEY_E) then blendlayer=2 end
	
	--cam.offset=terrain:GetHeight(cameraNode.position)
end
