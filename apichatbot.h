#ifndef APICHATBOT_H
#define APICHATBOT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSettings>
#include <QMap>
#include <QStringList>

class ApiChatBot : public QObject
{
    Q_OBJECT
public:
    explicit ApiChatBot(QObject *parent = nullptr);
    void getCodeRouteResponse(const QString &question);
    void getEmbedding(const QString &text);
    void generateText(const QString &prompt);
    void sendMessage(const QString &message) { getCodeRouteResponse(message); }
    QString loadApiKey() const;
    void saveApiKey(const QString &key);
    bool configureApiKey(QWidget *parent = nullptr);
    void listAvailableModels();
    QStringList getAvailableModels() const;
    QString getCurrentModel() const;
    bool setCurrentModel(const QString &modelId);

signals:
    void responseReceived(const QString &response);
    void errorOccurred(const QString &error);
    void modelChanged(const QString &modelId);

private slots:
    void onNetworkReply(QNetworkReply *reply);

private:
    void initializeModels();
    void listAvailableModelsFromApi();
    QNetworkAccessManager *m_manager;
    QString m_apiKey;  // La clé API Google AI
    QString m_currentModelId;  // Modèle actuellement sélectionné
    QMap<QString, QString> m_models;  // Dictionnaire des modèles disponibles
};

#endif // APICHATBOT_H
