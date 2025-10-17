#include "ajouter_employe.h"
#include "ui_ajouter_employe.h"
#include "employe.h"

ajouter_employe::ajouter_employe(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ajouter_employe)
{
    ui->setupUi(this);
}

ajouter_employe::~ajouter_employe()
{
    delete ui;
}

void ajouter_employe::on_pushButton_ajouter_clicked()
{
    // Fonction de design seulement - pas de logique métier
    this->close();
}

void ajouter_employe::on_pushButton_annuler_clicked()
{
    this->close();
}

void ajouter_employe::on_pushButton_vider_clicked()
{
    // Fonction de design seulement - pas de logique métier
}

void ajouter_employe::on_BretourAjouterEmploye_clicked()
{
    // Retourner à la page employé
    employe *employePage = qobject_cast<employe*>(parent());
    if (employePage) {
        employePage->show();
    }
    this->close();
}

