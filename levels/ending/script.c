#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/area.h"
#include "game/level_update.h"
#include "game/level_geo.h"

#include "levels/scripts.h"

#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/ending/header.h"

const LevelScript level_ending_entry_loop[] = {
    SLEEP(/*frames*/ 1),
    JUMP(level_ending_entry_loop), // (loop sleep 1 forever)
};

const LevelScript level_load_screen_entry[] = {
    CALL(/*arg*/ 0, /*func*/ init_load_screen_buffers),
    LOAD_LEVEL_DATA(ending),
    ALLOC_LEVEL_POOL(),

    AREA(/*index*/ 1, ending_load_screen_geo),
    END_AREA(),

    FREE_LEVEL_POOL(),
    SLEEP(/*frames*/ 15),
    BLACKOUT(/*active*/ FALSE),
    LOAD_AREA(/*area*/ 1),
    SET_MENU_MUSIC(/*seq*/ SEQ_SOUND_PLAYER),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_COLOR, /*time*/ 20, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 20),
    CALL_LOOP(/*arg*/ SMG23IH2_LEVEL_4, /*func*/ is_loading_screen_done),
    UNLOAD_AREA(/*area*/ 1),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 35),

    SET_REG(/*value*/ SMG23IH2_LEVEL_4),

    SLEEP_BEFORE_EXIT(/*frames*/ 1),
    EXIT(),
};

const LevelScript level_ending_entry[] = {
    INIT_LEVEL(),

    CALL(/*arg*/ 0, /*func*/ lvl_warp_type),
    JUMP_IF(OP_EQ, /*arg*/ 0x02,  level_load_screen_entry),

    LOAD_LEVEL_DATA(ending),
    ALLOC_LEVEL_POOL(),

    AREA(/*index*/ 1, ending_geo_area_1),
    END_AREA(),

    FREE_LEVEL_POOL(),
    SLEEP(/*frames*/ 60),
    BLACKOUT(/*active*/ FALSE),
    LOAD_AREA(/*area*/ 1),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_COLOR, /*time*/ 75, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 120),
    CALL(/*arg*/ 0, /*func*/ lvl_play_the_end_screen_sound),

    JUMP(level_ending_entry_loop), // (loop sleep 1 forever)
};
