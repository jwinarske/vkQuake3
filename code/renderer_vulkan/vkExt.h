#pragma once

#define VK_NO_PROTOTYPES
#include "vulkan/vulkan.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * assembly to vulkan resource mapping
 *
 * map vulkan resources such as
 * -push constants
 * -descriptor set entries
 *	-images
 *  -buffers
 *
 * to assembly uniform reads
 *
 * push constants should be one read
 *
 * buffers and images are handled through the TMU pipeline
 * and therefore carry implicit uniform reads
 * buffers should be one uniform (general memory read)
 * number of uniforms for images are dependent on type (and TMU writes)
 *
 * therefore what we need is a mapping for each assembly uniform read
 * to some vulkan resource
 * and the driver should be able to figure out what to put in the uniform queue
 * based on the mapping
 *
 * vertex and coordinate shader mappings are shared
 *
 */


typedef enum VkRpiAssemblyMappingTypeEXT {
	VK_RPI_ASSEMBLY_MAPPING_TYPE_DESCRIPTOR = 0,
	VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT = 1,
	VK_RPI_ASSEMBLY_MAPPING_TYPE_MAX
} VkRpiAssemblyMappingTypeEXT;

//defines mapping for a single uniform FIFO read to a Vulkan resource
typedef struct VkRpiAssemblyMappingEXT {
	VkRpiAssemblyMappingTypeEXT	mappingType;
	VkDescriptorType			descriptorType;
	uint32_t					descriptorSet;
	uint32_t					descriptorBinding;
	uint32_t					descriptorArrayElement;
	uint32_t					resourceOffset; //in bytes
	VkShaderStageFlagBits		shaderStage;
} VkRpiAssemblyMappingEXT;

typedef struct VkRpiShaderModuleAssemblyCreateInfoEXT {
	VkStructureType               sType;
	const void*                   pNext;
	uint64_t**					  instructions;
	uint32_t*					  numInstructions;
	VkRpiAssemblyMappingEXT*	  mappings;
	uint32_t					  numMappings;
} VkRpiShaderModuleAssemblyCreateInfoEXT;

#ifdef __cplusplus
}
#endif

