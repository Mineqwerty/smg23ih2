#ifndef BLOCKINGTON_INC_H
#define BLOCKINGTON_INC_H

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
    s32 dialogID;
    s32 soundID;
};

struct BlockingtonMiniDialogEntries {
    struct BlockingtonMiniDialog *startAddr;
    u8 dialogCount;
    u8 allowRepeat;
    u8 hasSpawned;
};

extern struct BlockingtonStates sBlockington;
extern struct BlockingtonMiniDialogEntries bMiniDialogs[];
extern const u32 bMiniDialogsCount;

void bhv_blockington_calculate_angle_scale_all(void);

#endif // BLOCKINGTON_INC_H
