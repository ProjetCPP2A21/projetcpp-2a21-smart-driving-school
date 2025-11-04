/********************************************************************************
** Form generated from reading UI file 'vehicule.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEHICULE_H
#define UI_VEHICULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
<<<<<<< HEAD
#include <QtWidgets/QTableWidget>
=======
#include <QtWidgets/QTableView>
>>>>>>> ae4c4d6 (hello)
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vehicule
{
public:
    QWidget *centralwidget;
    QLabel *label_10;
    QPushButton *Retour;
<<<<<<< HEAD
    QTableWidget *tableWidget;
    QLabel *label;
    QLineEdit *ID;
    QLabel *label_2;
    QComboBox *Type;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *ID_2;
    QLabel *label_4;
    QComboBox *Type_2;
=======
    QTableView *tableView;
    QLabel *label;
    QLineEdit *lineEdit_marque;
    QLabel *label_2;
    QComboBox *comboBox_type;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_ajouter;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QPushButton *pushButton_modifier;
    QPushButton *pushButton_supprimer;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QComboBox *comboBox_etat;
    QLineEdit *lineEdit_kilometrage;
    QLabel *label_5;
    QLineEdit *lineEdit_immatriculation;
    QLabel *label_7;
    QComboBox *comboBox_dispo;
    QLabel *label_8;
    QLineEdit *lineEdit_Capacite;
>>>>>>> ae4c4d6 (hello)
    QStatusBar *statusbar;

    void setupUi(QMainWindow *vehicule)
    {
        if (vehicule->objectName().isEmpty())
            vehicule->setObjectName("vehicule");
<<<<<<< HEAD
        vehicule->resize(800, 600);
=======
        vehicule->resize(1103, 521);
        vehicule->setStyleSheet(QString::fromUtf8("QWidget#centralwidget {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #f5f7fa,\n"
"        stop:1 #c3cfe2\n"
"    );\n"
"}"));
>>>>>>> ae4c4d6 (hello)
        centralwidget = new QWidget(vehicule);
        centralwidget->setObjectName("centralwidget");
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(230, 10, 291, 31));
        label_10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"}"));
        Retour = new QPushButton(centralwidget);
        Retour->setObjectName("Retour");
<<<<<<< HEAD
        Retour->setGeometry(QRect(720, 10, 75, 24));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidget->rowCount() < 8)
            tableWidget->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(0, 5, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(1, 4, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(1, 5, __qtablewidgetitem25);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(270, 70, 521, 241));
        tableWidget->setMinimumSize(QSize(521, 0));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 270, 101, 21));
        ID = new QLineEdit(centralwidget);
        ID->setObjectName("ID");
        ID->setGeometry(QRect(10, 150, 201, 22));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 180, 49, 16));
        Type = new QComboBox(centralwidget);
        Type->setObjectName("Type");
        Type->setGeometry(QRect(10, 220, 91, 22));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(270, 320, 521, 22));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 440, 81, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"}"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(280, 440, 81, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"}"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(400, 440, 81, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"}"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(550, 440, 81, 31));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"}"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(670, 440, 81, 31));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"}"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 120, 61, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 0, 131, 91));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/551980154_660256167125690_1149615457676933854_n (1).jpg")));
        label_5->setScaledContents(true);
        label_5->setWordWrap(false);
        label_5->setOpenExternalLinks(false);
        ID_2 = new QLineEdit(centralwidget);
        ID_2->setObjectName("ID_2");
        ID_2->setGeometry(QRect(10, 310, 201, 22));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 360, 51, 20));
        Type_2 = new QComboBox(centralwidget);
        Type_2->setObjectName("Type_2");
        Type_2->setGeometry(QRect(10, 390, 91, 22));
=======
        Retour->setGeometry(QRect(930, 10, 91, 41));
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
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(500, 100, 561, 261));
        tableView->setMinimumSize(QSize(521, 0));
        tableView->setStyleSheet(QString::fromUtf8("/* Style global du tableau */\n"
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
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 230, 101, 21));
        lineEdit_marque = new QLineEdit(centralwidget);
        lineEdit_marque->setObjectName("lineEdit_marque");
        lineEdit_marque->setGeometry(QRect(10, 130, 201, 31));
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
"        stop:0 #ff4b1f, stop:1 #ffc837); /* style feu au focus */\n"
"}"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 170, 49, 16));
        comboBox_type = new QComboBox(centralwidget);
        comboBox_type->addItem(QString());
        comboBox_type->setObjectName("comboBox_type");
        comboBox_type->setGeometry(QRect(10, 200, 170, 31));
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
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(510, 380, 551, 31));
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
"        stop:0 #ff4b1f, stop:1 #ffc837); /* style feu au focus */\n"
"}\n"
""));
        pushButton_ajouter = new QPushButton(centralwidget);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(270, 440, 121, 41));
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
"}"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 100, 61, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 290, 61, 31));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(-10, -10, 221, 131));
        label_6->setAutoFillBackground(false);
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/logo_no_bg.png")));
        label_6->setScaledContents(true);
        pushButton_modifier = new QPushButton(centralwidget);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(410, 440, 121, 41));
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
"}"));
        pushButton_supprimer = new QPushButton(centralwidget);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(540, 440, 121, 41));
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
"}"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(670, 440, 151, 41));
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
"        stop:0 #ff4e50,   /* rouge vif */\n"
"        stop:0.5 #fc913a, /* orange vif */\n"
"        stop:1 #f9d423   /* jaune lumineux */\n"
"    );\n"
"    border: 1px solid #e04b3f; /* bordure assortie au feu */\n"
"}"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(830, 440, 121, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(960, 440, 121, 41));
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
"        stop:0 #ff4e50,   /* rouge vif */\n"
"        stop:0.5 #fc913a, /* orange vif */\n"
"        stop:1 #f9d423   /* jaune lumineux */\n"
"    );\n"
"    border: 1px solid #e04b3f; /* bordure assortie au feu */\n"
"}"));
        comboBox_etat = new QComboBox(centralwidget);
        comboBox_etat->addItem(QString());
        comboBox_etat->setObjectName("comboBox_etat");
        comboBox_etat->setGeometry(QRect(10, 320, 170, 31));
        comboBox_etat->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        lineEdit_kilometrage = new QLineEdit(centralwidget);
        lineEdit_kilometrage->setObjectName("lineEdit_kilometrage");
        lineEdit_kilometrage->setGeometry(QRect(10, 260, 201, 31));
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
"        stop:0 #ff4b1f, stop:1 #ffc837); /* style feu au focus */\n"
"}"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 360, 131, 31));
        lineEdit_immatriculation = new QLineEdit(centralwidget);
        lineEdit_immatriculation->setObjectName("lineEdit_immatriculation");
        lineEdit_immatriculation->setGeometry(QRect(0, 390, 201, 31));
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
"        stop:0 #ff4b1f, stop:1 #ffc837); /* style feu au focus */\n"
"}"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(270, 100, 121, 31));
        comboBox_dispo = new QComboBox(centralwidget);
        comboBox_dispo->addItem(QString());
        comboBox_dispo->setObjectName("comboBox_dispo");
        comboBox_dispo->setGeometry(QRect(260, 140, 170, 31));
        comboBox_dispo->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(260, 180, 151, 31));
        lineEdit_Capacite = new QLineEdit(centralwidget);
        lineEdit_Capacite->setObjectName("lineEdit_Capacite");
        lineEdit_Capacite->setGeometry(QRect(260, 220, 201, 31));
        lineEdit_Capacite->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}"));
