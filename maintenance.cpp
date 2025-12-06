#include "maintenance.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QMessageBox>
#include <QSettings>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimer>
#include <QProcess>
#include <QRandomGenerator>
#include <QUrlQuery>
#include <QEventLoop>

Maintenance::Maintenance(QObject *parent) : QObject(parent)
{
    // NE PAS initialiser automatiquement une connexion
    // La connexion sera définie explicitement via setDatabaseConnection
    qDebug() << "Maintenance créée sans connexion automatique";
}

void Maintenance::setDatabaseConnection(const QSqlDatabase &db)
{
    // Utiliser la connexion passée en paramètre
    if (db.isValid()) {
        m_db = db;
        qDebug() << "Maintenance utilise maintenant la connexion:" << db.connectionName()
                 << "(ouverte:" << db.isOpen() << ")";
    } else {
        qWarning() << "Connexion invalide passée à Maintenance";
    }
}

Maintenance::~Maintenance()
{
    qDebug() << "Destruction de l'instance Maintenance";

    // NE PAS fermer la connexion si elle est partagée avec d'autres classes
    // La connexion principale doit rester ouverte
    // if (m_db.isOpen()) {
    //     m_db.close();
    // }
}

bool Maintenance::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO MAINTENANCES (vehicule_id, type, date_debut, date_fin, statut, description) "
                  "VALUES (:vehicule_id, :type, :date_debut, :date_fin, :statut, :description)");

    query.bindValue(":vehicule_id", vehiculeId);
    query.bindValue(":type", type);
    query.bindValue(":date_debut", dateDebut);
    query.bindValue(":date_fin", dateFin);
    query.bindValue(":statut", statut);
    query.bindValue(":description", description);

    if (!query.exec()) {
        qWarning() << "Erreur lors de l'ajout de la maintenance:" << query.lastError().text();
        return false;
    }

    id = query.lastInsertId().toInt();
    return true;
}

bool Maintenance::modifier()
{
    if (id == -1) return false;

    QSqlQuery query;
    query.prepare("UPDATE MAINTENANCES SET "
                  "vehicule_id = :vehicule_id, "
                  "type = :type, "
                  "date_debut = :date_debut, "
                  "date_fin = :date_fin, "
                  "statut = :statut, "
                  "description = :description "
                  "WHERE id = :id");

    query.bindValue(":vehicule_id", vehiculeId);
    query.bindValue(":type", type);
    query.bindValue(":date_debut", dateDebut);
    query.bindValue(":date_fin", dateFin);
    query.bindValue(":statut", statut);
    query.bindValue(":description", description);
    query.bindValue(":id", id);

    if (!query.exec()) {
        qWarning() << "Erreur lors de la modification de la maintenance:" << query.lastError().text();
        return false;
    }

    return true;
}

bool Maintenance::supprimer()
{
    if (id == -1) return false;

    QSqlQuery query;
    query.prepare("DELETE FROM MAINTENANCES WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qWarning() << "Erreur lors de la suppression de la maintenance:" << query.lastError().text();
        return false;
    }

    return true;
}

