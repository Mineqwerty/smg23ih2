void bhv_endless_stairs_music_controller_init(void) {
    if (save_file_exists(gCurrSaveFileNum - 1)) {
        set_background_music(0, SEQ_LEVEL_GRASS, 0);
        gShitMusic = TRUE;
        o->oAction = 0;
    } else {
        o->oAction = 2;
    }
}

void bhv_endless_stairs_music_controller_loop(void) {
    //s16 musicDist;

    switch (o->oAction) {
        case 0:
            if (o->oPlayingEndlessStaircaseMusic) {
                func_80321080(500);
                o->oPlayingEndlessStaircaseMusic = FALSE;
            }
            if (o->oTimer > 60) {
                gShitMusic = TRUE;
            }
            break;
        case 1:
            //musicDist = 128 - ((10000 + gMarioState->pos[1]) / 250);
            //if (musicDist < 0) musicDist = 0;
            //if (musicDist > 128) musicDist = 128;
            play_secondary_music(SEQ_EVENT_ENDLESS_STAIRS, 0, 255, 1000);
            o->oPlayingEndlessStaircaseMusic = TRUE;
            if (o->oTimer > 10) {
                gShitMusic = FALSE;
            }
            break;
        case 2:
        default:
            if (gShitMusic) {
                o->oAction = 0;
            } else {
                return;
            }
            break;
    }

    if (gMarioState->pos[1] < -4000) {
        o->oAction = 1;
    } else {
        o->oAction = 0;
    }
}

