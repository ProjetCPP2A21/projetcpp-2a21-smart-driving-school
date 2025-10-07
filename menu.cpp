#include "menu.h"
#include "ui_menu.h"
#include "examens.h"
#include "apprenant.h"
#include "moniteur.h"
#include "paiement.h"
#include "vehicule.h"

menu::menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_Bexamens_clicked()
{
    examens *examWindow = new examens(this);
    examWindow->show();
    this->hide();
}

void menu::on_Bapprenant_clicked()
{
    apprenant *apprenantWindow = new apprenant(this);
    apprenantWindow->show();
    this->hide();
}

void menu::on_Bmoniteurs_clicked()
{
    moniteur *moniteurWindow = new moniteur(this);
    moniteurWindow->show();
    this->hide();
}

void menu::on_Bpaiement_clicked()
{
    paiement *paiementWindow = new paiement(this);
    paiementWindow->show();
    this->hide();
}

void menu::on_Bvehicule_clicked()
{
    vehicule *vehiculeWindow = new vehicule(this);
    vehiculeWindow->show();
    this->hide();
}
