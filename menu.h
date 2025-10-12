#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "ui_menu.h"

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
    void on_Bexamens_clicked();
    void on_Bapprenant_clicked();
    void on_Bmoniteurs_clicked();
    void on_Bpaiement_clicked();
    void on_Bvehicule_clicked();
    void on_Bemploye_clicked();
};

#endif // MENU_H
