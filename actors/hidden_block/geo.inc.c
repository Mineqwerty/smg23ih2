// 0x0F000A30
const GeoLayout hidden_block_geo[] = {
   GEO_CULLING_RADIUS(500),
   GEO_OPEN_NODE(),
      GEO_SHADOW(SHADOW_SQUARE_PERMANENT, 0xB4, 308),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, hidden_block_dl),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
