#include <ultra64.h>

#include "sm64.h"
#include "rendering_graph_node.h"
#include "mario_misc.h"
#include "skybox.h"
#include "engine/math_util.h"
#include "camera.h"
#include "envfx_snow.h"
#include "level_geo.h"
#include "segment7.h"
#include "game_init.h"
#include "puppyprint.h"
#include "debug.h"

#define TEXTURE_SIZE (320*240*2)
#define CYCLE_COUNT 40

#define STATIC_TIME 240
#define TRANSITION_TIME 50

#define IMG0_TRANS_START (STATIC_TIME)
#define IMG0_TRANS_END   (IMG0_TRANS_START + TRANSITION_TIME)
#define IMG1_TRANS_START (IMG0_TRANS_END + STATIC_TIME)
#define IMG1_TRANS_END   (IMG1_TRANS_START + TRANSITION_TIME)
#define IMG2_TRANS_START (IMG1_TRANS_END + STATIC_TIME)
#define IMG2_TRANS_END   (IMG2_TRANS_START + TRANSITION_TIME)
#define IMG3_TRANS_START (IMG2_TRANS_END + STATIC_TIME)
#define IMG3_TRANS_END   (IMG3_TRANS_START + TRANSITION_TIME)
#define IMG4_TRANS_START (IMG3_TRANS_END + STATIC_TIME + 0x10000000) // Never cycle back to 0
#define IMG4_TRANS_END   (IMG4_TRANS_START + TRANSITION_TIME)

struct TextureAddrs {
    Texture *t0Addr;
    Texture *t1Addr;
};

struct TextureAddrs textureAddrs = {NULL, NULL};
Texture *t0 = NULL;
Texture *t1 = NULL;

static Texture *loadScreenImages[5] = {
    load_screen_0,
    load_screen_1,
    load_screen_2,
    load_screen_3,
    load_screen_4,
};

static const s32 loadScreenTransTimes[ARRAY_COUNT(loadScreenImages) * 2] = {
    IMG0_TRANS_START,
    IMG0_TRANS_END,
    IMG1_TRANS_START,
    IMG1_TRANS_END,
    IMG2_TRANS_START,
    IMG2_TRANS_END,
    IMG3_TRANS_START,
    IMG3_TRANS_END,
    IMG4_TRANS_START,
    IMG4_TRANS_END,
};

void init_load_screen_buffers(void) {
    u8 *memaddr = main_pool_alloc(TEXTURE_SIZE * 2, MEMORY_POOL_LEFT);
    if (memaddr == NULL) {
        error("Out of memory! :(");
    }

    t0 = &memaddr[0];
    t1 = &memaddr[320*240*2];

    bzero(&textureAddrs, sizeof(struct TextureAddrs));
}

void dma_read(u8 *dest, u8 *srcStart, u8 *srcEnd);
static void dma_images(Texture *image0, Texture *image1, struct TextureAddrs *addrs) {
    Texture *addr0 = textureAddrs.t0Addr;
    Texture *addr1 = textureAddrs.t1Addr;

    image0 = segmented_to_virtual(image0);
    image1 = segmented_to_virtual(image1);

    s32 match0 = -1;
    s32 match1 = -1;

    if (image0 == addr0) {
        match0 = 0;
        addrs->t0Addr = t0;
    } else if (image0 == addr1) {
        match0 = 1;
        addrs->t0Addr = t1;
    }

    if (image1 == addr0 && match0 != 0) {
        match1 = 0;
        addrs->t1Addr = t0;
    } else if (image1 == addr1 && match0 != 1) {
        match1 = 1;
        addrs->t1Addr = t1;
    }

    if (match0 < 0 && image0 != NULL) {
        if (match1 == 0) {
            dma_read(t1, image0, image0 + TEXTURE_SIZE);
            addrs->t0Addr = t1;
            textureAddrs.t1Addr = image0;
            match0 = 1;
        } else {
            dma_read(t0, image0, image0 + TEXTURE_SIZE);
            addrs->t0Addr = t0;
            textureAddrs.t0Addr = image0;
            match0 = 0;
        }
    }

    if (match1 < 0 && image1 != NULL) {
        if (match0 == 0) {
            dma_read(t1, image1, image1 + TEXTURE_SIZE);
            addrs->t1Addr = t1;
            textureAddrs.t1Addr = image1;
            match1 = 1;
        } else {
            dma_read(t0, image1, image1 + TEXTURE_SIZE);
            addrs->t1Addr = t0;
            textureAddrs.t0Addr = image1;
            match1 = 0;
        }
    }
}

