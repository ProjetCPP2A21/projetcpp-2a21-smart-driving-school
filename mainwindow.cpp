#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qrcode.h"
#include <QPainter>
#include <QPrinter>
#include <QTextDocument>
#include <QTextTable>
#include <QStandardPaths>
#include <QDir>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QProcess>
#include "cnx.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QSqlQuery>
#include <QSqlError>

#include <QDialog>
#include <QVBoxLayout>
#include <QFileDialog>        // Pour QFileDialog
#include <QPrinter>           // Pour QPrinter
#include <QTextDocument>      // Pour QTextDocument
#include <QAbstractItemModel> // Pour récupérer les données de la QTableView
#include <QDesktopServices>   // Pour ouvrir le dossier contenant le fichier

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupUI();
    
    // Connect signals and slots
    connect(ui->tabView, &QTableView::clicked,
            this, &MainWindow::on_tabView_clicked);
    
    // Set current date and time
    ui->Date->setDate(QDate::currentDate());
    ui->heure->setTime(QTime::currentTime());
    
    afficherTableauPaiement();
}

void MainWindow::setupUI()
{
    // Set window title
    setWindowTitle("Gestion des Paiements");
    
    // Set input validators
    ui->ID->setValidator(new QIntValidator(1, 999999, this));
    
    // Set up amount validator
    QDoubleValidator* montantValidator = new QDoubleValidator(0, 999999, 2, this);
    montantValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->montant->setValidator(montantValidator);
    
    // Set default values
    ui->Type->addItems({"Espèce", "Carte Bancaire", "Chèque", "Virement"});
    
    // Set date format
    ui->Date->setDisplayFormat("dd/MM/yyyy");
    ui->Date->setCalendarPopup(true);
    
    // Set time format
    ui->heure->setDisplayFormat("HH:mm");
    
    // Set table properties
    ui->tabView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tabView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tabView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

bool MainWindow::validateInput() const
{
    if (ui->ID->text().isEmpty()) {
        QMessageBox::warning(const_cast<MainWindow*>(this), "Champ manquant", 
                           "Veuillez saisir un ID valide.");
        ui->ID->setFocus();
        return false;
    }
    
    bool ok;
    double montant = ui->montant->text().replace(',', '.').toDouble(&ok);
    if (!ok || montant <= 0) {
        QMessageBox::warning(const_cast<MainWindow*>(this), "Montant invalide",
                           "Veuillez entrer un montant valide (supérieur à 0).");
        ui->montant->setFocus();
        return false;
    }
    
    if (ui->Type->currentText().isEmpty()) {
        QMessageBox::warning(const_cast<MainWindow*>(this), "Type manquant",
                           "Veuillez sélectionner un type de paiement.");
        return false;
    }
    
    return true;
}

void MainWindow::clearInputs()
{
    ui->ID->clear();
    ui->Type->setCurrentIndex(0);
    ui->Date->setDate(QDate::currentDate());
    ui->heure->setTime(QTime::currentTime());
    ui->montant->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Lecture des champs UI pour créer un Paiement
Paiement MainWindow::readPaiementFromUI() const
{
    double montant = ui->montant->text().replace(',', '.').toDouble();
    return Paiement(ui->ID->text().toInt(),
                   ui->Type->currentText(),
                   ui->Date->date().toString("dd-MM-yyyy"),
                   ui->heure->text(),
                   montant);
}

// Ajouter
void MainWindow::on_ajouter_clicked()
{
    if (!validateInput()) {
        return;
    }
    
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmer l'ajout",
                                "Voulez-vous vraiment ajouter ce paiement ?",
                                QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        Paiement p = readPaiementFromUI();
        if (p.ajouter()) {
            QMessageBox::information(this, "Succès", "Paiement ajouté avec succès.");
            afficherTableauPaiement();
            clearInputs();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de l'ajout du paiement.");
        }
    }
}

// Supprimer
void MainWindow::on_supprimer_clicked()
{
    if (ui->ID->text().isEmpty()) {
        QMessageBox::warning(this, "Champ manquant", "Veuillez sélectionner un paiement à supprimer.");
        return;
    }
    
    int id = ui->ID->text().toInt();
    
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmer la suppression",
                                "Êtes-vous sûr de vouloir supprimer ce paiement ?",
                                QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        if (Paiement::supprimer(id)) {
            QMessageBox::information(this, "Succès", "Paiement supprimé avec succès.");
            afficherTableauPaiement();
            clearInputs();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression du paiement.");
        }
    }
}

// Modifier
void MainWindow::on_modifier_clicked()
{
    if (!validateInput()) {
        return;
    }
    
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmer la modification",
                                "Voulez-vous vraiment modifier ce paiement ?",
                                QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        Paiement p = readPaiementFromUI();
        if (p.modifier()) {
            QMessageBox::information(this, "Succès", "Paiement modifié avec succès.");
            afficherTableauPaiement();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la modification du paiement.");
        }
    }
}

