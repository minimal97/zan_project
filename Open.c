//==========================
// ビール工場
//==========================
#include <Agb.h>
#include <AgbTypes.h>

#include "../h/maindef.h"
#include "../h/struct.h"
#include "../h/call.h"
#include "../h/global.h"

#include "./bmp/bin_open.c"

// -------------------------

void Opening_bgset(void);
void Opening_bgview(void);

void START(void);

//==========================
// STAGE1
//==========================
void bins_Opening(void) {

    if (startflg) {

        Opening_bgset();
        Opening_bgview();
        startflg = OFF;
    }

    if (EVY) {

        EVY--;
    }
    else {

        EVY = 0;
        getcont();
        START();
        BackSelector();
    }

    RANDOMIZE++;

    *(vu16 *) REG_BLDY = EVY;
}


//==========================
void Opening_bgset(void) {

    DmaArrayCopy(3, bin_Open_Character, BG_VRAM + (BGCHRBLK * 1), 32);
    DmaArrayCopy(3, bin_Open_Palette, BG_PLTT + (PAL_BASE * 0), 32);

    DmaArrayCopy(3, bin_Open_Map, BgBak, 32);
    DmaArrayCopy(3, BgBak, BG_VRAM + (BGMAPBLK * 14), 32);
}


//==========================
void Opening_bgview (void) {

    *(vu16 *) REG_BG1CNT =
                          BG_COLOR_16
                        | BG_SCREEN_SIZE_0
                        | BG_PRIORITY
                        | 14 << BG_SCREEN_BASE_SHIFT
                        | 1 << BG_CHAR_BASE_SHIFT;


    *(vu16 *) REG_DISPCNT = DISP_MODE_0
                        | DISP_BG1_ON;
}
// page 1