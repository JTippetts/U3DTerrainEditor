#ifndef ANL_H
#define ANL_H

// Define ANL_IMPLEMENTATION in exactly 1 source (.cpp) file before including this header.

#include "VM/coordinate.h"
#include "VM/instruction.h"
#include "VM/hashing.h"
#include "VM/utility.h"
#include "VM/noise_gen.h"
#include "VM/kernel.h"
#include "VM/vm.h"
#include "VM/random_gen.h"

#include "Expression/parsing.h"
#include "Expression/expressionbuilder.h"

#include "Imaging/imaging.h"

#include "Processing/erosion.h"

#ifdef ANL_IMPLEMENTATION
#include "VM/noise_lut.inl"
#include "VM/noise_gen.inl"
#include "VM/coordinate.inl"
#include "VM/hashing.inl"
#include "VM/kernel.inl"
#include "VM/vm.inl"

#include "Expression/parsing.inl"
#include "Expression/expressionbuilder.inl"

#include "Imaging/imaging.inl"

#ifdef IMPLEMENT_STB
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "Imaging/stb_image.h"
#include "Imaging/stb_image_write.h"
#undef STB_IMAGE_IMPLEMENTATION
#undef STB_IMAGE_WRITE_IMPLEMENTATION
#endif

#include "Processing/erosion.inl"
#endif

#endif
