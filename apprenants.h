#ifndef APPRENANTS_H
#define APPRENANTS_H

#include <QMainWindow>
#include "apprenant.h"

QT_BEGIN_NAMESPACE
namespace Ui { class apprenants; }
QT_END_NAMESPACE

class apprenants : public QMainWindow
{
    Q_OBJECT

public:
    explicit apprenants(QWidget *parent = nullptr);
    ~apprenants();

private slots:
    void afficherApprenants();
    bool verifierSaisie(int &id, QString &nom, QString &prenom, QString &dateNaissance,
                        QString &tel, QString &sexe, QString &adresse);

    void on_pushButton_ajouter_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_trier_clicked();
    void on_lineEdit_recherche_textChanged(const QString &arg1);
    void on_pushButton_exporterPDF_clicked();
    void on_pushButton_statistique_clicked();
    void on_tableView_apprenants_clicked(const QModelIndex &index);

private:
    void reinitialiserFormulaire();
    void afficherMessageControle(const QString &message, bool erreur = true);
    Ui::apprenants *ui;
};

#endif // APPRENANTS_H
