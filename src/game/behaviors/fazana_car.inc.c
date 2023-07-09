// fazana_car.inc.cs

struct ObjectHitbox sFazanaCarHitbox = {
    /* interactType:      */ INTERACT_GRABBABLE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 0,
    /* height:            */ 0,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_fazana_car_init(void) {
    o->oGravity = 2.5f;
    o->oFriction = 0.99f;
    o->oBuoyancy = 1.4f;
    cur_obj_scale(16.0f);
    // obj_set_hitbox(o, &sFazanaCarHitbox);
    o->oAnimState = BREAKABLE_BOX_ANIM_STATE_CORK_BOX;
    o->activeFlags |= ACTIVE_FLAG_DESTRUCTIVE_OBJ_DONT_DESTROY;
    cur_obj_become_tangible();
}

void fazana_car_spawn_dust(void) {
    return;

    // struct Object *smokeObj = spawn_object(o, MODEL_SMOKE, bhvSmoke);
    // smokeObj->oPosX += (s32)(random_float() * 80.0f) - 40;
    // smokeObj->oPosZ += (s32)(random_float() * 80.0f) - 40;
}

void fazana_car_act_move(void) {
    s16 collisionFlags = object_step();

    obj_attack_collided_from_other_object(o);

    if (collisionFlags == OBJ_COL_FLAG_GROUNDED) {
        cur_obj_play_sound_2(SOUND_GENERAL_SMALL_BOX_LANDING);
    }

    if (collisionFlags & OBJ_COL_FLAG_GROUNDED) {
        if (o->oForwardVel > 20.0f) {
            cur_obj_play_sound_2(SOUND_ENV_SLIDING);
            fazana_car_spawn_dust();
        }
    }

    if (collisionFlags & OBJ_COL_FLAG_HIT_WALL) {
        spawn_mist_particles();
        spawn_triangle_break_particles(20, MODEL_DIRT_ANIMATION, 0.7f, 3);
        obj_spawn_yellow_coins(o, 3);
        create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }

    obj_check_floor_death(collisionFlags, sObjFloor);
}

void fazana_car_released_loop(void) {
    o->oFazanaCarFramesSinceReleased++;

    // Begin flashing
    if (o->oFazanaCarFramesSinceReleased > 810) {
        COND_BIT((o->oFazanaCarFramesSinceReleased & 0x1), o->header.gfx.node.flags, GRAPH_RENDER_INVISIBLE);
    }

    // Despawn, and create a fazana car respawner
    if (o->oFazanaCarFramesSinceReleased > 900) {
        create_respawner(MODEL_CUSTOM_FAZANA_CAR, bhvBreakableBoxSmall, 3000);
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }
}

void fazana_car_idle_loop(void) {
    switch (o->oAction) {
        case FAZANA_CAR_ACT_MOVE:
            fazana_car_act_move();
            break;

        case OBJ_ACT_LAVA_DEATH:
            obj_lava_death();
            break;

        case OBJ_ACT_DEATH_PLANE_DEATH:
            o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
            create_respawner(MODEL_CUSTOM_FAZANA_CAR, bhvBreakableBoxSmall, 3000);
            break;
    }

    if (o->oFazanaCarReleased == TRUE) {
        fazana_car_released_loop();
    }
}

void fazana_car_get_dropped(void) {
    cur_obj_become_tangible();
    cur_obj_enable_rendering();
    cur_obj_get_dropped();
    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    o->oHeldState = HELD_FREE;
    o->oFazanaCarReleased = TRUE;
    o->oFazanaCarFramesSinceReleased = 0;
}

void fazana_car_get_thrown(void) {
    cur_obj_become_tangible();

    cur_obj_enable_rendering();
    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    o->oHeldState = HELD_FREE;
    o->oFlags &= ~OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW;
    o->oForwardVel = 40.0f;
    o->oVelY = 20.0f;
    o->oFazanaCarReleased = TRUE;
    o->oFazanaCarFramesSinceReleased = 0;
    o->activeFlags &= ~ACTIVE_FLAG_DESTRUCTIVE_OBJ_DONT_DESTROY;
}

void bhv_fazana_car_loop(void) {
    switch (o->oHeldState) {
        case HELD_FREE:
            fazana_car_idle_loop();
            break;

        case HELD_HELD:
            cur_obj_disable_rendering();
            cur_obj_become_intangible();
            break;

        case HELD_THROWN:
            fazana_car_get_thrown();
            break;

        case HELD_DROPPED:
            fazana_car_get_dropped();
            break;
    }
}
