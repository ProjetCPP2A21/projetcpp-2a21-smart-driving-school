#-------------------------------------------------
#
# Project created by QtCreator
#
#-------------------------------------------------

QT += core gui widgets sql

TARGET = Atelier_Connexion
TEMPLATE = app

CONFIG += c++11

# ----- SOURCES -----
SOURCES += \
    main.cpp \
    mainwindow.cpp \
    connection.cpp

# ----- HEADERS -----
HEADERS += \
    mainwindow.h \
    connection.h

# ----- UI FORMS -----
FORMS += \
    mainwindow.ui

# ----- AVERTISSEMENTS -----
DEFINES += QT_DEPRECATED_WARNINGS

# ----- RÈGLES DE DÉPLOIEMENT -----
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
