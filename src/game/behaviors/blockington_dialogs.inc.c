// BKTN_DIAs.inc.c

#include "blockington.h"

// Drive out of bounds
struct BlockingtonMiniDialog bMiniDiaOOB[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Hey wait! Where do you think you're\ngoing? Stop tryin'a cheeeese!!"},
};

// Coin 00: Coin on ground right at starting exit
struct BlockingtonMiniDialog bMiniDiaCoin00[] = {
    {.lineCount = 4, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "You got an artifact!\nWow good job yeah I'm not gonna\nlike keep bothering you or something\nfor awhile totally not haha lmao."},
};

// Coin 01: Coin on ground furthest from bridge

// Coin 02: Coin on low ramp jump
struct BlockingtonMiniDialog bMiniDiaCoin02[] = {
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Wheeeeeeeehehee!!\n\n:)"},
};

// Coin 03: Coin on ground ramp
struct BlockingtonMiniDialog bMiniDiaCoin03[] = {
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Ramp."},
};

// Coin 04: Coin on ground closest to bridge
// Coin 05: Coin approaching top of spiral section

// Coin 06: Coin at top of spiral section
struct BlockingtonMiniDialog bMiniDiaCoin06[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Ohoho, spirals for days!\nYou must be dizzy!"},
};

// Coin 07: Coin on top of high block (need to launch from coin 11 to reach)
struct BlockingtonMiniDialog bMiniDiaCoin07[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Blocktacular! I cannot believe\nyou retrieved that artifact!"},
};

// Coin 08: Coin on top of brown square
// Coin 09: Coin underneath top of brown square on ramp

// Coin 10: Coin on block in middle of brown square on block
struct BlockingtonMiniDialog bMiniDiaCoin10[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Unblockevable aim! That artifact must\nhave been challenging to reach!"},
};

// Coin 11: Coin at top of highest ramp

// Coin 12: Coin at end of (reasonable) precision ramp section
struct BlockingtonMiniDialog bMiniDiaCoin12Normal[] = {
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Wow, that was squariously impressive!"},
};
struct BlockingtonMiniDialog bMiniDiaCoin12Pity[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "SMH imagine having needed help with\nTHIS section, blocko."},
};

// Coin 13: Coin at top of (reasonable) precision ramp section
struct BlockingtonMiniDialog bMiniDiaCoin13[] = {
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Oh my block, this section is precise!"},
};

// Coin 14-19: Jackpot coins
struct BlockingtonMiniDialog bMiniDiaCoinJackpot[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Blocktastic! You won the artifact\nlottery!"},
};

// Coin 20: Coin on ramp closest to first bridge
// Coin 21: Coin on ramp furthest to first bridge
// Coin 22: Coin closest to second bridge

// Coin 23: Coin on ramp closest to first bridge
struct BlockingtonMiniDialog bMiniDiaCoin23[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Ooh, now that jump was quite the\nsight to blockhold!"},
};


// Cutscene Pity Bridge
struct BlockingtonMiniDialog bMiniDiaPityBridge[] = {
    {.lineCount = 4, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "You're telling me you can't get\nto that artifact? Okay fine, since\nyou're so pathetic, I'll build a bridge\nfor you!"},
};

// Cringe Path 0
struct BlockingtonMiniDialog bMiniDiaCringePath0[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Uhh...you know, I get the feeling\nthis path is a big waste of your time..."},
};

// Cringe Path 1
struct BlockingtonMiniDialog bMiniDiaCringePath1[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Bruh. Don't you have better things\nto do?"},
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "You know, like saving Blocktaria??"},
};

// Cringe Path 2
struct BlockingtonMiniDialog bMiniDiaCringePath2[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "You're a real piece of work, kid.\nThis next section seems imblockssible anyway!"},
};

// Cringe Path Collect
struct BlockingtonMiniDialog bMiniDiaCringePathCollect[] = {
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Get rekt nerd, LMAOOOOOOOO!"},
};


