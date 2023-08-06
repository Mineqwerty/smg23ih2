// fazana_car.inc.c

#define TURN_RATIO_CONSTANT 0.0325f
#define SLOW_TURN_MULT 2.0f
#define TURN_RATIO_AERIAL_CONSTANT 0.9f
#define TURN_RATIO_AERIAL_CONTROL_CONSTANT 0.1f
#define LAUNCH_CONST 0.667f
#define ROTATION_CONSTANT 0x120
#define FORWARD_VELOCITY_CAP 144.0f

#define MINIMUM_PITCH_IDLE 0.35f
#define CUTOFF_PITCH 0.45f
#define MINIMUM_PITCH_DRIVE 0.89f
#define MAXIMUM_PITCH 3.35f

#define DOOR_OPENING_CUTSCENE_DUR 68

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
    o->oGravity = 2.0f;
    o->oFriction = 0.97f;
    o->oBuoyancy = 3.5f;
    o->oBounciness = 0.225f;
    obj_set_hitbox(o, &sFazanaCarHitbox);
    cur_obj_become_tangible();

    o->oFazanaCarLeftDoor = -1;
    o->oFazanaCarRightDoor = -1;

    o->oFazanaCarBIndicator = spawn_object_relative(0x000B, 0, 0, 0, o, MODEL_NUMBER, bhvCarOrangeNumber);
    o->oFazanaCarLastGroundedY = o->oPosY;

    if (BPARAM4 == 1) {
        o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
    } else {
        if (find_first_object_with_behavior_and_bparams(bhvCQDoor, 0, 0)) {
            cur_obj_hide();
        }
    }
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

    s32 rotation = o->oFazanaCarAerialRotation * sqrtf(ABS(o->oForwardVel) * (1.0f / SLOW_TURN_MULT)) * SLOW_TURN_MULT * TURN_RATIO_CONSTANT;
    if (o->oForwardVel <= 0.0f) {
        rotation = -rotation;
    }

    o->oFaceAngleYaw = (s16) (o->oFaceAngleYaw + rotation);
    o->oMoveAngleYaw = o->oFaceAngleYaw;
}

void fazana_car_act_move(void) {
    f32 lastY = o->oPosY;

    s16 collisionFlags = object_step_without_floor_orient();

    if (o->oFloor == NULL) {
        o->oFazanaCarNoFloorTime++;
    } else {
        o->oFazanaCarNoFloorTime = 0;
    }

    if (o->oFazanaCarNoFloorTime == 120) {
        if (!find_first_object_with_behavior_and_bparams(bhvCQGate, 0, 0)) {
            struct Object *obj = spawn_object(o, MODEL_BLOCKINGTON_MINI, bhvBlockingtonMini);
            if (obj) {
                obj->oBehParams = ((BKTN_DIA_OOB) << 16) | 1; // Higher priority
            }
        }
    }

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
        if (o->oVelY > 0.0f) {
            o->oVelY *= 2.0f * o->oBounciness;
        } else {
            o->oFazanaCarGroundedLast = TRUE;

            if (o->oFloor != NULL && ((lastY - o->oFazanaCarLastGroundedY) - (o->oPosY - lastY) > 32.0f)) {
                o->oFazanaCarGroundedLast = FALSE;
                o->oVelY = (lastY - o->oFazanaCarLastGroundedY) * LAUNCH_CONST;
                if (o->oPosY < lastY + o->oVelY) {
                    o->oPosY = lastY + o->oVelY;
                }
            } else {
                o->oFazanaCarLastGroundedY = lastY;
            }
        }

        if (o->oFloor != NULL) {
            o->oFazanaCarLastFloor = o->oFloor;
        }
    } else {
        if (o->oFazanaCarGroundedLast) {
            o->oVelY = (lastY - o->oFazanaCarLastGroundedY) * LAUNCH_CONST;
            if (o->oPosY < lastY + o->oVelY) {
                o->oPosY = lastY + o->oVelY;
            }
        }
        o->oFazanaCarGroundedLast = FALSE;
        o->oFazanaCarLastGroundedY = o->oPosY;
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

    if (
      o->oDistanceToMario < 300.0f &&
      !(gTimeStopState & TIME_STOP_ENABLED) &&
      mario_ready_to_speak() &&
      gMarioState->action != ACT_WAITING_FOR_DIALOG
    ) {
        o->oFazanaCarBIndicator->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;

        if (gPlayer1Controller->buttonPressed & B_BUTTON) {
            u16 angleToMario = (u16) (obj_angle_to_object(o, gMarioObject) - o->oFaceAngleYaw);

            if (angleToMario >= 0x8000) {
                o->oFazanaCarRightDoor = 0;
            } else {
                o->oFazanaCarLeftDoor = 0;
            }

            o->oFazanaCarBIndicator->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            set_mario_action(gMarioState, ACT_WAITING_FOR_DIALOG, 0);
        }
    } else {
        o->oFazanaCarBIndicator->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    }
}

