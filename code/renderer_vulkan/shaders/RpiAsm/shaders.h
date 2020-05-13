#pragma once

#include <stdint.h>
#include "../../vkExt.h"

VkRpiAssemblyMappingEXT singleTextureVS_mapping[] = {
	{ //m0w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		12, //resource offset
	},
	{ //m1w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		28, //resource offset
	},
	{ //m0x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		0, //resource offset
	},
	{ //m1x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		16, //resource offset
	},
	{ //m0y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		4, //resource offset
	},
	{ //m1y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		20, //resource offset
	},
	{ //m0z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		8, //resource offset
	},
	{ //m1z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		24, //resource offset
	},
	{ //m2w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		44, //resource offset
	},
	{ //m3w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		60, //resource offset
	},
	{ //m2y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		36, //resource offset
	},
	{ //m2x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		32, //resource offset
	},
	{ //m2z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		40, //resource offset
	},
	{ //m3x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		48, //resource offset
	},
	{ //x scale
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		64, //resource offset
	},
	{ //m3y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		52, //resource offset
	},
	{ //y scale
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		68, //resource offset
	},
	{ //m3z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		56, //resource offset
	},
	{ //z scale
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		72, //resource offset
	},
	{ //z offset
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		76, //resource offset
	},
};

char singleTextureVS_str[] =
"sig_load_imm ; vr_setup.nop = load32.always(0x601a00) ; nop = load32.always() ;"
"sig_none ; rx2.nop = or.ws.always.nop(a, a, vpm_read, nop) ; nop = nop.never(r0, r0) ; "		//read rb2 = vx
"sig_none ; rx3.nop = or.always.nop(a, a, vpm_read, nop) ; nop = nop.never(r0, r0) ; "			//read ra3 = vy
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r2 = fmul.always(a, b) ; "				///vx * m0w
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra3, uni) ; r1 = fmul.always(b, a) ; "				///vy * m1w
"sig_none ; rx5.nop = fadd.always.nop(r2, r1, uni, rb2) ; r3 = fmul.always(a, b) ; "			///vx * m0x
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra3, uni) ; r2 = fmul.always(b, a) ; "				///vy * m1x
"sig_none ; rx3.nop = fadd.ws.always.nop(r3, r2, uni, rb2) ; r0 = fmul.always(a, b) ; "			///vx * m0y
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra3, uni) ; r3 = fmul.always(b, a) ; "				///vy * m1y
"sig_none ; rx4.nop = fadd.ws.always.nop(r0, r3, uni, rb2) ; r1 = fmul.always(a, b) ; "			///vx * m0z
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra3, uni) ; r0 = fmul.always(b, a) ; "				///vy * m1z
"sig_none ; rx4.nop = fadd.always.nop(r1, r0, vpm_read, nop) ; rx1 = v8min.always(a, a) ; "		//read rb1 = vz
"sig_load_imm ; vw_setup = load32.ws.always(0x1a00) ; nop = load32.always() ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb1) ; r0 = fmul.always(a, b) ; "				///vz * m2w
"sig_none ; r3.nop = fadd.always.nop(a, r0, ra5, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r0.nop = fadd.ws.always.nop(r3, b, vpm_read, uni) ; rx1 = v8min.always(a, a) ; "	///+m3w;
"sig_none ; sfu_recip.nop = or.ws.always.nop(r0, r0, uni, rb1) ; r3 = fmul.always(a, b) ; "		///1 / Wc, vz * m2y
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb1) ; r2 = fmul.always(a, b) ; "				///vz * m2x
"sig_none ; r1.nop = fadd.always.nop(b, r3, nop, rb4) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx2.nop = fadd.always.nop(b, r2, nop, rb3) ; r2 = fmul.always(r0, r4) ; "			//
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb1) ; r3 = fmul.always(a, b) ; "				///vz * m2z
"sig_none ; rx5.nop = fadd.ws.always.nop(a, r3, ra4, nop) ; nop = nop.never(r0, r0) ; "			//
"sig_small_imm ; r3.nop = fsub.always.nop(b, r2, nop, 0x40000000) ; nop = nop.never(r0, r0) ; "
"sig_none ; r0.nop = fadd.ws.always.nop(a, b, ra2, uni) ; rx6 = fmul.always(r4, r3) ; "			///+m3x, ra6 = 1/Wc
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r2 = fmul.always(r0, a) ; "				//Xscale
"sig_none ; r1.nop = fadd.always.nop(r1, b, ra6, uni) ; r3 = fmul.always(r2, a) ; "				///+m3y
"sig_none ; rx0.16a = ftoi.always.nop(r3, r3, uni, nop) ; r0 = fmul.always(r1, a) ;	"			//Yscale
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra6, nop) ; r1 = fmul.always(r0, a) ; "
"sig_none ; rx0.16b = ftoi.always.nop(r1, r1, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r1.nop = fadd.always.nop(b, a, uni, rb5) ; nop = nop.never(r0, r0) ; "				///+m3z
"sig_none ; vpm.nop = or.always.nop(a, a, ra0, uni) ; r0 = fmul.always(r1, b) ;	"				//write Xs/Ys, Zscale
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra6, nop) ; r1 = fmul.always(r0, a) ; "
"sig_none ; vpm.nop = fadd.always.nop(r1, b, vpm_read, uni) ; r0 = v8min.always(a, a) ;	"		//write Zs, Zoffset
"sig_none ; vpm.nop = or.always.nop(a, a, ra6, nop) ; nop = nop.never(r0, r0) ;	"				//write 1/Wc
"sig_none ; vpm.nop = fmax.always.8a(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = fmax.always.8b(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = fmax.always.8c(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = fmax.always.8d(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = or.always.nop(r0, r0, vpm_read, nop) ; r1 = v8min.always(a, a) ; "
"sig_none ; vpm.nop = or.always.nop(r1, r1, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;

VkRpiAssemblyMappingEXT singleTextureCS_mapping[] = {
	{ //m0x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		0, //resource offset
	},
	{ //m1x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		16, //resource offset
	},
	{ //m0y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		4, //resource offset
	},
	{ //m1w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		28, //resource offset
	},
	{ //m1y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		20, //resource offset
	},
	{ //m0w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		12, //resource offset
	},
	{ //m1z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		24, //resource offset
	},
	{ //m0z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		8, //resource offset
	},
	{ //m2x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		32, //resource offset
	},
	{ //m2w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		44, //resource offset
	},
	{ //m2y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		36, //resource offset
	},
	{ //m3x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		48, //resource offset
	},
	{ //m2z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		40, //resource offset
	},
	{ //m3w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		60, //resource offset
	},
	{ //m3y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		52, //resource offset
	},
	{ //m3z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		56, //resource offset
	},

	{ //y scale
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		68, //resource offset
	},
	{ //x scale
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		64, //resource offset
	},
	{ //z scale
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		72, //resource offset
	},
	{ //z offset
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		76, //resource offset
	},
};

char singleTextureCS_str[] =
"sig_load_imm ; vr_setup.nop = load32.always(0x301a00) ; nop = load32.always() ; "
"sig_none ; rx2.nop = or.always.nop(a, a, vpm_read, nop) ; nop = nop.never(r0, r0) ; "			//read ra2 = vx
"sig_none ; rx2.nop = or.ws.always.nop(a, a, vpm_read, nop) ; nop = nop.never(r0, r0) ; "		//read rb2 = vy
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra2, uni) ; r1 = fmul.always(b, a) ; "				///vx * m0x
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r0 = fmul.always(a, b) ; "				///vy * m1x
"sig_none ; rx4.nop = fadd.always.nop(r1, r0, ra2, uni) ; r2 = fmul.always(b, a) ; "			///vx * m0y
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r3 = fmul.always(a, b) ; "				///vy * m1w
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r1 = fmul.always(a, b) ; "				///vy * m1y
"sig_none ; rx1.nop = fadd.ws.always.nop(r2, r1, ra2, uni) ; r0 = fmul.always(b, a) ; "			///vx * m0w
"sig_none ; rx3.nop = fadd.always.nop(r0, r3, uni, rb2) ; r2 = fmul.always(a, b) ; "			///vy * m1z
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra2, uni) ; r3 = fmul.always(b, a) ; "				///vx * m0z
"sig_none ; rx1.nop = fadd.always.nop(r3, r2, vpm_read, nop) ; r2 = v8min.always(a, a) ; "		//read r2 = vz
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r0 = fmul.always(a, r2) ; "				///vz * m2x
"sig_none ; rx0.nop = fadd.ws.always.nop(a, r0, ra4, uni) ; r3 = fmul.always(b, r2) ; "			///vz * m2w
"sig_none ; r0.nop = fadd.always.nop(a, r3, ra3, uni) ; r1 = fmul.always(b, r2) ; "				///vz * m2y,
"sig_none ; rx4.nop = fadd.ws.always.nop(b, a, uni, rb0) ; nop = nop.never(r0, r0) ; "			///+m3x
"sig_none ; r3.nop = fadd.always.nop(b, r1, uni, rb1) ; r2 = fmul.always(a, r2) ; "				///vz * m2z
"sig_load_imm ; vw_setup = load32.ws.always(0x1a00) ; nop = load32.always() ; "
"sig_none ; r1.nop = fadd.always.nop(a, r2, ra1, rb4) ; vpm = v8min.always(b, b) ; "			//write Xc,
"sig_none ; r0.nop = fadd.always.nop(r0, a, uni, nop) ; nop = nop.never(r0, r0) ; "				///+m3w
"sig_none ; r2.nop = fadd.ws.always.nop(r3, a, uni, nop) ; sfu_recip = v8min.always(r0, r0) ; "	///+m3y
"sig_none ; rx5.nop = fadd.always.nop(r1, a, uni, nop) ; vpm = v8min.always(r2, r2) ; "			///write Yc, +m3z
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r3 = fmul.always(r2, a) ; "				//Yscale
"sig_none ; vpm.nop = or.always.nop(a, a, ra5, nop) ; nop = nop.never(r0, r0) ; "				//write Zc
"sig_none ; vpm.nop = or.always.nop(r0, r0, nop, nop) ; r0 = fmul.always(r0, r4) ; "			//write Wc
"sig_small_imm ; r1.nop = fsub.always.nop(b, r0, nop, 0x40000000) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; rx3 = fmul.always(r4, r1) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb4) ; r1 = fmul.always(b, a) ; "				//Xscale
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, rb3) ; r2 = fmul.always(r1, b) ; "
"sig_none ; rx0.16a = ftoi.always.nop(r2, r2, nop, rb3) ; r0 = fmul.always(r3, b) ; "
"sig_none ; rx0.16b = ftoi.always.nop(r0, r0, ra5, uni) ; r2 = fmul.always(a, b) ; "			//Zscale
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, rb3) ; r3 = fmul.always(r2, b) ; "
"sig_none ; vpm.nop = or.always.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ;	"				//write XsYs
"sig_none ; vpm.nop = fadd.always.nop(r3, a, uni, nop) ; nop = nop.never(r0, r0) ; "			//write Zs, Zoffset
"sig_none ; vpm.nop = or.always.nop(b, b, nop, rb3) ; nop = nop.never(r0, r0) ;	"				//write 1/Wc
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;

VkRpiAssemblyMappingEXT singleTextureClippingPlaneVS_mapping[] = {
	{ //em0x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		64+0, //resource offset
	},
	{ //em0y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		64+4, //resource offset
	},
	{ //em1x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		64+16, //resource offset
	},
	{ //em1y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		64+20, //resource offset
	},
	{ //m1w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		28, //resource offset
	},
	{ //m0w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		12, //resource offset
	},
	{ //em0z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		64+8, //resource offset
	},
	{ //em1z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		64+24, //resource offset
	},
	{ //m0x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		0, //resource offset
	},
	{ //m1x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		16, //resource offset
	},
	{ //m0y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		4, //resource offset
	},
	{ //m1y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		20, //resource offset
	},
	{ //m1z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		24, //resource offset
	},
	{ //m0z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		8, //resource offset
	},
	{ //em0w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		64+12, //resource offset
	},
	{ //em1w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		64+28, //resource offset
	},
	{ //em2y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		64+36, //resource offset
	},
	{ //m2y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		36, //resource offset
	},
	{ //em2z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		64+40, //resource offset
	},
	{ //m2w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		44, //resource offset
	},
	{ //em2x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		64+32, //resource offset
	},
	{ //em2w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		64+44, //resource offset
	},
	{ //m2z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		40, //resource offset
	},
	{ //em3x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		64+48, //resource offset
	},
	{ //em3y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		64+52, //resource offset
	},
	{ //CPx
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		128+0, //resource offset
	},
	{ //m2x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		32, //resource offset
	},
	{ //CPy
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		128+4, //resource offset
	},
	{ //m3w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		60, //resource offset
	},
	{ //em3z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		64+56, //resource offset
	},
	{ //CPz
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		128+8, //resource offset
	},
	{ //m3x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		48, //resource offset
	},
	{ //Xscale
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		128+16+0, //resource offset
	},
	{ //m3y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		52, //resource offset
	},
	{ //Yscale
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		128+16+4, //resource offset
	},
	{ //m3z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		56, //resource offset
	},
	{ //Zscale
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		128+16+8, //resource offset
	},
	{ //Zoffset
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		128+16+12, //resource offset
	},
	{ //em3w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		64+60, //resource offset
	},
	{ //CPw
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		128+12, //resource offset
	},
};

