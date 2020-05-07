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

uint64_t singleTextureVS[] =
{
	0xe0024c6700601a00,
	0x100210a715c27d80,
	0x100200e715c27d80,
	0x100049e220802037,
	0x100049e1200e003e,
	0x1002416321802477,
	0x100049e2200e003e,
	0x100250e0218026b7,
	0x100049e3200e003e,
	0x10025121218020f7,
	0x100049e0200e003e,
	0x1002410181c27236,
	0xe0025c6700001a00,
	0x100049e020801037,
	0x100208e701167c00,
	0x1002580181c207f6,
	0x10025d2335801037,
	0x100049e220801037,
	0x10020867019c4ec0,
	0x100240a2219c3e84,
	0x100049e320801037,
	0x1002116701127cc0,
	0xd00208e7029e1e80,
	0x10025806210a0de3,
	0x100049e220827006,
	0x10024863211a03d6,
	0x10124020278276ce,
	0x100049e1201a7006,
	0x10220027079e7240,
	0x1002086701805f80,
	0x10024c2035020d8f,
	0x100049e1201a7006,
	0x10024c2081c203f6,
	0x10020c27151a7d80,
	0x18020c2708067d80,
	0x1a020c2708067d80,
	0x1c020c2708067d80,
	0x1e020c2708067d80,
	0x10024c2195c27036,
	0x10020c27159e7240,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x100009e7009e7000,
};

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

uint64_t singleTextureCS[] =
{
	0xe0024c6700301a00,
	0x100200a715c27d80,
	0x100210a715c27d80,
	0x100049e1200a003e,
	0x100049e020802037,
	0x10024122210a023e,
	0x100049e320802037,
	0x100049e120802037,
	0x10025060210a047e,
	0x100240e2218020f7,
	0x100049e3200a003e,
	0x1002406281c276b6,
	0x100049e020827032,
	0x1002502321120c3a,
	0x10024821210e0cfa,
	0x1002112701800f80,
	0x100248e221801e72,
	0xe0025c6700001a00,
	0x1002487081044cbf,
	0x1002082701827180,
	0x100258b481827780,
	0x1002417081827392,
	0x100049e320827016,
	0x10020c2715167d80,
	0x10024c20359e7004,
	0xd0020867029e1e00,
	0x100049c3209e7021,
	0x100049e12080403e,
	0x100049e2209c300f,
	0x10124020279c349f,
	0x1022402227160037,
	0x100049e3209c3017,
	0x10020c2715027d80,
	0x10020c2701827780,
	0x10020c27159c3fc0,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x100009e7009e7000,
};

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

uint64_t singleTextureClippingPlaneVS[] =
{
	0xe0024c6700601a00,
	0x1002122715c27d80,
	0x1002026715c27d80,
	0x100049e02080803e,
	0x100049e22080803e,
	0x100049e120260037,
	0x100242a321260077,
	0x10025261212604fe,
	0x100049e320808037,
	0x100242222180867e,
	0x100049e320260037,
	0x100251e0218084f7,
	0x100049e22026003e,
	0x100251a1218080b7,
	0x100049e32026003e,
	0x10025160212602fe,
	0x100049e220808037,
	0x1002414281c27436,
	0x100049e32080803e,
	0x100049e220260037,
	0x10025120218026be,
	0x1002504181c09e36,
	0x100049e320802037,
	0x100049e02080203e,
	0x100201a7019c5ec0,
	0x10020127019c7e00,
	0x100049e120802037,
	0x100049e22080203e,
	0x100049e32080203e,
	0x100049e020802037,
	0x100210e701227c40,
	0x100200e7012a7c80,
	0x100212e7019c4ec0,
	0x100212a701167c00,
	0x10020867010e0dc0,
	0x100208e701801f80,
	0x100049e020827031,
	0x100049e220802037,
	0x100241e121806eb3,
	0x10020827019e7200,
	0x100208e701803f80,
	0x1002587481120ddb,
	0x100049e220827031,
	0x100202e7019e7080,
	0x100049e0209e701c,
	0xd0020867029e1e00,
	0x10025802211e0de1,
	0x100049e220827006,
	0x10020867011a0dc0,
	0x100049e3200a7016,
	0x10124020278276ce,
	0x100049e1200a7006,
	0x100208a70180af80,
	0x1022402227827256,
	0xe0025c6700001a00,
	0x100049e3200a7016,
	0x10020c2715027d80,
	0x10024c2081c207f6,
	0x10020c27150a7d80,
	0x18020c2708067d80,
	0x1a020c2708067d80,
	0x1c020c2708067d80,
	0x1e020c2708067d80,
	0x1002487095c27d80,
	0x100248308180bf89,
	0x100049e320827030,
	0x10020c27012e7cc0,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x100009e7009e7000,
};

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

