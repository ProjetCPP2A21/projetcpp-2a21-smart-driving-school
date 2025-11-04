QT       += core gui
<<<<<<< HEAD

=======
QT+=sql
>>>>>>> ae4c4d6 (hello)
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
<<<<<<< HEAD
    main.cpp \
    vehicule.cpp

HEADERS += \
    vehicule.h
=======
    cnx.cpp \
    main.cpp \
    vehicule.cpp \
    vehicules.cpp

HEADERS += \
    cnx.h \
    vehicule.h \
    vehicules.h
>>>>>>> ae4c4d6 (hello)

FORMS += \
    vehicule.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
<<<<<<< HEAD
=======

RESOURCES += \
    logo.qrc

DISTFILES += \
    ../../Bureau/Atelier_Connexion/Atelier_Connexion.pro.user
>>>>>>> ae4c4d6 (hello)
