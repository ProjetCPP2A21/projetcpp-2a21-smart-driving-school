#include "apprenants.h"
#include "ui_apprenants.h"
<<<<<<< HEAD
#include <QMessageBox>
#include <QPdfWriter>
=======
#include "chatwindow.h"
#include <QMessageBox>
#include <QThread>  // Pour QThread::msleep
#include <QInputDialog>
#include <QPdfWriter>
#include <QTextEdit>
>>>>>>> 4229cbb (ajout arduino)
#include <QPainter>
#include <QFileDialog>
#include <QPageLayout>
#include <QPageSize>
#include <QMargins>
#include <QColor>
#include <QList>
#include <algorithm>
<<<<<<< HEAD
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
=======
#include <QChartView>
#include <QPieSeries>
#include <QChart>
>>>>>>> 4229cbb (ajout arduino)
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
<<<<<<< HEAD
=======
#include <QScreen>
#include <QApplication>
>>>>>>> 4229cbb (ajout arduino)

apprenants::apprenants(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::apprenants)
<<<<<<< HEAD
=======
    , m_chatbot(new ApiChatBot(this))
    , chatbotButton(nullptr)
>>>>>>> 4229cbb (ajout arduino)
{
    ui->setupUi(this);
    ui->label_message->setVisible(false);
    ui->dateEdit_naissance->setDate(QDate::currentDate().addYears(-18));
<<<<<<< HEAD
=======
    
    // Le chatbot local ne nécessite pas de connexions de signaux
    
    // Créer le bouton du chatbot avec un style amélioré
    // Le bouton est un enfant direct de la fenêtre principale (this)
    chatbotButton = new QPushButton("🤖", this);
    
    // Style moderne et attrayant pour le bouton
    // Pas besoin    // Style du bouton de l'assistant
    QString buttonStyle = 
        "QPushButton {\n"
        "    background-color: #4CAF50;\n"
        "    border: none;\n"
        "    color: white;\n"
        "    text-align: center;\n"
        "    text-decoration: none;\n"
        "    display: inline-block;\n"
        "    font-size: 24px;\n"
        "    margin: 4px 2px;\n"
        "    cursor: pointer;\n"
        "    border-radius: 12px;\n"
        "    width: 50px;\n"
        "    height: 50px;\n"
        "    box-shadow: 0 4px 8px 0 rgba(0,0,0,0.2);\n"
        "    transition: all 0.3s;\n"
        "}\n"
        "\n"
        "QPushButton:hover {\n"
        "    background-color: #45a049;\n"
        "    transform: scale(1.1);\n"
        "    box-shadow: 0 8px 16px 0 rgba(0,0,0,0.2);\n"
        "}\n"
        "\n"
        "QPushButton:pressed {\n"
        "    background-color: #3e8e41;\n"
        "    transform: scale(0.95);\n"
        "}";
    
    chatbotButton->setStyleSheet(buttonStyle);
    
    // Ajouter un effet d'ombre portée
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(10);
    effect->setXOffset(0);
    effect->setYOffset(2);
    effect->setColor(QColor(0, 0, 0, 60));
    chatbotButton->setGraphicsEffect(effect);
    
    // Ajouter une infobulle
    chatbotButton->setToolTip("Cliquez pour poser une question sur le code de la route");
    
    // Positionnement initial du bouton dans le coin inférieur droit
    int buttonSize = 50;
    int margin = 5;  // Marge réduite pour déplacer le bouton plus à droite
    
    chatbotButton->setFixedSize(buttonSize, buttonSize);
    
    // Positionner dans le coin inférieur droit avec marge
    chatbotButton->move(width() - buttonSize - margin,  // À droite avec marge
                       height() - buttonSize - margin);  // En bas avec marge
    
    // Initialiser la communication avec l'Arduino
    setupArduino();
    
    // La position sera mise à jour dans la méthode resizeEvent
    
    connect(chatbotButton, &QPushButton::clicked, this, &apprenants::onChatbotButtonClicked);
    
    // Afficher une notification de bienvenue après un court délai
    QTimer::singleShot(1000, this, [this]() {
        afficherNotification("Bienvenue", 
                           "Bienvenue dans Smart Driving School ! Commencez par ajouter un apprenant.", 
                           NotificationType::MOTIVATION, 
                           8000);
        
        // Afficher une notification de rappel après un délai plus long
        QTimer::singleShot(5000, this, [this]() {
            afficherNotification("Astuce rapide", 
                               "Utilisez le bouton vert en bas à droite pour accéder à l'assistant virtuel.", 
                               NotificationType::TIP, 
                               10000);
        });
    });
    
>>>>>>> 4229cbb (ajout arduino)
    afficherMessageControle("Connexion réussie !", false);
    afficherApprenants();
}

