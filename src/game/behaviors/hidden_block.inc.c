// hidden_block.inc.c

#define HIDDEN_BLOCK_SCALE 308 // Hidden blocks are 300 x 300 x 300
#define HIDDEN_BLOCK_DOWNWARD_VELOCITY -20.0f

void bhv_hidden_block_init(void) {
    cur_obj_hide();
    if (o->oBehParams2ndByte != 0) {
        o->oHiddenBlockScale = (s32) (HIDDEN_BLOCK_SCALE * o->oBehParams2ndByte) / 0x10;
        cur_obj_scale((f32) o->oHiddenBlockScale / (f32) HIDDEN_BLOCK_SCALE);
    } else {
        o->oHiddenBlockScale = HIDDEN_BLOCK_SCALE;
        cur_obj_scale(1.0f);
    }
}

static void animate_hidden_block(void) {
    if (o->oTimer >= 5) {
        o->oPosY = o->oHomeY;
        o->oAction = HIDDEN_BLOCK_ACT_IDLE;
        load_object_static_model(); // NOTE: Change this logic if you ever plan to move these around after they've been hit!
        return;
    }

    o->oPosY = o->oHomeY + (o->oHiddenBlockScale * 0.225f) * sins(0x8000 * o->oTimer / 5);
    load_object_collision_model();
}

void bhv_hidden_block_loop(void) {
    if (o->oAction != HIDDEN_BLOCK_ACT_HIDDEN) {
        if (o->oAction == HIDDEN_BLOCK_ACT_ANIMATED) {
            animate_hidden_block();
        }
        return;
    }

    s32 distX = gMarioState->pos[0] - o->oPosX;
    s32 distY = gMarioState->pos[1] + 120.0f - o->oPosY;
    s32 distZ = gMarioState->pos[2] - o->oPosZ;

    if (ABS(distX) > (o->oHiddenBlockScale / 2) || ABS(distZ) > (o->oHiddenBlockScale / 2))
        return;

    // NOTE: This may be cheeseable if o->oHiddenBlockScale is significantly decreased
    if (distY < 0 || distY > (o->oHiddenBlockScale / 4) || gMarioObject->oVelY <= 0.0f)
        return;
    
    o->oAction = HIDDEN_BLOCK_ACT_ANIMATED;
    cur_obj_unhide();

    // Collect coin from the block
    gMarioState->numCoins++;
    gMarioState->health += 0x100;
    if (gMarioState->health > 0x880)
        gMarioState->health = 0x880;

    gMarioState->pos[1] = o->oPosY - 120.0f;
    gMarioState->vel[1] = HIDDEN_BLOCK_DOWNWARD_VELOCITY;
    gMarioObject->oVelY = gMarioState->vel[1];
    // load_object_collision_model(); // Can cause bonking and stuff

    cur_obj_play_sound_2(SOUND_ACTION_HIT_HIDDEN_BLOCK);
}
