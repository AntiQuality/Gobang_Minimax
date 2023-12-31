# Gobang with Minimax Search in C

> 中国科学院大学2022-2023秋季学期 《程序设计基础与实验（C语言）》课程大作业——基于Min-Max搜索策略的五子棋对战程序

采用Min-Max搜索策略的C语言五子棋，课程内迭代至1.4版本，更新日志如下所示。

游戏模式一共四种：
1. 人人对战
2. 人机对战（电脑执白）
3. 人机对战（电脑执黑）
4. 机机对战（电脑自动）

程序入口为```gobang_main.c```，各函数功能注释在```.h```文件中给出。

大作业体验很好，第一次感受工程代码的构建方式，PK大赛划水进入十六强看各路神仙打架，DDL前30秒提交非常锻炼心态，下次还会再来。

## version 1.1 20221226
1. 增加了电脑auto对战，方便调试
2. 暂时禁用了禁手
3. 修正了count_connection函数把空格也算在内的bug
4. 修正了board_evaluation函数，
5. 总结：终于不再是随机落子了

## version 1.2 20221229
0. 修正了落子board_step和判定有效落子位置valid_pos函数，是对于给定的棋局而不是全局棋盘
1. 为白方增加了简单的min-max搜索，不带alpha-beta剪枝
rec. min-max搜索每层都是对权值取负号，而不是正负交替
2. 修正了活四和活三的禁手判断
3. 棋局评估函数优化权值设置
4. 棋局评估函数考虑了对手的棋面

## version 1.3 20221231
0. 重新理解了活四和四四禁手：活四是指必胜的四；四四禁手指构成两个四，而非两个活四
1. 增加了判定活四的计数函数，修正了min-max不围堵活三的问题
2. 修正了判定活三的计数函数，修正了三三禁手的判定函数
3. 修正了黑方落子时判定禁手的问题
4. 进一步优化了打分，增加了活四的分值，同时突出了五连的分值，防止多个活四对潜在五连的时候不围堵
rec. 实测发现黑方只打分不搜索有时候也能战胜min-max搜索两层的白方
rec. 当活三变成冲三的时候，打分函数会优先跳四而不是连四，可能有一些高明考虑在的

## version 1.4 20221231
1. 还是把黑棋也加个搜索试试看吧
2. 进一步修正了活三的判定，活三+冲四不算三三禁手

## to-do list:
1. 增加悔棋功能
