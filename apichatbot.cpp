#include "apichatbot.h"
#include <QNetworkRequest>
#include <QEventLoop>
#include <QTimer>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>
#include <QUrlQuery>
#include <QSettings>
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>
#include <QList>
#include <QTimer>

ApiChatBot::ApiChatBot(QObject *parent)
    : QObject(parent)
    , m_manager(new QNetworkAccessManager(this))
    , m_currentModelId("gemini-2.0-flash-001")
{
    connect(m_manager, &QNetworkAccessManager::finished,
            this, &ApiChatBot::onNetworkReply);
    
    // Initialiser la liste des modèles
    initializeModels();
    
    // Charger la clé API au démarrage
    m_apiKey = loadApiKey();
    if (m_apiKey.isEmpty()) {
        qDebug() << "Aucune clé API n'est configurée";
    } else {
        qDebug() << "Clé API chargée avec succès";
    }
}

void ApiChatBot::getCodeRouteResponse(const QString &question)
{
    qDebug() << "Tentative de connexion à l'API Google AI...";
    
    if (m_apiKey.isEmpty()) {
        QString error = "Clé API non configurée. Veuillez configurer votre clé API Google AI via le bouton d'engrenage (⚙️).";
        qDebug() << error;
        emit errorOccurred(error);
        return;
    }

    // Vérifier que le modèle est valide
    if (!m_models.contains(m_currentModelId)) {
        emit errorOccurred("Modèle invalide sélectionné");
        return;
    }

    // Construire l'URL avec la clé API pour Gemini
    QUrl url(QString("https://generativelanguage.googleapis.com/v1beta/models/%1:generateContent?key=%2")
                .arg(m_currentModelId)
                .arg(m_apiKey));
    qDebug() << "URL de l'API Gemini:" << url.toString().left(100) + "..."; // N'affiche pas la clé complète dans les logs
    
    QNetworkRequest request;
    request.setUrl(url);
    
    // Configuration des en-têtes pour Google AI
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    
    // Préparation du prompt système et du message utilisateur
    QString systemPrompt = "Tu es un assistant spécialisé dans le code de la route tunisien. "
                         "Tu fournis des réponses claires et précises sur les règles de conduite, "
                         "les panneaux de signalisation et la législation routière en Tunisie. "
                         "Réponds en français et sois concis. Si la question n'est pas liée au code de la route, "
                         "explique poliment que tu es spécialisé uniquement dans le code de la route tunisien.";
    
    // Construction du corps de la requête pour Gemini
    QJsonObject textPart;
    textPart["text"] = systemPrompt + "\n\n" + question;
    
    QJsonObject part;
    part["text"] = systemPrompt + "\n\n" + question;
    
    QJsonArray parts;
    parts.append(part);
    
    QJsonObject content;
    content["role"] = "user";
    content["parts"] = parts;
    
    QJsonArray contents;
    contents.append(content);
    
    // Configuration de la génération
    QJsonObject generationConfig;
    generationConfig["temperature"] = 0.7;
    generationConfig["topP"] = 0.8;
    generationConfig["topK"] = 40;
    generationConfig["maxOutputTokens"] = 2048;
    
    // Paramètres de sécurité
    QJsonArray safetySettings;
    QJsonObject safetySetting;
    safetySetting["category"] = "HARM_CATEGORY_DANGEROUS_CONTENT";
    safetySetting["threshold"] = "BLOCK_NONE";
    safetySettings.append(safetySetting);
    
    // Construire le JSON final
    QJsonObject json;
    json["contents"] = contents;
    json["generationConfig"] = generationConfig;
    json["safetySettings"] = safetySettings;
    
    QJsonDocument doc(json);
    QByteArray data = doc.toJson();
    
    // Afficher les détails de la requête pour le débogage
    qDebug() << "=== Détails de la requête API ===";
    qDebug() << "URL:" << url.toString();
    qDebug() << "Headers:";
    qDebug() << "- Content-Type:" << request.header(QNetworkRequest::ContentTypeHeader);
    qDebug() << "- Authorization: Bearer" << (m_apiKey.left(5) + "..." + m_apiKey.right(5));
    qDebug() << "- User-Agent:" << request.rawHeader("User-Agent");
    qDebug() << "Body:" << data;
    qDebug() << "=================================\n";
    
    // Envoyer la requête
    qDebug() << "Envoi de la requête à l'API...";
    QNetworkReply *reply = m_manager->post(request, data);
    
    // Connecter les signaux de débogage
    connect(reply, &QNetworkReply::sslErrors, this, [this](const QList<QSslError> &errors) {
        qDebug() << "Erreurs SSL détectées:";
        for (const auto &error : errors) {
            qDebug() << " -" << error.errorString();
        }
    });
    
    qDebug() << "Requête envoyée, attente de la réponse...";
}

