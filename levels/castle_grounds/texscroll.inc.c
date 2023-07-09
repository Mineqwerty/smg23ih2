void scroll_castle_grounds_dl_Plane_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 4;
	int height = 128 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(castle_grounds_dl_Plane_mesh_layer_1_vtx_3);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_castle_grounds() {
	scroll_castle_grounds_dl_Plane_mesh_layer_1_vtx_3();
};
