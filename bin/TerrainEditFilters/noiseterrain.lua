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
		
		eb:setRandomSeed(ops["Random seed"])
		
		local gradientLayer="clamp(rotateDomain(scale(gradientBasis(3,rand), 2^n),rand01,rand01,0,rand01*3),-1,1)"
		local fBmcombine="prev+(1/(2^n))*layer"
		local fractal=fractalBuilder(eb,k,ops["Detail"],gradientLayer,fBmcombine)
		local freq=k:constant(ops["Frequency"])
		
		k:scaleDomain(fractal, freq)
		
		return k
	end,
	
	ridged=function(ops)
		local k=CKernel()
		local eb=CExpressionBuilder(k)
		
		eb:setRandomSeed(ops["Random seed"])
		
		local gradientLayer="clamp(rotateDomain(scale(gradientBasis(3,rand), 2^n),rand01,rand01,0,rand01*3),-1,1)"
		local ridgedcombine="prev+(1-abs(layer))*(1/(2^n))"
		local fractal=fractalBuilder(eb,k,ops["Detail"],gradientLayer,ridgedcombine)
		local freq=k:constant(ops["Frequency"])
		
		k:scaleDomain(fractal, freq)
		
		return k
	end,
	
}

noisekernelsindex=
{

}

local i,j
for i,j in pairs(noisekernels) do table.insert(noisekernelsindex, i) end

function bias(b, t)
    return math.pow(t, math.log(b)/math.log(0.5))
end

function gain(g, t)
    if(t<0.5) then return bias(1.0-g, 2.0*t)/2.0
    else return 1.0 - bias(1.0-g, 2.0 - 2.0*t)/2.0
    end
end

return
{
	name="Generate Noise Heightmap",
	description="Generate a terrain from a selection of noise functions.\n",
	options=
	{
		{name="Noise function", type="list", value="simplefbm", list=noisekernels},
		{name="Min scale", type="value", value=0},
		{name="Max scale", type="value", value=1},
		{name="Use Mask?", type="flag", value=false},
		{name="Invert Mask?", type="flag", value=false},
		{name="Frequency", type="value", value=16},
		{name="Detail", type="value", value=10},
		{name="Bias", type="value", value=0.5},
		{name="Gain", type="value", value=0.5},
		{name="Random seed", type="value", value=12345},
	},
	
	execute=function(self)
		local ops=GetOptions(self.options)
		
		local k=noisekernels[ops["Noise function"]](ops)
		if k then
			local hw,hh=TerrainState.hmap:GetWidth(),TerrainState.hmap:GetHeight()
			local buffer=CArray2Dd(hw,hh)
			
			map2D(SEAMLESS_NONE, buffer, k, SMappingRanges(0,1,0,1,0,1), 0, k:lastIndex())
			buffer:scaleToRange(ops["Min scale"], ops["Max scale"])
			
			
			local x,y
			for x=0,hw-1,1 do
				for y=0,hh-1,1 do
					buffer:set(x,y, bias(ops["Bias"], gain(ops["Gain"], buffer:get(x,y))))
				end
			end
			
			SetHeightFromRasterBuffer(TerrainState.hmap,buffer,mask,ops["Use Mask?"], ops["Invert Mask?"])
		
			TerrainState.terrain:ApplyHeightMap()
		end
	end
}
