#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "level_misc_macros.h"
#include "macro_preset_names.h"
#include "special_preset_names.h"
#include "textures.h"
#include "dialog_ids.h"

#include "make_const_nonconst.h"
#include "levels/sl/texture.inc.c"
#include "levels/sl/areas/1/1/model.inc.c"
#include "levels/sl/areas/1/2/model.inc.c"
#include "levels/sl/areas/1/3/model.inc.c"
#include "levels/sl/areas/1/4/model.inc.c"
#include "levels/sl/areas/1/5/model.inc.c"
#include "levels/sl/areas/1/6/model.inc.c"
#include "levels/sl/areas/1/7/model.inc.c"
#include "levels/sl/snow_mound/model.inc.c"
#include "levels/sl/unused_cracked_ice/model.inc.c"
#include "levels/sl/unused_ice_shard/model.inc.c" // Used in the unused behavior when ground pounding the cracked ice show in the above model.
#include "levels/sl/areas/2/1/model.inc.c"
#include "levels/sl/areas/2/2/model.inc.c"
#include "levels/sl/areas/2/3/model.inc.c"
#include "levels/sl/areas/2/4/model.inc.c"
#include "levels/sl/areas/1/collision.inc.c"
#include "levels/sl/areas/1/macro.inc.c"
#include "levels/sl/snow_mound/collision.inc.c"
#include "levels/sl/unused_cracked_ice/collision.inc.c"
#include "levels/sl/areas/2/collision.inc.c"
#include "levels/sl/areas/2/macro.inc.c"
#include "levels/sl/areas/1/movtext.inc.c"

#include "levels/sl/leveldata.inc.c"

#include "levels/sl/floating_stuff_1/model.inc.c"
#include "levels/sl/selectWheel/model.inc.c"
#include "levels/sl/skillIcon/model.inc.c"
#include "levels/sl/selectCircle/model.inc.c"
#include "levels/sl/attackIcon/model.inc.c"
#include "levels/sl/waitIcon/model.inc.c"
#include "levels/sl/tacticsIcon/model.inc.c"
#include "levels/sl/itemIcon/model.inc.c"
#include "levels/sl/fleeIcon/model.inc.c"
#include "levels/sl/personaIcon/model.inc.c"