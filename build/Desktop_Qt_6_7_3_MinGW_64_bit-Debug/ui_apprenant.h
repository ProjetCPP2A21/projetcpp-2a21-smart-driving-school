/********************************************************************************
** Form generated from reading UI file 'apprenant.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPRENANT_H
#define UI_APPRENANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_apprenant
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *apprenant)
    {
        if (apprenant->objectName().isEmpty())
            apprenant->setObjectName("apprenant");
        apprenant->resize(800, 600);
        centralwidget = new QWidget(apprenant);
        centralwidget->setObjectName("centralwidget");
        apprenant->setCentralWidget(centralwidget);
        menubar = new QMenuBar(apprenant);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        apprenant->setMenuBar(menubar);
        statusbar = new QStatusBar(apprenant);
        statusbar->setObjectName("statusbar");
        apprenant->setStatusBar(statusbar);

        retranslateUi(apprenant);

        QMetaObject::connectSlotsByName(apprenant);
    } // setupUi

    void retranslateUi(QMainWindow *apprenant)
    {
        apprenant->setWindowTitle(QCoreApplication::translate("apprenant", "apprenant", nullptr));
    } // retranslateUi

};

namespace Ui {
    class apprenant: public Ui_apprenant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPRENANT_H
