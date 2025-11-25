QT += core gui sql widgets printsupport charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++11

SOURCES += \
    main.cpp \
    moniteur.cpp \
    moniteur_ui.cpp \
    cnx.cpp

HEADERS += \
    moniteur.h \
    moniteur_ui.h \
    cnx.h

FORMS += \
    moniteur.ui

RESOURCES += \
    LOGO.qrc

DISTFILES +=
