#include "cnx.h"
#include <QSqlError>
#include <QDebug>

Connection::Connection() {}

bool Connection::createconnect()
{
    const QString connectionName = "oracle_connection";

    QSqlDatabase db;
    if (QSqlDatabase::contains(connectionName)) {
        db = QSqlDatabase::database(connectionName);
    } else {
        db = QSqlDatabase::addDatabase("QODBC", connectionName);
        db.setDatabaseName("Source_Projet2A");  // DSN configuré dans ODBC
        db.setUserName("islem");
        db.setPassword("islem");
    }

    if (!db.open()) {
        qDebug() << " Impossible d'ouvrir la base via ODBC:" << db.lastError().text();
        return false;
    }

    qDebug() << " Connexion réussie à Oracle via ODBC.";
    return true;
}
