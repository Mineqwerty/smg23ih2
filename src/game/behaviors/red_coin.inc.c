
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
    struct Object *hiddenRedCoinStar = cur_obj_nearest_object_with_behavior(bhvHiddenRedCoinStar);
    if (hiddenRedCoinStar != NULL) {
        o->parentObj = hiddenRedCoinStar;
    } else if ((hiddenRedCoinStar = cur_obj_nearest_object_with_behavior(bhvBowserCourseRedCoinStar)) != NULL) {
        o->parentObj = hiddenRedCoinStar;
    } else {
        o->parentObj = NULL;
    }

    obj_set_hitbox(o, &sRedCoinHitbox);

    if (o->parentObj != NULL && gCurrLevelNum == LEVEL_CASTLE_GROUNDS) {
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

            if (gCurrLevelNum == LEVEL_CASTLE_GROUNDS) {
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
#endif
        }

        coin_collected();
        // Despawn the coin.
        o->oInteractStatus = INT_STATUS_NONE;
    } else if (o->oRedCoinBounce) {
        red_coin_move();
    }
}
