#include "employe.h"
#include "ui_employe.h"
#include "menu.h"
#include "ajouter_employe.h"
#include "modifier_employe.h"

employe::employe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::employe)
{
    ui->setupUi(this);
}

employe::~employe()
{
    delete ui;
}

void employe::on_BretourEmploye_clicked()
{
    menu *menuWindow = new menu(this);
    menuWindow->show();
    this->close();
}

void employe::on_pushButton_9_clicked()
{
    ajouter_employe *ajouterWindow = new ajouter_employe(this);
    ajouterWindow->show();
}

void employe::on_pushButton_11_clicked()
{
    modifier_employe *modifierWindow = new modifier_employe(this);
    modifierWindow->show();
}

void employe::on_pushButton_8_clicked()
{
    // Logique de suppression d'employé
}
