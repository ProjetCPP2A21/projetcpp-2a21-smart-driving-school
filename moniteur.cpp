#include "moniteur.h"
#include "ui_moniteur.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QTableWidgetItem>
#include <QDebug>

void moniteur::afficherMoniteurs(QTableWidget *table) {
    table->setRowCount(0);
    QSqlQuery query("SELECT ID, NOM, PRENOM, TELEPHONE, SPECIALITE, DISPONIBILITE, HEURES_TRAVAIL FROM MONITEUR");

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
    QSqlQuery query;
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
    // Vérifier que l'ID est renseigné
    bool okConv = false;
    int id = ui->ID->text().trimmed().toInt(&okConv);
    if (!okConv) {
        qDebug() << "ID invalide pour la modification";
        return false;
    }

    QStringList setClauses;
    QMap<QString, QVariant> values;

    // Ajouter les champs remplis
    if (!ui->nom->text().trimmed().isEmpty()) {
        setClauses << "NOM = :nom";
        values[":nom"] = ui->nom->text().trimmed();
    }
    if (!ui->prenom->text().trimmed().isEmpty()) {
        setClauses << "PRENOM = :prenom";
        values[":prenom"] = ui->prenom->text().trimmed();
    }
    if (!ui->telephone->text().trimmed().isEmpty()) {
        setClauses << "TELEPHONE = :telephone";
        values[":telephone"] = ui->telephone->text().trimmed();
    }
    if (!ui->spec->currentText().trimmed().isEmpty()) {
        setClauses << "SPECIALITE = :spec";
        values[":spec"] = ui->spec->currentText().trimmed();
    }
    if (!ui->disp->currentText().trimmed().isEmpty()) {
        setClauses << "DISPONIBILITE = :disp";
        values[":disp"] = ui->disp->currentText().trimmed();
    }
    // On peut aussi vérifier que heures != 0 si on veut
    if (ui->heur->value() > 0) {
        setClauses << "HEURES_TRAVAIL = :heur";
        values[":heur"] = ui->heur->value();
    }

    // Si aucun champ n'est rempli, ne rien faire
    if (setClauses.isEmpty()) {
        qDebug() << "Aucun champ à modifier";
        return false;
    }

    // Construire la requête SQL dynamiquement
    QString sql = "UPDATE MONITEUR SET " + setClauses.join(", ") + " WHERE ID = :id";
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", id);

    // Lier toutes les valeurs
    for (auto it = values.begin(); it != values.end(); ++it) {
        query.bindValue(it.key(), it.value());
    }

    if (!query.exec()) {
        qDebug() << "Erreur SQL (modifierMoniteur):" << query.lastError().text();
        return false;
    }

    return query.numRowsAffected() > 0;
}


bool moniteur::supprimerMoniteur(Ui::moniteur *ui) {
    QSqlQuery query;
    query.prepare("DELETE FROM MONITEUR WHERE ID=:id");
    query.bindValue(":id", ui->ID->text());

    if (!query.exec()) {
        qDebug() << "Erreur SQL (supprimerMoniteur):" << query.lastError().text();
        return false;
    }
    return true;
}

// ------------------ Métier avancé : taux de réussite ------------------
double moniteur::tauxReussite(int idMoniteur) {
    QSqlQuery query;
    int total = 0;
    int reussis = 0;

    // Total examens passés par les apprenants du moniteur
    query.prepare(
        "SELECT COUNT(*) FROM PASSER P "
        "JOIN APPRENANT A ON P.ID_APPRENANT = A.ID_APPRENANT "
        "WHERE A.ID_MONITEUR = :id"
        );
    query.bindValue(":id", idMoniteur);
    if (!query.exec()) {
        qDebug() << "Erreur SQL (tauxReussite total):" << query.lastError().text();
    } else if (query.next()) {
        total = query.value(0).toInt();
    }

    // Examens réussis
    query.prepare(
        "SELECT COUNT(*) FROM PASSER P "
        "JOIN APPRENANT A ON P.ID_APPRENANT = A.ID_APPRENANT "
        "JOIN EXAMEN E ON P.ID_EXAMEN = E.ID_EXAMEN "
        "WHERE A.ID_MONITEUR = :id AND LOWER(E.RESULTAT) = 'reussi'"
        );
    query.bindValue(":id", idMoniteur);
    if (!query.exec()) {
        qDebug() << "Erreur SQL (tauxReussite reussis):" << query.lastError().text();
    } else if (query.next()) {
        reussis = query.value(0).toInt();
    }

    if (total == 0) return 0.0;
    return (reussis * 100.0) / total;
}


