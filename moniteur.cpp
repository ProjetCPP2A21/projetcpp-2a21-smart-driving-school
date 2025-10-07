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
    menu *menuWindow = new menu(this);  // créer un nouveau menu
    menuWindow->show();                 // afficher le menu
    this->close();                      // fermer la fenêtre moniteur
}
