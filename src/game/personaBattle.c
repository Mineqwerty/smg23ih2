#include <PR/ultratypes.h>

#include "src/game/personaBattle.h"
#include "src/s2d_engine/s2d_engine.h"

s8 gSelectedBattleCommand = 0;
s8 gSelectedSkillIndex = 0;
s16 gBattleOptionRotationTimer = 0;
u16 gPersonaMenuFlags = 0;
s8 gSelectedEnemy = 0;
u8 gSelectorCooldown = 0;

char *optionText[] = {
    COLOR "160 174 186 210" SCALE "20" "Attack",
    COLOR "160 174 186 210" SCALE "20" "Skill",
    COLOR "160 174 186 210" SCALE "20" "Item",
    COLOR "160 174 186 210" SCALE "20" "Tactics",
    COLOR "160 174 186 210" SCALE "20" "Persona",
    COLOR "160 174 186 210" SCALE "20" "Escape",
    COLOR "160 174 186 210" SCALE "20" "Wait",
    COLOR "188 99 126 210" SCALE "20" "Skill"
};

char *optionDescriptionText[] = {
    COLOR "140 154 166 210" SCALE "20" "Attack using equipped \nweapon.",
    COLOR "140 154 166 210" SCALE "20" "Use assigned Persona's \nspecial ability.",
    COLOR "140 154 166 210" SCALE "20" "Use an item.",
    COLOR "140 154 166 210" SCALE "20" "Give instructions to \nan ally",
    COLOR "140 154 166 210" SCALE "20" "Assign a new Persona",
    COLOR "140 154 166 210" SCALE "20" "Flee from battle.",
    COLOR "140 154 166 210" SCALE "20" "End turn without doing \nanything.",
    COLOR "140 154 166 210" SCALE "20" "Deals light Strike \ndamage to 1 foe.",
    COLOR "140 154 166 210" SCALE "20" "Deals light Fire \ndamage to 1 foe."
};