void ApiChatBot::onNetworkReply(QNetworkReply *reply)
{
    qDebug() << "\n=== Réponse de l'API ===";
    qDebug() << "URL:" << reply->url().toString();
    int httpStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << "Code HTTP:" << httpStatus;
    
    // Afficher les en-têtes de la réponse
    qDebug() << "En-têtes de la réponse:";
    QList<QByteArray> headers = reply->rawHeaderList();
    for (const QByteArray &header : headers) {
        qDebug() << "- " << header << ":" << reply->rawHeader(header);
    }
    
    reply->deleteLater();
    
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Erreur réseau:" << reply->errorString();
        qDebug() << "Détails de l'erreur:" << reply->error();
        QString errorMsg = QString("Erreur réseau (%1): %2")
                         .arg(reply->error())
                         .arg(reply->errorString());
        
        // Ajouter plus de détails sur l'erreur si disponibles
        if (reply->hasRawHeader("Content-Type") && 
            reply->rawHeader("Content-Type").contains("application/json")) {
            QJsonDocument jsonResponse = QJsonDocument::fromJson(reply->readAll());
            if (!jsonResponse.isNull() && jsonResponse.isObject()) {
                QJsonObject jsonObj = jsonResponse.object();
                if (jsonObj.contains("error") && jsonObj["error"].isObject()) {
                    QJsonObject errorObj = jsonObj["error"].toObject();
                    if (errorObj.contains("message")) {
                        errorMsg += QString("\nMessage: %1").arg(errorObj["message"].toString());
                    }
                    if (errorObj.contains("type")) {
                        errorMsg += QString("\nType: %1").arg(errorObj["type"].toString());
                    }
                }
            }
        }
        
        emit errorOccurred(errorMsg);
        return;
    }
    
    QByteArray responseData = reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
    
    if (jsonResponse.isNull()) {
        emit errorOccurred("Réponse d'API invalide");
        return;
    }
    
    QJsonObject jsonObj = jsonResponse.object();
    
    // Vérifier les erreurs de l'API
    if (jsonObj.contains("error")) {
        QString errorMsg = jsonObj["error"].toObject()["message"].toString();
        emit errorOccurred(QString("Erreur de l'API: %1").arg(errorMsg));
        return;
    }
    
    // Extraire la réponse de l'API Gemini
    if (jsonObj.contains("candidates") && jsonObj["candidates"].isArray()) {
        QJsonArray candidates = jsonObj["candidates"].toArray();
        if (!candidates.isEmpty()) {
            QJsonObject candidate = candidates[0].toObject();
            if (candidate.contains("content") && candidate["content"].isObject()) {
                QJsonObject content = candidate["content"].toObject();
                if (content.contains("parts") && content["parts"].isArray()) {
                    QJsonArray parts = content["parts"].toArray();
                    QString responseText;
                    
                    // Afficher la structure complète de la réponse pour le débogage
                    qDebug() << "Structure de la réponse reçue:";
                    qDebug() << jsonResponse.toJson(QJsonDocument::Indented);
                    
                    // Parcourir toutes les parties de la réponse
                    for (const auto& part : parts) {
                        if (part.isObject() && part.toObject().contains("text")) {
                            responseText += part.toObject()["text"].toString();
                        }
                    }
                    
                    if (!responseText.isEmpty()) {
                        qDebug() << "Réponse extraite avec succès";
                        emit responseReceived(responseText);
                        return;
                    } else {
                        emit errorOccurred("La réponse de l'API est vide ou dans un format inattendu");
                    }
                } else {
                    qDebug() << "Pas de 'parts' dans la réponse";
                }
            } else {
                qDebug() << "Pas de 'content' dans le candidat";
            }
        } else {
            qDebug() << "Aucun candidat dans la réponse";
        }
    } else {
        qDebug() << "Format de réponse inattendu ou erreur d'API";
    }
    
    // Vérifier les erreurs spécifiques à Google AI
    if (jsonObj.contains("error")) {
        QJsonObject errorObj = jsonObj["error"].toObject();
        QString errorMessage = errorObj["message"].toString();
        QString errorStatus = errorObj["status"].toString();
        
        emit errorOccurred(QString("Erreur Google AI (%1): %2").arg(errorStatus).arg(errorMessage));
        return;
    }
    
    emit errorOccurred("Format de réponse inattendu de l'API");
}

