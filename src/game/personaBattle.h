#ifndef PERSONA_BATTLE_H
#define PERSONA_BATTLE_H

extern s8 gSelectedBattleCommand;
extern s8 gSelectedSkillIndex;
extern s16 gBattleOptionRotationTimer;
extern char *optionText[];
extern char *optionDescriptionText[];
extern u16 gPersonaMenuFlags;
extern s8 gSelectedEnemy;
extern u8 gSelectorCooldown;
extern u8 gEnemyCount;
extern u8 gNumEnemyTurns;

enum PersonaMenuFlags {
    PERSONA_MENU_FLAGS_NONE         = /* 0x0000 */ (0 <<  0),
    PERSONA_MENU_FLAGS_MAIN_TEXT    = /* 0x0001 */ (1 <<  0),
    PERSONA_MENU_FLAGS_ATTACK_TEXT  = /* 0x0002 */ (1 <<  1),
    PERSONA_MENU_FLAGS_SKILL_TEXT  = /* 0x0004 */ (1 <<  2),
    PERSONA_MENU_FLAGS_USING_SKILL_BATTLE_TEXT  = /* 0x0004 */ (1 <<  3),
    PERSONA_MENU_FLAGS_STRIKE_ATTACK_TEXT  = /* 0x0004 */ (1 <<  4),

};

#endif // PERSONA_BATTLE_H
