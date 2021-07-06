#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
//�����AI
//#include "CHESS.h"
#include<vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define WHITE 1
#define BLACK 2
#define INFINITY INT_MAX //�����������
#define minINFINITY -INFINITY //������float��
#define LEVEl 4 //�������

#define USEALPHAONE false

//����������
struct TEMPLATE
{
    int five = 0;//��������			1
    int four = 0;//���ĸ���			2
    int deadFour = 0;//���ĸ���		3
    int three = 0;//��������			4
    int deadThree = 0;//��������		5
    int two = 0;//�������			6
    int deadTwo = 0;//�߶�����		7
    int one = 0;//��һ����			8
    int deadOne = 0;//��һ����		9
    TEMPLATE& operator+=(int n);
};

//��¼����λ���Լ������ӽ�������
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

//�����Ӽ�¼����
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
    int posx;//�õ����߷�
    int posy;
    //����
    int tempx=0;
    int tempy=0;
    //������һ����������趨�����ֻ����һƬ����������
    //�����µ�����ʱ��ROI���и���
    int roix1 = 4;
    int roiy1 = 4;
    int roix2 = 11;
    int roiy2 = 11;

    AIPLAYER();
    ~AIPLAYER();
    //����
    void setPieces(int board[15][15]);
    int alphaBeta(int player, int alpha, int beta, int board[15][15], int level);
    //���ۺ���������x,y��ʾ��һ�����ӵ�λ��
    int evaluate( int board[15][15],int side);
    //��ĳһ����λ�����ڵ������ߵ�ĳһ������
    int getScore(const vector<int>& vec);
    void getMove(vector<POS>& vec, int board[15][15]);
    //�°�����״̬�����غ���
    void getMove(vector<POS>& vec, int board[15][15],int side);
    //��һ�����������Ƿ���������ƥ��,����ֵ��ʾƥ�����
    //����������֮��һ����Ϸ��ֹ��������ʱ������һ���ͷ���
    int matchFive(int Side, const vector<int>& vec);
    //����ƥ��
    int matchFour(int side, const vector<int>& vec);
    //����ƥ��
    int matchDeadFour(int side, const vector<int>& vec);
    //����ƥ��
    int matchThree(int side, const vector<int>& vec);
    //�Գ�3����
    int matchDeadThree(int side, const vector<int>& vec);
    //���ƥ��
    int matchTwo(int side, const vector<int>& vec);
    //����һ�������ռ䣬�������ռ��е������������
    //ע�������start�ǿ�ʼλ�ã�end�ǽ����ĺ�һ�����͵������Ƚ�����
    void matchTemplate(int start, int end, const vector<int>& vec, TEMPLATE& tem);
    //�ж����ͣ�����0��ʾû�У�ʣ�µİ��սṹ˳��ƥ��
    int getTemplate(int aheadCount, int tailCount, int aheadNull, int midNull, int tailnull);
    //����һ��������Ѱ�����е������ռ�(������Ҫ����5����
    void getSpace(const vector<int>& vec, int side, vector<POS>& p);
    //��Ϸ����
    bool isOver(int x, int y, int tmpboard[15][15]);
};



