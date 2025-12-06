#include "ajouter_examen.h"
#include "ui_ajouter_examen.h"

Ajouter_examen::Ajouter_examen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ajouter_examen)
{
    ui->setupUi(this);
}

Ajouter_examen::~Ajouter_examen()
{
    delete ui;
}
