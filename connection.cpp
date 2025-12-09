#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db;
    if (QSqlDatabase::contains("oracle_connection")) {
        db = QSqlDatabase::database("oracle_connection");
    } else {
        db = QSqlDatabase::addDatabase("QODBC", "oracle_connection");
        db.setDatabaseName("Source_Projet2A");
        db.setUserName("islem");
        db.setPassword("islem");
    }

    if (!db.isOpen()) {
        test = db.open();
    } else {
        test = true;
    }
    return test;
}
