#include <PR/ultratypes.h>

#include "config.h"
#include "area.h"
#include "sm64.h"
#include "gfx_dimensions.h"
#include "behavior_data.h"
#include "game_init.h"
#include "object_list_processor.h"
#include "engine/surface_load.h"
#include "ingame_menu.h"
#include "screen_transition.h"
#include "mario.h"
#include "mario_actions_cutscene.h"
#include "print.h"
#include "hud.h"
#include "audio/external.h"
#include "area.h"
#include "rendering_graph_node.h"
#include "level_update.h"
#include "engine/geo_layout.h"
#include "save_file.h"
#include "level_table.h"
#include "dialog_ids.h"
#include "puppyprint.h"
#include "debug_box.h"
#include "engine/colors.h"
#include "profiling.h"
#ifdef S2DEX_TEXT_ENGINE
#include "s2d_engine/init.h"
#endif

f32 loadProgress = -0.02f;
s32 renderLoadScreen = FALSE;
static s32 hasMessedUpLoad = FALSE;
static s32 loadProgressFrameWait = 0;
static s32 dotFrames = 0;

struct SpawnInfo gPlayerSpawnInfos[1];
struct GraphNode *gGraphNodePointers[MODEL_ID_COUNT];
struct Area gAreaData[AREA_COUNT];

struct WarpTransition gWarpTransition;

s16 gCurrCourseNum;
s16 gCurrActNum = 1;
s16 gCurrAreaIndex;
s16 gSavedCourseNum;
s16 gMenuOptSelectIndex;
s16 gSaveOptSelectIndex;

struct SpawnInfo *gMarioSpawnInfo = &gPlayerSpawnInfos[0];
struct GraphNode **gLoadedGraphNodes = gGraphNodePointers;
struct Area *gAreas = gAreaData;
struct Area *gCurrentArea = NULL;
struct CreditsEntry *gCurrCreditsEntry = NULL;

Vp *gViewportOverride = NULL;
Vp *gViewportClip = NULL;
s16 gWarpTransDelay = 0;
RGBA16FILL gFBSetColor = 0;
RGBA16FILL gWarpTransFBSetColor = 0;
Color gWarpTransRed= 0;
Color gWarpTransGreen = 0;
Color gWarpTransBlue = 0;
s16 gCurrSaveFileNum = 1;
s16 gCurrLevelNum = LEVEL_MIN;

/*
 * The following two tables are used in get_mario_spawn_type() to determine spawn type
 * from warp behavior.
 * When looping through sWarpBhvSpawnTable, if the behavior function in the table matches
 * the spawn behavior executed, the index of that behavior is used with sSpawnTypeFromWarpBhv
*/

const BehaviorScript *sWarpBhvSpawnTable[] = {
    bhvDoorWarp,                bhvStar,                   bhvExitPodiumWarp,          bhvWarp,
    bhvWarpPipe,                bhvFadingWarp,             bhvInstantActiveWarp,       bhvAirborneWarp,
    bhvHardAirKnockBackWarp,    bhvSpinAirborneCircleWarp, bhvDeathWarp,               bhvSpinAirborneWarp,
    bhvFlyingWarp,              bhvSwimmingWarp,           bhvPaintingStarCollectWarp, bhvPaintingDeathWarp,
    bhvAirborneStarCollectWarp, bhvAirborneDeathWarp,      bhvLaunchStarCollectWarp,   bhvLaunchDeathWarp,
    bhvCheckpointWarp,
};

u8 sSpawnTypeFromWarpBhv[] = {
    MARIO_SPAWN_DOOR_WARP,             MARIO_SPAWN_IDLE,                 MARIO_SPAWN_PIPE,                  MARIO_SPAWN_PIPE,
    MARIO_SPAWN_PIPE,                  MARIO_SPAWN_TELEPORT,             MARIO_SPAWN_INSTANT_ACTIVE,        MARIO_SPAWN_AIRBORNE,
    MARIO_SPAWN_HARD_AIR_KNOCKBACK,    MARIO_SPAWN_SPIN_AIRBORNE_CIRCLE, MARIO_SPAWN_DEATH,                 MARIO_SPAWN_SPIN_AIRBORNE,
    MARIO_SPAWN_FLYING,                MARIO_SPAWN_SWIMMING,             MARIO_SPAWN_PAINTING_STAR_COLLECT, MARIO_SPAWN_PAINTING_DEATH,
    MARIO_SPAWN_AIRBORNE_STAR_COLLECT, MARIO_SPAWN_AIRBORNE_DEATH,       MARIO_SPAWN_LAUNCH_STAR_COLLECT,   MARIO_SPAWN_LAUNCH_DEATH,
    MARIO_SPAWN_CHECKPOINT_WARP,
};

