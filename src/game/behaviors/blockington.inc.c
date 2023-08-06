// blockington.inc.c

#include "blockington.h"

#define PITCH_VARIANCE 0x1200
#define YAW_VARIANCE 0x0C00
#define ROLL_VARIANCE 0x0C00

#define SCALE_VARIANCE_X 0.3f
#define SCALE_VARIANCE_Y 0.5f
#define SCALE_VARIANCE_Z 0.3f


#define BKTN_DIST_CAM_XZ 1600.0f
#define BKTN_DIST_CAM_Y 250.0f
#define BKTN_CUTSCENE_POS_SMOOTHSTEPXZ 0.12f
#define BKTN_CUTSCENE_POS_SMOOTHSTEPY 0.20f
#define BKTN_CUTSCENE_FOCUS_SMOOTHSTEPXZ 0.20f
#define BKTN_CUTSCENE_FOCUS_SMOOTHSTEPY 0.20f

enum ActBlockington {
    BLOCKINGTON_ACT_SPAWN_WAIT,
    BLOCKINGTON_ACT_TALK_MARIO,
    BLOCKINGTON_ACT_WAIT_CAR,
    BLOCKINGTON_ACT_TALK_CAR,
    BLOCKINGTON_ACT_WAIT_FOR_GATE,
    BLOCKINGTON_ACT_MOVE_AREA_1,
    BLOCKINGTON_ACT_WAIT_AREA_1,
    BLOCKINGTON_ACT_TALK_AREA_1,
    BLOCKINGTON_ACT_MOVE_AREA_2,
    BLOCKINGTON_ACT_WAIT_AREA_2,
    BLOCKINGTON_ACT_TALK_AREA_2,
    BLOCKINGTON_ACT_MOVE_AREA_3,
    BLOCKINGTON_ACT_WAIT_AREA_3,
    BLOCKINGTON_ACT_FINAL_CUTSCENE_TRANSITION,
    BLOCKINGTON_ACT_FINAL_GET_OUT_OF_CAR,
    BLOCKINGTON_ACT_FINAL_BKTN_MAD,
    BLOCKINGTON_ACT_FINAL_BKTN_TANGENT,
    BLOCKINGTON_ACT_FINAL_BKTN_SHOT,
};

struct BlockingtonStates sBlockington;

const Vec3i angleLimitFactors = {0x3000, 0x1800, 0x1800};

s32 approachFrames = 3;

const Vec3f coordDests[3] = {
    {0.0f, 1750.0f + 351.0f, -7500.0f},
    {1000.0f, 4750.0f + 351.0f, 11250.0f},
    {-29002.0f, 5768.0f + 100.0f + 351.0f, 22944.0f},
};

void bhv_blockington_init(void) {
    approachFrames = 3;

    cur_obj_scale(1.6f);
    vec3f_copy(&o->oHomeVec, &o->oPosVec);
    vec3i_copy(&o->oBlockingtonAngleHomeVec, &o->oFaceAngleVec);
    vec3i_copy(sBlockington.curAngle, &o->oFaceAngleVec);
    vec3_same(sBlockington.goalAngle, 0);
    vec3_same(sBlockington.approachAngle, 0);
    vec3f_copy(&o->oBlockingtonScaleHomeVec, o->header.gfx.scale);
    vec3f_copy(sBlockington.curScale, o->header.gfx.scale);
    vec3_same(sBlockington.goalScale, 1.0f);
    vec3_same(sBlockington.approachScale, 0.0f);

    o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;

    for (u32 i = 0; i < BKTN_DIA_COUNT; i++) {
        bMiniDialogs[i].hasSpawned = FALSE;
    }
}

