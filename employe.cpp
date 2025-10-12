#include "employe.h"
#include "ui_employe.h"
#include "menu.h"
#include "ajouter_employe.h"
#include "modifier_employe.h"
#include <QMessageBox>
#include <QTableWidgetItem>

employe::employe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::employe)
    , ajouterPage(nullptr)
    , modifierPage(nullptr)
{
    ui->setupUi(this);
    
    // Connexion des signaux
    connect(ui->pushButton_9, &QPushButton::clicked, this, &employe::on_pushButton_9_clicked);
    connect(ui->pushButton_11, &QPushButton::clicked, this, &employe::on_pushButton_11_clicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &employe::on_pushButton_8_clicked);
}

employe::~employe()
{
    delete ui;
    if (ajouterPage) delete ajouterPage;
    if (modifierPage) delete modifierPage;
}

void employe::on_BretourEmploye_clicked()
{
    menu *menuWindow = new menu(this);
    menuWindow->show();
    this->close();
}

void employe::on_pushButton_9_clicked()
{
    // Ouvrir la page d'ajout d'employé
    if (!ajouterPage) {
        ajouterPage = new ajouter_employe(this);
    }
    ajouterPage->show();
}

void employe::on_pushButton_11_clicked()
{
    // Vérifier qu'une ligne est sélectionnée dans le tableau
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner un employé à modifier.");
        return;
    }
    
    // Récupérer l'ID de l'employé sélectionné
    QTableWidgetItem *idItem = ui->tableWidget->item(currentRow, 0);
    if (!idItem) {
        QMessageBox::warning(this, "Erreur", "Impossible de récupérer l'ID de l'employé.");
        return;
    }
    
    QString idEmploye = idItem->text();
    
    // Ouvrir la page de modification d'employé
    if (!modifierPage) {
        modifierPage = new modifier_employe(this);
    }
    modifierPage->chargerEmploye(idEmploye);
    modifierPage->show();
}

void employe::on_pushButton_8_clicked()
{
    // Vérifier qu'une ligne est sélectionnée dans le tableau
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner un employé à supprimer.");
        return;
    }
    
    // Demander confirmation
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation", 
        "Êtes-vous sûr de vouloir supprimer cet employé ?",
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        // Récupérer l'ID de l'employé sélectionné
        QTableWidgetItem *idItem = ui->tableWidget->item(currentRow, 0);
        if (idItem) {
            QString idEmploye = idItem->text();
            
            // TODO: Implémenter la suppression dans la base de données
            // Pour l'instant, on supprime juste la ligne du tableau
            ui->tableWidget->removeRow(currentRow);
            QMessageBox::information(this, "Succès", "Employé supprimé avec succès.");
        }
    }
}
