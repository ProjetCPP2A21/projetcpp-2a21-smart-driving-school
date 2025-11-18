/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tabView;
    QPushButton *supprimer;
    QPushButton *selection;
    QPushButton *tri;
    QPushButton *modifier;
    QPushButton *exporter;
    QPushButton *ajouter;
    QPushButton *statistique;
    QLineEdit *lineEdit_3;
    QLineEdit *ID;
    QDateEdit *Date;
    QPushButton *Retour;
    QLabel *label;
    QLabel *label_2;
    QComboBox *Type;
    QTimeEdit *heure;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_10;
    QLabel *label_7;
    QLineEdit *montant;
    QLabel *label_8;
    QLabel *label_6;
    QLineEdit *montant_2;
    QComboBox *Type_2;
    QLabel *label_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1224, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget#centralwidget {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #f5f7fa,\n"
"        stop:1 #c3cfe2\n"
"    );\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabView = new QTableView(centralwidget);
        tabView->setObjectName("tabView");
        tabView->setGeometry(QRect(610, 140, 521, 241));
        tabView->setStyleSheet(QString::fromUtf8("/* Style global du tableau */\n"
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
"    borde"
                        "r-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-\n"
""));
        supprimer = new QPushButton(centralwidget);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(80, 470, 121, 41));
        supprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        selection = new QPushButton(centralwidget);
        selection->setObjectName("selection");
        selection->setGeometry(QRect(850, 470, 171, 41));
        selection->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        tri = new QPushButton(centralwidget);
        tri->setObjectName("tri");
        tri->setGeometry(QRect(750, 470, 81, 41));
        tri->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        modifier = new QPushButton(centralwidget);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(340, 470, 111, 41));
        modifier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        exporter = new QPushButton(centralwidget);
        exporter->setObjectName("exporter");
        exporter->setGeometry(QRect(470, 470, 141, 41));
        exporter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        ajouter = new QPushButton(centralwidget);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(220, 470, 101, 41));
        ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        statistique = new QPushButton(centralwidget);
        statistique->setObjectName("statistique");
        statistique->setGeometry(QRect(630, 470, 111, 41));
        statistique->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(600, 101, 520, 31));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}"));
        ID = new QLineEdit(centralwidget);
        ID->setObjectName("ID");
        ID->setGeometry(QRect(260, 180, 201, 31));
        ID->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}"));
        Date = new QDateEdit(centralwidget);
        Date->setObjectName("Date");
        Date->setGeometry(QRect(390, 240, 140, 31));
        Date->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
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
"}"));
        Retour = new QPushButton(centralwidget);
        Retour->setObjectName("Retour");
        Retour->setGeometry(QRect(1084, 13, 101, 41));
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
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(270, 150, 101, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(230, 220, 49, 16));
        Type = new QComboBox(centralwidget);
        Type->addItem(QString());
        Type->addItem(QString());
        Type->addItem(QString());
        Type->addItem(QString());
        Type->setObjectName("Type");
        Type->setGeometry(QRect(230, 240, 120, 31));
        Type->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        heure = new QTimeEdit(centralwidget);
        heure->setObjectName("heure");
        heure->setGeometry(QRect(230, 300, 120, 31));
        heure->setStyleSheet(QString::fromUtf8("QTimeEdit {\n"
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
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(390, 220, 49, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(230, 280, 49, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(390, 280, 49, 16));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(480, 40, 291, 51));
        label_10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"}"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(390, 290, 91, 20));
        montant = new QLineEdit(centralwidget);
        montant->setObjectName("montant");
        montant->setGeometry(QRect(390, 310, 140, 31));
        montant->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(30, 10, 171, 101));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/554337631_1437269814008871_8043664467412301076_n.png")));
        label_8->setScaledContents(true);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(390, 350, 49, 16));
        montant_2 = new QLineEdit(centralwidget);
        montant_2->setObjectName("montant_2");
        montant_2->setGeometry(QRect(390, 370, 140, 31));
        montant_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}"));
        Type_2 = new QComboBox(centralwidget);
        Type_2->addItem(QString());
        Type_2->addItem(QString());
        Type_2->addItem(QString());
        Type_2->setObjectName("Type_2");
        Type_2->setGeometry(QRect(230, 370, 120, 31));
        Type_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(230, 350, 49, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1224, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        selection->setText(QCoreApplication::translate("MainWindow", "selection", nullptr));
        tri->setText(QCoreApplication::translate("MainWindow", "Tri", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        exporter->setText(QCoreApplication::translate("MainWindow", "Exporter PDF", nullptr));
        ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        statistique->setText(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "Recherche...", nullptr));
        Retour->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ID PAIMEMANT :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Type :", nullptr));
        Type->setItemText(0, QCoreApplication::translate("MainWindow", "modes de paiement", nullptr));
        Type->setItemText(1, QCoreApplication::translate("MainWindow", "visa", nullptr));
        Type->setItemText(2, QCoreApplication::translate("MainWindow", "paypal", nullptr));
        Type->setItemText(3, QCoreApplication::translate("MainWindow", "esp\303\251ces", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "Date :", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Heure :", nullptr));
        label_5->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:700; font-style:italic; text-decoration: underline; color:#037f7b;\">Gestion de paiement</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "montant:", nullptr));
        montant->setText(QString());
        label_8->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Lieu:", nullptr));
        montant_2->setText(QString());
        Type_2->setItemText(0, QCoreApplication::translate("MainWindow", "20%", nullptr));
        Type_2->setItemText(1, QCoreApplication::translate("MainWindow", "10%", nullptr));
        Type_2->setItemText(2, QCoreApplication::translate("MainWindow", "15%", nullptr));

        label_9->setText(QCoreApplication::translate("MainWindow", "Offre :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
