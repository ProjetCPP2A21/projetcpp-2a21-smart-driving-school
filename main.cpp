#include "moniteur_ui.h"
#include "cnx.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Connection c;
    if (!c.createconnect()) {
        QMessageBox::critical(nullptr, "Erreur", "Échec de la connexion à la base de données !");
        return -1;
    } else {
        QMessageBox::information(nullptr, "Connexion", "Connexion à la base réussie !");
    }

    moniteur_ui w;
    w.show();

    return a.exec();
}
