#include "connection.h"
connection::connection() {}
bool connection::createconnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");   // Remplace par le nom exact de ta source ODBC
    db.setUserName("islem");        // Ton nom d’utilisateur Oracle
    db.setPassword("islem");     // Ton mot de passe Oracle

    return db.open(); // Retourne vrai si la connexion réussit
}
