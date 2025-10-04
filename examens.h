#ifndef EXAMENS_H
#define EXAMENS_H

#include <QMainWindow>
#include "ui_examens.h"

namespace Ui {
class examens;
}

class examens : public QMainWindow
{
    Q_OBJECT

public:
    explicit examens(QWidget *parent = nullptr);
    ~examens();

private:
    Ui::examens *ui;

private slots:
    void on_Bretour_clicked();   // <-- slot pour le bouton retour
};

#endif // EXAMENS_H
