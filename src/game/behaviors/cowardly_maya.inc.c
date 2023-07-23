void bhv_cowardly_maya_init(void) {
   
}

void bhv_cowardly_maya_loop(void) {
    if (o->oAction == 0) {
        if (o->oTimer <= 60) {
            cur_obj_hide();
        }
        else {
            cur_obj_unhide();
            cur_obj_scale((f32)(o->oTimer - 60) / 10.0f);
            if (o->oTimer == 70) {
                o->oAction = 1;
                cur_obj_scale(1);
            }
        }
    }
    if (o->oAction == 1) {
        cur_obj_init_animation(0);
    }
    if (o->oAction == 2) {
        cur_obj_init_animation(1);
    }
}

