#ifndef PAIEMENTMODULE_H
#define PAIEMENTMODULE_H

#include "module.h"
#include "mainwindow.h"
#include <QWidget>

class PaiementModule : public QObject
{
    Q_OBJECT

public:
    explicit PaiementModule(QObject *parent = nullptr);
    ~PaiementModule();

    // Implémentation de l'interface Module
    QString getNom() const { return "Paiement"; }
    QString getDescription() const { return "Gestion des paiements des apprenants"; }
    QString getIcone() const { return ":/icons/paiement.png"; }
    bool estActif() const { return m_estActif; }
    void setActif(bool actif) { m_estActif = actif; }
    
    // Méthodes spécifiques au module
    void afficherInterface(QWidget *parent = nullptr);
    void masquerInterface();

private:
    bool m_estActif;
    MainWindow *m_mainWindow;
};

#endif // PAIEMENTMODULE_H
