// cq_gate.inc.c

#define CQ_GATE_DIST_CAM_XZ_START 3500.0f
#define CQ_GATE_DIST_CAM_Y_START 1000.0f
#define CQ_GATE_DIST_CAM_XZ 2000.0f
#define CQ_GATE_DIST_CAM_Y 250.0f
#define CQ_GATE_CUTSCENE_POS_SMOOTHSTEPXZ 0.12f
#define CQ_GATE_CUTSCENE_POS_SMOOTHSTEPY 0.20f

static void bhv_cq_gate_approach_camera_goal(void) {
    if (!o->oCQGateCamShouldUpdate) {
        return;
    }

    vec3f_copy(gLakituState.goalFocus, &o->oHomeVec);
    vec3f_copy(gLakituState.curFocus, &o->oHomeVec);

    gLakituState.goalPos[0] = smoothstep(gLakituState.goalPos[0], o->oCQGateCamPosX, CQ_GATE_CUTSCENE_POS_SMOOTHSTEPXZ);
    gLakituState.goalPos[1] = smoothstep(gLakituState.goalPos[1], o->oCQGateCamPosY, CQ_GATE_CUTSCENE_POS_SMOOTHSTEPY);
    gLakituState.goalPos[2] = smoothstep(gLakituState.goalPos[2], o->oCQGateCamPosZ, CQ_GATE_CUTSCENE_POS_SMOOTHSTEPXZ);
}

void bhv_cq_gate_init(void) {
    o->oHomeY += 622;
    o->oCQGateCamShouldUpdate = TRUE;
}

static void bhv_cq_gate_hidden(void) {
    // if (gCamera->cutscene == FALSE && !(gTimeStopState & TIME_STOP_ENABLED) && (mario_ready_to_speak() || gMarioState->action == ACT_FAZANA_CAR)) {
        gTimeStopState |= TIME_STOP_ENABLED;
        o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
        gCamera->cutscene = TRUE;

        if (gMarioState->action != ACT_FAZANA_CAR) {
            set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0);
        }

        // vec3f_copy(sCameraStoreCutscene.focus, gLakituState.goalFocus);
        // vec3f_copy(sCameraStoreCutscene.pos, gLakituState.goalPos);

        o->oAction = ACT_CQGATE_ANIMATING;
        o->oSubAction = 0;
        
        // Calculate camera positions
        vec3f_copy(&o->oCQGateCamPosVec, &o->oHomeVec);

        o->oCQGateCamPosX += CQ_GATE_DIST_CAM_XZ * sins((s16) o->oFaceAngleYaw + 0x8000);
        o->oCQGateCamPosY += CQ_GATE_DIST_CAM_Y;
        o->oCQGateCamPosZ += CQ_GATE_DIST_CAM_XZ * coss((s16) o->oFaceAngleYaw + 0x8000);
    // }
}