Vp gViewport = { {
    { 640, 480, 511, 0 },
    { 640, 480, 511, 0 },
} };

Vp gShitViewport = { {
    { 64, 48, 511, 0 },
    { 64, 48, 511, 0 },
} };


#if MULTILANG
const char *gNoControllerMsg[] = {
    "NO CONTROLLER",
    "MANETTE DEBRANCHEE",
    "CONTROLLER FEHLT",
};
#endif

void override_viewport_and_clip(Vp *vpOverride, Vp *vpClip, Color red, Color green, Color blue) {
    RGBA16 color = ((red >> 3) << IDX_RGBA16_R) | ((green >> 3) << IDX_RGBA16_G) | ((blue >> 3) << IDX_RGBA16_B) | MSK_RGBA16_A;

    gFBSetColor = (color << 16) | color;
    gViewportOverride = vpOverride;
    gViewportClip = vpClip;
}

void set_warp_transition_rgb(Color red, Color green, Color blue) {
    RGBA16 warpTransitionRGBA16 = ((red >> 3) << IDX_RGBA16_R) | ((green >> 3) << IDX_RGBA16_G) | ((blue >> 3) << IDX_RGBA16_B) | MSK_RGBA16_A;

    gWarpTransFBSetColor = (warpTransitionRGBA16 << 16) | warpTransitionRGBA16;
    gWarpTransRed = red;
    gWarpTransGreen = green;
    gWarpTransBlue = blue;
}

void print_intro_text(void) {
#if MULTILANG
    s32 language = eu_get_language();
#endif
    if ((gGlobalTimer & 31) < 20) {
        if (gControllerBits == 0) {
#if MULTILANG
            print_text_centered(SCREEN_CENTER_X, 20, gNoControllerMsg[language]);
#else
            print_text_centered(SCREEN_CENTER_X, 20, "NO CONTROLLER");
#endif
        } else {
#ifdef VERSION_EU
            print_text(20, 20, "START");
#else
            print_text_centered(60, 38, "PRESS");
            print_text_centered(60, 20, "START");
#endif
        }
    }
}

u32 get_mario_spawn_type(struct Object *obj) {
    s32 i;
    const BehaviorScript *behavior = virtual_to_segmented(SEGMENT_BEHAVIOR_DATA, obj->behavior);

    for (i = 0; i < ARRAY_COUNT(sWarpBhvSpawnTable); i++) {
        if (sWarpBhvSpawnTable[i] == behavior) {
            return sSpawnTypeFromWarpBhv[i];
        }
    }
    return MARIO_SPAWN_NONE;
}

struct ObjectWarpNode *area_get_warp_node(u8 id) {
    struct ObjectWarpNode *node = NULL;

    for (node = gCurrentArea->warpNodes; node != NULL; node = node->next) {
        if (node->node.id == id) {
            break;
        }
    }
    return node;
}

struct ObjectWarpNode *area_get_warp_node_from_params(struct Object *obj) {
    return area_get_warp_node(GET_BPARAM2(obj->oBehParams));
}

void load_obj_warp_nodes(void) {
    struct ObjectWarpNode *warpNode;
    struct Object *children = (struct Object *) gObjParentGraphNode.children;

    do {
        struct Object *obj = children;

        if (obj->activeFlags != ACTIVE_FLAG_DEACTIVATED && get_mario_spawn_type(obj) != 0) {
            warpNode = area_get_warp_node_from_params(obj);
            if (warpNode != NULL) {
                warpNode->object = obj;
            }
        }
    } while ((children = (struct Object *) children->header.gfx.node.next)
             != (struct Object *) gObjParentGraphNode.children);
}

