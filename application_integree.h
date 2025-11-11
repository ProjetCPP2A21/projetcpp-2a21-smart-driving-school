#ifndef APPLICATION_INTEGREE_H
#define APPLICATION_INTEGREE_H

#include <QMainWindow>
#include "apprenant.h"
#include "examen.h"
#include "vehicules.h"
#include "moniteur.h"
#include "paiement.h"

#include <QSqlTableModel>
#include <QIntValidator>
#include <QTableView>
#include <QDateEdit>
#include <QTimeEdit>
#include <QLineEdit>
#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class application_integree; }
QT_END_NAMESPACE

class application_integree : public QMainWindow
{
    Q_OBJECT

public:
    explicit application_integree(QWidget *parent = nullptr);
    ~application_integree();

private slots:
    // Slots pour la page de login
    void on_pushButton_login_clicked();

    // Slots pour le menu principal
    void on_pushButton_apprenants_clicked();
    void on_Bapprenant_clicked(); // Bouton Apprenant (singulier)
    void on_pushButton_examens_clicked();
    void on_pushButton_vehicules_clicked();
    void on_pushButton_paiements_clicked(); // Nouveau bouton pour paiements

    // Slots pour la page Apprenants
    void afficherApprenants();
    bool verifierSaisieApprenant(int &id, QString &nom, QString &prenom, QString &dateNaissance,
                                 QString &tel, QString &sexe, QString &adresse);
    void on_pushButton_ajouter_apprenant_clicked();
    void on_pushButton_modifier_apprenant_clicked();
    void on_pushButton_supprimer_apprenant_clicked();
    void on_pushButton_trier_apprenant_clicked();
    void on_lineEdit_recherche_apprenant_textChanged(const QString &arg1);
    void on_pushButton_exporterPDF_apprenant_clicked();
    void on_pushButton_statistique_apprenant_clicked();
    void on_tableView_apprenants_clicked(const QModelIndex &index);
    void on_pushButton_retour_apprenants_clicked();

    // Slots pour la page Examens
    void on_pushButton_ajouter_examen_clicked();
    void on_pushButton_modifier_examen_clicked();
    void on_pushButton_supprimer_examen_clicked();
    void on_exporterPDF_examen_clicked();
    void on_tableView_examens_clicked(const QModelIndex &index);
    void rechercherParType(const QString &type);
    void trierDate(const QString &ordre);
    void afficherStatistiques();
    void on_pushButton_retour_examens_clicked();

    // Slots pour la page Véhicules
    void afficherVehicules();
    void on_pushButton_ajouter_vehicule_clicked();
    void on_pushButton_modifier_vehicule_clicked();
    void on_pushButton_supprimer_vehicule_clicked();
    void on_pushButton_trier_vehicule_clicked();
    void on_lineEdit_recherche_vehicule_textChanged(const QString &arg1);
    void on_pushButton_exporterPDF_vehicule_clicked();
    void on_pushButton_statistique_vehicule_clicked();
    void on_tableView_vehicules_clicked(const QModelIndex &index);
    void on_pushButton_retour_vehicules_clicked();

    void afficherMoniteurs();
    void clearFieldsMoniteur();

    void on_ajouter_clicked();
    void on_modifier_clicked();
    void on_supprimer_clicked();
    void on_pushButton_moniteurs_clicked();
    void on_pushButton_retour_moniteurs_clicked();

    // Slots pour la page Paiement
    void afficherPaiements();
    void on_pushButton_ajouter_paiement_clicked();
    void on_pushButton_modifier_paiement_clicked();
    void on_pushButton_supprimer_paiement_clicked();
    void on_tableView_paiements_clicked(const QModelIndex &index);
    void on_pushButton_retour_paiements_clicked();
    void clearFieldsPaiement();
    
    // Slots alternatifs pour les noms originaux du projet paiement
    void on_ajouter_paiement_clicked();  // Pour le bouton "ajouter" de paiement
    void on_modifier_paiement_clicked(); // Pour le bouton "modifier" de paiement
    void on_supprimer_paiement_clicked(); // Pour le bouton "supprimer" de paiement
    void on_Retour_paiement_clicked();   // Pour le bouton "Retour" de paiement
    void on_tabView_clicked(const QModelIndex &index); // Pour le tableau "tabView"

private:
    Ui::application_integree *ui;
    int selectedIdExamen;
    int selectedRowVehicule;
    int selectedRowMoniteur = -1;
    int selectedIdPaiement = 0;
    QSqlTableModel *modelVehicules;
    void clearFieldsExamen();
    void clearFieldsVehicule();
    void setupModelVehicules();
    
    // Fonctions utilitaires pour accès sécurisé aux widgets
    QTableView* findTableViewPaiement() const;
    QLineEdit* findLineEditPaiement(const QString& name) const;
    QComboBox* findComboBoxPaiement(const QString& name) const;
    QDateEdit* findDateEditPaiement(const QString& name) const;
    QTimeEdit* findTimeEditPaiement(const QString& name) const;




};

#endif // APPLICATION_INTEGREE_H

