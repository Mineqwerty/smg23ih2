void bhv_jumpman_init(void) {

}

void bhv_jumpman_loop(void) {
    switch (o->oBehParams2ndByte) {
        case 0:
            o->oFaceAngleYaw += 0x400;
            if (o->oTimer > 30) {
                o->oPosX -= 20;
                o->oPosZ -= 20;
            }
            if (o->oTimer == 40) {
                spawn_triangle_break_particles(60, MODEL_CARTOON_STAR, 0.3f, o->oBehParams2ndByte);
            }
            if (o->oTimer == 90) {
                obj_mark_for_deletion(o);
            }
        break;
        case 1:
            
            if (o->oTimer < 30) {
                o->oFaceAngleYaw += 0x400;
                o->oPosY += 10.0f;
            }
            else {
                o->oFaceAnglePitch -= 0x200;
            }

            if (o->oTimer == 90) {
                obj_mark_for_deletion(o);
            }
        break;
    }
}

