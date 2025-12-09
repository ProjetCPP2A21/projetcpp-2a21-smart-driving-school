/********************************************************************************
** Form generated from reading UI file 'arduino.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARDUINO_H
#define UI_ARDUINO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_arduino
{
public:

    void setupUi(QWidget *arduino)
    {
        if (arduino->objectName().isEmpty())
            arduino->setObjectName("arduino");
        arduino->resize(400, 300);

        retranslateUi(arduino);

        QMetaObject::connectSlotsByName(arduino);
    } // setupUi

    void retranslateUi(QWidget *arduino)
    {
        arduino->setWindowTitle(QCoreApplication::translate("arduino", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class arduino: public Ui_arduino {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARDUINO_H