// Scroll left, overlay on top of image to replace
static void render_trans_screen_0(Texture *tex0, Texture *tex1, f32 progressionPercentage) {
    s32 imageOffset = 320.0f * progressionPercentage;

    struct TextureAddrs taddrs;
    dma_images(tex0, tex1, &taddrs);

    render_multi_image(taddrs.t0Addr, 0, 0, 320, 240, 0, 0, G_CYC_1CYCLE);
    render_multi_image(taddrs.t1Addr, 320 - imageOffset, 0, 320, 240, 0, 0, G_CYC_1CYCLE);
}

// Crossfade
static void render_trans_screen_1(Texture *tex0, Texture *tex1, f32 progressionPercentage) {
    u8 transparency = 255.0f * progressionPercentage;

    struct TextureAddrs taddrs;
    dma_images(tex0, tex1, &taddrs);

    render_multi_image(taddrs.t0Addr, 0, 0, 320, 240, 0, 0, G_CYC_1CYCLE);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, transparency);
    render_multi_image(taddrs.t1Addr, 0, 0, 320, 240, 0, 0, G_CYC_1CYCLE);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
}

// Tile replace
static void render_trans_screen_2(Texture *tex0, Texture *tex1, f32 progressionPercentage) {
    s32 cycles = (CYCLE_COUNT / 2) * progressionPercentage; // Assumes CYCLE_COUNT is even, though may potentially not matter (untestable)
    
    struct TextureAddrs taddrs;
    dma_images(tex0, tex1, &taddrs);

    render_multi_image(taddrs.t0Addr, 0, 0, 320, 240,               cycles,               cycles, G_CYC_1CYCLE);
    render_multi_image(taddrs.t1Addr, 0, 0, 320, 240,                    0, CYCLE_COUNT - cycles, G_CYC_1CYCLE);
    render_multi_image(taddrs.t1Addr, 0, 0, 320, 240, CYCLE_COUNT - cycles,                    0, G_CYC_1CYCLE);
}

// Scroll up, also scroll image to replace
static void render_trans_screen_3(Texture *tex0, Texture *tex1, f32 progressionPercentage) {
    s32 imageOffset = -240.0f * progressionPercentage;
    
    struct TextureAddrs taddrs;
    dma_images(tex0, tex1, &taddrs);

    // Reverse order matters here, else visual jank
    render_multi_image(taddrs.t0Addr, 0,       imageOffset, 320, 240, 0, 0, G_CYC_1CYCLE);
    render_multi_image(taddrs.t1Addr, 0, 240 + imageOffset, 320, 240, 0, 0, G_CYC_1CYCLE);
}

static void process_load_screen(void) {
    s32 imageDoubleIndex;
    s32 imageIndex;
    s32 transImageIndex;
    f32 progressionPercentage;

    loadIsTransitioning = FALSE;

    if (loadScreenTimer < 0) {
        // Not loading loading screen
        struct TextureAddrs taddrs;
        dma_images(loadScreenImages[0], NULL, &taddrs);
        render_multi_image(taddrs.t0Addr, 0, 0, 320, 240, 0, 0, G_CYC_1CYCLE);
        return;
    }

    loadScreenTimer %= loadScreenTransTimes[ARRAY_COUNT(loadScreenTransTimes) - 1];

    for (imageDoubleIndex = 0; imageDoubleIndex < ARRAY_COUNT(loadScreenTransTimes) && loadScreenTimer >= loadScreenTransTimes[imageDoubleIndex]; imageDoubleIndex++);
    if (imageDoubleIndex == ARRAY_COUNT(loadScreenTransTimes)) {
        error("You suck at coding how did you get here");
    }

    transImageIndex = ((imageDoubleIndex + 1) / 2) % ARRAY_COUNT(loadScreenImages);
    imageIndex = imageDoubleIndex / 2;

    if (imageIndex == transImageIndex) {
        // Not transitioning
        struct TextureAddrs taddrs;
        dma_images(loadScreenImages[imageIndex], NULL, &taddrs);
        render_multi_image(taddrs.t0Addr, 0, 0, 320, 240, 0, 0, G_CYC_1CYCLE);
        return;
    }

    loadIsTransitioning = TRUE;

    // NOTE: This assumes the array accesses will always be in bounds. Safety checks are skipped here!!
    progressionPercentage = (f32) (loadScreenTimer - loadScreenTransTimes[imageDoubleIndex - 1]) / (f32) (loadScreenTransTimes[imageDoubleIndex] - loadScreenTransTimes[imageDoubleIndex - 1]);

    switch (imageIndex) {
        case 0:
            render_trans_screen_0(loadScreenImages[imageIndex], loadScreenImages[transImageIndex], progressionPercentage);
            break;
        case 1:
            render_trans_screen_1(loadScreenImages[imageIndex], loadScreenImages[transImageIndex], progressionPercentage);
            break;
        case 2:
            render_trans_screen_2(loadScreenImages[imageIndex], loadScreenImages[transImageIndex], progressionPercentage);
            break;
        case 3:
            render_trans_screen_3(loadScreenImages[imageIndex], loadScreenImages[transImageIndex], progressionPercentage);
            break;
        case 4:
            render_trans_screen_2(loadScreenImages[imageIndex], loadScreenImages[transImageIndex], progressionPercentage); // This should never happen
            break;
        default:
            break;
    }
}

