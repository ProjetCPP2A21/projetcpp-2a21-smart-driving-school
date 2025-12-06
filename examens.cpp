#include "mainwindow.h"
#include "employes.h"
 #include "examens.h"
#include "apprenants.h"
#include "vehicule.h"
#include "ui_examens.h"
#include "moniteur_ui.h"
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
#include <QTimer>
#include <QVBoxLayout>
#include <QDialog>
#include <QtCharts/QChart>
#include <QPrinter>
#include <QGraphicsDropShadowEffect>
#include <QTextDocument>

static inline QSqlDatabase db() {
    return QSqlDatabase::database("oracle_connection");
}


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
    connect(ui->pushButton_5, &QPushButton::clicked, this, &examens::on_pushButton_5_clicked);

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
    connect(ui->pushButton_rappel, &QPushButton::clicked, this, &examens::rappelExamensDuJour);


}

// 🟢 LOGIN
void examens::on_pushButton_login_clicked()
{
    QString email = ui->lineEdit_email->text().trimmed();
    QString password = ui->lineEdit_password->text().trimmed();

    if (email == "a" && password == "0000") {
        QMessageBox::information(this, "Connexion réussie", "Bienvenue !");
        // Aller au menu principal (index 2)
        ui->stackedWidget->setCurrentIndex(1);
        this->setWindowTitle("Menu Principal");
        ui->lineEdit_email->clear();
        ui->lineEdit_password->clear();
    }
    else if (email == "you" && password == "1112") {
        QMessageBox::information(this, "Connexion réussie", "Bienvenue dans l'interface de paiement !");
        // Aller directement à la page de paiement
        ui->lineEdit_email->clear();
        ui->lineEdit_password->clear();
    }
    else {
        QMessageBox::warning(this, "Erreur", "Email ou mot de passe incorrect !");
    }
}

// 🟡 MENU → PAGE EXAMENS
void examens::on_pushButton_examens_clicked()
{
    // Aller directement à la page des examens (index 3)
    ui->stackedWidget->setCurrentIndex(3);
    
    // Rafraîchir le modèle des données
    if (ui->tableView_examens) {
        ui->tableView_examens->setModel(Examen().afficher());
        ui->tableView_examens->clearSelection();
    }
    
    // Mettre à jour le titre de la fenêtre
    this->setWindowTitle("Gestion des examens");
    
    rappelExamensDuJour();
}

examens::~examens()
{
    if (m_apprenantsPage) {
        ui->stackedWidget->removeWidget(m_apprenantsPage);
        delete m_apprenantsPage;
        m_apprenantsPage = nullptr;
    }
    if (m_moniteurPage) {
        ui->stackedWidget->removeWidget(m_moniteurPage);
        delete m_moniteurPage;
        m_moniteurPage = nullptr;
    }
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

    // --- 🔥 AJOUTER LA VÉRIFICATION ICI ---

    // Vérification date >= today
    QDate dateExamenQ = ui->dateEdit_date->date();
    QDate dateActuelle = QDate::currentDate();

    if (dateExamenQ < dateActuelle) {
        QMessageBox::warning(this, "Date invalide",
                             "⚠️ Vous ne pouvez pas planifier un examen dans le passé !");
        return;
    }

    // Vérification de l'heure si la date est aujourd'hui
    QTime heureExamen = ui->timeEdit_heure->time();
    QTime heureActuelle = QTime::currentTime();

    if (dateExamenQ == dateActuelle && heureExamen <= heureActuelle) {
        QMessageBox::warning(this, "Heure invalide",
                             "⚠️ Vous ne pouvez pas planifier un examen dans une heure déjà passée !");
        return;
    }

    // --- 🔥 FIN vérifications date/heure ---

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
        clearFields();
    }
    else {
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
    // Si le champ est vide → afficher tout
    const QString t = type.trimmed();

    QSqlQueryModel* model = new QSqlQueryModel();

    if (t.isEmpty()) {
        model->setQuery(
            "SELECT ID_EXAMEN, TYPE, "
            "TO_CHAR(DATE_EXAMEN,'DD/MM/YYYY') AS DATE_EXAMEN, "
            "HEURE, LIEU, VEHICULE, RESULTAT "
            "FROM EXAMEN "
            "ORDER BY DATE_EXAMEN DESC, HEURE DESC",
            db() // ✅ même connexion Oracle
            );
    } else {
        QSqlQuery query(db()); // ✅ utilise oracle_connection
        query.prepare(
            "SELECT ID_EXAMEN, TYPE, "
            "TO_CHAR(DATE_EXAMEN,'DD/MM/YYYY') AS DATE_EXAMEN, "
            "HEURE, LIEU, VEHICULE, RESULTAT "
            "FROM EXAMEN "
            "WHERE LOWER(TYPE) LIKE LOWER(:type) "
            "ORDER BY DATE_EXAMEN DESC, HEURE DESC"
            );
        query.bindValue(":type", "%" + t + "%");

        if (!query.exec()) {
            qDebug() << "[EXAMENS] recherche type error:" << query.lastError().text();
            QMessageBox::critical(this, "Erreur",
                                  "Échec de la recherche : " + query.lastError().text());
            delete model;
            return;
        }

        // passer la requête exécutée au modèle (même connexion)
        model->setQuery(std::move(query));
    }

    if (model->lastError().isValid()) {
        qDebug() << "[EXAMENS] model error:" << model->lastError().text();
        QMessageBox::critical(this, "Erreur",
                              "Impossible d'afficher les résultats : " + model->lastError().text());
        delete model;
        return;
    }

    // Entêtes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Véhicule"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Résultat"));

    ui->tableView_examens->setModel(model);
    ui->tableView_examens->resizeColumnsToContents();
}

