#ifndef APPRENANT_H
#define APPRENANT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class apprenant;
}
QT_END_NAMESPACE

class apprenant : public QMainWindow
{
    Q_OBJECT

public:
    apprenant(QWidget *parent = nullptr);
    ~apprenant();

private:
    Ui::apprenant *ui;
};
#endif // APPRENANT_H
