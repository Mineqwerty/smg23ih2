#include "src/game/hud.h"

enum PersonaBattleActions {
    PERSONA_ACT_INTRO,
    PERSONA_ACT_MARIO_TURN,
};

void mario_move_fvel(void) {
    gMarioState->pos[0] += gMarioState->forwardVel * sins(gMarioState->faceAngle[1]);
    gMarioState->pos[2] += gMarioState->forwardVel * coss(gMarioState->faceAngle[1]);
}

void bhv_persona_battle_manager_init(void) {
    gCamera->cutscene = 1;
    gLakituState.goalPos[0] = 33;
    gLakituState.goalPos[1] = 176;
    gLakituState.goalPos[2] = 583;
    gMarioState->pos[0] = -608.0f;
    gMarioState->pos[1] = 0;
    gMarioState->pos[2] = 530.0f;
    gMarioState->faceAngle[1] = 0x2000;
    set_mario_anim_with_accel(gMarioState, MARIO_ANIM_RUNNING, 0x40000);
    gMarioState->forwardVel = 20.0f;
}

void bhv_persona_battle_manager_loop(void) {
   switch (o->oAction) {
    case PERSONA_ACT_INTRO:
        //camera
        if (o->oTimer < 45) {
            gCamera->cutscene = 1;
            gLakituState.goalPos[0] = -56;
            gLakituState.goalPos[1] = 176;
            gLakituState.goalPos[2] = 1611;
            gLakituState.goalFocus[0] = -608.0f;
            gLakituState.goalFocus[1] = 0;
            gLakituState.goalFocus[2] = 530.0f;
        }
        else {
            Vec3f endCameraPos = {1000.0f, 442.0f, 2300.0f};
            Vec3f endCameraFocus = {200.0f, 0.0f, 1400.0f};
            approach_vec3f_asymptotic(gLakituState.goalPos, endCameraPos, 0.05f, 0.05f, 0.05f);
            approach_vec3f_asymptotic(gLakituState.goalFocus, endCameraFocus, 0.05f, 0.05f, 0.05f);
        }

        //mario movement
        if (o->oTimer < 60) {
            mario_move_fvel();
        }
        if (o->oTimer == 60) {
            set_mario_animation(gMarioState, MARIO_ANIM_TURNING_PART1);
        }
        if (o->oTimer >= 60 && o->oTimer < 68) {
            mario_move_fvel();
            if (gMarioState->forwardVel > 0) gMarioState->forwardVel -= 1;
            if (is_anim_at_end(gMarioState)) {
                set_mario_animation(gMarioState, MARIO_ANIM_TURNING_PART2);
            }
        }
        if (o->oTimer >= 68 && o->oTimer < 150 && is_anim_at_end(gMarioState)) {
            gMarioState->faceAngle[1] += 0x8000;
            
            o->oTimer = 180;
        }
        if (o->oTimer == 181) {
            o->oAction = PERSONA_ACT_MARIO_TURN;
            gMarioState->forwardVel = 0;
            set_mario_animation(gMarioState, MARIO_ANIM_IDLE_HEAD_LEFT);
        }
    break;
    case PERSONA_ACT_MARIO_TURN:


        if (o->oTimer < 15) {
            gPersonaHUDAlpha = o->oTimer * 14;
        }
        else {
            gPersonaHUDAlpha = 210;
        }




        switch (gMarioState->actionState) {
            case 0:
                set_mario_animation(gMarioState, MARIO_ANIM_IDLE_HEAD_LEFT);
                break;

            case 1:
                set_mario_animation(gMarioState, MARIO_ANIM_IDLE_HEAD_RIGHT);
                break;

            case 2:
                set_mario_animation(gMarioState, MARIO_ANIM_IDLE_HEAD_CENTER);
                break;
        }

        if (is_anim_at_end(gMarioState)) {
            gMarioState->actionState++;
            if (gMarioState->actionState == 3) {
                gMarioState->actionState = 0;
            }
        }
    break;
   }
}

