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
	//���ӣ�side��ʾ��һ��,AIִ������
	bool setPieces(int x, int y, int side);
	//�Ե�ǰ�����ж��Ƿ���ƽ�ֻ���ĳһ��ʤ��,���� X y�����һ���µ�����λ��
	//����ֻ��Ҫ������������Χ�жϾͿ��ԣ�������ÿ��������������ʱ�ͽ����ж�
	//����-1��ʾƽ�֣�����1��ʾ�׷�Ӯ��0��ʾû�г��ֽ�֣�2.��
	int isOver(int x,int y);
	//��֦�㷨�������λ��
	//int alphaBeta(POS& p);
	int alphaBeta(int player, int alpha, int beta, int x,int y,int level);
	int alphaBeta(int player);
//private:
	int board[15][15];//���ڱ�ʾ����
	//������ʾ���˶��ٿ���
	int pieces = 0;
	//�����ӵ��������
	int evaluate(int x, int y,int side);
	//��һ��������������Ӧ�ķ���
	int getScore(vector<int> vec);
	//������һ����������趨�����ֻ����һƬ����������
	int roix1=7;
	int roiy1=7;
	int roix2=7;
	int roiy2=7;
	//��ÿ��ƶ�����
	void getMove(vector<POS>& vec);
	/*int maxValue(int b[15][15], int alpha, int beta,POS& p);
	int minValue(int b[15][15], int alpha, int beta, POS& p);*/
};