bool Maintenance::planifierMaintenance(int vehiculeId, int typeMaintenanceId, const QDateTime &dateSouhaitee)
{
    if (!m_db.isOpen()) {
        qWarning() << "Base de données non ouverte";
        return false;
    }

    // Vérifier si le véhicule existe
    QSqlQuery checkVehicule;
    checkVehicule.prepare("SELECT id FROM VEHICULES WHERE id = :id");
    checkVehicule.bindValue(":id", vehiculeId);

    if (!checkVehicule.exec() || !checkVehicule.next()) {
        qWarning() << "Véhicule non trouvé";
        return false;
    }

    // Récupérer les informations sur le type de maintenance
    QSqlQuery typeQuery;
    typeQuery.prepare("SELECT nom, duree_moyenne FROM TYPES_MAINTENANCE WHERE id = :id");
    typeQuery.bindValue(":id", typeMaintenanceId);

    if (!typeQuery.exec() || !typeQuery.next()) {
        qWarning() << "Type de maintenance non trouvé";
        return false;
    }

    QString typeMaintenance = typeQuery.value(0).toString();
    int dureeMinutes = typeQuery.value(1).toInt();

    // Vérifier la disponibilité du créneau
    QDateTime fin = dateSouhaitee.addSecs(dureeMinutes * 60);

    if (!verifierDisponibiliteCreneau(dateSouhaitee, fin, vehiculeId)) {
        qWarning() << "Créneau non disponible";
        return false;
    }

    // Créer la maintenance
    this->vehiculeId = vehiculeId;
    this->type = typeMaintenance;
    this->dateDebut = dateSouhaitee.date();
    this->dateFin = fin.date();
    this->statut = "Planifiée";
    this->description = QString("Maintenance de type %1 planifiée").arg(typeMaintenance);

    if (!ajouter()) {
        return false;
    }

    // Envoyer une notification
    QString message = QString("Nouvelle maintenance planifiée pour le véhicule %1: %2")
                          .arg(vehiculeId).arg(typeMaintenance);

    // Récupérer les destinataires des notifications
    QSettings settings;
    QStringList destinataires = settings.value("Notifications/Destinataires").toStringList();

    envoyerNotificationMaintenance(message, destinataires);

    return true;
}

void Maintenance::verifierMaintenancesRequises()
{
    if (!m_db.isOpen()) {
        qWarning() << "Base de données non ouverte";
        return;
    }

    // Récupérer tous les véhicules
    QSqlQuery vehiculesQuery("SELECT id, marque, modele, kilometrage FROM VEHICULES");

    while (vehiculesQuery.next()) {
        int vehiculeId = vehiculesQuery.value(0).toInt();
        QString marque = vehiculesQuery.value(1).toString();
        QString modele = vehiculesQuery.value(2).toString();
        int kilometrage = vehiculesQuery.value(3).toInt();

        // Vérifier les maintenances requises pour ce véhicule
        QSqlQuery maintenancesQuery;
        maintenancesQuery.prepare(
            "SELECT tm.id, tm.nom, tm.kilometrage_intervalle, tm.mois_intervalle, "
            "MAX(m.date_fin) as derniere_maintenance "
            "FROM TYPES_MAINTENANCE tm "
            "LEFT JOIN MAINTENANCES m ON m.vehicule_id = :vehicule_id AND m.type = tm.nom "
            "GROUP BY tm.id, tm.nom, tm.kilometrage_intervalle, tm.mois_intervalle");

        maintenancesQuery.bindValue(":vehicule_id", vehiculeId);

        if (!maintenancesQuery.exec()) {
            qWarning() << "Erreur lors de la vérification des maintenances requises:"
                       << maintenancesQuery.lastError().text();
            continue;
        }

        while (maintenancesQuery.next()) {
            int typeMaintenanceId = maintenancesQuery.value(0).toInt();
            QString typeMaintenance = maintenancesQuery.value(1).toString();
            int kilometrageIntervalle = maintenancesQuery.value(2).toInt();
            int moisIntervalle = maintenancesQuery.value(3).toInt();
            QDate derniereMaintenance = maintenancesQuery.value(4).toDate();

            bool maintenanceRequise = false;

            // Vérifier l'intervalle en kilomètres
            if (kilometrageIntervalle > 0) {
                // Récupérer le kilométrage de la dernière maintenance
                QSqlQuery kmQuery;
                kmQuery.prepare(
                    "SELECT kilometrage_effectue "
                    "FROM MAINTENANCES "
                    "WHERE vehicule_id = :vehicule_id AND type = :type "
                    "ORDER BY date_fin DESC LIMIT 1");

                kmQuery.bindValue(":vehicule_id", vehiculeId);
                kmQuery.bindValue(":type", typeMaintenance);

                int dernierKilometrage = 0;
                if (kmQuery.exec() && kmQuery.next()) {
                    dernierKilometrage = kmQuery.value(0).toInt();
                }

                if ((kilometrage - dernierKilometrage) >= kilometrageIntervalle) {
                    maintenanceRequise = true;
                }
            }

            // Vérifier l'intervalle en mois
            if (moisIntervalle > 0) {
                QDate prochaineEcheance = derniereMaintenance.isValid()
                ? derniereMaintenance.addMonths(moisIntervalle)
                : QDate::currentDate().addMonths(-moisIntervalle);

                if (QDate::currentDate() >= prochaineEcheance) {
                    maintenanceRequise = true;
                }
            }

            if (maintenanceRequise) {
                // Planifier automatiquement la maintenance
                QDateTime maintenant = QDateTime::currentDateTime();
                QDateTime debut = maintenant.addDays(2); // Planifier dans 2 jours par défaut

                // Planifier la maintenance
                planifierMaintenance(vehiculeId, typeMaintenanceId, debut);

                // Envoyer une notification
                QString message = QString("Maintenance requise pour le véhicule %1 %2 (ID: %3): %4")
                                      .arg(marque, modele).arg(vehiculeId).arg(typeMaintenance);

                QSettings settings;
                QStringList destinataires = settings.value("Notifications/Destinataires").toStringList();

                envoyerNotificationMaintenance(message, destinataires);
            }
        }
    }
}

