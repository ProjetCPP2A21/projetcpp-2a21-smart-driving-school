#ifndef APPLICATION_INTEGREE_H
#define APPLICATION_INTEGREE_H

#include <QMainWindow>
#include "apprenant.h"
#include "examen.h"

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

private:
    Ui::application_integree *ui;
    int selectedIdExamen;
    void clearFieldsExamen();
};

#endif // APPLICATION_INTEGREE_H

