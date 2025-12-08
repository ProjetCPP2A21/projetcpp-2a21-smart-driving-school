#include "vehicule.h"
#include "ui_vehicule.h"
#include <QTextEdit>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSettings>
#include "vehicules.h"
#include "connection.h"
#include "maintenance.h"
#include <QInputDialog>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QDateTime>
#include <QSqlRecord>
#include <QSqlField>
#include <QFormLayout>
#include <QDialog>
#include <QDialogButtonBox>
#include <QComboBox>
#include <QAbstractItemView>
#include <QPrinter>
#include <QChartView>
#include <QPieSeries>
#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QChart>
#include <QGraphicsDropShadowEffect>
#include <QLinearGradient>
#include <QRegularExpression>
#include <QTextToSpeech>
#include <QProcess>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QListWidget>
#include <QPushButton>

vehicule::vehicule(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::vehicule)
    , selectedRow(-1)
{
    ui->setupUi(this);

    // Désactiver les connexions automatiques par nom pour éviter les avertissements
    // Nous ferons toutes les connexions manuellement
    setObjectName("vehicule"); // Pour éviter les connexions automatiques

    // Initialiser le modèle
    setupModel();

    // Initialiser l'onglet de maintenance (supprimé pour simplification)
    // initialiserOngletMaintenance();

    // Initialisation des combobox
    QComboBox* comboBox_type = this->findChild<QComboBox*>(QStringLiteral("comboBox_type"));
    if (comboBox_type) {
        comboBox_type->clear();
        comboBox_type->addItem("Tous");
        comboBox_type->addItem("Berline manuelle");
        comboBox_type->addItem("Berline automatique");
        comboBox_type->addItem("SUV manuel");
        comboBox_type->addItem("SUV automatique");
        comboBox_type->setCurrentIndex(0);
    }

    QComboBox* comboBox_etat = this->findChild<QComboBox*>(QStringLiteral("comboBox_etat"));
    if (comboBox_etat) {
        comboBox_etat->clear();
        comboBox_etat->addItem("Tous");
        comboBox_etat->addItem("Bon");
        comboBox_etat->addItem("Moyen");
        comboBox_etat->addItem("A reviser");
        comboBox_etat->setCurrentIndex(0);
    }

    QComboBox* comboBox_disponibilite = this->findChild<QComboBox*>(QStringLiteral("comboBox_disponibilite"));
    if (comboBox_disponibilite) {
        comboBox_disponibilite->clear();
        comboBox_disponibilite->addItem("Tous");
        comboBox_disponibilite->addItem("Disponible");
        comboBox_disponibilite->addItem("Indisponible");
        comboBox_disponibilite->addItem("En maintenance");
        comboBox_disponibilite->setCurrentIndex(0);
    }

    // Connexion des boutons
    connect(ui->pushButton_5, &QPushButton::clicked, this, &vehicule::on_pb_stat_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &vehicule::on_pb_pdf_clicked);
    connect(ui->Retour, &QPushButton::clicked, this, &vehicule::returnRequested);

    // Connexion des champs de recherche
    // (autoconnect via on_lineEdit_3_textChanged)

    // Connexion du tableau
    // (autoconnect via on_tableView_clicked)



    tts = new QTextToSpeech(this);
}

vehicule::~vehicule()
{
    delete ui;
}

