void bhv_gaslight_block_init(void) {
    f32 dist;
    o->parentObj = obj_find_nearest_object_with_behavior(o, bhvGaslightManager, &dist);
}

void bhv_gaslight_block_loop(void) {
    if (o->parentObj->oF4 != o->oBehParams2ndByte) {
        load_object_collision_model();
    }
}

void bhv_gaslight_manager_init(void) {
    o->oF4 = random_u16() % 5;
}

void bhv_gaslight_manager_loop(void) {
    if (gMarioState->action == ACT_CHECKPOINT_WARP) {
        o->oF4 = random_u16() % 5;
    }
}
