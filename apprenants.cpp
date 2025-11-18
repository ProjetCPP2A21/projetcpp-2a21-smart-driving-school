#include "apprenants.h"
#include "ui_apprenants.h"
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QPageLayout>
#include <QPageSize>
#include <QMargins>
#include <QColor>
#include <QList>
#include <algorithm>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QVBoxLayout>
#include <QDate>
#include <QRegularExpression>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>
#include <QTimer>

apprenants::apprenants(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::apprenants)
{
    ui->setupUi(this);
    ui->label_message->setVisible(false);
    ui->dateEdit_naissance->setDate(QDate::currentDate().addYears(-18));
    afficherMessageControle("Connexion réussie !", false);
    afficherApprenants();
}

apprenants::~apprenants()
{
    delete ui;
}

// -------------------- Vérification des saisies --------------------
bool apprenants::verifierSaisie(int &id, QString &nom, QString &prenom, QString &dateNaissance,
                                QString &tel, QString &sexe, QString &adresse)
{
    bool idOk = false;
    id = ui->lineEdit_id->text().trimmed().toInt(&idOk);
    nom = ui->lineEdit_nom->text().trimmed();
    prenom = ui->lineEdit_prenom->text().trimmed();
    dateNaissance = ui->dateEdit_naissance->date().toString("dd/MM/yyyy");
    tel = ui->lineEdit_telephone->text().trimmed();
    sexe = ui->comboBox_sexe->currentText().trimmed();
    adresse = ui->lineEdit_adresse->text().trimmed();

    if(!idOk || id <= 0){
        afficherMessageControle("ID invalide : veuillez saisir un entier positif.");
        ui->lineEdit_id->setFocus();
        return false;
    }

    static const QRegularExpression regexNom(QStringLiteral("^[\\p{L}\\s'-]{2,40}$"));
    if(!regexNom.match(nom).hasMatch()){
        afficherMessageControle("Nom invalide : 2 à 40 lettres (espaces, tirets ou apostrophes autorisés).");
        ui->lineEdit_nom->setFocus();
        return false;
    }
    if(!regexNom.match(prenom).hasMatch()){
        afficherMessageControle("Prénom invalide : 2 à 40 lettres (espaces, tirets ou apostrophes autorisés).");
        ui->lineEdit_prenom->setFocus();
        return false;
    }

    const QDate aujourdHui = QDate::currentDate();
    const QDate naissance = ui->dateEdit_naissance->date();
    if(naissance > aujourdHui){
        afficherMessageControle("La date de naissance ne peut pas être future.");
        ui->dateEdit_naissance->setFocus();
        return false;
    }
    const int age = naissance.daysTo(aujourdHui)/365;
    if(age < 18){
        afficherMessageControle("L'apprenant doit avoir au moins 18 ans.");
        ui->dateEdit_naissance->setFocus();
        return false;
    }
    if(age > 90){
        afficherMessageControle("Veuillez vérifier la date de naissance (âge supérieur à 90 ans).");
        ui->dateEdit_naissance->setFocus();
        return false;
    }

    QString telNormalise = tel;
    telNormalise.remove(QRegularExpression("[\\s\\-]"));
    static const QRegularExpression regexTel(QStringLiteral("^\\+?\\d{8,15}$"));
    if(!regexTel.match(telNormalise).hasMatch()){
        afficherMessageControle("Téléphone invalide : 8 à 15 chiffres (préfixe + optionnel).");
        ui->lineEdit_telephone->setFocus();
        return false;
    }
    tel = telNormalise;

    static const QRegularExpression regexAdresse(QStringLiteral("^[\\p{L}\\d\\s',.-]{5,120}$"));
    if(!regexAdresse.match(adresse).hasMatch()){
        afficherMessageControle("Adresse invalide : 5 à 120 caractères (lettres, chiffres et ,.'-).");
        ui->lineEdit_adresse->setFocus();
        return false;
    }

    if(sexe.compare("Homme", Qt::CaseInsensitive) != 0 &&
       sexe.compare("Femme", Qt::CaseInsensitive) != 0){
        afficherMessageControle("Veuillez sélectionner un sexe valide.");
        ui->comboBox_sexe->setFocus();
        return false;
    }

    afficherMessageControle(QString());
    return true;
}

// -------------------- AFFICHER --------------------
void apprenants::afficherApprenants()
{
    Apprenant a;
    ui->tableView_apprenants->setModel(a.afficher());
}