void vehicule::analyzeDatabaseSchema()
{
    // Utiliser explicitement la connexion Oracle nommée
    QSqlDatabase db = QSqlDatabase::database("oracle_connection");
    QSqlRecord record = db.record("VEHICULES");

    qDebug() << "=== STRUCTURE RÉELLE DE LA TABLE VEHICULES ===";
    columnMapping.clear();

    for (int i = 0; i < record.count(); ++i) {
        QString fieldName = record.fieldName(i).toUpper();
        columnMapping[fieldName] = i;
        qDebug() << "Colonne" << i << ":" << fieldName << "(" << record.field(i).type() << ")";
    }
    qDebug() << "=====================================";

    // Afficher le mapping
    qDebug() << "=== MAPPING DES COLONNES ===";
    qDebug() << "ID ->" << (columnMapping.contains("ID") ? QString::number(columnMapping["ID"]) : "NON TROUVÉ");
    qDebug() << "MARQUE ->" << (columnMapping.contains("MARQUE") ? QString::number(columnMapping["MARQUE"]) : "NON TROUVÉ");
    qDebug() << "MODELE ->" << (columnMapping.contains("MODELE") ? QString::number(columnMapping["MODELE"]) : "NON TROUVÉ");
    qDebug() << "IMMATRICULATION ->" << (columnMapping.contains("IMMATRICULATION") ? QString::number(columnMapping["IMMATRICULATION"]) : "NON TROUVÉ");
    qDebug() << "TYPE ->" << (columnMapping.contains("TYPE") ? QString::number(columnMapping["TYPE"]) : "NON TROUVÉ");
    qDebug() << "KILOMETRAGE ->" << (columnMapping.contains("KILOMETRAGE") ? QString::number(columnMapping["KILOMETRAGE"]) : "NON TROUVÉ");
    qDebug() << "ETAT ->" << (columnMapping.contains("ETAT") ? QString::number(columnMapping["ETAT"]) : "NON TROUVÉ");
    qDebug() << "DISPONIBILITE ->" << (columnMapping.contains("DISPONIBILITE") ? QString::number(columnMapping["DISPONIBILITE"]) : "NON TROUVÉ");
    qDebug() << "CAPACITE ->" << (columnMapping.contains("CAPACITE") ? QString::number(columnMapping["CAPACITE"]) : "NON TROUVÉ");
    qDebug() << "==========================";
}

void vehicule::setupModel()
{
    // Utiliser la connexion "oracle_connection" comme tous les autres modules
    QSqlDatabase db = QSqlDatabase::database("oracle_connection");
    model = new QSqlTableModel(this, db);
    model->setTable("VEHICULES");

    // Analyser la structure de la base de données
    analyzeDatabaseSchema();

    model->select();
    qDebug() << "Table rechargée avec" << model->rowCount() << "lignes";

    // Définir les en-têtes des colonnes selon la structure réelle
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Marque"));
    model->setHeaderData(2, Qt::Horizontal, tr("Immatriculation"));
    model->setHeaderData(3, Qt::Horizontal, tr("Type"));
    model->setHeaderData(4, Qt::Horizontal, tr("Kilométrage"));
    model->setHeaderData(5, Qt::Horizontal, tr("État"));
    model->setHeaderData(6, Qt::Horizontal, tr("Disponibilité"));
    model->setHeaderData(7, Qt::Horizontal, tr("Capacité"));

    // Le tri doit rester côté fenêtre (vue) uniquement, pas en base

    // Configurer la stratégie d'édition
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    // Masquer la colonne ID
    ui->tableView->setColumnHidden(0, true);

    // (déplacé après setModel)

    // Créer le modèle proxy pour le filtrage
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    proxyModel->setFilterKeyColumn(-1); // Rechercher dans toutes les colonnes
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);

    ui->tableView->setModel(proxyModel);
    proxyModel->setDynamicSortFilter(true);
    int brandCol = columnMapping.contains("MARQUE") ? columnMapping["MARQUE"] : 1;
    ui->tableView->sortByColumn(brandCol, Qt::AscendingOrder);
    ui->tableView->setSortingEnabled(false);
    ui->tableView->resizeColumnsToContents();

    // Configurer la sélection par ligne
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    // Connecter le signal de sélection de ligne après affectation du modèle
    if (ui->tableView->selectionModel()) {
        connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged,
                this, [this]() {
                    QTableView* tv = ui->tableView;
                    if (!tv || !tv->selectionModel()) return;
                    QModelIndexList selection = tv->selectionModel()->selectedRows();
                    if (!selection.isEmpty()) {
                        QModelIndex srcIndex = proxyModel ? proxyModel->mapToSource(selection.first()) : selection.first();
                        selectedRow = srcIndex.row();
                    }
                });
    }
}

void vehicule::refreshTable()
{
    qDebug() << "=== REFRESH TABLE CALLED ===";
    qDebug() << "Lignes avant refresh:" << (model ? model->rowCount() : -1);

    if (model) {
        model->select();
        qDebug() << "Lignes après select:" << model->rowCount();
        ui->tableView->resizeColumnsToContents();
    }

    qDebug() << "=== END REFRESH TABLE ===";
}