uint64_t singleTextureClippingPlaneCS[] =
{
	0xe0024c6700301a00,
	0x100200a715c27d80,
	0x100210a715c27d80,
	0x100049e1200a003e,
	0x100049e020802037,
	0x10024122210a023e,
	0x100049e320802037,
	0x100049e120802037,
	0x10025060210a047e,
	0x100240e2218020f7,
	0x100049e3200a003e,
	0x1002406281c276b6,
	0x100049e020827032,
	0x1002502321120c3a,
	0x10024821210e0cfa,
	0x1002112701800f80,
	0x100248e221801e72,
	0xe0025c6700001a00,
	0x1002487081044cbf,
	0x1002082701827180,
	0x100258b481827780,
	0x1002417081827392,
	0x100049e320827016,
	0x10020c2715167d80,
	0x10024c20359e7004,
	0xd0020867029e1e00,
	0x100049c3209e7021,
	0x100049e12080403e,
	0x100049e2209c300f,
	0x10124020279c349f,
	0x1022402227160037,
	0x100049e3209c3017,
	0x10020c2715027d80,
	0x10020c2701827780,
	0x10020c27159c3fc0,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x100009e7009e7000,
};

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

uint64_t multiTextureVS[] =
{
	0xe0024c6700801a00,
	0x100210a715c27d80,
	0x100200e715c27d80,
	0x100049e020802037,
	0x100049e3200e003e,
	0x10024161218020f7,
	0x100049e0200e003e,
	0x100250e221802237,
	0x100049e1200e003e,
	0x1002512321802477,
	0x100049e2200e003e,
	0x1002410181c276b6,
	0xe0025c6700001a00,
	0x100049e220801037,
	0x1002086701167c80,
	0x1002588181c203f6,
	0x10025d21358014b7,
	0x100049e020801037,
	0x100208e7019c4e40,
	0x100240a0219c3e14,
	0x100049e120801037,
	0x1002116701127c40,
	0xd0020867029e1e00,
	0x10025886210a0de1,
	0x100049e020827016,
	0x100248e1211a07c6,
	0x101240222782725e,
	0x100049e3201a7016,
	0x1022402087c276f6,
	0x100208e701805f80,
	0x10024c2235020d9f,
	0x100049e3201a7016,
	0x10024c2181c207f6,
	0x10020c27151a7d80,
	0x18020c2708067d80,
	0x1a020c2708067d80,
	0x1c020c2708067d80,
	0x1e020c2708067d80,
	0x100248b095c27d80,
	0x100248f095c27d89,
	0x10020c27159e7480,
	0x10020c27159e76c0,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x100009e7009e7000,
};

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

uint64_t multiTextureCS[] =
{
	0xe0024c6700301a00,
	0x100200a715c27d80,
	0x100210a715c27d80,
	0x100049e1200a003e,
	0x100049e020802037,
	0x10024122210a023e,
	0x100049e320802037,
	0x100049e120802037,
	0x10025060210a047e,
	0x100240e2218020f7,
	0x100049e3200a003e,
	0x1002406281c276b6,
	0x100049e020827032,
	0x1002502321120c3a,
	0x10024821210e0cfa,
	0x1002112701800f80,
	0x100248e221801e72,
	0xe0025c6700001a00,
	0x1002487081044cbf,
	0x1002082701827180,
	0x100258b481827780,
	0x1002417081827392,
	0x100049e320827016,
	0x10020c2715167d80,
	0x10024c20359e7004,
	0xd0020867029e1e00,
	0x100049c3209e7021,
	0x100049e12080403e,
	0x100049e2209c300f,
	0x10124020279c349f,
	0x1022402227160037,
	0x100049e3209c3017,
	0x10020c2715027d80,
	0x10020c2701827780,
	0x10020c27159c3fc0,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x100009e7009e7000,
};                

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

