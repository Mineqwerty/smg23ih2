#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/ssl/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ssl_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ssl_segment_7SegmentRomStart, _ssl_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _ssl_skybox_yay0SegmentRomStart, _ssl_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group5_yay0SegmentRomStart, _group5_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group5_geoSegmentRomStart, _group5_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_6), 
    LOAD_MODEL_FROM_GEO(MODEL_CUSTOM_DOOR_A, custom_door_a_geo),
    LOAD_MODEL_FROM_GEO(MODEL_PORTAL_WARP, custom_portal_w_geo),
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PALM_TREE, palm_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, ssl_geo_0005C0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, ssl_geo_0005D8), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PYRAMID_TOP, ssl_geo_000618), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_GRINDEL, ssl_geo_000734), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_SPINDEL, ssl_geo_000764), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_MOVING_PYRAMID_WALL, ssl_geo_000794), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PYRAMID_ELEVATOR, ssl_geo_0007AC), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_TOX_BOX, ssl_geo_000630), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ssl_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xBA, LEVEL_SSL, 0x01, 0xBA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xBB, LEVEL_SSL, 0x01, 0xBB, WARP_NO_CHECKPOINT),
		WARP_NODE(0xCA, LEVEL_JRB, 0x01, 0xBB, WARP_NO_CHECKPOINT),
		WARP_NODE(0xDA, LEVEL_DDD, 0x01, 0xDA, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x01, 15400, 0, 0),
		INSTANT_WARP(0x01, 0x01, -15400, 0, 0),
		OBJECT(MODEL_CUSTOM_DOOR_A, 0, 0, -2110, 0, 0, 0, 0x00DA0000, bhvStaticDoor),
		OBJECT(MODEL_NONE, -400, 690, 1300, 0, -180, 0, 0x00BA0000, bhvFadingWarp),
		MARIO_POS(0x01, -180, -400, -20, 800),
		OBJECT(MODEL_NONE, -400, -20, 800, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_PORTAL_WARP, -400, -20, 4000, 0, 0, 0, 0x00000000, bhvStaticPortal),
		TERRAIN(ssl_area_1_collision),
		MACRO_OBJECTS(ssl_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		SET_BACKGROUND_MUSIC_WITH_REVERB(0x00, SEQ_LEVEL_ALONE_ELISE, 0x05, 0x05),
		SET_ECHO(0x16, 0x16),
		OBJECT(MODEL_WOODEN_SIGNPOST, -400, -20, 4250, 0, -180, 0, (DIALOG_004 << 16), bhvMessagePanel),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, -400, -20, 800),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
