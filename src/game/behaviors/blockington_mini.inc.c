// blockington_mini.inc.c

#define BMINI_DIST 10000.0f

static void bhv_blockington_mini_set_angle_scale(void) {
    o->oFaceAnglePitch = (s16) ((u16) o->oBlockingtonAngleHomePitch + (u16) sBlockington.curAngle[0]);
    o->oFaceAngleYaw = (s16) ((u16) o->oBlockingtonAngleHomeYaw + (u16) sBlockington.curAngle[1] + (u16) 0x600);
    o->oFaceAngleRoll = (s16) ((u16) o->oBlockingtonAngleHomeRoll + (u16) sBlockington.curAngle[2]);

    o->header.gfx.scale[0] = o->oBlockingtonScaleHomeX * sBlockington.curScale[0];
    o->header.gfx.scale[1] = o->oBlockingtonScaleHomeY * sBlockington.curScale[1];
    o->header.gfx.scale[2] = o->oBlockingtonScaleHomeZ * sBlockington.curScale[2];
}

static void bhv_blockington_mini_set_obj_pos(void) {
    s16 pitch;
    s16 yaw;

    vec3f_get_angle(gCamera->pos, gCamera->focus, &pitch, &yaw);

    pitch -= 0x600;
    yaw += 0x1000;

    o->oBlockingtonAngleHomePitch = pitch;
    o->oBlockingtonAngleHomeYaw = yaw + 0x8000;

    o->oPosX = gCamera->pos[0] + sins((u16) yaw) * coss((u16) -pitch) * BMINI_DIST;
    o->oPosY = gCamera->pos[1] + sins((u16) pitch) * BMINI_DIST;
    o->oPosZ = gCamera->pos[2] + coss((u16) yaw) * coss((u16) -pitch) * BMINI_DIST;
}

void bhv_blockington_mini_init(void) {
    cur_obj_scale(5.0f);
    o->oBlockingtonAngleHomePitch = 0;
    o->oBlockingtonAngleHomeYaw = 0;
    o->oBlockingtonAngleHomeRoll = 0;
    vec3f_copy(&o->oBlockingtonScaleHomeVec, o->header.gfx.scale);
}

void bhv_blockington_mini_loop(void) {
    bhv_blockington_mini_set_obj_pos();
    bhv_blockington_mini_set_angle_scale();
}
