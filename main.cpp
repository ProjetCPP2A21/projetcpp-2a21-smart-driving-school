<<<<<<< HEAD
#include "vehicule.h"

#include <QApplication>
=======
#include <QApplication>
#include "vehicules.h"
#include "cnx.h"
>>>>>>> ae4c4d6 (hello)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
<<<<<<< HEAD
    vehicule w;
    w.show();
=======

    Connection c;
    if(!c.createconnect()) {
        qDebug() << "Erreur de connexion à la base de données!";
        return -1;
    }

    vehicules w; // <-- fenêtre principale
    w.show();

>>>>>>> ae4c4d6 (hello)
    return a.exec();
}
