#ifndef _GUARD_CONFIG_H_
#define _GUARD_CONFIG_H_

#define N 15                            //五子棋棋盘的大小
#define StepN 225                       //棋局步数的上限
#define BLANK_MP  10                    //空白棋盘
#define BLACK_BEF 20                    //黑子先前落子
#define WHITE_BEF 21                    //白子先前落子
#define BLACK_NOW 30                    //黑子最近落子
#define WHITE_NOW 31                    //白子最近落子
#define DET_NOW 10                      //最近落子与先前落子的编号之差
#define DIR_CNT 4                       //判断相连的共四种方向
#define INF 1E8                         //定义一个无穷大值
#define SEARCH_DEPTH 1                  //Min-Max搜索的轮数，每轮都有一次双方Min-Max搜索

#define curx now.stk[now.cnt].x         //最近落子x坐标
#define cury now.stk[now.cnt].y         //最近落子y坐标

struct Point point_assign(int, int);    //转换一个Point类型
void exit_game(char []);                //退出游戏并输出一段信息

#endif