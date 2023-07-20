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

#define STATIC_TIME 195

#define CYCLE_COUNT 40

#define IMG0_TRANS_START (STATIC_TIME - 30)
#define IMG0_TRANS_END   (IMG0_TRANS_START + 60)
#define IMG1_TRANS_START (IMG0_TRANS_END + STATIC_TIME)
#define IMG1_TRANS_END   (IMG1_TRANS_START + 60)
#define IMG2_TRANS_START (IMG1_TRANS_END + STATIC_TIME)
#define IMG2_TRANS_END   (IMG2_TRANS_START + 60)
#define IMG3_TRANS_START (IMG2_TRANS_END + STATIC_TIME)
#define IMG3_TRANS_END   (IMG3_TRANS_START + 60)

static Texture *loadScreenImages[4] = {
    load_screen_0,
    load_screen_1,
    load_screen_2,
    load_screen_3,
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
};

static void render_trans_screen_0(Texture *tex0, Texture *tex1, f32 progressionPercentage) {
    s32 imageOffset = 320.0f * progressionPercentage;

    render_multi_image(segmented_to_virtual(tex0), 0, 0, 320, 240, 0, 0, G_CYC_COPY);
    render_multi_image(segmented_to_virtual(tex1), 320 - imageOffset, 0, 320, 240, 0, 0, G_CYC_COPY);

    loadTransitionStatus = 0; // For next transition
}

static void render_trans_screen_1(Texture *tex0, Texture *tex1) {
    if (loadTransitionStatus == 0) {
        play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 30, 0, 0, 0); // Hardcode to 30, who cares tbh
        loadTransitionStatus = 1;
    }

    render_multi_image(segmented_to_virtual((loadTransitionStatus < 2) ? tex0 : tex1), 0, 0, 320, 240, 0, 0, G_CYC_COPY);
}

static void render_trans_screen_2(Texture *tex0, Texture *tex1, f32 progressionPercentage) {
    s32 cycles = CYCLE_COUNT * progressionPercentage * 0.5f;

    render_multi_image(segmented_to_virtual(tex0), 0, 0, 320, 240,               cycles,               cycles, G_CYC_COPY);
    render_multi_image(segmented_to_virtual(tex1), 0, 0, 320, 240,                    0, CYCLE_COUNT - cycles, G_CYC_COPY);
    render_multi_image(segmented_to_virtual(tex1), 0, 0, 320, 240, CYCLE_COUNT - cycles,                    0, G_CYC_COPY);
}

static void render_trans_screen_3(Texture *tex0, Texture *tex1, f32 progressionPercentage) {
    s32 imageOffset = 240.0f * progressionPercentage;

    // Reverse order matters here, else visual jank
    render_multi_image(segmented_to_virtual(tex1), 0, imageOffset - 240, 320, 240, 0, 0, G_CYC_COPY);
    render_multi_image(segmented_to_virtual(tex0), 0,       imageOffset, 320, 240, 0, 0, G_CYC_COPY);
}

static void process_load_screen(void) {
    s32 imageDoubleIndex;
    s32 imageIndex;
    s32 transImageIndex;
    f32 progressionPercentage;

    loadIsTransitioning = FALSE;

    if (loadScreenTimer < 0) {
        // Not loading loading screen
        render_multi_image(segmented_to_virtual(loadScreenImages[0]), 0, 0, 320, 240, 0, 0, G_CYC_COPY);
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
        render_multi_image(segmented_to_virtual(loadScreenImages[imageIndex]), 0, 0, 320, 240, 0, 0, G_CYC_COPY);
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
            render_trans_screen_1(loadScreenImages[imageIndex], loadScreenImages[transImageIndex]);
            break;
        case 2:
            render_trans_screen_2(loadScreenImages[imageIndex], loadScreenImages[transImageIndex], progressionPercentage);
            break;
        case 3:
            render_trans_screen_3(loadScreenImages[imageIndex], loadScreenImages[transImageIndex], progressionPercentage);
            break;
        default:
            break;
    }
}

Gfx *geo_load_screen(s32 state, UNUSED struct GraphNode *node, UNUSED void *context) {
    if (state == GEO_CONTEXT_RENDER) {
        gSPDisplayList(gDisplayListHead++, dl_hud_img_begin);

        process_load_screen();

        gSPDisplayList(gDisplayListHead++, dl_hud_img_end);
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
