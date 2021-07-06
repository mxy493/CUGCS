#ifndef SIMULATEDANNEALING_H
#define SIMULATEDANNEALING_H

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <time.h>
#include<string>

using namespace std;

class simulatedAnnealing
{
private:
    int N;// 皇后的数目
    double time_t;
public:
    simulatedAnnealing(int N);// 默认构造函数
    void initChessboard(vector<int>& chessboard);// 初始化棋盘
    int getNumofConflicts(vector<int> *chessboard);// 计算当前棋盘存在的相互攻击的皇后对数
    int properPosition(const vector<int> *chessboard, int row);//利用模拟退火算法得到该行的合适位置
    // 利用模拟退火算法修改该行，得到一个合适的位置
    //（不一定是当前最优，以一定几率接受一个更差的解）
    vector<int>* nextState(vector<int> *chessboard, int row);
    vector<int>* solve(vector<int> *chessboard);// 求解主函数，在不同的行中不断搜寻下一步合适的位置
    vector<vector<string>> solveNQueens();
    double getTime(){return time_t;}
};

#endif // SIMULATEDANNEALING_H
