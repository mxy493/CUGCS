//#include "stdafx.h"
#include "CHESS.h"

CHESS::CHESS()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			board[i][j] = 0;
		}
	}
}

bool CHESS::setPieces(int x, int y, int side)
{
	if (board[x][y] == 0)
	{
		board[x][y] = side;
		pieces++;
		//�ж��Ƿ���Ҫ�޸�ROI
		roix1 = (roix1 < (x - 2) ? roix1 : (x - 2));
		roix2 = (roix2 > (x + 2) ? roix2 : (x + 2));
		roiy1 = (roiy1 < (y - 2) ? roiy1 : (y - 2));
		roiy2 = (roiy2 >(y + 2) ? roiy2 : (y + 2));
		if (roix1 < 0)
			roix1 = 0;
		if (roix2>14)
		{
			roix2 = 14;
		}
		if (roiy1<0)
		{
			roiy1 = 0;
		}
		if (roiy2>14)
		{
			roiy2 = 14;
		}
		return true;
	}
	return false;
}

int CHESS::isOver(int x,int y)
{
	//if(pieces==255)
	//�����ӵ��ĸ������жϼ���
	//������ˮƽ�����ж�
	int curSide = board[x][y];
	int tempx = x; int tempy = y;
	//vector<int> horize;
	int horize = 1;//��¼ˮƽ������ͬ�ĸ���
	while (tempx>=0)
	{
		tempx--;
		if (board[tempx][y]==curSide)
		{
			//����ߵ�
			//horize.push_back(curSide);
			horize++;
			if (horize==5)
			{
				return curSide;
			}
		}
		else
		{
			break;
		}
	}
	tempx = x;
	while (tempx <15)
	{
		tempx++;
		if (board[tempx][y] == curSide)
		{
			//���ұߵ�
			//horize.push_back(curSide);
			horize++;
			if (horize == 5)
			{
				return curSide;
			}
		}
		else
		{
			break;
		}
	}
	//��ֱ����
	int vertical = 1;
	while (tempy >= 0)
	{
		tempy--;
		if (board[x][tempy] == curSide)
		{
			//���ϱߵ�
			vertical++;
			if (vertical == 5)
			{
				return curSide;
			}
		}
		else
		{
			break;
		}
	}
	tempy = y;
	while (tempy <15)
	{
		tempy++;
		if (board[x][tempy] == curSide)
		{
			//���±ߵ�
			vertical++;
			if (vertical == 5)
			{
				return curSide;
			}
		}
		else
		{
			break;
		}
	}
	//б����1
	tempx = x;
	tempy = y;
	int xuyd = 1;
	while (tempx>=0&&tempy<15)
	{
		tempx--;
		tempy++;
		if (board[tempx][tempy] == curSide)
		{
			xuyd++;
			if (xuyd==5)
			{
				return curSide;
			}
		}
		else
		{
			break;
		}
	}
	tempx = x;
	tempy = y;
	while (tempx < 15 && tempy>=0)
	{
		tempx++;
		tempy--;
		if (board[tempx][tempy] == curSide)
		{
			xuyd++;
			if (xuyd == 5)
			{
				return curSide;
			}
		}
		else
		{
			break;
		}
	}
	//б����2
	tempx = x;
	tempy = y;
	int xdyu = 1;
	while (tempx >= 0 && tempy >= 0)
	{
		tempx--;
		tempy--;
		if (board[tempx][tempy] == curSide)
		{
			xdyu++;
			if (xdyu == 5)
			{
				return curSide;
			}
		}
		else
		{
			break;
		}
	}
	tempx = x;
	tempy = y;
	while (tempx < 15 && tempy <15)
	{
		tempx++;
		tempy++;
		if (board[tempx][tempy] == curSide)
		{
			xdyu++;
			if (xdyu == 5)
			{
				return curSide;
			}
		}
		else
		{
			break;
		}
	}
	//���е������ʾûӴʤ��
	if (pieces == 255)
	{
		//�����ˣ�ƽ��
		return -1;
	}
	return 0;
}

int CHESS::evaluate(int x, int y,int side)
{
	board[x][y] = side;
	//���赱ǰ��Ҫ������ x,y����õ�ǰ�÷�
	//����������ֻ��������ڵ�4����������Ӳ���Ӱ�죬����ֻȡ4����������ӽ����ж�
	int xbegin = x - 4;
	int xend = x + 4;
	if (xbegin < 0)
	{
		xbegin = 0;
	}
	if (xend>14)
	{
		xend = 14;
	}
	vector<int> horize;
	for (int i = xbegin; i < xend + 1; i++)
	{
		horize.push_back(board[i][y]);
	}
	int ybegin = y - 4;
	int yend = y + 4;
	if (ybegin < 0)
	{
		ybegin = 0;
	}
	if (yend>14)
	{
		yend = 14;
	}
	vector<int> vertical;
	for (int i = ybegin; i < yend+1; i++)
	{
		vertical.push_back(board[x][i]);
	}
	vector<int> xuyu;
	for (int i = xbegin, j = ybegin; i < xend&&j < yend; i++, j++)
	{
		xuyu.push_back(board[i][j]);
	}
	vector<int> xuyd;
	for (int i = xbegin, j = yend; i <= xend&&j >=ybegin; i++, j--)
	{
		xuyd.push_back(board[i][j]);
	}
	int score1 = getScore(horize);
	int score2 = getScore(vertical);
	int score3 = getScore(xuyd);
	int score4 = getScore(xuyu);


	board[x][y] = 0;//ʹ�ú�Ҫ��λ
	return score1+score2+score3+score4;
}