// Afficher dans QTableView
void MainWindow::afficherTableauPaiement()
{
    Paiement p;
    QSqlQueryModel* model = p.afficher();
    
    // Set the model to the table view
    ui->tabView->setModel(model);
    
    // Set French column headers
    if (model) {
        model->setHeaderData(0, Qt::Horizontal, tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, tr("Type de paiement"));
        model->setHeaderData(2, Qt::Horizontal, tr("Date"));
        model->setHeaderData(3, Qt::Horizontal, tr("Heure"));
        model->setHeaderData(4, Qt::Horizontal, tr("Montant (DT)"));
        
        // Set column resize modes
        ui->tabView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
        ui->tabView->horizontalHeader()->setStretchLastSection(true);
        
        // Set column widths
        ui->tabView->setColumnWidth(0, 60);    // ID
        ui->tabView->setColumnWidth(1, 150);   // Type
        ui->tabView->setColumnWidth(2, 100);   // Date
        ui->tabView->setColumnWidth(3, 80);    // Heure
        ui->tabView->setColumnWidth(4, 100);   // Montant
        
        // Enable sorting
        ui->tabView->setSortingEnabled(true);
        
        // Set selection behavior
        ui->tabView->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tabView->setSelectionMode(QAbstractItemView::SingleSelection);
        
        // Set alternating row colors for better readability
        ui->tabView->setAlternatingRowColors(true);
    }
}
//tri
void MainWindow::on_triDate_clicked()
{
    Paiement p;
    ui->tabView->setModel(p.trierParDate(true));  // true = ASC
}
//recherche selon id
void MainWindow::on_rechercher_clicked()
{
    // Trouver le champ de recherche par son nom d'objet
    QLineEdit* searchEdit = findChild<QLineEdit*>(QStringLiteral("rechIdApprenant"));
    if (!searchEdit) {
        QMessageBox::warning(this, "Erreur", "Champ de recherche introuvable");
        return;
    }

    bool ok;
    int id = searchEdit->text().toInt(&ok);
    
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide");
        return;
    }

    Paiement p;
    ui->tabView->setModel(p.rechercherParApprenant(id));
}
//exporter
#include <QPdfWriter>
#include <QPainter>
/*QSqlQueryModel* Paiement::rechercherParApprenant(int id) const
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT * FROM PAIEMENT WHERE ID_APPRENANT = :id");
    query.bindValue(":id", id);
    query.exec();

    model->setQuery(query);

    return model;
}*/


void MainWindow::on_exporter_clicked()
{
    // Choix du fichier PDF
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty())
        return;

    // Configuration du PDF
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));

    QTextDocument doc;

    // Entête HTML
    QString html = "<html><head><meta charset='UTF-8'></head><body>";
    html += "<h1 align='center'>Liste des Paiements</h1>";
    html += "<table border='1' cellpadding='5' cellspacing='0' width='100%'>";
    html += "<tr>"
            "<th>ID Paiement</th>"
            "<th>Type</th>"
            "<th>Date</th>"
            "<th>Heure</th>"
            "<th>Montant</th>"
            "<th>ID Apprenant</th>"
            "</tr>";

    // Récupération du modèle
    QAbstractItemModel* baseModel = ui->tabView->model();
    if (!baseModel) return;

    for (int row = 0; row < baseModel->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < baseModel->columnCount(); ++col) {
            html += "<td>" + baseModel->data(baseModel->index(row, col)).toString() + "</td>";
        }
        html += "</tr>";
    }

    html += "</table></body></html>";

    doc.setHtml(html);
    doc.print(&printer);

    QMessageBox::information(this, "Succès", "PDF exporté avec succès !");
}
//statistique


