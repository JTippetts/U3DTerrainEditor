# Define target name
set (TARGET_NAME ANL)

# Define source files
file (GLOB CPP_FILES VM/*.cpp Imaging/*.cpp)
file (GLOB H_FILES VM/*.h Imaging/*.h)
set (SOURCE_FILES ${CPP_FILES} ${H_FILES})

set(INCLUDE_DIRS_ONLY ./VM ./Imaging ./templates)

if(MINGW OR CMAKE_COMPILER_IS_GNUCXX)
	include(CheckCXXCompilerFlag)
	CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
	CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
	if(COMPILER_SUPPORTS_CXX11)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	elseif(COMPILER_SUPPORTS_CXX0X)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
	else()
			message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
	endif()
endif()

# Setup target
setup_library ()