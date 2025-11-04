#ifndef VEHICULE_H
#define VEHICULE_H

<<<<<<< HEAD
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class vehicule;
}
QT_END_NAMESPACE

class vehicule : public QMainWindow
{
    Q_OBJECT

public:
    vehicule(QWidget *parent = nullptr);
    ~vehicule();

private:
    Ui::vehicule *ui;
};
=======
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Vehicule {
public:
    Vehicule();
    Vehicule(QString marque, QString type, int kilometrage, QString etat, QString immatriculation, QString dispo, int capacite);

    // Getters
    QString getMarque() const;
    QString getType() const;
    int getKilometrage() const;
    QString getEtat() const;
    QString getImmatriculation() const;
    QString getDispo() const;
    int getCapacite() const;

    // Setters
    void setMarque(QString marque);
    void setType(QString type);
    void setKilometrage(int km);
    void setEtat(QString etat);
    void setImmatriculation(QString imm);
    void setDispo(QString dispo);
    void setCapacite(int cap);

    // CRUD
    bool ajouter();
    bool supprimer(QString immatriculation);
    bool modifier(QString immatriculation);
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercherParMarque(QString marque);

private:
    QString marque, type, etat, immatriculation, dispo;
    int kilometrage, capacite;
};

>>>>>>> ae4c4d6 (hello)
#endif // VEHICULE_H
