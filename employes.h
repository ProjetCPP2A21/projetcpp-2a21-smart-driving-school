#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSqlQueryModel>
#include"employe.h"
#include<QValidator>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include <QPrinter>
QT_BEGIN_NAMESPACE
namespace Ui { class Employes; }
QT_END_NAMESPACE

class Employes : public QMainWindow
{
    Q_OBJECT

public:
    Employes(QWidget *parent = nullptr);
    ~Employes();
bool matchesValidator(QValidator *v, const QString &s);
private slots:

    void on_ajoutEmpl_clicked();

    void on_modifierEmpl_clicked();

    void on_retour_AjoutEmpl_clicked();

    void on_retoure_modifierEmpl_clicked();

    void on_confirmer_AjoutEmpl_clicked();

    void on_tabEmploye_clicked(const QModelIndex &index);

    void on_supprimerEmploye_clicked();


    void on_trieEmpl_currentIndexChanged(const QString &arg1);

    void on_rechercheEmpl_textChanged(const QString &arg1);

    void on_PDFempl_clicked();

    void on_btn_statEmpl_clicked();

private:
    Ui::Employes *ui;
    QSqlQueryModel *tabEmploye;
    employe e;
};
#endif // MAINWINDOW_H
