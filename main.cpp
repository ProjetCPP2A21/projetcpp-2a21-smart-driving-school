#include <QApplication>
#include <QMessageBox>
#include "mainwindow.h"
#include "cnx.h"
#include "test.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 1️⃣ Initialisation de la connexion Oracle
    Connection c;
    if (!c.createconnect()) {
        QMessageBox::critical(nullptr,
                              "Erreur Connexion",
                              "Impossible de se connecter à la base de données Oracle.\n"
                              "Vérifiez le DSN et les identifiants.");
        return -1; // Arrêt de l'application si la connexion échoue
    }
    c.ensureSchema();

    // 2️⃣ Démarrage de l'écoute Arduino
    Test test;  // la classe démarre l'écoute série automatiquement

    // 3️⃣ Création et affichage de la fenêtre principale
    MainWindow w;
    w.setTest(&test);
    w.show();

    return a.exec();
}
