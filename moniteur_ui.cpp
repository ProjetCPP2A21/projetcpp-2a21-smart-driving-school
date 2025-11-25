#include "moniteur_ui.h"
#include "ui_moniteur.h"
#include "moniteur.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QInputDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QDialog>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlError>


moniteur_ui::moniteur_ui(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::moniteur)
{
    ui->setupUi(this);

    moniteur::afficherMoniteurs(ui->table);

    connect(ui->ajouter, &QPushButton::clicked, this, &moniteur_ui::onAjouterClicked);
    connect(ui->modifier, &QPushButton::clicked, this, &moniteur_ui::onModifierClicked);
    connect(ui->suprimer, &QPushButton::clicked, this, &moniteur_ui::onSupprimerClicked);
    connect(ui->pdf, &QPushButton::clicked, this, &moniteur_ui::onExporterPdfClicked);
    connect(ui->stat, &QPushButton::clicked, this, &moniteur_ui::onStatistiquesClicked);
    connect(ui->tri, &QPushButton::clicked, this, &moniteur_ui::onTriClicked);
    connect(ui->rechercher, &QLineEdit::textChanged, this, &moniteur_ui::onRechercheTextChanged);

    // Connexions des deux nouveaux boutons (noms : reussite, valider)
    // Assure-toi que dans le designer leurs objectName sont bien "reussite" et "valider"
    if (ui->reussite) connect(ui->reussite, &QPushButton::clicked, this, &moniteur_ui::onReussiteClicked);
    if (ui->AffectationAuto)  connect(ui->AffectationAuto,  &QPushButton::clicked, this, &moniteur_ui::onAffecterClicked);
}

moniteur_ui::~moniteur_ui() {
    delete ui;
}

void moniteur_ui::resetFields() {
    ui->ID->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->telephone->clear();
    ui->spec->setCurrentIndex(0);
    ui->disp->setCurrentIndex(0);
    ui->heur->setValue(0);
}

bool moniteur_ui::checkFields() {
    QRegularExpression regexNum("^[0-9]+$");
    QRegularExpression regexAlpha("^[A-Za-z\\s]+$");

    if (ui->ID->text().isEmpty() || !regexNum.match(ui->ID->text()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "ID invalide.");
        return false;
    }
    if (ui->nom->text().isEmpty() || !regexAlpha.match(ui->nom->text()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Nom invalide.");
        return false;
    }
    if (ui->prenom->text().isEmpty() || !regexAlpha.match(ui->prenom->text()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Prénom invalide.");
        return false;
    }
    if (ui->telephone->text().isEmpty() || !regexNum.match(ui->telephone->text()).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Téléphone invalide.");
        return false;
    }
    return true;
}

void moniteur_ui::onAjouterClicked() {
    if (!checkFields()) return;
    if (moniteur::ajouterMoniteur(ui)) {
        QMessageBox::information(this, "Ajout", "Moniteur ajouté !");
        moniteur::afficherMoniteurs(ui->table);
        resetFields();
    }
}

void moniteur_ui::onModifierClicked() {
    // Vérifier que l'ID est rempli
    if (ui->ID->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer l'ID du moniteur à modifier !");
        return;
    }

    // Vérifier que l'ID est numérique
    bool okConv = false;
    ui->ID->text().trimmed().toInt(&okConv);
    if (!okConv) {
        QMessageBox::warning(this, "Erreur", "ID invalide !");
        return;
    }

    // Modifier le moniteur en laissant les champs vides inchangés
    if (moniteur::modifierMoniteur(ui)) {
        QMessageBox::information(this, "Modification", "Moniteur modifié avec succès !");
        moniteur::afficherMoniteurs(ui->table); // rafraîchir le tableau
        resetFields(); // vider les champs
    } else {
        QMessageBox::warning(this, "Erreur", "Aucun champ modifié ou ID introuvable.");
    }
}


void moniteur_ui::onSupprimerClicked() {
    // Vérifier que l'ID est rempli
    if (ui->ID->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer l'ID !");
        return;
    }

    // Vérifier que l'ID est numérique
    bool okConv = false;
    int id = ui->ID->text().trimmed().toInt(&okConv);
    if (!okConv) {
        QMessageBox::warning(this, "Erreur", "ID invalide !");
        return;
    }

    // Supprimer le moniteur
    if (moniteur::supprimerMoniteur(ui)) {
        QMessageBox::information(this, "Suppression", "Moniteur supprimé !");
        moniteur::afficherMoniteurs(ui->table);
        resetFields();
    } else {
        QMessageBox::warning(this, "Erreur", "ID introuvable, suppression échouée.");
    }
}

void moniteur_ui::onExporterPdfClicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty())
        return;

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize::A4);

    QTextDocument doc;
    QString html = "<html><head><meta charset='UTF-8'></head><body>";
    html += "<h1 align='center'>Liste des Moniteurs</h1>";
    html += "<table border='1' cellpadding='5' cellspacing='0' width='100%'>";
    html += "<tr>"
            "<th>ID</th>"
            "<th>Nom</th>"
            "<th>Prénom</th>"
            "<th>Téléphone</th>"
            "<th>Spécialité</th>"
            "<th>Disponibilité</th>"
            "<th>Heures</th>"
            "</tr>";

    // Remplir les lignes à partir de la table UI
    for (int row = 0; row < ui->table->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < ui->table->columnCount(); ++col) {
            QTableWidgetItem* item = ui->table->item(row, col);
            html += "<td>" + QString(item ? item->text() : "") + "</td>";
        }
        html += "</tr>";
    }

    html += "</table></body></html>";

    doc.setHtml(html);
    doc.print(&printer);

    QMessageBox::information(this, "Succès", "PDF exporté avec succès.");
}



