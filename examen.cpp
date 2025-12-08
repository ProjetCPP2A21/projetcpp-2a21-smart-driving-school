#include "examen.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QDate>
#include <QRandomGenerator>
#include <QtGlobal>
#include <QTime>

static inline QSqlDatabase db()
{
    // Utilise la connexion Oracle déjà créée/ouverte ailleurs dans ton app
    return QSqlDatabase::database("oracle_connection");
}

Examen::Examen() {}

Examen::Examen(int id, QString type, QString date, QString heure, QString lieu, QString vehicule, QString resultat)
{
    this->id = id;
    this->type = type;
    this->date = date;
    this->heure = heure;
    this->lieu = lieu;
    this->vehicule = vehicule;
    this->resultat = resultat;
}

bool Examen::ajouter()
{
    // Vérifier que l’ID n’existe pas déjà
    QSqlQuery checkId(db());
    checkId.prepare("SELECT COUNT(*) FROM EXAMEN WHERE ID_EXAMEN = :id");
    checkId.bindValue(":id", id);
    if (!checkId.exec() || !checkId.next()) {
        QMessageBox::critical(nullptr, "Erreur SQL", "Erreur lors du contrôle d'ID : " + checkId.lastError().text());
        return false;
    }
    if (checkId.value(0).toInt() > 0) {
        QMessageBox::warning(nullptr, "Erreur", "⚠️ L'ID existe déjà dans la base !");
        return false;
    }

    // Vérifier que la date + heure ne sont pas prises
    QSqlQuery checkDispo(db());
    checkDispo.prepare("SELECT COUNT(*) FROM EXAMEN "
                       "WHERE TO_CHAR(DATE_EXAMEN,'DD/MM/YYYY') = :date "
                       "AND HEURE = :heure");
    checkDispo.bindValue(":date", date);
    checkDispo.bindValue(":heure", heure);
    if (!checkDispo.exec() || !checkDispo.next()) {
        QMessageBox::critical(nullptr, "Erreur SQL", "Erreur dispo créneau : " + checkDispo.lastError().text());
        return false;
    }
    if (checkDispo.value(0).toInt() > 0) {
        QMessageBox::warning(nullptr, "Créneau occupé", "⚠️ Ce créneau horaire est déjà réservé !");
        return false;
    }

    // Vérifier que le véhicule n’est pas déjà réservé au même moment
    QSqlQuery checkVeh(db());
    checkVeh.prepare("SELECT COUNT(*) FROM EXAMEN "
                     "WHERE VEHICULE = :vehicule "
                     "AND TO_CHAR(DATE_EXAMEN,'DD/MM/YYYY') = :date "
                     "AND HEURE = :heure");
    checkVeh.bindValue(":vehicule", vehicule);
    checkVeh.bindValue(":date", date);
    checkVeh.bindValue(":heure", heure);
    if (!checkVeh.exec() || !checkVeh.next()) {
        QMessageBox::critical(nullptr, "Erreur SQL", "Erreur dispo véhicule : " + checkVeh.lastError().text());
        return false;
    }
    if (checkVeh.value(0).toInt() > 0) {
        QMessageBox::warning(nullptr, "Véhicule occupé", "⚠️ Ce véhicule est déjà utilisé à cette date et heure !");
        return false;
    }

    // Ajout final
    QSqlQuery query(db());
    query.prepare("INSERT INTO EXAMEN (ID_EXAMEN, TYPE, DATE_EXAMEN, HEURE, LIEU, VEHICULE, RESULTAT) "
                  "VALUES (:id, :type, TO_DATE(:date, 'DD/MM/YYYY'), :heure, :lieu, :vehicule, :resultat)");
    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":date", date);
    query.bindValue(":heure", heure);
    query.bindValue(":lieu", lieu);
    query.bindValue(":vehicule", vehicule);
    query.bindValue(":resultat", resultat);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur SQL", "⚠️ Erreur : " + query.lastError().text());
        return false;
    }
    return true;
}

bool Examen::supprimer(int id)
{
    QSqlQuery query(db());
    query.prepare("DELETE FROM EXAMEN WHERE ID_EXAMEN = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "Erreur SQL (supprimer):" << query.lastError().text();
        return false;
    }
    return true;
}

