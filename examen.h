#ifndef EXAMEN_H
#define EXAMEN_H

#include <QString>
#include <QSqlQueryModel>

class Examen
{
public:
    Examen();
    Examen(int, QString, QString, QString, QString, QString, QString);

    bool ajouter();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel* afficher();

private:
    int id;
    QString type;
    QString date;
    QString heure;
    QString lieu;
    QString vehicule;
    QString resultat;
};

#endif // EXAMEN_H
<<<<<<< HEAD


=======
>>>>>>> 6261b74d60c6f1db7570688dee03222a2a4f5da2