int CHESS::getScore(vector<int> vec)
{
	if (vec.size()<5)
	{
		return 0;
	}
	else
	{
		//���������Ը������ͽ����ж�
		//����AIִ���ӣ����жϺ��ӣ��γɻ���100�֣�����50�����10�֣������5���򷵻�500
		int score = 0;
		bool isBlack = false;
		bool isWhie = false;
		bool whiteStart = (vec[0] == WHITE);
		int blackCount = (vec[0] == BLACK);
		//������������ÿռ䣬�����˺��ӻ��߿��Էź��ӵ������ռ�
		int bstart=-1, bend=-1;
		int wstart = -1, wend = -1;
		int mostLongW = 0;
		int mostLongB = 0;
		int indexBack[2];//���ڱ��������λ�õ���ֹ,����ҿ�
		int indexWhite[2];
		for (int i = 1; i < vec.size(); i++)
		{
			/*if (vec[i] == BLACK)
			{
				isBlack = true;
				blackCount++;
			}
			if (!isBlack)
			{
				if (blackCount==5)
				{
					return 500;
				}
				if (blackCount==4)
				{
					if (!whiteStart&&vec[i] == 0)
					{
						//���ģ�100
						score += 100;
					}
					else if (!whiteStart&&vec[i]==WHITE)
					{
						score += 10;
					}
				}
				if (blackCount==3)
				{

				}

			}*/
			if (vec[i] != WHITE&& bstart ==-1)
			{
				bstart = i;
			}
			if (vec[i] != BLACK && wstart == -1)
			{
				wstart = i;
			}
			if (vec[i]==WHITE&& bstart !=-1)
			{
				bend = i;
				int temp = bend - bstart;
				if (temp>mostLongB)
				{
					mostLongB = temp;
					indexBack[0] = bstart;
					indexBack[1] = bend;
					bstart = -1;
					bend = -1;
				}
			}
			if (vec[i] == BLACK && wstart != -1)
			{
				wend = i;
				int temp = wend - wstart;
				if (temp>mostLongW)
				{
					mostLongW = temp;
					indexWhite[0] = wstart;
					indexWhite[1] = wend;
					wstart = -1;
					wend = -1;
				}
			}
		}
		if (mostLongB>=5)
		{
			//��ʱ��ʾ�п����������ӣ���������
			//if (indexBack[0]==0)
			//{
			int count = 0;
			for (int i = indexBack[0]; i < indexBack[1]; i++)
			{
				if (vec[i] == BLACK)
				{
					count++;
				}
			}

			//}
			score = count * 10;

		}
		else if (mostLongW>=5)
		{
			int count = 0;
			for (int i = indexWhite[0]; i < indexWhite[1]; i++)
			{
				if (vec[i] == WHITE)
				{
					count++;
				}
			}
			score = -count * 10;
		}

		return score;
	}
}

void CHESS::getMove(vector<POS>& vec)
{
	//ʵ��˼·��Ҫ����ROI�����ڶԿ������ӵĸ�����������֣�Ȼ�����ѡ��һЩ����ĵ��������
	//Ϊ�����ó��������������Ƚ����е㷵�أ��������Ż�
	for (int i = roix1; i <= roix2; i++)
	{
		for (int j = roiy1; j <= roiy2; j++)
		{
			//vec.push_back(POS(i, j));
			if (board[i][j]==0)
			{
				vec.push_back(POS(i, j));
			}
		}
	}
}

//int CHESS::alphaBeta(POS & p)
//{
//	return maxValue(board, INFINITY, minINFINITY, p);
//	//return 0;
//}
//
//int CHESS::maxValue(int b[15][15], int alpha, int beta, POS & p)
//{
//
//	return 0;
//}
//
//int CHESS::minValue(int b[15][15], int alpha, int beta, POS & p)
//{
//	return 0;
//}

int CHESS::alphaBeta(int player, int alpha, int beta,int x=0,int y=0,int level=0)
{
    if(level!=0)
        board[x][y] = player;
	if (level == 4||isOver(x,y))
	{
		return evaluate(x, y, player);
	}
	vector<POS> posVec;
	getMove(posVec);
	if (player == BLACK)
	{
		for (auto s : posVec)
		{
			int score = alphaBeta(WHITE, alpha, beta, s.x, s.y, level + 1);
			if (score>alpha)
			{
				alpha = score;
			}
			if (alpha>beta)
			{
				return alpha;
			}
		}
		return alpha;
	}
	if (player==WHITE)
	{
		for (auto s : posVec)
		{
			int score = alphaBeta(BLACK, alpha, beta, s.x, s.y, level + 1);
			if (score<beta)
			{
				beta = score;
			}
			if (alpha>beta)
			{
				return beta;
			}
		}
		return beta;
	}
    if(level!=0)
        board[x][y] = 0;
}

int CHESS::alphaBeta(int player)
{
	return 0;
}
