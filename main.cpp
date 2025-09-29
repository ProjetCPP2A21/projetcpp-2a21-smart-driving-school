#include "moniteur.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    moniteur w;
    w.show();
    return a.exec();
}
