#include "src/game/envfx_snow.h"

const GeoLayout cq_bridge_geo[] = {
	GEO_CULLING_RADIUS(32767),
	GEO_OPEN_NODE(),
		GEO_RENDER_RANGE(0, 32767),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, cq_bridge_bridge_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cq_bridge_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
