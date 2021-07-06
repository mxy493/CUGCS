#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mygraph.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer=new QTimer;
    //->start(100);
    //������ͼ����ʾ�����ط�������
    nameVec={"Arad",
             "Bucharest",
             "Craiova",
             "Doberta",
             "Eforie",
             "Fagaras",
             "Glurgiu",
             "Hirsova",
             "Iasi",
             "Lugoj",
             "Mehadia",
             "Neamt",
             "Oradea",
             "Pitesti",
             "Rimmicu_Vikea",
             "Sibiu",
             "Timisoara",
             "Urziceni",
             "Vaslui",
             "Zerind"
            };
    //��Ӧ�ĸ����ص�����꣬���ڲ�������ͼ�λ����������ݣ����Ծ�Ĭ���趨
     coordinateVec={
        QPoint(5,100),//Arad
        QPoint(354,251),//Bucharest
        QPoint(191,364),//Craiova
        QPoint(92,334),//Doberta
        QPoint(528,349),//Eforie
        QPoint(225,136),//Fagaras
        QPoint(328,337),//Glurgiu
        QPoint(490,279),//Hirsova
        QPoint(502,101),//Iasi
        QPoint(52,247),//Lugoj
        QPoint(76,286),//Mehadia
        QPoint(471,45),//Neamt
        QPoint(76,41),//Oradea
        QPoint(250,235),//Pitesti
        QPoint(147,223),//Rimmicu
        QPoint(92,166),//Sibiu
        QPoint(24,218),//Timisoara
        QPoint(424,223),//Urziceni
        QPoint(533,148),//Vaslui
        QPoint(45,86)//Zerind

    };
