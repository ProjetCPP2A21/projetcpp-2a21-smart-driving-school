#include "examen.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QDate>

Examen::Examen() {}

Examen::Examen(int id, QString type, QString date, QString heure, QString lieu, QString vehicule, QString resultat)
{
    this->id = id;
    this->type = type;
    this->date = date;
    this->heure = heure;
    this->lieu = lieu;
    this->vehicule = vehicule;
    this->resultat = resultat;
}

bool Examen::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EXAMEN (ID_EXAMEN, TYPE, DATE_EXAMEN, HEURE, LIEU, VEHICULE, RESULTAT) "
                  "VALUES (:id, :type, TO_DATE(:date, 'DD/MM/YYYY'), :heure, :lieu, :vehicule, :resultat)");
    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":date", date);
    query.bindValue(":heure", heure);
    query.bindValue(":lieu", lieu);
    query.bindValue(":vehicule", vehicule);
    query.bindValue(":resultat", resultat);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur SQL",
                              "⚠️ Erreur : " + query.lastError().text());
        qDebug() << "Requête SQL :" << query.lastQuery();
        return false;
    }

    return true;
}

bool Examen::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EXAMEN WHERE ID_EXAMEN = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool Examen::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE EXAMEN SET TYPE=:type, DATE_EXAMEN=:date, HEURE=:heure, LIEU=:lieu, VEHICULE=:vehicule, RESULTAT=:resultat "
                  "WHERE ID_EXAMEN=:id");
    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":date", QDate::fromString(date,"dd/MM/yyyy").toString("yyyy-MM-dd")); // 🔹
    query.bindValue(":heure", heure);
    query.bindValue(":lieu", lieu);
    query.bindValue(":vehicule", vehicule);
    query.bindValue(":resultat", resultat);
    return query.exec();
}

QSqlQueryModel* Examen::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_EXAMEN, TYPE, DATE_EXAMEN, HEURE, LIEU, VEHICULE, RESULTAT FROM EXAMEN");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Véhicule"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Résultat"));
    return model;
}
