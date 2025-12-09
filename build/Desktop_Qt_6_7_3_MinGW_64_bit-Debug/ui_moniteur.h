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
    QPushButton *tauxReussite;
    QPushButton *affecterVehicule;
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
    QLineEdit *ID_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *moniteur)
    {
        if (moniteur->objectName().isEmpty())
            moniteur->setObjectName("moniteur");
        moniteur->resize(1399, 863);
        moniteur->setStyleSheet(QString::fromUtf8("/* ========== STYLE GLOBAL MODERNE ========== */\n"
"QMainWindow {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #667eea,\n"
"        stop:0.5 #764ba2,\n"
"        stop:1 #2c3e50\n"
"    );\n"
"}\n"
"\n"
"QWidget#centralwidget {\n"
"    background: transparent;\n"
"}\n"
"\n"
"/* ========== LABELS MODERNES ========== */\n"
"QLabel {\n"
"    color: #ffffff;\n"
"    font-family: 'Segoe UI', 'Arial', sans-serif;\n"
"    font-size: 10pt;\n"
"    font-weight: 600;\n"
"    background: transparent;\n"
"    text-shadow: 1px 1px 2px rgba(0, 0, 0, 0.3);\n"
"}\n"
"\n"
"/* ========== BOUTONS PRIMAIRES (Ajouter, Modifier) ========== */\n"
"QPushButton#ajouter, QPushButton#modifier {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #667eea,\n"
"        stop:1 #764ba2);\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    padding: 12px 24px;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    font-size: 11pt;\n"
"    font-"
                        "weight: 600;\n"
"    min-height: 45px;\n"
"}\n"
"\n"
"QPushButton#ajouter:hover, QPushButton#modifier:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #764ba2,\n"
"        stop:1 #667eea);\n"
"    transform: translateY(-2px);\n"
"}\n"
"\n"
"QPushButton#ajouter:pressed, QPushButton#modifier:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #5568d3,\n"
"        stop:1 #653a8f);\n"
"}\n"
"\n"
"/* ========== BOUTON DANGER (Supprimer) ========== */\n"
"QPushButton#suprimer {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #f093fb,\n"
"        stop:1 #f5576c);\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    padding: 12px 24px;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    font-size: 11pt;\n"
"    font-weight: 600;\n"
"    min-height: 45px;\n"
"}\n"
"\n"
"QPushButton#suprimer:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #f5576c,\n"
""
                        "        stop:1 #f093fb);\n"
"}\n"
"\n"
"QPushButton#suprimer:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #e0455a,\n"
"        stop:1 #d981e9);\n"
"}\n"
"\n"
"/* ========== BOUTONS SECONDAIRES (PDF, Statistiques, Tri) ========== */\n"
"QPushButton#pdf, QPushButton#stat, QPushButton#tri {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #43cea2,\n"
"        stop:1 #185a9d);\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    padding: 12px 24px;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    font-size: 11pt;\n"
"    font-weight: 600;\n"
"    min-height: 45px;\n"
"}\n"
"\n"
"QPushButton#pdf:hover, QPushButton#stat:hover, QPushButton#tri:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #185a9d,\n"
"        stop:1 #43cea2);\n"
"    box-shadow: 0 4px 15px rgba(67, 206, 162, 0.4);\n"
"}\n"
"\n"
"QPushButton#pdf:pressed, QPushButton#stat:pressed, QPushButton#tri:pressed {\n"
""
                        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #144d7e,\n"
"        stop:1 #35b890);\n"
"}\n"
"\n"
"/* ========== BOUTONS SP\303\211CIAUX (Taux R\303\251ussite, Affecter V\303\251hicule) ========== */\n"
"QPushButton#tauxReussite, QPushButton#affecterVehicule {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #fa709a,\n"
"        stop:1 #fee140);\n"
"    color: #2c3e50;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    padding: 12px 24px;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    font-size: 11pt;\n"
"    font-weight: 600;\n"
"    min-height: 45px;\n"
"}\n"
"\n"
"QPushButton#tauxReussite:hover, QPushButton#affecterVehicule:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #fee140,\n"
"        stop:1 #fa709a);\n"
"    box-shadow: 0 4px 15px rgba(250, 112, 154, 0.4);\n"
"}\n"
"\n"
"QPushButton#tauxReussite:pressed, QPushButton#affecterVehicule:pressed {\n"
"    background: qlineargradient(x1:0, y1:0,"
                        " x2:1, y2:0,\n"
"        stop:0 #f8d030,\n"
"        stop:1 #e85a88);\n"
"}\n"
"\n"
"/* ========== BOUTON RETOUR ========== */\n"
"QPushButton#Retour {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #4facfe,\n"
"        stop:1 #00f2fe);\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    padding: 12px 24px;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    font-size: 11pt;\n"
"    font-weight: 600;\n"
"    min-height: 45px;\n"
"}\n"
"\n"
"QPushButton#Retour:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #00f2fe,\n"
"        stop:1 #4facfe);\n"
"    box-shadow: 0 4px 15px rgba(79, 172, 254, 0.4);\n"
"}\n"
"\n"
"QPushButton#Retour:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #3d9be8,\n"
"        stop:1 #00d9e8);\n"
"}\n"
"\n"
"/* ========== CHAMPS DE SAISIE MODERNES ========== */\n"
"QLineEdit {\n"
"    background: white;\n"
"    border: 2px solid #e0e0e0;\n"
"    bo"
                        "rder-radius: 12px;\n"
"    padding: 10px 15px;\n"
"    color: #2c3e50;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    font-size: 10pt;\n"
"    selection-background-color: #667eea;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #667eea;\n"
"    background: #fafafa;\n"
"    box-shadow: 0 0 0 3px rgba(102, 126, 234, 0.1);\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 2px solid #b0b0b0;\n"
"    background: #fafafa;\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #95a5a6;\n"
"    font-style: italic;\n"
"}\n"
"\n"
"/* ========== COMBOBOX MODERNES ========== */\n"
"QComboBox {\n"
"    background: white;\n"
"    border: 2px solid #e0e0e0;\n"
"    border-radius: 12px;\n"
"    padding: 10px 15px;\n"
"    color: #2c3e50;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    font-size: 10pt;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 2px solid #b0b0b0;\n"
"    background: #fafafa;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px"
                        " solid #667eea;\n"
"    background: #fafafa;\n"
"    box-shadow: 0 0 0 3px rgba(102, 126, 234, 0.1);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left: 1px solid #e0e0e0;\n"
"    border-top-right-radius: 12px;\n"
"    border-bottom-right-radius: 12px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: none;\n"
"    border-left: 4px solid transparent;\n"
"    border-right: 4px solid transparent;\n"
"    border-top: 6px solid #667eea;\n"
"    width: 0;\n"
"    height: 0;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background: white;\n"
"    border: 2px solid #667eea;\n"
"    border-radius: 8px;\n"
"    selection-background-color: #667eea;\n"
"    selection-color: white;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* ========== SPINBOX MODERNE ========== */\n"
"QSpinBox {\n"
"    background: white;\n"
"    border: 2px solid #e0e0e0;\n"
"    border-radius: 12px;\n"
"    padding: 10px 15px;\n"
"    color: #"
                        "2c3e50;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QSpinBox:hover {\n"
"    border: 2px solid #b0b0b0;\n"
"    background: #fafafa;\n"
"}\n"
"\n"
"QSpinBox:focus {\n"
"    border: 2px solid #667eea;\n"
"    background: #fafafa;\n"
"    box-shadow: 0 0 0 3px rgba(102, 126, 234, 0.1);\n"
"}\n"
"\n"
"QSpinBox::up-button, QSpinBox::down-button {\n"
"    background: transparent;\n"
"    border: none;\n"
"    width: 25px;\n"
"}\n"
"\n"
"QSpinBox::up-arrow {\n"
"    border-left: 4px solid transparent;\n"
"    border-right: 4px solid transparent;\n"
"    border-bottom: 6px solid #667eea;\n"
"    width: 0;\n"
"    height: 0;\n"
"}\n"
"\n"
"QSpinBox::down-arrow {\n"
"    border-left: 4px solid transparent;\n"
"    border-right: 4px solid transparent;\n"
"    border-top: 6px solid #667eea;\n"
"    width: 0;\n"
"    height: 0;\n"
"}\n"
"\n"
"/* ========== TABLEAU PREMIUM ========== */\n"
"QTableWidget {\n"
"    background: white;\n"
"    border: 2px solid #e0e0e0;\n"
"    border-r"
                        "adius: 15px;\n"
"    gridline-color: #f0f0f0;\n"
"    selection-background-color: #667eea;\n"
"    selection-color: white;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    font-size: 10pt;\n"
"    alternate-background-color: #f8f9fa;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 8px;\n"
"    border: none;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: rgba(102, 126, 234, 0.1);\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #667eea;\n"
"    color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #667eea,\n"
"        stop:1 #764ba2);\n"
"    color: white;\n"
"    padding: 12px;\n"
"    border: none;\n"
"    font-family: 'Segoe UI', sans-serif;\n"
"    font-size: 10pt;\n"
"    font-weight: 600;\n"
"    text-transform: uppercase;\n"
"    letter-spacing: 0.5px;\n"
"}\n"
"\n"
"QHeaderView::section:first {\n"
"    border-top-left-radius: 13px;\n"
"}\n"
"\n"
"QHeaderView::section:last {\n"
""
                        "    border-top-right-radius: 13px;\n"
"}\n"
"\n"
"/* ========== SCROLLBAR MODERNE ========== */\n"
"QScrollBar:vertical {\n"
"    background: #f0f0f0;\n"
"    width: 12px;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    margin: 0;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #667eea;\n"
"    border-radius: 6px;\n"
"    min-height: 30px;\n"
"    margin: 2px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #764ba2;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"    background: transparent;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    background: #f0f0f0;\n"
"    height: 12px;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    margin: 0;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #667eea;\n"
"    border-radius: 6px;\n"
"    min-width: 30px;\n"
"    margin: 2px;\n"
"}\n"
"\n"
"QScrollBar::handle:ho"
                        "rizontal:hover {\n"
"    background: #764ba2;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {\n"
"    width: 0px;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {\n"
"    background: transparent;\n"
"}"));
        centralwidget = new QWidget(moniteur);
        centralwidget->setObjectName("centralwidget");
        ajouter = new QPushButton(centralwidget);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(10, 480, 141, 69));
        modifier = new QPushButton(centralwidget);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(170, 480, 161, 69));
        suprimer = new QPushButton(centralwidget);
        suprimer->setObjectName("suprimer");
        suprimer->setGeometry(QRect(360, 480, 201, 69));
        pdf = new QPushButton(centralwidget);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(580, 480, 191, 69));
        stat = new QPushButton(centralwidget);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(800, 480, 191, 69));
        tri = new QPushButton(centralwidget);
        tri->setObjectName("tri");
        tri->setGeometry(QRect(1020, 480, 151, 69));
        tauxReussite = new QPushButton(centralwidget);
        tauxReussite->setObjectName("tauxReussite");
        tauxReussite->setGeometry(QRect(20, 680, 251, 69));
        affecterVehicule = new QPushButton(centralwidget);
        affecterVehicule->setObjectName("affecterVehicule");
        affecterVehicule->setGeometry(QRect(20, 580, 251, 69));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 130, 141, 25));
        ID = new QLineEdit(centralwidget);
        ID->setObjectName("ID");
        ID->setGeometry(QRect(10, 164, 331, 41));
        spec = new QComboBox(centralwidget);
        spec->addItem(QString());
        spec->addItem(QString());
        spec->setObjectName("spec");
        spec->setGeometry(QRect(190, 310, 141, 44));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 210, 91, 25));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 210, 111, 25));
        prenom = new QLineEdit(centralwidget);
        prenom->setObjectName("prenom");
        prenom->setGeometry(QRect(190, 240, 141, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(200, 280, 121, 25));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 280, 131, 25));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 350, 181, 25));
        heur = new QSpinBox(centralwidget);
        heur->setObjectName("heur");
        heur->setGeometry(QRect(25, 380, 141, 41));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(200, 350, 151, 25));
        disp = new QComboBox(centralwidget);
        disp->addItem(QString());
        disp->addItem(QString());
        disp->setObjectName("disp");
        disp->setGeometry(QRect(190, 380, 151, 44));
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
        table->setGeometry(QRect(350, 110, 870, 260));
        table->setMinimumSize(QSize(870, 260));
        table->setAlternatingRowColors(true);
        rechercher = new QLineEdit(centralwidget);
        rechercher->setObjectName("rechercher");
        rechercher->setGeometry(QRect(360, 420, 520, 41));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(290, 10, 662, 60));
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background: transparent;\n"
"    color: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #667eea,\n"
"        stop:1 #764ba2);\n"
"    font-family: 'Segoe UI', 'Arial', sans-serif;\n"
"    font-size: 32pt;\n"
"    font-weight: 700;\n"
"    border: none;\n"
"    padding: 0px;\n"
"}"));
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Retour = new QPushButton(centralwidget);
        Retour->setObjectName("Retour");
        Retour->setGeometry(QRect(1100, 30, 181, 69));
        nom = new QLineEdit(centralwidget);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(20, 240, 151, 41));
        telephone = new QLineEdit(centralwidget);
        telephone->setObjectName("telephone");
        telephone->setGeometry(QRect(20, 310, 151, 41));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, 10, 201, 101));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/554337631_1437269814008871_8043664467412301076_n.png")));
        label_8->setScaledContents(true);
        ID_2 = new QLineEdit(centralwidget);
        ID_2->setObjectName("ID_2");
        ID_2->setGeometry(QRect(370, 590, 331, 41));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(404, 643, 241, 51));
        moniteur->setCentralWidget(centralwidget);
        menubar = new QMenuBar(moniteur);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1399, 22));
        moniteur->setMenuBar(menubar);
        statusbar = new QStatusBar(moniteur);
        statusbar->setObjectName("statusbar");
        moniteur->setStatusBar(statusbar);

        retranslateUi(moniteur);

        QMetaObject::connectSlotsByName(moniteur);
    } // setupUi

    void retranslateUi(QMainWindow *moniteur)
    {
        moniteur->setWindowTitle(QCoreApplication::translate("moniteur", "Gestion des Moniteurs", nullptr));
        ajouter->setText(QCoreApplication::translate("moniteur", "\342\236\225 Ajouter", nullptr));
        modifier->setText(QCoreApplication::translate("moniteur", "\342\234\217\357\270\217 Modifier", nullptr));
        suprimer->setText(QCoreApplication::translate("moniteur", "\360\237\227\221\357\270\217 Supprimer", nullptr));
        pdf->setText(QCoreApplication::translate("moniteur", "\360\237\223\204 Exporter PDF", nullptr));
        stat->setText(QCoreApplication::translate("moniteur", "\360\237\223\212 Statistiques", nullptr));
        tri->setText(QCoreApplication::translate("moniteur", "\360\237\224\200 Tri", nullptr));
        tauxReussite->setText(QCoreApplication::translate("moniteur", "\360\237\223\210 Taux R\303\251ussite", nullptr));
        affecterVehicule->setText(QCoreApplication::translate("moniteur", "\360\237\232\227 Affecter V\303\251hicule", nullptr));
        label->setText(QCoreApplication::translate("moniteur", "\360\237\206\224 ID Moniteur :", nullptr));
        ID->setPlaceholderText(QCoreApplication::translate("moniteur", "Entrez l'ID du moniteur", nullptr));
        spec->setItemText(0, QCoreApplication::translate("moniteur", "Code", nullptr));
        spec->setItemText(1, QCoreApplication::translate("moniteur", "Conduite", nullptr));

        label_2->setText(QCoreApplication::translate("moniteur", "\360\237\221\244 Nom :", nullptr));
        label_3->setText(QCoreApplication::translate("moniteur", "\360\237\221\244 Pr\303\251nom :", nullptr));
        prenom->setPlaceholderText(QCoreApplication::translate("moniteur", "Pr\303\251nom", nullptr));
        label_4->setText(QCoreApplication::translate("moniteur", "\360\237\216\257 Sp\303\251cialit\303\251 :", nullptr));
        label_5->setText(QCoreApplication::translate("moniteur", "\360\237\223\236 T\303\251l\303\251phone :", nullptr));
        label_6->setText(QCoreApplication::translate("moniteur", "\342\217\260 Heures de travail :", nullptr));
        label_7->setText(QCoreApplication::translate("moniteur", "\342\234\205 Disponibilit\303\251 :", nullptr));
        disp->setItemText(0, QCoreApplication::translate("moniteur", "Disponible", nullptr));
        disp->setItemText(1, QCoreApplication::translate("moniteur", "Non Disponible", nullptr));

        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("moniteur", "ID Moniteur", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("moniteur", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("moniteur", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("moniteur", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("moniteur", "Sp\303\251cialit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("moniteur", "Disponibilit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("moniteur", "Heures Travail", nullptr));

        const bool __sortingEnabled = table->isSortingEnabled();
        table->setSortingEnabled(false);
        table->setSortingEnabled(__sortingEnabled);

        rechercher->setPlaceholderText(QCoreApplication::translate("moniteur", "\360\237\224\215 Rechercher un moniteur...", nullptr));
        label_10->setText(QCoreApplication::translate("moniteur", "\360\237\216\223 Gestion des Moniteurs", nullptr));
        Retour->setText(QCoreApplication::translate("moniteur", "\360\237\224\231 Retour", nullptr));
        nom->setPlaceholderText(QCoreApplication::translate("moniteur", "Nom", nullptr));
        telephone->setPlaceholderText(QCoreApplication::translate("moniteur", "8 chiffres", nullptr));
        label_8->setText(QString());
        ID_2->setPlaceholderText(QCoreApplication::translate("moniteur", "Entrez l'ID du moniteur", nullptr));
        pushButton->setText(QCoreApplication::translate("moniteur", "Confirmer L'ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class moniteur: public Ui_moniteur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITEUR_H
