#ifndef PAIEMENT_H
#define PAIEMENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Paiement
{
public:
    Paiement();
    Paiement(int, QString, QString, QString, QString, QString, double);

    int getId();
    QString getType();
    QString getDate();
    QString getHeure();
    QString getLieu();
    QString getOffre();
    double getMontant();

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();

private:
    int id;
    QString type, date, heure, lieu, offre;
    double montant;
};

#endif // PAIEMENT_H
