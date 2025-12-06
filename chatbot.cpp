#include "chatbot.h"
#include <QNetworkRequest>
#include <QJsonArray>

ChatBot::ChatBot(QObject *parent) : QObject(parent)
{
    m_manager = new QNetworkAccessManager(this);
    connect(m_manager, &QNetworkAccessManager::finished, this, &ChatBot::onFinished);
}

void ChatBot::sendMessage(const QString &message)
{
    QNetworkRequest request;
    request.setUrl(QUrl(API_URL));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", ApiConfig::getAuthHeader());

    QJsonObject messageObj;
    messageObj["role"] = "user";
    messageObj["content"] = "Tu es un assistant qui aide à comprendre le code de la route en Tunisie. " + message;

    QJsonArray messages;
    messages.append(messageObj);

    QJsonObject json;
    json["model"] = "gpt-3.5-turbo";
    json["messages"] = messages;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    m_manager->post(request, data);
}

void ChatBot::onFinished(QNetworkReply *reply)
{
    QByteArray responseData = reply->readAll();
    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    
    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
        
        if (jsonResponse.isNull()) {
            emit errorOccurred("Erreur: Réponse JSON invalide");
            reply->deleteLater();
            return;
        }
        
        QJsonObject jsonObj = jsonResponse.object();
        
        if (jsonObj.contains("error")) {
            QString errorMsg = jsonObj["error"].toObject()["message"].toString();
            emit errorOccurred("Erreur de l'API: " + errorMsg);
        } 
        else if (jsonObj.contains("choices")) {
            QJsonArray choices = jsonObj["choices"].toArray();
            
            if (!choices.isEmpty()) {
                QJsonObject choice = choices[0].toObject();
                QJsonObject message = choice["message"].toObject();
                emit responseReceived(message["content"].toString());
            } else {
                emit errorOccurred("Aucune réponse valide reçue de l'API");
            }
        } else {
            emit errorOccurred("Format de réponse inattendu de l'API");
        }
    } else {
        QString errorMessage = QString("Erreur réseau (%1): %2\nRéponse: %3")
            .arg(statusCode.toString())
            .arg(reply->errorString())
            .arg(QString(responseData));
        
        emit errorOccurred(errorMessage);
    }
    
    reply->deleteLater();
}
