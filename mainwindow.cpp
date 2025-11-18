#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cnx.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    int id = ui->rechIdApprenant->text().toInt();
    Paiement p;

    ui->tabView->setModel(p.rechercherParApprenant(id));
}
//exporter
#include <QPdfWriter>
#include <QPainter>

void MainWindow::on_exporter_clicked()
{
    QString filePath = "paiements.pdf";
    QPdfWriter pdf(filePath);
    pdf.setPageSize(QPageSize(QPageSize::A4));


    QPainter painter(&pdf);
    int y = 200;

    painter.setFont(QFont("Arial", 16));
    painter.drawText(100, 100, "Liste des Paiements");

    QSqlQuery query("SELECT * FROM PAIEMENTS", QSqlDatabase::database("oracle_connection"));
    painter.setFont(QFont("Arial", 10));

    while (query.next()) {
        QString ligne = "ID: " + query.value(0).toString() +
                        " | Type: " + query.value(1).toString() +
                        " | Date: " + query.value(2).toString() +
                        " | Montant: " + query.value(4).toString();

        painter.drawText(100, y, ligne);
        y += 30;
    }

    painter.end();
    QMessageBox::information(this, "PDF", "PDF généré avec succès !");
}
//statistique


void MainWindow::on_statistique_clicked()
{
    QPieSeries *series = new QPieSeries();

    QSqlQuery query("SELECT TYPE_PAIEMENT, COUNT(*) FROM PAIEMENTS GROUP BY TYPE_PAIEMENT",
                    QSqlDatabase::database("oracle_connection"));

    while (query.next()) {
        series->append(query.value(0).toString(), query.value(1).toInt());
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques par type de paiement");

    QChartView *view = new QChartView(chart);
    view->setRenderHint(QPainter::Antialiasing);
    view->resize(600, 400);
    view->show();
}



