#include "menu.h"
#include "ui_menu.h"
#include "examens.h"
#include "apprenant.h"


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
void menu::on_Bexamens_clicked()
{
    examens *examWindow = new examens(this);
    examWindow->show();
    this->hide(); // optionnel, si tu veux fermer le menu
}

void menu::on_Bapprenant_clicked()
{
    apprenant *apprenantWindow = new apprenant(this);  // créer la fenêtre apprenant
    apprenantWindow->show();
    this->hide();  // cacher le menu
}