>>>>>>> ae4c4d6 (hello)
        vehicule->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(vehicule);
        statusbar->setObjectName("statusbar");
        vehicule->setStatusBar(statusbar);

        retranslateUi(vehicule);

        QMetaObject::connectSlotsByName(vehicule);
    } // setupUi

    void retranslateUi(QMainWindow *vehicule)
    {
        vehicule->setWindowTitle(QCoreApplication::translate("vehicule", "vehicule", nullptr));
        label_10->setText(QCoreApplication::translate("vehicule", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:700; font-style:italic; text-decoration: underline; color:#037f7b;\">Gestion des Vehicules</span></p></body></html>", nullptr));
        Retour->setText(QCoreApplication::translate("vehicule", "Retour", nullptr));
<<<<<<< HEAD
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("vehicule", "Photo", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("vehicule", "Marque", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("vehicule", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("vehicule", "Kilometrage", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("vehicule", "Capacit\303\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("vehicule", "Disponibilit\303\250", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(0, 0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("vehicule", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("vehicule", "kia", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("vehicule", "Berlin", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(0, 3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("vehicule", "120.00", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(0, 4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("vehicule", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(0, 5);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("vehicule", "reserver", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(1, 0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("vehicule", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(1, 1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("vehicule", "Hyndai", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(1, 2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("vehicule", "Berlin", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(1, 3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("vehicule", "128.739", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(1, 4);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("vehicule", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(1, 5);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("vehicule", "disponible", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        label->setText(QCoreApplication::translate("vehicule", "Kilom\303\251trage :", nullptr));
        label_2->setText(QCoreApplication::translate("vehicule", "Type :", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("vehicule", "Recherche.... ", nullptr));
        pushButton->setText(QCoreApplication::translate("vehicule", "Ajouter", nullptr));
        pushButton_2->setText(QCoreApplication::translate("vehicule", "Modifier", nullptr));
        pushButton_3->setText(QCoreApplication::translate("vehicule", "PDF", nullptr));
        pushButton_4->setText(QCoreApplication::translate("vehicule", "Statistique", nullptr));
        pushButton_5->setText(QCoreApplication::translate("vehicule", "Supprimer", nullptr));
        label_3->setText(QCoreApplication::translate("vehicule", "Marque :", nullptr));
        label_5->setText(QString());
        label_4->setText(QCoreApplication::translate("vehicule", "Etat :", nullptr));
=======
        label->setText(QCoreApplication::translate("vehicule", "Kilom\303\251trage :", nullptr));
        label_2->setText(QCoreApplication::translate("vehicule", "Type :", nullptr));
        comboBox_type->setItemText(0, QCoreApplication::translate("vehicule", "Tous", nullptr));

        lineEdit_3->setText(QCoreApplication::translate("vehicule", "Recherche.... ", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("vehicule", "Ajouter", nullptr));
        label_3->setText(QCoreApplication::translate("vehicule", "Marque :", nullptr));
        label_4->setText(QCoreApplication::translate("vehicule", "Etat :", nullptr));
        label_6->setText(QString());
        pushButton_modifier->setText(QCoreApplication::translate("vehicule", "Modifier", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("vehicule", "Supprimer", nullptr));
        pushButton_4->setText(QCoreApplication::translate("vehicule", "Exporter en PDF", nullptr));
        pushButton_5->setText(QCoreApplication::translate("vehicule", "Statistique", nullptr));
        pushButton_6->setText(QCoreApplication::translate("vehicule", "Tri", nullptr));
        comboBox_etat->setItemText(0, QCoreApplication::translate("vehicule", "Tous", nullptr));

        label_5->setText(QCoreApplication::translate("vehicule", "Immatrucilation", nullptr));
        label_7->setText(QCoreApplication::translate("vehicule", "Disponibilite :", nullptr));
        comboBox_dispo->setItemText(0, QCoreApplication::translate("vehicule", "Tous", nullptr));

        label_8->setText(QCoreApplication::translate("vehicule", "Capacit\303\251", nullptr));
>>>>>>> ae4c4d6 (hello)
    } // retranslateUi

};

namespace Ui {
    class vehicule: public Ui_vehicule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEHICULE_H
