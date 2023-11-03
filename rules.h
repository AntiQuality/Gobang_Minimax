#ifndef _GUARD_RULES_H_
#define _GUARD_RULES_H_

#include<stdbool.h>

int count_connection(struct Chessboard, struct Point, int);     //计数某个点不间断相邻的同色棋子数量，如果有特殊查找的fnd则立即返回
bool win_check(struct Chessboard, struct Point);                //检查当前棋局是否胜利
bool ban_check(struct Chessboard, struct Point);                //检查某一个位置是否是禁手
int count_4(struct Chessboard, struct Point);                   //检查四
int count_open_4(struct Chessboard, struct Point);              //检查活四
int count_open_3(struct Chessboard, struct Point);              //检查活三

#endif