char singleTextureClippingPlaneVS_str[] =
"sig_load_imm ; vr_setup.nop = load32.always(0x601a00) ; nop = load32.always() ; "
"sig_none ; rx8.nop = or.ws.always.nop(a, a, vpm_read, nop) ; nop = nop.never(r0, r0) ; "		//read rb8 = vx
"sig_none ; rx9.nop = or.always.nop(a, a, vpm_read, nop) ; nop = nop.never(r0, r0) ; "			//read ra9 = vy
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb8) ; r0 = fmul.always(b, a) ; "				///vx * em0x
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb8) ; r2 = fmul.always(b, a) ; "				///vx * em0y
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra9, uni) ; r1 = fmul.always(a, b) ; "				///vy * em1x
"sig_none ; rx10.nop = fadd.always.nop(r0, r1, ra9, uni) ; r3 = fmul.always(a, b) ; "			///vy * em1y
"sig_none ; rx9.nop = fadd.ws.always.nop(r2, r3, ra9, uni) ; r1 = fmul.always(b, a) ; "			///vy * m1w
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb8) ; r3 = fmul.always(a, b) ; "				///vx * m0w
"sig_none ; rx8.nop = fadd.always.nop(r3, r1, uni, rb8) ; r2 = fmul.always(b, a) ; "			///vx * em0z
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra9, uni) ; r3 = fmul.always(a, b) ; "				///vy * em1z
"sig_none ; rx7.nop = fadd.ws.always.nop(r2, r3, uni, rb8) ; r0 = fmul.always(a, b) ; "			///vx * m0x
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra9, uni) ; r2 = fmul.always(b, a) ; "				///vy * m1x
"sig_none ; rx6.nop = fadd.ws.always.nop(r0, r2, uni, rb8) ; r1 = fmul.always(a, b) ; "			///vx * m0y
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra9, uni) ; r3 = fmul.always(b, a) ; "				///vy * m1y
"sig_none ; rx5.nop = fadd.ws.always.nop(r1, r3, ra9, uni) ; r0 = fmul.always(b, a) ; "			///vy * m1z
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb8) ; r2 = fmul.always(a, b) ; "				///vx * m0z
"sig_none ; rx5.nop = fadd.always.nop(r2, r0, vpm_read, nop) ; rx2 = v8min.always(a, a) ; "		//read rb2 = vz
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb8) ; r3 = fmul.always(b, a) ; "				///vx * em0w
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra9, uni) ; r2 = fmul.always(a, b) ; "				///vy * em1w
"sig_none ; rx4.nop = fadd.ws.always.nop(r3, r2, uni, rb2) ; r0 = fmul.always(b, a) ; "			///vz * em2y
"sig_none ; rx1.nop = fadd.ws.always.nop(b, r0, vpm_read, rb9) ; rx1 = v8min.always(a, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r3 = fmul.always(a, b) ; "				///vz * m2y
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r0 = fmul.always(b, a) ; "				///vz * em2z
"sig_none ; rx6.nop = fadd.always.nop(b, r3, nop, rb5) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx4.nop = fadd.always.nop(b, r0, nop, rb7) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r1 = fmul.always(a, b) ; "				///vz * m2w
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r2 = fmul.always(b, a) ; "				///vz * em2x
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r3 = fmul.always(b, a) ; "				///vz * em2w
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r0 = fmul.always(a, b) ; "				///vz * m2z
"sig_none ; rx3.nop = fadd.ws.always.nop(a, r1, ra8, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx3.nop = fadd.always.nop(a, r2, ra10, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx11.nop = fadd.ws.always.nop(b, r3, nop, rb4) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx10.nop = fadd.ws.always.nop(a, r0, ra5, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r1.nop = fadd.always.nop(a, b, ra3, uni) ; nop = nop.never(r0, r0) ; "				///+em3x
"sig_none ; r3.nop = fadd.always.nop(b, a, uni, rb1) ; nop = nop.never(r0, r0) ; "				///+em3y
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r0 = fmul.always(a, r1) ; "				//CPx
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r2 = fmul.always(a, b) ; "				///vz * m2x
"sig_none ; rx7.nop = fadd.always.nop(b, r2, uni, rb6) ; r1 = fmul.always(a, r3) ; "			//CPy
"sig_none ; r0.nop = fadd.always.nop(r1, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3.nop = fadd.always.nop(b, a, uni, rb3) ; nop = nop.never(r0, r0) ; "				///+m3w
"sig_none ; r1.nop = fadd.ws.always.nop(a, b, ra4, uni) ; sfu_recip = v8min.always(r3, r3) ; "	///+em3z
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r2 = fmul.always(a, r1) ; "				//CPz
"sig_none ; rx11.nop = fadd.always.nop(r0, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; r0 = fmul.always(r3, r4) ; "
"sig_small_imm ; r1.nop = fsub.always.nop(b, r0, nop, 0x40000000) ; nop = nop.never(r0, r0) ; "
"sig_none ; r0.nop = fadd.ws.always.nop(a, b, ra7, uni) ; rx2 = fmul.always(r4, r1) ; "        ///+m3x
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r2 = fmul.always(r0, a) ; "				//Xscale
"sig_none ; r1.nop = fadd.always.nop(a, b, ra6, uni) ; nop = nop.never(r0, r0) ; "				///+m3y
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra2, nop) ; r3 = fmul.always(r2, a) ; "
"sig_none ; rx0.16a = ftoi.always.nop(r3, r3, uni, nop) ; r0 = fmul.always(r1, a) ; "			//Yscale
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra2, nop) ; r1 = fmul.always(r0, a) ; "
"sig_none ; r2.nop = fadd.always.nop(b, a, uni, rb10) ; nop = nop.never(r0, r0) ; "				///+m3z
"sig_none ; rx0.16b = ftoi.always.nop(r1, r1, uni, nop) ; r2 = fmul.always(r2, a) ; "			//zscale
"sig_load_imm ; vw_setup = load32.ws.always(0x1a00) ; nop = load32.always() ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra2, nop) ; r3 = fmul.always(r2, a) ; "
"sig_none ; vpm.nop = or.always.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "				//write XsYs
"sig_none ; vpm.nop = fadd.always.nop(r3, b, vpm_read, uni) ; r0 = v8min.always(a, a) ; "		//write Zs, zoffset
"sig_none ; vpm.nop = or.always.nop(a, a, ra2, nop) ; nop = nop.never(r0, r0) ; "				//write 1/Wc
"sig_none ; vpm.nop = fmax.always.8a(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "				//write incolorR
"sig_none ; vpm.nop = fmax.always.8b(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "				//write incolorG
"sig_none ; vpm.nop = fmax.always.8c(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "				//write incolorB
"sig_none ; vpm.nop = fmax.always.8d(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "				//write incolorA
"sig_none ; r1.nop = or.always.nop(a, a, vpm_read, nop) ; vpm = v8min.always(r0, r0) ; "		//write texcoordU
"sig_none ; r0.nop = fadd.always.nop(b, a, uni, rb11) ; vpm = v8min.always(r1, r1) ; "			///write texcoordV, +em3w
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r3 = fmul.always(a, r0) ; "				//CPw
"sig_none ; vpm.nop = fadd.always.nop(a, r3, ra11, nop) ; nop = nop.never(r0, r0) ;	"			//write clipDistance
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;

VkRpiAssemblyMappingEXT singleTextureClippingPlaneCS_mapping[] = {
	{ //m0x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		0, //resource offset
	},
	{ //m1x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		16, //resource offset
	},
	{ //m0y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		4, //resource offset
	},
	{ //m1w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		28, //resource offset
	},
	{ //m1y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		20, //resource offset
	},
	{ //m0w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		12, //resource offset
	},
	{ //m1z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		24, //resource offset
	},
	{ //m0z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		8, //resource offset
	},
	{ //m2z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		32, //resource offset
	},
	{ //m2w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		44, //resource offset
	},
	{ //m2y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		36, //resource offset
	},
	{ //m3x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		48, //resource offset
	},
	{ //m2z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		40, //resource offset
	},
	{ //m3w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		60, //resource offset
	},
	{ //m3y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		52, //resource offset
	},
	{ //m3z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		56, //resource offset
	},

	{ //y scale
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		128+16+4, //resource offset
	},
	{ //x scale
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		128+16+0, //resource offset
	},
	{ //z scale
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		128+16+8, //resource offset
	},
	{ //z offset
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		128+16+12, //resource offset
	},
};

char singleTextureClippingPlaneCS_str[] =
"sig_load_imm ; vr_setup.nop = load32.always(0x301a00) ; nop = load32.always() ;"
"sig_none ; rx2.nop = or.always.nop(a, a, vpm_read, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx2.nop = or.ws.always.nop(a, a, vpm_read, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra2, uni) ; r1 = fmul.always(b, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r0 = fmul.always(a, b) ; "
"sig_none ; rx4.nop = fadd.always.nop(r1, r0, ra2, uni) ; r2 = fmul.always(b, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r3 = fmul.always(a, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r1 = fmul.always(a, b) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r2, r1, ra2, uni) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx3.nop = fadd.always.nop(r0, r3, uni, rb2) ; r2 = fmul.always(a, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra2, uni) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r3, r2, vpm_read, nop) ; r2 = v8min.always(a, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r0 = fmul.always(a, r2) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(a, r0, ra4, uni) ; r3 = fmul.always(b, r2) ; "
"sig_none ; r0.nop = fadd.always.nop(a, r3, ra3, uni) ; r1 = fmul.always(b, r2) ; "
"sig_none ; rx4.nop = fadd.ws.always.nop(b, a, uni, rb0) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3.nop = fadd.always.nop(b, r1, uni, rb1) ; r2 = fmul.always(a, r2) ; "
"sig_load_imm ; vw_setup = load32.ws.always(0x1a00) ; nop = load32.always() ;"
"sig_none ; r1.nop = fadd.always.nop(a, r2, ra1, rb4) ; vpm = v8min.always(b, b) ; "
"sig_none ; r0.nop = fadd.always.nop(r0, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r2.nop = fadd.ws.always.nop(r3, a, uni, nop) ; sfu_recip = v8min.always(r0, r0) ; "
"sig_none ; rx5.nop = fadd.always.nop(r1, a, uni, nop) ; vpm = v8min.always(r2, r2) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r3 = fmul.always(r2, a) ; "
"sig_none ; vpm.nop = or.always.nop(a, a, ra5, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = or.always.nop(r0, r0, nop, nop) ; r0 = fmul.always(r0, r4) ; "
"sig_small_imm ; r1.nop = fsub.always.nop(b, r0, nop, 0x40000000) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; rx3 = fmul.always(r4, r1) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb4) ; r1 = fmul.always(b, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, rb3) ; r2 = fmul.always(r1, b) ; "
"sig_none ; rx0.16a = ftoi.always.nop(r2, r2, nop, rb3) ; r0 = fmul.always(r3, b) ; "
"sig_none ; rx0.16b = ftoi.always.nop(r0, r0, ra5, uni) ; r2 = fmul.always(a, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, rb3) ; r3 = fmul.always(r2, b) ; "
"sig_none ; vpm.nop = or.always.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = fadd.always.nop(r3, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = or.always.nop(b, b, nop, rb3) ; nop = nop.never(r0, r0) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;

