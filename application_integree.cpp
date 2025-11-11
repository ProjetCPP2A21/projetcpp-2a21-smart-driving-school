#include "application_integree.h"
#include "ui_application_integree.h"
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QVBoxLayout>
#include <QDate>
#include <QTime>
#include <QRegularExpression>
#include <QRect>
#include <QPageLayout>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QDateTime>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QItemSelectionModel>
#include <QPageSize>
#include <QMap>
#include <QAbstractItemView>

application_integree::application_integree(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::application_integree)
    , selectedIdExamen(0)
    , selectedRowVehicule(-1)
    , modelVehicules(nullptr)
{
    ui->setupUi(this);
    
    // Démarre sur la page de connexion
    ui->stackedWidget->setCurrentIndex(0);
    
    // Masquer le mot de passe
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    
    // Initialisation de la page Apprenants
    ui->dateEdit_naissance->setDate(QDate::currentDate().addYears(-18));
    afficherApprenants();
    
    // Initialisation de la page Examens
    ui->tableView_examens->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_examens->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_examens->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_examens->setModel(Examen().afficher());
    
    // Connexions pour la recherche et le tri des examens
    connect(ui->lineEdit_rechercheType, &QLineEdit::textChanged, this, &application_integree::rechercherParType);
    connect(ui->comboBox_triDate, &QComboBox::currentTextChanged, this, &application_integree::trierDate);
    connect(ui->pushButton_stats, &QPushButton::clicked, this, &application_integree::afficherStatistiques);
    
    // Initialisation de la page Véhicules
    setupModelVehicules();
    afficherVehicules();
}

application_integree::~application_integree()
{
    delete ui;
}

// ==================== PAGE LOGIN ====================
void application_integree::on_pushButton_login_clicked()
{
    QString email = ui->lineEdit_email->text().trimmed();
    QString password = ui->lineEdit_password->text().trimmed();

    if (email == "smart.drivingschool@esprit.tn" && password == "0000")
    {
        QMessageBox::information(this, "Connexion réussie", "Bienvenue !");
        ui->stackedWidget->setCurrentIndex(1); // Page menu
        ui->lineEdit_email->clear();
        ui->lineEdit_password->clear();
    }
    else
    {
        QMessageBox::warning(this, "Erreur", "Email ou mot de passe incorrect !");
    }
}

// ==================== MENU PRINCIPAL ====================
void application_integree::on_pushButton_apprenants_clicked()
{
    ui->stackedWidget->setCurrentIndex(3); // Page Apprenants (index 3)
    afficherApprenants();
}

void application_integree::on_Bapprenant_clicked()
{
    ui->stackedWidget->setCurrentIndex(3); // Page Apprenants (index 3)
    afficherApprenants();
}

void application_integree::on_pushButton_examens_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); // Page Examens (index 2)
    ui->tableView_examens->setModel(Examen().afficher());
    ui->tableView_examens->clearSelection();
}

void application_integree::on_pushButton_vehicules_clicked()
{
    ui->stackedWidget->setCurrentIndex(4); // Page Véhicules (index 4)
    afficherVehicules();
    ui->tableView_vehicules->clearSelection();
}

// ==================== PAGE APPRENANTS ====================
void application_integree::afficherApprenants()
{
    Apprenant a;
    ui->tableView_apprenants->setModel(a.afficher());
}

bool application_integree::verifierSaisieApprenant(int &id, QString &nom, QString &prenom, QString &dateNaissance,
                                                    QString &tel, QString &sexe, QString &adresse)
{
    id = ui->lineEdit_id->text().toInt();
    nom = ui->lineEdit_nom->text().trimmed();
    prenom = ui->lineEdit_prenom->text().trimmed();
    dateNaissance = ui->dateEdit_naissance->date().toString("dd/MM/yyyy");
    tel = ui->lineEdit_telephone->text().trimmed();
    sexe = ui->comboBox_sexe->currentText();
    adresse = ui->lineEdit_adresse->text().trimmed();

    if(id <= 0) { QMessageBox::warning(this,"Erreur","ID invalide !"); return false; }

    QRegularExpression regexNom("^[A-Za-z\\s-]+$");
    if(nom.isEmpty() || !regexNom.match(nom).hasMatch()){ QMessageBox::warning(this,"Erreur","Nom invalide !"); return false; }
    if(prenom.isEmpty() || !regexNom.match(prenom).hasMatch()){ QMessageBox::warning(this,"Erreur","Prénom invalide !"); return false; }

    QDate naissance = ui->dateEdit_naissance->date();
    if(naissance.daysTo(QDate::currentDate())/365 < 18){ QMessageBox::warning(this,"Erreur","L'apprenant doit avoir au moins 18 ans !"); return false; }

    QRegularExpression regexTel("^\\d{8,15}$");
    if(!regexTel.match(tel).hasMatch()){ QMessageBox::warning(this,"Erreur","Téléphone invalide !"); return false; }

    if(adresse.isEmpty()){ QMessageBox::warning(this,"Erreur","Adresse vide !"); return false; }

    return true;
}

