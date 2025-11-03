#include "apprenants.h"
#include "ui_apprenants.h"
#include "apprenant.h"
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QVBoxLayout>
#include <QDate>

apprenants::apprenants(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::apprenants)
{
    ui->setupUi(this);
    afficherApprenants();
}

apprenants::~apprenants()
{
    delete ui;
}

// -------------------- AFFICHER --------------------
void apprenants::afficherApprenants()
{
    Apprenant a;
    ui->tableView_apprenants->setModel(a.afficher());
}

// -------------------- AJOUTER --------------------
void apprenants::on_pushButton_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QDate dateNaissance = ui->dateEdit_naissance->date();
    int age = dateNaissance.daysTo(QDate::currentDate()) / 365;
    if(age < 18){
        QMessageBox::warning(this,"Âge insuffisant","L'apprenant doit avoir au moins 18 ans !");
        return;
    }
    QString dateN = dateNaissance.toString("dd/MM/yyyy");
    QString tel = ui->lineEdit_telephone->text();
    QString sexe = ui->comboBox_sexe->currentText();
    QString adresse = ui->lineEdit_adresse->text();

    Apprenant a(id, nom, prenom, dateN, tel, sexe, adresse);
    if(a.ajouter()){
        QMessageBox::information(this, "Ajout", "Apprenant ajouté avec succès !");
        afficherApprenants();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout.");
    }
}

// -------------------- MODIFIER --------------------
void apprenants::on_pushButton_modifier_clicked()
{
    int ancienId = ui->lineEdit_id->text().toInt();
    int nouvelId = ui->lineEdit_id->text().toInt(); // possibilité modifier ID
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QDate dateNaissance = ui->dateEdit_naissance->date();
    int age = dateNaissance.daysTo(QDate::currentDate()) / 365;
    if(age < 18){
        QMessageBox::warning(this,"Âge insuffisant","L'apprenant doit avoir au moins 18 ans !");
        return;
    }
    QString dateN = dateNaissance.toString("dd/MM/yyyy");
    QString tel = ui->lineEdit_telephone->text();
    QString sexe = ui->comboBox_sexe->currentText();
    QString adresse = ui->lineEdit_adresse->text();

    Apprenant a(ancienId, nom, prenom, dateN, tel, sexe, adresse);
    if(a.modifierAvecID(nouvelId)){
        QMessageBox::information(this,"Modification","Apprenant modifié !");
        afficherApprenants();
    } else {
        QMessageBox::critical(this,"Erreur","Échec de la modification !");
    }
}

// -------------------- SUPPRIMER --------------------
void apprenants::on_pushButton_supprimer_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    Apprenant a;
    if(a.supprimer(id)){
        QMessageBox::information(this, "Suppression", "Apprenant supprimé !");
        afficherApprenants();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
    }
}

// -------------------- TRI --------------------
void apprenants::on_pushButton_trier_clicked()
{
    static bool ordreCroissant = true;

    Apprenant a;
    if(ordreCroissant)
        ui->tableView_apprenants->setModel(a.trierParPrenomCroissant());
    else
        ui->tableView_apprenants->setModel(a.trierParPrenomDecroissant());

    ordreCroissant = !ordreCroissant;
}

// -------------------- RECHERCHE --------------------
void apprenants::on_lineEdit_recherche_textChanged(const QString &arg1)
{
    Apprenant a;
    if(arg1.isEmpty())
        afficherApprenants();
    else
        ui->tableView_apprenants->setModel(a.rechercher(arg1.toInt()));
}

// -------------------- EXPORTER PDF --------------------
void apprenants::on_pushButton_exporterPDF_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "*.pdf");
    if(fileName.isEmpty()) return;

    QPdfWriter pdf(fileName);
    pdf.setPageSize(QPageSize::A4);
    pdf.setPageMargins(QMargins(20,20,20,20));

    QPainter painter(&pdf);
    painter.setRenderHint(QPainter::Antialiasing);

    QFont titreFont("Arial", 14, QFont::Bold);
    painter.setFont(titreFont);
    painter.drawText(200, 50, "Liste des Apprenants");

    QAbstractItemModel *model = ui->tableView_apprenants->model();

    int y = 100;
    int ligneHeight = 30;
    int colonneWidth = 100;
    int xStart = 50;

    // Entêtes
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    int x = xStart;
    for(int col = 0; col < model->columnCount(); col++){
        painter.drawRect(x, y, colonneWidth, ligneHeight);
        painter.drawText(x + 5, y + 20, model->headerData(col, Qt::Horizontal).toString());
        x += colonneWidth;
    }
    y += ligneHeight;

    // Données
    painter.setFont(QFont("Arial", 10));
    for(int row = 0; row < model->rowCount(); row++){
        x = xStart;
        for(int col = 0; col < model->columnCount(); col++){
            painter.drawRect(x, y, colonneWidth, ligneHeight);
            painter.drawText(x + 5, y + 20, model->index(row, col).data().toString());
            x += colonneWidth;
        }
        y += ligneHeight;

        // Nouvelle page si on dépasse
        if(y > pdf.height() - 50){
            pdf.newPage();
            y = 50;
        }
    }

    painter.end();
    QMessageBox::information(this, "PDF", "Exportation réussie !");
}

// -------------------- STATISTIQUES --------------------
void apprenants::on_pushButton_statistique_clicked()
{
    Apprenant a;
    QMap<QString,int> stats = a.statistiquesSexe();
    int total = 0;
    for(auto val: stats) total += val;

    QPieSeries *series = new QPieSeries();
    for(auto it = stats.begin(); it != stats.end(); ++it){
        double pourcentage = (it.value() * 100.0)/total;
        QString label = it.key() + " (" + QString::number(it.value()) + ") : " + QString::number(pourcentage,'f',1) + "%";
        QPieSlice *slice = series->append(label, it.value());
        slice->setLabelVisible(true);
        if(it.key() == "Femme") slice->setBrush(Qt::magenta);
        else slice->setBrush(Qt::blue);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des apprenants selon le sexe");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QDialog *dialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);
    dialog->setLayout(layout);
    dialog->setWindowTitle("Statistiques");
    dialog->resize(500,400);
    dialog->exec();
}

// -------------------- SELECTION LIGNE --------------------
void apprenants::on_tableView_apprenants_clicked(const QModelIndex &index)
{
    if(!index.isValid()) return;

    QAbstractItemModel *model = ui->tableView_apprenants->model();

    ui->lineEdit_id->setText(model->index(index.row(),0).data().toString());
    ui->lineEdit_nom->setText(model->index(index.row(),1).data().toString());
    ui->lineEdit_prenom->setText(model->index(index.row(),2).data().toString());

    QString dateStr = model->index(index.row(),3).data().toString();
    QDate date = QDate::fromString(dateStr,"dd/MM/yyyy");
    if(date.isValid()) ui->dateEdit_naissance->setDate(date);

    ui->lineEdit_telephone->setText(model->index(index.row(),4).data().toString());
    ui->comboBox_sexe->setCurrentText(model->index(index.row(),5).data().toString());
    ui->lineEdit_adresse->setText(model->index(index.row(),6).data().toString());
}
