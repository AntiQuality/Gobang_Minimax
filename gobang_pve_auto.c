#include"headers.h"

extern int Turn;
extern struct Chessboard Chess;

void gobang_black(struct Chessboard);
void gobang_white(struct Chessboard);
void gobang_pve_auto(void)
{
    int Round;
    bool flag_ban,flag_win;

    printf("---------Welcome to GAMEMODE#4  机机对战（电脑自动）---------\n");
    board_init(&Chess);
    board_display(Chess);
    for (Round=1; Round<=N*N; Round++)
    {
        if (Turn) gobang_white(Chess);
        else{
            if (Round==1) Chess = board_step(Chess, point_assign(((1+N)>>1), ((1+N)>>1)), Turn);
            else gobang_black(Chess);
        }
        board_display(Chess);
        flag_win = win_check(Chess, Chess.stk[Chess.cnt]);
        if (flag_win) exit_game(Turn?"恭喜白方获胜！":"恭喜黑方获胜！");
        Turn ^= 1;
    }
    exit_game("棋盘已落满，双方平局，游戏结束……");
}