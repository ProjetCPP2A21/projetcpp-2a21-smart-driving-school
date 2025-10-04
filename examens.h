#ifndef EXAMENS_H
#define EXAMENS_H

#include <QMainWindow>
<<<<<<< HEAD
#include "ui_examens.h"   // <-- ajoute Ã§a aussi
=======
#include "ui_examens.h"
>>>>>>> origin/main-original

namespace Ui {
class examens;
}

class examens : public QMainWindow
{
    Q_OBJECT

public:
<<<<<<< HEAD
    explicit examens(QWidget *parent = nullptr);
=======
    explicit examens(QMainWindow *parent = nullptr);
>>>>>>> origin/main-original
    ~examens();

private:
    Ui::examens *ui;

private slots:
    void on_Bretour_clicked();   // <-- slot pour le bouton retour
};

#endif // EXAMENS_H
