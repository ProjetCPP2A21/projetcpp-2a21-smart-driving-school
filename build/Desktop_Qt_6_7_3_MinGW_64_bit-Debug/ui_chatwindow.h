/********************************************************************************
** Form generated from reading UI file 'chatwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow
{
public:
    QVBoxLayout *mainLayout;
    QWidget *header;
    QHBoxLayout *headerLayout;
    QPushButton *saveHistoryButton;
    QLabel *titleLabel;
    QPushButton *clearHistoryButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *messagesLayout;
    QWidget *inputWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *messageInput;
    QPushButton *sendButton;

    void setupUi(QDialog *ChatWindow)
    {
        if (ChatWindow->objectName().isEmpty())
            ChatWindow->setObjectName("ChatWindow");
        ChatWindow->resize(400, 700);
        ChatWindow->setMinimumSize(QSize(400, 600));
        mainLayout = new QVBoxLayout(ChatWindow);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        header = new QWidget(ChatWindow);
        header->setObjectName("header");
        header->setStyleSheet(QString::fromUtf8("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #4f46e5, stop:1 #818cf8);\n"
"padding: 10px 0;"));
        headerLayout = new QHBoxLayout(header);
        headerLayout->setSpacing(10);
        headerLayout->setObjectName("headerLayout");
        headerLayout->setContentsMargins(10, 0, 10, 0);
        saveHistoryButton = new QPushButton(header);
        saveHistoryButton->setObjectName("saveHistoryButton");
        saveHistoryButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: rgba(255, 255, 255, 0.2);\n"
"    color: white;\n"
"    border: 1px solid white;\n"
"    border-radius: 4px;\n"
"    padding: 4px 8px;\n"
"    font-size: 12px;\n"
"    min-width: 80px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: rgba(255, 255, 255, 0.3);\n"
"}\n"
"QPushButton:pressed {\n"
"    background: rgba(255, 255, 255, 0.4);\n"
"}"));

        headerLayout->addWidget(saveHistoryButton);

        titleLabel = new QLabel(header);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 16px;\n"
"font-weight: 600;\n"
"background: transparent;"));

        headerLayout->addWidget(titleLabel);

        clearHistoryButton = new QPushButton(header);
        clearHistoryButton->setObjectName("clearHistoryButton");
        clearHistoryButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: rgba(255, 255, 255, 0.2);\n"
"    color: white;\n"
"    border: 1px solid white;\n"
"    border-radius: 4px;\n"
"    padding: 4px 8px;\n"
"    font-size: 12px;\n"
"    min-width: 80px;\n"
"}\n"
"QPushButton:hover {\n"
"    background: rgba(255, 255, 255, 0.3);\n"
"}\n"
"QPushButton:pressed {\n"
"    background: rgba(255, 255, 255, 0.4);\n"
"}"));

        headerLayout->addWidget(clearHistoryButton);


        mainLayout->addWidget(header);

        scrollArea = new QScrollArea(ChatWindow);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"QWidget#scrollAreaWidgetContents {\n"
"    background: transparent;\n"
"}"));
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 380, 650));
        messagesLayout = new QVBoxLayout(scrollAreaWidgetContents);
        messagesLayout->setSpacing(10);
        messagesLayout->setObjectName("messagesLayout");
        messagesLayout->setContentsMargins(10, 10, 10, -1);
        scrollArea->setWidget(scrollAreaWidgetContents);

        mainLayout->addWidget(scrollArea);

        inputWidget = new QWidget(ChatWindow);
        inputWidget->setObjectName("inputWidget");
        inputWidget->setStyleSheet(QString::fromUtf8("background: white;"));
        horizontalLayout = new QHBoxLayout(inputWidget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        messageInput = new QLineEdit(inputWidget);
        messageInput->setObjectName("messageInput");
        messageInput->setMinimumSize(QSize(0, 40));
        messageInput->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #e2e8f0;\n"
"    border-radius: 16px;\n"
"    padding: 10px 20px 10px 15px;\n"
"    font-size: 14px;\n"
"    background: white;\n"
"    selection-background-color: #4f46e5;\n"
"    min-height: 20px;\n"
"    color: #1e293b;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #4f46e5;\n"
"    padding: 9px 19px 9px 14px;\n"
"    outline: none;\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #94a3b8;\n"
"    font-style: italic;\n"
"}"));

        horizontalLayout->addWidget(messageInput);

        sendButton = new QPushButton(inputWidget);
        sendButton->setObjectName("sendButton");
        sendButton->setMinimumSize(QSize(80, 40));
        sendButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: #4f46e5;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 20px;\n"
"    padding: 0 16px;\n"
"    font-weight: 600;\n"
"}\n"
"QPushButton:hover {\n"
"    background: #4338ca;\n"
"}\n"
"QPushButton:pressed {\n"
"    background: #3730a3;\n"
"}"));

        horizontalLayout->addWidget(sendButton);


        mainLayout->addWidget(inputWidget);


        retranslateUi(ChatWindow);

        sendButton->setDefault(true);


        QMetaObject::connectSlotsByName(ChatWindow);
    } // setupUi

    void retranslateUi(QDialog *ChatWindow)
    {
        ChatWindow->setWindowTitle(QCoreApplication::translate("ChatWindow", "Assistant Code de la Route", nullptr));
        saveHistoryButton->setText(QCoreApplication::translate("ChatWindow", "Sauvegarder", nullptr));
        titleLabel->setText(QCoreApplication::translate("ChatWindow", "Assistant Code de la Route", nullptr));
        clearHistoryButton->setText(QCoreApplication::translate("ChatWindow", "Effacer", nullptr));
        messageInput->setPlaceholderText(QCoreApplication::translate("ChatWindow", "\303\211crivez votre message ici...", nullptr));
        sendButton->setText(QCoreApplication::translate("ChatWindow", "Envoyer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
