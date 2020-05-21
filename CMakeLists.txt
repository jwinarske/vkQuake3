cmake_minimum_required (VERSION 3.0)

project (vkQuake3)

#SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
#SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(CMAKE_VERBOSE_MAKEFILE ON)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	message("Debug build")
	add_definitions(-DDEBUG_BUILD)
endif()

set(ARCH_STRING armv8-a)
add_definitions(-DARCH_STRING="${ARCH_STRING}")
add_definitions(-DPLATFORM="linux")
add_definitions(-DCROSS_COMPILING=1)
add_definitions(-DVERSION="1.36")
add_definitions(-DCLIENTBIN="ioquake3")
add_definitions(-DSERVERBIN="ioq3ded")
add_definitions(-DBASEGAME="baseq3")
add_definitions(-DMISSIONPACK="missionpack")
add_definitions(-DMOUNT_DIR="code")
add_definitions(-DBUILD_DIR="build")
add_definitions(-DBOTLIB)
#add_definitions(-DNO_VM_COMPILED)
add_definitions(-DUSE_RENDERER_DLOPEN)
add_definitions(-DNDEBUG)

set (SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
link_directories(${SOURCE_PATH}/code/SDL2/lib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(code)
