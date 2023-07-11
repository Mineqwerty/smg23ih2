// fazana_car.inc.cs

#define TURN_RATIO_CONSTANT 0.01f
#define TURN_RATIO_AERIAL_CONSTANT 0.875f
#define TURN_RATIO_AERIAL_CONTROL_CONSTANT 0.125f
#define ROTATION_CONSTANT 0x100
#define FORWARD_VELOCITY_CAP 96.0f

#define MINIMUM_PITCH_IDLE 0.35f
#define CUTOFF_PITCH 0.45f
#define MINIMUM_PITCH_DRIVE 0.89f
#define MAXIMUM_PITCH 3.35f

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

void bhv_car_orange_number_init(void) {
    cur_obj_scale(0.75f);
    o->oAnimState = o->oBehParams2ndByte;
    o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
}

void bhv_car_orange_number_loop(void) {
    vec3f_copy(&o->oPosVec, &o->parentObj->oPosVec);
    o->oPosY += 320;
}

void bhv_fazana_car_init(void) {
    o->oGravity = 1.25f;
    o->oFriction = 0.97f;
    o->oBuoyancy = 0.5f;
    o->oBounciness = 0.35f;
    obj_set_hitbox(o, &sFazanaCarHitbox);
    cur_obj_become_tangible();

    o->oFazanaCarBIndicator = spawn_object_relative(0x000B, 0, 0, 0, o, MODEL_NUMBER, bhvCarOrangeNumber);
}

static void fazana_car_set_forward_velocity_and_turn_wheels(void) {
    if (gPlayer1Controller->stickY <= -2.0f || gPlayer1Controller->stickY >= 2.0f) {
        f32 stickCapY = gPlayer1Controller->stickY / 52.0f;
        stickCapY = CLAMP(stickCapY, -1.0f, 1.0f);
        f32 target = stickCapY * FORWARD_VELOCITY_CAP;
        o->oForwardVel = lerpf(o->oForwardVel, target, 0.02f);
        o->oFriction = 0.995f;
    } else {
        o->oFriction = 0.98f;

        if (ABS(o->oForwardVel) < 1.0f) {
            o->oForwardVel = 0.0f; // Fix slow random weird rotation kinda
        }
    }

    if (o->oForwardVel > FORWARD_VELOCITY_CAP * 1.5f) {
        o->oForwardVel = FORWARD_VELOCITY_CAP * 1.5f;
    } else if (o->oForwardVel < -FORWARD_VELOCITY_CAP * 1.5f) {
        o->oForwardVel = -FORWARD_VELOCITY_CAP * 1.5f;
    }
    
    o->oFazanaCarWheelRot = (s32) (o->oFazanaCarWheelRot + (ROTATION_CONSTANT * o->oForwardVel)) & 0xFFFF;
    
    if (gPlayer1Controller->stickX <= -2.0f || gPlayer1Controller->stickX >= 2.0f) {
        f32 stickCapX = gPlayer1Controller->stickX / 52.0f;
        stickCapX = CLAMP(stickCapX, -1.0f, 1.0f);
        o->oFazanaCarWheelTurn = -0x780 * stickCapX;
    } else {
        o->oFazanaCarWheelTurn = 0;
    }

    o->oFazanaCarAerialRotation = (s16) ((o->oFazanaCarAerialRotation * TURN_RATIO_AERIAL_CONSTANT) + (o->oFazanaCarWheelTurn * TURN_RATIO_AERIAL_CONTROL_CONSTANT));
    o->oFazanaCarAerialRotation = o->oFazanaCarWheelTurn;
    if (!o->oFazanaCarGroundedLast) {
        o->oFazanaCarAerialRotation *= 0.3f;
    }

    o->oFaceAngleYaw = (s16) (o->oFaceAngleYaw + (s32) (o->oFazanaCarAerialRotation * o->oForwardVel * TURN_RATIO_CONSTANT));
    o->oMoveAngleYaw = o->oFaceAngleYaw;
}

void fazana_car_act_move(void) {
    s16 collisionFlags = object_step_without_floor_orient();

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
        o->oFazanaCarGroundedLast = TRUE;
        if (o->oVelY > 0.0f) {
            o->oVelY *= 2.0f * o->oBounciness;
        }

        if (o->oFloor != NULL) {
            o->oFazanaCarLastFloor = o->oFloor;
        }
    } else {
        o->oFazanaCarGroundedLast = FALSE;
    }

    if (o->oFazanaCarLastFloor) {
        struct Surface *floor = o->oFazanaCarLastFloor;
        obj_orient_graph(o, floor->normal.x, floor->normal.y, floor->normal.z);
    }

    f32 movementPercentage = ABS(o->oForwardVel) / FORWARD_VELOCITY_CAP;
    f32 lerpDest = movementPercentage * MAXIMUM_PITCH;
    f32 lerpStart = o->oFazanaCarSoundPitch;
    if (lerpStart < MINIMUM_PITCH_IDLE) {
        lerpStart = MINIMUM_PITCH_IDLE;
    }

    switch(o->oAction) {
        case FAZANA_CAR_ACT_DRIVE:
            lerpDest += (1.0f - movementPercentage) * MINIMUM_PITCH_DRIVE;
            break;
        case FAZANA_CAR_ACT_IDLE:
        default:
            lerpDest += (1.0f - movementPercentage) * MINIMUM_PITCH_IDLE;
            break;
    }

    o->oFazanaCarSoundPitch = lerpf(lerpStart, lerpDest, 0.2f);

    if (o->oFazanaCarSoundPitch < MINIMUM_PITCH_IDLE) {
        o->oFazanaCarSoundPitch = MINIMUM_PITCH_IDLE;
    }

    if (o->oFazanaCarSoundPitch >= CUTOFF_PITCH) {
        cur_obj_play_sound_2(SOUND_ENV_CAR_MOTOR);
    }
}

void fazana_car_idle_loop(void) {
    load_object_collision_model();

    gMarioState->fazanaCar = NULL;

    o->oFriction = 0.97f;
    if (ABS(o->oForwardVel) < 1.0f) {
        o->oForwardVel = 0.0f; // Fix random weird rotation caused by even the slightest movement
    }
    o->oFazanaCarWheelRot = (s32) (o->oFazanaCarWheelRot + (ROTATION_CONSTANT * o->oForwardVel)) & 0xFFFF;
    o->oFazanaCarWheelTurn = 0;

    if (o->oDistanceToMario < 300.0f) {
        o->oFazanaCarBIndicator->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;

        if (gPlayer1Controller->buttonPressed & B_BUTTON) {
            o->oFazanaCarBIndicator->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            gMarioState->fazanaCar = o;
            set_mario_action(gMarioState, ACT_FAZANA_CAR, 0);
            o->oAction = FAZANA_CAR_ACT_DRIVE;
        }
    } else {
        o->oFazanaCarBIndicator->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    }
}

void fazana_car_drive_loop(void) {
    fazana_car_set_forward_velocity_and_turn_wheels();

    if (gPlayer1Controller->buttonPressed & Z_TRIG || gMarioState->action != ACT_FAZANA_CAR) {
        gMarioState->fazanaCar = NULL;
        o->oAction = FAZANA_CAR_ACT_IDLE;
    }
}

void bhv_fazana_car_loop(void) {
    switch(o->oAction) {
        case FAZANA_CAR_ACT_DRIVE:
            fazana_car_drive_loop();
            break;
        case FAZANA_CAR_ACT_IDLE:
        default:
            fazana_car_idle_loop();
            break;
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
