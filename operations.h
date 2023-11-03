#ifndef _GUARD_OPERATIONS_H_
#define _GUARD_OPERATIONS_H_

#include<stdbool.h>

int read(void);                                 //读入一个整型数字
bool read_pos(void);                            //判断读入的棋局坐标是否合法
void input_pos(struct Chessboard);              //输出提示到读入合法坐标为止
bool valid_pos(struct Chessboard, struct Point);//判断一个Point坐标是否可下

#endif