void application_integree::on_pushButton_ajouter_apprenant_clicked()
{
    int id; QString nom, prenom, dateNaissance, tel, sexe, adresse;
    if(!verifierSaisieApprenant(id, nom, prenom, dateNaissance, tel, sexe, adresse)) return;

    Apprenant a(id, nom, prenom, dateNaissance, tel, sexe, adresse);
    if(a.ajouter()){
        QMessageBox::information(this, "Ajout", "Apprenant ajouté avec succès !");
        afficherApprenants();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout.");
    }
}

void application_integree::on_pushButton_modifier_apprenant_clicked()
{
    int id; QString nom, prenom, dateNaissance, tel, sexe, adresse;
    if(!verifierSaisieApprenant(id, nom, prenom, dateNaissance, tel, sexe, adresse)) return;

    Apprenant a(id, nom, prenom, dateNaissance, tel, sexe, adresse);
    if(a.modifier()){
        QMessageBox::information(this,"Modification","Apprenant modifié !");
        afficherApprenants();
    } else {
        QMessageBox::critical(this,"Erreur","Échec de la modification !");
    }
}

void application_integree::on_pushButton_supprimer_apprenant_clicked()
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

void application_integree::on_pushButton_trier_apprenant_clicked()
{
    static bool ordreCroissant = true;
    Apprenant a;
    if(ordreCroissant)
        ui->tableView_apprenants->setModel(a.trierParPrenomCroissant());
    else
        ui->tableView_apprenants->setModel(a.trierParPrenomDecroissant());
    ordreCroissant = !ordreCroissant;
}

void application_integree::on_lineEdit_recherche_apprenant_textChanged(const QString &arg1)
{
    Apprenant a;
    if(arg1.isEmpty())
        afficherApprenants();
    else
        ui->tableView_apprenants->setModel(a.rechercher(arg1));
}

void application_integree::on_pushButton_exporterPDF_apprenant_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "*.pdf");
    if(fileName.isEmpty()) return;

    QAbstractItemModel* model = ui->tableView_apprenants->model();
    if(!model || model->rowCount() == 0){
        QMessageBox::warning(this, "Erreur", "Aucune donnée à exporter !");
        return;
    }

    QPdfWriter pdf(fileName);
    pdf.setPageSize(QPageSize::A4);
    pdf.setPageMargins(QMargins(20, 20, 20, 20), QPageLayout::Millimeter);
    
    QPainter painter(&pdf);
    if(!painter.isActive()){
        QMessageBox::critical(this, "Erreur", "Impossible de créer le fichier PDF !");
        return;
    }

    int pageWidth = pdf.width();
    int pageHeight = pdf.height();
    int margin = 20;
    int y = margin;
    int ligneHeight = 30;
    int headerHeight = 30;
    int xStart = margin;
    
    int nbColonnes = model->columnCount();
    QList<int> colonneWidths;
    int totalWidth = pageWidth - 2 * margin;
    
    if(nbColonnes == 7){
        colonneWidths << (int)(totalWidth * 0.08);
        colonneWidths << (int)(totalWidth * 0.15);
        colonneWidths << (int)(totalWidth * 0.15);
        colonneWidths << (int)(totalWidth * 0.12);
        colonneWidths << (int)(totalWidth * 0.12);
        colonneWidths << (int)(totalWidth * 0.08);
        colonneWidths << (int)(totalWidth * 0.30);
    } else {
        int baseWidth = totalWidth / nbColonnes;
        for(int i = 0; i < nbColonnes; i++){
            colonneWidths.append(baseWidth);
        }
    }

    QFont titleFont("Arial", 24, QFont::Bold);
    painter.setFont(titleFont);
    painter.setPen(QPen(Qt::black, 2));
    QRect titleRect(0, 30, pageWidth, 50);
    painter.drawText(titleRect, Qt::AlignCenter | Qt::AlignVCenter, "LISTE DES APPRENANTS");
    y = 90;

    QFont headerFont("Arial", 11, QFont::Bold);
    painter.setFont(headerFont);
    painter.setPen(QPen(QColor(200, 200, 200), 1));
    
    int x = xStart;
    int headerY = y;
    for(int col = 0; col < nbColonnes; col++){
        QRect headerRect(x, headerY, colonneWidths[col], headerHeight);
        painter.setPen(QPen(QColor(200, 200, 200), 1));
        painter.drawRect(headerRect);
        
        QString header = model->headerData(col, Qt::Horizontal).toString();
        QRect textRect(x + 8, headerY + 8, colonneWidths[col] - 16, headerHeight - 16);
        painter.setPen(QPen(Qt::black, 1));
        painter.drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, header);
        x += colonneWidths[col];
    }
    y = headerY + headerHeight + 2;

    QFont dataFont("Arial", 10);
    painter.setFont(dataFont);
    painter.setPen(QPen(Qt::black, 1));
    
    bool alternerCouleur = false;
    for(int row = 0; row < model->rowCount(); row++){
        int rowY = y;
        int maxHeight = ligneHeight;
        int x = xStart;
        for(int col = 0; col < nbColonnes; col++){
            QString text = model->index(row, col).data().toString();
            QRect textRect(x + 8, rowY + 8, colonneWidths[col] - 16, 1000);
            QRect boundingRect = painter.boundingRect(textRect, Qt::AlignLeft | Qt::AlignTop | Qt::TextWordWrap, text);
            int textHeight = boundingRect.height() + 16;
            if(textHeight > maxHeight){
                maxHeight = textHeight;
            }
            x += colonneWidths[col];
        }
        
        if(y + maxHeight > pageHeight - margin){
            pdf.newPage();
            y = 90;
            
            painter.setFont(titleFont);
            QRect titleRect2(0, 30, pageWidth, 50);
            painter.drawText(titleRect2, Qt::AlignCenter | Qt::AlignVCenter, "LISTE DES APPRENANTS");
            
            painter.setFont(headerFont);
            x = xStart;
            headerY = y;
            for(int col = 0; col < nbColonnes; col++){
                QRect headerRect2(x, headerY, colonneWidths[col], headerHeight);
                painter.setPen(QPen(QColor(200, 200, 200), 1));
                painter.drawRect(headerRect2);
                QString header = model->headerData(col, Qt::Horizontal).toString();
                QRect textRect2(x + 8, headerY + 8, colonneWidths[col] - 16, headerHeight - 16);
                painter.setPen(QPen(Qt::black, 1));
                painter.drawText(textRect2, Qt::AlignLeft | Qt::AlignVCenter, header);
                x += colonneWidths[col];
            }
            y = headerY + headerHeight + 2;
            painter.setFont(dataFont);
            alternerCouleur = false;
        }
        
        x = xStart;
        for(int col = 0; col < nbColonnes; col++){
            QRect cellRect(x, rowY, colonneWidths[col], maxHeight);
            
            painter.setPen(QPen(QColor(200, 200, 200), 1));
            painter.drawRect(cellRect);
            
            QString text = model->index(row, col).data().toString();
            QRect textRect(x + 8, rowY + 8, colonneWidths[col] - 16, maxHeight - 16);
            painter.setPen(QPen(Qt::black, 1));
            painter.drawText(textRect, Qt::AlignLeft | Qt::AlignTop | Qt::TextWordWrap, text);
            x += colonneWidths[col];
        }
        y = rowY + maxHeight + 2;
        alternerCouleur = !alternerCouleur;
    }

    painter.end();
    QMessageBox::information(this, "PDF", "Exportation réussie !");
}