void clear_areas(void) {
    s32 i, j;

    gCurrentArea = NULL;
    gWarpTransition.isActive = FALSE;
    gWarpTransition.pauseRendering = FALSE;
    gMarioSpawnInfo->areaIndex = -1;

    for (i = 0; i < AREA_COUNT; i++) {
        gAreaData[i].index = i;
        gAreaData[i].flags = AREA_FLAG_UNLOAD;
        gAreaData[i].terrainType = TERRAIN_GRASS;
        gAreaData[i].graphNode = NULL;
        gAreaData[i].terrainData = NULL;
        gAreaData[i].surfaceRooms = NULL;
        gAreaData[i].macroObjects = NULL;
        gAreaData[i].warpNodes = NULL;
        gAreaData[i].paintingWarpNodes = NULL;
        gAreaData[i].instantWarps = NULL;
        gAreaData[i].objectSpawnInfos = NULL;
        gAreaData[i].camera = NULL;
        gAreaData[i].unused = NULL;
        for (j = 0; j < ARRAY_COUNT(gAreaData[i].whirlpools); j++) {
            gAreaData[i].whirlpools[j] = NULL;
        }
        gAreaData[i].dialog[0] = DIALOG_NONE;
        gAreaData[i].dialog[1] = DIALOG_NONE;
        gAreaData[i].musicParam = 0;
        gAreaData[i].musicParam2 = 0;
        gAreaData[i].useEchoOverride = FALSE;
        gAreaData[i].echoOverride = 0;
#ifdef BETTER_REVERB
        gAreaData[i].betterReverbPreset = 0;
#endif
    }
}

void clear_area_graph_nodes(void) {
    s32 i;

    if (gCurrentArea != NULL) {
        geo_call_global_function_nodes(&gCurrentArea->graphNode->node, GEO_CONTEXT_AREA_UNLOAD);
        gCurrentArea = NULL;
        gWarpTransition.isActive = FALSE;
    }

    for (i = 0; i < AREA_COUNT; i++) {
        if (gAreaData[i].graphNode != NULL) {
            geo_call_global_function_nodes(&gAreaData[i].graphNode->node, GEO_CONTEXT_AREA_INIT);
            gAreaData[i].graphNode = NULL;
        }
    }
}

void load_area(s32 index) {
    if (gCurrentArea == NULL && gAreaData[index].graphNode != NULL) {
        gCurrentArea = &gAreaData[index];
        gCurrAreaIndex = gCurrentArea->index;
        main_pool_pop_state();
        main_pool_push_state();

        gMarioCurrentRoom = 0;

        if (gCurrentArea->terrainData != NULL) {
            load_area_terrain(index, gCurrentArea->terrainData, gCurrentArea->surfaceRooms,
                              gCurrentArea->macroObjects);
        }

        if (gCurrentArea->objectSpawnInfos != NULL) {
            spawn_objects_from_info(0, gCurrentArea->objectSpawnInfos);
        }

        load_obj_warp_nodes();
        geo_call_global_function_nodes(&gCurrentArea->graphNode->node, GEO_CONTEXT_AREA_LOAD);
    }
}

void unload_area(void) {
    if (gCurrentArea != NULL) {
        unload_objects_from_area(0, gCurrentArea->index);
        geo_call_global_function_nodes(&gCurrentArea->graphNode->node, GEO_CONTEXT_AREA_UNLOAD);

        gCurrentArea->flags = AREA_FLAG_UNLOAD;
        gCurrentArea = NULL;
        gWarpTransition.isActive = FALSE;
    }
}

void load_mario_area(void) {
    stop_sounds_in_continuous_banks();
    load_area(gMarioSpawnInfo->areaIndex);

    if (gCurrentArea->index == gMarioSpawnInfo->areaIndex) {
        gCurrentArea->flags |= AREA_FLAG_LOAD;
        spawn_objects_from_info(0, gMarioSpawnInfo);
    }

    if (gAreaSkyboxStart[gCurrAreaIndex - 1]) {
        load_segment_decompress(SEGMENT_SKYBOX, gAreaSkyboxStart[gCurrAreaIndex - 1], gAreaSkyboxEnd[gCurrAreaIndex - 1]);
    }
}

void unload_mario_area(void) {
    if ((gCurrentArea != NULL) && (gCurrentArea->flags & AREA_FLAG_LOAD)) {
        unload_objects_from_area(0, gMarioSpawnInfo->activeAreaIndex);

        gCurrentArea->flags &= ~AREA_FLAG_LOAD;
        if (gCurrentArea->flags == AREA_FLAG_UNLOAD) {
            unload_area();
        }
    }
}

