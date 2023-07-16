const GeoLayout mario_maker_laugh_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	  GEO_BILLBOARD(),
	  GEO_SWITCH_CASE(3, geo_switch_anim_state),
	  GEO_OPEN_NODE(),
	    GEO_DISPLAY_LIST(LAYER_FORCE_ALPHA_ON_TOP, mario_maker_laugh_pink_mesh_layer_4_mario),
	    GEO_DISPLAY_LIST(LAYER_FORCE_ALPHA_ON_TOP, mario_maker_laugh_blue_mesh_layer_4_mario),
	    GEO_DISPLAY_LIST(LAYER_FORCE_ALPHA_ON_TOP, mario_maker_laugh_yellow_mesh_layer_4_mario),
	  GEO_CLOSE_NODE(),
	  GEO_DISPLAY_LIST(LAYER_FORCE_ALPHA_ON_TOP, mario_maker_laugh_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
