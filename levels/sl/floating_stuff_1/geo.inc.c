#include "src/game/envfx_snow.h"

const GeoLayout floating_stuff_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, floating_stuff_1_Plane_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, floating_stuff_1_Plane_002_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, floating_stuff_1_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, floating_stuff_1_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
