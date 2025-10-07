#ifndef EXAMENS_H
#define EXAMENS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class examens;
}
QT_END_NAMESPACE

class examens : public QMainWindow
{
    Q_OBJECT

public:
    explicit examens(QWidget *parent = nullptr);
    ~examens();

private:
    Ui::examens *ui;

private slots:
    void on_Bretour_clicked();   // slot pour le bouton retour
};

#endif // EXAMENS_H
