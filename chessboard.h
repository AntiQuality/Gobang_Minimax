#ifndef _GUARD_CHESSBOARD_H_
#define _GUARD_CHESSBOARD_H_

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

struct Point
{
    int x,y;
};
struct Chessboard
{
    int cnt,mp[N+5][N+5];
    struct Point stk[StepN+5];
};

void board_init(struct Chessboard*);                                //为棋盘初始化
void board_display(struct Chessboard);                              //打印当前的棋盘
int board_evaluation(struct Chessboard, int Turn);                  //评估当前棋面的分数，以Turn方的视角
bool board_in(struct Point);                                        //判断点是否在棋盘内
bool board_in_i(int, int);                                          //判断点是否在棋盘内，int版
struct Chessboard board_step(struct Chessboard, struct Point, int); //为棋盘走上新的一步

#endif