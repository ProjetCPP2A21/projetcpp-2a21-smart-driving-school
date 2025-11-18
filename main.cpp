#include "examens.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;

    if (!c.createconnect()) {
        QMessageBox::critical(nullptr, "Erreur", "Connexion échouée !");
        return 0;
    }

    QMessageBox::information(nullptr, "Connexion", "Connexion réussie !");

    examens w;
    w.show();



    return a.exec();
}
