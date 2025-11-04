/********************************************************************************
** Form generated from reading UI file 'ajouter_examen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTER_EXAMEN_H
#define UI_AJOUTER_EXAMEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ajouter_examen
{
public:

    void setupUi(QWidget *Ajouter_examen)
    {
        if (Ajouter_examen->objectName().isEmpty())
            Ajouter_examen->setObjectName("Ajouter_examen");
        Ajouter_examen->resize(400, 300);

        retranslateUi(Ajouter_examen);

        QMetaObject::connectSlotsByName(Ajouter_examen);
    } // setupUi

    void retranslateUi(QWidget *Ajouter_examen)
    {
        Ajouter_examen->setWindowTitle(QCoreApplication::translate("Ajouter_examen", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ajouter_examen: public Ui_Ajouter_examen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTER_EXAMEN_H
