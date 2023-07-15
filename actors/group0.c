#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "geo_commands.h"

#include "make_const_nonconst.h"

// Note: This bin does not use bin IDs, unlike the other segmented bins.
#include "mario/model.inc.c"

#include "bubble/model.inc.c"

#include "walk_smoke/model.inc.c"

#include "burn_smoke/model.inc.c"

#include "small_water_splash/model.inc.c"

#include "water_wave/model.inc.c"

#include "sparkle/model.inc.c"

#include "water_splash/model.inc.c"

#include "white_particle_small/model.inc.c"

#include "sparkle_animation/model.inc.c"

#include "hidden_block/model.inc.c"
#include "hidden_block/collision.inc.c"

#ifdef S2DEX_TEXT_ENGINE
#include "src/s2d_engine/s2d_config.h"
#include FONT_C_FILE
#endif

#include "mario/anims/data.inc.c"
#include "mario/anims/table.inc.c"
#include "ragdoll_mario/anims/data.inc.c"
#include "ragdoll_mario/anims/table.inc.c"
#include "ragdoll_mario/model.inc.c"
#include "supergoomb/model.inc.c"
#include "cappy/model.inc.c"
#include "fazana_car/model.inc.c"
#include "fazana_car/collision.inc.c"
#include "custom_mario_death_sprite/model.inc.c"
