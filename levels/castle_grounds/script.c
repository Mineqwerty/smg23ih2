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
#include "levels/castle_grounds/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _outside_yay0SegmentRomStart, _outside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group10_yay0SegmentRomStart, _group10_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group10_geoSegmentRomStart, _group10_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_11), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, castle_grounds_geo_0006F4), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_METAL_DOOR, metal_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_VCUTM_GRILL, castle_grounds_geo_00070C), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_FLAG, castle_grounds_geo_000660), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CANNON_GRILL, castle_grounds_geo_000724), 
	LOAD_MODEL_FROM_GEO(MODEL_TROLL_WATER_LEVEL, troll_water_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SPONGE_CIRCLE, sponge_circle_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_grounds_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_EXCLAMATION_BOX, -3697, 212, -1218, 0, 0, 0, (9 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -3810, 212, -1218, 0, 0, 0, (9 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -3810, 212, -1341, 0, 0, 0, (9 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -3574, 212, -1341, 0, 0, 0, (9 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -3574, 212, -1216, 0, 0, 0, (9 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -3697, 355, -1345, 0, 0, 0, (9 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -3697, 212, -1480, 0, 0, 0, (9 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -3810, 212, -1480, 0, 0, 0, (9 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -3574, 212, -1478, 0, 0, 0, (9 << 16), bhvExclamationBox),
		OBJECT(MODEL_CAPPY, -6486, 212, 10452, 0, 180, 0, (15 << 16), bhvBreakableBoxSmall),
		OBJECT(MODEL_NONE, 2307, -1311, -1565, 0, 0, 0, 0x00000000, bhvIntroScene),
		OBJECT(MODEL_CHUCKYA, -5056, 212, -36, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, -1, 100, 5, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, -2309, 212, -795, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_GOOMBA, 4018, 212, 9891, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -5728, 212, 6680, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, -7515, 212, 4928, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_NONE, -385, 1248, 17540, 0, 0, 0, 0x00000000, bhvEnemyLakitu),
		OBJECT(MODEL_MARIOS_METAL_CAP, 5341, -1311, 1606, 0, 0, 0, 0x00000000, bhvMetalCap),
		OBJECT(MODEL_RED_COIN, 4907, 212, 6329, 0, 0, 0, 0x00000000, bhvMoneybagHidden),
		OBJECT(MODEL_RED_COIN, -3697, 214, -1345, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_FLYGUY, -1612, 1003, 3869, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_RED_COIN, -4443, 360, -1345, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3568, -1289, -4368, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1362, 799, 10289, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3359, 1197, 12206, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -30, 799, 17616, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -7001, 1425, 2062, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_WOODEN_SIGNPOST, 5034, -1311, 1611, 0, -90, 0, (16 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, -6486, 212, 9984, 0, 180, 0, (15 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, 4810, 212, 9565, 0, -155, 0, (18 << 16), bhvMessagePanel),
		OBJECT(MODEL_SPONGE_CIRCLE, 3468, -10763, -4312, 0, 0, 0, 0x00000000, bhvSpongeCircle),
		OBJECT(MODEL_SPONGE_CIRCLE, 3468, -10763, -4312, 0, 0, 0, 0x00000000, bhvSpongeCircle),
		OBJECT(MODEL_SPONGE_CIRCLE, 3468, -10763, -4312, 0, 0, 0, 0x00000000, bhvSpongeCircle),
		OBJECT(MODEL_SPONGE_CIRCLE, 3468, -10763, -2057, 0, 0, 0, 0x00000000, bhvSpongeCircle),
		OBJECT(MODEL_SPONGE_CIRCLE, 3468, -10763, -2057, 0, 0, 0, 0x00000000, bhvSpongeCircle),
		OBJECT(MODEL_SPONGE_CIRCLE, 3468, -10763, -2057, 0, 0, 0, 0x00000000, bhvSpongeCircle),
		OBJECT(MODEL_STAR, 3568, -1155, -6158, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, -6995, 212, 2056, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_TROLL_WATER_LEVEL, 3503, -1289, -3281, 0, 0, 0, 0x00000000, bhvTrollWaterLevel),
		OBJECT(MODEL_NONE, -1328, 212, 4664, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, -180, -1328, 212, 4664),
		OBJECT(MODEL_NONE, -5055, -1499, 118, 0, 0, 0, 0x00000000, bhvWaterLevelDiamond),
		OBJECT(MODEL_NONE, 2469, -1311, -1383, 0, 0, 0, 0x00000000, bhvInitializeChangingWaterLevel),
		OBJECT(MODEL_NONE, 2133, -1311, -1424, 0, 0, 0, 0x00000000, bhvEndlessStairsMusicController),
		TERRAIN(castle_grounds_area_1_collision),
		MACRO_OBJECTS(castle_grounds_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, -1328, 212, 4664),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
