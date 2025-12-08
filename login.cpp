#include "login.h"
#include "ui_login.h"
#include "employes.h"
#include <QMessageBox>

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_btn_connexion_clicked()
{
    Employes *employes = new Employes();
    employes->show();
    this->close();
}

void Login::on_btn_motdepasse_oublie_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Mot de passe oublié"),
                             QObject::tr("Fonctionnalité à venir.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}
