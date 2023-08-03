#include "src/engine/math_util.h"

extern s16 object_step();

void bhv_giggler_init(void) {
    o->oGravity = 3.0f;
    o->oFloatF4 = 1.0f;
}

void bhv_giggler_loop(void) {
    elastic_approach_i_stole_from_cozies(&o->oFloatF4, &o->oFloatF8, absf(o->oVelY / 50.0f), 0.1f,
                                         0.3f);

    if (object_step() & OBJ_COL_FLAG_GROUNDED) {
        o->oVelY = 70.0f;
        cur_obj_play_sound_1(SOUND_GENERAL_CRAZY_BOX_BOING_SLOW);
    }
    obj_scale_xyz(o, CLAMP(o->oFloatF4, 0.25f, 5.0f), CLAMP(1.0f / o->oFloatF4, 0.01f, 2.0f), 1.0f);

    if (o->oTimer == 2594) {
        obj_mark_for_deletion(o);
    }
}
