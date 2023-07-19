// thwomp.inc.c

void grindel_thwomp_act_on_ground(void) {
    if (o->oTimer == 0) {
        o->oThwompRandomTimer = random_float() * 10.0f + 20.0f;
    }
    if (o->oTimer > o->oThwompRandomTimer) {
        o->oAction = GRINDEL_THWOMP_ACT_RISING;
    }
}

void grindel_thwomp_act_falling(void) {
    o->oVelY += -4.0f;
    o->oPosY += o->oVelY;
    if (o->oPosY < o->oHomeY) {
        o->oPosY = o->oHomeY;
        o->oVelY = 0.0f;
        o->oAction = GRINDEL_THWOMP_ACT_LAND;
    }
}

void grindel_thwomp_act_land(void) {
    if (o->oTimer == 0 && o->oDistanceToMario < 1500.0f) {
        cur_obj_shake_screen(SHAKE_POS_SMALL);
        cur_obj_play_sound_2(SOUND_OBJ_THWOMP);
    }
    if (o->oTimer >= 10) {
        o->oAction = GRINDEL_THWOMP_ACT_ON_GROUND;
    }
}

void grindel_thwomp_act_floating(void) {
    if (o->oTimer == 0) {
        o->oThwompRandomTimer = random_float() * 30.0f + 10.0f;
    }
    if (o->oTimer > o->oThwompRandomTimer) {
        o->oAction = GRINDEL_THWOMP_ACT_FALLING;
    }
}

void grindel_thwomp_act_rising(void) {
    if (o->oBehParams2ndByte + 40 < o->oTimer) {
        o->oAction = GRINDEL_THWOMP_ACT_FLOATING;
        o->oPosY += 5.0f;
    } else {
        o->oPosY += 10.0f;
    }
}

ObjActionFunc sGrindelThwompActions[] = {
    grindel_thwomp_act_rising,
    grindel_thwomp_act_floating,
    grindel_thwomp_act_falling,
    grindel_thwomp_act_land,
    grindel_thwomp_act_on_ground
};

void bhv_grindel_thwomp_loop(void) {
    cur_obj_call_action_function(sGrindelThwompActions);
}

#define OFFSCREEN_THWOMP_SCALE 2.5f
#define OFFSCREEN_THWOMP_RADIUS (OFFSCREEN_THWOMP_SCALE * 156.0f)
void bhv_offscreen_thwomp_init(void) {
    o->oPosY = o->oHomeY + 4000.0f;
    cur_obj_scale(OFFSCREEN_THWOMP_SCALE);
    cur_obj_hide();
}

void bhv_offscreen_thwomp_loop(void) {
    if (o->header.gfx.node.flags & GRAPH_RENDER_INVISIBLE) {
        if (lateral_dist_between_objects(o, gMarioObject) > 400.0f) {
            cur_obj_hide();
            return;
        } else {
            cur_obj_unhide();
            o->oAction = GRINDEL_THWOMP_ACT_FALLING;
        }
    }

    cur_obj_unhide();
    load_object_collision_model();
    cur_obj_call_action_function(sGrindelThwompActions);

    f32 xDiff = gMarioState->pos[0] - o->oPosX;
    f32 yDiff = gMarioState->pos[1] - (o->oPosY + OFFSCREEN_THWOMP_RADIUS);
    f32 zDiff = gMarioState->pos[2] - o->oPosZ;

    if (
        ABS(xDiff) < OFFSCREEN_THWOMP_RADIUS &&
        ABS(yDiff) < OFFSCREEN_THWOMP_RADIUS &&
        ABS(zDiff) < OFFSCREEN_THWOMP_RADIUS
    ) {
        gMarioState->pos[1] = o->oPosY;
    }
}
