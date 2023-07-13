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