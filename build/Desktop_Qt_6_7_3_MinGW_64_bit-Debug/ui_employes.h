/********************************************************************************
** Form generated from reading UI file 'employes.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYES_H
#define UI_EMPLOYES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Employes
{
public:
    QWidget *centralwidget;
    QGroupBox *menu;
    QPushButton *Bemploye;
    QPushButton *Bvehicule;
    QPushButton *Bapprenant;
    QPushButton *Bmoniteurs;
    QPushButton *Bpaiement;
    QPushButton *Bexamens;
    QGroupBox *grp_ajoutEmpl;
    QLabel *label_47;
    QLineEdit *idEmpl_ajout;
    QLabel *label_48;
    QLineEdit *nomEmpl_ajout;
    QLabel *label_49;
    QLineEdit *prenomEmpl_ajput;
    QLabel *label_51;
    QLineEdit *EmailEmpl_ajout;
    QLabel *label_53;
    QLabel *label_54;
    QLineEdit *mdpEmpl_ajout;
    QLabel *label_55;
    QPushButton *retour_AjoutEmpl;
    QPushButton *confirmer_AjoutEmpl;
    QPushButton *pushButton_annuler_5;
    QComboBox *posteEmpl_ajout;
    QPushButton *pushButton;
    QGroupBox *Employe;
    QLabel *label_56;
    QLineEdit *idEmploye;
    QLabel *label_57;
    QLineEdit *nomEmploye;
    QLabel *label_58;
    QLineEdit *prenomEmploye;
    QLabel *label_60;
    QLineEdit *emailEmploye;
    QLabel *label_62;
    QLabel *label_63;
    QLineEdit *mdpEmploye;
    QLabel *label_64;
    QPushButton *retourEmpl;
    QPushButton *modifierEmpl;
    QPushButton *supprimerEmploye;
    QPushButton *ajoutEmpl;
    QPushButton *btn_statEmpl;
    QPushButton *PDFempl;
    QLineEdit *rechercheEmpl;
    QComboBox *trieEmpl;
    QTableView *tabEmploye;
    QComboBox *posteEmploye;
    QLabel *lab_statEmpl;
    QGroupBox *grp_ModifierEmpl;
    QLabel *label_65;
    QLineEdit *lineEdit_id_6;
    QLabel *label_66;
    QLineEdit *lineEdit_nom_6;
    QLabel *label_67;
    QLineEdit *lineEdit_prenom_6;
    QLabel *label_68;
    QLabel *label_69;
    QLineEdit *lineEdit_email_6;
    QLabel *label_70;
    QLineEdit *lineEdit_telephone_6;
    QLabel *label_71;
    QLineEdit *lineEdit_poste_6;
    QLabel *label_72;
    QLineEdit *lineEdit_motdepasse_6;
    QLabel *label_73;
    QPushButton *retoure_modifierEmpl;
    QPushButton *pushButton_confirmer;
    QPushButton *pushButton_annuler_6;
    QDateEdit *dateEdit_naissance_6;
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

    void setupUi(QMainWindow *Employes)
    {
        if (Employes->objectName().isEmpty())
            Employes->setObjectName("Employes");
        Employes->resize(1892, 801);
        centralwidget = new QWidget(Employes);
        centralwidget->setObjectName("centralwidget");
        menu = new QGroupBox(centralwidget);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(0, 0, 1881, 721));
        Bemploye = new QPushButton(menu);
        Bemploye->setObjectName("Bemploye");
        Bemploye->setGeometry(QRect(10, 310, 111, 81));
        Bemploye->setStyleSheet(QString::fromUtf8("\n"
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
"        stop:0 #2ebf91,\n"
"        stop:1 #0f2027\n"
"    );"));
        Bvehicule = new QPushButton(menu);
        Bvehicule->setObjectName("Bvehicule");
        Bvehicule->setGeometry(QRect(10, 160, 111, 71));
        Bvehicule->setStyleSheet(QString::fromUtf8("\n"
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
"        stop:0 #2ebf91,\n"
"        stop:1 #0f2027\n"
"    );"));
        Bapprenant = new QPushButton(menu);
        Bapprenant->setObjectName("Bapprenant");
        Bapprenant->setGeometry(QRect(10, 0, 111, 81));
        Bapprenant->setStyleSheet(QString::fromUtf8("\n"
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
"        stop:0 #2ebf91,\n"
"        stop:1 #0f2027\n"
"    );"));
        Bmoniteurs = new QPushButton(menu);
        Bmoniteurs->setObjectName("Bmoniteurs");
        Bmoniteurs->setGeometry(QRect(10, 80, 111, 81));
        Bmoniteurs->setStyleSheet(QString::fromUtf8("\n"
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
"        stop:0 #2ebf91,\n"
"        stop:1 #0f2027\n"
"    );"));
        Bpaiement = new QPushButton(menu);
        Bpaiement->setObjectName("Bpaiement");
        Bpaiement->setGeometry(QRect(10, 390, 111, 91));
        Bpaiement->setStyleSheet(QString::fromUtf8("\n"
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
"        stop:0 #2ebf91,\n"
"        stop:1 #0f2027\n"
"    );"));
        Bexamens = new QPushButton(menu);
        Bexamens->setObjectName("Bexamens");
        Bexamens->setGeometry(QRect(10, 230, 111, 81));
        Bexamens->setStyleSheet(QString::fromUtf8("\n"
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
"        stop:0 #2ebf91,\n"
"        stop:1 #0f2027\n"
"    );"));
        grp_ajoutEmpl = new QGroupBox(menu);
        grp_ajoutEmpl->setObjectName("grp_ajoutEmpl");
        grp_ajoutEmpl->setGeometry(QRect(320, 20, 611, 611));
        grp_ajoutEmpl->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        label_47 = new QLabel(grp_ajoutEmpl);
        label_47->setObjectName("label_47");
        label_47->setGeometry(QRect(60, 130, 71, 20));
        idEmpl_ajout = new QLineEdit(grp_ajoutEmpl);
        idEmpl_ajout->setObjectName("idEmpl_ajout");
        idEmpl_ajout->setGeometry(QRect(60, 160, 141, 31));
        idEmpl_ajout->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_48 = new QLabel(grp_ajoutEmpl);
        label_48->setObjectName("label_48");
        label_48->setGeometry(QRect(290, 210, 63, 20));
        nomEmpl_ajout = new QLineEdit(grp_ajoutEmpl);
        nomEmpl_ajout->setObjectName("nomEmpl_ajout");
        nomEmpl_ajout->setGeometry(QRect(290, 240, 140, 26));
        nomEmpl_ajout->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_49 = new QLabel(grp_ajoutEmpl);
        label_49->setObjectName("label_49");
        label_49->setGeometry(QRect(60, 210, 63, 20));
        prenomEmpl_ajput = new QLineEdit(grp_ajoutEmpl);
        prenomEmpl_ajput->setObjectName("prenomEmpl_ajput");
        prenomEmpl_ajput->setGeometry(QRect(60, 240, 140, 26));
        prenomEmpl_ajput->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_51 = new QLabel(grp_ajoutEmpl);
        label_51->setObjectName("label_51");
        label_51->setGeometry(QRect(290, 130, 63, 20));
        EmailEmpl_ajout = new QLineEdit(grp_ajoutEmpl);
        EmailEmpl_ajout->setObjectName("EmailEmpl_ajout");
        EmailEmpl_ajout->setGeometry(QRect(290, 160, 140, 26));
        EmailEmpl_ajout->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_53 = new QLabel(grp_ajoutEmpl);
        label_53->setObjectName("label_53");
        label_53->setGeometry(QRect(60, 280, 63, 20));
        label_54 = new QLabel(grp_ajoutEmpl);
        label_54->setObjectName("label_54");
        label_54->setGeometry(QRect(290, 280, 81, 21));
        mdpEmpl_ajout = new QLineEdit(grp_ajoutEmpl);
        mdpEmpl_ajout->setObjectName("mdpEmpl_ajout");
        mdpEmpl_ajout->setGeometry(QRect(290, 310, 140, 26));
        mdpEmpl_ajout->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        mdpEmpl_ajout->setEchoMode(QLineEdit::Normal);
        label_55 = new QLabel(grp_ajoutEmpl);
        label_55->setObjectName("label_55");
        label_55->setGeometry(QRect(230, -10, 201, 31));
        label_55->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #2c3e50;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    background: transparent;\n"
"    border: none;\n"
"    padding: 0px;\n"
"}"));
        retour_AjoutEmpl = new QPushButton(grp_ajoutEmpl);
        retour_AjoutEmpl->setObjectName("retour_AjoutEmpl");
        retour_AjoutEmpl->setGeometry(QRect(490, 60, 91, 41));
        retour_AjoutEmpl->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        confirmer_AjoutEmpl = new QPushButton(grp_ajoutEmpl);
        confirmer_AjoutEmpl->setObjectName("confirmer_AjoutEmpl");
        confirmer_AjoutEmpl->setGeometry(QRect(330, 480, 91, 41));
        confirmer_AjoutEmpl->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_annuler_5 = new QPushButton(grp_ajoutEmpl);
        pushButton_annuler_5->setObjectName("pushButton_annuler_5");
        pushButton_annuler_5->setGeometry(QRect(80, 480, 101, 41));
        pushButton_annuler_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        posteEmpl_ajout = new QComboBox(grp_ajoutEmpl);
        posteEmpl_ajout->addItem(QString());
        posteEmpl_ajout->addItem(QString());
        posteEmpl_ajout->addItem(QString());
        posteEmpl_ajout->setObjectName("posteEmpl_ajout");
        posteEmpl_ajout->setGeometry(QRect(60, 310, 140, 31));
        posteEmpl_ajout->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
"QComboBox:focus {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #ff4b1f, stop:1 #ffc837);\n"
"    box-shadow: 0 0 4px rgba(255, 107, 53, 0.6);\n"
"}\n"
"\n"
"/* Hover */\n"
"QComboBox:hover {\n"
"    border: 2px solid #43cea2;\n"
"    box-shadow: 0 0 4px rgba(67, 206, 162, 0.6);\n"
"}\n"
"\n"
"/* Placeholder text */\n"
"QComboBox[placeholderText]:empty {\n"
"    color: #95a5a6;\n"
"}\n"
""));
        pushButton = new QPushButton(menu);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(-10, 680, 1631, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"}"));
        Employe = new QGroupBox(menu);
        Employe->setObjectName("Employe");
        Employe->setGeometry(QRect(320, 20, 1521, 571));
        Employe->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        label_56 = new QLabel(Employe);
        label_56->setObjectName("label_56");
        label_56->setGeometry(QRect(60, 130, 71, 20));
        idEmploye = new QLineEdit(Employe);
        idEmploye->setObjectName("idEmploye");
        idEmploye->setGeometry(QRect(60, 160, 141, 31));
        idEmploye->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_57 = new QLabel(Employe);
        label_57->setObjectName("label_57");
        label_57->setGeometry(QRect(290, 210, 63, 20));
        nomEmploye = new QLineEdit(Employe);
        nomEmploye->setObjectName("nomEmploye");
        nomEmploye->setGeometry(QRect(290, 240, 140, 26));
        nomEmploye->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_58 = new QLabel(Employe);
        label_58->setObjectName("label_58");
        label_58->setGeometry(QRect(60, 210, 63, 20));
        prenomEmploye = new QLineEdit(Employe);
        prenomEmploye->setObjectName("prenomEmploye");
        prenomEmploye->setGeometry(QRect(60, 240, 140, 26));
        prenomEmploye->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_60 = new QLabel(Employe);
        label_60->setObjectName("label_60");
        label_60->setGeometry(QRect(290, 130, 63, 20));
        emailEmploye = new QLineEdit(Employe);
        emailEmploye->setObjectName("emailEmploye");
        emailEmploye->setGeometry(QRect(290, 160, 140, 26));
        emailEmploye->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_62 = new QLabel(Employe);
        label_62->setObjectName("label_62");
        label_62->setGeometry(QRect(60, 290, 63, 20));
        label_63 = new QLabel(Employe);
        label_63->setObjectName("label_63");
        label_63->setGeometry(QRect(290, 280, 81, 21));
        mdpEmploye = new QLineEdit(Employe);
        mdpEmploye->setObjectName("mdpEmploye");
        mdpEmploye->setGeometry(QRect(290, 320, 140, 26));
        mdpEmploye->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        mdpEmploye->setEchoMode(QLineEdit::Normal);
        label_64 = new QLabel(Employe);
        label_64->setObjectName("label_64");
        label_64->setGeometry(QRect(470, 0, 201, 31));
        label_64->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #2c3e50;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    background: transparent;\n"
