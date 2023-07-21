void bhv_float_in_place_init(void) {
   
}

void bhv_float_in_place_loop(void) {
   o->oPosY = o->oHomeY + o->oBehParams2ndByte * sins(o->oTimer * 0x200);
}