void bhv_blockington_calculate_angle_scale_all(void) {
    s32 isTalking;

    if (gGlobalTimer == sBlockington.updateVar) {
        return;
    }

    // Only run as main blockington if blockington mini doesn't exist
    if (o->behavior == segmented_to_virtual(bhvBlockington)) {
        if (find_first_object_with_behavior_and_bparams(bhvBlockingtonMini, 0, 0)) {
            return;
        }

        isTalking = (o->oAction == BLOCKINGTON_ACT_FINAL_BKTN_TANGENT);
    } else {
        isTalking = (o->oAction == ACT_BMINI_TALK);
        
        if (!isTalking && o->parentObj && o->parentObj->behavior == segmented_to_virtual(bhvBlockington)) {
            isTalking = (o->parentObj->oAction == BLOCKINGTON_ACT_FINAL_BKTN_TANGENT);
        }
    }

    sBlockington.updateVar = gGlobalTimer;

    if (o->oTimer % approachFrames == 0) {
        if (isTalking) {
            sBlockington.goalAngle[0] = ((random_float() * 2.0f - 1.0f) * PITCH_VARIANCE);
            sBlockington.goalAngle[1] = ((random_float() * 2.0f - 1.0f) * YAW_VARIANCE);
            sBlockington.goalAngle[2] = ((random_float() * 2.0f - 1.0f) * ROLL_VARIANCE);

            sBlockington.goalScale[0] = 1.0f + (random_float() * 2.0f - 1.0f) * SCALE_VARIANCE_X;
            sBlockington.goalScale[1] = 1.0f + (random_float() * 2.0f - 1.0f) * SCALE_VARIANCE_Y;
            sBlockington.goalScale[2] = 1.0f + (random_float() * 2.0f - 1.0f) * SCALE_VARIANCE_Z;
        } else {
            sBlockington.goalAngle[0] = 0;
            sBlockington.goalAngle[1] = 0;
            sBlockington.goalAngle[2] = 0;

            sBlockington.goalScale[0] = 1.0f;
            sBlockington.goalScale[1] = 1.0f;
            sBlockington.goalScale[2] = 1.0f;
        }

        sBlockington.approachAngle[0] = ((s16) ((u16) sBlockington.goalAngle[0] - (u16) sBlockington.curAngle[0])) / (s16) approachFrames;
        sBlockington.approachAngle[1] = ((s16) ((u16) sBlockington.goalAngle[1] - (u16) sBlockington.curAngle[1])) / (s16) approachFrames;
        sBlockington.approachAngle[2] = ((s16) ((u16) sBlockington.goalAngle[2] - (u16) sBlockington.curAngle[2])) / (s16) approachFrames;
        
        sBlockington.approachScale[0] = (sBlockington.goalScale[0] - sBlockington.curScale[0]) / approachFrames;
        sBlockington.approachScale[1] = (sBlockington.goalScale[1] - sBlockington.curScale[1]) / approachFrames;
        sBlockington.approachScale[2] = (sBlockington.goalScale[2] - sBlockington.curScale[2]) / approachFrames;
    }

    vec3i_add(sBlockington.curAngle, sBlockington.approachAngle);
    vec3f_add(sBlockington.curScale, sBlockington.approachScale);
}

static void bhv_blockington_set_angle_scale(void) {
    o->oFaceAnglePitch = (s16) ((u16) o->oBlockingtonAngleHomePitch + (u16) sBlockington.curAngle[0]);
    o->oFaceAngleYaw = (s16) ((u16) o->oBlockingtonAngleHomeYaw + (u16) sBlockington.curAngle[1] + (u16) o->oAngleToMario);
    o->oFaceAngleRoll = (s16) ((u16) o->oBlockingtonAngleHomeRoll + (u16) sBlockington.curAngle[2]);

    o->header.gfx.scale[0] = o->oBlockingtonScaleHomeX * sBlockington.curScale[0];
    o->header.gfx.scale[1] = o->oBlockingtonScaleHomeY * sBlockington.curScale[1];
    o->header.gfx.scale[2] = o->oBlockingtonScaleHomeZ * sBlockington.curScale[2];
}

