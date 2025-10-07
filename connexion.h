#ifndef CONNEXION_H
#define CONNEXION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class connexion;
}
QT_END_NAMESPACE

class connexion : public QMainWindow
{
    Q_OBJECT

public:
    explicit connexion(QWidget *parent = nullptr);
    ~connexion();

private:
    Ui::connexion *ui;

private slots:
    void on_Bconnexion_clicked();
};

#endif // CONNEXION_H
