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
#include "game/behaviors/blockington.h"
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/hmc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_hmc_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _hmc_segment_7SegmentRomStart, _hmc_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _cave_yay0SegmentRomStart, _cave_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group6_yay0SegmentRomStart, _group6_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group6_geoSegmentRomStart, _group6_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xa, _bbh_skybox_yay0SegmentRomStart, _bbh_skybox_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_7), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_BLOCKINGTON, blockington_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BLOCKINGTON_MINI, blockington_mini_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BLOCKINGTON_CHILD, blockington_child_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BLOCKINGTON_ADULT, blockington_adult_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CQ_DOOR, cq_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CQ_GATE, cq_gate_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CQ_RED_CUBE, cq_red_cube_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CQ_BRIDGE, cq_bridge_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_WOODEN_DOOR, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_METAL_DOOR, metal_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_HAZY_MAZE_DOOR, hazy_maze_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_METAL_PLATFORM, hmc_geo_0005A0), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_METAL_ARROW_PLATFORM, hmc_geo_0005B8), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_ELEVATOR_PLATFORM, hmc_geo_0005D0), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_ROLLING_ROCK, hmc_geo_000548), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_ROCK_PIECE, hmc_geo_000570), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_ROCK_SMALL_PIECE, hmc_geo_000588), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_RED_GRILLS, hmc_geo_000530), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, hmc_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_SL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLOCKINGTON, 350, 580, -1750, 0, 0, 0, 0x00000000, bhvBlockington),
		OBJECT(MODEL_BLOCKINGTON_ADULT, -1000, 4350, 26615, 0, 0, 0, 0x00000000, bhvBlockingtonChild),
		OBJECT(MODEL_BLOCKINGTON_CHILD, 9828, 2753, -3349, 0, 0, 0, 0x00000000, bhvBlockingtonChild),
		OBJECT(MODEL_BLOCKINGTON_CHILD, 3521, 2863, -21695, 0, 0, 0, 0x00000000, bhvBlockingtonChild),
		OBJECT(MODEL_BLOCKINGTON_CHILD, -9136, 2852, -15760, 0, 0, 0, 0x00000000, bhvBlockingtonChild),
		OBJECT(MODEL_BLOCKINGTON_CHILD, -4556, 3038, -1158, 0, 0, 0, 0x00000000, bhvBlockingtonChild),
		OBJECT(MODEL_BLOCKINGTON_CHILD, 0, 4350, 26304, 0, 0, 0, 0x00000000, bhvBlockingtonChild),
		OBJECT(MODEL_BLOCKINGTON_CHILD, -1495, 4350, 27443, 0, 0, 0, 0x00000000, bhvBlockingtonChild),
		OBJECT(MODEL_BLOCKINGTON_CHILD, -1564, 4350, 25598, 0, 0, 0, 0x00000000, bhvBlockingtonChild),
		OBJECT(MODEL_BLOCKINGTON_CHILD, 19890, 4350, 19032, 0, 0, 0, 0x00000000, bhvBlockingtonChild),
		OBJECT(MODEL_BLOCKINGTON_CHILD, -10673, 4350, 22735, 0, 0, 0, 0x00000000, bhvBlockingtonChild),
		OBJECT(MODEL_BLOCKINGTON_CHILD, 9392, 4350, 16588, 0, 0, 0, 0x00000000, bhvBlockingtonChild),
		OBJECT(MODEL_NONE, 2266, 5080, 18239, 0, 0, 0, (BKTN_DIA_CRINGE_PATH_0 << 16) | (256), bhvBlockingtonTrigger),
		OBJECT(MODEL_NONE, 654, 5819, 19901, 0, 0, 0, (BKTN_DIA_CRINGE_PATH_1 << 16) | (256), bhvBlockingtonTrigger),
		OBJECT(MODEL_NONE, -230, 6548, 15196, 0, 0, 0, (BKTN_DIA_CRINGE_PATH_2 << 16) | (256), bhvBlockingtonTrigger),
		OBJECT(MODEL_NONE, 18600, 5423, 14000, 0, 0, 0, (BKTN_DIA_PITY_BRIDGE << 16) | (512), bhvBlockingtonTrigger),
		OBJECT(MODEL_CQ_BRIDGE, 1030, 2653, 7111, 0, 0, 0, (1 << 16), bhvCQBridge),
		OBJECT(MODEL_CQ_BRIDGE, -21387, 4209, 23266, 0, -90, 0, (2 << 16), bhvCQBridge),
		OBJECT(MODEL_CQ_BRIDGE, 23729, 4268, 14270, 0, -180, 0, (3 << 16), bhvCQBridge),
		OBJECT(MODEL_CUSTOM_FAZANA_CAR, -3, 231, 2115, 0, -180, 0, 0x00000000, bhvFazanaCar),
		OBJECT(MODEL_NONE, 0, 231, -200, 0, 0, 0, (0 << 16) | (250), bhvCheckpoint),
		OBJECT(MODEL_CQ_DOOR, 0, 231, 1107, 0, 0, 0, 0x00000000, bhvCQDoor),
		OBJECT(MODEL_CQ_RED_CUBE, -2093, 8271, 16972, 0, 0, 0, 0x00000000, bhvFakeRedCoinCube),
		OBJECT(MODEL_CQ_GATE, 0, 231, -2618, 0, 0, 0, 0x00000000, bhvCQGate),
		OBJECT(MODEL_NONE, 1030, 2653, 7111, 0, 0, 0, (1), bhvHiddenRedCoinStar),
		OBJECT(MODEL_NONE, -21387, 4209, 23266, 0, 0, 0, (2), bhvHiddenRedCoinStar),
		OBJECT(MODEL_CQ_RED_CUBE, 59, 1171, -9756, 0, 0, 0, (0 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, 6741, 1853, -19313, 0, 0, 0, (1 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, 2887, 3534, -15364, 0, 0, 0, (2 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, 15078, 3227, -16274, 0, 0, 0, (3 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, -388, 2183, -2536, 0, 0, 0, (4 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, -7439, 4958, -11959, 0, 0, 0, (5 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, -6455, 7072, -11709, 0, 0, 0, (6 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, 8394, 4221, -8295, 0, 0, 0, (7 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, -5499, 4373, -22647, 0, 0, 0, (8 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, -5732, 3199, -22575, 0, 0, 0, (9 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, -4101, 3453, -22542, 0, 0, 0, (10 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, 10515, 4693, -5536, 0, 0, 0, (11 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, 23773, 5507, 11840, 0, 0, 0, (12 << 16) | (2), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, 20409, 7309, 14095, 0, 0, 0, (13 << 16) | (2), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, 11290, 4318, 20644, 0, 0, 0, (14 << 16) | (2), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, 10637, 4318, 21672, 0, 0, 0, (15 << 16) | (2), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, 10081, 4318, 23247, 0, 0, 0, (16 << 16) | (2), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, 8699, 4318, 25503, 0, 0, 0, (17 << 16) | (2), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, 6867, 4318, 26596, 0, 0, 0, (18 << 16) | (2), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, 9464, 4318, 24613, 0, 0, 0, (19 << 16) | (2), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, -6155, 5371, 18453, 0, 0, 0, (20 << 16) | (2), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, -6155, 5371, 24626, 0, 0, 0, (21 << 16) | (2), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, -14906, 4318, 22980, 0, 0, 0, (22 << 16) | (2), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, 10080, 5151, 23030, 0, 0, 0, (23 << 16) | (2), bhvRedCoin),
		OBJECT(MODEL_NONE, 0, 231, -200, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 231, -200),
		TERRAIN(hmc_area_1_collision),
		MACRO_OBJECTS(hmc_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		SET_BACKGROUND_MUSIC_WITH_REVERB(0, SEQ_LEVEL_UNDERGROUND, 4, 4),
		SET_ECHO(0x18, 0x18),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 231, -200),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
