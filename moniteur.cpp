#include "moniteur.h"
#include "ui_moniteur.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QAbstractItemView>
#include <QDebug>

void moniteur::afficherMoniteurs(QTableWidget *table) {
    if (!table) return;
    table->clear();
    table->setColumnCount(7);
    table->setHorizontalHeaderLabels(QStringList()
                                     << "ID" << "Nom" << "Prénom" << "Téléphone"
                                     << "Spécialité" << "Disponibilité" << "Heures");
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setAlternatingRowColors(true);
    table->setRowCount(0);
    QSqlQuery query(QSqlDatabase::database("oracle_connection"));
    query.prepare("SELECT ID, NOM, PRENOM, TELEPHONE, SPECIALITE, DISPONIBILITE, HEURES_TRAVAIL FROM MONITEUR");
    
    if (!query.exec()) {
        qDebug() << "Erreur SQL (afficherMoniteurs):" << query.lastError().text();
        return;
    }

    int row = 0;
    while (query.next()) {
        table->insertRow(row);
        for (int col = 0; col < 7; ++col) {
            table->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }
}

bool moniteur::ajouterMoniteur(Ui::moniteur *ui) {
    QSqlQuery query(QSqlDatabase::database("oracle_connection"));
    query.prepare("INSERT INTO MONITEUR (ID, NOM, PRENOM, TELEPHONE, SPECIALITE, DISPONIBILITE, HEURES_TRAVAIL) "
                  "VALUES (:id, :nom, :prenom, :tel, :spec, :disp, :heures)");
    query.bindValue(":id", ui->ID->text());
    query.bindValue(":nom", ui->nom->text());
    query.bindValue(":prenom", ui->prenom->text());
    query.bindValue(":tel", ui->telephone->text());
    query.bindValue(":spec", ui->spec->currentText());
    query.bindValue(":disp", ui->disp->currentText());
    query.bindValue(":heures", ui->heur->value());

    if (!query.exec()) {
        qDebug() << "Erreur SQL (ajouterMoniteur):" << query.lastError().text();
        return false;
    }
    return true;
}

bool moniteur::modifierMoniteur(Ui::moniteur *ui) {
    QSqlQuery query(QSqlDatabase::database("oracle_connection"));
    query.prepare("UPDATE MONITEUR SET "
                  "NOM = :nom, "
                  "PRENOM = :prenom, "
                  "TELEPHONE = :telephone, "
                  "SPECIALITE = :spec, "
                  "DISPONIBILITE = :disp, "
                  "HEURES_TRAVAIL = :heur "
                  "WHERE ID = :id");

    query.bindValue(":id", ui->ID->text().trimmed().toInt());
    query.bindValue(":nom", ui->nom->text().trimmed());
    query.bindValue(":prenom", ui->prenom->text().trimmed());
    query.bindValue(":telephone", ui->telephone->text().trimmed());
    query.bindValue(":spec", ui->spec->currentText().trimmed());
    query.bindValue(":disp", ui->disp->currentText().trimmed());
    query.bindValue(":heur", ui->heur->value());

    if (!query.exec()) {
        qDebug() << "Erreur SQL (modifierMoniteur):" << query.lastError().text();
        return false;
    }

    return query.numRowsAffected() > 0;
}

bool moniteur::supprimerMoniteur(Ui::moniteur *ui) {
    QSqlQuery query(QSqlDatabase::database("oracle_connection"));
    query.prepare("DELETE FROM MONITEUR WHERE ID=:id");
    query.bindValue(":id", ui->ID->text());

    if (!query.exec()) {
        qDebug() << "Erreur SQL (supprimerMoniteur):" << query.lastError().text();
        return false;
    }
    return true;
}

bool moniteur::existe(QString id)
{
    QSqlDatabase db = QSqlDatabase::database("oracle_connection");
    if (!db.isOpen()) {
        qDebug() << "[employe::existe] Connexion Oracle non ouverte";
        return false;
    }

    QSqlQuery query(db);
    query.prepare("SELECT 1 FROM EMPLOYE WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "[employe::existe] Erreur SQL:" << query.lastError().text();
        return false;
    }

    // ✅ Retourne vrai si un résultat est trouvé
    return query.next();
}
