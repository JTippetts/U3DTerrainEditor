-- Default UI styles

defaultuistyles={}

defaultuistyles.BorderImage=
{
	Type="BorderImage",
	Texture="Textures/UI_modified.png",
}

defaultuistyles.Button=
{
	Type="Button",
	Style=defaultuistyles.BorderImage,
	Size={16,16},
	ImageRect={16,0,32,16},
	Border={4,4,4,4},
	PressedOffset={16,0},
	PressedChildOffset={-1,1},
	HoverOffset={0,16},
},

defaultuistyles.ToggledButton=
{
	Style=defaultuistyles.Button,
	Type="Button",
	ImageRect={160, 64, 176, 80}
}

defaultuistyles.CheckBox=
{
	Type="CheckBox",
	MinSize={16,16},
	MaxSize={16,16},
	ImageRect={80,0,96,16},
	CheckedOffset={16,0},
	HoverOffset={0,16},
}

defaultuistyles.CloseButton=
{
	Style=defaultuistyles.Button,
	Type="Button",
	MinSize={16,16},
	MaxSize={16,16},
	ImageRect={144,0,160,16},
	FocusMode=FM_NOTFOCUSABLE,
}