void examens::trierDate(const QString &ordre)
{
    QString direction;

    if (ordre == "Croissant")
        direction = "ASC";
    else if (ordre == "Décroissant")
        direction = "DESC";
    else
        return; // aucune action si ordre vide ou inconnu

    // ✅ Connexion Oracle centralisée
    QSqlDatabase db = QSqlDatabase::database("oracle_connection");

    if (!db.isOpen()) {
        QMessageBox::critical(this, "Erreur de connexion",
                              "Connexion Oracle inactive !");
        return;
    }

    QSqlQueryModel* model = new QSqlQueryModel();

    // ✅ Requête Oracle avec formatage date et ordre dynamique
    QString sql = QString(
                      "SELECT ID_EXAMEN, TYPE, "
                      "TO_CHAR(DATE_EXAMEN,'DD/MM/YYYY') AS DATE_EXAMEN, "
                      "HEURE, LIEU, VEHICULE, RESULTAT "
                      "FROM EXAMEN "
                      "ORDER BY DATE_EXAMEN %1"
                      ).arg(direction);

    model->setQuery(sql, db);

    // ✅ Vérification d’erreur SQL
    if (model->lastError().isValid()) {
        qDebug() << "[EXAMENS] Erreur tri:" << model->lastError().text();
        QMessageBox::critical(this, "Erreur SQL",
                              "Échec du tri des examens : " + model->lastError().text());
        delete model;
        return;
    }

    // ✅ Entêtes cohérentes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Véhicule"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Résultat"));

    // ✅ Application au tableau
    ui->tableView_examens->setModel(model);
    ui->tableView_examens->resizeColumnsToContents();

    qDebug() << "[EXAMENS] Tri appliqué sur DATE_EXAMEN en" << direction;
}


void examens::on_exporterPDF_clicked()
{
    QAbstractItemModel *model = ui->tableView_examens->model();
    if (!model || model->rowCount() == 0) {
        QMessageBox::warning(this, "Avertissement", "Aucun examen à exporter !");
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty()) return;

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));

    QTextDocument doc;
    QString html = "<h1 align='center'>Liste des Examens</h1><table border='1' width='100%'><tr>";

    for (int col = 0; col < model->columnCount(); ++col)
        html += "<th>" + model->headerData(col, Qt::Horizontal).toString() + "</th>";
    html += "</tr>";

    for (int row = 0; row < model->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < model->columnCount(); ++col)
            html += "<td>" + model->data(model->index(row, col)).toString() + "</td>";
        html += "</tr>";
    }
    html += "</table>";

    doc.setHtml(html);
    doc.print(&printer);

    QMessageBox::information(this, "Succès", "PDF exporté avec succès.");
}




