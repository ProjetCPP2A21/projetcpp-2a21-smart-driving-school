#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "moniteur_ui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // Initialisation de la connexion à la base Oracle via ODBC
    Connection c;
    if (!c.createconnect()) {
        QMessageBox::critical(nullptr,
                          "Erreur Connexion",
                          "Impossible de se connecter à la base de données.\n"
                          "Veuillez réessayer plus tard.");
        return -1;
    }
    
    // Afficher uniquement l'interface de gestion des moniteurs
    moniteur_ui w;
    w.show();
    
    return a.exec();
}
