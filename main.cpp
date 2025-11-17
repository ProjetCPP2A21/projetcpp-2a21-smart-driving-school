#include "apprenants.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;

    if(c.createconnect()){
        QMessageBox::information(nullptr, "Connexion", "Connexion réussie !");
        apprenants w;  // <-- classe correcte
        w.show();
        return a.exec();
    }
    else{
        QMessageBox::critical(nullptr, "Erreur", "Échec de la connexion à la base de données");
        return 0;
    }
}