uint64_t multiTextureClippingPlaneVS[] =
{
	0xe0024c6700801a00,
	0x1002122715c27d80,
	0x1002026715c27d80,
	0x100049e22080803e,
	0x100049e02080803e,
	0x100049e320260037,
	0x100242a1212604f7,
	0x100252632126007e,
	0x100049e120808037,
	0x10024220218082fe,
	0x100049e120260037,
	0x100251e221808077,
	0x100049e02026003e,
	0x100251a321808437,
	0x100049e12026003e,
	0x100251622126067e,
	0x100049e020808037,
	0x1002414281c270b6,
	0x100049e12080803e,
	0x100049e020260037,
	0x100251222180223e,
	0x1002504181c09eb6,
	0x100049e120802037,
	0x100049e22080203e,
	0x100201a7019c5e40,
	0x10020127019c7e80,
	0x100049e320802037,
	0x100049e02080203e,
	0x100049e12080203e,
	0x100049e220802037,
	0x100210e701227cc0,
	0x100200e7012a7c00,
	0x100212e7019c4e40,
	0x100212a701167c80,
	0x100208e7010e0dc0,
	0x1002086701801f80,
	0x100049e220827033,
	0x100049e020802037,
	0x100241e321806e31,
	0x100208a7019e7680,
	0x1002086701803f80,
	0x100258f481120dc9,
	0x100049e020827033,
	0x100202e7019e7400,
	0x100049e2209e700c,
	0xd00208e7029e1e80,
	0x10025882211e0de3,
	0x100049e020827016,
	0x100208e7011a0dc0,
	0x100049e1200a7006,
	0x101240222782725e,
	0x100049e3200a7016,
	0x100208270180af80,
	0x10224020278276c6,
	0xe0025c6700001a00,
	0x100049e1200a7006,
	0x10020c2715027d80,
	0x10024c2081c203f6,
	0x10020c27150a7d80,
	0x18020c2708067d80,
	0x1a020c2708067d80,
	0x1c020c2708067d80,
	0x1e020c2708067d80,
	0x10024c2195c27036,
	0x10024c2295c27276,
	0x100248f095c27d92,
	0x100248b08180bf9b,
	0x100049e120827032,
	0x10020c27012e7c40,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x100009e7009e7000,
};

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

uint64_t multiTextureClippingPlaneCS[] =
{
	0xe0024c6700301a00,
	0x100200a715c27d80,
	0x100210a715c27d80,
	0x100049e1200a003e,
	0x100049e020802037,
	0x10024122210a023e,
	0x100049e320802037,
	0x100049e120802037,
	0x10025060210a047e,
	0x100240e2218020f7,
	0x100049e3200a003e,
	0x1002406281c276b6,
	0x100049e020827032,
	0x1002502321120c3a,
	0x10024821210e0cfa,
	0x1002112701800f80,
	0x100248e221801e72,
	0xe0025c6700001a00,
	0x1002487081044cbf,
	0x1002082701827180,
	0x100258b481827780,
	0x1002417081827392,
	0x100049e320827016,
	0x10020c2715167d80,
	0x10024c20359e7004,
	0xd0020867029e1e00,
	0x100049c3209e7021,
	0x100049e12080403e,
	0x100049e2209c300f,
	0x10124020279c349f,
	0x1022402227160037,
	0x100049e3209c3017,
	0x10020c2715027d80,
	0x10020c2701827780,
	0x10020c27159c3fc0,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x100009e7009e7000,
};


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

uint64_t singleTexture_AlphaDisabled_BlendDisabled_DepthStencilEnabled_FS[] =
{
	0x100049e0203e303e,
	0x10024021213e317e,
	0x10025022213e337e,
	0x10024063213e357e,
	0x10025060213e377e,
	0x100248e1213e317e,
	0x600208a7019e7340,
	0x10021e67159e7480,
	0x10021e27159e76c0,
	0xa0020ae715827d80,
	0x190208e7049e7900,
	0x1b62482324027933,
	0x1d524863249c0938,
	0x1f4248a324067931,
	0x117049e3209c103a,
	0x10020b27159cffc0,
	0x10020ba7159e76c0,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x500009e7009e7000,
};

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

uint64_t singleTexture_AlphaDisabled_DstZero_SrcDstColor_DepthStencilEnabled_FS[] =
{
	0x100049e0203e303e,
	0x10024021213e317e,
	0x10025022213e337e,
	0x10024063213e357e,
	0x10025060213e377e,
	0x100248e1213e317e,
	0x600208a7019e7340,
	0x10021e67159e7480,
	0x10021e27159e76c0,
	0xa00009e7009e7000,
	0x190208e7049e7900,
	0x1b62482324027933,
	0x1d524863249c0938,
	0x1f4248a324067931,
	0x117049e3209c103a,
	0x80020ae715827d80,
	0x10020b27159cffc0,
	0x100059ee609e701c,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x500009e7009e7000,
};

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

