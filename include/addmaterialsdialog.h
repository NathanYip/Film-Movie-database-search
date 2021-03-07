#ifndef ADDMATERIALSDIALOG_H
#define ADDMATERIALSDIALOG_H

#include <QDialog>
#include "popupdialog.h"
#include "projcreationwindow.h"
#include "filmmaterials.h"
#include "support.h"

namespace Ui {
class AddMaterialsDialog;
}

class AddMaterialsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddMaterialsDialog(QWidget *parent = 0);
    ~AddMaterialsDialog();

private slots:
    void on_btn_AddAudioFormat_clicked();

    void on_btn_DelAudioFormat_clicked();

    void on_Btn_AddBonusFeature_clicked();

    void on_btn_DelBonusFeature_clicked();

    void on_btn_Cancel_clicked();

    void on_btn_Apply_clicked();

private:
    Ui::AddMaterialsDialog *ui;
    PopupDialog *popupDialog;
    FilmMaterials *newMaterials;
};

#endif // ADDMATERIALSDIALOG_H