QList<CreneauMaintenance> Maintenance::trouverCreneauxDisponibles(
    const QDate &dateDebut, const QDate &dateFin, int dureeMinutes) const
{
    QList<CreneauMaintenance> creneaux;

    if (!m_db.isOpen() || !dateDebut.isValid() || !dateFin.isValid() || dureeMinutes <= 0) {
        return creneaux;
    }

    // Heures d'ouverture de l'atelier (9h-12h et 14h-18h)
    QTime heureDebutMatin(9, 0);
    QTime heureFinMatin(12, 0);
    QTime heureDebutApresMidi(14, 0);
    QTime heureFinSoir(18, 0);

    // Parcourir chaque jour de la plage de dates
    for (QDate date = dateDebut; date <= dateFin; date = date.addDays(1)) {
        // Ignorer les week-ends
        if (date.dayOfWeek() == 6 || date.dayOfWeek() == 7) {
            continue;
        }

        // Créer des créneaux pour la matinée
        QDateTime debutCreneau(date, heureDebutMatin);
        QDateTime finCreneau = debutCreneau.addSecs(dureeMinutes * 60);

        while (finCreneau.time() <= heureFinMatin) {
            CreneauMaintenance creneau;
            creneau.debut = debutCreneau;
            creneau.fin = finCreneau;
            creneau.estDisponible = verifierDisponibiliteCreneau(debutCreneau, finCreneau, -1);

            creneaux.append(creneau);

            // Passer au créneau suivant (par pas de 30 minutes)
            debutCreneau = debutCreneau.addSecs(30 * 60);
            finCreneau = debutCreneau.addSecs(dureeMinutes * 60);
        }

        // Créer des créneaux pour l'après-midi
        debutCreneau = QDateTime(date, heureDebutApresMidi);
        finCreneau = debutCreneau.addSecs(dureeMinutes * 60);

        while (finCreneau.time() <= heureFinSoir) {
            CreneauMaintenance creneau;
            creneau.debut = debutCreneau;
            creneau.fin = finCreneau;
            creneau.estDisponible = verifierDisponibiliteCreneau(debutCreneau, finCreneau, -1);

            creneaux.append(creneau);

            // Passer au créneau suivant (par pas de 30 minutes)
            debutCreneau = debutCreneau.addSecs(30 * 60);
            finCreneau = debutCreneau.addSecs(dureeMinutes * 60);
        }
    }

    return creneaux;
}