void vehicule::on_pushButton_ajouter_clicked()
{
    QString marque = ui->lineEdit_marque ? ui->lineEdit_marque->text().trimmed() : QString();
    QString immatriculation = ui->lineEdit_immatriculation ? ui->lineEdit_immatriculation->text().trimmed() : QString();
    QString type = ui->comboBox_type ? ui->comboBox_type->currentText() : QString();
    double kilometrage = ui->lineEdit_kilometrage ? ui->lineEdit_kilometrage->text().toDouble() : 0.0;
    QString etat = ui->comboBox_etat ? ui->comboBox_etat->currentText() : QString();
    QString disponibilite = ui->comboBox_disponibilite ? ui->comboBox_disponibilite->currentText() : QString();
    int capacite = ui->lineEdit_capacite ? ui->lineEdit_capacite->text().toInt() : 0;

    // Normaliser l'immatriculation pour éviter les doublons liés à la casse/espaces
    immatriculation = immatriculation.replace(" ", "").toUpper();

    if (immatriculation.isEmpty() || marque.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez remplir au minimum l'immatriculation et la marque.");
        return;
    }

    // Vérifier unicité de l'immatriculation (ORA-00001 si doublon)
    {
        QSqlQuery chk(QSqlDatabase::database("oracle_connection"));
        chk.prepare("SELECT COUNT(*) FROM VEHICULES WHERE IMMATRICULATION = ?");
        chk.addBindValue(immatriculation);
        if (chk.exec() && chk.next()) {
            int exists = chk.value(0).toInt();
            if (exists > 0) {
                QMessageBox::warning(this, "Immatriculation existante",
                                     QString("L'immatriculation '%1' existe déjà. Choisissez une autre valeur.").arg(immatriculation));
                return;
            }
        } else {
            // Si la vérification échoue, mieux vaut annuler avant insert
            QMessageBox::critical(this, "Erreur",
                                  "Impossible de vérifier l'unicité de l'immatriculation: " + chk.lastError().text());
            return;
        }
    }

    // Récupérer le prochain ID_VEHICULE disponible
    int nextId = 1;
    {
        QSqlQuery idQuery(QSqlDatabase::database("oracle_connection"));
        // Essayer d'abord avec une séquence Oracle (nom commun)
        idQuery.prepare("SELECT NVL(MAX(ID_VEHICULE), 0) + 1 FROM VEHICULES");
        if (idQuery.exec() && idQuery.next()) {
            nextId = idQuery.value(0).toInt();
        } else {
            // Si échec, essayer avec une séquence nommée (si elle existe)
            idQuery.prepare("SELECT VEHICULES_SEQ.NEXTVAL FROM DUAL");
            if (idQuery.exec() && idQuery.next()) {
                nextId = idQuery.value(0).toInt();
            } else {
                // Dernière tentative : utiliser MAX + 1
                idQuery.prepare("SELECT NVL(MAX(ID_VEHICULE), 0) + 1 FROM VEHICULES");
                if (idQuery.exec() && idQuery.next()) {
                    nextId = idQuery.value(0).toInt();
                }
            }
        }
    }

    QSqlQuery query(QSqlDatabase::database("oracle_connection"));
    query.prepare("INSERT INTO VEHICULES (ID_VEHICULE, MARQUE, IMMATRICULATION, TYPE_VEHICULE, KILOMETRAGE, ETAT, DISPONIBILITE, CAPACITE) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(nextId);
    query.addBindValue(marque);
    query.addBindValue(immatriculation);
    query.addBindValue(type);
    query.addBindValue(kilometrage);
    query.addBindValue(etat);
    query.addBindValue(disponibilite);
    query.addBindValue(capacite);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Véhicule ajouté avec succès!");
        if (ui->lineEdit_marque) ui->lineEdit_marque->clear();
        if (ui->lineEdit_immatriculation) ui->lineEdit_immatriculation->clear();
        if (ui->comboBox_type) ui->comboBox_type->setCurrentIndex(0);
        if (ui->lineEdit_kilometrage) ui->lineEdit_kilometrage->clear();
        if (ui->comboBox_etat) ui->comboBox_etat->setCurrentIndex(0);
        if (ui->comboBox_disponibilite) ui->comboBox_disponibilite->setCurrentIndex(0);
        if (ui->lineEdit_capacite) ui->lineEdit_capacite->clear();
        refreshTable();
    } else {
        QString err = query.lastError().text();
        if (err.contains("ORA-00001") || err.contains("unique constraint", Qt::CaseInsensitive)) {
            QMessageBox::warning(this, "Immatriculation déjà utilisée",
                                 QString("Impossible d'ajouter: l'immatriculation '%1' existe déjà.").arg(immatriculation));
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout: " + err);
        }
    }
}