QString ApiChatBot::loadApiKey() const
{
    // Retourne directement la nouvelle clé API
    return "AIzaSyBtC7aSHBJofCbYpDyZMg2i-PT5CpnhW5k";
}

void ApiChatBot::saveApiKey(const QString &key)
{
    QSettings settings("MyCompany", "ApprenantsApp");
    // Utilisation de la clé fournie en paramètre
    settings.setValue("google_ai_api_key", key);
    m_apiKey = key;
    qDebug() << "Clé API Google AI mise à jour avec succès";
}

void ApiChatBot::initializeModels()
{
    // Modèles disponibles avec leur description
    m_models.clear();
    m_models["gemini-2.0-flash-001"] = "Gemini 2.0 Flash (Rapide, gratuit)";
    m_models["gemini-2.0-flash-lite-001"] = "Gemini 2.0 Flash Lite (Très rapide, léger)";
    m_models["gemini-pro-latest"] = "Gemini Pro (Plus puissant, gratuit)";
    m_models["gemini-2.5-flash"] = "Gemini 2.5 Flash (Nouveauté, rapide)";
    m_models["gemini-2.5-pro"] = "Gemini 2.5 Pro (Nouveauté, puissant)";
}

QStringList ApiChatBot::getAvailableModels() const
{
    QStringList models;
    for (auto it = m_models.constBegin(); it != m_models.constEnd(); ++it) {
        models << QString("%1 - %2").arg(it.key()).arg(it.value());
    }
    return models;
}

QString ApiChatBot::getCurrentModel() const
{
    return m_currentModelId;
}

bool ApiChatBot::setCurrentModel(const QString &modelId)
{
    if (m_models.contains(modelId)) {
        if (m_currentModelId != modelId) {
            m_currentModelId = modelId;
            emit modelChanged(modelId);
            qDebug() << "Modèle changé pour:" << modelId;
        }
        return true;
    }
    qWarning() << "Tentative de sélection d'un modèle invalide:" << modelId;
    return false;
}

void ApiChatBot::listAvailableModels()
{
    qDebug() << "=== Modèles disponibles ===";
    for (auto it = m_models.constBegin(); it != m_models.constEnd(); ++it) {
        qDebug() << it.key() << ":" << it.value() 
                << (it.key() == m_currentModelId ? "[Sélectionné]" : "");
    }
}