bool Maintenance::verifierDisponibiliteCreneau(
    const QDateTime &debut, const QDateTime &fin, int vehiculeId) const
{
    if (!m_db.isOpen() || !debut.isValid() || !fin.isValid() || debut >= fin) {
        return false;
    }

    // Vérifier les chevauchements avec les maintenances existantes
    QSqlQuery query;
    query.prepare(
        "SELECT COUNT(*) FROM MAINTENANCES "
        "WHERE ((date_debut BETWEEN :debut AND :fin) OR (date_fin BETWEEN :debut AND :fin) "
        "OR (date_debut <= :debut AND date_fin >= :fin)) "
        "AND statut NOT IN ('Annulée', 'Terminée')");

    query.bindValue(":debut", debut);
    query.bindValue(":fin", fin);

    if (!query.exec() || !query.next()) {
        qWarning() << "Erreur lors de la vérification de la disponibilité:" << query.lastError().text();
        return false;
    }

    int chevauchements = query.value(0).toInt();

    // Si le véhicule est spécifié, vérifier s'il n'a pas déjà une maintenance prévue
    if (vehiculeId != -1) {
        query.prepare(
            "SELECT COUNT(*) FROM MAINTENANCES "
            "WHERE vehicule_id = :vehicule_id AND "
            "((date_debut BETWEEN :debut AND :fin) OR (date_fin BETWEEN :debut AND :fin) "
            "OR (date_debut <= :debut AND date_fin >= :fin)) "
            "AND statut NOT IN ('Annulée', 'Terminée')");

        query.bindValue(":vehicule_id", vehiculeId);
        query.bindValue(":debut", debut);
        query.bindValue(":fin", fin);

        if (!query.exec() || !query.next()) {
            qWarning() << "Erreur lors de la vérification de la disponibilité du véhicule:"
                       << query.lastError().text();
            return false;
        }

        chevauchements += query.value(0).toInt();
    }

    return (chevauchements == 0);
}

bool Maintenance::envoyerNotificationMaintenance(const QString &message, const QStringList &destinataires)
{
    if (destinataires.isEmpty()) {
        qWarning() << "Aucun destinataire spécifié pour la notification";
        return false;
    }
    QSettings settings;
    bool notifEmail = settings.value("Notifications/Email", true).toBool();
    bool notifSMS = settings.value("Notifications/SMS", true).toBool();
    if (notifSMS) {
        QString sid = settings.value("Twilio/AccountSid").toString();
        QString token = settings.value("Twilio/AuthToken").toString();
        QString from = settings.value("Twilio/FromNumber").toString();
        QString mss = settings.value("Twilio/MessagingServiceSid").toString();
        if (sid.trimmed().isEmpty()) sid = QString::fromUtf8(qgetenv("TWILIO_ACCOUNT_SID"));
        if (token.trimmed().isEmpty()) token = QString::fromUtf8(qgetenv("TWILIO_AUTH_TOKEN"));
        if (from.trimmed().isEmpty()) from = QString::fromUtf8(qgetenv("TWILIO_FROM_NUMBER"));
        if (mss.trimmed().isEmpty()) mss = QString::fromUtf8(qgetenv("TWILIO_MESSAGING_SERVICE_SID"));
        QStringList envDest;
        QByteArray envD = qgetenv("TWILIO_DESTINATAIRES");
        // Les identifiants Twilio doivent être définis dans les variables d'environnement
        // TWILIO_ACCOUNT_SID, TWILIO_AUTH_TOKEN, TWILIO_FROM_NUMBER
        if (!envD.isEmpty()) {
            envDest = QString::fromUtf8(envD).split(',', Qt::SkipEmptyParts);
        }
        QStringList targets; targets << "+21624740996";
        if (sid.isEmpty() || token.isEmpty() || (from.isEmpty() && mss.isEmpty()) || targets.isEmpty()) {
            qWarning() << "Configuration Twilio manquante";
            return false;
        }
        QNetworkAccessManager nam;
        bool anySuccess = false;
        for (const QString &to : targets) {
            QUrl url(QString("https://api.twilio.com/2010-04-01/Accounts/%1/Messages.json").arg(sid));
            QNetworkRequest req(url);
            QByteArray auth = (sid + ":" + token).toUtf8().toBase64();
            req.setRawHeader("Authorization", "Basic " + auth);
            req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
            QUrlQuery data;
            data.addQueryItem("To", to);
            if (!mss.isEmpty()) {
                data.addQueryItem("MessagingServiceSid", mss);
            } else {
                data.addQueryItem("From", from);
            }
            data.addQueryItem("Body", message);
            QEventLoop loop;
            QNetworkReply *reply = nam.post(req, data.query(QUrl::FullyEncoded).toUtf8());
            QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
            loop.exec();
            int status = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
            QByteArray payload = reply->readAll();
            if (reply->error() != QNetworkReply::NoError || (status < 200 || status >= 300)) {
                qWarning() << "Erreur SMS" << to << status << reply->errorString() << payload;
            } else {
                anySuccess = true;
                qDebug() << "SMS accepté" << to;
            }
            reply->deleteLater();
        }
        return anySuccess;
    }
    return false;
}

