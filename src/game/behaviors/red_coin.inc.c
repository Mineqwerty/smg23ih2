
/**
 * This file contains the initialization and behavior for red coins.
 * Behavior controls audio and the orange number spawned, as well as interacting with
 * the course's red coin star.
 */

/**
 * Red coin's hitbox details.
 */
static struct ObjectHitbox sRedCoinHitbox = {
    /* interactType:      */ INTERACT_COIN,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 64,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void red_coin_move(void) {
    cur_obj_update_floor_and_walls();
    cur_obj_if_hit_wall_bounce_away();
    cur_obj_move_standard(-62);

    struct Surface *floor = o->oFloor;

    if (floor != NULL) {
        if (o->oMoveFlags & OBJ_MOVE_ON_GROUND) {
            o->oAction = BOUNCING_COIN_ACT_BOUNCING;
        }
        if (o->oAction == BOUNCING_COIN_ACT_BOUNCING) {
            if (floor->normal.y < 0.9f) {
                s16 targetYaw = SURFACE_YAW(floor);
                cur_obj_rotate_yaw_toward(targetYaw, 0x400);
            }
        }
    }

    if (o->oTimer >= 20) {
        cur_obj_become_tangible();
    }

    if (o->oMoveFlags & OBJ_MOVE_BOUNCE) {
        if (o->oCoinBounceTimer < 5) {
            cur_obj_play_sound_2(SOUND_GENERAL_COIN_DROP);
        }
        o->oCoinBounceTimer++;
    }
}

/**
 * Red coin initialization function. Sets the coin's hitbox and parent object.
 */
void bhv_red_coin_init(void) {
    // Set the red coins to have a parent of the closest red coin star.
    if (gCurrLevelNum == SMG23IH2_LEVEL_4) {
        struct Object *hiddenRedCoinStar = find_first_object_with_behavior_and_bparams(bhvHiddenRedCoinStar, BPARAM4, 0xFF);
        if (hiddenRedCoinStar != NULL) {
            o->parentObj = hiddenRedCoinStar;
        } else if ((hiddenRedCoinStar = find_first_object_with_behavior_and_bparams(bhvBowserCourseRedCoinStar, BPARAM4, 0xFF)) != NULL) {
            o->parentObj = hiddenRedCoinStar;
        } else {
            o->parentObj = NULL;
        }
    } else {
        struct Object *hiddenRedCoinStar = cur_obj_nearest_object_with_behavior(bhvHiddenRedCoinStar);
        if (hiddenRedCoinStar != NULL) {
            o->parentObj = hiddenRedCoinStar;
        } else if ((hiddenRedCoinStar = cur_obj_nearest_object_with_behavior(bhvBowserCourseRedCoinStar)) != NULL) {
            o->parentObj = hiddenRedCoinStar;
        } else {
            o->parentObj = NULL;
        }
    }

    obj_set_hitbox(o, &sRedCoinHitbox);

    if (o->parentObj != NULL && gCurrLevelNum == SMG23IH2_LEVEL_1) {
        o->parentObj->oHiddenStarTriggerCounter = (s32) save_file_get_red_coin_flags_count();
        if (save_file_get_red_coin_flags() & (1U << o->oBehParams2ndByte)) {
            o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
        }
    }
}

/**
 * Bouncey red coin initialization function. Sets the coin's hitbox and parent object.
 */
void bhv_bouncey_red_coin_init(void) {
    bhv_red_coin_init();

    
    o->oVelY = random_float() * 45.0f + 20.0f;
    o->oForwardVel = random_float() * 30.0f + 5.0f;
    o->oMoveAngleYaw = random_u16();

    o->oRedCoinBounce = TRUE;

    cur_obj_set_behavior(bhvRedCoin);
    cur_obj_become_intangible();
}

/**
 * Main behavior for red coins. Primarily controls coin collection noise and spawning
 * the orange number counter.
 */
void bhv_red_coin_loop(void) {
    // If Mario interacted with the object...
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        // ...and there is a red coin star in the level...
        if (o->parentObj != NULL) {
            // ...increment the star's counter.
            o->parentObj->oHiddenStarTriggerCounter++;

            if (gCurrLevelNum == SMG23IH2_LEVEL_1) {
                save_file_set_red_coin_flags(1U << o->oBehParams2ndByte);
                o->parentObj->oHiddenStarTriggerCounter = (s32) save_file_get_red_coin_flags_count();
            }

            // Spawn the orange number counter, as long as it isn't the last coin.
            if (o->parentObj->oHiddenStarTriggerCounter != o->parentObj->oHiddenStarTriggerTotal) {
                // Cap visible count to 99
                if (o->parentObj->oHiddenStarTriggerCounter > 99) {
                    spawn_orange_number(9, 28, 0, 0);
                    spawn_orange_number(9, -28, 0, 0);
                }
                else if (o->parentObj->oHiddenStarTriggerCounter >= 10) {
                    spawn_orange_number(o->parentObj->oHiddenStarTriggerCounter % 10, 28, 0, 0);
                    spawn_orange_number(o->parentObj->oHiddenStarTriggerCounter / 10, -28, 0, 0);
                }
                else {
                    spawn_orange_number(o->parentObj->oHiddenStarTriggerCounter, 0, 0, 0);
                }
            }

#ifdef JP_RED_COIN_SOUND
            // For JP version, play an identical sound for all coins.
            create_sound_spawner(SOUND_GENERAL_RED_COIN);
#else
            if (gCurrLevelNum == SMG23IH2_LEVEL_4) {
                if (o->parentObj->oHiddenStarTriggerTotal - o->parentObj->oHiddenStarTriggerCounter > 11) {
                    // Play the first red coin sound until it gets to the final 8
                    play_sound(SOUND_MENU_COLLECT_RED_COIN2_0, gGlobalSoundSource);
                }
                else {
                    // On all versions but the JP version, each coin collected plays a higher noise.
                    play_sound(SOUND_MENU_COLLECT_RED_COIN2_0
                            + (((u8) 11 - (o->parentObj->oHiddenStarTriggerTotal - o->parentObj->oHiddenStarTriggerCounter)) << 16),
                            gGlobalSoundSource);
                }

                s32 newBparam2 = -1;
                switch (o->oBehParams2ndByte) {
                    case 0:
                        newBparam2 = BKTN_DIA_COIN_00;
                        break;
                    case 2:
                        newBparam2 = BKTN_DIA_COIN_02;
                        break;
                    case 3:
                        newBparam2 = BKTN_DIA_COIN_03;
                        break;
                    case 6:
                        newBparam2 = BKTN_DIA_COIN_06;
                        break;
                    case 7:
                        newBparam2 = BKTN_DIA_COIN_07;
                        break;
                    case 10:
                        newBparam2 = BKTN_DIA_COIN_10;
                        break;
                    case 12:
                        newBparam2 = BKTN_DIA_COIN_12_NORMAL;
                        break;
                    case 13:
                        newBparam2 = BKTN_DIA_COIN_13;
                        break;
                    case 14:
                    case 15:
                    case 16:
                    case 17:
                    case 18:
                    case 19:
                        newBparam2 = BKTN_DIA_COIN_JACKPOT;
                        break;
                    case 23:
                        newBparam2 = BKTN_DIA_COIN_23;
                        break;
                    default:
                        break;
                }

                if (newBparam2 > 0) {
                    struct Object *obj = spawn_object(o, MODEL_BLOCKINGTON_MINI, bhvBlockingtonMini);
                    if (obj) {
                        obj->oBehParams = (((u32) newBparam2 & 0xFF) << 16) | 0x00;
                    }
                }
            } else {
                if (o->parentObj->oHiddenStarTriggerTotal - o->parentObj->oHiddenStarTriggerCounter > 7) {
                    // Play the first red coin sound until it gets to the final 8
                    play_sound(SOUND_MENU_COLLECT_RED_COIN, gGlobalSoundSource);
                }
                else {
                    // On all versions but the JP version, each coin collected plays a higher noise.
                    play_sound(SOUND_MENU_COLLECT_RED_COIN
                            + (((u8) 7 - (o->parentObj->oHiddenStarTriggerTotal - o->parentObj->oHiddenStarTriggerCounter)) << 16),
                            gGlobalSoundSource);
                }
            }
#endif
        }

        coin_collected();
        // Despawn the coin.
        o->oInteractStatus = INT_STATUS_NONE;
    } else if (o->oRedCoinBounce) {
        red_coin_move();
    }
}