<<<<<<< HEAD
apprenants::~apprenants()
{
    delete ui;
=======
void apprenants::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    
    // Mettre à jour la position du bouton lors du redimensionnement
    if (chatbotButton) {
        int buttonSize = 50;
        int margin = 5;  // Marge réduite pour déplacer le bouton plus à droite
        chatbotButton->move(width() - buttonSize - margin,
                          height() - buttonSize - margin);
    }
}

apprenants::~apprenants()
{
    delete ui;
    delete m_chatbot;
    delete chatbotButton;
    
    // Fermer la connexion série si elle est ouverte
    if (arduino && arduino->isOpen()) {
        arduino->close();
    }
    delete arduino;
    
    // Nettoyer les notifications
    qDeleteAll(m_notifications);
    m_notifications.clear();
}

void apprenants::onChatbotButtonClicked()
{
    // Vérifier si la clé API est configurée
    QString apiKey = m_chatbot->loadApiKey();
    if (apiKey.isEmpty()) {
        // Si la clé n'est pas configurée, demander à l'utilisateur de la saisir
        bool ok;
        apiKey = QInputDialog::getText(this, 
                                     "Configuration requise",
                                     "Veuillez entrer votre clé API OpenAI :",
                                     QLineEdit::Normal,
                                     "",
                                     &ok);
        if (ok && !apiKey.isEmpty()) {
            m_chatbot->saveApiKey(apiKey);
        } else {
            QMessageBox::warning(this, "Configuration requise", 
                               "Une clé API valide est nécessaire pour utiliser l'assistant.");
            return;
        }
    }

    // Créer et afficher la fenêtre de chat
    ChatWindow *chatWindow = new ChatWindow(this);
    chatWindow->setAttribute(Qt::WA_DeleteOnClose);  // Supprimer la fenêtre lorsqu'elle est fermée
    chatWindow->show();
}

void apprenants::onChatbotResponse(const QString &response)
{
    // Créer une boîte de dialogue personnalisée
    QDialog dialog(this);
    dialog.setWindowTitle("🔍 Réponse de l'assistant");
    dialog.setMinimumWidth(500);
    
    // Style pour la boîte de dialogue
    dialog.setStyleSheet(
        "QDialog {\n"
        "    background-color: #f8f9fa;\n"
        "    font-family: 'Segoe UI', Arial, sans-serif;\n"
        "}\n"
        "\n"
        "QTextEdit {\n"
        "    border: 1px solid #dee2e6;\n"
        "    border-radius: 8px;\n"
        "    padding: 15px;\n"
        "    background-color: white;\n"
        "    font-size: 14px;\n"
        "    line-height: 1.5;\n"
        "}\n"
        "\n"
        "QPushButton {\n"
        "    background-color: #4a6baf;\n"
        "    color: white;\n"
        "    border: none;\n"
        "    border-radius: 5px;\n"
        "    padding: 8px 20px;\n"
        "    font-weight: bold;\n"
        "}\n"
        "\n"
        "QPushButton:hover {\n"
        "    background-color: #3a5b9f;\n"
        "}"
    );
    
    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    
    // Zone de texte pour la réponse avec mise en forme
    QTextEdit *textEdit = new QTextEdit();
    textEdit->setText(response);
    textEdit->setReadOnly(true);
    textEdit->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::LinksAccessibleByMouse);
    
    // Bouton de fermeture
    QPushButton *closeButton = new QPushButton("Fermer");
    connect(closeButton, &QPushButton::clicked, &dialog, &QDialog::accept);
    
    // Ajout des widgets au layout
    layout->addWidget(textEdit);
    
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(closeButton);
    
    layout->addLayout(buttonLayout);
    
    // Afficher la boîte de dialogue
    dialog.exec();
}