"    border: none;\n"
"    padding: 0px;\n"
"}"));
        retourEmpl = new QPushButton(Employe);
        retourEmpl->setObjectName("retourEmpl");
        retourEmpl->setGeometry(QRect(1090, 30, 91, 41));
        retourEmpl->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        modifierEmpl = new QPushButton(Employe);
        modifierEmpl->setObjectName("modifierEmpl");
        modifierEmpl->setGeometry(QRect(120, 490, 101, 41));
        modifierEmpl->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        supprimerEmploye = new QPushButton(Employe);
        supprimerEmploye->setObjectName("supprimerEmploye");
        supprimerEmploye->setGeometry(QRect(300, 490, 111, 41));
        supprimerEmploye->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        ajoutEmpl = new QPushButton(Employe);
        ajoutEmpl->setObjectName("ajoutEmpl");
        ajoutEmpl->setGeometry(QRect(210, 440, 91, 41));
        ajoutEmpl->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btn_statEmpl = new QPushButton(Employe);
        btn_statEmpl->setObjectName("btn_statEmpl");
        btn_statEmpl->setGeometry(QRect(800, 490, 131, 41));
        btn_statEmpl->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        PDFempl = new QPushButton(Employe);
        PDFempl->setObjectName("PDFempl");
        PDFempl->setGeometry(QRect(950, 490, 131, 41));
        PDFempl->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        rechercheEmpl = new QLineEdit(Employe);
        rechercheEmpl->setObjectName("rechercheEmpl");
        rechercheEmpl->setGeometry(QRect(520, 430, 401, 31));
        rechercheEmpl->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43cea2, stop:1 #185a9d);\n"
