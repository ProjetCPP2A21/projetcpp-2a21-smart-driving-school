#include "connection.h"
<<<<<<< HEAD
#include <QSqlError>
#include <QDebug>

Connection::Connection() {}
=======
>>>>>>> 6261b74d60c6f1db7570688dee03222a2a4f5da2

bool Connection::createconnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
<<<<<<< HEAD
=======

    // ⚠️ adapte le nom de ta source de données ODBC ici :
>>>>>>> 6261b74d60c6f1db7570688dee03222a2a4f5da2
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("islem");
    db.setPassword("islem");

<<<<<<< HEAD
    if(!db.open()){
        qDebug() << "Erreur de connexion:" << db.lastError().text();
        return false;
    }
    return true;
}


=======
    return db.open(); // true si la connexion réussit, false sinon
}
>>>>>>> 6261b74d60c6f1db7570688dee03222a2a4f5da2
