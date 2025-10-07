#include "vehicule.h"
#include "ui_vehicule.h"
#include "menu.h"

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

void vehicule::on_BretourVehicule_clicked()
{
    menu *menuWindow = new menu(this);
    menuWindow->show();
    this->close();
}
