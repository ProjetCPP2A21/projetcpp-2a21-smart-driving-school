/********************************************************************************
** Form generated from reading UI file 'ajouter.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTER_H
#define UI_AJOUTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ajouter
{
public:

    void setupUi(QWidget *Ajouter)
    {
        if (Ajouter->objectName().isEmpty())
            Ajouter->setObjectName("Ajouter");
        Ajouter->resize(400, 300);

        retranslateUi(Ajouter);

        QMetaObject::connectSlotsByName(Ajouter);
    } // setupUi

    void retranslateUi(QWidget *Ajouter)
    {
        Ajouter->setWindowTitle(QCoreApplication::translate("Ajouter", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ajouter: public Ui_Ajouter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTER_H
