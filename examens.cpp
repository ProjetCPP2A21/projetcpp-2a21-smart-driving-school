#include "examens.h"
#include "ui_examens.h"
#include <QMessageBox>
#include <QDate>
#include <QTime>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QFont>
#include <QAbstractItemModel>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>


examens::examens(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::examens)
{
    ui->setupUi(this);

    // ✅ Démarre sur la page de connexion
    ui->stackedWidget->setCurrentIndex(0);

    // Masquer le mot de passe
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

    // Connexions
    connect(ui->pushButton_examens, &QPushButton::clicked, this, &examens::on_pushButton_examens_clicked);

    // Initialisation de la table examens (ta partie existante)
    selectedId = 0;
    ui->tableView_examens->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_examens->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_examens->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_examens->setModel(Examen().afficher());

    connect(ui->tableView_examens, &QTableView::clicked, this, &examens::on_tableView_examens_clicked);
    connect(ui->lineEdit_rechercheType, &QLineEdit::textChanged, this, &examens::rechercherParType);
    connect(ui->comboBox_triDate, &QComboBox::currentTextChanged, this, &examens::trierDate);

    connect(ui->pushButton_stats, &QPushButton::clicked, this, &examens::afficherStatistiques);
}

// 🟢 LOGIN
void examens::on_pushButton_login_clicked()
{
    QString email = ui->lineEdit_email->text().trimmed();
    QString password = ui->lineEdit_password->text().trimmed();

    if (email == "smart.drivingschool@esprit.tn" && password == "0000")
    {
        QMessageBox::information(this, "Connexion réussie", "Bienvenue !");
        ui->stackedWidget->setCurrentIndex(1); // Page menu
        ui->lineEdit_email->clear();
        ui->lineEdit_password->clear();
    }
    else
    {
        QMessageBox::warning(this, "Erreur", "Email ou mot de passe incorrect !");
    }
}

// 🟡 MENU → PAGE EXAMENS
void examens::on_pushButton_examens_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); // Passe à l’interface examens
    ui->tableView_examens->setModel(Examen().afficher());
    ui->tableView_examens->clearSelection();
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
   /* if (idText.isEmpty() || type.isEmpty() || date.isEmpty() || heure.isEmpty() ||
        lieu.isEmpty() || vehicule.isEmpty() || resultat.isEmpty())
    {
        QMessageBox::warning(this, "Champs manquants",
                             "⚠️ Veuillez remplir tous les champs !");
        return;
    }*/

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
        clearFields(); // 🟢 vide les champs après ajout
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l’ajout !");
    }
}


