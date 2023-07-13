// checkpoint.inc.c

void bhv_checkpoint_loop(void) {
    f32 dist;
    f32 radius = (u16) GET_BPARAM34(o->oBehParams);

    if (
        o->oDistanceToMario < radius &&
        gMarioState->health >= 0x100 &&
        (
            (
                !(gMarioState->action & (ACT_FLAG_AIR | ACT_FLAG_INVULNERABLE | ACT_FLAG_INTANGIBLE)) &&
                (gMarioState->action & (ACT_FLAG_STATIONARY | ACT_FLAG_MOVING))
            ) ||
            gMarioState->action == ACT_FAZANA_CAR ||
            gMarioState->action == ACT_DEBUG_FREE_MOVE
        ) &&
        o == obj_find_nearest_object_with_behavior(gMarioObject, bhvCheckpoint, &dist)
    ) {
        save_file_set_checkpoint(o->oBehParams2ndByte, gCurrLevelNum, gCurrAreaIndex);
    }
}
