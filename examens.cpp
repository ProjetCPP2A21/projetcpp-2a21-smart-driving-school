#include "examens.h"
#include "ui_examens.h"
#include <QMessageBox>
#include <QDate>
#include <QTime>
#include <QSqlQuery>
#include <QSqlQueryModel>

examens::examens(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::examens)
{
    ui->setupUi(this);

    // -------------------- CONFIGURATION TABLE --------------------
    ui->tableView_examens->setSelectionBehavior(QAbstractItemView::SelectRows); // sélection par ligne
    ui->tableView_examens->setSelectionMode(QAbstractItemView::SingleSelection); // une seule ligne à la fois
    ui->tableView_examens->setEditTriggers(QAbstractItemView::NoEditTriggers); // pas d'édition directe

    // Afficher la table au démarrage
    ui->tableView_examens->setModel(Examen().afficher());

    // Connecter le clic sur le tableau au slot
    connect(ui->tableView_examens, &QTableView::clicked,
            this, &examens::on_tableView_examens_clicked);

    // Connexion du QLineEdit à la recherche
    connect(ui->lineEdit_rechercheType, &QLineEdit::textChanged,
            this, &examens::rechercherParType);
    connect(ui->comboBox_triDate, &QComboBox::currentTextChanged,
            this, &examens::on_pushButton_trierDate_clicked);
}

examens::~examens()
{
    delete ui;
}

// -------------------- AJOUTER --------------------
void examens::on_pushButton_ajouter_clicked()
{
    QString idText = ui->lineEdit_id->text();
    QString type = ui->comboBox_type->currentText();
    QString date = ui->dateEdit_date->date().toString("dd/MM/yyyy");
    QString heure = ui->timeEdit_heure->time().toString("hh:mm");
    QString lieu = ui->lineEdit_lieu->text();
    QString vehicule = ui->comboBox_vehicule->currentText();
    QString resultat = ui->comboBox_resultat->currentText();

    // Vérification des champs
    if (idText.isEmpty() || type.isEmpty() || date.isEmpty() || heure.isEmpty() ||
        lieu.isEmpty() || vehicule.isEmpty() || resultat.isEmpty())
    {
        QMessageBox::warning(this, "Champs manquants",
                             "⚠️ Veuillez remplir tous les champs !");
        return;
    }

    // Vérification de l'ID entier
    bool ok;
    int id = idText.toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "L'ID doit être un entier !");
        return;
    }

    Examen e(id, type, date, heure, lieu, vehicule, resultat);
    if (e.ajouter()) {
        QMessageBox::information(this, "Succès", "Examen ajouté !");
        ui->tableView_examens->setModel(Examen().afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l’ajout !");
    }
}

// -------------------- MODIFIER --------------------
void examens::on_pushButton_modifier_clicked()
{
    QModelIndexList selection = ui->tableView_examens->selectionModel()->selectedRows();
    if (selection.count() == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une ligne à modifier !");
        return;
    }

    int id = selection.at(0).data().toInt(); // ID de la ligne sélectionnée

    QString type = ui->comboBox_type->currentText();
    QString date = ui->dateEdit_date->date().toString("dd/MM/yyyy");
    QString heure = ui->timeEdit_heure->time().toString("hh:mm");
    QString lieu = ui->lineEdit_lieu->text();
    QString vehicule = ui->comboBox_vehicule->currentText();
    QString resultat = ui->comboBox_resultat->currentText();

    Examen e(id, type, date, heure, lieu, vehicule, resultat);
    if (e.modifier()) {
        QMessageBox::information(this, "Succès", "Examen modifié !");
        ui->tableView_examens->setModel(Examen().afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification !");
    }
}

// -------------------- SUPPRIMER --------------------
void examens::on_pushButton_supprimer_clicked()
{
    QModelIndexList selection = ui->tableView_examens->selectionModel()->selectedRows();
    if (selection.count() == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une ligne à supprimer !");
        return;
    }

    int id = selection.at(0).data().toInt();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmer", "Voulez-vous vraiment supprimer cet examen ?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        if (Examen().supprimer(id)) {
            QMessageBox::information(this, "Succès", "Examen supprimé !");
            ui->tableView_examens->setModel(Examen().afficher());

            // Vider les champs du formulaire
            ui->lineEdit_id->clear();
            ui->comboBox_type->setCurrentIndex(0);
            ui->dateEdit_date->setDate(QDate::currentDate());
            ui->timeEdit_heure->setTime(QTime::currentTime());
            ui->lineEdit_lieu->clear();
            ui->comboBox_vehicule->setCurrentIndex(0);
            ui->comboBox_resultat->setCurrentIndex(0);
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression !");
        }
    }
}

// -------------------- CLIC SUR LA TABLE --------------------
void examens::on_tableView_examens_clicked(const QModelIndex &index)
{
    // Vérifier que l'utilisateur clique sur la colonne ID
    if (index.column() == 0) {
        ui->tableView_examens->selectRow(index.row()); // sélectionner toute la ligne

        int row = index.row();
        int id = ui->tableView_examens->model()->index(row, 0).data().toInt();
        QString type = ui->tableView_examens->model()->index(row, 1).data().toString();
        QString date = ui->tableView_examens->model()->index(row, 2).data().toString();
        QString heure = ui->tableView_examens->model()->index(row, 3).data().toString();
        QString lieu = ui->tableView_examens->model()->index(row, 4).data().toString();
        QString vehicule = ui->tableView_examens->model()->index(row, 5).data().toString();
        QString resultat = ui->tableView_examens->model()->index(row, 6).data().toString();

        ui->lineEdit_id->setText(QString::number(id));
        ui->comboBox_type->setCurrentText(type);
        ui->dateEdit_date->setDate(QDate::fromString(date, "dd/MM/yyyy"));
        ui->timeEdit_heure->setTime(QTime::fromString(heure, "hh:mm"));
        ui->lineEdit_lieu->setText(lieu);
        ui->comboBox_vehicule->setCurrentText(vehicule);
        ui->comboBox_resultat->setCurrentText(resultat);
    }
}

// -------------------- Recherche --------------------
void examens::rechercherParType(const QString &type)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Requête SQL pour filtrer par type (insensible à la casse)
    query.prepare("SELECT ID_EXAMEN, TYPE, DATE_EXAMEN, HEURE, LIEU, VEHICULE, RESULTAT "
                  "FROM EXAMEN WHERE LOWER(TYPE) LIKE LOWER(:type)");
    query.bindValue(":type", "%" + type + "%"); // permet la recherche partielle
    query.exec();

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Véhicule"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Résultat"));

    ui->tableView_examens->setModel(model);
}

void examens::on_pushButton_trierDate_clicked()
{
    QString ordre = ui->comboBox_triDate->currentText();  // Récupère le choix du comboBox
    QString direction;

    if (ordre == "Croissant")
        direction = "ASC";   // Tri croissant
    else if (ordre == "Décroissant")
        direction = "DESC";  // Tri décroissant
    else {
        QMessageBox::warning(this, "Erreur", "Veuillez choisir un ordre de tri !");
        return;
    }

    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Requête SQL avec tri dynamique
    query.prepare("SELECT ID_EXAMEN, TYPE, DATE_EXAMEN, HEURE, LIEU, VEHICULE, RESULTAT "
                  "FROM EXAMEN ORDER BY DATE_EXAMEN " + direction);
    query.exec();

    model->setQuery(std::move(query));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Véhicule"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Résultat"));

    ui->tableView_examens->setModel(model);
}
