#ifndef VEHICULE_H
#define VEHICULE_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QTimer>
#include <QPainter>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextTable>
#include <QTextCursor>
#include <QTextTableFormat>
#include <QTextCharFormat>
#include <QTextDocumentWriter>
#include <QSqlError>
#include <QDate>
#include <QDebug>
#include <QDateEdit>
#include <QTableView>
#include <QSpinBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
class QTextToSpeech;

namespace Ui {
class vehicule;
}

class vehicule : public QMainWindow
{
    Q_OBJECT

public:
    explicit vehicule(QWidget *parent = nullptr);
    ~vehicule();

public slots:
    // Slots pour les boutons
    void on_pushButton_ajouter_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_4_clicked(); // Exporter PDF
    void on_pushButton_5_clicked(); // Statistiques
    void on_pushButton_6_clicked(); // Appliquer le tri
    void on_pushButton_retour_clicked(); // Bouton retour
    void on_lineEdit_3_textChanged(const QString &arg1); // Recherche
    // Slots pour les boutons principaux
    void on_pb_stat_clicked();
    void on_pb_pdf_clicked();
    void on_pushButton_pdf_clicked();
    void on_pb_calendar_clicked();
    void on_pb_calendar_2_clicked();

signals:
    void returnRequested(); // Signal pour revenir au menu

private slots:
    // UI Slots
    void on_tableView_clicked(const QModelIndex &index);
    void on_recherche_textChanged(const QString &arg1);

    // Fonctions pour résoudre les erreurs de compilation


    void on_pushButton_entretien_clicked();
    void on_pushButton_stats_chart_clicked();

    void on_pushButton_reco_window_clicked();
    void on_pushButton_sms_alert_clicked();

private:
    Ui::vehicule *ui;
    QSqlTableModel *model;
    QSortFilterProxyModel *proxyModel;
    int selectedRow;
    QTimer *timer;
    QTextToSpeech *tts;

    // Mapping des colonnes de la base de données
    QMap<QString, int> columnMapping;

    // Méthodes d'initialisation
    void setupModel();
    void refreshTable();
    void analyzeDatabaseSchema();

    // Méthodes utilitaires
    void clearFields();
    void applyAdvancedFilters();


    // Méthodes de gestion des erreurs
    void afficherErreur(const QString &message);
};

#endif // VEHICULE_H
