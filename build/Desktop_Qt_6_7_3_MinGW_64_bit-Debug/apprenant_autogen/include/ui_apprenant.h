/********************************************************************************
** Form generated from reading UI file 'apprenant.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPRENANT_H
#define UI_APPRENANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_apprenant
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QLabel *label_10;
    QLineEdit *lineEdit_3;
    QPushButton *Retour;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QComboBox *comboBox;
    QLineEdit *lineEdit_6;
    QLabel *label_8;
    QDateEdit *dateEdit;
    QPushButton *pushButton_7;

    void setupUi(QMainWindow *apprenant)
    {
        if (apprenant->objectName().isEmpty())
            apprenant->setObjectName("apprenant");
        apprenant->resize(1029, 670);
        apprenant->setStyleSheet(QString::fromUtf8("QWidget#centralwidget {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #f5f7fa,\n"
"        stop:1 #c3cfe2\n"
"    );\n"
"}"));
        centralwidget = new QWidget(apprenant);
        centralwidget->setObjectName("centralwidget");
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
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
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (tableWidget->rowCount() < 8)
            tableWidget->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(1, 4, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(1, 5, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(1, 6, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(1, 7, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(2, 2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(2, 3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(2, 4, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(2, 5, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setItem(2, 6, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setItem(2, 7, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setItem(3, 2, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setItem(3, 3, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setItem(3, 4, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setItem(3, 5, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget->setItem(3, 6, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget->setItem(3, 7, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget->setItem(5, 0, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget->setItem(6, 0, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget->setItem(7, 0, __qtablewidgetitem43);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(440, 200, 541, 271));
        tableWidget->setMinimumSize(QSize(521, 0));
        tableWidget->setStyleSheet(QString::fromUtf8("/* Style global du tableau */\n"
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
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(90, 540, 121, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(710, 540, 111, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(240, 540, 121, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(540, 540, 141, 41));
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
"}\n"
""));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(400, 540, 121, 41));
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
"}\n"
""));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(370, 70, 321, 41));
        label_10->setStyleSheet(QString::fromUtf8(""));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(450, 150, 520, 31));
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
"}\n"
""));
        Retour = new QPushButton(centralwidget);
        Retour->setObjectName("Retour");
        Retour->setGeometry(QRect(904, 20, 101, 41));
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
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 120, 101, 16));
        label_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(90, 140, 141, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 170, 63, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 220, 63, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(90, 330, 63, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(90, 380, 81, 21));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(90, 430, 63, 20));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(90, 190, 140, 26));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(90, 240, 140, 26));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(90, 400, 140, 26));
        lineEdit_5->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(90, 350, 141, 31));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(90, 450, 140, 26));
        lineEdit_6->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(90, 270, 131, 21));
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(90, 300, 141, 31));
        dateEdit->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
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
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(860, 540, 121, 41));
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
"        stop:0 #ff4e50,   /* rouge vif */\n"
"        stop:0.5 #fc913a, /* orange vif */\n"
"        stop:1 #f9d423   /* jaune lumineux */\n"
"    );\n"
"    border: 1px solid #e04b3f; /* bordure assortie au feu */\n"
"}\n"
""));
        apprenant->setCentralWidget(centralwidget);

        retranslateUi(apprenant);

        QMetaObject::connectSlotsByName(apprenant);
    } // setupUi

    void retranslateUi(QMainWindow *apprenant)
    {
        apprenant->setWindowTitle(QCoreApplication::translate("apprenant", "apprenant", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QCoreApplication::translate("apprenant", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("apprenant", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("apprenant", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("apprenant", "Date de naissance", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("apprenant", "sexe", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("apprenant", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("apprenant", "Adresse", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(1, 0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("apprenant", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(1, 1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("apprenant", "12456789", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(1, 2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("apprenant", "gharbi", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(1, 3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("apprenant", "youssef", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(1, 4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("apprenant", "3/8/2005", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(1, 5);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("apprenant", "Homme", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(1, 6);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("apprenant", "26893838", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(1, 7);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("apprenant", "youssef.gharbi@gmail.com", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(2, 0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("apprenant", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(2, 1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("apprenant", "35678743", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(2, 2);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("apprenant", "melki", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(2, 3);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("apprenant", "islem", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(2, 4);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("apprenant", "25/6/2003", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(2, 5);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("apprenant", "Femme", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(2, 6);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("apprenant", "363946203", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(2, 7);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("apprenant", "islem.melki@gmailcom", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(3, 0);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("apprenant", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(3, 1);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("apprenant", "25796436", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(3, 2);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("apprenant", "mannai", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(3, 3);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("apprenant", "islem", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(3, 4);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("apprenant", "9/1/2004", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(3, 5);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("apprenant", "Femme", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(3, 6);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("apprenant", "93639364", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(3, 7);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("apprenant", "islem.mannai@gmailcom", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(4, 0);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("apprenant", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->item(5, 0);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("apprenant", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->item(6, 0);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("apprenant", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->item(7, 0);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("apprenant", "7", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        pushButton->setText(QCoreApplication::translate("apprenant", "Ajouter", nullptr));
        pushButton_2->setText(QCoreApplication::translate("apprenant", "Modifier", nullptr));
        pushButton_3->setText(QCoreApplication::translate("apprenant", "Supprimer", nullptr));
        pushButton_4->setText(QCoreApplication::translate("apprenant", "Exporter PDF", nullptr));
        pushButton_6->setText(QCoreApplication::translate("apprenant", "Tri", nullptr));
        label_10->setText(QCoreApplication::translate("apprenant", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:700; font-style:italic; text-decoration: underline; color:#037f7b;\">Gestion des Apprenants</span></p></body></html>", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("apprenant", "Recherche...", nullptr));
        Retour->setText(QCoreApplication::translate("apprenant", "Retour", nullptr));
        label_2->setText(QCoreApplication::translate("apprenant", "ID Apprenant", nullptr));
        label_3->setText(QCoreApplication::translate("apprenant", "Nom", nullptr));
        label_4->setText(QCoreApplication::translate("apprenant", "Pr\303\251nom", nullptr));
        label_5->setText(QCoreApplication::translate("apprenant", "Sexe", nullptr));
        label_6->setText(QCoreApplication::translate("apprenant", "T\303\251l\303\251phone", nullptr));
        label_7->setText(QCoreApplication::translate("apprenant", "Adresse", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("apprenant", "Homme", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("apprenant", "Femme", nullptr));

        label_8->setText(QCoreApplication::translate("apprenant", "Date de naissance", nullptr));
        pushButton_7->setText(QCoreApplication::translate("apprenant", "Statistique", nullptr));
    } // retranslateUi

};

namespace Ui {
    class apprenant: public Ui_apprenant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPRENANT_H
