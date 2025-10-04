#ifndef EXAMENS_H
#define EXAMENS_H

#include <QMainWindow>
#include "ui_examens.h"   // <-- ajoute Ã§a aussi

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
};

#endif // EXAMENS_H
