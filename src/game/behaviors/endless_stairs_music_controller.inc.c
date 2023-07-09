void bhv_endless_stairs_music_controller_init(void) {
   
}

void bhv_endless_stairs_music_controller_loop(void) {

    if (gDialogID != -1) {
        o->oTimer = 0;
    }

    if (o->oTimer > 90 && o->oAction == 0 && gCamera->cutscene == 0 && gDialogID == -1) {
        play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_LEVEL_GRASS), 0);
        gShitMusic = 1;
        o->oAction++;
    }


    //s16 musicDist;


   if (gMarioState->pos[1] < -4000) {
    gShitMusic = 0;
    //musicDist = 128 - ((10000 + gMarioState->pos[1]) / 250);
    //if (musicDist < 0) musicDist = 0;
    //if (musicDist > 128) musicDist = 128;
    func_80321080(10);
    play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_EVENT_ENDLESS_STAIRS), 0);
   }
}

