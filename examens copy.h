#ifndef EXAMENS_H
#define EXAMENS_H

#include <QMainWindow>

#include "examen.h"
#include "ui_examens.h"


#include"employes.h"
namespace Ui {
class examens;
 
}

 
class apprenants;
class examens : public QMainWindow
{
    Q_OBJECT

public:
    explicit examens(QWidget *parent = nullptr);
    ~examens();

private slots:
    void on_pushButton_login_clicked();
    void on_pushButton_examens_clicked();
    void on_pushButton_ajouter_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_supprimer_clicked();
    void on_exporterPDF_clicked();
    void on_tableView_examens_clicked(const QModelIndex &index);
    void rechercherParType(const QString &type); // recherche dynamique
    void trierDate(const QString &ordre); // 🔹 slot pour le comboBox
    void afficherStatistiques(); // nouveau slot pour les stats
    void on_pushButton_retour_clicked();
    void on_pushButton_planifier_clicked(); // nouveau slot
    void rappelExamensDuJour(); // rappel automatique
    void on_Bapprenant_clicked();
    void on_Bvehicule_clicked(); // navigation vers véhicules
    void on_Bpaiement_clicked(); // navigation vers le module de paiement
    void on_Bmoniteurs_clicked(); // navigation vers le module moniteur


    void on_pushButton_5_clicked();

private:
    Ui::examens *ui;
    int selectedId;           // 🔹 ID de la ligne sélectionnée
    void clearFields();       // 🔹 Fonction pour vider tous les champs
    // Page des apprenants intégrée dans le stackedWidget
    apprenants *m_apprenantsPage = nullptr;
    // Page des véhicules intégrée dans le stackedWidget
    class vehicule *m_vehiculePage = nullptr;
    // Page de paiement intégrée dans le stackedWidget
    class MainWindow *m_paiementPage = nullptr;
    // Page des moniteurs intégrée dans le stackedWidget
    class moniteur_ui *m_moniteurPage = nullptr;
};

#endif // EXAMENS_H


