#ifndef HILLCLIMBING_H
#define HILLCLIMBING_H

#include <iostream>
#include <random>
#include <vector>
#include <time.h>

using namespace std;

class HillClimbing
{
private:
    vector<vector<int>> map;
    vector<vector<string>> nqueens;
    double time_t;
    int n;

public:
    vector<int> X, Y;
    HillClimbing(int n);
    vector<vector<string>> solveNQueens();
    void vector_cpy(vector<int>& main_vector, vector<int>& copy_vector);
    void randGenerate();
    void clean();
    void set_map();
    void convert();
    int price(vector<int> x, vector<int> y, int p);
    int price(vector<int> x, vector<int> y);
    bool move(vector<int>& y, int row);
    bool search();
    void HCstart();
    double getTime() { return time_t; }
};

#endif // HILLCLIMBING_H