void MainWindow::on_statistique_clicked()
{
    // --- Récupération des statistiques depuis la base ---
    QSqlQuery query(QSqlDatabase::database("oracle_connection"));
    query.prepare("SELECT TYPE_PAIEMENT, COUNT(*) FROM PAIEMENTS GROUP BY TYPE_PAIEMENT");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
        return;
    }

    QMap<QString,int> stats;
    int total = 0;

    while (query.next()) {
        QString type = query.value(0).toString();
        int count = query.value(1).toInt();
        stats[type] = count;
        total += count;
    }

    if (total == 0) {
        QMessageBox::information(this, "Statistiques", "Aucun paiement enregistré.");
        return;
    }

    // --- Série Donut ---
    QPieSeries* series = new QPieSeries();
    series->setHoleSize(0.25);

    for (auto it = stats.begin(); it != stats.end(); ++it) {

        double pourcentage = (it.value() * 100.0) / total;

        QString label = it.key() + " (" + QString::number(it.value()) +
                        ") : " + QString::number(pourcentage, 'f', 1) + "%";

        QPieSlice* slice = series->append(label, it.value());
        slice->setLabelVisible(true);

        // --- Couleurs personnalisées selon type ---
        if (it.key().toLower() == "espece" || it.key().toLower() == "espèces")
            slice->setBrush(QColor("#43cea2"));  // Vert pastel
        else if (it.key().toLower() == "cheque" || it.key().toLower() == "chèque")
            slice->setBrush(QColor("#185a9d"));  // Bleu foncé
        else if (it.key().toLower() == "virement")
            slice->setBrush(QColor("#f39c12"));  // Orange
        else
            slice->setBrush(QColor("#185a9d"));  // Violet par défaut

        // --- Explosion animation (hover) ---
        slice->setExploded(false);
        QObject::connect(slice, &QPieSlice::hovered, [slice](bool state){
            slice->setExploded(state);
            slice->setLabelVisible(true);
        });
    }

    // --- Création du graphique ---
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    chart->setBackgroundVisible(false);

    // --- Titre ---
    chart->setTitle("Répartition des paiements selon le type");
    chart->setTitleFont(QFont("Segoe UI", 14, QFont::Bold));
    chart->setTitleBrush(QBrush(QColor("#185a9d")));

    // --- Légende ---
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->legend()->setFont(QFont("Segoe UI", 10, QFont::Bold));
    chart->legend()->setLabelColor(QColor("#185a9d"));

    // --- Affichage dans une fenêtre ---
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QDialog* dialog = new QDialog(this);
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);

    dialog->setWindowTitle("Statistiques Paiements");
    dialog->resize(550, 450);
    dialog->exec();
}
void MainWindow::on_tabView_clicked(const QModelIndex &index)
{
    int row = index.row();
    QAbstractItemModel *model = ui->tabView->model();

    // Remplir les champs avec les données de la ligne sélectionnée
    ui->ID->setText(model->data(model->index(row, 0)).toString());
    ui->Type->setCurrentText(model->data(model->index(row, 1)).toString());
    ui->Date->setDate(QDate::fromString(model->data(model->index(row, 2)).toString(), "dd-MM-yyyy"));
    
    // Convert the time string to QTime and set it
    QString timeStr = model->data(model->index(row, 3)).toString();
    QTime time = QTime::fromString(timeStr, "hh:mm:ss");
    if (time.isValid()) {
        ui->heure->setTime(time);
    } else {
        // Fallback to current time if time string is invalid
        ui->heure->setTime(QTime::currentTime());
    }
    
    ui->montant->setText(model->data(model->index(row, 4)).toString());
}

QString MainWindow::genererContenuFacture(const Paiement &paiement)
{
    QString contenu = QString(
        "<h1>Facture de Paiement</h1>"
        "<table>"
        "<tr><td><b>ID Paiement:</b></td><td>%1</td></tr>"
        "<tr><td><b>Type:</b></td><td>%2</td></tr>"
        "<tr><td><b>Date:</b></td><td>%3</td></tr>"
        "<tr><td><b>Heure:</b></td><td>%4</td></tr>"
        "<tr><td><b>Montant:</b></td><td>%5 TND</td></tr>"
        "<tr><td><b>ID Apprenant:</b></td><td>%6</td></tr>"
        "</table>"
        "<p>Merci pour votre confiance !</p>"
    ).arg(
        QString::number(paiement.getId()),
        paiement.getType(),
        paiement.getDate(),
        paiement.getHeure(),
        QString::number(paiement.getMontant(), 'f', 2),
        paiement.getIdApprenant() > 0 ? QString::number(paiement.getIdApprenant()) : "N/A"
    );
    
    return contenu;
}

