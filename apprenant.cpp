#include "apprenant.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QDate>

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
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Erreur: Base de données non ouverte";
        return false;
    }
    
    // Vérification de l'existence de la table
    if (!db.tables().contains("APPRENANTS")) {
        qDebug() << "Erreur: La table APPRENANTS n'existe pas";
        return false;
    }
    
    qDebug() << "Tentative d'ajout d'un apprenant avec les données:";
    qDebug() << "ID:" << id;
    qDebug() << "Nom:" << nom;
    qDebug() << "Prénom:" << prenom;
    qDebug() << "Date de naissance:" << dateNaissance;
    qDebug() << "Téléphone:" << telephone;
    qDebug() << "Sexe:" << sexe;
    qDebug() << "Adresse:" << adresse;
    
    QSqlQuery query;
    bool prepareOk = query.prepare("INSERT INTO APPRENANTS (ID_APPRENANT, NOM, PRENOM, DATE_NAISSANCE, TELEPHONE, SEXE, ADRESSE) "
                                "VALUES (:id, :nom, :prenom, TO_DATE(:dateNaissance,'DD/MM/YYYY'), :telephone, :sexe, :adresse)");
    
    if (!prepareOk) {
        qDebug() << "Erreur de préparation de la requête:" << query.lastError().text();
        return false;
    }
    
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    
    // Conversion de la date
    QDate date = QDate::fromString(dateNaissance, "dd/MM/yyyy");
    query.bindValue(":dateNaissance", date.toString("dd/MM/yyyy"));
    
    // Conversion du téléphone en nombre
    bool ok;
    int tel = telephone.toInt(&ok);
    if (!ok) {
        qDebug() << "Erreur: Le numéro de téléphone doit être numérique";
        return false;
    }
    query.bindValue(":telephone", tel);
    
    query.bindValue(":sexe", sexe);
    query.bindValue(":adresse", adresse);

    if(!query.exec()){
        qDebug() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
        qDebug() << "Requête:" << query.lastQuery();
        qDebug() << "Valeurs liées:";
        qDebug() << "ID:" << id;
        qDebug() << "Nom:" << nom;
        qDebug() << "Prénom:" << prenom;
        qDebug() << "Date de naissance:" << dateNaissance;
        qDebug() << "Téléphone:" << telephone;
        qDebug() << "Sexe:" << sexe;
        qDebug() << "Adresse:" << adresse;
        return false;
    }
    
    qDebug() << "Apprenant ajouté avec succès";
    return true;
}

/**
 * @brief Modifie les informations d'un apprenant dans la base de données
 * @return true si la modification a réussi, false sinon
 */
bool Apprenant::modifier()
{
    // Vérification de la validité de l'ID
    if (id <= 0) {
        qWarning() << "Tentative de modification avec un ID invalide:" << id;
        return false;
    }

    // Vérification des champs obligatoires
    if (nom.trimmed().isEmpty() || prenom.trimmed().isEmpty()) {
        qWarning() << "Erreur: Le nom et le prénom sont obligatoires";
        return false;
    }

    // Vérification de la connexion à la base de données
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qCritical() << "Erreur: Base de données non connectée";
        return false;
    }

    // Début de la transaction
    db.transaction();

    try {
        // 1. Vérifier que l'apprenant existe avant de le modifier
        if (!existe(id)) {
            qWarning() << "Erreur: Aucun apprenant trouvé avec l'ID" << id;
            db.rollback();
            return false;
        }

        // 2. Préparation de la requête de mise à jour
        QSqlQuery query;
        bool prepareOk = query.prepare(
            "UPDATE APPRENANTS SET "
            "NOM = :nom, "
            "PRENOM = :prenom, "
            "DATE_NAISSANCE = TO_DATE(:dateNaissance, 'DD/MM/YYYY'), "
            "TELEPHONE = :telephone, "
            "SEXE = :sexe, "
            "ADRESSE = :adresse "
            "WHERE ID_APPRENANT = :id"
        );
        
        if (!prepareOk) {
            qCritical() << "Erreur de préparation de la requête:" << query.lastError().text();
            db.rollback();
            return false;
        }
        
        // 3. Validation et conversion des données
        
        // Validation du téléphone
        bool telOk;
        int tel = telephone.toInt(&telOk);
        if (!telOk || tel < 10000000 || tel > 99999999) {
            qWarning() << "Erreur: Numéro de téléphone invalide (doit être un nombre de 8 chiffres)";
            db.rollback();
            return false;
        }

        // Validation de la date
        QDate date = QDate::fromString(dateNaissance, "dd/MM/yyyy");
        if (!date.isValid()) {
            qWarning() << "Erreur: Date de naissance invalide";
            db.rollback();
            return false;
        }

        // Validation du sexe (doit être 'Homme' ou 'Femme')
        QString sexeUpper = sexe.toUpper();
        if (sexeUpper != "HOMME" && sexeUpper != "FEMME") {
            qWarning() << "Erreur: Le sexe doit être 'Homme' ou 'Femme'";
            db.rollback();
            return false;
        }

        // 4. Liaison des valeurs
        query.bindValue(":id", id);
        query.bindValue(":nom", nom.trimmed());
        query.bindValue(":prenom", prenom.trimmed());
        query.bindValue(":dateNaissance", date.toString("dd/MM/yyyy"));
        query.bindValue(":telephone", tel);
        query.bindValue(":sexe", sexe);
        query.bindValue(":adresse", adresse.trimmed());

        // 5. Exécution de la requête
        if (!query.exec()) {
            qCritical() << "Erreur lors de la modification de l'apprenant:" << query.lastError().text();
            qDebug() << "Détails de la requête:" << query.lastQuery();
            qDebug() << "Valeurs:" << id << nom << prenom << dateNaissance << tel << sexe << adresse;
            db.rollback();
            return false;
        }

        // 6. Vérification qu'une ligne a bien été mise à jour
        if (query.numRowsAffected() <= 0) {
            qWarning() << "Aucune ligne modifiée. L'ID spécifié n'existe peut-être pas:" << id;
            db.rollback();
            return false;
        }

        // 7. Validation de la transaction
        if (!db.commit()) {
            qCritical() << "Erreur lors de la validation de la transaction:" << db.lastError().text();
            db.rollback();
            return false;
        }

        qInfo() << "Apprenant modifié avec succès - ID:" << id;
        return true;

    } catch (const std::exception &e) {
        db.rollback();
        qCritical() << "Exception lors de la modification de l'apprenant:" << e.what();
        return false;
    } catch (...) {
        db.rollback();
        qCritical() << "Erreur inconnue lors de la modification de l'apprenant";
        return false;
    }
}

