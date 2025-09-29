#include "moniteur.h"
#include "ui_moniteur.h"

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
