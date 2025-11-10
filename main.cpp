<<<<<<< HEAD
#include "application_integree.h"
=======
#include "examens.h"
>>>>>>> 6261b74d60c6f1db7570688dee03222a2a4f5da2
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;

<<<<<<< HEAD
    if(c.createconnect()){
        QMessageBox::information(nullptr, "Connexion", "Connexion réussie !");
        application_integree w;
        w.show();
        return a.exec();
    }
    else{
        QMessageBox::critical(nullptr, "Erreur", "Échec de la connexion à la base de données");
        return 0;
    }
}


=======
    if (c.createconnect()) {
        QMessageBox::information(nullptr, "Connexion", "Connexion réussie !");
        examens w;
        w.show();
        return a.exec();
    } else {
        QMessageBox::critical(nullptr, "Erreur", "Connexion échouée !");
        return 0;
    }
}
>>>>>>> 6261b74d60c6f1db7570688dee03222a2a4f5da2
