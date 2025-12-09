/********************************************************************************
** Form generated from reading UI file 'examens.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMENS_H
#define UI_EXAMENS_H

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

class Ui_examens
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *Connexion;
    QPushButton *pushButton;
    QLabel *label_7;
    QLineEdit *lineEdit_email;
    QPushButton *pushButton_login;
    QLineEdit *lineEdit_password;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *Vehicule;
    QWidget *formGroup;
    QLabel *label_immatriculation;
    QLineEdit *lineEdit_immatriculation;
    QLabel *label_21;
    QLineEdit *lineEdit_marque;
    QLabel *label_22;
    QComboBox *comboBox_type_2;
    QLabel *label_23;
    QLineEdit *lineEdit_kilometrage;
    QLabel *label_24;
    QComboBox *comboBox_etat;
    QLabel *label_disponibilite;
    QComboBox *comboBox_disponibilite;
    QLabel *label_capacite;
    QLineEdit *lineEdit_capacite;
    QPushButton *Retour_2;
    QLabel *label_25;
    QPushButton *pushButton_reco_window;
    QTableView *tableView;
    QPushButton *pushButton_4;
    QWidget *actionGroup;
    QPushButton *pushButton_ajouter_3;
    QPushButton *pushButton_modifier_3;
    QPushButton *pushButton_supprimer_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QWidget *searchGroup;
    QLabel *label_26;
    QLineEdit *lineEdit_3;
    QWidget *statsContainer;
    QPushButton *pushButton_sms_alert;
    QWidget *Menu;
    QPushButton *pushButton_examens;
    QPushButton *Bvehicule;
    QLabel *label_12;
    QPushButton *pushButton_5;
    QPushButton *Bapprenant;
    QPushButton *Bpaiement;
    QPushButton *Bmoniteurs;
    QPushButton *pushButton_8;
    QWidget *Gestion_des_examens;
    QTableView *tableView_examens;
    QPushButton *exporterPDF;
    QComboBox *comboBox_vehicule;
    QPushButton *pushButton_stats;
    QLabel *label;
    QPushButton *pushButton_ajouter;
    QLabel *label_4;
    QComboBox *comboBox_type;
    QLineEdit *lineEdit_rechercheType;
    QTimeEdit *timeEdit_heure;
    QLabel *label_8;
    QComboBox *comboBox_triDate;
    QComboBox *comboBox_resultat;
    QLineEdit *lineEdit_lieu;
    QLabel *label_9;
    QLineEdit *lineEdit_id;
    QLabel *label_2;
    QLabel *label_3;
    QDateEdit *dateEdit_date;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_retour;
    QPushButton *pushButton_planifier;
    QPushButton *pushButton_supprimer;
    QPushButton *pushButton_modifier;
    QPushButton *pushButton_9;
    QPushButton *pushButton_rappel;
    QWidget *page;
    QPushButton *pushButton_ajouter_2;
    QPushButton *pushButton_statistique;
    QLabel *label_13;
    QLabel *label_14;
    QTableView *tableView_apprenants;
    QLineEdit *lineEdit_telephone;
    QLabel *label_15;
    QPushButton *pushButton_trier;
    QPushButton *Retour;
    QLineEdit *lineEdit_prenom;
    QLabel *label_16;
    QLineEdit *lineEdit_adresse;
    QLabel *label_17;
    QDateEdit *dateEdit_naissance;
    QLabel *label_18;
    QLineEdit *lineEdit_id_2;
    QPushButton *pushButton_supprimer_2;
    QLineEdit *lineEdit_recherche;
    QLabel *label_19;
    QPushButton *pushButton_modifier_2;
    QLineEdit *lineEdit_nom;
    QPushButton *pushButton_exporterPDF;
    QLabel *label_20;
    QComboBox *comboBox_sexe;
    QLabel *label_message;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *examens)
    {
        if (examens->objectName().isEmpty())
            examens->setObjectName("examens");
        examens->resize(1396, 795);
        examens->setAutoFillBackground(false);
        examens->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(examens);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1361, 751));
        stackedWidget->setStyleSheet(QString::fromUtf8("background: qlineargradient(\n"
"    x1: 0, y1: 0, x2: 0, y2: 1,\n"
"    stop: 0   rgba(200, 225, 255, 255),   /* Bleu clair professionnel */\n"
"    stop: 0.5 rgba(255, 255, 255, 255),   /* Blanc central */\n"
"    stop: 1   rgba(210, 245, 230, 255)    /* Vert p\303\242le rassurant */\n"
");\n"
""));
        Connexion = new QWidget();
        Connexion->setObjectName("Connexion");
        pushButton = new QPushButton(Connexion);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 620, 1361, 51));
        pushButton->setStyleSheet(QString::fromUtf8("  background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 102, 204, 255), stop: 0.5 rgba(144, 238, 144, 255), stop: 1 rgba(0, 51, 102, 255));\n"
"    border: 2px solid rgba(144, 238, 144, 200);\n"
"    padding: 8px;\n"
"    color: rgba(0, 51, 102, 255);\n"
"    font-weight: bold;\n"
"    border-radius: 10px;\n"
"    transition: all 0.3s ease;"));
        label_7 = new QLabel(Connexion);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(-10, -20, 811, 671));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/logo /logo.png")));
        label_7->setScaledContents(true);
        lineEdit_email = new QLineEdit(Connexion);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(860, 240, 301, 41));
        lineEdit_email->setStyleSheet(QString::fromUtf8(" background-color: rgba(255, 255, 255, 255);\n"
"    border: 2px solid rgba(144, 238, 144, 200);\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    color: rgba(0, 51, 102, 255);"));
        pushButton_login = new QPushButton(Connexion);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setGeometry(QRect(860, 430, 301, 41));
        pushButton_login->setStyleSheet(QString::fromUtf8("  background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 102, 204, 255), stop: 0.5 rgba(144, 238, 144, 255), stop: 1 rgba(0, 51, 102, 255));\n"
"    border: 2px solid rgba(144, 238, 144, 200);\n"
"    padding: 8px;\n"
"    color: rgba(0, 51, 102, 255);\n"
"    font-weight: bold;\n"
"    border-radius: 10px;\n"
"    transition: all 0.3s ease;"));
        lineEdit_password = new QLineEdit(Connexion);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(860, 350, 301, 41));
        lineEdit_password->setStyleSheet(QString::fromUtf8(" background-color: rgba(255, 255, 255, 255);\n"
"    border: 2px solid rgba(144, 238, 144, 200);\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    color: rgba(0, 51, 102, 255);\n"
""));
        label_10 = new QLabel(Connexion);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(860, 190, 81, 31));
        label_11 = new QLabel(Connexion);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(860, 310, 121, 31));
        stackedWidget->addWidget(Connexion);
        label_7->raise();
        lineEdit_email->raise();
        pushButton_login->raise();
        lineEdit_password->raise();
        label_10->raise();
        label_11->raise();
        pushButton->raise();
        Vehicule = new QWidget();
        Vehicule->setObjectName("Vehicule");
        formGroup = new QWidget(Vehicule);
        formGroup->setObjectName("formGroup");
        formGroup->setGeometry(QRect(10, 50, 230, 441));
        label_immatriculation = new QLabel(formGroup);
        label_immatriculation->setObjectName("label_immatriculation");
        label_immatriculation->setGeometry(QRect(0, 0, 101, 21));
        lineEdit_immatriculation = new QLineEdit(formGroup);
        lineEdit_immatriculation->setObjectName("lineEdit_immatriculation");
        lineEdit_immatriculation->setGeometry(QRect(0, 20, 220, 31));
        lineEdit_immatriculation->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"        stop:0 #ff4b1f, stop:1 #ffc837);\n"
