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
        board[posx][posy] = BLACK;//黑子
    }
}

int AIPLAYER::evaluate( int board[15][15],int side)
{
    //对整个棋盘进行评价
    //先对横着的和竖着的

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
    //斜着/的，上三角
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
    //斜着/的，下三角
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
    //斜着\的，下三角
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
    //斜着\的，上三角
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
    //实现思路主要是在ROI区域内对可以落子的各个点进行评分，然后从中选出一些优秀的点进行搜索
    //为了先让程序跑起来，首先将所有点返回，后面再优化
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
                //探测八个方向，将空的加入
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
        //排序
        //sort(evalPosVec.begin(), evalPosVec.end());
        GreaterFun evaGreater;
        sort(evalPosVec.begin(), evalPosVec.end(), evaGreater);
        //选出较大的前10个（如果有的话）
        qDebug() << "BLACK ";
        int num = 0;
        while (num != evalPosVec.size() && num != 8)
        {
            vec.push_back(evalPosVec[num].p);
            qDebug() << "坐标" << evalPosVec[num].p.x <<" "<< evalPosVec[num].p.y << "评价值" << evalPosVec[num].n;
            num++;
        }

    }
    else
    {
        //GreaterFun evaGreater;
        //排序
        //sort(evalPosVec.begin(), evalPosVec.end(), evaGreater);
        sort(evalPosVec.begin(), evalPosVec.end());
        qDebug() << "WHITE";
        //选出较小的前10个（如果有的话）
        int num = 0;
        while (num != evalPosVec.size() && num != 8)
        {
            vec.push_back(evalPosVec[num].p);
            qDebug() << "坐标" << evalPosVec[num].p.x << " " << evalPosVec[num].p.y << "评价值" << evalPosVec[num].n;
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
    if (level == LEVEl )//达到最大搜索深度
    {
        int n= evaluate(board,player);
//        qDebug() << "********n="<<n;
//        qDebug() << n;
        return n;
    }
    vector<POS> posVec;
//    qDebug() << "layer：" << level;
    getMove(posVec, board, player);
//    qDebug() << "***************:" ;
    int newBoard[15][15];

    //如果是黑棋
    if (player == BLACK)
    {
        //复制棋局board
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                newBoard[i][j] = board[i][j];
            }
        }
        int bestVal = minINFINITY;//负无穷
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
            //递归
            int score = alphaBeta(WHITE, alpha, beta, newBoard, level + 1);
            //qDebug() <<"score**"<< score;
            //qDebug() << "alpha**" << alpha;
            if(bestVal < score)
            {
                bestVal = score;
            }
            if (bestVal > alpha)
            {
                //得到下一步走法
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

    //如果是白棋
    if (player == WHITE)
    {
        //复制棋盘board
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                newBoard[i][j] = board[i][j];
            }
        }
        int bestVal=INFINITY;//无穷大
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
    //找到第一个棋子为side的即可
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
    //对活四匹配，只要找到连续的四个，然后判断首尾是不是空就好
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
    //对死四匹配，只要找到连续的四个，然后判断首尾是不是空就好，或者中间有一个空
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
    int aheadNull = 0;//空白个数
    int tailNull = 0;
    int midNull = 0;
    int aheadCount = 0;//棋子个数
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
                //执行一次判断后重新开
                //执行判断函数
                int n = getTemplate(aheadCount, tailCount, aheadNull, midNull, tailNull);
                tem += n;
                //状态重新开始
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
        //五连
        return 1;
    }
    if(aheadCount==4&&(aheadNull!=0)&&(midNull!=0||tailNull!=0))
    {
        //四连
        return 2;
    }
    if (tailCount==4&&(tailNull!=0)/*&&(aheadNull!=0||midNull!=0)*/)
    {
        //四连，至少一头不被堵
        return 2;
    }
    if ((aheadCount+tailCount)>3&&midNull==1)
    {
        //眠四，中间被堵
        return 3;
    }
    if ((aheadNull == 0||tailNull==0) && aheadCount == 4)
    {
        //眠四，两头被堵
        return 3;
    }
    if (aheadCount == 3 && aheadNull != 0 && tailNull != 0)
    {
        //活三
        return 4;
    }
    if (aheadCount == 3 && (aheadNull == 0 || tailNull == 0))
    {
        //眠三
        return 5;
    }
    if (midNull == 1 && (aheadCount + tailCount == 3))
    {
        //眠三
        return 5;
    }
    if (aheadNull != 0 && aheadCount == 2 && tailNull!=0)
    {
        //活二
        return 6;
    }
    if (aheadCount == 2 && (aheadNull == 0 || tailNull == 0))
    {
        //眠二
        return 7;
    }
    if (midNull == 1 && (aheadCount + tailCount == 2))
    {
        //眠二
        return 7;
    }
    if (aheadNull != 0 && aheadCount == 1 && tailNull != 0)
    {
        //活一
        return 8;
    }
    if (aheadCount == 1 && (aheadNull == 0 || tailNull == 0))
    {
        //眠一
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
    //看落子的周围有没有五连即可
    if (tmpboard[x][y]==0)
    {
        return false;
    }

    //首先判断竖直方向
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

    //水平方向
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

    // /方向
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

    // \方向
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