void application_integree::on_pushButton_statistique_apprenant_clicked()
{
    Apprenant a;
    QMap<QString,int> stats = a.statistiquesSexe();
    int total = 0; for(auto val: stats) total += val;

    QPieSeries* series = new QPieSeries();
    for(auto it=stats.begin(); it!=stats.end(); ++it){
        double pourcentage = (it.value()*100.0)/total;
        QString label = it.key()+" ("+QString::number(it.value())+") : "+QString::number(pourcentage,'f',1)+"%";
        QPieSlice* slice = series->append(label,it.value());
        slice->setLabelVisible(true);
        slice->setBrush(it.key()=="Femme"?Qt::magenta:Qt::blue);
    }

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des apprenants selon le sexe");

    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QDialog* dialog = new QDialog(this);
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);
    dialog->setLayout(layout);
    dialog->setWindowTitle("Statistiques");
    dialog->resize(500,400);
    dialog->exec();
}

void application_integree::on_tableView_apprenants_clicked(const QModelIndex &index)
{
    if(!index.isValid()) return;
    QAbstractItemModel* model = ui->tableView_apprenants->model();

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

void application_integree::on_pushButton_retour_apprenants_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); // Retour au menu
}

// ==================== PAGE EXAMENS ====================
void application_integree::on_pushButton_ajouter_examen_clicked()
{
    QString idText = ui->lineEdit_id_examen->text();
    QString type = ui->comboBox_type->currentText();
    QString date = ui->dateEdit_date->date().toString("dd/MM/yyyy");
    QString heure = ui->timeEdit_heure->time().toString("hh:mm");
    QString lieu = ui->lineEdit_lieu->text();
    QString vehicule = ui->comboBox_vehicule->currentText();
    QString resultat = ui->comboBox_resultat->currentText();

    bool ok;
    int id = idText.toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "L'ID doit être un entier !");
        return;
    }
    Examen e(id, type, date, heure, lieu, vehicule, resultat);
    if (e.ajouter()) {
        QMessageBox::information(this, "Succès", "Examen ajouté !");
        ui->tableView_examens->setModel(Examen().afficher());
        clearFieldsExamen();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout !");
    }
}

