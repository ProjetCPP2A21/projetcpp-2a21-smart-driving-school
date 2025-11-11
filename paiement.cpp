#include "paiement.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlDatabase>
#include <QVariant>

Paiement::Paiement() : id(0), montant(0), id_apprenant(0) {}

Paiement::Paiement(int id, QString type, QString date, QString heure,
                   double montant, int id_apprenant)
    : id(id), type(type), date(date), heure(heure),
    montant(montant), id_apprenant(id_apprenant) {}

// Getters
int Paiement::getId() const { return id; }
QString Paiement::getType() const { return type; }
QString Paiement::getDate() const { return date; }
QString Paiement::getHeure() const { return heure; }
double Paiement::getMontant() const { return montant; }
int Paiement::getIdApprenant() const { return id_apprenant; }

// Ajouter
bool Paiement::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO PAIEMENTS (ID_PAIEMENT, TYPE_PAIEMENT, DATE_PAIEMENT, HEURE_PAIEMENT, "
                  "MONTANT, ID_APPRENANT) "
                  "VALUES (:id, :type, TO_DATE(:date,'DD-MM-YYYY'), :heure, :montant, :id_apprenant)");

    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":date", date);
    query.bindValue(":heure", heure);
    query.bindValue(":montant", montant);
    if (id_apprenant > 0) {
        query.bindValue(":id_apprenant", id_apprenant);
    } else {
        query.bindValue(":id_apprenant", QVariant()); // NULL
    }

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de l'ajout:" << query.lastError().text();
        return false;
    }
    return true;
}

// Modifier
bool Paiement::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE PAIEMENTS SET TYPE_PAIEMENT=:type, DATE_PAIEMENT=TO_DATE(:date,'DD-MM-YYYY'), "
                  "HEURE_PAIEMENT=:heure, MONTANT=:montant, ID_APPRENANT=:id_apprenant "
                  "WHERE ID_PAIEMENT=:id");

    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":date", date);
    query.bindValue(":heure", heure);
    query.bindValue(":montant", montant);
    if (id_apprenant > 0) {
        query.bindValue(":id_apprenant", id_apprenant);
    } else {
        query.bindValue(":id_apprenant", QVariant()); // NULL
    }

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la modification:" << query.lastError().text();
        return false;
    }
    return true;
}

// Supprimer (statique)
bool Paiement::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM PAIEMENTS WHERE ID_PAIEMENT=:id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la suppression:" << query.lastError().text();
        return false;
    }
    return true;
}

// Afficher
QSqlQueryModel* Paiement::afficher() const
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_PAIEMENT, TYPE_PAIEMENT, "
                  "TO_CHAR(DATE_PAIEMENT,'DD-MM-YYYY') AS DATE_PAIEMENT, "
                  "HEURE_PAIEMENT, MONTANT, ID_APPRENANT "
                  "FROM PAIEMENTS");
    query.exec();
    
    model->setQuery(std::move(query));

    model->setHeaderData(0, Qt::Horizontal, "ID Paiement");
    model->setHeaderData(1, Qt::Horizontal, "Type");
    model->setHeaderData(2, Qt::Horizontal, "Date");
    model->setHeaderData(3, Qt::Horizontal, "Heure");
    model->setHeaderData(4, Qt::Horizontal, "Montant");
    model->setHeaderData(5, Qt::Horizontal, "ID Apprenant");

    return model;
}

