#include "apprenant.h"
#include "ui_apprenant.h"
#include "menu.h"

apprenant::apprenant(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::apprenant)
{
    ui->setupUi(this);
}

apprenant::~apprenant()
{
    delete ui;
}

void apprenant::on_Brapprenant_clicked()
{
    menu *menuWindow = new menu(this);  // créer un nouveau menu
    menuWindow->show();                 // afficher le menu
    this->close();                      // fermer la fenêtre apprenant
}
