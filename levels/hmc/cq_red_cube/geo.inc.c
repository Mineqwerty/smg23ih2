#include "src/game/envfx_snow.h"

const GeoLayout cq_red_cube_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cq_red_cube_Cube_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cq_red_cube_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