"}"));
        label_21 = new QLabel(formGroup);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(0, 60, 61, 21));
        lineEdit_marque = new QLineEdit(formGroup);
        lineEdit_marque->setObjectName("lineEdit_marque");
        lineEdit_marque->setGeometry(QRect(0, 80, 220, 31));
        lineEdit_marque->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"        stop:0 #ff4b1f, stop:1 #ffc837);\n"
"}"));
        label_22 = new QLabel(formGroup);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(0, 120, 49, 16));
        comboBox_type_2 = new QComboBox(formGroup);
        comboBox_type_2->setObjectName("comboBox_type_2");
        comboBox_type_2->setGeometry(QRect(0, 140, 220, 31));
        comboBox_type_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43cea2, stop:1 #185a9d);\n"
"    border-radius: 10px;\n"
"    padding: 4px 8px;\n"
"    background: white;\n"
"    color: #2c3e50;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #ff4b1f, stop:1 #ffc837);\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 2px solid #43cea2;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background: white;\n"
"    border: 1px solid #43cea2;\n"
"    selection-background-color: #43cea2;\n"
"    selection-color: white;\n"
"}"));
        label_23 = new QLabel(formGroup);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(0, 180, 101, 21));
        lineEdit_kilometrage = new QLineEdit(formGroup);
        lineEdit_kilometrage->setObjectName("lineEdit_kilometrage");
        lineEdit_kilometrage->setGeometry(QRect(0, 200, 220, 31));
        lineEdit_kilometrage->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"        stop:0 #ff4b1f, stop:1 #ffc837);\n"
