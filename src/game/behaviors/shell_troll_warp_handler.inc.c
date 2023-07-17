void bhv_shell_troll_warp_handler_init(void) {
   
}

void bhv_shell_troll_warp_handler_loop(void) {
   if (gMarioState->pos[1] < -2000 && o->oAction == 0) {
      gChangeArea = 2;
      vec3f_set(gMarioState->pos, 0.f, 30.f, 0.f);
      o->oAction++;
      mario_stop_riding_object(gMarioState);
      set_mario_action(gMarioState, ACT_FREEFALL, 0);
   }
}

u8 progressiveSignTable[] = {DIALOG_032, DIALOG_035, DIALOG_036};
void bhv_sign_change_dialog(void) {
   if (o->oBehParams2ndByte == progressiveSignTable[0] || o->oWoodenPostDialogProgression != 0) {
      switch (o->oAction) {
         case 0:
            if (gMarioState->action == ACT_READING_SIGN) {
               o->oAction = 1;
            }
            break;
         case 1:
            if (gMarioState->action != ACT_READING_SIGN) {
               o->oAction = 0;
               o->oWoodenPostDialogProgression++;
               if (o->oWoodenPostDialogProgression >= ARRAY_COUNT(progressiveSignTable)) {
                  o->oWoodenPostDialogProgression = ARRAY_COUNT(progressiveSignTable) - 1;
               }
               o->oBehParams2ndByte = progressiveSignTable[o->oWoodenPostDialogProgression];
            }
            break;
      }
   }
}