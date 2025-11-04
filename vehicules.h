#ifndef VEHICULES_H
#define VEHICULES_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTableView>
#include "vehicule.h"

QT_BEGIN_NAMESPACE
namespace Ui { class vehicule; } //UI file
QT_END_NAMESPACE

class vehicules : public QMainWindow
{
    Q_OBJECT

public:
    explicit vehicules(QWidget *parent = nullptr);
    ~vehicules();

private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_supprimer_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void rechercherParMarque(const QString &marque);

private:
    Ui::vehicule *ui; //  UI class
};

#endif // VEHICULES_H
