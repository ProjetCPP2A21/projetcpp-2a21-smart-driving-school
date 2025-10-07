#include "paiement.h"
#include "ui_paiement.h"
#include "menu.h"

paiement::paiement(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::paiement)
{
    ui->setupUi(this);
}

paiement::~paiement()
{
    delete ui;
}

void paiement::on_BretourPaiement_clicked()
{
    menu *menuWindow = new menu(this);
    menuWindow->show();
    this->close();
}
