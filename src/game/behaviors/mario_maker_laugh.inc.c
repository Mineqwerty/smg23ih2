// mario_maker_laugh.inc.c

#define MARIO_MAKER_LAUGH_DURATION 70
#define MARIO_MAKER_LAUGH_FADE_DURATION 10
#define MARIO_MAKER_LAUGH_SCALE_FLUCTUATION_CYCLE 6
#define MARIO_MAKER_LAUGH_SCALE_FLUCTUATION 0.075f

#define MARIO_MAKER_LAUGH_SPAWNER_POS_VARIANCE_VERTICAL 300.0f
#define MARIO_MAKER_LAUGH_SPAWNER_POS_VARIANCE_HORIZONTAL 600.0f
#define MARIO_MAKER_LAUGH_SPAWNER_SPAWN_FRAME_INTERMISSION 2

void bhv_mario_maker_laugh_init(void) {
    o->oAnimState = o->oBehParams2ndByte;
    if (BPARAM3 != 0) {
        o->oMarioMakerLaughScale = (f32) BPARAM3 / 0x10;
    } else {
        o->oMarioMakerLaughScale = 1.0f;
    }
}

void bhv_mario_maker_laugh_loop(void) {
    f32 totalScale = o->oMarioMakerLaughScale;

    if (o->oTimer >= MARIO_MAKER_LAUGH_DURATION) {
        obj_mark_for_deletion(o);
        return;
    }

    if (o->oTimer < MARIO_MAKER_LAUGH_FADE_DURATION) {
        totalScale = (f32) (o->oTimer + 1) / MARIO_MAKER_LAUGH_FADE_DURATION;
    } else if (o->oTimer > MARIO_MAKER_LAUGH_DURATION - MARIO_MAKER_LAUGH_FADE_DURATION) {
        totalScale = (f32) (MARIO_MAKER_LAUGH_DURATION - o->oTimer) / MARIO_MAKER_LAUGH_FADE_DURATION;
    }

    s16 cycle = ((o->oTimer % MARIO_MAKER_LAUGH_SCALE_FLUCTUATION_CYCLE) * 0x10000) / MARIO_MAKER_LAUGH_SCALE_FLUCTUATION_CYCLE;

    f32 scaleX = (totalScale - MARIO_MAKER_LAUGH_SCALE_FLUCTUATION);
    f32 scaleY = (totalScale - MARIO_MAKER_LAUGH_SCALE_FLUCTUATION);
    scaleX += 2.0f * MARIO_MAKER_LAUGH_SCALE_FLUCTUATION * sins(cycle);
    scaleY += 2.0f * MARIO_MAKER_LAUGH_SCALE_FLUCTUATION * coss(cycle);

    o->header.gfx.scale[0] = scaleX;
    o->header.gfx.scale[1] = scaleY;
    o->header.gfx.scale[2] = totalScale;
}

void bhv_mario_maker_laugh_spawner_init(void) {
    play_sound(SOUND_CUSTOM_MISC_MARIO_MAKER_LAUGH_0 + ((u32) (random_u16() % 3) << 16), gGlobalSoundSource);
    // cur_obj_play_sound_2(SOUND_CUSTOM_MISC_MARIO_MAKER_LAUGH_0 + ((u32) (random_u16() % 3) << 16));
}

void bhv_mario_maker_laugh_spawner_loop(void) {
    struct Object *obj;
    Vec3f offsets;
    f32 offsetMult;
    u8 bparam2;
    u8 bparam3 = 0;

    if (o->oTimer > (o->oBehParams2ndByte - 1) * MARIO_MAKER_LAUGH_SPAWNER_SPAWN_FRAME_INTERMISSION) {
        obj_mark_for_deletion(o);
        return;
    }

    if (o->oTimer % MARIO_MAKER_LAUGH_SPAWNER_SPAWN_FRAME_INTERMISSION != 0) {
        return;
    }

    if (BPARAM3 != 0) {
        offsetMult = (f32) BPARAM3 / 0x10;
    } else {
        offsetMult = 1.0f;
    }

    bparam2 = (o->oTimer / MARIO_MAKER_LAUGH_SPAWNER_SPAWN_FRAME_INTERMISSION) % 3;
    switch (bparam2) {
        case 0:
            bparam3 = 0x16;
            break;
        case 1:
            bparam3 = 0x10;
            break;
        case 2:
            bparam3 = 0x0C;
            break;
    }

    offsets[0] = o->oHomeX + ((random_float() - 0.5f) * MARIO_MAKER_LAUGH_SPAWNER_POS_VARIANCE_HORIZONTAL * offsetMult);
    offsets[1] = o->oHomeY + ((random_float() - 0.5f) * MARIO_MAKER_LAUGH_SPAWNER_POS_VARIANCE_VERTICAL * offsetMult);
    offsets[2] = o->oHomeZ + ((random_float() - 0.5f) * MARIO_MAKER_LAUGH_SPAWNER_POS_VARIANCE_HORIZONTAL * offsetMult);

    obj = spawn_object_abs_with_rot(o, 0, MODEL_MARIO_MAKER_LAUGH, bhvMarioMakerLaugh, offsets[0], offsets[1], offsets[2], 0, 0, 0);
    if (obj) {
        obj->oBehParams2ndByte = bparam2;
        SET_BPARAM2(obj->oBehParams, bparam2);
        SET_BPARAM3(obj->oBehParams, bparam3);
    }
}
