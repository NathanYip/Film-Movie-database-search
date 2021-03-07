#ifndef PROJCREATIONWINDOW_H
#define PROJCREATIONWINDOW_H

#include <QWidget>
#include <QFileDialog>
#include <QListWidget>
#include <QLineEdit>
#include <QDebug>
#include "mastercontroller.h"
#include "film.h"
#include "addmaterialsdialog.h"
#include "popupdialog.h"

//Circular dependancy? Later we can fix this
class AddMaterialsDialog;

namespace Ui {
class projCreationWindow;
}

class projCreationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit projCreationWindow(QWidget *parent = 0);
    ~projCreationWindow();
    static Film *newFilm;

private slots:
    void on_btn_AddLanguage_clicked();

    void on_txt_Languages_returnPressed();

    void on_btn_DelLanguauges_clicked();

    void on_btn_AddFilmLoc_clicked();

    void on_txt_FilmLocs_returnPressed();

    void on_btn_DelFilmLoc_clicked();

    void on_btn_AddKeyword_clicked();

    void on_txt_Keyword_returnPressed();

    void on_btn_DelKeyword_clicked();

    void on_btn_SaveDetails_clicked();

    void on_btn_AddMaterial_clicked();

    void addTextToList(QListWidget *list, QLineEdit *text);

    void selectFile();

    void on_date_ReleaseDate_userDateChanged(const QDate &date);

private:
    Ui::projCreationWindow *ui;

    Support supporter;
    AddMaterialsDialog *materialsDialog;
    PopupDialog *popupDialog;
};

#endif // PROJCREATIONWINDOW_H
