#ifndef MONITEUR_H
#define MONITEUR_H
#include <Qstring>
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
    bool existe(QString id);

};

#endif // MONITEUR_H

