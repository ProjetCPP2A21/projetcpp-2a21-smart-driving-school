#include "connection.h"
#include <QSqlError>
#include <QDebug>

Connection::Connection() {}

bool Connection::createconnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("islem");
    db.setPassword("islem");

    if(!db.open()){
        qDebug() << "Erreur de connexion:" << db.lastError().text();
        return false;
    }
    return true;
}


