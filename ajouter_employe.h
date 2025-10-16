#ifndef AJOUTER_EMPLOYE_H
#define AJOUTER_EMPLOYE_H

#include <QWidget>

namespace Ui {
class ajouter_employe;
}

class ajouter_employe : public QWidget
{
    Q_OBJECT

public:
    explicit ajouter_employe(QWidget *parent = nullptr);
    ~ajouter_employe();

private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_annuler_clicked();
    void on_pushButton_vider_clicked();
    void on_BretourAjouterEmploye_clicked();

private:
    Ui::ajouter_employe *ui;
};

#endif // AJOUTER_EMPLOYE_H
