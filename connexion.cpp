#include "connexion.h"
#include "ui_connexion.h"
#include "menu.h"

connexion::connexion(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::connexion)
{
    ui->setupUi(this);
}

connexion::~connexion()
{
    delete ui;
}

void connexion::on_Bconnexion_clicked()
{
    menu *menuWindow = new menu(this);
    menuWindow->show();
    this->hide();
}
