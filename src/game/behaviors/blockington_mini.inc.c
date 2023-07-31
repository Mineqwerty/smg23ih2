// blockington_mini.inc.c

#include "blockington.h"

#include "blockington_dialogs.inc.c"

#define BMINI_DIST 10000.0f
#define BMINI_ANIM_DUR 30
#define BMINI_ANIM_WAIT 10
#define BMINI_MAX_ANIM_CAMERA_PITCH -0x300
#define BMINI_MAX_ANIM_CAMERA_YAW 0x700
#define BMINI_MAX_ANIM_PITCH 0xC00
#define BMINI_MAX_ANIM_YAW 0x1800

void bhv_blockington_mini_init(void) {
    u32 bparam2 = BPARAM2;
    if (bparam2 >= bMiniDialogsCount || (bMiniDialogs[bparam2].allowRepeat == FALSE && bMiniDialogs[bparam2].hasSpawned == TRUE)) {
        obj_mark_for_deletion(o);
        return;
    }

    o->oBehParams2ndByte = bparam2;

    o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;

    bMiniDialogs[bparam2].hasSpawned = TRUE; // TODO: set to FALSE in the special cases

    cur_obj_scale(5.0f);
    o->oBlockingtonAngleHomePitch = 0;
    o->oBlockingtonAngleHomeYaw = 0;
    o->oBlockingtonAngleHomeRoll = 0;
    vec3f_copy(&o->oBlockingtonScaleHomeVec, o->header.gfx.scale);
    cur_obj_hide();
}

static void bhv_blockington_mini_set_angle_scale(void) {
    o->oFaceAnglePitch = (s16) ((u16) o->oFaceAnglePitch + (u16) o->oBlockingtonAngleHomePitch + (u16) sBlockington.curAngle[0]);
    o->oFaceAngleYaw = (s16) ((u16) o->oFaceAngleYaw + (u16) o->oBlockingtonAngleHomeYaw + (u16) sBlockington.curAngle[1] + (u16) 0x600);
    o->oFaceAngleRoll = (s16) ((u16) o->oFaceAngleRoll + (u16) o->oBlockingtonAngleHomeRoll + (u16) sBlockington.curAngle[2]);

    o->header.gfx.scale[0] *= sBlockington.curScale[0];
    o->header.gfx.scale[1] *= sBlockington.curScale[1];
    o->header.gfx.scale[2] *= sBlockington.curScale[2];
}

static void bhv_blockington_mini_calculate_additional_rotation_and_set_scale(s16 *pitch, s16 *yaw) {
    f32 mult;

    if (o->oAction == ACT_BMINI_APPEARING) {
        mult = (f32) o->oTimer / (f32) BMINI_ANIM_DUR;
    } else if (o->oAction == ACT_BMINI_DISAPPEARING) {
        mult = (f32) (BMINI_ANIM_DUR - o->oTimer) / (f32) BMINI_ANIM_DUR;
    } else {
        o->oFaceAnglePitch = 0;
        o->oFaceAngleYaw = 0;
        o->oFaceAngleRoll = 0;
        o->header.gfx.scale[0] = o->oBlockingtonScaleHomeX;
        o->header.gfx.scale[1] = o->oBlockingtonScaleHomeY;
        o->header.gfx.scale[2] = o->oBlockingtonScaleHomeZ;
        return; // Do nothing basically
    }

    mult = smoothstep(50.0f, 0.0f, 1.0f - mult) / 50.0f;

    if (mult < 0.001f) {
        mult = 0.001f;
    } else if (mult > 0.999f) {
        mult = 0.999f;
    }

    o->header.gfx.scale[0] = o->oBlockingtonScaleHomeX * mult;
    o->header.gfx.scale[1] = o->oBlockingtonScaleHomeY * mult;
    o->header.gfx.scale[2] = o->oBlockingtonScaleHomeZ * mult;

    *pitch += BMINI_MAX_ANIM_CAMERA_PITCH * (1.0f - mult);
    *yaw += BMINI_MAX_ANIM_CAMERA_YAW * (1.0f - mult);

    o->oFaceAnglePitch = BMINI_MAX_ANIM_PITCH * (1.0f - mult);
    o->oFaceAngleYaw = BMINI_MAX_ANIM_YAW * (1.0f - mult);
    o->oFaceAngleRoll = 0;
}

static void bhv_blockington_mini_set_obj_pos(void) {
    s16 pitch;
    s16 yaw;

    vec3f_get_angle(gCamera->pos, gCamera->focus, &pitch, &yaw);

    pitch -= 0x800;
    yaw += 0x1100;

    bhv_blockington_mini_calculate_additional_rotation_and_set_scale(&pitch, &yaw);

    o->oBlockingtonAngleHomePitch = pitch;
    o->oBlockingtonAngleHomeYaw = yaw + 0x8000;

    o->oPosX = gCamera->pos[0] + sins((u16) yaw) * coss((u16) -pitch) * BMINI_DIST;
    o->oPosY = gCamera->pos[1] + sins((u16) pitch) * BMINI_DIST;
    o->oPosZ = gCamera->pos[2] + coss((u16) yaw) * coss((u16) -pitch) * BMINI_DIST;

    bhv_blockington_mini_set_angle_scale();
}

