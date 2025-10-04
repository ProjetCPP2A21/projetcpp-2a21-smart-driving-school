QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    examens.cpp \
    main.cpp \
    connexion.cpp \
    menu.cpp

HEADERS += \
    connexion.h \
    examens.h \
    menu.h

FORMS += \
    connexion.ui \
    examens.ui \
    menu.ui

<<<<<<< HEAD
=======
TRANSLATIONS += \
    integ-menu-examens_fr_FR.ts
CONFIG += lrelease
CONFIG += embed_translations

>>>>>>> origin/main-original
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    logo.qrc
