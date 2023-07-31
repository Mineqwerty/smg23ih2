// blockington.inc.c

#include "blockington.inc.h"

#define PITCH_VARIANCE 0x1200
#define YAW_VARIANCE 0x0C00
#define ROLL_VARIANCE 0x0C00

#define SCALE_VARIANCE_X 0.3f
#define SCALE_VARIANCE_Y 0.5f
#define SCALE_VARIANCE_Z 0.3f

#define APPROACH_FRAMES 3

struct BlockingtonStates sBlockington;

const Vec3i angleLimitFactors = {0x3000, 0x1800, 0x1800};

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

    for (u32 i = 0; i < bMiniDialogsCount; i++) {
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

void bhv_blockington_loop(void) {
    if (gPlayer1Controller->buttonPressed == L_TRIG) {
        struct Object *obj = spawn_object(o, MODEL_BLOCKINGTON_MINI, bhvBlockingtonMini);
        if (obj) {
            obj->oBehParams = (random_u16() % 5) << 16;
        }
    }

    bhv_blockington_calculate_angle_scale_all();
    bhv_blockington_set_angle_scale();
}

