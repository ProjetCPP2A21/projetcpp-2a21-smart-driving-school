#include "moniteur_ui.h"
#include "ui_moniteur.h"
#include "moniteur.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QDateTime>
#include <QPageSize>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QWidget>
#include <QScrollArea>
#include <QGraphicsDropShadowEffect>

moniteur_ui::moniteur_ui(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::moniteur),
    m_chartView(nullptr),
    m_statisticsVisible(false)
{
    ui->setupUi(this);
    setWindowTitle("Gestion des moniteurs");
    applyModernStyle();

    if (ui->table) {
        ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->table->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->table->setAlternatingRowColors(true);
        ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
    if (ui->rechercher) {
        ui->rechercher->setPlaceholderText("Rechercher...");
    }

    moniteur::afficherMoniteurs(ui->table);

    connect(ui->ajouter, &QPushButton::clicked, this, &moniteur_ui::onAjouterClicked);
    connect(ui->modifier, &QPushButton::clicked, this, &moniteur_ui::onModifierClicked);
    connect(ui->suprimer, &QPushButton::clicked, this, &moniteur_ui::onSupprimerClicked);
    connect(ui->pdf, &QPushButton::clicked, this, &moniteur_ui::onExporterPdfClicked);
    connect(ui->stat, &QPushButton::clicked, this, &moniteur_ui::onStatistiquesClicked);
    connect(ui->tri, &QPushButton::clicked, this, &moniteur_ui::onTriClicked);
    connect(ui->rechercher, &QLineEdit::textChanged, this, &moniteur_ui::onRechercheTextChanged);
    
    // Connecter le bouton Taux de Réussite
    if (ui->tauxReussite) {
        connect(ui->tauxReussite, &QPushButton::clicked, this, &moniteur_ui::onTauxReussiteClicked);
    }
    
    // Connecter le bouton Affecter Véhicule
    if (ui->affecterVehicule) {
        connect(ui->affecterVehicule, &QPushButton::clicked, this, &moniteur_ui::onAffecterVehiculeClicked);
    }
    
    // Connecter le bouton Retour
    if (ui->Retour) {
        connect(ui->Retour, &QPushButton::clicked, this, &moniteur_ui::onRetourClicked);
    }
}

moniteur_ui::~moniteur_ui() {
    if (m_chartView) {
        delete m_chartView;
        m_chartView = nullptr;
    }
    delete ui;
}

void moniteur_ui::resetFields() {
    ui->ID->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->telephone->clear();
    ui->spec->setCurrentIndex(0);
    ui->disp->setCurrentIndex(0);
    ui->heur->setValue(0);
}

bool moniteur_ui::checkFields() {
    QRegularExpression regexNum("^[0-9]+$");
    QRegularExpression regexAlpha("^[A-Za-z\\s]+$");

    if (ui->ID->text().isEmpty() || !regexNum.match(ui->ID->text()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "ID invalide.");
        return false;
    }
    if (ui->nom->text().isEmpty() || !regexAlpha.match(ui->nom->text()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Nom invalide.");
        return false;
    }
    if (ui->prenom->text().isEmpty() || !regexAlpha.match(ui->prenom->text()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Prénom invalide.");
        return false;
    }
    if (ui->telephone->text().isEmpty() || !regexNum.match(ui->telephone->text()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Téléphone invalide.");
        return false;
    }
    return true;
}

void moniteur_ui::onAjouterClicked() {
    if (!checkFields()) return;
    if (moniteur::ajouterMoniteur(ui)) {
        QMessageBox::information(this, "Ajout", "Moniteur ajouté !");
        moniteur::afficherMoniteurs(ui->table);
        resetFields();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du moniteur.");
    }
}

void moniteur_ui::onModifierClicked() {
    // ✅ Vérifier que l'ID est saisi (obligatoire pour identifier le moniteur)
    QString idText = ui->ID->text().trimmed();
    if (idText.isEmpty()) {
        QMessageBox::warning(this, "Erreur", 
            "Veuillez entrer l'ID du moniteur à modifier !");
        return;
    }
    
    int idMoniteur = idText.toInt();
    if (idMoniteur <= 0) {
        QMessageBox::warning(this, "Erreur", "ID de moniteur non valide !");
        return;
    }
    
    // ✅ Vérifier que le moniteur existe
    QSqlQuery checkQuery(QSqlDatabase::database("oracle_connection"));
    checkQuery.prepare("SELECT ID, NOM, PRENOM FROM MONITEUR WHERE ID = :id");
    checkQuery.bindValue(":id", idMoniteur);
    
    if (!checkQuery.exec() || !checkQuery.next()) {
        QMessageBox::critical(this, "Erreur", 
            QString("Le moniteur avec l'ID %1 n'existe pas dans la base de données !").arg(idMoniteur));
        return;
    }
    
    QString nomExistant = checkQuery.value(1).toString();
    QString prenomExistant = checkQuery.value(2).toString();
    
    // ✅ Récupérer uniquement les champs remplis (modification partielle)
    QStringList updates;
    QVariantList values;
    
    QString nom = ui->nom->text().trimmed();
    if (!nom.isEmpty()) {
        updates << "NOM = :nom";
        values << nom;
    }
    
    QString prenom = ui->prenom->text().trimmed();
    if (!prenom.isEmpty()) {
        updates << "PRENOM = :prenom";
        values << prenom;
    }
    
    QString telephone = ui->telephone->text().trimmed();
    if (!telephone.isEmpty()) {
        // Vérifier le format du téléphone si rempli
        QRegularExpression regexNum("^[0-9]{8}$");
        if (!regexNum.match(telephone).hasMatch()) {
            QMessageBox::warning(this, "Erreur", "Format de téléphone invalide (8 chiffres requis).");
            return;
        }
        updates << "TELEPHONE = :telephone";
        values << telephone;
    }
    
    QString specialite = ui->spec->currentText().trimmed();
    if (!specialite.isEmpty() && specialite != "Sélectionner") {
        updates << "SPECIALITE = :specialite";
        values << specialite;
    }
    
    QString disponibilite = ui->disp->currentText().trimmed();
    if (!disponibilite.isEmpty() && disponibilite != "Sélectionner") {
        updates << "DISPONIBILITE = :disponibilite";
        values << disponibilite;
    }
    
    // Pour les heures de travail, vérifier si la valeur a changé (différente de 0 ou valeur par défaut)
    if (ui->heur && ui->heur->value() > 0) {
        updates << "HEURES_TRAVAIL = :heures";
        values << ui->heur->value();
    }
    
    // ✅ Vérifier qu'au moins un champ a été modifié
    if (updates.isEmpty()) {
        QMessageBox::information(this, "Information", 
            "Aucun champ à modifier. Veuillez remplir au moins un champ avant de cliquer sur Modifier.");
        return;
    }
    
    // ⚠️ Demander confirmation avant modification
    QString champsModifies = updates.join(", ").replace(" = :", " : ");
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,
                                  "Confirmation",
                                  QString("Voulez-vous vraiment modifier le moniteur ID %1 (%2 %3) ?\n\n"
                                         "Champs à modifier :\n%4")
                                  .arg(idMoniteur).arg(nomExistant).arg(prenomExistant).arg(champsModifies),
                                  QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::No) {
        return;
    }
    
    // ✅ Construire et exécuter la requête UPDATE dynamique
    QString sqlQuery = "UPDATE MONITEUR SET " + updates.join(", ") + " WHERE ID = :id";
    QSqlQuery query(QSqlDatabase::database("oracle_connection"));
    query.prepare(sqlQuery);
    
    // Bind les valeurs
    int paramIndex = 0;
    if (!nom.isEmpty()) {
        query.bindValue(":nom", nom);
        paramIndex++;
    }
    if (!prenom.isEmpty()) {
        query.bindValue(":prenom", prenom);
        paramIndex++;
    }
    if (!telephone.isEmpty()) {
        query.bindValue(":telephone", telephone);
        paramIndex++;
    }
    if (!specialite.isEmpty() && specialite != "Sélectionner") {
        query.bindValue(":specialite", specialite);
        paramIndex++;
    }
    if (!disponibilite.isEmpty() && disponibilite != "Sélectionner") {
        query.bindValue(":disponibilite", disponibilite);
        paramIndex++;
    }
    if (ui->heur && ui->heur->value() > 0) {
        query.bindValue(":heures", ui->heur->value());
        paramIndex++;
    }
    
    query.bindValue(":id", idMoniteur);
    
    if (query.exec()) {
        int rowsAffected = query.numRowsAffected();
        if (rowsAffected > 0) {
            QMessageBox::information(this, "Succès", 
                QString("Moniteur ID %1 modifié avec succès !\n%2 champ(s) mis à jour.")
                .arg(idMoniteur).arg(updates.count()));
            moniteur::afficherMoniteurs(ui->table);  // 🔄 Rafraîchir le tableau
            resetFields();   // 🧹 Vider les champs après modification
            ui->table->clearSelection(); // 🔁 Réinitialiser la sélection
        } else {
            QMessageBox::warning(this, "Avertissement", 
                "Aucune modification effectuée. Le moniteur existe mais les valeurs sont peut-être identiques.");
        }
    } else {
        QMessageBox::critical(this, "Erreur", 
            "Échec de la modification dans la base de données !\n" + query.lastError().text());
    }
}

void moniteur_ui::onSupprimerClicked() {
    if (ui->ID->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer l'ID !");
        return;
    }
    
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmer", "Voulez-vous vraiment supprimer ce moniteur ?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        if (moniteur::supprimerMoniteur(ui)) {
            QMessageBox::information(this, "Suppression", "Moniteur supprimé !");
            moniteur::afficherMoniteurs(ui->table);
            resetFields();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
        }
    }
}

void moniteur_ui::onExporterPdfClicked() {
    // Vérifier qu'il y a des données à exporter
    if (ui->table->rowCount() == 0) {
        QMessageBox::warning(this, "Avertissement", "Aucun moniteur à exporter !");
        return;
    }
    
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF",
                                                    "moniteurs_" + QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss") + ".pdf",
                                                    "PDF Files (*.pdf)");
    if (fileName.isEmpty()) {
        return;
    }
    
    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive)) {
        fileName += ".pdf";
    }
    
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(15, 15, 15, 15), QPageLayout::Millimeter);
    
    // Construction du HTML avec style moderne
    QString html;
    html += "<html><head>";
    html += "<meta charset='utf-8'>";
    html += "<style>"
            "body {"
            "    font-family: 'Segoe UI', Arial, Helvetica, sans-serif;"
            "    color: #2c3e50;"
            "    margin: 0;"
            "    padding: 20px;"
            "}"
            "h1 {"
            "    font-size: 28px;"
            "    text-align: center;"
            "    margin: 0 0 10px 0;"
            "    color: #185a9d;"
            "    font-weight: bold;"
            "    text-shadow: 2px 2px 4px rgba(0,0,0,0.1);"
            "}"
            ".date {"
            "    font-size: 12px;"
            "    text-align: center;"
            "    margin-bottom: 20px;"
            "    color: #7f8c8d;"
            "    font-style: italic;"
            "}"
            ".info {"
            "    text-align: center;"
            "    margin-bottom: 25px;"
            "    color: #34495e;"
            "    font-size: 14px;"
            "}"
            "table {"
            "    width: 100%;"
            "    margin: 0 auto;"
            "    border-collapse: collapse;"
            "    table-layout: fixed;"
            "    box-shadow: 0 2px 8px rgba(0,0,0,0.1);"
            "}"
            "th {"
            "    background: linear-gradient(135deg, #43cea2 0%, #185a9d 100%);"
            "    color: white;"
            "    font-weight: bold;"
            "    text-align: center;"
            "    padding: 12px 8px;"
            "    font-size: 12px;"
            "    border: 1px solid #144d7e;"
            "    text-transform: uppercase;"
            "    letter-spacing: 0.5px;"
            "}"
            "td {"
            "    border: 1px solid #ddd;"
            "    padding: 10px 8px;"
            "    font-size: 11px;"
            "    text-align: left;"
            "    vertical-align: middle;"
            "    word-break: break-word;"
            "}"
            "tr:nth-child(even) {"
            "    background-color: #f8f9fa;"
            "}"
            "tr:nth-child(odd) {"
            "    background-color: #ffffff;"
            "}"
            ".footer {"
            "    margin-top: 30px;"
            "    text-align: center;"
            "    font-size: 10px;"
            "    color: #95a5a6;"
            "    border-top: 2px solid #ecf0f1;"
            "    padding-top: 10px;"
            "}"
            "</style>";
    html += "</head><body>";
    
    // Titre
    html += "<h1>📋 Liste des Moniteurs</h1>";
    
    // Date et informations
    html += "<div class='date'>📅 Date d'exportation: " + QDateTime::currentDateTime().toString("dd/MM/yyyy à hh:mm") + "</div>";
    html += "<div class='info'>📊 Nombre total de moniteurs: <strong>" + QString::number(ui->table->rowCount()) + "</strong></div>";
    
    // Tableau
    html += "<table>";
    html += "<thead><tr>"
            "<th style='width:8%'>ID</th>"
            "<th style='width:15%'>Nom</th>"
            "<th style='width:15%'>Prénom</th>"
            "<th style='width:12%'>Téléphone</th>"
            "<th style='width:15%'>Spécialité</th>"
            "<th style='width:15%'>Disponibilité</th>"
            "<th style='width:10%'>Heures</th>"
            "</tr></thead><tbody>";
    
    // Remplir le tableau avec les données
    for (int row = 0; row < ui->table->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < ui->table->columnCount(); ++col) {
            QTableWidgetItem *item = ui->table->item(row, col);
            QString cellText = item ? item->text() : "";
            
            // Style spécial pour certaines colonnes
            QString cellStyle = "";
            if (col == 0) { // ID
                cellStyle = "text-align:center; font-weight:bold; color:#185a9d;";
            } else if (col == 4) { // Spécialité
                if (cellText.toLower().contains("code")) {
                    cellStyle = "color:#27ae60; font-weight:bold;";
                } else if (cellText.toLower().contains("conduite")) {
                    cellStyle = "color:#3498db; font-weight:bold;";
                }
            } else if (col == 5) { // Disponibilité
                if (cellText.toLower().contains("disponible")) {
                    cellStyle = "color:#27ae60; font-weight:bold;";
                } else {
                    cellStyle = "color:#e74c3c; font-weight:bold;";
                }
            } else if (col == 6) { // Heures
                cellStyle = "text-align:center;";
                int heures = cellText.toInt();
                if (heures >= 20) {
                    cellStyle += "color:#e74c3c; font-weight:bold;";
                } else if (heures >= 15) {
                    cellStyle += "color:#f39c12; font-weight:bold;";
                } else {
                    cellStyle += "color:#27ae60;";
                }
            }
            
            html += QString("<td style='%1'>%2</td>").arg(cellStyle, cellText.isEmpty() ? "&nbsp;" : cellText);
        }
        html += "</tr>";
    }
    
    html += "</tbody></table>";
    
    // Pied de page
    html += "<div class='footer'>"
            "Document généré par le système de gestion des moniteurs<br>"
            "© " + QDateTime::currentDateTime().toString("yyyy") + " - Tous droits réservés"
            "</div>";
    
    html += "</body></html>";
    
    // Créer le document et exporter
    QTextDocument doc;
    doc.setHtml(html);
    doc.print(&printer);
    
    QMessageBox::information(this, "Export Réussi", 
        "Les données ont été exportées avec succès dans :\n" + fileName);
}

