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
    QGraphicsScene *scene;  //����һ������
    QGraphicsView *view; //����һ����ͼ
    //�����ڽ����ϻ��������ص�
   // MyGraph romaniaGraph;
     vector<QPoint> coordinateVec;
     vector<std::string> nameVec;
    AStar romaniaAStar;
    //����·�����ÿ��ӻ�
    vector<pathNode> pathNodeVec;
    //����·��
    vector<int> finalPath;
    void drawGrpah();
    //��ȡ����·��������·��
    void getPathData();
    //�������ݿ��ӻ�
    void visualData();
    //���ڴ洢ֱ��
    vector<QGraphicsLineItem*> lineVec;
    vector<QGraphicsLineItem*>::iterator iter;
    bool first=true;
   // void setLineVisible();
    QTimer *timer;

};

#endif // MAINWINDOW_H
