#ifndef EXAMENS_H
#define EXAMENS_H

#include <QMainWindow>
#include "examen.h"
#include "ui_examens.h"
#include <QMainWindow>
#include <QSerialPort>
#include <QtSql>
namespace Ui {
class examens;
}

class examens : public QMainWindow
{
    Q_OBJECT

public:
    explicit examens(QWidget *parent = nullptr);
    ~examens();


private slots:
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
    // ----- Arduino -----
    void setupArduino();              // config et ouverture port Arduino
    void lireArduino();               // lire les données venant de l'Arduino
    void verifierID(const QString &id); // vérifier si ID valide et action moteur
void on_pushButton_ouvrir_clicked(); // <-- nouveau



private:
    Ui::examens *ui;
    int selectedId;           // 🔹 ID de la ligne sélectionnée
    void clearFields();
    QSqlDatabase db;    // 🔹 Fonction pour vider tous les champs
    QSerialPort *arduino;       // port série pour Arduino
    QString bufferArduino;       // pour accumuler les données série


    bool idValide(const QString &id); // vérifie si l'ID est dans la base

};


#endif // EXAMENS_H
