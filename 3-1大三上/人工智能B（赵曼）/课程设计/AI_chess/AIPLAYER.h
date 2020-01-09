#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
//定义的AI
//#include "CHESS.h"
#include<vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define WHITE 1
#define BLACK 2
#define INFINITY INT_MAX //正无穷大整型
#define minINFINITY -INFINITY //负无穷float型
#define LEVEl 4 //搜索深度

#define USEALPHAONE false

//各棋型数量
struct TEMPLATE
{
    int five = 0;//五连个数			1
    int four = 0;//活四个数			2
    int deadFour = 0;//眠四个数		3
    int three = 0;//活三个数			4
    int deadThree = 0;//眠三个数		5
    int two = 0;//活二个数			6
    int deadTwo = 0;//眠二个数		7
    int one = 0;//活一个数			8
    int deadOne = 0;//眠一个数		9
    TEMPLATE& operator+=(int n);
};

//记录落子位置以及对落子进行评价
struct POS
{
    int x = 0;
    int y = 0;
    POS() = default;
    POS(int mx, int my) { x = mx; y = my; }
    bool operator ==(const POS& p)
    {
        return x == p.x && y == p.y;
    }
};

//对落子记录分数
struct EvaPos
{
    POS p;
    int n = 0;
    EvaPos() = default;
    EvaPos(POS rp, int mn)
    {
        p = rp;
        n =mn ;
    }
    bool operator==(const EvaPos& rp)
    {
        return p == rp.p;
    }
    bool operator<(const EvaPos& rp)
    {
        return n < rp.n;
    }
};

struct GreaterFun
{
    bool operator()(const EvaPos& lp, const EvaPos&rp)
    {
        return lp.n > rp.n;
    }
};

class AIPLAYER
{
public:
    int posx;//得到的走法
    int posy;
    //落子
    int tempx=0;
    int tempy=0;
    //下面这一组变量用于设定活动区域，只在这一片区域内搜索
    //在有新的落子时对ROI进行更新
    int roix1 = 4;
    int roiy1 = 4;
    int roix2 = 11;
    int roiy2 = 11;

    AIPLAYER();
    ~AIPLAYER();
    //落子
    void setPieces(int board[15][15]);
    int alphaBeta(int player, int alpha, int beta, int board[15][15], int level);
    //评价函数，其中x,y表示上一次落子的位置
    int evaluate( int board[15][15],int side);
    //对某一落子位置所在的四条边的某一边评价
    int getScore(const vector<int>& vec);
    void getMove(vector<POS>& vec, int board[15][15]);
    //新版获得新状态的重载函数
    void getMove(vector<POS>& vec, int board[15][15],int side);
    //对一个向量进行是否有五连的匹配,返回值表示匹配个数
    //由于有五连之后一定游戏终止，所以这时搜索到一个就返回
    int matchFive(int Side, const vector<int>& vec);
    //活四匹配
    int matchFour(int side, const vector<int>& vec);
    //死四匹配
    int matchDeadFour(int side, const vector<int>& vec);
    //活三匹配
    int matchThree(int side, const vector<int>& vec);
    //对冲3评价
    int matchDeadThree(int side, const vector<int>& vec);
    //活二匹配
    int matchTwo(int side, const vector<int>& vec);
    //输入一串连续空间，对连续空间中的棋型输出数量
    //注意输入的start是开始位置，end是结束的后一个，和迭代器比较相似
    void matchTemplate(int start, int end, const vector<int>& vec, TEMPLATE& tem);
    //判断棋型，返回0表示没有，剩下的按照结构顺序匹配
    int getTemplate(int aheadCount, int tailCount, int aheadNull, int midNull, int tailnull);
    //给定一个向量，寻找其中的连续空间(长度需要大于5），
    void getSpace(const vector<int>& vec, int side, vector<POS>& p);
    //游戏结束
    bool isOver(int x, int y, int tmpboard[15][15]);
};