void moniteur_ui::onRechercheTextChanged(const QString &text) {
    for (int row = 0; row < ui->table->rowCount(); ++row) {
        bool match = false;
        for (int col = 0; col < ui->table->columnCount(); ++col) {
            if (ui->table->item(row, col)->text().contains(text, Qt::CaseInsensitive)) {
                match = true;
                break;
            }
        }
        ui->table->setRowHidden(row, !match);
    }
}

void moniteur_ui::onTriClicked() {
    ui->table->setSortingEnabled(true);
    ui->table->sortItems(1, Qt::AscendingOrder);
    QMessageBox::information(this, "Tri", "Tri par Nom effectué !");
}

void moniteur_ui::onStatistiquesClicked() {
    int codeCount = 0, conduiteCount = 0;

    // Comptage des spécialités
    for (int row = 0; row < ui->table->rowCount(); ++row) {
        QString spec = ui->table->item(row, 4)->text().trimmed().toLower();
        if (spec == "code") codeCount++;
        else if (spec == "conduite") conduiteCount++;
    }

    // Stockage dans QMap pour itération facile
    QMap<QString, int> stats;
    stats["Code"] = codeCount;
    stats["Conduite"] = conduiteCount;

    int total = codeCount + conduiteCount;

    // Création de la série pour le diagramme
    QPieSeries* series = new QPieSeries();
    series->setHoleSize(0.25);  // Donut léger

    for (auto it = stats.begin(); it != stats.end(); ++it) {
        double pourcentage = (it.value() * 100.0) / total;
        QString label = it.key() + " (" + QString::number(it.value()) +
                        ") : " + QString::number(pourcentage, 'f', 1) + "%";

        QPieSlice* slice = series->append(label, it.value());
        slice->setLabelVisible(true);

        // Couleurs
        if (it.key() == "Code") slice->setBrush(QColor("#43cea2"));
        else if (it.key() == "Conduite") slice->setBrush(QColor("#185a9d"));

        // Animation sur survol
        slice->setExploded(false);
        QObject::connect(slice, &QPieSlice::hovered, [slice](bool state){
            slice->setExploded(state);
            slice->setLabelVisible(true);
        });
    }

    // Création du chart
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setBackgroundVisible(false);
    chart->setPlotAreaBackgroundVisible(false);
    chart->setTitle("Répartition des moniteurs selon la spécialité");
    chart->setTitleFont(QFont("Segoe UI", 14, QFont::Bold));
    chart->setTitleBrush(QBrush(QColor("#185a9d")));
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->legend()->setFont(QFont("Segoe UI", 10, QFont::Bold));
    chart->legend()->setLabelColor(QColor("#185a9d"));

    // Affichage
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QDialog* dialog = new QDialog(this);
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);

    dialog->setWindowTitle("Statistiques");
    dialog->resize(550, 450);
    dialog->exec();
}