void vehicule::on_pushButton_modifier_clicked()
{
    QModelIndexList selection = ui->tableView && ui->tableView->selectionModel()
    ? ui->tableView->selectionModel()->selectedRows()
    : QModelIndexList();

    QSqlRecord record;
    QString immatriculation;
    if (!selection.isEmpty()) {
        QModelIndex srcIndex = proxyModel ? proxyModel->mapToSource(selection.first()) : selection.first();
        record = model->record(srcIndex.row());
        immatriculation = record.value("IMMATRICULATION").toString();
    } else {
        immatriculation = ui->lineEdit_immatriculation ? ui->lineEdit_immatriculation->text().trimmed() : QString();
        if (immatriculation.isEmpty()) {
            QMessageBox::warning(this, "Attention", "Veuillez sélectionner une ligne ou saisir l'immatriculation.");
            return;
        }
    }

    QString marque = ui->lineEdit_marque ? ui->lineEdit_marque->text().trimmed() : (record.isEmpty() ? QString() : record.value("MARQUE").toString());
    QString type = ui->comboBox_type ? ui->comboBox_type->currentText() : (record.isEmpty() ? QString() : record.value("TYPE_VEHICULE").toString());
    double kilometrage = ui->lineEdit_kilometrage ? ui->lineEdit_kilometrage->text().toDouble() : (record.isEmpty() ? 0.0 : record.value("KILOMETRAGE").toDouble());
    QString etat = ui->comboBox_etat ? ui->comboBox_etat->currentText() : (record.isEmpty() ? QString() : record.value("ETAT").toString());
    QString disponibilite = ui->comboBox_disponibilite ? ui->comboBox_disponibilite->currentText() : (record.isEmpty() ? QString() : record.value("DISPONIBILITE").toString());
    int capacite = ui->lineEdit_capacite ? ui->lineEdit_capacite->text().toInt() : (record.isEmpty() ? 0 : record.value("CAPACITE").toInt());

    QSqlQuery query(QSqlDatabase::database("oracle_connection"));
    query.prepare("UPDATE VEHICULES SET MARQUE=?, TYPE_VEHICULE=?, KILOMETRAGE=?, ETAT=?, DISPONIBILITE=?, CAPACITE=? WHERE IMMATRICULATION=?");
    query.addBindValue(marque);
    query.addBindValue(type);
    query.addBindValue(kilometrage);
    query.addBindValue(etat);
    query.addBindValue(disponibilite);
    query.addBindValue(capacite);
    query.addBindValue(immatriculation);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Véhicule modifié avec succès!");
        refreshTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification: " + query.lastError().text());
    }
}

void vehicule::on_pushButton_supprimer_clicked()
{
    if (selectedRow < 0) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner un véhicule à supprimer.");
        return;
    }

    QSqlRecord record = model->record(selectedRow);
    QString immatriculation = record.value("IMMATRICULATION").toString();

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation",
                                                              QString("Êtes-vous sûr de vouloir supprimer le véhicule immatriculé '%1' ?").arg(immatriculation),
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
    QSqlQuery query(QSqlDatabase::database("oracle_connection"));
        query.prepare("DELETE FROM VEHICULES WHERE IMMATRICULATION=?");
        query.addBindValue(immatriculation);

        if (query.exec()) {
            QMessageBox::information(this, "Succès", "Véhicule supprimé avec succès!");
            refreshTable();
            selectedRow = -1;
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression: " + query.lastError().text());
        }
    }
}

