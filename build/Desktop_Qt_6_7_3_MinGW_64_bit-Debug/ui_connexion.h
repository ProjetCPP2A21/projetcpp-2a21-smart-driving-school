/********************************************************************************
** Form generated from reading UI file 'connexion.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNEXION_H
#define UI_CONNEXION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_connexion
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QPushButton *Bconnexion;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *connexion)
    {
        if (connexion->objectName().isEmpty())
            connexion->setObjectName("connexion");
        connexion->resize(906, 524);
        centralwidget = new QWidget(connexion);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(490, 180, 301, 31));
        lineEdit->setStyleSheet(QString::fromUtf8(" background-color: rgba(255, 255, 255, 255);\n"
"    border: 2px solid rgba(144, 238, 144, 200);\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    color: rgba(0, 51, 102, 255);\n"
""));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 450, 911, 51));
        pushButton->setStyleSheet(QString::fromUtf8("  background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 102, 204, 255), stop: 0.5 rgba(144, 238, 144, 255), stop: 1 rgba(0, 51, 102, 255));\n"
"    border: 2px solid rgba(144, 238, 144, 200);\n"
"    padding: 8px;\n"
"    color: rgba(0, 51, 102, 255);\n"
"    font-weight: bold;\n"
"    border-radius: 10px;\n"
"    transition: all 0.3s ease;"));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(490, 130, 301, 31));
        lineEdit_2->setStyleSheet(QString::fromUtf8(" background-color: rgba(255, 255, 255, 255);\n"
"    border: 2px solid rgba(144, 238, 144, 200);\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    color: rgba(0, 51, 102, 255);"));
        Bconnexion = new QPushButton(centralwidget);
        Bconnexion->setObjectName("Bconnexion");
        Bconnexion->setGeometry(QRect(490, 250, 301, 41));
        Bconnexion->setStyleSheet(QString::fromUtf8("  background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 102, 204, 255), stop: 0.5 rgba(144, 238, 144, 255), stop: 1 rgba(0, 51, 102, 255));\n"
"    border: 2px solid rgba(144, 238, 144, 200);\n"
"    padding: 8px;\n"
"    color: rgba(0, 51, 102, 255);\n"
"    font-weight: bold;\n"
"    border-radius: 10px;\n"
"    transition: all 0.3s ease;"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 40, 381, 371));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/554337631_1437269814008871_8043664467412301076_n.png")));
        label->setScaledContents(true);
        connexion->setCentralWidget(centralwidget);
        menubar = new QMenuBar(connexion);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 906, 22));
        connexion->setMenuBar(menubar);
        statusbar = new QStatusBar(connexion);
        statusbar->setObjectName("statusbar");
        connexion->setStatusBar(statusbar);

        retranslateUi(connexion);

        QMetaObject::connectSlotsByName(connexion);
    } // setupUi

    void retranslateUi(QMainWindow *connexion)
    {
        connexion->setWindowTitle(QCoreApplication::translate("connexion", "connexion", nullptr));
        pushButton->setText(QString());
        Bconnexion->setText(QCoreApplication::translate("connexion", "connexion", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class connexion: public Ui_connexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNEXION_H
