#ifndef VEHICULES_H
#define VEHICULES_H

#include <QString>

class Vehicules
{
private:
    QString marque;
    QString immatriculation;
    QString type;
    double kilometrage;
    QString etat;
    QString disponibilite;
    int capacite;

public:
    Vehicules();
    Vehicules(QString, QString, QString, double, QString, QString, int);
    
    // Getters
    QString getMarque();
    QString getImmatriculation();
    QString getType();
    double getKilometrage();
    QString getEtat();
    QString getDisponibilite();
    int getCapacite();
    
    // Setters
    void setMarque(QString);
    void setImmatriculation(QString);
    void setType(QString);
    void setKilometrage(double);
    void setEtat(QString);
    void setDisponibilite(QString);
    void setCapacite(int);
    
    // CRUD Operations
    bool ajouter();
    bool modifier(QString);
    bool supprimer(QString);
    bool rechercher(QString);
};

#endif // VEHICULES_H