// -------------------- MODIFIER --------------------
void examens::on_pushButton_modifier_clicked()
{
    // ✅ Vérifier qu'une ligne est bien sélectionnée dans le tableau
    QModelIndexList selection = ui->tableView_examens->selectionModel()->selectedRows();
    if (selection.count() == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une ligne à modifier !");
        return;
    }

    // ✅ Récupérer l'ID depuis la ligne sélectionnée
    int id = selection.at(0).data().toInt();
    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID non valide !");
        return;
    }

    // ✅ Récupérer les valeurs modifiées dans les champs
    QString type = ui->comboBox_type->currentText().trimmed();
    QString date = ui->dateEdit_date->date().toString("dd/MM/yyyy");
    QString heure = ui->timeEdit_heure->time().toString("hh:mm");
    QString lieu = ui->lineEdit_lieu->text().trimmed();
    QString vehicule = ui->comboBox_vehicule->currentText().trimmed();
    QString resultat = ui->comboBox_resultat->currentText().trimmed();

    // ✅ Vérification : aucun champ obligatoire ne doit être vide
    if (type.isEmpty() || lieu.isEmpty() || vehicule.isEmpty() || resultat.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs avant de modifier !");
        return;
    }
    // ⚠️ Demander confirmation avant modification
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,
                                  "Confirmation",
                                  "Voulez-vous vraiment modifier cet examen ?",
                                  QMessageBox::Yes | QMessageBox::No);


    // ✅ Créer un objet Examen avec les nouvelles valeurs
    Examen e(id, type, date, heure, lieu, vehicule, resultat);

    // ✅ Lancer la modification dans la base de données
    if (e.modifier()) {
        QMessageBox::information(this, "Succès", "Examen modifié avec succès !");
        ui->tableView_examens->setModel(Examen().afficher());  // 🔄 Rafraîchir le tableau
        clearFields();   // 🧹 Vider les champs après modification
        selectedId = 0;  // 🔁 Réinitialiser la sélection
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification dans la base de données !");
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
            clearFields(); // 🟢 vide les champs après suppression
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

void examens::trierDate(const QString &ordre)
{
    QString direction;

    if (ordre == "Croissant")
        direction = "ASC";
    else if (ordre == "Décroissant")
        direction = "DESC";
    else
        return; // aucune action

    QSqlQueryModel* model = new QSqlQueryModel();
    QString sql = QString("SELECT ID_EXAMEN, TYPE, TO_CHAR(DATE_EXAMEN, 'DD/MM/YYYY') AS DATE_EXAMEN, HEURE, LIEU, VEHICULE, RESULTAT "
                          "FROM EXAMEN ORDER BY DATE_EXAMEN %1").arg(direction);

    model->setQuery(sql);

    if (model->lastError().isValid()) {
        qDebug() << "Erreur tri:" << model->lastError().text();
        return;
    }

    // Entêtes de colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Véhicule"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Résultat"));

    ui->tableView_examens->setModel(model);
}


void examens::on_exporterPDF_clicked()
{
    QModelIndexList selectedRows = ui->tableView_examens->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner une ligne à exporter !");
        return;
    }

    int selectedRow = selectedRows.first().row();
    QAbstractItemModel *model = ui->tableView_examens->model();

    QString filePath = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichier PDF (*.pdf)");
    if (filePath.isEmpty())
        return;
    if (!filePath.endsWith(".pdf", Qt::CaseInsensitive))
        filePath += ".pdf";

    QPdfWriter pdf(filePath);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setTitle("Fiche d’examen");

    QPainter painter(&pdf);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setFont(QFont("Helvetica", 18, QFont::Bold));
    painter.drawText(2000, 1500, "Fiche d'examen");
    painter.setFont(QFont("Helvetica", 10));
    painter.drawText(2000, 1800, "Date d'exportation : " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm"));

    painter.setPen(QPen(Qt::black, 2));
    painter.drawLine(1000, 2000, 5000, 2000);

    int y = 2500;
    int lineSpacing = 500;

    painter.setFont(QFont("Helvetica", 12));

    for (int col = 0; col < model->columnCount(); ++col) {
        QString header = model->headerData(col, Qt::Horizontal).toString();
        QString data = model->data(model->index(selectedRow, col)).toString();
        painter.drawText(1200, y, header + " : " + data);
        y += lineSpacing;
    }

    painter.setPen(QPen(Qt::gray, 1, Qt::DashLine));
    painter.drawLine(1000, y + 200, 5000, y + 200);

    painter.setFont(QFont("Helvetica", 9, QFont::StyleItalic));
    painter.drawText(2000, 11000, "Document généré automatiquement - " + QDate::currentDate().toString("dd/MM/yyyy"));

    painter.end();

    QMessageBox::information(this, "Succès", "La fiche d’examen a été exportée avec succès !");
}


void examens::afficherStatistiques()
{
    QSqlQuery query;
    // 🔹 Grouper par RESULTAT au lieu de TYPE
    query.prepare("SELECT RESULTAT, COUNT(*) FROM EXAMEN GROUP BY RESULTAT");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les statistiques : " + query.lastError().text());
        return;
    }

    QPieSeries *series = new QPieSeries();
    while (query.next()) {
        QString resultat = query.value(0).toString(); // "Réussi" ou "Échec"
        int count = query.value(1).toInt();
        series->append(resultat, count);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des examens selon le résultat");
    chart->legend()->setAlignment(Qt::AlignRight);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // 🔹 Affichage dans une nouvelle fenêtre
    QMainWindow *statWindow = new QMainWindow(this);
    statWindow->setCentralWidget(chartView);
    statWindow->resize(600, 400);
    statWindow->show();
}



void examens::clearFields()
{
    ui->lineEdit_id->clear();
    ui->comboBox_type->setCurrentIndex(-1);
    ui->dateEdit_date->setDate(QDate::currentDate());
    ui->timeEdit_heure->setTime(QTime::currentTime());
    ui->lineEdit_lieu->clear();
    ui->comboBox_vehicule->setCurrentIndex(-1);
    ui->comboBox_resultat->setCurrentIndex(-1);
}

// 🟢 RETOUR → MENU
void examens::on_pushButton_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); // index 1 = page menu
}
