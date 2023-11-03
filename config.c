#include"headers.h"

extern struct Chessboard Chess;

struct Point point_assign(int x, int y)
{
    struct Point ret;
    ret.x = x, ret.y = y;
    return ret;
}
void exit_game(char info[])
{
    printf("\n%s\n",info);
    printf("-----下面是本场棋局棋局信息-----");
    printf("总着数：%d\n",Chess.cnt);
    for (int i=1; i<=Chess.cnt; i++)
    {
        printf(i&1?"●":"○");
        printf("%d: %c%d\n",i,'A'+Chess.stk[i].y-1,N-Chess.stk[i].x+1);
    }
    exit(0);
}