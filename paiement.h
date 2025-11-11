#ifndef PAIEMENT_H
#define PAIEMENT_H

#include <QString>
#include <QSqlQueryModel>

class Paiement
{
private:
    int id;
    QString type;
    QString date;
    QString heure;
    double montant;
    int id_apprenant;

public:
    Paiement();
    Paiement(int id, QString type, QString date, QString heure,
             double montant, int id_apprenant = 0);

    // Getters
    int getId() const;
    QString getType() const;
    QString getDate() const;
    QString getHeure() const;
    double getMontant() const;
    int getIdApprenant() const;

    // CRUD
    bool ajouter();
    bool modifier();
    static bool supprimer(int id);  // Méthode statique
    QSqlQueryModel* afficher() const;
};

#endif // PAIEMENT_H

