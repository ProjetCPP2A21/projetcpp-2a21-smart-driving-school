#include "vehicules.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Vehicules::Vehicules()
{
    marque = "";
    immatriculation = "";
    type = "";
    kilometrage = 0;
    etat = "";
    disponibilite = "";
    capacite = 0;
}

Vehicules::Vehicules(QString m, QString i, QString t, double k, QString e, QString d, int c)
{
    marque = m;
    immatriculation = i;
    type = t;
    kilometrage = k;
    etat = e;
    disponibilite = d;
    capacite = c;
}

// Getters
QString Vehicules::getMarque() { return marque; }
QString Vehicules::getImmatriculation() { return immatriculation; }
QString Vehicules::getType() { return type; }
double Vehicules::getKilometrage() { return kilometrage; }
QString Vehicules::getEtat() { return etat; }
QString Vehicules::getDisponibilite() { return disponibilite; }
int Vehicules::getCapacite() { return capacite; }

// Setters
void Vehicules::setMarque(QString m) { marque = m; }
void Vehicules::setImmatriculation(QString i) { immatriculation = i; }
void Vehicules::setType(QString t) { type = t; }
void Vehicules::setKilometrage(double k) { kilometrage = k; }
void Vehicules::setEtat(QString e) { etat = e; }
void Vehicules::setDisponibilite(QString d) { disponibilite = d; }
void Vehicules::setCapacite(int c) { capacite = c; }

// Ajouter un véhicule
bool Vehicules::ajouter()
{
    QSqlQuery query;
    
    // ESSAYER D'ABORD AVEC LA SÉQUENCE
    query.prepare("INSERT INTO VEHICULES (ID_VEHICULE, MARQUE, IMMATRICULATION, TYPE_VEHICULE, KILOMETRAGE, ETAT, DISPONIBILITE, CAPACITE) "
                  "VALUES (SEQ_VEHICULES.NEXTVAL, :marque, :immatriculation, :type, :kilometrage, :etat, :disponibilite, :capacite)");
    query.bindValue(":marque", marque);
    query.bindValue(":immatriculation", immatriculation);
    query.bindValue(":type", type);
    query.bindValue(":kilometrage", kilometrage);
    query.bindValue(":etat", etat);
    query.bindValue(":disponibilite", disponibilite);
    query.bindValue(":capacite", capacite);

    if (query.exec()) {
        return true;
    } else {
        QString error = query.lastError().text();
        qDebug() << "Erreur ajout avec séquence:" << error;
        
        // SI LA SÉQUENCE N'EXISTE PAS, ESSAYER SANS L'ID (le trigger s'en occupera)
        if (error.contains("sequence does not exist") || error.contains("ORA-02289")) {
            query.prepare("INSERT INTO VEHICULES (MARQUE, IMMATRICULATION, TYPE_VEHICULE, KILOMETRAGE, ETAT, DISPONIBILITE, CAPACITE) "
                          "VALUES (:marque, :immatriculation, :type, :kilometrage, :etat, :disponibilite, :capacite)");
            query.bindValue(":marque", marque);
            query.bindValue(":immatriculation", immatriculation);
            query.bindValue(":type", type);
            query.bindValue(":kilometrage", kilometrage);
            query.bindValue(":etat", etat);
            query.bindValue(":disponibilite", disponibilite);
            query.bindValue(":capacite", capacite);
            
            if (query.exec()) {
                return true;
            } else {
                qDebug() << "Erreur ajout sans séquence:" << query.lastError().text();
                return false;
            }
        }
        return false;
    }
}

// Modifier un véhicule
bool Vehicules::modifier(QString immatriculation)
{
    QSqlQuery query;
    // CORRECTION : La colonne s'appelle TYPE_VEHICULE dans la base de données
    query.prepare("UPDATE VEHICULES SET MARQUE=:marque, TYPE_VEHICULE=:type, KILOMETRAGE=:kilometrage, "
                  "ETAT=:etat, DISPONIBILITE=:disponibilite, CAPACITE=:capacite "
                  "WHERE IMMATRICULATION=:immatriculation");
    query.bindValue(":marque", marque);
    query.bindValue(":type", type);
    query.bindValue(":kilometrage", kilometrage);
    query.bindValue(":etat", etat);
    query.bindValue(":disponibilite", disponibilite);
    query.bindValue(":capacite", capacite);
    query.bindValue(":immatriculation", immatriculation);

    return query.exec();
}

// Supprimer un véhicule
bool Vehicules::supprimer(QString immatriculation)
{
    QSqlQuery query;
    query.prepare("DELETE FROM VEHICULES WHERE IMMATRICULATION=:immatriculation");
    query.bindValue(":immatriculation", immatriculation);

    return query.exec();
}

// Rechercher un véhicule
bool Vehicules::rechercher(QString marque)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM VEHICULES WHERE MARQUE LIKE :marque");
    query.bindValue(":marque", "%" + marque + "%");

    return query.exec();
}

