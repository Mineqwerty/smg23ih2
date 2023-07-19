Gfx babomb_excivatoin_0_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 babomb_excivatoin_0_rgba16[] = {
	#include "levels/wf/babomb_excivatoin_0.rgba16.inc.c"
};
Gfx babomb_excivatoin_1_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 babomb_excivatoin_1_rgba16[] = {
	#include "levels/wf/babomb_excivatoin_1.rgba16.inc.c"
};
Gfx babomb_excivatoin_2_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 babomb_excivatoin_2_rgba16[] = {
	#include "levels/wf/babomb_excivatoin_2.rgba16.inc.c"
};
Gfx babomb_excivatoin_3_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 babomb_excivatoin_3_rgba16[] = {
	#include "levels/wf/babomb_excivatoin_3.rgba16.inc.c"
};
Gfx babomb_excivatoin_4_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 babomb_excivatoin_4_rgba16[] = {
	#include "levels/wf/babomb_excivatoin_4.rgba16.inc.c"
};
Gfx babomb_excivatoin_5_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 babomb_excivatoin_5_rgba16[] = {
	#include "levels/wf/babomb_excivatoin_5.rgba16.inc.c"
};
Gfx babomb_excivatoin_6_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 babomb_excivatoin_6_rgba16[] = {
	#include "levels/wf/babomb_excivatoin_6.rgba16.inc.c"
};
Gfx babomb_excivatoin_7_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 babomb_excivatoin_7_rgba16[] = {
	#include "levels/wf/babomb_excivatoin_7.rgba16.inc.c"
};
Gfx babomb_excivatoin_8_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 babomb_excivatoin_8_rgba16[] = {
	#include "levels/wf/babomb_excivatoin_8.rgba16.inc.c"
};
Gfx babomb_excivatoin_9_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 babomb_excivatoin_9_rgba16[] = {
	#include "levels/wf/babomb_excivatoin_9.rgba16.inc.c"
};
Gfx babomb_excivatoin_10_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 babomb_excivatoin_10_rgba16[] = {
	#include "levels/wf/babomb_excivatoin_10.rgba16.inc.c"
};
Gfx babomb_excivatoin_11_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 babomb_excivatoin_11_rgba16[] = {
	#include "levels/wf/babomb_excivatoin_11.rgba16.inc.c"
};
Gfx babomb_excivatoin_12_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 babomb_excivatoin_12_rgba16[] = {
	#include "levels/wf/babomb_excivatoin_12.rgba16.inc.c"
};
Gfx babomb_excivatoin_13_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 babomb_excivatoin_13_rgba16[] = {
	#include "levels/wf/babomb_excivatoin_13.rgba16.inc.c"
};
Gfx babomb_excivatoin_14_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 babomb_excivatoin_14_rgba16[] = {
	#include "levels/wf/babomb_excivatoin_14.rgba16.inc.c"
};
Gfx babomb_excivatoin_15_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 babomb_excivatoin_15_rgba16[] = {
	#include "levels/wf/babomb_excivatoin_15.rgba16.inc.c"
};
Gfx babomb_excivatoin_16_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 babomb_excivatoin_16_rgba16[] = {
	#include "levels/wf/babomb_excivatoin_16.rgba16.inc.c"
};

Vtx babomb_excivatoin_Letter_WallSprite_mesh_layer_4_vtx_0[4] = {
	{{{-95, -95, 0},0, {0, 1024},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{95, -95, 0},0, {1024, 1024},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{95, 95, 0},0, {1024, 0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-95, 95, 0},0, {0, 0},{0x0, 0x0, 0x7F, 0xFF}}},
};