"}"));
        label_24 = new QLabel(formGroup);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(0, 240, 61, 31));
        comboBox_etat = new QComboBox(formGroup);
        comboBox_etat->setObjectName("comboBox_etat");
        comboBox_etat->setGeometry(QRect(0, 270, 220, 31));
        comboBox_etat->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43cea2, stop:1 #185a9d);\n"
"    border-radius: 10px;\n"
"    padding: 4px 8px;\n"
"    background: white;\n"
"    color: #2c3e50;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #ff4b1f, stop:1 #ffc837);\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 2px solid #43cea2;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background: white;\n"
"    border: 1px solid #43cea2;\n"
"    selection-background-color: #43cea2;\n"
"    selection-color: white;\n"
"}"));
        label_disponibilite = new QLabel(formGroup);
        label_disponibilite->setObjectName("label_disponibilite");
        label_disponibilite->setGeometry(QRect(0, 310, 101, 21));
        comboBox_disponibilite = new QComboBox(formGroup);
        comboBox_disponibilite->setObjectName("comboBox_disponibilite");
        comboBox_disponibilite->setGeometry(QRect(0, 330, 220, 31));
        comboBox_disponibilite->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43cea2, stop:1 #185a9d);\n"
"    border-radius: 10px;\n"
"    padding: 4px 8px;\n"
"    background: white;\n"
"    color: #2c3e50;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #ff4b1f, stop:1 #ffc837);\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 2px solid #43cea2;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background: white;\n"
"    border: 1px solid #43cea2;\n"
"    selection-background-color: #43cea2;\n"
"    selection-color: white;\n"
"}"));
        label_capacite = new QLabel(formGroup);
        label_capacite->setObjectName("label_capacite");
        label_capacite->setGeometry(QRect(0, 370, 101, 21));
        lineEdit_capacite = new QLineEdit(formGroup);
        lineEdit_capacite->setObjectName("lineEdit_capacite");
        lineEdit_capacite->setGeometry(QRect(0, 390, 220, 31));
        lineEdit_capacite->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"        stop:0 #ff4b1f, stop:1 #ffc837);\n"
"}"));
        Retour_2 = new QPushButton(Vehicule);
        Retour_2->setObjectName("Retour_2");
        Retour_2->setGeometry(QRect(790, 10, 91, 41));
        Retour_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"        stop:0 #ff0000,\n"
"        stop:0.5 #cc0000,\n"
"        stop:1 #990000\n"
"    );\n"
"    border: 1px solid #800000;\n"
"    color: white;\n"
"}"));
        label_25 = new QLabel(Vehicule);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(250, 10, 400, 51));
        label_25->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"    font-size: 18px;\n"
"}"));
        label_25->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_reco_window = new QPushButton(Vehicule);
        pushButton_reco_window->setObjectName("pushButton_reco_window");
        pushButton_reco_window->setGeometry(QRect(140, 680, 230, 41));
        pushButton_reco_window->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #8e44ad,\n"
"        stop:1 #6c3483\n"
"    );\n"
"    color: white;\n"
"    border-radius: 12px;\n"
"    padding: 10px 22px;\n"
"    font-weight: bold;\n"
"    border: 1px solid #512e5f;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #9b59b6,\n"
"        stop:1 #7d3c98\n"
"    );\n"
"    border: 1px solid #7d3c98;\n"
"}"));
        tableView = new QTableView(Vehicule);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(250, 70, 591, 301));
        tableView->setMinimumSize(QSize(521, 0));
        tableView->setStyleSheet(QString::fromUtf8("QTableWidget, QTableView {\n"
"    background-color: white;\n"
"    border: 2px solid #43cea2;\n"
"    border-radius: 12px;\n"
"    gridline-color: #dcdcdc;\n"
"    selection-background-color: #43cea2;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43cea2,\n"
"        stop:1 #185a9d);\n"
"    color: white;\n"
"    padding: 4px;\n"
"    border: 1px solid #144d7e;\n"
"    border-radius: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 4px;\n"
"    border-bottom: 1px solid #eaeaea;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: rgba(67, 206, 162, 0.1);\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #43cea2;\n"
"    color: white;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: #f0f0f0;\n"
"    width: 12px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #43ce"
                        "a2;\n"
"    min-height: 20px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}"));
        pushButton_4 = new QPushButton(Vehicule);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(250, 540, 151, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"        stop:0 #ff4e50,\n"
"        stop:0.5 #fc913a,\n"
"        stop:1 #f9d423\n"
"    );\n"
"    border: 1px solid #e04b3f;\n"
"}"));
        actionGroup = new QWidget(Vehicule);
        actionGroup->setObjectName("actionGroup");
        actionGroup->setGeometry(QRect(10, 480, 230, 120));
        pushButton_ajouter_3 = new QPushButton(actionGroup);
        pushButton_ajouter_3->setObjectName("pushButton_ajouter_3");
        pushButton_ajouter_3->setGeometry(QRect(0, 10, 110, 41));
        pushButton_ajouter_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"        stop:0 #ff4e50,\n"
