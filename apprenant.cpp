#include "apprenant.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

Apprenant::Apprenant() {}

Apprenant::Apprenant(int id, QString nom, QString prenom, QString dateNaissance,
                     QString telephone, QString sexe, QString adresse)
{
    this->id = id;
    this->nom = nom;
    this->prenom = prenom;
    this->dateNaissance = dateNaissance;
    this->telephone = telephone;
    this->sexe = sexe;
    this->adresse = adresse;
}

bool Apprenant::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO APPRENANTS (ID_APPRENANT, NOM, PRENOM, DATE_NAISSANCE, TELEPHONE, SEXE, ADRESSE) "
                  "VALUES (:id, :nom, :prenom, TO_DATE(:dateNaissance,'DD/MM/YYYY'), :telephone, :sexe, :adresse)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":dateNaissance", dateNaissance);
    query.bindValue(":telephone", telephone);
    query.bindValue(":sexe", sexe);
    query.bindValue(":adresse", adresse);

    if(!query.exec()){
        qDebug() << "Erreur ajout:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Apprenant::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE APPRENANTS SET NOM=:nom, PRENOM=:prenom, DATE_NAISSANCE=TO_DATE(:dateNaissance,'DD/MM/YYYY'), "
                  "TELEPHONE=:telephone, SEXE=:sexe, ADRESSE=:adresse WHERE ID_APPRENANT=:id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":dateNaissance", dateNaissance);
    query.bindValue(":telephone", telephone);
    query.bindValue(":sexe", sexe);
    query.bindValue(":adresse", adresse);

    if(!query.exec()){
        qDebug() << "Erreur modification:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Apprenant::modifierAvecID(int nouvelId)
{
    QSqlQuery query;
    query.prepare("UPDATE APPRENANTS SET ID_APPRENANT=:nouvelId, NOM=:nom, PRENOM=:prenom, DATE_NAISSANCE=TO_DATE(:dateNaissance,'DD/MM/YYYY'), "
                  "TELEPHONE=:telephone, SEXE=:sexe, ADRESSE=:adresse WHERE ID_APPRENANT=:id");
    query.bindValue(":id", id);
    query.bindValue(":nouvelId", nouvelId);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":dateNaissance", dateNaissance);
    query.bindValue(":telephone", telephone);
    query.bindValue(":sexe", sexe);
    query.bindValue(":adresse", adresse);

    if(!query.exec()){
        qDebug() << "Erreur modification avec nouvel ID:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Apprenant::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM APPRENANTS WHERE ID_APPRENANT=:id");
    query.bindValue(":id", id);

    if(!query.exec()){
        qDebug() << "Erreur suppression:" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel* Apprenant::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_APPRENANT, NOM, PRENOM, TO_CHAR(DATE_NAISSANCE,'DD/MM/YYYY') AS DATE_NAISSANCE, TELEPHONE, SEXE, ADRESSE FROM APPRENANTS");

    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nom");
    model->setHeaderData(2, Qt::Horizontal, "Prénom");
    model->setHeaderData(3, Qt::Horizontal, "Date Naissance");
    model->setHeaderData(4, Qt::Horizontal, "Téléphone");
    model->setHeaderData(5, Qt::Horizontal, "Sexe");
    model->setHeaderData(6, Qt::Horizontal, "Adresse");

    return model;
}
QSqlQueryModel* Apprenant::rechercher(int id)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_APPRENANT, NOM, PRENOM, TO_CHAR(DATE_NAISSANCE,'DD/MM/YYYY') AS DATE_NAISSANCE, TELEPHONE, SEXE, ADRESSE "
                  "FROM APPRENANTS WHERE ID_APPRENANT=:id");
    query.bindValue(":id", id);
    query.exec();

    // passer par move pour éviter le warning Qt6
    model->setQuery(std::move(query));

    return model;
}

QSqlQueryModel* Apprenant::rechercherParPrefixe(const QString &prefix)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_APPRENANT, NOM, PRENOM, TO_CHAR(DATE_NAISSANCE,'DD/MM/YYYY') AS DATE_NAISSANCE, TELEPHONE, SEXE, ADRESSE "
                  "FROM APPRENANTS WHERE TO_CHAR(ID_APPRENANT) LIKE :pattern");
    query.bindValue(":pattern", prefix + "%");
    query.exec();

    model->setQuery(std::move(query));
    return model;
}

QSqlQueryModel* Apprenant::trierParPrenomCroissant()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_APPRENANT, NOM, PRENOM, TO_CHAR(DATE_NAISSANCE,'DD/MM/YYYY') AS DATE_NAISSANCE, TELEPHONE, SEXE, ADRESSE "
                    "FROM APPRENANTS ORDER BY PRENOM ASC");
    return model;
}

QSqlQueryModel* Apprenant::trierParPrenomDecroissant()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_APPRENANT, NOM, PRENOM, TO_CHAR(DATE_NAISSANCE,'DD/MM/YYYY') AS DATE_NAISSANCE, TELEPHONE, SEXE, ADRESSE "
                    "FROM APPRENANTS ORDER BY PRENOM DESC");
    return model;
}

QMap<QString,int> Apprenant::statistiquesSexe()
{
    QMap<QString,int> stats;
    QSqlQuery query;
    query.prepare("SELECT SEXE, COUNT(*) FROM APPRENANTS GROUP BY SEXE");
    if(query.exec()){
        while(query.next()){
            stats[query.value(0).toString()] = query.value(1).toInt();
        }
    }
    return stats;
}

bool Apprenant::existe(int id)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(1) FROM APPRENANTS WHERE ID_APPRENANT=:id");
    query.bindValue(":id", id);

    if(!query.exec()){
        qDebug() << "Erreur vérification existence:" << query.lastError().text();
        return false;
    }

    if(query.next())
        return query.value(0).toInt() > 0;

    return false;
}