#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

namespace Ui {
class menu;
}

class employe;

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private:
    Ui::menu *ui;

private slots:
    void on_Bemploye_clicked();
};

#endif // MENU_H
