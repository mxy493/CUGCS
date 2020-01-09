#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

int Widget::getN()
{
    QString a = ui->lineEdit_n->text();
    int result = a.toInt();
    if(a.isEmpty() || (result < 4 && result != 1))
    {
        QMessageBox::warning(NULL, "Warning", "输入信息不符合要求（N==1或N>=4），请重新输入！", QMessageBox::Yes);
    }
    return result;
}

void Widget::getSolution()
{
    NQueens queen;
    int algorithm = ui->comboBox->currentIndex();
    nqueens = queen.solveNQueens(n, algorithm);
    time = queen.getTime();
}

int Widget::getBoardWidth()
{
    return n * getGridWidth();
}

int Widget::getGridWidth()
{
    if (width() - 220 < height() )
        return (width() - 270) / n;
    else
        return (height() - 100) / n;
}

void Widget::adjustPosition()
{
      //窗口大小
//    this->resize(height() + 100 + 120, height());

    int xspace = (width() - (xMargin + n * getGridWidth())) / 4;
    //int yspace = height() - 100;
    //复选框
    ui->comboBox->resize(120, 40);
    ui->comboBox->move(width() - 170, 50);
    //标签
    ui->label->move(width() - 170, 50 + 60);
    ui->label_width->move(width() - 170 + 60, 50 + 60);
    ui->label_2->move(width() - 170, 50 + 90);
    ui->label_height->move(width() - 170 + 60, 50 + 90);
    ui->label_3->move(width() - 170, 50 + 120);
    ui->label_time->move(width() - 170 + 60, 50 + 120);
    //单行输入框
    ui->lineEdit_n->resize(120, 40);
    ui->lineEdit_n->move(width() - 170, height() - 50 - 100);
    //RUN按钮
    ui->pushButton_run->resize(120, 40);
    ui->pushButton_run->move(width() - 170, height() - 50 - 40);
}

void Widget::paintEvent(QPaintEvent *event)
{
    //不符合条件，后面的绘制会用到n，继续绘制会导致程序卡退
    if(n < 4 && n != 1)
        return;

    //打印窗口大小
    ui->label_width->setText(QString::number(width()));
    ui->label_height->setText(QString::number(height()));

    //计算棋盘边缘
    if (width() - 220 < height() )
    {
        xMargin = 50;
        yMargin = (height() - n * getGridWidth()) / 2;
    }
    else
    {
        xMargin = (width() - 220 - n * getGridWidth()) / 2;
        yMargin = 50;
    }
    //动态调整部件位置
    adjustPosition();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true); // 抗锯齿

    // 绘制棋盘
    for (int i = 0; i < n+1; i++)
    {
        //画竖线
        painter.drawLine(xMargin + getGridWidth() * i, yMargin, xMargin + getGridWidth() * i, yMargin + getBoardWidth());
        //画横线
        painter.drawLine(xMargin, yMargin + getGridWidth() * i, xMargin + getBoardWidth(), yMargin + getGridWidth() * i);
    }

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    if(!nqueens.empty())
    {
        vector<string> res=nqueens.front();
        //绘制第一种解法
        QImage image;
        image.load(":/img/queen.png");
        QImage scaledImage = image.scaled(getGridWidth(), getGridWidth(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        for(int i=0;i < res.size();i++)
        {
            string e=res[i];
            for(int j=0;j < e.size();j++)
            {
                char c=e[j];
                if(c=='Q')
                {
                    painter.drawImage(xMargin + j * getGridWidth(), yMargin + i * getGridWidth(), scaledImage);
                }
            }
        }
    }
}

//点击RUN按钮运行程序
void Widget::on_pushButton_run_clicked()
{
    n = getN();//按下RUN按钮才获取皇后数量
    if(n < 4 && n != 1)
        return;
    getSolution();

    //打印耗时
//    double time_to_print = time;
//    QString time_string;
//    if (time < 0.0001)
//    {
//        time_to_print = time * 1000;
//        QString time_string = QString::number(time_to_print, 'f', 4);//以浮点数格式输出，小数点后保留四位
//        time_string.append('ms');
//    }
//    else {
//        time_string = QString::number(time_to_print, 'f', 4);//以浮点数格式输出，小数点后保留四位
//        time_string.append('s');
//    }
    QString time_string = QString::number(time, 'f', 4);//以浮点数格式输出，小数点后保留四位
    time_string.append('s');
    ui->label_time->setText(time_string);

    update();
//    repaint();
}
