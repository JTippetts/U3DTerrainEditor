-- Third Person Camera
--

scrollspeed=32
scrollthreshold=64
zoomspeed=1000

function TopLevelNodeFromDrawable(drawable, scene)
	local n=drawable:GetNode()
	if not n then return nil end
	while n.parent~=scene do if n.parent==nil then return nil end n=n.parent end
	return n
end

ThirdPersonCamera=ScriptObject()

function ThirdPersonCamera:Start()
	-- Override any of these parameters when instancing the component in order to change the characteristics
	-- of the view.
	
	self.cellsize=128           -- Orthographic on-screen size of 1 unit 
	self.pitch=30            -- 30 degrees for standard 2:1 tile ratio
	self.yaw=45            -- 45 degrees for standard axonometric projections
	self.follow=10              -- Target zoom distance
	self.minfollow=1            -- Closest zoom distance for perspective modes
	self.maxfollow=20           -- Furthest zoom distance for perspective modes
	self.clipdist=60            -- Far clip distance
	self.allowspin=true         -- Camera yaw angle can be adjusted via MOUSEB_MIDDLE + Mouse move in X
	self.allowpitch=true        -- Camera pitch can be adjusted via MOUSEB_MIDDLE + Mouse move in y
	self.allowzoom=true         -- Camera can be zoomed via Mouse wheel
	self.orthographic=false     -- Orthographic projection
	self.clipcamera=true        -- Clip camera to solid objects
	
	self.curfollow=self.follow  -- Current zoom distance (internal use only)
	self.followvel=0            -- Zoom movement velocity (internal use only)
	
	self.lastmx=0
	self.lastmz=0
	
	self.offset=2
	self.tracksurface=true
end

function ThirdPersonCamera:Finalize()
	self.curfollow=self.follow
	
	-- Set up node hierarchy
	-- root level node is used for position and yaw control
	-- shakenode is used for applying camera shake translations
	-- anglenode is used for pitch control
	-- cameranode holds the camera and is used for zoom distance control as well
	
	self.anglenode=self.node:CreateChild("AngleNode", LOCAL)
	self.cameranode=self.anglenode:CreateChild("CameraNode", LOCAL)
	self.camera=self.cameranode:CreateComponent("Camera")
	
	-- If orthographic, use the cellsize to calculate the orthographic size
	
	if self.orthographic then
		self.camera:SetOrthographic(true)
		local w,h=graphics:GetWidth(), graphics:GetHeight()
		self.camera:SetOrthoSize(Vector2(w/(self.cellsize*math.sqrt(2)), h/(self.cellsize*math.sqrt(2))))
	end
	
	self.viewport=Viewport:new(self.node:GetScene(), self.camera)
    renderer:SetViewport(0, self.viewport)
	
	-- Apply initial pitch/yaw/zoom
	
	self.node:SetRotation(Quaternion(self.yaw, Vector3(0,1,0)))
	self.cameranode.position=Vector3(0,0,-self.follow)
	self.anglenode:SetRotation(Quaternion(self.pitch, Vector3(1,0,0)))
	self.node.position=Vector3(0,0,0)
	
	self:SubscribeToEvent("Update", "ThirdPersonCamera:HandleUpdate")
	self:SubscribeToEvent("RequestMouseGround", "ThirdPersonCamera:HandleRequestMouseGround")
	self:SubscribeToEvent("RequestMouseRay", "ThirdPersonCamera:HandleRequestMouseRay")
	self:SubscribeToEvent("RequestCameraRotation", "ThirdPersonCamera:HandleRequestCameraRotation")
	
	self.camera:SetFarClip(self.clipdist)
end

function ThirdPersonCamera:GetMouseRay()
	-- Construct a ray based on current mouse coordinates.
	
	local mousepos
	if input.mouseVisible then
		mousepos=input:GetMousePosition()
	else
		mousepos=ui:GetCursorPosition()
	end
	
	return self.camera:GetScreenRay(mousepos.x/graphics.width, mousepos.y/graphics.height)
end

