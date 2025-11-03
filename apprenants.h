#ifndef APPRENANTS_H
#define APPRENANTS_H

#include <QMainWindow>
#include <QModelIndex>
#include "apprenant.h"

QT_BEGIN_NAMESPACE
namespace Ui { class apprenants; }
QT_END_NAMESPACE

class apprenants : public QMainWindow
{
    Q_OBJECT

public:
    apprenants(QWidget *parent = nullptr);
    ~apprenants();
    void afficherApprenants();

private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_trier_clicked();
    void on_lineEdit_recherche_textChanged(const QString &arg1);
    void on_pushButton_exporterPDF_clicked();
    void on_pushButton_statistique_clicked();
    void on_tableView_apprenants_clicked(const QModelIndex &index);

private:
    Ui::apprenants *ui;
};

#endif // APPRENANTS_H
