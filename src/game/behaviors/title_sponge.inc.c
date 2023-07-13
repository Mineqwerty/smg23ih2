#include "src/game/game_init.h"
#include "actors/title_sponge/geo_header.h"

void bhv_title_sponge_init(void) {
   
}

void bhv_title_sponge_loop(void) {
   extern const u8 sponge_top_textures_dma[];
    extern u8 title_sponge_dmatex_rgba16[];
    u8 *topTexture = segmented_to_virtual(&title_sponge_dmatex_rgba16);

    extern const u8 sponge_bottom_textures_dma[];
    extern u8 title_sponge_dma2_rgba16[];
    u8 *bottomTexture = segmented_to_virtual(&title_sponge_dma2_rgba16);

    if (o->oTimer > 50) {
        cur_obj_unhide();

        if (o->oTimer < (50 + 48)) {
            dma_read(topTexture, (((o->oTimer - 50) / 3)*4096) + sponge_top_textures_dma, (((o->oTimer - 50) / 3)*4096) + sponge_top_textures_dma + 4096);
            dma_read(bottomTexture, (((o->oTimer - 50) / 3)*4096) + sponge_bottom_textures_dma, (((o->oTimer - 50) / 3)*4096) + sponge_bottom_textures_dma + 4096);
        }
    }
    else {
        cur_obj_hide();
    }
    
}

