// confetti.inc.c

static void confetti_update_pos_and_color(void) {
    u32 val = (random_u16() << 16) | random_u16();

    o->oAnimState = val >> 29; // 8 states

    o->oConfettiColorR = val & 0xFF;
    o->oConfettiColorG = (val >> 8) & 0xFF;
    o->oConfettiColorB = (val >> 16) & 0xFF;

    o->oPosY = o->oHomeY + 1000.0f;

    f32 dist = 1500.0f * random_float();
    s16 angle = random_u16();

    o->oPosX = o->oHomeX + sins(angle) * dist;
    o->oPosZ = o->oHomeZ + coss(angle) * dist;

    o->oVelY = -((f32) (4 + ((val >> 24) & 0x0F)));

    o->oVelX = (random_float() - 0.5f) * 24.0f;
    o->oVelZ = (random_float() - 0.5f) * 24.0f;
}

void bhv_confetti_init(void) {
    o->oHomeX = o->oPosX + 500;
    o->oHomeY = o->oPosY - 80;
    o->oHomeZ = o->oPosZ;

    confetti_update_pos_and_color();

    o->oPosY = o->oHomeY + 1000.0f * random_float();
}

void bhv_confetti_loop(void) {
    vec3f_add(&o->oPosVec, &o->oVelVec);

    if (o->oPosY < o->oHomeY) {
        confetti_update_pos_and_color();
    }
}

Gfx *geo_confetti(s32 callContext, struct GraphNode *node, UNUSED s32 context) {
    Gfx *gfxHead = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeGenerated *graphNode = (struct GraphNodeGenerated *) node;

        // Set layers if object is alpha or not
        SET_GRAPH_NODE_LAYER(graphNode->fnNode.node.flags, LAYER_ALPHA);

        Gfx *gfx = gfxHead = alloc_display_list(2 * sizeof(Gfx));

        gDPSetEnvColor(gfx++, obj->oConfettiColorR, obj->oConfettiColorG, obj->oConfettiColorB, 255);
        gSPEndDisplayList(gfx);
    }

    return gfxHead;
}