Vtx rhdc_pfp_RHDCSprite_RHDCSprite_mesh_layer_4_vtx_0[4] = {
	{{{-200, -200, 0},0, {0, 1024},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{200, -200, 0},0, {1024, 1024},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{200, 200, 0},0, {1024, 0},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-200, 200, 0},0, {0, 0},{0x0, 0x0, 0x7F, 0xFF}}},
};

Gfx rhdc_pfp_RHDCSprite_RHDCSprite_mesh_layer_4_tri_0[] = {
	gsSPVertex(rhdc_pfp_RHDCSprite_RHDCSprite_mesh_layer_4_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_rhdc_pfp_Icon_start[] = {
	gsDPPipeSync(),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_rhdc_pfp_Icon[] = {
	gsDPTileSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_32b_BYTES)),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_32b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
	gsSPEndDisplayList(),
};

Gfx mat_revert_rhdc_pfp_RHDCSprite_Icon[] = {
	gsDPPipeSync(),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsSPEndDisplayList(),
};

Gfx rhdc_pfp_mesh_layer_4_start[] = {
	gsSPDisplayList(mat_rhdc_pfp_Icon_start),
	gsSPEndDisplayList(),
};

Gfx rhdc_pfp_mesh_layer_4[] = {
	gsSPDisplayList(mat_rhdc_pfp_Icon),
	gsSPDisplayList(rhdc_pfp_RHDCSprite_RHDCSprite_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_rhdc_pfp_RHDCSprite_Icon),
	gsSPEndDisplayList(),
};

Gfx rhdc_pfp_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

