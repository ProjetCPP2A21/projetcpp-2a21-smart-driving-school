/********************************************************************************
** Form generated from reading UI file 'application_integree.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATION_INTEGREE_H
#define UI_APPLICATION_INTEGREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_application_integree
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *pagelogin;
    QPushButton *pushButton;
    QLabel *label_7;
    QLineEdit *lineEdit_email;
    QPushButton *pushButton_login;
    QLineEdit *lineEdit_password;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *page_menu;
    QPushButton *pushButton_apprenants;
    QPushButton *pushButton_examens;
    QPushButton *pushButton_4;
    QPushButton *Bvehicule;
    QLabel *label_12;
    QPushButton *pushButton_5;
    QPushButton *Bapprenant;
    QPushButton *Bpaiement;
    QPushButton *Bmoniteurs;
    QWidget *pageexamen;
    QTableView *tableView_examens;
    QPushButton *exporterPDF_examen;
    QComboBox *comboBox_vehicule;
    QPushButton *pushButton_stats;
    QLabel *label;
    QPushButton *pushButton_ajouter_examen;
    QPushButton *pushButton_modifier_examen;
    QLabel *label_4;
    QPushButton *pushButton_supprimer_examen;
    QComboBox *comboBox_type;
    QLineEdit *lineEdit_rechercheType;
    QTimeEdit *timeEdit_heure;
    QLabel *label_8;
    QComboBox *comboBox_triDate;
    QComboBox *comboBox_resultat;
    QLineEdit *lineEdit_lieu;
    QLabel *label_9;
    QLineEdit *lineEdit_id_examen;
    QLabel *label_2;
    QLabel *label_3;
    QDateEdit *dateEdit_date;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_retour_examens;
    QPushButton *pushButton_7;
    QWidget *page;
    QDateEdit *dateEdit_naissance;
    QLabel *label_13;
    QLabel *label_14;
    QPushButton *pushButton_retour_apprenants;
    QLabel *label_15;
    QLineEdit *lineEdit_recherche_apprenant;
    QPushButton *pushButton_ajouter_apprenant;
    QPushButton *pushButton_supprimer_apprenant;
    QPushButton *pushButton_trier_apprenant;
    QTableView *tableView_apprenants;
    QLabel *label_16;
    QPushButton *pushButton_statistique_apprenant;
    QLabel *label_17;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_adresse;
    QPushButton *pushButton_modifier_apprenant;
    QLineEdit *lineEdit_telephone;
    QLabel *label_18;
    QComboBox *comboBox_sexe;
    QLabel *label_19;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_prenom;
    QLabel *label_20;
    QPushButton *pushButton_exporterPDF_apprenant;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *application_integree)
    {
        if (application_integree->objectName().isEmpty())
            application_integree->setObjectName("application_integree");
        application_integree->resize(941, 596);
        application_integree->setAutoFillBackground(false);
        application_integree->setStyleSheet(QString::fromUtf8("\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #f5f7fa,\n"
"        stop:1 #c3cfe2\n"
"    );\n"
"\n"
""));
        centralwidget = new QWidget(application_integree);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 941, 621));
        pagelogin = new QWidget();
        pagelogin->setObjectName("pagelogin");
        pushButton = new QPushButton(pagelogin);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 510, 911, 51));
        pushButton->setStyleSheet(QString::fromUtf8("  background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 102, 204, 255), stop: 0.5 rgba(144, 238, 144, 255), stop: 1 rgba(0, 51, 102, 255));\n"
"    border: 2px solid rgba(144, 238, 144, 200);\n"
"    padding: 8px;\n"
"    color: rgba(0, 51, 102, 255);\n"
"    font-weight: bold;\n"
"    border-radius: 10px;\n"
"    transition: all 0.3s ease;"));
        label_7 = new QLabel(pagelogin);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 80, 431, 401));
        label_7->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/554337631_1437269814008871_8043664467412301076_n.png")));
        label_7->setScaledContents(true);
        lineEdit_email = new QLineEdit(pagelogin);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(490, 180, 301, 31));
        lineEdit_email->setStyleSheet(QString::fromUtf8(" background-color: rgba(255, 255, 255, 255);\n"
"    border: 2px solid rgba(144, 238, 144, 200);\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    color: rgba(0, 51, 102, 255);"));
        pushButton_login = new QPushButton(pagelogin);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setGeometry(QRect(490, 330, 301, 41));
        pushButton_login->setStyleSheet(QString::fromUtf8("  background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 102, 204, 255), stop: 0.5 rgba(144, 238, 144, 255), stop: 1 rgba(0, 51, 102, 255));\n"
"    border: 2px solid rgba(144, 238, 144, 200);\n"
"    padding: 8px;\n"
"    color: rgba(0, 51, 102, 255);\n"
"    font-weight: bold;\n"
"    border-radius: 10px;\n"
"    transition: all 0.3s ease;"));
        lineEdit_password = new QLineEdit(pagelogin);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(490, 270, 301, 31));
        lineEdit_password->setStyleSheet(QString::fromUtf8(" background-color: rgba(255, 255, 255, 255);\n"
"    border: 2px solid rgba(144, 238, 144, 200);\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    color: rgba(0, 51, 102, 255);\n"
""));
        label_10 = new QLabel(pagelogin);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(500, 145, 81, 31));
        label_11 = new QLabel(pagelogin);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(490, 230, 121, 31));
        stackedWidget->addWidget(pagelogin);
        page_menu = new QWidget();
        page_menu->setObjectName("page_menu");
        pushButton_apprenants = new QPushButton(page_menu);
        pushButton_apprenants->setObjectName("pushButton_apprenants");
        pushButton_apprenants->setGeometry(QRect(0, 200, 111, 81));
        pushButton_apprenants->setStyleSheet(QString::fromUtf8("\n"
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
        pushButton_examens = new QPushButton(page_menu);
        pushButton_examens->setObjectName("pushButton_examens");
        pushButton_examens->setGeometry(QRect(0, 270, 111, 81));
        pushButton_examens->setStyleSheet(QString::fromUtf8("\n"
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
        pushButton_4 = new QPushButton(page_menu);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(0, 520, 921, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"}"));
        Bvehicule = new QPushButton(page_menu);
        Bvehicule->setObjectName("Bvehicule");
        Bvehicule->setGeometry(QRect(0, 200, 111, 71));
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
        label_12 = new QLabel(page_menu);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(110, -20, 801, 541));
        label_12->setStyleSheet(QString::fromUtf8("image: url(:/Downloads/554337631_1437269814008871_8043664467412301076_n.png);"));
        pushButton_5 = new QPushButton(page_menu);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(0, 350, 111, 81));
        pushButton_5->setStyleSheet(QString::fromUtf8("\n"
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
        Bapprenant = new QPushButton(page_menu);
        Bapprenant->setObjectName("Bapprenant");
        Bapprenant->setGeometry(QRect(0, 40, 111, 81));
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
        Bpaiement = new QPushButton(page_menu);
        Bpaiement->setObjectName("Bpaiement");
        Bpaiement->setGeometry(QRect(0, 430, 111, 91));
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
        Bmoniteurs = new QPushButton(page_menu);
        Bmoniteurs->setObjectName("Bmoniteurs");
        Bmoniteurs->setGeometry(QRect(0, 120, 111, 81));
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
        stackedWidget->addWidget(page_menu);
        pageexamen = new QWidget();
        pageexamen->setObjectName("pageexamen");
        tableView_examens = new QTableView(pageexamen);
        tableView_examens->setObjectName("tableView_examens");
        tableView_examens->setGeometry(QRect(370, 117, 501, 221));
        tableView_examens->setStyleSheet(QString::fromUtf8("/* Style global du tableau */\n"
