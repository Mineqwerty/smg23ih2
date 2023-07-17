#include "src/game/game_init.h"
#include "levels/wf/squid_word/geo_header.h"

void bhv_squid_word_init(void) {
}

void bhv_squid_word_loop(void) {
    extern const u8 sq_tl_textures_dma[];
    extern u8 squid_word_sqtl0_rgba16_rgba16[];
    u8 *topLeftTexture = segmented_to_virtual(&squid_word_sqtl0_rgba16_rgba16);

    extern const u8 sq_tr_textures_dma[];
    extern u8 squid_word_sqtr0_rgba16_rgba16[];
    u8 *topRightTexture = segmented_to_virtual(&squid_word_sqtr0_rgba16_rgba16);

    extern const u8 sq_bl_textures_dma[];
    extern u8 squid_word_sqbl0_rgba16_rgba16[];
    u8 *bottomLeftTexture = segmented_to_virtual(&squid_word_sqbl0_rgba16_rgba16);

    extern const u8 sq_br_textures_dma[];
    extern u8 squid_word_sqbr0_rgba16_rgba16[];
    u8 *bottomRightTexture = segmented_to_virtual(&squid_word_sqbr0_rgba16_rgba16);

    // set action to 1 when cucking mario, or change if statement acoordingly otherwise so that it only dmas when squid is active
    if (o->oAction == 1 && o->oTimer < 42) {
        dma_read(topLeftTexture, ((o->oTimer / 2) * 4096) + (u8 *) sq_tl_textures_dma,
                 ((o->oTimer / 2) * 4096) + (u8 *) sq_tl_textures_dma + 4096);
        dma_read(topRightTexture, ((o->oTimer / 2) * 4096) + (u8 *) sq_tr_textures_dma,
                 ((o->oTimer / 2) * 4096) + (u8 *) sq_tr_textures_dma + 4096);
        dma_read(bottomLeftTexture, ((o->oTimer / 2) * 4096) + (u8 *) sq_bl_textures_dma,
                 ((o->oTimer / 2) * 4096) + (u8 *) sq_bl_textures_dma + 4096);
        dma_read(bottomRightTexture, ((o->oTimer / 2) * 4096) + (u8 *) sq_br_textures_dma,
                 ((o->oTimer / 2) * 4096) + (u8 *) sq_br_textures_dma + 4096);

        load_object_collision_model();
    }

    //placeholder transition to action 1
    if (o->oAction == 0 && o->oTimer == 30) {
        o->oAction = 1;
    }
}
