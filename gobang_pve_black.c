#include"headers.h"

extern int Turn;
extern struct Chessboard Chess;

void gobang_white(struct Chessboard);
int gobang_black_dfs(struct Chessboard now, int depth, int Turn)
{
    struct Point p;
    struct Chessboard tmp;
    int score,score_tmp;

    score = -INF;
    if (!depth) return -board_evaluation(now, Turn^1);
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
        {
            p = point_assign(i, j);
            if (valid_pos(now, p)){
                tmp = board_step(now, p, Turn);
                score_tmp = gobang_black_dfs(tmp, depth-1, Turn^1);
                if (score < -score_tmp){
                    score = -score_tmp;
                }
            }
        }
    return score;
}
void gobang_black(struct Chessboard now)                                        //电脑执黑棋
{
    struct Point p;
    struct Chessboard res,tmp;
    int score,score_tmp;

    score = -INF;
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N; j++)
        {
            p = point_assign(i, j);
            if (valid_pos(now, p)){
                tmp = board_step(now, p, Turn);
                if (!ban_check(tmp, p)){
                    score_tmp = gobang_black_dfs(tmp, SEARCH_DEPTH*2-1, Turn^1);
                    if (score < -score_tmp){
                        res = tmp, score = -score_tmp;
                    }
                }
            }
        }
    }
    Chess = res;

    if (score==-INF){
        gobang_white(Chess);
    }else{
        Chess = res;
    }
}
void gobang_pve_black(void)
{
    int Round;
    bool flag_ban,flag_win;

    printf("---------Welcome to GAMEMODE#3  人机对战（电脑执黑）---------\n");
    board_init(&Chess);
    board_display(Chess);
    for (Round=1; Round<=N*N; Round++)
    {
        if (Turn) input_pos(Chess);
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