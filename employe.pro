QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# uncomment to disable APIs deprecated before Qt 6.0.0
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    

SOURCES += \
    main.cpp \
    employe.cpp \
    modifier_employe.cpp \
    ajouter_employe.cpp

HEADERS += \
    employe.h \
    modifier_employe.h \
    ajouter_employe.h

FORMS += \
    employe.ui \
    modifier_employe.ui \
    ajouter_employe.ui

TRANSLATIONS += \
    employe_fr_FR.ts

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target