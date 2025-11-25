#ifndef MONITEUR_UI_H
#define MONITEUR_UI_H

#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QDialog>
#include <QVBoxLayout>

namespace Ui {
class moniteur;
}

class moniteur_ui : public QMainWindow {
    Q_OBJECT

public:
    explicit moniteur_ui(QWidget *parent = nullptr);
    ~moniteur_ui();

private slots:
    void onAjouterClicked();
    void onModifierClicked();
    void onSupprimerClicked();
    void onExporterPdfClicked();
    void onRechercheTextChanged(const QString &text);
    void onStatistiquesClicked();
    void onTriClicked();

    // Nouveaux slots pour les métiers avancés
    void onReussiteClicked(); // bouton "reussite"
    void onAffecterClicked();    // <-- déclarer ici

private:
    Ui::moniteur *ui;
    void resetFields();   // Vider les champs
    bool checkFields();   // Vérifier chaque champ individuellement
};

#endif // MONITEUR_UI_H
