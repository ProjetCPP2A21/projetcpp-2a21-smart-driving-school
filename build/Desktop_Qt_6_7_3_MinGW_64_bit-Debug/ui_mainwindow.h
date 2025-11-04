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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tab;
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
    QLabel *label_6;
    QComboBox *Type;
    QTimeEdit *heure;
    QLineEdit *lieu;
    QComboBox *choisir;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_10;
    QLabel *label_7;
    QLineEdit *montant;
    QLabel *label_8;
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
        tab = new QTableWidget(centralwidget);
        if (tab->columnCount() < 8)
            tab->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tab->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tab->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tab->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tab->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tab->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tab->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tab->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tab->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (tab->rowCount() < 8)
            tab->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tab->setVerticalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tab->setVerticalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tab->setVerticalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tab->setVerticalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tab->setVerticalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tab->setVerticalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tab->setVerticalHeaderItem(6, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tab->setVerticalHeaderItem(7, __qtablewidgetitem15);
        QFont font;
        font.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font);
        tab->setItem(0, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tab->setItem(0, 1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tab->setItem(0, 2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tab->setItem(0, 3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tab->setItem(0, 4, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tab->setItem(0, 5, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tab->setItem(0, 6, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tab->setItem(0, 7, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tab->setItem(1, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tab->setItem(1, 1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tab->setItem(1, 2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tab->setItem(1, 3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tab->setItem(1, 4, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tab->setItem(1, 5, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tab->setItem(1, 6, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tab->setItem(1, 7, __qtablewidgetitem31);
        tab->setObjectName("tab");
        tab->setGeometry(QRect(610, 140, 521, 241));
        tab->setMinimumSize(QSize(521, 0));
        tab->setStyleSheet(QString::fromUtf8("/* Style global du tableau */\n"
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
        ID->setGeometry(QRect(280, 140, 201, 31));
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
        Date->setGeometry(QRect(440, 200, 140, 31));
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
        label->setGeometry(QRect(280, 110, 101, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(280, 180, 49, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(280, 300, 151, 20));
        Type = new QComboBox(centralwidget);
        Type->addItem(QString());
        Type->addItem(QString());
        Type->addItem(QString());
        Type->addItem(QString());
        Type->setObjectName("Type");
        Type->setGeometry(QRect(280, 200, 120, 31));
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
        heure->setGeometry(QRect(280, 260, 120, 31));
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
        lieu = new QLineEdit(centralwidget);
        lieu->setObjectName("lieu");
        lieu->setGeometry(QRect(440, 260, 140, 31));
        lieu->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        choisir = new QComboBox(centralwidget);
        choisir->addItem(QString());
        choisir->addItem(QString());
        choisir->setObjectName("choisir");
        choisir->setGeometry(QRect(280, 320, 120, 31));
        choisir->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(440, 180, 49, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(280, 240, 49, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(440, 240, 49, 16));
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
        label_7->setGeometry(QRect(440, 300, 91, 20));
        montant = new QLineEdit(centralwidget);
        montant->setObjectName("montant");
        montant->setGeometry(QRect(440, 320, 140, 31));
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
        QTableWidgetItem *___qtablewidgetitem = tab->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tab->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tab->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tab->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Heure", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tab->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Lieu", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tab->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Apprenant", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tab->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Moniteur", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tab->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "R\303\251sultat", nullptr));

        const bool __sortingEnabled = tab->isSortingEnabled();
        tab->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem8 = tab->item(0, 0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tab->item(0, 1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tab->item(0, 2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "01-01-2025", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tab->item(0, 3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "12:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tab->item(0, 4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Tunis", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tab->item(0, 5);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Islem", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tab->item(0, 6);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Ahmed", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tab->item(0, 7);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "Admis", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tab->item(1, 0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tab->item(1, 1);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "Parking", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tab->item(1, 2);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "05-02-2025", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tab->item(1, 3);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "10:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tab->item(1, 4);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "Bardo", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tab->item(1, 5);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "Mariem", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tab->item(1, 6);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "Amin", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tab->item(1, 7);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "\303\251chou\303\251", nullptr));
        tab->setSortingEnabled(__sortingEnabled);

        supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        selection->setText(QCoreApplication::translate("MainWindow", "selection", nullptr));
        tri->setText(QCoreApplication::translate("MainWindow", "Tri", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        exporter->setText(QCoreApplication::translate("MainWindow", "Exporter PDF", nullptr));
        ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        statistique->setText(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "Recherche...", nullptr));
        Retour->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ID apprenant :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Type :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "choissir ton offre:", nullptr));
        Type->setItemText(0, QCoreApplication::translate("MainWindow", "modes de paiement", nullptr));
        Type->setItemText(1, QCoreApplication::translate("MainWindow", "visa", nullptr));
        Type->setItemText(2, QCoreApplication::translate("MainWindow", "paypal", nullptr));
        Type->setItemText(3, QCoreApplication::translate("MainWindow", "esp\303\251ces", nullptr));

        lieu->setText(QString());
        choisir->setItemText(0, QCoreApplication::translate("MainWindow", "1et", nullptr));
        choisir->setItemText(1, QCoreApplication::translate("MainWindow", "2et", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "Date :", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Heure :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Lieu :", nullptr));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
