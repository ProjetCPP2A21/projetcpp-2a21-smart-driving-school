#include "cnx.h"
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>

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

bool Connection::ensureSchema()
{
    QSqlDatabase db = QSqlDatabase::database("oracle_connection");
    if (!db.isOpen()) return false;

    QSqlQuery q(db);

    q.prepare("SELECT COUNT(*) FROM user_tables WHERE table_name = 'PAIEMENTS'");
    if (!q.exec()) {
        qDebug() << "Erreur vérification tables:" << q.lastError().text();
        return false;
    }
    bool paiementsExists = false;
    if (q.next()) paiementsExists = (q.value(0).toInt() > 0);
    if (!paiementsExists) {
        QString ddlPaiements =
            "CREATE TABLE PAIEMENTS ("
            "  ID_PAIEMENT NUMBER PRIMARY KEY,"
            "  TYPE_PAIEMENT VARCHAR2(50) NOT NULL,"
            "  DATE_PAIEMENT DATE NOT NULL,"
            "  HEURE_PAIEMENT VARCHAR2(20) NOT NULL,"
            "  MONTANT NUMBER(12,2) NOT NULL,"
            "  ID_APPRENANT NUMBER"
            ")";
        if (!q.exec(ddlPaiements)) {
            qDebug() << "Erreur création PAIEMENTS:" << q.lastError().text();
            return false;
        }
    }

    q.prepare("SELECT COUNT(*) FROM user_tables WHERE table_name = 'EMPREINTES'");
    if (!q.exec()) {
        qDebug() << "Erreur vérification tables:" << q.lastError().text();
        return false;
    }
    bool empreintesExists = false;
    if (q.next()) empreintesExists = (q.value(0).toInt() > 0);
    if (!empreintesExists) {
        QString ddlEmpreintes =
            "CREATE TABLE EMPREINTES ("
            "  ID VARCHAR2(64) PRIMARY KEY"
            ")";
        if (!q.exec(ddlEmpreintes)) {
            qDebug() << "Erreur création EMPREINTES:" << q.lastError().text();
            return false;
        }
    }

    return true;
}