"QTableWidget, QTableView {\n"
"    background-color: white;          /* fond neutre */\n"
"    border: 2px solid #43cea2;        /* contour vert-bleu */\n"
"    border-radius: 12px;\n"
"    gridline-color: #dcdcdc;          /* lignes discr\303\250tes */\n"
"    selection-background-color: #43cea2;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"/* En-t\303\252tes horizontaux */\n"
"QHeaderView::section {\n"
"    background: white;                /* fond neutre */\n"
"    color: #2c3e50;                   /* texte gris fonc\303\251 */\n"
"    padding: 4px;\n"
"    border: 1px solid #43cea2;        /* contour vert-bleu */\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"/* Lignes de cellule */\n"
"QTableWidget::item {\n"
"    padding: 4px;\n"
"    border-bottom: 1px solid #eaeaea; /* lignes grises claires */\n"
"}\n"
"\n"
"/* Lignes au survol */\n"
"QTableWidget::item:hover {\n"
"    background-color: rgba(67, 206, 162, 0.1); /* l\303\251ger voile vert */\n"
"}\n"
"\n"
"/* Lignes s\303"
                        "\251lectionn\303\251es */\n"
"QTableWidget::item:selected {\n"
"    background-color: #43cea2;        /* vert-bleu */\n"
"    color: white;\n"
"}\n"
"\n"
"/* Scrollbars sobres */\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: #f0f0f0;\n"
"    width: 12px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #43cea2;              /* juste la poign\303\251e color\303\251e */\n"
"    min-height: 20px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-"));
        exporterPDF_examen = new QPushButton(pageexamen);
        exporterPDF_examen->setObjectName("exporterPDF_examen");
        exporterPDF_examen->setGeometry(QRect(600, 417, 121, 41));
        exporterPDF_examen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        comboBox_vehicule = new QComboBox(pageexamen);
        comboBox_vehicule->addItem(QString());
        comboBox_vehicule->addItem(QString());
        comboBox_vehicule->setObjectName("comboBox_vehicule");
        comboBox_vehicule->setGeometry(QRect(50, 327, 120, 31));
        comboBox_vehicule->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        pushButton_stats = new QPushButton(pageexamen);
        pushButton_stats->setObjectName("pushButton_stats");
        pushButton_stats->setGeometry(QRect(740, 417, 131, 41));
        pushButton_stats->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label = new QLabel(pageexamen);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 107, 61, 21));
        pushButton_ajouter_examen = new QPushButton(pageexamen);
        pushButton_ajouter_examen->setObjectName("pushButton_ajouter_examen");
        pushButton_ajouter_examen->setGeometry(QRect(110, 387, 91, 41));
        pushButton_ajouter_examen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_modifier_examen = new QPushButton(pageexamen);
        pushButton_modifier_examen->setObjectName("pushButton_modifier_examen");
        pushButton_modifier_examen->setGeometry(QRect(30, 437, 101, 41));
        pushButton_modifier_examen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_4 = new QLabel(pageexamen);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 237, 49, 16));
        pushButton_supprimer_examen = new QPushButton(pageexamen);
        pushButton_supprimer_examen->setObjectName("pushButton_supprimer_examen");
        pushButton_supprimer_examen->setGeometry(QRect(190, 437, 111, 41));
        pushButton_supprimer_examen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        comboBox_type = new QComboBox(pageexamen);
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->setObjectName("comboBox_type");
        comboBox_type->setGeometry(QRect(50, 197, 120, 31));
        comboBox_type->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        lineEdit_rechercheType = new QLineEdit(pageexamen);
        lineEdit_rechercheType->setObjectName("lineEdit_rechercheType");
        lineEdit_rechercheType->setGeometry(QRect(370, 347, 421, 31));
        lineEdit_rechercheType->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        timeEdit_heure = new QTimeEdit(pageexamen);
        timeEdit_heure->setObjectName("timeEdit_heure");
        timeEdit_heure->setGeometry(QRect(50, 257, 120, 31));
        timeEdit_heure->setStyleSheet(QString::fromUtf8("QTimeEdit {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43cea2, stop:1 #185a9d);\n"
"    border-radius: 10px;\n"
"    padding: 4px 8px;\n"
"    background: white;\n"
"    color: #2c3e50;\n"
"    min-width: 100px;\n"
"    max-width: 150px;\n"
"    height: 24px;\n"
"    selection-background-color: #43cea2; /* couleur quand on s\303\251lectionne une partie de l'heure */\n"
"    selection-color: white;\n"
"}\n"
"\n"
"/* Boutons d\342\200\231incr\303\251mentation/d\303\251cr\303\251mentation */\n"
"QTimeEdit::up-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: top right;\n"
"    width: 16px;\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QTimeEdit::down-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: bottom right;\n"
"    width: 16px;\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QTimeEdit::up-arrow, QTimeEdit::down-arrow {\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"\n"
""
                        "/* Focus */\n"
"QTimeEdit:focus {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #ff4b1f, stop:1 #ffc837);\n"
"    /* \342\232\240\357\270\217 box-shadow n\342\200\231est pas support\303\251 par Qt StyleSheets */\n"
"}\n"
"\n"
"/* Hover */\n"
"QTimeEdit:hover {\n"
"    border: 2px solid #43cea2;\n"
"}"));
        label_8 = new QLabel(pageexamen);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 307, 61, 16));
        label_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"}\n"
