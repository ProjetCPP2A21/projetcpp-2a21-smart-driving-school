#include "paiement.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>

Paiement::Paiement() {}

Paiement::Paiement(int id, QString type, QString date, QString heure, QString lieu, QString offre, double montant)
{
    this->id = id;
    this->type = type;
    this->date = date;
    this->heure = heure;
    this->lieu = lieu;
    this->offre = offre;
    this->montant = montant;
}

int Paiement::getId() { return id; }
QString Paiement::getType() { return type; }
QString Paiement::getDate() { return date; }
QString Paiement::getHeure() { return heure; }
QString Paiement::getLieu() { return lieu; }
QString Paiement::getOffre() { return offre; }
double Paiement::getMontant() { return montant; }

bool Paiement::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO PAIEMENT (ID, TYPE_PAIEMENT, DATE_DE_PAIEMENT, HEURE, LIEU, OFFRE, MONTANT) "
                  "VALUES (:id, :type, TO_DATE(:date, 'DD-MM-YYYY'), :heure, :lieu, :offre, :montant)");

    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":date", date);
    query.bindValue(":heure", heure);
    query.bindValue(":lieu", lieu);
    query.bindValue(":offre", offre);
    query.bindValue(":montant", montant);
    qDebug() << "Erreur SQL lors de l'ajout:" << query.lastError().text();

    return query.exec();
}

QSqlQueryModel* Paiement::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID, TYPE_PAIEMENT, TO_CHAR(DATE_DE_PAIEMENT, 'DD-MM-YYYY') AS DATE, HEURE, LIEU, OFFRE, MONTANT FROM PAIEMENT");
    return model;
}

bool Paiement::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM PAIEMENT WHERE ID = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool Paiement::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE PAIEMENT SET TYPE_PAIEMENT=:type, DATE_DE_PAIEMENT=TO_DATE(:date,'DD-MM-YYYY'), "
                  "HEURE=:heure, LIEU=:lieu, OFFRE=:offre, MONTANT=:montant WHERE ID=:id");

    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":date", date);
    query.bindValue(":heure", heure);
    query.bindValue(":lieu", lieu);
    query.bindValue(":offre", offre);
    query.bindValue(":montant", montant);

    return query.exec();
}
