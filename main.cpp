#include <QApplication>
#include <QMessageBox>
#include "mainwindow.h"
#include "cnx.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Initialisation de la connexion à la base Oracle via ODBC
    Connection c;
    if (!c.createconnect()) {
        QMessageBox::critical(nullptr,
                              "Erreur Connexion",
                              "Impossible de se connecter à la base de données Oracle.\n"
                              "Vérifiez le DSN et les identifiants.");
        return -1; // Arrêt de l'application si la connexion échoue
    }

    // Création et affichage de la fenêtre principale
    MainWindow w;
    w.show();

    return a.exec();
}
