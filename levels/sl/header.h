#ifndef SL_HEADER_H
#define SL_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

// geo
extern const GeoLayout sl_geo_000360[];
extern const GeoLayout sl_geo_000378[];
extern const GeoLayout sl_geo_000390[];
extern const GeoLayout sl_geo_0003A8[];
extern const GeoLayout sl_geo_000484[];

// leveldata
extern const Gfx sl_seg7_dl_07005478[];
extern const Gfx sl_seg7_dl_070056B0[];
extern const Gfx sl_seg7_dl_070073D0[];
extern const Gfx sl_seg7_dl_07007880[];
extern const Gfx sl_seg7_dl_070088B0[];
extern const Gfx sl_seg7_dl_07008D58[];
extern const Gfx sl_seg7_dl_0700A5A0[];
extern const Gfx sl_seg7_dl_0700A780[];
extern const Gfx sl_seg7_dl_0700A890[];
extern const Gfx sl_seg7_dl_0700A980[];
extern const Gfx sl_seg7_dl_0700BAE8[];
extern const Gfx sl_seg7_dl_0700BCF8[];
extern const Gfx sl_seg7_dl_0700C9E8[];
extern const Gfx sl_seg7_dl_0700CB58[];
extern const Collision sl_seg7_area_1_collision[];
extern const MacroObject sl_seg7_area_1_macro_objs[];
extern const Collision sl_seg7_collision_sliding_snow_mound[];
extern const Collision sl_seg7_collision_pound_explodes[];
extern const Collision sl_seg7_area_2_collision[];
extern const MacroObject sl_seg7_area_2_macro_objs[];
extern const struct MovtexQuadCollection sl_movtex_water[];

// script
extern const LevelScript level_sl_entry[];


#include "levels/sl/header.inc.h"

#include "levels/sl/floating_stuff_1/geo_header.h"

#include "levels/sl/selectWheel/header.h"

#include "levels/sl/skillIcon/header.h"

#include "levels/sl/selectCircle/header.h"

#include "levels/sl/attackIcon/header.h"

#include "levels/sl/waitIcon/header.h"

#include "levels/sl/tacticsIcon/header.h"

#include "levels/sl/itemIcon/header.h"

#include "levels/sl/fleeIcon/header.h"

#include "levels/sl/personaIcon/header.h"

#include "levels/sl/cowardly_maya/geo_header.h"

#include "levels/sl/cowardly_maya/anim_header.h"

#include "levels/sl/enemy_selector/geo_header.h"

#include "levels/sl/selectBox/header.h"

#include "levels/sl/skillWheel/header.h"

#include "levels/sl/generalSkillIcon/header.h"

#include "levels/sl/jumpman/geo_header.h"

#include "levels/sl/shadow_particle/geo_header.h"

#endif