void change_area(s32 index) {
    s32 areaFlags = gCurrentArea->flags;

    if (gCurrAreaIndex != index) {
        unload_area();
        load_area(index);

        gCurrentArea->flags = areaFlags;
        gMarioObject->oActiveParticleFlags = ACTIVE_PARTICLE_NONE;
    }

    if (areaFlags & AREA_FLAG_LOAD) {
        gMarioObject->header.gfx.areaIndex = index, gMarioSpawnInfo->areaIndex = index;
    }
}

void area_update_objects(void) {
    gAreaUpdateCounter++;
    update_objects(0);
}

/*
 * Sets up the information needed to play a warp transition, including the
 * transition type, time in frames, and the RGB color that will fill the screen.
 */
void play_transition(s16 transType, s16 time, Color red, Color green, Color blue) {
#ifndef L3DEX2_ALONE
    gWarpTransition.isActive = TRUE;
    gWarpTransition.type = transType;
    gWarpTransition.time = time;
    gWarpTransition.pauseRendering = FALSE;

    // The lowest bit of transType determines if the transition is fading in or out.
    if (transType & WARP_TRANSITION_FADE_INTO) {
        set_warp_transition_rgb(red, green, blue);
    } else {
        red = gWarpTransRed, green = gWarpTransGreen, blue = gWarpTransBlue;
    }

    if (transType < WARP_TRANSITION_TYPE_STAR) { // if transition is WARP_TRANSITION_TYPE_COLOR
        gWarpTransition.data.red = red;
        gWarpTransition.data.green = green;
        gWarpTransition.data.blue = blue;
    } else { // if transition is textured
        gWarpTransition.data.red = red;
        gWarpTransition.data.green = green;
        gWarpTransition.data.blue = blue;

        // Both the start and end textured transition are always located in the middle of the screen.
        // If you really wanted to, you could place the start at one corner and the end at
        // the opposite corner. This will make the transition image look like it is moving
        // across the screen.
        gWarpTransition.data.startTexX = SCREEN_CENTER_X;
        gWarpTransition.data.startTexY = SCREEN_CENTER_Y;
        gWarpTransition.data.endTexX = SCREEN_CENTER_X;
        gWarpTransition.data.endTexY = SCREEN_CENTER_Y;

        gWarpTransition.data.texTimer = 0;

        if (transType & WARP_TRANSITION_FADE_INTO) { // Is the image fading in?
            gWarpTransition.data.startTexRadius = GFX_DIMENSIONS_FULL_RADIUS;
            if (transType >= WARP_TRANSITION_FADES_INTO_LARGE) {
                gWarpTransition.data.endTexRadius = 16;
            } else {
                gWarpTransition.data.endTexRadius = 0;
            }
        } else { // The image is fading out. (Reverses start & end circles)
            if (transType >= WARP_TRANSITION_FADES_FROM_LARGE) {
                gWarpTransition.data.startTexRadius = 16;
            } else {
                gWarpTransition.data.startTexRadius = 0;
            }
            gWarpTransition.data.endTexRadius = GFX_DIMENSIONS_FULL_RADIUS;
        }
    }
#endif
}

/*
 * Sets up the information needed to play a warp transition, including the
 * transition type, time in frames, and the RGB color that will fill the screen.
 * The transition will play only after a number of frames specified by 'delay'
 */
void play_transition_after_delay(s16 transType, s16 time, u8 red, u8 green, u8 blue, s16 delay) {
    gWarpTransDelay = delay; // Number of frames to delay playing the transition.
    play_transition(transType, time, red, green, blue);
}

static const char puppyprintStr0[] = "CLEARING MEMORY POOLS...";
static const char puppyprintStr1[] = "LOADING ASSETS...";
static const char puppyprintStr2[] = "CONFIGURING LEVEL SETTINGS...";
static const char puppyprintStr3[] = "PLACING OBJECTS...";
static const char puppyprintStr4[] = "MESSED SOMETHING UP, TRYING AGAIN!";
static const char puppyprintStr5[] = "CONFIGURING SETTINGS, ATTEMPT 2...";
static const char puppyprintStr6[] = "WAITING ON AUDIO DMA...";
static const char puppyprintStr7[] = "RENDERING LEVEL...";
static const char puppyprintStr8[] = "LOAD COMPLETE!";

