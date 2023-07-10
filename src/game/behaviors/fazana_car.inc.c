// fazana_car.inc.cs

struct ObjectHitbox sFazanaCarHitbox = {
    /* interactType:      */ INTERACT_NONE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 150,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 150,
    /* hurtboxHeight:     */ 100,
};

void bhv_fazana_car_init(void) {
    o->oGravity = 1.25f;
    o->oFriction = 0.97f;
    o->oBuoyancy = 1.0f;
    obj_set_hitbox(o, &sFazanaCarHitbox);
    cur_obj_become_tangible();
}

void fazana_car_spawn_dust(void) {
    return;

    // struct Object *smokeObj = spawn_object(o, MODEL_SMOKE, bhvSmoke);
    // smokeObj->oPosX += (s32)(random_float() * 80.0f) - 40;
    // smokeObj->oPosZ += (s32)(random_float() * 80.0f) - 40;
}

#define TURN_RATIO_CONSTANT 0.01f
#define ROTATION_CONSTANT 0x100
#define FORWARD_VELOCITY_CAP 96.0f
static void fazana_car_set_forward_velocity_and_turn_wheels(void) {
    if (gPlayer1Controller->stickY <= -2.0f || gPlayer1Controller->stickY >= 2.0f) {
        f32 target = (gPlayer1Controller->stickY / 64.0f) * FORWARD_VELOCITY_CAP;
        o->oForwardVel = lerpf(o->oForwardVel, target, 0.025f);
        o->oFriction = 0.9925f;
    } else {
        o->oFriction = 0.98f;
    }

    if (o->oForwardVel > FORWARD_VELOCITY_CAP * 1.5f) {
        o->oForwardVel = FORWARD_VELOCITY_CAP * 1.5f;
    } else if (o->oForwardVel < -FORWARD_VELOCITY_CAP * 1.5f) {
        o->oForwardVel = -FORWARD_VELOCITY_CAP * 1.5f;
    }
    
    o->oFazanaCarWheelRot = (s32) (o->oFazanaCarWheelRot + (ROTATION_CONSTANT * o->oForwardVel)) & 0xFFFF;
    
    if (gPlayer1Controller->stickX <= -2.0f || gPlayer1Controller->stickX >= 2.0f) {
        o->oFazanaCarWheelTurn = -0x800 * (gPlayer1Controller->stickX / 64.0f);
    } else {
        o->oFazanaCarWheelTurn = 0;
    }

    o->oFaceAngleYaw = (o->oFaceAngleYaw + 0x10000 + (s32) (o->oFazanaCarWheelTurn * o->oForwardVel * TURN_RATIO_CONSTANT)) & 0xFFFF;
    o->oMoveAngleYaw = o->oFaceAngleYaw;
}

extern u32 attack_object(struct Object *obj, s32 interaction);
extern void check_collision_in_list(struct Object *a, struct Object *b, struct Object *c);
extern void print_text_fmt_int(s32 x, s32 y, const char *str, s32 n);
void fazana_car_act_move(void) {
    s16 collisionFlags = object_step();

    s32 collidedObjects = o->numCollidedObjs;
    while (collidedObjects > 0) {
        struct Object *other;

        collidedObjects--;
        other = o->collidedObjs[collidedObjects];

        if (other != gMarioObject) {
            other->oInteractStatus |= INT_STATUS_TOUCHED_MARIO | INT_STATUS_WAS_ATTACKED | INT_STATUS_INTERACTED
                                      | INT_STATUS_TOUCHED_BOB_OMB;
        }
    }

    if (collisionFlags == OBJ_COL_FLAG_GROUNDED) {
        cur_obj_play_sound_2(SOUND_GENERAL_SMALL_BOX_LANDING);
    }

    if (collisionFlags & OBJ_COL_FLAG_GROUNDED) {
        if (ABS(o->oForwardVel) > 20.0f) {
            cur_obj_play_sound_2(SOUND_ENV_SLIDING);
            fazana_car_spawn_dust();
        }
    }

    // if (collisionFlags & OBJ_COL_FLAG_HIT_WALL) {
    //     spawn_mist_particles();
    //     spawn_triangle_break_particles(20, MODEL_DIRT_ANIMATION, 0.7f, 3);
    //     obj_spawn_yellow_coins(o, 3);
    //     create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
    //     o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    // }

    // obj_check_floor_death(collisionFlags, sObjFloor);
}

