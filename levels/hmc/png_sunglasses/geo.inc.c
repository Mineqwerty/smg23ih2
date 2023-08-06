#include "src/game/envfx_snow.h"

const GeoLayout png_sunglasses_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, png_sunglasses_png_sunglasses_sprite_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, png_sunglasses_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
