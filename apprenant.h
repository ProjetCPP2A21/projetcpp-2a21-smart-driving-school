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
    QSqlQueryModel* rechercher(int id);
    QSqlQueryModel* rechercherParPrefixe(const QString &prefix);
    QSqlQueryModel* trierParPrenomCroissant();
    QSqlQueryModel* trierParPrenomDecroissant();

    QMap<QString,int> statistiquesSexe();
    bool existe(int id);
};

#endif // APPRENANT_H
