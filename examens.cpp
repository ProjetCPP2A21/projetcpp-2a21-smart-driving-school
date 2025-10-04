#include "examens.h"
#include "ui_examens.h"
<<<<<<< HEAD
#include "menu.h"   // pour pouvoir revenir au menu

examens::examens(QWidget *parent)
=======
#include "menu.h"


examens::examens(QMainWindow *parent)
>>>>>>> origin/main-original
    : QMainWindow(parent)
    , ui(new Ui::examens)
{
    ui->setupUi(this);
}

examens::~examens()
{
    delete ui;
}
<<<<<<< HEAD

=======
>>>>>>> origin/main-original
void examens::on_Bretour_clicked()
{
    menu *menuWindow = new menu(this->parentWidget()); // récupère le menu parent
    menuWindow->show();   // affiche le menu
    this->close();        // ferme la fenêtre examens
}