void vehicule::on_pb_stat_clicked()
{
    QWidget *container = ui->statsContainer;
    if (!container) return;

    QLayout *old = container->layout();
    if (old) {
        QLayoutItem *child;
        while ((child = old->takeAt(0)) != nullptr) {
            if (child->widget()) child->widget()->deleteLater();
            delete child;
        }
        delete old;
    }

    QVBoxLayout *v = new QVBoxLayout(container);
    v->setContentsMargins(8,8,8,8);
    v->setSpacing(8);

    QMap<QString,int> byType;
    QSqlQuery qt1(QSqlDatabase::database("oracle_connection"));
    qt1.prepare("SELECT TYPE_VEHICULE, COUNT(*) FROM VEHICULES GROUP BY TYPE_VEHICULE");
    if (qt1.exec()) {
        while (qt1.next()) byType[qt1.value(0).toString()] = qt1.value(1).toInt();
    }

    int total = 0;
    for (auto it = byType.begin(); it != byType.end(); ++it) total += it.value();

    QPieSeries *pieSeries = new QPieSeries();
    QStringList colors = {"#3498db", "#e74c3c", "#2ecc71", "#f39c12", "#9b59b6", "#1abc9c", "#e67e22", "#34495e"};
    int colorIndex = 0;
    int maxCount = -1; QString maxKey;
    for (auto it = byType.begin(); it != byType.end(); ++it) {
        QPieSlice *slice = pieSeries->append(it.key(), it.value());
        double pct = total > 0 ? (double)it.value() / total * 100.0 : 0.0;
        slice->setLabel(QString("%1 (%2%)").arg(it.key()).arg(QString::number(pct, 'f', 1)));
        slice->setLabelVisible(true);
        QColor base(colors[colorIndex % colors.size()]);
        QLinearGradient grad(0, 0, 100, 100);
        grad.setColorAt(0.0, base.lighter(130));
        grad.setColorAt(0.5, base);
        grad.setColorAt(1.0, base.darker(140));
        slice->setBrush(QBrush(grad));
        slice->setPen(QPen(base.darker(160), 1.5));
        if (it.value() > maxCount) { maxCount = it.value(); maxKey = it.key(); }
        colorIndex++;
    }
    for (auto s : pieSeries->slices()) {
        if (s->label().startsWith(maxKey)) { s->setExploded(true); s->setPen(QPen(Qt::darkGray, 2)); }
    }

    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Répartition par type de véhicule");
    pieChart->setAnimationOptions(QChart::AllAnimations);
    pieChart->setBackgroundVisible(false);
    pieChart->setPlotAreaBackgroundVisible(false);
    pieChart->legend()->setAlignment(Qt::AlignRight);
    QChartView *pieView = new QChartView(pieChart);
    pieView->setRenderHint(QPainter::Antialiasing);
    pieView->setStyleSheet("background: transparent");
    pieView->setAttribute(Qt::WA_TranslucentBackground);

    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(pieView);
    shadow->setBlurRadius(18);
    shadow->setOffset(0, 3);
    shadow->setColor(QColor(0,0,0,80));
    pieView->setGraphicsEffect(shadow);
    v->addWidget(pieView);
}

void vehicule::on_pb_pdf_clicked()
{
    on_pushButton_pdf_clicked();
}


void vehicule::on_lineEdit_3_textChanged(const QString &arg1)
{
    on_recherche_textChanged(arg1);
}

void vehicule::on_recherche_textChanged(const QString &arg1)
{
    if (!proxyModel) return;

    proxyModel->setFilterFixedString(arg1);

    qDebug() << "Recherche appliquée:" << arg1 << ", lignes visibles:" << proxyModel->rowCount();

    // Rafraîchir la vue
    ui->tableView->reset();
}





