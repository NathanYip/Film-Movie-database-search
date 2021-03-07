#ifndef VIEWPROJECTSWINDOW_H
#define VIEWPROJECTSWINDOW_H

#include <QDialog>
#include <QStringListModel>
#include <QListWidgetItem>
#include "film.h"
#include "support.h"
#include "mastercontroller.h"
#include "viewprojectdialog.h"

class viewProjectDialog;

namespace Ui {
class ViewProjectsWindow;
}

class ViewProjectsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ViewProjectsWindow(QWidget *parent = 0);
    ~ViewProjectsWindow();
    static int getSelectedInt() { return selectedIndex; }

private slots:

    void on_btn_Cancel_clicked();

    void on_btn_Ok_clicked();

    void on_lst_Projects_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::ViewProjectsWindow *ui;
    viewProjectDialog *projectDialog;
    static int selectedIndex;
};

#endif // VIEWPROJECTSWINDOW_H