static void bhv_blockington_approach_camera_goal(void) {
    gLakituState.goalFocus[0] = smoothstep(gLakituState.goalFocus[0], o->oPosX, BKTN_CUTSCENE_FOCUS_SMOOTHSTEPXZ);
    gLakituState.goalFocus[1] = smoothstep(gLakituState.goalFocus[1], o->oPosY, BKTN_CUTSCENE_FOCUS_SMOOTHSTEPY);
    gLakituState.goalFocus[2] = smoothstep(gLakituState.goalFocus[2], o->oPosZ, BKTN_CUTSCENE_FOCUS_SMOOTHSTEPXZ);

    s16 yaw = atan2s(sCameraStoreCutscene.pos[2] - o->oPosZ, sCameraStoreCutscene.pos[0] - o->oPosX);

    gLakituState.goalPos[0] = smoothstep(gLakituState.goalPos[0], o->oPosX + (BKTN_DIST_CAM_XZ * sins((s16) (yaw))), BKTN_CUTSCENE_POS_SMOOTHSTEPXZ);
    gLakituState.goalPos[2] = smoothstep(gLakituState.goalPos[2], o->oPosZ + (BKTN_DIST_CAM_XZ * coss((s16) (yaw))), BKTN_CUTSCENE_POS_SMOOTHSTEPXZ);
    if (o->oAction == BLOCKINGTON_ACT_MOVE_AREA_1) {
        gLakituState.goalPos[1] = smoothstep(gLakituState.goalPos[1], o->oPosY - BKTN_DIST_CAM_Y, BKTN_CUTSCENE_POS_SMOOTHSTEPY * 0.5f);
    } else {
        gLakituState.goalPos[1] = smoothstep(gLakituState.goalPos[1], o->oPosY + BKTN_DIST_CAM_Y, BKTN_CUTSCENE_POS_SMOOTHSTEPY);
    }
}

static void blockington_act_spawn_wait(void) {
    if (
        o->oDistanceToMario <= 800.0f &&
        gCamera->cutscene == FALSE &&
        !(gTimeStopState & TIME_STOP_ENABLED) &&
        (mario_ready_to_speak() || gMarioState->action == ACT_FAZANA_CAR)
    ) {
        gTimeStopState |= TIME_STOP_ENABLED;
        gCamera->cutscene = TRUE;

        if (gMarioState->action != ACT_FAZANA_CAR) {
            set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0);
            gMarioState->faceAngle[1] = atan2s(o->oPosZ - gMarioState->pos[2], o->oPosX - gMarioState->pos[0]);
        }

        vec3f_copy(sCameraStoreCutscene.focus, gLakituState.goalFocus);
        vec3f_copy(sCameraStoreCutscene.pos, gLakituState.goalPos);

        o->oAction++;

        bhv_blockington_approach_camera_goal();
    }
}

static void blockington_act_talk_mario(void) {
    bhv_blockington_approach_camera_goal();

    if (o->oTimer == 0) {
        struct Object *obj = spawn_object(o, MODEL_BLOCKINGTON_MINI, bhvBlockingtonMini);
        if (obj) {
            obj->oBehParams = ((BKTN_DIA_CS_MARIO) << 16) | 10; // Top priority
            obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
        } else {
            o->oAction++;
        }
    }

    // BlockingtonMini should update the next action
}

static void blockington_act_wait_car(void) {
    if (o->oTimer == 0) {
        bhv_blockington_approach_camera_goal();
        struct Object *obj = find_first_object_with_behavior_and_bparams(bhvCQDoor, 0, 0);
        if (obj) {
            obj->oAction++;
            obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
        }

        return;
    }

    if (
        o->oDistanceToMario <= 800.0f &&
        gCamera->cutscene == FALSE &&
        !(gTimeStopState & TIME_STOP_ENABLED) &&
        gMarioState->action == ACT_FAZANA_CAR
    ) {
        gTimeStopState |= TIME_STOP_ENABLED;
        gCamera->cutscene = TRUE;

        if (gMarioState->action != ACT_FAZANA_CAR) {
            set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0);
        }

        vec3f_copy(sCameraStoreCutscene.focus, gLakituState.goalFocus);
        vec3f_copy(sCameraStoreCutscene.pos, gLakituState.goalPos);

        o->oAction++;

        bhv_blockington_approach_camera_goal();
    }
}

static void blockington_act_talk_car(void) {
    bhv_blockington_approach_camera_goal();

    if (o->oTimer == 0) {
        struct Object *obj = spawn_object(o, MODEL_BLOCKINGTON_MINI, bhvBlockingtonMini);
        if (obj) {
            obj->oBehParams = ((BKTN_DIA_CS_CAR) << 16) | 10; // Top priority
            obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
        } else {
            o->oAction++;
        }
    }

    // BlockingtonMini should update the next action
}

