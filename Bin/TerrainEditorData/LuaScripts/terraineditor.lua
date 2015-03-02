-- Terrain editing prototype
-- Water example.
-- This sample demonstrates:
--     - Creating a large plane to represent a water body for rendering
--     - Setting up a second camera to render reflections on the water surface

require "LuaScripts/Utilities/Sample"
require "LuaScripts/thirdpersoncamera"
require "LuaScripts/terraineditUIoriginal"
require "LuaScripts/ui"

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
	local i,j
	for i,j in pairs(tolua) do print(i,j) end
	
end

function CreateScene()
    scene_ = Scene()
	CreateCursor()

    -- Create octree, use default volume (-1000, -1000, -1000) to (1000, 1000, 1000)
    scene_:CreateComponent("Octree")

    -- Create a Zone component for ambient lighting & fog control
    local zoneNode = scene_:CreateChild("Zone")
    local zone = zoneNode:CreateComponent("Zone")
    zone.boundingBox = BoundingBox(-1000.0, 1000.0)
    zone.ambientColor = Color(0.03, 0.03, 0.04)
    zone.fogColor = Color(1,1,1)
    zone.fogStart = 300.0
    zone.fogEnd = 325.0

    -- Create a directional light to the world. Enable cascaded shadows on it
    local lightNode = scene_:CreateChild("DirectionalLight")
    lightNode.direction = Vector3(0.8, -1.0, 1.0)
    local light = lightNode:CreateComponent("Light")
    light.lightType = LIGHT_DIRECTIONAL
    light.castShadows = true
    light.shadowBias = BiasParameters(0.00025, 0.5)
    light.shadowCascade = CascadeParameters(10.0, 50.0, 200.0, 0.0, 0.8)
    light.specularIntensity = 0.2;
    -- Apply slightly overbright lighting to match the skybox
    light.color = Color(1,0.9,0.8);
	
	lightNode = scene_:CreateChild("DirectionalLight")
    lightNode.direction = Vector3(-1.2, -1.0, -1.6)
    local light = lightNode:CreateComponent("Light")
    light.lightType = LIGHT_DIRECTIONAL
    light.castShadows = true
    light.shadowBias = BiasParameters(0.00025, 0.5)
    light.shadowCascade = CascadeParameters(10.0, 50.0, 200.0, 0.0, 0.8)
    light.specularIntensity = 0.2;
    -- Apply slightly overbright lighting to match the skybox
    light.color = Color(0.4,0.45,0.5);

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
    terrain.spacing = Vector3(0.20, 0.1, 0.20) -- Spacing between vertices and vertical resolution of the height map
    terrain.smoothing = true
	hmap=Image:new(context)
	hmap:SetSize(2049,2049,3)
	hmap:Clear(Color(0.1,0,0,0))
    terrain.heightMap = hmap
    terrain.material = cache:GetResource("Material", "Materials/TerrainEdit.xml")
	--terrain.material = cache:GetResource("Material", "Materials/TerrainEdit8.xml")
	--terrain.material = cache:GetResource("Material", "Materials/TerrainColorDetailEdit8.xml")
	--terrain.material = cache:GetResource("Material", "Materials/TerrainBlend4NormalEdit.xml")
	
    -- The terrain consists of large triangles, which fits well for occlusion rendering, as a hill can occlude all
    -- terrain patches and other objects behind it
    terrain.occluder = true
	
	mask=Image(context)
	masktex=Texture2D:new(context)
	masktex:SetSize(0,0,0,TEXTURE_DYNAMIC)
	mask:SetSize(2048,2048,3)
	mask:Clear(Color(1,0,0))
	masktex:SetData(mask, false)
	terrain:GetMaterial():SetTexture(12,masktex)
	
	hmap:Clear(Color(0,0,0))
	terrain:SetSmoothing(false)
	print("Components: "..hmap:GetComponents())
	blendtex1=Texture2D:new(context)
	blendtex1:SetSize(0,0,0,TEXTURE_DYNAMIC)
	terrain:GetMaterial():SetTexture(0,blendtex1)
	
	--blendtex2=Texture2D:new(context)
	--blendtex2:SetSize(0,0,0,TEXTURE_DYNAMIC)
	--terrain:GetMaterial():SetTexture(1,blendtex2)
	
	blend1=Image(context)
	blend1:SetSize(2048,2048,4)
	blend1:Clear(Color(1,0,0,0))
	blendtex1:SetData(blend1, false)
	
	--blend2=Image(context)
	--blend2:SetSize(1024,1024,4)
	--blend2:Clear(Color(0,0,0,0))
	--blendtex2:SetData(blend2, false)
	
	-- Color detailing
	--colortex=Texture2D:new(context)
	--colortex:SetSize(0,0,0,TEXTURE_DYNAMIC)
	--terrain:GetMaterial():SetTexture(4,colortex)
	--color=Image(context)
	--color:SetSize(1024,1024,3)
	--color:Clear(Color(0.5,0.5,0.5))
	--colortex:SetData(color, false)

	
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
	
	--local lt=cameraNode:CreateComponent("Light")

	projecttozero=true
end

function CreateInstructions()
    
end

function SubscribeToEvents()
    -- Subscribe HandleUpdate() function for processing update events
    SubscribeToEvent("Update", "HandleUpdate")
end

function HandleUpdate(eventType, eventData)
    -- Take the frame time step, which is stored as a float
    local timeStep = eventData:GetFloat("TimeStep")
	
	
	if input:GetKeyPress(KEY_S) then
		hmap:SavePNG("TerrainEditorData/Textures/terrain.png")
	end
	
	if input:GetKeyPress(KEY_D) then
		blend1:SavePNG("TerrainEditorData/Textures/blend.png")
	end
	
	if input:GetKeyPress(KEY_K) then
		hmap=cache:GetResource("Image", "Textures/terrain.png")
		terrain:SetHeightMap(hmap)
	end
	
	if input:GetKeyPress(KEY_L) then
		blend1=cache:GetResource("Image", "Textures/blend.png")
		blendtex1:SetData(blend1)
	end
	
	if input:GetKeyPress(KEY_A) then
		local img=Image(context)
		graphics:TakeScreenShot(img)
		local t=os.date("*t")
		local filename="screen-"..tostring(t.year).."-"..tostring(t.month).."-"..tostring(t.day).."-"..tostring(t.hour).."-"..tostring(t.min).."-"..tostring(t.sec)..".png"
		img:SavePNG(filename)
	end
	
end