s32 adjust_load_progress_bar(void) {
    const s32 posX = 15;
    const s32 posY = 189;

    s32 dotCount;

    if (loadProgress >= 0.0f) {
        if (dotFrames < 5.0f || dotFrames >= 27.0f)
            dotCount = -3;
        else if (dotFrames < 8.0f || dotFrames >= 24.0f)
            dotCount = -2;
        else if (dotFrames < 11.0f || dotFrames >= 21.0f)
            dotCount = -1;
        else
            dotCount = 0;

        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
        print_small_text(SCREEN_CENTER_X, 16, "LOADING COURSE", PRINT_TEXT_ALIGN_CENTRE, PRINT_ALL, FONT_OUTLINE);

        dotFrames = (dotFrames + 1) % 32;

        if (loadProgress < 0.15f && hasMessedUpLoad == FALSE) {
            f32 f1 = random_float();
            f32 f2 = random_float();
            loadProgress += MIN(f1, f2) / 400.0f;
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
            print_small_text(posX, posY, puppyprintStr0, PRINT_TEXT_ALIGN_LEFT, sizeof(puppyprintStr0) + dotCount - 1, FONT_OUTLINE);
            return TRUE;
        }
        if (loadProgress < 0.33f && hasMessedUpLoad == FALSE) {
            if (random_u16() % 8 == 0)
                loadProgress += 0.01f;
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
            print_small_text(posX, posY, puppyprintStr1, PRINT_TEXT_ALIGN_LEFT, sizeof(puppyprintStr1) + dotCount - 1, FONT_OUTLINE);
            return TRUE;
        }
        if (loadProgress < 0.5f && hasMessedUpLoad != 2) {
            f32 f1 = random_float();
            f32 f2 = random_float();
            loadProgress += MIN(f1, f2) / 120.0f;
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
            if (hasMessedUpLoad)
                print_small_text(posX, posY, puppyprintStr5, PRINT_TEXT_ALIGN_LEFT, sizeof(puppyprintStr5) + dotCount - 1, FONT_OUTLINE);
            else
                print_small_text(posX, posY, puppyprintStr2, PRINT_TEXT_ALIGN_LEFT, sizeof(puppyprintStr2) + dotCount - 1, FONT_OUTLINE);
            if (loadProgress >= 0.5f) {
                if (hasMessedUpLoad == FALSE)
                    loadProgressFrameWait = 55;
                else
                    loadProgressFrameWait = 25;
            }
            return TRUE;
        }
        if ((loadProgress < 0.75f || loadProgressFrameWait > 0) && hasMessedUpLoad == FALSE) {
            if (loadProgressFrameWait > 0) {
                loadProgressFrameWait--;
            }
            else {
                f32 f1 = random_float();
                f32 f2 = random_float();
                f1 *= f1;
                f2 *= f2;
                loadProgress += MAX(f1, f2) / 75.0f;
                if (loadProgress >= 0.751f) 
                    loadProgress = 0.751f;
                if (loadProgress >= 0.75f)
                    loadProgressFrameWait = 45;
            }
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
            print_small_text(posX, posY, puppyprintStr3, PRINT_TEXT_ALIGN_LEFT, sizeof(puppyprintStr3) + dotCount - 1, FONT_OUTLINE);
            return TRUE;
        }
        if (loadProgress < 0.75f && hasMessedUpLoad == TRUE) {
            if (loadProgressFrameWait > 0) {
                loadProgressFrameWait--;
            }
            else {
                f32 f1 = random_float();
                f32 f2 = random_float();
                f1 *= f1;
                f2 *= f2;
                loadProgress += MAX(f1, f2) / 75.0f;
                if (loadProgress >= 0.751f) 
                    loadProgress = 0.751f;
            }
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
            print_small_text(posX, posY, puppyprintStr3, PRINT_TEXT_ALIGN_LEFT, sizeof(puppyprintStr3) + dotCount - 1, FONT_OUTLINE);
            return TRUE;
        }
        if ((loadProgress >= 0.75f && hasMessedUpLoad == FALSE) || hasMessedUpLoad == 2) {
            hasMessedUpLoad = 2;
            if (loadProgressFrameWait > 0) {
                loadProgressFrameWait--;
                if (loadProgressFrameWait == 0) {
                    hasMessedUpLoad = TRUE;
                    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
                    print_small_text(posX, posY, puppyprintStr5, PRINT_TEXT_ALIGN_LEFT, sizeof(puppyprintStr5) + dotCount - 1, FONT_OUTLINE);
                    return TRUE;
                }
            }
            else {
                loadProgress -= 0.0045f;
            }
            if (hasMessedUpLoad == 2) {
                gDPSetEnvColor(gDisplayListHead++, 255, 127, 127, 255);
            } else {
                gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
            }
            print_small_text(posX, posY, puppyprintStr4, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_OUTLINE);
            if (loadProgress < 0.33f && hasMessedUpLoad == 2 && loadProgressFrameWait <= 0)
                loadProgressFrameWait = 12;
            return TRUE;
        }
        if (loadProgress < 0.925f) {
            loadProgress += 0.015f;
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
            print_small_text(posX, posY, puppyprintStr6, PRINT_TEXT_ALIGN_LEFT, sizeof(puppyprintStr6) + dotCount - 1, FONT_OUTLINE);
            return TRUE;
        }
        if (loadProgress < 0.999f) {
            f32 f1 = random_float();
            f32 f2 = random_float();
            loadProgress += MIN(f1, f2) / 650.0f;
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
            print_small_text(posX, posY, puppyprintStr7, PRINT_TEXT_ALIGN_LEFT, sizeof(puppyprintStr7) + dotCount - 1, FONT_OUTLINE);
            if (loadProgress >= 0.999f) {
                loadProgress = 0.9991f;
                loadProgressFrameWait = 90;
            }
            return TRUE;
        }
        if (loadProgress < 1.0f) {
            if (loadProgressFrameWait > 0) {
                loadProgressFrameWait--;
            } else {
                loadProgress = 1.0005f;
            }
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
            print_small_text(posX, posY, puppyprintStr7, PRINT_TEXT_ALIGN_LEFT, sizeof(puppyprintStr7) + dotCount - 1, FONT_OUTLINE);
            return TRUE;
        }
    } else {
        loadProgress += 0.001f;
        return FALSE;
    }

    loadProgress += 0.001f;
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    print_small_text(posX, posY, puppyprintStr8, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_OUTLINE);
    return TRUE;
}

