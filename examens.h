#ifndef EXAMENS_H
#define EXAMENS_H

#include <QMainWindow>
#include "examen.h"

namespace Ui {
class examens;
}

class examens : public QMainWindow
{
    Q_OBJECT

public:
    explicit examens(QWidget *parent = nullptr);
    ~examens();

private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_supprimer_clicked();
    void on_tableView_examens_clicked(const QModelIndex &index);
    void rechercherParType(const QString &type); // recherche dynamique
    void on_pushButton_trierDate_clicked();
private:
    Ui::examens *ui;
};

#endif // EXAMENS_H
