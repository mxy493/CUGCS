//#include "stdafx.h"
#include "AIPLAYER.h"
#include <qdebug.h>

TEMPLATE& TEMPLATE::operator+=(int n)
{
    switch (n)
    {
    case 0:break;
    case 1: five++; break;
    case 2:four++; break;
    case 3:deadFour++; break;
    case 4: three++; break;
    case 5:deadThree++; break;
    case 6:two++; break;
    case 7:deadTwo++; break;
    case 8:one++; break;
    case 9:deadOne++; break;
    default:
        break;
    }
    return *this;
}

AIPLAYER::AIPLAYER()
{
}

AIPLAYER::~AIPLAYER()
{
}

void AIPLAYER::setPieces(int board[15][15])
{
    if (board[posx][posy]==0)
    {
        board[posx][posy] = BLACK;//����
    }
}

int AIPLAYER::evaluate( int board[15][15],int side)
{
    //���������̽�������
    //�ȶԺ��ŵĺ����ŵ�

    long score = 0;
    for (int i = 0; i < 15; i++)
    {
        vector<int> horize;
        vector<int> vertical;
        for (int  j = 0; j < 15; j++)
        {
            horize.push_back(board[j][i]);
            vertical.push_back(board[i][j]);
        }
        score += getScore(horize);
        score += getScore(vertical);
    }
    //б��/�ģ�������
    for (int i = 4; i < 15; i++)
    {
        vector<int> vec;
        int x = 0;
        int y = i;
        while (y>=0)
        {
            vec.push_back(board[x++][y--]);
        }
        score += getScore(vec);
    }
    //б��/�ģ�������
    for (int i = 1; i < 11; i++)
    {
        vector<int> vec;
        int x = i;
        int y = 14;
        while(x < 15)
        {
            vec.push_back(board[x++][y--]);
        }
        score += getScore(vec);
    }
    //б��\�ģ�������
    for (int i = 0; i < 15; i++)
    {
        vector<int> vec;
        int x = 0;
        int y = i;
        while (y<15)
        {
            vec.push_back(board[x++][y++]);
        }
        score += getScore(vec);
    }
    //б��\�ģ�������
    for (int i = 1; i < 11; i++)
    {
        vector<int> vec;
        int x = i;
        int y = 0;
        while (x<15)
        {
            vec.push_back(board[x++][y++]);
        }
        score += getScore(vec);
    }
    return score;

}


int AIPLAYER::getScore(const vector<int>& vec)
{
    if (vec.size()<5)
    {
        return 0;
    }
    else
    {
        vector<POS> bIndex;
        vector<POS>wIndex;
        TEMPLATE bTem;
        TEMPLATE wTem;
        getSpace(vec, BLACK, bIndex);
        getSpace(vec, WHITE, wIndex);
        for (auto s : bIndex)
        {
            int start = s.x;
            int end = s.y;
            matchTemplate(start, end, vec, bTem);
        }
        for (auto s : wIndex)
        {
            int start = s.x;
            int end = s.y;
            matchTemplate(start, end, vec, wTem);
        }

        int blackScore = bTem.five * 8000 + bTem.four * 2000 + (bTem.deadFour + bTem.three) * 800 + (bTem.deadThree + bTem.two) * 100 + (bTem.deadTwo + bTem.one) * 30 + bTem.deadOne * 2;
        int whiteScore = wTem.five * 20000 + wTem.four * 2500 + (wTem.deadFour + wTem.three) * 1500 + (wTem.deadThree + wTem.two) * 150 + (wTem.deadTwo + wTem.one) * 40 + wTem.deadOne * 3;

        return blackScore - whiteScore;
    }

}