void examens::afficherStatistiques()
{
    // ---------------- Récupération des statistiques ----------------
    QSqlQuery query(db());  // ✅ utilise la connexion Oracle nommée
    query.prepare("SELECT RESULTAT, COUNT(*) FROM EXAMEN GROUP BY RESULTAT");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur",
                              "Impossible de récupérer les statistiques : " + query.lastError().text());
        return;
    }

    QMap<QString,int> stats;
    int total = 0;

    while (query.next()) {
        const QString resultat = query.value(0).toString();  // ex: Admis / En attente / Refusé
        const int count = query.value(1).toInt();
        stats[resultat] = count;
        total += count;
    }

    if (total == 0) {
        QMessageBox::information(this, "Info", "Aucun examen trouvé !");
        return;
    }

    // ---------------- Création de la série (donut chart) ----------------
    QPieSeries* series = new QPieSeries();
    series->setHoleSize(0.35);   // Donut moderne

    for (auto it = stats.begin(); it != stats.end(); ++it) {
        const double pourcentage = (it.value() * 100.0) / total;
        const QString label = it.key() + " (" + QString::number(it.value()) +
                              ") : " + QString::number(pourcentage, 'f', 1) + "%";

        QPieSlice* slice = series->append(label, it.value());
        slice->setLabelVisible(true);

        // 🎨 Couleurs selon le résultat (insensible à la casse/accents)
        const QString key = it.key().toLower();
        if (key == "admis") {
            slice->setBrush(QColor("#43cea2"));   // vert
        } else if (key == "en attente") {
            slice->setBrush(QColor("#f1c40f"));   // jaune
        } else if (key == "refusé" || key == "refuse") {
            slice->setBrush(QColor("#e74c3c"));   // rouge
        }

        // ✨ Animation explosion au survol
        slice->setExploded(false);
        QObject::connect(slice, &QPieSlice::hovered, [slice](bool state){
            slice->setExploded(state);
            slice->setLabelVisible(true);
        });
    }

    // ---------------- Création du graphique ----------------
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    chart->setBackgroundVisible(false);
    chart->setPlotAreaBackgroundVisible(false);

    chart->setTitle("Répartition des examens selon le résultat");
    chart->setTitleFont(QFont("Segoe UI", 14, QFont::Bold));
    chart->setTitleBrush(QBrush(QColor("#185a9d")));

    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->legend()->setFont(QFont("Segoe UI", 10, QFont::Bold));
    chart->legend()->setLabelColor(QColor("#185a9d"));

    // ---------------- Affichage dans un QDialog ----------------
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QDialog* dialog = new QDialog(this);
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);

    dialog->setWindowTitle("Statistiques des Examens");
    dialog->resize(550, 450);
    dialog->exec();
}



void examens::on_pushButton_planifier_clicked()
{
    QString type = ui->comboBox_type->currentText();
    QString lieu = ui->lineEdit_lieu->text();
    QString vehicule = ui->comboBox_vehicule->currentText();

    Examen e;

    if (e.planifierAutomatique(type, lieu, vehicule)) {
        QMessageBox::information(this, "Succès", "Examen planifié automatiquement !");
        ui->tableView_examens->setModel(e.afficher());
    } else {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
    }
}



void examens::rappelExamensDuJour()
{
    static QDialog* rappelDialog = nullptr; // Empêche double ouverture
    if (rappelDialog && rappelDialog->isVisible())
        return;

    QSqlQuery query(db());                         // ✅ connexion Oracle
    const QDate today = QDate::currentDate();

    query.prepare(
        "SELECT ID_EXAMEN, TYPE, HEURE, LIEU, VEHICULE "
        "FROM EXAMEN "
        "WHERE TO_CHAR(DATE_EXAMEN,'DD/MM/YYYY') = :date "
        "ORDER BY HEURE"
        );
    query.bindValue(":date", today.toString("dd/MM/yyyy"));

    if (!query.exec()) {
        qDebug() << "Erreur rappelExamensDuJour:" << query.lastError().text();
        QMessageBox::critical(this, "Erreur",
                              "Impossible de récupérer les examens du jour : "
                                  + query.lastError().text());
        return;
    }

    // --- Créer le dialog ---
    rappelDialog = new QDialog(this);
    rappelDialog->setWindowTitle("📅 Rappel des examens du jour");
    rappelDialog->setModal(true);
    rappelDialog->setFixedSize(600, 500);
    rappelDialog->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    // --- Style ---
    rappelDialog->setStyleSheet(
        "QDialog{background-color:#fff8f0; border-radius:15px;}"
        "QLabel{font-family:Segoe UI; font-size:11pt;}"
        "QPushButton{background-color:#ff8c00; color:white; border:none;"
        "border-radius:8px; padding:10px 20px; font-size:12pt;}"
        "QPushButton:hover{background-color:#ffa733;}"
        );

    QVBoxLayout* mainLayout = new QVBoxLayout(rappelDialog);
    mainLayout->setContentsMargins(15,15,15,15);
    mainLayout->setSpacing(10);

    QLabel* titleLabel = new QLabel(
        "📌 Examens programmés aujourd'hui", rappelDialog);
    titleLabel->setStyleSheet("font-size:16pt; font-weight:bold; color:#2B547E;");
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    // --- Zone scrollable ---
    QScrollArea* scrollArea = new QScrollArea(rappelDialog);
    scrollArea->setWidgetResizable(true);
    QWidget* scrollContent = new QWidget();
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);

    bool hasExams = false;
    while (query.next()) {
        hasExams = true;

        const QString html = QString(
                                 "<b style='color:#1F618D;'>ID: %1 | ⏰ %2</b><br>"
                                 "<span style='color:#2E4053;'>• Type :</span> %3<br>"
                                 "<span style='color:#2E4053;'>• Lieu :</span> %4<br>"
                                 "<span style='color:#2E4053;'>• Véhicule :</span> %5"
                                 )
                                 .arg(query.value("ID_EXAMEN").toString())
                                 .arg(query.value("HEURE").toString())
                                 .arg(query.value("TYPE").toString())
                                 .arg(query.value("LIEU").toString())
                                 .arg(query.value("VEHICULE").toString());

        QLabel* examLabel = new QLabel(html, scrollContent);
        examLabel->setWordWrap(true);
        examLabel->setStyleSheet(
            "padding:8px; border:1px solid #ff8c00; border-radius:8px; "
            "background:#fff3e0;");
        scrollLayout->addWidget(examLabel);
    }

    if (!hasExams) {
        QLabel* emptyLabel = new QLabel(
            "✅ Aucun examen prévu pour aujourd'hui.", scrollContent);
        emptyLabel->setAlignment(Qt::AlignCenter);
        emptyLabel->setStyleSheet("font-size:12pt; color:#2E4053;");
        scrollLayout->addWidget(emptyLabel);
    }

    scrollContent->setLayout(scrollLayout);
    scrollArea->setWidget(scrollContent);
    mainLayout->addWidget(scrollArea);

    // --- Bouton OK ---
    QPushButton* okButton = new QPushButton("✓ OK", rappelDialog);
    okButton->setCursor(Qt::PointingHandCursor);
    QObject::connect(okButton, &QPushButton::clicked, rappelDialog, &QDialog::accept);
    mainLayout->addWidget(okButton, 0, Qt::AlignCenter);

    // --- Ombre ---
    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect(rappelDialog);
    shadow->setBlurRadius(20);
    shadow->setOffset(0,5);
    shadow->setColor(QColor(0,0,0,100));
    rappelDialog->setGraphicsEffect(shadow);

    // --- Reset du pointeur statique ---
    QObject::connect(rappelDialog, &QDialog::finished, [=](){
        rappelDialog->deleteLater();
        rappelDialog = nullptr;
    });

    rappelDialog->exec();
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
    ui->stackedWidget->setCurrentIndex(1); // index 2 = page menu principal
    this->setWindowTitle("Menu Principal");
}

