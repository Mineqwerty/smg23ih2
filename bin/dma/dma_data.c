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

ALIGNED8 const Texture patchy_textures_dma[] = {
    #include "actors/amp/patchy1.rgba16.inc.c"
    ,
#include "actors/amp/patchy2.rgba16.inc.c"
    ,
#include "actors/amp/patchy3.rgba16.inc.c"
    ,
#include "actors/amp/patchy4.rgba16.inc.c"
    ,
#include "actors/amp/patchy5.rgba16.inc.c"
,

#include "actors/amp/patchy6.rgba16.inc.c"
    ,
#include "actors/amp/patchy7.rgba16.inc.c"
    ,
#include "actors/amp/patchy8.rgba16.inc.c"
    ,
#include "actors/amp/patchy9.rgba16.inc.c"
    ,
#include "actors/amp/patchy10.rgba16.inc.c"
    ,
#include "actors/amp/patchy11.rgba16.inc.c"
    ,
#include "actors/amp/patchy12.rgba16.inc.c"
    ,
#include "actors/amp/patchy13.rgba16.inc.c"
    ,
#include "actors/amp/patchy14.rgba16.inc.c"
    ,
#include "actors/amp/patchy15.rgba16.inc.c"
    ,
#include "actors/amp/patchy16.rgba16.inc.c"
    ,
#include "actors/amp/patchy17.rgba16.inc.c"
    ,
#include "actors/amp/patchy18.rgba16.inc.c"
    ,
#include "actors/amp/patchy19.rgba16.inc.c"
    ,
#include "actors/amp/patchy20.rgba16.inc.c"
    ,
#include "actors/amp/patchy21.rgba16.inc.c"
    ,
#include "actors/amp/patchy22.rgba16.inc.c"
    ,
#include "actors/amp/patchy23.rgba16.inc.c"
    ,
#include "actors/amp/patchy24.rgba16.inc.c"
    ,
#include "actors/amp/patchy25.rgba16.inc.c"
    ,
#include "actors/amp/patchy26.rgba16.inc.c"
    ,
#include "actors/amp/patchy27.rgba16.inc.c"
    ,
#include "actors/amp/patchy28.rgba16.inc.c"
    ,
#include "actors/amp/patchy29.rgba16.inc.c"
    ,
#include "actors/amp/patchy30.rgba16.inc.c"
    ,
#include "actors/amp/patchy31.rgba16.inc.c"
    ,
#include "actors/amp/patchy32.rgba16.inc.c"
    ,
#include "actors/amp/patchy33.rgba16.inc.c"
    ,
#include "actors/amp/patchy34.rgba16.inc.c"
    ,
#include "actors/amp/patchy35.rgba16.inc.c"
    ,
#include "actors/amp/patchy36.rgba16.inc.c"
    ,
#include "actors/amp/patchy37.rgba16.inc.c"
    ,
#include "actors/amp/patchy38.rgba16.inc.c"
    ,
#include "actors/amp/patchy39.rgba16.inc.c"
    ,
#include "actors/amp/patchy40.rgba16.inc.c"
    ,
#include "actors/amp/patchy41.rgba16.inc.c"
    ,
#include "actors/amp/patchy42.rgba16.inc.c"
    ,
#include "actors/amp/patchy43.rgba16.inc.c"
    ,
#include "actors/amp/patchy44.rgba16.inc.c"
    ,
#include "actors/amp/patchy45.rgba16.inc.c"
    ,
#include "actors/amp/patchy46.rgba16.inc.c"
    ,
#include "actors/amp/patchy47.rgba16.inc.c"
    ,
#include "actors/amp/patchy48.rgba16.inc.c"
    ,
#include "actors/amp/patchy49.rgba16.inc.c"
    ,
#include "actors/amp/patchy50.rgba16.inc.c"
    ,
#include "actors/amp/patchy51.rgba16.inc.c"
    ,
#include "actors/amp/patchy52.rgba16.inc.c"
    ,
#include "actors/amp/patchy53.rgba16.inc.c"
    ,
#include "actors/amp/patchy54.rgba16.inc.c"
    ,
#include "actors/amp/patchy55.rgba16.inc.c"
    ,
#include "actors/amp/patchy56.rgba16.inc.c"
    ,
#include "actors/amp/patchy57.rgba16.inc.c"
    ,
#include "actors/amp/patchy58.rgba16.inc.c"
    ,
#include "actors/amp/patchy59.rgba16.inc.c"
    ,
#include "actors/amp/patchy60.rgba16.inc.c"
    ,
#include "actors/amp/patchy61.rgba16.inc.c"
    ,
#include "actors/amp/patchy62.rgba16.inc.c"
    ,
#include "actors/amp/patchy63.rgba16.inc.c"
    ,
#include "actors/amp/patchy64.rgba16.inc.c"
    ,
#include "actors/amp/patchy65.rgba16.inc.c"
    ,
#include "actors/amp/patchy66.rgba16.inc.c"
    ,
#include "actors/amp/patchy67.rgba16.inc.c"
    ,
#include "actors/amp/patchy68.rgba16.inc.c"
    ,
#include "actors/amp/patchy69.rgba16.inc.c"
    ,
#include "actors/amp/patchy70.rgba16.inc.c"
    ,
#include "actors/amp/patchy71.rgba16.inc.c"
    ,
#include "actors/amp/patchy72.rgba16.inc.c"
    ,
#include "actors/amp/patchy73.rgba16.inc.c"
    ,
#include "actors/amp/patchy74.rgba16.inc.c"
    ,
#include "actors/amp/patchy75.rgba16.inc.c"
    ,
#include "actors/amp/patchy76.rgba16.inc.c"
    ,
#include "actors/amp/patchy77.rgba16.inc.c"
    ,
#include "actors/amp/patchy78.rgba16.inc.c"
    ,
#include "actors/amp/patchy79.rgba16.inc.c"
    ,
#include "actors/amp/patchy80.rgba16.inc.c"
    ,
#include "actors/amp/patchy81.rgba16.inc.c"
    ,
#include "actors/amp/patchy82.rgba16.inc.c"
    ,
#include "actors/amp/patchy83.rgba16.inc.c"
    ,
#include "actors/amp/patchy84.rgba16.inc.c"
    ,
#include "actors/amp/patchy85.rgba16.inc.c"
    ,
#include "actors/amp/patchy86.rgba16.inc.c"
    ,
#include "actors/amp/patchy87.rgba16.inc.c"
    ,
#include "actors/amp/patchy88.rgba16.inc.c"
    ,
#include "actors/amp/patchy89.rgba16.inc.c"
    ,
#include "actors/amp/patchy90.rgba16.inc.c"
    ,
#include "actors/amp/patchy91.rgba16.inc.c"
    ,
#include "actors/amp/patchy92.rgba16.inc.c"
    ,
#include "actors/amp/patchy93.rgba16.inc.c"
    ,
#include "actors/amp/patchy94.rgba16.inc.c"
    ,
#include "actors/amp/patchy95.rgba16.inc.c"
    ,
#include "actors/amp/patchy96.rgba16.inc.c"
    ,
#include "actors/amp/patchy97.rgba16.inc.c"
    ,
#include "actors/amp/patchy98.rgba16.inc.c"
    ,
#include "actors/amp/patchy99.rgba16.inc.c"
    ,
#include "actors/amp/patchy100.rgba16.inc.c"
    ,
#include "actors/amp/patchy101.rgba16.inc.c"
    ,
#include "actors/amp/patchy102.rgba16.inc.c"
    ,
#include "actors/amp/patchy103.rgba16.inc.c"
    ,
#include "actors/amp/patchy104.rgba16.inc.c"
    ,
#include "actors/amp/patchy105.rgba16.inc.c"
    ,
#include "actors/amp/patchy106.rgba16.inc.c"
    ,
#include "actors/amp/patchy107.rgba16.inc.c"
    ,
#include "actors/amp/patchy108.rgba16.inc.c"
    ,
#include "actors/amp/patchy109.rgba16.inc.c"
    ,
#include "actors/amp/patchy110.rgba16.inc.c"
    ,
#include "actors/amp/patchy111.rgba16.inc.c"
    ,
#include "actors/amp/patchy112.rgba16.inc.c"
    ,
#include "actors/amp/patchy113.rgba16.inc.c"
    ,
#include "actors/amp/patchy114.rgba16.inc.c"
    ,
#include "actors/amp/patchy115.rgba16.inc.c"
    ,
#include "actors/amp/patchy116.rgba16.inc.c"
    ,
#include "actors/amp/patchy117.rgba16.inc.c"
    ,
#include "actors/amp/patchy118.rgba16.inc.c"
    ,
#include "actors/amp/patchy119.rgba16.inc.c"
    ,
#include "actors/amp/patchy120.rgba16.inc.c"
    ,
#include "actors/amp/patchy121.rgba16.inc.c"
    ,
#include "actors/amp/patchy122.rgba16.inc.c"
    ,
#include "actors/amp/patchy123.rgba16.inc.c"
    ,
#include "actors/amp/patchy124.rgba16.inc.c"
    ,
#include "actors/amp/patchy125.rgba16.inc.c"
    ,
#include "actors/amp/patchy126.rgba16.inc.c"
    ,
#include "actors/amp/patchy127.rgba16.inc.c"
    ,
#include "actors/amp/patchy128.rgba16.inc.c"
    ,
#include "actors/amp/patchy129.rgba16.inc.c"
    ,
#include "actors/amp/patchy130.rgba16.inc.c"
    ,
#include "actors/amp/patchy131.rgba16.inc.c"
    ,
#include "actors/amp/patchy132.rgba16.inc.c"
    ,
#include "actors/amp/patchy133.rgba16.inc.c"
    ,
#include "actors/amp/patchy134.rgba16.inc.c"
    ,
#include "actors/amp/patchy135.rgba16.inc.c"
    ,
#include "actors/amp/patchy136.rgba16.inc.c"
    ,
#include "actors/amp/patchy137.rgba16.inc.c"
    ,
#include "actors/amp/patchy138.rgba16.inc.c"
    ,
#include "actors/amp/patchy139.rgba16.inc.c"
    ,
#include "actors/amp/patchy140.rgba16.inc.c"
    ,
#include "actors/amp/patchy141.rgba16.inc.c"
    ,
#include "actors/amp/patchy142.rgba16.inc.c"
    ,
#include "actors/amp/patchy143.rgba16.inc.c"
    ,
#include "actors/amp/patchy144.rgba16.inc.c"
    ,
#include "actors/amp/patchy145.rgba16.inc.c"
    ,
#include "actors/amp/patchy146.rgba16.inc.c"
    ,
#include "actors/amp/patchy147.rgba16.inc.c"
    ,
#include "actors/amp/patchy148.rgba16.inc.c"
    ,
#include "actors/amp/patchy149.rgba16.inc.c"
    ,
#include "actors/amp/patchy150.rgba16.inc.c"
    ,
#include "actors/amp/patchy151.rgba16.inc.c"
    ,
#include "actors/amp/patchy152.rgba16.inc.c"
    ,
#include "actors/amp/patchy153.rgba16.inc.c"
    ,
#include "actors/amp/patchy154.rgba16.inc.c"
    ,
#include "actors/amp/patchy155.rgba16.inc.c"
    ,
#include "actors/amp/patchy156.rgba16.inc.c"
    ,
#include "actors/amp/patchy157.rgba16.inc.c"
    ,
#include "actors/amp/patchy158.rgba16.inc.c"
    ,
#include "actors/amp/patchy159.rgba16.inc.c"
    ,
#include "actors/amp/patchy160.rgba16.inc.c"
    ,
#include "actors/amp/patchy161.rgba16.inc.c"
    ,
#include "actors/amp/patchy162.rgba16.inc.c"
    ,
#include "actors/amp/patchy163.rgba16.inc.c"
    ,
#include "actors/amp/patchy164.rgba16.inc.c"
    ,
#include "actors/amp/patchy165.rgba16.inc.c"
    ,
#include "actors/amp/patchy166.rgba16.inc.c"
    ,
#include "actors/amp/patchy167.rgba16.inc.c"
    ,
#include "actors/amp/patchy168.rgba16.inc.c"
    ,
#include "actors/amp/patchy169.rgba16.inc.c"
    ,
#include "actors/amp/patchy170.rgba16.inc.c"
    ,
#include "actors/amp/patchy171.rgba16.inc.c"
    ,
#include "actors/amp/patchy172.rgba16.inc.c"
    ,
#include "actors/amp/patchy173.rgba16.inc.c"
    ,
#include "actors/amp/patchy174.rgba16.inc.c"
    ,
#include "actors/amp/patchy175.rgba16.inc.c"
    ,
#include "actors/amp/patchy176.rgba16.inc.c"
    ,
#include "actors/amp/patchy177.rgba16.inc.c"
    ,
#include "actors/amp/patchy178.rgba16.inc.c"
    ,
#include "actors/amp/patchy179.rgba16.inc.c"
    ,
#include "actors/amp/patchy180.rgba16.inc.c"
    ,
#include "actors/amp/patchy181.rgba16.inc.c"
    ,
#include "actors/amp/patchy182.rgba16.inc.c"
    ,
#include "actors/amp/patchy183.rgba16.inc.c"
    ,
#include "actors/amp/patchy184.rgba16.inc.c"
    ,
#include "actors/amp/patchy185.rgba16.inc.c"
    ,
#include "actors/amp/patchy186.rgba16.inc.c"
    ,
#include "actors/amp/patchy187.rgba16.inc.c"
    ,
#include "actors/amp/patchy188.rgba16.inc.c"
    ,
#include "actors/amp/patchy189.rgba16.inc.c"
    ,
#include "actors/amp/patchy190.rgba16.inc.c"
    ,
#include "actors/amp/patchy191.rgba16.inc.c"
    ,
#include "actors/amp/patchy192.rgba16.inc.c"
    ,
#include "actors/amp/patchy193.rgba16.inc.c"
    ,
#include "actors/amp/patchy194.rgba16.inc.c"
    ,
#include "actors/amp/patchy195.rgba16.inc.c"
    ,
#include "actors/amp/patchy196.rgba16.inc.c"
    ,
#include "actors/amp/patchy197.rgba16.inc.c"
    ,
#include "actors/amp/patchy198.rgba16.inc.c"
    ,
#include "actors/amp/patchy199.rgba16.inc.c"
    ,
#include "actors/amp/patchy200.rgba16.inc.c"
    ,
#include "actors/amp/patchy201.rgba16.inc.c"
    ,
#include "actors/amp/patchy202.rgba16.inc.c"
    ,
#include "actors/amp/patchy203.rgba16.inc.c"
    ,
#include "actors/amp/patchy204.rgba16.inc.c"
    ,
#include "actors/amp/patchy205.rgba16.inc.c"
    ,
#include "actors/amp/patchy206.rgba16.inc.c"
    ,
#include "actors/amp/patchy207.rgba16.inc.c"
    ,
#include "actors/amp/patchy208.rgba16.inc.c"
    ,
#include "actors/amp/patchy209.rgba16.inc.c"
    ,
#include "actors/amp/patchy210.rgba16.inc.c"
    ,
#include "actors/amp/patchy211.rgba16.inc.c"
    ,
#include "actors/amp/patchy212.rgba16.inc.c"
    ,
#include "actors/amp/patchy213.rgba16.inc.c"
    ,
#include "actors/amp/patchy214.rgba16.inc.c"
};
