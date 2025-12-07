#ifndef VEHICULES_H
#define VEHICULES_H

#include <QDialog>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSettings>
#include <QFileDialog>
#include <QString>

// Forward declaration
namespace Ui {
    class Vehicules;
}

class Vehicules : public QDialog
{
    Q_OBJECT
    
public:
    explicit Vehicules(QWidget *parent = nullptr);
    ~Vehicules();

    // Getters
    QString getMarque() const { return marque; }
    QString getImmatriculation() const { return immatriculation; }
    QString getType() const { return type; }
    double getKilometrage() const { return kilometrage; }
    QString getEtat() const { return etat; }
    QString getDisponibilite() const { return disponibilite; }
    int getCapacite() const { return capacite; }

    // Setters
    void setMarque(const QString &value) { marque = value; }
    void setImmatriculation(const QString &value) { immatriculation = value; }
    void setType(const QString &value) { type = value; }
    void setKilometrage(double value) { kilometrage = value; }
    void setEtat(const QString &value) { etat = value; }
    void setDisponibilite(const QString &value) { disponibilite = value; }
    void setCapacite(int value) { capacite = value; }

    // Opérations CRUD
    bool ajouter();
    bool modifier(const QString &immatriculation);
    bool supprimer(const QString &immatriculation);
    bool rechercher(const QString &critere);

private:
    // Méthodes utilitaires
    void viderChamps();
    bool verifierChamps() const;
    void afficherMessage(const QString &titre, const QString &message, QMessageBox::Icon icone = QMessageBox::Information) const;

public slots:
    // Méthodes principales
    void ajouterVehicule();
    void modifierVehicule();
    void supprimerVehicule();
    void rechercherVehicule();
    void selectionnerVehicule(const QModelIndex &index = QModelIndex());
    
private slots:
    // Slots pour les connexions manuelles
    void onAjouterButtonClicked();
    void onModifierButtonClicked();
    void onSupprimerButtonClicked();
    void onRechercherButtonClicked();
    void onTableViewClicked(const QModelIndex &index);

private:
    Ui::Vehicules *ui;
    QSqlTableModel *model;
    
    // Données du véhicule
    QString marque;
    QString immatriculation;
    QString type;
    double kilometrage;
    QString etat;
    QString disponibilite;
    int capacite;
    
    // Méthodes d'initialisation
    void setupUi();
    void setupModel();
    void setupConnections();
    
    // Méthodes utilitaires
    void chargerTableau();
};

#endif // VEHICULES_H
