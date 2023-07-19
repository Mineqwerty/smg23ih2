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
#include "levels/wf/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wf_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _grass_yay0SegmentRomStart, _grass_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, wf_geo_0007E0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, wf_geo_000820), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, wf_geo_000860), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, wf_geo_000878), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, wf_geo_000890), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_08, wf_geo_0008A8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_09, wf_geo_0008E8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0A, wf_geo_000900), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0C, wf_geo_000940), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_GIANT_POLE, wf_geo_000AE0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0E, wf_geo_000958), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0F, wf_geo_0009A0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_PLATFORM, wf_geo_0009B8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_11, wf_geo_0009D0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_12, wf_geo_0009E8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_SMALL_BOMP, wf_geo_000A00), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_LARGE_BOMP, wf_geo_000A40), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_WOODEN_PLATFORM, wf_geo_000A58), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_SLIDING_PLATFORM, wf_geo_000A98), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE_PART, wf_geo_000AB0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE, wf_geo_000AC8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_TRAPEZOID_PLATORM, wf_geo_000AF8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM, wf_geo_000B10), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM_UNUSED, wf_geo_000B38), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM_ELEVATOR, wf_geo_000B60), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BREAKABLE_WALL_RIGHT, wf_geo_000B78), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BREAKABLE_WALL_LEFT, wf_geo_000B90), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_KICKABLE_BOARD, wf_geo_000BA8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_DOOR, wf_geo_000BE0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_KICKABLE_BOARD_FELLED, wf_geo_000BC8), 
	LOAD_MODEL_FROM_GEO(MODEL_GLOBAL_DOOR, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FUNNYBOX, funny_box_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SLIDING_FLOOR, sliding_floor_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GASLIGHT_BLOCK, gaslight_block_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SQUID_WORD, squid_word_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wf_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -23, 67, -7, 0, -180, 0, (250), bhvCheckpoint),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, -180, 0, 200, 0),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, 0x00000000, bhvShellTrollWarpHandler),
		TERRAIN(wf_area_1_collision),
		MACRO_OBJECTS(wf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_EVENT_POWERUP),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, wf_area_2),
		WARP_NODE(0x0A, LEVEL_WF, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WF, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_WF, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_GLOBAL_DOOR, -590, 83, -9402, 0, 90, 0, (11 << 16), bhvDoorWarp),
		OBJECT(MODEL_NONE, -3907, 829, -9771, 0, 90, 0, (11 << 16), bhvDoorWarp),
		OBJECT(MODEL_NONE, -4998, 829, -6269, 0, 90, 0, (11 << 16), bhvDoorWarp),
		OBJECT(MODEL_NONE, -4577, 829, -6269, 0, 90, 0, (11 << 16), bhvDoorWarp),
		OBJECT(MODEL_NONE, -4790, 829, -6025, 0, -180, 0, (11 << 16), bhvDoorWarp),
		OBJECT(MODEL_NONE, -4489, 829, -3241, 0, -180, 0, (11 << 16), bhvDoorWarp),
		OBJECT(MODEL_NONE, -5123, 829, -3241, 0, -180, 0, (11 << 16), bhvDoorWarp),
		OBJECT(MODEL_WOODEN_SIGNPOST, -524, 67, -7, 0, 90, 0, (32 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, -2701, 2094, 7008, 0, -90, 0, (37 << 16), bhvMessagePanel),
		OBJECT(MODEL_GASLIGHT_BLOCK, -4815, 749, 965, 0, 0, 0, (0 << 16), bhvGaslightBlock),
		OBJECT(MODEL_GASLIGHT_BLOCK, -4815, 749, 1911, 0, 0, 0, (1 << 16), bhvGaslightBlock),
		OBJECT(MODEL_GASLIGHT_BLOCK, -4815, 749, 2770, 0, 0, 0, (2 << 16), bhvGaslightBlock),
		OBJECT(MODEL_GASLIGHT_BLOCK, -4815, 749, 3621, 0, 0, 0, (3 << 16), bhvGaslightBlock),
		OBJECT(MODEL_GASLIGHT_BLOCK, -4815, 749, 4461, 0, 0, 0, (4 << 16), bhvGaslightBlock),
		OBJECT(MODEL_NONE, -4815, 1756, 2770, 0, 0, 0, 0x00000000, bhvGaslightManager),
		OBJECT(MODEL_HIDDEN_BLOCK, 913, 282, -6437, 0, 90, 0, (6), bhvHiddenBlock),
		OBJECT(MODEL_HIDDEN_BLOCK, 609, 282, -6437, 0, 90, 0, (6), bhvHiddenBlock),
		OBJECT(MODEL_HIDDEN_BLOCK, -2748, 781, -9307, 0, 90, 0, (30), bhvHiddenBlock),
		OBJECT(MODEL_HIDDEN_BLOCK, -4583, 1132, 6834, 0, 90, 0, (1 << 16) | (6), bhvHiddenBlock),
		OBJECT(MODEL_HIDDEN_BLOCK, -4583, 1132, 7138, 0, 90, 0, (1 << 16) | (6), bhvHiddenBlock),
		OBJECT(MODEL_HIDDEN_BLOCK, -1737, 2330, 6995, 0, 90, 0, 0x00000000, bhvHiddenBlock),
		OBJECT(MODEL_HIDDEN_BLOCK, 609, 282, -6741, 0, 90, 0, (6), bhvHiddenBlock),
		OBJECT(MODEL_HIDDEN_BLOCK, 913, 282, -6741, 0, 90, 0, (6), bhvHiddenBlock),
		OBJECT(MODEL_HIDDEN_BLOCK, -4583, 1280, 6834, 0, 90, 0, (1 << 16) | (6), bhvHiddenBlock),
		OBJECT(MODEL_HIDDEN_BLOCK, -4583, 1280, 7138, 0, 90, 0, (1 << 16) | (6), bhvHiddenBlock),
		OBJECT(MODEL_SLIDING_FLOOR, -4815, 749, -4576, 0, 0, 0, 0x00000000, bhvSlidingFloor),
		OBJECT(MODEL_STAR, -1761, 2469, 6993, 0, -90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 200, 0),
		TERRAIN(wf_area_2_collision),
		MACRO_OBJECTS(wf_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_SHIT_BROS_3),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */

		OBJECT(MODEL_THWOMP, -4815, 1729, -320, 0, 180, 0, 0x00800000, bhvOffscreenThwomp),
		OBJECT(MODEL_HIDDEN_BLOCK, -2456, 829, -9780, 0, 0, 0, (6), bhvHiddenBlock),
		OBJECT(MODEL_BREAKABLE_BOX, -4815, 829, -9365, 0, 0, 0, BP(0, BREAKABLE_BOX_BP_LARGE, 1, 0), bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -4815, 829, -9023, 0, 0, 0, BP(0, BREAKABLE_BOX_BP_LARGE, 1, 0), bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -4815, 829, -8681, 0, 0, 0, BP(0, BREAKABLE_BOX_BP_LARGE, 1, 0), bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -4815, 829, -8339, 0, 0, 0, BP(0, BREAKABLE_BOX_BP_LARGE, 2, 0), bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -4815, 829, -7997, 0, 0, 0, BP(0, BREAKABLE_BOX_BP_LARGE, 1, 0), bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -4815, 829, -7655, 0, 0, 0, BP(0, BREAKABLE_BOX_BP_LARGE, 1, 0), bhvBreakableBox),
		OBJECT(MODEL_BLACK_BOBOMB, -4815, 829, -9780, 0, 90, 0, BP(0, BOBOMB_BP_STYPE_STATIONARY, 0, 0), bhvBobomb),

		// NOTE: PLEASE REMOVE EVERYTHING BELOW HERE FROM BLENDER MODEL!!!!!!!

		// All checkpoints
		OBJECT(MODEL_NONE, -23, 67, -7, 0, 0, 0, (1 << 16) | 250, bhvCheckpoint),
		OBJECT(MODEL_NONE, 757, 83, -7733, 0, 0, 0, (2 << 16) | 1500, bhvCheckpoint),
		OBJECT(MODEL_NONE, -4815, 829, -6271, 0, 180, 0, (3 << 16) | 1000, bhvCheckpoint),
		OBJECT(MODEL_NONE, -4815, 829, -600, 0, 180, 0, (4 << 16) | 1500, bhvCheckpoint),
		OBJECT(MODEL_NONE, -4815, 829, 6506, 0, 180, 0, (5 << 16) | 1500, bhvCheckpoint),

		// Hidden blocks after bomb excavation
		OBJECT(MODEL_HIDDEN_BLOCK, -4663, 1060, -7320, 0, 0, 0, BP(0, 0, 0x08, 6), bhvHiddenBlock),
		OBJECT(MODEL_HIDDEN_BLOCK, -4813, 1060, -7320, 0, 0, 0, BP(0, 0, 0x08, 6), bhvHiddenBlock),
		OBJECT(MODEL_HIDDEN_BLOCK, -4967, 1060, -7320, 0, 0, 0, BP(0, 0, 0x08, 6), bhvHiddenBlock),
		OBJECT(MODEL_HIDDEN_BLOCK, -4663, 1060, -7168, 0, 0, 0, BP(0, 0, 0x08, 6), bhvHiddenBlock),
		OBJECT(MODEL_HIDDEN_BLOCK, -4813, 1060, -7168, 0, 0, 0, BP(0, 0, 0x08, 6), bhvHiddenBlock),
		OBJECT(MODEL_HIDDEN_BLOCK, -4967, 1060, -7168, 0, 0, 0, BP(0, 0, 0x08, 6), bhvHiddenBlock),

		// Squid Word
		OBJECT(MODEL_SQUID_WORD, 0, 450, -1336, 0, 0, 0, 0x00000000, bhvSquidWord),

		// Antisoftlock Bullet Bill
		OBJECT(MODEL_BULLET_BILL, -4831, 625, -4000, 0, -180, 0, 0x00000000, bhvHiddenBulletBill),

		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, wf_area_3),
		WARP_NODE(0x0A, LEVEL_WF, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WF, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_GLOBAL_DOOR, 0, 200, -269, 0, 0, 0, 0x000A0000, bhvDoorWarp),
		OBJECT(MODEL_FUNNYBOX, 0, 0, 0, 0, 0, 0, 0x00000000, bhvFunnyBox),
		OBJECT(MODEL_SPINY, -216, -789, 313, 0, 0, 0, 0x00000000, bhvSpiny),
		OBJECT(MODEL_SPINY, 441, -789, 337, 0, 0, 0, 0x00000000, bhvSpiny),
		OBJECT(MODEL_SPINY, 408, -789, -294, 0, 0, 0, 0x00000000, bhvSpiny),
		OBJECT(MODEL_SPINY, -411, -789, -374, 0, 0, 0, 0x00000000, bhvSpiny),
		OBJECT(MODEL_SPINY, -181, -789, 27, 0, 0, 0, 0x00000000, bhvSpiny),
		OBJECT(MODEL_SPINY, -473, -789, 464, 0, 0, 0, 0x00000000, bhvSpiny),
		OBJECT(MODEL_SPINY, 113, -789, 509, 0, 0, 0, 0x00000000, bhvSpiny),
		OBJECT(MODEL_SPINY, 106, -789, -507, 0, 0, 0, 0x00000000, bhvSpiny),
		OBJECT(MODEL_SPINY, 239, -789, 59, 0, 0, 0, 0x00000000, bhvSpiny),
		OBJECT(MODEL_SPINY, 520, -789, -575, 0, 0, 0, 0x00000000, bhvSpiny),
		OBJECT(MODEL_SPINY, -508, -789, 34, 0, 0, 0, 0x00000000, bhvSpiny),
		TERRAIN(wf_area_3_collision),
		MACRO_OBJECTS(wf_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SLIDE),
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
