#ifndef APPRENANT_H
#define APPRENANT_H

#include <QString>
#include <QSqlQueryModel>
#include <QMap>

class Apprenant
{
private:
    int id;
    QString nom, prenom, dateNaissance, telephone, sexe, adresse;

public:
    Apprenant();
    Apprenant(int id, QString nom, QString prenom, QString dateNaissance,
              QString telephone, QString sexe, QString adresse);

    bool ajouter();
    bool modifier();
    bool modifierAvecID(int nouvelId);
    bool supprimer(int id);

    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercher(const QString &prefixeId);
    QSqlQueryModel* trierParPrenomCroissant();
    QSqlQueryModel* trierParPrenomDecroissant();

    QMap<QString,int> statistiquesSexe();
};

#endif // APPRENANT_H


