cmake_minimum_required (VERSION 3.4.3)

# Name your project. Can be anything.
project (TEdit)

# Minimal supported C++ version.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set binary output directories. Changing these paths will require you adjusting your resource path configuration!
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include cloned engine directory in a build.
# add_subdirectory(Urho3D)
include (${URHO3D_SDK}/share/CMake/Modules/UrhoCommon.cmake)
include(${URHO3D_SDK}/share/CMake/Urho3D.cmake)

file(GLOB_RECURSE MY_CPP_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp)
file(GLOB_RECURSE MY_H_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Source/*.h)

set(MY_SOURCE_FILES ${MY_CPP_FILES} ${MY_H_FILES})
add_executable(TEdit WIN32 ${MY_SOURCE_FILES})
target_link_libraries(TEdit PRIVATE Urho3D)