bool Maintenance::validerMaintenance(int maintenanceId, const QDateTime &dateReelle, int kilometrageReel)
{
    if (!m_db.isOpen() || maintenanceId <= 0 || !dateReelle.isValid()) {
        return false;
    }

    QSqlQuery query;
    query.prepare(
        "UPDATE MAINTENANCES "
        "SET date_reelle = :date_reelle, kilometrage_effectue = :kilometrage, "
        "statut = 'Terminée', date_mise_a_jour = CURRENT_TIMESTAMP "
        "WHERE id = :id");

    query.bindValue(":date_reelle", dateReelle);
    query.bindValue(":kilometrage", kilometrageReel);
    query.bindValue(":id", maintenanceId);

    if (!query.exec()) {
        qWarning() << "Erreur lors de la validation de la maintenance:" << query.lastError().text();
        return false;
    }

    // Mettre à jour le kilométrage du véhicule si nécessaire
    if (kilometrageReel > 0) {
        QSqlQuery updateKm;
        updateKm.prepare(
            "UPDATE VEHICULES v "
            "SET kilometrage = GREATEST(kilometrage, :kilometrage) "
            "FROM MAINTENANCES m "
            "WHERE m.id = :maintenance_id AND m.vehicule_id = v.id");

        updateKm.bindValue(":kilometrage", kilometrageReel);
        updateKm.bindValue(":maintenance_id", maintenanceId);

        if (!updateKm.exec()) {
            qWarning() << "Erreur lors de la mise à jour du kilométrage du véhicule:"
                       << updateKm.lastError().text();
        }
    }

    return true;
}

bool Maintenance::annulerMaintenance(int maintenanceId, const QString &raison)
{
    if (!m_db.isOpen() || maintenanceId <= 0 || raison.isEmpty()) {
        return false;
    }

    QSqlQuery query;
    query.prepare(
        "UPDATE MAINTENANCES "
        "SET statut = 'Annulée', commentaire_annulation = :raison, "
        "date_mise_a_jour = CURRENT_TIMESTAMP "
        "WHERE id = :id");

    query.bindValue(":raison", raison);
    query.bindValue(":id", maintenanceId);

    if (!query.exec()) {
        qWarning() << "Erreur lors de l'annulation de la maintenance:" << query.lastError().text();
        return false;
    }

    // Envoyer une notification d'annulation
    QString message = QString("La maintenance #%1 a été annulée. Raison: %2")
                          .arg(maintenanceId).arg(raison);

    QSettings settings;
    QStringList destinataires = settings.value("Notifications/Destinataires").toStringList();

    envoyerNotificationMaintenance(message, destinataires);

    return true;
}

QList<QMap<QString, QVariant>> Maintenance::obtenirMaintenancesAVenir(int vehiculeId) const
{
    QList<QMap<QString, QVariant>> resultats;

    if (!m_db.isOpen()) {
        return resultats;
    }

    QSqlQuery query;
    QString requete =
        "SELECT m.id, v.immatriculation, v.marque, v.modele, m.type, "
        "m.date_debut, m.date_fin, m.statut, m.description "
        "FROM MAINTENANCES m "
        "JOIN VEHICULES v ON m.vehicule_id = v.id "
        "WHERE m.date_fin >= CURRENT_DATE "
        "AND m.statut NOT IN ('Annulée', 'Terminée')";

    if (vehiculeId != -1) {
        requete += " AND m.vehicule_id = :vehicule_id";
    }

    requete += " ORDER BY m.date_debut ASC";

    query.prepare(requete);

    if (vehiculeId != -1) {
        query.bindValue(":vehicule_id", vehiculeId);
    }

    if (!query.exec()) {
        qWarning() << "Erreur lors de la récupération des maintenances à venir:"
                   << query.lastError().text();
        return resultats;
    }

    while (query.next()) {
        QMap<QString, QVariant> ligne;
        ligne["id"] = query.value(0);
        ligne["immatriculation"] = query.value(1);
        ligne["marque"] = query.value(2);
        ligne["modele"] = query.value(3);
        ligne["type"] = query.value(4);
        ligne["date_debut"] = query.value(5);
        ligne["date_fin"] = query.value(6);
        ligne["statut"] = query.value(7);
        ligne["description"] = query.value(8);

        resultats.append(ligne);
    }

    return resultats;
}