void apprenants::onChatbotError(const QString &error)
{
    // Boîte de dialogue d'erreur simplifiée pour le chatbot local
    QMessageBox::warning(this, 
                        "Erreur de l'assistant", 
                        "Désolé, une erreur est survenue :\n" + error);
>>>>>>> 4229cbb (ajout arduino)
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
<<<<<<< HEAD
        afficherMessageControle(
            QString("Apprenant %1 %2 (ID %3) ajouté avec succès !")
                .arg(prenom).arg(nom).arg(id),
            false);
        afficherApprenants();
        reinitialiserFormulaire();
    } else {
        afficherMessageControle("Échec de l'ajout : veuillez réessayer.");
=======
        QString message = QString("L'apprenant %1 %2 a été ajouté avec succès").arg(prenom, nom);
        afficherMessageControle("Ajout avec succès", false);
        ui->tableView_apprenants->setModel(a.afficher());
        reinitialiserFormulaire();
        
        // Afficher une notification de succès
        afficherNotification("Nouvel apprenant", message, NotificationType::MOTIVATION);
        
        // Afficher une notification pour les modules disponibles
        QTimer::singleShot(2000, this, [this]() {
            afficherNotification("Module disponible", 
                               "Découvrez nos nouveaux modules de formation", 
                               NotificationType::THEORY, 
                               10000);
        });
    } else {
        afficherMessageControle("Erreur lors de l'ajout");
        afficherNotification("Erreur", 
                           "Impossible d'ajouter l'apprenant. Veuillez réessayer.", 
                           NotificationType::ALERT);
>>>>>>> 4229cbb (ajout arduino)
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
<<<<<<< HEAD
        afficherMessageControle(
            QString("Apprenant %1 %2 (ID %3) modifié avec succès !")
                .arg(prenom).arg(nom).arg(id),
            false);
        afficherApprenants();
        reinitialiserFormulaire();
    } else {
        afficherMessageControle("Échec de la modification : veuillez réessayer.");
=======
        QString message = QString("Les informations de %1 %2 (ID %3) ont été mises à jour")
                            .arg(prenom, nom).arg(id);
        
        afficherMessageControle("Modification réussie !", false);
        afficherApprenants();
        reinitialiserFormulaire();
        
        // Afficher une notification de succès
        afficherNotification("Mise à jour réussie", message, NotificationType::TIP);
        
        // Si c'est une mise à jour de numéro de téléphone, afficher un rappel
        if (!tel.isEmpty()) {
            QTimer::singleShot(1500, this, [this, prenom, nom]() {
                afficherNotification("Rappel important", 
                                   QString("N'oubliez pas de confirmer votre numéro de téléphone, %1").arg(prenom), 
                                   NotificationType::REMINDER, 
                                   8000);
            });
        }
    } else {
        afficherMessageControle("Échec de la modification : veuillez réessayer.");
        afficherNotification("Erreur de modification", 
                           "La mise à jour des informations a échoué. Veuillez réessayer.", 
                           NotificationType::ALERT);
>>>>>>> 4229cbb (ajout arduino)
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

<<<<<<< HEAD
    if(service.supprimer(id)){
        afficherMessageControle(
            QString("Apprenant (ID %1) supprimé avec succès.").arg(id),
            false);
        afficherApprenants();
        reinitialiserFormulaire();
    } else {
        afficherMessageControle("Échec de la suppression : veuillez réessayer.");
=======
    // Récupérer le nom et prénom avant la suppression pour l'affichage
    QString nom = ui->lineEdit_nom->text().trimmed();
    QString prenom = ui->lineEdit_prenom->text().trimmed();
    
    if(service.supprimer(id)){
        QString message = QString("L'apprenant %1 %2 (ID %3) a été supprimé").arg(prenom, nom).arg(id);
        
        afficherMessageControle("Suppression effectuée avec succès !", false);
        afficherApprenants();
        reinitialiserFormulaire();
        
        // Afficher une notification de confirmation
        afficherNotification("Suppression réussie", message, NotificationType::ALERT);
        
        // Afficher une notification de suggestion après un court délai
        QTimer::singleShot(2000, this, [this]() {
            afficherNotification("Astuce", 
                               "Vous pouvez ajouter un nouvel apprenant en utilisant le formulaire ci-dessus.", 
                               NotificationType::TIP, 
                               5000);
        });
    } else {
        afficherMessageControle("Échec de la suppression : l'apprenant n'existe pas ou une erreur est survenue.");
        afficherNotification("Erreur de suppression", 
                           "La suppression a échoué. L'apprenant n'existe pas ou une erreur est survenue.", 
                           NotificationType::ALERT);
>>>>>>> 4229cbb (ajout arduino)
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
<<<<<<< HEAD
        QMessageBox::warning(this, "Erreur", "Aucune donnée à exporter !");
=======
        afficherMessageControle("Erreur", "Aucune donnée à exporter !");
>>>>>>> 4229cbb (ajout arduino)
        return;
    }

    QPdfWriter pdf(fileName);
    pdf.setPageSize(QPageSize::A4);
    pdf.setPageMargins(QMargins(20, 20, 20, 20), QPageLayout::Millimeter);

    QPainter painter(&pdf);
    if(!painter.isActive()){
<<<<<<< HEAD
        QMessageBox::critical(this, "Erreur", "Impossible de créer le PDF !");
=======
       afficherMessageControle("Erreur", "Impossible de créer le PDF !");
>>>>>>> 4229cbb (ajout arduino)
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
<<<<<<< HEAD
    QMessageBox::information(this, "PDF", "Exportation réussie !");
=======
    afficherMessageControle( "PDF Exportation réussie !", false);
>>>>>>> 4229cbb (ajout arduino)
}

// -------------------- STATISTIQUES --------------------
void apprenants::on_pushButton_statistique_clicked()
{
    Apprenant a;
    QMap<QString,int> stats = a.statistiquesSexe();
<<<<<<< HEAD
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
=======
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

    // Création de la fenêtre de dialogue
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Statistiques des apprenants");
    dialog->setMinimumSize(800, 600);
    
    // Configuration de la vue du graphique
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    
    // Mise en page
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);
    
    // Ajouter un bouton de fermeture
    QPushButton *closeButton = new QPushButton("Fermer", dialog);
    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);
    layout->addWidget(closeButton, 0, Qt::AlignRight);
    
    // Afficher la fenêtre
    dialog->setLayout(layout);
>>>>>>> 4229cbb (ajout arduino)
    dialog->exec();
}