static void bhv_cq_gate_animating(void) {
    struct Object *obj;
    Vec3f pos;

    switch (o->oSubAction) {
        case 0:
            if (o->oTimer < 10) {
                return; // Do not increment anim timer either
            }

            if (o->oTimer == 10) {
                vec3f_copy(pos, &o->oHomeVec);
                pos[0] += CQ_GATE_DIST_CAM_XZ_START * sins((s16) o->oFaceAngleYaw + 0x8000);
                pos[1] += CQ_GATE_DIST_CAM_Y_START;
                pos[2] += CQ_GATE_DIST_CAM_XZ_START * coss((s16) o->oFaceAngleYaw + 0x8000);

                vec3f_copy(gLakituState.goalPos, pos);
                vec3f_copy(gLakituState.curPos, pos);
            }

            if (o->oTimer >= 25) {
                o->oSubAction++;
                o->oTimer = 0;
            }

            bhv_cq_gate_approach_camera_goal();
            break;
        case 1:
            switch (o->oTimer) {
                case 1:
                    obj = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
                    cur_obj_play_sound_2(SOUND_GENERAL2_BOBOMB_EXPLOSION);
                    if (obj) {
                        obj->oPosX = o->oHomeX + (195 * 4);
                        obj->oPosY = o->oHomeY + (107 * 2);
                        obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                        obj->oBehParams = 0x1C;
                    }
                    break;
                case 4:
                    obj = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
                    cur_obj_play_sound_2(SOUND_GENERAL2_BOBOMB_EXPLOSION);
                    if (obj) {
                        obj->oPosX = o->oHomeX - (195 * 4);
                        obj->oPosY = o->oHomeY - (107 * 2);
                        obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                        obj->oBehParams = 0x1C;
                    }
                    break;
                case 7:
                    obj = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
                    cur_obj_play_sound_2(SOUND_GENERAL2_BOBOMB_EXPLOSION);
                    if (obj) {
                        obj->oPosX = o->oHomeX + (195 * 2);
                        obj->oPosY = o->oHomeY + (107 * 2);
                        obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                        obj->oBehParams = 0x1C;
                    }
                    break;
                case 10:
                    obj = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
                    cur_obj_play_sound_2(SOUND_GENERAL2_BOBOMB_EXPLOSION);
                    if (obj) {
                        obj->oPosX = o->oHomeX - (195 * 2);
                        obj->oPosY = o->oHomeY - (107 * 2);
                        obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                        obj->oBehParams = 0x1C;
                    }
                    break;
                case 13:
                    obj = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
                    cur_obj_play_sound_2(SOUND_GENERAL2_BOBOMB_EXPLOSION);
                    if (obj) {
                        obj->oPosX = o->oHomeX + (195 * 4);
                        obj->oPosY = o->oHomeY;
                        obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                        obj->oBehParams = 0x1C;
                    }
                    break;
                case 16:
                    obj = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
                    cur_obj_play_sound_2(SOUND_GENERAL2_BOBOMB_EXPLOSION);
                    if (obj) {
                        obj->oPosX = o->oHomeX;
                        obj->oPosY = o->oHomeY;
                        obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                        obj->oBehParams = 0x1C;
                    }
                    break;
                case 19:
                    obj = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
                    cur_obj_play_sound_2(SOUND_GENERAL2_BOBOMB_EXPLOSION);
                    if (obj) {
                        obj->oPosX = o->oHomeX - (195 * 4);
                        obj->oPosY = o->oHomeY + (107 * 2);
                        obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                        obj->oBehParams = 0x1C;
                    }
                    break;
                case 22:
                    obj = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
                    cur_obj_play_sound_2(SOUND_GENERAL2_BOBOMB_EXPLOSION);
                    if (obj) {
                        obj->oPosX = o->oHomeX - (195 * 2);
                        obj->oPosY = o->oHomeY - (107 * 2);
                        obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                        obj->oBehParams = 0x1C;
                    }
                    break;
                case 25:
                    obj = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
                    cur_obj_play_sound_2(SOUND_GENERAL2_BOBOMB_EXPLOSION);
                    if (obj) {
                        obj->oPosX = o->oHomeX + (195 * 2);
                        obj->oPosY = o->oHomeY + (107 * 2);
                        obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                        obj->oBehParams = 0x1C;
                    }
                    break;
                case 28:
                    obj = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
                    cur_obj_play_sound_2(SOUND_GENERAL2_BOBOMB_EXPLOSION);
                    if (obj) {
                        obj->oPosX = o->oHomeX + (195 * 2);
                        obj->oPosY = o->oHomeY - (107 * 2);
                        obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                        obj->oBehParams = 0x1C;
                    }
                    break;
                case 31:
                    obj = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
                    cur_obj_play_sound_2(SOUND_GENERAL2_BOBOMB_EXPLOSION);
                    if (obj) {
                        obj->oPosX = o->oHomeX - (195 * 2);
                        obj->oPosY = o->oHomeY + (107 * 2);
                        obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                        obj->oBehParams = 0x1C;
                    }
                    break;
                case 50:
                    cur_obj_hide();

                    obj = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
                    cur_obj_play_sound_2(SOUND_GENERAL2_BOBOMB_EXPLOSION);
                    if (obj) {
                        obj->oPosY = o->oHomeY;
                        obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                        obj->oBehParams = 0x48;
                    }

                    o->oSubAction++;
                    o->oTimer = 0;
                    break;
            }

            bhv_cq_gate_approach_camera_goal();
            break;
        case 2:
            if (o->oTimer >= 60) {
                // NOTE: Handled in blockington behavior
                // vec3f_copy(gLakituState.goalFocus, sCameraStoreCutscene.focus);
                // vec3f_copy(gLakituState.goalPos, sCameraStoreCutscene.pos);
                // vec3f_copy(gLakituState.curFocus, sCameraStoreCutscene.focus);
                // vec3f_copy(gLakituState.curPos, sCameraStoreCutscene.pos);

                // gTimeStopState &= ~TIME_STOP_ENABLED;
                // o->activeFlags &= ~ACTIVE_FLAG_INITIATED_TIME_STOP;
                // gCamera->cutscene = FALSE;

                // if (gMarioState->action != ACT_FAZANA_CAR) {
                //     set_mario_action(gMarioState, ACT_IDLE, 0);
                // }

                obj_mark_for_deletion(o);
            } else {
                bhv_cq_gate_approach_camera_goal();
            }
            break;
        default:
            break;
    }
}

void bhv_cq_gate_loop(void) {
    switch (o->oAction) {
        case ACT_CQGATE_WAITING:
            // Triggered externally
            break;
        case ACT_CQGATE_HIDDEN:
            bhv_cq_gate_hidden();
            break;
        case ACT_CQGATE_ANIMATING:
            bhv_cq_gate_animating();
            break;
        default:
            obj_mark_for_deletion(o);
            break;
    }
}
