#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

#include "NQueens.h"
#include "Backtrack.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

private:
    Ui::Widget *ui;

    int n = 8;//皇后数
    vector<vector<string>> nqueens;//保存获取到的解
    double time;//耗时

    int xMargin = 50;//横向棋盘边缘
    int yMargin = 50;//纵向棋盘边缘

    void paintEvent(QPaintEvent *event);

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int getN();//获取皇后数
    void getSolution();//获取解
    int getBoardWidth();//获取棋盘宽度
    int getGridWidth();//获取格子宽度
    void adjustPosition();//动态调整部件位置

private slots:
    void on_pushButton_run_clicked();
};
#endif // WIDGET_H
