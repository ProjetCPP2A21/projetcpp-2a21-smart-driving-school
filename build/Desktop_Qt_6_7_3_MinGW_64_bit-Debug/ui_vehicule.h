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
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vehicule
{
public:
    QWidget *centralwidget;
    QLabel *label_10;
    QTableView *tableView;
    QWidget *statsContainer;
    QWidget *formGroup;
    QLabel *label_immatriculation;
    QLineEdit *lineEdit_immatriculation;
    QLabel *label_3;
    QLineEdit *lineEdit_marque;
    QLabel *label_2;
    QComboBox *comboBox_type;
    QLabel *label;
    QLineEdit *lineEdit_kilometrage;
    QLabel *label_4;
    QComboBox *comboBox_etat;
    QLabel *label_disponibilite;
    QComboBox *comboBox_disponibilite;
    QLabel *label_capacite;
    QLineEdit *lineEdit_capacite;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *page_2;
    QWidget *searchGroup;
    QLabel *label_11;
    QLineEdit *lineEdit_3;
    QWidget *actionGroup;
    QPushButton *pushButton_ajouter;
    QPushButton *pushButton_modifier;
    QPushButton *pushButton_supprimer;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_sms_alert;
    QPushButton *Retour;
    QPushButton *pushButton_reco_window;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *vehicule)
    {
        if (vehicule->objectName().isEmpty())
            vehicule->setObjectName("vehicule");
        vehicule->resize(1223, 816);
        vehicule->setStyleSheet(QString::fromUtf8("QWidget#centralwidget {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #f5f7fa,\n"
"        stop:1 #c3cfe2\n"
"    );\n"
"}"));
        centralwidget = new QWidget(vehicule);
        centralwidget->setObjectName("centralwidget");
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(250, 10, 400, 51));
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(0, 0, 50, 255), stop: 0.5 rgba(47, 79, 79, 255), stop: 1 rgba(25, 25, 112, 255));\n"
"    border: 2px solid rgba(100, 100, 100, 200);\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"    font-size: 18px;\n"
"}"));
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tableView = new QTableView(centralwidget);
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
        statsContainer = new QWidget(centralwidget);
        statsContainer->setObjectName("statsContainer");
        statsContainer->setGeometry(QRect(760, 390, 451, 301));
        statsContainer->setStyleSheet(QString::fromUtf8("QWidget#statsContainer { border: 0px; background: transparent; }"));
        formGroup = new QWidget(centralwidget);
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
        label_3 = new QLabel(formGroup);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 60, 61, 21));
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
        label_2 = new QLabel(formGroup);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 120, 49, 16));
        comboBox_type = new QComboBox(formGroup);
        comboBox_type->setObjectName("comboBox_type");
        comboBox_type->setGeometry(QRect(0, 140, 220, 31));
        comboBox_type->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        label = new QLabel(formGroup);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 180, 101, 21));
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
        label_4 = new QLabel(formGroup);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 240, 61, 31));
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
        toolBox = new QToolBox(formGroup);
        toolBox->setObjectName("toolBox");
        toolBox->setGeometry(QRect(10, 340, 69, 129));
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 69, 69));
        toolBox->addItem(page, QString::fromUtf8("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 69, 69));
        toolBox->addItem(page_2, QString::fromUtf8("Page 2"));
        searchGroup = new QWidget(centralwidget);
        searchGroup->setObjectName("searchGroup");
        searchGroup->setGeometry(QRect(220, 380, 630, 60));
        label_11 = new QLabel(searchGroup);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(0, 10, 81, 21));
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
        actionGroup = new QWidget(centralwidget);
        actionGroup->setObjectName("actionGroup");
        actionGroup->setGeometry(QRect(10, 480, 230, 120));
        pushButton_ajouter = new QPushButton(actionGroup);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(0, 10, 110, 41));
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
"        stop:0 #ff4e50,\n"
"        stop:0.5 #fc913a,\n"
"        stop:1 #f9d423\n"
"    );\n"
"    border: 1px solid #e04b3f;\n"
"}"));
        pushButton_modifier = new QPushButton(actionGroup);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(120, 10, 110, 41));
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
"        stop:0 #ff4e50,\n"
"        stop:0.5 #fc913a,\n"
"        stop:1 #f9d423\n"
"    );\n"
"    border: 1px solid #e04b3f;\n"
"}"));
        pushButton_supprimer = new QPushButton(actionGroup);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(0, 60, 110, 41));
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
"        stop:0 #ff4e50,\n"
"        stop:0.5 #fc913a,\n"
"        stop:1 #f9d423\n"
"    );\n"
"    border: 1px solid #e04b3f;\n"
"}"));
        pushButton_5 = new QPushButton(actionGroup);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(120, 60, 110, 41));
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
"        stop:0 #ff4e50,\n"
"        stop:0.5 #fc913a,\n"
"        stop:1 #f9d423\n"
"    );\n"
"    border: 1px solid #e04b3f;\n"
"}"));
        pushButton_4 = new QPushButton(centralwidget);
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
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(260, 490, 131, 41));
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
        pushButton_sms_alert = new QPushButton(centralwidget);
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
        Retour = new QPushButton(centralwidget);
        Retour->setObjectName("Retour");
        Retour->setGeometry(QRect(790, 10, 91, 41));
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
"        stop:0 #ff0000,\n"
"        stop:0.5 #cc0000,\n"
"        stop:1 #990000\n"
"    );\n"
"    border: 1px solid #800000;\n"
"    color: white;\n"
"}"));
        pushButton_reco_window = new QPushButton(centralwidget);
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
        vehicule->setCentralWidget(centralwidget);
        menubar = new QMenuBar(vehicule);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1223, 22));
        vehicule->setMenuBar(menubar);
        statusbar = new QStatusBar(vehicule);
        statusbar->setObjectName("statusbar");
        vehicule->setStatusBar(statusbar);

        retranslateUi(vehicule);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(vehicule);
    } // setupUi

    void retranslateUi(QMainWindow *vehicule)
    {
        vehicule->setWindowTitle(QCoreApplication::translate("vehicule", "Gestion des v\303\251hicules", nullptr));
        label_10->setText(QCoreApplication::translate("vehicule", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:700; font-style:italic; text-decoration: underline; color:#037f7b;\">Gestion des V\303\251hicules</span></p></body></html>", nullptr));
        label_immatriculation->setText(QCoreApplication::translate("vehicule", "Immatriculation :", nullptr));
        label_3->setText(QCoreApplication::translate("vehicule", "Marque :", nullptr));
        label_2->setText(QCoreApplication::translate("vehicule", "Type :", nullptr));
        label->setText(QCoreApplication::translate("vehicule", "Kilom\303\251trage :", nullptr));
        label_4->setText(QCoreApplication::translate("vehicule", "\303\211tat :", nullptr));
        label_disponibilite->setText(QCoreApplication::translate("vehicule", "Disponibilit\303\251 :", nullptr));
        label_capacite->setText(QCoreApplication::translate("vehicule", "Capacit\303\251 :", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("vehicule", "Page 1", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("vehicule", "Page 2", nullptr));
        label_11->setText(QCoreApplication::translate("vehicule", "Recherche :", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("vehicule", "Recherche par marque...", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("vehicule", "Ajouter", nullptr));
        pushButton_modifier->setText(QCoreApplication::translate("vehicule", "Modifier", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("vehicule", "Supprimer", nullptr));
        pushButton_5->setText(QCoreApplication::translate("vehicule", "Statistiques", nullptr));
        pushButton_4->setText(QCoreApplication::translate("vehicule", "Exporter en PDF", nullptr));
        pushButton_6->setText(QCoreApplication::translate("vehicule", "Tri", nullptr));
        pushButton_sms_alert->setText(QCoreApplication::translate("vehicule", "Alerte Diagnostic SMS", nullptr));
        Retour->setText(QCoreApplication::translate("vehicule", "Retour", nullptr));
        pushButton_reco_window->setText(QCoreApplication::translate("vehicule", "Recommandation IA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class vehicule: public Ui_vehicule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEHICULE_H
