#ifndef MONITEUR_UI_H
#define MONITEUR_UI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_END_NAMESPACE

namespace Ui {
class moniteur;
}

class moniteur_ui : public QMainWindow {
    Q_OBJECT

public:
    explicit moniteur_ui(QWidget *parent = nullptr);
    ~moniteur_ui();

signals:
    void returnRequested();

private slots:
    void onAjouterClicked();
    void onModifierClicked();
    void onSupprimerClicked();
    void onExporterPdfClicked();
    void onRechercheTextChanged(const QString &text);
    void onStatistiquesClicked();
    void onTriClicked();
    void onRetourClicked();
    void onTauxReussiteClicked(); // Nouveau slot pour le taux de réussite
    void onAffecterVehiculeClicked(); // Nouveau slot pour affecter un véhicule

private:
    Ui::moniteur *ui;
    QChartView *m_chartView;  // Widget pour afficher le graphique
    bool m_statisticsVisible; // État d'affichage des statistiques
    void resetFields();   // Vider les champs
    bool checkFields();   // Vérifier chaque champ individuellement
    void setupStatisticsChart(); // Créer et configurer le graphique
    void showStatistics(); // Afficher les statistiques
    void hideStatistics(); // Masquer les statistiques
    void applyModernStyle();
};

#endif // MONITEUR_UI_H
