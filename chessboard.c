#include"headers.h"

extern int Turn;

void board_init(struct Chessboard *now)
{
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            (*now).mp[i][j] = BLANK_MP;
}
void board_display(struct Chessboard now)
{
    char tar[8] = "";
    struct Chessboard prt;

    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            prt.mp[i][j] = BLANK_MP;
    for (int i=1; i<=N; i++)
    {
        prt.mp[1][i] = 11;      //┬
        prt.mp[N][i] = 12;      //┴
        prt.mp[i][1] = 13;      //├
        prt.mp[i][N] = 14;      //┤
    }
    prt.mp[1][1] = 15;          //┌
    prt.mp[1][N] = 16;          //┐
    prt.mp[N][1] = 17;          //└
    prt.mp[N][N] = 18;          //┘
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            prt.mp[i][j] = now.mp[i][j]==BLANK_MP?prt.mp[i][j]:now.mp[i][j];
    if (now.cnt) prt.mp[curx][cury] += DET_NOW;
    for (int i=1; i<=N; i++)
    {
        printf("%2d ",N-i+1);      //行数字序号
        for (int j=1; j<=N; j++)
        {
            switch (prt.mp[i][j])
            {
                case BLANK_MP: strcpy(tar, "┼");break;
                case 11: strcpy(tar, "┬");break;
                case 12: strcpy(tar, "┴");break;
                case 13: strcpy(tar, "├");break;
                case 14: strcpy(tar, "┤");break;
                case 15: strcpy(tar, "┌");break;
                case 16: strcpy(tar, "┐");break;
                case 17: strcpy(tar, "└");break;
                case 18: strcpy(tar, "┘");break;
                case BLACK_BEF: strcpy(tar, "●");break;
                case WHITE_BEF: strcpy(tar, "○");break;
                case BLACK_NOW: strcpy(tar, "▲");break;
                case WHITE_NOW: strcpy(tar, "△");break;
                default: 
                    exit_game("\nUnidentified Cell");
                    break;
            } 
            printf("%s",tar);
        }
        puts("");
    }
    printf("%s","   ");
    for (int i=1; i<=N; i++) printf("%c",'A'+i-1);     //列字母序号
    puts("");
}
int board_evaluation(struct Chessboard now, int Turn)
{
    int ret,mid,coef;
    struct Point p;

    ret = 0, mid = (N+1)>>1;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            if (now.mp[i][j]!=BLANK_MP)
            {
                coef = (now.mp[i][j]==(Turn?WHITE_BEF:BLACK_BEF))?1:-2;
                p = point_assign(i, j);
                ret += coef*(count_connection(now, p, 5)==5)*5000000;
                ret += coef*count_open_4(now, p)*100000;
                ret += coef*count_4(now, p)*5000;
                ret += coef*count_open_3(now, p)*5000;
                ret += coef*(count_connection(now, p, -1)==3)*10;
                ret += coef*(count_connection(now, p, -1)==2)*(rand()%3+2);
                ret += coef*(mid-abs(i-mid)+rand()%2);
                ret += coef*(mid-abs(j-mid)+rand()%2);
            }
    return ret;
}
bool board_in(struct Point now)
{
    return !(now.x < 1||now.x > N||now.y < 1||now.y > N);
}
bool board_in_i(int x, int y)
{
    return !(x < 1||x > N||y < 1||y > N);
}
struct Chessboard board_step(struct Chessboard now, struct Point p, int Turn)
{
    struct Chessboard ret = now;

    ret.stk[++ret.cnt] = p;
    ret.mp[p.x][p.y] = Turn?WHITE_BEF:BLACK_BEF;
    return ret;
}