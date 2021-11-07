cmake_minimum_required (VERSION 3.10.2)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: Debug, Release, or MinSizeRel." FORCE)
    message(STATUS "CMAKE_BUILD_TYPE not set, defaulting to Release.")
endif ()

project (vkQuake3 
         DESCRIPTION "Vulkan Quake3 Engine"
         LANGUAGES CXX C ASM)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	message("Debug build")
	add_definitions(-DDEBUG_BUILD)
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(NOT CMAKE_CROSSCOMPILING)
    set(ARCH_STRING x86_64)
else()
	#armv8-a	#RPi support: 2B 1.2, 3B, 3B+
	#armv7-a	#RPi support: 2B
	#armv8		#RPi support: 3A+
	#armv6z		#RPi support: 1A, 1A+, 1B, Zero 1.2, Zero 1.3, Zero W
	if (NOT ARCH_STRING)
		set(ARCH_STRING "armv8-a" CACHE STRING "Choose the arch of build." FORCE)
		message(STATUS "CMAKE_BUILD_TYPE not set, defaulting to armv8-a.")
	endif ()
endif()

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
if(${ARCH_STRING} STREQUAL armv6z)
	add_definitions(-DNO_VM_COMPILED)
endif()
add_definitions(-DUSE_RENDERER_DLOPEN)
add_definitions(-DNDEBUG)

set (SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(code)
