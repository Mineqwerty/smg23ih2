void bhv_shell_troll_warp_handler_init(void) {
   
}

void bhv_shell_troll_warp_handler_loop(void) {
   if (gMarioState->pos[1] < -2000 && o->oAction == 0) {
    gChangeArea = 2;
    vec3f_set(gMarioState->pos, 0.f, 0.f, 0.f);
    o->oAction++;
   }
}