Gfx babomb_excivatoin_Letter_WallSprite_mesh_layer_4_tri_0[] = {
	gsSPVertex(babomb_excivatoin_Letter_WallSprite_mesh_layer_4_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_babomb_excivatoin_Letter_Icon_0[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, babomb_excivatoin_0_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};
Gfx mat_babomb_excivatoin_Letter_Icon_1[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, babomb_excivatoin_1_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};
Gfx mat_babomb_excivatoin_Letter_Icon_2[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, babomb_excivatoin_2_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};
Gfx mat_babomb_excivatoin_Letter_Icon_3[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, babomb_excivatoin_3_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};
Gfx mat_babomb_excivatoin_Letter_Icon_4[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, babomb_excivatoin_4_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};
Gfx mat_babomb_excivatoin_Letter_Icon_5[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, babomb_excivatoin_5_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};
Gfx mat_babomb_excivatoin_Letter_Icon_6[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, babomb_excivatoin_6_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};
Gfx mat_babomb_excivatoin_Letter_Icon_7[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, babomb_excivatoin_7_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};
Gfx mat_babomb_excivatoin_Letter_Icon_8[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, babomb_excivatoin_8_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};
Gfx mat_babomb_excivatoin_Letter_Icon_9[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, babomb_excivatoin_9_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};
Gfx mat_babomb_excivatoin_Letter_Icon_10[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, babomb_excivatoin_10_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};
Gfx mat_babomb_excivatoin_Letter_Icon_11[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, babomb_excivatoin_11_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};
Gfx mat_babomb_excivatoin_Letter_Icon_12[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, babomb_excivatoin_12_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};
Gfx mat_babomb_excivatoin_Letter_Icon_13[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, babomb_excivatoin_13_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};
Gfx mat_babomb_excivatoin_Letter_Icon_14[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, babomb_excivatoin_14_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};
Gfx mat_babomb_excivatoin_Letter_Icon_15[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, babomb_excivatoin_15_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};
Gfx mat_babomb_excivatoin_Letter_Icon_16[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, babomb_excivatoin_16_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_babomb_excivatoin_Letter_Icon[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPEndDisplayList(),
};

Gfx babomb_excivatoin_Letter_WallSprite_mesh_layer_4_0[] = {
	gsSPDisplayList(mat_babomb_excivatoin_Letter_Icon_0),
	gsSPDisplayList(babomb_excivatoin_Letter_WallSprite_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_babomb_excivatoin_Letter_Icon),
	gsSPEndDisplayList(),
};
Gfx babomb_excivatoin_Letter_WallSprite_mesh_layer_4_1[] = {
	gsSPDisplayList(mat_babomb_excivatoin_Letter_Icon_1),
	gsSPDisplayList(babomb_excivatoin_Letter_WallSprite_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_babomb_excivatoin_Letter_Icon),
	gsSPEndDisplayList(),
};
Gfx babomb_excivatoin_Letter_WallSprite_mesh_layer_4_2[] = {
	gsSPDisplayList(mat_babomb_excivatoin_Letter_Icon_2),
	gsSPDisplayList(babomb_excivatoin_Letter_WallSprite_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_babomb_excivatoin_Letter_Icon),
	gsSPEndDisplayList(),
};
Gfx babomb_excivatoin_Letter_WallSprite_mesh_layer_4_3[] = {
	gsSPDisplayList(mat_babomb_excivatoin_Letter_Icon_3),
	gsSPDisplayList(babomb_excivatoin_Letter_WallSprite_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_babomb_excivatoin_Letter_Icon),
	gsSPEndDisplayList(),
};
Gfx babomb_excivatoin_Letter_WallSprite_mesh_layer_4_4[] = {
	gsSPDisplayList(mat_babomb_excivatoin_Letter_Icon_4),
	gsSPDisplayList(babomb_excivatoin_Letter_WallSprite_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_babomb_excivatoin_Letter_Icon),
	gsSPEndDisplayList(),
};
Gfx babomb_excivatoin_Letter_WallSprite_mesh_layer_4_5[] = {
	gsSPDisplayList(mat_babomb_excivatoin_Letter_Icon_5),
	gsSPDisplayList(babomb_excivatoin_Letter_WallSprite_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_babomb_excivatoin_Letter_Icon),
	gsSPEndDisplayList(),
};
Gfx babomb_excivatoin_Letter_WallSprite_mesh_layer_4_6[] = {
	gsSPDisplayList(mat_babomb_excivatoin_Letter_Icon_6),
	gsSPDisplayList(babomb_excivatoin_Letter_WallSprite_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_babomb_excivatoin_Letter_Icon),
	gsSPEndDisplayList(),
};
Gfx babomb_excivatoin_Letter_WallSprite_mesh_layer_4_7[] = {
	gsSPDisplayList(mat_babomb_excivatoin_Letter_Icon_7),
	gsSPDisplayList(babomb_excivatoin_Letter_WallSprite_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_babomb_excivatoin_Letter_Icon),
	gsSPEndDisplayList(),
};
Gfx babomb_excivatoin_Letter_WallSprite_mesh_layer_4_8[] = {
	gsSPDisplayList(mat_babomb_excivatoin_Letter_Icon_8),
	gsSPDisplayList(babomb_excivatoin_Letter_WallSprite_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_babomb_excivatoin_Letter_Icon),
	gsSPEndDisplayList(),
};
Gfx babomb_excivatoin_Letter_WallSprite_mesh_layer_4_9[] = {
	gsSPDisplayList(mat_babomb_excivatoin_Letter_Icon_9),
	gsSPDisplayList(babomb_excivatoin_Letter_WallSprite_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_babomb_excivatoin_Letter_Icon),
	gsSPEndDisplayList(),
};
Gfx babomb_excivatoin_Letter_WallSprite_mesh_layer_4_10[] = {
	gsSPDisplayList(mat_babomb_excivatoin_Letter_Icon_10),
	gsSPDisplayList(babomb_excivatoin_Letter_WallSprite_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_babomb_excivatoin_Letter_Icon),
	gsSPEndDisplayList(),
};
Gfx babomb_excivatoin_Letter_WallSprite_mesh_layer_4_11[] = {
	gsSPDisplayList(mat_babomb_excivatoin_Letter_Icon_11),
	gsSPDisplayList(babomb_excivatoin_Letter_WallSprite_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_babomb_excivatoin_Letter_Icon),
	gsSPEndDisplayList(),
};
Gfx babomb_excivatoin_Letter_WallSprite_mesh_layer_4_12[] = {
	gsSPDisplayList(mat_babomb_excivatoin_Letter_Icon_12),
	gsSPDisplayList(babomb_excivatoin_Letter_WallSprite_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_babomb_excivatoin_Letter_Icon),
	gsSPEndDisplayList(),
};
Gfx babomb_excivatoin_Letter_WallSprite_mesh_layer_4_13[] = {
	gsSPDisplayList(mat_babomb_excivatoin_Letter_Icon_13),
	gsSPDisplayList(babomb_excivatoin_Letter_WallSprite_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_babomb_excivatoin_Letter_Icon),
	gsSPEndDisplayList(),
};
Gfx babomb_excivatoin_Letter_WallSprite_mesh_layer_4_14[] = {
	gsSPDisplayList(mat_babomb_excivatoin_Letter_Icon_14),
	gsSPDisplayList(babomb_excivatoin_Letter_WallSprite_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_babomb_excivatoin_Letter_Icon),
	gsSPEndDisplayList(),
};
Gfx babomb_excivatoin_Letter_WallSprite_mesh_layer_4_15[] = {
	gsSPDisplayList(mat_babomb_excivatoin_Letter_Icon_15),
	gsSPDisplayList(babomb_excivatoin_Letter_WallSprite_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_babomb_excivatoin_Letter_Icon),
	gsSPEndDisplayList(),
};
Gfx babomb_excivatoin_Letter_WallSprite_mesh_layer_4_16[] = {
	gsSPDisplayList(mat_babomb_excivatoin_Letter_Icon_16),
	gsSPDisplayList(babomb_excivatoin_Letter_WallSprite_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_babomb_excivatoin_Letter_Icon),
	gsSPEndDisplayList(),
};

Gfx babomb_excivatoin_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

