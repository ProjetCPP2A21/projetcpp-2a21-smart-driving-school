/********************************************************************************
** Form generated from reading UI file 'paiement.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAIEMENT_H
#define UI_PAIEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_paiement
{
public:
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_7;
    QPushButton *pushButton;
    QComboBox *comboBox_4;
    QPushButton *pushButton_2;
    QLineEdit *ID;
    QPushButton *pushButton_7;
    QLabel *label_8;
    QLineEdit *lineEdit_2;
    QTimeEdit *timeEdit;
    QPushButton *pushButton_8;
    QDateEdit *Date;
    QPushButton *pushButton_4;
    QLabel *label_6;
    QPushButton *pushButton_3;
    QLabel *label;
    QComboBox *comboBox_2;
    QPushButton *BretourPaiement;
    QLabel *label_2;
    QTableWidget *tableWidget;
    QComboBox *Type;
    QLineEdit *lineEdit_4;
    QLabel *label_5;

    void setupUi(QWidget *paiement)
    {
        if (paiement->objectName().isEmpty())
            paiement->setObjectName("paiement");
        paiement->resize(906, 525);
        label_4 = new QLabel(paiement);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 230, 49, 16));
        label_3 = new QLabel(paiement);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 170, 49, 16));
        lineEdit_3 = new QLineEdit(paiement);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(290, 360, 471, 31));
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
        label_7 = new QLabel(paiement);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(170, 290, 91, 20));
        pushButton = new QPushButton(paiement);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(100, 370, 91, 41));
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
        comboBox_4 = new QComboBox(paiement);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(10, 320, 120, 31));
        comboBox_4->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        pushButton_2 = new QPushButton(paiement);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(30, 420, 101, 41));
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
        ID = new QLineEdit(paiement);
        ID->setObjectName("ID");
        ID->setGeometry(QRect(10, 130, 201, 31));
        ID->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        pushButton_7 = new QPushButton(paiement);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(0, 480, 921, 41));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"}"));
        label_8 = new QLabel(paiement);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, 0, 111, 91));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/554337631_1437269814008871_8043664467412301076_n.png")));
        label_8->setScaledContents(true);
        lineEdit_2 = new QLineEdit(paiement);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(170, 250, 91, 31));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        timeEdit = new QTimeEdit(paiement);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setGeometry(QRect(10, 250, 120, 31));
        timeEdit->setStyleSheet(QString::fromUtf8("QTimeEdit {\n"
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
        pushButton_8 = new QPushButton(paiement);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(610, 410, 131, 41));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Date = new QDateEdit(paiement);
        Date->setObjectName("Date");
        Date->setGeometry(QRect(170, 190, 91, 31));
        Date->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
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
        pushButton_4 = new QPushButton(paiement);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(750, 410, 121, 41));
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
        label_6 = new QLabel(paiement);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 290, 151, 20));
        pushButton_3 = new QPushButton(paiement);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(170, 420, 111, 41));
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
        label = new QLabel(paiement);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 100, 101, 21));
        comboBox_2 = new QComboBox(paiement);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(770, 360, 120, 31));
        comboBox_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        BretourPaiement = new QPushButton(paiement);
        BretourPaiement->setObjectName("BretourPaiement");
        BretourPaiement->setGeometry(QRect(784, 30, 81, 41));
        BretourPaiement->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_2 = new QLabel(paiement);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 170, 49, 16));
        tableWidget = new QTableWidget(paiement);
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
        tableWidget->setItem(0, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(0, 5, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(0, 6, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(0, 7, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(1, 4, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(1, 5, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setItem(1, 6, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setItem(1, 7, __qtablewidgetitem31);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(290, 110, 581, 241));
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
        Type = new QComboBox(paiement);
        Type->addItem(QString());
        Type->addItem(QString());
        Type->addItem(QString());
        Type->addItem(QString());
        Type->setObjectName("Type");
        Type->setGeometry(QRect(10, 190, 120, 31));
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
        lineEdit_4 = new QLineEdit(paiement);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(170, 320, 91, 31));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_5 = new QLabel(paiement);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(170, 230, 49, 16));

        retranslateUi(paiement);

        QMetaObject::connectSlotsByName(paiement);
    } // setupUi

    void retranslateUi(QWidget *paiement)
    {
        paiement->setWindowTitle(QCoreApplication::translate("paiement", "gestion des paiments", nullptr));
        label_4->setText(QCoreApplication::translate("paiement", "Heure :", nullptr));
        label_3->setText(QCoreApplication::translate("paiement", "Date :", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("paiement", "Recherche...", nullptr));
        label_7->setText(QCoreApplication::translate("paiement", "montant:", nullptr));
        pushButton->setText(QCoreApplication::translate("paiement", "Ajouter", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("paiement", "1et", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("paiement", "2et", nullptr));

        pushButton_2->setText(QCoreApplication::translate("paiement", "Modifier", nullptr));
        pushButton_7->setText(QString());
        label_8->setText(QString());
        lineEdit_2->setText(QString());
        pushButton_8->setText(QCoreApplication::translate("paiement", "Statistiques", nullptr));
        pushButton_4->setText(QCoreApplication::translate("paiement", "Exporter PDF", nullptr));
        label_6->setText(QCoreApplication::translate("paiement", "choissir ton offre:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("paiement", "Supprimer", nullptr));
        label->setText(QCoreApplication::translate("paiement", "ID apprenant :", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("paiement", "             Tri", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("paiement", "Croissant", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("paiement", "D\303\251croissant", nullptr));

        BretourPaiement->setText(QCoreApplication::translate("paiement", "Retour", nullptr));
        label_2->setText(QCoreApplication::translate("paiement", "Type :", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("paiement", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("paiement", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("paiement", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("paiement", "Heure", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("paiement", "Lieu", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("paiement", "Apprenant", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("paiement", "Moniteur", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("paiement", "R\303\251sultat", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("paiement", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(0, 1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("paiement", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(0, 2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("paiement", "01-01-2025", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(0, 3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("paiement", "12:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(0, 4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("paiement", "Tunis", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(0, 5);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("paiement", "Islem", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(0, 6);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("paiement", "Ahmed", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(0, 7);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("paiement", "Admis", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(1, 0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("paiement", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(1, 1);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("paiement", "Parking", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(1, 2);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("paiement", "05-02-2025", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(1, 3);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("paiement", "10:00", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(1, 4);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("paiement", "Bardo", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(1, 5);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("paiement", "Mariem", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(1, 6);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("paiement", "Amin", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(1, 7);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("paiement", "\303\251chou\303\251", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        Type->setItemText(0, QCoreApplication::translate("paiement", "modes de paiement", nullptr));
        Type->setItemText(1, QCoreApplication::translate("paiement", "visa", nullptr));
        Type->setItemText(2, QCoreApplication::translate("paiement", "paypal", nullptr));
        Type->setItemText(3, QCoreApplication::translate("paiement", "esp\303\251ces", nullptr));

        lineEdit_4->setText(QString());
        label_5->setText(QCoreApplication::translate("paiement", "Lieu :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class paiement: public Ui_paiement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAIEMENT_H
