#include "examens.h"
#include "ui_examens.h"

examens::examens(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::examens)
{
    ui->setupUi(this);
}

examens::~examens()
{
    delete ui;
}