"        stop:0.5 #fc913a,\n"
"        stop:1 #f9d423\n"
"    );\n"
"    border: 1px solid #e04b3f;\n"
"}"));
        pushButton_modifier_3 = new QPushButton(actionGroup);
        pushButton_modifier_3->setObjectName("pushButton_modifier_3");
        pushButton_modifier_3->setGeometry(QRect(120, 10, 110, 41));
        pushButton_modifier_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"        stop:0 #ff4e50,\n"
"        stop:0.5 #fc913a,\n"
"        stop:1 #f9d423\n"
"    );\n"
"    border: 1px solid #e04b3f;\n"
"}"));
        pushButton_supprimer_3 = new QPushButton(actionGroup);
        pushButton_supprimer_3->setObjectName("pushButton_supprimer_3");
        pushButton_supprimer_3->setGeometry(QRect(0, 60, 110, 41));
        pushButton_supprimer_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"        stop:0 #ff4e50,\n"
"        stop:0.5 #fc913a,\n"
"        stop:1 #f9d423\n"
"    );\n"
"    border: 1px solid #e04b3f;\n"
"}"));
        pushButton_6 = new QPushButton(actionGroup);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(120, 60, 110, 41));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"        stop:0 #ff4e50,\n"
"        stop:0.5 #fc913a,\n"
"        stop:1 #f9d423\n"
"    );\n"
"    border: 1px solid #e04b3f;\n"
"}"));
        pushButton_7 = new QPushButton(Vehicule);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(260, 490, 131, 41));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"        stop:0 #ff4e50,\n"
"        stop:0.5 #fc913a,\n"
"        stop:1 #f9d423\n"
"    );\n"
"    border: 1px solid #e04b3f;\n"
"}"));
        searchGroup = new QWidget(Vehicule);
        searchGroup->setObjectName("searchGroup");
        searchGroup->setGeometry(QRect(220, 380, 630, 60));
        label_26 = new QLabel(searchGroup);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(0, 10, 81, 21));
        lineEdit_3 = new QLineEdit(searchGroup);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(90, 10, 521, 31));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"        stop:0 #ff4b1f, stop:1 #ffc837);\n"
"}"));
        statsContainer = new QWidget(Vehicule);
        statsContainer->setObjectName("statsContainer");
        statsContainer->setGeometry(QRect(760, 390, 451, 301));
        statsContainer->setStyleSheet(QString::fromUtf8("QWidget#statsContainer { border: 0px; background: transparent; }"));
        pushButton_sms_alert = new QPushButton(Vehicule);
        pushButton_sms_alert->setObjectName("pushButton_sms_alert");
        pushButton_sms_alert->setGeometry(QRect(420, 540, 231, 41));
        pushButton_sms_alert->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #e74c3c,\n"