void ApiChatBot::listAvailableModelsFromApi()
{
    if (m_apiKey.isEmpty()) {
        QString errorMsg = "Aucune clé API configurée. Veuillez configurer votre clé API d'abord.";
        qDebug() << errorMsg;
        emit errorOccurred(errorMsg);
        return;
    }

    // URL de base de l'API
    QUrl url("https://generativelanguage.googleapis.com/v1beta/models");
    
    // Ajout de la clé API en tant que paramètre de requête
    QUrlQuery query;
    query.addQueryItem("key", m_apiKey);
    url.setQuery(query);

    // Configuration de la requête
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    
    // Pour le débogage
    qDebug() << "=== Détails de la requête ===";
    qDebug() << "URL:" << url.toString();
    qDebug() << "Méthode: GET";
    qDebug() << "En-têtes:" << request.rawHeaderList();
    
    // Création d'un gestionnaire de réseau temporaire pour le débogage
    QNetworkAccessManager tempManager;
    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);
    
    // Connexion des signaux
    QObject::connect(&tempManager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    
    // Configuration de la requête avec timeout
    request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, QNetworkRequest::NoLessSafeRedirectPolicy);
    request.setRawHeader("User-Agent", "ApprenantsApp/1.0");
    request.setRawHeader("Accept", "application/json");
    
    qDebug() << "\n=== Envoi de la requête ===";
    qDebug() << "URL complète:" << request.url().toString();
    qDebug() << "En-têtes de la requête:";
    for (const auto &header : request.rawHeaderList()) {
        qDebug() << "  " << header << ":" << request.rawHeader(header);
    }
    
    // Envoi de la requête avec timeout
    QNetworkReply *reply = tempManager.get(request);
    qDebug() << "Requête envoyée, attente de la réponse...";
    timer.start(30000); // Timeout de 30 secondes
    
    // Attente de la réponse ou du timeout
    loop.exec();
    
    // Vérification du timeout
    if (!timer.isActive()) {
        // Timeout
        QString errorMsg = "La requête a expiré (timeout de 30 secondes). Vérifiez votre connexion Internet.";
        qDebug() << errorMsg;
        reply->abort();
        reply->deleteLater();
        emit errorOccurred(errorMsg);
        return;
    }
    timer.stop();
    
    // Vérification de la réponse
    if (reply->error() == QNetworkReply::OperationCanceledError) {
        QString errorMsg = "La requête a été annulée. Vérifiez votre connexion Internet.";
        qDebug() << errorMsg;
        reply->deleteLater();
        emit errorOccurred(errorMsg);
        return;
    }
    
    // Lecture de la réponse
    QByteArray response = reply->readAll();
    int httpStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QNetworkReply::NetworkError error = reply->error();
    
    // Affichage des informations de débogage
    qDebug() << "\n=== Réponse brute de l'API ===";
    qDebug() << "Code HTTP:" << httpStatus;
    qDebug() << "Erreur réseau:" << error << "-" << reply->errorString();
    qDebug() << "En-têtes de réponse:";
    for (const auto &header : reply->rawHeaderPairs()) {
        qDebug() << header.first << ":" << header.second;
    }
    qDebug() << "Taille de la réponse:" << response.size() << "octets";
    
    // Vérification de la réponse vide
    if (response.isEmpty()) {
        QString errorMsg = "La réponse de l'API est vide. Vérifiez votre connexion Internet.";
        qDebug() << errorMsg;
        emit errorOccurred(errorMsg);
        reply->deleteLater();
        return;
    }
    
    // Affichage des premiers 500 caractères de la réponse pour le débogage
    qDebug() << "Début de la réponse:" << response.left(500);
    if (response.size() > 500) {
        qDebug() << "... (réponse tronquée, taille totale:" << response.size() << "octets)";
    }
    
    // Traitement de la réponse
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(response, &parseError);
    
    if (parseError.error != QJsonParseError::NoError) {
        QString errorMsg = QString("Erreur d'analyse JSON: %1\nPosition: %2\nContexte: %3")
            .arg(parseError.errorString())
            .arg(parseError.offset)
            .arg(QString(response).mid(qMax(0, parseError.offset - 20), 40));
        
        qDebug() << errorMsg;
        emit errorOccurred(errorMsg);
        reply->deleteLater();
        return;
    }
    
    // Vérification que le document est un objet JSON
    if (!doc.isObject()) {
        QString errorMsg = "La réponse n'est pas un objet JSON valide";
        qDebug() << errorMsg;
        emit errorOccurred(errorMsg);
        reply->deleteLater();
        return;
    }
    
    QJsonObject rootObj = doc.object();
    
    // Vérification des erreurs de l'API
    if (rootObj.contains("error")) {
        QJsonObject errorObj = rootObj["error"].toObject();
        QString message = errorObj["message"].toString("Erreur inconnue");
        int code = errorObj["code"].toInt();
        QString status = errorObj["status"].toString("inconnu");
        
        QString errorMsg = QString("Erreur de l'API (%1 - %2): %3")
            .arg(code)
            .arg(status)
            .arg(message);
            
        qDebug() << errorMsg;
        emit errorOccurred(errorMsg);
        reply->deleteLater();
        return;
    }
    
    // Vérification de la présence de la liste des modèles
    if (!rootObj.contains("models")) {
        QString errorMsg = "La réponse ne contient pas de liste de modèles. Réponse complète :\n" + response;
        qDebug() << errorMsg;
        emit errorOccurred(errorMsg);
        reply->deleteLater();
        return;
    }
    
    // Traitement de la liste des modèles
    QJsonArray models = rootObj["models"].toArray();
    QStringList modelList;
    
    for (const QJsonValue &model : models) {
        if (model.isObject()) {
            QJsonObject modelObj = model.toObject();
            QString name = modelObj["name"].toString("Inconnu");
            QString displayName = modelObj["displayName"].toString("Sans nom");
            QString description = modelObj["description"].toString("Pas de description");
            
            // Récupération des méthodes supportées
            QStringList methods;
            if (modelObj.contains("supportedGenerationMethods") && 
                modelObj["supportedGenerationMethods"].isArray()) {
                QJsonArray methodsArray = modelObj["supportedGenerationMethods"].toArray();
                for (const QJsonValue &method : methodsArray) {
                    methods << method.toString();
                }
            }
            
            // Formatage des informations du modèle
            modelList << QString("🔹 %1\n   - ID: %2\n   - Description: %3\n   - Méthodes: %4")
                .arg(displayName)
                .arg(name)
                .arg(description)
                .arg(methods.isEmpty() ? "Aucune méthode spécifiée" : methods.join(", "));
        }
    }
    
    // Construction du résultat final
    QString result;
    if (!modelList.isEmpty()) {
        result = QString("=== %1 Modèles disponibles ===\n\n%2")
            .arg(modelList.size())
            .arg(modelList.join("\n\n"));
    } else {
        result = "Aucun modèle trouvé dans la réponse.";
    }
    
    qDebug() << "Liste des modèles générée avec succès";
    emit responseReceived(result);
    reply->deleteLater();
}

