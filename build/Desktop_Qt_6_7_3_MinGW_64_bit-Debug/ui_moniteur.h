/********************************************************************************
** Form generated from reading UI file 'moniteur.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITEUR_H
#define UI_MONITEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_moniteur
{
public:
    QWidget *centralwidget;
    QPushButton *ajouter;
    QPushButton *modifier;
    QPushButton *suprimer;
    QPushButton *pdf;
    QPushButton *stat;
    QPushButton *tri;
    QLabel *label;
    QLineEdit *ID;
    QComboBox *spec;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *prenom;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *heur;
    QLabel *label_7;
    QComboBox *disp;
    QTableWidget *table;
    QLineEdit *rechercher;
    QLabel *label_10;
    QPushButton *Retour;
    QLineEdit *nom;
    QLineEdit *telephone;
    QLabel *label_8;
    QPushButton *AffectationAuto;
    QPushButton *reussite;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *moniteur)
    {
        if (moniteur->objectName().isEmpty())
            moniteur->setObjectName("moniteur");
        moniteur->resize(1128, 533);
        moniteur->setStyleSheet(QString::fromUtf8("QWidget#centralwidget {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #f5f7fa,\n"
"        stop:1 #c3cfe2\n"
"    );\n"
"}"));
        centralwidget = new QWidget(moniteur);
        centralwidget->setObjectName("centralwidget");
        ajouter = new QPushButton(centralwidget);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(10, 430, 111, 41));
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
        modifier = new QPushButton(centralwidget);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(130, 430, 111, 41));
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
        suprimer = new QPushButton(centralwidget);
        suprimer->setObjectName("suprimer");
        suprimer->setGeometry(QRect(250, 430, 121, 41));
        suprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pdf = new QPushButton(centralwidget);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(380, 430, 141, 41));
        pdf->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        stat = new QPushButton(centralwidget);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(530, 430, 131, 41));
        stat->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        tri->setGeometry(QRect(670, 430, 121, 41));
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
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 140, 91, 21));
        ID = new QLineEdit(centralwidget);
        ID->setObjectName("ID");
        ID->setGeometry(QRect(30, 170, 291, 31));
        ID->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        spec = new QComboBox(centralwidget);
        spec->addItem(QString());
        spec->addItem(QString());
        spec->setObjectName("spec");
        spec->setGeometry(QRect(190, 310, 141, 31));
        spec->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 210, 63, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 210, 63, 20));
        prenom = new QLineEdit(centralwidget);
        prenom->setObjectName("prenom");
        prenom->setGeometry(QRect(190, 240, 141, 31));
        prenom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(200, 280, 71, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 280, 81, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 350, 111, 20));
        heur = new QSpinBox(centralwidget);
        heur->setObjectName("heur");
        heur->setGeometry(QRect(30, 380, 136, 31));
        heur->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43cea2, stop:1 #185a9d);\n"
"    border-radius: 10px;       /* m\303\252me style que QComboBox */\n"
"    padding: 2px 6px;\n"
"    background: white;\n"
"    color: #2c3e50;\n"
"    min-width: 80px;\n"
"    max-width: 120px;\n"
"    height: 24px;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"/* Boutons haut/bas */\n"
"QSpinBox::up-button, QSpinBox::down-button {\n"
"    subcontrol-origin: border;\n"
"    width: 20px;\n"
"    background: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"/* Bouton haut */\n"
"QSpinBox::up-button {\n"
"    subcontrol-position: top right;\n"
"    border-top-right-radius: 8px;\n"
"    margin: 1px;\n"
"}\n"
"\n"
"/* Bouton bas */\n"
"QSpinBox::down-button {\n"
"    subcontrol-position: bottom right;\n"
"    border-bottom-right-radius: 8px;\n"
"    margin: 1px;\n"
"}\n"
"\n"
"/* Fl\303\250che haut */\n"
"QSpinBox::up-arrow {\n"
"    image: url(:/icons/arrow-up-dark.png);\n"
"    width: 10px;\n"
""
                        "    height: 10px;\n"
