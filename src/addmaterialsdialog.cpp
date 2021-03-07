#include "addmaterialsdialog.h"
#include "ui_addmaterialsdialog.h"

AddMaterialsDialog::AddMaterialsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMaterialsDialog)
{
    ui->setupUi(this);
    newMaterials = new FilmMaterials();
	QStringList types;// = { "Single-sided DVD", "Double-sided DVD", "VHS", "Blue-rays" };
	types.push_back("Single-sided DVD");
	types.push_back("Double-sided DVD");
	types.push_back("VHS");
	types.push_back("Blue-rays");
    ui->cmbBox_Types->addItems(types);
    popupDialog = new PopupDialog();
    connect(ui->txt_AudioFormats,SIGNAL(returnPressed()),SLOT(on_btn_AddAudioFormat_clicked()));
    connect(ui->txt_BonusFeatures, SIGNAL(returnPressed()), SLOT(on_Btn_AddBonusFeature_clicked()));
}

AddMaterialsDialog::~AddMaterialsDialog()
{
    delete ui;
}

void AddMaterialsDialog::on_btn_AddAudioFormat_clicked()
{
    if (ui->txt_AudioFormats->text() == "")
    {
        popupDialog->setDialog(QString("This can't be empty"));
        popupDialog->show();
    }
    else
    {
        ui->lst_AudioFormats->addItem(ui->txt_AudioFormats->text());
        ui->txt_AudioFormats->setText("");
    }
}

void AddMaterialsDialog::on_btn_DelAudioFormat_clicked()
{
    qDeleteAll(ui->lst_AudioFormats->selectedItems());
}

void AddMaterialsDialog::on_Btn_AddBonusFeature_clicked()
{
    if (ui->txt_BonusFeatures->text() == "")
    {
        popupDialog->setDialog(QString("This can't be empty"));
        popupDialog->show();
    }
    else
    {
        ui->lst_BonusFeatures->addItem(ui->txt_BonusFeatures->text());
        ui->txt_BonusFeatures->setText("");
    }
}

void AddMaterialsDialog::on_btn_DelBonusFeature_clicked()
{
    qDeleteAll(ui->lst_BonusFeatures->selectedItems());
}

void AddMaterialsDialog::on_btn_Cancel_clicked()
{
    this->close();
}

void AddMaterialsDialog::on_btn_Apply_clicked()
{
    newMaterials->type = Support::QString_To_String(ui->cmbBox_Types->itemText(ui->cmbBox_Types->currentIndex()));
    newMaterials->frame = Support::QString_To_String(ui->txt_Frame->text());

    for (int i = 0; i < ui->lst_AudioFormats->count(); ++i)
    {
        newMaterials->audioFormat.push_back(Support::QString_To_String(ui->lst_AudioFormats->takeItem(i)->text()));
    }
    for (int i = 0; i < ui->lst_BonusFeatures->count(); ++i)
    {
        newMaterials->bonusFeatures.push_back(Support::QString_To_String(ui->lst_BonusFeatures->takeItem(i)->text()));
    }
    projCreationWindow::newFilm->materials.push_back(*&newMaterials);

    this->close();
}