"    border-radius: 12px;\n"
"    padding: 6px 12px;\n"
"    background: white;\n"
"    color: #2c3e50;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #ff4b1f, stop:1 #ffc837); /* style feu au focus */\n"
"}\n"
""));
        trieEmpl = new QComboBox(Employe);
        trieEmpl->addItem(QString());
        trieEmpl->addItem(QString());
        trieEmpl->addItem(QString());
        trieEmpl->setObjectName("trieEmpl");
        trieEmpl->setGeometry(QRect(960, 430, 120, 31));
        trieEmpl->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43cea2, stop:1 #185a9d);\n"
"    border-radius: 10px;    /* un peu moins arrondi si tu veux */\n"
"    padding: 4px 8px;       /* moins d'espace int\303\251rieur */\n"
"    background: white;\n"
"    color: #2c3e50;\n"
"    min-width: 100px;       /* largeur minimale plus petite */\n"
"    max-width: 150px;       /* facultatif : limite largeur */\n"
"    height: 24px;           /* hauteur plus petite */\n"
"}\n"
"\n"
"/* Drop-down (fl\303\250che) */\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;           /* r\303\251duit largeur fl\303\250che */\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"/* Hover et focus restent inchang\303\251s */\n"
"QComboBox:focus {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"       "
                        " stop:0 #ff4b1f, stop:1 #ffc837);\n"