void application_integree::on_pushButton_modifier_examen_clicked()
{
    QModelIndexList selection = ui->tableView_examens->selectionModel()->selectedRows();
    if (selection.count() == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une ligne à modifier !");
        return;
    }

    int id = selection.at(0).data().toInt();
    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID non valide !");
        return;
    }

    QString type = ui->comboBox_type->currentText().trimmed();
    QString date = ui->dateEdit_date->date().toString("dd/MM/yyyy");
    QString heure = ui->timeEdit_heure->time().toString("hh:mm");
    QString lieu = ui->lineEdit_lieu->text().trimmed();
    QString vehicule = ui->comboBox_vehicule->currentText().trimmed();
    QString resultat = ui->comboBox_resultat->currentText().trimmed();

    if (type.isEmpty() || lieu.isEmpty() || vehicule.isEmpty() || resultat.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs avant de modifier !");
        return;
    }
    
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,
                                  "Confirmation",
                                  "Voulez-vous vraiment modifier cet examen ?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply != QMessageBox::Yes) return;

    Examen e(id, type, date, heure, lieu, vehicule, resultat);

    if (e.modifier()) {
        QMessageBox::information(this, "Succès", "Examen modifié avec succès !");
        ui->tableView_examens->setModel(Examen().afficher());
        clearFieldsExamen();
        selectedIdExamen = 0;
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification dans la base de données !");
    }
}

void application_integree::on_pushButton_supprimer_examen_clicked()
{
    QModelIndexList selection = ui->tableView_examens->selectionModel()->selectedRows();
    if (selection.count() == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une ligne à supprimer !");
        return;
    }

    int id = selection.at(0).data().toInt();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmer", "Voulez-vous vraiment supprimer cet examen ?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply != QMessageBox::Yes) return;
    
    if (Examen().supprimer(id)) {
        QMessageBox::information(this, "Succès", "Examen supprimé !");
        clearFieldsExamen();
        ui->tableView_examens->setModel(Examen().afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression !");
    }
}

void application_integree::on_exporterPDF_examen_clicked()
{
    QModelIndexList selectedRows = ui->tableView_examens->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner une ligne à exporter !");
        return;
    }

    int selectedRow = selectedRows.first().row();
    QAbstractItemModel *model = ui->tableView_examens->model();

    QString filePath = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichier PDF (*.pdf)");
    if (filePath.isEmpty())
        return;
    if (!filePath.endsWith(".pdf", Qt::CaseInsensitive))
        filePath += ".pdf";

    QPdfWriter pdf(filePath);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setTitle("Fiche d'examen");

    QPainter painter(&pdf);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setFont(QFont("Helvetica", 18, QFont::Bold));
    painter.drawText(2000, 1500, "Fiche d'examen");
    painter.setFont(QFont("Helvetica", 10));
    painter.drawText(2000, 1800, "Date d'exportation : " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm"));

    painter.setPen(QPen(Qt::black, 2));
    painter.drawLine(1000, 2000, 5000, 2000);

    int y = 2500;
    int lineSpacing = 500;

    painter.setFont(QFont("Helvetica", 12));

    for (int col = 0; col < model->columnCount(); ++col) {
        QString header = model->headerData(col, Qt::Horizontal).toString();
        QString data = model->data(model->index(selectedRow, col)).toString();
        painter.drawText(1200, y, header + " : " + data);
        y += lineSpacing;
    }

    painter.setPen(QPen(Qt::gray, 1, Qt::DashLine));
    painter.drawLine(1000, y + 200, 5000, y + 200);

    painter.setFont(QFont("Helvetica", 9, QFont::StyleItalic));
    painter.drawText(2000, 11000, "Document généré automatiquement - " + QDate::currentDate().toString("dd/MM/yyyy"));

    painter.end();

    QMessageBox::information(this, "Succès", "La fiche d'examen a été exportée avec succès !");
}

void application_integree::on_tableView_examens_clicked(const QModelIndex &index)
{
    if (index.column() == 0) {
        ui->tableView_examens->selectRow(index.row());

        int row = index.row();
        int id = ui->tableView_examens->model()->index(row, 0).data().toInt();
        QString type = ui->tableView_examens->model()->index(row, 1).data().toString();
        QString date = ui->tableView_examens->model()->index(row, 2).data().toString();
        QString heure = ui->tableView_examens->model()->index(row, 3).data().toString();
        QString lieu = ui->tableView_examens->model()->index(row, 4).data().toString();
        QString vehicule = ui->tableView_examens->model()->index(row, 5).data().toString();
        QString resultat = ui->tableView_examens->model()->index(row, 6).data().toString();

        ui->lineEdit_id_examen->setText(QString::number(id));
        ui->comboBox_type->setCurrentText(type);
        ui->dateEdit_date->setDate(QDate::fromString(date, "dd/MM/yyyy"));
        ui->timeEdit_heure->setTime(QTime::fromString(heure, "hh:mm"));
        ui->lineEdit_lieu->setText(lieu);
        ui->comboBox_vehicule->setCurrentText(vehicule);
        ui->comboBox_resultat->setCurrentText(resultat);
    }
}

void application_integree::rechercherParType(const QString &type)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT ID_EXAMEN, TYPE, DATE_EXAMEN, HEURE, LIEU, VEHICULE, RESULTAT "
                  "FROM EXAMEN WHERE LOWER(TYPE) LIKE LOWER(:type)");
    query.bindValue(":type", "%" + type + "%");
    query.exec();

    model->setQuery(std::move(query));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Véhicule"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Résultat"));

    ui->tableView_examens->setModel(model);
}