bool Apprenant::modifierAvecID(int nouvelId)
{
    // Vérification de la validité du nouvel ID
    if (nouvelId <= 0) {
        qDebug() << "Erreur: Le nouvel ID doit être un nombre positif";
        return false;
    }

    // Vérification de la connexion à la base de données
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Erreur: Base de données non connectée";
        return false;
    }

    // Vérification que le nouvel ID n'existe pas déjà
    if (existe(nouvelId) && nouvelId != id) {
        qDebug() << "Erreur: Un apprenant avec l'ID" << nouvelId << "existe déjà";
        return false;
    }

    // Début de la transaction
    db.transaction();
    
    try {
        // 1. Mise à jour de l'ID de l'apprenant
        QSqlQuery query;
        query.prepare("UPDATE APPRENANTS SET "
                     "ID_APPRENANT = :nouvelId, "
                     "NOM = :nom, "
                     "PRENOM = :prenom, "
                     "DATE_NAISSANCE = TO_DATE(:dateNaissance, 'DD/MM/YYYY'), "
                     "TELEPHONE = :telephone, "
                     "SEXE = :sexe, "
                     "ADRESSE = :adresse "
                     "WHERE ID_APPRENANT = :id");

        // Conversion et validation du numéro de téléphone
        bool telOk;
        int tel = telephone.toInt(&telOk);
        if (!telOk || tel < 10000000 || tel > 99999999) {
            qDebug() << "Erreur: Numéro de téléphone invalide";
            db.rollback();
            return false;
        }

        // Conversion de la date
        QDate date = QDate::fromString(dateNaissance, "dd/MM/yyyy");
        if (!date.isValid()) {
            qDebug() << "Erreur: Date de naissance invalide";
            db.rollback();
            return false;
        }

        // Liaison des valeurs
        query.bindValue(":id", id);
        query.bindValue(":nouvelId", nouvelId);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":dateNaissance", date.toString("dd/MM/yyyy"));
        query.bindValue(":telephone", tel);
        query.bindValue(":sexe", sexe);
        query.bindValue(":adresse", adresse);

        if (!query.exec()) {
            qCritical() << "Erreur lors de la modification de l'apprenant:" << query.lastError().text();
            db.rollback();
            return false;
        }

        // Vérification qu'une ligne a bien été mise à jour
        if (query.numRowsAffected() <= 0) {
            qDebug() << "Aucune ligne modifiée. L'ID spécifié n'existe peut-être pas:" << id;
            db.rollback();
            return false;
        }

        // Validation de la transaction
        if (!db.commit()) {
            qCritical() << "Erreur lors de la validation de la transaction:" << db.lastError().text();
            db.rollback();
            return false;
        }

        // Mise à jour de l'ID de l'objet courant
        id = nouvelId;
        
        qDebug() << "Apprenant modifié avec succès - Ancien ID:" << id << "Nouvel ID:" << nouvelId;
        return true;
        
    } catch (...) {
        // En cas d'erreur inattendue, on annule la transaction
        db.rollback();
        qCritical() << "Erreur inattendue lors de la modification de l'apprenant";
        return false;
    }
}

bool Apprenant::supprimer(int id)
{
    // Vérification de la validité de l'ID
    if (id <= 0) {
        qDebug() << "Erreur: ID invalide pour la suppression";
        return false;
    }

    // Vérification de la connexion à la base de données
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Erreur: Base de données non connectée";
        return false;
    }

    // Vérification que l'apprenant existe avant suppression
    if (!existe(id)) {
        qDebug() << "Erreur: Aucun apprenant trouvé avec l'ID" << id;
        return false;
    }

    // Préparation de la requête de suppression
    QSqlQuery query;
    bool prepareOk = query.prepare("DELETE FROM APPRENANTS WHERE ID_APPRENANT = :id");
    
    if (!prepareOk) {
        qCritical() << "Erreur de préparation de la requête de suppression:" << query.lastError().text();
        return false;
    }
    
    // Liaison de la valeur
    query.bindValue(":id", id);

    // Exécution de la requête
    if (!query.exec()) {
        qCritical() << "Erreur lors de la suppression de l'apprenant:" << query.lastError().text();
        qDebug() << "Détails de la requête:" << query.lastQuery();
        qDebug() << "ID à supprimer:" << id;
        return false;
    }

    // Vérification qu'une ligne a bien été supprimée
    if (query.numRowsAffected() <= 0) {
        qDebug() << "Aucune ligne supprimée. L'ID spécifié n'existe peut-être pas:" << id;
        return false;
    }

    qDebug() << "Apprenant supprimé avec succès - ID:" << id;
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
