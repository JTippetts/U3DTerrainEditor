-- Test filter
return
{
	name="Cliffify",
	description="Set terrain to cliff (Blend layer 4) depending on slope of terrain at point.",
	
	options=
	{
		{name="Steepness threshold", type="value", value=0.7},
		{name="Fade", type="value", value=0.4},
		{name="Cliff Layer", type="value", value=1},
		{name="Use Mask?", type="flag", value=false},
		{name="Invert Mask?", type="flag", value=false},
	},
	
	execute=function(self)
		local ops=GetOptions(self.options)
		local bw,bh=blend1:GetWidth(), blend1:GetHeight()
		
		local halffade=ops["Fade"]*0.5
		local fade=ops["Fade"]
		local thresh=ops["Steepness threshold"]
		local layer=ops["Cliff Layer"]
		local usemask=ops["Use Mask?"]
		local invertmask=ops["Invert Mask?"]
		
		local buffer=RasterBuffer(bw,bh)
		
		local x,y
		for x=0,bw-1,1 do
			for y=0,bh-1,1 do
				local nworld=Vector2(x/(bw-1), y/(bh-1))
				local world=NormalizedToWorld(hmap,terrain,nworld)
				local normal=terrain:GetNormal(world)
				
				local steep=math.abs(normal:DotProduct(Vector3(0,1,0)))
				local i=(steep-(thresh-halffade))/fade
				i=math.max(0,math.min(1,i))
				i=1-i
				
				buffer:set(x,(bh-1)-y,i)
			end
			collectgarbage()
		end
		
		BlendRasterizedBuffer8Max(blend1,blend2,buffer,layer,mask,usemask,invertmask)
		blendtex1:SetData(blend1,false)
		blendtex2:SetData(blend2,false)
	end,
}