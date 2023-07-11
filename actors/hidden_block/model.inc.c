// Hidden Block

ALIGNED8 static const Texture hidden_block_texture[] = {
#include "actors/hidden_block/hidden_block.rgba16.inc.c"
};

static const Vtx hidden_block_vertex_0[] = {
    {{{   154,    307,   -153}, 0, {   990,      0}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{  -153,    307,   -153}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{  -153,    307,    154}, 0, {     0,   2012}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{   154,    307,    154}, 0, {   990,   2012}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{  -153,      0,   -153}, 0, {   990,   2012}, {0x00, 0x00, 0x81, 0xff}}},
    {{{  -153,    307,   -153}, 0, {   990,      0}, {0x00, 0x00, 0x81, 0xff}}},
    {{{   154,    307,   -153}, 0, {     0,      0}, {0x00, 0x00, 0x81, 0xff}}},
    {{{   154,      0,   -153}, 0, {     0,   2012}, {0x00, 0x00, 0x81, 0xff}}},
    {{{  -153,      0,    154}, 0, {   990,   2012}, {0x81, 0x00, 0x00, 0xff}}},
    {{{  -153,    307,    154}, 0, {   990,      0}, {0x81, 0x00, 0x00, 0xff}}},
    {{{  -153,    307,   -153}, 0, {     0,      0}, {0x81, 0x00, 0x00, 0xff}}},
    {{{  -153,      0,   -153}, 0, {     0,   2012}, {0x81, 0x00, 0x00, 0xff}}},
    {{{   154,      0,    154}, 0, {   990,      0}, {0x00, 0x81, 0x00, 0xff}}},
    {{{  -153,      0,    154}, 0, {     0,      0}, {0x00, 0x81, 0x00, 0xff}}},
    {{{  -153,      0,   -153}, 0, {     0,   2012}, {0x00, 0x81, 0x00, 0xff}}},
    {{{   154,      0,   -153}, 0, {   990,   2012}, {0x00, 0x81, 0x00, 0xff}}},
};

static const Vtx hidden_block_vertex_1[] = {
    {{{   154,      0,    154}, 0, {   990,   2012}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{  -153,    307,    154}, 0, {     0,      0}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{  -153,      0,    154}, 0, {     0,   2012}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{   154,    307,    154}, 0, {   990,      0}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{   154,      0,   -153}, 0, {   990,   2012}, {0x7f, 0x00, 0x00, 0xff}}},
    {{{   154,    307,   -153}, 0, {   990,      0}, {0x7f, 0x00, 0x00, 0xff}}},
    {{{   154,    307,    154}, 0, {   -24,    -36}, {0x7f, 0x00, 0x00, 0xff}}},
    {{{   154,      0,    154}, 0, {   -24,   2008}, {0x7f, 0x00, 0x00, 0xff}}},
};

const Gfx hidden_block_dl_verts[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hidden_block_texture),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 64 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLightColor(LIGHT_1, 0xffffffff),
    gsSPLightColor(LIGHT_2, 0x7f7f7fff),
    gsSPVertex(hidden_block_vertex_0, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSP2Triangles( 4,  5,  6, 0x0,  4,  6,  7, 0x0),
    gsSP2Triangles( 8,  9, 10, 0x0,  8, 10, 11, 0x0),
    gsSP2Triangles(12, 13, 14, 0x0, 12, 14, 15, 0x0),
    gsSPVertex(hidden_block_vertex_1, 8, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  3,  1, 0x0),
    gsSP2Triangles( 4,  5,  6, 0x0,  4,  6,  7, 0x0),
    gsSPEndDisplayList(),
};

const Gfx hidden_block_dl[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_MODULATERGB),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (64 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPDisplayList(hidden_block_dl_verts),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};
