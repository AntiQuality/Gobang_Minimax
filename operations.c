#include"headers.h"

extern int Turn;
extern struct Chessboard Chess;

int read(void)
{
    int num = 0;
    char ch = getchar();
    for (; !isdigit(ch); ch=getchar())
        ;
    for (; isdigit(ch); ch=getchar())
        num = (num<<1)+(num<<3)+ch-48;
    return num;
}
#define MAX_STRLEN 1000                                             //临时读入字符串的最大长度
bool valid_pos(struct Chessboard now, struct Point p)               //判断一个Point是否是可以落子的
{
    if (!board_in(p)) return false;                                 //输入的位置不在棋盘之内
    if (now.mp[p.x][p.y]!=BLANK_MP) return false;                   //输入的位置已经被下过了
    return true;
}
bool read_pos(void)
{
    static char s[MAX_STRLEN];                                      //节省内存避免每次重新申请
    int tmp_inpx,tmp_inpy;
    struct Point final_inp;

    if (scanf("%s",s)==EOF) exit_game("输入EOF，游戏结束……");          //ctrl+D强制结束
    if ((s[0]<'a'||s[0]>'z')&&(s[0]<'A'||s[0]>'Z')) return false;
    if (strlen(s) > 3||strlen(s) < 2||!isdigit(s[1])) return false;
    tmp_inpx = (s[0]>='a'&&s[0]<='z')?s[0]-'a'+1:s[0]-'A'+1;
    tmp_inpy = s[1]-'0';
    if (strlen(s)==3) tmp_inpy = tmp_inpy*10+s[2]-'0';
    final_inp.x = N-tmp_inpy+1;
    final_inp.y = tmp_inpx;
    if (!valid_pos(Chess, final_inp)) return false;
    Chess = board_step(Chess, final_inp, Turn);
    return true;
}
void input_pos(struct Chessboard now)        //输出提示并读取坐标
{
    if (now.cnt) printf("上一次%s方落子在:%c%d\n",Turn?"黑":"白",'A'+cury-1,N-curx+1);
    printf("现在是%s方落子，请输入落子坐标，格式形如\'A15\'或\'a15\':",Turn?"白":"黑");
    while (!read_pos())
        printf("现在是%s方落子，请输入规范的落子坐标，格式形如\'A15\'或\'a15\':",Turn?"白":"黑");
}