uint64_t singleTexture_AlphaDisabled_DstOneMinusSrcAlpha_SrcSrcAlpha_DepthStencilEnabled_FS[] =
{
	0x100049e0203e303e,
	0x10024061213e317e,
	0x10025062213e337e,
	0x100240a3213e357e,
	0x10025020213e377e,
	0x100248e1213e317e,
	0x600208a7019e7340,
	0x10021e67159e7480,
	0x10021e27159e76c0,
	0xa00009e7009e7000,
	0x190208e7049e7900,
	0x1b62580024067933,
	0x1d525840249c1938,
	0x114059c0200a7031,
	0x1f0049e2209c003c,
	0x117059c0809e7012,
	0x113049e3809e7012,
	0x10024821770276f3,
	0x80020ae715827d80,
	0x10024b20759cffe0,
	0x100059eec09e7008,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x500009e7009e7000,
};

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

uint64_t singleTexture_AlphaDisabled_DstOne_SrcDstColor_DepthStencilEnabled_FS[] =
{
	0x100049e0203e303e,
	0x10024021213e317e,
	0x10025022213e337e,
	0x10024063213e357e,
	0x10025060213e377e,
	0x10024821213e317e,
	0x600208a7019e7340,
	0x10021e67159e7480,
	0x10021e27159e7000,
	0xa00009e7009e7000,
	0x190208e7049e7900,
	0x1b62482324027933,
	0x1d524863249c0938,
	0x1f4248a324067931,
	0x117049e3209c103a,
	0x80020ae715827d80,
	0x10024b23759cffdc,
	0x100059eec09e701c,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x500009e7009e7000,
};

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

uint64_t singleTexture_AlphaDisabled_DstOne_SrcOne_DepthStencilEnabled_FS[] =
{
	0x100049e0203e303e,
	0x10024021213e317e,
	0x10025022213e337e,
	0x10024063213e357e,
	0x10025060213e377e,
	0x100248e1213e317e,
	0x600208a7019e7340,
	0x10021e67159e7480,
	0x10021e27159e76c0,
	0xa00009e7009e7000,
	0x190208e7049e7900,
	0x1b62482324027933,
	0x1d524863249c0938,
	0x1f4248a324067931,
	0x117049e3209c103a,
	0x80020ae715827d80,
	0x10020b27159cffc0,
	0x100059eec09e701c,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x500009e7009e7000,
};

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

uint64_t singleTexture_AlphaDisabled_DstOneMinusSrcAlpha_SrcSrcAlpha_DepthStencilDisabled_FS[] =
{
	0x100049e0203e303e,
	0x10025021213e317e,
	0x10024062213e337e,
	0x10025063213e357e,
	0x10024020213e377e,
	0x100248e1213e317e,
	0x600208a7019e7340,
	0x10021e67159e7480,
	0x10021e27159e76c0,
	0xa00009e7009e7000,
	0x190208e7049e7900,
	0x1b624822249c093b,
	0x1d52486224067930,
	0x1f0049e320027034,
	0x114049e2209c1039,
	0x113049e0809e701b,
	0x11724862979e701b,
	0x100049e3609e7010,
	0x800009e7009e7000,
	0x100049e2609e7021,
	0x100059eec09e701a,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x500009e7009e7000,
};

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

uint64_t singleTextureClippingPlane_AlphaDisabled_BlendDisabled_DepthStencilEnabled_FS[] =
{
	0x100049e0203e303e,
	0x10025021213e317e,
	0x10024062213e337e,
	0x10025063213e357e,
	0x100240a0213e377e,
	0x100248e1213e317e,
	0x100208a7019e7340,
	0x10021e67159e7480,
	0x10024e23353e36fe,
	0xd0020027159c0fc0,
	0x60020827019e7740,
	0x100229e7049e7000,
	0xd0080027159dffc0,
	0xa0020ae715827d80,
	0x19020867049e7900,
	0x1b6248a1249c0939,
	0x1d5248e124067932,
	0x100229e715027d80,
	0x1f424821249c193b,
	0x117049e1200a7030,
	0x10040b27159cffc0,
	0x10040ba7159e7240,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x500009e7009e7000,
};

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

