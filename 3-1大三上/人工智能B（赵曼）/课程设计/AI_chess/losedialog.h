#ifndef LOSEDIALOG_H
#define LOSEDIALOG_H

#include <QDialog>
#include <QMouseEvent>

namespace Ui {
class LoseDialog;
}

class LoseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoseDialog(QWidget *parent = 0);
    ~LoseDialog();

private:
    Ui::LoseDialog *ui;
    void mousePressEvent(QMouseEvent *event);
};

#endif // LOSEDIALOG_H
