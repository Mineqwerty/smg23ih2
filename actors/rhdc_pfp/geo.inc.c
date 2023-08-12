const GeoLayout rhdc_pfp_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rhdc_pfp_mesh_layer_4_start),
	  GEO_ASM(0, geo_rhdc_pfp),
	  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rhdc_pfp_mesh_layer_4),
	  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rhdc_pfp_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
