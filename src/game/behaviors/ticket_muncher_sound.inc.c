// ticket_muncher_sound.inc.c

void bhv_ticket_muncher_sound_loop(void) {
    if (o->oDistanceToMario > 2000.0f) {
        return;
    }

    cur_obj_play_sound_2(SOUND_ENV_TICKET_MUNCHER);
}
