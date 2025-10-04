#include "examens.h"
#include "ui_examens.h"
#include "menu.h"


examens::examens(QMainWindow *parent)
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
    menu *menuWindow = new menu(this->parentWidget()); // récupère le menu parent
    menuWindow->show();   // affiche le menu
    this->close();        // ferme la fenêtre examens
}