uint64_t singleTexture_AlphaDisabled_BlendDisabled_DepthStencilDisabled_FS[] =
{
	0x100049e0203e303e,
	0x10024021213e317e,
	0x10025022213e337e,
	0x10024063213e357e,
	0x10025060213e377e,
	0x100248e1213e317e,
	0x600208a7019e7340,
	0x10021e67159e7480,
	0x10021e27159e76c0,
	0xa00009e7009e7000,
	0x190208e7049e7900,
	0x1b62482324027933,
	0x1d524863249c0938,
	0x1f4248a324067931,
	0x117049e3209c103a,
	0x10020ba7159e76c0,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x500009e7009e7000,
};

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

uint64_t singleTextureClippingPlane_AlphaDisabled_BlendDisabled_DepthStencilDisabled_FS[] =
{
	0x100049e0203e303e,
	0x10025021213e317e,
	0x10024062213e337e,
	0x10025063213e357e,
	0x100240a0213e377e,
	0x100248e1213e317e,
	0x100208a7019e7340,
	0x10021e67159e7480,
	0x10024e23353e36fe,
	0xd0020027159c0fc0,
	0x60020827019e7740,
	0x100229e7049e7000,
	0xd0080027159dffc0,
	0xa00009e7009e7000,
	0x19020867049e7900,
	0x1b6248a1249c0939,
	0x1d5248e124067932,
	0x1f424821249c193b,
	0x100229e715027d80,
	0x117049e1200a7030,
	0x10040ba7159e7240,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x500009e7009e7000,
};

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

uint64_t singleTextureClippingPlane_AlphaDisabled_DstOneMinusSrcAlpha_SrcSrcAlpha_DepthStencilEnabled_FS[] =
{
	0x100049e0203e303e,
	0x10025021213e317e,
	0x10024062213e337e,
	0x10025063213e357e,
	0x100240a0213e377e,
	0x10024821213e317e,
	0x100248a3213e337e,
	0x10021e67159e7480,
	0x10024838819e7740,
	0xd0020027159c0fc0,
	0x600229e7049e7000,
	0xd0080027159dffc0,
	0x100009e7009e7000,
	0x100229e715027d80,
	0xa00009e7009e7000,
	0x19020867049e7900,
	0x1b6248a0249c0939,
	0x1d5248e024067932,
	0x1f0049e1200a7034,
	0x114049e0209c103b,
	0x113049e2809e7009,
	0x117248e0979e7489,
	0x100049e1609e7002,
	0x80020ae715827d80,
	0x10044b20759cffe3,
	0x100049e2c09e7008,
	0x10040ba7159e7480,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x500009e7009e7000,
};

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

uint64_t singleTextureClippingPlane_AlphaDisabled_DstOne_SrcOne_DepthStencilEnabled_FS[] =
{
	0x100049e0203e303e,
	0x10025021213e317e,
	0x10024062213e337e,
	0x10025063213e357e,
	0x100240a0213e377e,
	0x100248e1213e317e,
	0x100208a7019e7340,
	0x10021e67159e7480,
	0x10024e23353e36fe,
	0xd0020027159c0fc0,
	0x60020827019e7740,
	0x100229e7049e7000,
	0xd0080027159dffc0,
	0xa00009e7009e7000,
	0x19020867049e7900,
	0x1b6248a1249c0939,
	0x1d5248e124067932,
	0x1f424821249c193b,
	0x100229e715027d80,
	0x117049e1200a7030,
	0x80020ae715827d80,
	0x10044b20d59cffcc,
	0x10040ba7159e7000,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x500009e7009e7000,
};

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

uint64_t singleTextureClippingPlane_AlphaDisabled_DstOneMinusSrcAlpha_SrcSrcAlpha_DepthStencilDisabled_FS[] =
{
	0x100049e0203e303e,
	0x10025021213e317e,
	0x10024062213e337e,
	0x10025063213e357e,
	0x100240a0213e377e,
	0x100248e1213e317e,
	0x100208a7019e7340,
	0x10021e67159e7480,
	0x10024e23353e36fe,
	0xd0020027159c0fc0,
	0x60020827019e7740,
	0x100229e7049e7000,
	0xd0080027159dffc0,
	0xa00009e7009e7000,
	0x19020867049e7900,
	0x1b6248a0249c0939,
	0x1d5248e024067932,
	0x114049e0209c103b,
	0x1f0049e2200a7034,
	0x117049e0809e7012,
	0x113049e3809e7012,
	0x10024821779e76c3,
	0x100229e715027d80,
	0x800009e7009e7000,
	0x100049e0609e7020,
	0x100049e1c09e7008,
	0x10040ba7159e7240,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x500009e7009e7000,
};