// Cutscene Mario
struct BlockingtonMiniDialog bMiniDiaCSMario[] = {
    {.lineCount = 4, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "H-hey there, who the hell are you?\nYou don't seem very...blocky to me.\nI'm afraid I'm not allowed\nto let you into this place."},
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Now, with all due respect,\nwould you please kindly get\nthe hell out of here!"},
};

// Cutscene Car
struct BlockingtonMiniDialog bMiniDiaCSCar[] = {
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Hmm, you look interesting. You don't\nexactly meet the block standards but\nehhh, you're close enough."},
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Blocktaria is in too much trouble\nto nitpick at the highest detail!\nWe need someone to save us!"},
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Alright, I shall let you pass.\nYou had better respect your privilege\nof making it though here, stranger!"},
};

// Cutscene First Area
struct BlockingtonMiniDialog bMiniDiaCSFirstArea[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Now, we have something of a\ncritical problem here."},
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "You see that over there?\nSome motherblocker thought it would be\nfunny to destroy Blocktaria's block bridges!"},
    {.lineCount = 4, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Oh, HOW am I supposed to get over\nthere now? We need somebody to\nrescue all of the artifacts in order\nto reconstruct this bridge!"},
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "This is where you come in.\nPlease collect the artifacts so that\nI can visit that area again!"},
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "In the meantime, I'll be\nwaiting for you over there on\nthe other side. Now get to work!"},
};

// Cutscene Second Area
struct BlockingtonMiniDialog bMiniDiaCSSecondArea[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Oh no, What am I going to do?\nMy favorite island is unreachable!"},
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Can you help me rebuild this\nbridge too? PLEEEEASE?\n:("},
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "I'll be waiting for you on\nmy favorite island. Don't keep\nme waiting!"},
};

// Cutscene Final 0
struct BlockingtonMiniDialog bMiniDiaCSFinal0[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "INCREDIBLOCK, YOU DID IT!!!\nYOU SAVED BLOCKTAVIA!"},
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "You were able to restore peace\nto our world!"},
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Please, be my friend forever, hero!\nI could tell stories about you\nfor centuries to come!"},
};

// Cutscene Final 1
struct BlockingtonMiniDialog bMiniDiaCSFinal1[] = {
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "...W-WAIT A MINUTE!"},
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "So it was YOU!"},
    {.lineCount = 3, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "I thought I made myself clear\nthat you are not permitted entry to\nthis world!"},
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "I SHALL BANISH YOU TO THE CIRCLE REALM!\nDO YOU REALIZE WHAT YOU'VE DONE!?"},
};


struct BlockingtonMiniDialogEntries bMiniDialogs[] = {
    [BKTN_DIA_OOB]                 = {.startAddr = bMiniDiaOOB,               .dialogCount = ARRAY_COUNT(bMiniDiaOOB),               .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_COIN_00]             = {.startAddr = bMiniDiaCoin00,            .dialogCount = ARRAY_COUNT(bMiniDiaCoin00),            .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
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
    [BKTN_DIA_CS_MARIO]            = {.startAddr = bMiniDiaCSMario,           .dialogCount = ARRAY_COUNT(bMiniDiaCSMario),           .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_CS_CAR]              = {.startAddr = bMiniDiaCSCar,             .dialogCount = ARRAY_COUNT(bMiniDiaCSCar),             .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_CS_FIRST_AREA]       = {.startAddr = bMiniDiaCSFirstArea,       .dialogCount = ARRAY_COUNT(bMiniDiaCSFirstArea),       .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_CS_SECOND_AREA]      = {.startAddr = bMiniDiaCSSecondArea,      .dialogCount = ARRAY_COUNT(bMiniDiaCSSecondArea),      .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_CS_FINAL_0]          = {.startAddr = bMiniDiaCSFinal0,          .dialogCount = ARRAY_COUNT(bMiniDiaCSFinal0),          .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    [BKTN_DIA_CS_FINAL_1]          = {.startAddr = bMiniDiaCSFinal1,          .dialogCount = ARRAY_COUNT(bMiniDiaCSFinal1),          .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
};

STATIC_ASSERT(BKTN_DIA_COUNT == ARRAY_COUNT(bMiniDialogs), "MISSED A BLOCKINGTON DIALOG!");
