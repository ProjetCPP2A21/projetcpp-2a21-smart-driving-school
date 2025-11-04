#include "vehicules.h"
#include "ui_vehicule.h"
#include "vehicule.h"
#include <QModelIndexList>

vehicules::vehicules(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vehicule)
{
    ui->setupUi(this);

    //  tableView
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setModel(Vehicule().afficher());

    //
    connect(ui->tableView, &QTableView::clicked, this, &vehicules::on_tableView_clicked);
    connect(ui->lineEdit_marque, &QLineEdit::textChanged, this, &vehicules::rechercherParMarque);
}

vehicules::~vehicules() { delete ui; }

// ------------------- Slots -------------------
void vehicules::on_pushButton_ajouter_clicked() {
    Vehicule v(ui->lineEdit_marque->text(),
               ui->comboBox_type->currentText(),
               ui->lineEdit_kilometrage->text().toInt(),
               ui->comboBox_etat->currentText(),
               ui->lineEdit_immatriculation->text(),
               ui->comboBox_dispo->currentText(),
               ui->lineEdit_Capacite->text().toInt());
    if(v.ajouter()) {
        QMessageBox::information(this, "Ajouter", "Véhicule ajouté avec succès");
        ui->tableView->setModel(Vehicule().afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout");
    }
}

void vehicules::on_pushButton_modifier_clicked() {
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();
    if(selection.empty()) return;

    QString immatriculation = ui->lineEdit_immatriculation->text();
    Vehicule v(ui->lineEdit_marque->text(),
               ui->comboBox_type->currentText(),
               ui->lineEdit_kilometrage->text().toInt(),
               ui->comboBox_etat->currentText(),
               immatriculation,
               ui->comboBox_dispo->currentText(),
               ui->lineEdit_Capacite->text().toInt());
    if(v.modifier(immatriculation)) {
        QMessageBox::information(this, "Modifier", "Véhicule modifié avec succès");
        ui->tableView->setModel(Vehicule().afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification");
    }
}

void vehicules::on_pushButton_supprimer_clicked() {
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();
    if(selection.empty()) return;

    QString immatriculation = ui->tableView->model()->index(selection.at(0).row(), 4).data().toString();
    if(Vehicule().supprimer(immatriculation)) {
        QMessageBox::information(this, "Supprimer", "Véhicule supprimé avec succès");
        ui->tableView->setModel(Vehicule().afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression");
    }
}

void vehicules::on_tableView_clicked(const QModelIndex &index) {
    int row = index.row();
    ui->lineEdit_marque->setText(ui->tableView->model()->index(row, 0).data().toString());
    ui->comboBox_type->setCurrentText(ui->tableView->model()->index(row, 1).data().toString());
    ui->lineEdit_kilometrage->setText(ui->tableView->model()->index(row, 2).data().toString());
    ui->comboBox_etat->setCurrentText(ui->tableView->model()->index(row, 3).data().toString());
    ui->lineEdit_immatriculation->setText(ui->tableView->model()->index(row, 4).data().toString());
    ui->comboBox_dispo->setCurrentText(ui->tableView->model()->index(row, 5).data().toString());
    ui->lineEdit_Capacite->setText(ui->tableView->model()->index(row, 6).data().toString());
}

void vehicules::rechercherParMarque(const QString &marque) {
    ui->tableView->setModel(Vehicule().rechercherParMarque(marque));
}
