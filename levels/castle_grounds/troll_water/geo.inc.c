#include "src/game/envfx_snow.h"

const GeoLayout troll_water_geo[] = {
	GEO_CULLING_RADIUS(32767),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, troll_water_Plane_001_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, troll_water_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
