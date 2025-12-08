#ifndef APICONFIGDIALOG_H
#define APICONFIGDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class ApiConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ApiConfigDialog(QWidget *parent = nullptr);
    QString getApiKey() const;
    void setApiKey(const QString &apiKey);

private slots:
    void saveConfig();

private:
    QLineEdit *apiKeyEdit;
};

#endif // APICONFIGDIALOG_H