"    box-shadow: 0 0 4px rgba(255, 107, 53, 0.6);\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 2px solid #43cea2;\n"
"    box-shadow: 0 0 4px rgba(67, 206, 162, 0.6);\n"
"}\n"
"\n"
"/* Menu d\303\251roulant */\n"
"QComboBox QAbstractItemView {\n"
"    background: white;\n"
"    border: 1px solid #43cea2;\n"
"    selection-background-color: #43cea2;\n"
"    selection-color: white;\n"
"}"));
        tabEmploye = new QTableView(Employe);
        tabEmploye->setObjectName("tabEmploye");
        tabEmploye->setGeometry(QRect(510, 140, 561, 231));
        posteEmploye = new QComboBox(Employe);
        posteEmploye->addItem(QString());
        posteEmploye->addItem(QString());
        posteEmploye->addItem(QString());
        posteEmploye->setObjectName("posteEmploye");
        posteEmploye->setGeometry(QRect(50, 330, 140, 31));
        posteEmploye->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
"QComboBox:focus {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #ff4b1f, stop:1 #ffc837);\n"
"    box-shadow: 0 0 4px rgba(255, 107, 53, 0.6);\n"
"}\n"
"\n"
"/* Hover */\n"
"QComboBox:hover {\n"
"    border: 2px solid #43cea2;\n"
"    box-shadow: 0 0 4px rgba(67, 206, 162, 0.6);\n"
"}\n"
"\n"
"/* Placeholder text */\n"
"QComboBox[placeholderText]:empty {\n"
"    color: #95a5a6;\n"
"}\n"
""));
        lab_statEmpl = new QLabel(Employe);
        lab_statEmpl->setObjectName("lab_statEmpl");
        lab_statEmpl->setGeometry(QRect(1130, 140, 351, 281));
        grp_ModifierEmpl = new QGroupBox(menu);
        grp_ModifierEmpl->setObjectName("grp_ModifierEmpl");
        grp_ModifierEmpl->setGeometry(QRect(320, 20, 611, 571));
        grp_ModifierEmpl->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        label_65 = new QLabel(grp_ModifierEmpl);
        label_65->setObjectName("label_65");
        label_65->setGeometry(QRect(60, 130, 71, 20));
        lineEdit_id_6 = new QLineEdit(grp_ModifierEmpl);
        lineEdit_id_6->setObjectName("lineEdit_id_6");
        lineEdit_id_6->setGeometry(QRect(60, 160, 141, 31));
        lineEdit_id_6->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_66 = new QLabel(grp_ModifierEmpl);
        label_66->setObjectName("label_66");
        label_66->setGeometry(QRect(290, 210, 63, 20));
        lineEdit_nom_6 = new QLineEdit(grp_ModifierEmpl);
        lineEdit_nom_6->setObjectName("lineEdit_nom_6");
        lineEdit_nom_6->setGeometry(QRect(290, 240, 140, 26));
        lineEdit_nom_6->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_67 = new QLabel(grp_ModifierEmpl);
        label_67->setObjectName("label_67");
        label_67->setGeometry(QRect(60, 210, 63, 20));
        lineEdit_prenom_6 = new QLineEdit(grp_ModifierEmpl);
        lineEdit_prenom_6->setObjectName("lineEdit_prenom_6");
        lineEdit_prenom_6->setGeometry(QRect(60, 240, 140, 26));
        lineEdit_prenom_6->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_68 = new QLabel(grp_ModifierEmpl);
        label_68->setObjectName("label_68");
        label_68->setGeometry(QRect(290, 280, 131, 20));
        label_69 = new QLabel(grp_ModifierEmpl);
        label_69->setObjectName("label_69");
        label_69->setGeometry(QRect(290, 130, 63, 20));
        lineEdit_email_6 = new QLineEdit(grp_ModifierEmpl);
        lineEdit_email_6->setObjectName("lineEdit_email_6");
        lineEdit_email_6->setGeometry(QRect(290, 160, 140, 26));
        lineEdit_email_6->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_70 = new QLabel(grp_ModifierEmpl);
        label_70->setObjectName("label_70");
        label_70->setGeometry(QRect(60, 280, 81, 21));
        lineEdit_telephone_6 = new QLineEdit(grp_ModifierEmpl);
        lineEdit_telephone_6->setObjectName("lineEdit_telephone_6");
        lineEdit_telephone_6->setGeometry(QRect(60, 310, 140, 26));
        lineEdit_telephone_6->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_71 = new QLabel(grp_ModifierEmpl);
        label_71->setObjectName("label_71");
        label_71->setGeometry(QRect(60, 350, 63, 20));
        lineEdit_poste_6 = new QLineEdit(grp_ModifierEmpl);
        lineEdit_poste_6->setObjectName("lineEdit_poste_6");
        lineEdit_poste_6->setGeometry(QRect(60, 380, 140, 26));
        lineEdit_poste_6->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_72 = new QLabel(grp_ModifierEmpl);
        label_72->setObjectName("label_72");
        label_72->setGeometry(QRect(290, 350, 81, 21));
        lineEdit_motdepasse_6 = new QLineEdit(grp_ModifierEmpl);
        lineEdit_motdepasse_6->setObjectName("lineEdit_motdepasse_6");
        lineEdit_motdepasse_6->setGeometry(QRect(290, 380, 140, 26));
        lineEdit_motdepasse_6->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_motdepasse_6->setEchoMode(QLineEdit::Normal);
        label_73 = new QLabel(grp_ModifierEmpl);
        label_73->setObjectName("label_73");
        label_73->setGeometry(QRect(230, -10, 201, 31));
        label_73->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #2c3e50;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    background: transparent;\n"