QList<QMap<QString, QVariant>> Maintenance::obtenirHistoriqueMaintenance(int vehiculeId) const
{
    QList<QMap<QString, QVariant>> resultats;

    if (!m_db.isOpen()) {
        return resultats;
    }

    QSqlQuery query;
    QString requete =
        "SELECT m.id, v.immatriculation, v.marque, v.modele, m.type, "
        "m.date_debut, m.date_fin, m.date_reelle, m.statut, "
        "m.kilometrage_effectue, m.description, m.commentaire_annulation "
        "FROM MAINTENANCES m "
        "JOIN VEHICULES v ON m.vehicule_id = v.id "
        "WHERE m.date_fin < CURRENT_DATE "
        "OR m.statut IN ('Annulée', 'Terminée')";

    if (vehiculeId != -1) {
        requete += " AND m.vehicule_id = :vehicule_id";
    }

    requete += " ORDER BY m.date_fin DESC";

    query.prepare(requete);

    if (vehiculeId != -1) {
        query.bindValue(":vehicule_id", vehiculeId);
    }

    if (!query.exec()) {
        qWarning() << "Erreur lors de la récupération de l'historique des maintenances:"
                   << query.lastError().text();
        return resultats;
    }

    while (query.next()) {
        QMap<QString, QVariant> ligne;
        ligne["id"] = query.value(0);
        ligne["immatriculation"] = query.value(1);
        ligne["marque"] = query.value(2);
        ligne["modele"] = query.value(3);
        ligne["type"] = query.value(4);
        ligne["date_debut"] = query.value(5);
        ligne["date_fin"] = query.value(6);
        ligne["date_reelle"] = query.value(7);
        ligne["statut"] = query.value(8);
        ligne["kilometrage_effectue"] = query.value(9);
        ligne["description"] = query.value(10);
        ligne["commentaire_annulation"] = query.value(11);

        resultats.append(ligne);
    }

    return resultats;
}

bool Maintenance::reserverCreneau(const QDateTime &debut, const QDateTime &fin, int maintenanceId, const QString &raison)
{
    if (!m_db.isOpen() || !debut.isValid() || !fin.isValid() || debut >= fin || maintenanceId <= 0) {
        return false;
    }

    // Vérifier que la maintenance existe
    QSqlQuery checkMaintenance;
    checkMaintenance.prepare("SELECT id FROM MAINTENANCES WHERE id = :id");
    checkMaintenance.bindValue(":id", maintenanceId);

    if (!checkMaintenance.exec() || !checkMaintenance.next()) {
        qWarning() << "Maintenance non trouvée pour la réservation";
        return false;
    }

    // Vérifier la disponibilité du créneau
    if (!verifierDisponibiliteCreneau(debut, fin, -1)) {
        qWarning() << "Créneau non disponible pour la réservation";
        return false;
    }

    // Mettre à jour la maintenance avec les détails de la réservation
    QSqlQuery query;
    query.prepare(
        "UPDATE MAINTENANCES "
        "SET date_debut = :debut, date_fin = :fin, "
        "statut = 'Planifiée', commentaire = :raison, "
        "date_mise_a_jour = CURRENT_TIMESTAMP "
        "WHERE id = :id");

    query.bindValue(":debut", debut);
    query.bindValue(":fin", fin);
    query.bindValue(":raison", raison);
    query.bindValue(":id", maintenanceId);

    if (!query.exec()) {
        qWarning() << "Erreur lors de la réservation du créneau:" << query.lastError().text();
        return false;
    }

    return true;
}

