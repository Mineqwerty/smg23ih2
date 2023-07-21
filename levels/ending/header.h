#ifndef ENDING_HEADER_H
#define ENDING_HEADER_H

#include "types.h"

// geo
extern const GeoLayout ending_geo_area_1[];
extern const GeoLayout ending_load_screen_geo[];

// texture
extern const Texture load_screen_0[];
extern const Texture load_screen_1[];
extern const Texture load_screen_2[];
extern const Texture load_screen_3[];
extern const Texture load_screen_4[];

// leveldata
extern const Gfx dl_cake_end_screen[];
#ifndef EU_CUSTOM_CAKE_FIX
extern const Gfx dl_cake_end_screen_eu_english[];
extern const Gfx dl_cake_end_screen_eu_french[];
extern const Gfx dl_cake_end_screen_eu_german[];
#else
extern const Gfx dl_cake_end_screen_eu_fix[];
#endif

// script
extern const LevelScript level_ending_entry[];

#endif
