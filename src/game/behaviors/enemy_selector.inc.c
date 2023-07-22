

void bhv_enemy_selector_init(void) {
   
}

void bhv_enemy_selector_loop(void) {
    if (!(gPersonaMenuFlags & PERSONA_MENU_FLAGS_ATTACK_TEXT)) {
        obj_mark_for_deletion(o);
        return;
    }

   struct Object *currentEnemy;
   currentEnemy = cur_obj_find_object_with_bparam_2nd_byte(bhvCowardlyMaya, gSelectedEnemy);
   if (currentEnemy) {
    o->oPosX = currentEnemy->oPosX;
    o->oPosY = currentEnemy->oPosY + 70;
    o->oPosZ = currentEnemy->oPosZ;
   }

   
}

