#include "boardwindow.h"
#include "ui_boardwindow.h"

boardWindow::boardWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::boardWindow)
{
    ui->setupUi(this);
    this->setFixedSize(650,650);
    this->setAutoFillBackground(true);
    QPalette p;
    p.setColor(QPalette::Background,QColor("#B1723C"));
    this->setPalette(p);
    //mouseflag=false;
    setMouseTracking(true);
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
            board[i][j]=0;
    }
    setPieces(7, 7, BLACK);
}

boardWindow::~boardWindow()
{
    delete ui;
}

void boardWindow::paintEvent(QPaintEvent *event)

{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen=painter.pen();
    pen.setColor(QColor("#8D5822"));
    pen.setWidth(7);
    painter.setPen(pen);

    QBrush brush;
    brush.setColor(QColor("#EEC085"));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(20,20,610,610);

    pen.setColor(Qt::black);
    pen.setWidth(1);
    painter.setPen(pen);
    //painter.drawLine(20,20,50,50);
    for(int i=0;i<15;i++)
    {
        painter.drawLine(40+i*40,40,40+i*40,600);
        painter.drawLine(40,40+i*40,600,40+i*40);
    }

    brush.setColor(Qt::black);
    painter.setBrush(brush);
    //算出中间黑点画出来
    painter.drawRect(40+7*40-5,40+7*40-5,10,10);
    painter.drawRect(40+3*40-5,40+3*40-5,10,10);
    painter.drawRect(40+3*40-5,40+11*40-5,10,10);
    painter.drawRect(40+11*40-5,40+11*40-5,10,10);
    painter.drawRect(40+11*40-5,40+3*40-5,10,10);
    //画棋子
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            //黑子
            if(board[i][j]==2)
            {
                brush.setColor(Qt::black);
                painter.setBrush(brush);
                painter.drawEllipse(QPoint((40+40*j),(40+i*40)),18,18);
            }
            if(board[i][j]==1)
            {
                brush.setColor(Qt::white);
                painter.setBrush(brush);
                painter.drawEllipse(QPoint((40+40*j),(40+i*40)),18,18);
            }

        }
    }
    //画数字
    pen.setColor(Qt::red);
    pen.setWidth(1);
    painter.setPen(pen);
    for(int i=0;i<posVecOfPieces.size();i++)
    {
        painter.drawText(QPoint((38+40*posVecOfPieces[i].y - 6),(38+posVecOfPieces[i].x*40 + 8)), QString::number(i+1));
    }
}

void boardWindow::mousePressEvent(QMouseEvent *mouseClicked)
{
    if(mouseClicked->button()==2)
        return;

    int y=(mouseClicked->x()-20)/40;
    int x=(mouseClicked->y()-20)/40;
    if(!setPieces(x,y,player))
        return ;
    repaint();
    if (isOver(x,y)&&player!=0)
    {
        int ret=QMessageBox::information(this, "五子棋","恭喜你，你赢啦！",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);
        if(ret==16384)
        {
            reset();
            player=1;
            return ;
        }
        player=0;
        return;

    }
    else
    {
        if(posVecOfPieces.size()==255)
        {
            int ret=QMessageBox::information(this,"五子棋","平局，要再来一局吗？",QMessageBox::Yes|QMessageBox::No);
            if(ret==16384)
            {
                reset();
                player=1;
                return;
            }
            player=0;
            return;
        }
    }
    if(player==2)
    {
        player=1;
    }
    else if(player==1)
    {
        player=2;
        ai.alphaBeta(player, minINFINITY, INFINITY, board,0);
        setPieces(ai.posx,ai.posy, player);
        repaint();
        player = 1;
        if (isOver(ai.posx, ai.posy)&&player!=0)
        {
            int ret=QMessageBox::information(this, "五子棋","你输了！要再来一局吗？",QMessageBox::Yes|QMessageBox::No);
            if(ret==16384)
            {
                reset();
                player = 1;
                return;
            }
            player=0;
            return;
        }
    }
    if(player==0)
    {
        int ret=QMessageBox::information(this,"五子棋","要再来一局吗？",QMessageBox::Yes|QMessageBox::No);
        if(ret==16384)
        {
            reset();
            player = 1;
            return;

        }
    }
}

bool boardWindow::setPieces(int x, int y, int side)
{
    if(board[x][y]==0)
    {
        board[x][y]=side;
        if(side!=0)
        {
            posVecOfPieces.push_back(POS(x,y));

        }
        //update();
        //paintEvent();
        return true;
    }
    return false;


}

bool boardWindow::isOver(int x, int y)
{
    //看落子的周围有没有五连即可
    //首先判断竖直方向
    int j = y-1;
    int count = 1;
    while (j>=0)
    {
        if (board[x][j--]==board[x][y])
        {
            count++;
            if (count==5)
                return true;
        }
        else
            break;
    }
    j = y + 1;
    while (j<15)
    {
        if (board[x][j++]==board[x][y])
        {
            count++;
            if (count==5)
                return true;
        }
        else
            break;
    }
    //水平方向
    int i = x - 1;
    count = 1;
    while (i>=0)
    {
        if (board[i--][y]==board[x][y])
        {
            count++;
            if (count==5)
                return true;
        }
        else
            break;
    }
    i = x + 1;
    while (i<15)
    {
        if (board[i++][y]==board[x][y])
        {
            count++;
            if (count==5)
                return true;
        }
        else
            break;
    }
    // /方向
    i = x - 1;
    j = y + 1;
    count = 1;
    while (x>=0&&j<15)
    {
        if (board[i--][j++]==board[x][y])
        {
            count++;
            if (count==5)
                return true;
        }
        else
            break;
    }
    i = x + 1; j = y - 1;
    while (x<15&&y>=0)
    {
        if (board[i++][j--]==board[x][y])
        {
            count++;
            if (count==5)
                return true;
        }
        else
            break;
    }
    // \方向
    i = x - 1; j = y - 1;
    count = 1;
    while (i>=0&&j>=0)
    {
        if (board[i--][j--]==board[x][y])
        {
            count++;
            if (count==5)
                return true;
        }
        else
            break;
    }
    i = x + 1; j = y + 1;
    while (i<15&&j<15)
    {
        if (board[i++][j++]==board[x][y])
        {
            count++;
            if (count==5)
                return true;
        }
        else
            break;
    }
    return false;
}

void boardWindow::reset()
{
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            board[i][j]=0;
        }
    }
    board[7][7]=BLACK;//放置中心棋子
    posVecOfPieces.clear();
    posVecOfPieces.push_back(POS(7,7));
    update();
}
