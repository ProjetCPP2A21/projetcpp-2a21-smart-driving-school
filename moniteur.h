#ifndef MONITEUR_H
#define MONITEUR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class moniteur;
}
QT_END_NAMESPACE

class moniteur : public QMainWindow
{
    Q_OBJECT

public:
    explicit moniteur(QWidget *parent = nullptr);
    ~moniteur();

private:
    Ui::moniteur *ui;

private slots:
    void on_BretourMoniteur_clicked();  // slot bouton retour
};

#endif // MONITEUR_H
