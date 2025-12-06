#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
<<<<<<< HEAD

Connection::Connection() {}

bool Connection::createconnect()
{
=======
#include <QMessageBox>

Connection::Connection() : lastError("") {}

bool Connection::createconnect()
{
    // Réinitialisation du message d'erreur
    lastError = "";
    
    // Vérification de la disponibilité du pilote ODBC
    if (!QSqlDatabase::isDriverAvailable("QODBC")) {
        lastError = "Le pilote QODBC n'est pas disponible sur ce système.";
        qCritical() << lastError;
        return false;
    }

    // Configuration de la connexion
>>>>>>> 4229cbb (ajout arduino)
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("islem");
    db.setPassword("islem");

<<<<<<< HEAD
    if(!db.open()){
        qDebug() << "Erreur de connexion:" << db.lastError().text();
        return false;
    }
=======
    // Tentative de connexion
    if (!db.open()) {
        lastError = "Échec de la connexion à la base de données : " + db.lastError().text();
        qCritical() << lastError;
        return false;
    }
    
    // Vérification que la connexion est valide
    if (!db.isValid()) {
        lastError = "La connexion à la base de données n'est pas valide.";
        qCritical() << lastError;
        db.close();
        return false;
    }
    
    qDebug() << "Connexion à la base de données établie avec succès.";
>>>>>>> 4229cbb (ajout arduino)
    return true;
}
