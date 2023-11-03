#include"headers.h"

extern int Turn;
extern struct Chessboard Chess;

void gobang_pvp(void)
{
    int Round;
    bool flag_ban,flag_win;

    printf("-------------Welcome to GAMEMODE#1  人人对战-------------\n");
    board_init(&Chess);
    board_display(Chess);
    for (Round=1; Round<=N*N; Round++)
    {
        input_pos(Chess);
        board_display(Chess);
        if (!Turn) flag_ban = ban_check(Chess, Chess.stk[Chess.cnt]);           //黑子则进行禁手判断
        flag_win = win_check(Chess, Chess.stk[Chess.cnt]);
        if (flag_win) exit_game(Turn?"恭喜白方获胜！":"恭喜黑方获胜！");
        if (flag_ban) exit_game("黑方触犯禁手，判白方胜");
        Turn ^= 1;                                                              //黑白手互换
    }
    exit_game("棋盘已落满，双方平局，游戏结束……");
}