void AIPLAYER::getMove(vector<POS>&vec, int board[15][15])
{
    /*
    //ʵ��˼·��Ҫ����ROI�����ڶԿ������ӵĸ�����������֣�Ȼ�����ѡ��һЩ����ĵ��������
    //Ϊ�����ó��������������Ƚ����е㷵�أ��������Ż�
    //for (int i = roix1; i <= roix2; i++)
    //{
    //	for (int j = roiy1; j <= roiy2; j++)
    //	{
    //		//vec.push_back(POS(i, j));
    //		if (board[i][j] == 0)
    //		{
    //			vec.push_back(POS(i, j));
    //		}
    //	}
    //}
    */

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (board[i][j]!=0)
            {
                //̽��˸����򣬽��յļ���
                /*if (i-1>=0)
                {
                    if (board[i-1][j]==0)
                    {
                        POS p(i-1,j);
                        auto iter = find(vec.begin(), vec.end(),p);
                        if (iter==vec.end())
                        {
                            vec.push_back(p);
                        }

                    }
                    if (j-1>=0)
                    {
                        if (board[i][j- 1] == 0)
                        {
                            POS p(i , j-1);
                            auto iter = find(vec.begin(), vec.end(), p);
                            if (iter == vec.end())
                            {
                                vec.push_back(p);
                            }

                        }
                    }
                    if (j+1<15)
                    {
                        if (board[i][j + 1] == 0)
                        {
                            POS p(i, j + 1);
                            auto iter = find(vec.begin(), vec.end(), p);
                            if (iter == vec.end())
                            {
                                vec.push_back(p);
                            }

                        }
                    }
                }*/
                int tempi = i - 1;
                if (tempi<=0)
                {
                    tempi = 0;
                }

                for (; tempi < i + 2&&tempi<15; tempi++)
                {
                    int tempj = j - 1;
                    if (tempj<0)
                    {
                        tempj = 0;
                    }
                    for (; tempj < j + 2&&tempj<15; tempj++)
                    {
                        if (board[tempi][tempj]==0)
                        {
                            POS p(tempi, tempj);
                            auto iter = find(vec.begin(), vec.end(), p);
                            if (iter == vec.end())
                            {
                                vec.push_back(p);
                            }
                        }
                    }
                }
            }
        }
    }

}

void AIPLAYER::getMove(vector<POS>& vec, int board[15][15], int side)
{
    vector<POS> tmpvec;
    vector<EvaPos> evalPosVec;
    getMove(tmpvec, board);

    for (auto s : tmpvec)
    {
        board[s.x][s.y] = side;
        int n = evaluate(board,side);
        board[s.x][s.y] = 0;
        evalPosVec.push_back(EvaPos(s, n));
    }

    if (side == BLACK)
    {
        //����
        //sort(evalPosVec.begin(), evalPosVec.end());
        GreaterFun evaGreater;
        sort(evalPosVec.begin(), evalPosVec.end(), evaGreater);
        //ѡ���ϴ��ǰ10��������еĻ���
        qDebug() << "BLACK ";
        int num = 0;
        while (num != evalPosVec.size() && num != 8)
        {
            vec.push_back(evalPosVec[num].p);
            qDebug() << "����" << evalPosVec[num].p.x <<" "<< evalPosVec[num].p.y << "����ֵ" << evalPosVec[num].n;
            num++;
        }

    }
    else
    {
        //GreaterFun evaGreater;
        //����
        //sort(evalPosVec.begin(), evalPosVec.end(), evaGreater);
        sort(evalPosVec.begin(), evalPosVec.end());
        qDebug() << "WHITE";
        //ѡ����С��ǰ10��������еĻ���
        int num = 0;
        while (num != evalPosVec.size() && num != 8)
        {
            vec.push_back(evalPosVec[num].p);
            qDebug() << "����" << evalPosVec[num].p.x << " " << evalPosVec[num].p.y << "����ֵ" << evalPosVec[num].n;
            num++;
        }
    }
}
#if USEALPHAONE

int AIPLAYER::alphaBeta(int player, int alpha, int beta, int board[15][15], int level)
{

    if (level ==0||isOver(tempx,tempy,board) )
    {
        int n= evaluate(tempx,tempy,board);
        qDebug() << n;
        return n;
    }
    vector<POS> posVec;
    getMove(posVec,board);
    int newBoard[15][15];
    //for (int i = 0; i < 15; i++)
    //{
    //	for (int j = 0; j < 15; j++)
    //	{
    //		newBoard[i][j] = board[i][j];
    //	}
    //}
    if (player == BLACK)
    {
        for (auto s : posVec)
        {
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    newBoard[i][j] = board[i][j];
                }
            }
            newBoard[s.x][s.y] = BLACK;
            //posx = s.x;
            //posy = s.y;
            tempx = s.x;
            tempy = s.y;
            int score = alphaBeta(WHITE, alpha, beta, newBoard, level - 1);
            qDebug() <<"score**"<< score;
            qDebug() << "alpha**" << alpha;
            if (score>alpha)
            {
                posx = s.x;
                posy = s.y;
                alpha = score;
            }
            if (alpha>=beta)
            {
                //delete[] newBoard;
                qDebug() << "alpha cut off"<<alpha<<"  "<<beta;
                return alpha;
            }

        }
        return alpha;
    }
    if (player == WHITE)
    {
        for (auto s : posVec)
        {
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    newBoard[i][j] = board[i][j];
                }
            }
            newBoard[s.x][s.y] = WHITE;
            tempx = s.x;
            tempy = s.y;
            int score = alphaBeta(BLACK, alpha, beta, newBoard, level - 1);
            if (score<beta)
            {
                //posx = s.x;
                //posy = s.y;
                beta = score;
            }
            if (alpha>=beta)
            {
                //delete[] newBoard;
                qDebug() << "beta cut off" << alpha << "  " << beta;
                return beta;
            }


        }
        //delete[] newBoard;
        return beta;
    }

}
#else