static void bhv_blockington_mini_act_waiting(void) {
    u32 bparam4 = BPARAM4;

    const uintptr_t *behaviorAddr = o->behavior;
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct Object *obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr &&
            obj->activeFlags != ACTIVE_FLAG_DEACTIVATED &&
            (
                (obj->oAction != ACT_BMINI_WAITING) ||
                (GET_BPARAM4(obj->oBehParams) > bparam4)
            )
        ) {
            return;
        }

        obj = (struct Object *) obj->header.next;
    }

    // Nothing active or of higher priority in queue
    o->oAction = ACT_BMINI_APPEARING;
    o->oTimer = 0;
    cur_obj_unhide();
}

static void bhv_blockington_mini_act_appearing(void) {
    if (o->oTimer >= BMINI_ANIM_DUR - 1) {
        o->oTimer = 0;
        o->oAction = ACT_BMINI_WAITING_TO_TALK;
        o->oBMiniDialogIndex = 0;
    }
}

static void bhv_blockington_mini_act_waiting_to_talk(void) {
    if (bMiniDialogs[o->oBehParams2ndByte].shouldRender) {
        u8 transparency = 255.0f * (f32) ((f32) o->oTimer / (f32) BMINI_ANIM_WAIT);
        set_blockington_dialog_entry(&bMiniDialogs[o->oBehParams2ndByte].startAddr[o->oBMiniDialogIndex], transparency);
    }

    if (o->oTimer >= BMINI_ANIM_WAIT) {
        o->oTimer = 0;
        o->oAction = ACT_BMINI_TALK;
        o->oSubAction = 0;
    }
}

static void bhv_blockington_mini_act_talk(void) {
    if (bMiniDialogs[o->oBehParams2ndByte].shouldRender) {
        set_blockington_dialog_entry(&bMiniDialogs[o->oBehParams2ndByte].startAddr[o->oBMiniDialogIndex], 255);
    }

    if (o->oTimer == 0) {
        play_sound(bMiniDialogs[o->oBehParams2ndByte].startAddr[o->oSubAction].soundID, gGlobalSoundSource);
        return;
    }

    if (sIsBlockingtonStillTalking == TRUE) {
        return;
    }

    if (o->oSubAction >= 4) {
        o->oTimer = 0;
        o->oSubAction = 0;
        o->oAction = ACT_BMINI_WAITING_TO_DISAPPEAR;
        return;
    }

    o->oSubAction++;
}

static void bhv_blockington_mini_act_waiting_to_disappear(void) {
    if (bMiniDialogs[o->oBehParams2ndByte].shouldRender) {
        u8 transparency = 255.0f * (f32) ((f32) (BMINI_ANIM_WAIT - o->oTimer) / (f32) BMINI_ANIM_WAIT);
        set_blockington_dialog_entry(&bMiniDialogs[o->oBehParams2ndByte].startAddr[o->oBMiniDialogIndex], transparency);
    }

    if (o->oTimer >= BMINI_ANIM_WAIT) {
        o->oTimer = 0;
        if (o->oBMiniDialogIndex + 1 >= bMiniDialogs[o->oBehParams2ndByte].dialogCount) {
            o->oAction = ACT_BMINI_DISAPPEARING;
        } else {
            o->oBMiniDialogIndex++;
            o->oAction = ACT_BMINI_WAITING_TO_TALK;
        }
    }
}

static void bhv_blockington_mini_act_disappearing(void) {
    if (o->oTimer >= BMINI_ANIM_DUR - 1) {
        o->oTimer = 0;
        o->oAction = ACT_BMINI_WAITING_TO_DESPAWN;
        cur_obj_hide();
    }
}

static void bhv_blockington_mini_act_waiting_to_despawn(void) {
    if (o->oTimer >= BMINI_ANIM_WAIT*2) {
        obj_mark_for_deletion(o);
    }
}

void bhv_blockington_mini_loop(void) {
    switch(o->oAction) {
        case ACT_BMINI_WAITING:
            bhv_blockington_mini_act_waiting();
            break;
        case ACT_BMINI_APPEARING:
            bhv_blockington_mini_act_appearing();
            break;
        case ACT_BMINI_WAITING_TO_TALK:
            bhv_blockington_mini_act_waiting_to_talk();
            break;
        case ACT_BMINI_TALK:
            bhv_blockington_mini_act_talk();
            break;
        case ACT_BMINI_WAITING_TO_DISAPPEAR:
            bhv_blockington_mini_act_waiting_to_disappear();
            break;
        case ACT_BMINI_DISAPPEARING:
            bhv_blockington_mini_act_disappearing();
            break;
        case ACT_BMINI_WAITING_TO_DESPAWN:
            bhv_blockington_mini_act_waiting_to_despawn();
            break;
    }

    bhv_blockington_calculate_angle_scale_all();
    bhv_blockington_mini_set_obj_pos();
}
