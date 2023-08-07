// BKTN_DIAs.inc.c

#include "blockington.h"

// Drive out of bounds
struct BlockingtonMiniDialog bMiniDiaOOB[] = {
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_OOB, .dialogStr = "Hey wait! Where do you think you're\ngoing? Stop tryin'a cheeeese!!\n:("},
};

// Coin 00: Coin on ground right at starting exit
struct BlockingtonMiniDialog bMiniDiaCoin00[] = {
    {.lineCount = 4, .soundID = SOUND_BLOCKINGTON_COIN_00, .dialogStr = "You got an artifact!\nWow good job yeah I'm not gonna\nlike keep bothering you or something\nfor awhile totally not haha lmao."},
};

// Coin 01: Coin on ground furthest from bridge

// Coin 02: Coin on low ramp jump
struct BlockingtonMiniDialog bMiniDiaCoin02[] = {
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_COIN_02, .dialogStr = "Wheeeeeeeehehee!!\n\n:)"},
};

// Coin 03: Coin on ground ramp
struct BlockingtonMiniDialog bMiniDiaCoin03[] = {
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_COIN_03, .dialogStr = "Ramp."},
};

// Coin 04: Coin on ground closest to bridge
// Coin 05: Coin approaching top of spiral section

// Coin 06: Coin at top of spiral section
struct BlockingtonMiniDialog bMiniDiaCoin06[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_COIN_06, .dialogStr = "Ohoho, spirals for days!\nYou must be dizzy!"},
};

// Coin 07: Coin on top of high block (need to launch from coin 11 to reach)
struct BlockingtonMiniDialog bMiniDiaCoin07[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_COIN_07, .dialogStr = "Unblockevable aim! That artifact must\nhave been challenging to reach!"},
};

// Coin 08: Coin on top of brown square
// Coin 09: Coin underneath top of brown square on ramp

// Coin 10: Coin on block in middle of brown square on block
struct BlockingtonMiniDialog bMiniDiaCoin10[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_COIN_10, .dialogStr = "Blocktacular! I cannot believe\nyou retrieved that artifact!"},
};

// Coin 11: Coin at top of highest ramp

// Coin 12: Coin at end of (reasonable) precision ramp section
struct BlockingtonMiniDialog bMiniDiaCoin12Normal[] = {
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_COIN_12_NORMAL, .dialogStr = "Wow, that was squariously impressive!"},
};
struct BlockingtonMiniDialog bMiniDiaCoin12Pity[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_COIN_12_PITY, .dialogStr = "SMH imagine having needed help with\nTHIS section, blocko."},
};

// Coin 13: Coin at top of (reasonable) precision ramp section
struct BlockingtonMiniDialog bMiniDiaCoin13[] = {
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_COIN_13, .dialogStr = "Oh my block, this section is precise!"},
};

// Coin 14-19: Jackpot coins
struct BlockingtonMiniDialog bMiniDiaCoinJackpot[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_COIN_JACKPOT, .dialogStr = "Blocktastic! You won the artifact\nlottery!"},
};

// Coin 20: Coin on ramp closest to first bridge
// Coin 21: Coin on ramp furthest to first bridge
// Coin 22: Coin closest to second bridge

// Coin 23: Coin on ramp closest to first bridge
struct BlockingtonMiniDialog bMiniDiaCoin23[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_COIN_23, .dialogStr = "Ooh, now that jump was quite the\nsight to blockhold!"},
};


// Cutscene Pity Bridge
struct BlockingtonMiniDialog bMiniDiaPityBridge[] = {
    {.lineCount = 4, .soundID = SOUND_BLOCKINGTON_PITY_BRIDGE, .dialogStr = "You're telling me you can't get\nto that artifact? Okay fine, since\nyou're so pathetic, I'll build a bridge\nfor you!"},
};

// Cringe Path 0
struct BlockingtonMiniDialog bMiniDiaCringePath0[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_CRINGE_PATH_0, .dialogStr = "Uhh...you know, I get the feeling\nthis path is a big waste of your time..."},
};

// Cringe Path 1
struct BlockingtonMiniDialog bMiniDiaCringePath1[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_CRINGE_PATH_1_0, .dialogStr = "Bruh. Don't you have better things\nto do?"},
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_CRINGE_PATH_1_1, .dialogStr = "You know, like saving Blocktaria??"},
};

// Cringe Path 2
struct BlockingtonMiniDialog bMiniDiaCringePath2[] = {
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_CRINGE_PATH_2, .dialogStr = "You're a real piece of work, kid.\nThis next section seems imblockssible\nanyway!"},
};

