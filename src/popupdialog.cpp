#include "popupdialog.h"
#include "ui_popupdialog.h"

PopupDialog::PopupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopupDialog)
{
    ui->setupUi(this);
}

PopupDialog::~PopupDialog()
{
    delete ui;
}

void PopupDialog::setDialog(QString msg)
{
    ui->lbl_DialogMsg->setText(msg);
}

void PopupDialog::on_pushButton_clicked()
{
    this->close();
}
