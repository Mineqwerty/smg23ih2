#include "src/game/game_init.h"
#include "levels/wf/squid_word/geo_header.h"

#define SQUID_WORD_SPAWN_FRAMES 10
#define SQUID_WORD_UPWARD_DISTANCE_PER_FRAME 250

extern const u8 sq_tl_textures_dma[];
extern u8 squid_word_sqtl0_rgba16_rgba16[];
extern const u8 sq_tr_textures_dma[];
extern u8 squid_word_sqtr0_rgba16_rgba16[];
extern const u8 sq_bl_textures_dma[];
extern u8 squid_word_sqbl0_rgba16_rgba16[];
extern const u8 sq_br_textures_dma[];
extern u8 squid_word_sqbr0_rgba16_rgba16[];

enum SquidWordActions {
    SQUID_WORD_ACT_IDLE,
    SQUID_WORD_ACT_BECOME_ACTIVE,
    SQUID_WORD_ACT_ACTIVE,
    SQUID_WORD_ACT_DEAD,
};

static void bhv_squid_word_idle(void) {
    if (
        lateral_dist_between_objects(o, gMarioObject) < 800.0f && 
        gMarioState->pos[1] >= 100.0f &&
        (gMarioState->floor && gMarioState->floor->type == SURFACE_DEATH_PLANE)
    ) {
        cur_obj_unhide();
        o->oAction = SQUID_WORD_ACT_BECOME_ACTIVE;
        o->oPosY = o->oHomeY - (SQUID_WORD_UPWARD_DISTANCE_PER_FRAME * SQUID_WORD_SPAWN_FRAMES);
        cur_obj_play_sound_2(SOUND_CUSTOM0_SQUID_WORD_SCREAM);
    }
}

static void bhv_squid_word_become_active(void) {
    if (o->oTimer >= SQUID_WORD_SPAWN_FRAMES - 1) {
        o->oAction = SQUID_WORD_ACT_ACTIVE;
    }

    o->oPosY += SQUID_WORD_UPWARD_DISTANCE_PER_FRAME;
    load_object_collision_model();
}

static void bhv_squid_word_active(void) {
    u8 *topLeftTexture = segmented_to_virtual(&squid_word_sqtl0_rgba16_rgba16);
    u8 *topRightTexture = segmented_to_virtual(&squid_word_sqtr0_rgba16_rgba16);
    u8 *bottomLeftTexture = segmented_to_virtual(&squid_word_sqbl0_rgba16_rgba16);
    u8 *bottomRightTexture = segmented_to_virtual(&squid_word_sqbr0_rgba16_rgba16);

    if (o->oTimer < 42) {
        dma_read(topLeftTexture, ((o->oTimer / 2) * 4096) + (u8 *) sq_tl_textures_dma,
                 ((o->oTimer / 2) * 4096) + (u8 *) sq_tl_textures_dma + 4096);
        dma_read(topRightTexture, ((o->oTimer / 2) * 4096) + (u8 *) sq_tr_textures_dma,
                 ((o->oTimer / 2) * 4096) + (u8 *) sq_tr_textures_dma + 4096);
        dma_read(bottomLeftTexture, ((o->oTimer / 2) * 4096) + (u8 *) sq_bl_textures_dma,
                 ((o->oTimer / 2) * 4096) + (u8 *) sq_bl_textures_dma + 4096);
        dma_read(bottomRightTexture, ((o->oTimer / 2) * 4096) + (u8 *) sq_br_textures_dma,
                 ((o->oTimer / 2) * 4096) + (u8 *) sq_br_textures_dma + 4096);

        load_object_collision_model();
    } else if (o->oTimer >= 60) {
        o->oAction = SQUID_WORD_ACT_DEAD;
        o->oVelY = 90.0f;
        o->oMoveAngleRoll = 0x1800;
        cur_obj_play_sound_2(SOUND_CUSTOM0_KICK_SHELL);

        load_object_collision_model();
    }
}

static void bhv_squid_word_dead(void) {
        if (o->oPosY + o->oVelY <= FLOOR_LOWER_LIMIT) {
            obj_mark_for_deletion(o);
            return;
        }

        o->oPosY += o->oVelY;
        o->oFaceAngleRoll = (s16) (o->oFaceAngleRoll + o->oMoveAngleRoll);

        o->oVelY -= 9.0f;
        o->oMoveAngleRoll *= 0.955f;

        // Do not load collision
}

ObjActionFunc sSquidWordActFunctions[] = {
    [SQUID_WORD_ACT_IDLE]          = bhv_squid_word_idle,
    [SQUID_WORD_ACT_BECOME_ACTIVE] = bhv_squid_word_become_active,
    [SQUID_WORD_ACT_ACTIVE]        = bhv_squid_word_active,
    [SQUID_WORD_ACT_DEAD]          = bhv_squid_word_dead,
};

void bhv_squid_word_init(void) {
    cur_obj_scale(2.5f);
    cur_obj_hide();
}

void bhv_squid_word_loop(void) {
    cur_obj_call_action_function(sSquidWordActFunctions);
}
