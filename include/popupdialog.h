#ifndef POPUPDIALOG_H
#define POPUPDIALOG_H

#include <QDialog>
#include <QLabel>
#include <iostream>

namespace Ui {
class PopupDialog;
}

class PopupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PopupDialog(QWidget *parent = 0);
    ~PopupDialog();
    QString dialogMessage;
    void setDialog(QString msg);

private slots:
    void on_pushButton_clicked();

private:
    Ui::PopupDialog *ui;
};

#endif // POPUPDIALOG_H
