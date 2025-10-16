/********************************************************************************
** Form generated from reading UI file 'modifier_employe.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFIER_EMPLOYE_H
#define UI_MODIFIER_EMPLOYE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_modifier_employe
{
public:
    QLabel *label;
    QGroupBox *modification;
    QLabel *label_2;
    QLineEdit *lineEdit_id;
    QLabel *label_3;
    QLineEdit *lineEdit_nom;
    QLabel *label_4;
    QLineEdit *lineEdit_prenom;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_email;
    QLabel *label_7;
    QLineEdit *lineEdit_telephone;
    QLabel *label_8;
    QLineEdit *lineEdit_poste;
    QLabel *label_9;
    QLineEdit *lineEdit_motdepasse;
    QLabel *label_10;
    QPushButton *BretourModifierEmploye;
    QPushButton *pushButton_confirmer;
    QPushButton *pushButton_annuler;
    QDateEdit *dateEdit_naissance;

    void setupUi(QWidget *modifier_employe)
    {
        if (modifier_employe->objectName().isEmpty())
            modifier_employe->setObjectName("modifier_employe");
        modifier_employe->resize(1418, 656);
        modifier_employe->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #f0f2f5, stop:1 #e1e8ed);\n"
"    color: #2c3e50;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"    font-size: 13px;\n"
"}"));
        label = new QLabel(modifier_employe);
        label->setObjectName("label");
        label->setGeometry(QRect(0, -10, 111, 91));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/554337631_1437269814008871_8043664467412301076_n.png")));
        label->setScaledContents(true);
        modification = new QGroupBox(modifier_employe);
        modification->setObjectName("modification");
        modification->setGeometry(QRect(60, 60, 611, 571));
        modification->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
"}\n"
""));
        label_2 = new QLabel(modification);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 130, 71, 20));
        lineEdit_id = new QLineEdit(modification);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(60, 160, 141, 31));
        lineEdit_id->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}\n"
""));
        label_3 = new QLabel(modification);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(290, 210, 63, 20));
        lineEdit_nom = new QLineEdit(modification);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(290, 240, 140, 26));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}\n"
""));
        label_4 = new QLabel(modification);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 210, 63, 20));
        lineEdit_prenom = new QLineEdit(modification);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(60, 240, 140, 26));
        lineEdit_prenom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}\n"
""));
        label_5 = new QLabel(modification);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(290, 280, 131, 20));
        label_6 = new QLabel(modification);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(290, 130, 63, 20));
        lineEdit_email = new QLineEdit(modification);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(290, 160, 140, 26));
        lineEdit_email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}\n"
""));
        label_7 = new QLabel(modification);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(60, 280, 81, 21));
        lineEdit_telephone = new QLineEdit(modification);
        lineEdit_telephone->setObjectName("lineEdit_telephone");
        lineEdit_telephone->setGeometry(QRect(60, 310, 140, 26));
        lineEdit_telephone->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}\n"
""));
        label_8 = new QLabel(modification);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(60, 350, 63, 20));
        lineEdit_poste = new QLineEdit(modification);
        lineEdit_poste->setObjectName("lineEdit_poste");
        lineEdit_poste->setGeometry(QRect(60, 380, 140, 26));
        lineEdit_poste->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}\n"
""));
        label_9 = new QLabel(modification);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(290, 350, 81, 21));
        lineEdit_motdepasse = new QLineEdit(modification);
        lineEdit_motdepasse->setObjectName("lineEdit_motdepasse");
        lineEdit_motdepasse->setGeometry(QRect(290, 380, 140, 26));
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
"}\n"
""));
        lineEdit_motdepasse->setEchoMode(QLineEdit::EchoMode::Password);
        label_10 = new QLabel(modification);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(230, -10, 201, 31));
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #2c3e50;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    background: transparent;\n"
"    border: none;\n"
"    padding: 0px;\n"
"}"));
        BretourModifierEmploye = new QPushButton(modification);
        BretourModifierEmploye->setObjectName("BretourModifierEmploye");
        BretourModifierEmploye->setGeometry(QRect(490, 60, 91, 41));
        BretourModifierEmploye->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"/* Hover : d\303\251grad\303\251 de rouges uniquement */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #ff0000,   /* rouge vif */\n"
