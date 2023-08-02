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

    PERSONA_ACT_ENEMY_TURNS,
    PERSONA_ACT_VICTORY

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

void transition_to_enemy_turn(void) {
    o->oAction = PERSONA_ACT_ENEMY_TURNS;
    gSelectedEnemy = 0;
    gMarioState->pos[0] = 333;
    gMarioState->pos[1] = 0;
    gMarioState->pos[2] = 1471;
    gMarioState->faceAngle[1] = -0x6000;
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
    struct Object *selectedEnemy = NULL;
    Vec3f endCameraPos = {1000.0f, 442.0f, 2300.0f};
    Vec3f endCameraFocus = {200.0f, 0.0f, 1400.0f};
    Vec3f relEnemyPos = {0, 0, 0};

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
                            gPersonaMenuFlags &= ~(PERSONA_MENU_FLAGS_MAIN_TEXT);
                            gPersonaMenuFlags &= ~(PERSONA_MENU_FLAGS_ATTACK_TEXT);
                            gPersonaMenuFlags |= PERSONA_MENU_FLAGS_SKILL_TEXT;
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
        else if (gPlayer1Controller->buttonPressed & A_BUTTON) {
            o->oAction = PERSONA_ACT_MARIO_ATTACKING;
            gPersonaMenuFlags &= ~(PERSONA_MENU_FLAGS_MAIN_TEXT);
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
    case PERSONA_ACT_MARIO_ATTACKING:
        switch (o->oSubAction) {
            case 0:
                selectedEnemy = cur_obj_find_object_with_bparam_2nd_byte(bhvCowardlyMaya, gSelectedEnemy);
                gLakituState.goalPos[0] = selectedEnemy->oPosX + 30;
                gLakituState.goalPos[1] = 1000;
                gLakituState.goalPos[2] = selectedEnemy->oPosZ + 2300;
                set_mario_anim_with_accel(gMarioState, MARIO_ANIM_RUNNING, 0x40000);
                gPersonaMenuFlags |= PERSONA_MENU_FLAGS_STRIKE_ATTACK_TEXT;
                if (o->oTimer == 0) {
                    vec3f_copy(gLakituState.goalFocus, gMarioState->pos);
                }
                else {
                    approach_vec3f_asymptotic(gLakituState.goalFocus, gMarioState->pos, 0.05f, 0.05f, 0.05f);
                }
                if (o->oTimer < 40) {
                    vec3f_copy(relEnemyPos, &selectedEnemy->oPosVec);
                    relEnemyPos[0] += 200;
                    relEnemyPos[2] += 200;

                    approach_vec3f_asymptotic(gMarioState->pos, relEnemyPos, 0.08f, 0.08f, 0.08f);
                    gMarioState->faceAngle[1] = approach_s16_symmetric(gMarioState->faceAngle[1], 
                        atan2s(selectedEnemy->oPosZ - gMarioState->pos[2], 
                        selectedEnemy->oPosX - gMarioState->pos[0]), 0x200);
                }
                if (o->oTimer == 40) {
                    gLakituState.goalPos[0] = gMarioState->pos[0] + 90;
                gLakituState.goalPos[1] = 200;
                gLakituState.goalPos[2] = gMarioState->pos[2] + 300;
                vec3f_copy(gLakituState.goalFocus, &selectedEnemy->oPosVec);
                    set_mario_animation(gMarioState, MARIO_ANIM_FIRST_PUNCH);
                    play_sound(SOUND_MARIO_PUNCH_YAH, gGlobalSoundSource);
                    gPersonaMenuFlags &= ~(PERSONA_MENU_FLAGS_STRIKE_ATTACK_TEXT);
                    o->oSubAction++;
                }
            break;
            case 1:
                if (is_anim_at_end(gMarioState)) {
                    set_mario_animation(gMarioState, MARIO_ANIM_FIRST_PUNCH_FAST);
                    o->oSubAction++;
                    o->oTimer = 0;
                    selectedEnemy = cur_obj_find_object_with_bparam_2nd_byte(bhvCowardlyMaya, gSelectedEnemy);
                    selectedEnemy->oAction = 4;
                }
            break;
            case 2:
                if (is_anim_at_end(gMarioState) && o->oTimer > 20) {
                    set_mario_animation(gMarioState, MARIO_ANIM_SECOND_PUNCH);
                    play_sound(SOUND_MARIO_PUNCH_WAH, gGlobalSoundSource);
                    o->oSubAction++;
                }
            break;
            case 3:
                if (is_anim_at_end(gMarioState)) {
                    set_mario_animation(gMarioState, MARIO_ANIM_SECOND_PUNCH_FAST);
                    o->oSubAction++;
                    o->oTimer = 0;
                    selectedEnemy = cur_obj_find_object_with_bparam_2nd_byte(bhvCowardlyMaya, gSelectedEnemy);
                    selectedEnemy->oAction = 3;
                    gEnemyCount--;
                }
            break;
            case 4:
                if (is_anim_at_end(gMarioState) && o->oTimer > 40) {
                    selectedEnemy = cur_obj_find_object_with_bparam_2nd_byte(bhvCowardlyMaya, gSelectedEnemy);
                    obj_mark_for_deletion(selectedEnemy);
                if (gEnemyCount == 0) {
                    o->oAction = PERSONA_ACT_VICTORY;
                }
                else {
                    transition_to_enemy_turn();
                }
                    
                }
            break;
        }
    break;
    case PERSONA_ACT_SELECT_SKILL:
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
                    o->oAction = PERSONA_ACT_SELECT_SKILL_TARGET;
                    gPersonaMenuFlags |= PERSONA_MENU_FLAGS_ATTACK_TEXT;
                    gSelectedEnemy = 0;
                    select_enemy(selectedEnemy);
                    spawn_object_relative(gSelectedSkillIndex + 1, 0, 0, 0, o, MODEL_ENEMY_SELECTOR, bhvEnemySelector);
                }
                else if (gPlayer1Controller->buttonPressed & B_BUTTON) {
                    o->oAction = PERSONA_ACT_MARIO_TURN;
                    play_sound(SOUND_CUSTOM0_P_CANCEL, gGlobalSoundSource);
                    gPersonaMenuFlags &= ~(PERSONA_MENU_FLAGS_SKILL_TEXT);
                    gPersonaMenuFlags |= PERSONA_MENU_FLAGS_MAIN_TEXT;
                }
                else if (gPlayer1Controller->rawStickY > 8) {
                    play_sound(SOUND_CUSTOM0_P_SELECTOR, gGlobalSoundSource);
                    gSelectedSkillIndex++;
                    if (gSelectedSkillIndex == 2) {
                        gSelectedSkillIndex = 0;
                    }
                    gBattleOptionRotationTimer = 1;
                    o->oSubAction = 2;
                }
                else if (gPlayer1Controller->rawStickY <= -8) {
                    play_sound(SOUND_CUSTOM0_P_SELECTOR, gGlobalSoundSource);
                    gSelectedSkillIndex--;
                    if (gSelectedSkillIndex == -1) {
                        gSelectedSkillIndex = 1;
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
    case PERSONA_ACT_SELECT_SKILL_TARGET:
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
            o->oAction = PERSONA_ACT_SELECT_SKILL;
            play_sound(SOUND_CUSTOM0_P_CANCEL, gGlobalSoundSource);
            gPersonaMenuFlags &= ~(PERSONA_MENU_FLAGS_ATTACK_TEXT);
        }
        else if (gPlayer1Controller->buttonPressed & A_BUTTON) {
            o->oAction = PERSONA_ACT_USING_SKILL;

            gLakituState.goalPos[0] = gMarioState->pos[0] - 200;
            gLakituState.goalPos[1] = 200;
            gLakituState.goalPos[2] = gMarioState->pos[2] - 200;

            gLakituState.goalFocus[0] = gMarioState->pos[0];
            gLakituState.goalFocus[1] = 100;
            gLakituState.goalFocus[2] = gMarioState->pos[2];

            gPersonaMenuFlags &= ~(PERSONA_MENU_FLAGS_SKILL_TEXT);
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
    case PERSONA_ACT_USING_SKILL:
    if (o->oSubAction == 0) {
    Vec3f marioFront = {gMarioState->pos[0] - 300, 300, gMarioState->pos[2] - 300};
            approach_vec3f_asymptotic(gLakituState.goalPos, marioFront, 0.05f, 0.05f, 0.05f);
            approach_vec3f_asymptotic(gLakituState.goalFocus, gMarioState->pos, 0.05f, 0.05f, 0.05f);
            gPersonaMenuFlags |= PERSONA_MENU_FLAGS_USING_SKILL_BATTLE_TEXT;

            if (o->oTimer == 60) {
                o->oSubAction++;
                o->oTimer = 0;
                gPersonaMenuFlags &= ~(PERSONA_MENU_FLAGS_USING_SKILL_BATTLE_TEXT);
                select_enemy(selectedEnemy);
                selectedEnemy = cur_obj_find_object_with_bparam_2nd_byte(bhvCowardlyMaya, gSelectedEnemy);
                spawn_object_relative(gSelectedSkillIndex, 200, 30, 200, selectedEnemy, MODEL_JUMPMAN, bhvJumpman);
            }
    }
    else {
        
        select_enemy(selectedEnemy);
        selectedEnemy = cur_obj_find_object_with_bparam_2nd_byte(bhvCowardlyMaya, gSelectedEnemy);
        gLakituState.goalPos[1] = 400;
        gLakituState.goalFocus[0] = selectedEnemy->oPosX;
        gLakituState.goalFocus[2] = selectedEnemy->oPosZ;
        if (o->oTimer == 30 && gSelectedSkillIndex == 1) {
            selectedEnemy->oAction = 3;
            for (int i = 0; i < 10; i++) {
                spawn_object_relative(0, 0, i * 5, 0, selectedEnemy, MODEL_RED_FLAME, bhvAgiParticle);
            }
        }

        if (o->oTimer == 45 && gSelectedSkillIndex == 0) {
            selectedEnemy->oAction = 3;
            
        }

        if (o->oTimer == 90) {
            obj_mark_for_deletion(selectedEnemy);
            gEnemyCount--;
            if (gEnemyCount == 0) {
                o->oAction = PERSONA_ACT_VICTORY;
            }
            else {
                o->oAction = PERSONA_ACT_ENEMY_TURNS;
            }
            gSelectedEnemy = 0;
        }
    }
    break;
    case PERSONA_ACT_ENEMY_TURNS:
        switch (o->oSubAction) {
            case 0:
                gPersonaMenuFlags |= PERSONA_MENU_FLAGS_STRIKE_ATTACK_TEXT;
                gLakituState.goalPos[0] = gMarioState->pos[0] + 130;
                gLakituState.goalPos[1] = 200;
                gLakituState.goalPos[2] = gMarioState->pos[2] - 500;
                gLakituState.goalFocus[0] = gMarioState->pos[0];
                gLakituState.goalFocus[1] = gMarioState->pos[1];
                gLakituState.goalFocus[2] = gMarioState->pos[2];
                select_enemy(selectedEnemy);
                selectedEnemy = cur_obj_find_object_with_bparam_2nd_byte(bhvCowardlyMaya, gSelectedEnemy);
                selectedEnemy->oPosX = gMarioState->pos[0] - 400;
                selectedEnemy->oPosZ = gMarioState->pos[2] - 400;
                selectedEnemy->oAction = 2;
                o->oSubAction++;

            break;
            case 1:
                selectedEnemy = cur_obj_find_object_with_bparam_2nd_byte(bhvCowardlyMaya, gSelectedEnemy);
                Vec3f enemyCameraPos = {gMarioState->pos[0] + 180, 342.0f, gMarioState->pos[2] - 530};
                Vec3f enemyCameraFocus = {selectedEnemy->oPosX, 42.0f, selectedEnemy->oPosZ};
                approach_vec3f_asymptotic(gLakituState.goalPos, enemyCameraPos, 0.05f, 0.05f, 0.05f);
                approach_vec3f_asymptotic(gLakituState.goalFocus, enemyCameraFocus, 0.05f, 0.05f, 0.05f);

                if (o->oTimer < 20) {
                    selectedEnemy->oPosX += 10;
                    selectedEnemy->oPosZ += 10;
                    animate_mario_idle();
                }
                if (o->oTimer == 28) {
                    set_mario_animation(gMarioState, MARIO_ANIM_BACKWARD_KB);
                    gMarioState->health -= 256;
                    gPersonaMenuFlags &= ~(PERSONA_MENU_FLAGS_STRIKE_ATTACK_TEXT);
                }
                if (o->oTimer == 60) {
                    selectedEnemy->oPosX = selectedEnemy->oHomeX;
                    selectedEnemy->oPosZ = selectedEnemy->oHomeZ;
                    selectedEnemy->oAction = 1;
                    gSelectedEnemy++;
                    o->oTimer = 0;
                    o->oSubAction = 0;
                    gNumEnemyTurns++;
                    if (gNumEnemyTurns == gEnemyCount) {
                        gSelectedEnemy = 0;
                        gNumEnemyTurns = 0;
                        gPersonaMenuFlags |= PERSONA_MENU_FLAGS_MAIN_TEXT;
                        o->oAction = PERSONA_ACT_MARIO_TURN;
                    }
                }
            break;
        }
    break;
    case PERSONA_ACT_VICTORY:
        gLakituState.goalPos[0] = gMarioState->pos[0] - 200;
            gLakituState.goalPos[1] = 200;
            gLakituState.goalPos[2] = gMarioState->pos[2] - 200;

            gLakituState.goalFocus[0] = gMarioState->pos[0];
            gLakituState.goalFocus[1] = 100;
            gLakituState.goalFocus[2] = gMarioState->pos[2];

            gPersonaMenuFlags &= ~(PERSONA_MENU_FLAGS_SKILL_TEXT);
            gPersonaMenuFlags &= ~(PERSONA_MENU_FLAGS_ATTACK_TEXT);
            gPersonaMenuFlags &= ~(PERSONA_MENU_FLAGS_STRIKE_ATTACK_TEXT);

            if (o->oTimer == 0) {
                set_mario_animation(gMarioState, MARIO_ANIM_STAR_DANCE);
            }

            if (o->oTimer == 90) {
                initiate_warp(LEVEL_RR, 1, 0x0A, 0);
            }
    break;
   }
}

