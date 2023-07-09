#include "src/game/envfx_snow.h"

const GeoLayout sponge_circle_geo[] = {
	GEO_CULLING_RADIUS(32767),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sponge_circle_Circle_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sponge_circle_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
