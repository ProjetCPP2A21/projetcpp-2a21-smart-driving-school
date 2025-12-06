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
    QLabel *header;
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
        header = new QLabel(ChatWindow);
        header->setObjectName("header");
        header->setAlignment(Qt::AlignCenter);
        header->setStyleSheet(QString::fromUtf8("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #4f46e5, stop:1 #818cf8);\n"
"color: white;\n"
"padding: 16px 20px;\n"
"font-size: 16px;\n"
"font-weight: 600;"));

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
"    border: 2px solid #e2e8f0;\n"
"    border-radius: 20px;\n"
"    padding: 0 16px;\n"
"    font-size: 14px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border-color: #818cf8;\n"
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
        header->setText(QCoreApplication::translate("ChatWindow", "Assistant Code de la Route", nullptr));
        messageInput->setPlaceholderText(QCoreApplication::translate("ChatWindow", "\303\211crivez votre message...", nullptr));
        sendButton->setText(QCoreApplication::translate("ChatWindow", "Envoyer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
