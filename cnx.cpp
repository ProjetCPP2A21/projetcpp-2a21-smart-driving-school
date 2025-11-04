#include "cnx.h"
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de données
    db.setUserName("youssefgh");//inserer nom de l'utilisateur
    db.setPassword("1245");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;





    return  test;
}