void application_integree::trierDate(const QString &ordre)
{
    QString direction;

    if (ordre == "Croissant")
        direction = "ASC";
    else if (ordre == "Décroissant")
        direction = "DESC";
    else
        return;

    QSqlQueryModel* model = new QSqlQueryModel();
    QString sql = QString("SELECT ID_EXAMEN, TYPE, TO_CHAR(DATE_EXAMEN, 'DD/MM/YYYY') AS DATE_EXAMEN, HEURE, LIEU, VEHICULE, RESULTAT "
                          "FROM EXAMEN ORDER BY DATE_EXAMEN %1").arg(direction);

    model->setQuery(sql);

    if (model->lastError().isValid()) {
        qDebug() << "Erreur tri:" << model->lastError().text();
        return;
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Véhicule"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Résultat"));

    ui->tableView_examens->setModel(model);
}

void application_integree::afficherStatistiques()
{
    QSqlQuery query;
    query.prepare("SELECT RESULTAT, COUNT(*) FROM EXAMEN GROUP BY RESULTAT");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les statistiques : " + query.lastError().text());
        return;
    }

    QPieSeries *series = new QPieSeries();
    while (query.next()) {
        QString resultat = query.value(0).toString();
        int count = query.value(1).toInt();
        series->append(resultat, count);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des examens selon le résultat");
    chart->legend()->setAlignment(Qt::AlignRight);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow *statWindow = new QMainWindow(this);
    statWindow->setCentralWidget(chartView);
    statWindow->resize(600, 400);
    statWindow->show();
}

void application_integree::clearFieldsExamen()
{
    ui->lineEdit_id_examen->clear();
    ui->comboBox_type->setCurrentIndex(-1);
    ui->dateEdit_date->setDate(QDate::currentDate());
    ui->timeEdit_heure->setTime(QTime::currentTime());
    ui->lineEdit_lieu->clear();
    ui->comboBox_vehicule->setCurrentIndex(-1);
    ui->comboBox_resultat->setCurrentIndex(-1);
}

void application_integree::on_pushButton_retour_examens_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); // Retour au menu
}

// ==================== PAGE VÉHICULES ====================
void application_integree::setupModelVehicules()
{
    modelVehicules = new QSqlTableModel(this);
    modelVehicules->setTable("VEHICULES");
    modelVehicules->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelVehicules->select();
    
    // Définir les en-têtes des colonnes
    if (modelVehicules->columnCount() > 0) {
        for (int i = 0; i < modelVehicules->columnCount(); ++i) {
            QString header = modelVehicules->headerData(i, Qt::Horizontal).toString();
            if (header.contains("MARQUE", Qt::CaseInsensitive))
                modelVehicules->setHeaderData(i, Qt::Horizontal, "Marque");
            else if (header.contains("IMMATRICULATION", Qt::CaseInsensitive))
                modelVehicules->setHeaderData(i, Qt::Horizontal, "Immatriculation");
            else if (header.contains("TYPE_VEHICULE", Qt::CaseInsensitive) || header.contains("TYPE", Qt::CaseInsensitive))
                modelVehicules->setHeaderData(i, Qt::Horizontal, "Type");
            else if (header.contains("KILOMETRAGE", Qt::CaseInsensitive))
                modelVehicules->setHeaderData(i, Qt::Horizontal, "Kilométrage");
            else if (header.contains("ETAT", Qt::CaseInsensitive))
                modelVehicules->setHeaderData(i, Qt::Horizontal, "État");
            else if (header.contains("DISPONIBILITE", Qt::CaseInsensitive))
                modelVehicules->setHeaderData(i, Qt::Horizontal, "Disponibilité");
            else if (header.contains("CAPACITE", Qt::CaseInsensitive))
                modelVehicules->setHeaderData(i, Qt::Horizontal, "Capacité");
        }
    }
    
    ui->tableView_vehicules->setModel(modelVehicules);
    ui->tableView_vehicules->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_vehicules->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_vehicules->setEditTriggers(QAbstractItemView::NoEditTriggers);
    
    // Masquer la colonne PHOTO
    for (int i = 0; i < modelVehicules->columnCount(); ++i) {
        if (modelVehicules->headerData(i, Qt::Horizontal).toString().toUpper() == "PHOTO") {
            ui->tableView_vehicules->setColumnHidden(i, true);
            break;
        }
    }
    
    // Remplir les combobox - Type
    ui->comboBox_type_vehicule->clear();
    ui->comboBox_type_vehicule->addItem("Berline manuelle");
    ui->comboBox_type_vehicule->addItem("Berline automatique");
    ui->comboBox_type_vehicule->addItem("SUV manuel");
    ui->comboBox_type_vehicule->addItem("SUV automatique");
    
    // État
    ui->comboBox_etat_vehicule->clear();
    ui->comboBox_etat_vehicule->addItem("Bon");
    ui->comboBox_etat_vehicule->addItem("Moyen");
    ui->comboBox_etat_vehicule->addItem("A reviser");
    
    // Disponibilité
    ui->comboBox_disponibilite_vehicule->clear();
    ui->comboBox_disponibilite_vehicule->addItem("Disponible");
    ui->comboBox_disponibilite_vehicule->addItem("Reserve");
    ui->comboBox_disponibilite_vehicule->addItem("En maintenance");
    
    // Valideur pour le champ kilométrage
    ui->lineEdit_kilometrage_vehicule->setValidator(new QIntValidator(0, 1000000, this));
    
    // Connecter le signal de sélection
    connect(ui->tableView_vehicules->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, [this]() {
                QModelIndexList selection = ui->tableView_vehicules->selectionModel()->selectedRows();
                if (!selection.isEmpty()) {
                    selectedRowVehicule = selection.first().row();
                }
            });
}

