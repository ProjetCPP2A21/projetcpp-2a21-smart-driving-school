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

void modifier_employe::chargerEmploye(const QString &idEmploye)
{
    idEmployeActuel = idEmploye;
    // Charger les données de l'employé
}

void modifier_employe::on_pushButton_confirmer_clicked()
{
    // Logique de modification d'employé
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