void moniteur_ui::onRechercheTextChanged(const QString &text) {
    for (int row = 0; row < ui->table->rowCount(); ++row) {
        bool match = false;
        for (int col = 0; col < ui->table->columnCount(); ++col) {
            QTableWidgetItem *item = ui->table->item(row, col);
            if (item && item->text().contains(text, Qt::CaseInsensitive)) {
                match = true;
                break;
            }
        }
        ui->table->setRowHidden(row, !match);
    }
}

void moniteur_ui::onTriClicked() {
    ui->table->setSortingEnabled(true);
    ui->table->sortItems(1, Qt::AscendingOrder);
    QMessageBox::information(this, "Tri", "Tri par Nom effectué !");
}

void moniteur_ui::onStatistiquesClicked() {
    // Basculer l'affichage des statistiques
    if (m_statisticsVisible) {
        hideStatistics();
    } else {
        showStatistics();
    }
}

void moniteur_ui::showStatistics() {
    // ---------------- Récupération des statistiques depuis la base de données ----------------
    QSqlQuery query(QSqlDatabase::database("oracle_connection"));
    query.prepare("SELECT SPECIALITE, COUNT(*) FROM MONITEUR GROUP BY SPECIALITE");
    
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur",
                              "Impossible de récupérer les statistiques : " + query.lastError().text());
        return;
    }
    
    // ✅ Normalisation des spécialités pour éviter les doublons
    QMap<QString, int> stats;
    int total = 0;
    
    while (query.next()) {
        QString specialite = query.value(0).toString().trimmed().toLower();
        int count = query.value(1).toInt();
        
        // Normaliser les variations de "Code" et "Conduite"
        QString normalizedSpec;
        if (specialite.contains("code")) {
            normalizedSpec = "Code";
        } else if (specialite.contains("conduite")) {
            normalizedSpec = "Conduite";
        } else {
            // Pour les autres spécialités, capitaliser la première lettre
            normalizedSpec = specialite.isEmpty() ? "Autre" : specialite;
            normalizedSpec[0] = normalizedSpec[0].toUpper();
        }
        
        // Regrouper les spécialités normalisées
        if (stats.contains(normalizedSpec)) {
            stats[normalizedSpec] += count;
        } else {
            stats[normalizedSpec] = count;
        }
        total += count;
    }
    
    if (total == 0) {
        QMessageBox::information(this, "Info", "Aucun moniteur trouvé !");
        return;
    }
    
    // ---------------- Création de la série (donut chart) ----------------
    QPieSeries* series = new QPieSeries();
    series->setHoleSize(0.35);   // Donut moderne
    
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        double pourcentage = (it.value() * 100.0) / total;
        QString label = it.key() + " (" + QString::number(it.value()) +
                        ") : " + QString::number(pourcentage, 'f', 1) + "%";
        
        QPieSlice* slice = series->append(label, it.value());
        slice->setLabelVisible(true);
        
        // 🎨 Couleurs personnalisées selon la spécialité
        QString specLower = it.key().toLower();
        if (specLower.contains("code")) {
            slice->setBrush(QColor("#43cea2"));   // vert
        } else if (specLower.contains("conduite")) {
            slice->setBrush(QColor("#185a9d"));   // bleu
        } else if (specLower.contains("pratique")) {
            slice->setBrush(QColor("#f1c40f"));   // jaune
        } else {
            slice->setBrush(QColor("#e74c3c"));   // rouge par défaut
        }
        
        // ✨ Animation explosion
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
    
    // Fond transparent
    chart->setBackgroundVisible(false);
    chart->setPlotAreaBackgroundVisible(false);
    
    // 🎯 Titre stylé (minimisé pour s'adapter à la taille réduite)
    chart->setTitle("📊 Répartition par Spécialité");
    chart->setTitleFont(QFont("Segoe UI", 10, QFont::Bold));
    chart->setTitleBrush(QBrush(QColor("#ffffff")));
    
    // 📝 Légendes modernes (très compactes)
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->legend()->setFont(QFont("Segoe UI", 8, QFont::Normal));
    chart->legend()->setLabelColor(QColor("#ffffff"));
    chart->legend()->setBackgroundVisible(false); // Fond transparent pour la légende
    chart->legend()->setContentsMargins(0, 0, 0, 0); // Marges minimales
    
    // ---------------- Création/Affichage du QChartView ----------------
    if (m_chartView) {
        delete m_chartView;
        m_chartView = nullptr;
    }
    
    m_chartView = new QChartView(chart, ui->centralwidget);
    m_chartView->setRenderHint(QPainter::Antialiasing);
    // Taille minimisée pour s'adapter à l'écran
    m_chartView->setFixedSize(350, 250);
    // Fond complètement transparent (sans background)
    m_chartView->setStyleSheet(
        "QChartView {"
        "    background: transparent; "
        "    border: none; "
        "}"
    );
    // Fond transparent pour le widget
    m_chartView->setAttribute(Qt::WA_TranslucentBackground, true);
    
    // Positionner le graphique sous les boutons (y = 480 environ, après les boutons à y=430)
    // et centré horizontalement
    int xPos = (this->width() - 350) / 2;
    if (xPos < 0) xPos = 30; // Marge minimale
    int yPos = 485; // Sous les boutons, légèrement plus bas
    m_chartView->move(xPos, yPos);
    m_chartView->show();
    m_chartView->raise(); // Mettre au premier plan
    m_statisticsVisible = true;
    
    // Pas besoin d'ajuster la taille de la fenêtre, le graphique est maintenant assez petit
}

