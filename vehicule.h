#ifndef VEHICULE_H
#define VEHICULE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class vehicule;
}
QT_END_NAMESPACE

class vehicule : public QMainWindow
{
    Q_OBJECT

public:
    explicit vehicule(QWidget *parent = nullptr);
    ~vehicule();

private:
    Ui::vehicule *ui;

private slots:
    void on_BretourVehicule_clicked();  // slot bouton retour
};

#endif // VEHICULE_H