// -------------------- SELECTION LIGNE --------------------
void apprenants::on_tableView_apprenants_clicked(const QModelIndex &index)
{
<<<<<<< HEAD
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
=======
    int row = index.row();
    QVariant id = ui->tableView_apprenants->model()->data(ui->tableView_apprenants->model()->index(row, 0));
    QVariant nom = ui->tableView_apprenants->model()->data(ui->tableView_apprenants->model()->index(row, 1));
    QVariant prenom = ui->tableView_apprenants->model()->data(ui->tableView_apprenants->model()->index(row, 2));
    QVariant date_naissance = ui->tableView_apprenants->model()->data(ui->tableView_apprenants->model()->index(row, 3));
    QVariant tel = ui->tableView_apprenants->model()->data(ui->tableView_apprenants->model()->index(row, 4));
    QVariant sexe = ui->tableView_apprenants->model()->data(ui->tableView_apprenants->model()->index(row, 5));
    QVariant adresse = ui->tableView_apprenants->model()->data(ui->tableView_apprenants->model()->index(row, 6));

    ui->lineEdit_id->setText(id.toString());
    ui->lineEdit_nom->setText(nom.toString());
    ui->lineEdit_prenom->setText(prenom.toString());
    ui->dateEdit_naissance->setDate(QDate::fromString(date_naissance.toString(), "dd/MM/yyyy"));
    ui->lineEdit_telephone->setText(tel.toString());
    ui->comboBox_sexe->setCurrentText(sexe.toString());
    ui->lineEdit_adresse->setText(adresse.toString());
}

void apprenants::afficherNotification(const QString &titre, const QString &message, NotificationType type, int dureeAffichage)
{
    // Nettoyer les notifications terminées
    nettoyerNotifications();
    
    // Créer et afficher une nouvelle notification
    Notification *notification = new Notification(this);
    notification->showNotification(titre, message, type, dureeAffichage);
    
    // Connecter le signal de clic sur la notification
    connect(notification, &Notification::notificationClicked, this, [this](NotificationType type, const QString &titre) {
        // Gérer l'action lorsque l'utilisateur clique sur une notification
        QMessageBox::information(this, titre, 
            QString("Action pour la notification de type %1").arg(static_cast<int>(type)));
    });
    
    // Positionner la notification en fonction du nombre de notifications déjà affichées
    QScreen *screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    int y = screenGeometry.height() - 150 - (m_notifications.size() * 150);
    notification->move(screenGeometry.width() - notification->width() - 20, y);
    
    // Ajouter à la liste des notifications actives
    m_notifications.append(notification);
}

void apprenants::nettoyerNotifications()
{
    // Supprimer les notifications qui ne sont plus affichées
    for (int i = m_notifications.size() - 1; i >= 0; --i) {
        if (!m_notifications[i] || !m_notifications[i]->isVisible()) {
            delete m_notifications.takeAt(i);
        }
    }
}