void fazana_car_cutscene_loop(void) {
    if (o->oTimer == 0) {
        gMarioState->fazanaCar = NULL;
        o->oFazanaCarWheelTurn = 0;
        o->oFazanaCarWheelRot = 0;
        o->oFazanaCarRightDoor = -1;
        o->oFazanaCarLeftDoor = -1;
        o->oFazanaCarBIndicator->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
        o->oFaceAngleYaw = 0xC000;
        o->oMoveAngleYaw = o->oFaceAngleYaw;
        
        object_step_without_floor_orient();
    }
}

void fazana_car_drive_loop(void) {
    fazana_car_set_forward_velocity_and_turn_wheels();

#ifdef ENABLE_DEBUG_FREE_MOVE
    if (gPlayer1Controller->buttonPressed & Z_TRIG || gMarioState->action != ACT_FAZANA_CAR) {
#else
    if (gMarioState->action != ACT_FAZANA_CAR) {
#endif
        gMarioState->fazanaCar = NULL;
        o->oAction = FAZANA_CAR_ACT_IDLE;
    }
}

static void bhv_fazana_car_update_door_rot(s32 *field) {
    if (*field < 0) {
        return;
    } else if (*field == 0) {
        cur_obj_play_sound_2(SOUND_OBJ_CAR_DOOR_OPEN);
    }

    (*field)++;

    if (*field == DOOR_OPENING_CUTSCENE_DUR * 4 / 10) {
        if (o->oAction == FAZANA_CAR_ACT_IDLE) {
            o->oFazanaCarBIndicator->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            gMarioState->fazanaCar = o;
            set_mario_action(gMarioState, ACT_FAZANA_CAR, 0);
            o->oAction = FAZANA_CAR_ACT_DRIVE;
            if (gMadeByBlakeoramoTimer < 0) {
                gMadeByBlakeoramoTimer = 0;
            }
            set_cam_angle(CAM_ANGLE_MARIO);
            gCameraMovementFlags |= CAM_MOVE_ZOOMED_OUT;
            sCameraSoundFlags = 0;
        } else if (o->oAction == FAZANA_CAR_ACT_CUTSCENE) {
            play_sound(SOUND_MARIO_YAHOO_UNPITCHED, gMarioObject->header.gfx.cameraToObject);
            struct Object *obj = spawn_object(gMarioObject, MODEL_PNG_MARIO, bhvStaticPNG);
            if (!obj) {
                error("Mario no spawn!");
            }

            obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
            obj->oBehParams = (1) << 16;
            obj->oBehParams2ndByte = GET_BPARAM2(obj->oBehParams);
        }
    } else if (*field >= DOOR_OPENING_CUTSCENE_DUR) {
        cur_obj_play_sound_2(SOUND_OBJ_CAR_DOOR_SHUT);
        *field = -1;
    }
}

void bhv_fazana_car_loop(void) {
    switch(o->oAction) {
        case FAZANA_CAR_ACT_DRIVE:
            fazana_car_drive_loop();
            fazana_car_act_move();
            break;
        case FAZANA_CAR_ACT_CUTSCENE:
            fazana_car_cutscene_loop();
            break;
        case FAZANA_CAR_ACT_IDLE:
        default:
            fazana_car_idle_loop();
            fazana_car_act_move();
            break;
    }

    bhv_fazana_car_update_door_rot(&o->oFazanaCarLeftDoor);
    bhv_fazana_car_update_door_rot(&o->oFazanaCarRightDoor);

    o->oInteractStatus = INT_STATUS_NONE;
}

static s16 bhv_fazana_car_calculate_door_rot(f32 field) {
    f32 val;

    if (field < 0) {
        return 0;
    }

    if (field < (f32) DOOR_OPENING_CUTSCENE_DUR / 3.0f) {
        val = field / ((f32) DOOR_OPENING_CUTSCENE_DUR / 3.0f);
    } else if (field > ((f32) DOOR_OPENING_CUTSCENE_DUR * 2.0f) / 3.0f) {
        val = (((f32) DOOR_OPENING_CUTSCENE_DUR / 3.0f) - (field - (((f32) DOOR_OPENING_CUTSCENE_DUR * 2.0f) / 3.0f))) / ((f32) DOOR_OPENING_CUTSCENE_DUR / 3.0f);
    } else {
        val = 1.0f;
    }

    return (s16) (val * 0x3C00);
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
        s16 rot = bhv_fazana_car_calculate_door_rot(obj->oFazanaCarLeftDoor);

        rotNode->rotation[0] = 0;
        rotNode->rotation[1] = -rot; // Negative door angle
        rotNode->rotation[2] = 0;
    }

    return NULL;
}

Gfx *car_right_door(s32 callContext, struct GraphNode *node, UNUSED Mat4 *c) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeTranslationRotation *rotNode = (struct GraphNodeTranslationRotation *) node->next;
        s16 rot = bhv_fazana_car_calculate_door_rot(obj->oFazanaCarRightDoor);

        rotNode->rotation[0] = 0;
        rotNode->rotation[1] = rot; // Positive door angle
        rotNode->rotation[2] = 0;
    }

    return NULL;
}
