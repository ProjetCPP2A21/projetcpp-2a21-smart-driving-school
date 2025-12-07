#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPainter>
#include <QPixmap>
#include <QFileDialog>
#include <QStandardPaths>
#include <QPrinter>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QTextTableFormat>
#include "paiement.h"
#include "qrcodegen.hpp"
class Test;

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
    void on_tabView_clicked(const QModelIndex &index);
    void on_genererQRCode_clicked(); // Nouveau slot pour générer le QR code
    void on_testp_clicked();

private:
    Ui::MainWindow *ui;
    void afficherTableauPaiement();
    Paiement readPaiementFromUI() const;
    QString genererContenuFacture(const Paiement &paiement);
    void genererQRCode(const Paiement &paiement);
    bool validateInput() const;
    void clearInputs();
    void setupUI();
    int verifierApprenantId(const QString &id);
public:
    void setTest(Test *t);
private:
    Test *m_test = nullptr;
};


#endif // MAINWINDOW_H
