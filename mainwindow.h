#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "paiement.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_clicked();
    void on_supprimer_clicked();
    void on_modifier_clicked();
    void on_triDate_clicked();
    void on_rechercher_clicked();
    void on_exporter_clicked();
    void on_statistique_clicked();

private:
    Ui::MainWindow *ui;
    void afficherTableauPaiement();
    Paiement readPaiementFromUI() const;
};

#endif // MAINWINDOW_H
