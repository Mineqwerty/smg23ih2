// babomb_excivatoin_letter.inc.c

void bhv_babomb_excivatoin_letter_init(void) {
    o->oAnimState = o->oBehParams2ndByte;
}

void bhv_babomb_excivatoin_letter_loop(void) {
    if (o->oTimer >= 45) {
        o->oTimer = 0;
    }

    if (o->oTimer == 0) {
        o->oFaceAngleRoll = (random_float() - 0.5f) * (f32) 0x2000;
        o->oBabombExcivatoinLetterColor = ((u32) random_u16() << 16) | random_u16();
    }
}


Gfx *geo_babomb_excivatoin_letter_color(s32 callContext, struct GraphNode *node, UNUSED s32 context) {
    Gfx *gfxHead = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeGenerated *graphNode = (struct GraphNodeGenerated *) node;

        u32 color = obj->oBabombExcivatoinLetterColor;

        // Set layers if object is transparent or not
        SET_GRAPH_NODE_LAYER(graphNode->fnNode.node.flags, LAYER_ALPHA_DECAL);

        Gfx *gfx = gfxHead = alloc_display_list(2 * sizeof(Gfx));

        gDPSetEnvColor(gfx++, (((color >> 24) & 0x7F) + 0x20), (((color >> 16) & 0x7F) + 0x20), (((color >> 8) & 0x3F) + 0x20), 255);
        // gDPSetEnvColor(gfx++, 0, 0, 0, 255);
        gSPEndDisplayList(gfx);
    }

    return gfxHead;
}
