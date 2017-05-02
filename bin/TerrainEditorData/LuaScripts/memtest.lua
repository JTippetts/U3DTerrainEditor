

require "LuaScripts/Utilities/Sample"



function Start()
    SampleStart()
	CreateScene()
    SubscribeToEvents()
	
end

function CreateScene()
    text=Text:new(context)
	ui.root:AddChild(text)
	text.position=IntVector2(0,200)
	text.font=cache:GetResource("Font", "Fonts/BlueHighway.ttf")
	
	local instructions=Text:new(context)
	ui.root:AddChild(instructions)
	instructions.position=IntVector2(400,200)
	instructions.font=cache:GetResource("Font", "Fonts/BlueHighway.ttf")
	instructions.text="Press 'd' to execute a loop containing 10000000 creations of a local Color object."
end


function SubscribeToEvents()
    -- Subscribe HandleUpdate() function for processing update events
    SubscribeToEvent("Update", "HandleUpdate")
end

function DoThing()
	local c
	for c=1,10000000,1 do
		local c=Color(1,1,1,1)
	end
end

function HandleUpdate(eventType, eventData)
    local memused=collectgarbage("count")
	text.text="Memory used: "..memused
	
	if input:GetKeyPress(KEY_D) then
		DoThing()
	end
	
	if input:GetKeyPress(KEY_A) then
		local img=Image(context)
		graphics:TakeScreenShot(img)
		local t=os.date("*t")
		local filename="screen-"..tostring(t.year).."-"..tostring(t.month).."-"..tostring(t.day).."-"..tostring(t.hour).."-"..tostring(t.min).."-"..tostring(t.sec)..".png"
		img:SavePNG(filename)
	end
	
	collectgarbage() -- Force explicit collection cycle
end