void vehicule::on_pushButton_reco_window_clicked()
{
    QDialog *dlg = new QDialog(this);
    dlg->setWindowTitle("Recommandation IA");
    dlg->setModal(true);
    dlg->resize(520, 460);
    dlg->setStyleSheet("QDialog{background:#f7f9fc;} QLabel{font-weight:bold;color:#2c3e50;} QPushButton{border-radius:8px;padding:8px 14px;font-weight:bold;color:white;} QPushButton#reco{background:#2c3e50;} QPushButton#micro{background:#27ae60;} QPushButton#speak{background:#3498db;} QTextEdit{background:white;border:1px solid #ccd; border-radius:6px;} QListWidget{background:white;border:1px solid #ccd; border-radius:6px;}");

    QVBoxLayout *v = new QVBoxLayout(dlg);
    QLabel *title = new QLabel("Choisissez vos préférences");
    title->setAlignment(Qt::AlignCenter);
    v->addWidget(title);

    QTextEdit *prefs = new QTextEdit();
    prefs->setPlaceholderText("Ex: Berline automatique 5 places faible kilométrage bon état");
    v->addWidget(prefs);

    QHBoxLayout *btns = new QHBoxLayout();
    QPushButton *btnReco = new QPushButton("Recommander"); btnReco->setObjectName("reco");
    QPushButton *btnMic = new QPushButton("🎙️"); btnMic->setObjectName("micro");
    QPushButton *btnSpeak = new QPushButton("🔊"); btnSpeak->setObjectName("speak");
    btns->addStretch(); btns->addWidget(btnReco); btns->addWidget(btnMic); btns->addWidget(btnSpeak); btns->addStretch();
    v->addLayout(btns);

    QListWidget *list = new QListWidget();
    v->addWidget(list);

    auto recommend = [this, prefs, list]() {
        QString p = prefs->toPlainText().toLower().trimmed();
        QString preferredType; if (p.contains("suv")) preferredType = "SUV"; else if (p.contains("berline")) preferredType = "Berline"; else if (p.contains("voiture")) preferredType = "Voiture";
        bool preferAuto = p.contains("auto"); bool preferManuel = p.contains("manuel"); bool preferLowKm = p.contains("faible") || p.contains("peu") || p.contains("low") || p.contains("moins");
        QString preferredEtat; if (p.contains("bon")) preferredEtat = "Bon"; else if (p.contains("moyen")) preferredEtat = "Moyen"; else if (p.contains("reviser")) preferredEtat = "A reviser";
        QRegularExpression re("(\\d+)"); QRegularExpressionMatch m = re.match(p); int desiredCap = m.hasMatch() ? m.captured(1).toInt() : -1;
        struct Item{int row; double score;}; QVector<Item> items; items.reserve(model->rowCount());
        for (int r=0;r<model->rowCount();++r){ QSqlRecord rec=model->record(r); QString dispo=rec.value("DISPONIBILITE").toString(); QString type=rec.value("TYPE_VEHICULE").toString(); QString etat=rec.value("ETAT").toString(); int cap=rec.value("CAPACITE").toInt(); double km=rec.value("KILOMETRAGE").toDouble(); QString marque=rec.value("MARQUE").toString().toLower(); double s=0.0; if(dispo=="Disponible") s+=50.0; else s-=20.0; if(!preferredType.isEmpty() && type.contains(preferredType,Qt::CaseInsensitive)) s+=20.0; if(preferAuto && type.contains("automatique",Qt::CaseInsensitive)) s+=10.0; if(preferManuel && type.contains("manuel",Qt::CaseInsensitive)) s+=10.0; if(!preferredEtat.isEmpty() && etat.compare(preferredEtat,Qt::CaseInsensitive)==0) s+=10.0; if(desiredCap>0) s+=qMax(0.0,15.0-qAbs(cap-desiredCap)*3.0); if(preferLowKm) s+=qMax(0.0,20.0-qMin(km/5000.0,20.0)); QStringList brands={"ford","kia","toyota","bmw","mercedes","renault","peugeot","audi","rang rover","range rover"}; for(const QString &b:brands) if(p.contains(b) && marque.contains(b)){ s+=10.0; break;} items.append({r,s}); }
        std::sort(items.begin(),items.end(),[](const Item&a,const Item&b){return a.score>b.score;});
        list->clear(); int count=qMin(5,items.size()); for(int i=0;i<count;++i){ QSqlRecord rec=model->record(items[i].row); list->addItem(QString("%1 — %2 — %3 — %4 km — %5 places — %6").arg(rec.value("MARQUE").toString(), rec.value("IMMATRICULATION").toString(), rec.value("TYPE_VEHICULE").toString(), rec.value("KILOMETRAGE").toString(), rec.value("CAPACITE").toString(), rec.value("ETAT").toString())); }
    };

    connect(btnReco,&QPushButton::clicked, recommend);
    connect(btnMic,&QPushButton::clicked,[this,prefs](){ QString script=R"(Add-Type -AssemblyName System.Speech;$rec=New-Object System.Speech.Recognition.SpeechRecognitionEngine;$rec.SetInputToDefaultAudioDevice();$rec.LoadGrammar([System.Speech.Recognition.DictationGrammar]::new());$res=$rec.Recognize();if($res){[Console]::OutputEncoding=[System.Text.Encoding]::UTF8;Write-Output $res.Text})"; QProcess *p=new QProcess(this); QStringList args; args<<"-NoProfile"<<"-Command"<<script; p->start("powershell",args); if(!p->waitForFinished(15000)){ p->kill(); return;} QString out=QString::fromUtf8(p->readAllStandardOutput()).trimmed(); prefs->setPlainText(out); p->deleteLater(); });
    connect(btnSpeak,&QPushButton::clicked,[this,list](){ if(!tts) return; QString t=list->currentItem()?list->currentItem()->text():(list->count()>0?list->item(0)->text():QString("Aucune recommandation")); tts->say(t); });

    dlg->exec();
}

