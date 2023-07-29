// cq_bridge.inc.c

#define CQ_BRIDGE_DIST_CAM_XZ 11000.0f
#define CQ_BRIDGE_DIST_CAM_Y 7500.0f
#define CQ_BRIDGE_CUTSCENE_POS_SMOOTHSTEPXZ 0.12f
#define CQ_BRIDGE_CUTSCENE_POS_SMOOTHSTEPY 0.20f
#define CQ_BRIDGE_CUTSCENE_FOCUS_SMOOTHSTEPXZ 0.55f
#define CQ_BRIDGE_CUTSCENE_FOCUS_SMOOTHSTEPY 0.55f

enum CQBridgeActions {
    ACT_CQBRIDGE_HIDDEN,
    ACT_CQBRIDGE_ANIMATING,
    ACT_CQBRIDGE_VISIBLE,
};

static void bhv_cq_bridge_approach_camera_goal(void) {
    gLakituState.goalFocus[0] = smoothstep(gLakituState.goalFocus[0], o->oHomeX, CQ_BRIDGE_CUTSCENE_FOCUS_SMOOTHSTEPXZ);
    gLakituState.goalFocus[1] = smoothstep(gLakituState.goalFocus[1], o->oHomeY, CQ_BRIDGE_CUTSCENE_FOCUS_SMOOTHSTEPXZ);
    gLakituState.goalFocus[2] = smoothstep(gLakituState.goalFocus[2], o->oHomeZ, CQ_BRIDGE_CUTSCENE_FOCUS_SMOOTHSTEPXZ);

    gLakituState.goalPos[0] = smoothstep(gLakituState.goalPos[0], o->oCQBridgeCamPosX, CQ_BRIDGE_CUTSCENE_POS_SMOOTHSTEPXZ);
    gLakituState.goalPos[1] = smoothstep(gLakituState.goalPos[1], o->oCQBridgeCamPosY, CQ_BRIDGE_CUTSCENE_POS_SMOOTHSTEPY);
    gLakituState.goalPos[2] = smoothstep(gLakituState.goalPos[2], o->oCQBridgeCamPosZ, CQ_BRIDGE_CUTSCENE_POS_SMOOTHSTEPXZ);
}

static void bhv_cq_bridge_hidden(void) {
    Vec3f pos1;
    Vec3f pos2;
    Vec3f tmp;
    f32 dist1;
    f32 dist2;

    if (!(gPlayer1Controller->buttonPressed & L_TRIG)) {
        return;
    }

    if (gCamera->cutscene == FALSE && !(gTimeStopState & TIME_STOP_ENABLED) && (mario_ready_to_speak() || gMarioState->action == ACT_FAZANA_CAR)) {
        gTimeStopState |= TIME_STOP_ENABLED;
        o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
        gCamera->cutscene = TRUE;

        if (gMarioState->action != ACT_FAZANA_CAR) {
            set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0);
        }

        vec3f_copy(sCameraStoreCutscene.focus, gLakituState.goalFocus);
        vec3f_copy(sCameraStoreCutscene.pos, gLakituState.goalPos);

        o->oPosY = FLOOR_LOWER_LIMIT;
        o->oAction = ACT_CQBRIDGE_ANIMATING;
        o->oSubAction = 0;
        o->oCQBridgePanFrames = 0;
        
        // Calculate camera positions
        vec3f_copy(&o->oCQBridgeCamPosVec, &o->oHomeVec);
        o->oCQBridgeCamPosY += CQ_BRIDGE_DIST_CAM_Y;

        vec3f_copy(pos1, &o->oCQBridgeCamPosVec);
        vec3f_copy(pos2, &o->oCQBridgeCamPosVec);

        pos1[0] += CQ_BRIDGE_DIST_CAM_XZ * coss((s16) o->oFaceAngleYaw);
        pos1[2] += CQ_BRIDGE_DIST_CAM_XZ * sins((s16) o->oFaceAngleYaw);
        pos2[0] += CQ_BRIDGE_DIST_CAM_XZ * coss((s16) (o->oFaceAngleYaw + 0x8000));
        pos2[2] += CQ_BRIDGE_DIST_CAM_XZ * sins((s16) (o->oFaceAngleYaw + 0x8000));
        
        vec3_diff(tmp, sCameraStoreCutscene.pos, pos1);
        dist1 = vec3_sumsq(tmp);
        vec3_diff(tmp, sCameraStoreCutscene.pos, pos2);
        dist2 = vec3_sumsq(tmp);

        if (dist1 <= dist2) {
            vec3f_copy(&o->oCQBridgeCamPosVec, pos1);
        } else {
            vec3f_copy(&o->oCQBridgeCamPosVec, pos2);
        }
    }
}

static void bhv_cq_bridge_animating(void) {
    s32 diff = o->oHomeY - o->oPosY;

    switch (o->oSubAction) {
        case 0:
            if (o->oTimer < 10) {
                return; // Do not increment anim timer either
            }

            if (o->oTimer >= 30) {
                o->oSubAction++;
            }

            bhv_cq_bridge_approach_camera_goal();
            break;
        case 1:
            cur_obj_unhide();

            // TODO: object raising
            o->oPosY = lerpf(o->oPosY, o->oHomeY, 0.035f) + 4.0f;
            diff = o->oHomeY - o->oPosY;

            if (ABS(diff) < 5.0f) {
                o->oPosY = o->oHomeY;
                o->oSubAction++;
                o->oTimer = 0;
                cur_obj_play_sound_2(SOUND_GENERAL_ELEVATOR_LAND);
            } else {
                cur_obj_play_sound_2(SOUND_ENV_METAL_BOX_PUSH);
            }

            bhv_cq_bridge_approach_camera_goal();
            break;
        case 2:
            if (o->oTimer == 10) {
                play_puzzle_jingle();
            }

            if (o->oTimer >= 30) {
                o->oAction = ACT_CQBRIDGE_VISIBLE;
                load_object_static_model();

                vec3f_copy(gLakituState.goalFocus, sCameraStoreCutscene.focus);
                vec3f_copy(gLakituState.goalPos, sCameraStoreCutscene.pos);

                gTimeStopState &= ~TIME_STOP_ENABLED;
                o->activeFlags &= ~ACTIVE_FLAG_INITIATED_TIME_STOP;
                gCamera->cutscene = FALSE;

                if (gMarioState->action != ACT_FAZANA_CAR) {
                    set_mario_action(gMarioState, ACT_IDLE, 0);
                }
            } else {
                bhv_cq_bridge_approach_camera_goal();
            }
            break;
        case 3:
        default:
            break;
    }

    o->oCQBridgePanFrames++;
}

void bhv_cq_bridge_init(void) {
    cur_obj_hide();
}

void bhv_cq_bridge_loop(void) {
    switch (o->oAction) {
        case ACT_CQBRIDGE_HIDDEN:
            bhv_cq_bridge_hidden();
            break;
        case ACT_CQBRIDGE_ANIMATING:
            bhv_cq_bridge_animating();
            break;
        case ACT_CQBRIDGE_VISIBLE:
        default:
            break;
    }
}
