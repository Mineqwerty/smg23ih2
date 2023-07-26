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
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CQ_BRIDGE, 1030, 2653, 7111, 0, 0, 0, 0x00000000, bhvCQBridge),
		OBJECT(MODEL_CUSTOM_FAZANA_CAR, -3, 231, 2115, 0, -180, 0, 0x00000000, bhvFazanaCar),
		OBJECT(MODEL_NONE, 0, 250, 0, 0, 0, 0, (0 << 16) | (250), bhvCheckpoint),
		OBJECT(MODEL_CQ_DOOR, 0, 231, 1107, 0, 0, 0, 0x00000000, bhvCQDoor),
		OBJECT(MODEL_CQ_GATE, 0, 231, -2618, 0, 0, 0, 0x00000000, bhvCQGate),
		OBJECT(MODEL_NONE, -9181, 2955, -17009, 0, 0, 0, (1), bhvHiddenRedCoinStar),
		OBJECT(MODEL_CQ_RED_CUBE, 59, 1171, -9756, 0, 0, 0, (0 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, 6741, 1853, -19313, 0, 0, 0, (1 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, 2887, 3334, -15364, 0, 0, 0, (2 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, 15078, 3227, -16274, 0, 0, 0, (3 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, -388, 2183, -2536, 0, 0, 0, (4 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, -7439, 4958, -11959, 0, 0, 0, (5 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, -6455, 7072, -11709, 0, 0, 0, (6 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, 8394, 4221, -8295, 0, 0, 0, (7 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, -5499, 4373, -22647, 0, 0, 0, (8 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, -5732, 3199, -22575, 0, 0, 0, (9 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, -4101, 3453, -22542, 0, 0, 0, (10 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_CQ_RED_CUBE, 10515, 4693, -5536, 0, 0, 0, (11 << 16) | (1), bhvRedCoin),
		OBJECT(MODEL_NONE, 0, 250, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 250, 0),
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
	MARIO_POS(0x01, 0, 0, 250, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
