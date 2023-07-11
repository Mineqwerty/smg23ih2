void bhv_shell_troll_warp_handler_init(void) {
   
}

void bhv_shell_troll_warp_handler_loop(void) {
    //i didnt actually test any of this yet because i dont feel like making the level rn lmao
   if (gMarioState->pos[1] < -2000) {
    change_area(2);
    vec3f_set(gMarioState->pos, 0.f, 0.f, 0.f);
   }
}

