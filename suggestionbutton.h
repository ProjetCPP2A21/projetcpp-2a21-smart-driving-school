#ifndef SUGGESTIONBUTTON_H
#define SUGGESTIONBUTTON_H

#include <QPushButton>

class SuggestionButton : public QPushButton
{
    Q_OBJECT
public:
    explicit SuggestionButton(const QString &text, QWidget *parent = nullptr);

signals:
    void clicked(const QString &text);

private slots:
    void handleClick();

private:
    QString suggestionText;
};

#endif // SUGGESTIONBUTTON_H
