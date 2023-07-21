#include <ultra64.h>

#include "sm64.h"
#include "make_const_nonconst.h"

ALIGNED8 const u8 sponge_top_textures_dma[] = {
#include "actors/amp/spongetop0.rgba16.inc.c"
    ,
#include "actors/amp/spongetop1.rgba16.inc.c"
    ,
    #include "actors/amp/spongetop2.rgba16.inc.c"
    ,
    #include "actors/amp/spongetop3.rgba16.inc.c"
    ,
    #include "actors/amp/spongetop4.rgba16.inc.c"
    ,
    #include "actors/amp/spongetop5.rgba16.inc.c"
    ,
    #include "actors/amp/spongetop6.rgba16.inc.c"
    ,
    #include "actors/amp/spongetop7.rgba16.inc.c"
    ,
    #include "actors/amp/spongetop8.rgba16.inc.c"
    ,
    #include "actors/amp/spongetop9.rgba16.inc.c"
    ,
    #include "actors/amp/spongetop10.rgba16.inc.c"
    ,
    #include "actors/amp/spongetop11.rgba16.inc.c"
    ,
    #include "actors/amp/spongetop12.rgba16.inc.c"
    ,
    #include "actors/amp/spongetop13.rgba16.inc.c"
};

ALIGNED8 const u8 sponge_bottom_textures_dma[] = {
#include "actors/amp/spongebottom0.rgba16.inc.c"
    ,
#include "actors/amp/spongebottom1.rgba16.inc.c"
    ,
    #include "actors/amp/spongebottom2.rgba16.inc.c"
    ,
    #include "actors/amp/spongebottom3.rgba16.inc.c"
    ,
    #include "actors/amp/spongebottom4.rgba16.inc.c"
    ,
    #include "actors/amp/spongebottom5.rgba16.inc.c"
    ,
    #include "actors/amp/spongebottom6.rgba16.inc.c"
    ,
    #include "actors/amp/spongebottom7.rgba16.inc.c"
    ,
    #include "actors/amp/spongebottom8.rgba16.inc.c"
    ,
    #include "actors/amp/spongebottom9.rgba16.inc.c"
    ,
    #include "actors/amp/spongebottom10.rgba16.inc.c"
    ,
    #include "actors/amp/spongebottom11.rgba16.inc.c"
    ,
    #include "actors/amp/spongebottom12.rgba16.inc.c"
    ,
    #include "actors/amp/spongebottom13.rgba16.inc.c"
};

ALIGNED8 const u8 sq_tl_textures_dma[] = {
#include "actors/amp/sqtl0.rgba16.inc.c"
    ,
#include "actors/amp/sqtl1.rgba16.inc.c"
    ,
    #include "actors/amp/sqtl2.rgba16.inc.c"
    ,
    #include "actors/amp/sqtl3.rgba16.inc.c"
    ,
    #include "actors/amp/sqtl4.rgba16.inc.c"
    ,
    #include "actors/amp/sqtl5.rgba16.inc.c"
    ,
    #include "actors/amp/sqtl6.rgba16.inc.c"
    ,
    #include "actors/amp/sqtl7.rgba16.inc.c"
    ,
    #include "actors/amp/sqtl8.rgba16.inc.c"
    ,
    #include "actors/amp/sqtl9.rgba16.inc.c"
    ,
    #include "actors/amp/sqtl10.rgba16.inc.c"
    ,
    #include "actors/amp/sqtl11.rgba16.inc.c"
    ,
    #include "actors/amp/sqtl12.rgba16.inc.c"
    ,
    #include "actors/amp/sqtl13.rgba16.inc.c"
    ,
    #include "actors/amp/sqtl14.rgba16.inc.c"
    ,
    #include "actors/amp/sqtl15.rgba16.inc.c"
    ,
    #include "actors/amp/sqtl16.rgba16.inc.c"
    ,
    #include "actors/amp/sqtl17.rgba16.inc.c"
    ,
    #include "actors/amp/sqtl18.rgba16.inc.c"
    ,
    #include "actors/amp/sqtl19.rgba16.inc.c"
    ,
    #include "actors/amp/sqtl20.rgba16.inc.c"
};