static void blockington_act_wait_for_gate(void) {
    if (o->oTimer == 0) {
        bhv_blockington_approach_camera_goal();
        struct Object *obj = find_first_object_with_behavior_and_bparams(bhvCQGate, 0, 0);
        if (obj) {
            obj->oAction++;
            obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
        } else {
            o->oAction++;
        }

        return;
    }

    
    s16 angle = atan2s(coordDests[0][2] - o->oPosZ, coordDests[0][0] - o->oPosX);
    o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, angle, 0xA00);

    struct Object *obj = find_first_object_with_behavior_and_bparams(bhvCQGate, 0, 0);

    if (obj == NULL || (obj->oAction == ACT_CQGATE_ANIMATING && obj->oSubAction == 2 && obj->oTimer >= 15)) {
        obj->oCQGateCamShouldUpdate = FALSE;
        o->oAction++;
        bhv_blockington_approach_camera_goal();
    }
}

static void blockington_act_move_area_1(void) {
    s16 angle;
    f32 ratio;

    bhv_blockington_approach_camera_goal();

    switch (o->oSubAction) {
        case 0:
            angle = atan2s(coordDests[0][2] - o->oPosZ, coordDests[0][0] - o->oPosX);
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, angle, 0xA00);
            if (angle == o->oFaceAngleYaw) {
                o->oSubAction++;
                o->oTimer = 0;
            }
            break;
        case 1:
            if (o->oTimer < 5) {
                break;
            }

            ratio = (f32) (o->oTimer + 5) / 105.0f;

            if (ratio >= 1.0f) {
                vec3f_copy(&o->oPosVec, coordDests[0]);
                vec3f_copy(&o->oHomeVec, coordDests[0]);
                o->oSubAction++;
                break;
            }

            o->oPosX = coordDests[0][0] * ratio + o->oHomeX * (1.0f - ratio);
            o->oPosY = coordDests[0][1] * ratio + o->oHomeY * (1.0f - ratio);
            o->oPosZ = coordDests[0][2] * ratio + o->oHomeZ * (1.0f - ratio);

            break;
        case 2:
            angle = atan2s(gMarioState->pos[2] - o->oPosZ, gMarioState->pos[0] - o->oPosX);
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, angle, 0xA00);
            if (angle == o->oFaceAngleYaw) {
                o->oSubAction++;
                o->oTimer = 0;
            }
            break;
        case 3:
            if (o->oTimer >= 45) {
                o->oAction++;
            }
            break;
    }
}

static void blockington_act_wait_area_1(void) {
    if (o->oTimer == 0) {
        vec3f_copy(gLakituState.goalFocus, sCameraStoreCutscene.focus);
        vec3f_copy(gLakituState.goalPos, sCameraStoreCutscene.pos);
        // vec3f_copy(gLakituState.curFocus, sCameraStoreCutscene.focus);
        // vec3f_copy(gLakituState.curPos, sCameraStoreCutscene.pos);

        gTimeStopState &= ~TIME_STOP_ENABLED;
        gCamera->cutscene = FALSE;

        if (gMarioState->action != ACT_FAZANA_CAR) {
            set_mario_action(gMarioState, ACT_IDLE, 0);
        }
    }

    if (
        (o->oDistanceToMario <= 1500.0f || gMarioState->pos[1] > 1499.0f) &&
        gCamera->cutscene == FALSE &&
        !(gTimeStopState & TIME_STOP_ENABLED) &&
        (mario_ready_to_speak() || gMarioState->action == ACT_FAZANA_CAR)
    ) {
        gTimeStopState |= TIME_STOP_ENABLED;
        gCamera->cutscene = TRUE;

        if (gMarioState->action != ACT_FAZANA_CAR) {
            set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0);
        }

        vec3f_copy(sCameraStoreCutscene.focus, gLakituState.goalFocus);
        vec3f_copy(sCameraStoreCutscene.pos, gLakituState.goalPos);

        o->oAction++;

        bhv_blockington_approach_camera_goal();
    }
}

static void blockington_act_talk_area_1(void) {
    bhv_blockington_approach_camera_goal();

    if (o->oTimer == 0) {
        struct Object *obj = spawn_object(o, MODEL_BLOCKINGTON_MINI, bhvBlockingtonMini);
        if (obj) {
            obj->oBehParams = ((BKTN_DIA_CS_FIRST_AREA) << 16) | 10; // Top priority
            obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
        } else {
            o->oAction++;
        }
    }

    // BlockingtonMini should update the next action
}

