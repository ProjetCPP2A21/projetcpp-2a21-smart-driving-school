#include "apprenants.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    if(c.createconnect()){
        QMessageBox::information(nullptr,"Connection","Connection réussie!");
        apprenants w;
        w.show();
        return a.exec();
    }
    else{
        QMessageBox::critical(nullptr,"Erreur","échec de connection à la base de données");
        return 0;
    }
}