// ------------------ Slot : calcul du taux de réussite ------------------
void moniteur_ui::onReussiteClicked() {
    if (!ui->ID || ui->ID->text().trimmed().isEmpty()) {
        QDialog* dialog = new QDialog(this);
        QVBoxLayout* layout = new QVBoxLayout(dialog);
        QLabel* label = new QLabel("Veuillez entrer l'ID du moniteur (champ ID).");
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("font-size: 14px; color: #d32f2f;"); // rouge moderne
        layout->addWidget(label);
        dialog->setWindowTitle("Erreur");
        dialog->resize(400, 150);
        dialog->exec();
        return;
    }

    bool okConv = false;
    int id = ui->ID->text().trimmed().toInt(&okConv);
    if (!okConv) {
        QDialog* dialog = new QDialog(this);
        QVBoxLayout* layout = new QVBoxLayout(dialog);
        QLabel* label = new QLabel("ID moniteur invalide.");
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("font-size: 14px; color: #d32f2f;");
        layout->addWidget(label);
        dialog->setWindowTitle("Erreur");
        dialog->resize(400, 150);
        dialog->exec();
        return;
    }

    double taux = moniteur::tauxReussite(id);
    QString msg;
    if (taux <= 0.0)
        msg = QString("Aucun examen trouvé pour le moniteur %1 ou taux = 0%.").arg(id);
    else
        msg = QString("Taux de réussite du moniteur %1 : %2 %").arg(id).arg(QString::number(taux, 'f', 2));

    QDialog* dialog = new QDialog(this);
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* label = new QLabel(msg);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 14px; color: #185a9d; font-weight: bold;");
    layout->addWidget(label);
    dialog->setWindowTitle("Taux de réussite");
    dialog->resize(450, 150);
    dialog->exec();
}


// ------------------ Slot : validation d'un véhicule ------------------
void moniteur_ui::onAffecterClicked() {
    bool ok = false;
    int idMoniteur = QInputDialog::getInt(this, "Affectation automatique",
                                          "Entrez l'ID du moniteur :", 1, 1, 1000000000, 1, &ok);
    if (!ok) return;

    // 1️⃣ Vérifier disponibilité du moniteur
    QSqlQuery queryMon;
    queryMon.prepare("SELECT DISPONIBILITE FROM MONITEUR WHERE ID = :id");
    queryMon.bindValue(":id", idMoniteur);
    if (!queryMon.exec() || !queryMon.next()) {
        QMessageBox::warning(this, "Erreur", "Moniteur introuvable.");
        return;
    }
    QString dispoMon = queryMon.value(0).toString().trimmed().toLower();
    if (dispoMon != "oui" && dispoMon != "disponible") {
        QMessageBox::warning(this, "Indisponible", "Le moniteur n'est pas disponible.");
        return;
    }

    // 2️⃣ Chercher un véhicule disponible selon critères
    int idVehicule = -1;
    QString marqueVehicule;
    QSqlQuery queryVeh;
    queryVeh.prepare("SELECT ID_VEHICULE, MARQUE FROM VEHICULES "
                     "WHERE DISPONIBILITE IN ('oui','disponible') "
                     "AND ETAT IN ('bon','ok') AND CAPACITE >= 4 "
                     "ORDER BY KILOMETRAGE ASC LIMIT 1");
    if (!queryVeh.exec() || !queryVeh.next()) {
        // Aucun véhicule disponible
        QDialog* dialog = new QDialog(this);
        QVBoxLayout* layout = new QVBoxLayout(dialog);
        QLabel* label = new QLabel("Aucun véhicule disponible pour ce moniteur.");
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("font-size:14px;color:#d32f2f;font-weight:bold;");
        layout->addWidget(label);
        dialog->setWindowTitle("Affectation impossible");
        dialog->resize(450, 150);
        dialog->exec();
        return;
    }
    idVehicule = queryVeh.value("ID_VEHICULE").toInt();
    marqueVehicule = queryVeh.value("MARQUE").toString();

    // 3️⃣ Effectuer l'affectation automatique (comme IA)
    // Marquer le véhicule comme "non disponible"
    QSqlQuery updateVeh;
    updateVeh.prepare("UPDATE VEHICULES SET DISPONIBILITE='non' WHERE ID_VEHICULE=:id");
    updateVeh.bindValue(":id", idVehicule);
    updateVeh.exec();

    // Marquer le moniteur comme "occupé"
    QSqlQuery updateMon;
    updateMon.prepare("UPDATE MONITEURS SET DISPONIBILITE='non' WHERE ID=:id");
    updateMon.bindValue(":id", idMoniteur);
    updateMon.exec();

    // 4️⃣ Affichage du résultat dans un QDialog moderne
    QDialog* dialog = new QDialog(this);
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* label = new QLabel(
        QString("Moniteur ID %1 affecté au véhicule %2 (ID %3) avec succès !")
            .arg(idMoniteur)
            .arg(marqueVehicule)
            .arg(idVehicule)
        );
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size:14px;color:#43cea2;font-weight:bold;");
    layout->addWidget(label);
    dialog->setWindowTitle("Affectation réussie");
    dialog->resize(500, 150);
    dialog->exec();
}
