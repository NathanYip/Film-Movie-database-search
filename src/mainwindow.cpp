#include "include/mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"


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

void MainWindow::on_btn_OpenProjCreation_clicked()
{
    newProjectWindow.show();
}

void MainWindow::closeEvent (QCloseEvent *event)
{
	// fail safe; flush storage, in case pointer deletion fails
	MasterController::getInstance()->movieStore->flush();
	MasterController::getInstance()->appStore->flush();

	// should flush once more to make sure any new changes are stored before destroying
	delete MasterController::getInstance();
	
}

void MainWindow::on_btn_ViewProjects_clicked()
{
    viewProjectsWindow.setModal(true);
    viewProjectsWindow.show();
}
