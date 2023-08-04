#include <PR/ultratypes.h>

#include "src/game/personaBattle.h"
#include "src/s2d_engine/s2d_engine.h"

s8 gSelectedBattleCommand = 0;
s8 gSelectedSkillIndex = 0;
s16 gBattleOptionRotationTimer = 0;
u16 gPersonaMenuFlags = 0;
s8 gSelectedEnemy = 0;
u8 gEnemyCount = 3;
u8 gNumEnemyTurns = 0;
u8 gSelectorCooldown = 0;

char *optionText[] = {
    "Attack",
    "Skill",
    "Item",
    "Tactics",
    "Persona",
    "Escape",
    "Wait",
    "Skill"
};

char *optionDescriptionText[] = {
    "Attack using equipped \nweapon.",
    "Use assigned Persona's \nspecial ability.",
    "Use an item.",
    "Give instructions to \nan ally",
    "Assign a new Persona",
    "Flee from battle.",
    "End turn without doing \nanything.",
    "Deals light Strike \ndamage to 1 foe.",
    "Deals light Fire \ndamage to 1 foe."
};