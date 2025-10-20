#include "connection.h"

bool Connection::createconnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("SYSTEM");   // nom de ta source ODBC
    db.setUserName("islem");        // ton nom utilisateur Oracle
    db.setPassword("islem123");     // ton mot de passe Oracle

    return db.open(); // retourne vrai si la connexion réussit
}
