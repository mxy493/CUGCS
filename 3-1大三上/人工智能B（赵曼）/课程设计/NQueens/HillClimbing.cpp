#include "HillClimbing.h"

HillClimbing::HillClimbing(int assign) {
    n = assign;
}

vector<vector<string>> HillClimbing::solveNQueens()
{
    clock_t start = clock();
    HCstart();
    clock_t end = clock();
    time_t = (double)(end - start) / CLOCKS_PER_SEC;
    return nqueens;
}

//複製vector : main_vector  to  copy_vector
void HillClimbing::vector_cpy(vector<int>& main_vector, vector<int>& copy_vector) {
    copy_vector.clear();
    copy_vector.assign(main_vector.begin(), main_vector.end());
}

void HillClimbing::randGenerate() {
    clean();
//    random_device rd; //利用硬體系統給的值來取值
//    default_random_engine generator(rd()); //初始化，並利用rd()的值找出相對應的種子碼??
//    uniform_int_distribution<int> distribution(0, n - 1); //設定範圍與決定要產生什麼類型的亂數 ex:int float..
    for (int i = 0; i < n; i++) {
//        int randnumber = distribution(generator);
//        srand((unsigned)time(NULL));//初始化随机数
        int randnumber = (rand() % (n));
        X.push_back(i);
        Y.push_back(randnumber);
    }
}

void HillClimbing::clean() {
    X.clear();
    Y.clear();
}

void HillClimbing::set_map() {
    map.clear();
    //初始化棋盤
    for (int i = 0; i < n; i++) {
        vector<int> tempv;
        for (int j = 0; j < n; j++) {
            tempv.push_back(0);
        }
        map.push_back(tempv);
    }

    for (int i = 0; i < static_cast<int>(X.size()); i++) {
        map[X.at(i)][Y.at(i)] = 1;
    }
}

void HillClimbing::convert() {
    set_map();
    vector<string> queen;
    for (int i = 0; i < n; i++) {
        string str;
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1) {
                str += 'Q';
//                cout << "Q";
            }
            else {
                str += '.';
//                cout << ".";
            }
        }
//        cout << "\n";
        queen.push_back(str);
    }
//    cout << "\n";
    nqueens.push_back(queen);
}

int HillClimbing::price(vector<int> x, vector<int> y, int p) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double _x = x[i] - x[j];
            double _y = y[i] - y[j];
            double m = _y / _x;
            if (_x == 0.0 || _y == 0.0 || m == 1.0 || m == -1.0) {
                count++;
                if (count >= p)
                    return count;
                continue;
            }
        }
    }
    return count;
}

int HillClimbing::price(vector<int> x, vector<int> y) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double _x = x[i] - x[j];
            double _y = y[i] - y[j];
            double m = _y / _x;
            if (_x == 0.0 || _y == 0.0 || m == 1.0 || m == -1.0) {
                count++;
                continue;
            }
        }
    }
    return count;
}

bool HillClimbing::move(vector<int>& y, int row) {
    int p = price(X, y);
    for (int col = 0; col < n; col++) {
        y.at(row) = col;//set

        int vp = price(X, y, p);
        if (vp < p)
            return true;
    }
    return false;
}

bool HillClimbing::search() {
    for (int i = 0; i < n; i++) {
        vector<int> y;
        vector_cpy(Y, y);
        if (move(y, i)) {
            vector_cpy(y, Y);
//            cout << "End of Search.  price=" << price(X, Y) << endl;
            return true;
        }
    }
    return false;
}

void HillClimbing::HCstart() {
    int count = 0;
    while (true) {
        randGenerate();
        while (true) {
            if (!search()) {
                if (price(X, Y) == 0) {
                    convert();
//                    cout << "restart:" << count << "\n";
                    return;
                }
                else {
                    break;
                }
            }
        }
        count++;
    }
}
