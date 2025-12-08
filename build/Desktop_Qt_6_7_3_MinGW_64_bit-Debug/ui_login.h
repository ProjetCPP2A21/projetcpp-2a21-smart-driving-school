/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QGroupBox *grp_login;
    QLabel *label_titre;
    QLabel *label_adresse;
    QLineEdit *lineEdit_adresse;
    QLabel *label_motdepasse;
    QLineEdit *lineEdit_motdepasse;
    QPushButton *btn_connexion;
    QPushButton *btn_motdepasse_oublie;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(800, 600);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName("centralwidget");
        grp_login = new QGroupBox(centralwidget);
        grp_login->setObjectName("grp_login");
        grp_login->setGeometry(QRect(200, 100, 400, 400));
        grp_login->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    font-weight: bold;\n"
"    font-size: 16px;\n"
"    color: #2c3e50;\n"
"    border: 3px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43cea2, stop:1 #185a9d);\n"
"    border-radius: 15px;\n"
"    margin-top: 15px;\n"
"    padding-top: 15px;\n"
"    background: rgba(255, 255, 255, 0.95);\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 15px;\n"
"    padding: 0 8px 0 8px;\n"
"    background: white;\n"
"    color: #2c3e50;\n"
"    font-weight: bold;\n"
"    font-size: 16px;\n"
"}"));
        label_titre = new QLabel(grp_login);
        label_titre->setObjectName("label_titre");
        label_titre->setGeometry(QRect(120, 20, 161, 31));
        label_titre->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #2c3e50;\n"
"    font-size: 24px;\n"
"    font-weight: bold;\n"
"    background: transparent;\n"
"    border: none;\n"
"    padding: 0px;\n"
"}"));
        label_adresse = new QLabel(grp_login);
        label_adresse->setObjectName("label_adresse");
        label_adresse->setGeometry(QRect(50, 100, 71, 20));
        lineEdit_adresse = new QLineEdit(grp_login);
        lineEdit_adresse->setObjectName("lineEdit_adresse");
        lineEdit_adresse->setGeometry(QRect(50, 130, 300, 31));
        lineEdit_adresse->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43cea2, stop:1 #185a9d);\n"
"    border-radius: 10px;\n"
"    padding: 4px 8px;\n"
"    background: white;\n"
"    color: #2c3e50;\n"
"    min-width: 120px;\n"
"    max-width: 200px;\n"
"    height: 24px;\n"
"    selection-background-color: #43cea2;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"/* Focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #ff4b1f, stop:1 #ffc837);\n"
"    box-shadow: 0 0 4px rgba(255, 107, 53, 0.6);\n"
"}\n"
"\n"
"/* Hover */\n"
"QLineEdit:hover {\n"
"    border: 2px solid #43cea2;\n"
"    box-shadow: 0 0 4px rgba(67, 206, 162, 0.6);\n"
"}\n"
"\n"
"/* Placeholder text */\n"
"QLineEdit[placeholderText]:empty {\n"
"    color: #95a5a6;\n"
"}"));
        label_motdepasse = new QLabel(grp_login);
        label_motdepasse->setObjectName("label_motdepasse");
        label_motdepasse->setGeometry(QRect(50, 190, 81, 21));
        lineEdit_motdepasse = new QLineEdit(grp_login);
        lineEdit_motdepasse->setObjectName("lineEdit_motdepasse");
        lineEdit_motdepasse->setGeometry(QRect(50, 220, 300, 31));
        lineEdit_motdepasse->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43cea2, stop:1 #185a9d);\n"
"    border-radius: 10px;\n"
"    padding: 4px 8px;\n"
"    background: white;\n"
"    color: #2c3e50;\n"
"    min-width: 120px;\n"
"    max-width: 200px;\n"
"    height: 24px;\n"
"    selection-background-color: #43cea2;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"/* Focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #ff4b1f, stop:1 #ffc837);\n"
"    box-shadow: 0 0 4px rgba(255, 107, 53, 0.6);\n"
"}\n"
"\n"
"/* Hover */\n"
"QLineEdit:hover {\n"
"    border: 2px solid #43cea2;\n"
"    box-shadow: 0 0 4px rgba(67, 206, 162, 0.6);\n"
"}\n"
"\n"
"/* Placeholder text */\n"
"QLineEdit[placeholderText]:empty {\n"
"    color: #95a5a6;\n"
"}"));
        lineEdit_motdepasse->setEchoMode(QLineEdit::Password);
        btn_connexion = new QPushButton(grp_login);
        btn_connexion->setObjectName("btn_connexion");
        btn_connexion->setGeometry(QRect(120, 280, 161, 41));
        btn_connexion->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43cea2,\n"
"        stop:1 #185a9d\n"
"    );\n"
"    color: white;\n"
"    border-radius: 12px;\n"
"    padding: 10px 22px;\n"
"    font-weight: bold;\n"
"    border: 1px solid #144d7e;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #ff4e50,   /* rouge vif */\n"
"        stop:0.5 #fc913a, /* orange vif */\n"
"        stop:1 #f9d423   /* jaune lumineux */\n"
"    );\n"
"    border: 1px solid #e04b3f; /* bordure assortie au feu */\n"
"}"));
        btn_motdepasse_oublie = new QPushButton(grp_login);
        btn_motdepasse_oublie->setObjectName("btn_motdepasse_oublie");
        btn_motdepasse_oublie->setGeometry(QRect(100, 340, 201, 31));
        btn_motdepasse_oublie->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: transparent;\n"
"    color: #185a9d;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"    text-decoration: underline;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: #43cea2;\n"
"}"));
        Login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Login);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Login->setMenuBar(menubar);
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName("statusbar");
        Login->setStatusBar(statusbar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Connexion", nullptr));
        grp_login->setTitle(QString());
        label_titre->setText(QCoreApplication::translate("Login", "Connexion", nullptr));
        label_adresse->setText(QCoreApplication::translate("Login", "Adresse", nullptr));
        lineEdit_adresse->setPlaceholderText(QCoreApplication::translate("Login", "Entrez votre adresse", nullptr));
        label_motdepasse->setText(QCoreApplication::translate("Login", "Mot de passe", nullptr));
        lineEdit_motdepasse->setPlaceholderText(QCoreApplication::translate("Login", "Entrez votre mot de passe", nullptr));
        btn_connexion->setText(QCoreApplication::translate("Login", "Connexion", nullptr));
        btn_motdepasse_oublie->setText(QCoreApplication::translate("Login", "Mot de passe oubli\303\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