int AIPLAYER::alphaBeta(int player, int alpha, int beta, int board[15][15], int level)
{
    if (level == LEVEl )//�ﵽ����������
    {
        int n= evaluate(board,player);
//        qDebug() << "********n="<<n;
//        qDebug() << n;
        return n;
    }
    vector<POS> posVec;
//    qDebug() << "layer��" << level;
    getMove(posVec, board, player);
//    qDebug() << "***************:" ;
    int newBoard[15][15];

    //����Ǻ���
    if (player == BLACK)
    {
        //�������board
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                newBoard[i][j] = board[i][j];
            }
        }
        int bestVal = minINFINITY;//������
        for (auto s : posVec)
        {
            newBoard[s.x][s.y] = BLACK;
            if(isOver(s.x,s.y,newBoard))
             {
                if (level == 0)
                {
                    posx = s.x;
                    posy = s.y;
                }
                return INFINITY-10;
            }
            //�ݹ�
            int score = alphaBeta(WHITE, alpha, beta, newBoard, level + 1);
            //qDebug() <<"score**"<< score;
            //qDebug() << "alpha**" << alpha;
            if(bestVal < score)
            {
                bestVal = score;
            }
            if (bestVal > alpha)
            {
                //�õ���һ���߷�
                if (level == 0)
                {
                    posx = s.x;
                    posy = s.y;
                }
                alpha = bestVal;
            }
            if (alpha>=beta)
            {
                //qDebug() << "alpha cut off"<<alpha<<"  "<<beta;
                return alpha;
            }
            newBoard[s.x][s.y] = 0;
        }
        return bestVal;
    }

    //����ǰ���
    if (player == WHITE)
    {
        //��������board
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                newBoard[i][j] = board[i][j];
            }
        }
        int bestVal=INFINITY;//�����
        for (auto s : posVec)
        {
            newBoard[s.x][s.y] = WHITE;
            if(isOver(s.x,s.y,newBoard))
             {
                return minINFINITY+10;
            }
            int score = alphaBeta(BLACK, alpha, beta, newBoard, level + 1);
            if(bestVal>score)
            {
                bestVal=score;
            }
            if (bestVal<beta)
            {
                beta = bestVal;
            }
            if (alpha>=beta)
            {
                return beta;
            }
            newBoard[s.x][s.y] = 0;
        }
        return bestVal;
    }
}
#endif


int AIPLAYER::matchFive(int side, const vector<int>& vec)
{
    //�ҵ���һ������Ϊside�ļ���
    int count = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i]==side)
        {
            count++;
            if (count==5)
            {
                return 1;
            }
        }
        else
        {
            count = 0;
        }
    }
    return 0;
}

int AIPLAYER::matchFour(int side, const vector<int>& vec)
{
    //�Ի���ƥ�䣬ֻҪ�ҵ��������ĸ���Ȼ���ж���β�ǲ��ǿվͺ�
    int n = 0;
    int count = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == side)
        {
            count++;
            if (count==4)
            {
                if ((i-4)>=0&&vec[i - 4] == 0 && (++i) < vec.size() && vec[i] == 0)
                {
                    n++;
                }
            }
        }
        else
        {
            count = 0;
        }
    }
    return n;
}

