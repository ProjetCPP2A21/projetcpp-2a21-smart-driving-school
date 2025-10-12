#ifndef MODIFIER_EMPLOYE_H
#define MODIFIER_EMPLOYE_H

#include <QWidget>
#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

namespace Ui {
class modifier_employe;
}

class modifier_employe : public QWidget
{
    Q_OBJECT

public:
    explicit modifier_employe(QWidget *parent = nullptr);
    ~modifier_employe();
    
    // Méthode pour charger les données d'un employé existant
    void chargerEmploye(const QString &idEmploye);

private slots:
    void on_pushButton_confirmer_clicked();
    void on_pushButton_annuler_clicked();
    void on_BretourModifierEmploye_clicked();

private:
    Ui::modifier_employe *ui;
    QString idEmployeActuel; // ID de l'employé en cours de modification
    
    bool validerFormulaire();
    bool modifierEmploye();
    bool verifierEmailUnique(const QString &email, const QString &idExclu);
    void chargerDonneesEmploye();
};

#endif // MODIFIER_EMPLOYE_H
