#ifndef PAIEMENT_H
#define PAIEMENT_H

#include <QWidget>

namespace Ui {
class paiement;
}

class paiement : public QWidget
{
    Q_OBJECT

public:
    explicit paiement(QWidget *parent = nullptr);
    ~paiement();

private:
    Ui::paiement *ui;
};

#endif // PAIEMENT_H
