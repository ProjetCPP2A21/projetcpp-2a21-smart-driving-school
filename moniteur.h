#ifndef MONITEUR_H
#define MONITEUR_H

#include <QString>   // <-- indispensable pour QString

class QTableWidget;
namespace Ui {
class moniteur;
}

class moniteur {
public:
    static void afficherMoniteurs(QTableWidget *table);
    static bool ajouterMoniteur(Ui::moniteur *ui);
    static bool modifierMoniteur(Ui::moniteur *ui);
    static bool supprimerMoniteur(Ui::moniteur *ui);

    // Métier avancé : taux de réussite
    static double tauxReussite(int idMoniteur);

    // Métier avancé : validation de véhicule

};

#endif // MONITEUR_H