void application_integree::afficherVehicules()
{
    if (modelVehicules) {
        modelVehicules->select();
        ui->tableView_vehicules->resizeColumnsToContents();
    }
}

void application_integree::clearFieldsVehicule()
{
    ui->lineEdit_marque_vehicule->clear();
    ui->lineEdit_immatriculation_vehicule->clear();
    ui->lineEdit_kilometrage_vehicule->clear();
    ui->comboBox_type_vehicule->setCurrentIndex(0);
    ui->comboBox_etat_vehicule->setCurrentIndex(0);
    ui->comboBox_disponibilite_vehicule->setCurrentIndex(0);
    ui->lineEdit_capacite_vehicule->clear();
    selectedRowVehicule = -1;
}

void application_integree::on_pushButton_ajouter_vehicule_clicked()
{
    QString marque = ui->lineEdit_marque_vehicule->text().trimmed();
    QString immatriculation = ui->lineEdit_immatriculation_vehicule->text().trimmed();
    QString type = ui->comboBox_type_vehicule->currentText();
    QString kilometrageStr = ui->lineEdit_kilometrage_vehicule->text().trimmed();
    QString etat = ui->comboBox_etat_vehicule->currentText();
    QString disponibilite = ui->comboBox_disponibilite_vehicule->currentText();
    QString capaciteStr = ui->lineEdit_capacite_vehicule->text().trimmed();
    
    // Validation
    if (marque.isEmpty() || immatriculation.isEmpty() || kilometrageStr.isEmpty() || capaciteStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires.");
        return;
    }
    
    bool ok;
    double kilometrage = kilometrageStr.toDouble(&ok);
    if (!ok || kilometrage < 0 || kilometrage > 1000000) {
        QMessageBox::warning(this, "Erreur", "Le kilométrage doit être un nombre valide entre 0 et 1 000 000 km.");
        return;
    }

    int capacite = capaciteStr.toInt(&ok);
    if (!ok || capacite < 0 || capacite > 5) {
        QMessageBox::warning(this, "Erreur", "La capacité doit être un nombre valide entre 0 et 5.");
        return;
    }
    
    // Vérifier si l'immatriculation existe déjà
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM VEHICULES WHERE IMMATRICULATION = :immatriculation");
    checkQuery.bindValue(":immatriculation", immatriculation);
    if (checkQuery.exec() && checkQuery.next()) {
        if (checkQuery.value(0).toInt() > 0) {
            QMessageBox::warning(this, "Erreur", "Cette immatriculation existe déjà.");
            return;
        }
    }
    
    Vehicules v(marque, immatriculation, type, kilometrage, etat, disponibilite, capacite);
    
    if (v.ajouter()) {
        QMessageBox::information(this, "Succès", "Véhicule ajouté avec succès.");
        afficherVehicules();
        clearFieldsVehicule();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout du véhicule.");
    }
}

void application_integree::on_pushButton_modifier_vehicule_clicked()
{
    if (selectedRowVehicule < 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un véhicule à modifier.");
        return;
    }
    
    QString marque = ui->lineEdit_marque_vehicule->text().trimmed();
    QString immatriculation = ui->lineEdit_immatriculation_vehicule->text().trimmed();
    QString type = ui->comboBox_type_vehicule->currentText();
    QString kilometrageStr = ui->lineEdit_kilometrage_vehicule->text().trimmed();
    QString etat = ui->comboBox_etat_vehicule->currentText();
    QString disponibilite = ui->comboBox_disponibilite_vehicule->currentText();
    QString capaciteStr = ui->lineEdit_capacite_vehicule->text().trimmed();
    
    if (marque.isEmpty() || immatriculation.isEmpty() || kilometrageStr.isEmpty() || capaciteStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires.");
        return;
    }
    
    bool ok;
    double kilometrage = kilometrageStr.toDouble(&ok);
    if (!ok || kilometrage < 0 || kilometrage > 1000000) {
        QMessageBox::warning(this, "Erreur", "Le kilométrage doit être un nombre valide entre 0 et 1 000 000 km.");
        return;
    }

    int capacite = capaciteStr.toInt(&ok);
    if (!ok || capacite < 0 || capacite > 5) {
        QMessageBox::warning(this, "Erreur", "La capacité doit être un nombre valide entre 0 et 5.");
        return;
    }
    
    // Trouver la colonne d'immatriculation
    int immatriculationCol = -1;
    for (int i = 0; i < modelVehicules->columnCount(); ++i) {
        QString header = modelVehicules->headerData(i, Qt::Horizontal).toString().toUpper();
        if (header.contains("IMMATRICULATION")) {
            immatriculationCol = i;
            break;
        }
    }
    
    if (immatriculationCol == -1) {
        QMessageBox::critical(this, "Erreur", "Colonne immatriculation non trouvée.");
        return;
    }
    
    // Récupérer l'ancienne immatriculation
    QString oldImmatriculation = modelVehicules->data(modelVehicules->index(selectedRowVehicule, immatriculationCol)).toString();
    
    Vehicules v;
    v.setMarque(marque);
    v.setImmatriculation(immatriculation);
    v.setType(type);
    v.setKilometrage(kilometrage);
    v.setEtat(etat);
    v.setDisponibilite(disponibilite);
    v.setCapacite(capacite);
    
    if (v.modifier(oldImmatriculation)) {
        QMessageBox::information(this, "Succès", "Véhicule modifié avec succès.");
        afficherVehicules();
        clearFieldsVehicule();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification du véhicule.");
    }
}

