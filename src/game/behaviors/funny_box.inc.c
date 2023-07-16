void bhv_funny_box_init(void) {
   o->oHomeY = o->oPosY;
   play_sound(SOUND_DRUNK_SQUIRREL, gGlobalSoundSource);
}

void bhv_funny_box_loop(void) {
   o->oFaceAngleYaw += 0x400;
   o->oPosY = o->oHomeY + (300 * sins(o->oTimer * 0x200));
}

