# Accidental Noise Library

## Building
ANL is a header-only library. The library can be included into your project using #include <anl.h>. However, in exactly 1 compilation unit (main.cpp or otherwise), you must #define ANL_IMPLEMENTATION then #include "anl.h" to resolve link dependencies.

Included in the root level directory is a CMakeLists.txt to facilitate building a sample Lua-based command-line framework that allows experimenting with the library. To build, create an empty folder wherever you wish to build the project, change to that directory, and execute:

	cmake [path to ANL folder] -G [makefile generator of your choice]
	
The ANL executable, when executed, enters a Lua interpreter. The executable can be run instead with a Lua script filename passed on the command line to execute that file instead.

By default, ANL uses a hashing algorithm similar to the reference implementation of Perlin noise. A 512-element look-up table is used, and input coordinates are ANDed with 0xff to reference the table. This means that the noise functions will have a period of 256; with coordinates higher than that, the patterns will repeat. If a larger period is required, one can #define ANL_LONG_PERIOD_HASHING to use a long-period hash instead. This hash is based on the algorithm detailed at http://graphics.cs.kuleuven.be/publications/LD06LPHFPT/ and provides a significantly longer period for the underlying functions in exchange for a slight decrease in performance.

## Overview

The ANL is a C++ library (C++11 supported) for the generation of complex noise functions. Functions include noise generators such as Ken Perlin's [improved gradient noise](https://mrl.nyu.edu/~perlin/noise/) and [simplex noise](http://webstaff.itn.liu.se/~stegu/simplexnoise/simplexnoise.pdf) variants, a value noise generator, and [Worley's cellular noise](https://en.wikipedia.org/wiki/Worley_noise). The library allows combining various generator functions using operations (arithmetic and otherwise) in order to generate a complex output.

The library is based mostly on 2 classes:  [CKernel](https://github.com/JTippetts/accidental-noise-library/blob/master/VM/kernel.h) and [CNoiseExecutor](https://github.com/JTippetts/accidental-noise-library/blob/master/VM/vm.h#L99). CKernel encapsulate a compound noise function, and CNoiseExecutor is used to evaluate the function or a specified sub-element of the function. It's easiest to see by example:

    anl::CKernel kernel;
    anl::CNoiseExecutor vm(kernel);

    auto b=kernel.gradientBasis(kernel.constant(3), kernel.seed(1546));

    auto i=vm.evaluateScalar(0.1,0.1,b);
    std::cout << i << std::endl;
	
	--> 0.113505
	
In this short snippet, a kernel is created and assigned to a newly created noise executor. Then the method `CKernel::gradientBasis()` is called. This method creates a function generator based on Perlin's improved gradient noise. The gradientBasis() method accepts 2 input parameters: a constant denoting which interpolation type to use (see section on interpolation), and a constant to use as a random seed. All function creation methods of CKernel return an instance of the CInstructionIndex class, which can be used to access a given function. (The class simply encapsulates an unsigned int index into a std::vector, but is there to prevent users trying to pass constants directly, as opposed to creating a constant as part of the process.) Any functions that require constants, operands or source functions for their operation, require such to be created in the same kernel and referenced using CInstructionIndex parameters. Using the returned index from gradientBasis(), the `CNoiseExecutor::evaluateScalar()` method is called, with 2 coordinates (x and y) and the index of the created gradient function. The value is output to console.

Behind the scenes, CKernel stores a function chain as a flat array in a std::vector. Each element of the array is an instance of CInstruction, which stores all the data needed to reference parameters and evaluate a result. CNoiseExecutor simply evaluates the chain, starting at the given index, and returns a result.



## Interpolation

The `gradientBasis()` and `valueBasis()` functions make use of an interpolation parameter, specified (usually) as a constant. (Note that since all parameters are specified as CInstructionIndex, they can in reality point to any function in the kernel, rather than merely constants. This can give rise to complex behavior, where the operation of the function changes depending on how the input parameter changes.) The types of interpolation are: None, Linear, Cubic, and Quintic. They determine how the values of the corners of the N-dimensional hypercube used to generate the noise are interpolated. None, of course, uses no interpolation:

![None](http://i.imgur.com/HJD7mIc.png)

Linear uses simple linear `(A + t*(B-A))` interpolation:

![Linear](http://i.imgur.com/NfdYARA.png)

Cubic uses hermite interpolation, ie `t=(t*t*(3-2*t))` :

![Cubic](http://i.imgur.com/kguMGv0.png)

Quintic is the smoothest, using `t=t*t*t*(t*(t*6-15)+10)` :

![Quintic](http://i.imgur.com/LXzzp91.png)

## Expressions

Recent releases of the ANL have included an in-progress implementation of an expression parsing and evaluating class called [CExpressionBuilder](https://github.com/JTippetts/accidental-noise-library/blob/master/Expression/expressionbuilder.h). This is an attempt to make the creation of complex noise chains more concise. The principle of the expression builder is that a function can be described by an expression string:

    std::string e="clamp(scaleY(scaleX(gradientBasis(3,rand),3),3)*0.5+0.5,0,1)";
	
The string can be evaluated with an expression builder:

    anl::CExpressionBuilder eb(kernel);
	auto index=eb.eval(e);
	
The result of this is the same as if you had performed the construction of the function manually:

    auto index=kernel.clamp(kernel.add(kernel.multiply(kernel.scaleY(kernel.scaleX(kernel.gradientBasis(kernel.constant(3),kernel.seed(randomNumber)),kernel.constant(3)), kernel.constant(3)), kernel.constant(0.5)), kernel.constant(0.5)), kernel.constant(0), kernel.constant(1));

Only, as you can see, the expression is MUCH more concise than the manual function building. When the string is evaluated, numbers are automatically converted to constants in the kernel, operators map to the corresponding arithmetic functions, and other functions are available by name. The expression builder functionality is not yet complete, nor is it yet fully tested. (TODO: All this stuff.) But where it works, it works quite well. 

## Coordinates and Imaging

CNoiseExecutor provides methods called `evaluateScalar()` and `evaluateColor()`, that accept an input coordinate specified as individual parameters to the method. ie, there is a variant `evaluateScalar(x,y,index)`, a variant `evaluateScalar(x,y,z,index)` and so on. These are provided as a convenience, and are simple wrappers around the more general-purpose method, `evaluateAt()`. This method accepts 2 input parameters: an instance of a `CCoordinate` object, and an index.

    auto b=kernel.gradientBasis(kernel.constant(3), kernel.seed(1546));
	anl::CCoordinate coord(0.4, 0.5, 0.6);
	auto scalar=vm.evaluateAt(coord, b).outfloat_;
	auto color=vm.evaluateAt(coord, b).outrgba_;

All functions can be evaluated in terms of scalar values (double floating point type) or colors. The method `evaluateAt()`, then, outputs values of type SVMOutput, which is a simple structure that encapsulates both a scalar value and a color.

The ANL provides the ability to evaluate noise functions in 2, 3, 4 or 6 dimensions (more on the rationale for that in a bit). In order to consolidate the interface and simplify the back-end code, the CCoordinate class can encapsulate a single coordinate of a specific dimension. This interface allows the use of coordinates of arbitrary dimension, without requiring compile-time knowledge of the coordinate dimensions.

A common use-case for noise functions is the generation of textures and images. Because of this, all functions output both a scalar value and a color value. If one is interested in only the scalar value, the color can be safely ignored, and vice versa. In order to facilitate image generation, the ANL provides some utility mapping functions. These mapping functions operate on 1 of 4 basic data containers:

* CArray2Dd -- A 2D array of scalar (double) values
* CArray2Drgba -- A 2D array of colors
* CArray3Dd -- A 3D array of scalar values
* CArray3Drgba -- A 3D array of colors

The functions provided for imaging are:

* `map2D(seamlessmode, image, kernel, mappingranges, index, z)`
* `map2DNoZ(seamlessmode, image, kernel, mappingranges, index)`
* `mapRGBA2D(seamlessmode, image, kernel, mappingranges, index, z)`
* `mapRGBA2DNoZ(seamlessmode, image, kernel, mappingranges, index)`
* `map3D(seamlessmode, image3D, kernel, mappingranges, index)`
* `mapRGBA3D(seamlessmode, image3D, kernel, mappingranges, index)`

These functions are used to map scalar functions to grayscale images, or scalar/color functions to color images. The 2D variants are split into variants that accept a Z value and variants that do not. I will explain more about those in the section on seamless noise. Here is a quick example of mapping a color image:

    anl::CKernel kernel;
    anl::CArray2Drgba img(256,256);

    auto r=kernel.add(kernel.multiply(kernel.valueBasis(kernel.constant(1), kernel.seed(1234)), kernel.point5()), kernel.point5());
    auto g=kernel.add(kernel.multiply(kernel.valueBasis(kernel.constant(2), kernel.seed(5678)), kernel.point5()), kernel.point5());
    auto b=kernel.add(kernel.multiply(kernel.valueBasis(kernel.constant(0), kernel.seed(9101112)), kernel.point5()), kernel.point5());
    auto col=kernel.scaleDomain(kernel.combineRGBA(r,g,b,kernel.one()), kernel.constant(5));
	
	anl::mapRGBA2D(anl::SEAMLESS_NONE, img, kernel, anl::SMappingRanges(), 0, col);
    anl::saveRGBAArray("img.png", &img);
	
This snippet of code creates a kernel and an image sized 256x256. A function chain is set up by creating 3 sub-modules for the red, green and blue channels of a color. Each channel is based on a valueBasis() function that is scaled to the range 0,1 by multiplying by 0.5 and adding 0.5. (Note here that the snippet is using one of CKernel's built-in constants, in this case the constant 0.5, which are provided for convenience for commonly used constants such as 0, 1, 0.5, pi, e, and so forth).

The three channels are combined together using a `combineRGBA()` function, and the input coordinate is scaled by 5. Then the function is mapped to the image and the image is saved to .PNG. The result looks like this:

![Colors](http://i.imgur.com/rdRHgFo.png)

Note that the mapRGBA2D() method takes the image, the kernel, and the index of the function to map. But note also the mysterious SEAMLESS_NONE enumeration and the creation of an anonymous anl::SMappingRanges() object. This is a good point to segue into...

## Seamless Noise and Mapping Modes

A noise function defines a function in some number of dimensions. In the ANL, the input domain is supported in 2, 3, 4 and 6 dimensions. Behind the scenes, appropriate generators are called depending on the dimensionality of the input coordinate. So, calling `CNoiseExecutor::evaluateScalar(x,y,index)` uses behind-the-scenes calls to a 2-dimensional noise function. The domain of the function stretches to 'infinity'. In practicality, the extent of the domain is the practical extents of a coordinate expressed as double-precision floating-point numbers. Throughout this domain, the noise pattern exists without repetition.

(As a note: ANL uses [long-period hashing](http://graphics.cs.kuleuven.be/publications/LD06LPHFPT/) in order to extend the period of the underlying Perlin and value generators. The reference implementation of improved Perlin gradient noise will repeat on a period of, IIRC, 256 due to the way the hash is implemented. The long-period hash grants it a MUCH larger period.)

In some applications, it is desirable that a noise pattern be made to repeat in one or more coordinate dimensions, in order to facilitate the generation of seamlessly-tiling textures. There are blending-based methods that can be used to construct a tiling texture, but they are frequently inadequate due to the introduction of blending artifacts. The mapping functions of ANL can be used to generate seamlessly tiling noise in 1, 2 or 3 directions through the use of domain distortion, rather than blending. For example, given the noise function for this plasma texture:

![Non-tiling](http://i.imgur.com/41d7GoM.png)

Using the enumeration SEAMLESS_XY, this texture can be made to tile in the X and Y directions:

![Tiling](http://i.imgur.com/5iAfsr1.png)

In order to perform this type of seamless mapping, it is necessary to introduce higher dimensionalities to the noise functions. For example, to create a 2D texture that is seamless in both X and Y, you require a noise function that is 4-dimensional. In order to create a 3D texture, or a slice of a 3D texture mapped to a 2D image, that is seamless in 3 dimensions, you need to have a 6-dimensional noise function. For this reason the noise functions in ANL are available in dimensions up to 6.

For a more in-depth look at how the seamless mapping functions operate, see [this blog post](http://www.gamedev.net/blog/33/entry-2138456-seamless-noise/).

Note that the mapping functions take an object of type `anl::SMappingRanges`. This is a simple struct that looks like this:

    struct SMappingRanges
    {
        double mapx0,mapy0,mapz0, mapx1,mapy1,mapz1;
        double loopx0,loopy0,loopz0, loopx1,loopy1,loopz1;
	};
	
The members named mapx0, mapy0, mapz0, mapx1, mapy1, and mapz1 are used by the mapping function to determine the region of the function domain to map to the image. The members named loopx0, loopy0, loopz0, loopx1, loopy1, loopz1 determine the region of the function domain which will repeat in a seamless mapping. By default these are set to (0,0,0)->(1,1,1). This means that when a function is mapped, the function is sampled from (0,0,0) to (1,1,1) and mapped to the pixels of the image. If the mapping mode chosen is seamless in X and Y, then the pattern that occurs in the sub-region of the function will repeat across the entire domain of the function.


