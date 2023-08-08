
Gfx png_sunglasses_png_sunglasses_ci4_aligner[] = {gsSPEndDisplayList()};
u8 png_sunglasses_png_sunglasses_ci4[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 
	0x00, 0x00, 0x11, 0x21, 0x21, 0x11, 0x11, 0x11, 
	0x11, 0x11, 0x21, 0x12, 0x11, 0x11, 0x11, 0x10, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x12, 0x12, 0x11, 0x11, 0x11, 
	0x11, 0x11, 0x12, 0x11, 0x21, 0x11, 0x11, 0x10, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x11, 0x21, 0x21, 0x11, 0x11, 
	0x10, 0x01, 0x11, 0x21, 0x12, 0x11, 0x11, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x11, 0x11, 0x11, 0x11, 
	0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x10, 
	0x00, 0x00, 0x01, 0x11, 0x11, 0x11, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	
};

Gfx png_sunglasses_png_sunglasses_ci4_pal_ia16_aligner[] = {gsSPEndDisplayList()};
u8 png_sunglasses_png_sunglasses_ci4_pal_ia16[] = {
	0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 
};

Vtx png_sunglasses_png_sunglasses_sprite_mesh_layer_4_vtx_0[4] = {
	{{ {-64, -8, 0}, 0, {0, 256}, {0, 0, 127, 255} }},
	{{ {64, -8, 0}, 0, {2048, 256}, {0, 0, 127, 255} }},
	{{ {64, 8, 0}, 0, {2048, 0}, {0, 0, 127, 255} }},
	{{ {-64, 8, 0}, 0, {0, 0}, {0, 0, 127, 255} }},
};

Gfx png_sunglasses_png_sunglasses_sprite_mesh_layer_4_tri_0[] = {
	gsSPVertex(png_sunglasses_png_sunglasses_sprite_mesh_layer_4_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};


Gfx mat_png_sunglasses_png_sunglasses[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, SHADE, TEXEL0_ALPHA, SHADE, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, SHADE, TEXEL0_ALPHA, SHADE, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetTextureFilter(G_TF_POINT),
	gsSPTexture(65535, 65535, 0, 0, 1),
    gsSPLightColor(LIGHT_1, 0xffffffff),
    gsSPLightColor(LIGHT_2, 0x7f7f7fff),
	gsDPSetTextureLUT(G_TT_IA16),
	gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_16b, 1, png_sunglasses_png_sunglasses_ci4_pal_ia16),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(7, 2),
	gsDPLoadSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, png_sunglasses_png_sunglasses_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 3, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0),
	gsDPLoadBlock(7, 0, 0, 127, 512),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 4, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 3, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 28),
	gsSPEndDisplayList(),
};

Gfx mat_revert_png_sunglasses_png_sunglasses[] = {
	gsDPPipeSync(),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx png_sunglasses_png_sunglasses_sprite_mesh_layer_4[] = {
	gsSPDisplayList(mat_png_sunglasses_png_sunglasses),
	gsSPDisplayList(png_sunglasses_png_sunglasses_sprite_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_png_sunglasses_png_sunglasses),
	gsSPEndDisplayList(),
};

Gfx png_sunglasses_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};
