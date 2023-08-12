// rhdc_pfp.inc.c

void bhv_rhdc_pfp_init(void) {

}

void bhv_rhdc_pfp_loop(void) {

}

Gfx *geo_rhdc_pfp(s32 callContext, struct GraphNode *node, UNUSED s32 context) {
    Gfx *gfxHead = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeGenerated *graphNode = (struct GraphNodeGenerated *) node;

        // Set layers if object is alpha or not
        SET_GRAPH_NODE_LAYER(graphNode->fnNode.node.flags, LAYER_TRANSPARENT);

        Gfx *gfx = gfxHead = alloc_display_list(2 * sizeof(Gfx));

        gDPSetTextureImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 1, VIRTUAL_TO_PHYSICAL(rhdcPFPRGBA32));
        gSPEndDisplayList(gfx);
    }

    return gfxHead;
}