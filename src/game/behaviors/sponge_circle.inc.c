void bhv_sponge_circle_init(void) {
    o->oAngleVelRoll = random_u16() / 64;
    o->oAngleVelYaw = random_u16() / 64;
    o->oAngleVelPitch = random_u16() / 64;
}

void bhv_sponge_circle_loop(void) {
   o->oFaceAngleYaw += o->oAngleVelYaw;
   o->oFaceAnglePitch += o->oAngleVelPitch;
   o->oFaceAngleRoll += o->oAngleVelRoll;

   if (gMarioState->pos[1] < -8000) {
    if (random_u16() % 60 == 1) {
        play_sound(SOUND_SPONGE, gMarioState->marioObj->header.gfx.cameraToObject);
    }
   }
}

