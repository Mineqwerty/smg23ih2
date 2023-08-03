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
#include "levels/ttc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ttc_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ttc_segment_7SegmentRomStart, _ttc_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _machine_yay0SegmentRomStart, _machine_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xa, _bitfs_skybox_yay0SegmentRomStart, _bitfs_skybox_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	LOAD_MODEL_FROM_GEO(MODEL_GLAGGLE_CUBE, glaggle_cube_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GIGGLER, giggler_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GIGGLE_SUN, giggle_sun_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ttc_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_GLAGGLE_CUBE, -2114, 795, 551, 0, 0, 0, (20 << 16), bhvFloatInPlace),
		OBJECT(MODEL_GIGGLE_SUN, -3087, 1315, 3599, 0, 0, 0, 0x00000000, bhvRotateInPlace),
		OBJECT(MODEL_GIGGLE_SUN, -3993, 1056, -2884, 0, -47, 0, 0x00000000, bhvRotateInPlace),
		OBJECT(MODEL_GIGGLE_SUN, 4194, 705, 3718, 0, -171, 0, 0x00000000, bhvRotateInPlace),
		OBJECT(MODEL_GIGGLER, 212, 0, 3586, 0, 0, 0, 0x00000000, bhvGiggler),
		OBJECT(MODEL_GIGGLER, 1291, 292, 1752, 0, 0, 0, 0x00000000, bhvGiggler),
		OBJECT(MODEL_GIGGLER, -3503, 364, 953, 0, 0, 0, 0x00000000, bhvGiggler),
		OBJECT(MODEL_GIGGLER, -1076, 112, -3053, 0, 0, 0, 0x00000000, bhvGiggler),
		OBJECT(MODEL_GIGGLER, 3093, 2103, -770, 0, 0, 0, 0x00000000, bhvGiggler),
		OBJECT(MODEL_NONE, -390, 2497, 3401, 0, 0, 0, 0x00000000, bhvGlaggleland),
		OBJECT(MODEL_STAR, 8050, 100, -3113, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 200, 0),
		TERRAIN(ttc_area_1_collision),
		MACRO_OBJECTS(ttc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_STREAMED_GLAGGLELAND),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 200, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
