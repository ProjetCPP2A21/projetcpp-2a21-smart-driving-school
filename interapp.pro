# ========================================
# Projet InterApp - Fusion Apprenants + Examens
# ========================================

QT       += core gui widgets network sql charts printsupport

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
# SOURCES - Fichiers sources
# ========================================
SOURCES += \
    main.cpp \
    apprenants.cpp \
    apprenant.cpp \
    chatwindow.cpp \
    chatbot.cpp \
    apichatbot.cpp \
    suggestionbutton.cpp \
    connection.cpp \
    notification.cpp \
    modulemanager.cpp \
    examens.cpp \
    examen.cpp \
    ajouter.cpp \
    ajouter_examen.cpp \
    arduino.cpp \
    apiconfigdialog.cpp \
    apiconfig.cpp

# ========================================
# HEADERS - Fichiers headers
# ========================================
HEADERS += \
    apprenants.h \
    apprenant.h \
    chatwindow.h \
    chatbot.h \
    apichatbot.h \
    notification.h \
    suggestionbutton.h \
    connection.h \
    module.h \
    modulemanager.h \
    apiconfig.h \
    apiconfigdialog.h \
    examens.h \
    examen.h \
    ajouter.h \
    ajouter_examen.h \
    arduino.h

# ========================================
# FORMS - Fichiers UI
# ========================================
FORMS += \
    examens.ui
# RESOURCES - Fichiers de ressources
# ========================================
RESOURCES += \
    resources.qrc \
    logo.qrc \
    recherche.qrc \
    rech.qrc \
    video_background.qrc

# ========================================
# TRANSLATIONS - Fichiers de traduction
# ========================================
TRANSLATIONS += \
    examens_fr_FR.ts

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


