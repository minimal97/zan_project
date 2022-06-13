//=========================================
//
//  掃除当番
//
//=========================================
#include    <Agb.h>
#include    <AgbTypes.h>
#include    "../sound/m4aLib.h"

#include    "../h/struct.h"
#include    "../h/call.h"
#include    "../h/maindef.h"
#include    "../h/global.h"
#include    "../h/AGB2.h"


#include    "gomidef.h"
#include    "gomiext.h"

#include    "./bmp/G_OBJ.c"
#include    "./bmp/Bout.c"
#include    "./bmp/gomi_HUD.c"

//  横  ストップ位置

extern  u8  SoundBak[256];              // サウンド用バッファ

u8  timer;                              // タイマー
u8  TimerLevel;                         // 間隔
u8  asimoto [LINES];                    // 足元
u8  Miss_Cnt;                           // ミスの回数
u8  dead;

/* ----------------------- ゲーム本体 ----------------------- */
void GomiPlay_bgset(void);
void GomiPlay_bgview(void);
void GomiPlay_initoam(void);
void GomiPlay_value_set(void);
void GomiPlay(void);

void gomi_jiki_move(void);
void jiki_muteki(void);
void moveing(void);
void cleaning(OBJS* , OBJS*);
void clean_anm(void);
void BodySet(void);

void GomiSetLoop(void);
void GomiSet(void);
void GomiMove(void);
void GomiPlus(void);
void GomiHit(void);

void GomiAnime(OBJS*);

void Gomi_Int(void);

void GomiPause(void);

void AsimotoSet(void);

void KarasuEvent(void);

void KarasuSetLoop(void);

void KarasuTutu(OBJS*);
void KarasuCheck(OBJS*);
void KarasuWalk(OBJS*);
void KarasuFlyStep(OBJS*);
void FlyStepSet(OBJS*);
void KarasuFly(OBJS*);
void AllFlyStep(void);
void gomi_ten(u16);















