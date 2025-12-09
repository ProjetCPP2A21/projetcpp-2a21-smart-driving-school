# ========================================
# Projet InterApp - Plateforme Intégrée (Examens + Apprenants + Véhicules)
# ========================================
QT       += core gui sql
QT       += core gui printsupport
QT       += core charts
QT += charts
QT       += core gui  serialport
QT += core gui sql printsupport charts network
    quick
QT += core gui multimedia multimediawidgets

QT       += core gui widgets network sql charts printsupport texttospeech

# Configuration du compilateur C++
CONFIG += c++17

# Désactiver les avertissements de suppression de fichiers
CONFIG += no_duplicate_files

# Configuration pour MinGW
win32:g++ {
    QMAKE_CXXFLAGS += -mthreads
    QMAKE_LFLAGS += -Wl,-subsystem,windows

    # Désactiver les avertissements spécifiques
    QMAKE_CXXFLAGS_WARN_OFF = -w
    QMAKE_CFLAGS_WARN_OFF = -w
}

# Désactiver les avertissements inutiles
QMAKE_CXXFLAGS += -w
QMAKE_CFLAGS += -w

# Configuration du build
TEMPLATE = app
TARGET = InterApp
DESTDIR = bin

# ========================================
# SOURCES - Fichiers sources (Moniteur uniquement)
# ========================================
SOURCES += \
    arduino.cpp \
    main.cpp \
    connection.cpp \
    moniteur.cpp \
    moniteur_ui.cpp

# ========================================
# HEADERS - Fichiers headers (Moniteur uniquement)
# ========================================
HEADERS += \
    arduino.h \
    connection.h \
    moniteur.h \
    moniteur_ui.h

# ========================================
# FORMS - Fichiers UI (Moniteur uniquement)
# ========================================
FORMS += \
    moniteur.ui
# RESOURCES - Fichiers de ressources
# ========================================
RESOURCES += \
    resources.qrc \
    logo.qrc \
    recherche.qrc \
    rech.qrc \
    video_background.qrc \
    paiement.qrc

# ========================================
# TRANSLATIONS - Fichiers de traduction
# ========================================
TRANSLATIONS +=

CONFIG += lrelease
CONFIG += embed_translations

# ========================================
# CONFIGURATION
# ========================================

# Nettoyage des fichiers générés
QMAKE_CLEAN += *.o moc_* ui_* *.obj

# Options de compilation
win32: LIBS += -lOle32

# Inclure les répertoires d'en-têtes
INCLUDEPATH += .

# Définitions supplémentaires
DEFINES += QT_DEPRECATED_WARNINGS

# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS +=