char multiTextureVS_str[] =
"sig_load_imm ; vr_setup.nop = load32.always(0x801a00) ; nop = load32.always() ;"
"sig_none ; rx2.nop = or.ws.always.nop(a, a, vpm_read, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx3.nop = or.always.nop(a, a, vpm_read, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r0 = fmul.always(a, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra3, uni) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx5.nop = fadd.always.nop(r0, r3, uni, rb2) ; r1 = fmul.always(a, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra3, uni) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx3.nop = fadd.ws.always.nop(r1, r0, uni, rb2) ; r2 = fmul.always(a, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra3, uni) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx4.nop = fadd.ws.always.nop(r2, r1, uni, rb2) ; r3 = fmul.always(a, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra3, uni) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx4.nop = fadd.always.nop(r3, r2, vpm_read, nop) ; rx1 = v8min.always(a, a) ; "
"sig_load_imm ; vw_setup = load32.ws.always(0x1a00) ; nop = load32.always() ;"
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb1) ; r2 = fmul.always(a, b) ; "
"sig_none ; r1.nop = fadd.always.nop(a, r2, ra5, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r2.nop = fadd.ws.always.nop(r1, b, vpm_read, uni) ; rx1 = v8min.always(a, a) ; "
"sig_none ; sfu_recip.nop = or.ws.always.nop(r2, r2, uni, rb1) ; r1 = fmul.always(a, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb1) ; r0 = fmul.always(a, b) ; "
"sig_none ; r3.nop = fadd.always.nop(b, r1, nop, rb4) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx2.nop = fadd.always.nop(b, r0, nop, rb3) ; r0 = fmul.always(r2, r4) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb1) ; r1 = fmul.always(a, b) ; "
"sig_none ; rx5.nop = fadd.ws.always.nop(a, r1, ra4, nop) ; nop = nop.never(r0, r0) ; "
"sig_small_imm ; r1.nop = fsub.always.nop(b, r0, nop, 0x40000000) ; nop = nop.never(r0, r0) ; "
"sig_none ; r2.nop = fadd.ws.always.nop(a, b, ra2, uni) ; rx6 = fmul.always(r4, r1) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r0 = fmul.always(r2, a) ; "
"sig_none ; r3.nop = fadd.always.nop(r3, b, ra6, uni) ; r1 = fmul.always(r0, a) ; "
"sig_none ; rx0.16a = ftoi.always.nop(r1, r1, uni, nop) ; r2 = fmul.always(r3, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra6, nop) ; r3 = fmul.always(r2, a) ; "
"sig_none ; rx0.16b = ftoi.always.nop(r3, r3, vpm_read, nop) ; r0 = v8min.always(a, a) ; "
"sig_none ; r3.nop = fadd.always.nop(b, a, uni, rb5) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = or.always.nop(a, a, ra0, uni) ; r2 = fmul.always(r3, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra6, nop) ; r3 = fmul.always(r2, a) ; "
"sig_none ; vpm.nop = fadd.always.nop(r3, b, vpm_read, uni) ; r1 = v8min.always(a, a) ; "
"sig_none ; vpm.nop = or.always.nop(a, a, ra6, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = fmax.always.8a(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = fmax.always.8b(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = fmax.always.8c(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = fmax.always.8d(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r2.nop = or.always.nop(a, a, vpm_read, nop) ; vpm = v8min.always(r0, r0) ; "
"sig_none ; r3.nop = or.always.nop(a, a, vpm_read, nop) ; vpm = v8min.always(r1, r1) ; "
"sig_none ; vpm.nop = or.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = or.always.nop(r3, r3, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;

char multiTextureCS_str[] =
"sig_load_imm ; vr_setup.nop = load32.always(0x301a00) ; nop = load32.always() ;"
"sig_none ; rx2.nop = or.always.nop(a, a, vpm_read, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx2.nop = or.ws.always.nop(a, a, vpm_read, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra2, uni) ; r1 = fmul.always(b, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r0 = fmul.always(a, b) ; "
"sig_none ; rx4.nop = fadd.always.nop(r1, r0, ra2, uni) ; r2 = fmul.always(b, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r3 = fmul.always(a, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r1 = fmul.always(a, b) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r2, r1, ra2, uni) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx3.nop = fadd.always.nop(r0, r3, uni, rb2) ; r2 = fmul.always(a, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra2, uni) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r3, r2, vpm_read, nop) ; r2 = v8min.always(a, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r0 = fmul.always(a, r2) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(a, r0, ra4, uni) ; r3 = fmul.always(b, r2) ; "
"sig_none ; r0.nop = fadd.always.nop(a, r3, ra3, uni) ; r1 = fmul.always(b, r2) ; "
"sig_none ; rx4.nop = fadd.ws.always.nop(b, a, uni, rb0) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3.nop = fadd.always.nop(b, r1, uni, rb1) ; r2 = fmul.always(a, r2) ; "
"sig_load_imm ; vw_setup = load32.ws.always(0x1a00) ; nop = load32.always() ;"
"sig_none ; r1.nop = fadd.always.nop(a, r2, ra1, rb4) ; vpm = v8min.always(b, b) ; "
"sig_none ; r0.nop = fadd.always.nop(r0, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r2.nop = fadd.ws.always.nop(r3, a, uni, nop) ; sfu_recip = v8min.always(r0, r0) ; "
"sig_none ; rx5.nop = fadd.always.nop(r1, a, uni, nop) ; vpm = v8min.always(r2, r2) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r3 = fmul.always(r2, a) ; "
"sig_none ; vpm.nop = or.always.nop(a, a, ra5, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = or.always.nop(r0, r0, nop, nop) ; r0 = fmul.always(r0, r4) ; "
"sig_small_imm ; r1.nop = fsub.always.nop(b, r0, nop, 0x40000000) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; rx3 = fmul.always(r4, r1) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb4) ; r1 = fmul.always(b, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, rb3) ; r2 = fmul.always(r1, b) ; "
"sig_none ; rx0.16a = ftoi.always.nop(r2, r2, nop, rb3) ; r0 = fmul.always(r3, b) ; "
"sig_none ; rx0.16b = ftoi.always.nop(r0, r0, ra5, uni) ; r2 = fmul.always(a, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, rb3) ; r3 = fmul.always(r2, b) ; "
"sig_none ; vpm.nop = or.always.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = fadd.always.nop(r3, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = or.always.nop(b, b, nop, rb3) ; nop = nop.never(r0, r0) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;           

char multiTextureClippingPlaneVS_str[] =
"sig_load_imm ; vr_setup.nop = load32.always(0x801a00) ; nop = load32.always() ;"
"sig_none ; rx8.nop = or.ws.always.nop(a, a, vpm_read, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx9.nop = or.always.nop(a, a, vpm_read, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb8) ; r2 = fmul.always(b, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb8) ; r0 = fmul.always(b, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra9, uni) ; r3 = fmul.always(a, b) ; "
"sig_none ; rx10.nop = fadd.always.nop(r2, r3, ra9, uni) ; r1 = fmul.always(a, b) ; "
"sig_none ; rx9.nop = fadd.ws.always.nop(r0, r1, ra9, uni) ; r3 = fmul.always(b, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb8) ; r1 = fmul.always(a, b) ; "
"sig_none ; rx8.nop = fadd.always.nop(r1, r3, uni, rb8) ; r0 = fmul.always(b, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra9, uni) ; r1 = fmul.always(a, b) ; "
"sig_none ; rx7.nop = fadd.ws.always.nop(r0, r1, uni, rb8) ; r2 = fmul.always(a, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra9, uni) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx6.nop = fadd.ws.always.nop(r2, r0, uni, rb8) ; r3 = fmul.always(a, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra9, uni) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx5.nop = fadd.ws.always.nop(r3, r1, ra9, uni) ; r2 = fmul.always(b, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb8) ; r0 = fmul.always(a, b) ; "
"sig_none ; rx5.nop = fadd.always.nop(r0, r2, vpm_read, nop) ; rx2 = v8min.always(a, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb8) ; r1 = fmul.always(b, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra9, uni) ; r0 = fmul.always(a, b) ; "
"sig_none ; rx4.nop = fadd.ws.always.nop(r1, r0, uni, rb2) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(b, r2, vpm_read, rb9) ; rx1 = v8min.always(a, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r1 = fmul.always(a, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx6.nop = fadd.always.nop(b, r1, nop, rb5) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx4.nop = fadd.always.nop(b, r2, nop, rb7) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r3 = fmul.always(a, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r0 = fmul.always(b, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r1 = fmul.always(b, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r2 = fmul.always(a, b) ; "
"sig_none ; rx3.nop = fadd.ws.always.nop(a, r3, ra8, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx3.nop = fadd.always.nop(a, r0, ra10, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx11.nop = fadd.ws.always.nop(b, r1, nop, rb4) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx10.nop = fadd.ws.always.nop(a, r2, ra5, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3.nop = fadd.always.nop(a, b, ra3, uni) ; nop = nop.never(r0, r0) ; "
"sig_none ; r1.nop = fadd.always.nop(b, a, uni, rb1) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r2 = fmul.always(a, r3) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r0 = fmul.always(a, b) ; "
"sig_none ; rx7.nop = fadd.always.nop(b, r0, uni, rb6) ; r3 = fmul.always(a, r1) ; "
"sig_none ; r2.nop = fadd.always.nop(r3, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r1.nop = fadd.always.nop(b, a, uni, rb3) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3.nop = fadd.ws.always.nop(a, b, ra4, uni) ; sfu_recip = v8min.always(r1, r1) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r0 = fmul.always(a, r3) ; "
"sig_none ; rx11.nop = fadd.always.nop(r2, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; r2 = fmul.always(r1, r4) ; "
"sig_small_imm ; r3.nop = fsub.always.nop(b, r2, nop, 0x40000000) ; nop = nop.never(r0, r0) ; "
"sig_none ; r2.nop = fadd.ws.always.nop(a, b, ra7, uni) ; rx2 = fmul.always(r4, r3) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r0 = fmul.always(r2, a) ; "
"sig_none ; r3.nop = fadd.always.nop(a, b, ra6, uni) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra2, nop) ; r1 = fmul.always(r0, a) ; "
"sig_none ; rx0.16a = ftoi.always.nop(r1, r1, uni, nop) ; r2 = fmul.always(r3, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra2, nop) ; r3 = fmul.always(r2, a) ; "
"sig_none ; r0.nop = fadd.always.nop(b, a, uni, rb10) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx0.16b = ftoi.always.nop(r3, r3, uni, nop) ; r0 = fmul.always(r0, a) ; "
"sig_load_imm ; vw_setup = load32.ws.always(0x1a00) ; nop = load32.always() ;"
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra2, nop) ; r1 = fmul.always(r0, a) ; "
"sig_none ; vpm.nop = or.always.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = fadd.always.nop(r1, b, vpm_read, uni) ; r0 = v8min.always(a, a) ; "
"sig_none ; vpm.nop = or.always.nop(a, a, ra2, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = fmax.always.8a(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = fmax.always.8b(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = fmax.always.8c(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = fmax.always.8d(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = or.always.nop(r0, r0, vpm_read, nop) ; r1 = v8min.always(a, a) ; "
"sig_none ; vpm.nop = or.always.nop(r1, r1, vpm_read, nop) ; r2 = v8min.always(a, a) ; "
"sig_none ; r3.nop = or.always.nop(a, a, vpm_read, nop) ; vpm = v8min.always(r2, r2) ; "
"sig_none ; r2.nop = fadd.always.nop(b, a, uni, rb11) ; vpm = v8min.always(r3, r3) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r1 = fmul.always(a, r2) ; "
"sig_none ; vpm.nop = fadd.always.nop(a, r1, ra11, nop) ; nop = nop.never(r0, r0) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;

