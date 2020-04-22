#pragma once

#include <stdint.h>
#include "../../vkExt.h"

uint64_t singleTextureVS[] =
{
	0xe0024c6700901a00,
	0x1002106715c27d80,
	0x100200a715c27d80,
	0x100049e220801037,
	0x100049e1200a003e,
	0x1002412321801477,
	0x100049e2200a003e,
	0x100250a0218016b7,
	0x100049e3200a003e,
	0x100250e1218010f7,
	0x100049e0200a003e,
	0x100240c081c27236,
	0xe0025c6700001a00,
	0x100049e020800037,
	0x100208e701127c00,
	0x1002082701827780,
	0x10025d2335800037,
	0x100049e220800037,
	0x10020867019c3ec0,
	0x10024062219c2e84,
	0x100049e320800037,
	0x10021127010e7cc0,
	0xd00208e7029e1e80,
	0x1002580521060de3,
	0x100049e220827006,
	0x10024863211603d6,
	0x10124020278276ce,
	0x100049e120167006,
	0x10220027079e7240,
	0x1002086701804f80,
	0x10024c2035020d8f,
	0x100049e120167006,
	0x10024c2081c203f6,
	0x10020c2715167d80,
	0x10024c2195c27036,
	0x10024c2295c27276,
	0x10024c2395c274b6,
	0x10024c2095c276f6,
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
	{ //m0y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		4, //resource offset
	},
	{ //m1x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		16, //resource offset
	},
	{ //m3y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		52, //resource offset
	},
	{ //m1y
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		20, //resource offset
	},
	{ //m3x
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		48, //resource offset
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
	{ //m0z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		8, //resource offset
	},
	{ //m3z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		56, //resource offset
	},
	{ //m1z
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		24, //resource offset
	},
	{ //m0w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		12, //resource offset
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
	{ //m1w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		28, //resource offset
	},
	{ //m2w
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		44, //resource offset
	},

	{ //y scale
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		64, //resource offset
	},
	{ //x scale
		VK_RPI_ASSEMBLY_MAPPING_TYPE_PUSH_CONSTANT,
		VK_DESCRIPTOR_TYPE_MAX_ENUM, //descriptor type
		0, //descriptor set #
		0, //descriptor binding #
		0, //descriptor array element #
		68, //resource offset
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

/**
sig_load_imm ; vr_setup.nop = load32.always(0x301a00) ; nop = load32.always() ;
sig_none ; rx2.nop = or.always.nop(a, a, vpm_read, nop) ; nop = nop.never(r0, r0) ;		//read ra2 = vx
sig_none ; rx2.nop = or.ws.always.nop(a, a, vpm_read, nop) ; nop = nop.never(r0, r0) ;	//read rb2 = vy
sig_none ; nop.nop = nop.never.nop(r0, r0, ra2, uni) ; r1 = fmul.always(b, a) ;			//vx * m0x
sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r0 = fmul.always(a, b) ;			//vy * m0y
sig_none ; rx4.nop = fadd.always.nop(r1, r0, ra2, uni) ; r2 = fmul.always(b, a) ;		//vx * m1x
sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r3 = fmul.always(a, b) ;			//vy * m3y
sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb2) ; r1 = fmul.always(a, b) ;			//vy * m1y
sig_none ; rx1.nop = fadd.ws.always.nop(r2, r1, ra2, uni) ; r0 = fmul.always(b, a) ;	//vx * m3x
sig_none ; rx3.nop = fadd.always.nop(r0, r3, uni, rb2) ; r2 = fmul.always(a, b) ;		//vy * m2y
sig_none ; nop.nop = nop.never.nop(r0, r0, ra2, uni) ; r3 = fmul.always(b, a) ;			//vx * m2x
sig_none ; rx1.nop = fadd.always.nop(r3, r2, vpm_read, nop) ; r2 = v8min.always(a, a) ;	//read r2 = vz
sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r0 = fmul.always(a, r2) ;		//vz * m0z
sig_none ; rx0.nop = fadd.ws.always.nop(a, r0, ra4, uni) ; r3 = fmul.always(b, r2) ;	//vz * m3z
sig_none ; r0.nop = fadd.always.nop(a, r3, ra3, uni) ; r1 = fmul.always(b, r2) ;		//vz * m1z,
sig_none ; rx4.nop = fadd.ws.always.nop(b, a, uni, rb0) ; nop = nop.never(r0, r0) ;		//+m0w
sig_none ; r3.nop = fadd.always.nop(b, r1, uni, rb1) ; r2 = fmul.always(a, r2) ;		//vz * m2z
sig_load_imm ; vw_setup = load32.ws.always(0x1a00) ; nop = load32.always() ;
sig_none ; r1.nop = fadd.always.nop(a, r2, ra1, rb4) ; vpm = v8min.always(b, b) ;		//write Xc,
sig_none ; r0.nop = fadd.always.nop(r0, a, uni, nop) ; nop = nop.never(r0, r0) ;		//+m3w
sig_none ; r2.nop = fadd.ws.always.nop(r3, a, uni, nop) ; sfu_recip = v8min.always(r0, r0) ;	//+m1w
sig_none ; rx5.nop = fadd.always.nop(r1, a, uni, nop) ; vpm = v8min.always(r2, r2) ;	//write Yc, +m2w
sig_none ; nop.nop = nop.never.nop(r0, r0, uni, nop) ; r3 = fmul.always(r2, a) ;		//Yscale
sig_none ; vpm.nop = or.always.nop(a, a, ra5, nop) ; nop = nop.never(r0, r0) ;			//write Zc
sig_none ; vpm.nop = or.always.nop(r0, r0, nop, nop) ; r0 = fmul.always(r0, r4) ;		//write Wc
sig_small_imm ; r1.nop = fsub.always.nop(b, r0, nop, 0x40000000) ; nop = nop.never(r0, r0) ;
sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; rx3 = fmul.always(r4, r1) ;
sig_none ; nop.nop = nop.never.nop(r0, r0, uni, rb4) ; r1 = fmul.always(b, a) ;			//Xscale
sig_none ; nop.nop = nop.never.nop(r0, r0, nop, rb3) ; r2 = fmul.always(r1, b) ;
sig_none ; rx0.16a = ftoi.always.nop(r2, r2, nop, rb3) ; r0 = fmul.always(r3, b) ;
sig_none ; rx0.16b = ftoi.always.nop(r0, r0, ra5, uni) ; r2 = fmul.always(a, b) ;		//Zscale
sig_none ; nop.nop = nop.never.nop(r0, r0, nop, rb3) ; r3 = fmul.always(r2, b) ;
sig_none ; vpm.nop = or.always.nop(a, a, ra0, nop) ; nop = nop.never(r0, r0) ;			//write XsYs
sig_none ; vpm.nop = fadd.always.nop(r3, a, uni, nop) ; nop = nop.never(r0, r0) ;		//write Zs, Zoffset
sig_none ; vpm.nop = or.always.nop(b, b, nop, rb3) ; nop = nop.never(r0, r0) ;			//write 1/Wc
sig_end ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ;
sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ;
sig_none ; nop.nop = nop.never.nop(r0, r0, nop, nop) ; nop = nop.never(r0, r0) ;
/**/

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

uint64_t singleTextureClippingPlaneVS[] =
{
	0xe0024c6700901a00,
	0x100211e715c27d80,
	0x1002022715c27d80,
	0x100049e02080703e,
	0x100049e22080703e,
	0x100049e120220037,
	0x1002426321220077,
	0x10025221212204fe,
	0x100049e320807037,
	0x100241e22180767e,
	0x100049e320220037,
	0x100251a0218074f7,
	0x100049e22022003e,
	0x10025161218070b7,
	0x100049e32022003e,
	0x10025120212202fe,
	0x100049e220807037,
	0x1002410181c27436,
	0x100049e32080703e,
	0x100049e220220037,
	0x100250e0218016be,
	0x10021027019c8e00,
	0x100049e320801037,
	0x100049e02080103e,
	0x10020167019c4ec0,
	0x100200e7019c6e00,
	0x100049e120801037,
	0x100049e22080103e,
	0x100049e32080103e,
	0x100049e020801037,
	0x100210a7011e7c40,
	0x100200a701267c80,
	0x100212a7019c3ec0,
	0x1002126701127c00,
	0x10020867010a0dc0,
	0x100208e701800f80,
	0x100049e020827031,
	0x100049e220801037,
	0x100241a121805eb3,
	0x10020827019e7200,
	0x100208e701802f80,
	0x10025874810e0ddb,
	0x100049e220827031,
	0x100202a7019e7080,
	0x100049e0209e701c,
	0xd0020867029e1e00,
	0x10025801211a0de1,
	0x100049e220827006,
	0x1002086701160dc0,
	0x100049e320067016,
	0x10124020278276ce,
	0x100049e120067006,
	0x100208a701809f80,
	0x1022402227827256,
	0xe0025c6700001a00,
	0x100049e320067016,
	0x10020c2715027d80,
	0x10024c2081c207f6,
	0x10020c2715067d80,
	0x10024c2195c27036,
	0x10024c2295c27276,
	0x10024c2395c274b6,
	0x10024c2095c276f6,
	0x1002487095c27d80,
	0x100248308180af89,
	0x100049e320827030,
	0x10020c27012a7cc0,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x100009e7009e7000,
};

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

uint64_t multiTextureVS[] =
{
	0xe0024c6700b01a00,
	0x1002106715c27d80,
	0x100200a715c27d80,
	0x100049e020801037,
	0x100049e3200a003e,
	0x10024121218010f7,
	0x100049e0200a003e,
	0x100250a221801237,
	0x100049e1200a003e,
	0x100250e321801477,
	0x100049e2200a003e,
	0x100240c081c276b6,
	0xe0025c6700001a00,
	0x100049e220800037,
	0x1002086701127c80,
	0x100208a701827380,
	0x10025d21358004b7,
	0x100049e020800037,
	0x100208e7019c3e40,
	0x10024060219c2e14,
	0x100049e120800037,
	0x10021127010e7c40,
	0xd0020867029e1e00,
	0x1002588521060de1,
	0x100049e020827016,
	0x100248e1211607c6,
	0x101240222782725e,
	0x100049e320167016,
	0x1022402087c276f6,
	0x100208e701804f80,
	0x10024c2235020d9f,
	0x100049e320167016,
	0x10024c2181c207f6,
	0x10020c2715167d80,
	0x100248b095c27d80,
	0x100248f095c27d89,
	0x1002483095c27d92,
	0x1002487095c27d9b,
	0x100248b095c27d80,
	0x100248f095c27d89,
	0x10020c27159e7480,
	0x10020c27159e76c0,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x100009e7009e7000,
};

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

uint64_t multiTextureClippingPlaneVS[] =
{
	0xe0024c6700b01a00,
	0x100211e715c27d80,
	0x1002022715c27d80,
	0x100049e22080703e,
	0x100049e02080703e,
	0x100049e320220037,
	0x10024261212204f7,
	0x100252232122007e,
	0x100049e120807037,
	0x100241e0218072fe,
	0x100049e120220037,
	0x100251a221807077,
	0x100049e02022003e,
	0x1002516321807437,
	0x100049e12022003e,
	0x100251222122067e,
	0x100049e020807037,
	0x1002410181c270b6,
	0x100049e12080703e,
	0x100049e020220037,
	0x100250e22180123e,
	0x10021027019c8e80,
	0x100049e120801037,
	0x100049e22080103e,
	0x10020167019c4e40,
	0x100200e7019c6e80,
	0x100049e320801037,
	0x100049e02080103e,
	0x100049e12080103e,
	0x100049e220801037,
	0x100210a7011e7cc0,
	0x100200a701267c00,
	0x100212a7019c3e40,
	0x1002126701127c80,
	0x100208e7010a0dc0,
	0x1002086701800f80,
	0x100049e220827033,
	0x100049e020801037,
	0x100241a321805e31,
	0x100208a7019e7680,
	0x1002086701802f80,
	0x100258f4810e0dc9,
	0x100049e020827033,
	0x100202a7019e7400,
	0x100049e2209e700c,
	0xd00208e7029e1e80,
	0x10025881211a0de3,
	0x100049e020827016,
	0x100208e701160dc0,
	0x100049e120067006,
	0x101240222782725e,
	0x100049e320067016,
	0x1002082701809f80,
	0x10224020278276c6,
	0xe0025c6700001a00,
	0x100049e120067006,
	0x10020c2715027d80,
	0x10024c2081c203f6,
	0x10020c2715067d80,
	0x10024c2195c27036,
	0x10024c2295c27276,
	0x10024c2395c274b6,
	0x10024c2095c276f6,
	0x10024c2195c27036,
	0x10024c2295c27276,
	0x100248f095c27d92,
	0x100248b08180af9b,
	0x100049e120827032,
	0x10020c27012a7c40,
	0x300009e7009e7000,
	0x100009e7009e7000,
	0x100009e7009e7000,
};


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
