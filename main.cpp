#include "application_integree.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;

    if(c.createconnect()){
        QMessageBox::information(nullptr, "Connexion", "Connexion réussie !");
        application_integree w;
        w.show();
        return a.exec();
    }
    else{
        QMessageBox::critical(nullptr, "Erreur", "Échec de la connexion à la base de données");
        return 0;
    }
}


