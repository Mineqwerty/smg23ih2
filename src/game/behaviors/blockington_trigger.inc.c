// blockington_trigger.inc.c

void bhv_blockington_trigger_init(void) {

}

static void bhv_blockington_trigger_generic(void) {
    if (gMarioState->fazanaCar->oFazanaCarGroundedLast == FALSE) {
        return;
    }

    if (dist_between_objects(o, gMarioState->fazanaCar) <= GET_BPARAM34(o->oBehParams)) {
        struct Object *obj = spawn_object(o, MODEL_BLOCKINGTON_MINI, bhvBlockingtonMini);
        if (obj) {
            obj->oBehParams = (o->oBehParams2ndByte) << 16;
        }
        obj_mark_for_deletion(o);
    }
}

static void bhv_blockington_trigger_pity_bridge(void) {
    // Twelfth red coin is the one that matters
    if (find_first_object_with_behavior_and_bparams(bhvRedCoin, 12 << 16, 0x00FF0000) == NULL) {
        struct Object *obj = spawn_object(o, MODEL_BLOCKINGTON_MINI, bhvBlockingtonMini);
        if (obj) {
            if (!o->oBTrigBridgeRaised || o->oBTrigHitOffGround) {
                obj->oBehParams = (BKTN_DIA_COIN_12_NORMAL) << 16;
            } else {
                obj->oBehParams = (BKTN_DIA_COIN_12_PITY) << 16;
            }
        }

        obj_mark_for_deletion(o);
        return;
    }

    // Thirteenth red coin needs to be collected in order to commence special state
    if (!o->oBTrigRedCollected) {
        if (find_first_object_with_behavior_and_bparams(bhvRedCoin, 13 << 16, 0x00FF0000) != NULL) {
            return;
        }

        o->oBTrigHitOffGround = TRUE;
        o->oBTrigRedCollected = TRUE;
    }

    if (dist_between_objects(o, gMarioState->fazanaCar) <= GET_BPARAM34(o->oBehParams)) {
        o->oBTrigHitOffGround = TRUE;
    } else if (o->oBTrigHitOffGround && gMarioState->fazanaCar->oFazanaCarGroundedLast == TRUE && gMarioState->fazanaCar->oPosY <= o->oPosY - 800.0f) {
        o->oBTrigMissCounter++;

        if (o->oBTrigMissCounter == 3) {
            struct Object *obj = spawn_object(o, MODEL_BLOCKINGTON_MINI, bhvBlockingtonMini);
            if (obj) {
                obj->oBehParams = ((BKTN_DIA_PITY_BRIDGE) << 16) | 2; // Higher priority
            }
        }

        o->oBTrigHitOffGround = FALSE;
    }
}

void bhv_blockington_trigger_loop(void) {
    if (gMarioState->action != ACT_FAZANA_CAR || gMarioState->fazanaCar == NULL || gMarioState->fazanaCar->activeFlags & ACTIVE_FLAG_DEACTIVATED) {
        return;
    }

    switch(o->oBehParams2ndByte) {
        case BKTN_DIA_PITY_BRIDGE:
            bhv_blockington_trigger_pity_bridge();
            break;
        default:
            bhv_blockington_trigger_generic();
            break;
    }
}