QList<QMap<QString, QVariant>> Maintenance::executerRequete(const QString &requete, const QVariantList &params) const
{
    QList<QMap<QString, QVariant>> resultats;

    if (!m_db.isOpen() || requete.isEmpty()) {
        return resultats;
    }

    QSqlQuery query;
    query.prepare(requete);

    // Lier les paramètres
    for (int i = 0; i < params.size(); ++i) {
        query.bindValue(i, params.at(i));
    }

    if (!query.exec()) {
        qWarning() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
        return resultats;
    }

    // Récupérer les résultats
    QSqlRecord record = query.record();
    int fieldCount = record.count();

    while (query.next()) {
        QMap<QString, QVariant> ligne;

        for (int i = 0; i < fieldCount; ++i) {
            QString fieldName = record.fieldName(i);
            QVariant value = query.value(i);
            ligne[fieldName] = value;
        }

        resultats.append(ligne);
    }

    return resultats;
}

QDateTime Maintenance::calculerProchaineEcheance(int vehiculeId, int typeMaintenanceId) const
{
    if (!m_db.isOpen() || vehiculeId <= 0 || typeMaintenanceId <= 0) {
        return QDateTime();
    }

    // Implémentation simplifiée - à adapter selon les besoins
    // Ici, on retourne simplement la date actuelle + 30 jours
    return QDateTime::currentDateTime().addDays(30);
}

void Maintenance::creerEvenementCalendrier(const QDateTime &debut, const QDateTime &fin,
                                           const QString &titre, const QString &description)
{
    // Implémentation simplifiée - à adapter selon l'API de calendrier utilisée
    qDebug() << "Création d'un événement de calendrier:";
    qDebug() << "Titre:" << titre;
    qDebug() << "Description:" << description;
    qDebug() << "Début:" << debut.toString();
    qDebug() << "Fin:" << fin.toString();

    // Ici, on pourrait utiliser une API comme Google Calendar, Outlook, etc.
    // ou simplement enregistrer l'événement dans une table dédiée
}



// ===================================================================
// VERSION AVEC EMAIL RÉEL (pas simulation)
// ===================================================================




// ===================================================================
// MÉTHODE D'ENVOI D'EMAIL (REMPLACEMENT DU SMS)
// ===================================================================


// ===================================================================
// MÉTHODE D'ENVOI D'EMAIL RÉEL VIA GMAIL SMTP (PRODUCTION)
// ===================================================================


// ===================================================================
// MÉTHODE DE PRODUCTION - À UTILISER AVEC VRAIE API TWILIO
// ===================================================================


void Maintenance::planifierEntretienAutomatique(int vehiculeId, const QString &typeEntretien, int kilometrageDeclencheur)
{
    qDebug() << "=== PLANIFICATION ENTRETIEN AUTOMATIQUE ===";
    qDebug() << "Véhicule ID:" << vehiculeId;
    qDebug() << "Type entretien:" << typeEntretien;
    qDebug() << "Kilométrage déclencheur:" << kilometrageDeclencheur;

    // Trouver un créneau disponible dans les prochains jours
    QList<CreneauMaintenance> creneaux = trouverCreneauxDisponibles(QDate::currentDate(), QDate::currentDate().addDays(7), 120);

    if (!creneaux.isEmpty()) {
        CreneauMaintenance creneau = creneaux.first();

        // Créer la maintenance
        this->setVehiculeId(vehiculeId);
        this->setType(typeEntretien);
        this->setDateDebut(creneau.debut.date());
        this->setDateFin(creneau.fin.date());
        this->setStatut("planifiee");
        this->setDescription(QString("Entretien automatique - Kilométrage: %1 km").arg(kilometrageDeclencheur));

        if (this->ajouter()) {
            qDebug() << "✅ Entretien planifié automatiquement pour le véhicule ID:" << vehiculeId;

            // Réserver le créneau dans le calendrier
            reserverCreneau(creneau.debut, creneau.fin, this->getId(), "Entretien automatique");

            // Créer un événement calendrier
            creerEvenementCalendrier(creneau.debut, creneau.fin,
                                     QString("Entretien %1").arg(typeEntretien),
                                     QString("Véhicule ID: %1 - Entretien automatique").arg(vehiculeId));
        } else {
            qWarning() << "❌ Échec de la planification automatique pour le véhicule ID:" << vehiculeId;
        }
    } else {
        qWarning() << "⚠️ Aucun créneau disponible pour l'entretien automatique du véhicule ID:" << vehiculeId;
    }
}