static void blockington_act_move_area_2(void) {
    s16 angle;
    f32 ratio;

    if (o->oTimer == 0) {
        vec3f_copy(gLakituState.goalFocus, sCameraStoreCutscene.focus);
        vec3f_copy(gLakituState.goalPos, sCameraStoreCutscene.pos);
        // vec3f_copy(gLakituState.curFocus, sCameraStoreCutscene.focus);
        // vec3f_copy(gLakituState.curPos, sCameraStoreCutscene.pos);

        gTimeStopState &= ~TIME_STOP_ENABLED;
        gCamera->cutscene = FALSE;

        if (gMarioState->action != ACT_FAZANA_CAR) {
            set_mario_action(gMarioState, ACT_IDLE, 0);
        }
    }

    switch (o->oSubAction) {
        case 0:
            if (o->oTimer < 20) {
                break;
            }

            angle = atan2s(coordDests[1][2] - o->oPosZ, coordDests[1][0] - o->oPosX);
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, angle, 0xA00);
            if (angle == o->oFaceAngleYaw) {
                o->oSubAction++;
                o->oTimer = 0;
            }
            break;
        case 1:
            if (o->oTimer < 5) {
                break;
            }

            ratio = (f32) (o->oTimer - 5) / 105.0f;

            if (ratio >= 1.0f) {
                vec3f_copy(&o->oPosVec, coordDests[1]);
                vec3f_copy(&o->oHomeVec, coordDests[1]);
                o->oSubAction++;
                break;
            }

            o->oPosX = coordDests[1][0] * ratio + o->oHomeX * (1.0f - ratio);
            o->oPosY = coordDests[1][1] * ratio + o->oHomeY * (1.0f - ratio);
            o->oPosZ = coordDests[1][2] * ratio + o->oHomeZ * (1.0f - ratio);

            break;
        case 2:
            angle = atan2s(gMarioState->pos[2] - o->oPosZ, gMarioState->pos[0] - o->oPosX);
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, angle, 0xA00);
            if (ABS(angle - o->oFaceAngleYaw) < 0xA00) {
                o->oSubAction++;
                o->oTimer = 0;
            }
            break;
        case 3:
            if (o->oTimer >= 10) {
                o->oAction++;
            }
            break;
    }
}

static void blockington_act_wait_area_2(void) {
    if (
        (o->oDistanceToMario <= 1200.0f || (gMarioState->pos[1] > 4317.0f && gMarioState->pos[2] > 7500.0f)) &&
        gCamera->cutscene == FALSE &&
        !(gTimeStopState & TIME_STOP_ENABLED) &&
        (mario_ready_to_speak() || 
            (gMarioState->action == ACT_FAZANA_CAR && gMarioState->fazanaCar && gMarioState->fazanaCar->oFloor != NULL))
    ) {
        gTimeStopState |= TIME_STOP_ENABLED;
        gCamera->cutscene = TRUE;

        if (gMarioState->action != ACT_FAZANA_CAR) {
            set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0);
        }

        vec3f_copy(sCameraStoreCutscene.focus, gLakituState.goalFocus);
        vec3f_copy(sCameraStoreCutscene.pos, gLakituState.goalPos);

        o->oAction++;

        bhv_blockington_approach_camera_goal();
    }
}

static void blockington_act_talk_area_2(void) {
    bhv_blockington_approach_camera_goal();

    if (o->oTimer == 0) {
        struct Object *obj = spawn_object(o, MODEL_BLOCKINGTON_MINI, bhvBlockingtonMini);
        if (obj) {
            obj->oBehParams = ((BKTN_DIA_CS_SECOND_AREA) << 16) | 10; // Top priority
            obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
        } else {
            o->oAction++;
        }
    }

    // BlockingtonMini should update the next action
}

