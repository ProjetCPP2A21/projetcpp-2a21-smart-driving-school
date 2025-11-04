#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "paiement.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    afficherTableauPaiement();
}

Paiement p;

void MainWindow::on_ajouter_clicked()
{
    int id = ui->ID->text().toInt();
    QString type = ui->Type->currentText();
    QString date = ui->Date->date().toString("dd-MM-yyyy");
    QString heure = ui->heure->text();
    QString lieu = ui->lieu->text();
    QString offre = ui->choisir->currentText();
    double montant = ui->montant->text().toDouble();

    Paiement P(id, type, date, heure, lieu, offre, montant);

    bool test = P.ajouter();
    if (test) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué avec succès."), QMessageBox::Ok);
        afficherTableauPaiement();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("L'ajout a échoué."), QMessageBox::Cancel);
    }
}

void MainWindow::on_supprimer_clicked()
{
    int id = ui->ID->text().toInt();
    bool test = p.supprimer(id);

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée."), QMessageBox::Ok);
        afficherTableauPaiement();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Suppression non effectuée."), QMessageBox::Cancel);
    }
}

void MainWindow::on_modifier_clicked()
{
    int id = ui->ID->text().toInt();
    QString type = ui->Type->currentText();
    QString date = ui->Date->date().toString("dd-MM-yyyy");
    QString heure = ui->heure->text();
    QString lieu = ui->lieu->text();
    QString offre = ui->choisir->currentText();
    double montant = ui->montant->text().toDouble();

    Paiement P(id, type, date, heure, lieu, offre, montant);

    bool test = P.modifier();
    if (test) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Modification effectuée."), QMessageBox::Ok);
        afficherTableauPaiement();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("La modification a échoué."), QMessageBox::Cancel);
    }
}

void MainWindow::afficherTableauPaiement()
{
    QSqlQuery query;
    // ✅ Correspond exactement à ta table Oracle : PAIEMENTS
    query.prepare("SELECT ID_PAIEMENT, TYPE_PAIEMENT, TO_CHAR(DATE_PAIEMENT, 'DD-MM-YYYY'), HEURE_PAIEMENT, MONTANT, ID_APPRENANT FROM PAIEMENTS");
    query.exec();

    // Configuration du QTableWidget
    ui->tab->setColumnCount(6);
    QStringList headers = {"ID", "Type", "Date", "Heure", "Montant", "ID Apprenant"};
    ui->tab->setHorizontalHeaderLabels(headers);
    ui->tab->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tab->insertRow(row);
        for (int col = 0; col < 6; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            ui->tab->setItem(row, col, item);
        }
        row++;
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
