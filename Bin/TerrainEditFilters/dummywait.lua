-- Dummy wait filter

return
{
	name="Dummy wait filter",
	description="Just waits for a few seconds",
	options=
	{
		{name="Seconds", type="value", value=15},
	},
	
	execute=function(self)
		local starttime=os.clock()
		while os.clock()<starttime+self.options[1].value do
			-- Busy wait
		end
	end
}