void bhv_whomp_checker_init(void) {
   
}

void bhv_whomp_checker_loop(void) {
    if (o->oTimer > 30) {
        f32 dist;
        struct Object *whomp = obj_find_nearest_object_with_behavior(o, bhvSmallWhomp, &dist);
        if (!whomp) {
            initiate_warp(SMG23IH2_LEVEL_6, 1, 10, 0);
        }
    }
}

