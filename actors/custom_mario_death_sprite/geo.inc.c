const GeoLayout custom_mario_death_sprite_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	  GEO_BILLBOARD(),
	  GEO_DISPLAY_LIST(LAYER_FORCE_ALPHA_ON_TOP, custom_mario_death_sprite_DeathSprite_DeathSprite_mesh_layer_4_mario),
	  GEO_DISPLAY_LIST(LAYER_FORCE_ALPHA_ON_TOP, custom_mario_death_sprite_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
