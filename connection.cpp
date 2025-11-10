#include "connection.h"

bool Connection::createconnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    // ⚠️ adapte le nom de ta source de données ODBC ici :
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("islem");
    db.setPassword("islem");

    return db.open(); // true si la connexion réussit, false sinon
}
