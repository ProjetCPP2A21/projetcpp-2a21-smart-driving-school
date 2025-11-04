/********************************************************************************
** Form generated from reading UI file 'examen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMEN_H
#define UI_EXAMEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_examen
{
public:

    void setupUi(QWidget *examen)
    {
        if (examen->objectName().isEmpty())
            examen->setObjectName("examen");
        examen->resize(400, 300);

        retranslateUi(examen);

        QMetaObject::connectSlotsByName(examen);
    } // setupUi

    void retranslateUi(QWidget *examen)
    {
        examen->setWindowTitle(QCoreApplication::translate("examen", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class examen: public Ui_examen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMEN_H
