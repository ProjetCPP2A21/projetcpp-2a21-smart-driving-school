#include "paiement.h"
#include "ui_paiement.h"

paiement::paiement(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::paiement)
{
    ui->setupUi(this);
}

paiement::~paiement()
{
    delete ui;
}
