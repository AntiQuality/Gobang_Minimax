#include"headers.h"

extern int Turn;
extern struct Chessboard Chess;

bool first_step_middle(struct Chessboard now)
{
    return curx==((1+N)>>1)&&cury==((1+N)>>1);
}
int gobang_white_dfs(struct Chessboard now, int depth, int Turn)
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
                score_tmp = gobang_white_dfs(tmp, depth-1, Turn^1);
                if (score < -score_tmp){
                    score = -score_tmp;
                }
            }
        }
    return score;
}
void gobang_white(struct Chessboard now)                                        //电脑执白棋
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
                score_tmp = gobang_white_dfs(tmp, SEARCH_DEPTH*2-1, Turn^1);
                if (score < -score_tmp){
                    res = tmp, score = -score_tmp;
                }
            }
        }
    }
    Chess = res;
}
void gobang_pve_white(void)
{
    int Round;
    bool flag_ban,flag_win;

    printf("---------Welcome to GAMEMODE#2  人机对战（电脑执白）---------\n");
    board_init(&Chess);
    board_display(Chess);
    for (Round=1; Round<=N*N; Round++)
    {
        if (!Turn) input_pos(Chess);
        else{
            gobang_white(Chess);
        }
        board_display(Chess);
        if (Round==1&&!first_step_middle(Chess))
            exit_game("黑方第一着必须要下在天元处！");
        if (!Turn) flag_ban = ban_check(Chess, Chess.stk[Chess.cnt]);           //黑子则进行禁手判断
        flag_win = win_check(Chess, Chess.stk[Chess.cnt]);
        if (flag_win) exit_game(Turn?"恭喜白方获胜！":"恭喜黑方获胜！");
        if (flag_ban) exit_game("黑方触犯禁手，判白方胜");
        Turn ^= 1;
    }
    exit_game("棋盘已落满，双方平局，游戏结束……");
}