void apprenants::setupArduino()
{
    arduino = new QSerialPort(this);
    
    // Configuration pour utiliser spécifiquement COM8
    arduino->setPortName("COM8");

    // Vérifier si le port est disponible
    bool portDisponible = false;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.portName() == "COM8") {
            portDisponible = true;
            break;
        }
    }

    if (!portDisponible) {
        afficherMessageControle("Le port COM8 n'est pas disponible", true);
        return;
    }

    // Configuration du port série
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);

    if (!arduino->open(QIODevice::ReadWrite)) {
        afficherMessageControle("Impossible d'ouvrir le port " + arduino->portName(), true);
        return;
    }

    // Attendre que la connexion soit établie
    QThread::sleep(2); // Attente de 2 secondes pour l'initialisation
    arduino->clear(); // Vider les buffers

    // Se connecter au signal readyRead
    connect(arduino, &QSerialPort::readyRead,
            this, &apprenants::lireArduino);

    // Configuration de la temporisation pour la lecture en continu
    arduino->setReadBufferSize(64); // Taille du buffer de lecture
    arduino->setDataTerminalReady(true); // Activer DTR pour certains modules RFID

    afficherNotification("Arduino", "Connexion établie sur " + arduino->portName(),
                         NotificationType::INFORMATION);
    qDebug() << "Connexion Arduino établie sur" << arduino->portName() << "à 9600 bauds";
}

void apprenants::lireArduino()
{
    static QByteArray buffer;
    static qint64 lastReadTime = 0;
    const qint64 debounceTime = 1000; // Délai d'attente en ms entre deux lectures
    
    qint64 currentTime = QDateTime::currentMSecsSinceEpoch();
    
    // Vérifier si le délai minimum entre deux lectures est respecté
    if ((currentTime - lastReadTime) < debounceTime) {
        arduino->clear(); // Nettoyer le buffer pour éviter les lectures en attente
        return;
    }
    
    // Lire toutes les données disponibles
    while (arduino->bytesAvailable() > 0) {
        buffer += arduino->readAll();
        // Petite pause pour permettre la réception de données supplémentaires
        QCoreApplication::processEvents();
        QThread::usleep(5000);  // Réduit à 5ms pour une meilleure réactivité
    }

    // Vérifier si nous avons une ligne complète
    int endOfLine = buffer.indexOf('\n');
    if (endOfLine == -1) {
        // Pas de ligne complète reçue encore
        // Si le buffer devient trop grand, le vider pour éviter les fuites de mémoire
        if (buffer.size() > 100) {
            buffer.clear();
            qDebug() << "Buffer nettoyé pour éviter les fuites de mémoire";
        }
        return;
    }

    // Extraire la ligne complète
    QByteArray ligneComplete = buffer.left(endOfLine).trimmed();
    // Conserver le reste dans le buffer
    buffer = buffer.mid(endOfLine + 1);

    // Traiter la ligne reçue
    QString ligne = QString::fromUtf8(ligneComplete);
    qDebug() << "Données brutes reçues:" << ligne;

    // Vérifier le format UID (ex: "UID:0102A3B4")
    if (ligne.startsWith("UID:")) {
        QString uid = ligne.mid(4).trimmed().toUpper();
        if (!uid.isEmpty()) {
            // Formater l'UID pour un affichage plus lisible (ajouter des tirets)
            QString formattedUid;
            for (int i = 0; i < uid.length(); i += 2) {
                if (i > 0) formattedUid += "-";
                formattedUid += uid.mid(i, 2);
            }
            
            // Mettre à jour le temps de la dernière lecture valide
            lastReadTime = currentTime;
            
            qDebug() << "UID détecté :" << formattedUid;
            emit rfidDetected(formattedUid);
            
            // Vérifier l'UID et afficher le message approprié
            if (formattedUid == "D3-2F-3F-44") {
                afficherNotification("Accès autorisé", "ID valide : " + formattedUid,
                                   NotificationType::MOTIVATION, 2000);
            } else if (formattedUid == "FF-78-07-C6") {
                afficherNotification("Accès refusé", "ID invalide : " + formattedUid,
                                   NotificationType::ALERT, 2000);
            } else {
                afficherNotification("Carte détectée", "UID : " + formattedUid,
                                   NotificationType::INFORMATION, 2000);
            }
            
            // Vider le buffer après détection
            buffer.clear();
            
            // Vider le buffer de réception matériel
            arduino->clear();
            
            // Ajouter un délai logiciel pour éviter les lectures multiples
            QThread::msleep(100);
        }
    }
>>>>>>> 4229cbb (ajout arduino)
}
