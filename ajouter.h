#ifndef AJOUTER_H
#define AJOUTER_H

#include <QWidget>

namespace Ui {
class Ajouter;
}

class Ajouter : public QWidget
{
    Q_OBJECT

public:
    explicit Ajouter(QWidget *parent = nullptr);
    ~Ajouter();

private:
    Ui::Ajouter *ui;
};

#endif // AJOUTER_H