"        stop:1 #c0392b\n"
"    );\n"
"    color: white;\n"
"    border-radius: 12px;\n"
"    padding: 10px 22px;\n"
"    font-weight: bold;\n"
"    border: 1px solid #922b21;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #ff6b6b,\n"
"        stop:1 #ff3b3b\n"
"    );\n"
"    border: 1px solid #b03a2e;\n"
"}"));
        stackedWidget->addWidget(Vehicule);
        Menu = new QWidget();
        Menu->setObjectName("Menu");
        pushButton_examens = new QPushButton(Menu);
        pushButton_examens->setObjectName("pushButton_examens");
        pushButton_examens->setGeometry(QRect(0, 320, 111, 101));
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
        Bvehicule = new QPushButton(Menu);
        Bvehicule->setObjectName("Bvehicule");
        Bvehicule->setGeometry(QRect(0, 220, 111, 101));
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
        label_12 = new QLabel(Menu);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(110, -180, 1261, 991));
        label_12->setStyleSheet(QString::fromUtf8("image: url(:/Downloads/554337631_1437269814008871_8043664467412301076_n.png);"));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/logo /logo.png")));
        label_12->setScaledContents(true);
        pushButton_5 = new QPushButton(Menu);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(0, 420, 111, 111));
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
        Bapprenant = new QPushButton(Menu);
        Bapprenant->setObjectName("Bapprenant");
        Bapprenant->setGeometry(QRect(0, 10, 111, 111));
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
        Bpaiement = new QPushButton(Menu);
        Bpaiement->setObjectName("Bpaiement");
        Bpaiement->setGeometry(QRect(0, 530, 111, 101));
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
        Bmoniteurs = new QPushButton(Menu);
        Bmoniteurs->setObjectName("Bmoniteurs");
        Bmoniteurs->setGeometry(QRect(0, 120, 111, 101));
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
        pushButton_8 = new QPushButton(Menu);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(0, 630, 1361, 51));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"}"));
        stackedWidget->addWidget(Menu);
        label_12->raise();
        pushButton_5->raise();
        Bapprenant->raise();
        Bpaiement->raise();
        Bmoniteurs->raise();
        pushButton_8->raise();
        pushButton_examens->raise();
        Bvehicule->raise();
        Gestion_des_examens = new QWidget();
        Gestion_des_examens->setObjectName("Gestion_des_examens");
        tableView_examens = new QTableView(Gestion_des_examens);
        tableView_examens->setObjectName("tableView_examens");
        tableView_examens->setGeometry(QRect(670, 110, 641, 311));
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
        exporterPDF = new QPushButton(Gestion_des_examens);
        exporterPDF->setObjectName("exporterPDF");
        exporterPDF->setGeometry(QRect(1120, 520, 181, 41));
        exporterPDF->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        comboBox_vehicule = new QComboBox(Gestion_des_examens);
        comboBox_vehicule->addItem(QString());
        comboBox_vehicule->addItem(QString());
        comboBox_vehicule->setObjectName("comboBox_vehicule");
        comboBox_vehicule->setGeometry(QRect(150, 420, 170, 41));
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
        pushButton_stats = new QPushButton(Gestion_des_examens);
        pushButton_stats->setObjectName("pushButton_stats");
        pushButton_stats->setGeometry(QRect(930, 520, 171, 41));
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
        label = new QLabel(Gestion_des_examens);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 110, 61, 21));
        pushButton_ajouter = new QPushButton(Gestion_des_examens);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(290, 470, 101, 41));
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_4 = new QLabel(Gestion_des_examens);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(150, 310, 49, 16));
        comboBox_type = new QComboBox(Gestion_des_examens);
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->setObjectName("comboBox_type");
        comboBox_type->setGeometry(QRect(150, 250, 161, 41));
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
        lineEdit_rechercheType = new QLineEdit(Gestion_des_examens);
        lineEdit_rechercheType->setObjectName("lineEdit_rechercheType");
        lineEdit_rechercheType->setGeometry(QRect(670, 430, 551, 31));
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
        timeEdit_heure = new QTimeEdit(Gestion_des_examens);
        timeEdit_heure->setObjectName("timeEdit_heure");
        timeEdit_heure->setGeometry(QRect(150, 340, 170, 41));
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
        label_8 = new QLabel(Gestion_des_examens);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(160, 390, 61, 16));
        label_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"}\n"
""));
        comboBox_triDate = new QComboBox(Gestion_des_examens);
        comboBox_triDate->addItem(QString());
        comboBox_triDate->addItem(QString());
        comboBox_triDate->addItem(QString());
        comboBox_triDate->setObjectName("comboBox_triDate");
        comboBox_triDate->setGeometry(QRect(1230, 430, 91, 31));
        comboBox_triDate->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43cea2, stop:1 #185a9d);\n"
"    border-radius: 10px;    /* un peu moins arrondi si tu veux */\n"
"    padding: 4px 8px;       /* moins d'espace int\303\251rieur */\n"
"    background: white;\n"
"    color: #2c3e50;\n"
"   \n"
" \n"
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
"        stop:0 #ff4b1f, stop:1 #ffc837);\n"
"    box-shadow: 0 0 4px rgba(255, 107, 53, 0.6);\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 2px solid #43cea2;\n"
"    box-shadow: 0 "
                        "0 4px rgba(67, 206, 162, 0.6);\n"