char multiTextureClippingPlaneCS_str[] =
"sig_load_imm ; vr_setup.nop = load32.always(0x301a00) ; nop = load32.always() ;"
"sig_none ; rx2.nop = or.always.nop(a, a, vpm_read, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx2.nop = or.ws.always.nop(a, a, vpm_read, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra2, uni) ; r1 = fmul.always(b, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r0 = fmul.always(a, b) ; "
"sig_none ; rx4.nop = fadd.always.nop(r1, r0, ra2, uni) ; r2 = fmul.always(b, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r3 = fmul.always(a, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r1 = fmul.always(a, b) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r2, r1, ra2, uni) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx3.nop = fadd.always.nop(r0, r3, uni, rb2) ; r2 = fmul.always(a, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra2, uni) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r3, r2, vpm_read, nop) ; r2 = v8min.always(a, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r0 = fmul.always(a, r2) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(a, r0, ra4, uni) ; r3 = fmul.always(b, r2) ; "
"sig_none ; r0.nop = fadd.always.nop(a, r3, ra3, uni) ; r1 = fmul.always(b, r2) ; "
"sig_none ; rx4.nop = fadd.ws.always.nop(b, a, uni, rb0) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3.nop = fadd.always.nop(b, r1, uni, rb1) ; r2 = fmul.always(a, r2) ; "
"sig_load_imm ; vw_setup = load32.ws.always(0x1a00) ; nop = load32.always() ;"
"sig_none ; r1.nop = fadd.always.nop(a, r2, ra1, rb4) ; vpm = v8min.always(b, b) ; "
"sig_none ; r0.nop = fadd.always.nop(r0, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r2.nop = fadd.ws.always.nop(r3, a, uni, nop) ; sfu_recip = v8min.always(r0, r0) ; "
"sig_none ; rx5.nop = fadd.always.nop(r1, a, uni, nop) ; vpm = v8min.always(r2, r2) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r3 = fmul.always(r2, a) ; "
"sig_none ; vpm.nop = or.always.nop(a, a, ra5, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = or.always.nop(r0, r0, nop, nop) ; r0 = fmul.always(r0, r4) ; "
"sig_small_imm ; r1.nop = fsub.always.nop(b, r0, nop, 0x40000000) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; rx3 = fmul.always(r4, r1) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb4) ; r1 = fmul.always(b, a) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, rb3) ; r2 = fmul.always(r1, b) ; "
"sig_none ; rx0.16a = ftoi.always.nop(r2, r2, nop, rb3) ; r0 = fmul.always(r3, b) ; "
"sig_none ; rx0.16b = ftoi.always.nop(r0, r0, ra5, uni) ; r2 = fmul.always(a, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, rb3) ; r3 = fmul.always(r2, b) ; "
"sig_none ; vpm.nop = or.always.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = fadd.always.nop(r3, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; vpm.nop = or.always.nop(b, b, nop, rb3) ; nop = nop.never(r0, r0) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;

//======================================================================
//======================================================================
//======================================================================
//======================================================================
//======================================================================
//======================================================================

VkRpiAssemblyMappingEXT singleTexture_DepthStencilEnabled_FS_mapping[] = {
	{ //tex0
		VK_RPI_ASSEMBLY_MAPPING_TYPE_DESCRIPTOR,
		VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		0, //resource offset
	},
	{ //stencil setup
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		0, //resource offset
	},
};

VkRpiAssemblyMappingEXT singleTexture_DepthStencilDisabled_FS_mapping[] = {
	{ //tex0
		VK_RPI_ASSEMBLY_MAPPING_TYPE_DESCRIPTOR,
		VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		0, //resource offset
	},
};

VkRpiAssemblyMappingEXT multiTexture_DepthStencilEnabled_FS_mapping[] = {
	{ //tex0
		VK_RPI_ASSEMBLY_MAPPING_TYPE_DESCRIPTOR,
		VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		0, //resource offset
	},
	{ //tex1
		VK_RPI_ASSEMBLY_MAPPING_TYPE_DESCRIPTOR,
		VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, //descriptor type
		1, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		0, //resource offset
	},
	{ //stencil setup
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		0, //resource offset
	},
};

VkRpiAssemblyMappingEXT multiTexture_DepthStencilDisabled_FS_mapping[] = {
	{ //tex0
		VK_RPI_ASSEMBLY_MAPPING_TYPE_DESCRIPTOR,
		VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		0, //resource offset
	},
	{ //tex1
		VK_RPI_ASSEMBLY_MAPPING_TYPE_DESCRIPTOR,
		VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, //descriptor type
		1, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		0, //resource offset
	},
};

