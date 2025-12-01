#include "chatwindow.h"
#include "ui_chatwindow.h"
#include "apichatbot.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QLineEdit>
#include <QPushButton>
#include <QInputDialog>
#include <QDebug>
#include <QTimer>
#include <QScrollBar>
#include <QToolButton>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QScrollBar>
#include <QRandomGenerator>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QFileDialog>
#include <QDir>
#include <QDateTime>
#include <QTextEdit>

ChatWindow::ChatWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::ChatWindow)
{
    ui->setupUi(this);

    m_chatbot = new ApiChatBot(this);

    // Connexion du signal pour recevoir la réponse de l'API
    if (m_chatbot) {
        connect(m_chatbot, &ApiChatBot::responseReceived, this, [this](const QString &response) {
            addMessage("Assistant", response, false);
        });
        connect(m_chatbot, &ApiChatBot::errorOccurred, this, [this](const QString &error) {
            addMessage("Erreur", error, false);
        });
    }

    // Setup interface
    ui->sendButton->setText("Envoyer");
    ui->sendButton->setIcon(QIcon(":/icons/send.png"));
    ui->sendButton->setIconSize(QSize(16, 16));
    ui->sendButton->setStyleSheet(
        "QPushButton { "
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #4f46e5, stop:1 #7c3aed);"
        "    color: white;"
        "    border: none;"
        "    border-radius: 12px;"
        "    padding: 8px 20px;"
        "    font-size: 14px;"
        "    font-weight: 600;"
        "    min-width: 100px;"
        "    box-shadow: 0 2px 4px rgba(79, 70, 229, 0.3);"
        "    transition: all 0.2s ease;"
        "}"
        "QPushButton:hover { "
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #4338ca, stop:1 #6d28d9);"
        "    box-shadow: 0 4px 8px rgba(79, 70, 229, 0.4);"
        "    transform: translateY(-1px);"
        "}"
        "QPushButton:pressed { "
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #3730a3, stop:1 #5b21b6);"
        "    box-shadow: 0 1px 2px rgba(0,0,0,0.1);"
        "    transform: translateY(1px);"
        "}"
    );
    
    // Style pour le champ de saisie
    ui->messageInput->setPlaceholderText("Tapez votre message...");
    ui->messageInput->setStyleSheet(
        "QLineEdit { "
        "    border: 2px solid #e2e8f0;"
        "    border-radius: 12px;"
        "    padding: 10px 15px;"
        "    font-size: 14px;"
        "    background: white;"
        "    selection-background-color: #4f46e5;"
        "}"
        "QLineEdit:focus { "
        "    border: 2px solid #a5b4fc;"
        "    background: #f8fafc;"
        "}"
    );

    // Ajout des boutons de configuration
    QToolButton *configButton = new QToolButton(this);
    configButton->setIcon(QIcon(":/icons/settings.png"));
    configButton->setToolTip("Configurer l'API");
    configButton->setStyleSheet("QToolButton { border: none; padding: 5px; }");
    
    QToolButton *modelsButton = new QToolButton(this);
    modelsButton->setText("Modèles");
    modelsButton->setToolTip("Afficher les modèles disponibles");
    modelsButton->setStyleSheet("QToolButton { border: 1px solid #ccc; padding: 5px; border-radius: 3px; }");
    
    // Connexion des boutons
    connect(modelsButton, &QToolButton::clicked, this, &ChatWindow::listModels);
    
    // Connexion du bouton d'envoi de message
    connect(ui->sendButton, &QPushButton::clicked, this, &ChatWindow::sendMessage);
    
    // Connexion de la touche Entrée dans le champ de message
    connect(ui->messageInput, &QLineEdit::returnPressed, this, &ChatWindow::sendMessage);
    
    // Création des boutons
    QPushButton *saveButton = new QPushButton("Sauvegarder", this);
    QPushButton *clearButton = new QPushButton("Effacer", this);
    QPushButton *historyButton = new QPushButton("Historique", this);
    
    // Style moderne pour le bouton Sauvegarder
    QString saveButtonStyle = "QPushButton { "
                            "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #00c6ff, stop:1 #0072ff);"
                            "    color: white;"
                            "    border: none;"
                            "    border-radius: 8px;"
                            "    padding: 2px 8px;"
                            "    font-size: 10px;"
                            "    font-weight: 500;"
                            "    min-width: 70px;"
                            "    max-height: 24px;"
                            "    box-shadow: 0 1px 1px rgba(0,0,0,0.1);"
                            "}"
                            "QPushButton:hover { "
                            "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #00b4ff, stop:1 #0066ff);"
                            "    box-shadow: 0 4px 8px rgba(0, 115, 230, 0.3);"
                            "    transform: translateY(-1px);"
                            "}"
                            "QPushButton:pressed { "
                            "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #00a3e6, stop:1 #0052cc);"
                            "    box-shadow: 0 1px 2px rgba(0,0,0,0.1);"
                            "    transform: translateY(1px);"
                            "}";
    
    // Style moderne pour le bouton Effacer
    QString clearButtonStyle = "QPushButton { "
                             "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #ff416c, stop:1 #ff4b2b);"
                             "    color: white;"
                             "    border: none;"
                             "    border-radius: 8px;"
                             "    padding: 2px 8px;"
                             "    font-size: 10px;"
                             "    font-weight: 500;"
                             "    min-width: 70px;"
                             "    max-height: 24px;"
                             "    box-shadow: 0 1px 1px rgba(0,0,0,0.1);"
                             "}"
                             "QPushButton:hover { "
                             "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #ff2b6b, stop:1 #ff3a1f);"
                             "    box-shadow: 0 4px 8px rgba(255, 65, 108, 0.3);"
                             "    transform: translateY(-1px);"
                             "}"
                             "QPushButton:pressed { "
                             "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #e61e4d, stop:1 #d01c1f);"
                             "    box-shadow: 0 1px 2px rgba(0,0,0,0.1);"
                             "    transform: translateY(1px);"
                             "}";
    
    // Style moderne pour le bouton Historique
    QString historyButtonStyle = "QPushButton { "
                              "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #9C27B0, stop:1 #673AB7);"
                              "    color: white;"
                              "    border: none;"
                              "    border-radius: 8px;"
                              "    padding: 2px 8px;"
                              "    font-size: 10px;"
                              "    font-weight: 500;"
                              "    min-width: 70px;"
                              "    max-height: 24px;"
                              "    box-shadow: 0 1px 1px rgba(0,0,0,0.1);"
                              "}"
                              "QPushButton:hover { "
                              "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #8E24AA, stop:1 #5E35B1);"
                              "    box-shadow: 0 4px 8px rgba(156, 39, 176, 0.3);"
                              "}"
                              "QPushButton:pressed { "
                              "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #7B1FA2, stop:1 #512DA8);"
                              "    box-shadow: 0 1px 2px rgba(0,0,0,0.1);"
                              "}";
    
    saveButton->setStyleSheet(saveButtonStyle);
    clearButton->setStyleSheet(clearButtonStyle);
    historyButton->setStyleSheet(historyButtonStyle);
    
    // Connexion des boutons
    connect(saveButton, &QPushButton::clicked, this, &ChatWindow::saveChatHistory);
    connect(clearButton, &QPushButton::clicked, this, &ChatWindow::clearChatHistory);
    connect(historyButton, &QPushButton::clicked, this, &ChatWindow::showHistory);
    
    // Ajout des boutons à la barre d'outils avec un espacement cohérent
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->setSpacing(6);  // Espacement réduit entre les boutons
    topLayout->setContentsMargins(4, 4, 4, 4);  // Marges réduites
    topLayout->addWidget(saveButton);
    topLayout->addWidget(historyButton);
    topLayout->addStretch();
    topLayout->addWidget(clearButton);
    
    // Ajustement de la taille des boutons existants
    modelsButton->setIconSize(QSize(16, 16));
    configButton->setIconSize(QSize(16, 16));
    modelsButton->setFixedSize(24, 24);
    configButton->setFixedSize(24, 24);
    
    topLayout->addWidget(modelsButton);
    topLayout->addWidget(configButton);
    
    // Insérer la barre d'outils au-dessus de la zone de chat
    QVBoxLayout *mainLayout = qobject_cast<QVBoxLayout*>(layout());
    if (mainLayout) {
        mainLayout->insertLayout(0, topLayout);
    }

    // Connexion des signaux/slots
    connect(ui->sendButton, &QPushButton::clicked, this, &ChatWindow::sendMessage);
    connect(ui->messageInput, &QLineEdit::returnPressed, this, &ChatWindow::sendMessage);
    connect(configButton, &QToolButton::clicked, this, &ChatWindow::configureApi);
    
    // Le bouton de recherche a été supprimé de l'interface
    // La fonctionnalité d'embedding peut être appelée directement si nécessaire
    
    // Configurer le style de la fenêtre de chat
    setStyleSheet(
        "QDialog { background-color: #f5f5f5; }"
        "QScrollArea { background-color: white; border: none; }"
        "QLineEdit { "
        "    border: 1px solid #ddd; "
        "    border-radius: 15px; "
        "    padding: 5px 15px; "
        "    min-height: 30px;"
        "}"
        "QPushButton { "
        "    background-color: #007bff; "
        "    color: white; "
        "    border: none; "
        "    border-radius: 15px; "
        "    padding: 5px 15px; "
        "    min-height: 30px;"
        "}"
        "QPushButton:hover { "
        "    background-color: #0056b3; "
        "}"
    );
    
    // Configurer la zone de défilement
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);
    
    // Désactiver les barres de défilement horizontales
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    
    // Configurer les suggestions
    setupSuggestions();
    
    // Message d'accueil simplifié
    addMessage("Assistant", 
              "Bonjour ! Je suis votre assistant pour le code de la route tunisien. "
              "Comment puis-je vous aider aujourd'hui ?", 
              false);
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::sendMessage()
{
    QString userText = ui->messageInput->text().trimmed();
    if (userText.isEmpty())
        return;
        
    // Effacer le champ de saisie
    ui->messageInput->clear();
    
    // Afficher le message de l'utilisateur
    addMessage("Vous", userText, true);
    
    // Afficher l'indicateur de frappe
    QLabel *typingIndicator = new QLabel("L'assistant rédige une réponse...");
    typingIndicator->setStyleSheet("color: #666; font-style: italic;");
    typingIndicator->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    typingIndicator->setContentsMargins(10, 5, 10, 5);
    
    // Ajouter l'indicateur de frappe à l'interface
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->scrollAreaWidgetContents->layout());
    if (layout) {
        layout->addWidget(typingIndicator);
    }
    
    // Simuler un délai de frappe
    QTimer::singleShot(1500, this, [this, typingIndicator, userText]() {
        // Supprimer l'indicateur de frappe
        if (typingIndicator) {
            typingIndicator->deleteLater();
        }
        
        // Obtenir et afficher la réponse du chatbot
        if (m_chatbot) {
            // Si le chatbot a une méthode sendMessage asynchrone
            m_chatbot->sendMessage(userText);
        } else {
            addMessage("Assistant", "Désolé, le chatbot n'est pas disponible pour le moment.", false);
        }
    });  // Fin du singleShot
}

