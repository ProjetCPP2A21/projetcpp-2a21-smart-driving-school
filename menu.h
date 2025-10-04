#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "ui_menu.h"   // <-- ajoute ça pour avoir la vraie définition

namespace Ui {
class menu;
}

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
    void on_Bapprenant_clicked(); // Nouveau slot pour ouvrir apprenant
};
#endif // MENU_H
