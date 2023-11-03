#include"headers.h"

extern int Turn;
extern int dx[],dy[];
extern struct Chessboard Chess;

int count_connection(struct Chessboard now, struct Point p, int fnd)
{
    int ret,cnt;
    int tx,ty;

    ret = 0;
    if (now.mp[p.x][p.y]==BLANK_MP) return ret;
    for (int i=1; i<=DIR_CNT; i++)
    {
        cnt = 1;
        for (int det_id=i*2-2; det_id<i*2; det_id++)
        {
            tx = p.x+dx[det_id], ty = p.y+dy[det_id];
            while (board_in_i(tx, ty)&&now.mp[tx][ty]==now.mp[p.x][p.y])
                ++cnt, tx += dx[det_id], ty += dy[det_id];
        }
        if (cnt==fnd) return fnd;
        ret = ret < cnt?cnt:ret;
    }
    return ret;
}
bool win_check(struct Chessboard now, struct Point p)
{
    return count_connection(now, p, 5)==5;
}
bool overline_check(struct Chessboard now, struct Point p)
{
    return count_connection(now, p, -1) > 5;
}
int count_open_4(struct Chessboard now, struct Point p)                         //xoooox
{
    int cnt,blank_cnt,p_cnt;
    int tx,ty;
    bool dir_flag;

    cnt = 0;
    for (int det_id=0; det_id < DIR_CNT*2; det_id+=2)
    {
        dir_flag = false;
        for (int i=-3; i<=0&&!dir_flag; i++)
        {
            p_cnt = blank_cnt = 0;
            for (int j=0; j<=3; j++)
            {
                tx = p.x+(i+j)*dx[det_id];
                ty = p.y+(i+j)*dy[det_id];
                if (board_in_i(tx, ty)){
                    p_cnt += now.mp[tx][ty]==now.mp[p.x][p.y];
                }
            }
            tx = p.x+(i-1)*dx[det_id], ty = p.y+(i-1)*dy[det_id];
            blank_cnt += board_in_i(tx, ty)?(now.mp[tx][ty]==BLANK_MP?1:0):0;
            tx = p.x+(i+4)*dx[det_id], ty = p.y+(i+4)*dy[det_id];
            blank_cnt += board_in_i(tx, ty)?(now.mp[tx][ty]==BLANK_MP?1:0):0;
            dir_flag |= (p_cnt==4)&&(blank_cnt==2);
        }
        if (dir_flag) ++cnt;
    }
    return cnt;
}
int count_4(struct Chessboard now, struct Point p)
{
    int cnt,blank_cnt,p_cnt;
    int tx,ty;
    bool dir_flag;

    cnt = 0;
    for (int det_id=0; det_id < DIR_CNT*2; det_id+=2)
    {
        dir_flag = false;
        for (int i=-4; i<=0&&!dir_flag; i++)
        {
            p_cnt = blank_cnt = 0;
            for (int j=0; j<=4; j++)
            {
                tx = p.x+(i+j)*dx[det_id];
                ty = p.y+(i+j)*dy[det_id];
                if (board_in_i(tx, ty)){
                    p_cnt += now.mp[tx][ty]==now.mp[p.x][p.y];
                    blank_cnt += now.mp[tx][ty]==BLANK_MP;
                }
            }
            dir_flag |= (p_cnt==4)&&(blank_cnt==1);
        }
        if (dir_flag) ++cnt;
    }
    return cnt;
}
int count_open_3(struct Chessboard now, struct Point p)
{
    int cnt,blank_cnt,p_cnt,exa_cnt;
    int tx,ty;
    bool dir_flag,ban_flag;

    cnt = 0;
    for (int det_id=0; det_id < DIR_CNT*2; det_id+=2)                            //xoooxx || xxooox
    {
        dir_flag = false;
        for (int i=-2; i<=0&&!dir_flag; i++)
        {
            p_cnt = blank_cnt = 0;
            for (int j=0; j<=2; j++)
            {
                tx = p.x+(i+j)*dx[det_id];
                ty = p.y+(i+j)*dy[det_id];
                if (board_in_i(tx, ty)){
                    p_cnt += now.mp[tx][ty]==now.mp[p.x][p.y];
                    // blank_cnt += now.mp[tx][ty]==BLANK_MP;
                }
            }
            ban_flag = false;
            tx = p.x+(i-1)*dx[det_id], ty = p.y+(i-1)*dy[det_id];
            blank_cnt += board_in_i(tx, ty)?(now.mp[tx][ty]==BLANK_MP?1:0):0;
            tx = p.x+(i+3)*dx[det_id], ty = p.y+(i+3)*dy[det_id];
            blank_cnt += board_in_i(tx, ty)?(now.mp[tx][ty]==BLANK_MP?1:0):0;
            tx = p.x+(i+4)*dx[det_id], ty = p.y+(i+4)*dy[det_id];
            blank_cnt += board_in_i(tx, ty)?(now.mp[tx][ty]==BLANK_MP?1:0):0;
            tx = p.x+(i-2)*dx[det_id], ty = p.y+(i-2)*dy[det_id];
            if (board_in_i(tx, ty)) ban_flag |= now.mp[tx][ty]==now.mp[p.x][p.y];
            tx = p.x+(i+5)*dx[det_id], ty = p.y+(i+5)*dy[det_id];
            if (board_in_i(tx, ty)) ban_flag |= now.mp[tx][ty]==now.mp[p.x][p.y];
            dir_flag |= !ban_flag&&(p_cnt==3)&&(blank_cnt==3);

            blank_cnt = 0, ban_flag = false;
            tx = p.x+(i-1)*dx[det_id], ty = p.y+(i-1)*dy[det_id];
            blank_cnt += board_in_i(tx, ty)?(now.mp[tx][ty]==BLANK_MP?1:0):0;
            tx = p.x+(i+3)*dx[det_id], ty = p.y+(i+3)*dy[det_id];
            blank_cnt += board_in_i(tx, ty)?(now.mp[tx][ty]==BLANK_MP?1:0):0;
            tx = p.x+(i-2)*dx[det_id], ty = p.y+(i-2)*dy[det_id];
            blank_cnt += board_in_i(tx, ty)?(now.mp[tx][ty]==BLANK_MP?1:0):0;
            tx = p.x+(i-3)*dx[det_id], ty = p.y+(i-3)*dy[det_id];
            if (board_in_i(tx, ty)) ban_flag |= now.mp[tx][ty]==now.mp[p.x][p.y];
            tx = p.x+(i+4)*dx[det_id], ty = p.y+(i+4)*dy[det_id];
            if (board_in_i(tx, ty)) ban_flag |= now.mp[tx][ty]==now.mp[p.x][p.y];
            dir_flag |= !ban_flag&&(p_cnt==3)&&(blank_cnt==3);
        }
        if (dir_flag) ++cnt;
    }
    for (int det_id=0; det_id < DIR_CNT*2; det_id++)                            //xooxox
    {
        dir_flag = false;
        for (int i=-3; i<=0&&!dir_flag; i++)
        {
            if (i==-2) continue;
            p_cnt = blank_cnt = 0;
            for (int j=0; j<=3; j++)
            {
                if (j==2) continue;
                tx = p.x+(i+j)*dx[det_id];
                ty = p.y+(i+j)*dy[det_id];
                if (board_in_i(tx, ty)){
                    p_cnt += now.mp[tx][ty]==now.mp[p.x][p.y];
                    // blank_cnt += now.mp[tx][ty]==BLANK_MP;
                }
            }
            tx = p.x+(i-1)*dx[det_id], ty = p.y+(i-1)*dy[det_id];
            blank_cnt += board_in_i(tx, ty)?(now.mp[tx][ty]==BLANK_MP?1:0):0;
            tx = p.x+(i+2)*dx[det_id], ty = p.y+(i+2)*dy[det_id];
            blank_cnt += board_in_i(tx, ty)?(now.mp[tx][ty]==BLANK_MP?1:0):0;
            tx = p.x+(i+4)*dx[det_id], ty = p.y+(i+4)*dy[det_id];
            blank_cnt += board_in_i(tx, ty)?(now.mp[tx][ty]==BLANK_MP?1:0):0;

            dir_flag |= (p_cnt==3)&&(blank_cnt==3);
        }
        if (dir_flag) ++cnt;
    }
    return cnt;
}
bool double_4_check(struct Chessboard now, struct Point p)
{
    return count_4(now, p) >= 2;
}
bool double_open_3_check(struct Chessboard now, struct Point p)
{
    return count_open_3(now, p) >= 2;
}
bool ban_check(struct Chessboard now, struct Point p)
{
    if (count_connection(now, p, 5)==5) return false;
    if (overline_check(now, p)) return true;
    if (double_4_check(now, p)) return true;
    if (double_open_3_check(now, p)) return true;
    return false;
}