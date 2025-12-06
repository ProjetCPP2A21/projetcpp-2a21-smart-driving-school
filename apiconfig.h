#ifndef APICONFIG_H
#define APICONFIG_H

#include <QString>

// Configuration de l'API
namespace ApiConfig {
    // Clé API
    const QString API_KEY = "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";
    
    // URL de base de l'API
    const QString BASE_URL = "https://api.openai.com/v1/chat/completions";
    
    // En-têtes de requête
    QByteArray getAuthHeader() {
        return QString("Bearer %1").arg(API_KEY).toUtf8();
    }
}

#endif // APICONFIG_H