void ChatWindow::addMessage(const QString &sender, const QString &message, bool isUser)
{
    // Création du conteneur du message
    QWidget *messageWidget = new QWidget(this);
    QHBoxLayout *messageLayout = new QHBoxLayout(messageWidget);
    messageLayout->setContentsMargins(6, 6, 6, 6);
    messageLayout->setSpacing(8);

    // Horodatage
    QString timestamp = QTime::currentTime().toString("HH:mm");
    
    // Création du label pour le message
    QLabel *messageLabel = new QLabel(this);
    messageLabel->setWordWrap(true);
    messageLabel->setTextFormat(Qt::RichText);
    messageLabel->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::LinksAccessibleByMouse);
    messageLabel->setOpenExternalLinks(true);
    
    // Formatage du message avec HTML pour un meilleur contrôle du style
    QString formattedMessage = QString(
        "<html><body style='margin:0; padding:0;'>"
        "<div style='font-size: 13px; color: %1; margin-bottom: 2px;'>%2</div>"
        "<div style='font-size: 14px; color: %3;'>%4</div>"
        "<div style='font-size: 11px; color: %5; margin-top: 2px; text-align: right;'>%6</div>"
        "</body></html>"
    );

    // Style du message en fonction de l'expéditeur
    if (isUser) {
        // Message de l'utilisateur (à droite)
        messageLabel->setText(formattedMessage
            .arg("#4f46e5")  // Couleur expéditeur
            .arg("Vous")
            .arg("#1e293b")  // Couleur texte
            .arg(message.toHtmlEscaped().replace("\n", "<br>"))
            .arg("#94a3b8")  // Couleur horodatage
            .arg(timestamp)
        );
        
        messageLabel->setStyleSheet(
            "background: #f1f5f9;"
            "border-radius: 12px;"
            "padding: 10px 14px;"
            "margin-left: 40px;"
            "border: 1px solid #e2e8f0;"
        );
        
        messageLayout->addStretch();
        messageLayout->addWidget(messageLabel);
    } else {
        // Message de l'assistant (à gauche)
        // Création de l'avatar
        QLabel *avatarLabel = new QLabel(this);
        avatarLabel->setFixedSize(32, 32);
        avatarLabel->setStyleSheet(
            "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #4f46e5, stop:1 #818cf8);"
            "color: white;"
            "border-radius: 16px;"
            "font-weight: bold;"
            "font-size: 14px;"
            "qproperty-alignment: AlignCenter;"
        );
        avatarLabel->setText("A");
        
        // Ajout d'emojis en fonction du contenu du message
        QString messageWithEmoji = message;
        
        // Détection de mots-clés pour les emojis (par ordre de priorité)
        if (message.contains("bonjour", Qt::CaseInsensitive) || 
            message.contains("salut", Qt::CaseInsensitive) ||
            message.contains("coucou", Qt::CaseInsensitive) ||
            message.contains("hello", Qt::CaseInsensitive) ||
            message.contains("hi", Qt::CaseInsensitive) ||
            message.contains("yo", Qt::CaseInsensitive)) {
            // Salutations avec des combinaisons aléatoires
            QStringList greetings = {
                "👋✨ ", "👋😊 ", "👋🌟 ", "👋🚗💨 ", "👋📚 ",
                "👨‍🏫💡 ", "🚗💨✨ ", "📚😊 "
            };
            messageWithEmoji = greetings[QRandomGenerator::global()->bounded(greetings.size())] + messageWithEmoji;
        } else if (message.contains("merci", Qt::CaseInsensitive) ||
                  message.contains("remercie", Qt::CaseInsensitive)) {
            // Réponses reconnaissantes avec variations
            QStringList thanks = {
                "🙏✨ ", "😊🙏 ", "👍🙏 ", "💙🙏 ", "🙏🌟 ",
                "🙏💖 ", "🙏😊 ", "🙌✨ "
            };
            messageWithEmoji = thanks[QRandomGenerator::global()->bounded(thanks.size())] + messageWithEmoji;
        } else if (message.contains("code de la route", Qt::CaseInsensitive) ||
                  message.contains("permis de conduire", Qt::CaseInsensitive)) {
            // Emojis pour le code de la route avec variations
            QStringList codeRoute = {
                "📚🚦 ", "🚗📖✨ ", "🚦📝 ", "🚘📚 ", "👨‍🏫🚦 ",
                "🚦🔍 ", "📖💡 ", "🚗📚✨ "
            };
            messageWithEmoji = codeRoute[QRandomGenerator::global()->bounded(codeRoute.size())] + messageWithEmoji;
        } else if (message.contains("vitesse", Qt::CaseInsensitive) || 
                  message.contains("limitation", Qt::CaseInsensitive) ||
                  message.contains("km/h", Qt::CaseInsensitive)) {
            // Emojis pour la vitesse avec variations dynamiques
            QStringList speedEmojis = {
                "🚗💨 ", "🏎️💨 ", "🚙✨ ", "🚘💨 ", "🏁🚗 ",
                "🚦🏎️ ", "📏🚗 ", "⏱️🏁 "
            };
            messageWithEmoji = speedEmojis[QRandomGenerator::global()->bounded(speedEmojis.size())] + messageWithEmoji;
        } else if (message.contains("panneau", Qt::CaseInsensitive) ||
                  message.contains("signalisation", Qt::CaseInsensitive)) {
            // Emojis pour la signalisation avec variations
            QStringList signEmojis = {
                "🚸🛑 ", "📝🚦 ", "🛣️🚸 ", "🚸⚠️ ", "🚗👀 ",
                "🛑📋 ", "🚸📚 ", "⚠️🛣️ "
            };
            messageWithEmoji = signEmojis[QRandomGenerator::global()->bounded(signEmojis.size())] + messageWithEmoji;
        } else if (message.contains("intersection", Qt::CaseInsensitive) || 
                  message.contains("carrefour", Qt::CaseInsensitive) ||
                  message.contains("croisement", Qt::CaseInsensitive)) {
            // Emojis pour les intersections avec variations
            QStringList intersectionEmojis = {
                "🚥🚗 ", "🚦🚘 ", "🛣️➕ ", "🚗↔️🚙 ", "🚦⚠️ ",
                "🚥🔄 ", "🛑🚸 ", "🚗🚦🚙 "
            };
            messageWithEmoji = intersectionEmojis[QRandomGenerator::global()->bounded(intersectionEmojis.size())] + messageWithEmoji;
        } else if (message.contains("danger", Qt::CaseInsensitive) || 
                  message.contains("attention", Qt::CaseInsensitive) ||
                  message.contains("prudence", Qt::CaseInsensitive)) {
            // Emojis pour les dangers avec variations expressives
            QStringList dangerEmojis = {
                "⚠️🚨 ", "🚧⚠️ ", "🔴⛔ ", "🚫💥 ", "⚠️👀 ",
                "🔊⚠️ ", "🚸⛔ ", "🛑🚷 "
            };
            messageWithEmoji = dangerEmojis[QRandomGenerator::global()->bounded(dangerEmojis.size())] + messageWithEmoji;
        } else if (message.contains("stationnement", Qt::CaseInsensitive) || 
                  message.contains("se garer", Qt::CaseInsensitive) ||
                  message.contains("parking", Qt::CaseInsensitive)) {
            // Emojis pour le stationnement avec variations
            QStringList parkingEmojis = {
                "🅿️🚗 ", "🚙⏸️ ", "🅿️⏱️ ", "🚗🚫 ", "⛔🅿️ ",
                "🚘💤 ", "🅿️🔑 ", "🚗🔒 "
            };
            messageWithEmoji = parkingEmojis[QRandomGenerator::global()->bounded(parkingEmojis.size())] + messageWithEmoji;
        } else if ((message.contains("feu", Qt::CaseInsensitive) && 
                   message.contains("tricolore", Qt::CaseInsensitive)) ||
                   message.contains("feux de circulation", Qt::CaseInsensitive)) {
            // Emojis pour les feux tricolores avec variations
            QStringList trafficLightEmojis = {
                "🚦🔴🟢🟡 ", "🚥🚗 ", "🔴🟢🟡 ", "🚦⚠️ ", "🚗🚦 ",
                "🚥🚸 ", "🚦📛 ", "🛑🟢 "
            };
            messageWithEmoji = trafficLightEmojis[QRandomGenerator::global()->bounded(trafficLightEmojis.size())] + messageWithEmoji;
        } else if (message.contains("piéton", Qt::CaseInsensitive) ||
                  message.contains("piétonne", Qt::CaseInsensitive) ||
                  message.contains("passage piéton", Qt::CaseInsensitive)) {
            // Emojis pour les piétons avec variations
            QStringList pedestrianEmojis = {
                "🚶‍♂️👣 ", "🚸👥 ", "🚶‍♀️🚸 ", "👣⚠️ ", "🚶🚦 ",
                "🚸🚗 ", "👨‍👩‍👧‍👦🚸 ", "🚶‍♂️🛑 "
            };
            messageWithEmoji = pedestrianEmojis[QRandomGenerator::global()->bounded(pedestrianEmojis.size())] + messageWithEmoji;
        } else if (message.contains("vélo", Qt::CaseInsensitive) || 
                  message.contains("cycliste", Qt::CaseInsensitive) ||
                  message.contains("bicyclette", Qt::CaseInsensitive)) {
            // Emojis pour les vélos avec variations
            QStringList bikeEmojis = {
                "🚴‍♂️💨 ", "🚲✨ ", "🚴‍♀️🛣️ ", "🚲🚸 ", "🚴🚲 ",
                "🚲🔔 ", "🚴‍♂️⚠️ ", "🚲🚗 "
            };
            messageWithEmoji = bikeEmojis[QRandomGenerator::global()->bounded(bikeEmojis.size())] + messageWithEmoji;
        } else if (message.contains("examen", Qt::CaseInsensitive) || 
                  message.contains("test", Qt::CaseInsensitive) ||
                  message.contains("épreuve", Qt::CaseInsensitive)) {
            // Emojis pour les examens avec variations
            QStringList examEmojis = {
                "📝✏️ ", "📚🤔 ", "🧠💡 ", "📋✅ ", "📖🔍 ",
                "📝🤓 ", "📚🎯 ", "✏️💯 "
            };
            messageWithEmoji = examEmojis[QRandomGenerator::global()->bounded(examEmojis.size())] + messageWithEmoji;
        } else if (message.contains("priorité", Qt::CaseInsensitive) ||
                  message.contains("céder le passage", Qt::CaseInsensitive) ||
                  message.contains("stop", Qt::CaseInsensitive)) {
            messageWithEmoji = "🛑 " + messageWithEmoji;
        } else if (message.contains("autoroute", Qt::CaseInsensitive) ||
                  message.contains("péage", Qt::CaseInsensitive)) {
            messageWithEmoji = "🛣️ " + messageWithEmoji;
        } else if (message.contains("alcool", Qt::CaseInsensitive) ||
                  message.contains("taux", Qt::CaseInsensitive) && 
                  (message.contains("sang", Qt::CaseInsensitive) ||
                   message.contains("alcoolémie", Qt::CaseInsensitive))) {
            messageWithEmoji = "🍷 " + messageWithEmoji;
        } else if (message.contains("téléphone", Qt::CaseInsensitive) ||
                  message.contains("portable", Qt::CaseInsensitive) ||
                  message.contains("sms", Qt::CaseInsensitive)) {
            messageWithEmoji = "📱 " + messageWithEmoji;
        } else if (message.contains("ceinture", Qt::CaseInsensitive) ||
                  message.contains("sécurité", Qt::CaseInsensitive)) {
            messageWithEmoji = "🔐 " + messageWithEmoji;
        } else if (message.contains("accident", Qt::CaseInsensitive) ||
                  message.contains("collision", Qt::CaseInsensitive)) {
            messageWithEmoji = "💥 " + messageWithEmoji;
        } else if (message.contains("pluie", Qt::CaseInsensitive) ||
                  message.contains("pluvieux", Qt::CaseInsensitive) ||
                  message.contains("météo", Qt::CaseInsensitive)) {
            messageWithEmoji = "🌧️ " + messageWithEmoji;
        } else if (message.contains("brouillard", Qt::CaseInsensitive) ||
                  message.contains("brume", Qt::CaseInsensitive)) {
            messageWithEmoji = "🌫️ " + messageWithEmoji;
        } else if (message.contains("nuit", Qt::CaseInsensitive) ||
                  message.contains("nocturne", Qt::CaseInsensitive)) {
            messageWithEmoji = "🌙 " + messageWithEmoji;
        } else if (message.contains("enfant", Qt::CaseInsensitive) ||
                  message.contains("bébé", Qt::CaseInsensitive) ||
                  message.contains("bebe", Qt::CaseInsensitive)) {
            messageWithEmoji = "👶 " + messageWithEmoji;
        } else if (message.contains("pneu", Qt::CaseInsensitive) ||
                  message.contains("pneus", Qt::CaseInsensitive) ||
                  message.contains("gonflage", Qt::CaseInsensitive)) {
            messageWithEmoji = "🛞 " + messageWithEmoji;
        }
        
        messageLabel->setText(formattedMessage
            .arg("#4f46e5")  // Couleur expéditeur
            .arg("Assistant")
            .arg("#1e293b")  // Couleur texte
            .arg(messageWithEmoji.toHtmlEscaped().replace("\n", "<br>"))
            .arg("#94a3b8")  // Couleur horodatage
            .arg(timestamp)
        );
        
        messageLabel->setStyleSheet(
            "background: white;"
            "border-radius: 12px;"
            "padding: 10px 14px;"
            "margin-right: 10px;"
            "border: 1px solid #e2e8f0;"
            "box-shadow: 0 1px 2px rgba(0, 0, 0, 0.05);"
        );
        
        // Ajout de l'avatar et du message
        QVBoxLayout *avatarLayout = new QVBoxLayout();
        avatarLayout->addWidget(avatarLabel);
        avatarLayout->setAlignment(Qt::AlignTop);
        
        messageLayout->addLayout(avatarLayout);
        messageLayout->addWidget(messageLabel);
    }

    // Ajout du message à la zone de chat
    QVBoxLayout *messagesLayout = qobject_cast<QVBoxLayout*>(ui->scrollAreaWidgetContents->layout());
    if (messagesLayout) {
        messagesLayout->addWidget(messageWidget);
        
        // Ajout d'un espacement après le message
        QSpacerItem *spacer = new QSpacerItem(0, 4, QSizePolicy::Minimum, QSizePolicy::Fixed);
        messagesLayout->addItem(spacer);
    }

    // Défilement vers le bas pour voir le nouveau message
    QTimer::singleShot(50, this, [this]() {
        QScrollBar *scrollBar = ui->scrollArea->verticalScrollBar();
        scrollBar->setValue(scrollBar->maximum());
    });
}