""));
        comboBox_triDate = new QComboBox(pageexamen);
        comboBox_triDate->addItem(QString());
        comboBox_triDate->addItem(QString());
        comboBox_triDate->addItem(QString());
        comboBox_triDate->setObjectName("comboBox_triDate");
        comboBox_triDate->setGeometry(QRect(800, 347, 61, 31));
        comboBox_triDate->setStyleSheet(QString::fromUtf8(""));
        comboBox_resultat = new QComboBox(pageexamen);
        comboBox_resultat->addItem(QString());
        comboBox_resultat->addItem(QString());
        comboBox_resultat->setObjectName("comboBox_resultat");
        comboBox_resultat->setGeometry(QRect(190, 327, 120, 31));
        comboBox_resultat->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        lineEdit_lieu = new QLineEdit(pageexamen);
        lineEdit_lieu->setObjectName("lineEdit_lieu");
        lineEdit_lieu->setGeometry(QRect(190, 257, 121, 31));
        lineEdit_lieu->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_9 = new QLabel(pageexamen);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(190, 307, 51, 20));
        label_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"}"));
        lineEdit_id_examen = new QLineEdit(pageexamen);
        lineEdit_id_examen->setObjectName("lineEdit_id_examen");
        lineEdit_id_examen->setGeometry(QRect(50, 137, 201, 31));
        lineEdit_id_examen->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_2 = new QLabel(pageexamen);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 177, 49, 16));
        label_3 = new QLabel(pageexamen);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(190, 177, 49, 16));
        dateEdit_date = new QDateEdit(pageexamen);
        dateEdit_date->setObjectName("dateEdit_date");
        dateEdit_date->setGeometry(QRect(190, 197, 121, 31));
        dateEdit_date->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
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
        label_5 = new QLabel(pageexamen);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(190, 237, 49, 16));
        label_6 = new QLabel(pageexamen);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 0, 91, 81));
        label_6->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/logo.png")));
        label_6->setScaledContents(true);
        pushButton_retour_examens = new QPushButton(pageexamen);
        pushButton_retour_examens->setObjectName("pushButton_retour_examens");
        pushButton_retour_examens->setGeometry(QRect(770, 40, 91, 41));
        pushButton_retour_examens->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_7 = new QPushButton(pageexamen);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(0, 500, 921, 41));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"}"));
        stackedWidget->addWidget(pageexamen);
        page = new QWidget();
        page->setObjectName("page");
        dateEdit_naissance = new QDateEdit(page);
        dateEdit_naissance->setObjectName("dateEdit_naissance");
        dateEdit_naissance->setGeometry(QRect(10, 290, 140, 41));
        dateEdit_naissance->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43cea2, stop:1 #185a9d);\n"