void render_loading_screen(void) {
    const s32 percX = 305;
    const s32 percY = 189;

    const s32 curX = 16;
    const s32 curY = 204;
    const s32 height = 14;
    const s32 thickness = 1;
    char percent[8];

    s32 color = 0xFFFFFFFF;
    s32 progressX = curX + ((SCREEN_WIDTH - (curX * 2)) * loadProgress);

    s32 sLoadProgress = (loadProgress * 100.0f);
    if (sLoadProgress > 100)
        sLoadProgress = 100;
    else if (sLoadProgress < 0)
        sLoadProgress = 0;

    sprintf(percent, "%d%%", sLoadProgress);

    if (hasMessedUpLoad == 2) {
        gDPSetEnvColor(gDisplayListHead++, 255, 191, 191, 255);
        print_small_text(percX, percY, percent, PRINT_TEXT_ALIGN_RIGHT, PRINT_ALL, FONT_OUTLINE);
        gDPSetEnvColor(gDisplayListHead++, 255, 191, 191, 255);
        color = 0xFDF7FDF7;
    } else {
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
        print_small_text(percX, percY, percent, PRINT_TEXT_ALIGN_RIGHT, PRINT_ALL, FONT_OUTLINE);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
    }

    gDPSetCycleType( gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP);

    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, color);
    gDPFillRectangle(gDisplayListHead++, curX - thickness * 2, curY - thickness * 2,
                    SCREEN_WIDTH - curX + thickness * 2 - 1, curY - thickness - 1);

    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, color);
    gDPFillRectangle(gDisplayListHead++, curX - thickness * 2, curY - thickness * 2,
                    curX - thickness - 1, curY + height + thickness * 2 - 1);

    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, color);
    gDPFillRectangle(gDisplayListHead++, curX - thickness * 2, curY + height + thickness,
                    SCREEN_WIDTH - curX + thickness * 2 - 1, curY + height + thickness * 2 - 1);

    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, color);
    gDPFillRectangle(gDisplayListHead++, SCREEN_WIDTH - curX + thickness, curY - thickness * 2,
                    SCREEN_WIDTH - curX + thickness * 2 - 1, curY + height + thickness * 2 - 1);

    // Progress Bar
    if (progressX <= curX)
        return;
    if (loadProgress >= 1.0f)
        progressX = SCREEN_WIDTH - curX;

    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, color);
    gDPFillRectangle(gDisplayListHead++, curX, curY, progressX - 1, curY + height - 1);
}