void ChatWindow::configureApi()
{
    if (m_chatbot) {
        m_chatbot->configureApiKey(this);
    }
}

void ChatWindow::listModels()
{
    if (m_chatbot) {
        addMessage("Système", "Récupération de la liste des modèles disponibles...", false);
        m_chatbot->listAvailableModels();
    } else {
        addMessage("Erreur", "Chatbot non initialisé", false);
    }
}

void ChatWindow::testEmbedding()
{
    if (!m_chatbot) return;
    
    // Créer une boîte de dialogue pour entrer le texte à tester
    bool ok;
    QString text = QInputDialog::getMultiLineText(this, "Tester l'embedding", 
                                                 "Entrez le texte à tester :", 
                                                 "", &ok);
    
    if (ok && !text.isEmpty()) {
        // Appeler la fonction getEmbedding
        m_chatbot->getEmbedding(text);
        QMessageBox::information(this, "Test d'embedding", 
                               "La requête d'embedding a été envoyée avec succès.");
    }
}

void ChatWindow::saveChatHistory()
{
    // Créer un nom de fichier avec la date et l'heure actuelles
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH.mm.ss");
    
    // Créer une boîte de dialogue personnalisée
    QFileDialog dialog(this, "Enregistrer l'historique");
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setDirectory(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));
    dialog.selectFile("Conversation " + timestamp + ".md");
    dialog.setDefaultSuffix("md");
    dialog.setNameFilter("Fichiers Markdown (*.md);;Fichiers texte (*.txt);;Tous les fichiers (*.*)");
    
    // Style moderne pour la boîte de dialogue
    dialog.setStyleSheet(
        "QFileDialog { background-color: #ffffff; }"
        "QLabel { color: #1e293b; font-size: 13px; }"
        "QLineEdit { border: 2px solid #e2e8f0; border-radius: 6px; padding: 6px; }"
        "QLineEdit:focus { border-color: #818cf8; }"
        "QPushButton { "
        "    background: #4f46e5; "
        "    color: white; "
        "    border: none; "
        "    border-radius: 6px; "
        "    padding: 6px 16px; "
        "    font-weight: 500; "
        "    min-width: 80px; "
        "}"
        "QPushButton:hover { background: #4338ca; }"
        "QPushButton:pressed { background: #3730a3; }"
        "QPushButton:disabled { background: #cbd5e1; }"
    );
    
    // Afficher la boîte de dialogue et récupérer le nom de fichier
    if (!dialog.exec() || dialog.selectedFiles().isEmpty()) {
        return; // Annulation par l'utilisateur
    }
    
    QString fileName = dialog.selectedFiles().first();
    
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // Message d'erreur moderne
        QMessageBox msgBox;
        msgBox.setWindowTitle("Erreur");
        msgBox.setText("Impossible d'enregistrer le fichier");
        msgBox.setInformativeText("Vérifiez que vous avez les droits d'écriture dans le dossier sélectionné et que le fichier n'est pas ouvert par un autre programme.");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStyleSheet(
            "QMessageBox { background-color: white; }"
            "QLabel { color: #1e293b; font-size: 13px; }"
            "QPushButton { "
            "    background: #4f46e5; "
            "    color: white; "
            "    border: none; "
            "    border-radius: 6px; "
            "    padding: 6px 16px; "
            "    min-width: 80px; "
            "}"
            "QPushButton:hover { background: #4338ca; }"
        );
        msgBox.exec();
        return;
    }
    
    QTextStream out(&file);
    
    // En-tête du fichier Markdown
    out << "# Historique de conversation\n\n";
    out << "*Sauvegardé le " << QDateTime::currentDateTime().toString("dddd d MMMM yyyy 'à' HH:mm") << "*\n\n";
    out << "---\n\n";
    
    // Parcourir tous les widgets dans le layout des messages
    QLayout *mainLayout = ui->scrollAreaWidgetContents->layout();
    if (!mainLayout || mainLayout->count() == 0) {
        // Message d'information moderne
        QMessageBox msgBox;
        msgBox.setWindowTitle("Information");
        msgBox.setText("Aucun message à sauvegarder");
        msgBox.setInformativeText("La conversation est vide.");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStyleSheet(
            "QMessageBox { background-color: white; }"
            "QLabel { color: #1e293b; font-size: 13px; }"
            "QPushButton { "
            "    background: #4f46e5; "
            "    color: white; "
            "    border: none; "
            "    border-radius: 6px; "
            "    padding: 6px 16px; "
            "    min-width: 80px; "
            "}"
            "QPushButton:hover { background: #4338ca; }"
        );
        msgBox.exec();
        file.remove(); // Supprimer le fichier vide
        return;
    }
    
    int messageCount = 0;
    
    for (int i = 0; i < mainLayout->count(); ++i) {
        QWidget *widget = mainLayout->itemAt(i)->widget();
        if (!widget) continue;
        
        // Trouver le QLabel qui contient le message
        QList<QLabel*> labels = widget->findChildren<QLabel*>();
        if (labels.isEmpty()) continue;
        
        // Le premier label contient l'expéditeur et le message
        QLabel *messageLabel = labels.first();
        QString htmlContent = messageLabel->text();
        
        // Extraire le contenu du message du HTML
        QRegularExpression re("<div style='font-size: 14px; color: [^']+;'>(.*?)</div>");
        QRegularExpression timeRe("<div style='[^']+'>([^<]+)</div>$");
        
        QRegularExpressionMatch match = re.match(htmlContent);
        QRegularExpressionMatch timeMatch = timeRe.match(htmlContent);
        
        if (match.hasMatch()) {
            QString message = match.captured(1);
            // Nettoyer le message HTML
            message = message.replace("<br>", "\n")
                           .replace("&lt;", "<")
                           .replace("&gt;", ">")
                           .replace("&amp;", "&");
            
            // Déterminer l'expéditeur
            bool isUser = htmlContent.contains("Vous");
            QString sender = isUser ? "**Vous**" : "**Assistant**";
            
            // Formater l'horodatage
            QString timestamp = "";
            if (timeMatch.hasMatch()) {
                timestamp = " *(" + timeMatch.captured(1).trimmed() + ")*";
            }
            
            // Écrire dans le fichier avec formatage Markdown
            out << "---\n\n";
            out << "### " << sender << timestamp << "\n\n";
            out << message << "\n\n";
            
            messageCount++;
        }
    }
    
    file.close();
    
    // Message de succès moderne
    QMessageBox msgBox;
    msgBox.setWindowTitle("Sauvegarde réussie");
    msgBox.setText(QString("La conversation a été sauvegardée avec succès.\n%1 messages enregistrés.").arg(messageCount));
    msgBox.setIconPixmap(QIcon(":/icons/check-circle.svg").pixmap(32, 32));
    msgBox.setStyleSheet(
        "QMessageBox { background-color: white; }"
        "QLabel { color: #1e293b; font-size: 13px; }"
        "QPushButton { "
        "    background: #4f46e5; "
        "    color: white; "
        "    border: none; "
        "    border-radius: 6px; "
        "    padding: 6px 16px; "
        "    min-width: 80px; "
        "}"
        "QPushButton:hover { background: #4338ca; }"
    );
    
    // Ajouter un bouton pour ouvrir le dossier de destination
    QPushButton *openFolderButton = msgBox.addButton("Ouvrir le dossier", QMessageBox::ActionRole);
    msgBox.addButton(QMessageBox::Ok);
    
    // Afficher la boîte de dialogue
    msgBox.exec();
    
    // Gérer le clic sur le bouton "Ouvrir le dossier"
    if (msgBox.clickedButton() == openFolderButton) {
        QFileInfo fileInfo(fileName);
        QDesktopServices::openUrl(QUrl::fromLocalFile(fileInfo.absolutePath()));
    }
}

