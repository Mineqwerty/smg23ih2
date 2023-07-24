#define PITCH_VARIANCE 0x1200
#define YAW_VARIANCE 0x0C00
#define ROLL_VARIANCE 0x0C00

#define SCALE_VARIANCE_X 0.3f
#define SCALE_VARIANCE_Y 0.5f
#define SCALE_VARIANCE_Z 0.3f

#define APPROACH_FRAMES 3

enum BlockingtonActions {
    ACT_BLOCKINGTON_IDLE,
    ACT_BLOCKINGTON_TALK,
};

struct BlockingtonStates {
    Vec3i angle;
    Vec3i approachAngle;
    Vec3f scale;
    Vec3f approachScale;
} sBlockington;

const Vec3i angleLimitFactors = {0x3000, 0x1800, 0x1800};

UNUSED static void bhv_blockington_reset_angle_scale(void) {
    vec3i_copy(&o->oFaceAngleVec, sBlockington.angle);
    vec3_same(sBlockington.approachAngle, 0);
    vec3f_copy(o->header.gfx.scale, sBlockington.scale);
    vec3_same(sBlockington.approachScale, 0.0f);
}

static void bhv_blockington_talking(void) {
    if (o->oTimer % APPROACH_FRAMES == 0) {
        if (o->oAction == ACT_BLOCKINGTON_TALK) {
            Vec3i angle;
            Vec3f scale;

            angle[0] = sBlockington.angle[0] + ((random_float() * 2.0f - 1.0f) * PITCH_VARIANCE);
            angle[1] = sBlockington.angle[1] + ((random_float() * 2.0f - 1.0f) * YAW_VARIANCE);
            angle[2] = sBlockington.angle[2] + ((random_float() * 2.0f - 1.0f) * ROLL_VARIANCE);
            sBlockington.approachAngle[0] = ((s16) ((u16) angle[0] - (u16) o->oFaceAnglePitch)) / (s16) APPROACH_FRAMES;
            sBlockington.approachAngle[1] = ((s16) ((u16) angle[1] - (u16) o->oFaceAngleYaw)) / (s16) APPROACH_FRAMES;
            sBlockington.approachAngle[2] = ((s16) ((u16) angle[2] - (u16) o->oFaceAngleRoll)) / (s16) APPROACH_FRAMES;

            scale[0] = sBlockington.scale[0] + ((random_float() * 2.0f - 1.0f) * (sBlockington.scale[0] * SCALE_VARIANCE_X));
            scale[1] = sBlockington.scale[1] + ((random_float() * 2.0f - 1.0f) * (sBlockington.scale[1] * SCALE_VARIANCE_Y));
            scale[2] = sBlockington.scale[2] + ((random_float() * 2.0f - 1.0f) * (sBlockington.scale[2] * SCALE_VARIANCE_Z));
            sBlockington.approachScale[0] = (scale[0] - o->header.gfx.scale[0]) / APPROACH_FRAMES;
            sBlockington.approachScale[1] = (scale[1] - o->header.gfx.scale[1]) / APPROACH_FRAMES;
            sBlockington.approachScale[2] = (scale[2] - o->header.gfx.scale[2]) / APPROACH_FRAMES;
        } else {
            sBlockington.approachAngle[0] = ((s16) ((u16) sBlockington.angle[0] - (u16) o->oFaceAnglePitch)) / (s16) APPROACH_FRAMES;
            sBlockington.approachAngle[1] = ((s16) ((u16) sBlockington.angle[1] - (u16) o->oFaceAngleYaw)) / (s16) APPROACH_FRAMES;
            sBlockington.approachAngle[2] = ((s16) ((u16) sBlockington.angle[2] - (u16) o->oFaceAngleRoll)) / (s16) APPROACH_FRAMES;

            sBlockington.approachScale[0] = (sBlockington.scale[0] - o->header.gfx.scale[0]) / APPROACH_FRAMES;
            sBlockington.approachScale[1] = (sBlockington.scale[1] - o->header.gfx.scale[1]) / APPROACH_FRAMES;
            sBlockington.approachScale[2] = (sBlockington.scale[2] - o->header.gfx.scale[2]) / APPROACH_FRAMES;
        }
    }

    vec3i_add(&o->oFaceAngleVec, sBlockington.approachAngle);
    vec3f_add(o->header.gfx.scale, sBlockington.approachScale);
}

void bhv_blockington_init(void) {
    cur_obj_scale(1.6f);
    vec3i_copy(sBlockington.angle, &o->oFaceAngleVec);
    vec3_same(sBlockington.approachAngle, 0);
    vec3f_copy(sBlockington.scale, o->header.gfx.scale);
    vec3_same(sBlockington.approachScale, 0.0f);
}

void bhv_blockington_loop(void) {
    sBlockington.angle[1] = o->oAngleToMario;

    bhv_blockington_talking();
}