static void blockington_act_move_area_3(void) {
    s16 angle;
    f32 ratio;

    if (o->oTimer == 0) {
        vec3f_copy(gLakituState.goalFocus, sCameraStoreCutscene.focus);
        vec3f_copy(gLakituState.goalPos, sCameraStoreCutscene.pos);
        // vec3f_copy(gLakituState.curFocus, sCameraStoreCutscene.focus);
        // vec3f_copy(gLakituState.curPos, sCameraStoreCutscene.pos);

        gTimeStopState &= ~TIME_STOP_ENABLED;
        gCamera->cutscene = FALSE;

        if (gMarioState->action != ACT_FAZANA_CAR) {
            set_mario_action(gMarioState, ACT_IDLE, 0);
        }
    }

    switch (o->oSubAction) {
        case 0:
            if (o->oTimer < 20) {
                break;
            }

            angle = atan2s(coordDests[2][2] - o->oPosZ, coordDests[2][0] - o->oPosX);
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, angle, 0xA00);
            if (angle == o->oFaceAngleYaw) {
                o->oSubAction++;
                o->oTimer = 0;
            }
            break;
        case 1:
            if (o->oTimer < 5) {
                break;
            }

            ratio = (f32) (o->oTimer - 5) / 105.0f;

            if (ratio >= 1.0f) {
                vec3f_copy(&o->oPosVec, coordDests[2]);
                vec3f_copy(&o->oHomeVec, coordDests[2]);
                o->oSubAction++;
                break;
            }

            o->oPosX = coordDests[2][0] * ratio + o->oHomeX * (1.0f - ratio);
            o->oPosY = coordDests[2][1] * ratio + o->oHomeY * (1.0f - ratio);
            o->oPosZ = coordDests[2][2] * ratio + o->oHomeZ * (1.0f - ratio);

            break;
        case 2:
            angle = atan2s(gMarioState->pos[2] - o->oPosZ, gMarioState->pos[0] - o->oPosX);
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, angle, 0xA00);
            if (ABS(angle - o->oFaceAngleYaw) < 0xA00) {
                o->oSubAction++;
                o->oTimer = 0;
            }
            break;
        case 3:
            if (o->oTimer >= 10) {
                o->oAction++;
            }
            break;
    }
}

static void blockington_act_wait_area_3(void) {
    if (
        o->oDistanceToMario <= 1600.0f &&
        gCamera->cutscene == FALSE &&
        !(gTimeStopState & TIME_STOP_ENABLED) &&
        (gMarioState->action == ACT_FAZANA_CAR && gMarioState->fazanaCar && gMarioState->fazanaCar->oFloor != NULL)
    ) {
        o->oAction++;
    }
}

#define BLOCKINGTON_TRANSITION_TIME_OUT 16
#define BLOCKINGTON_TRANSITION_TIME_IN 16
extern void set_background_music(u16 a, u16 seqArgs, s16 fadeTimer);
extern s16 object_step_without_floor_orient(void);
static void blockington_act_final_cutscene_transition(void) {
    if (o->oTimer == 0) {
        play_transition(WARP_TRANSITION_FADE_INTO_COLOR, BLOCKINGTON_TRANSITION_TIME_OUT, 0x00, 0x00, 0x00);
        fadeout_music((3 * BLOCKINGTON_TRANSITION_TIME_OUT / 2) * 8 - 2);
    }
    if (o->oTimer == BLOCKINGTON_TRANSITION_TIME_OUT) {
        gTimeStopState |= TIME_STOP_ENABLED;
        gCamera->cutscene = TRUE;
        play_transition(WARP_TRANSITION_FADE_FROM_COLOR, BLOCKINGTON_TRANSITION_TIME_IN, 0x00, 0x00, 0x00);

        set_background_music(0, SEQ_LEVEL_SNOW, 0);

        gHudDisplay.flags = HUD_DISPLAY_NONE;

        struct Object *obj = find_first_object_with_behavior_and_bparams(bhvFazanaCar, 0, 0);
        if (!obj) {
            error("No car found, that's kinda bad.");
        }

        set_mario_action(gMarioState, ACT_DISAPPEARED, 0);

        obj->oAction = FAZANA_CAR_ACT_CUTSCENE;
        obj->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
        obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
        vec3f_copy(&obj->oPosVec, &o->oPosVec);
        obj->oPosX += 2000;
        obj->oPosZ += 0;
        obj->oPosY = find_floor_height(obj->oPosX, obj->oPosY, obj->oPosZ);
        obj->oForwardVel = 0.0f;
        obj->oVelX = 0;
        obj->oVelY = 0;
        obj->oVelZ = 0;

        vec3f_copy(gMarioState->pos, &obj->oPosVec);

        vec3f_copy(gLakituState.goalFocus, &o->oPosVec);
        vec3f_copy(gLakituState.goalPos, &o->oPosVec);

        gLakituState.goalPos[0] = o->oPosX + 4500;
        gLakituState.goalPos[1] = o->oPosY + 850;
        gLakituState.goalPos[2] = o->oPosZ + 0;

        vec3f_copy(gLakituState.curFocus, gLakituState.goalFocus);
        vec3f_copy(gLakituState.curPos, gLakituState.goalPos);
    }

    if (o->oTimer == BLOCKINGTON_TRANSITION_TIME_OUT + (BLOCKINGTON_TRANSITION_TIME_IN / 2)) {
        struct Object *obj = spawn_object(o, MODEL_BLOCKINGTON_MINI, bhvBlockingtonMini);
        if (obj) {
            obj->oBehParams = ((BKTN_DIA_CS_FINAL_0) << 16) | 20; // Top priority
            obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
        } else {
            o->oAction++;
        }

        // BlockingtonMini should update the next action
    }
}

