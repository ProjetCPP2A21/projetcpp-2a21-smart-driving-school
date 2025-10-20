#include "apprenants.h"
#include "ui_apprenants.h"

apprenants::apprenants(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::apprenants)
{
    ui->setupUi(this);
}

apprenants::~apprenants()
{
    delete ui;
}
