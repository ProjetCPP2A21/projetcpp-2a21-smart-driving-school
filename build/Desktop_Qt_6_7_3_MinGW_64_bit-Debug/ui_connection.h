/********************************************************************************
** Form generated from reading UI file 'connection.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTION_H
#define UI_CONNECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_connection
{
public:

    void setupUi(QWidget *connection)
    {
        if (connection->objectName().isEmpty())
            connection->setObjectName("connection");
        connection->resize(400, 300);

        retranslateUi(connection);

        QMetaObject::connectSlotsByName(connection);
    } // setupUi

    void retranslateUi(QWidget *connection)
    {
        connection->setWindowTitle(QCoreApplication::translate("connection", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class connection: public Ui_connection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTION_H
