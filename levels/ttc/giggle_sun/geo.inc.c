#include "src/game/envfx_snow.h"

const GeoLayout giggle_sun_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, giggle_sun_Plane_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, giggle_sun_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
