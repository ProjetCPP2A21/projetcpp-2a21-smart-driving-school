#include "menu.h"
#include "ui_menu.h"
#include "employe.h"

menu::menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_Bemploye_clicked()
{
    employe *employeWindow = new employe(this);
    employeWindow->show();
    this->hide();
}
