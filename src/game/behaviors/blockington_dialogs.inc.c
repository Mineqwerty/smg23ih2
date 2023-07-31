// blockington_dialogs.inc.c

struct BlockingtonMiniDialog bMiniDia0[] = {
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_1, .dialogStr = "Temporary Dialog 1"},
};
struct BlockingtonMiniDialog bMiniDia1[] = {
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_2, .dialogStr = "Temporary Dialog 2"},
};
struct BlockingtonMiniDialog bMiniDia2[] = {
    {.lineCount = 2, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_3, .dialogStr = "Temporary Dialog 3, but actually a\nlot longer this time"},
};
struct BlockingtonMiniDialog bMiniDia3[] = {
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_4, .dialogStr = "Temporary Dialog 4 (Part 1)"},
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_4, .dialogStr = "Temporary Dialog 4 (Part 2)"},
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_4, .dialogStr = "Temporary Dialog 4 (Part 3)"},
    {.lineCount = 1, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_4, .dialogStr = "Temporary Dialog 4 (Part 4)"},
};
struct BlockingtonMiniDialog bMiniDia4[] = {
    {.lineCount = 6, .soundID = SOUND_BLOCKINGTON_TEMPORARY_DIALOG_5, .dialogStr = "Temporary Dialog 5\nbut\nwith\nmore\nunscripted\nlines"},
};

struct BlockingtonMiniDialogEntries bMiniDialogs[] = {
    {.startAddr = bMiniDia0, .dialogCount = ARRAY_COUNT(bMiniDia0), .shouldRender = FALSE, .allowRepeat = FALSE, .hasSpawned = FALSE},
    {.startAddr = bMiniDia1, .dialogCount = ARRAY_COUNT(bMiniDia1), .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    {.startAddr = bMiniDia2, .dialogCount = ARRAY_COUNT(bMiniDia2), .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    {.startAddr = bMiniDia3, .dialogCount = ARRAY_COUNT(bMiniDia3), .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
    {.startAddr = bMiniDia4, .dialogCount = ARRAY_COUNT(bMiniDia4), .shouldRender = TRUE,  .allowRepeat = FALSE, .hasSpawned = FALSE},
};

const u32 bMiniDialogsCount = ARRAY_COUNT(bMiniDialogs);
