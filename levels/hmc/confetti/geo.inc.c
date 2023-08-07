#include "src/game/envfx_snow.h"

const GeoLayout confetti_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
    	GEO_BILLBOARD(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_confetti),
			GEO_SWITCH_CASE(8, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_ALPHA, confetti_conf_0_mesh_layer_4),
				GEO_DISPLAY_LIST(LAYER_ALPHA, confetti_conf_1_mesh_layer_4),
				GEO_DISPLAY_LIST(LAYER_ALPHA, confetti_conf_2_mesh_layer_4),
				GEO_DISPLAY_LIST(LAYER_ALPHA, confetti_conf_3_mesh_layer_4),
				GEO_DISPLAY_LIST(LAYER_ALPHA, confetti_conf_4_mesh_layer_4),
				GEO_DISPLAY_LIST(LAYER_ALPHA, confetti_conf_5_mesh_layer_4),
				GEO_DISPLAY_LIST(LAYER_ALPHA, confetti_conf_6_mesh_layer_4),
				GEO_DISPLAY_LIST(LAYER_ALPHA, confetti_conf_7_mesh_layer_4),
			GEO_CLOSE_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, confetti_material_revert_render_settings),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
