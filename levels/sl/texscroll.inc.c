void scroll_gfx_mat_sl_dl_f3dlite_material_010() {
	Gfx *mat = segmented_to_virtual(mat_sl_dl_f3dlite_material_010);


	shift_s(mat, 9, PACK_TILESIZE(0, 2));
	shift_t_down(mat, 9, PACK_TILESIZE(0, 2));
	shift_s_down(mat, 11, PACK_TILESIZE(0, 1));
	shift_t(mat, 11, PACK_TILESIZE(0, 1));

};

void scroll_sl() {
	scroll_gfx_mat_sl_dl_f3dlite_material_010();
};