void moniteur_ui::hideStatistics() {
    if (m_chartView) {
        m_chartView->hide();
        m_statisticsVisible = false;
        // Pas besoin de réduire la taille de la fenêtre car le graphique est maintenant très petit
    }
}

void moniteur_ui::onRetourClicked() {
    emit returnRequested();
}

void moniteur_ui::applyModernStyle() {
    QString s;
    s += "QMainWindow { background-color: #f7f9fc; }";
    s += "QPushButton { background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #43cea2, stop:1 #185a9d); color: white; border: none; border-radius: 8px; padding: 8px 16px; font-weight: bold; }";
    s += "QPushButton:hover { background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #2ebf91, stop:1 #0f2027); }";
    s += "QLineEdit, QComboBox { border: 1px solid #ccd; border-radius: 6px; padding: 6px 10px; background: white; }";
    s += "QTableWidget { background: white; border: 1px solid #e0e0e0; border-radius: 8px; }";
    s += "QHeaderView::section { background-color: #185a9d; color: white; padding: 8px; border: none; font-weight: bold; }";
    setStyleSheet(s);
}

void moniteur_ui::onTauxReussiteClicked() {
    // Créer un dialog pour afficher les résultats
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Taux de Réussite par Moniteur");
    dialog->setMinimumSize(800, 500);
    
    QVBoxLayout *mainLayout = new QVBoxLayout(dialog);
    
    // Titre
    QLabel *titleLabel = new QLabel("📊 Taux de Réussite des Moniteurs", dialog);
    titleLabel->setStyleSheet("font-size: 16pt; font-weight: bold; color: #185a9d; padding: 10px;");
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);
    
    // Tableau pour afficher les résultats
    QTableWidget *resultTable = new QTableWidget(dialog);
    resultTable->setColumnCount(6);
    resultTable->setHorizontalHeaderLabels(QStringList() << "ID Moniteur" << "Nom" << "Prénom" 
                                                          << "Total Examens" << "Examens Réussis" << "Taux de Réussite (%)");
    resultTable->horizontalHeader()->setStretchLastSection(true);
    resultTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    resultTable->setAlternatingRowColors(true);
    resultTable->setStyleSheet(
        "QTableWidget {"
        "    border: 2px solid #43cea2;"
        "    border-radius: 8px;"
        "    background-color: white;"
        "}"
        "QHeaderView::section {"
        "    background-color: #185a9d;"
        "    color: white;"
        "    padding: 8px;"
        "    font-weight: bold;"
        "    border: none;"
        "}"
        "QTableWidget::item {"
        "    padding: 5px;"
        "}"
    );
    
    // Structure réelle de la base de données selon les schémas fournis :
    // - MONITEUR (ID, NOM, PRENOM, ...)
    // - APPRENANTS (ID_APPRENANT, NOM, PRENOM, ...) - PAS de ID_MONITEUR directement
    // - EXAMEN (ID_EXAMEN, RESULTAT, ...) - PAS de ID_APPRENANT directement
    // - PASSER (ID_APPRENANT, ID_EXAMEN) : table de liaison entre APPRENANTS et EXAMEN
    // - AFFECTER (ID_MONITEUR, IMMATRICULATION) : lie MONITEUR aux véhicules
    
    QSqlDatabase db = QSqlDatabase::database("oracle_connection");
    QStringList tables = db.tables();
    
    // Vérifier l'existence des tables
    QString tableExamen, tableApprenant, tablePasser;
    
    for (const QString &table : tables) {
        QString tableUpper = table.toUpper();
        if (tableUpper == "EXAMEN" || tableUpper == "EXAMENS") {
            tableExamen = table;
        }
        if (tableUpper == "APPRENANT" || tableUpper == "APPRENANTS") {
            tableApprenant = table;
        }
        if (tableUpper == "PASSER") {
            tablePasser = table;
        }
    }
    
    // Utiliser les noms par défaut si non trouvés
    if (tableExamen.isEmpty()) tableExamen = "EXAMEN";
    if (tableApprenant.isEmpty()) tableApprenant = "APPRENANTS";
    if (tablePasser.isEmpty()) tablePasser = "PASSER";
    
    qDebug() << "Tables détectées - EXAMEN:" << tableExamen 
             << ", APPRENANTS:" << tableApprenant 
             << ", PASSER:" << tablePasser;
    
    QSqlRecord apprenantRecord;
    {
        QSqlQuery colQ(QSqlDatabase::database("oracle_connection"));
        colQ.prepare(QString("SELECT * FROM %1 WHERE 1=0").arg(tableApprenant));
        colQ.exec();
        apprenantRecord = colQ.record();
    }
    QStringList apprenantColumns;
    for (int i = 0; i < apprenantRecord.count(); ++i) {
        apprenantColumns << apprenantRecord.fieldName(i).toUpper();
    }
    
    qDebug() << "Colonnes APPRENANTS:" << apprenantColumns;
    
    QString sqlQuery;
    QSqlQuery query(QSqlDatabase::database("oracle_connection"));
    
    // Construire la requête selon la structure détectée
    // Si APPRENANTS a ID_MONITEUR : MONITEUR → APPRENANTS → PASSER → EXAMEN
    if (apprenantColumns.contains("ID_MONITEUR")) {
        sqlQuery = QString(
            "SELECT "
            "    M.ID, "
            "    M.NOM, "
            "    M.PRENOM, "
            "    COUNT(DISTINCT E.ID_EXAMEN) AS TOTAL_EXAMENS, "
            "    SUM(CASE WHEN UPPER(TRIM(E.RESULTAT)) = 'ADMIS' THEN 1 ELSE 0 END) AS EXAMENS_REUSSIS "
            "FROM MONITEUR M "
            "LEFT JOIN %1 A ON A.ID_MONITEUR = M.ID "
            "LEFT JOIN %2 P ON P.ID_APPRENANT = A.ID_APPRENANT "
            "LEFT JOIN %3 E ON E.ID_EXAMEN = P.ID_EXAMEN "
            "GROUP BY M.ID, M.NOM, M.PRENOM "
            "ORDER BY M.ID"
        ).arg(tableApprenant, tablePasser, tableExamen);
        
        qDebug() << "✓ Structure détectée : APPRENANTS a ID_MONITEUR";
        qDebug() << "Requête SQL construite avec succès";
    } else {
        // Si APPRENANTS n'a pas ID_MONITEUR, on doit trouver une autre relation
        // Vérifier s'il y a une table de liaison entre MONITEUR et APPRENANTS
        QString tableLiaison;
        for (const QString &table : tables) {
            QString tableUpper = table.toUpper();
            QSqlRecord record = db.record(table);
            QStringList columns;
            for (int i = 0; i < record.count(); ++i) {
                columns << record.fieldName(i).toUpper();
            }
            
            // Chercher une table qui a à la fois ID_MONITEUR et ID_APPRENANT
            if (columns.contains("ID_MONITEUR") && columns.contains("ID_APPRENANT")) {
                tableLiaison = table;
                qDebug() << "Table de liaison trouvée:" << tableLiaison;
                break;
            }
        }
        
        if (!tableLiaison.isEmpty()) {
            // Utiliser la table de liaison
            sqlQuery = QString(
                "SELECT "
                "    M.ID, "
                "    M.NOM, "
                "    M.PRENOM, "
                "    COUNT(DISTINCT E.ID_EXAMEN) AS TOTAL_EXAMENS, "
                "    SUM(CASE WHEN UPPER(TRIM(E.RESULTAT)) = 'ADMIS' THEN 1 ELSE 0 END) AS EXAMENS_REUSSIS "
                "FROM MONITEUR M "
                "LEFT JOIN %1 L ON L.ID_MONITEUR = M.ID "
                "LEFT JOIN %2 A ON A.ID_APPRENANT = L.ID_APPRENANT "
                "LEFT JOIN %3 P ON P.ID_APPRENANT = A.ID_APPRENANT "
                "LEFT JOIN %4 E ON E.ID_EXAMEN = P.ID_EXAMEN "
                "GROUP BY M.ID, M.NOM, M.PRENOM "
                "ORDER BY M.ID"
            ).arg(tableLiaison, tableApprenant, tablePasser, tableExamen);
        } else {
            // Si aucune table de liaison n'est trouvée, chercher ENSEIGNEMENT ou autres tables possibles
            QStringList possibleLiaisonTables;
            for (const QString &table : tables) {
                QString tableUpper = table.toUpper();
                if (tableUpper == "ENSEIGNEMENT" || 
                    tableUpper == "COURS" || 
                    tableUpper == "AFFECTATION" ||
                    tableUpper == "ENCADREMENT") {
                    QSqlRecord record = db.record(table);
                    QStringList columns;
                    for (int i = 0; i < record.count(); ++i) {
                        columns << record.fieldName(i).toUpper();
                    }
                    if (columns.contains("ID_MONITEUR") && columns.contains("ID_APPRENANT")) {
                        possibleLiaisonTables << table;
                    }
                }
            }
            
            if (!possibleLiaisonTables.isEmpty()) {
                // Utiliser la première table de liaison trouvée
                QString tableLiaison = possibleLiaisonTables.first();
                sqlQuery = QString(
                    "SELECT "
                    "    M.ID, "
                    "    M.NOM, "
                    "    M.PRENOM, "
                    "    COUNT(DISTINCT E.ID_EXAMEN) AS TOTAL_EXAMENS, "
                    "    SUM(CASE WHEN UPPER(TRIM(E.RESULTAT)) = 'ADMIS' THEN 1 ELSE 0 END) AS EXAMENS_REUSSIS "
                    "FROM MONITEUR M "
                    "LEFT JOIN %1 L ON L.ID_MONITEUR = M.ID "
                    "LEFT JOIN %2 A ON A.ID_APPRENANT = L.ID_APPRENANT "
                    "LEFT JOIN %3 P ON P.ID_APPRENANT = A.ID_APPRENANT "
                    "LEFT JOIN %4 E ON E.ID_EXAMEN = P.ID_EXAMEN "
                    "GROUP BY M.ID, M.NOM, M.PRENOM "
                    "ORDER BY M.ID"
                ).arg(tableLiaison, tableApprenant, tablePasser, tableExamen);
            } else {
                // Si aucune relation n'est trouvée, afficher un message d'erreur avec instructions
                QMessageBox msgBox(this);
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.setWindowTitle("Structure de base de données");
                msgBox.setText("Impossible de calculer le taux de réussite.");
                msgBox.setInformativeText(
                    "La table APPRENANTS n'a pas de colonne ID_MONITEUR et aucune table de liaison n'a été trouvée.\n\n"
                    "SOLUTION : Exécutez le fichier SQL 'fix_taux_reussite.sql' dans votre base de données.\n\n"
                    "Ce fichier contient 3 solutions possibles :\n"
                    "1. Ajouter ID_MONITEUR à APPRENANTS (simple)\n"
                    "2. Créer une table ENSEIGNEMENT (recommandé)\n"
                    "3. Utiliser la table AFFECTER existante\n\n"
                    "Le fichier se trouve dans :\n"
                    "louz5 le5er (1)/louz5/interapp/fix_taux_reussite.sql"
                );
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.exec();
                delete dialog;
                return;
            }
        }
    }
    
    // Vérifier que la requête a été construite
    if (sqlQuery.isEmpty()) {
        QMessageBox::critical(this, "Erreur", 
            "Impossible de construire la requête SQL.\n\n"
            "Vérifiez que la colonne ID_MONITEUR existe bien dans la table APPRENANTS.\n"
            "Si vous venez de l'ajouter, redémarrez l'application.");
        delete dialog;
        return;
    }
    
    qDebug() << "Requête SQL exécutée:" << sqlQuery;
    
    // Exécuter la requête
    if (!query.exec(sqlQuery)) {
        QString errorText = query.lastError().text();
        qDebug() << "Erreur SQL:" << errorText;
        QMessageBox::critical(this, "Erreur SQL", 
            "Impossible de calculer le taux de réussite.\n\n"
            "Erreur SQL: " + errorText + "\n\n"
            "Vérifications à faire :\n"
            "1. La colonne ID_MONITEUR existe dans APPRENANTS\n"
            "2. Les tables PASSER et EXAMEN existent\n"
            "3. Les données sont correctement liées\n\n"
            "Consultez les logs pour plus de détails.");
        delete dialog;
        return;
    }
    
    // Remplir le tableau avec les résultats
    int row = 0;
    while (query.next()) {
        int idMoniteur = query.value(0).toInt();
        QString nom = query.value(1).toString();
        QString prenom = query.value(2).toString();
        int totalExamens = query.value(3).toInt();
        int examensReussis = query.value(4).toInt();
        
        // Calculer le taux de réussite
        double tauxReussite = 0.0;
        if (totalExamens > 0) {
            tauxReussite = (static_cast<double>(examensReussis) / totalExamens) * 100.0;
        }
        
        resultTable->insertRow(row);
        resultTable->setItem(row, 0, new QTableWidgetItem(QString::number(idMoniteur)));
        resultTable->setItem(row, 1, new QTableWidgetItem(nom));
        resultTable->setItem(row, 2, new QTableWidgetItem(prenom));
        resultTable->setItem(row, 3, new QTableWidgetItem(QString::number(totalExamens)));
        resultTable->setItem(row, 4, new QTableWidgetItem(QString::number(examensReussis)));
        
        QTableWidgetItem *tauxItem = new QTableWidgetItem(QString::number(tauxReussite, 'f', 2) + "%");
        // Colorier selon le taux de réussite
        if (tauxReussite >= 80) {
            tauxItem->setBackground(QColor(76, 175, 80)); // Vert
            tauxItem->setForeground(Qt::white);
        } else if (tauxReussite >= 60) {
            tauxItem->setBackground(QColor(255, 193, 7)); // Jaune
            tauxItem->setForeground(Qt::black);
        } else {
            tauxItem->setBackground(QColor(244, 67, 54)); // Rouge
            tauxItem->setForeground(Qt::white);
        }
        resultTable->setItem(row, 5, tauxItem);
        
        row++;
    }
    
    if (row == 0) {
        QMessageBox::information(this, "Information", 
            "Aucune donnée trouvée.\n"
            "Assurez-vous que les tables sont correctement liées dans la base de données.");
        delete dialog;
        return;
    }
    
    resultTable->resizeColumnsToContents();
    mainLayout->addWidget(resultTable);
    
    // Bouton de fermeture
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    QPushButton *closeButton = new QPushButton("Fermer", dialog);
    closeButton->setStyleSheet(
        "QPushButton {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #43cea2, stop:1 #185a9d);"
        "    color: white;"
        "    border-radius: 8px;"
        "    padding: 10px 30px;"
        "    font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #2ebf91, stop:1 #0f2027);"
        "}"
    );
    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);
    buttonLayout->addWidget(closeButton);
    buttonLayout->addStretch();
    mainLayout->addLayout(buttonLayout);
    
    dialog->exec();
    delete dialog;
}

