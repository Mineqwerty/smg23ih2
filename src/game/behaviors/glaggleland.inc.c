void bhv_glaggleland_init(void) {
   
}

void bhv_glaggleland_loop(void) {
    if (!gGlaggleMad) {
        print_text(220, 142 + (u8)(40*sins(o->oTimer * 0x200)), "|");
        print_text(123 + (u8)(40*sins((o->oTimer + 5)* 0x300)), 193, "|");

        print_text(10, 10, "ENABLE FRAMEBUFFER EMU");
    }
}
