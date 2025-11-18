#include "apprenants.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;

    if(c.createconnect()){
        apprenants w;  // <-- classe correcte
        w.show();
        return a.exec();
    }
    else{
        return 0;
    }
}
