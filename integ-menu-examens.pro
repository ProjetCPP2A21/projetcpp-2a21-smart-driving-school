QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ajouter_employe.cpp \
    apprenant.cpp \
    employe.cpp \
    examens.cpp \
    main.cpp \
    connexion.cpp \
    menu.cpp \
    modifier_employe.cpp \
    moniteur.cpp \
    paiement.cpp \
    vehicule.cpp
    employe.cpp

HEADERS += \
    ajouter_employe.h \
    apprenant.h \
    connexion.h \
    employe.h \
    examens.h \
    menu.h \
    modifier_employe.h \
    moniteur.h \
    paiement.h \
    vehicule.h
    employe.h

FORMS += \
    ajouter_employe.ui \
    apprenant.ui \
    connexion.ui \
    employe.ui \
    examens.ui \
    menu.ui \
    modifier_employe.ui \
    moniteur.ui \
    paiement.ui \
    vehicule.ui
    employe.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    logo.qrc
