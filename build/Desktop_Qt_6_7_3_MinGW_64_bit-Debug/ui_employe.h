/********************************************************************************
** Form generated from reading UI file 'employe.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYE_H
#define UI_EMPLOYE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_employe
{
public:
    QLabel *label;
    QGroupBox *gestion;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_7;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QLabel *label_8;
    QLineEdit *lineEdit_6;
    QLabel *label_9;
    QLineEdit *lineEdit_8;
    QTableWidget *tableWidget;
    QLabel *label_10;
    QPushButton *BretourEmploye;
    QPushButton *pushButton_11;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_7;
    QPushButton *pushButton_10;
    QLineEdit *lineEdit_3;
    QComboBox *comboBox_2;
    QDateEdit *dateEdit;

    void setupUi(QWidget *employe)
    {
        if (employe->objectName().isEmpty())
            employe->setObjectName("employe");
        employe->resize(1418, 656);
        employe->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #f0f2f5, stop:1 #e1e8ed);\n"
"    color: #2c3e50;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"    font-size: 13px;\n"
"}"));
        label = new QLabel(employe);
        label->setObjectName("label");
        label->setGeometry(QRect(0, -10, 111, 91));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/554337631_1437269814008871_8043664467412301076_n.png")));
        label->setScaledContents(true);
        gestion = new QGroupBox(employe);
        gestion->setObjectName("gestion");
        gestion->setGeometry(QRect(60, 60, 1201, 571));
        gestion->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        label_2 = new QLabel(gestion);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 130, 71, 20));
        lineEdit = new QLineEdit(gestion);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(60, 160, 141, 31));
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
"    color: #95a5a6;\n"
"}\n"
""));
        label_3 = new QLabel(gestion);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(290, 210, 63, 20));
        lineEdit_2 = new QLineEdit(gestion);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(290, 240, 140, 26));
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
"    color: #95a5a6;\n"
"}\n"
""));
        label_4 = new QLabel(gestion);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 210, 63, 20));
        lineEdit_4 = new QLineEdit(gestion);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(60, 240, 140, 26));
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
"    color: #95a5a6;\n"
"}\n"
""));
        label_5 = new QLabel(gestion);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(290, 280, 131, 20));
        label_6 = new QLabel(gestion);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(290, 130, 63, 20));
        lineEdit_7 = new QLineEdit(gestion);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(290, 160, 140, 26));
        lineEdit_7->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_7 = new QLabel(gestion);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(60, 280, 81, 21));
        lineEdit_5 = new QLineEdit(gestion);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(60, 310, 140, 26));
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
"    color: #95a5a6;\n"
"}\n"
""));
        label_8 = new QLabel(gestion);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(60, 350, 63, 20));
        lineEdit_6 = new QLineEdit(gestion);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(60, 380, 140, 26));
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
"    color: #95a5a6;\n"
"}\n"
""));
        label_9 = new QLabel(gestion);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(290, 350, 81, 21));
        lineEdit_8 = new QLineEdit(gestion);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(290, 380, 140, 26));
        lineEdit_8->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_8->setEchoMode(QLineEdit::EchoMode::Password);
        tableWidget = new QTableWidget(gestion);
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
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(0, 5, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(0, 6, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(0, 7, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(1, 4, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(1, 5, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(1, 6, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(1, 7, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(2, 2, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setItem(2, 3, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setItem(2, 4, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setItem(2, 5, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setItem(2, 6, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setItem(2, 7, __qtablewidgetitem34);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(520, 130, 561, 281));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background: white;\n"
"    border: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43cea2, stop:1 #185a9d);\n"
"    border-radius: 12px;\n"
"    gridline-color: #e1e8ed;\n"
"    selection-background-color: #43cea2;\n"
"    selection-color: white;\n"
"    font-size: 12px;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"/* En-t\303\252tes */\n"
"QHeaderView::section {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43cea2, stop:1 #185a9d);\n"
"    color: white;\n"
"    padding: 8px 12px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"    font-size: 13px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"/* Lignes altern\303\251es */\n"
"QTableWidget::item:alternate {\n"
"    background: #f8f9fa;\n"
"}\n"
"\n"
"/* Hover sur les lignes */\n"
"QTableWidget::item:hover {\n"
"    background: #e3f2fd;\n"
"    color: #1976d2;\n"
"}\n"
"\n"
"/* S\303\251lection */\n"
"QTableWidget::item:selected {\n"
"    background: #43cea2;\n"
"    color: white;\n"
""
                        "}\n"
