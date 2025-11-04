#include "vehicule.h"
<<<<<<< HEAD
#include "ui_vehicule.h"

vehicule::vehicule(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::vehicule)
{
    ui->setupUi(this);
}

vehicule::~vehicule()
{
    delete ui;
=======
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>

// ----------------- Constructors -----------------
Vehicule::Vehicule() {
    marque = type = etat = immatriculation = dispo = "";
    kilometrage = capacite = 0;
}

Vehicule::Vehicule(QString marque, QString type, int kilometrage, QString etat, QString immatriculation, QString dispo, int capacite) {
    this->marque = marque;
    this->type = type;
    this->kilometrage = kilometrage;
    this->etat = etat;
    this->immatriculation = immatriculation;
    this->dispo = dispo;
    this->capacite = capacite;
}

// ----------------- Getters -----------------
QString Vehicule::getMarque() const { return marque; }
QString Vehicule::getType() const { return type; }
int Vehicule::getKilometrage() const { return kilometrage; }
QString Vehicule::getEtat() const { return etat; }
QString Vehicule::getImmatriculation() const { return immatriculation; }
QString Vehicule::getDispo() const { return dispo; }
int Vehicule::getCapacite() const { return capacite; }

// ----------------- Setters -----------------
void Vehicule::setMarque(QString m) { marque = m; }
void Vehicule::setType(QString t) { type = t; }
void Vehicule::setKilometrage(int km) { kilometrage = km; }
void Vehicule::setEtat(QString e) { etat = e; }
void Vehicule::setImmatriculation(QString i) { immatriculation = i; }
void Vehicule::setDispo(QString d) { dispo = d; }
void Vehicule::setCapacite(int c) { capacite = c; }

// ----------------- CRUD -----------------
bool Vehicule::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO VEHICULES (MARQUE, TYPE, KILOMETRAGE, ETAT, IMMATRICULATION, DISPO, CAPACITE) "
                  "VALUES (:marque, :type, :km, :etat, :imm, :dispo, :cap)");
    query.bindValue(":marque", marque);
    query.bindValue(":type", type);
    query.bindValue(":km", kilometrage);
    query.bindValue(":etat", etat);
    query.bindValue(":imm", immatriculation);
    query.bindValue(":dispo", dispo);
    query.bindValue(":cap", capacite);
    return query.exec();
}

bool Vehicule::supprimer(QString imm) {
    QSqlQuery query;
    query.prepare("DELETE FROM VEHICULES WHERE IMMATRICULATION = :imm");
    query.bindValue(":imm", imm);
    return query.exec();
}

bool Vehicule::modifier(QString imm) {
    QSqlQuery query;
    query.prepare("UPDATE VEHICULES SET MARQUE=:marque, TYPE=:type, KILOMETRAGE=:km, ETAT=:etat, DISPO=:dispo, CAPACITE=:cap "
                  "WHERE IMMATRICULATION=:imm");
    query.bindValue(":marque", marque);
    query.bindValue(":type", type);
    query.bindValue(":km", kilometrage);
    query.bindValue(":etat", etat);
    query.bindValue(":dispo", dispo);
    query.bindValue(":cap", capacite);
    query.bindValue(":imm", imm);
    return query.exec();
}

QSqlQueryModel* Vehicule::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT MARQUE, TYPE, KILOMETRAGE, ETAT, IMMATRICULATION, DISPO, CAPACITE FROM VEHICULES");
    return model;
}

QSqlQueryModel* Vehicule::rechercherParMarque(QString m) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT MARQUE, TYPE, KILOMETRAGE, ETAT, IMMATRICULATION, DISPO, CAPACITE FROM VEHICULES WHERE MARQUE LIKE :marque");
    query.bindValue(":marque", "%" + m + "%");
    query.exec();
    model->setQuery(query);
    return model;
>>>>>>> ae4c4d6 (hello)
}
