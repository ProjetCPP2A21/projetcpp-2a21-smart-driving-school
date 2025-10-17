#include "modifier_employe.h"
#include "ui_modifier_employe.h"
#include "employe.h"

modifier_employe::modifier_employe(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::modifier_employe)
{
    ui->setupUi(this);
}

modifier_employe::~modifier_employe()
{
    delete ui;
}


void modifier_employe::on_pushButton_confirmer_clicked()
{
    // Fonction de design seulement - pas de logique métier
    this->close();
}

void modifier_employe::on_pushButton_annuler_clicked()
{
    this->close();
}

void modifier_employe::on_BretourModifierEmploye_clicked()
{
    // Retourner à la page employé
    employe *employePage = qobject_cast<employe*>(parent());
    if (employePage) {
        employePage->show();
    }
    this->close();
}