"        stop:0.5 #cc0000, /* rouge moyen */\n"
"        stop:1 #990000    /* rouge fonc\303\251 */\n"
"    );\n"
"    border: 1px solid #800000; /* bordure assortie au d\303\251grad\303\251 */\n"
"    color: white;               /* texte reste blanc */\n"
"}"));
        pushButton_confirmer = new QPushButton(modification);
        pushButton_confirmer->setObjectName("pushButton_confirmer");
        pushButton_confirmer->setGeometry(QRect(300, 480, 111, 41));
        pushButton_confirmer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}\n"
""));
        pushButton_annuler = new QPushButton(modification);
        pushButton_annuler->setObjectName("pushButton_annuler");
        pushButton_annuler->setGeometry(QRect(80, 480, 101, 41));
        pushButton_annuler->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}\n"
""));
        dateEdit_naissance = new QDateEdit(modification);
        dateEdit_naissance->setObjectName("dateEdit_naissance");
        dateEdit_naissance->setGeometry(QRect(290, 310, 141, 31));
        dateEdit_naissance->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43cea2, stop:1 #185a9d);\n"
"    border-radius: 12px;\n"
"    padding: 6px 12px;\n"
"    background: white;\n"
"    color: #2c3e50;\n"
"}\n"
"\n"
"QDateEdit:focus {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #ff4b1f, stop:1 #ffc837); /* effet feu au focus */\n"
"}"));

        retranslateUi(modifier_employe);

        QMetaObject::connectSlotsByName(modifier_employe);
    } // setupUi

    void retranslateUi(QWidget *modifier_employe)
    {
        modifier_employe->setWindowTitle(QCoreApplication::translate("modifier_employe", "Modifier un employ\303\251", nullptr));
        label->setText(QString());
        modification->setTitle(QString());
        label_2->setText(QCoreApplication::translate("modifier_employe", "ID Employ\303\251", nullptr));
        lineEdit_id->setText(QCoreApplication::translate("modifier_employe", "1512", nullptr));
        lineEdit_id->setPlaceholderText(QCoreApplication::translate("modifier_employe", "Entrez l'ID employ\303\251", nullptr));
        label_3->setText(QCoreApplication::translate("modifier_employe", "Nom", nullptr));
        lineEdit_nom->setText(QCoreApplication::translate("modifier_employe", "lamouchi", nullptr));
        lineEdit_nom->setPlaceholderText(QCoreApplication::translate("modifier_employe", "Entrez le nom", nullptr));
        label_4->setText(QCoreApplication::translate("modifier_employe", "Pr\303\251nom", nullptr));
        lineEdit_prenom->setText(QCoreApplication::translate("modifier_employe", "ghassen", nullptr));
        lineEdit_prenom->setPlaceholderText(QCoreApplication::translate("modifier_employe", "Entrez le pr\303\251nom", nullptr));
        label_5->setText(QCoreApplication::translate("modifier_employe", "Date de naissance", nullptr));
        label_6->setText(QCoreApplication::translate("modifier_employe", "Email", nullptr));
        lineEdit_email->setText(QCoreApplication::translate("modifier_employe", "lamouchighassen@gmail.com", nullptr));
        lineEdit_email->setPlaceholderText(QCoreApplication::translate("modifier_employe", "exemple@email.com", nullptr));
        label_7->setText(QCoreApplication::translate("modifier_employe", "T\303\251l\303\251phone", nullptr));
        lineEdit_telephone->setPlaceholderText(QCoreApplication::translate("modifier_employe", "58 588 255", nullptr));
        label_8->setText(QCoreApplication::translate("modifier_employe", "Poste", nullptr));
        lineEdit_poste->setText(QCoreApplication::translate("modifier_employe", "Responsable", nullptr));
        lineEdit_poste->setPlaceholderText(QCoreApplication::translate("modifier_employe", "Responsable", nullptr));
        label_9->setText(QCoreApplication::translate("modifier_employe", "Mot de passe", nullptr));
        lineEdit_motdepasse->setText(QCoreApplication::translate("modifier_employe", "**************", nullptr));
        lineEdit_motdepasse->setPlaceholderText(QCoreApplication::translate("modifier_employe", "Mot de passe", nullptr));
        label_10->setText(QCoreApplication::translate("modifier_employe", "Modifier un Employ\303\251", nullptr));
        BretourModifierEmploye->setText(QCoreApplication::translate("modifier_employe", "Retour", nullptr));
        pushButton_confirmer->setText(QCoreApplication::translate("modifier_employe", "Confirmer", nullptr));
        pushButton_annuler->setText(QCoreApplication::translate("modifier_employe", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class modifier_employe: public Ui_modifier_employe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFIER_EMPLOYE_H
