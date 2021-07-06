#pragma once
#include <vector>
using namespace std;
#define WHITE 1
#define BLACK 2
#define INFINITY INT_MAX
#define minINFINITY -INFINITY

struct SCORENODE
{
	int score = 0;
	int index = 0;
};



struct POS
{
	int x = 0;
	int y = 0;
	POS() = default;
	POS(int mx, int my) { x = mx; y = my; }
};

class CHESS
{
public:
	CHESS();
	//下子，side表示哪一方,AI执黑先走
	bool setPieces(int x, int y, int side);
	//对当前棋盘判断是否有平局或者某一方胜利,其中 X y是最近一次下的棋子位置
	//由于只需要在新下棋子周围判断就可以，所以在每次有新棋子落子时就进行判断
	//返回-1表示平局，返回1表示白方赢，0表示没有出现结局，2.黑
	int isOver(int x,int y);
	//剪枝算法获得落子位置
	//int alphaBeta(POS& p);
	int alphaBeta(int player, int alpha, int beta, int x,int y,int level);
	int alphaBeta(int player);
//private:
	int board[15][15];//用于表示棋盘
	//用来表示下了多少颗子
	int pieces = 0;
	//对下子的棋局评价
	int evaluate(int x, int y,int side);
	//给一个向量，其打出对应的分数
	int getScore(vector<int> vec);
	//下面这一组变量用于设定活动区域，只在这一片区域内搜索
	int roix1=7;
	int roiy1=7;
	int roix2=7;
	int roiy2=7;
	//获得可移动序列
	void getMove(vector<POS>& vec);
	/*int maxValue(int b[15][15], int alpha, int beta,POS& p);
	int minValue(int b[15][15], int alpha, int beta, POS& p);*/
};