bool Examen::modifier()
{
    // On garde le même format de date que partout : on reçoit "dd/MM/yyyy"
    // et on le convertit côté SQL avec TO_DATE
    QSqlQuery query(db());
    query.prepare("UPDATE EXAMEN "
                  "SET TYPE = :type, "
                  "    DATE_EXAMEN = TO_DATE(:date, 'DD/MM/YYYY'), "
                  "    HEURE = :heure, "
                  "    LIEU = :lieu, "
                  "    VEHICULE = :vehicule, "
                  "    RESULTAT = :resultat "
                  "WHERE ID_EXAMEN = :id");
    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":date", date); // string "dd/MM/yyyy"
    query.bindValue(":heure", heure);
    query.bindValue(":lieu", lieu);
    query.bindValue(":vehicule", vehicule);
    query.bindValue(":resultat", resultat);

    if (!query.exec()) {
        qDebug() << "Erreur SQL (modifier):" << query.lastError().text();
        return false;
    }
    return true;
}

bool Examen::planifierAutomatique(QString type, QString lieu, QString vehicule)
{
    if (type.isEmpty() || lieu.isEmpty() || vehicule.isEmpty())
        return false;

    QStringList horaires = {"08:00", "09:00", "10:00", "11:00", "12:00"};

    QDate today = QDate::currentDate();
    QTime heureActuelle = QTime::currentTime();

    QDate date = today;
    bool planifie = false;

    // On cherche jusqu'à trouver un créneau libre (max 30 jours)
    for (int jour = 0; jour < 30 && !planifie; ++jour)
    {
        QString dateStr = date.toString("dd/MM/yyyy");

        for (const QString &heure : horaires)
        {
            QTime heureSlot = QTime::fromString(heure, "HH:mm");

            // aujourd'hui → ignorer les heures passées
            if (date == today && heureSlot <= heureActuelle)
                continue;

            // Vérifier disponibilité
            QSqlQuery check(db());
            check.prepare("SELECT COUNT(*) FROM EXAMEN "
                          "WHERE TO_CHAR(DATE_EXAMEN,'DD/MM/YYYY') = :date "
                          "AND HEURE = :heure");
            check.bindValue(":date", dateStr);
            check.bindValue(":heure", heure);
            if (!check.exec() || !check.next()) {
                qDebug() << "Erreur SQL (check dispo auto):" << check.lastError().text();
                return false;
            }

            if (check.value(0).toInt() == 0)
            {
                // Créneau libre → on planifie
                int newId = QRandomGenerator::global()->bounded(1000, 9999);
                QString resultat = "En attente";

                QSqlQuery insert(db());
                insert.prepare("INSERT INTO EXAMEN "
                               "(ID_EXAMEN, TYPE, DATE_EXAMEN, HEURE, LIEU, VEHICULE, RESULTAT) "
                               "VALUES (:id, :type, TO_DATE(:date,'DD/MM/YYYY'), :heure, "
                               ":lieu, :vehicule, :resultat)");
                insert.bindValue(":id", newId);
                insert.bindValue(":type", type);
                insert.bindValue(":date", dateStr);
                insert.bindValue(":heure", heure);
                insert.bindValue(":lieu", lieu);
                insert.bindValue(":vehicule", vehicule);
                insert.bindValue(":resultat", resultat);

                if (!insert.exec()) {
                    qDebug() << "Erreur SQL (insert auto):" << insert.lastError().text();
                    return false;
                }

                planifie = true;
                break;
            }
        }

        if (!planifie)
            date = date.addDays(1);
    }

    return planifie;
}

// Affichage
QSqlQueryModel* Examen::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(
        "SELECT ID_EXAMEN, TYPE, "
        "TO_CHAR(DATE_EXAMEN, 'DD/MM/YYYY') AS DATE_EXAMEN, "
        "HEURE, LIEU, VEHICULE, RESULTAT "
        "FROM EXAMEN",
        db() // <<<<<< connexion Oracle passée ici
        );

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Véhicule"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Résultat"));

    return model;
}














