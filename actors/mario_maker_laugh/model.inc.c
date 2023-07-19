Gfx mario_maker_laugh_laugh_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 mario_maker_laugh_pink_rgba16[] = {
	#include "actors/mario_maker_laugh/laugh_pink.rgba16.inc.c"
};

u8 mario_maker_laugh_blue_rgba16[] = {
	#include "actors/mario_maker_laugh/laugh_blue.rgba16.inc.c"
};

u8 mario_maker_laugh_yellow_rgba16[] = {
	#include "actors/mario_maker_laugh/laugh_yellow.rgba16.inc.c"
};

Vtx mario_maker_laugh_LaughSprite_LaughSprite_mesh_layer_4_mario_vtx_0[4] = {
	{{{-80, -80, 0},0, {0, 2048},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{0, -80, 0},0, {1024, 2048},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{0, 80, 0},0, {1024, 0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-80, 80, 0},0, {0, 0},{0x0, 0x0, 0x7F, 0xFF}}},
};

Vtx mario_maker_laugh_LaughSprite_LaughSprite_mesh_layer_4_mario_vtx_1[4] = {
	{{{80, -80, 0},0, {0, 2048},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{0, -80, 0},0, {1024, 2048},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{0, 80, 0},0, {1024, 0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{80, 80, 0},0, {0, 0},{0x0, 0x0, 0x7F, 0xFF}}},
};

Gfx mario_maker_laugh_LaughSprite_LaughSprite_mesh_layer_4_mario_tri_0[] = {
	gsSPVertex(mario_maker_laugh_LaughSprite_LaughSprite_mesh_layer_4_mario_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mario_maker_laugh_LaughSprite_LaughSprite_mesh_layer_4_mario_tri_1[] = {
	gsSPVertex(mario_maker_laugh_LaughSprite_LaughSprite_mesh_layer_4_mario_vtx_1 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_mario_maker_laugh_pink_Icon_mario[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK | G_ZBUFFER),
	gsDPSetTextureFilter(G_TF_POINT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, mario_maker_laugh_pink_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 64 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (64 - 1) << G_TEXTURE_IMAGE_FRAC),
	gsSPEndDisplayList(),
};

Gfx mat_mario_maker_laugh_blue_Icon_mario[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK | G_ZBUFFER),
	gsDPSetTextureFilter(G_TF_POINT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, mario_maker_laugh_blue_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 64 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (64 - 1) << G_TEXTURE_IMAGE_FRAC),
	gsSPEndDisplayList(),
};

Gfx mat_mario_maker_laugh_yellow_Icon_mario[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK | G_ZBUFFER),
	gsDPSetTextureFilter(G_TF_POINT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, mario_maker_laugh_yellow_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 64 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (64 - 1) << G_TEXTURE_IMAGE_FRAC),
	gsSPEndDisplayList(),
};

Gfx mat_revert_mario_maker_laugh_LaughSprite_Icon[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK | G_ZBUFFER),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPEndDisplayList(),
};

Gfx mario_maker_laugh_pink_mesh_layer_4_mario[] = {
	gsSPDisplayList(mat_mario_maker_laugh_pink_Icon_mario),
	gsSPDisplayList(mario_maker_laugh_LaughSprite_LaughSprite_mesh_layer_4_mario_tri_0),
	gsSPDisplayList(mat_revert_mario_maker_laugh_LaughSprite_Icon),
	gsSPDisplayList(mat_mario_maker_laugh_pink_Icon_mario),
	gsSPDisplayList(mario_maker_laugh_LaughSprite_LaughSprite_mesh_layer_4_mario_tri_1),
	gsSPDisplayList(mat_revert_mario_maker_laugh_LaughSprite_Icon),
	gsSPEndDisplayList(),
};

Gfx mario_maker_laugh_blue_mesh_layer_4_mario[] = {
	gsSPDisplayList(mat_mario_maker_laugh_blue_Icon_mario),
	gsSPDisplayList(mario_maker_laugh_LaughSprite_LaughSprite_mesh_layer_4_mario_tri_0),
	gsSPDisplayList(mat_revert_mario_maker_laugh_LaughSprite_Icon),
	gsSPDisplayList(mat_mario_maker_laugh_blue_Icon_mario),
	gsSPDisplayList(mario_maker_laugh_LaughSprite_LaughSprite_mesh_layer_4_mario_tri_1),
	gsSPDisplayList(mat_revert_mario_maker_laugh_LaughSprite_Icon),
	gsSPEndDisplayList(),
};

Gfx mario_maker_laugh_yellow_mesh_layer_4_mario[] = {
	gsSPDisplayList(mat_mario_maker_laugh_yellow_Icon_mario),
	gsSPDisplayList(mario_maker_laugh_LaughSprite_LaughSprite_mesh_layer_4_mario_tri_0),
	gsSPDisplayList(mat_revert_mario_maker_laugh_LaughSprite_Icon),
	gsSPDisplayList(mat_mario_maker_laugh_yellow_Icon_mario),
	gsSPDisplayList(mario_maker_laugh_LaughSprite_LaughSprite_mesh_layer_4_mario_tri_1),
	gsSPDisplayList(mat_revert_mario_maker_laugh_LaughSprite_Icon),
	gsSPEndDisplayList(),
};

Gfx mario_maker_laugh_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

