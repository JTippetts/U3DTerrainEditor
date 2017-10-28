#ifndef EROSION_H
#define EROSION_H

#include "../VM/random_gen.h"
#include "../Imaging/imaging.h"

void simpleErode(anl::CArray2Dd &map, unsigned int numdrops, float power);
void waterFlow(anl::CArray2Dd &map, anl::CArray2Dd &flow, unsigned int numdrops);

#endif