Gfx *geo_load_screen(s32 state, UNUSED struct GraphNode *node, UNUSED void *context) {
    if (state == GEO_CONTEXT_RENDER) {
        gSPDisplayList(gDisplayListHead++, dl_hud_img_begin);
        gDPSetCombineMode(gDisplayListHead++, G_CC_FADEA, G_CC_FADEA);
        gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

        process_load_screen();

        gSPDisplayList(gDisplayListHead++, dl_hud_img_end);
        gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
    }

    return NULL;
}

/**
 * Geo function that generates a displaylist for environment effects such as
 * snow or jet stream bubbles.
 */
Gfx *geo_envfx_main(s32 callContext, struct GraphNode *node, Mat4 mtxf) {
    Vec3s marioPos;
    Vec3s camFrom;
    Vec3s camTo;
    void *particleList;
    Gfx *gfx = NULL;

    if (callContext == GEO_CONTEXT_RENDER && gCurGraphNodeCamera != NULL) {
        struct GraphNodeGenerated *execNode = (struct GraphNodeGenerated *) node;
        u32 *params = &execNode->parameter; // accessed a s32 as 2 u16s by pointing to the variable and
                                            // casting to a local struct as necessary.

        if (GET_HIGH_U16_OF_32(*params) != gAreaUpdateCounter) {
            s32 snowMode = GET_LOW_U16_OF_32(*params);

            vec3f_to_vec3s(camTo, gCurGraphNodeCamera->focus);
            vec3f_to_vec3s(camFrom, gCurGraphNodeCamera->pos);
            vec3f_to_vec3s(marioPos, gPlayerCameraState->pos);
            particleList = envfx_update_particles(snowMode, marioPos, camTo, camFrom);
            if (particleList != NULL) {
                Mtx *mtx = alloc_display_list(sizeof(*mtx));

                gfx = alloc_display_list(2 * sizeof(*gfx));
                mtxf_to_mtx(mtx, mtxf);
                gSPMatrix(&gfx[0], VIRTUAL_TO_PHYSICAL(mtx), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
                gSPBranchList(&gfx[1], VIRTUAL_TO_PHYSICAL(particleList));
                SET_GRAPH_NODE_LAYER(execNode->fnNode.node.flags, LAYER_OCCLUDE_SILHOUETTE_ALPHA);
            }
            SET_HIGH_U16_OF_32(*params, gAreaUpdateCounter);
        }
    } else if (callContext == GEO_CONTEXT_AREA_INIT) {
        // Give these arguments some dummy values. Not used in ENVFX_MODE_NONE
        vec3s_copy(camTo, gVec3sZero);
        vec3s_copy(camFrom, gVec3sZero);
        vec3s_copy(marioPos, gVec3sZero);
        envfx_update_particles(ENVFX_MODE_NONE, marioPos, camTo, camFrom);
    }

    return gfx;
}

/**
 * Geo function that generates a displaylist for the skybox. Can be assigned
 * as the function of a GraphNodeBackground.
 */
Gfx *geo_skybox_main(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    Gfx *gfx = NULL;
    struct GraphNodeBackground *backgroundNode = (struct GraphNodeBackground *) node;

    if (callContext == GEO_CONTEXT_AREA_LOAD) {
        backgroundNode->unused = 0;
#ifndef L3DEX2_ALONE
    } else if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeCamera *camNode = (struct GraphNodeCamera *) gCurGraphNodeRoot->views[0];
        struct GraphNodePerspective *camFrustum =
            (struct GraphNodePerspective *) camNode->fnNode.node.parent;
        gfx = create_skybox_facing_camera(0, backgroundNode->background, camFrustum->fov, gLakituState.pos, gLakituState.focus);
#endif
    }

    return gfx;
}