void examens::on_Bapprenant_clicked()
{
    // Afficher la page des apprenants dans le stackedWidget
    if(!m_apprenantsPage) {
        m_apprenantsPage = new apprenants(this);
        ui->stackedWidget->addWidget(m_apprenantsPage);
        // Connecter le signal de retour au menu
        connect(m_apprenantsPage, &apprenants::returnRequested, this, [this]() {
            ui->stackedWidget->setCurrentIndex(1); // Retour au menu (index 2)
            this->setWindowTitle("Menu Principal");
        });
    }
    ui->stackedWidget->setCurrentWidget(m_apprenantsPage);
    // Mettre à jour le titre de la fenêtre
    this->setWindowTitle("Gestion des apprenants");
}

void examens::on_Bvehicule_clicked()
{
    if (!m_vehiculePage) {
        m_vehiculePage = new vehicule();
        ui->stackedWidget->addWidget(m_vehiculePage);
        // Connecter le signal de retour au menu
        connect(m_vehiculePage, &vehicule::returnRequested, this, [this]() {
            ui->stackedWidget->setCurrentIndex(1); // Retour au menu (index 2)
            this->setWindowTitle("Menu Principal");
        });
    }
    ui->stackedWidget->setCurrentWidget(m_vehiculePage);
    // Mettre à jour le titre de la fenêtre
    this->setWindowTitle("Gestion des véhicules");
}

void examens::on_Bpaiement_clicked()
{
    if (!m_paiementPage) {
        m_paiementPage = new MainWindow();
        ui->stackedWidget->addWidget(m_paiementPage);
        connect(m_paiementPage, &MainWindow::returnRequested, this, [this]() {
            ui->stackedWidget->setCurrentIndex(1);
            this->setWindowTitle("Menu Principal");
        });
    }
    ui->stackedWidget->setCurrentWidget(m_paiementPage);
    this->setWindowTitle("Gestion des paiements");
}
void examens::on_Bmoniteurs_clicked()
{
    if (!m_moniteurPage) {
        m_moniteurPage = new moniteur_ui();
        ui->stackedWidget->addWidget(m_moniteurPage);
        // Connecter le signal de retour au menu
        connect(m_moniteurPage, &moniteur_ui::returnRequested, this, [this]() {
            ui->stackedWidget->setCurrentIndex(1); // Retour au menu (index 2)
            this->setWindowTitle("Menu Principal");
        });
    }
    ui->stackedWidget->setCurrentWidget(m_moniteurPage);
    // Mettre à jour le titre de la fenêtre
    this->setWindowTitle("Gestion des moniteurs");
}

void examens::on_pushButton_5_clicked()
{
    Employes *emp = new Employes();  // créer la fenêtre Employes
    emp->show();                     // l'afficher
    this->close();                   // fermer l'actuelle window examens
}

