void apprenants::reinitialiserFormulaire()
{
    ui->lineEdit_id->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_telephone->clear();
    ui->lineEdit_adresse->clear();
    ui->dateEdit_naissance->setDate(QDate::currentDate().addYears(-18));
    if(ui->comboBox_sexe->count() > 0)
        ui->comboBox_sexe->setCurrentIndex(0);
    ui->tableView_apprenants->clearSelection();
    afficherMessageControle(QString());
}

void apprenants::afficherMessageControle(const QString &message, bool erreur)
{
    if(message.isEmpty()){
        ui->label_message->clear();
        ui->label_message->setVisible(false);
        return;
    }

    if(erreur){
        // Fenêtre de dialogue personnalisée professionnelle
        QDialog *dialog = new QDialog(this);
        dialog->setWindowTitle(tr("⚠ Contrôle de saisie"));
        dialog->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
        dialog->setModal(true);
        dialog->setFixedSize(450, 200);

        // Style moderne avec dégradé
        QString styleSheet = QStringLiteral(
            "QDialog {"
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
            "        stop:0 #ffffff, stop:1 #fff5f5);"
            "    border: 2px solid #e53935;"
            "    border-radius: 15px;"
            "}"
            "QLabel#titleLabel {"
            "    color: #c62828;"
            "    font-size: 18px;"
            "    font-weight: bold;"
            "    padding: 10px;"
            "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, "
            "        stop:0 #ffebee, stop:1 #ffcdd2);"
            "    border-top-left-radius: 13px;"
            "    border-top-right-radius: 13px;"
            "    border-bottom: 2px solid #e53935;"
            "}"
            "QLabel#messageLabel {"
            "    color: #b71c1c;"
            "    font-size: 13px;"
            "    padding: 20px;"
            "    background: transparent;"
            "    min-height: 80px;"
            "}"
            "QPushButton {"
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
            "        stop:0 #e53935, stop:1 #c62828);"
            "    color: white;"
            "    border: none;"
            "    border-radius: 8px;"
            "    padding: 10px 30px;"
            "    font-size: 13px;"
            "    font-weight: bold;"
            "    min-width: 100px;"
            "}"
            "QPushButton:hover {"
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
            "        stop:0 #f44336, stop:1 #d32f2f);"
            "    transform: scale(1.05);"
            "}"
            "QPushButton:pressed {"
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
            "        stop:0 #c62828, stop:1 #b71c1c);"
            "}"
        );

        dialog->setStyleSheet(styleSheet);

        QVBoxLayout *mainLayout = new QVBoxLayout(dialog);
        mainLayout->setSpacing(0);
        mainLayout->setContentsMargins(0, 0, 0, 0);

        // Titre
        QLabel *titleLabel = new QLabel("⚠ Erreur de validation", dialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(titleLabel);

        // Message
        QLabel *messageLabel = new QLabel(message, dialog);
        messageLabel->setObjectName("messageLabel");
        messageLabel->setWordWrap(true);
        messageLabel->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
        mainLayout->addWidget(messageLabel);

        // Bouton OK
        QHBoxLayout *buttonLayout = new QHBoxLayout();
        buttonLayout->addStretch();
        QPushButton *okButton = new QPushButton("✓ Compris", dialog);
        okButton->setCursor(Qt::PointingHandCursor);
        connect(okButton, &QPushButton::clicked, dialog, &QDialog::accept);
        buttonLayout->addWidget(okButton);
        buttonLayout->addStretch();
        mainLayout->addLayout(buttonLayout);
        mainLayout->addSpacing(15);

        // Effet d'ombre
        QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(dialog);
        shadow->setBlurRadius(20);
        shadow->setColor(QColor(0, 0, 0, 100));
        shadow->setOffset(0, 5);
        dialog->setGraphicsEffect(shadow);

        // Centrer la fenêtre
        QPoint center = mapToGlobal(rect().center());
        dialog->move(center.x() - dialog->width()/2, center.y() - dialog->height()/2);

        dialog->exec();
        delete dialog;

        ui->label_message->clear();
        ui->label_message->setVisible(false);
    } else {
        // Fenêtre de succès professionnelle
        QDialog *dialog = new QDialog(this);
        dialog->setWindowTitle(tr("✓ Succès"));
        dialog->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
        dialog->setModal(true);
        dialog->setFixedSize(450, 200);

        // Style moderne avec dégradé vert
        QString styleSheet = QStringLiteral(
            "QDialog {"
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
            "        stop:0 #ffffff, stop:1 #f1f8f4);"
            "    border: 2px solid #4caf50;"
            "    border-radius: 15px;"
            "}"
            "QLabel#titleLabel {"
            "    color: #2e7d32;"
            "    font-size: 18px;"
            "    font-weight: bold;"
            "    padding: 10px;"
            "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, "
            "        stop:0 #e8f5e9, stop:1 #c8e6c9);"
            "    border-top-left-radius: 13px;"
            "    border-top-right-radius: 13px;"
            "    border-bottom: 2px solid #4caf50;"
            "}"
            "QLabel#messageLabel {"
            "    color: #1b5e20;"
            "    font-size: 13px;"
            "    padding: 20px;"
            "    background: transparent;"
            "    min-height: 80px;"
            "}"
            "QPushButton {"
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
            "        stop:0 #4caf50, stop:1 #388e3c);"
            "    color: white;"
            "    border: none;"
            "    border-radius: 8px;"
            "    padding: 10px 30px;"
            "    font-size: 13px;"
            "    font-weight: bold;"
            "    min-width: 100px;"
            "}"
            "QPushButton:hover {"
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
            "        stop:0 #66bb6a, stop:1 #4caf50);"
            "    transform: scale(1.05);"
            "}"
            "QPushButton:pressed {"
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
            "        stop:0 #388e3c, stop:1 #2e7d32);"
            "}"
        );

        dialog->setStyleSheet(styleSheet);

        QVBoxLayout *mainLayout = new QVBoxLayout(dialog);
        mainLayout->setSpacing(0);
        mainLayout->setContentsMargins(0, 0, 0, 0);

        // Titre
        QLabel *titleLabel = new QLabel("✓ Opération réussie", dialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(titleLabel);

        // Message
        QLabel *messageLabel = new QLabel(message, dialog);
        messageLabel->setObjectName("messageLabel");
        messageLabel->setWordWrap(true);
        messageLabel->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
        mainLayout->addWidget(messageLabel);

        // Bouton OK
        QHBoxLayout *buttonLayout = new QHBoxLayout();
        buttonLayout->addStretch();
        QPushButton *okButton = new QPushButton("✓ OK", dialog);
        okButton->setCursor(Qt::PointingHandCursor);
        connect(okButton, &QPushButton::clicked, dialog, &QDialog::accept);
        buttonLayout->addWidget(okButton);
        buttonLayout->addStretch();
        mainLayout->addLayout(buttonLayout);
        mainLayout->addSpacing(15);

        // Effet d'ombre
        QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(dialog);
        shadow->setBlurRadius(20);
        shadow->setColor(QColor(76, 175, 80, 100));
        shadow->setOffset(0, 5);
        dialog->setGraphicsEffect(shadow);

        // Centrer la fenêtre
        QPoint center = mapToGlobal(rect().center());
        dialog->move(center.x() - dialog->width()/2, center.y() - dialog->height()/2);

        dialog->exec();
        delete dialog;

        ui->label_message->clear();
        ui->label_message->setVisible(false);
    }
}

// -------------------- AJOUTER --------------------
void apprenants::on_pushButton_ajouter_clicked()
{
    int id; QString nom, prenom, dateNaissance, tel, sexe, adresse;
    if(!verifierSaisie(id, nom, prenom, dateNaissance, tel, sexe, adresse)) return;

    Apprenant service;
    if(service.existe(id)){
        afficherMessageControle("Un apprenant avec cet ID existe déjà.");
        ui->lineEdit_id->setFocus();
        return;
    }

    Apprenant a(id, nom, prenom, dateNaissance, tel, sexe, adresse);
    if(a.ajouter()){
        afficherMessageControle(
            QString("Apprenant %1 %2 (ID %3) ajouté avec succès !")
                .arg(prenom).arg(nom).arg(id),
            false);
        afficherApprenants();
        reinitialiserFormulaire();
    } else {
        afficherMessageControle("Échec de l'ajout : veuillez réessayer.");
    }
}

// -------------------- MODIFIER --------------------
void apprenants::on_pushButton_modifier_clicked()
{
    int id; QString nom, prenom, dateNaissance, tel, sexe, adresse;
    if(!verifierSaisie(id, nom, prenom, dateNaissance, tel, sexe, adresse)) return;

    Apprenant service;
    if(!service.existe(id)){
        afficherMessageControle("Impossible de modifier : aucun apprenant avec cet ID.");
        return;
    }

    Apprenant a(id, nom, prenom, dateNaissance, tel, sexe, adresse);
    if(a.modifier()){
        afficherMessageControle(
            QString("Apprenant %1 %2 (ID %3) modifié avec succès !")
                .arg(prenom).arg(nom).arg(id),
            false);
        afficherApprenants();
        reinitialiserFormulaire();
    } else {
        afficherMessageControle("Échec de la modification : veuillez réessayer.");
    }
}

// -------------------- SUPPRIMER --------------------
void apprenants::on_pushButton_supprimer_clicked()
{
    bool ok = false;
    int id = ui->lineEdit_id->text().trimmed().toInt(&ok);
    if(!ok || id <= 0){
        afficherMessageControle("Veuillez saisir un ID numérique valide avant de supprimer.");
        ui->lineEdit_id->setFocus();
        return;
    }

    Apprenant service;
    if(!service.existe(id)){
        afficherMessageControle("Aucun apprenant trouvé avec cet ID.");
        return;
    }

    if(service.supprimer(id)){
        afficherMessageControle(
            QString("Apprenant (ID %1) supprimé avec succès.").arg(id),
            false);
        afficherApprenants();
        reinitialiserFormulaire();
    } else {
        afficherMessageControle("Échec de la suppression : veuillez réessayer.");
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
    QString prefix = arg1.trimmed();
    if(prefix.isEmpty())
        afficherApprenants();
    else
        ui->tableView_apprenants->setModel(a.rechercherParPrefixe(prefix));
}

// -------------------- EXPORTER PDF --------------------
void apprenants::on_pushButton_exporterPDF_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "*.pdf");
    if(fileName.isEmpty()) return;
    if(!fileName.endsWith(".pdf", Qt::CaseInsensitive))
        fileName += ".pdf";

    QAbstractItemModel* model = ui->tableView_apprenants->model();
    if(!model || model->rowCount() == 0){
        afficherMessageControle("Erreur", "Aucune donnée à exporter !");
        return;
    }

    QPdfWriter pdf(fileName);
    pdf.setPageSize(QPageSize::A4);
    pdf.setPageMargins(QMargins(20, 20, 20, 20), QPageLayout::Millimeter);

    QPainter painter(&pdf);
    if(!painter.isActive()){
       afficherMessageControle("Erreur", "Impossible de créer le PDF !");
        return;
    }

    const int margin = 30;
    const int pageWidth = pdf.width();
    const int pageHeight = pdf.height();
    const int headerHeight = 120;
    const int rowMinHeight = 40;
    const int tableSpacing = 100;
    const int headerToDataSpacing = 30;
    const int cellPadding = 16;

    const QColor primaryColor(33, 150, 243);
    const QColor headerBg(232, 240, 252);
    const QColor headerBorder(180, 190, 200);
    const QColor headerTextColor(0, 70, 140);
    const QColor textColor(30, 30, 30);
    const QColor rowAlternate(248, 250, 252);

    const QString titleText = tr("Liste des apprenants");

    QFont titleFont("Arial", 24, QFont::Bold);
    QFont headerFont("Arial", 10, QFont::Bold);
    QFont dataFont("Arial", 9);

    int nbColonnes = model->columnCount();
    QList<int> widths;
    int totalWidth = pageWidth - 2 * margin;

    if(nbColonnes == 7){
        widths << static_cast<int>(totalWidth * 0.10)
               << static_cast<int>(totalWidth * 0.15)
               << static_cast<int>(totalWidth * 0.15)
               << static_cast<int>(totalWidth * 0.20)
               << static_cast<int>(totalWidth * 0.16)
               << static_cast<int>(totalWidth * 0.10)
               << static_cast<int>(totalWidth * 0.18);
    } else {
        int base = nbColonnes ? totalWidth / nbColonnes : totalWidth;
        for(int i = 0; i < nbColonnes; ++i)
            widths.append(base);
    }

    auto drawHeader = [&](int y) {
        painter.setFont(headerFont);
        int x = margin;
        for(int col = 0; col < nbColonnes; ++col){
            QRect headerRect(x, y, widths[col], headerHeight);
            painter.setPen(QPen(headerBorder, 1));
            painter.setBrush(headerBg);
            painter.drawRect(headerRect);

            QString title = model->headerData(col, Qt::Horizontal).toString().toUpper();
            QRect textR(x + cellPadding, y, widths[col] - 2 * cellPadding, headerHeight);
            painter.setPen(headerTextColor);
            painter.drawText(textR, Qt::AlignLeft | Qt::AlignVCenter, title);

            x += widths[col];
        }
    };

    painter.setFont(titleFont);
    QRect titleRect(margin, 50, totalWidth, 320);
    painter.setPen(Qt::white);
    painter.setBrush(primaryColor);
    painter.drawRoundedRect(titleRect, 12, 12);
    painter.drawText(titleRect, Qt::AlignCenter, titleText.toUpper());

    painter.setFont(dataFont);
    int y = titleRect.bottom() + tableSpacing;

    painter.setPen(QPen(headerBorder, 1, Qt::DashLine));
    painter.drawLine(margin, y - tableSpacing / 2, pageWidth - margin, y - tableSpacing / 2);
    painter.setPen(QPen(headerBorder, 1));
    drawHeader(y);
    y += headerHeight + headerToDataSpacing;

    bool alternate = false;

    for(int row = 0; row < model->rowCount(); ++row){
        int rowHeight = rowMinHeight;
        for(int col = 0; col < nbColonnes; ++col){
            QString text = model->index(row, col).data().toString();
            QRect measureRect(0, 0, widths[col] - 2 * cellPadding, 2000);
            QRect bounding = painter.boundingRect(measureRect, Qt::TextWordWrap, text);
            rowHeight = std::max(rowHeight, bounding.height() + 12);
        }

        if(y + rowHeight > pageHeight - margin){
            pdf.newPage();

            painter.setFont(titleFont);
            painter.setPen(Qt::white);
            painter.setBrush(primaryColor);
            QRect newTitleRect(margin, 50, totalWidth, 320);
            painter.drawRoundedRect(newTitleRect, 12, 12);
            painter.drawText(newTitleRect, Qt::AlignCenter, titleText.toUpper());

            painter.setFont(dataFont);
            y = newTitleRect.bottom() + tableSpacing;

            painter.setPen(QPen(headerBorder, 1, Qt::DashLine));
            painter.drawLine(margin, y - tableSpacing / 2, pageWidth - margin, y - tableSpacing / 2);
            painter.setPen(QPen(headerBorder, 1));
            drawHeader(y);
            y += headerHeight + headerToDataSpacing;

            alternate = false;
        }

        int x = margin;
        for(int col = 0; col < nbColonnes; ++col){
            QRect cellRect(x, y, widths[col], rowHeight);
            painter.setBrush(alternate ? rowAlternate : Qt::white);
            painter.setPen(QPen(headerBorder, 1));
            painter.drawRect(cellRect);

            QString text = model->index(row, col).data().toString();
            QRect textRect(x + cellPadding, y + 6, widths[col] - 2 * cellPadding, rowHeight - 12);
            painter.setPen(textColor);
            painter.drawText(textRect, Qt::TextWordWrap | Qt::AlignLeft | Qt::AlignVCenter, text);

            x += widths[col];
        }

        y += rowHeight + 3;
        alternate = !alternate;
    }

    painter.end();
    afficherMessageControle( "PDF Exportation réussie !", false);
}

// -------------------- STATISTIQUES --------------------
void apprenants::on_pushButton_statistique_clicked()
{
    Apprenant a;
    QMap<QString,int> stats = a.statistiquesSexe();
    int total = 0;
    for (auto val : stats) total += val;

    QPieSeries* series = new QPieSeries();
    series->setHoleSize(0.25);  // Donut léger (plus moderne)

    for (auto it = stats.begin(); it != stats.end(); ++it) {

        double pourcentage = (it.value() * 100.0) / total;
        QString label = it.key() + " (" + QString::number(it.value()) +
                        ") : " + QString::number(pourcentage, 'f', 1) + "%";

        QPieSlice* slice = series->append(label, it.value());
        slice->setLabelVisible(true);

        if (it.key() == "Femme") {
            slice->setBrush(QColor("#43cea2"));  // couleur Femme
        }
        else if (it.key() == "Homme") {
            slice->setBrush(QColor("#185a9d"));  // couleur Homme
        }

        // ✨ Explosion animation au survol
        slice->setExploded(false);
        QObject::connect(slice, &QPieSlice::hovered, [slice](bool state){
            slice->setExploded(state);
            slice->setLabelVisible(true);
        });
    }

    // 📊 Création du chart
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // 🎨 Fond transparent
    chart->setBackgroundVisible(false);
    chart->setPlotAreaBackgroundVisible(false);

    // Titre stylé
    chart->setTitle("Répartition des apprenants selon le sexe");
    chart->setTitleFont(QFont("Segoe UI", 14, QFont::Bold));
    chart->setTitleBrush(QBrush(QColor("#185a9d")));

    // 🏷️ Légende stylée
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


// -------------------- SELECTION LIGNE --------------------
void apprenants::on_tableView_apprenants_clicked(const QModelIndex &index)
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
