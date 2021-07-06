#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma execution_character_set("utf-8")
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPen>
#include <QApplication>
#include <QtGui>
#include <QGridLayout>
#include <vector>
#include <string>
#include "mygraph.h"
#include "astar.h"
#include <QDebug>
#include <QpropertyAnimation.h>
#include <synchapi.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void setLineVisible();
    void setTimer();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;  //定义一个场景
    QGraphicsView *view; //定义一个视图
    //用于在界面上画出各个地点
   // MyGraph romaniaGraph;
     vector<QPoint> coordinateVec;
     vector<std::string> nameVec;
    AStar romaniaAStar;
    //搜索路径，用可视化
    vector<pathNode> pathNodeVec;
    //最终路径
    vector<int> finalPath;
    void drawGrpah();
    //获取搜索路径和最终路径
    void getPathData();
    //最终数据可视化
    void visualData();
    //用于存储直线
    vector<QGraphicsLineItem*> lineVec;
    vector<QGraphicsLineItem*>::iterator iter;
    bool first=true;
   // void setLineVisible();
    QTimer *timer;

};

#endif // MAINWINDOW_H
