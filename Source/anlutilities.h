#pragma once

#include "../ThirdParty/accidental-noise-library/anl.h"
#include <Urho3D/Resource/Image.h>

Vector2 RenderANLKernelToImage(Image *buffer, CKernel *kernel, float lowrange, float highrange, Image *histogram,int seamlessmode, bool usez, float z, float scalex, float scaley, bool rescale);