"    border: none;\n"
"    padding: 0px;\n"
"}"));
        retoure_modifierEmpl = new QPushButton(grp_ModifierEmpl);
        retoure_modifierEmpl->setObjectName("retoure_modifierEmpl");
        retoure_modifierEmpl->setGeometry(QRect(490, 60, 91, 41));
        retoure_modifierEmpl->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_confirmer = new QPushButton(grp_ModifierEmpl);
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
        pushButton_annuler_6 = new QPushButton(grp_ModifierEmpl);
        pushButton_annuler_6->setObjectName("pushButton_annuler_6");
        pushButton_annuler_6->setGeometry(QRect(80, 480, 101, 41));
        pushButton_annuler_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        dateEdit_naissance_6 = new QDateEdit(grp_ModifierEmpl);
        dateEdit_naissance_6->setObjectName("dateEdit_naissance_6");
        dateEdit_naissance_6->setGeometry(QRect(290, 310, 141, 31));
        dateEdit_naissance_6->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
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
        Bemploye->raise();
        Bvehicule->raise();
        Bapprenant->raise();
        Bmoniteurs->raise();
        Bpaiement->raise();
        Bexamens->raise();
        grp_ajoutEmpl->raise();
        pushButton->raise();
        grp_ModifierEmpl->raise();
        Employe->raise();
        grp_login = new QGroupBox(centralwidget);
        grp_login->setObjectName("grp_login");
        grp_login->setGeometry(QRect(320, 100, 400, 400));
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
        lineEdit_adresse->setGeometry(QRect(50, 130, 220, 31));
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
        lineEdit_motdepasse->setGeometry(QRect(50, 220, 220, 31));
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
        Employes->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Employes);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1892, 26));
        Employes->setMenuBar(menubar);
        statusbar = new QStatusBar(Employes);
        statusbar->setObjectName("statusbar");
        Employes->setStatusBar(statusbar);

        retranslateUi(Employes);

        QMetaObject::connectSlotsByName(Employes);
    } // setupUi

    void retranslateUi(QMainWindow *Employes)
    {
        Employes->setWindowTitle(QCoreApplication::translate("Employes", "Employes", nullptr));
        menu->setTitle(QString());
        Bemploye->setText(QCoreApplication::translate("Employes", "Employ\303\251s", nullptr));
        Bvehicule->setText(QCoreApplication::translate("Employes", "V\303\251hicule", nullptr));
        Bapprenant->setText(QCoreApplication::translate("Employes", "Apprenant", nullptr));
        Bmoniteurs->setText(QCoreApplication::translate("Employes", "Moniteur", nullptr));
        Bpaiement->setText(QCoreApplication::translate("Employes", "Paiement", nullptr));
        Bexamens->setText(QCoreApplication::translate("Employes", "examens", nullptr));
        grp_ajoutEmpl->setTitle(QString());
        label_47->setText(QCoreApplication::translate("Employes", "ID Employ\303\251", nullptr));
        idEmpl_ajout->setPlaceholderText(QCoreApplication::translate("Employes", "Entrez l'ID employ\303\251", nullptr));
        label_48->setText(QCoreApplication::translate("Employes", "Nom", nullptr));
        nomEmpl_ajout->setPlaceholderText(QCoreApplication::translate("Employes", "Entrez le nom", nullptr));
        label_49->setText(QCoreApplication::translate("Employes", "Pr\303\251nom", nullptr));
        prenomEmpl_ajput->setPlaceholderText(QCoreApplication::translate("Employes", "Entrez le pr\303\251nom", nullptr));
        label_51->setText(QCoreApplication::translate("Employes", "Email", nullptr));
        EmailEmpl_ajout->setPlaceholderText(QCoreApplication::translate("Employes", "exemple@email.com", nullptr));
        label_53->setText(QCoreApplication::translate("Employes", "Poste", nullptr));
        label_54->setText(QCoreApplication::translate("Employes", "Mot de passe", nullptr));
        mdpEmpl_ajout->setPlaceholderText(QCoreApplication::translate("Employes", "Mot de passe", nullptr));
        label_55->setText(QCoreApplication::translate("Employes", "Ajouter un Employ\303\251", nullptr));
        retour_AjoutEmpl->setText(QCoreApplication::translate("Employes", "Retour", nullptr));
        confirmer_AjoutEmpl->setText(QCoreApplication::translate("Employes", "Ajouter", nullptr));
        pushButton_annuler_5->setText(QCoreApplication::translate("Employes", "Annuler", nullptr));
        posteEmpl_ajout->setItemText(0, QCoreApplication::translate("Employes", "Agent", nullptr));
        posteEmpl_ajout->setItemText(1, QCoreApplication::translate("Employes", "Admin", nullptr));
        posteEmpl_ajout->setItemText(2, QCoreApplication::translate("Employes", "RH", nullptr));

        pushButton->setText(QString());
        Employe->setTitle(QString());
        label_56->setText(QCoreApplication::translate("Employes", "ID Employ\303\251", nullptr));
        idEmploye->setPlaceholderText(QCoreApplication::translate("Employes", "Entrez l'ID employ\303\251", nullptr));
        label_57->setText(QCoreApplication::translate("Employes", "Nom", nullptr));
        nomEmploye->setPlaceholderText(QCoreApplication::translate("Employes", "Entrez le nom", nullptr));
        label_58->setText(QCoreApplication::translate("Employes", "Pr\303\251nom", nullptr));
        prenomEmploye->setPlaceholderText(QCoreApplication::translate("Employes", "Entrez le pr\303\251nom", nullptr));
        label_60->setText(QCoreApplication::translate("Employes", "Email", nullptr));
        emailEmploye->setPlaceholderText(QCoreApplication::translate("Employes", "exemple@email.com", nullptr));
        label_62->setText(QCoreApplication::translate("Employes", "Poste", nullptr));
        label_63->setText(QCoreApplication::translate("Employes", "Mot de passe", nullptr));
        mdpEmploye->setPlaceholderText(QCoreApplication::translate("Employes", "Mot de passe", nullptr));
        label_64->setText(QCoreApplication::translate("Employes", "Gestion des Employ\303\251s", nullptr));
        retourEmpl->setText(QCoreApplication::translate("Employes", "Retour", nullptr));
        modifierEmpl->setText(QCoreApplication::translate("Employes", "Modifier", nullptr));
        supprimerEmploye->setText(QCoreApplication::translate("Employes", "Supprimer", nullptr));
        ajoutEmpl->setText(QCoreApplication::translate("Employes", "Ajouter", nullptr));
        btn_statEmpl->setText(QCoreApplication::translate("Employes", "Statistiques", nullptr));
        PDFempl->setText(QCoreApplication::translate("Employes", "Exporter PDF", nullptr));
        rechercheEmpl->setText(QCoreApplication::translate("Employes", "Recherche...", nullptr));
        trieEmpl->setItemText(0, QCoreApplication::translate("Employes", "nom", nullptr));
        trieEmpl->setItemText(1, QCoreApplication::translate("Employes", "prenom", nullptr));
        trieEmpl->setItemText(2, QCoreApplication::translate("Employes", "poste", nullptr));

        posteEmploye->setItemText(0, QCoreApplication::translate("Employes", "Agent", nullptr));
        posteEmploye->setItemText(1, QCoreApplication::translate("Employes", "Admin", nullptr));
        posteEmploye->setItemText(2, QCoreApplication::translate("Employes", "RH", nullptr));

        lab_statEmpl->setText(QString());
        grp_ModifierEmpl->setTitle(QString());
        label_65->setText(QCoreApplication::translate("Employes", "ID Employ\303\251", nullptr));
        lineEdit_id_6->setText(QCoreApplication::translate("Employes", "1512", nullptr));
        lineEdit_id_6->setPlaceholderText(QCoreApplication::translate("Employes", "Entrez l'ID employ\303\251", nullptr));
        label_66->setText(QCoreApplication::translate("Employes", "Nom", nullptr));
        lineEdit_nom_6->setText(QCoreApplication::translate("Employes", "lamouchi", nullptr));
        lineEdit_nom_6->setPlaceholderText(QCoreApplication::translate("Employes", "Entrez le nom", nullptr));
        label_67->setText(QCoreApplication::translate("Employes", "Pr\303\251nom", nullptr));
        lineEdit_prenom_6->setText(QCoreApplication::translate("Employes", "ghassen", nullptr));
        lineEdit_prenom_6->setPlaceholderText(QCoreApplication::translate("Employes", "Entrez le pr\303\251nom", nullptr));
        label_68->setText(QCoreApplication::translate("Employes", "Date de naissance", nullptr));
        label_69->setText(QCoreApplication::translate("Employes", "Email", nullptr));
        lineEdit_email_6->setText(QCoreApplication::translate("Employes", "lamouchighassen@gmail.com", nullptr));
        lineEdit_email_6->setPlaceholderText(QCoreApplication::translate("Employes", "exemple@email.com", nullptr));
        label_70->setText(QCoreApplication::translate("Employes", "T\303\251l\303\251phone", nullptr));
        lineEdit_telephone_6->setPlaceholderText(QCoreApplication::translate("Employes", "58 588 255", nullptr));
        label_71->setText(QCoreApplication::translate("Employes", "Poste", nullptr));
        lineEdit_poste_6->setText(QCoreApplication::translate("Employes", "Responsable", nullptr));
        lineEdit_poste_6->setPlaceholderText(QCoreApplication::translate("Employes", "Responsable", nullptr));
        label_72->setText(QCoreApplication::translate("Employes", "Mot de passe", nullptr));
        lineEdit_motdepasse_6->setText(QCoreApplication::translate("Employes", "**************", nullptr));
        lineEdit_motdepasse_6->setPlaceholderText(QCoreApplication::translate("Employes", "Mot de passe", nullptr));
        label_73->setText(QCoreApplication::translate("Employes", "Modifier un Employ\303\251", nullptr));
        retoure_modifierEmpl->setText(QCoreApplication::translate("Employes", "Retour", nullptr));
        pushButton_confirmer->setText(QCoreApplication::translate("Employes", "Confirmer", nullptr));
        pushButton_annuler_6->setText(QCoreApplication::translate("Employes", "Annuler", nullptr));
        grp_login->setTitle(QString());
        label_titre->setText(QCoreApplication::translate("Employes", "Connexion", nullptr));
        label_adresse->setText(QCoreApplication::translate("Employes", "Adresse", nullptr));
        lineEdit_adresse->setPlaceholderText(QCoreApplication::translate("Employes", "Entrez votre adresse", nullptr));
        label_motdepasse->setText(QCoreApplication::translate("Employes", "Mot de passe", nullptr));
        lineEdit_motdepasse->setPlaceholderText(QCoreApplication::translate("Employes", "Entrez votre mot de passe", nullptr));
        btn_connexion->setText(QCoreApplication::translate("Employes", "Connexion", nullptr));
        btn_motdepasse_oublie->setText(QCoreApplication::translate("Employes", "Mot de passe oubli\303\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Employes: public Ui_Employes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYES_H
