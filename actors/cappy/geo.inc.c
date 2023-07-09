#include "src/game/envfx_snow.h"

const GeoLayout cappy_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cappy_CapManHero__HeadMT_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cappy_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
