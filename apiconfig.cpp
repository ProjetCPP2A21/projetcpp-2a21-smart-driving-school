#include "apiconfig.h"

namespace ApiConfig {
    QByteArray getAuthHeader() {
        return QString("Bearer %1").arg(API_KEY).toUtf8();
    }
}
