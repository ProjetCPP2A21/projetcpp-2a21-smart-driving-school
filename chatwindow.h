#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>

class ApiChatBot;

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = nullptr);
    ~ChatWindow();

private slots:
    void sendMessage();
    void configureApi();
    void listModels();
    void testEmbedding();
    void saveChatHistory();
    void clearChatHistory();
    void showHistory();

private:
    Ui::ChatWindow *ui;
    ApiChatBot *m_chatbot;

    void addMessage(const QString &sender, const QString &message, bool isUser);
    void setupSuggestions();
};

#endif // CHATWINDOW_H
