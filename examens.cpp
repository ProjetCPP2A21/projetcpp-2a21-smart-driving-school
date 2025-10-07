#include "examens.h"
#include "ui_examens.h"
#include "menu.h"

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

void examens::on_Bretour_clicked()
{
    menu *menuWindow = new menu(this->parentWidget());
    menuWindow->show();
    this->close();
}
