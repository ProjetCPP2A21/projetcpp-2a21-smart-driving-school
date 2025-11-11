#ifndef MONITEUR_H
#define MONITEUR_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QSqlQuery>

class moniteur : public QWidget
{
    Q_OBJECT

public:
    explicit moniteur(QWidget *parent = nullptr);
    ~moniteur();

    // Fonctions CRUD
    bool ajouterMoniteur();
    bool modifierMoniteur();
    bool supprimerMoniteur();

private:
    // Widgets de la page moniteur
    QLineEdit *ID;
    QLineEdit *nom;
    QLineEdit *prenom;
    QLineEdit *telephone;
    QComboBox *spec;
    QComboBox *disp;
    QSpinBox *heur;
};

#endif // MONITEUR_H
