const int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
const int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};           //分别对应水平、垂直、正对角线、反对角线四个方向

struct Chessboard Chess;
int Turn;                                               //目前是黑棋落子还是白棋落子，0代表黑棋，1代表白棋