void moniteur_ui::onAffecterVehiculeClicked() {
    // Vérifier qu'un moniteur est sélectionné
    if (ui->ID->text().isEmpty()) {
        QMessageBox::warning(this, "Sélection requise", 
            "Veuillez sélectionner un moniteur en entrant son ID ou en cliquant sur une ligne du tableau.");
        return;
    }
    
    int idMoniteur = ui->ID->text().toInt();
    if (idMoniteur <= 0) {
        QMessageBox::warning(this, "ID invalide", "L'ID du moniteur doit être un nombre positif.");
        return;
    }
    
    QSqlDatabase db = QSqlDatabase::database("oracle_connection");
    QSqlQuery query(db);
    
    // 1. Vérifier que le moniteur existe et récupérer ses informations
    query.prepare("SELECT ID, NOM, PRENOM, DISPONIBILITE, HEURES_TRAVAIL FROM MONITEUR WHERE ID = :id");
    query.bindValue(":id", idMoniteur);
    
    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Erreur", 
            "Le moniteur avec l'ID " + QString::number(idMoniteur) + " n'existe pas.");
        return;
    }
    
    QString nomMoniteur = query.value(1).toString();
    QString prenomMoniteur = query.value(2).toString();
    QString disponibilite = query.value(3).toString();
    int heuresTravail = query.value(4).toInt();
    
    // 2. Vérifier la disponibilité du moniteur
    QString disponibiliteUpper = disponibilite.toUpper().trimmed();
    // Accepter différentes variantes de "Disponible"
    if (!disponibiliteUpper.contains("DISPONIBLE", Qt::CaseInsensitive) && 
        disponibiliteUpper != "OUI" && 
        disponibiliteUpper != "YES") {
        QMessageBox::warning(this, "Moniteur non disponible", 
            QString("Le moniteur %1 %2 n'est pas disponible.\nDisponibilité actuelle: %3\n\n"
                   "Un moniteur doit être disponible pour recevoir un véhicule.")
            .arg(nomMoniteur, prenomMoniteur, disponibilite));
        return;
    }
    
    // 3. Vérifier que les heures de travail ne dépassent pas 20h
    if (heuresTravail >= 20) {
        QMessageBox::warning(this, "Heures de travail dépassées", 
            QString("Le moniteur %1 %2 a déjà %3 heures de travail.\n"
                   "La limite est de 20 heures par semaine.")
            .arg(nomMoniteur, prenomMoniteur, QString::number(heuresTravail)));
        return;
    }
    
    // 4. Vérifier si le moniteur a déjà un véhicule affecté
    query.prepare("SELECT COUNT(*) FROM AFFECTER WHERE ID_MONITEUR = :id");
    query.bindValue(":id", idMoniteur);
    if (query.exec() && query.next()) {
        int nbAffectations = query.value(0).toInt();
        if (nbAffectations > 0) {
            int reponse = QMessageBox::question(this, "Véhicule déjà affecté", 
                QString("Le moniteur %1 %2 a déjà un véhicule affecté.\n"
                       "Voulez-vous le remplacer par un nouveau véhicule ?")
                .arg(nomMoniteur, prenomMoniteur),
                QMessageBox::Yes | QMessageBox::No);
            
            if (reponse == QMessageBox::No) {
                return;
            }
            
            // Supprimer l'ancienne affectation
            query.prepare("DELETE FROM AFFECTER WHERE ID_MONITEUR = :id");
            query.bindValue(":id", idMoniteur);
            if (!query.exec()) {
                QMessageBox::critical(this, "Erreur", 
                    "Impossible de supprimer l'ancienne affectation.\n" + query.lastError().text());
                return;
            }
        }
    }
    
    // 5. Trouver un véhicule disponible et en bon état
    // Chercher d'abord les véhicules non affectés
    query.prepare(
        "SELECT IMMATRICULATION, MARQUE, TYPE_VEHICULE, ETAT, DISPONIBILITE "
        "FROM VEHICULES V "
        "WHERE UPPER(TRIM(V.DISPONIBILITE)) LIKE '%DISPONIBLE%' "
        "AND (UPPER(TRIM(V.ETAT)) LIKE '%BON%' OR UPPER(TRIM(V.ETAT)) = 'EXCELLENT' OR UPPER(TRIM(V.ETAT)) LIKE '%EXCELLENT%') "
        "AND NOT EXISTS (SELECT 1 FROM AFFECTER A WHERE A.IMMATRICULATION = V.IMMATRICULATION) "
        "AND ROWNUM = 1 "
        "ORDER BY CASE WHEN UPPER(TRIM(V.ETAT)) = 'EXCELLENT' THEN 1 WHEN UPPER(TRIM(V.ETAT)) LIKE '%BON%' THEN 2 ELSE 3 END"
    );
    
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", 
            "Erreur lors de la recherche d'un véhicule disponible.\n" + query.lastError().text());
        return;
    }
    
    if (!query.next()) {
        QMessageBox::information(this, "Aucun véhicule disponible", 
            "Aucun véhicule disponible et en bon état n'a été trouvé.\n\n"
            "Vérifiez que :\n"
            "- Au moins un véhicule a la disponibilité 'Disponible'\n"
            "- L'état du véhicule est 'Bon', 'Excellent' ou 'Bon état'\n"
            "- Le véhicule n'est pas déjà affecté à un autre moniteur");
        return;
    }
    
    QString immatriculation = query.value(0).toString();
    QString marque = query.value(1).toString();
    QString typeVehicule = query.value(2).toString();
    QString etat = query.value(3).toString();
    
    // 6. Demander confirmation à l'utilisateur
    int confirmation = QMessageBox::question(this, "Confirmation d'affectation", 
        QString("Affecter le véhicule suivant au moniteur %1 %2 ?\n\n"
               "Véhicule :\n"
               "- Immatriculation : %3\n"
               "- Marque : %4\n"
               "- Type : %5\n"
               "- État : %6\n\n"
               "Moniteur :\n"
               "- Nom : %1 %2\n"
               "- Heures de travail : %7h")
        .arg(nomMoniteur, prenomMoniteur, immatriculation, marque, typeVehicule, etat, QString::number(heuresTravail)),
        QMessageBox::Yes | QMessageBox::No);
    
    if (confirmation == QMessageBox::No) {
        return;
    }
    
    // 7. Insérer l'affectation dans la table AFFECTER
    query.prepare("INSERT INTO AFFECTER (ID_MONITEUR, IMMATRICULATION) VALUES (:id_moniteur, :immatriculation)");
    query.bindValue(":id_moniteur", idMoniteur);
    query.bindValue(":immatriculation", immatriculation);
    
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", 
            "Impossible d'affecter le véhicule.\n" + query.lastError().text());
        return;
    }
    
    // 8. Optionnel : Mettre à jour la disponibilité du véhicule (si nécessaire)
    // On peut laisser le véhicule en "Disponible" car il est maintenant affecté mais toujours disponible pour utilisation
    
    // 9. Afficher un message de succès
    QMessageBox::information(this, "Affectation réussie", 
        QString("Le véhicule %1 (%2) a été affecté avec succès au moniteur %3 %4.")
        .arg(immatriculation, marque, nomMoniteur, prenomMoniteur));
    
    qDebug() << "✓ Véhicule" << immatriculation << "affecté au moniteur" << idMoniteur;
}
