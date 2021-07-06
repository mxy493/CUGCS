#include "SimulatedAnnealing.h"

// 默认构造函数
simulatedAnnealing::simulatedAnnealing(int N) {
    this->N = N;
}

// 初始化棋盘
void simulatedAnnealing::initChessboard(vector<int>& chessboard) {
    for (int i = 0; i < N; i++) {
        chessboard.push_back(i);
    }

    srand((unsigned)time(0));
    for (int row1 = 0; row1 < N; row1++) {
        int row2 = rand() % N;
        // 随机交换行，打散棋盘，但保证皇后都在不同列
        swap(chessboard[row1], chessboard[row2]);
    }
}

// 计算当前棋盘存在的相互攻击的皇后对数
int simulatedAnnealing::getNumofConflicts(vector<int> *chessboard) {
    int numOfConflicts = 0;
    int width = this->N;
    for (int i = 0; i < width; i++) {
        for (int j = i + 1; j < width; j++) {
            // 当存在皇后位于对角线的时候 冲突数+1
            if (abs(j - i) == abs((*chessboard)[i] - (*chessboard)[j])) {
                numOfConflicts++;
            }
            // 当存在皇后位于同一列的时候，冲突数+1
            if ((*chessboard)[i] == (*chessboard)[j]) {
                numOfConflicts++;
            }
        }
    }
    return numOfConflicts;
}

//利用模拟退火算法得到该行的合适位置
int simulatedAnnealing::properPosition(const vector<int> *chessboard, int row) {
    double T = 18;          // 当前温度
    double Tmin = 1.0;         // 最小温度
    double decreaseRate = 0.8; // 降温速率

    // 当前状态和下一状态
    vector<int>* currentChessboard = new vector<int>(N);
    vector<int>* nextChessboard = new vector<int>(N);

    for (int i = 0; i < this->N; i++) {
        (*currentChessboard)[i] = ((*chessboard)[i]);
        (*nextChessboard)[i] = ((*chessboard)[i]);
    }

    //int queenPosition = 0;
    // 开始模拟退火
    while (T > Tmin) {
        // 修改下一状态，改变row行的皇后位置
        for (int queenPosition = 0; queenPosition < this->N; queenPosition++) {
            (*nextChessboard)[row] = queenPosition;
            // 得到前后状态的能量差
            double dE = getNumofConflicts(nextChessboard) - getNumofConflicts(currentChessboard);
            // 如果下一步更优则，接受该移动
            if (dE <= 0) {
                (*currentChessboard)[row] = (*nextChessboard)[row];
                //cout << "更优，接受该移动" << " pos = " << queenPosition << endl;
            }
            //  如果下一步更差，则一定几率接受该移动，几率逐渐变小
            else {
                if (exp((-1) * dE / T) > (rand() % 100)* 1.0 / 100) {
                    //	cout << "更差，但还是接受该移动" << " pos = " << queenPosition << endl;
                    (*currentChessboard)[row] = (*nextChessboard)[row];
                }
                else {
                    //		cout << "  不接受该移动 pos = " << queenPosition << endl;
                }
            }
        }
        //  降温
        T = decreaseRate * T;

    }
    //	cout << "-----------------------------" << endl;
    return (*currentChessboard)[row];
}

// 利用模拟退火算法修改该行，得到一个合适的位置
//（不一定是当前最优，以一定几率接受一个更差的解）
vector<int>* simulatedAnnealing::nextState(vector<int> *chessboard, int row) {
    (*chessboard)[row] = properPosition(chessboard, row);
    return chessboard;
}

// 求解主函数，在不同的行中不断搜寻下一步合适的位置
vector<int>* simulatedAnnealing::solve(vector<int> *chessboard) {
    int rowPosition = 0;
    int step = 0;
    while (getNumofConflicts(chessboard)) {
        if (rowPosition == this->N) {
            rowPosition %= rowPosition;
        }
        chessboard = nextState(chessboard, rowPosition++);
        step++;
    }
//    cout << "Solved the problem, totally " << step << " steps. " << endl;
    return chessboard;
}

vector<vector<string>> simulatedAnnealing::solveNQueens()
{
    clock_t start = clock();
    vector<int> chessboard;
    initChessboard(chessboard);
    solve(&chessboard);
    clock_t end = clock();
    time_t = (double)(end-start)/CLOCKS_PER_SEC;

    vector<vector<string>> res;
    vector<string> vec;
    for(int i = 0; i < N; i++)
    {
        string str;
        for(int j = 0; j < N; j++)
        {
            if(j == chessboard[i])
                str += 'Q';
            else
                str += '.';
        }
        vec.push_back(str);
    }
    res.push_back(vec);
    return res;
}