void vehicule::on_pushButton_6_clicked()
{
    bool ok;
    QStringList orders = {"Croissant (A-Z)", "Décroissant (Z-A)"};
    QString selectedOrder = QInputDialog::getItem(this, "Trier par Marque",
                                                  "Choisir l'ordre de tri:", orders, 0, false, &ok);
    if (!ok || selectedOrder.isEmpty()) {
        return;
    }

    int brandCol = columnMapping.contains("MARQUE") ? columnMapping["MARQUE"] : 1;
    Qt::SortOrder order = (selectedOrder == orders[0]) ? Qt::AscendingOrder : Qt::DescendingOrder;
    proxyModel->sort(brandCol, order);
    QString orderText = (order == Qt::AscendingOrder) ? "croissant" : "décroissant";
    QMessageBox::information(this, "Tri appliqué",
                             QString("Tri effectué par Marque (%1)").arg(orderText));
}

void vehicule::on_pushButton_pdf_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF",
                                                    "vehicules_" + QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss") + ".pdf",
                                                    "PDF Files (*.pdf)");
    if (fileName.isEmpty()) {
        return;
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    QString html;
    html += "<html><head>";
    html += "<meta charset='utf-8'>";
    html += "<style>"
            "body{font-family:Arial,Helvetica,sans-serif;color:#2c3e50;}"
            "h1{font-size:24px;text-align:center;margin:0 0 12px 0;}"
            ".date{font-size:12px;text-align:center;margin-bottom:18px;color:#555;}"
            "table{width:95%;margin:0 auto;border-collapse:collapse;table-layout:fixed;}"
            "th,td{border:2px solid #999;padding:12px;font-size:12px;word-break:break-word;}"
            "th{background:#e6e6e6;color:#333;font-weight:bold;text-align:center;}"
            "td{text-align:left;vertical-align:middle;}"
            "</style>";
    html += "</head><body>";
    html += "<h1>Liste des Véhicules</h1>";
    html += "<div class='date'>Date: " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm") + "</div>";
    html += "<table>";
    html += "<thead><tr>"
            "<th>Marque</th>"
            "<th>Immatriculation</th>"
            "<th>Type</th>"
            "<th>Kilométrage</th>"
            "<th>État</th>"
            "<th>Disponibilité</th>"
            "<th>Capacité</th>"
            "</tr></thead><tbody>";

    for (int row = 0; row < model->rowCount(); ++row) {
        QSqlRecord record = model->record(row);
        QString marque = record.value("MARQUE").toString();
        QString immat = record.value("IMMATRICULATION").toString();
        QString type = record.value("TYPE_VEHICULE").toString();
        QString km = record.value("KILOMETRAGE").toString();
        QString etat = record.value("ETAT").toString();
        QString dispo = record.value("DISPONIBILITE").toString();
        QString cap = record.value("CAPACITE").toString();

        html += "<tr>";
        html += "<td>" + marque + "</td>";
        html += "<td>" + immat + "</td>";
        html += "<td>" + type + "</td>";
        html += "<td style=\"text-align:center\">" + km + "</td>";
        html += "<td>" + etat + "</td>";
        html += "<td>" + dispo + "</td>";
        html += "<td style=\"text-align:center\">" + cap + "</td>";
        html += "</tr>";
    }

    html += "</tbody></table></body></html>";

    QTextDocument doc;
    doc.setHtml(html);
    doc.print(&printer);

    QMessageBox::information(this, "Export Réussi", "Les données ont été exportées avec succès dans " + fileName);
}

void vehicule::on_tableView_clicked(const QModelIndex &index)
{
    if (!index.isValid())
        return;

    QModelIndex srcIndex = proxyModel ? proxyModel->mapToSource(index) : index;
    selectedRow = srcIndex.row();

    QSqlRecord record = model->record(selectedRow);
    if (ui->lineEdit_marque) ui->lineEdit_marque->setText(record.value("marque").toString());
    if (ui->lineEdit_immatriculation) ui->lineEdit_immatriculation->setText(record.value("immatriculation").toString());
    if (ui->comboBox_type) ui->comboBox_type->setCurrentText(record.value("type").toString());
    if (ui->lineEdit_kilometrage) ui->lineEdit_kilometrage->setText(record.value("kilometrage").toString());
    if (ui->comboBox_etat) ui->comboBox_etat->setCurrentText(record.value("etat").toString());
    if (ui->comboBox_disponibilite) ui->comboBox_disponibilite->setCurrentText(record.value("disponibilite").toString());
    if (ui->lineEdit_capacite) ui->lineEdit_capacite->setText(record.value("capacite").toString());
}

