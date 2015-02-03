-- Test filter
return
{
	name="Cliffify",
	description="Set terrain to cliff (Blend layer 4) depending on slope of terrain at point.",
	
	options=
	{
		{name="Steepness threshold", type="value", value=0.7},
		{name="Fade", type="value", value=0.15},
		{name="Cliff Layer", type="value", value=3},
		{name="Use Mask?", type="flag", value=false},
		{name="Invert Mask?", type="flag", value=false},
	},
	
	execute=function(self)
		local bw,bh=blend:GetWidth(), blend:GetHeight()
		
		local halffade=self.options[2].value*0.5
		local fade=self.options[2].value
		local thresh=self.options[1].value
		
		local x,y
		for x=0,bw-1,1 do
			for y=0,bh-1,1 do
				local nworld=Vector2(x/bw, y/bh)
				local world=NormalizedToWorld(hmap,terrain,nworld)
				local normal=terrain:GetNormal(world)
				
				local steep=math.abs(normal:DotProduct(Vector3(0,1,0)))
				--print(steep, normal.x, normal.y)
				local i=(steep-(thresh-halffade))/fade
				i=math.max(0,math.min(1,i))
				i=1-i
				
				if self.options[4].value==true then
					local maskval=mask:GetPixelBilinear(nworld.x,1-nworld.y).r
					if self.options[5].value==true then maskval=1-maskval end
					i=i*maskval
				end
				
				local col=blend:GetPixel(x,(bh-1)-y)
				local newcol
				if self.options[3].value==0 then
					newcol=col:Lerp(Color(1,0,0,0),i)
				elseif self.options[3].value==1 then
					newcol=col:Lerp(Color(0,1,0,0),i)
				elseif self.options[3].value==2 then
					newcol=col:Lerp(Color(0,0,1,0),i)
				else
					newcol=col:Lerp(Color(0,0,0,1),i)
				end
				blend:SetPixel(x,(bh-1)-y,newcol)
			end
			collectgarbage()
		end
		
		blendtex:SetData(blend,false)
	
		print("Filter executed with options: ")
		local c
		for _,c in ipairs(self.options) do
			print(c.name..": "..tostring(c.value))
		end
	end,
}