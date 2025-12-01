#include "examen.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QDate>
#include <QRandomGenerator>
#include <QtGlobal> // pour qrand
#include <QTime>    // pour qrand seed

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
    QSqlQuery checkId;
    checkId.prepare("SELECT COUNT(*) FROM EXAMEN WHERE ID_EXAMEN = :id");
    checkId.bindValue(":id", id);
    checkId.exec();
    checkId.next();

    if (checkId.value(0).toInt() > 0) {
        QMessageBox::warning(nullptr, "Erreur",
                             "⚠️ L'ID existe déjà dans la base !");
        return false;
    }

    // Vérifier que la date + heure ne sont pas prises
    QSqlQuery checkDispo;
    checkDispo.prepare("SELECT COUNT(*) FROM EXAMEN "
                       "WHERE TO_CHAR(DATE_EXAMEN,'DD/MM/YYYY') = :date "
                       "AND HEURE = :heure");
    checkDispo.bindValue(":date", date);
    checkDispo.bindValue(":heure", heure);
    checkDispo.exec();
    checkDispo.next();

    if (checkDispo.value(0).toInt() > 0) {
        QMessageBox::warning(nullptr, "Créneau occupé",
                             "⚠️ Ce créneau horaire est déjà réservé !");
        return false;
    }

    // Vérifier que le véhicule n’est pas déjà réservé au même moment
    QSqlQuery checkVeh;
    checkVeh.prepare("SELECT COUNT(*) FROM EXAMEN "
                     "WHERE VEHICULE = :vehicule "
                     "AND TO_CHAR(DATE_EXAMEN,'DD/MM/YYYY') = :date "
                     "AND HEURE = :heure");
    checkVeh.bindValue(":vehicule", vehicule);
    checkVeh.bindValue(":date", date);
    checkVeh.bindValue(":heure", heure);
    checkVeh.exec();
    checkVeh.next();

    if (checkVeh.value(0).toInt() > 0) {
        QMessageBox::warning(nullptr, "Véhicule occupé",
                             "⚠️ Ce véhicule est déjà utilisé à cette date et heure !");
        return false;
    }

    // Ajout final
    QSqlQuery query;
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
        QMessageBox::critical(nullptr, "Erreur SQL",
                              "⚠️ Erreur : " + query.lastError().text());
        return false;
    }

    return true;
}


bool Examen::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EXAMEN WHERE ID_EXAMEN = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool Examen::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE EXAMEN SET TYPE=:type, DATE_EXAMEN=:date, HEURE=:heure, LIEU=:lieu, VEHICULE=:vehicule, RESULTAT=:resultat "
                  "WHERE ID_EXAMEN=:id");
    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":date", QDate::fromString(date,"dd/MM/yyyy").toString("yyyy-MM-dd")); // 🔹
    query.bindValue(":heure", heure);
    query.bindValue(":lieu", lieu);
    query.bindValue(":vehicule", vehicule);
    query.bindValue(":resultat", resultat);
    return query.exec();
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

    // 🔥 On cherche jusqu'à trouver un créneau libre (max 30 jours)
    for (int jour = 0; jour < 30 && !planifie; ++jour)
    {
        QString dateStr = date.toString("dd/MM/yyyy");

        for (const QString &heure : horaires)
        {
            QTime heureSlot = QTime::fromString(heure, "HH:mm");

            // 🔥 Règle : aujourd'hui → ignorer les heures passée
            if (date == today && heureSlot <= heureActuelle)
                continue;

            // Vérifier disponibilité
            QSqlQuery check;
            check.prepare("SELECT COUNT(*) FROM EXAMEN "
                          "WHERE TO_CHAR(DATE_EXAMEN,'DD/MM/YYYY') = :date "
                          "AND HEURE = :heure");
            check.bindValue(":date", dateStr);
            check.bindValue(":heure", heure);
            check.exec();
            check.next();

            if (check.value(0).toInt() == 0)
            {
                // Créneau libre → on planifie
                int id = QRandomGenerator::global()->bounded(1000, 9999);
                QString resultat = "En attente";

                QSqlQuery insert;
                insert.prepare("INSERT INTO EXAMEN "
                               "(ID_EXAMEN, TYPE, DATE_EXAMEN, HEURE, LIEU, VEHICULE, RESULTAT) "
                               "VALUES (:id, :type, TO_DATE(:date,'DD/MM/YYYY'), :heure, "
                               ":lieu, :vehicule, :resultat)");

                insert.bindValue(":id", id);
                insert.bindValue(":type", type);
                insert.bindValue(":date", dateStr);
                insert.bindValue(":heure", heure);
                insert.bindValue(":lieu", lieu);
                insert.bindValue(":vehicule", vehicule);
                insert.bindValue(":resultat", resultat);

                if (!insert.exec()) {
                    qDebug() << "Erreur SQL :" << insert.lastError().text();
                    return false;
                }

                planifie = true;
                break;
            }
        }

        // 🔥 Si aucun créneau trouvé aujourd’hui → passer au jour suivant
        if (!planifie)
            date = date.addDays(1);
    }

    return planifie;
}





// Affichage
QSqlQueryModel* Examen::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery(
        "SELECT ID_EXAMEN, TYPE, "
        "TO_CHAR(DATE_EXAMEN, 'DD/MM/YYYY') AS DATE_EXAMEN, "
        "HEURE, LIEU, VEHICULE, RESULTAT "
        "FROM EXAMEN"
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