"}\n"
"\n"
"/* Fl\303\250che bas */\n"
"QSpinBox::down-arrow {\n"
"    image: url(:/icons/arrow-down-dark.png);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"\n"
"/* Focus */\n"
"QSpinBox:focus {\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #ff4b1f, stop:1 #ffc837);\n"
"    box-shadow: 0 0 4px rgba(255, 107, 53, 0.6);\n"
"}\n"
"\n"
"/* Hover */\n"
"QSpinBox:hover {\n"
"    border: 2px solid #43cea2;\n"
"    box-shadow: 0 0 4px rgba(67, 206, 162, 0.6);\n"
"}\n"
""));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(200, 350, 101, 20));
        disp = new QComboBox(centralwidget);
        disp->addItem(QString());
        disp->addItem(QString());
        disp->setObjectName("disp");
        disp->setGeometry(QRect(190, 380, 141, 31));
        disp->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        table = new QTableWidget(centralwidget);
        if (table->columnCount() < 7)
            table->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (table->rowCount() < 4)
            table->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        table->setVerticalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        table->setItem(0, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        table->setItem(0, 1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        table->setItem(0, 2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        table->setItem(0, 3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        table->setItem(0, 4, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        table->setItem(0, 5, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        table->setItem(0, 6, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        table->setItem(1, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        table->setItem(1, 1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        table->setItem(1, 2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        table->setItem(1, 3, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        table->setItem(1, 4, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        table->setItem(1, 5, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        table->setItem(1, 6, __qtablewidgetitem24);
        table->setObjectName("table");
        table->setGeometry(QRect(350, 180, 761, 231));
        table->setMinimumSize(QSize(521, 0));
        table->setStyleSheet(QString::fromUtf8("/* Style global du tableau */\n"
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
        rechercher = new QLineEdit(centralwidget);
        rechercher->setObjectName("rechercher");
        rechercher->setGeometry(QRect(350, 140, 520, 31));
        rechercher->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(410, 40, 291, 31));
        label_10->setStyleSheet(QString::fromUtf8("PushButton {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"}"));
        Retour = new QPushButton(centralwidget);
        Retour->setObjectName("Retour");
        Retour->setGeometry(QRect(980, 30, 111, 41));
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
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #ff4e50,   /* rouge vif */\n"
"        stop:0.5 #fc913a, /* orange vif */\n"
"        stop:1 #f9d423   /* jaune lumineux */\n"
"    );\n"
"    border: 1px solid #e04b3f; /* bordure assortie au feu */\n"
"}"));
        nom = new QLineEdit(centralwidget);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(30, 240, 141, 31));
        nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        telephone = new QLineEdit(centralwidget);
        telephone->setObjectName("telephone");
        telephone->setGeometry(QRect(30, 310, 141, 31));
        telephone->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_8->setGeometry(QRect(20, -10, 251, 161));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/582053170_1306629171149846_3027987359576536556_n-removebg-preview.png")));
        label_8->setScaledContents(true);
        AffectationAuto = new QPushButton(centralwidget);
        AffectationAuto->setObjectName("AffectationAuto");
        AffectationAuto->setGeometry(QRect(800, 430, 161, 41));
        AffectationAuto->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        reussite = new QPushButton(centralwidget);
        reussite->setObjectName("reussite");
        reussite->setGeometry(QRect(970, 430, 151, 41));
        reussite->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        moniteur->setCentralWidget(centralwidget);
        menubar = new QMenuBar(moniteur);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1128, 26));
        moniteur->setMenuBar(menubar);
        statusbar = new QStatusBar(moniteur);
        statusbar->setObjectName("statusbar");
        moniteur->setStatusBar(statusbar);

        retranslateUi(moniteur);

        QMetaObject::connectSlotsByName(moniteur);
    } // setupUi

    void retranslateUi(QMainWindow *moniteur)
    {
        moniteur->setWindowTitle(QCoreApplication::translate("moniteur", "moniteur", nullptr));
        ajouter->setText(QCoreApplication::translate("moniteur", "Ajouter", nullptr));
        modifier->setText(QCoreApplication::translate("moniteur", "Modifier", nullptr));
        suprimer->setText(QCoreApplication::translate("moniteur", "Supprimer", nullptr));
        pdf->setText(QCoreApplication::translate("moniteur", "Exporter PDF", nullptr));
        stat->setText(QCoreApplication::translate("moniteur", "Statistiques", nullptr));
        tri->setText(QCoreApplication::translate("moniteur", "Tri", nullptr));
        label->setText(QCoreApplication::translate("moniteur", "ID  Moniteur :", nullptr));
        spec->setItemText(0, QCoreApplication::translate("moniteur", "Code ", nullptr));
        spec->setItemText(1, QCoreApplication::translate("moniteur", "Conduite", nullptr));

        label_2->setText(QCoreApplication::translate("moniteur", "Nom :", nullptr));
        label_3->setText(QCoreApplication::translate("moniteur", "Pr\303\251nom :", nullptr));
        label_4->setText(QCoreApplication::translate("moniteur", "Sp\303\251cialite :", nullptr));
        label_5->setText(QCoreApplication::translate("moniteur", "T\303\251l\303\251phone :", nullptr));
        label_6->setText(QCoreApplication::translate("moniteur", "Heurs de travail :", nullptr));
        label_7->setText(QCoreApplication::translate("moniteur", "Disponibilit\303\251 :", nullptr));
        disp->setItemText(0, QCoreApplication::translate("moniteur", "Disponible", nullptr));
        disp->setItemText(1, QCoreApplication::translate("moniteur", "Non Disponible", nullptr));

        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("moniteur", "ID moniteur", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("moniteur", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("moniteur", "prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("moniteur", "Telephone", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("moniteur", "Sp\303\251cialit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("moniteur", "Disponabilit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("moniteur", "Heurs_travail", nullptr));

        const bool __sortingEnabled = table->isSortingEnabled();
        table->setSortingEnabled(false);
        table->setSortingEnabled(__sortingEnabled);

        rechercher->setText(QCoreApplication::translate("moniteur", "Recherche...", nullptr));
        label_10->setText(QCoreApplication::translate("moniteur", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:700; font-style:italic; text-decoration: underline; color:#037f7b;\">Gestion des Moniteurs</span></p></body></html>", nullptr));
        Retour->setText(QCoreApplication::translate("moniteur", "Retour", nullptr));
        label_8->setText(QString());
        AffectationAuto->setText(QCoreApplication::translate("moniteur", "AffectationAuto", nullptr));
        reussite->setText(QCoreApplication::translate("moniteur", "Taux-Reussite", nullptr));
    } // retranslateUi

};

namespace Ui {
    class moniteur: public Ui_moniteur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITEUR_H
