#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QCloseEvent>

#include "mastercontroller.h"
#include "projcreationwindow.h"
#include "viewprojectswindow.h"

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
    void on_btn_OpenProjCreation_clicked();
	void closeEvent(QCloseEvent *);
    void on_btn_ViewProjects_clicked();

private:
    Ui::MainWindow *ui;
    projCreationWindow newProjectWindow;
    ViewProjectsWindow viewProjectsWindow;

};

#endif // MAINWINDOW_H