function ThirdPersonCamera:GetScreenRay(mousex, mousey)
	return self.camera:GetScreenRay(mousex/graphics.width, mousey/graphics.height)
end

function ThirdPersonCamera:GetMouseGround()
	-- Calculate the intersection of the current mouse coordinates with the ground plane
	
	local ray=self:GetMouseRay()
	
	local pos=self.node:GetWorldPosition()
	local x,y,z=pos.x,pos.y,pos.z
	local hitdist=ray:HitDistance(Plane(Vector3(0,1,0), Vector3(0,0,0)))
	local dx=(ray.origin.x+ray.direction.x*hitdist)
	local dz=(ray.origin.z+ray.direction.z*hitdist)
	return dx,dz
end

function ThirdPersonCamera:GetScreenGround(mousex, mousey)
	local ray=self:GetScreenRay(mousex, mousey)
	
	local hitdist=ray:HitDistance(Plane(Vector3(0,1,0), Vector3(0,0,0)))
	if hitdist==M_INFINITY then return nil end
	local dx=(ray.origin.x+ray.direction.x*hitdist)
	local dz=(ray.origin.z+ray.direction.z*hitdist)
	--print("Hit dist: "..hitdist)
	return Vector3(dx,0,dz)
end

function ThirdPersonCamera:PickGround(mousex, mousey, maxDistance)
	if not maxDistance then maxDistance=1000.0 end
	
	
	local hitPos = nil
    local hitDrawable = nil
	if (ui.cursor and not ui.cursor.visible and input.mouseVisible==false) then
		return nil
	end
	
	local ray=self:GetScreenRay(mousex, mousey)
   
    local octree = scene_:GetComponent("Octree")
   
	local resultvec=octree:Raycast(ray, RAY_TRIANGLE, maxDistance, DRAWABLE_GEOMETRY)
	if #resultvec==0 then return nil end
	
	local hitPos=0
	
	local i
	for i=1,#resultvec,1 do
		if resultvec[i].distance >= 0 then
			hitPos = ray.origin + ray.direction * resultvec[i].distance
			return hitPos
		end
	end
	
	return nil
end

function ThirdPersonCamera:CameraPick(ray, followdist)
	-- Cast a ray from camera target toward camera and determine the nearest clip position.
	-- Only objects marked by setting node user var solid=true are considered.
	
	local scene=self.node:GetScene()
	local octree = scene:GetComponent("Octree")
    
	local resultvec=octree:Raycast(ray, RAY_TRIANGLE, followdist, DRAWABLE_GEOMETRY)
	if #resultvec==0 then return followdist end
	
	local i
	for i=1,#resultvec,1 do
		--local node=TopLevelNodeFromDrawable(resultvec[i].drawable, scene)
		if --[[node:GetVars():GetBool("solid")==true and]] resultvec[i].distance>=0 then
			return math.min(math.max(0,resultvec[i].distance-1),followdist)
		end
	end
	
	return followdist
end

function ThirdPersonCamera:HandleRequestCameraRotation(eventType, eventData)
	-- Request to provide the camera pitch and yaw, for controllers that use it such as the WASD controllers
	
	eventData:SetFloat("spin", self.yaw)
	eventData:SetFloat("pitch", self.pitch)
end

function ThirdPersonCamera:SpringFollow(dt)
	-- Spring function to smooth camera zoom action
	
	local df=self.follow-self.curfollow
	local af=9*df-6*self.followvel
	self.followvel=self.followvel+dt*af
	self.curfollow=self.curfollow+dt*self.followvel
end

