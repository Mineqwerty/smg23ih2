#include "src/game/envfx_snow.h"

const GeoLayout title_sponge_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, title_sponge_Plane_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, title_sponge_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
