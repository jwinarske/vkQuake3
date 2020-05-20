/*
===========================================================================
Copyright (C) 1999-2005 Id Software, Inc.

This file is part of Quake III Arena source code.

Quake III Arena source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Quake III Arena source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Quake III Arena source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/


// the window surface needs to be createdd right after the instance creation
// because it can actually influence the physical device selection

#include "VKimpl.h"
#include "vk_instance.h"

#include "tr_cvar.h"
#include "icon_oa.h"
#include "glConfig.h"

#include <dlfcn.h>


#ifdef _WIN32
	#include "../SDL2/include/SDL.h"
	#include "../SDL2/include/SDL_vulkan.h"
#else
	#include <SDL2/SDL.h>
    #include <SDL2/SDL_syswm.h>
    #include <SDL2/SDL_vulkan.h>
#endif


static VkDisplayModeKHR displayMode;


// TODO: multi display support
static cvar_t* r_displayIndex;


static int VKimp_SetMode(int mode, qboolean fullscreen)
{
	ri.Printf(PRINT_ALL,  "...VKimp_SetMode()...\n");

	uint32_t displayCount;
	qvkGetPhysicalDeviceDisplayPropertiesKHR(vk.physical_device, &displayCount, 0);
	VkDisplayPropertiesKHR* displayProperties = (VkDisplayPropertiesKHR*)malloc(sizeof(VkDisplayPropertiesKHR)*displayCount);
	qvkGetPhysicalDeviceDisplayPropertiesKHR(vk.physical_device, &displayCount, displayProperties);

	if (displayCount < 1)
	{
		ri.Printf(PRINT_ALL, "No displays found\n");
	}

	uint32_t modeCount;
	qvkGetDisplayModePropertiesKHR(vk.physical_device, displayProperties[r_displayIndex->integer].display, &modeCount, 0);
	VkDisplayModePropertiesKHR* displayModeProperties = (VkDisplayModePropertiesKHR*)malloc(sizeof(VkDisplayModePropertiesKHR)*modeCount);
	qvkGetDisplayModePropertiesKHR(vk.physical_device, displayProperties[r_displayIndex->integer].display, &modeCount, displayModeProperties);

	//if(fullscreen)
    {
        // prevent crush the OS
		r_mode->integer = mode = -1;
		R_SetWinMode( -1, 0, 0, 0 );
    }

    int width = 640;
    int height = 480;

    R_GetWinResolution(&width, &height);

	vk_createSurfaceImpl(width, height);

	free(displayProperties);
	free(displayModeProperties);

	return 0;
}

/*
 * This routine is responsible for initializing the OS specific portions of Vulkan
 */
void vk_createWindow(void)
{
	ri.Printf(PRINT_ALL, "...Creating window (using Vulkan Direct to Display)...\n");

	r_displayIndex = ri.Cvar_Get( "r_displayIndex", "0", CVAR_ARCHIVE | CVAR_LATCH );

	if(ri.Cvar_VariableIntegerValue( "com_abnormalExit" ) )
	{
		ri.Cvar_Set( "r_fullscreen", "0" );
        ri.Cvar_Set( "r_mode", "3" );
		ri.Cvar_Set( "com_abnormalExit", "0" );
	}

	if( 0 == VKimp_SetMode(r_mode->integer, r_fullscreen->integer) )
	{
        goto success;
	}
    else
    {
        ri.Printf(PRINT_ALL, "Setting r_mode=%d, r_fullscreen=%d failed, falling back on r_mode=%d\n",
                r_mode->integer, r_fullscreen->integer, 3 );

        if( 0 == VKimp_SetMode(3, qfalse) )
        {
            goto success;
        }
        else
        {
            ri.Error(ERR_FATAL, "VKimp_Init() - could not load Vulkan subsystem" );
        }
    }


success:

	//TODO
	ri.IN_Init(NULL);
}


void vk_getInstanceProcAddrImpl(void)
{

	void* vkLib = dlopen("libvulkan.so", RTLD_NOW);

	if (!vkLib) {
		ri.Error(ERR_FATAL, "Failed to load Vulkan library\n");
    }
    // Create the window 

	qvkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr) dlsym(vkLib, "vkGetInstanceProcAddr");
    if( qvkGetInstanceProcAddr == NULL)
    {
        ri.Error(ERR_FATAL, "Failed to find entrypoint vkGetInstanceProcAddr\n"); 
    }
    
	ri.Printf(PRINT_ALL,  " Get instance proc address.\n");
}


void vk_destroyWindow( void )
{
	ri.Printf(PRINT_ALL, " Destroy Window Subsystem.\n");

	ri.IN_Shutdown();
}


void vk_createSurfaceImpl(uint32_t width, uint32_t height)
{
	ri.Printf(PRINT_ALL, " Create Surface: vk.surface %u x %u\n", width, height);

	uint32_t displayCount;
	qvkGetPhysicalDeviceDisplayPropertiesKHR(vk.physical_device, &displayCount, 0);
	VkDisplayPropertiesKHR* displayProperties = (VkDisplayPropertiesKHR*)malloc(sizeof(VkDisplayPropertiesKHR)*displayCount);
	qvkGetPhysicalDeviceDisplayPropertiesKHR(vk.physical_device, &displayCount, displayProperties);

	//TODO r_displayIndex->integer
	uint32_t modeCount;
	qvkGetDisplayModePropertiesKHR(vk.physical_device, displayProperties[0].display, &modeCount, 0);
	VkDisplayModePropertiesKHR* displayModeProperties = (VkDisplayModePropertiesKHR*)malloc(sizeof(VkDisplayModePropertiesKHR)*modeCount);
	qvkGetDisplayModePropertiesKHR(vk.physical_device, displayProperties[0].display, &modeCount, displayModeProperties);

	int mode = -1;
	for(uint32_t c = 0; c < modeCount; ++c)
	{
		if(displayModeProperties[c].parameters.visibleRegion.width == width &&
		   displayModeProperties[c].parameters.visibleRegion.height == height)
		{
			mode = c;
			break;
		}
	}

	VkDisplayModeCreateInfoKHR dmci = {};
	dmci.sType = VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR;
	dmci.parameters = displayModeProperties[mode].parameters;
	VkDisplayModeKHR displayMode;
	qvkCreateDisplayModeKHR(vk.physical_device, displayProperties[0].display, &dmci, 0, &displayMode);

	VkDisplaySurfaceCreateInfoKHR dsci = {};
	dsci.sType = VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR;
	dsci.displayMode = displayMode;
	dsci.transform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
	dsci.alphaMode = VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR;
	dsci.imageExtent = displayModeProperties[mode].parameters.visibleRegion;
	qvkCreateDisplayPlaneSurfaceKHR(vk.instance, &dsci, 0, &vk.surface);

	free(displayProperties);
	free(displayModeProperties);

	if(!vk.surface)
    {
        vk.surface = VK_NULL_HANDLE;
		ri.Error(ERR_FATAL, "Failed to create Vulkan Direct to Display surface\n");
    }
}




/*
===============
Minimize the game so that user is back at the desktop
===============
*/
void vk_minimizeWindow( void )
{
    VkBool32 toggleWorked = 1;
    ri.Printf( PRINT_ALL, " Minimizing Window (SDL). \n");
}
