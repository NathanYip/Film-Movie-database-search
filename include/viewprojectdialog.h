#ifndef VIEWPROJECTDIALOG_H
#define VIEWPROJECTDIALOG_H

#include <QDialog>
#include "viewprojectswindow.h"

namespace Ui {
class viewProjectDialog;
}

class viewProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit viewProjectDialog(QWidget *parent = 0);
    ~viewProjectDialog();

private slots:
    void on_btn_Ok_clicked();

private:
    Ui::viewProjectDialog *ui;
};

#endif // VIEWPROJECTDIALOG_H
