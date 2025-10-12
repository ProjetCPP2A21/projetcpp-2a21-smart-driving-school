#ifndef AJOUTER_EMPLOYE_H
#define AJOUTER_EMPLOYE_H

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
class ajouter_employe;
}

class ajouter_employe : public QWidget
{
    Q_OBJECT

public:
    explicit ajouter_employe(QWidget *parent = nullptr);
    ~ajouter_employe();

private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_annuler_clicked();
    void on_pushButton_vider_clicked();
    void on_BretourAjouterEmploye_clicked();

private:
    Ui::ajouter_employe *ui;
    bool validerFormulaire();
    void viderChamps();
    bool ajouterEmploye();
    bool verifierEmailUnique(const QString &email);
    bool verifierIdUnique(const QString &id);
};

#endif // AJOUTER_EMPLOYE_H