void application_integree::on_pushButton_supprimer_vehicule_clicked()
{
    if (selectedRowVehicule < 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un véhicule à supprimer.");
        return;
    }
    
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation", 
                                     "Êtes-vous sûr de vouloir supprimer ce véhicule ?",
                                     QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        // Trouver la colonne d'immatriculation
        int immatriculationCol = -1;
        for (int i = 0; i < modelVehicules->columnCount(); ++i) {
            QString header = modelVehicules->headerData(i, Qt::Horizontal).toString().toUpper();
            if (header.contains("IMMATRICULATION")) {
                immatriculationCol = i;
                break;
            }
        }
        
        if (immatriculationCol == -1) {
            QMessageBox::critical(this, "Erreur", "Colonne immatriculation non trouvée.");
            return;
        }
        
        QString immatriculation = modelVehicules->data(modelVehicules->index(selectedRowVehicule, immatriculationCol)).toString();
        
        Vehicules v;
        if (v.supprimer(immatriculation)) {
            QMessageBox::information(this, "Succès", "Véhicule supprimé avec succès.");
            afficherVehicules();
            clearFieldsVehicule();
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression du véhicule.");
        }
    }
}

void application_integree::on_pushButton_trier_vehicule_clicked()
{
    QString etat = ui->comboBox_etat_vehicule->currentText();
    
    if (etat.isEmpty() || etat == "Tous") {
        modelVehicules->setFilter("");
    } else {
        modelVehicules->setFilter("ETAT = '" + etat + "'");
    }
    
    // Trouver la colonne d'état pour le tri
    int etatCol = -1;
    for (int i = 0; i < modelVehicules->columnCount(); ++i) {
        QString header = modelVehicules->headerData(i, Qt::Horizontal).toString().toUpper();
        if (header.contains("ETAT")) {
            etatCol = i;
            break;
        }
    }
    
    if (etatCol >= 0) {
        modelVehicules->setSort(etatCol, Qt::AscendingOrder);
    }
    
    modelVehicules->select();
}

void application_integree::on_lineEdit_recherche_vehicule_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()) {
        modelVehicules->setFilter("");
    } else {
        modelVehicules->setFilter("MARQUE LIKE '%" + arg1 + "%'");
    }
    modelVehicules->select();
}

void application_integree::on_pushButton_exporterPDF_vehicule_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty())
        return;
    
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize::A4);
    
    QTextDocument doc;
    QString html = "<html><head><meta charset='UTF-8'></head><body>";
    html += "<h1 align='center'>Liste des Véhicules</h1>";
    html += "<table border='1' cellpadding='5' cellspacing='0' width='100%'>";
    html += "<tr><th>Marque</th><th>Immatriculation</th><th>Type</th><th>Kilométrage</th><th>État</th><th>Disponibilité</th><th>Capacité</th></tr>";
    
    // Trouver les index de colonnes
    QMap<QString, int> colMap;
    for (int i = 0; i < modelVehicules->columnCount(); ++i) {
        QString header = modelVehicules->headerData(i, Qt::Horizontal).toString().toUpper();
        if (header.contains("MARQUE"))
            colMap["MARQUE"] = i;
        else if (header.contains("IMMATRICULATION"))
            colMap["IMMATRICULATION"] = i;
        else if (header.contains("TYPE_VEHICULE") || header.contains("TYPE"))
            colMap["TYPE"] = i;
        else if (header.contains("KILOMETRAGE"))
            colMap["KILOMETRAGE"] = i;
        else if (header.contains("ETAT"))
            colMap["ETAT"] = i;
        else if (header.contains("DISPONIBILITE"))
            colMap["DISPONIBILITE"] = i;
        else if (header.contains("CAPACITE"))
            colMap["CAPACITE"] = i;
    }
    
    for (int row = 0; row < modelVehicules->rowCount(); ++row) {
        html += "<tr>";
        html += "<td>" + (colMap.contains("MARQUE") ? modelVehicules->data(modelVehicules->index(row, colMap["MARQUE"])).toString() : "") + "</td>";
        html += "<td>" + (colMap.contains("IMMATRICULATION") ? modelVehicules->data(modelVehicules->index(row, colMap["IMMATRICULATION"])).toString() : "") + "</td>";
        html += "<td>" + (colMap.contains("TYPE") ? modelVehicules->data(modelVehicules->index(row, colMap["TYPE"])).toString() : "") + "</td>";
        html += "<td>" + (colMap.contains("KILOMETRAGE") ? modelVehicules->data(modelVehicules->index(row, colMap["KILOMETRAGE"])).toString() : "") + "</td>";
        html += "<td>" + (colMap.contains("ETAT") ? modelVehicules->data(modelVehicules->index(row, colMap["ETAT"])).toString() : "") + "</td>";
        html += "<td>" + (colMap.contains("DISPONIBILITE") ? modelVehicules->data(modelVehicules->index(row, colMap["DISPONIBILITE"])).toString() : "") + "</td>";
        html += "<td>" + (colMap.contains("CAPACITE") ? modelVehicules->data(modelVehicules->index(row, colMap["CAPACITE"])).toString() : "") + "</td>";
        html += "</tr>";
    }
    
    html += "</table></body></html>";
    doc.setHtml(html);
    doc.print(&printer);
    
    QMessageBox::information(this, "Succès", "PDF exporté avec succès.");
}

