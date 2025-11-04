#include "ajouter.h"
#include "ui_ajouter.h"

Ajouter::Ajouter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ajouter)
{
    ui->setupUi(this);
}

Ajouter::~Ajouter()
{
    delete ui;
}
