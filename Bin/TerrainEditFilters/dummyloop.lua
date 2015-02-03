return
{
	name="Dummy Loop",
	description="Create a mottled dirt/grass terrain.",
	options=
	{
		{name="Frequency", type="value", value=8},
		{name="Num Octaves", type="value", value=6},
		{name="Gain", type="value", value=0.8},
		{name="Seed", type="value", value=12345},
		{name="Use Mask?", type="flag", value=false},
	},
	
	execute=function(self)
		collectgarbage("restart")
		local hw,hh=blend:GetWidth(),blend:GetHeight()
		local x,y
		local c1=Color(1,0,0,0)
		local c2=Color(0,1,0,0)
		local c3=Color(0,0,0,0)
		
		print("S: "..collectgarbage("count"))
		local c=Color(1,1,1,1)
		print("E: "..collectgarbage("count"))
		
		print("Memory before loop: "..collectgarbage("count"))
		
		
		for x=0,1000000,1 do
			local col=Color(1,1,1,1)
		end
		print("Memory after loop: "..collectgarbage("count"))
		collectgarbage()
		collectgarbage()
		collectgarbage()
		collectgarbage()
		collectgarbage()
		collectgarbage()
		print("Memory after collectgarbage call: "..collectgarbage("count"))
	end,
}