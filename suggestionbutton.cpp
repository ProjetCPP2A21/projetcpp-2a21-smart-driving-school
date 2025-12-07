#include "suggestionbutton.h"
#include <QHBoxLayout>
#include <QStyle>

SuggestionButton::SuggestionButton(const QString &text, QWidget *parent)
    : QPushButton(parent), suggestionText(text)
{
    setText(text);
    setStyleSheet(R"(
        QPushButton {
            background-color: #e3f2fd;
            border: 1px solid #bbdefb;
            border-radius: 12px;
            padding: 6px 12px;
            margin: 2px;
            color: #1565c0;
            font-size: 12px;
        }
        QPushButton:hover {
            background-color: #bbdefb;
            border-color: #90caf9;
        }
        QPushButton:pressed {
            background-color: #90caf9;
        }
    )");
    setCursor(Qt::PointingHandCursor);
    connect(this, &QPushButton::clicked, this, &SuggestionButton::handleClick);
}

void SuggestionButton::handleClick()
{
    emit clicked(suggestionText);
}