int AIPLAYER::matchDeadFour(int side, const vector<int>& vec)
{
    //������ƥ�䣬ֻҪ�ҵ��������ĸ���Ȼ���ж���β�ǲ��ǿվͺã������м���һ����
    int null = 0;
    int n = 0;
    int count = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == side)
        {
            count++;
            if (count == 4)
            {
                if ((i-4)>=0&&((vec[i - 4] == 0&&(i+1)<vec.size()&&vec[i+1]!=0&&vec[i+1]!=side )|| null==1 ||(  (i + 1)<vec.size() && vec[i +1] == 0&& vec[i -4] != 0 && vec[i -4] != side)))
                {
                    n++;
                }
            }
        }
        else if (count!=0&&vec[i]==0&&null==0)
        {
            null++;
        }
        else
        {
            count = 0;
            null = 0;
        }
    }
    return n;
}


int AIPLAYER::matchThree(int side, const vector<int>& vec)
{
    int n = 0;
    int count = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == side)
        {
            count++;
            if (count == 3)
            {
                if ((i-3)>=0&&vec[i - 3] == 0 && (++i) < vec.size() && vec[i] == 0)
                {
                    n++;
                }
            }
        }
        else
        {
            count = 0;
        }
    }
    return n;

}

int AIPLAYER::matchTwo(int side, const vector<int>& vec)
{
    int n = 0;
    int count = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == side)
        {
            count++;
            if (count == 2)
            {
                if (/*vec[i - 2] == 0 &&*/ (++i) < vec.size() && vec[i] == 0)
                {
                    n++;
                }
            }
        }
        else
        {
            count = 0;
        }
    }
    return n;
}

int AIPLAYER::matchDeadThree(int side, const vector<int>& vec)
{
    int n = 0;
    int aheadNull = 0;
    int midNull = 0;
    int tailNull = 0;
    int count = 0;
    for (int  i = 0; i < vec.size(); i++)
    {
        if (vec[i] == 0 && count == 0)
        {
            aheadNull++;
        }
        if (vec[i]==side)
        {
            count++;
            if (count==3)
            {
                if (aheadNull==0&&midNull==0)
                {
                    if (i+2<vec.size())
                    {
                        if ((vec[i+1]==0||vec[i+1]==side)&&(vec[i+2]==0||vec[i+2]==side))
                        {
                            n++;
                        }
                    }
                }
                if (midNull==1)
                {
                    int j = i;
                    while (++j<vec.size())
                    {
                        if (vec[j]==0||vec[j]==side)
                        {
                            tailNull++;
                            if (tailNull==2)
                            {
                                break;
                            }
                        }
                    }
                    if (aheadNull+tailNull>=2)
                    {
                        n++;
                    }
                }
            }
        }
        if (vec[i]==0&&(count==1||count==2)&&midNull==0)
        {
            midNull++;
        }
        else if (vec[i]==0&&count!=0&&midNull==1)
        {
            midNull = 0;
            count = 0;
        }
    }
    return n;
}

void AIPLAYER::matchTemplate(int start, int end, const vector<int>& vec, TEMPLATE & tem)
{
    int aheadNull = 0;//�հ׸���
    int tailNull = 0;
    int midNull = 0;
    int aheadCount = 0;//���Ӹ���
    int tailCount = 0;
    for (int i = start; i < end; i++)
    {
        if (vec[i]==0)
        {
            if (aheadCount==0)
            {
                aheadNull++;
            }
            else
            {
                tailNull++;
            }
        }
        else
        {
            if (midNull==0&&tailNull==0)
            {
                aheadCount++;
            }
            else if(midNull==1)
            {
                tailCount++;
            }
            else if (tailNull==1)
            {
                midNull = 1;
                tailNull = 0;
                tailCount++;
            }
            else if (tailNull > 1)
            {
                //ִ��һ���жϺ����¿�
                //ִ���жϺ���
                int n = getTemplate(aheadCount, tailCount, aheadNull, midNull, tailNull);
                tem += n;
                //״̬���¿�ʼ
                aheadNull = tailNull;
                midNull = 0;
                tailNull = 0;
                aheadCount = 1;
                tailCount = 0;
            }
        }
    }
    int n = getTemplate(aheadCount, tailCount, aheadNull, midNull, tailNull);
    tem += n;
}

