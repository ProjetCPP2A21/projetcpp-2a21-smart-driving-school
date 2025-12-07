#ifndef MODULE_H
#define MODULE_H

#include <QString>

struct Module {
    int id;
    QString nom;
    QString description;
    QString icone;
    bool estActif;
    
    Module(int id = 0, const QString &nom = "", const QString &description = "", 
           const QString &icone = "", bool estActif = true)
        : id(id), nom(nom), description(description), icone(icone), estActif(estActif) {}
};

#endif // MODULE_H
