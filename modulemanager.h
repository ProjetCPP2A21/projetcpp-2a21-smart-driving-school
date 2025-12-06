#ifndef MODULEMANAGER_H
#define MODULEMANAGER_H

#include "module.h"
#include <QObject>
#include <QVector>
#include <QSettings>

class ModuleManager : public QObject
{
    Q_OBJECT

public:
    static ModuleManager* instance();
    
    // Gestion des modules
    void ajouterModule(const Module &module);
    void supprimerModule(int id);
    void mettreAJourModule(const Module &module);
    QVector<Module> getModules() const;
    Module getModule(int id) const;
    
    // Charger/sauvegarder les modules
    void chargerModules();
    void sauvegarderModules() const;
    
    // Activer/désactiver un module
    void activerModule(int id, bool actif = true);
    
    // Vérifier si un module est actif
    bool estModuleActif(int id) const;

signals:
    void modulesModifies();

private:
    explicit ModuleManager(QObject *parent = nullptr);
    ~ModuleManager();
    
    static ModuleManager* m_instance;
    QVector<Module> m_modules;
    QSettings m_settings;
};

#endif // MODULEMANAGER_H
