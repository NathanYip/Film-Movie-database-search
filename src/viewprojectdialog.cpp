#include "include/viewprojectdialog.h"
#include "ui_viewprojectdialog.h"

viewProjectDialog::viewProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewProjectDialog)
{
    ui->setupUi(this);
    InfoContainer *tempContainer = MasterController::getInstance()->movieStore->getAt(ViewProjectsWindow::getSelectedInt());
    Film *tempFilm = static_cast<Film*>(tempContainer);
    ui->txt_Title->setText(Support::stringtoQString(tempFilm->title));
    ui->txt_Date->setText(Support::stringtoQString(tempFilm->releaseDate));
    ui->txt_Genre->setText(Support::stringtoQString(tempFilm->genre));
    ui->txt_Runtime->setText(Support::stringtoQString(Support::intToString(tempFilm->runtime.seconds) + " "
                                                      + Support::intToString(tempFilm->runtime.minutes) + " "
                                                      + Support::intToString(tempFilm->runtime.hours)));
    ui->txt_Summary->setText(Support::stringtoQString(tempFilm->summary));

    for (int i =0; i < tempFilm->keywords.size(); ++i)
        ui->lst_FilmLocs->addItem(Support::stringtoQString(tempFilm->keywords.at(i)));

    for (int i = 0; i < tempFilm->languages.size(); ++i)
        ui->lst_Lang->addItem(Support::stringtoQString(tempFilm->languages.at(i)));

    for (int i = 0; i < tempFilm->locations.size(); ++i)
        ui->lst_FilmLocs->addItem(Support::stringtoQString(tempFilm->locations.at(i)));
}

viewProjectDialog::~viewProjectDialog()
{
    delete ui;

}

void viewProjectDialog::on_btn_Ok_clicked()
{
    this->close();
}
