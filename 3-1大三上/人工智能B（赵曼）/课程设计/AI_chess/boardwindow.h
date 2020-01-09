#ifndef BOARDWINDOW_H
#define BOARDWINDOW_H

#include <QDialog>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
//#include "CHESS.h"
#include "AIPLAYER.h"
//#include "windialog.h"
//#include "losedialog.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QMessageBox>

namespace Ui {
class boardWindow;
}

class boardWindow : public QDialog
{
    Q_OBJECT

public:
    explicit boardWindow(QWidget *parent = 0);
    ~boardWindow();

private:
    Ui::boardWindow *ui;
    void paintEvent(QPaintEvent *event);
    //棋盘
    int board[15][15];
    //选手
    int player = 1;
    void mousePressEvent(QMouseEvent* mouseClicked);
    bool setPieces(int x,int y,int side);
    //判断游戏是否结束
	bool isOver(int x, int y);
    //重置棋局
    void reset();
    //CHESS chess;
	AIPLAYER ai;
    //用这个来按落子顺序存储每一颗子的位置，方便后面复现问题
    vector<POS> posVecOfPieces;
};

#endif // BOARDWINDOW_H
