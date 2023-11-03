//Conducted by aq
#include<stdio.h>

#include"headers.h"
#include"declarations.h"

int game_mode;

extern void gobang_pvp();              //人人对战
extern void gobang_pve_black();        //人机对战，电脑白棋
extern void gobang_pve_white();        //人机对战，电脑黑棋
extern void gobang_pve_auto();         //机机对战，电脑自动
int main()
{
    srand(time(0));                    //准备随机数
    printf("--------五子棋（2022-2023秋季学期限定版）Conducted by aq--------\n");
    do{
        printf("请选择游戏模式：\n\t1.人人对战\n\t2.人机对战（电脑执白）\n\t3.人机对战（电脑执黑）\n\t4.机机对战（电脑自动）");
        printf("我的选择是（输入1~4中的一个数）：");
        game_mode = read();
    }while (game_mode < 1||game_mode > 4);
    printf("--------------------My choice is: %d--------------------\n",game_mode);
    switch (game_mode)
    {
        case 1:
            gobang_pvp();
            break;
        case 2: 
            gobang_pve_white();
            break;
        case 3:
            gobang_pve_black();
            break;
        case 4:
            gobang_pve_auto();
            break;
        default:
            break;
    }
    return 0;
}