void ApiChatBot::getEmbedding(const QString &text)
{
    if (m_apiKey.isEmpty()) {
        emit errorOccurred("Aucune clé API configurée. Veuillez configurer votre clé API d'abord.");
        return;
    }

    QUrl url("https://generativelanguage.googleapis.com/v1beta/models/embedding-001:embedContent");
    QUrlQuery query;
    query.addQueryItem("key", m_apiKey);
    url.setQuery(query);

    // Construction du corps de la requête
    QJsonObject requestBody;
    QJsonObject content;
    content.insert("parts", QJsonArray() << QJsonObject({{ "text", text }}));
    requestBody.insert("content", content);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonDocument doc(requestBody);
    QByteArray data = doc.toJson();

    qDebug() << "Envoi de la requête d'embedding à:" << url.toString();
    qDebug() << "Corps de la requête:" << data;

    QNetworkReply *reply = m_manager->post(request, data);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        QByteArray response = reply->readAll();
        int httpStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        
        qDebug() << "=== Réponse d'embedding reçue ===";
        qDebug() << "Code HTTP:" << httpStatus;
        qDebug() << "Réponse:" << response;

        if (reply->error() != QNetworkReply::NoError) {
            QString errorMsg = QString("Erreur réseau (%1): %2\nDétails: %3")
                .arg(reply->error())
                .arg(reply->errorString())
                .arg(QString(response));
            
            emit errorOccurred(errorMsg);
            reply->deleteLater();
            return;
        }

        // Traitement de la réponse
        QJsonParseError parseError;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(response, &parseError);
        
        if (parseError.error != QJsonParseError::NoError) {
            emit errorOccurred("Erreur d'analyse JSON: " + parseError.errorString());
            reply->deleteLater();
            return;
        }

        QJsonObject jsonObj = jsonResponse.object();
        
        if (jsonObj.contains("error")) {
            QJsonObject errorObj = jsonObj["error"].toObject();
            QString errorMsg = errorObj["message"].toString();
            emit errorOccurred("Erreur de l'API: " + errorMsg);
        } else if (jsonObj.contains("embedding")) {
            QJsonObject embeddingObj = jsonObj["embedding"].toObject();
            if (embeddingObj.contains("values")) {
                QJsonArray values = embeddingObj["values"].toArray();
                emit responseReceived("Embedding généré avec succès (" + 
                                    QString::number(values.size()) + " dimensions)");
            }
        } else {
            emit errorOccurred("Format de réponse inattendu");
        }
        
        reply->deleteLater();
    });
}

bool ApiChatBot::configureApiKey(QWidget *parent)
{
    bool ok;
    QString apiKey = QInputDialog::getText(parent, 
                                         "Configuration de l'API Google AI",
                                         "Entrez votre clé API Google AI :\n(Disponible sur https://aistudio.google.com/app/apikey)",
                                         QLineEdit::Normal,
                                         loadApiKey(),
                                         &ok);

    if (ok) {
        if (apiKey.isEmpty()) {
            QMessageBox::warning(parent, 
                               "Erreur", 
                               "La clé API ne peut pas être vide.");
            return false;
        }
        saveApiKey(apiKey);
        QMessageBox::information(parent, 
                               "Configuration enregistrée",
                               "La clé API Google AI a été mise à jour avec succès.");
        return true;
    }
    return false;
}