////    QGridLayout *gridLayout = new QGridLayout(this);
////    gridLayout->addWidget(pView, 0, Qt::AlignCenter);
       drawGrpah();
       getPathData();
       visualData();
       //setLineVisible();
      // connect(ui->show,SIGNAL(clicked(bool)),this,SLOT(setLineVisible()));
       //connect(ui->show,SIGNAL(),this,SLOT(setTimer()));
       connect(ui->show,SIGNAL(clicked(bool)),this,SLOT(setTimer()));
       connect(timer,SIGNAL(timeout()),this,SLOT(setLineVisible()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawGrpah()
{
//    //������ͼ����ʾ�����ط�������
//    std::vector<std::string> tem_nameVec={"Arad",
//                                    "Bucharest",
//                                    "Craiova",
//                                    "Doberta",
//                                    "Eforie",
//                                    "Fagaras",
//                                    "Glurgiu",
//                                    "Hirsova",
//                                    "Iasi",
//                                    "Lugoj",
//                                    "Mehadia",
//                                    "Neamt",
//                                    "Oradea",
//                                    "Pitesti",
//                                    "Rimmicu_Vikea",
//                                    "Sibiu",
//                                    "Timisoara",
//                                    "Urziceni",
//                                    "Vaslui",
//                                    "Zerind"
//                                    };
//    //��Ӧ�ĸ����ص�����꣬���ڲ�������ͼ�λ����������ݣ����Ծ�Ĭ���趨
//    std::vector<QPoint> tem_coordinateVec={
//        QPoint(5,100),//Arad
//        QPoint(354,251),//Bucharest
//        QPoint(191,364),//Craiova
//        QPoint(92,334),//Doberta
//        QPoint(528,349),//Eforie
//        QPoint(225,136),//Fagaras
//        QPoint(328,337),//Glurgiu
//        QPoint(490,279),//Hirsova
//        QPoint(502,101),//Iasi
//        QPoint(52,247),//Lugoj
//        QPoint(76,286),//Mehadia
//        QPoint(471,45),//Neamt
//        QPoint(76,41),//Oradea
//        QPoint(250,235),//Pitesti
//        QPoint(147,223),//Rimmicu
//        QPoint(92,166),//Sibiu
//        QPoint(24,218),//Timisoara
//        QPoint(424,223),//Urziceni
//        QPoint(533,148),//Vaslui
//        QPoint(45,86)//Zerind

//    };
   // nameVec=tem_nameVec;
   // coordinateVec=tem_coordinateVec;
//    QGraphicsScene*/ *
    scene=new QGraphicsScene();
//    QGraphicsView *
    view=ui->graphicsView;
    //scene->setSceneRect(0,0,view->width(),view->height());
    scene->setSceneRect(0,0,600,400);

    QPen pen;
    pen.setWidth(2);
    pen.setColor(QColor(140, 40, 40));
    //scene=new QGraphicsScene;
    // scene->addEllipse(QRectF(600,600,10,10),pen);
    int i=0;
    for(auto s:coordinateVec)
    {
        scene->addEllipse(QRectF(s.x()-5,s.y()-5,10,10),pen);
        QGraphicsTextItem *txtitem = new QGraphicsTextItem(QString::fromStdString(nameVec[i]));
        txtitem->setPos(QPointF(s.x()+5,s.y()-10));//����Ҫ���õĵ�λ��
        scene->addItem(txtitem);//���item��scene��
        i++;
    }
//    if(!romaniaGraph.initiFromFile())
//        qDebug()<<"initial failed";
    for(auto s:nameVec)
    {
        int v=romaniaAStar.romaniaGraph.getPos(s);
        int v2=romaniaAStar.romaniaGraph.getFirstNeighbor(v);
        //if(v2==-1)
       //     continue;
       // scene->addLine(QLineF(coordinateVec[v],coordinateVec[v2]),pen);
        while (v2!=-1)
        {
            scene->addLine(QLineF(coordinateVec[v],coordinateVec[v2]),pen);
            v2=romaniaAStar.romaniaGraph.getNextNeighbor(v,v2);
        }
    }
    //view.show();
    // view.setScene(scene);

//    pen.setColor(QColor(100,100,100));
//    romaniaAStar.useAStar();
//    pathNodeVec=romaniaAStar.getPathNodeVec();
//    finalPath=romaniaAStar.getPath();
//    for(auto s:pathNodeVec)
//    {
//        scene->addLine(QLineF(coordinateVec[s.start],coordinateVec[s.end]),pen);
//        qDebug()<<s.start<<"    "<<s.end;

//    }
//    //��������·��
//    auto iter=finalPath.begin();
//    auto iter2=iter+1;
//    pen.setColor(QColor(150,120,200));
//    for(;iter2!=finalPath.end()-1;iter++,iter2++)
//    {
//        scene->addLine(QLineF(coordinateVec[*iter],coordinateVec[*iter2]),pen);
//    }


    view->setScene(scene);
    view->show();
}

void MainWindow::getPathData()
{
    romaniaAStar.useAStar();
    pathNodeVec=romaniaAStar.getPathNodeVec();
    finalPath=romaniaAStar.getPath();
}

void MainWindow::visualData()
{
   // QGraphicsScene *scene=new QGraphicsScene();
    //QGraphicsView *view=ui->graphicsView;
    QPen pen;
    pen.setWidth(2);
    pen.setColor(QColor(255, 0, 255));
    //�Ȼ�����������
    for(auto s:pathNodeVec)
    {
          auto line=scene->addLine(QLineF(coordinateVec[s.start],coordinateVec[s.end]),pen);
//        QPropertyAnimation *pScaleAnimation1;//���嶯����ָ��
//        pScaleAnimation1 = new QPropertyAnimation(ui->pScaleAnimation1, "geometry");//�½�һ������
//        pScaleAnimation1->setEasingCurve(QEasingCurve::InOutQuad);
       // Sleep(100);
        //QGraphicsView *nview=new QGraphicsView();
        //nview->setScene(scene);
        //nview->show();
        lineVec.push_back(line);
        line->hide();
        qDebug()<<s.start<<"    "<<s.end;

    }
    //��������·��
    auto iter=finalPath.begin();
    auto iter2=iter+1;
    pen.setWidth(4);
    pen.setColor(QColor(0,0,200));
    for(;iter2!=finalPath.end()-1;iter++,iter2++)
    {
        auto line= scene->addLine(QLineF(coordinateVec[*iter],coordinateVec[*iter2]),pen);
        lineVec.push_back(line);
        line->hide();
    }
    //view->setScene(scene);
    //view->show();
}

void MainWindow::setLineVisible()
{
     //iter=lineVec.begin();
    if(first)
    {
        iter=lineVec.begin();
        first=false;
    }
    (*iter)->show();
    iter++;
    timer->start(100);
    if(iter==lineVec.end())
    {
        iter=lineVec.begin();
        timer->stop();

    QGraphicsTextItem *txtitem = new QGraphicsTextItem(QString::fromStdString("The blue indicates the final path!"));
    txtitem->setPos(QPointF(0,10));//����Ҫ���õĵ�λ��
    scene->addItem(txtitem);//���item��scene��
    //ui->textEdit->setText(QString::fromStdString("�㷨ִ�й�����\nһ��̽���� "+to_string(romaniaAStar.getNumOfNode())+"��\n�ڵ㡣"));
    //ui->textEdit->(QString::fromStdString("����·������Ϊ\n "+to_string(romaniaAStar.getFinalCost())+""));
    QString str;
    str=QString::fromStdString("�㷨ִ�й�����\nһ��̽���� "+to_string(romaniaAStar.getNumOfNode())+"��\n�ڵ㡣\n");
    str+=QString::fromStdString("����·������Ϊ\n "+to_string(romaniaAStar.getFinalCost())+"��\n");
    str+="����·���뿴��ͼ��ɫ·����";
    ui->textEdit->setText(str);
    }
}

void MainWindow::setTimer()
{
   // setLineVisible();
    timer->start(100);
}




