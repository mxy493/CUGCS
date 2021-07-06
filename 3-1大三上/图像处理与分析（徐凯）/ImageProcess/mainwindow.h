#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <process.h>
#include <QFileDialog>
#include "myimage.h"

#define USE_QIMAGE false

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
    void on_openImageButton_clicked();

    void on_imageInverseButton_clicked();

    void on_zhifangtuButton_clicked();

    void on_laplaceButton_clicked();

    void on_saveImageButton_clicked();

    void on_blurButton_clicked();

    void on_gamaButton_clicked();

private:
    Ui::MainWindow *ui;

    QImage srcImage;
    QImage paintImage;
    MyImage mySrcImage;
    QString filePath;//文件路径
    QString fileSavePath;//文件保存路径
    int gaussKerelSize=3;
    double gaussSigma=0.8;
    double gama=0.8;

    void paintEvent(QPaintEvent* paintEvent);
};

#endif // MAINWINDOW_H
