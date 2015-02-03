-- Terrain editing prototype
-- Water example.
-- This sample demonstrates:
--     - Creating a large plane to represent a water body for rendering
--     - Setting up a second camera to render reflections on the water surface

require "LuaScripts/Utilities/Sample"
require "LuaScripts/thirdpersoncamera"
require "LuaScripts/terraineditUI"
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
	hmap:SetSize(1025,1025,3)
    terrain.heightMap = hmap
    terrain.material = cache:GetResource("Material", "Materials/TerrainEdit.xml")
    -- The terrain consists of large triangles, which fits well for occlusion rendering, as a hill can occlude all
    -- terrain patches and other objects behind it
    terrain.occluder = true
	
	mask=Image(context)
	masktex=Texture2D:new(context)
	masktex:SetSize(0,0,0,TEXTURE_DYNAMIC)
	mask:SetSize(1024,1024,3)
	mask:Clear(Color(1,0,0))
	masktex:SetData(mask, false)
	terrain:GetMaterial():SetTexture(12,masktex)
	
	hmap:Clear(Color(0,0,0))
	terrain:SetSmoothing(false)
	print("Components: "..hmap:GetComponents())
	blendtex=Texture2D:new(context)
	blendtex:SetSize(0,0,0,TEXTURE_DYNAMIC)
	terrain:GetMaterial():SetTexture(0,blendtex)
	
	blend=Image(context)
	blend:SetSize(1024,1024,4)
	blend:Clear(Color(1,0,0,0))
	blendtex:SetData(blend, false)
	
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
		blend:SavePNG("TerrainEditorData/Textures/blend.png")
	end
	
	if input:GetKeyPress(KEY_K) then
		hmap=cache:GetResource("Image", "Textures/terrain.png")
		terrain:SetHeightMap(hmap)
	end
	
	if input:GetKeyPress(KEY_L) then
		blend=cache:GetResource("Image", "Textures/blend.png")
		blendtex:SetData(blend)
	end
	
	if input:GetKeyPress(KEY_A) then
		local img=Image(context)
		graphics:TakeScreenShot(img)
		local t=os.date("*t")
		local filename="screen-"..tostring(t.year).."-"..tostring(t.month).."-"..tostring(t.day).."-"..tostring(t.hour).."-"..tostring(t.min).."-"..tostring(t.sec)..".png"
		img:SavePNG(filename)
	end
	
end
