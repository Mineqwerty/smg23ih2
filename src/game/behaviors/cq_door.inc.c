// cq_door.inc.c

#define CQ_DOOR_DIST_CAM_XZ_START 2500.0f
#define CQ_DOOR_DIST_CAM_Y_START 250.0f
#define CQ_DOOR_DIST_CAM_XZ 1250.0f
#define CQ_DOOR_DIST_CAM_Y 50.0f
#define CQ_DOOR_CUTSCENE_POS_SMOOTHSTEPXZ 0.12f
#define CQ_DOOR_CUTSCENE_POS_SMOOTHSTEPY 0.20f

static void bhv_cq_door_approach_camera_goal(void) {
    vec3f_copy(gLakituState.goalFocus, &o->oHomeVec);
    vec3f_copy(gLakituState.curFocus, &o->oHomeVec);

    gLakituState.goalPos[0] = smoothstep(gLakituState.goalPos[0], o->oCQDoorCamPosX, CQ_DOOR_CUTSCENE_POS_SMOOTHSTEPXZ);
    gLakituState.goalPos[1] = smoothstep(gLakituState.goalPos[1], o->oCQDoorCamPosY, CQ_DOOR_CUTSCENE_POS_SMOOTHSTEPY);
    gLakituState.goalPos[2] = smoothstep(gLakituState.goalPos[2], o->oCQDoorCamPosZ, CQ_DOOR_CUTSCENE_POS_SMOOTHSTEPXZ);
}

void bhv_cq_door_init(void) {
    o->oHomeY += 266;
}

static void bhv_cq_door_hidden(void) {
    // if (gCamera->cutscene == FALSE && !(gTimeStopState & TIME_STOP_ENABLED) && (mario_ready_to_speak() || gMarioState->action == ACT_FAZANA_CAR)) {
        gTimeStopState |= TIME_STOP_ENABLED;
        o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
        gCamera->cutscene = TRUE;

        if (gMarioState->action != ACT_FAZANA_CAR) {
            set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0);
        }

        // vec3f_copy(sCameraStoreCutscene.focus, gLakituState.goalFocus);
        // vec3f_copy(sCameraStoreCutscene.pos, gLakituState.goalPos);

        o->oAction = ACT_CQDOOR_ANIMATING;
        o->oSubAction = 0;
        
        // Calculate camera positions
        vec3f_copy(&o->oCQDoorCamPosVec, &o->oHomeVec);

        o->oCQDoorCamPosX += CQ_DOOR_DIST_CAM_XZ * sins((s16) o->oFaceAngleYaw + 0x8000);
        o->oCQDoorCamPosY += CQ_DOOR_DIST_CAM_Y;
        o->oCQDoorCamPosZ += CQ_DOOR_DIST_CAM_XZ * coss((s16) o->oFaceAngleYaw + 0x8000);
    // }
}

static void bhv_cq_door_animating(void) {
    struct Object *obj;
    Vec3f pos;

    switch (o->oSubAction) {
        case 0:
            if (o->oTimer < 10) {
                return; // Do not increment anim timer either
            }

            if (o->oTimer == 10) {
                vec3f_copy(pos, &o->oHomeVec);
                pos[0] += CQ_DOOR_DIST_CAM_XZ_START * sins((s16) o->oFaceAngleYaw + 0x8000);
                pos[1] += CQ_DOOR_DIST_CAM_Y_START;
                pos[2] += CQ_DOOR_DIST_CAM_XZ_START * coss((s16) o->oFaceAngleYaw + 0x8000);

                vec3f_copy(gLakituState.goalPos, pos);
                vec3f_copy(gLakituState.curPos, pos);
            }

            if (o->oTimer >= 45) {
                o->oSubAction++;
                o->oTimer = 0;
            }

            bhv_cq_door_approach_camera_goal();
            break;
        case 1:
            cur_obj_hide();
    
            obj = find_first_object_with_behavior_and_bparams(bhvFazanaCar, 0, 0xFF);
            if (obj) {
                obj->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
            }

            obj = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
            if (obj) {
                obj->oPosY = o->oHomeY;
                obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                obj->oBehParams = 0x16;
            }

            o->oSubAction++;
            o->oTimer = 0;

            bhv_cq_door_approach_camera_goal();
            break;
        case 2:
            if (o->oTimer >= 60) {
                vec3f_copy(gLakituState.goalFocus, sCameraStoreCutscene.focus);
                vec3f_copy(gLakituState.goalPos, sCameraStoreCutscene.pos);
                vec3f_copy(gLakituState.curFocus, sCameraStoreCutscene.focus);
                vec3f_copy(gLakituState.curPos, sCameraStoreCutscene.pos);

                gTimeStopState &= ~TIME_STOP_ENABLED;
                o->activeFlags &= ~ACTIVE_FLAG_INITIATED_TIME_STOP;
                gCamera->cutscene = FALSE;

                if (gMarioState->action != ACT_FAZANA_CAR) {
                    set_mario_action(gMarioState, ACT_IDLE, 0);
                }

                obj_mark_for_deletion(o);
            } else {
                bhv_cq_door_approach_camera_goal();
            }
            break;
        default:
            break;
    }
}

void bhv_cq_door_loop(void) {
    switch (o->oAction) {
        case ACT_CQDOOR_WAITING:
            // Triggered externally
            break;
        case ACT_CQDOOR_HIDDEN:
            bhv_cq_door_hidden();
            break;
        case ACT_CQDOOR_ANIMATING:
            bhv_cq_door_animating();
            break;
        default:
            obj_mark_for_deletion(o);
            break;
    }
}