void ChatWindow::showHistory()
{
    // Création de la boîte de dialogue
    QDialog *historyDialog = new QDialog(this);
    historyDialog->setWindowTitle("Historique des conversations");
    historyDialog->setMinimumSize(500, 400);
    
    // Création du layout principal
    QVBoxLayout *mainLayout = new QVBoxLayout(historyDialog);
    
    // Zone de texte pour afficher l'historique
    QTextEdit *historyText = new QTextEdit(historyDialog);
    historyText->setReadOnly(true);
    historyText->setStyleSheet("QTextEdit { background-color: #f8f9fa; border: 1px solid #dee2e6; border-radius: 5px; padding: 10px; }");
    
    // Récupération de l'historique des messages
    QString history;
    QVBoxLayout *messagesLayout = qobject_cast<QVBoxLayout*>(ui->scrollAreaWidgetContents->layout());
    
    if (messagesLayout) {
        for (int i = 0; i < messagesLayout->count(); ++i) {
            QLayoutItem *item = messagesLayout->itemAt(i);
            if (item && item->widget()) {
                QWidget *widget = item->widget();
                if (QHBoxLayout *messageLayout = qobject_cast<QHBoxLayout*>(widget->layout())) {
                    // Le premier widget est soit un layout d'avatar, soit un stretch
                    QWidget *messageWidget = nullptr;
                    bool isUser = false;
                    
                    // Vérifier si c'est un message utilisateur (à droite) ou assistant (à gauche)
                    if (messageLayout->count() > 1) {
                        // Si le premier élément est un layout, c'est un message d'assistant
                        if (qobject_cast<QVBoxLayout*>(messageLayout->itemAt(0)->layout())) {
                            // Message de l'assistant
                            messageWidget = messageLayout->itemAt(1)->widget();
                            isUser = false;
                        } else {
                            // Message de l'utilisateur
                            messageWidget = messageLayout->itemAt(1)->widget();
                            isUser = true;
                        }
                    }
                    
                    if (messageWidget) {
                        if (QLabel *messageLabel = qobject_cast<QLabel*>(messageWidget)) {
                            // Extraire le texte brut du HTML
                            QString message = messageLabel->text();
                            QTextDocument doc;
                            doc.setHtml(message);
                            QString plainText = doc.toPlainText().trimmed();
                            
                            // Formater l'historique
                            history += QString("[%1] %2\n%3\n\n")
                                .arg(QTime::currentTime().toString("hh:mm"))
                                .arg(isUser ? "Vous" : "Assistant")
                                .arg(plainText);
                        }
                    }
                }
            }
        }
    }
    
    if (history.isEmpty()) {
        history = "💬 Historique de conversation vide\n\n"
                "Commencez à discuter avec l'assistant pour voir l'historique s'afficher ici.\n\n"
                "• Envoyez un message pour commencer\n"
                "• L'historique se met à jour automatiquement";
        
        // Style pour le message d'historique vide
        historyText->setStyleSheet(
            "QTextEdit { "
            "    background-color: #f8f9fa; "
            "    border: 1px solid #e9ecef; "
            "    border-radius: 8px; "
            "    padding: 20px; "
            "    color: #6c757d; "
            "    font-size: 12px; "
            "    line-height: 1.5; "
            "    text-align: center;"
            "}");
    } else {
        // Style normal quand il y a de l'historique
        historyText->setStyleSheet(
            "QTextEdit { "
            "    background-color: #f8f9fa; "
            "    border: 1px solid #dee2e6; "
            "    border-radius: 5px; "
            "    padding: 10px;"
            "}");
    }
    
    historyText->setText(history);
    
    // Bouton de fermeture
    QPushButton *closeButton = new QPushButton("Fermer", historyDialog);
    closeButton->setStyleSheet(
        "QPushButton { "
        "    background: #6c757d; "
        "    color: white; "
        "    border: none; "
        "    border-radius: 4px; "
        "    padding: 8px 16px; "
        "    font-size: 13px; "
        "    min-width: 100px; "
        "}"
        "QPushButton:hover { "
        "    background: #5a6268; "
        "}"
        "QPushButton:pressed { "
        "    background: #545b62; "
        "}");
    
    connect(closeButton, &QPushButton::clicked, historyDialog, &QDialog::accept);
    
    // Ajout des widgets au layout
    mainLayout->addWidget(historyText);
    mainLayout->addWidget(closeButton, 0, Qt::AlignRight);
    
    // Affichage de la boîte de dialogue
    historyDialog->exec();
    
    // Nettoyage
    historyDialog->deleteLater();
}