char singleTexture_AlphaDisabled_BlendDisabled_DepthStencilEnabled_FS_str[] =
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_last_thread_switch ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.ws.always.nop(r3, r3, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r0 = fmax.pm.always.8b(r4, r4, ra0, nop) ; r3.8c = fmul.always(a, r3) ; "
"sig_none ; r1 = fmax.pm.always.8c(r4, r4, nop, rb0) ; r3.8b = fmul.always(b, r0) ; "
"sig_none ; r2 = fmax.pm.always.8d(r4, r4, ra1, nop) ; r3.8a = fmul.always(a, r1) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, rb1) ; r3.8d = fmul.always(b, r2) ; "
"sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_color_all.nop = or.always.nop(r3, r3, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;

char singleTexture_AlphaDisabled_DstZero_SrcDstColor_DepthStencilEnabled_FS_str[] =
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_last_thread_switch ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.ws.always.nop(r3, r3, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r0 = fmax.pm.always.8b(r4, r4, ra0, nop) ; r3.8c = fmul.always(a, r3) ; "
"sig_none ; r1 = fmax.pm.always.8c(r4, r4, nop, rb0) ; r3.8b = fmul.always(b, r0) ; "
"sig_none ; r2 = fmax.pm.always.8d(r4, r4, ra1, nop) ; r3.8a = fmul.always(a, r1) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, rb1) ; r3.8d = fmul.always(b, r2) ; "
"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.ws.never.nop(r0, r0, nop, nop) ; tlb_color_all = v8muld.always(r3, r4) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;

char singleTexture_AlphaDisabled_DstOneMinusSrcAlpha_SrcSrcAlpha_DepthStencilEnabled_FS_str[] =
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx2.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_last_thread_switch ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.ws.always.nop(r3, r3, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r0 = fmax.ws.pm.always.8b(r4, r4, ra1, nop) ; rx0.8c = fmul.always(a, r3) ; "
"sig_none ; r1 = fmax.ws.pm.always.8c(r4, r4, nop, rb1) ; rx0.8b = fmul.always(b, r0) ; "
"sig_none ; nop = nop.ws.pm.never.nop(r0, r0, ra2, nop) ; rx0.8a = fmul.always(a, r1) ; "
"sig_none ; nop = nop.pm.never.8d(r0, r0, nop, rb0) ; r2.nop = fmul.always(b, r4) ; "
"sig_none ; nop = nop.ws.pm.never.nop(r0, r0, nop, nop) ; rx0.8d = v8min.always(r2, r2) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r3.8888 = v8min.always(r2, r2) ; "
"sig_none ; r0.nop = not.always.nop(r3, r3, ra0, nop) ; r1 = v8muld.always(a, r3) ; "
"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; r0 = v8muld.always(r4, r0) ; "
"sig_none ; nop.nop = nop.ws.never.nop(r0, r0, nop, nop) ; tlb_color_all = v8adds.always(r1, r0) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;

char singleTexture_AlphaDisabled_DstOne_SrcDstColor_DepthStencilEnabled_FS_str[] =
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_last_thread_switch ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.ws.always.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r0 = fmax.pm.always.8b(r4, r4, ra0, nop) ; r3.8c = fmul.always(a, r3) ; "
"sig_none ; r1 = fmax.pm.always.8c(r4, r4, nop, rb0) ; r3.8b = fmul.always(b, r0) ; "
"sig_none ; r2 = fmax.pm.always.8d(r4, r4, ra1, nop) ; r3.8a = fmul.always(a, r1) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, rb1) ; r3.8d = fmul.always(b, r2) ; "
"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; r3 = v8muld.always(r3, r4) ; "
"sig_none ; nop.nop = nop.ws.never.nop(r0, r0, nop, nop) ; tlb_color_all = v8adds.always(r3, r4) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;

char singleTexture_AlphaDisabled_DstOne_SrcOne_DepthStencilEnabled_FS_str[] =
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_last_thread_switch ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.ws.always.nop(r3, r3, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r0 = fmax.pm.always.8b(r4, r4, ra0, nop) ; r3.8c = fmul.always(a, r3) ; "
"sig_none ; r1 = fmax.pm.always.8c(r4, r4, nop, rb0) ; r3.8b = fmul.always(b, r0) ; "
"sig_none ; r2 = fmax.pm.always.8d(r4, r4, ra1, nop) ; r3.8a = fmul.always(a, r1) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, rb1) ; r3.8d = fmul.always(b, r2) ; "
"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.ws.never.nop(r0, r0, nop, nop) ; tlb_color_all = v8adds.always(r3, r4) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;

char singleTexture_AlphaDisabled_DstOneMinusSrcAlpha_SrcSrcAlpha_DepthStencilDisabled_FS_str[] =
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_last_thread_switch ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.ws.always.nop(r3, r3, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r0 = fmax.pm.always.8b(r4, r4, nop, rb0) ; r2.8c = fmul.always(b, r3) ; "
"sig_none ; r1 = fmax.pm.always.8c(r4, r4, ra1, nop) ; r2.8b = fmul.always(a, r0) ; "
"sig_none ; nop = nop.pm.never.8d(r0, r0, ra0, nop) ; r3.nop = fmul.always(a, r4) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, rb1) ; r2.8a = fmul.always(b, r1) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r0.8888 = v8min.always(r3, r3) ; "
"sig_none ; r1 = not.pm.always.nop(r0, r0, nop, nop) ; r2.8d = v8min.always(r3, r3) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; r3 = v8muld.always(r2, r0) ; "
"sig_color_load ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; r2 = v8muld.always(r4, r1) ; "
"sig_none ; nop.nop = nop.ws.never.nop(r0, r0, nop, nop) ; tlb_color_all = v8adds.always(r3, r2) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;

char singleTextureClippingPlane_AlphaDisabled_BlendDisabled_DepthStencilEnabled_FS_str[] =
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx2.nop = fadd.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.always.nop(r3, r3, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_small_imm ; rx0.nop = or.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
"sig_last_thread_switch ; r0.nop = fadd.always.nop(r3, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = fmax.always.sf.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_small_imm ; rx0.nop = or.ns.nop(b, b, nop, -1) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r1 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r2 = fmax.pm.always.8b(r4, r4, nop, rb0) ; r1.8c = fmul.always(b, r1) ; "
"sig_none ; r3 = fmax.pm.always.8c(r4, r4, ra1, nop) ; r1.8b = fmul.always(a, r2) ; "
"sig_none ; nop.nop = or.always.sf.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r0 = fmax.pm.always.8d(r4, r4, nop, rb1) ; r1.8a = fmul.always(b, r3) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, ra2, nop) ; r1.8d = fmul.always(a, r0) ; "
"sig_none ; tlb_z.nop = or.zs.nop(b, b, nop, pay_zw) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_color_all.nop = or.zs.nop(r1, r1, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;

char singleTexture_AlphaDisabled_BlendDisabled_DepthStencilDisabled_FS_str[] =
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_last_thread_switch ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.ws.always.nop(r3, r3, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r0 = fmax.pm.always.8b(r4, r4, ra0, nop) ; r3.8c = fmul.always(a, r3) ; "
"sig_none ; r1 = fmax.pm.always.8c(r4, r4, nop, rb0) ; r3.8b = fmul.always(b, r0) ; "
"sig_none ; r2 = fmax.pm.always.8d(r4, r4, ra1, nop) ; r3.8a = fmul.always(a, r1) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, rb1) ; r3.8d = fmul.always(b, r2) ; "
"sig_none ; tlb_color_all.nop = or.always.nop(r3, r3, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;

char singleTextureClippingPlane_AlphaDisabled_BlendDisabled_DepthStencilDisabled_FS_str[] =
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx2.nop = fadd.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.always.nop(r3, r3, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_small_imm ; rx0.nop = or.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
"sig_last_thread_switch ; r0.nop = fadd.always.nop(r3, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = fmax.always.sf.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_small_imm ; rx0.nop = or.ns.nop(b, b, nop, -1) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r1 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r2 = fmax.pm.always.8b(r4, r4, nop, rb0) ; r1.8c = fmul.always(b, r1) ; "
"sig_none ; r3 = fmax.pm.always.8c(r4, r4, ra1, nop) ; r1.8b = fmul.always(a, r2) ; "
"sig_none ; r0 = fmax.pm.always.8d(r4, r4, nop, rb1) ; r1.8a = fmul.always(b, r3) ; "
"sig_none ; nop.nop = or.always.sf.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, ra2, nop) ; r1.8d = fmul.always(a, r0) ; "
"sig_none ; tlb_color_all.nop = or.zs.nop(r1, r1, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;

char singleTextureClippingPlane_AlphaDisabled_DstOneMinusSrcAlpha_SrcSrcAlpha_DepthStencilEnabled_FS_str[] =
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx2.nop = fadd.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; r2.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r0.nop = fadd.always.nop(r3, r5, nop, nop) ; tmu0_s = v8min.always(r0, r0) ; "
"sig_small_imm ; rx0.nop = or.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
"sig_last_thread_switch ; nop.nop = fmax.always.sf.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_small_imm ; rx0.nop = or.ns.nop(b, b, nop, -1) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = or.always.sf.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r1 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r2 = fmax.pm.always.8b(r4, r4, nop, rb0) ; r0.8c = fmul.always(b, r1) ; "
"sig_none ; r3 = fmax.pm.always.8c(r4, r4, ra1, nop) ; r0.8b = fmul.always(a, r2) ; "
"sig_none ; nop = nop.pm.never.8d(r0, r0, ra2, nop) ; r1.nop = fmul.always(a, r4) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, rb1) ; r0.8a = fmul.always(b, r3) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r2.8888 = v8min.always(r1, r1) ; "
"sig_none ; r3 = not.pm.always.nop(r2, r2, nop, nop) ; r0.8d = v8min.always(r1, r1) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; r1 = v8muld.always(r0, r2) ; "
"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_z.nop = or.zs.nop(b, b, nop, pay_zw) ; r0 = v8muld.always(r4, r3) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; r2 = v8adds.always(r1, r0) ; "
"sig_none ; tlb_color_all.nop = or.zs.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;

char singleTextureClippingPlane_AlphaDisabled_DstOne_SrcOne_DepthStencilEnabled_FS_str[] =
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx2.nop = fadd.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.always.nop(r3, r3, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_small_imm ; rx0.nop = or.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
"sig_last_thread_switch ; r0.nop = fadd.always.nop(r3, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = fmax.always.sf.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_small_imm ; rx0.nop = or.ns.nop(b, b, nop, -1) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r1 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r2 = fmax.pm.always.8b(r4, r4, nop, rb0) ; r1.8c = fmul.always(b, r1) ; "
"sig_none ; r3 = fmax.pm.always.8c(r4, r4, ra1, nop) ; r1.8b = fmul.always(a, r2) ; "
"sig_none ; r0 = fmax.pm.always.8d(r4, r4, nop, rb1) ; r1.8a = fmul.always(b, r3) ; "
"sig_none ; nop.nop = or.always.sf.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, ra2, nop) ; r1.8d = fmul.always(a, r0) ; "
"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_z.nop = or.zs.nop(b, b, nop, pay_zw) ; r0 = v8adds.always(r1, r4) ; "
"sig_none ; tlb_color_all.nop = or.zs.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;

char singleTextureClippingPlane_AlphaDisabled_DstOneMinusSrcAlpha_SrcSrcAlpha_DepthStencilDisabled_FS_str[] =
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx2.nop = fadd.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.always.nop(r3, r3, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_small_imm ; rx0.nop = or.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
"sig_last_thread_switch ; r0.nop = fadd.always.nop(r3, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = fmax.always.sf.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_small_imm ; rx0.nop = or.ns.nop(b, b, nop, -1) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r1 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r2 = fmax.pm.always.8b(r4, r4, nop, rb0) ; r0.8c = fmul.always(b, r1) ; "
"sig_none ; r3 = fmax.pm.always.8c(r4, r4, ra1, nop) ; r0.8b = fmul.always(a, r2) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, rb1) ; r0.8a = fmul.always(b, r3) ; "
"sig_none ; nop = nop.pm.never.8d(r0, r0, ra2, nop) ; r2.nop = fmul.always(a, r4) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r0.8d = v8min.always(r2, r2) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r3.8888 = v8min.always(r2, r2) ; "
"sig_none ; r0.nop = not.always.nop(r3, r3, nop, nop) ; r1 = v8muld.always(r0, r3) ; "
"sig_none ; nop.nop = or.always.sf.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
"sig_color_load ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; r0 = v8muld.always(r4, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; r1 = v8adds.always(r1, r0) ; "
"sig_none ; tlb_color_all.nop = or.zs.nop(r1, r1, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
;

char singleTexture_AlphaDisabled_DstSrcColor_SrcDstColor_DepthStencilEnabled_FS_str[] =
{
	"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; rx0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; rx0.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_last_thread_switch ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_s.nop = or.ws.always.nop(r3, r3, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r3 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
	"sig_none ; r0 = fmax.pm.always.8b(r4, r4, ra0, nop) ; r3.8c = fmul.always(a, r3) ; "
	"sig_none ; r1 = fmax.pm.always.8c(r4, r4, nop, rb0) ; r3.8b = fmul.always(b, r0) ; "
	"sig_none ; r2 = fmax.pm.always.8d(r4, r4, ra1, nop) ; r3.8a = fmul.always(a, r1) ; "
	"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, rb1) ; r3.8d = fmul.always(b, r2) ; "
	"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; r0 = v8muld.always(r3, r4) ; "
	"sig_none ; nop.nop = nop.ws.never.nop(r0, r0, nop, nop) ; tlb_color_all = v8adds.always(r0, r0) ; "
	"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char singleTextureClippingPlane_AlphaDisabled_DstSrcColor_SrcDstColor_DepthStencilEnabled_FS_str[] =
{
	"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; rx0.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.ws.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_none ; rx2.nop = fadd.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_s.nop = or.always.nop(r3, r3, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_small_imm ; rx0.nop = or.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
	"sig_last_thread_switch ; r0.nop = fadd.always.nop(r3, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = fmax.always.sf.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_small_imm ; rx0.nop = or.ns.nop(b, b, nop, -1) ; nop = nop.never(r0, r0) ; "
	"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r1 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
	"sig_none ; r2 = fmax.pm.always.8b(r4, r4, nop, rb0) ; r1.8c = fmul.always(b, r1) ; "
	"sig_none ; r3 = fmax.pm.always.8c(r4, r4, ra1, nop) ; r1.8b = fmul.always(a, r2) ; "
	"sig_none ; r0 = fmax.pm.always.8d(r4, r4, nop, rb1) ; r1.8a = fmul.always(b, r3) ; "
	"sig_none ; nop = nop.pm.never.nop(r0, r0, ra2, nop) ; r1.8d = fmul.always(a, r0) ; "
	"sig_none ; nop.nop = or.always.sf.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
	"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tlb_z.nop = or.zs.nop(b, b, nop, pay_zw) ; r1 = v8muld.always(r1, r4) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; r2 = v8adds.always(r1, r1) ; "
	"sig_none ; tlb_color_all.nop = or.zs.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char multiTextureMul_AlphaDisabled_BlendDisabled_DepthStencilEnabled_FS_str[] =
{
	"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; rx3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; rx3.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
	"sig_none ; rx4.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_none ; rx4.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; r0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; r2.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_thread_switch ; rx1.nop = fadd.always.nop(r3, r5, nop, nop) ; tmu0_t = v8min.always(r2, r2) ; "
	"sig_none ; tmu0_s.nop = or.always.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; rx0.nop = fadd.always.nop(r0, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; rx14.nop = fmax.ws.always.nop(a, a, ra3, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_t.nop = or.ws.always.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
	"sig_last_thread_switch ; tmu0_s.nop = or.ws.always.nop(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "
	"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; rx2.nop = or.always.nop(r4, r4, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_load_tmu0 ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.8a(r0, r0, ra2, rb14) ; rx0 = fmul.always(b, a) ; "
	"sig_none ; r1 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
	"sig_none ; r2 = fmax.pm.always.8b(r4, r4, nop, rb0) ; rx2.8c = fmul.always(b, r1) ; "
	"sig_none ; nop.nop = nop.never.8b(r0, r0, ra2, rb3) ; r1 = fmul.always(b, a) ; "
	"sig_none ; rx14.nop = fmax.ws.always.nop(a, a, ra4, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r3 = fmax.pm.always.8c(r4, r4, nop, nop) ; rx2.8b = fmul.always(r1, r2) ; "
	"sig_none ; nop.nop = nop.never.8c(r0, r0, ra2, rb14) ; r2 = fmul.always(b, a) ; "
	"sig_none ; r0 = fmax.pm.always.8d(r4, r4, nop, nop) ; rx2.8a = fmul.always(r2, r3) ; "
	"sig_none ; nop.nop = nop.never.8d(r0, r0, ra2, rb4) ; r3 = fmul.always(b, a) ; "
	"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; rx2.8d = fmul.always(r3, r0) ; "
	"sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tlb_color_all.nop = or.always.nop(b, b, nop, rb2) ; nop = nop.never(r0, r0) ; "
	"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char multiTextureMulClippingPlane_AlphaDisabled_BlendDisabled_DepthStencilEnabled_FS_str[] =
{
	"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; rx3.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; rx4.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
	"sig_none ; rx4.nop = fadd.ws.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_none ; rx5.nop = fadd.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; rx14.nop = fmax.ws.always.nop(a, a, ra4, nop) ; tmu0_t = v8min.always(r2, r2) ; "
	"sig_none ; tmu0_s.nop = or.always.nop(r3, r3, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; rx0.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_small_imm ; rx3.nop = or.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
	"sig_thread_switch ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = fmax.always.sf.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_small_imm ; rx3.nop = or.ns.nop(b, b, nop, -1) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_t.nop = or.ws.always.nop(b, b, nop, rb0) ; nop = nop.never(r0, r0) ; "
	"sig_last_thread_switch ; tmu0_s.nop = or.ws.always.nop(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "
	"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; rx2.nop = or.always.nop(r4, r4, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = or.always.sf.nop(a, a, ra3, nop) ; nop = nop.never(r0, r0) ; "
	"sig_load_tmu0 ; nop.nop = nop.ws.never.8a(r0, r0, ra2, rb3) ; rx0 = fmul.always(b, a) ; "
	"sig_none ; r3 = fmax.ws.pm.always.8a(r4, r4, uni, nop) ; tlb_stencil_setup.nop = v8min.always(a, a) ; "
	"sig_none ; r0 = fmax.pm.always.8b(r4, r4, ra0, nop) ; rx2.8c = fmul.always(a, r3) ; "
	"sig_none ; nop.nop = nop.never.8b(r0, r0, ra2, rb14) ; r3 = fmul.always(b, a) ; "
	"sig_none ; r1 = fmax.pm.always.8c(r4, r4, nop, nop) ; rx2.8b = fmul.always(r3, r0) ; "
	"sig_none ; nop.nop = nop.never.8c(r0, r0, ra2, rb4) ; r0 = fmul.always(b, a) ; "
	"sig_none ; rx14.nop = fmax.ws.always.nop(a, a, ra5, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r2 = fmax.pm.always.8d(r4, r4, nop, nop) ; rx2.8a = fmul.always(r0, r1) ; "
	"sig_none ; nop.nop = nop.never.8d(r0, r0, ra2, rb14) ; r1 = fmul.always(b, a) ; "
	"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; rx2.8d = fmul.always(r1, r2) ; "
	"sig_none ; tlb_z.nop = or.zs.nop(b, b, nop, pay_zw) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tlb_color_all.nop = or.zs.nop(b, b, nop, rb2) ; nop = nop.never(r0, r0) ; "
	"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char singleTextureClippingPlane_AlphaDisabled_DstZero_SrcDstColor_DepthStencilEnabled_FS[] =
{
	"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; rx0.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.ws.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_none ; rx2.nop = fadd.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_s.nop = or.always.nop(r3, r3, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_small_imm ; rx0.nop = or.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
	"sig_last_thread_switch ; r0.nop = fadd.always.nop(r3, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = fmax.always.sf.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_small_imm ; rx0.nop = or.ns.nop(b, b, nop, -1) ; nop = nop.never(r0, r0) ; "
	"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r1 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
	"sig_none ; r2 = fmax.pm.always.8b(r4, r4, nop, rb0) ; r1.8c = fmul.always(b, r1) ; "
	"sig_none ; r3 = fmax.pm.always.8c(r4, r4, ra1, nop) ; r1.8b = fmul.always(a, r2) ; "
	"sig_none ; r0 = fmax.pm.always.8d(r4, r4, nop, rb1) ; r1.8a = fmul.always(b, r3) ; "
	"sig_none ; nop.nop = or.always.sf.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop = nop.pm.never.nop(r0, r0, ra2, nop) ; r1.8d = fmul.always(a, r0) ; "
	"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tlb_z.nop = or.zs.nop(b, b, nop, pay_zw) ; r0 = v8muld.always(r1, r4) ; "
	"sig_none ; tlb_color_all.nop = or.zs.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char singleTexture_AlphaDisabled_DstSrcAlpha_SrcDstColor_DepthStencilEnabled_FS[] =
{
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx2.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_last_thread_switch ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.ws.always.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r0 = fmax.ws.pm.always.8b(r4, r4, ra1, nop) ; rx0.8c = fmul.always(a, r3) ; "
"sig_none ; r1 = fmax.ws.pm.always.8c(r4, r4, nop, rb1) ; rx0.8b = fmul.always(b, r0) ; "
"sig_none ; nop = nop.ws.pm.never.nop(r0, r0, ra2, nop) ; rx0.8a = fmul.always(a, r1) ; "
"sig_none ; nop = nop.pm.never.8d(r0, r0, nop, rb0) ; r2.nop = fmul.always(b, r4) ; "
"sig_none ; nop = nop.ws.pm.never.nop(r0, r0, nop, nop) ; rx0.8d = v8min.always(r2, r2) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r3.8888 = v8min.always(r2, r2) ; "
"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; r2 = v8muld.always(r4, r3) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra0, nop) ; r1 = v8muld.always(a, r4) ; "
"sig_none ; nop.nop = nop.ws.never.nop(r0, r0, nop, nop) ; tlb_color_all = v8adds.always(r1, r2) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char singleTextureClippingPlane_AlphaDisabled_DstSrcAlpha_SrcDstColor_DepthStencilEnabled_FS[] =
{
	"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; rx0.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.ws.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_none ; rx2.nop = fadd.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; r0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; r2.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r0.nop = fadd.always.nop(r3, r5, nop, nop) ; tmu0_s = v8min.always(r0, r0) ; "
	"sig_small_imm ; rx0.nop = or.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
	"sig_last_thread_switch ; nop.nop = fmax.always.sf.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_small_imm ; rx0.nop = or.ns.nop(b, b, nop, -1) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = or.always.sf.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
	"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r1 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
	"sig_none ; r2 = fmax.pm.always.8b(r4, r4, nop, rb0) ; r0.8c = fmul.always(b, r1) ; "
	"sig_none ; r3 = fmax.pm.always.8c(r4, r4, ra1, nop) ; r0.8b = fmul.always(a, r2) ; "
	"sig_none ; nop = nop.pm.never.8d(r0, r0, ra2, nop) ; r1.nop = fmul.always(a, r4) ; "
	"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, rb1) ; r0.8a = fmul.always(b, r3) ; "
	"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r2.8888 = v8min.always(r1, r1) ; "
	"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r0.8d = v8min.always(r1, r1) ; "
	"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tlb_z.nop = or.zs.nop(b, b, nop, pay_zw) ; r3 = v8muld.always(r4, r2) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; r0 = v8muld.always(r0, r4) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; r1 = v8adds.always(r0, r3) ; "
	"sig_none ; tlb_color_all.nop = or.zs.nop(r1, r1, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char singleTexture_AlphaDisabled_DstOneMinusDstAlpha_SrcDstColor_DepthStencilEnabled_FS[] =
{
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx2.nop = fadd.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_last_thread_switch ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.ws.always.nop(r3, r3, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r0 = fmax.ws.pm.always.8b(r4, r4, nop, rb0) ; rx0.8c = fmul.always(b, r3) ; "
"sig_none ; r1 = fmax.ws.pm.always.8c(r4, r4, ra1, nop) ; rx0.8b = fmul.always(a, r0) ; "
"sig_none ; r2 = fmax.ws.pm.always.8d(r4, r4, nop, rb1) ; rx0.8a = fmul.always(b, r1) ; "
"sig_none ; nop = nop.ws.pm.never.nop(r0, r0, ra2, nop) ; rx0.8d = fmul.always(a, r2) ; "
"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_imm ; rx3 = load32.always(0x18) ; nop = load32() ;"
"sig_none ; r2.nop = shr.always.nop(r4, a, ra3, pay_zw) ; tlb_z = v8min.always(b, b) ; "
"sig_small_imm ; r3.nop = shl.always.nop(r2, b, nop, 8) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3.nop = or.always.nop(r2, r3, ra0, nop) ; r2 = v8muld.always(a, r4) ; "
"sig_load_imm ; rx3 = load32.always(0x10) ; nop = load32() ;"
"sig_none ; r0.nop = shl.always.nop(r3, a, ra3, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r0.nop = or.always.nop(r3, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r1.nop = not.always.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; r0 = v8muld.always(r4, r1) ; "
"sig_none ; nop.nop = nop.ws.never.nop(r0, r0, nop, nop) ; tlb_color_all = v8adds.always(r2, r0) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char singleTextureClippingPlane_AlphaDisabled_DstOneMinusDstAlpha_SrcDstColor_DepthStencilEnabled_FS[] =
{
	"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
	"sig_none ; rx2.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_none ; rx2.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_s.nop = or.always.nop(r3, r3, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_small_imm ; rx0.nop = or.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
	"sig_last_thread_switch ; r0.nop = fadd.always.nop(r3, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = fmax.always.sf.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_small_imm ; rx0.nop = or.ns.nop(b, b, nop, -1) ; nop = nop.never(r0, r0) ; "
	"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r1 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
	"sig_none ; r2 = fmax.pm.always.8b(r4, r4, ra1, nop) ; rx0.8c = fmul.always(a, r1) ; "
	"sig_none ; r3 = fmax.pm.always.8c(r4, r4, nop, rb1) ; rx0.8b = fmul.always(b, r2) ; "
	"sig_none ; r0 = fmax.pm.always.8d(r4, r4, ra2, nop) ; rx0.8a = fmul.always(a, r3) ; "
	"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, rb2) ; rx0.8d = fmul.always(b, r0) ; "
	"sig_none ; nop.nop = or.always.sf.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
	"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
	"sig_load_imm ; rx3 = load32.always(0x18) ; nop = load32() ;"
	"sig_none ; r2.nop = shr.always.nop(r4, a, ra3, pay_zw) ; tlb_z = v8min.zs(b, b) ; "
	"sig_small_imm ; r1.nop = shl.always.nop(r2, b, nop, 8) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r3.nop = or.always.nop(r2, r1, nop, rb0) ; r1 = v8muld.always(b, r4) ; "
	"sig_load_imm ; rx3 = load32.always(0x10) ; nop = load32() ;"
	"sig_none ; r2.nop = shl.always.nop(r3, a, ra3, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r0.nop = or.always.nop(r3, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r3.nop = not.always.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; r0 = v8muld.always(r4, r3) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; r0 = v8adds.always(r1, r0) ; "
	"sig_none ; tlb_color_all.nop = or.zs.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char singleTextureClippingPlane_AlphaDisabled_DstOne_SrcDstColor_DepthStencilEnabled_FS[] =
{
	"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; rx0.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.ws.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_none ; rx2.nop = fadd.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_s.nop = or.always.nop(r3, r3, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_small_imm ; rx0.nop = or.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
	"sig_last_thread_switch ; r0.nop = fadd.always.nop(r3, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = fmax.always.sf.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_small_imm ; rx0.nop = or.ns.nop(b, b, nop, -1) ; nop = nop.never(r0, r0) ; "
	"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r1 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
	"sig_none ; r2 = fmax.pm.always.8b(r4, r4, nop, rb0) ; r1.8c = fmul.always(b, r1) ; "
	"sig_none ; r3 = fmax.pm.always.8c(r4, r4, ra1, nop) ; r1.8b = fmul.always(a, r2) ; "
	"sig_none ; r0 = fmax.pm.always.8d(r4, r4, nop, rb1) ; r1.8a = fmul.always(b, r3) ; "
	"sig_none ; nop = nop.pm.never.nop(r0, r0, ra2, nop) ; r1.8d = fmul.always(a, r0) ; "
	"sig_none ; nop.nop = or.always.sf.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
	"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tlb_z.nop = or.zs.nop(b, b, nop, pay_zw) ; r1 = v8muld.always(r1, r4) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; r0 = v8adds.always(r1, r4) ; "
	"sig_none ; tlb_color_all.nop = or.zs.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char singleTextureClippingPlane_AlphaDisabled_DstSrcAlpha_SrcOneMinusSrcAlpha_DepthStencilEnabled_FS[] =
{
	"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
	"sig_none ; rx2.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_none ; rx2.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; r0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; r2.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r0.nop = fadd.always.nop(r3, r5, nop, nop) ; tmu0_s = v8min.always(r0, r0) ; "
	"sig_small_imm ; rx0.nop = or.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
	"sig_last_thread_switch ; nop.nop = fmax.always.sf.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_small_imm ; rx0.nop = or.ns.nop(b, b, nop, -1) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = or.always.sf.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
	"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r1 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
	"sig_none ; r2 = fmax.pm.always.8b(r4, r4, ra1, nop) ; rx0.8c = fmul.always(a, r1) ; "
	"sig_none ; r3 = fmax.pm.always.8c(r4, r4, nop, rb1) ; rx0.8b = fmul.always(b, r2) ; "
	"sig_none ; nop = nop.pm.never.nop(r0, r0, ra2, nop) ; rx0.8a = fmul.always(a, r3) ; "
	"sig_none ; nop = nop.pm.never.8d(r0, r0, nop, rb2) ; r2.nop = fmul.always(b, r4) ; "
	"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; rx0.8d = v8min.always(r2, r2) ; "
	"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r1.8888 = v8min.always(r2, r2) ; "
	"sig_none ; r0.nop = not.always.nop(r1, r1, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, rb0) ; r3 = v8muld.always(b, r0) ; "
	"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tlb_z.nop = or.zs.nop(b, b, nop, pay_zw) ; r1 = v8muld.always(r4, r1) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; r2 = v8adds.always(r3, r1) ; "
	"sig_none ; tlb_color_all.nop = or.zs.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char singleTextureClippingPlane_AlphaDisabled_DstOneMinusSrcAlpha_SrcOne_DepthStencilEnabled_FS[] =
{
	"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
	"sig_none ; rx2.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_none ; rx2.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; r0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; r2.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r0.nop = fadd.always.nop(r3, r5, nop, nop) ; tmu0_s = v8min.always(r0, r0) ; "
	"sig_small_imm ; rx0.nop = or.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
	"sig_last_thread_switch ; nop.nop = fmax.always.sf.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_small_imm ; rx0.nop = or.ns.nop(b, b, nop, -1) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = or.always.sf.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
	"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r1 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
	"sig_none ; r2 = fmax.pm.always.8b(r4, r4, ra1, nop) ; rx0.8c = fmul.always(a, r1) ; "
	"sig_none ; r3 = fmax.pm.always.8c(r4, r4, nop, rb1) ; rx0.8b = fmul.always(b, r2) ; "
	"sig_none ; nop = nop.pm.never.8d(r0, r0, nop, rb2) ; r2.nop = fmul.always(b, r4) ; "
	"sig_none ; nop = nop.pm.never.nop(r0, r0, ra2, nop) ; rx0.8a = fmul.always(a, r3) ; "
	"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r0.8888 = v8min.always(r2, r2) ; "
	"sig_none ; r3 = not.pm.always.nop(r0, r0, nop, nop) ; rx0.8d = v8min.always(r2, r2) ; "
	"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tlb_z.nop = or.zs.nop(b, b, nop, pay_zw) ; r1 = v8muld.always(r4, r3) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, rb0) ; r1 = v8adds.always(b, r1) ; "
	"sig_none ; tlb_color_all.nop = or.zs.nop(r1, r1, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char singleTextureClippingPlane_AlphaDisabled_DstOneMinusSrcColor_SrcZero_DepthStencilEnabled_FS[] =
{
	"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; rx0.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.ws.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_none ; rx2.nop = fadd.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_s.nop = or.always.nop(r3, r3, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_small_imm ; rx0.nop = or.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
	"sig_last_thread_switch ; r0.nop = fadd.always.nop(r3, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = fmax.always.sf.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_small_imm ; rx0.nop = or.ns.nop(b, b, nop, -1) ; nop = nop.never(r0, r0) ; "
	"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r1 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
	"sig_none ; r2 = fmax.pm.always.8b(r4, r4, nop, rb0) ; r1.8c = fmul.always(b, r1) ; "
	"sig_none ; r3 = fmax.pm.always.8c(r4, r4, ra1, nop) ; r1.8b = fmul.always(a, r2) ; "
	"sig_none ; r0 = fmax.pm.always.8d(r4, r4, nop, rb1) ; r1.8a = fmul.always(b, r3) ; "
	"sig_none ; nop = nop.pm.never.nop(r0, r0, ra2, nop) ; r1.8d = fmul.always(a, r0) ; "
	"sig_none ; nop.nop = or.always.sf.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r1.nop = not.always.nop(r1, r1, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tlb_z.nop = or.zs.nop(b, b, nop, pay_zw) ; r0 = v8muld.always(r4, r1) ; "
	"sig_none ; tlb_color_all.nop = or.zs.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};


char singleTextureClippingPlane_AlphaDisabled_DstOneMinusSrcColor_SrcOne_DepthStencilEnabled_FS[] =
{
	"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
	"sig_none ; rx2.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_none ; rx2.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_s.nop = or.always.nop(r3, r3, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_small_imm ; rx0.nop = or.ws.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
	"sig_last_thread_switch ; r0.nop = fadd.always.nop(r3, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = fmax.always.sf.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_small_imm ; rx0.nop = or.ws.ns.nop(b, b, nop, -1) ; nop = nop.never(r0, r0) ; "
	"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r1 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
	"sig_none ; r2 = fmax.ws.pm.always.8b(r4, r4, ra1, nop) ; rx0.8c = fmul.always(a, r1) ; "
	"sig_none ; r3 = fmax.ws.pm.always.8c(r4, r4, nop, rb1) ; rx0.8b = fmul.always(b, r2) ; "
	"sig_none ; r0 = fmax.ws.pm.always.8d(r4, r4, ra2, nop) ; rx0.8a = fmul.always(a, r3) ; "
	"sig_none ; nop = nop.ws.pm.never.nop(r0, r0, nop, rb2) ; rx0.8d = fmul.always(b, r0) ; "
	"sig_none ; nop.nop = or.always.sf.nop(b, b, nop, rb0) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r2.nop = not.always.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
	"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tlb_z.nop = or.zs.nop(b, b, nop, pay_zw) ; r1 = v8muld.always(r4, r2) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, ra0, nop) ; r0 = v8adds.always(a, r1) ; "
	"sig_none ; tlb_color_all.nop = or.zs.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char singleTexture_AlphaDisabled_DstSrcAlpha_SrcOneMinusSrcAlpha_DepthStencilEnabled_FS[] =
{
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx2.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_last_thread_switch ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.ws.always.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r0 = fmax.ws.pm.always.8b(r4, r4, ra1, nop) ; rx0.8c = fmul.always(a, r3) ; "
"sig_none ; r1 = fmax.ws.pm.always.8c(r4, r4, nop, rb1) ; rx0.8b = fmul.always(b, r0) ; "
"sig_none ; nop = nop.ws.pm.never.nop(r0, r0, ra2, nop) ; rx0.8a = fmul.always(a, r1) ; "
"sig_none ; nop = nop.pm.never.8d(r0, r0, nop, rb0) ; r3.nop = fmul.always(b, r4) ; "
"sig_none ; nop = nop.ws.pm.never.nop(r0, r0, nop, nop) ; rx0.8d = v8min.always(r3, r3) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r1.8888 = v8min.always(r3, r3) ; "
"sig_none ; r2.nop = not.always.nop(r1, r1, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, ra0, nop) ; r3 = v8muld.always(a, r2) ; "
"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; r2 = v8muld.always(r4, r1) ; "
"sig_none ; nop.nop = nop.ws.never.nop(r0, r0, nop, nop) ; tlb_color_all = v8adds.always(r3, r2) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char singleTexture_AlphaDisabled_DstOneMinusSrcAlpha_SrcOne_DepthStencilEnabled_FS[]=
{
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx2.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_last_thread_switch ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.ws.always.nop(r3, r3, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r0 = fmax.ws.pm.always.8b(r4, r4, ra1, nop) ; rx0.8c = fmul.always(a, r3) ; "
"sig_none ; r1 = fmax.ws.pm.always.8c(r4, r4, nop, rb1) ; rx0.8b = fmul.always(b, r0) ; "
"sig_none ; nop = nop.pm.never.8d(r0, r0, nop, rb0) ; r3.nop = fmul.always(b, r4) ; "
"sig_none ; nop = nop.ws.pm.never.nop(r0, r0, ra2, nop) ; rx0.8a = fmul.always(a, r1) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r2.8888 = v8min.always(r3, r3) ; "
"sig_none ; r0 = not.ws.pm.always.nop(r2, r2, nop, nop) ; rx0.8d = v8min.always(r3, r3) ; "
"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; r0 = v8muld.always(r4, r0) ; "
"sig_none ; nop.nop = nop.ws.never.nop(r0, r0, ra0, nop) ; tlb_color_all = v8adds.always(a, r0) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char singleTexture_AlphaDisabled_DstOneMinusSrcColor_SrcZero_DepthStencilEnabled_FS[] =
{
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_last_thread_switch ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.ws.always.nop(r3, r3, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r0 = fmax.pm.always.8b(r4, r4, ra0, nop) ; r3.8c = fmul.always(a, r3) ; "
"sig_none ; r1 = fmax.pm.always.8c(r4, r4, nop, rb0) ; r3.8b = fmul.always(b, r0) ; "
"sig_none ; r2 = fmax.pm.always.8d(r4, r4, ra1, nop) ; r3.8a = fmul.always(a, r1) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, rb1) ; r3.8d = fmul.always(b, r2) ; "
"sig_none ; r0.nop = not.always.nop(r3, r3, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.ws.never.nop(r0, r0, nop, nop) ; tlb_color_all = v8muld.always(r4, r0) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char singleTexture_AlphaDisabled_DstOneMinusSrcColor_SrcOne_DepthStencilEnabled_FS[]=
{
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx2.nop = fadd.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_last_thread_switch ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.ws.always.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r0 = fmax.ws.pm.always.8b(r4, r4, nop, rb0) ; rx0.8c = fmul.always(b, r3) ; "
"sig_none ; r1 = fmax.ws.pm.always.8c(r4, r4, ra1, nop) ; rx0.8b = fmul.always(a, r0) ; "
"sig_none ; r2 = fmax.ws.pm.always.8d(r4, r4, nop, rb1) ; rx0.8a = fmul.always(b, r1) ; "
"sig_none ; nop = nop.ws.pm.never.nop(r0, r0, ra2, nop) ; rx0.8d = fmul.always(a, r2) ; "
"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3.nop = not.always.nop(a, a, ra0, pay_zw) ; tlb_z = v8min.always(b, b) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; r1 = v8muld.always(r4, r3) ; "
"sig_none ; nop.nop = nop.ws.never.nop(r0, r0, ra0, nop) ; tlb_color_all = v8adds.always(a, r1) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char singleTexture_AlphaGE80_BlendDisabled_DepthStencilEnabled_FS[] =
{
	"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; rx0.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
	"sig_none ; rx1.nop = fadd.ws.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	"sig_none ; rx0.nop = fadd.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_last_thread_switch ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_s.nop = or.ws.always.nop(r3, r3, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_small_imm ; r2.nop = or.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
	"sig_load_tmu0 ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; r3 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
	"sig_none ; r0 = fmax.pm.always.8b(r4, r4, nop, rb0) ; r3.8c = fmul.always(b, r3) ; "
	"sig_none ; r1 = fmax.pm.always.8c(r4, r4, ra1, nop) ; r3.8b = fmul.always(a, r0) ; "
	"sig_none ; nop = nop.pm.never.8d(r0, r0, ra0, nop) ; r0.nop = fmul.always(a, r4) ; "
	"sig_none ; nop.nop = fmax.always.sf.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_small_imm ; r2.nop = or.zs.nop(b, b, nop, -1) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, rb1) ; r3.8a = fmul.always(b, r1) ; "
	"sig_none ; nop.nop = or.always.sf.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r3.8d = v8min.always(r0, r0) ; "
	"sig_none ; tlb_z.nop = or.zs.nop(b, b, nop, pay_zw) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tlb_color_all.nop = or.zs.nop(r3, r3, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char singleTextureClippingPlane_AlphaGE80_BlendDisabled_DepthStencilEnabled_FS[] =
{
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx2.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx2.nop = fadd.ws.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.always.nop(r3, r3, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_small_imm ; rx0.nop = or.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
"sig_last_thread_switch ; r0.nop = fadd.always.nop(r3, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = fmax.always.sf.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_small_imm ; rx0.nop = or.ns.nop(b, b, nop, -1) ; nop = nop.never(r0, r0) ; "
"sig_small_imm ; r0.nop = or.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r1 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r2 = fmax.pm.always.8b(r4, r4, nop, rb1) ; rx0.8c = fmul.always(b, r1) ; "
"sig_none ; r3 = fmax.pm.always.8c(r4, r4, ra2, nop) ; rx0.8b = fmul.always(a, r2) ; "
"sig_none ; nop = nop.pm.never.8d(r0, r0, ra1, nop) ; r1.nop = fmul.always(a, r4) ; "
"sig_small_imm ; r2.nop = or.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = fmax.always.sf.nop(r1, r1, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r2 = or.pm.always.nop(a, a, ra0, rb2) ; rx0.8a = fmul.always(b, r3) ; "
"sig_small_imm ; r0.nop = or.zs.nop(b, b, nop, -1) ; nop = nop.never(r0, r0) ; "
"sig_none ; r2 = or.pm.always.nop(a, r0, ra0, nop) ; rx0.8d = v8min.always(r1, r1) ; "
"sig_none ; nop.nop = or.always.sf.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_z.nop = or.zs.nop(b, b, nop, pay_zw) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_color_all.nop = or.zs.nop(b, b, nop, rb0) ; nop = nop.never(r0, r0) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char multiTextureAdd_AlphaDisabled_BlendDisabled_DepthStencilEnabled_FS[] =
{
	"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	 "sig_none ; rx4.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	 "sig_none ; rx4.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
	 "sig_none ; rx3.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	 "sig_none ; rx3.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	 "sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	 "sig_none ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	 "sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
	 "sig_thread_switch ; tmu0_s.nop = or.always.nop(r3, r3, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
	 "sig_none ; rx0.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	 "sig_none ; rx0.nop = fadd.always.nop(r0, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	 "sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	 "sig_none ; tmu0_t.nop = or.ws.always.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
	 "sig_none ; tmu0_s.nop = or.ws.always.nop(b, b, nop, rb0) ; nop = nop.never(r0, r0) ; "
	 "sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	 "sig_none ; nop = nop.ws.pm.never.8c(r0, r0, ra3, nop) ; rx2.nop = fmul.always(a, r4) ; "
	 "sig_last_thread_switch ; nop = nop.pm.never.8b(r0, r0, ra4, nop) ; rx1.nop = fmul.always(a, r4) ; "
	 "sig_none ; nop = nop.ws.pm.never.8a(r0, r0, nop, rb4) ; rx1.nop = fmul.always(b, r4) ; "
	 "sig_none ; nop = nop.pm.never.8d(r0, r0, nop, rb3) ; rx2.nop = fmul.always(b, r4) ; "
	 "sig_load_tmu0 ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
	 "sig_none ; r1 = fmax.pm.always.8d(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
	 "sig_none ; r3 = fadd.pm.always.8c(a, r4, ra2, rb2) ; r1.8d = fmul.always(b, r1) ; "
	 "sig_none ; r2 = fadd.pm.always.8b(b, r4, nop, rb1) ; r1.8a = v8min.always(r3, r3) ; "
	 "sig_none ; r0 = fadd.pm.always.8a(a, r4, ra1, nop) ; r1.8b = v8min.always(r2, r2) ; "
	 "sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r1.8c = v8min.always(r0, r0) ; "
	 "sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; nop = nop.never(r0, r0) ; "
	 "sig_none ; tlb_color_all.nop = or.always.nop(r1, r1, nop, nop) ; nop = nop.never(r0, r0) ; "
	 "sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	 "sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	 "sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char multiTextureAddClippingPlane_AlphaDisabled_BlendDisabled_DepthStencilEnabled_FS[] =
{
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx4.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx4.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx3.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx3.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_thread_switch ; tmu0_s.nop = or.always.nop(r3, r3, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.always.nop(r0, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.ws.always.nop(b, b, nop, rb0) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop = nop.ws.pm.never.8c(r0, r0, ra3, nop) ; rx2.nop = fmul.always(a, r4) ; "
"sig_last_thread_switch ; nop = nop.pm.never.8b(r0, r0, ra4, nop) ; rx1.nop = fmul.always(a, r4) ; "
"sig_none ; nop = nop.ws.pm.never.8a(r0, r0, nop, rb4) ; rx1.nop = fmul.always(b, r4) ; "
"sig_none ; nop = nop.pm.never.8d(r0, r0, nop, rb3) ; rx2.nop = fmul.always(b, r4) ; "
"sig_load_tmu0 ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r1 = fmax.pm.always.8d(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fadd.pm.always.8c(a, r4, ra2, rb2) ; r1.8d = fmul.always(b, r1) ; "
"sig_none ; r2 = fadd.pm.always.8b(b, r4, nop, rb1) ; r1.8a = v8min.always(r3, r3) ; "
"sig_none ; r0 = fadd.pm.always.8a(a, r4, ra1, nop) ; r1.8b = v8min.always(r2, r2) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r1.8c = v8min.always(r0, r0) ; "
"sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_color_all.nop = or.always.nop(r1, r1, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char multiTextureAdd_AlphaDisabled_DstZero_SrcDstColor_DepthStencilEnabled_FS[] =
{
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx4.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx4.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx3.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx3.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_thread_switch ; tmu0_s.nop = or.always.nop(r3, r3, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.always.nop(r0, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.ws.always.nop(b, b, nop, rb0) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop = nop.ws.pm.never.8c(r0, r0, ra3, nop) ; rx2.nop = fmul.always(a, r4) ; "
"sig_last_thread_switch ; nop = nop.pm.never.8b(r0, r0, ra4, nop) ; rx1.nop = fmul.always(a, r4) ; "
"sig_none ; nop = nop.ws.pm.never.8a(r0, r0, nop, rb4) ; rx1.nop = fmul.always(b, r4) ; "
"sig_none ; nop = nop.pm.never.8d(r0, r0, nop, rb3) ; rx2.nop = fmul.always(b, r4) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r1 = fmax.pm.always.8d(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fadd.pm.always.8c(a, r4, ra2, rb2) ; r1.8d = fmul.always(b, r1) ; "
"sig_none ; r2 = fadd.pm.always.8b(b, r4, nop, rb1) ; r1.8a = v8min.always(r3, r3) ; "
"sig_none ; r0 = fadd.pm.always.8a(a, r4, ra1, nop) ; r1.8b = v8min.always(r2, r2) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r1.8c = v8min.always(r0, r0) ; "
"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.ws.never.nop(r0, r0, nop, nop) ; tlb_color_all = v8muld.always(r1, r4) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char multiTextureAddClippingPlane_AlphaDisabled_DstZero_SrcDstColor_DepthStencilEnabled_FS[] =
{
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx4.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx4.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx3.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx3.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_thread_switch ; tmu0_s.nop = or.always.nop(r3, r3, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.always.nop(r0, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.ws.always.nop(b, b, nop, rb0) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop = nop.ws.pm.never.8c(r0, r0, ra3, nop) ; rx2.nop = fmul.always(a, r4) ; "
"sig_last_thread_switch ; nop = nop.pm.never.8b(r0, r0, ra4, nop) ; rx1.nop = fmul.always(a, r4) ; "
"sig_none ; nop = nop.ws.pm.never.8a(r0, r0, nop, rb4) ; rx1.nop = fmul.always(b, r4) ; "
"sig_none ; nop = nop.pm.never.8d(r0, r0, nop, rb3) ; rx2.nop = fmul.always(b, r4) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r1 = fmax.pm.always.8d(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fadd.pm.always.8c(a, r4, ra2, rb2) ; r1.8d = fmul.always(b, r1) ; "
"sig_none ; r2 = fadd.pm.always.8b(b, r4, nop, rb1) ; r1.8a = v8min.always(r3, r3) ; "
"sig_none ; r0 = fadd.pm.always.8a(a, r4, ra1, nop) ; r1.8b = v8min.always(r2, r2) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r1.8c = v8min.always(r0, r0) ; "
"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.ws.never.nop(r0, r0, nop, nop) ; tlb_color_all = v8muld.always(r1, r4) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char multiTextureMul_AlphaDisabled_DstZero_SrcDstColor_DepthStencilEnabled_FS[] =
{
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx3.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx4.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx4.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; r2.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_thread_switch ; rx1.nop = fadd.always.nop(r3, r5, nop, nop) ; tmu0_t = v8min.always(r2, r2) ; "
"sig_none ; tmu0_s.nop = or.always.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.always.nop(r0, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx14.nop = fmax.ws.always.nop(a, a, ra3, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
"sig_last_thread_switch ; tmu0_s.nop = or.ws.always.nop(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx2.nop = or.always.nop(r4, r4, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.8a(r0, r0, ra2, rb14) ; rx0 = fmul.always(b, a) ; "
"sig_none ; r1 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r2 = fmax.pm.always.8b(r4, r4, nop, rb0) ; rx2.8c = fmul.always(b, r1) ; "
"sig_none ; nop.nop = nop.never.8b(r0, r0, ra2, rb3) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx14.nop = fmax.ws.always.nop(a, a, ra4, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fmax.pm.always.8c(r4, r4, nop, nop) ; rx2.8b = fmul.always(r1, r2) ; "
"sig_none ; nop.nop = nop.never.8c(r0, r0, ra2, rb14) ; r2 = fmul.always(b, a) ; "
"sig_none ; r0 = fmax.pm.always.8d(r4, r4, nop, nop) ; rx2.8a = fmul.always(r2, r3) ; "
"sig_none ; nop.nop = nop.never.8d(r0, r0, ra2, rb4) ; r3 = fmul.always(b, a) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; rx2.8d = fmul.always(r3, r0) ; "
"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.ws.never.nop(r0, r0, nop, rb2) ; tlb_color_all = v8muld.always(b, r4) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char multiTextureMulClippingPlane_AlphaDisabled_DstZero_SrcDstColor_DepthStencilEnabled_FS[] =
{
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx3.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx3.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx4.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx4.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; r2.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_thread_switch ; rx1.nop = fadd.always.nop(r3, r5, nop, nop) ; tmu0_t = v8min.always(r2, r2) ; "
"sig_none ; tmu0_s.nop = or.always.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.always.nop(r0, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx14.nop = fmax.ws.always.nop(a, a, ra3, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
"sig_last_thread_switch ; tmu0_s.nop = or.ws.always.nop(a, a, ra1, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; rx2.nop = or.always.nop(r4, r4, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.8a(r0, r0, ra2, rb14) ; rx0 = fmul.always(b, a) ; "
"sig_none ; r1 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r2 = fmax.pm.always.8b(r4, r4, nop, rb0) ; rx2.8c = fmul.always(b, r1) ; "
"sig_none ; nop.nop = nop.never.8b(r0, r0, ra2, rb3) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx14.nop = fmax.ws.always.nop(a, a, ra4, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fmax.pm.always.8c(r4, r4, nop, nop) ; rx2.8b = fmul.always(r1, r2) ; "
"sig_none ; nop.nop = nop.never.8c(r0, r0, ra2, rb14) ; r2 = fmul.always(b, a) ; "
"sig_none ; r0 = fmax.pm.always.8d(r4, r4, nop, nop) ; rx2.8a = fmul.always(r2, r3) ; "
"sig_none ; nop.nop = nop.never.8d(r0, r0, ra2, rb4) ; r3 = fmul.always(b, a) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; rx2.8d = fmul.always(r3, r0) ; "
"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.ws.never.nop(r0, r0, nop, rb2) ; tlb_color_all = v8muld.always(b, r4) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};


char singleTexture_AlphaDisabled_DstSrcAlpha_SrcZero_DepthStencilEnabled_FS[] =
{
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; r1.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx3.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; rx3 = fmul.always(b, a) ; " //TODO hack
"sig_none ; rx3.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; rx3 = fmul.always(b, a) ; "
"sig_none ; rx3.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; rx3 = fmul.always(b, a) ; "
"sig_last_thread_switch ; r3.nop = fadd.always.nop(r2, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r3, r3, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.ws.always.nop(r1, r1, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop = nop.pm.never.8d(r0, r0, ra0, nop) ; r0.nop = fmul.always(a, r4) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r2.8888 = v8min.always(r0, r0) ; "
"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.ws.never.nop(r0, r0, nop, nop) ; tlb_color_all = v8muld.always(r4, r2) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char singleTextureClippingPlane_AlphaDisabled_DstSrcAlpha_SrcZero_DepthStencilEnabled_FS[] =
{
	"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_none ; rx0.nop = fadd.ws.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
	"sig_none ; r0.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
	"sig_none ; rx3.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; rx3 = fmul.always(b, a) ; " //TODO hack
	"sig_none ; rx3.nop = fadd.always.nop(r1, r5, pay_zw, vary) ; rx3 = fmul.always(b, a) ; "
	"sig_none ; r3.nop = fadd.always.nop(r2, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_t.nop = or.ws.always.nop(r3, r3, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tmu0_s.nop = or.always.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
	"sig_small_imm ; rx0.nop = or.always.nop(b, b, nop, 0) ; nop = nop.never(r0, r0) ; "
	"sig_last_thread_switch ; r1.nop = fadd.always.nop(r0, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = fmax.always.sf.nop(r1, r1, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_small_imm ; rx0.nop = or.ns.nop(b, b, nop, -1) ; nop = nop.never(r0, r0) ; "
	"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop = nop.pm.never.8d(r0, r0, nop, rb0) ; r2.nop = fmul.always(b, r4) ; "
	"sig_none ; nop.nop = or.always.sf.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r3.8888 = v8min.always(r2, r2) ; "
	"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; tlb_z.nop = or.zs.nop(b, b, nop, pay_zw) ; r1 = v8muld.always(r4, r3) ; "
	"sig_none ; tlb_color_all.nop = or.zs.nop(r1, r1, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
	"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "};

char singleTexture_AlphaDisabled_DstSrcAlpha_SrcOne_DepthStencilEnabled_FS[] =
{
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx2.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_last_thread_switch ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.ws.always.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r0 = fmax.ws.pm.always.8b(r4, r4, ra1, nop) ; rx0.8c = fmul.always(a, r3) ; "
"sig_none ; r1 = fmax.ws.pm.always.8c(r4, r4, nop, rb1) ; rx0.8b = fmul.always(b, r0) ; "
"sig_none ; nop = nop.pm.never.8d(r0, r0, nop, rb0) ; r2.nop = fmul.always(b, r4) ; "
"sig_none ; nop = nop.ws.pm.never.nop(r0, r0, ra2, nop) ; rx0.8a = fmul.always(a, r1) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r3.8888 = v8min.always(r2, r2) ; "
"sig_none ; nop = nop.ws.pm.never.nop(r0, r0, nop, nop) ; rx0.8d = v8min.always(r2, r2) ; "
"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; r1 = v8muld.always(r4, r3) ; "
"sig_none ; nop.nop = nop.ws.never.nop(r0, r0, ra0, nop) ; tlb_color_all = v8adds.always(a, r1) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};

char singleTextureClippingPlane_AlphaDisabled_DstSrcAlpha_SrcOne_DepthStencilEnabled_FS[] =
{
"sig_none ; nop.nop = nop.never.nop(r0, r0, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_none ; rx1.nop = fadd.ws.always.nop(r1, r5, pay_zw, vary) ; r2 = fmul.always(b, a) ; "
"sig_none ; rx2.nop = fadd.always.nop(r2, r5, pay_zw, vary) ; r3 = fmul.always(b, a) ; "
"sig_none ; rx0.nop = fadd.ws.always.nop(r3, r5, pay_zw, vary) ; r0 = fmul.always(b, a) ; "
"sig_none ; r0.nop = fadd.always.nop(r0, r5, pay_zw, vary) ; r1 = fmul.always(b, a) ; "
"sig_last_thread_switch ; r2.nop = fadd.always.nop(r1, r5, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_t.nop = or.ws.always.nop(r2, r2, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tmu0_s.nop = or.ws.always.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_load_tmu0 ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; r3 = fmax.pm.always.8a(r4, r4, nop, nop) ; nop.nop = nop.never(r0, r0) ; "
"sig_none ; r0 = fmax.ws.pm.always.8b(r4, r4, ra1, nop) ; rx0.8c = fmul.always(a, r3) ; "
"sig_none ; r1 = fmax.ws.pm.always.8c(r4, r4, nop, rb1) ; rx0.8b = fmul.always(b, r0) ; "
"sig_none ; nop = nop.pm.never.8d(r0, r0, nop, rb0) ; r2.nop = fmul.always(b, r4) ; "
"sig_none ; nop = nop.ws.pm.never.nop(r0, r0, ra2, nop) ; rx0.8a = fmul.always(a, r1) ; "
"sig_none ; nop = nop.pm.never.nop(r0, r0, nop, nop) ; r3.8888 = v8min.always(r2, r2) ; "
"sig_none ; nop = nop.ws.pm.never.nop(r0, r0, nop, nop) ; rx0.8d = v8min.always(r2, r2) ; "
"sig_color_load ; tlb_stencil_setup.nop = or.always.nop(a, a, uni, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; tlb_z.nop = or.always.nop(b, b, nop, pay_zw) ; r1 = v8muld.always(r4, r3) ; "
"sig_none ; nop.nop = nop.ws.never.nop(r0, r0, ra0, nop) ; tlb_color_all = v8adds.always(a, r1) ; "
"sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
"sig_unlock_score ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ; "
};
