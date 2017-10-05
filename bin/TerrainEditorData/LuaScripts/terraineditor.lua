-- Terrain editing prototype
-- Water example.
-- This sample demonstrates:
--     - Creating a large plane to represent a water body for rendering
--     - Setting up a second camera to render reflections on the water surface

require "LuaScripts/Utilities/Sample"
require "LuaScripts/thirdpersoncamera"
require "LuaScripts/terraineditUIoriginal"
require "LuaScripts/ui"
require "LuaScripts/buildcomposite"
require "LuaScripts/filterui"
require "LuaScripts/saveloadui"
require "LuaScripts/terrainselectui"
require "LuaScripts/nodegraphui"

require 'LuaScripts/Class'

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

--TerrainState=
--{
--}

TerrainState=TerrainEdit()


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

function Stop()
	
end

function CreateScene()
    scene_ = Scene()
	CreateCursor()
	
	local buf=VectorBuffer()
	buf:WriteFloat(1.4)
	buf:WriteFloat(2.3)
	
	local ary=Variant()
	ary:Set(buf)

    -- Create octree, use default volume (-1000, -1000, -1000) to (1000, 1000, 1000)
    scene_:CreateComponent("Octree")

    -- Create a Zone component for ambient lighting & fog control
    local zoneNode = scene_:CreateChild("Zone")
    local zone = zoneNode:CreateComponent("Zone")
    zone.boundingBox = BoundingBox(-1000.0, 1000.0)
    zone.ambientColor = Color(0.5, 0.5, 0.7)
    zone.fogColor = Color(0.7,0.8,0.9)
    zone.fogStart = 800.0
    zone.fogEnd = 875.0

    -- Create a directional light to the world. Enable cascaded shadows on it
    local lightNode = scene_:CreateChild("DirectionalLight")
    lightNode.direction = Vector3(0.8, -1.0, 1.0)
    local light = lightNode:CreateComponent("Light")
    light.lightType = LIGHT_DIRECTIONAL
    light.castShadows = true
    --light.shadowBias = BiasParameters(0.00025, 0.5)
    --light.shadowCascade = CascadeParameters(10.0, 50.0, 200.0, 0.0, 0.8)
    light.specularIntensity = 0.01;
    light.color = Color(1.2,1.2,1.2);
	--light.shadowBias = BiasParameters(0,0,0.015)
	
	--[[lightNode = scene_:CreateChild("DirectionalLight")
    lightNode.direction = Vector3(-1.2, -1.0, -1.6)
    local light = lightNode:CreateComponent("Light")
    light.lightType = LIGHT_DIRECTIONAL
    light.castShadows = true
    light.shadowBias = BiasParameters(0.00025, 0.5)
    light.shadowCascade = CascadeParameters(10.0, 50.0, 200.0, 0.0, 0.8)
    light.specularIntensity = 0.01;
    light.color = Color(0.13,0.14,0.15);]]

    local skyNode = scene_:CreateChild("Sky")
    skyNode:SetScale(500.0) -- The scale actually does not matter
    local skybox = skyNode:CreateComponent("Skybox")
    skybox.model = cache:GetResource("Model", "Models/Box.mdl")
    skybox.material = cache:GetResource("Material", "Materials/Skybox.xml")

    
	
	terrainui=scene_:CreateScriptObject("TerrainEditUI")
	
	terrainui:NewTerrain(1025,1025,2048,2048,true,false,true)
	terrainui:BuildUI()
	filterui=scene_:CreateScriptObject("FilterUI")
	saveloadui=scene_:CreateScriptObject("SaveLoadUI")
	--terrainselectui=scene_:CreateScriptObject("TerrainSelectUI")
	
   
    -- Create the camera. Set far clip to match the fog. Note: now we actually create the camera node outside
    -- the scene, because we want it to be unaffected by scene load / save
    cameraNode=scene_:CreateChild("Camera")
	cam=cameraNode:CreateScriptObject("ThirdPersonCamera")
	cam.clipcamera=false
	cam.allowspin=true
	cam.allowzoom=true
	cam.allowpitch=true
	cam.maxfollow=300
	cam.follow=100
	cam.clipdist=875
	cam:Finalize()
	
	--local lt=cameraNode:CreateComponent("Light")

	projecttozero=true
	graphics.flushGPU=true
	
	function distortKernel(detail, frequency, seed)
		local k=CKernel()
		local eb=CExpressionBuilder(k)
		
		eb:setRandomSeed(seed)
		
		local gradientLayer="clamp(rotateDomain(scale(gradientBasis(3,rand), 2^n),rand01,rand01,0,rand01*3),-1,1)"
		local fBmcombine="prev+(1/(2^n))*layer"
		local fractal=fractalBuilder(eb,k,detail,gradientLayer,fBmcombine)
		local freq=k:constant(frequency)
		
		k:scaleDomain(fractal, freq)
		return k
	end

	--[[xdistort=CArray2Dd(blend1:GetWidth(), blend1:GetHeight())
	local xdk=distortKernel(6, 64, 1234)
	map2D(SEAMLESS_NONE, xdistort, xdk, SMappingRanges(0,1,0,1,0,1), 0, xdk:lastIndex())
	xdistort:scaleToRange(-1,1)

	ydistort=CArray2Dd(blend1:GetWidth(), blend1:GetHeight())
	local ydk=distortKernel(6, 64, 1234)
	map2D(SEAMLESS_NONE, ydistort, ydk, SMappingRanges(0,1,0,1,0,1), 0, ydk:lastIndex())
	ydistort:scaleToRange(0,1)]]
end

function CreateInstructions()
    
end

function SubscribeToEvents()
    SubscribeToEvent("Update", "HandleUpdate")
end

function HandleUpdate(eventType, eventData)
    -- Take the frame time step, which is stored as a float
    local timeStep = eventData["TimeStep"]:GetFloat()
	
	
	if input:GetKeyPress(KEY_A) then
		local img=Image(context)
		graphics:TakeScreenShot(img)
		local t=os.date("*t")
		local filename="screen-"..tostring(t.year).."-"..tostring(t.month).."-"..tostring(t.day).."-"..tostring(t.hour).."-"..tostring(t.min).."-"..tostring(t.sec)..".png"
		img:SavePNG(filename)
	end
	
end
