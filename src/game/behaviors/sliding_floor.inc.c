void bhv_sliding_floor_init(void) {
   
}

void bhv_sliding_floor_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                o->oAction = 1;
            }
        break;
        case 1:
            o->oPosX += 80 * coss(o->oTimer * 0x222);
            if (o->oTimer == 30) {
                o->oAction = 2;
            }
        break;
    }
   
}