// Cringe Path Collect
struct BlockingtonMiniDialog bMiniDiaCringePathCollect[] = {
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_CRINGE_PATH_COLLECT, .dialogStr = "Get rekt nerd, LMAOOOOOOOO!"},
};


// Cutscene Mario
struct BlockingtonMiniDialog bMiniDiaCSMario[] = {
    {.lineCount = 4, .soundID = SOUND_BLOCKINGTON_CS_MARIO_0, .dialogStr = "H-hey there, who the hell are you?\nYou don't seem very...blocky to me.\nI'm afraid I'm not allowed to let you into this\nplace."},
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_CS_MARIO_1, .dialogStr = "Now, with all due respect, would you please\nkindly get the hell out of here!"},
};

// Cutscene Car 
struct BlockingtonMiniDialog bMiniDiaCSCar[] = {
    {.lineCount = 4, .soundID = SOUND_BLOCKINGTON_CS_CAR_0, .dialogStr = "Hmm, you look interesting. You don't exactly meet\nthe block standards but...ehhh, you're close\nenough."}, // NOTE: line count set to 4 for Blakeoramo meme
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_CS_CAR_1, .dialogStr = "Blocktaria is in too much trouble to nitpick at\nthe highest detail! We need someone to save us!"},
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_CS_CAR_2, .dialogStr = "Alright, I shall let you pass.\nYou had better respect your privilege of making\nit though here, stranger!"},
};

// Cutscene First Area
struct BlockingtonMiniDialog bMiniDiaCSFirstArea[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_CS_FIRST_AREA_0, .dialogStr = "Now, we have something of a critical problem\nhere."},
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_CS_FIRST_AREA_1, .dialogStr = "You see that over there?\nSome MOTHERBLOCKER thought it would be\nfunny to destroy Blocktaria's block bridges!"},
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_CS_FIRST_AREA_2, .dialogStr = "Oh, <SHAKE>HOW<SHAKE> am I supposed to get over there now?\nWe need somebody to rescue all of the artifacts\nin order to reconstruct this bridge!"},
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_CS_FIRST_AREA_3, .dialogStr = "This is where you come in.\nPlease collect the artifacts so that I can visit\nthat area again!"},
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_CS_FIRST_AREA_4, .dialogStr = "In the meantime, I'll be waiting for you over\nthere on the other side. Now get to work!"},
};

// Cutscene Second Area
struct BlockingtonMiniDialog bMiniDiaCSSecondArea[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_CS_SECOND_AREA_0, .dialogStr = "Oh no, what am I going to do?\nMy favorite island is unreachable!"},
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_CS_SECOND_AREA_1, .dialogStr = "Can you help me rebuild this bridge too?\nPLEEEEASE?\n:("},
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_CS_SECOND_AREA_2, .dialogStr = "I'll be waiting for you on my favorite island.\nDon't keep me waiting!"},
};

// Cutscene Final 0
struct BlockingtonMiniDialog bMiniDiaCSFinal0[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_CS_FINAL_0_0, .dialogStr = "INCREDIBLOCK, YOU DID IT!!!\nYOU SAVED BLOCKTARIA!"},
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_CS_FINAL_0_1, .dialogStr = "You were able to restore peace to our world!"},
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_CS_FINAL_0_2, .dialogStr = "Please, be my friend forever, hero!\nI could tell stories about you for centuries\nto come!"},
};

// Cutscene Final 1
struct BlockingtonMiniDialog bMiniDiaCSFinal1[] = {
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_CS_FINAL_1_0, .dialogStr = "W-WAIT A MINUTE!"},
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_CS_FINAL_1_1, .dialogStr = "...So it was YOU!"},
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_CS_FINAL_1_2, .dialogStr = "I thought I made myself clear that you are not\npermitted entry to this world!"},
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_CS_FINAL_1_3, .dialogStr = "I SHALL BANISH YOU TO THE CIRCLE REALM!\nDO YOU REALIZE WHAT YOU'VE DONE!?"},
};

// Cutscene Final Death
struct BlockingtonMiniDialog bMiniDiaCSFinalDeath[] = {
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_CS_DEATH_2, .dialogStr = "...I'll see y-you in hell...BLOCKAROOOO..."},
};