void application_integree::on_pushButton_statistique_vehicule_clicked()
{
    QSqlQuery query;
    QString stats = "Statistiques par Type:\n\n";
    
    query.exec("SELECT TYPE_VEHICULE, COUNT(*) FROM VEHICULES GROUP BY TYPE_VEHICULE");
    while (query.next()) {
        stats += query.value(0).toString() + ": " + query.value(1).toString() + " véhicule(s)\n";
    }
    
    stats += "\nStatistiques par État:\n\n";
    query.exec("SELECT ETAT, COUNT(*) FROM VEHICULES GROUP BY ETAT");
    while (query.next()) {
        stats += query.value(0).toString() + ": " + query.value(1).toString() + " véhicule(s)\n";
    }
    
    stats += "\nStatistiques par Disponibilité:\n\n";
    query.exec("SELECT DISPONIBILITE, COUNT(*) FROM VEHICULES GROUP BY DISPONIBILITE");
    while (query.next()) {
        stats += query.value(0).toString() + ": " + query.value(1).toString() + " véhicule(s)\n";
    }
    
    QMessageBox::information(this, "Statistiques", stats);
}

void application_integree::on_tableView_vehicules_clicked(const QModelIndex &index)
{
    selectedRowVehicule = index.row();
    if (selectedRowVehicule >= 0 && selectedRowVehicule < modelVehicules->rowCount()) {
        // Trouver les colonnes
        QMap<QString, int> colMap;
        for (int i = 0; i < modelVehicules->columnCount(); ++i) {
            QString header = modelVehicules->headerData(i, Qt::Horizontal).toString().toUpper();
            if (header.contains("MARQUE"))
                colMap["MARQUE"] = i;
            else if (header.contains("IMMATRICULATION"))
                colMap["IMMATRICULATION"] = i;
            else if (header.contains("TYPE_VEHICULE") || header.contains("TYPE"))
                colMap["TYPE"] = i;
            else if (header.contains("KILOMETRAGE"))
                colMap["KILOMETRAGE"] = i;
            else if (header.contains("ETAT"))
                colMap["ETAT"] = i;
            else if (header.contains("DISPONIBILITE"))
                colMap["DISPONIBILITE"] = i;
            else if (header.contains("CAPACITE"))
                colMap["CAPACITE"] = i;
        }
        
        if (colMap.contains("MARQUE"))
            ui->lineEdit_marque_vehicule->setText(modelVehicules->data(modelVehicules->index(selectedRowVehicule, colMap["MARQUE"])).toString());
        if (colMap.contains("IMMATRICULATION"))
            ui->lineEdit_immatriculation_vehicule->setText(modelVehicules->data(modelVehicules->index(selectedRowVehicule, colMap["IMMATRICULATION"])).toString());
        if (colMap.contains("TYPE"))
            ui->comboBox_type_vehicule->setCurrentText(modelVehicules->data(modelVehicules->index(selectedRowVehicule, colMap["TYPE"])).toString());
        if (colMap.contains("KILOMETRAGE"))
            ui->lineEdit_kilometrage_vehicule->setText(modelVehicules->data(modelVehicules->index(selectedRowVehicule, colMap["KILOMETRAGE"])).toString());
        if (colMap.contains("ETAT"))
            ui->comboBox_etat_vehicule->setCurrentText(modelVehicules->data(modelVehicules->index(selectedRowVehicule, colMap["ETAT"])).toString());
        if (colMap.contains("DISPONIBILITE"))
            ui->comboBox_disponibilite_vehicule->setCurrentText(modelVehicules->data(modelVehicules->index(selectedRowVehicule, colMap["DISPONIBILITE"])).toString());
        if (colMap.contains("CAPACITE"))
            ui->lineEdit_capacite_vehicule->setText(modelVehicules->data(modelVehicules->index(selectedRowVehicule, colMap["CAPACITE"])).toString());
    }
}

void application_integree::on_pushButton_retour_vehicules_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); // Retour au menu
}