"}\n"
"\n"
"/* Menu d\303\251roulant */\n"
"QComboBox QAbstractItemView {\n"
"    background: white;\n"
"    border: 1px solid #43cea2;\n"
"    selection-background-color: #43cea2;\n"
"    selection-color: white;\n"
"}"));
        comboBox_resultat = new QComboBox(Gestion_des_examens);
        comboBox_resultat->addItem(QString());
        comboBox_resultat->addItem(QString());
        comboBox_resultat->addItem(QString());
        comboBox_resultat->setObjectName("comboBox_resultat");
        comboBox_resultat->setGeometry(QRect(360, 420, 170, 41));
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
        lineEdit_lieu = new QLineEdit(Gestion_des_examens);
        lineEdit_lieu->setObjectName("lineEdit_lieu");
        lineEdit_lieu->setGeometry(QRect(360, 340, 171, 41));
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
        label_9 = new QLabel(Gestion_des_examens);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(360, 390, 51, 20));
        label_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"}"));
        lineEdit_id = new QLineEdit(Gestion_des_examens);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(150, 150, 371, 41));
        lineEdit_id->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_2 = new QLabel(Gestion_des_examens);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(150, 220, 49, 16));
        label_3 = new QLabel(Gestion_des_examens);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(370, 220, 49, 16));
        dateEdit_date = new QDateEdit(Gestion_des_examens);
        dateEdit_date->setObjectName("dateEdit_date");
        dateEdit_date->setGeometry(QRect(360, 250, 181, 41));
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
        label_5 = new QLabel(Gestion_des_examens);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(370, 310, 49, 16));
        label_6 = new QLabel(Gestion_des_examens);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 0, 141, 111));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/logo /logo.png")));
        label_6->setScaledContents(true);
        pushButton_retour = new QPushButton(Gestion_des_examens);
        pushButton_retour->setObjectName("pushButton_retour");
        pushButton_retour->setGeometry(QRect(1220, 40, 91, 41));
        pushButton_retour->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_planifier = new QPushButton(Gestion_des_examens);
        pushButton_planifier->setObjectName("pushButton_planifier");
        pushButton_planifier->setGeometry(QRect(290, 570, 101, 41));
        pushButton_planifier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_supprimer = new QPushButton(Gestion_des_examens);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(400, 520, 111, 41));
        pushButton_supprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_modifier = new QPushButton(Gestion_des_examens);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(170, 520, 111, 41));
        pushButton_modifier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_9 = new QPushButton(Gestion_des_examens);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(0, 630, 1361, 51));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"}"));
        pushButton_rappel = new QPushButton(Gestion_des_examens);
        pushButton_rappel->setObjectName("pushButton_rappel");
        pushButton_rappel->setGeometry(QRect(290, 520, 101, 41));
        pushButton_rappel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        stackedWidget->addWidget(Gestion_des_examens);
        page = new QWidget();
        page->setObjectName("page");
        pushButton_ajouter_2 = new QPushButton(page);
        pushButton_ajouter_2->setObjectName("pushButton_ajouter_2");
        pushButton_ajouter_2->setGeometry(QRect(70, 560, 131, 51));
        pushButton_ajouter_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_statistique = new QPushButton(page);
        pushButton_statistique->setObjectName("pushButton_statistique");
        pushButton_statistique->setGeometry(QRect(990, 560, 151, 51));
        pushButton_statistique->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_13 = new QLabel(page);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(80, 310, 131, 31));
        label_14 = new QLabel(page);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(170, 140, 131, 31));
        label_14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        tableView_apprenants->setGeometry(QRect(590, 140, 681, 301));
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
        lineEdit_telephone = new QLineEdit(page);
        lineEdit_telephone->setObjectName("lineEdit_telephone");
        lineEdit_telephone->setGeometry(QRect(80, 450, 171, 31));
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
        label_15 = new QLabel(page);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(320, 220, 71, 31));
        pushButton_trier = new QPushButton(page);
        pushButton_trier->setObjectName("pushButton_trier");
        pushButton_trier->setGeometry(QRect(1130, 460, 131, 41));
        pushButton_trier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Retour = new QPushButton(page);
        Retour->setObjectName("Retour");
        Retour->setGeometry(QRect(1220, 10, 111, 51));
        Retour->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEdit_prenom = new QLineEdit(page);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(320, 260, 171, 31));
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
        label_16 = new QLabel(page);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(470, 40, 381, 71));
        label_16->setStyleSheet(QString::fromUtf8(""));
        lineEdit_adresse = new QLineEdit(page);
        lineEdit_adresse->setObjectName("lineEdit_adresse");
        lineEdit_adresse->setGeometry(QRect(320, 450, 171, 31));
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
        label_17 = new QLabel(page);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(80, 220, 91, 31));
        dateEdit_naissance = new QDateEdit(page);
        dateEdit_naissance->setObjectName("dateEdit_naissance");
        dateEdit_naissance->setGeometry(QRect(80, 350, 170, 41));
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
        label_18 = new QLabel(page);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(330, 310, 71, 31));
        lineEdit_id_2 = new QLineEdit(page);
        lineEdit_id_2->setObjectName("lineEdit_id_2");
        lineEdit_id_2->setGeometry(QRect(170, 180, 220, 31));
        lineEdit_id_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        pushButton_supprimer_2 = new QPushButton(page);
        pushButton_supprimer_2->setObjectName("pushButton_supprimer_2");
        pushButton_supprimer_2->setGeometry(QRect(290, 560, 131, 51));
        pushButton_supprimer_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEdit_recherche = new QLineEdit(page);
        lineEdit_recherche->setObjectName("lineEdit_recherche");
        lineEdit_recherche->setGeometry(QRect(600, 460, 491, 41));
        lineEdit_recherche->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_19 = new QLabel(page);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(80, 410, 81, 31));
        pushButton_modifier_2 = new QPushButton(page);
        pushButton_modifier_2->setObjectName("pushButton_modifier_2");
        pushButton_modifier_2->setGeometry(QRect(490, 560, 131, 51));
        pushButton_modifier_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEdit_nom = new QLineEdit(page);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(80, 260, 171, 31));
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
        pushButton_exporterPDF = new QPushButton(page);
        pushButton_exporterPDF->setObjectName("pushButton_exporterPDF");
        pushButton_exporterPDF->setGeometry(QRect(710, 560, 191, 51));
        pushButton_exporterPDF->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_20 = new QLabel(page);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(320, 410, 81, 31));
        comboBox_sexe = new QComboBox(page);
        comboBox_sexe->addItem(QString());
        comboBox_sexe->addItem(QString());
        comboBox_sexe->setObjectName("comboBox_sexe");
        comboBox_sexe->setGeometry(QRect(320, 350, 170, 31));
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
        stackedWidget->addWidget(page);
        label_message = new QLabel(centralwidget);
        label_message->setObjectName("label_message");
        label_message->setGeometry(QRect(330, 640, 480, 36));
        label_message->setStyleSheet(QString::fromUtf8("color: #c62828;\n"
"font-weight: bold;"));
        label_message->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_message->setWordWrap(true);
        examens->setCentralWidget(centralwidget);
        menubar = new QMenuBar(examens);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1396, 22));
        examens->setMenuBar(menubar);
        statusbar = new QStatusBar(examens);
        statusbar->setObjectName("statusbar");
        examens->setStatusBar(statusbar);

        retranslateUi(examens);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(examens);
    } // setupUi

    void retranslateUi(QMainWindow *examens)
    {
        examens->setWindowTitle(QCoreApplication::translate("examens", "examens", nullptr));
        pushButton->setText(QString());
        label_7->setText(QString());
        pushButton_login->setText(QCoreApplication::translate("examens", "connexion", nullptr));
        label_10->setText(QCoreApplication::translate("examens", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#000063;\">Email :</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("examens", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#00005b;\">Mot de passe :</span></p></body></html>", nullptr));
        label_immatriculation->setText(QCoreApplication::translate("examens", "Immatriculation :", nullptr));
        label_21->setText(QCoreApplication::translate("examens", "Marque :", nullptr));
        label_22->setText(QCoreApplication::translate("examens", "Type :", nullptr));
        label_23->setText(QCoreApplication::translate("examens", "Kilom\303\251trage :", nullptr));
        label_24->setText(QCoreApplication::translate("examens", "\303\211tat :", nullptr));
        label_disponibilite->setText(QCoreApplication::translate("examens", "Disponibilit\303\251 :", nullptr));
        label_capacite->setText(QCoreApplication::translate("examens", "Capacit\303\251 :", nullptr));
        Retour_2->setText(QCoreApplication::translate("examens", "Retour", nullptr));
        label_25->setText(QCoreApplication::translate("examens", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:700; font-style:italic; text-decoration: underline; color:#037f7b;\">Gestion des V\303\251hicules</span></p></body></html>", nullptr));
        pushButton_reco_window->setText(QCoreApplication::translate("examens", "Recommandation IA", nullptr));
        pushButton_4->setText(QCoreApplication::translate("examens", "Exporter en PDF", nullptr));
        pushButton_ajouter_3->setText(QCoreApplication::translate("examens", "Ajouter", nullptr));
        pushButton_modifier_3->setText(QCoreApplication::translate("examens", "Modifier", nullptr));
        pushButton_supprimer_3->setText(QCoreApplication::translate("examens", "Supprimer", nullptr));
        pushButton_6->setText(QCoreApplication::translate("examens", "Statistiques", nullptr));
        pushButton_7->setText(QCoreApplication::translate("examens", "Tri", nullptr));
        label_26->setText(QCoreApplication::translate("examens", "Recherche :", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("examens", "Recherche par marque...", nullptr));
        pushButton_sms_alert->setText(QCoreApplication::translate("examens", "Alerte Diagnostic SMS", nullptr));
        pushButton_examens->setText(QCoreApplication::translate("examens", "examens", nullptr));
        Bvehicule->setText(QCoreApplication::translate("examens", "V\303\251hicule", nullptr));
        label_12->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("examens", "Employ\303\251s", nullptr));
        Bapprenant->setText(QCoreApplication::translate("examens", "Apprenant", nullptr));
        Bpaiement->setText(QCoreApplication::translate("examens", "Paiement", nullptr));
        Bmoniteurs->setText(QCoreApplication::translate("examens", "Moniteur", nullptr));
        pushButton_8->setText(QString());
#if QT_CONFIG(tooltip)
        tableView_examens->setToolTip(QCoreApplication::translate("examens", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        exporterPDF->setText(QCoreApplication::translate("examens", "Exporter PDF", nullptr));
        comboBox_vehicule->setItemText(0, QCoreApplication::translate("examens", "A", nullptr));
        comboBox_vehicule->setItemText(1, QCoreApplication::translate("examens", "B", nullptr));

        pushButton_stats->setText(QCoreApplication::translate("examens", "Statistiques", nullptr));
        label->setText(QCoreApplication::translate("examens", "ID Exemen :", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("examens", "Ajouter", nullptr));
        label_4->setText(QCoreApplication::translate("examens", "Heure :", nullptr));
        comboBox_type->setItemText(0, QCoreApplication::translate("examens", "Code", nullptr));
        comboBox_type->setItemText(1, QCoreApplication::translate("examens", "Circuit", nullptr));
        comboBox_type->setItemText(2, QCoreApplication::translate("examens", "Parking", nullptr));

        lineEdit_rechercheType->setText(QString());
        label_8->setText(QCoreApplication::translate("examens", "V\303\251hicule :", nullptr));
        comboBox_triDate->setItemText(0, QCoreApplication::translate("examens", "Tri", nullptr));
        comboBox_triDate->setItemText(1, QCoreApplication::translate("examens", "Croissant", nullptr));
        comboBox_triDate->setItemText(2, QCoreApplication::translate("examens", "D\303\251croissant", nullptr));

#if QT_CONFIG(tooltip)
        comboBox_triDate->setToolTip(QCoreApplication::translate("examens", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        comboBox_resultat->setItemText(0, QCoreApplication::translate("examens", "Admis", nullptr));
        comboBox_resultat->setItemText(1, QCoreApplication::translate("examens", "En attente", nullptr));
        comboBox_resultat->setItemText(2, QCoreApplication::translate("examens", "Refuse", nullptr));

        lineEdit_lieu->setText(QString());
        label_9->setText(QCoreApplication::translate("examens", "R\303\251sultat :", nullptr));
        label_2->setText(QCoreApplication::translate("examens", "Type :", nullptr));
        label_3->setText(QCoreApplication::translate("examens", "Date :", nullptr));
        label_5->setText(QCoreApplication::translate("examens", "Lieu :", nullptr));
        label_6->setText(QString());
        pushButton_retour->setText(QCoreApplication::translate("examens", "Retour", nullptr));
        pushButton_planifier->setText(QCoreApplication::translate("examens", "planifier", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("examens", "Supprimer", nullptr));
        pushButton_modifier->setText(QCoreApplication::translate("examens", "Modifier", nullptr));
        pushButton_9->setText(QString());
        pushButton_rappel->setText(QCoreApplication::translate("examens", "Rappel ", nullptr));
        pushButton_ajouter_2->setText(QCoreApplication::translate("examens", "Ajouter", nullptr));
        pushButton_statistique->setText(QCoreApplication::translate("examens", "Statistique", nullptr));
        label_13->setText(QCoreApplication::translate("examens", "Date de naissance", nullptr));
        label_14->setText(QCoreApplication::translate("examens", "ID Apprenant", nullptr));
        label_15->setText(QCoreApplication::translate("examens", "Pr\303\251nom", nullptr));
        pushButton_trier->setText(QCoreApplication::translate("examens", "Tri", nullptr));
        Retour->setText(QCoreApplication::translate("examens", "Retour", nullptr));
        label_16->setText(QCoreApplication::translate("examens", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:700; font-style:italic; color:#037f7b;\">      </span><span style=\" font-size:16pt; font-weight:700; font-style:italic; text-decoration: underline; color:#037f7b;\">Gestion des Apprenants</span></p></body></html>", nullptr));
        label_17->setText(QCoreApplication::translate("examens", "Nom", nullptr));
        label_18->setText(QCoreApplication::translate("examens", "Sexe", nullptr));
        pushButton_supprimer_2->setText(QCoreApplication::translate("examens", "Supprimer", nullptr));
        lineEdit_recherche->setText(QCoreApplication::translate("examens", "Recherche...", nullptr));
        label_19->setText(QCoreApplication::translate("examens", "T\303\251l\303\251phone", nullptr));
        pushButton_modifier_2->setText(QCoreApplication::translate("examens", "Modifier", nullptr));
        pushButton_exporterPDF->setText(QCoreApplication::translate("examens", "Exporter PDF", nullptr));
        label_20->setText(QCoreApplication::translate("examens", "Adresse", nullptr));
        comboBox_sexe->setItemText(0, QCoreApplication::translate("examens", "Homme", nullptr));
        comboBox_sexe->setItemText(1, QCoreApplication::translate("examens", "Femme", nullptr));

        label_message->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class examens: public Ui_examens {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMENS_H