struct BlockingtonMiniDialogEntries bMiniDialogs[] = {
    [BKTN_DIA_OOB]                 = {.startAddr = bMiniDiaOOB,               .dialogCount = ARRAY_COUNT(bMiniDiaOOB),               .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_COIN_00]             = {.startAddr = bMiniDiaCoin00,            .dialogCount = ARRAY_COUNT(bMiniDiaCoin00),            .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE}, // unused
    [BKTN_DIA_COIN_02]             = {.startAddr = bMiniDiaCoin02,            .dialogCount = ARRAY_COUNT(bMiniDiaCoin02),            .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_COIN_03]             = {.startAddr = bMiniDiaCoin03,            .dialogCount = ARRAY_COUNT(bMiniDiaCoin03),            .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_COIN_06]             = {.startAddr = bMiniDiaCoin06,            .dialogCount = ARRAY_COUNT(bMiniDiaCoin06),            .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_COIN_07]             = {.startAddr = bMiniDiaCoin07,            .dialogCount = ARRAY_COUNT(bMiniDiaCoin07),            .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_COIN_10]             = {.startAddr = bMiniDiaCoin10,            .dialogCount = ARRAY_COUNT(bMiniDiaCoin10),            .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_COIN_12_NORMAL]      = {.startAddr = bMiniDiaCoin12Normal,      .dialogCount = ARRAY_COUNT(bMiniDiaCoin12Normal),      .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_COIN_12_PITY]        = {.startAddr = bMiniDiaCoin12Pity,        .dialogCount = ARRAY_COUNT(bMiniDiaCoin12Pity),        .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_COIN_13]             = {.startAddr = bMiniDiaCoin13,            .dialogCount = ARRAY_COUNT(bMiniDiaCoin13),            .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_COIN_JACKPOT]        = {.startAddr = bMiniDiaCoinJackpot,       .dialogCount = ARRAY_COUNT(bMiniDiaCoinJackpot),       .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_COIN_23]             = {.startAddr = bMiniDiaCoin23,            .dialogCount = ARRAY_COUNT(bMiniDiaCoin23),            .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_PITY_BRIDGE]         = {.startAddr = bMiniDiaPityBridge,        .dialogCount = ARRAY_COUNT(bMiniDiaPityBridge),        .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_CRINGE_PATH_0]       = {.startAddr = bMiniDiaCringePath0,       .dialogCount = ARRAY_COUNT(bMiniDiaCringePath0),       .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_CRINGE_PATH_1]       = {.startAddr = bMiniDiaCringePath1,       .dialogCount = ARRAY_COUNT(bMiniDiaCringePath1),       .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_CRINGE_PATH_2]       = {.startAddr = bMiniDiaCringePath2,       .dialogCount = ARRAY_COUNT(bMiniDiaCringePath2),       .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_CRINGE_PATH_COLLECT] = {.startAddr = bMiniDiaCringePathCollect, .dialogCount = ARRAY_COUNT(bMiniDiaCringePathCollect), .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_CS_MARIO]            = {.startAddr = bMiniDiaCSMario,           .dialogCount = ARRAY_COUNT(bMiniDiaCSMario),           .shouldRender = FALSE, .allowRepeat = TRUE,  .hasSpawned = FALSE},
    [BKTN_DIA_CS_CAR]              = {.startAddr = bMiniDiaCSCar,             .dialogCount = ARRAY_COUNT(bMiniDiaCSCar),             .shouldRender = FALSE, .allowRepeat = TRUE,  .hasSpawned = FALSE},
    [BKTN_DIA_CS_FIRST_AREA]       = {.startAddr = bMiniDiaCSFirstArea,       .dialogCount = ARRAY_COUNT(bMiniDiaCSFirstArea),       .shouldRender = FALSE, .allowRepeat = TRUE,  .hasSpawned = FALSE},
    [BKTN_DIA_CS_SECOND_AREA]      = {.startAddr = bMiniDiaCSSecondArea,      .dialogCount = ARRAY_COUNT(bMiniDiaCSSecondArea),      .shouldRender = FALSE, .allowRepeat = TRUE,  .hasSpawned = FALSE},
    [BKTN_DIA_CS_FINAL_0]          = {.startAddr = bMiniDiaCSFinal0,          .dialogCount = ARRAY_COUNT(bMiniDiaCSFinal0),          .shouldRender = FALSE, .allowRepeat = TRUE,  .hasSpawned = FALSE},
    [BKTN_DIA_CS_FINAL_1]          = {.startAddr = bMiniDiaCSFinal1,          .dialogCount = ARRAY_COUNT(bMiniDiaCSFinal1),          .shouldRender = FALSE, .allowRepeat = TRUE,  .hasSpawned = FALSE},
    [BKTN_DIA_CS_FINAL_DEATH]      = {.startAddr = bMiniDiaCSFinalDeath,      .dialogCount = ARRAY_COUNT(bMiniDiaCSFinalDeath),      .shouldRender = FALSE, .allowRepeat = TRUE,  .hasSpawned = FALSE},
};

STATIC_ASSERT(BKTN_DIA_COUNT == ARRAY_COUNT(bMiniDialogs), "MISSED A BLOCKINGTON DIALOG!");
