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
    if (o->oAction == 3) {
        cur_obj_init_animation(2);
        if (o->oTimer == 5) {
            for (int i = 0; i < 10; i++) {
                spawn_object_relative(0, 0, i * 5, 0, o, MODEL_SHADOW_PARTICLE, bhvAgiParticle);
            }
            cur_obj_hide();
        }
    }
    if (o->oAction == 4) {
        cur_obj_init_animation(2);
        if (o->oTimer == 30) {
            cur_obj_init_animation(0);
        }
    }
}

void bhv_agi_particle_init(void) {
    o->oVelX = (random_float() * 20.0f) - 10.0f;
    o->oVelY = (random_float() * 20.0f) - 10.0f;
    o->oVelZ = (random_float() * 20.0f) - 10.0f;
}

void bhv_agi_particle_loop(void) {
    o->oPosX += o->oVelX;
    o->oPosY += o->oVelY;
    o->oPosZ += o->oVelZ;

    if (o->oTimer > 38 && (random_u16() % 4) == 0) {
        obj_mark_for_deletion(o);
    }
}