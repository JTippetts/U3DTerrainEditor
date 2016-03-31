-- ANL Expression Kernel filter
-- Generate a terrain from an expression

function fractalBuilder(eb, k, numoctaves, basisexpr, combinexpr)
	local c
	local ret
	eb:storeVar("prev", k:zero())
	for c=0,numoctaves-1,1 do
		eb:storeVar("n", k:constant(c))
		eb:evalAndStoreVar("layer", basisexpr)
		ret=eb:evalAndStoreVar("prev", combinexpr)
	end
	return ret
end

noisekernels=
{
	simplefBm=function(ops)
		local k=CKernel()
		local eb=CExpressionBuilder(k)
		
		local gradientLayer="clamp(rotateDomain(scale(gradientBasis(3,rand), 2^n),rand01,rand01,0,rand01*3),-1,1)"
		local fBmcombine="prev+(1/(2^n))*layer"
		local fractal=fractalBuilder(eb,k,10,gradientLayer,fBmcombine)
		local freq=k:constant(ops["Frequency"])
		eb:storeVar("freq", freq)
		fractal=eb:eval("scale(prev,freq)")
		
		return k
		
	end,
	
	ridged=function(ops)
		local k=CKernel()
		local eb=CExpressionBuilder(k)
		
		local gradientLayer="clamp(rotateDomain(scale(gradientBasis(3,rand), 2^n),rand01,rand01,0,rand01*3),-1,1)"
		local ridgedcombine="prev+(1-abs(layer)*cos(prev))*(1/(2^n))"
		local fractal=fractalBuilder(eb,k,10,gradientLayer,ridgedcombine)
		local freq=k:constant(ops["Frequency"])
		eb:storeVar("freq", freq)
		fractal=eb:eval("scale(prev,freq)")
		
		return k
		
	end,
	
}

return
{
	name="Noise Kernel Terrain",
	description="Generate a terrain from a function call.\n",
	options=
	{
		{name="Noise function", type="list", value="simplefBm", list={"simplefBm","ridged"}},
		{name="Min scale", type="value", value=0},
		{name="Max scale", type="value", value=1},
		{name="Use Mask?", type="flag", value=false},
		{name="Invert Mask?", type="flag", value=false},
		{name="Frequency", type="value", value=16},
	},
	
	execute=function(self)
		local ops=GetOptions(self.options)
		
		local k=noisekernels[ops["Noise function"]](ops)
		if k then
			local hw,hh=hmap:GetWidth(),hmap:GetHeight()
			local buffer=RasterBuffer(hw,hh)
			RenderANLKernelToBuffer(buffer,k,ops["Min scale"],ops["Max scale"])
			SetHeightFromRasterBuffer(hmap,buffer,mask,ops["Use Mask?"], ops["Invert Mask?"])
		
			terrain:ApplyHeightMap()
		end
	end
}