void MainWindow::genererQRCode(const Paiement &paiement)
{
    try {
        // Créer une chaîne structurée pour le QR code
        QString qrData = QString("PAIEMENT\n"
                               "ID: %1\n"
                               "Type: %2\n"
                               "Date: %3\n"
                               "Heure: %4\n"
                               "Montant: %5 DT")
                        .arg(paiement.getId())
                        .arg(paiement.getType())
                        .arg(paiement.getDate())
                        .arg(paiement.getHeure())
                        .arg(QString::number(paiement.getMontant(), 'f', 2));

        // Générer le QR code
        qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(qrData.toUtf8().constData(), 
            qrcodegen::QrCode::Ecc::HIGH);
        
        // Paramètres du QR code
        const int size = qr.getSize();
        const int border = 4;
        const int moduleSize = 8; // Taille de chaque module en pixels
        const int imageSize = (size + 2 * border) * moduleSize;
        
        // Créer l'image
        QImage qrImage(imageSize, imageSize, QImage::Format_RGB32);
        qrImage.fill(Qt::white);
        
        // Préparer le peintre
        QPainter painter(&qrImage);
        painter.setRenderHint(QPainter::Antialiasing);
        
        // Couleurs modernes
        QColor darkColor(58, 35, 100);  // Violet foncé
        QColor lightColor(255, 255, 255); // Blanc
        QColor backgroundColor(245, 245, 250); // Gris très clair
        
        // Remplir l'arrière-plan
        painter.fillRect(0, 0, imageSize, imageSize, backgroundColor);
        
        // Dessiner les modules du QR code avec des coins arrondis
        painter.setPen(Qt::NoPen);
        painter.setBrush(darkColor);
        
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                if (qr.getModule(x, y)) {
                    QRectF rect(
                        (border + x) * moduleSize,
                        (border + y) * moduleSize,
                        moduleSize,
                        moduleSize
                    );
                    painter.drawRoundedRect(rect, 2, 2);
                }
            }
        }
        
        // Ajouter une bordure décorative
        QPen borderPen;
        borderPen.setColor(QColor(200, 200, 220));
        borderPen.setWidth(moduleSize * 2);
        painter.setPen(borderPen);
        painter.setBrush(Qt::NoBrush);
        painter.drawRoundedRect(
            moduleSize, 
            moduleSize, 
            imageSize - 2 * moduleSize, 
            imageSize - 2 * moduleSize, 
            10, 10
        );
        
        // Créer un nom de fichier unique
        QString fileName = QString("Paiement_%1_%2.png")
            .arg(paiement.getId())
            .arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss"));
            
        // Obtenir le répertoire des documents
        QString documentsPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
        QString filePath = documentsPath + "/" + fileName;
        
        // Sauvegarder l'image avec une haute qualité
        if (qrImage.save(filePath, "PNG", 100)) {
            // Afficher un message de succès avec un style moderne
            QMessageBox msgBox;
            msgBox.setWindowTitle("Succès");
            msgBox.setText("Le code QR a été généré avec succès !");
            msgBox.setInformativeText(QString("Emplacement :\n%1").arg(filePath));
            
            // Créer une chaîne de style
            QString style = ""
                "QMessageBox { "
                "    background-color: #f8f9fa; "
                "    border: 1px solid #e0e0e0; "
                "    border-radius: 8px; "
                "}"
                ""
                "QMessageBox QLabel { "
                "    color: #2c3e50; "
                "    font-size: 14px; "
                "    padding: 10px; "
                "}"
                ""
                "QMessageBox QPushButton { "
                "    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #6e45e2, stop:1 #88d3ce);"
                "    color: white; "
                "    border: none; "
                "    padding: 8px 16px; "
                "    border-radius: 4px; "
                "    min-width: 100px; "
                "    font-weight: bold; "
                "    margin: 5px; "
                "}"
                ""
                "QMessageBox QPushButton:hover { "
                "    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #5d3db8, stop:1 #6bbab5); "
                "    box-shadow: 0 2px 5px rgba(0,0,0,0.2); "
                "}"
                ""
                "QMessageBox QPushButton:pressed { "
                "    padding-top: 9px; "
                "    padding-bottom: 7px; "
                "}";
            
            // Appliquer le style
            msgBox.setStyleSheet(style);
            
            // Ajouter les boutons
            QPushButton *btnOuvrir = msgBox.addButton("Ouvrir le dossier", QMessageBox::ActionRole);
            msgBox.addButton("Fermer", QMessageBox::RejectRole);
            
            // Afficher la boîte de message
            msgBox.exec();
            
            // Vérifier quel bouton a été cliqué
            if (msgBox.clickedButton() == btnOuvrir) {
                // Ouvrir le dossier avec la méthode la plus fiable
                #ifdef Q_OS_WIN
                    // Méthode spécifique pour Windows
                    QProcess::startDetached("explorer", QStringList() << "/select," << QDir::toNativeSeparators(filePath));
                #else
                    // Méthode générique pour les autres systèmes
                    QDesktopServices::openUrl(QUrl::fromLocalFile(documentsPath));
                #endif
            }
        } else {
            QMessageBox::warning(this, "Erreur", 
                QString("Impossible de sauvegarder le fichier : %1").arg(filePath));
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Erreur", 
            QString("Erreur lors de la génération du QR code : %1").arg(e.what()));
    }
}

void MainWindow::on_genererQRCode_clicked()
{
    // Récupérer le paiement actuel
    Paiement p = readPaiementFromUI();
    if (p.getId() == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un paiement valide");
        return;
    }
    
    // Générer le QR code
    genererQRCode(p);
}
