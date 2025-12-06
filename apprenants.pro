<<<<<<< HEAD
QT += core gui sql widgets charts

CONFIG += c++17

SOURCES += \
    apprenant.cpp \
    connection.cpp \
    main.cpp \
    apprenants.cpp

HEADERS += \
    apprenant.h \
    apprenants.h \
    connection.h

FORMS += \
    apprenants.ui
=======
# -----------------------------
# Projet Apprenants Chatbot
# -----------------------------

QT       += core gui widgets network sql

# Qt Charts
QT       += charts

# Qt SerialPort pour la communication avec l'Arduino
QT       += serialport

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
TARGET = ApprenantsApp
DESTDIR = bin

# Fichiers sources
SOURCES += \
    main.cpp \
    apprenants.cpp \
    apprenant.cpp \
    chatwindow.cpp \
    apichatbot.cpp \
    suggestionbutton.cpp \
    connection.cpp \
    notification.cpp

# Fichiers headers
HEADERS += \
    apprenants.h \
    apprenant.h \
    chatwindow.h \
    apichatbot.h \
    notification.h \
    suggestionbutton.h \
    connection.h

# Fichiers UI (uniquement une déclaration)
FORMS += \
    apprenants.ui \
    chatwindow.ui

# Fichier de ressources
RESOURCES += \
    resources.qrc

# Nettoyage des fichiers générés
QMAKE_CLEAN += *.o moc_* ui_* *.obj

# Options de compilation
win32: LIBS += -lOle32

# Inclure les répertoires d'en-têtes
INCLUDEPATH += .

# Définitions supplémentaires
DEFINES += QT_DEPRECATED_WARNINGS
>>>>>>> 4229cbb (ajout arduino)