// Fonctions manquantes pour résoudre les erreurs de compilation

void vehicule::on_pushButton_entretien_clicked()
{
    // Fonction supprimée - bouton non utilisé dans l'interface actuelle
    QMessageBox::information(this, "Fonction non disponible",
                             "Cette fonctionnalité n'est pas disponible dans la version actuelle.");
}

void vehicule::on_pushButton_stats_chart_clicked()
{
    // Fonction supprimée - remplacée par on_pb_stat_clicked()
    on_pb_stat_clicked();
}

void vehicule::on_pushButton_4_clicked()
{
    // Redirection vers la fonction PDF
    on_pb_pdf_clicked();
}

void vehicule::on_pushButton_5_clicked()
{
    // Redirection vers la fonction statistiques
    on_pb_stat_clicked();
}


void vehicule::on_pb_calendar_clicked()
{
    // Fonction supprimée - calendrier non disponible dans cette version
    QMessageBox::information(this, "Fonction non disponible",
                             "Le calendrier n'est pas disponible dans cette version.");
}

void vehicule::on_pb_calendar_2_clicked()
{
    // Redirection vers la fonction calendrier
    on_pb_calendar_clicked();
}

void vehicule::on_pushButton_retour_clicked()
{
    // Émettre le signal pour revenir au menu
    emit returnRequested();
}

void vehicule::on_pushButton_sms_alert_clicked()
{
    QSqlRecord record;
    if (selectedRow >= 0) {
        record = model->record(selectedRow);
    } else {
        QString imm = ui->lineEdit_immatriculation ? ui->lineEdit_immatriculation->text().trimmed() : QString();
        if (imm.isEmpty()) {
            QMessageBox::warning(this, "Alerte", "Sélectionnez un véhicule ou saisissez l'immatriculation.");
            return;
        }
        QSqlQuery q(QSqlDatabase::database("oracle_connection"));
        q.prepare("SELECT * FROM VEHICULES WHERE IMMATRICULATION = ?");
        q.addBindValue(imm.replace(" ", "").toUpper());
        if (!q.exec() || !q.next()) {
            QMessageBox::warning(this, "Alerte", "Véhicule introuvable.");
            return;
        }
        record = q.record();
    }

    int km = 0;
    if (columnMapping.contains("KILOMETRAGE")) {
        km = record.value(columnMapping["KILOMETRAGE"]).toInt();
    } else {
        km = record.value("KILOMETRAGE").toInt();
        if (km == 0) km = record.value("kilometrage").toInt();
    }

    QString immat = record.value(columnMapping.contains("IMMATRICULATION") ? columnMapping["IMMATRICULATION"] : record.indexOf("IMMATRICULATION")).toString();
    if (immat.isEmpty()) immat = record.value("immatriculation").toString();

    if (km <= 20000) {
        QMessageBox::information(this, "Information", "Kilométrage inférieur ou égal à 20000. Aucune alerte envoyée.");
        return;
    }

    QString marque = record.value(columnMapping.contains("MARQUE") ? columnMapping["MARQUE"] : record.indexOf("MARQUE")).toString();
    if (marque.isEmpty()) marque = record.value("marque").toString();

    QString message = QString("Alerte diagnostic: %1 (%2) a dépassé %3 km. Merci de planifier un diagnostic.").arg(marque).arg(immat).arg(km);

    QSettings settings;
    QStringList destinataires = settings.value("Notifications/Destinataires").toStringList();
    if (destinataires.isEmpty()) {
        destinataires << "+21624740996";
    }

    Maintenance m;
    bool ok = m.envoyerNotificationMaintenance(message, destinataires);
    if (ok) {
        QMessageBox::information(this, "SMS", "Notification SMS envoyée.");
    } else {
        QMessageBox::critical(this, "SMS", "Échec de l'envoi SMS. Vérifiez la configuration Twilio et le numéro.");
    }
}