"    border-radius: 10px;\n"
"    padding: 4px 8px;\n"
"    background: white;\n"
"    color: #2c3e50;\n"
"    min-width: 120px;\n"
"    max-width: 150px;\n"
"    height: 24px;\n"
"}\n"
"\n"
"/* Bouton pour ouvrir le calendrier */\n"
"QDateEdit::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"\n"
"/* Fl\303\250che du calendrier */\n"
"QDateEdit::down-arrow {\n"
"    image: url(:/icons/calendar-white.png);\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"/* Focus */\n"
"QDateEdit:focus {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #ff4b1f, stop:1 #ffc837);\n"
"    box-shadow: 0 0 4px rgba(255, 107, 53, 0.6);\n"
"}\n"
"\n"
"/* Hover */\n"
"QDateEdit:hover {\n"
"    border: 2px solid #43cea2;\n"
"    box-shadow: 0 0 "
                        "4px rgba(67, 206, 162, 0.6);\n"
"}\n"
"\n"
"/* Menu du calendrier */\n"
"QCalendarWidget QWidget {\n"
"    background-color: white;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton {\n"
"    background-color: #43cea2;\n"
"    color: white;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QCalendarWidget QSpinBox {\n"
"    width: 60px;\n"
"}\n"
""));
        label_13 = new QLabel(page);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(20, 350, 81, 21));
        label_14 = new QLabel(page);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(170, 360, 63, 20));
        pushButton_retour_apprenants = new QPushButton(page);
        pushButton_retour_apprenants->setObjectName("pushButton_retour_apprenants");
        pushButton_retour_apprenants->setGeometry(QRect(800, 10, 101, 41));
        pushButton_retour_apprenants->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}\n"
