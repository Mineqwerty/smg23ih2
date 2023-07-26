
Vtx cq_red_cube_Cube_mesh_layer_1_vtx_0[24] = {
	{{ {-63, 4, 63}, 0, {499, 973}, {129, 0, 0, 255} }},
	{{ {-63, 129, 63}, 0, {663, 973}, {129, 0, 0, 255} }},
	{{ {-63, 129, -63}, 0, {676, 761}, {129, 0, 0, 255} }},
	{{ {-63, 4, -63}, 0, {506, 761}, {129, 0, 0, 255} }},
	{{ {-63, 4, -63}, 0, {506, 761}, {0, 0, 129, 255} }},
	{{ {-63, 129, -63}, 0, {676, 761}, {0, 0, 129, 255} }},
	{{ {63, 129, -63}, 0, {600, 479}, {0, 0, 129, 255} }},
	{{ {63, 4, -63}, 0, {518, 479}, {0, 0, 129, 255} }},
	{{ {63, 4, -63}, 0, {518, 479}, {127, 0, 0, 255} }},
	{{ {63, 129, -63}, 0, {600, 479}, {127, 0, 0, 255} }},
	{{ {63, 129, 63}, 0, {600, 253}, {127, 0, 0, 255} }},
	{{ {63, 4, 63}, 0, {517, 253}, {127, 0, 0, 255} }},
	{{ {63, 4, 63}, 0, {517, 253}, {0, 0, 127, 255} }},
	{{ {63, 129, 63}, 0, {600, 253}, {0, 0, 127, 255} }},
	{{ {-63, 129, 63}, 0, {691, 14}, {0, 0, 127, 255} }},
	{{ {-63, 4, 63}, 0, {510, 14}, {0, 0, 127, 255} }},
	{{ {-63, 4, -63}, 0, {122, 457}, {0, 129, 0, 255} }},
	{{ {63, 4, -63}, 0, {518, 479}, {0, 129, 0, 255} }},
	{{ {63, 4, 63}, 0, {517, 253}, {0, 129, 0, 255} }},
	{{ {-63, 4, 63}, 0, {122, 279}, {0, 129, 0, 255} }},
	{{ {63, 129, -63}, 0, {600, 479}, {0, 127, 0, 255} }},
	{{ {-63, 129, -63}, 0, {850, 457}, {0, 127, 0, 255} }},
	{{ {-63, 129, 63}, 0, {850, 279}, {0, 127, 0, 255} }},
	{{ {63, 129, 63}, 0, {600, 253}, {0, 127, 0, 255} }},
};

Gfx cq_red_cube_Cube_mesh_layer_1_tri_0[] = {
	gsSPVertex(cq_red_cube_Cube_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(cq_red_cube_Cube_mesh_layer_1_vtx_0 + 16, 8, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSPEndDisplayList(),
};


Gfx mat_cq_red_cube_f3dlite_material_010[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
    gsSPLightColor(LIGHT_1, 0xff0008ff),
    gsSPLightColor(LIGHT_2, 0x7f0002ff),
	gsSPEndDisplayList(),
};

Gfx cq_red_cube_Cube_mesh_layer_1[] = {
	gsSPDisplayList(mat_cq_red_cube_f3dlite_material_010),
	gsSPDisplayList(cq_red_cube_Cube_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx cq_red_cube_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

