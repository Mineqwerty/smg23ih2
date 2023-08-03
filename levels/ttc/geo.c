#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"

#include "game/level_geo.h"
#include "game/geo_misc.h"
#include "game/camera.h"
#include "game/moving_texture.h"
#include "game/screen_transition.h"
#include "game/paintings.h"

#include "make_const_nonconst.h"

#include "levels/ttc/header.h"

#include "levels/ttc/rotating_cube/geo.inc.c"
#include "levels/ttc/rotating_prism/geo.inc.c"
#include "levels/ttc/pendulum/geo.inc.c"
#include "levels/ttc/large_treadmill/geo.inc.c"
#include "levels/ttc/small_treadmill/geo.inc.c"
#include "levels/ttc/push_block/geo.inc.c"
#include "levels/ttc/rotating_hexagon/geo.inc.c"
#include "levels/ttc/rotating_triangle/geo.inc.c"
#include "levels/ttc/pit_block/geo.inc.c"
#include "levels/ttc/pit_block_2/geo.inc.c"
#include "levels/ttc/elevator_platform/geo.inc.c"
#include "levels/ttc/clock_hand/geo.inc.c"
#include "levels/ttc/spinner/geo.inc.c"
#include "levels/ttc/small_gear/geo.inc.c"
#include "levels/ttc/large_gear/geo.inc.c"
#include "levels/ttc/areas/1/geo.inc.c"

#include "levels/ttc/geo.inc.c"

#include "levels/ttc/glaggle_cube/geo.inc.c"
#include "levels/ttc/giggler/geo.inc.c"
#include "levels/ttc/giggle_sun/geo.inc.c"