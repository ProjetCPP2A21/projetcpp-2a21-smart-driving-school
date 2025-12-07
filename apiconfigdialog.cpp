#include "apiconfigdialog.h"
#include <QFormLayout>
#include <QMessageBox>
#include <QApplication>
#include <QClipboard>

ApiConfigDialog::ApiConfigDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Configuration de l'API");
    setMinimumWidth(400);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Informations sur l'API
    QLabel *infoLabel = new QLabel(
        "Pour utiliser l'API, vous avez besoin d'une clé API valide.\n"
        "Veuillez entrer votre clé API ci-dessous :"
    );
    infoLabel->setWordWrap(true);
    mainLayout->addWidget(infoLabel);

    // Champ pour la clé API
    QFormLayout *formLayout = new QFormLayout();
    
    apiKeyEdit = new QLineEdit();
    apiKeyEdit->setEchoMode(QLineEdit::Password);
    apiKeyEdit->setPlaceholderText("Entrez votre clé API ici...");
    
    formLayout->addRow("Clé API :", apiKeyEdit);
    mainLayout->addLayout(formLayout);

    // Bouton pour afficher/masquer la clé
    QPushButton *toggleButton = new QPushButton("Afficher/Masquer la clé", this);
    connect(toggleButton, &QPushButton::clicked, [this]() {
        apiKeyEdit->setEchoMode(apiKeyEdit->echoMode() == QLineEdit::Password ? 
                              QLineEdit::Normal : QLineEdit::Password);
    });
    mainLayout->addWidget(toggleButton);

    // Boutons de dialogue
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    
    QPushButton *saveButton = new QPushButton("Enregistrer", this);
    QPushButton *cancelButton = new QPushButton("Annuler", this);
    
    connect(saveButton, &QPushButton::clicked, this, &ApiConfigDialog::saveConfig);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
    
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(cancelButton);
    
    mainLayout->addLayout(buttonLayout);
}

QString ApiConfigDialog::getApiKey() const
{
    return apiKeyEdit->text().trimmed();
}

void ApiConfigDialog::setApiKey(const QString &apiKey)
{
    apiKeyEdit->setText(apiKey);
}

void ApiConfigDialog::saveConfig()
{
    if (apiKeyEdit->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez entrer une clé API valide.");
        return;
    }
    
    // Vérification basique de la clé API (format sk- suivi d'au moins 20 caractères)
    if (!apiKeyEdit->text().startsWith("sk-") || apiKeyEdit->text().length() < 24) {
        QMessageBox::warning(this, "Clé API invalide", 
                           "La clé API ne semble pas être au bon format.\n"
                           "Une clé API commence généralement par 'sk-'.");
        return;
    }
    
    accept();
}