static void blockington_act_final_get_out_of_car(void) {
    if (o->oTimer == 0) {
        struct Object *obj = find_first_object_with_behavior_and_bparams(bhvFazanaCar, 0, 0);
        if (!obj) {
            error("No car found, that's kinda bad.");
        }

        gMarioState->pos[2] += 350;
        gMarioState->faceAngle[1] = 0xC000;
        gMarioObject->oFaceAngleYaw = gMarioState->faceAngle[1];

        vec3f_copy(gLakituState.goalFocus, &obj->oPosVec);
        vec3f_copy(gLakituState.goalPos, &obj->oPosVec);

        gLakituState.goalFocus[1] += 150;
        gLakituState.goalFocus[2] += 350;

        gLakituState.goalPos[0] = gLakituState.goalFocus[0] - (1250 + 400);
        gLakituState.goalPos[1] = gLakituState.goalFocus[1] + (1000 + 125);
        gLakituState.goalPos[2] = gLakituState.goalFocus[2];

        vec3f_copy(gLakituState.curFocus, gLakituState.goalFocus);
        vec3f_copy(gLakituState.curPos, gLakituState.goalPos);
    } else if (o->oTimer == 10) {
        struct Object *obj = find_first_object_with_behavior_and_bparams(bhvFazanaCar, 0, 0);
        if (!obj) {
            error("No car found, that's kinda bad.");
        }

        obj->oFazanaCarLeftDoor = 0;
    } else if (o->oTimer > 55 && o->oTimer <= 100) {
        struct Object *obj = find_first_object_with_behavior_and_bparams(bhvFazanaCar, 0, 0);
        if (!obj) {
            error("No car found, that's kinda bad.");
        }

        f32 mult = coss(0x4000 * (f32) (o->oTimer - 55) / 45.0f);
        gLakituState.goalPos[0] = gLakituState.goalFocus[0] - ((mult * 1250) + 400);
        gLakituState.goalPos[1] = gLakituState.goalFocus[1] + ((mult * 1000) + 125);

        vec3f_copy(gLakituState.curPos, gLakituState.goalPos);
    } 
    
    if (o->oTimer == 150) {
        o->oAction++;
    }
}

static void blockington_act_final_bktn_mad(void) {
    if (o->oTimer == 0) {
        vec3f_copy(gLakituState.goalFocus, &o->oPosVec);
        vec3f_copy(gLakituState.goalPos, &o->oPosVec);

        gLakituState.goalPos[0] = o->oPosX + 4500;
        gLakituState.goalPos[1] = o->oPosY + 850;
        gLakituState.goalPos[2] = o->oPosZ + 0;

        vec3f_copy(gLakituState.curFocus, gLakituState.goalFocus);
        vec3f_copy(gLakituState.curPos, gLakituState.goalPos);

        struct Object *obj = spawn_object(o, MODEL_BLOCKINGTON_MINI, bhvBlockingtonMini);
        if (obj) {
            obj->oBehParams = ((BKTN_DIA_CS_FINAL_1) << 16) | 20; // Top priority
            obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
        } else {
            o->oAction++;
        }

        // BlockingtonMini should update the next action
    }
}