// void fazana_car_released_loop(void) {
//     o->oFazanaCarFramesSinceReleased++;

//     // Begin flashing
//     if (o->oFazanaCarFramesSinceReleased > 810) {
//         COND_BIT((o->oFazanaCarFramesSinceReleased & 0x1), o->header.gfx.node.flags, GRAPH_RENDER_INVISIBLE);
//     }

//     // Despawn, and create a fazana car respawner
//     if (o->oFazanaCarFramesSinceReleased > 900) {
//         create_respawner(MODEL_CUSTOM_FAZANA_CAR, bhvBreakableBoxSmall, 3000);
//         o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
//     }
// }

// void fazana_car_idle_loop(void) {
//     switch (o->oAction) {
//         case FAZANA_CAR_ACT_MOVE:
//             fazana_car_act_move();
//             break;

//         case OBJ_ACT_LAVA_DEATH:
//             obj_lava_death();
//             break;

//         case OBJ_ACT_DEATH_PLANE_DEATH:
//             o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
//             create_respawner(MODEL_CUSTOM_FAZANA_CAR, bhvBreakableBoxSmall, 3000);
//             break;
//     }

//     if (o->oFazanaCarReleased == TRUE) {
//         fazana_car_released_loop();
//     }
// }

void fazana_car_idle_loop(void) {
    load_object_collision_model();
    gMarioState->fazanaCar = NULL;

    o->oFriction = 0.97f;
    o->oFazanaCarWheelRot = (s32) (o->oFazanaCarWheelRot + (ROTATION_CONSTANT * o->oForwardVel)) & 0xFFFF;
    o->oFazanaCarWheelTurn = 0;

    if (o->oDistanceToMario < 350.0f && gPlayer1Controller->buttonPressed & B_BUTTON) {
        gMarioState->fazanaCar = o;
        set_mario_action(gMarioState, ACT_FAZANA_CAR, 0);
    }
}

void fazana_car_drive_loop(void) {
    fazana_car_set_forward_velocity_and_turn_wheels();

    if (gPlayer1Controller->buttonPressed & Z_TRIG || gMarioState->action != ACT_FAZANA_CAR) {
        gMarioState->fazanaCar = NULL;
    }
}

void bhv_fazana_car_loop(void) {
    if (gMarioState->action == ACT_FAZANA_CAR) {
        fazana_car_drive_loop();
    } else {
        fazana_car_idle_loop();
    }

    fazana_car_act_move();

    o->oInteractStatus = INT_STATUS_NONE;
}

Gfx *car_front_wheels(s32 callContext, struct GraphNode *node, UNUSED Mat4 *c) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeTranslationRotation *rotNode = (struct GraphNodeTranslationRotation *) node->next;

        rotNode->rotation[0] = obj->oFazanaCarWheelRot;
        rotNode->rotation[1] = obj->oFazanaCarWheelTurn;
        rotNode->rotation[2] = 0;

    }
    return NULL;
}

Gfx *car_rear_wheels(s32 callContext, struct GraphNode *node, UNUSED Mat4 *c) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeTranslationRotation *rotNode = (struct GraphNodeTranslationRotation *) node->next;

        rotNode->rotation[0] = obj->oFazanaCarWheelRot;
        rotNode->rotation[1] = 0;
        rotNode->rotation[2] = 0;

    }
    return NULL;
}

Gfx *car_left_door(s32 callContext, struct GraphNode *node, UNUSED Mat4 *c) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeTranslationRotation *rotNode = (struct GraphNodeTranslationRotation *) node->next;

        rotNode->rotation[0] = 0;
        rotNode->rotation[1] = -obj->oFazanaCarLeftDoor; // Negative Door angle
        rotNode->rotation[2] = 0;

    }
    return NULL;
}

Gfx *car_right_door(s32 callContext, struct GraphNode *node, UNUSED Mat4 *c) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeTranslationRotation *rotNode = (struct GraphNodeTranslationRotation *) node->next;

        rotNode->rotation[0] = 0;
        rotNode->rotation[1] = obj->oFazanaCarRightDoor; // Positive door angle
        rotNode->rotation[2] = 0;

    }
    return NULL;
}
