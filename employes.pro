QT += core widgets

CONFIG += c++17

TARGET = employes
TEMPLATE = app

# Fichiers sources
SOURCES += \
    main.cpp \
    connexion.cpp \
    menu.cpp \
    employe.cpp \
    ajouter_employe.cpp \
    modifier_employe.cpp

# Fichiers headers
HEADERS += \
    connexion.h \
    menu.h \
    employe.h \
    ajouter_employe.h \
    modifier_employe.h

# Fichiers UI
FORMS += \
    connexion.ui \
    menu.ui \
    employe.ui \
    ajouter_employe.ui \
    modifier_employe.ui

# Ressources
RESOURCES += \
    logo.qrc

# Configuration pour Windows
win32 {
    TARGET_EXT = .exe
}

# Configuration pour macOS
macx {
    TARGET_EXT = .app
}

# Configuration pour Linux
unix {
    TARGET_EXT = 
}

