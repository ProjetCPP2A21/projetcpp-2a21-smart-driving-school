#ifndef CHATBOT_H
#define CHATBOT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include "apiconfig.h"

class ChatBot : public QObject
{
    Q_OBJECT
public:
    explicit ChatBot(QObject *parent = nullptr);
    void sendMessage(const QString &message);

signals:
    void responseReceived(const QString &response);
    void errorOccurred(const QString &error);

private slots:
    void onFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *m_manager;
    const QString API_KEY = ApiConfig::API_KEY;
    const QString API_URL = ApiConfig::BASE_URL;
};

#endif // CHATBOT_H
