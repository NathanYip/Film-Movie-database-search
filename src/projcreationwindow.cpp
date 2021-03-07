#include "projcreationwindow.h"
#include "ui_projcreationwindow.h"

Film  * projCreationWindow::newFilm = new Film();

projCreationWindow::projCreationWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::projCreationWindow)
{
    ui->setupUi(this);
    popupDialog = new PopupDialog();
    materialsDialog = new AddMaterialsDialog();
    popupDialog->setModal(true);
    materialsDialog->setModal(true);
    connect(ui->btn_SelectImg, SIGNAL(clicked()), SLOT(selectFile()));
    ui->date_ReleaseDate->setDate(QDate::currentDate());
}

projCreationWindow::~projCreationWindow()
{
    delete ui;
}

void projCreationWindow::addTextToList(QListWidget *list, QLineEdit *text)
{
    if (text->text() == "")
    {
        popupDialog->setDialog(QString("This box can't be empty"));
        popupDialog->show();
    }
    else
    {
        list->addItem(text->text());
        text->setText("");
    }
}

void projCreationWindow::on_btn_AddLanguage_clicked()
{
    if (ui->txt_Languages->text() == "")
    {
        popupDialog->setDialog(QString("This box can't be empty"));
        popupDialog->show();
    }

    else
    {
        ui->lst_Languages->addItem(ui->txt_Languages->text());
        ui->txt_Languages->setText("");
    }
}

void projCreationWindow::on_txt_Languages_returnPressed()
{
    on_btn_AddLanguage_clicked();
}

void projCreationWindow::on_btn_DelLanguauges_clicked()
{
    qDeleteAll(ui->lst_Languages->selectedItems());
}

void projCreationWindow::on_btn_AddFilmLoc_clicked()
{
    if (ui->txt_FilmLocs->text() == "")
    {
       popupDialog->setDialog(QString("This box can't be empty"));
       popupDialog->show();
    }

    else
    {
        ui->lst_FilmLocs->addItem(ui->txt_FilmLocs->text());
        ui->txt_FilmLocs->setText("");
    }
}

void projCreationWindow::on_txt_FilmLocs_returnPressed()
{
    on_btn_AddFilmLoc_clicked();
}

void projCreationWindow::on_btn_DelFilmLoc_clicked()
{
    qDeleteAll(ui->lst_FilmLocs->selectedItems());
}

void projCreationWindow::on_btn_AddKeyword_clicked()
{
    if (ui->txt_Keyword->text() == "")
    {
        popupDialog->setDialog(QString("This box can't be empty"));
        popupDialog->show();
    }

    else
    {
        ui->lst_Keywords->addItem(ui->txt_Keyword->text());
        ui->txt_Keyword->setText("");
    }
}

void projCreationWindow::on_txt_Keyword_returnPressed()
{
    on_btn_AddKeyword_clicked();
}

void projCreationWindow::on_btn_DelKeyword_clicked()
{
    qDeleteAll(ui->lst_Keywords->selectedItems());
}

void projCreationWindow::on_btn_SaveDetails_clicked()
{
    //Checks that the runtime field has the correct syntax
    if (ui->txt_RunTime->text().indexOf('-') != 2)
    {
        popupDialog->setDialog(QString("The runtime syntax is wrong\nit should be SS-MM-HH"));
        popupDialog->show();
    }
    else
    { 
		Film *newFilm = new Film();
        newFilm->filmID = MasterController::getInstance()->movieStore->length();
        newFilm->title = supporter.QString_To_String(ui->txt_Title->text());
        newFilm->genre = supporter.QString_To_String(ui->txt_Genre->text());

        vector<string> movieRuntime = supporter.splitString(supporter.QString_To_String(ui->txt_RunTime->text()),"-");
        newFilm->runtime.seconds = std::stoi(movieRuntime[0]);
        newFilm->runtime.minutes = std::stoi(movieRuntime[1]);
        newFilm->runtime.hours = std::stoi(movieRuntime[2]);

        if (newFilm->isReleased())
        {

        }

        newFilm->summary = supporter.QString_To_String(ui->txt_Summary->toPlainText());

        for (int i = 0;i < ui->lst_Keywords->count(); ++i)
            newFilm->keywords.push_back(supporter.QString_To_String(ui->lst_Keywords->takeItem(i)->text()));

        for (int i = 0;i < ui->lst_FilmLocs->count(); ++i)
            newFilm->locations.push_back(supporter.QString_To_String(ui->lst_FilmLocs->takeItem(i)->text()));

        for (int i = 0; i < ui->lst_Languages->count(); ++i)
            newFilm->languages.push_back(supporter.QString_To_String(ui->lst_Languages->takeItem(i)->text()));

        if (MasterController::getInstance()->addFilm(newFilm))
        {
            popupDialog->setDialog(QString("Project succesfully created"));
            popupDialog->show();
        }
        else
        {
            popupDialog->setDialog(QString("Project Creation Failure!"));
            popupDialog->show();
        }
        this->close();
    }
}

void projCreationWindow::on_btn_AddMaterial_clicked()
{
    if (newFilm->isReleased())
    {
        materialsDialog->exec();
    }
    else
    {
        popupDialog->setDialog(QString("The project is not released"));
        popupDialog->show();
    }
}

void projCreationWindow::selectFile()
{
    QString directory = QFileDialog::getOpenFileName(this,
                            tr("Open File"), QDir::currentPath());
    QPixmap img;
    img.load(directory);

    if (!directory.isEmpty())
    {
        ui->lbl_Img->setPixmap(img);
    }
}

void projCreationWindow::on_date_ReleaseDate_userDateChanged(const QDate &date)
{
    newFilm->releaseDate = supporter.QString_To_String(ui->date_ReleaseDate->date().toString());
}