"\n"
"/* Scrollbar */\n"
"QScrollBar:vertical {\n"
"    background: #f0f2f5;\n"
"    width: 12px;\n"
"    border-radius: 6px;\n"
"    margin: 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #43cea2;\n"
"    border-radius: 6px;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #185a9d;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
""));
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->verticalHeader()->setVisible(false);
        label_10 = new QLabel(gestion);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(470, 0, 201, 31));
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #2c3e50;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    background: transparent;\n"
"    border: none;\n"
"    padding: 0px;\n"
"}"));
        BretourEmploye = new QPushButton(gestion);
        BretourEmploye->setObjectName("BretourEmploye");
        BretourEmploye->setGeometry(QRect(1090, 30, 91, 41));
        BretourEmploye->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_11 = new QPushButton(gestion);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(120, 490, 101, 41));
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_8 = new QPushButton(gestion);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(300, 490, 111, 41));
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
        pushButton_9 = new QPushButton(gestion);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(210, 440, 91, 41));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_7 = new QPushButton(gestion);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(800, 490, 131, 41));
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
        pushButton_10 = new QPushButton(gestion);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(950, 490, 131, 41));
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEdit_3 = new QLineEdit(gestion);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(520, 430, 401, 31));
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
        comboBox_2 = new QComboBox(gestion);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(960, 430, 120, 31));
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
        dateEdit = new QDateEdit(gestion);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(290, 310, 141, 31));
        dateEdit->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
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

        retranslateUi(employe);

        QMetaObject::connectSlotsByName(employe);
    } // setupUi

    void retranslateUi(QWidget *employe)
    {
        employe->setWindowTitle(QCoreApplication::translate("employe", "gestion des employ\303\251s", nullptr));
        label->setText(QString());
        gestion->setTitle(QString());
        label_2->setText(QCoreApplication::translate("employe", "ID Employ\303\251", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("employe", "Entrez l'ID employ\303\251", nullptr));
        label_3->setText(QCoreApplication::translate("employe", "Nom", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("employe", "Entrez le nom", nullptr));
        label_4->setText(QCoreApplication::translate("employe", "Pr\303\251nom", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("employe", "Entrez le pr\303\251nom", nullptr));
        label_5->setText(QCoreApplication::translate("employe", "Date de naissance", nullptr));
        label_6->setText(QCoreApplication::translate("employe", "Email", nullptr));
        lineEdit_7->setPlaceholderText(QCoreApplication::translate("employe", "exemple@email.com", nullptr));
        label_7->setText(QCoreApplication::translate("employe", "T\303\251l\303\251phone", nullptr));
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("employe", "58 588 255", nullptr));
        label_8->setText(QCoreApplication::translate("employe", "Poste", nullptr));
        lineEdit_6->setPlaceholderText(QCoreApplication::translate("employe", "Responsable", nullptr));
        label_9->setText(QCoreApplication::translate("employe", "Mot de passe", nullptr));
        lineEdit_8->setPlaceholderText(QCoreApplication::translate("employe", "Mot de passe", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("employe", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("employe", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("employe", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("employe", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("employe", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("employe", "Poste", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("employe", "Date de naissance", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("employe", "Mot de passe", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("employe", "****", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("employe", "****", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("employe", "****", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(0, 0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("employe", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(0, 1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("employe", "Lamouchi ", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(0, 2);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("employe", "Ghassen", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(0, 3);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("employe", "lamouchighassen@gmail.com", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(0, 4);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("employe", "51 228 019", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(0, 5);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("employe", "Responsable", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(0, 6);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("employe", "13/02/2003", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(0, 7);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("employe", "*********", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(1, 0);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("employe", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(1, 1);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("employe", "Ouramdan", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(1, 2);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("employe", "Salah Eddine", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(1, 3);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("employe", "salahouramdan@outlook.fr", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(1, 4);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("employe", "52 285 261", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(1, 5);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("employe", "Responsable", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(1, 6);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("employe", "23/10/1999", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(1, 7);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("employe", "*********", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(2, 0);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("employe", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(2, 1);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("employe", "Koc", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(2, 2);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("employe", "Berdan", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(2, 3);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("employe", "kocberdan@hotmail.fr", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(2, 4);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("employe", "25 952 357", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->item(2, 5);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("employe", "Responsable", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->item(2, 6);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("employe", "31/12/1999", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->item(2, 7);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("employe", "*********", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        label_10->setText(QCoreApplication::translate("employe", "Gestion des Employ\303\251s", nullptr));
        BretourEmploye->setText(QCoreApplication::translate("employe", "Retour", nullptr));
        pushButton_11->setText(QCoreApplication::translate("employe", "Modifier", nullptr));
        pushButton_8->setText(QCoreApplication::translate("employe", "Supprimer", nullptr));
        pushButton_9->setText(QCoreApplication::translate("employe", "Ajouter", nullptr));
        pushButton_7->setText(QCoreApplication::translate("employe", "Statistiques", nullptr));
        pushButton_10->setText(QCoreApplication::translate("employe", "Exporter PDF", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("employe", "Recherche...", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("employe", "             Tri", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("employe", "Croissant", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("employe", "D\303\251croissant", nullptr));

    } // retranslateUi

};

namespace Ui {
    class employe: public Ui_employe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYE_H
