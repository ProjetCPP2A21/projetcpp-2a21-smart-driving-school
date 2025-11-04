#include "cnx.h"
#include <QSqlError>
#include <QDebug>

Connection::Connection() {}

bool Connection::createconnect() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A"); // nom de la source ODBC
    db.setUserName("AMIN");                // utilisateur Oracle
    db.setPassword("15021980");            // mot de passe Oracle

    if (!db.open()) {
        qDebug() << "Erreur de connexion:" << db.lastError().text();
        return false;
    } else {
        qDebug() << "Connexion réussie à la base de données.";
        return true;
    }
}
