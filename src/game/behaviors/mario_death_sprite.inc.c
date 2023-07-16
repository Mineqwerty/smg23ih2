// mario_death_sprite.inc.c

enum MarioDeathSpriteActions {
    ACT_MARIO_DEATH_SPRITE_STATIONARY,
    ACT_MARIO_DEATH_SPRITE_MOVING,
    ACT_MARIO_DEATH_SPRITE_BOTTOMED,
};

void bhv_mario_death_sprite_loop(void) {
    switch (o->oAction) {
        case ACT_MARIO_DEATH_SPRITE_STATIONARY:
            if (gCamera && gMarioObject) {
                if ((u16) ((u16) gCamera->yaw - (u16) gMarioObject->oFaceAngleYaw) < 0x8000) {
                    o->oAnimState = 1;
                } else {
                    o->oAnimState = 0;
                }
            }
            if (o->oTimer >= 24) {
                o->oAction = ACT_MARIO_DEATH_SPRITE_MOVING;
                o->oVelY = 55.0f;
            }
            break;
        case ACT_MARIO_DEATH_SPRITE_MOVING:
            o->oVelY -= 5.0f;
            if (o->oVelY < -75.0f) {
                o->oVelY = -75.0f;
            }
            if (o->oPosY - o->oVelY < FLOOR_LOWER_LIMIT) {
                o->oAction = ACT_MARIO_DEATH_SPRITE_BOTTOMED;
                o->oPosY = FLOOR_LOWER_LIMIT;
                o->oVelY = 0;
            }
            break;
        default:
            break;
    }

    o->oPosY += o->oVelY;
}
