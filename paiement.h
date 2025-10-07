#ifndef PAIEMENT_H
#define PAIEMENT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class paiement;
}
QT_END_NAMESPACE

class paiement : public QMainWindow
{
    Q_OBJECT

public:
    explicit paiement(QWidget *parent = nullptr);
    ~paiement();

private:
    Ui::paiement *ui;

private slots:
    void on_BretourPaiement_clicked(); // slot bouton retour
};

#endif // PAIEMENT_H
