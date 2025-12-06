#include "apprenants.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
<<<<<<< HEAD

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
=======
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // Configuration du style de l'application
    app.setStyle(QStyleFactory::create("Fusion"));
    
    // Création et configuration de la connexion
    Connection connection;
    if (!connection.createconnect()) {
        // Affichage du message d'erreur détaillé
        QMessageBox::critical(nullptr, 
                             "Erreur de connexion", 
                             "Impossible de se connecter à la base de données.\n\n"
                             "Détails : " + connection.getLastError() + "\n\n"
                             "Veuillez vérifier :\n"
                             "1. Que le serveur de base de données est en cours d'exécution\n"
                             "2. Que les identifiants de connexion sont corrects\n"
                             "3. Que le DSN 'Source_Projet2A' est correctement configuré");
        return 1; // Code de sortie d'erreur
    }
    
    // Si la connexion est établie, on lance l'application
    try {
        apprenants mainWindow;
        mainWindow.show();
        return app.exec();
    } catch (const std::exception &e) {
        QMessageBox::critical(nullptr, "Erreur critique", 
                            QString("Une erreur critique est survenue : %1").arg(e.what()));
        return 1;
    } catch (...) {
        QMessageBox::critical(nullptr, "Erreur inconnue", 
                            "Une erreur inconnue est survenue.");
        return 1;
>>>>>>> 4229cbb (ajout arduino)
    }
}
