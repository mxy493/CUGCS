#ifndef GENETIC_H
#define GENETIC_H

#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;

class Genetic {
private:
    int m_Num;                                // 皇后数量
    bool m_IsSuccess;                         // 是否成功找到最优解
    double time;                              //耗时
    vector<vector<string>> res;               //保存所有解
    vector<int>m_optimalSolution;             // 最优解.
    vector<vector<int> >m_population;          // 种群
    vector<double>m_adaptive;                 // 种群的适应值(1/冲突数)。
    vector<double>m_AdaptValue;               // 累积的适应值(定位哪一个被选中的)

public:
    Genetic(int numOfQueens, int initialGroupNum = 120);
    double getTime(){return time;}
    double CalcuAdaptive(vector<int>& state);         // 计算适应值（互不相攻击的皇后对数）
    void SetPopulation();
    void Choose();                                    // 选择
    void GeneticCrossover();                          // 杂交
    void GeneticMutate();                             // 变异
    vector<vector<string>> GeneticCalculation();
};

#endif // GENETIC_H