""));
        label_15 = new QLabel(page);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 140, 101, 16));
        label_15->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEdit_recherche_apprenant = new QLineEdit(page);
        lineEdit_recherche_apprenant->setObjectName("lineEdit_recherche_apprenant");
        lineEdit_recherche_apprenant->setGeometry(QRect(330, 400, 451, 31));
        lineEdit_recherche_apprenant->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43cea2, stop:1 #185a9d);\n"
"    border-radius: 10px;\n"
"    padding: 4px 8px;\n"
"    background: white;\n"
"    color: #2c3e50;\n"
"    min-width: 120px;\n"
"    max-width: 500px;\n"
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
"    color: #95a5a6;  /* gris clair pour le placeholder */\n"
"}\n"
""));
        pushButton_ajouter_apprenant = new QPushButton(page);
        pushButton_ajouter_apprenant->setObjectName("pushButton_ajouter_apprenant");
        pushButton_ajouter_apprenant->setGeometry(QRect(10, 500, 121, 41));
        pushButton_ajouter_apprenant->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_supprimer_apprenant = new QPushButton(page);
        pushButton_supprimer_apprenant->setObjectName("pushButton_supprimer_apprenant");
        pushButton_supprimer_apprenant->setGeometry(QRect(180, 500, 121, 41));
        pushButton_supprimer_apprenant->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_trier_apprenant = new QPushButton(page);
        pushButton_trier_apprenant->setObjectName("pushButton_trier_apprenant");
        pushButton_trier_apprenant->setGeometry(QRect(790, 400, 121, 41));
        pushButton_trier_apprenant->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        tableView_apprenants = new QTableView(page);
        tableView_apprenants->setObjectName("tableView_apprenants");
        tableView_apprenants->setGeometry(QRect(340, 110, 581, 271));
        tableView_apprenants->setMinimumSize(QSize(521, 0));
        tableView_apprenants->setStyleSheet(QString::fromUtf8("/* Style global du tableau */\n"
"QTableWidget, QTableView {\n"
"    background-color: white;          /* fond neutre */\n"
"    border: 2px solid #43cea2;        /* contour vert-bleu */\n"
"    border-radius: 12px;\n"
"    gridline-color: #dcdcdc;          /* lignes discr\303\250tes */\n"
"    selection-background-color: #43cea2;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"/* En-t\303\252tes horizontaux */\n"
"QHeaderView::section {\n"
"    background: white;                /* fond neutre */\n"
"    color: #2c3e50;                   /* texte gris fonc\303\251 */\n"
"    padding: 4px;\n"
"    border: 1px solid #43cea2;        /* contour vert-bleu */\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"/* Lignes de cellule */\n"
"QTableWidget::item {\n"
"    padding: 4px;\n"
"    border-bottom: 1px solid #eaeaea; /* lignes grises claires */\n"
"}\n"
"\n"
"/* Lignes au survol */\n"
"QTableWidget::item:hover {\n"
"    background-color: rgba(67, 206, 162, 0.1); /* l\303\251ger voile vert */\n"
"}\n"
"\n"
"/* Lignes s\303"
                        "\251lectionn\303\251es */\n"
"QTableWidget::item:selected {\n"
"    background-color: #43cea2;        /* vert-bleu */\n"
"    color: white;\n"
"}\n"
"\n"
"/* Scrollbars sobres */\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: #f0f0f0;\n"
"    width: 12px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #43cea2;              /* juste la poign\303\251e color\303\251e */\n"
"    min-height: 20px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-"));
        label_16 = new QLabel(page);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(170, 200, 63, 20));
        pushButton_statistique_apprenant = new QPushButton(page);
        pushButton_statistique_apprenant->setObjectName("pushButton_statistique_apprenant");
        pushButton_statistique_apprenant->setGeometry(QRect(750, 500, 131, 41));
        pushButton_statistique_apprenant->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_17 = new QLabel(page);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(290, 40, 321, 41));
        label_17->setStyleSheet(QString::fromUtf8(""));
        lineEdit_id = new QLineEdit(page);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(10, 160, 220, 31));
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
"    color: #95a5a6;  /* gris clair pour le placeholder */\n"
"}\n"
""));
        lineEdit_adresse = new QLineEdit(page);
        lineEdit_adresse->setObjectName("lineEdit_adresse");
        lineEdit_adresse->setGeometry(QRect(170, 380, 140, 26));
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
"    color: #95a5a6;  /* gris clair pour le placeholder */\n"
"}\n"
""));
        pushButton_modifier_apprenant = new QPushButton(page);
        pushButton_modifier_apprenant->setObjectName("pushButton_modifier_apprenant");
        pushButton_modifier_apprenant->setGeometry(QRect(360, 500, 111, 41));
        pushButton_modifier_apprenant->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEdit_telephone = new QLineEdit(page);
        lineEdit_telephone->setObjectName("lineEdit_telephone");
        lineEdit_telephone->setGeometry(QRect(10, 380, 140, 26));
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
"    color: #95a5a6;  /* gris clair pour le placeholder */\n"
"}\n"
""));
        label_18 = new QLabel(page);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(10, 200, 63, 20));
        comboBox_sexe = new QComboBox(page);
        comboBox_sexe->addItem(QString());
        comboBox_sexe->addItem(QString());
        comboBox_sexe->setObjectName("comboBox_sexe");
        comboBox_sexe->setGeometry(QRect(170, 290, 141, 31));
        comboBox_sexe->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
