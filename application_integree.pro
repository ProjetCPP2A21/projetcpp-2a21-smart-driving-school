QT += core gui sql widgets charts printsupport

CONFIG += c++17

SOURCES += \
    apprenant.cpp \
    connection.cpp \
    examen.cpp \
    moniteur.cpp \
    vehicules.cpp \
    paiement.cpp \
    main.cpp \
    application_integree.cpp

HEADERS += \
    apprenant.h \
    connection.h \
    examen.h \
    moniteur.h \
    vehicules.h \
    paiement.h \
    application_integree.h

FORMS += \
    application_integree.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



