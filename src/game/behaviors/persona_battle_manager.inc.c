#include "src/game/hud.h"
#include "src/game/personaBattle.h"

enum PersonaBattleActions {
    PERSONA_ACT_INTRO,
    PERSONA_ACT_MARIO_TURN,
    PERSONA_ACT_SELECT_ATTACK,
    PERSONA_ACT_MARIO_ATTACKING,
    PERSONA_ACT_SELECT_SKILL,
    PERSONA_ACT_SELECT_SKILL_TARGET,
    PERSONA_ACT_USING_SKILL,

};

void mario_move_fvel(void) {
    gMarioState->pos[0] += gMarioState->forwardVel * sins(gMarioState->faceAngle[1]);
    gMarioState->pos[2] += gMarioState->forwardVel * coss(gMarioState->faceAngle[1]);
}

void animate_mario_idle(void) {
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
}

void select_enemy(struct Object *selectedEnemy) {
    struct Object *findEnemy = cur_obj_find_object_with_bparam_2nd_byte(bhvCowardlyMaya, gSelectedEnemy);
    if (!findEnemy) {
        gSelectedEnemy += 1;
        if (gSelectedEnemy > 2) {
            gSelectedEnemy = 0;
        }
        select_enemy(selectedEnemy);
    }
    else {
        selectedEnemy = findEnemy;
    }
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

    struct Object *selectedEnemy;
    Vec3f endCameraPos = {1000.0f, 442.0f, 2300.0f};
    Vec3f endCameraFocus = {200.0f, 0.0f, 1400.0f};

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
            gPersonaMenuFlags |= PERSONA_MENU_FLAGS_MAIN_TEXT;
            gMarioState->forwardVel = 0;
            set_mario_animation(gMarioState, MARIO_ANIM_IDLE_HEAD_LEFT);
        }
    break;
    case PERSONA_ACT_MARIO_TURN:
        switch (o->oSubAction) {
            case 0:
                if (o->oTimer < 15) {
                    gPersonaHUDAlpha = o->oTimer * 14;
                }
                else {
                    gPersonaHUDAlpha = 210;
                    o->oSubAction = 1;
                }

                
                approach_vec3f_asymptotic(gLakituState.goalPos, endCameraPos, 0.15f, 0.15f, 0.15f);
                approach_vec3f_asymptotic(gLakituState.goalFocus, endCameraFocus, 0.15f, 0.15f, 0.15f);
            break;
            case 1:
                if (gPlayer1Controller->buttonPressed & A_BUTTON) {
                    switch (gSelectedBattleCommand) {
                        case 0:
                            o->oAction = PERSONA_ACT_SELECT_ATTACK;
                            gPersonaMenuFlags |= PERSONA_MENU_FLAGS_ATTACK_TEXT;
                            gSelectedEnemy = 0;
                            select_enemy(selectedEnemy);
                            spawn_object(o, MODEL_ENEMY_SELECTOR, bhvEnemySelector);
                            
                        break;
                        case 1:
                            o->oAction = PERSONA_ACT_SELECT_SKILL;
                        break;
                    }
                }
                else if (gPlayer1Controller->rawStickY > 8) {
                    play_sound(SOUND_CUSTOM0_P_MENU_ROTATE, gGlobalSoundSource);
                    gSelectedBattleCommand++;
                    if (gSelectedBattleCommand == 7) {
                        gSelectedBattleCommand = 0;
                    }
                    gBattleOptionRotationTimer = 1;
                    o->oSubAction = 2;
                }
                else if (gPlayer1Controller->rawStickY <= -8) {
                    play_sound(SOUND_CUSTOM0_P_MENU_ROTATE, gGlobalSoundSource);
                    gSelectedBattleCommand--;
                    if (gSelectedBattleCommand == -1) {
                        gSelectedBattleCommand = 6;
                    }
                    gBattleOptionRotationTimer = -1;
                    o->oSubAction = 3;
                }
            break;
            case 2:
                gBattleOptionRotationTimer++;
                if (gBattleOptionRotationTimer == 10) {
                    o->oSubAction = 1;
                    gBattleOptionRotationTimer = 0;
                }
            break;
            case 3:
                gBattleOptionRotationTimer--;
                if (gBattleOptionRotationTimer == -10) {
                    o->oSubAction = 1;
                    gBattleOptionRotationTimer = 0;
                }
            break;
        }




        animate_mario_idle();
    break;

    case PERSONA_ACT_SELECT_ATTACK:
        if (gPlayer1Controller->rawStickX > 8) {
            if (gSelectorCooldown == FALSE) {
                gSelectorCooldown = TRUE;
                gSelectedEnemy++;
                if (gSelectedEnemy == 3) {
                    gSelectedEnemy = 0;
                }
                select_enemy(selectedEnemy);
                play_sound(SOUND_CUSTOM0_P_SELECTOR, gGlobalSoundSource);
            }
        }
        else if (gPlayer1Controller->rawStickX < -8) {
            if (gSelectorCooldown == FALSE) {
                gSelectorCooldown = TRUE;
                gSelectedEnemy--;
                if (gSelectedEnemy == -1) {
                    gSelectedEnemy = 2;
                }
                select_enemy(selectedEnemy);
                play_sound(SOUND_CUSTOM0_P_SELECTOR, gGlobalSoundSource);
            }
        }
        else if (gPlayer1Controller->buttonPressed & B_BUTTON) {
            o->oAction = PERSONA_ACT_MARIO_TURN;
            play_sound(SOUND_CUSTOM0_P_CANCEL, gGlobalSoundSource);
            gPersonaMenuFlags &= ~(PERSONA_MENU_FLAGS_ATTACK_TEXT);
        }
        else {
            gSelectorCooldown = FALSE;
        }

        selectedEnemy = cur_obj_find_object_with_bparam_2nd_byte(bhvCowardlyMaya, gSelectedEnemy);

        if (selectedEnemy) {
            Vec3f enemyCameraPos = {selectedEnemy->oPosX + 500, 342.0f, selectedEnemy->oPosZ + 500};
            Vec3f enemyCameraFocus = {selectedEnemy->oPosX, 42.0f, selectedEnemy->oPosZ};
            approach_vec3f_asymptotic(gLakituState.goalPos, enemyCameraPos, 0.05f, 0.05f, 0.05f);
            approach_vec3f_asymptotic(gLakituState.goalFocus, enemyCameraFocus, 0.05f, 0.05f, 0.05f);
        }
        animate_mario_idle();
    break;
   }
}

