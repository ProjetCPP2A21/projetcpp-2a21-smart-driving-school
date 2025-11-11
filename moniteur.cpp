#include "moniteur.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QSqlQuery>

moniteur::moniteur(QWidget *parent)
    : QWidget(parent)
{
    // Création des widgets
    ID = new QLineEdit(this);
    nom = new QLineEdit(this);
    prenom = new QLineEdit(this);
    telephone = new QLineEdit(this);
    spec = new QComboBox(this);
    disp = new QComboBox(this);
    heur = new QSpinBox(this);

    // Valeurs par défaut dans les comboBox
    spec->addItems({"Spécialité1", "Spécialité2", "Spécialité3"});
    disp->addItems({"Disponible", "Indisponible"});

    heur->setRange(0, 100); // Exemple : nombre d'heures max

    // Layout
    QFormLayout *form = new QFormLayout;
    form->addRow("ID", ID);
    form->addRow("Nom", nom);
    form->addRow("Prénom", prenom);
    form->addRow("Téléphone", telephone);
    form->addRow("Spécialité", spec);
    form->addRow("Disponibilité", disp);
    form->addRow("Heures", heur);

    setLayout(form);
}

moniteur::~moniteur()
{
    // Les widgets sont détruits automatiquement par le parent
}

// Ajouter un moniteur
bool moniteur::ajouterMoniteur()
{
    QSqlQuery query;
    query.prepare("INSERT INTO MONITEUR (ID, NOM, PRENOM, TELEPHONE, SPECIALITE, DISPONIBILITE, HEURES_TRAVAIL) "
                  "VALUES (:id, :nom, :prenom, :tel, :spec, :disp, :heures)");

    query.bindValue(":id", ID->text());
    query.bindValue(":nom", nom->text());
    query.bindValue(":prenom", prenom->text());
    query.bindValue(":tel", telephone->text());
    query.bindValue(":spec", spec->currentText());
    query.bindValue(":disp", disp->currentText());
    query.bindValue(":heures", heur->value());

    return query.exec();
}

// Modifier un moniteur
bool moniteur::modifierMoniteur()
{
    QSqlQuery query;
    query.prepare("UPDATE MONITEUR SET NOM=:nom, PRENOM=:prenom, TELEPHONE=:telephone, "
                  "SPECIALITE=:spec, DISPONIBILITE=:disp, HEURES_TRAVAIL=:heur "
                  "WHERE ID=:id");

    query.bindValue(":id", ID->text().toInt());
    query.bindValue(":nom", nom->text());
    query.bindValue(":prenom", prenom->text());
    query.bindValue(":telephone", telephone->text());
    query.bindValue(":spec", spec->currentText());
    query.bindValue(":disp", disp->currentText());
    query.bindValue(":heur", heur->value());

    return query.exec();
}

// Supprimer un moniteur
bool moniteur::supprimerMoniteur()
{
    QSqlQuery query;
    query.prepare("DELETE FROM MONITEUR WHERE ID=:id");
    query.bindValue(":id", ID->text());
    return query.exec();
}
