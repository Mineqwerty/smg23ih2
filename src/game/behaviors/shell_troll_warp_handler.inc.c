void bhv_shell_troll_warp_handler_init(void) {
   
}

void bhv_shell_troll_warp_handler_loop(void) {
   if (gMarioState->pos[1] < -2000 && o->oAction == 0) {
    gChangeArea = 2;
    vec3f_set(gMarioState->pos, 0.f, 30.f, 0.f);
    o->oAction++;
   }
}

void bhv_sign_change_dialog(void) {
   //for your sanity dont read this and just trust me that it works as intended
   if (o->oBehParams2ndByte == 32) {
      if (gMarioState->action == ACT_READING_SIGN) {
         o->oAction = 1;
      }

      if (o->oAction == 1 && o->oTimer > 30) {
         o->oBehParams2ndByte = 35;
         o->oAction = 2;
      }
   }

   if (o->oBehParams2ndByte == 35) {
      if (gMarioState->action == ACT_READING_SIGN && o->oAction == 3) {
         o->oAction = 4;
      }
      else if (gMarioState->action != ACT_READING_SIGN) {
         o->oAction = 3;
      }

      if (o->oAction == 4 && o->oTimer > 30) {
         o->oBehParams2ndByte = 36;
         o->oAction = 5;
      }
   }
}