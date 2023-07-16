Gfx custom_mario_death_sprite_mario_sprite_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 custom_mario_death_sprite_mariosad_0_rgba16[] = {
	#include "actors/custom_mario_death_sprite/mariosad_0.rgba16.inc.c"
};
u8 custom_mario_death_sprite_mariosad_1_rgba16[] = {
	#include "actors/custom_mario_death_sprite/mariosad_1.rgba16.inc.c"
};
u8 custom_mario_death_sprite_mariosad_2_rgba16[] = {
	#include "actors/custom_mario_death_sprite/mariosad_2.rgba16.inc.c"
};

Vtx custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_layer_4_mario_vtx_0[4] = {
	{{{-50, 100, 0},0, {0, 1024},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{50, 100, 0},0, {2048, 1024},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{50, 150, 0},0, {2048, 0},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-50, 150, 0},0, {0, 0},{0xFF, 0xFF, 0xFF, 0xFF}}},
};
Vtx custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_layer_4_mario_vtx_1[4] = {
	{{{-50, 50, 0},0, {0, 1024},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{50, 50, 0},0, {2048, 1024},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{50, 100, 0},0, {2048, 0},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-50, 100, 0},0, {0, 0},{0xFF, 0xFF, 0xFF, 0xFF}}},
};
Vtx custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_layer_4_mario_vtx_2[4] = {
	{{{-50, 0, 0},0, {0, 1024},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{50, 0, 0},0, {2048, 1024},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{50, 50, 0},0, {2048, 0},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-50, 50, 0},0, {0, 0},{0xFF, 0xFF, 0xFF, 0xFF}}},
};

Vtx custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_inv_layer_4_mario_vtx_0[4] = {
	{{{50, 100, 0},0, {0, 1024},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-50, 100, 0},0, {2048, 1024},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-50, 150, 0},0, {2048, 0},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{50, 150, 0},0, {0, 0},{0xFF, 0xFF, 0xFF, 0xFF}}},
};
Vtx custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_inv_layer_4_mario_vtx_1[4] = {
	{{{50, 50, 0},0, {0, 1024},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-50, 50, 0},0, {2048, 1024},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-50, 100, 0},0, {2048, 0},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{50, 100, 0},0, {0, 0},{0xFF, 0xFF, 0xFF, 0xFF}}},
};
Vtx custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_inv_layer_4_mario_vtx_2[4] = {
	{{{50, 0, 0},0, {0, 1024},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-50, 0, 0},0, {2048, 1024},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-50, 50, 0},0, {2048, 0},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{50, 50, 0},0, {0, 0},{0xFF, 0xFF, 0xFF, 0xFF}}},
};

Gfx custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_layer_4_mario_tri_0[] = {
	gsSPVertex(custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_layer_4_mario_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};
Gfx custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_layer_4_mario_tri_1[] = {
	gsSPVertex(custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_layer_4_mario_vtx_1 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};
Gfx custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_layer_4_mario_tri_2[] = {
	gsSPVertex(custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_layer_4_mario_vtx_2 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_inv_layer_4_mario_tri_0[] = {
	gsSPVertex(custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_inv_layer_4_mario_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};
Gfx custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_inv_layer_4_mario_tri_1[] = {
	gsSPVertex(custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_inv_layer_4_mario_vtx_1 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};
Gfx custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_inv_layer_4_mario_tri_2[] = {
	gsSPVertex(custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_inv_layer_4_mario_vtx_2 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_custom_mario_death_sprite_DeathSprite_Icon_mario_0[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK | G_ZBUFFER),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, custom_mario_death_sprite_mariosad_0_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0),
	gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 64 * 32 - 1, CALC_DXT(64, G_IM_SIZ_16b_BYTES)),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0),
    gsDPSetTileSize(0, 0, 0, (64 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
	gsSPEndDisplayList(),
};
Gfx mat_custom_mario_death_sprite_DeathSprite_Icon_mario_1[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK | G_ZBUFFER),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, custom_mario_death_sprite_mariosad_1_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0),
	gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 64 * 32 - 1, CALC_DXT(64, G_IM_SIZ_16b_BYTES)),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0),
    gsDPSetTileSize(0, 0, 0, (64 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
	gsSPEndDisplayList(),
};
Gfx mat_custom_mario_death_sprite_DeathSprite_Icon_mario_2[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK | G_ZBUFFER),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, custom_mario_death_sprite_mariosad_2_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0),
	gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 64 * 32 - 1, CALC_DXT(64, G_IM_SIZ_16b_BYTES)),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0),
    gsDPSetTileSize(0, 0, 0, (64 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
	gsSPEndDisplayList(),
};

Gfx mat_revert_custom_mario_death_sprite_DeathSprite_Icon[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK | G_ZBUFFER),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPEndDisplayList(),
};

Gfx custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_layer_4_mario[] = {
	gsSPDisplayList(mat_custom_mario_death_sprite_DeathSprite_Icon_mario_2),
	gsSPDisplayList(custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_layer_4_mario_tri_2),
	gsSPDisplayList(mat_custom_mario_death_sprite_DeathSprite_Icon_mario_1),
	gsSPDisplayList(custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_layer_4_mario_tri_1),
	gsSPDisplayList(mat_custom_mario_death_sprite_DeathSprite_Icon_mario_0),
	gsSPDisplayList(custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_layer_4_mario_tri_0),
	gsSPDisplayList(mat_revert_custom_mario_death_sprite_DeathSprite_Icon),
	gsSPEndDisplayList(),
};

Gfx custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_inv_layer_4_mario[] = {
	gsSPDisplayList(mat_custom_mario_death_sprite_DeathSprite_Icon_mario_2),
	gsSPDisplayList(custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_inv_layer_4_mario_tri_2),
	gsSPDisplayList(mat_custom_mario_death_sprite_DeathSprite_Icon_mario_1),
	gsSPDisplayList(custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_inv_layer_4_mario_tri_1),
	gsSPDisplayList(mat_custom_mario_death_sprite_DeathSprite_Icon_mario_0),
	gsSPDisplayList(custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_inv_layer_4_mario_tri_0),
	gsSPDisplayList(mat_revert_custom_mario_death_sprite_DeathSprite_Icon),
	gsSPEndDisplayList(),
};

Gfx custom_mario_death_sprite_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

