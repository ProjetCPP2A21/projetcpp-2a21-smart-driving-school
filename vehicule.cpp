#include "vehicule.h"
#include "ui_vehicule.h"

vehicule::vehicule(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::vehicule)
{
    ui->setupUi(this);
}

vehicule::~vehicule()
{
    delete ui;
}
