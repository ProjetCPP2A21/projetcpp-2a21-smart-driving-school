#ifndef APPRENANTS_H
#define APPRENANTS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class apprenants;
}
QT_END_NAMESPACE

class apprenants : public QMainWindow
{
    Q_OBJECT

public:
    apprenants(QWidget *parent = nullptr);
    ~apprenants();

private:
    Ui::apprenants *ui;
};
#endif // APPRENANTS_H
