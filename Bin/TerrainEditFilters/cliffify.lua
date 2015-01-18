-- Test filter
return
{
	name="Cliffify",
	description="Set terrain to cliff (Blend layer 4) depending on slope of terrain at point.",
	
	options=
	{
		{name="Steepness threshold", type="value", value=0.7},
		{name="Fade", type="value", value=0.15},
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
				local world=NormalizedToWorld(nworld)
				local normal=terrain:GetNormal(world)
				
				local steep=math.abs(normal:DotProduct(Vector3(0,1,0)))
				--print(steep, normal.x, normal.y)
				local i=(steep-(thresh-halffade))/fade
				i=math.max(0,math.min(1,i))
				local col=blend:GetPixel(x,(bh-1)-y)
				local newcol=Color(0,0,0,1):Lerp(col, i)
				
					blend:SetPixel(x,(bh-1)-y,newcol)
			end
		end
		
		blendtex:SetData(blend)
	
		print("Filter executed with options: ")
		local c
		for _,c in ipairs(self.options) do
			print(c.name..": "..tostring(c.value))
		end
	end,
}