int AIPLAYER::getTemplate(int aheadCount, int tailCount, int aheadNull, int midNull, int tailNull)
{
    if (aheadCount + tailCount + aheadNull + midNull + tailNull < 5)
        return 0;
    if (aheadCount>=5||tailCount>=5)
    {
        //����
        return 1;
    }
    if(aheadCount==4&&(aheadNull!=0)&&(midNull!=0||tailNull!=0))
    {
        //����
        return 2;
    }
    if (tailCount==4&&(tailNull!=0)/*&&(aheadNull!=0||midNull!=0)*/)
    {
        //����������һͷ������
        return 2;
    }
    if ((aheadCount+tailCount)>3&&midNull==1)
    {
        //���ģ��м䱻��
        return 3;
    }
    if ((aheadNull == 0||tailNull==0) && aheadCount == 4)
    {
        //���ģ���ͷ����
        return 3;
    }
    if (aheadCount == 3 && aheadNull != 0 && tailNull != 0)
    {
        //����
        return 4;
    }
    if (aheadCount == 3 && (aheadNull == 0 || tailNull == 0))
    {
        //����
        return 5;
    }
    if (midNull == 1 && (aheadCount + tailCount == 3))
    {
        //����
        return 5;
    }
    if (aheadNull != 0 && aheadCount == 2 && tailNull!=0)
    {
        //���
        return 6;
    }
    if (aheadCount == 2 && (aheadNull == 0 || tailNull == 0))
    {
        //�߶�
        return 7;
    }
    if (midNull == 1 && (aheadCount + tailCount == 2))
    {
        //�߶�
        return 7;
    }
    if (aheadNull != 0 && aheadCount == 1 && tailNull != 0)
    {
        //��һ
        return 8;
    }
    if (aheadCount == 1 && (aheadNull == 0 || tailNull == 0))
    {
        //��һ
        return 9;
    }
    return 0;
}

void AIPLAYER::getSpace(const vector<int>& vec, int side, vector<POS>& p)
{
    if (vec.size() < 5)
        return;
    int start = -1;
    int end = -1;
    for (int i = 0; i < vec.size(); i++)
    {
        if ( start == -1&&(vec[i] == 0 || vec[i] == side) )
        {
            start = i;
        }
        if (vec[i] != 0 && vec[i] != side && start != -1)
        {
            //end = i;
            if (i - start > 4)
            {
                POS tmp(start, i);
                p.push_back(tmp);
            }
            start = -1;
            end = -1;
        }
    }
    if (start!=-1&&vec.size()-start>4)
    {
        POS tmp(start, vec.size());
        p.push_back(tmp);
    }
}

bool AIPLAYER::isOver(int x, int y,int tmpboard[15][15])
{
    //�����ӵ���Χ��û����������
    if (tmpboard[x][y]==0)
    {
        return false;
    }

    //�����ж���ֱ����
    int j = y - 1;
    int count = 1;
    while (j >= 0)
    {
        if (tmpboard[x][j--] == tmpboard[x][y])
        {
            count++;
            if (count == 5)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    j = y + 1;
    while (j<15)
    {
        if (tmpboard[x][j++] == tmpboard[x][y])
        {
            count++;
            if (count == 5)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }

    //ˮƽ����
    int i = x - 1;
    count = 1;
    while (i >= 0)
    {
        if (tmpboard[i--][y] == tmpboard[x][y])
        {
            count++;
            if (count == 5)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    i = x + 1;
    while (i<15)
    {
        if (tmpboard[i++][y] == tmpboard[x][y])
        {
            count++;
            if (count == 5)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }

    // /����
    i = x - 1;
    j = y + 1;
    count = 1;
    while (x >= 0 && j<15)
    {
        if (tmpboard[i--][j++] == tmpboard[x][y])
        {
            count++;
            if (count == 5)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    i = x + 1;
    j = y - 1;
    while (x<15 && y >= 0)
    {
        if (tmpboard[i++][j--] == tmpboard[x][y])
        {
            count++;
            if (count == 5)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }

    // \����
    i = x - 1; j = y - 1;
    count = 1;
    while (i >= 0 && j >= 0)
    {
        if (tmpboard[i--][j--] == tmpboard[x][y])
        {
            count++;
            if (count == 5)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    i = x + 1; j = y + 1;
    while (i<15 && j<15)
    {
        if (tmpboard[i++][j++] == tmpboard[x][y])
        {
            count++;
            if (count == 5)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    return false;
}
