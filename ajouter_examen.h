#ifndef AJOUTER_EXAMEN_H
#define AJOUTER_EXAMEN_H

#include <QWidget>

namespace Ui {
class Ajouter_examen;
}

class Ajouter_examen : public QWidget
{
    Q_OBJECT

public:
    explicit Ajouter_examen(QWidget *parent = nullptr);
    ~Ajouter_examen();

private:
    Ui::Ajouter_examen *ui;
};

#endif // AJOUTER_EXAMEN_H