ALIGNED8 const u8 sq_tr_textures_dma[] = {
#include "actors/amp/sqtr0.rgba16.inc.c"
    ,
#include "actors/amp/sqtr1.rgba16.inc.c"
    ,
    #include "actors/amp/sqtr2.rgba16.inc.c"
    ,
    #include "actors/amp/sqtr3.rgba16.inc.c"
    ,
    #include "actors/amp/sqtr4.rgba16.inc.c"
    ,
    #include "actors/amp/sqtr5.rgba16.inc.c"
    ,
    #include "actors/amp/sqtr6.rgba16.inc.c"
    ,
    #include "actors/amp/sqtr7.rgba16.inc.c"
    ,
    #include "actors/amp/sqtr8.rgba16.inc.c"
    ,
    #include "actors/amp/sqtr9.rgba16.inc.c"
    ,
    #include "actors/amp/sqtr10.rgba16.inc.c"
    ,
    #include "actors/amp/sqtr11.rgba16.inc.c"
    ,
    #include "actors/amp/sqtr12.rgba16.inc.c"
    ,
    #include "actors/amp/sqtr13.rgba16.inc.c"
    ,
    #include "actors/amp/sqtr14.rgba16.inc.c"
    ,
    #include "actors/amp/sqtr15.rgba16.inc.c"
    ,
    #include "actors/amp/sqtr16.rgba16.inc.c"
    ,
    #include "actors/amp/sqtr17.rgba16.inc.c"
    ,
    #include "actors/amp/sqtr18.rgba16.inc.c"
    ,
    #include "actors/amp/sqtr19.rgba16.inc.c"
    ,
    #include "actors/amp/sqtr20.rgba16.inc.c"
};

ALIGNED8 const u8 sq_bl_textures_dma[] = {
#include "actors/amp/sqbl0.rgba16.inc.c"
    ,
#include "actors/amp/sqbl1.rgba16.inc.c"
    ,
    #include "actors/amp/sqbl2.rgba16.inc.c"
    ,
    #include "actors/amp/sqbl3.rgba16.inc.c"
    ,
    #include "actors/amp/sqbl4.rgba16.inc.c"
    ,
    #include "actors/amp/sqbl5.rgba16.inc.c"
    ,
    #include "actors/amp/sqbl6.rgba16.inc.c"
    ,
    #include "actors/amp/sqbl7.rgba16.inc.c"
    ,
    #include "actors/amp/sqbl8.rgba16.inc.c"
    ,
    #include "actors/amp/sqbl9.rgba16.inc.c"
    ,
    #include "actors/amp/sqbl10.rgba16.inc.c"
    ,
    #include "actors/amp/sqbl11.rgba16.inc.c"
    ,
    #include "actors/amp/sqbl12.rgba16.inc.c"
    ,
    #include "actors/amp/sqbl13.rgba16.inc.c"
    ,
    #include "actors/amp/sqbl14.rgba16.inc.c"
    ,
    #include "actors/amp/sqbl15.rgba16.inc.c"
    ,
    #include "actors/amp/sqbl16.rgba16.inc.c"
    ,
    #include "actors/amp/sqbl17.rgba16.inc.c"
    ,
    #include "actors/amp/sqbl18.rgba16.inc.c"
    ,
    #include "actors/amp/sqbl19.rgba16.inc.c"
    ,
    #include "actors/amp/sqbl20.rgba16.inc.c"
};

ALIGNED8 const u8 sq_br_textures_dma[] = {
#include "actors/amp/sqbr0.rgba16.inc.c"
    ,
#include "actors/amp/sqbr1.rgba16.inc.c"
    ,
    #include "actors/amp/sqbr2.rgba16.inc.c"
    ,
    #include "actors/amp/sqbr3.rgba16.inc.c"
    ,
    #include "actors/amp/sqbr4.rgba16.inc.c"
    ,
    #include "actors/amp/sqbr5.rgba16.inc.c"
    ,
    #include "actors/amp/sqbr6.rgba16.inc.c"
    ,
    #include "actors/amp/sqbr7.rgba16.inc.c"
    ,
    #include "actors/amp/sqbr8.rgba16.inc.c"
    ,
    #include "actors/amp/sqbr9.rgba16.inc.c"
    ,
    #include "actors/amp/sqbr10.rgba16.inc.c"
    ,
    #include "actors/amp/sqbr11.rgba16.inc.c"
    ,
    #include "actors/amp/sqbr12.rgba16.inc.c"
    ,
    #include "actors/amp/sqbr13.rgba16.inc.c"
    ,
    #include "actors/amp/sqbr14.rgba16.inc.c"
    ,
    #include "actors/amp/sqbr15.rgba16.inc.c"
    ,
    #include "actors/amp/sqbr16.rgba16.inc.c"
    ,
    #include "actors/amp/sqbr17.rgba16.inc.c"
    ,
    #include "actors/amp/sqbr18.rgba16.inc.c"
    ,
    #include "actors/amp/sqbr19.rgba16.inc.c"
    ,
    #include "actors/amp/sqbr20.rgba16.inc.c"
};

ALIGNED8 const Texture load_screen_0[] = {
#include "actors/amp/load_screen_0.rgba16.inc.c"
};

ALIGNED8 const Texture load_screen_1[] = {
#include "actors/amp/load_screen_1.rgba16.inc.c"
};

ALIGNED8 const Texture load_screen_2[] = {
#include "actors/amp/load_screen_2.rgba16.inc.c"
};

ALIGNED8 const Texture load_screen_3[] = {
#include "actors/amp/load_screen_3.rgba16.inc.c"
};

ALIGNED8 const Texture load_screen_4[] = {
#include "actors/amp/load_screen_4.rgba16.inc.c"
};
