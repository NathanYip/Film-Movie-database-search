#include "include/viewprojectswindow.h"
#include "ui_viewprojectswindow.h"

int ViewProjectsWindow::selectedIndex = 0 ;

ViewProjectsWindow::ViewProjectsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewProjectsWindow)
{
    ui->setupUi(this);
    projectDialog = new viewProjectDialog();
    for (int i = 0; i < MasterController::getInstance()->movieStore->length(); ++i)
    {
        InfoContainer *tempContainer = MasterController::getInstance()->movieStore->getAt(i);
        Film *tempFilm = static_cast<Film*>(tempContainer);
		//ui->lst_Projects->addItem(QString(Support::stringToQByteArray(tempFilm->filmID +"-"+tempFilm->title)));

		string linepre = Support::intToString(tempFilm->filmID) + "-";
		string line = linepre + tempFilm->title;
		const char * str = line.data();

		ui->lst_Projects->addItem( QString( str ) );
    }

}

ViewProjectsWindow::~ViewProjectsWindow()
{
    delete ui;
}

void ViewProjectsWindow::on_btn_Cancel_clicked()
{
    this->close();
}

void ViewProjectsWindow::on_btn_Ok_clicked()
{
    projectDialog->setModal(true);
    projectDialog->show();
}

void ViewProjectsWindow::on_lst_Projects_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
   // lbl_poster

   vector<string> tempString = Support::splitString(  Support::QString_To_String(ui->lst_Projects->currentItem()->text()),"-");
   selectedIndex = Support::stringToInt(tempString.at(0));

   Film *f = static_cast<Film*>(MasterController::getInstance()->movieStore->getAt( selectedIndex ));

   
   string posterName = f->imageFilePath;

   string posterPath =  Support::getResourcePath() + ( posterName.substr(1, posterName.length()-1) );

   QImage image;

   bool stat = image.load(QString(posterPath.data()));

   QPixmap p;

   p.load(QString(posterPath.data()));

   qDebug( Support::stringToQByteArray(""+posterPath + Support::booleanToString(stat)) );

   ui->lbl_poster->setPixmap(p);

}