"}\n"
""));
        label_19 = new QLabel(page);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(10, 260, 131, 21));
        lineEdit_nom = new QLineEdit(page);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(10, 220, 140, 26));
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
"    color: #95a5a6;  /* gris clair pour le placeholder */\n"
"}\n"
""));
        lineEdit_prenom = new QLineEdit(page);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(170, 220, 140, 26));
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
"    color: #95a5a6;  /* gris clair pour le placeholder */\n"
"}\n"
""));
        label_20 = new QLabel(page);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(170, 270, 63, 20));
        pushButton_exporterPDF_apprenant = new QPushButton(page);
        pushButton_exporterPDF_apprenant->setObjectName("pushButton_exporterPDF_apprenant");
        pushButton_exporterPDF_apprenant->setGeometry(QRect(520, 500, 161, 41));
        pushButton_exporterPDF_apprenant->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        stackedWidget->addWidget(page);
        application_integree->setCentralWidget(centralwidget);
        menubar = new QMenuBar(application_integree);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 941, 26));
        application_integree->setMenuBar(menubar);
        statusbar = new QStatusBar(application_integree);
        statusbar->setObjectName("statusbar");
        application_integree->setStatusBar(statusbar);

        retranslateUi(application_integree);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(application_integree);
    } // setupUi

    void retranslateUi(QMainWindow *application_integree)
    {
        application_integree->setWindowTitle(QCoreApplication::translate("application_integree", "Application Int\303\251gr\303\251e - Apprenants et Examens", nullptr));
        pushButton->setText(QString());
        label_7->setText(QString());
        pushButton_login->setText(QCoreApplication::translate("application_integree", "connexion", nullptr));
        label_10->setText(QCoreApplication::translate("application_integree", "Email :", nullptr));
        label_11->setText(QCoreApplication::translate("application_integree", "Mot de passe :", nullptr));
        pushButton_apprenants->setText(QCoreApplication::translate("application_integree", "Apprenants", nullptr));
        pushButton_examens->setText(QCoreApplication::translate("application_integree", "Examens", nullptr));
        pushButton_4->setText(QString());
        Bvehicule->setText(QCoreApplication::translate("application_integree", "V\303\251hicule", nullptr));
        label_12->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("application_integree", "Employ\303\251s", nullptr));
        Bapprenant->setText(QCoreApplication::translate("application_integree", "Apprenant", nullptr));
        Bpaiement->setText(QCoreApplication::translate("application_integree", "Paiement", nullptr));
        Bmoniteurs->setText(QCoreApplication::translate("application_integree", "Moniteur", nullptr));
