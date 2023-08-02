// explosion.inc.c

void bhv_explosion_init(void) {
    if (o->parentObj == NULL || o->parentObj->behavior != segmented_to_virtual(bhvCQGate)) {
        /**
         * Idk why but this doesn't behave the same as just playing the sound effect normally in the source,
         * leaving some quickly repeated explosion sounds to be cut out entirely.
         * This seems to be related to the individual explosion object moreso than usage of the spawner, but I still don't get it.
         * Could it be related to the sound's object camera position referencing a different- address?
         */
        create_sound_spawner(SOUND_GENERAL2_BOBOMB_EXPLOSION);
    }
    set_environmental_camera_shake(SHAKE_ENV_EXPLOSION);

    o->oOpacity = 255;
}

void bhv_explosion_loop(void) {
    s32 i;

    if (o->oTimer == 9) {
        if (find_water_level(o->oPosX, o->oPosZ) > o->oPosY) {
            for (i = 0; i < 40; i++) {
                struct Object *obj = spawn_object(o, MODEL_WHITE_PARTICLE_SMALL, bhvBobombExplosionBubble);
                if (obj) {
                    obj->oBehParams = o->oBehParams;
                }
            }
        } else {
            struct Object *obj = spawn_object(o, MODEL_SMOKE, bhvBobombBullyDeathSmoke);
            if (obj) {
                obj->oBehParams = o->oBehParams;
            }
        }

        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }

    o->oOpacity -= 14;

    f32 scale = 1.0f;
    if (BPARAM4) {
        scale *= (f32) BPARAM4 / 16.0f;
    }

    cur_obj_scale(((f32) o->oTimer / 9.0f + 1.0f) * scale);
}

void bhv_bobomb_bully_death_smoke_init(void) {
    f32 scale = 1.0f;
    if (BPARAM4) {
        scale *= (f32) BPARAM4 / 16.0f;
    }

    o->oPosY -= 300.0f * scale;

    cur_obj_scale(10.0f * scale);
}

void bhv_bobomb_explosion_bubble_init(void) {
    o->oBobombExpBubGfxScale = 1.0f;

    if (BPARAM4) {
        o->oBobombExpBubGfxScale *= (f32) BPARAM4 / 16.0f;
    }

    obj_scale_xyz(o, 2.0f * o->oBobombExpBubGfxScale, 2.0f * o->oBobombExpBubGfxScale, o->oBobombExpBubGfxScale);

    o->oBobombExpBubGfxExpRateX = (s32)(random_float() * 2048.0f) + 0x800;
    o->oBobombExpBubGfxExpRateY = (s32)(random_float() * 2048.0f) + 0x800;
    o->oTimer = random_float() * 10.0f;
    o->oVelY = (s32)(random_float() * 4.0f * o->oBobombExpBubGfxScale) + 4;
}

void bhv_bobomb_explosion_bubble_loop(void) {
    f32 waterY = gMarioState->waterLevel;

    o->header.gfx.scale[0] = (sins(o->oBobombExpBubGfxScaleFacX) * 0.5f + 2.0f) * o->oBobombExpBubGfxScale;
    o->oBobombExpBubGfxScaleFacX += o->oBobombExpBubGfxExpRateX;

    o->header.gfx.scale[1] = (sins(o->oBobombExpBubGfxScaleFacY) * 0.5f + 2.0f) * o->oBobombExpBubGfxScale;
    o->oBobombExpBubGfxScaleFacY += o->oBobombExpBubGfxExpRateY;

    if (o->oPosY > waterY) {
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
        o->oPosY += 5.0f * o->oBobombExpBubGfxScale;
        struct Object *obj = spawn_object(o, MODEL_SMALL_WATER_SPLASH, bhvObjectWaterSplash);
        if (BPARAM4 && obj) {
            vec3_same(obj->header.gfx.scale, (f32) BPARAM4 / 16.0f);
        }
    }

    if (o->oTimer > 60) {
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }
    o->oPosY += o->oVelY;
    o->oTimer++;
}
