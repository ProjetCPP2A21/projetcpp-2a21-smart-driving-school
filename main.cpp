#include "employes.h"

#include <QApplication>
#include"connection.h"
#include<QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    if (c.createconnect() == false )
        {
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                QObject::tr("connection failed.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("database is open"),
                                QObject::tr("connection succes.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
        }
    Employes w;
    w.show();
    return a.exec();
}