#if QT_CONFIG(tooltip)
        tableView_examens->setToolTip(QCoreApplication::translate("application_integree", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        exporterPDF_examen->setText(QCoreApplication::translate("application_integree", "Exporter PDF", nullptr));
        comboBox_vehicule->setItemText(0, QCoreApplication::translate("application_integree", "A", nullptr));
        comboBox_vehicule->setItemText(1, QCoreApplication::translate("application_integree", "B", nullptr));

        pushButton_stats->setText(QCoreApplication::translate("application_integree", "Statistiques", nullptr));
        label->setText(QCoreApplication::translate("application_integree", "ID Exemen :", nullptr));
        pushButton_ajouter_examen->setText(QCoreApplication::translate("application_integree", "Ajouter", nullptr));
        pushButton_modifier_examen->setText(QCoreApplication::translate("application_integree", "Modifier", nullptr));
        label_4->setText(QCoreApplication::translate("application_integree", "Heure :", nullptr));
        pushButton_supprimer_examen->setText(QCoreApplication::translate("application_integree", "Supprimer", nullptr));
        comboBox_type->setItemText(0, QCoreApplication::translate("application_integree", "Code", nullptr));
        comboBox_type->setItemText(1, QCoreApplication::translate("application_integree", "Circuit", nullptr));
        comboBox_type->setItemText(2, QCoreApplication::translate("application_integree", "Parking", nullptr));

        lineEdit_rechercheType->setText(QString());
        label_8->setText(QCoreApplication::translate("application_integree", "V\303\251hicule :", nullptr));
        comboBox_triDate->setItemText(0, QCoreApplication::translate("application_integree", "Tri", nullptr));
        comboBox_triDate->setItemText(1, QCoreApplication::translate("application_integree", "Croissant", nullptr));
        comboBox_triDate->setItemText(2, QCoreApplication::translate("application_integree", "D\303\251croissant", nullptr));

#if QT_CONFIG(tooltip)
        comboBox_triDate->setToolTip(QCoreApplication::translate("application_integree", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        comboBox_resultat->setItemText(0, QCoreApplication::translate("application_integree", "Admis", nullptr));
        comboBox_resultat->setItemText(1, QCoreApplication::translate("application_integree", "\303\251chou\303\251", nullptr));

        lineEdit_lieu->setText(QString());
        label_9->setText(QCoreApplication::translate("application_integree", "R\303\251sultat :", nullptr));
        label_2->setText(QCoreApplication::translate("application_integree", "Type :", nullptr));
        label_3->setText(QCoreApplication::translate("application_integree", "Date :", nullptr));
        label_5->setText(QCoreApplication::translate("application_integree", "Lieu :", nullptr));
        label_6->setText(QString());
        pushButton_retour_examens->setText(QCoreApplication::translate("application_integree", "Retour", nullptr));
        pushButton_7->setText(QString());
        label_13->setText(QCoreApplication::translate("application_integree", "T\303\251l\303\251phone", nullptr));
        label_14->setText(QCoreApplication::translate("application_integree", "Adresse", nullptr));
        pushButton_retour_apprenants->setText(QCoreApplication::translate("application_integree", "Retour", nullptr));
        label_15->setText(QCoreApplication::translate("application_integree", "ID Apprenant", nullptr));
        lineEdit_recherche_apprenant->setText(QCoreApplication::translate("application_integree", "Recherche...", nullptr));
        pushButton_ajouter_apprenant->setText(QCoreApplication::translate("application_integree", "Ajouter", nullptr));
        pushButton_supprimer_apprenant->setText(QCoreApplication::translate("application_integree", "Supprimer", nullptr));
        pushButton_trier_apprenant->setText(QCoreApplication::translate("application_integree", "Tri", nullptr));
        label_16->setText(QCoreApplication::translate("application_integree", "Pr\303\251nom", nullptr));
        pushButton_statistique_apprenant->setText(QCoreApplication::translate("application_integree", "Statistique", nullptr));
        label_17->setText(QCoreApplication::translate("application_integree", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:700; font-style:italic; text-decoration: underline; color:#037f7b;\">Gestion des Apprenants</span></p></body></html>", nullptr));
        pushButton_modifier_apprenant->setText(QCoreApplication::translate("application_integree", "Modifier", nullptr));
        label_18->setText(QCoreApplication::translate("application_integree", "Nom", nullptr));
        comboBox_sexe->setItemText(0, QCoreApplication::translate("application_integree", "Homme", nullptr));
        comboBox_sexe->setItemText(1, QCoreApplication::translate("application_integree", "Femme", nullptr));

        label_19->setText(QCoreApplication::translate("application_integree", "Date de naissance", nullptr));
        label_20->setText(QCoreApplication::translate("application_integree", "Sexe", nullptr));
        pushButton_exporterPDF_apprenant->setText(QCoreApplication::translate("application_integree", "Exporter PDF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class application_integree: public Ui_application_integree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATION_INTEGREE_H
