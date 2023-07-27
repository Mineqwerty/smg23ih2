Vtx selectBox_selectWheel_002_mesh_vtx_0[4] = {
	{{ {-219, -19, 5}, 0, {-16, 1008}, {0, 0, 0, 189} }},
	{{ {225, -19, 5}, 0, {1008, 1008}, {0, 0, 0, 189} }},
	{{ {225, 19, 5}, 0, {1008, -16}, {0, 0, 0, 189} }},
	{{ {-219, 19, 5}, 0, {-16, -16}, {0, 0, 0, 189} }},
};

Gfx selectBox_selectWheel_002_mesh_tri_0[] = {
	gsSPVertex(selectBox_selectWheel_002_mesh_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_selectBox_f3dlite_material_002[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, SHADE, 0, PRIMITIVE, 0, 0, 0, 0, SHADE, SHADE, 0, PRIMITIVE, 0),
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_selectBox_f3dlite_material_002[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx selectBox_selectWheel_002_mesh[] = {
	gsSPDisplayList(mat_selectBox_f3dlite_material_002),
	gsSPDisplayList(selectBox_selectWheel_002_mesh_tri_0),
	gsSPDisplayList(mat_revert_selectBox_f3dlite_material_002),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};

