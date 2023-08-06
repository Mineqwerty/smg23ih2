#ifndef BLOCKINGTON_INC_H
#define BLOCKINGTON_INC_H

enum BlockingtonDialogIDs {
    BKTN_DIA_OOB,
    BKTN_DIA_COIN_00,
    BKTN_DIA_COIN_02,
    BKTN_DIA_COIN_03,
    BKTN_DIA_COIN_06,
    BKTN_DIA_COIN_07,
    BKTN_DIA_COIN_10,
    BKTN_DIA_COIN_12_NORMAL,
    BKTN_DIA_COIN_12_PITY,
    BKTN_DIA_COIN_13,
    BKTN_DIA_COIN_JACKPOT,
    BKTN_DIA_COIN_23,
    BKTN_DIA_PITY_BRIDGE,
    BKTN_DIA_CRINGE_PATH_0,
    BKTN_DIA_CRINGE_PATH_1,
    BKTN_DIA_CRINGE_PATH_2,
    BKTN_DIA_CRINGE_PATH_COLLECT,
    BKTN_DIA_CS_MARIO,
    BKTN_DIA_CS_CAR,
    BKTN_DIA_CS_FIRST_AREA,
    BKTN_DIA_CS_SECOND_AREA,
    BKTN_DIA_CS_FINAL_0,
    BKTN_DIA_CS_FINAL_1,
    BKTN_DIA_CS_FINAL_DEATH,

    BKTN_DIA_COUNT,
};

struct BlockingtonStates {
    Vec3i goalAngle;
    Vec3i approachAngle;
    Vec3i curAngle;
    Vec3f goalScale;
    Vec3f approachScale;
    Vec3f curScale;
      u32 updateVar;
};

struct BlockingtonMiniDialog {
      u8  lineCount;
     s32  soundID;
    char *dialogStr;
};

struct BlockingtonMiniDialogEntries {
    struct BlockingtonMiniDialog *startAddr;
    u8 dialogCount;
    u8 shouldRender;
    u8 allowRepeat;
    u8 hasSpawned;
};

extern struct BlockingtonStates sBlockington;
extern struct BlockingtonMiniDialogEntries bMiniDialogs[];

void bhv_blockington_calculate_angle_scale_all(void);

#endif // BLOCKINGTON_INC_H
