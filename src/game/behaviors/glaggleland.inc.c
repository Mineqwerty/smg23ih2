void bhv_glaggleland_init(void) {
   
}

void bhv_glaggleland_loop(void) {
    if (o->oTimer >= 2594) {
        gGlaggleMad = TRUE;
        gMarioState->action = ACT_WAITING_FOR_DIALOG;
        gCamera->cutscene = 1;
    }

    else {
        print_text(220, 142 + (u8)(40*sins(o->oTimer * 0x200)), "|"); 
        print_text(123 + (u8)(40*sins((o->oTimer + 5)* 0x300)), 193, "|"); 

        print_text(10, 10, "ENABLE FRAMEBUFFER EMU"); 
    }

    
}