function ThirdPersonCamera:HandleUpdate(eventType, eventData)
	local dt=eventData["TimeStep"]:GetFloat()
	
	if self.allowzoom and not ui:GetElementAt(ui.cursor:GetPosition()) then
		-- Modify follow (zoom) in response to wheel motion
		-- This modifies the target zoom, or the desired zoom level, not the actual zoom.
		
		local wheel=input:GetMouseMoveWheel()
		self.follow=self.follow-wheel*dt*zoomspeed
		if self.follow<self.minfollow then self.follow=self.minfollow end
		if self.follow>self.maxfollow then self.follow=self.maxfollow end
	end
	
	if input:GetMouseButtonDown(MOUSEB_MIDDLE) and (self.allowspin or self.allowpitch) then
		-- Hide the cursor when altering the camera angles
		ui.cursor.visible=false
		
		if self.allowpitch then
			-- Adjust camera pitch angle
			
			local mmovey=input:GetMouseMoveY()/graphics:GetHeight()
			self.pitch=self.pitch+mmovey*600

			if self.pitch<-89 then self.pitch=-89 end
			if self.pitch>89 then self.pitch=89 end
		end
		
		if self.allowspin then
			-- Adjust camera yaw angle
			
			local mmovex=input:GetMouseMoveX()/graphics:GetWidth()
			self.yaw=self.yaw+mmovex*800
			while self.yaw<0 do self.yaw=self.yaw+360 end
			while self.yaw>=360 do self.yaw=self.yaw-360 end
		end
		
	else
		ui.cursor.visible=true
	end

	
	local mousepos
	if input.mouseVisible then
		mousepos=input:GetMousePosition()
	else
		mousepos=ui:GetCursorPosition()
	end
	
	local trans=Vector3(0,0,0)
	
	--[[
	if mousepos.x <= scrollthreshold then
		local amt=(1.0-mousepos.x/scrollthreshold)*dt*scrollspeed
		local right=self.node:GetRight()
		right.x=right.x*amt
		right.y=0
		right.z=right.z*amt
		trans.x=trans.x-right.x
		trans.z=trans.z-right.z
		
	elseif mousepos.x >= graphics.width-scrollthreshold then
		local amt=((mousepos.x-(graphics.width-scrollthreshold))/scrollthreshold)*dt*scrollspeed
		local right=self.node:GetRight()
		right.x=right.x*amt
		right.y=0
		right.z=right.z*amt
		trans.x=trans.x+right.x
		trans.z=trans.z+right.z
	end
	
	if mousepos.y <= scrollthreshold then
		local amt=(1.0-mousepos.y/scrollthreshold)*dt*scrollspeed
		local right=self.node:GetDirection()
		right.x=right.x*amt
		right.y=0
		right.z=right.z*amt
		trans.x=trans.x+right.x
		trans.z=trans.z+right.z
	elseif mousepos.y >= graphics.height-scrollthreshold then
		local amt=((mousepos.y-(graphics.height-scrollthreshold))/scrollthreshold)*dt*scrollspeed
		local right=self.node:GetDirection()
		right.x=right.x*amt
		right.y=0
		right.z=right.z*amt
		trans.x=trans.x-right.x
		trans.z=trans.z-right.z

	end
	]]
	if input:GetMouseButtonPress(MOUSEB_RIGHT) then
		self.lastmx, self.lastmz=mousepos.x,mousepos.y
	end
	
	if input:GetMouseButtonDown(MOUSEB_RIGHT) then
		trans=Vector3(0,0,0)
		local oldx,oldy,newx,newy=0,0,0,0
		local oldground=self:GetScreenGround(self.lastmx, self.lastmz)
		if oldground then
			oldx,oldy=oldground.x, oldground.z
			local newground=self:GetScreenGround(mousepos.x, mousepos.y)
			if newground then
				newx,newy=newground.x, newground.z
		
				trans.x=trans.x+(oldx-newx)
				trans.z=trans.z+(oldy-newy)
		
				self.lastmx=mousepos.x
				self.lastmz=mousepos.y
			end
		end
	else
		local quat=Quaternion(self.yaw,Vector3(0,1,0))
		local speed=10.0
		if input:GetKeyDown(KEY_W) then
			trans.z=trans.z+1.0
		end
		
		if input:GetKeyDown(KEY_S) then
			trans.z=trans.z-1
		end
		
		if input:GetKeyDown(KEY_A) then
			trans.x=trans.x-1
		end
		
		if input:GetKeyDown(KEY_D) then
			trans.x=trans.x+1
		end
		trans=quat*trans*dt*speed
	end
	
	local np=Vector3(self.node.position.x+trans.x,0,self.node.position.z+trans.z)
	local nrm=TerrainState:WorldToNormalized(np)
	nrm.x = math.max(0, math.min(1, nrm.x))
	nrm.y = math.max(0, math.min(1, nrm.y))
	np=TerrainState:NormalizedToWorld(nrm)
	if self.tracksurface then
		np.y=TerrainState:GetTerrain():GetHeight(np) + 1
	else
		np.y=1
	end
	
	self.node.position=np
	
		-- Apply the spring function to the zoom (follow) level.
	-- This provides smooth camera movement toward the desired zoom level.
	
	self:SpringFollow(dt)	
	if self.clipcamera then
		-- After calculating the camera zoom position, test a ray from view center for obstruction and
		-- clip camera position to nearest obstruction distance.
		--print("clipping")
		local ray=self.camera:GetScreenRay(0.5,0.5)
		local revray=Ray(self.node.position, ray.direction*Vector3(-1,-1,-1))
		
		self.curfollow=self:CameraPick(revray, self.curfollow)
	end	
	
	
	-- Set camera pitch, zoom and yaw.
	self.node:SetRotation(Quaternion(self.yaw, Vector3(0,1,0)))
	self.cameranode.position=Vector3(0,0,-self.curfollow)
	self.anglenode:SetRotation(Quaternion(self.pitch, Vector3(1,0,0)))
	
	