void ChatWindow::clearChatHistory()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", 
                                "Êtes-vous sûr de vouloir effacer tout l'historique de la conversation ?",
                                QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        // Supprimer tous les widgets du layout des messages
        QLayoutItem *item;
        while ((item = ui->scrollAreaWidgetContents->layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        
        // Ajouter un message indiquant que l'historique a été effacé
        addMessage("Système", "L'historique de la conversation a été effacé.", false);
    }
}

void ChatWindow::setupSuggestions()
{
    // Créer un widget pour contenir les suggestions
    QWidget *suggestionsWidget = new QWidget();
    QVBoxLayout *suggestionsLayout = new QVBoxLayout(suggestionsWidget);
    suggestionsLayout->setContentsMargins(10, 10, 10, 10);
    suggestionsLayout->setSpacing(8);
    
    // Ajouter un titre
    QLabel *titleLabel = new QLabel("Sujets de discussion suggérés :");
    titleLabel->setStyleSheet("font-weight: bold; color: #4f46e5; font-size: 14px;");
    suggestionsLayout->addWidget(titleLabel);
    
    // Liste des suggestions de questions
    QStringList questions = {
        "Quelles sont les règles de priorité aux intersections ?",
        "Comment fonctionnent les feux tricolores ?",
        "Quelles sont les limitations de vitesse en ville ?",
        "Comment bien préparer l'examen du code de la route ?",
        "Quels sont les documents obligatoires à avoir dans son véhicule en Tunisie ?",
        "Comment se comporter face à un passage à niveau ?",
        "Quelles sont les règles de stationnement en ville ?",
        "Comment fonctionne le système de points du permis de conduire ?",
        "Quelles sont les distances de sécurité à respecter ?",
        "Comment réagir face à un accident de la route ?"
    };
    
    // Créer des boutons pour chaque suggestion
    for (const QString &question : questions) {
        QPushButton *button = new QPushButton(question);
        button->setStyleSheet(
            "QPushButton { "
            "    text-align: left; "
            "    padding: 10px; "
            "    border: 1px solid #e2e8f0; "
            "    border-radius: 8px; "
            "    background-color: white; "
            "    color: #1e293b; "
            "    font-size: 13px; "
            "    border-left: 4px solid #4f46e5; "
            "} "
            "QPushButton:hover { "
            "    background-color: #f8fafc; "
            "    border-color: #cbd5e1; "
            "}"
        );
        
        // Connecter le bouton pour insérer la question dans le champ de saisie
        connect(button, &QPushButton::clicked, [this, question]() {
            ui->messageInput->setText(question);
            ui->messageInput->setFocus();
        });
        
        suggestionsLayout->addWidget(button);
    }
    
    // Ajouter un espacement
    suggestionsLayout->addStretch();
    
    // Créer une zone de défilement pour les suggestions
    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(suggestionsWidget);
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    
    // Ajouter la zone de défilement à la zone de messages
    QVBoxLayout *mainLayout = qobject_cast<QVBoxLayout*>(ui->scrollAreaWidgetContents->layout());
    if (mainLayout) {
        mainLayout->insertWidget(0, scrollArea);
    }
}

