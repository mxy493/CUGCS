#include "Backtrack.h"

Backtrack::Backtrack()
{
    //构造函数
}

Backtrack::~Backtrack()
{
    //析构函数
}

/* 输入棋盘边长 n，返回所有合法的放置 */
vector<vector<string>> Backtrack::solveNQueens(int n) {
    // '.' 表示空，'Q' 表示皇后，初始化空棋盘。
    clock_t start = clock();

    vector<string> board(n, string(n, '.'));//初始化全为'.'
    backtrack(board, 0);//回溯法求解

    clock_t end = clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    return res;
}

// 路径：board 中小于 row 的那些行都已经成功放置了皇后
// 选择列表：第 row 行的所有列都是放置皇后的选择
// 结束条件：row 超过 board 的最后一行
void Backtrack::backtrack(vector<string>& board, int row) {
    //找到一个解便不再继续往下找
    if (res.size() != 0)
        return;

    // 触发结束条件
    if (row == board.size()) {

        res.push_back(board);
        return;
    }
    int n = board[row].size();
    for (int col = 0; col < n; col++) {
        // 排除不合法选择
        if (!isValid(board, row, col))
            continue;
        // 做选择
        board[row][col] = 'Q';
        // 进入下一行决策
        backtrack(board, row + 1);
        // 撤销选择
        board[row][col] = '.';
    }
}

/* 是否可以在 board[row][col] 放置皇后？*/
bool Backtrack::isValid(vector<string>& board, int row, int col) {
    int n = board.size();
    // 检查列是否有皇后互相冲突
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q')
            return false;
    }
    // 检查右上方是否有皇后互相冲突
    for (int i = row - 1, j = col + 1;
        i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }
    // 检查左上方是否有皇后互相冲突
    for (int i = row - 1, j = col - 1;
        i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}
