#include "src/game/envfx_snow.h"

const GeoLayout cowardly_maya_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, cowardly_maya_root_mesh_layer_4),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -62, -39, 101, 4, 3, 36),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, cowardly_maya_armR_mesh_layer_1),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, cowardly_maya_foreArmR_skinned_mesh_layer_1),
					GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 132, 0, 5, 0, -2),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, cowardly_maya_foreArmR_mesh_layer_1),
						GEO_OPEN_NODE(),
							GEO_DISPLAY_LIST(LAYER_OPAQUE, cowardly_maya_handR_skinned_mesh_layer_1),
							GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 67, 0, -2, 1, 7),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, cowardly_maya_handR_mesh_layer_1),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 64, -39, 101, 7, 3, -35),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, cowardly_maya_armR_001_mesh_layer_1),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, cowardly_maya_foreArmR_001_skinned_mesh_layer_1),
					GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 132, 0, 4, 14, 4),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, cowardly_maya_foreArmR_001_mesh_layer_1),
						GEO_OPEN_NODE(),
							GEO_DISPLAY_LIST(LAYER_OPAQUE, cowardly_maya_handR_001_skinned_mesh_layer_1),
							GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 67, 0, -4, -37, -6),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, cowardly_maya_handR_001_mesh_layer_1),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, cowardly_maya_head_skinned_mesh_layer_4),
			GEO_ANIMATED_PART(LAYER_ALPHA, 0, 62, 0, cowardly_maya_head_mesh_layer_4),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, cowardly_maya_head_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cowardly_maya_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, cowardly_maya_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};