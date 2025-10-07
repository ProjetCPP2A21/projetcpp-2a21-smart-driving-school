#include "moniteur.h"
#include "ui_moniteur.h"
#include "menu.h"

moniteur::moniteur(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::moniteur)
{
    ui->setupUi(this);
}

moniteur::~moniteur()
{
    delete ui;
}

void moniteur::on_BretourMoniteur_clicked()
{
    menu *menuWindow = new menu(this);
    menuWindow->show();
    this->close();
}
