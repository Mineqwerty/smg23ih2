Gfx custom_mario_death_sprite_mario_sprite_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 custom_mario_death_sprite_mario_sprite_rgba16[] = {
	#include "actors/custom_mario_death_sprite/mario_death_sprite.rgba16.inc.c"
};

Vtx custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_layer_4_mario_vtx_0[4] = {
	{{{-80, 0, 0},0, {0, 1024},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{80, 0, 0},0, {1024, 1024},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{80, 160, 0},0, {1024, 0},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-80, 160, 0},0, {0, 0},{0xFF, 0xFF, 0xFF, 0xFF}}},
};

Gfx custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_layer_4_mario_tri_0[] = {
	gsSPVertex(custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_layer_4_mario_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_custom_mario_death_sprite_DeathSprite_Icon_mario[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK | G_ZBUFFER),
	gsDPSetTextureFilter(G_TF_POINT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, custom_mario_death_sprite_mario_sprite_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_custom_mario_death_sprite_DeathSprite_Icon[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK | G_ZBUFFER),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPEndDisplayList(),
};

Gfx custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_layer_4_mario[] = {
	gsSPDisplayList(mat_custom_mario_death_sprite_DeathSprite_Icon_mario),
	gsSPDisplayList(custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_layer_4_mario_tri_0),
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

