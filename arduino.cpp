#include "arduino.h"
#include "ui_arduino.h"

arduino::arduino(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::arduino)
{
    ui->setupUi(this);
}

arduino::~arduino()
{
    delete ui;
}