void render_game(void) {
    PROFILER_GET_SNAPSHOT_TYPE(PROFILER_DELTA_COLLISION);
    if (gCurrentArea != NULL && !gWarpTransition.pauseRendering) {
        switch (gCurrLevelNum) {
            case SMG23IH2_LEVEL_3:
                gSPClipRatio(gDisplayListHead++, FRUSTRATIO_6);
                break;
            default:
                gSPClipRatio(gDisplayListHead++, FRUSTRATIO_2);
                break;
        }

        if (gBetterMarioCam && gCurrLevelNum == SMG23IH2_LEVEL_1) {
            gShitViewport.vp.vscale[0] = 48;
            gShitViewport.vp.vscale[1] = 32;
            gShitViewport.vp.vtrans[0] = SCREEN_WIDTH  * 2;
            gShitViewport.vp.vtrans[1] = SCREEN_HEIGHT * 2;
            override_viewport_and_clip(NULL, &gShitViewport, 0, 0, 0);
        }

        if (gCurrentArea->graphNode) {
            geo_process_root(gCurrentArea->graphNode, gViewportOverride, gViewportClip, gFBSetColor);
        }
#ifdef PUPPYPRINT
        bzero(gCurrEnvCol, sizeof(ColorRGBA));
#endif

        gSPViewport(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(&gViewport));

        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, gBorderHeight, SCREEN_WIDTH,
                      SCREEN_HEIGHT - gBorderHeight);
        render_hud();

        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        render_text_labels();
#ifdef PUPPYPRINT
        puppyprint_print_deferred();
#endif
        do_cutscene_handler();
        print_displaying_credits_entry();
        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, gBorderHeight, SCREEN_WIDTH,
                      SCREEN_HEIGHT - gBorderHeight);
        gMenuOptSelectIndex = render_menus_and_dialogs();

        if (gMenuOptSelectIndex != 0) {
            gSaveOptSelectIndex = gMenuOptSelectIndex;
        }

        if (gViewportClip != NULL) {
            make_viewport_clip_rect(gViewportClip);
        } else
            gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, gBorderHeight, SCREEN_WIDTH,
                          SCREEN_HEIGHT - gBorderHeight);

        if (gWarpTransition.isActive) {
            if (gWarpTransDelay == 0) {
                gWarpTransition.isActive = !render_screen_transition(0, gWarpTransition.type, gWarpTransition.time,
                                                                     &gWarpTransition.data);
                if (!gWarpTransition.isActive) {
                    if (gWarpTransition.type & WARP_TRANSITION_FADE_INTO) {
                        gWarpTransition.pauseRendering = TRUE;
                    } else {
                        set_warp_transition_rgb(0, 0, 0);
                    }
                }
            } else {
                gWarpTransDelay--;
            }
        }
#ifdef S2DEX_TEXT_ENGINE
        s2d_init();

        // place any custom text engine code here if not using deferred prints

        s2d_handle_deferred();
        s2d_stop();
#endif
    } else {
        render_text_labels();
#ifdef PUPPYPRINT
        puppyprint_print_deferred();
#endif
        if (gViewportClip != NULL) {
            clear_viewport(gViewportClip, gWarpTransFBSetColor);
        } else {
            clear_framebuffer(gWarpTransFBSetColor);
        }
    }

    gViewportOverride = NULL;
    gViewportClip     = NULL;


    if (renderLoadScreen) {
        if (adjust_load_progress_bar())
            render_loading_screen();
    } else {
        hasMessedUpLoad = FALSE;
        loadProgress = -0.02f;
        dotFrames = 0;
    }

    profiler_update(PROFILER_TIME_GFX, profiler_get_delta(PROFILER_DELTA_COLLISION) - first);
    profiler_print_times();
#ifdef PUPPYPRINT_DEBUG
    puppyprint_render_profiler();
#endif
}
