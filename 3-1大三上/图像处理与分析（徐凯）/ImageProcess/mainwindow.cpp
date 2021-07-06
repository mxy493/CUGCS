#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *paintEvent)
{
    QPainter painter(this);
#if USE_QIMAGE
    painter.drawImage(10,40,paintImage);
#else
    //painter.drawImage(10,40,srcImage);
    if(filePath!="")
    {
        //MyImage myimage(filePath.toStdString());
        // mySrcImage.load(filePath.toStdString());
        for(int i=0;i<mySrcImage.width();i++)
        {
            for(int j=0;j<mySrcImage.height();j++)
            {
                painter.setPen(qRgb(mySrcImage.getPixelColor(i,j).rgbRed,mySrcImage.getPixelColor(i,j).rgbRed,mySrcImage.getPixelColor(i,j).rgbRed));
                //cout<<mySrcImage.getPixelColor(i,j).rgbRed<<" ";
                painter.drawPoint(i+10,j+40);
            }
           // cout<<endl;
        }
    }
#endif
}

void MainWindow::on_openImageButton_clicked()
{
    //打开文件
    filePath=QFileDialog::getOpenFileName(this,tr("Open Image"), ".", tr("Image Files (*.png *.jpg *.bmp)"));
#if USE_QIMAGE
    srcImage.load(filePath);
#else
    mySrcImage.load(filePath.toStdString());
#endif
    //MyImage myimage(filePath.toStdString());
    update();
}

void MainWindow::on_imageInverseButton_clicked()
{
#if USE_QIMAGE
    paintImage=imageInverse(srcImage);
#else
    mySrcImage=imageInverse(mySrcImage);
#endif
//    for(int i=0;i<mySrcImage.height();i++)
//    {
//        for(int j=0;j<mySrcImage.width();j++)
//        {
//            cout<<mySrcImage.getPixelColor(j,i).rgbBlue<<" ";
//        }
//        cout<<endl;
//    }
    update();

}

void MainWindow::on_zhifangtuButton_clicked()
{
#if USE_QIMAGE
    paintImage=histoEqalizate(srcImage);
#else
    mySrcImage=histoEqalizate(mySrcImage);
#endif
    update();
}

void MainWindow::on_laplaceButton_clicked()
{
#if USE_QIMAGE
    paintImage=laplaceProcess(srcImage);
#else
    mySrcImage=laplaceProcess(mySrcImage);
#endif
    update();
}

void MainWindow::on_saveImageButton_clicked()
{
    fileSavePath = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "./newImage.bmp",
                               tr("Images (*.bmp)"));
    //mySrcImage.writeFile(fileSavePath.toStdString());
    //MyImage saveImage;
    //saveImage=mySrcImage;
    //saveImage.writeFile(fileSavePath.toStdString());
    //QImage image(20,20,QImage::Format_Grayscale8);
    //image.setColorCount(8);
    //image.fill(50);
    //image.save(fileSavePath);
#if USE_QIMAGE
    paintImage.save(fileSavePath);
#else
    mySrcImage.writeFile(fileSavePath.toStdString());
#endif

}

void MainWindow::on_blurButton_clicked()
{
   int tempSize= ui->intEdit->toPlainText().toInt();
   double tempSigma=ui->doubleEdit->toPlainText().toDouble();
   if(tempSize>=0&&tempSize!=3&&(tempSize&1))
   {
       gaussKerelSize=tempSize;
   }
   if(tempSigma>=0)
   {
       gaussSigma=tempSigma;
   }
#if USE_QIMAGE
    paintImage=gaussianBlur(srcImage,gaussKerelSize,gaussSigma);
#else
    mySrcImage=gaussianBlur(mySrcImage,gaussKerelSize,gaussSigma);
#endif
    update();
}

void MainWindow::on_gamaButton_clicked()
{
    double tempGama=ui->doubleEdit->toPlainText().toDouble();
    if(tempGama>=0)
    {
        gama=tempGama;
    }
#if USE_QIMAGE
    paintImage=mySrcImage=gamaProcess(srcImage,gama);
#else
    mySrcImage=gamaProcess(mySrcImage,gama);
#endif
    update();
}
