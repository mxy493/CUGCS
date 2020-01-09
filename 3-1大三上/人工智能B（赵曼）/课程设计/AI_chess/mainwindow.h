#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QMainWindow>
#include "boardwindow.h"
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
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
   // Ui::boardWindow *bw;
};

#endif // MAINWINDOW_H
