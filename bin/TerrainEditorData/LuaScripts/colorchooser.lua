-- Color Chooser

hsv2rgb=function(h,s,v)
	local H,S,V=h,s,v
	local P,Q,T,fract
	
	if H>=360 then H=0 else H=H/60 end
	fract = H - math.floor(H)
	
	P = V*(1.0-S)
	Q = V*(1.0-S*fract)
	T = V*(1.0-S*(1.0-fract))
	
	
	if H>=0 and H<1 then return Color(V,T,P,1)
	elseif H>=1 and H<2 then return Color(Q,V,P,1)
	elseif H>=2 and H<3 then return Color(P,V,T,1)
	elseif H>=3 and H<4 then return Color(P,Q,V,1)
	elseif H>=4 and H<5 then return Color(T,P,V,1)
	elseif H>=5 and H<6 then return Color(V,P,Q,1)
	else return Color(0,0,0,1)
	end
end

function rgb2hsv(col)
	local fmax=math.max(math.max(col.r, col.g), col.b)
	local fmin=math.min(math.min(col.r, col.g), col.b)
	local fdelta=fmax-fmin
	local h,s,v
	
	if fdelta>0 then
		if fmax==col.r then h=60.0*(math.fmod(((col.g-col.b) / fdelta), 6.0))
		elseif fmax==col.g then h=60.0 * (((col.b-col.r) / fdelta) + 2)
		else h = 60.0 * (((col.r-col.g)/fdelta)+4)
		end
	
		if fmax>0 then
			s=fdelta/fmax
		else
			s=0.0
		end
		
		v=fmax
	else
		h=0
		s=0
		v=fmax
	end
	
	if h<0 then h=360+h end
	return h,s,v
			
end

ColorChooser=ScriptObject()

function ColorChooser:Start()
	self.panel=ui:LoadLayout(cache:GetResource("XMLFile", "UI/ColorChooser.xml"))
	ui.root:AddChild(self.panel)
	self.panel.visible=false
	
	self.value=self.panel:GetChild("Value", true)
	self.close=self.panel:GetChild("Close", true)
	self.cursor=self.panel:GetChild("Cursor", true)
	self.colorwheel=self.panel:GetChild("ColorWheel", true)
	self.swatch=self.panel:GetChild("Swatch", true)
	self.color=Color(1,1,1)
	self.swatch.color=self.color
end

function ColorChooser:SetColor(col)
	local h,s,v = rgb2hsv(col)
	
	self.value.value=math.floor((1-v)*127)
	local angle=h/360
	angle = angle*2.0-1.0
	angle=angle*3.14159265
	local dx=math.cos(angle)
	local dy=math.sin(angle)
	local newx=math.floor(64 + dx*s*64)
	local newy=math.floor(64 + dy*s*64)
	print(newx,newy,self.value.value)
	self.cursor.position=IntVector2(newx-4,newy-4)
	self.color=col
end

function ColorChooser:Show(x,y)
	self.panel.visible=true
	self:CalcColor()
end

function ColorChooser:Hide()
	self.panel.visible=false
end

function ColorChooser:CalcColor()
	local cursorpos=self.cursor:GetPosition()
	--print(cursorpos.x,cursorpos.y)
	local cx=cursorpos.x+4
	local cy=cursorpos.y+4
	
	local dx=(cx-64)/64
	local dy=(cy-64)/64
	local len=math.sqrt(dx*dx+dy*dy)
	local angle=math.atan2(dy,dx)
	angle = angle / (3.14159265)
	angle = (angle * 0.5) + 0.5
	if len > 1 then len=1 end
	
	local v=1.0-(self.value.value / self.value.range)
	--print(self.value.value, self.value.range)
	
	self.color=hsv2rgb(angle*360, len, v)
	self.swatch.color=self.color
end

function ColorChooser:Update(dt)
	if self.panel.visible==false then return end
	
	if input:GetMouseButtonDown(MOUSEB_LEFT) then
		--if ui.cursor.visible==false then return end
		
		local sp=ui.cursor:GetPosition()
		if self.colorwheel:IsInside(sp, true) then
			
			local ep=self.colorwheel:ScreenToElement(sp)
			local dx=((ep.x)-64)
			local dy=((ep.y)-64)
			local len=math.sqrt(dx*dx+dy*dy)
			dx=dx/len
			dy=dy/len
			len=math.min(64,len)
			local newx=math.floor(64 + dx*len)
			local newy=math.floor(64 + dy*len)
			self.cursor.position=IntVector2(newx-4, newy-4)
		end
	end
	
	self:CalcColor()
end