end

function ThirdPersonCamera:HandleShakeCamera(eventType, eventData)
	-- Apply some shake factors
	-- Shake is applied via three values
	
	-- magnitude determines the strength of the shake, or maximum deflection, from great big swooping shakes
	-- to small vibrations.
	
	-- speed determines the velocity of the shake vibration
	
	-- damping determines how quickly the shaking fades out.
	
	self.shakemagnitude=eventData:GetFloat("magnitude");
    self.shakespeed=eventData:GetFloat("speed");
    self.shakedamping=eventData:GetFloat("damping");
end

function ThirdPersonCamera:HandleRequestMouseGround(eventType, eventData)
	local dx,dz=self:GetMouseGround()
	
	eventData:SetVector3("ground", Vector3(dx,0,dz))
end

function ThirdPersonCamera:HandleRequestMouseRay(eventType, eventData)
	local ray=self:GetMouseRay()
	eventData:SetVector3("origin", ray.origin)
	eventData:SetVector3("direction", ray.direction)
end

function ThirdPersonCamera:HandleSetCamera(eventType, eventData)
	-- Allow for run-time adjustment of camera parameters.
	
	self.orthographic=eventData("orthographic")
	if self.orthographic then
		self.camera:SetOrthographic(true)
		local w,h=graphics:GetWidth(), graphics:GetHeight()
		self.cellsize=eventData:GetFloat("cellsize")
		self.camera:SetOrthoSize(Vector2(w/(self.cellsize*math.sqrt(2)), h/(self.cellsize*math.sqrt(2))))
	end
	
	self.yaw=eventData:GetFloat("yaw")
	self.pitch=eventData:GetFloat("pitchangle")
	self.allowspin=eventData:GetBool("allowspin")
	self.allowzoom=eventData:GetBool("allowzoom")
	if self.allowzoom then
		self.minfollow=eventData:GetFloat("minfollow")
		self.maxfollow=eventData:GetFloat("maxfollow")
	end
	self.follow=eventData:GetFloat("follow")
	self.follow=math.max(self.minfollow, math.min(self.maxfollow, self.follow))
end





-- CameraControl
-- Component for controlling the position of the camera.
-- Place this component on the main actor/avatar object in your scene to allow mirroring
-- that object's world translation to the camera root node.

CameraControl=ScriptObject()

function CameraControl:Start()
	self.offset=0.5
	self.vm=VariantMap()
end

function CameraControl:TransformChanged()
	local x,y,z=self.node.position
	self.vm:SetFloat("x", x)
	self.vm:SetFloat("y", y+self.offset)
	self.vm:SetFloat("z", z)
	self.node:SendEvent("SetCameraPosition", self.vm)
end