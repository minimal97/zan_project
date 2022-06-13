// ==========================================
//
//
//
void Bingo_HUB_W (void) {

    u8  i;

    for (i = 0 ;i< MY_BOX_SIZE ; i++) {

        BgBak[(32 * 3) + 8 + i] = BG2_Map[HUD_SQU + My_Box[i]];
    }
}


// ==========================================
//
//  位置 = 位置 + ベクトル
//
u8 obj_move (OBJS *Me) {

    Me->x += Me->vx;
    Me->y += Me->vy;

    if (GetObi(Me-> x >> 8 , 280 , 480)) return 1;
    if (GetObi(Me-> y >> 8 , 160 , 200)) return 1;

    return 0;
}


// ==========================================
void tokuten (u16 scr) {

    u32 seed;
    u8 wak;

    seed = S_KWA;

    for (i = 0;i < S_KETA ; i++) {

        wak = (u8)(scr / seed);
        BgBak[SCORE_START + i] = BG2_Map[wak + HUD_FIG];        // 上の行
        scr = (scr % seed);
        seed /= 10;
    }
}


// ==========================================
void BoxDebug (void) {

    if (Trg & L_BUTTON) {

        My_Box[0]++;
        My_Box[0] = My_Box[0] % 8;
        getaway();
    }
}
