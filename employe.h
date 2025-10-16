#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class employe;
}
QT_END_NAMESPACE

class employe : public QMainWindow
{
    Q_OBJECT

public:
    explicit employe(QWidget *parent = nullptr);
    ~employe();

private:
    Ui::employe *ui;

private slots:
    void on_BretourEmploye_clicked();  // slot bouton retour
    void on_pushButton_9_clicked();   // slot bouton ajouter
    void on_pushButton_11_clicked();  // slot bouton modifier
    void on_pushButton_8_clicked();   // slot bouton supprimer
};

#endif // EMPLOYE_H