static void blockington_act_final_bktn_tangent(void) {
    if (o->oTimer == 0) {
        approachFrames = 3;

        gLakituState.goalPos[0] = o->oPosX + 0;
        gLakituState.goalPos[1] = o->oPosY + 500;
        gLakituState.goalPos[2] = o->oPosZ + 2500;
        gLakituState.goalPos[0] += 1450;

        vec3f_copy(gLakituState.goalFocus, &o->oPosVec);
        gLakituState.goalFocus[0] += 1050;
        gLakituState.goalFocus[2] += 125;
    
        vec3f_copy(gLakituState.curPos, gLakituState.goalPos);
        vec3f_copy(gLakituState.curFocus, gLakituState.goalFocus);

        struct Object *obj = find_first_object_with_behavior_and_bparams(bhvStaticPNG, (1) << 16, 0x00FF0000);
        if (obj) {
            obj->oFaceAngleYaw += 0x2000;
        }
    }

    if (o->oTimer == 135) {
        approachFrames = 2;
    }

    if (o->oTimer == 270) {
        approachFrames = 1;
    }

    // gLakituState.goalPos[0] = 0;
    // gLakituState.goalPos[1] = 0;
    // gLakituState.goalPos[2] = 0;

    // vec3f_copy(gLakituState.curFocus, gLakituState.goalFocus);
    // vec3f_copy(gLakituState.curPos, gLakituState.goalPos);

    play_sound(SOUND_BLOCKINGTON_CS_ADLIB, gGlobalSoundSource);
}

static void blockington_act_final_bktn_shot(void) {
    approachFrames = 3;
}

ObjActionFunc sBlockingtonActions[] = {
    [BLOCKINGTON_ACT_SPAWN_WAIT]                = blockington_act_spawn_wait,
    [BLOCKINGTON_ACT_TALK_MARIO]                = blockington_act_talk_mario,
    [BLOCKINGTON_ACT_WAIT_CAR]                  = blockington_act_wait_car,
    [BLOCKINGTON_ACT_TALK_CAR]                  = blockington_act_talk_car,
    [BLOCKINGTON_ACT_WAIT_FOR_GATE]             = blockington_act_wait_for_gate,
    [BLOCKINGTON_ACT_MOVE_AREA_1]               = blockington_act_move_area_1,
    [BLOCKINGTON_ACT_WAIT_AREA_1]               = blockington_act_wait_area_1,
    [BLOCKINGTON_ACT_TALK_AREA_1]               = blockington_act_talk_area_1,
    [BLOCKINGTON_ACT_MOVE_AREA_2]               = blockington_act_move_area_2,
    [BLOCKINGTON_ACT_WAIT_AREA_2]               = blockington_act_wait_area_2,
    [BLOCKINGTON_ACT_TALK_AREA_2]               = blockington_act_talk_area_2,
    [BLOCKINGTON_ACT_MOVE_AREA_3]               = blockington_act_move_area_3,
    [BLOCKINGTON_ACT_WAIT_AREA_3]               = blockington_act_wait_area_3,
    [BLOCKINGTON_ACT_FINAL_CUTSCENE_TRANSITION] = blockington_act_final_cutscene_transition,
    [BLOCKINGTON_ACT_FINAL_GET_OUT_OF_CAR]      = blockington_act_final_get_out_of_car,
    [BLOCKINGTON_ACT_FINAL_BKTN_MAD]            = blockington_act_final_bktn_mad,
    [BLOCKINGTON_ACT_FINAL_BKTN_TANGENT]        = blockington_act_final_bktn_tangent,
    [BLOCKINGTON_ACT_FINAL_BKTN_SHOT]           = blockington_act_final_bktn_shot,
};

void bhv_blockington_loop(void) {
    cur_obj_call_action_function(sBlockingtonActions);

#ifdef ENABLE_DEBUG_FREE_MOVE
    if (gPlayer1Controller->buttonPressed & L_TRIG) {
        o->oAction = BLOCKINGTON_ACT_FINAL_CUTSCENE_TRANSITION;
        vec3f_copy(&o->oPosVec, coordDests[2]);
        vec3f_copy(&o->oHomeVec, coordDests[2]);
        return;
    }
#endif

    bhv_blockington_calculate_angle_scale_all();
    switch (o->oAction) {
        case BLOCKINGTON_ACT_WAIT_FOR_GATE:
        case BLOCKINGTON_ACT_MOVE_AREA_1:
        case BLOCKINGTON_ACT_MOVE_AREA_2:
        case BLOCKINGTON_ACT_MOVE_AREA_3:
            break;
        default:
            bhv_blockington_set_angle_scale();
    }
}
