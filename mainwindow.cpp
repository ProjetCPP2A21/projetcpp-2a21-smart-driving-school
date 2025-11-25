#include "mainwindow.h"
#include "ui_mainwindow.h"
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


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->tabView, &QTableView::clicked,
            this, &MainWindow::on_tabView_clicked);

    afficherTableauPaiement();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Lecture des champs UI pour créer un Paiement
Paiement MainWindow::readPaiementFromUI() const
{
    return Paiement(ui->ID->text().toInt(),
                    ui->Type->currentText(),
                    ui->Date->date().toString("dd-MM-yyyy"),
                    ui->heure->text(),
                    ui->montant->text().toDouble());
}

// Ajouter
void MainWindow::on_ajouter_clicked()
{
    Paiement p = readPaiementFromUI();
    if (p.ajouter()) {
        QMessageBox::information(this, "OK", "Ajout effectué avec succès.");
        afficherTableauPaiement();
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout a échoué.");
    }
}

// Supprimer
void MainWindow::on_supprimer_clicked()
{
    int id = ui->ID->text().toInt();
    if (Paiement::supprimer(id)) {
        QMessageBox::information(this, "OK", "Suppression effectuée.");
        afficherTableauPaiement();
    } else {
        QMessageBox::critical(this, "Erreur", "Suppression non effectuée.");
    }
}

// Modifier
void MainWindow::on_modifier_clicked()
{
    Paiement p = readPaiementFromUI();
    if (p.modifier()) {
        QMessageBox::information(this, "OK", "Modification effectuée.");
        afficherTableauPaiement();
    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué.");
    }
}

// Afficher dans QTableView
void MainWindow::afficherTableauPaiement()
{
    Paiement p;
    QSqlQueryModel* model = p.afficher();
    // Assure que le widget de la vue s'appelle tabView (QTableView)
    ui->tabView->setModel(model);
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



