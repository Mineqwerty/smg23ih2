// blockington.inc.c

#include "blockington.h"

#define PITCH_VARIANCE 0x1200
#define YAW_VARIANCE 0x0C00
#define ROLL_VARIANCE 0x0C00

#define SCALE_VARIANCE_X 0.3f
#define SCALE_VARIANCE_Y 0.5f
#define SCALE_VARIANCE_Z 0.3f

#define APPROACH_FRAMES 3


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
    BLOCKINGTON_ACT_FINAL_CUTSCENE_TODO,
};

struct BlockingtonStates sBlockington;

const Vec3i angleLimitFactors = {0x3000, 0x1800, 0x1800};

const Vec3f coordDests[3] = {
    {0.0f, 1750.0f + 351.0f, -7500.0f},
    {1000.0f, 4750.0f + 351.0f, 11250.0f},
    {-27502.0f, 5768.0f + 351.0f, 22944.0f},
};

void bhv_blockington_init(void) {
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

        isTalking = FALSE;
    } else {
        isTalking = (o->oAction == ACT_BMINI_TALK);
    }

    sBlockington.updateVar = gGlobalTimer;

    if (o->oTimer % APPROACH_FRAMES == 0) {
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

        sBlockington.approachAngle[0] = ((s16) ((u16) sBlockington.goalAngle[0] - (u16) sBlockington.curAngle[0])) / (s16) APPROACH_FRAMES;
        sBlockington.approachAngle[1] = ((s16) ((u16) sBlockington.goalAngle[1] - (u16) sBlockington.curAngle[1])) / (s16) APPROACH_FRAMES;
        sBlockington.approachAngle[2] = ((s16) ((u16) sBlockington.goalAngle[2] - (u16) sBlockington.curAngle[2])) / (s16) APPROACH_FRAMES;
        
        sBlockington.approachScale[0] = (sBlockington.goalScale[0] - sBlockington.curScale[0]) / APPROACH_FRAMES;
        sBlockington.approachScale[1] = (sBlockington.goalScale[1] - sBlockington.curScale[1]) / APPROACH_FRAMES;
        sBlockington.approachScale[2] = (sBlockington.goalScale[2] - sBlockington.curScale[2]) / APPROACH_FRAMES;
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
            obj->oBehParams = (BKTN_DIA_CS_MARIO) << 16;
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
            obj->oBehParams = (BKTN_DIA_CS_CAR) << 16;
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
            obj->oBehParams = (BKTN_DIA_CS_FIRST_AREA) << 16;
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
            obj->oBehParams = (BKTN_DIA_CS_SECOND_AREA) << 16;
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
        (mario_ready_to_speak() || 
            (gMarioState->action == ACT_FAZANA_CAR && gMarioState->fazanaCar && gMarioState->fazanaCar->oFloor != NULL))
    ) {
        // TODO: final cutscene shit

        FORCE_CRASH; // TODO: remove (obviously), but crashing here means success for now
        o->oAction++;
    }
}

static void blockington_act_final_cutscene_todo(void) {

}

ObjActionFunc sBlockingtonActions[] = {
    [BLOCKINGTON_ACT_SPAWN_WAIT]          = blockington_act_spawn_wait,
    [BLOCKINGTON_ACT_TALK_MARIO]          = blockington_act_talk_mario,
    [BLOCKINGTON_ACT_WAIT_CAR]            = blockington_act_wait_car,
    [BLOCKINGTON_ACT_TALK_CAR]            = blockington_act_talk_car,
    [BLOCKINGTON_ACT_WAIT_FOR_GATE]       = blockington_act_wait_for_gate,
    [BLOCKINGTON_ACT_MOVE_AREA_1]         = blockington_act_move_area_1,
    [BLOCKINGTON_ACT_WAIT_AREA_1]         = blockington_act_wait_area_1,
    [BLOCKINGTON_ACT_TALK_AREA_1]         = blockington_act_talk_area_1,
    [BLOCKINGTON_ACT_MOVE_AREA_2]         = blockington_act_move_area_2,
    [BLOCKINGTON_ACT_WAIT_AREA_2]         = blockington_act_wait_area_2,
    [BLOCKINGTON_ACT_TALK_AREA_2]         = blockington_act_talk_area_2,
    [BLOCKINGTON_ACT_MOVE_AREA_3]         = blockington_act_move_area_3,
    [BLOCKINGTON_ACT_WAIT_AREA_3]         = blockington_act_wait_area_3,
    [BLOCKINGTON_ACT_FINAL_CUTSCENE_TODO] = blockington_act_final_cutscene_todo,
};

void bhv_blockington_loop(void) {
    cur_obj_call_action_function(sBlockingtonActions);

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
