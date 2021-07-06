#include "losedialog.h"
#include "ui_losedialog.h"

LoseDialog::LoseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoseDialog)
{
    ui->setupUi(this);
}

LoseDialog::~LoseDialog()
{
    delete ui;
}
void LoseDialog::mousePressEvent(QMouseEvent *event)
{

}
