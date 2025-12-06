#include "modulemanager.h"
#include <QDebug>

ModuleManager* ModuleManager::m_instance = nullptr;

ModuleManager* ModuleManager::instance()
{
    if (!m_instance) {
        m_instance = new ModuleManager();
    }
    return m_instance;
}

ModuleManager::ModuleManager(QObject *parent)
    : QObject(parent)
    , m_settings("MonEntreprise", "GestionApprenants")
{
    chargerModules();
}

ModuleManager::~ModuleManager()
{
    sauvegarderModules();
}

void ModuleManager::ajouterModule(const Module &module)
{
    m_modules.append(module);
    emit modulesModifies();
}

void ModuleManager::supprimerModule(int id)
{
    for (int i = 0; i < m_modules.size(); ++i) {
        if (m_modules[i].id == id) {
            m_modules.remove(i);
            emit modulesModifies();
            return;
        }
    }
}

void ModuleManager::mettreAJourModule(const Module &module)
{
    for (auto &m : m_modules) {
        if (m.id == module.id) {
            m = module;
            emit modulesModifies();
            return;
        }
    }
    // Si le module n'existe pas, on l'ajoute
    ajouterModule(module);
}

QVector<Module> ModuleManager::getModules() const
{
    return m_modules;
}

Module ModuleManager::getModule(int id) const
{
    for (const auto &module : m_modules) {
        if (module.id == id) {
            return module;
        }
    }
    return Module();
}

void ModuleManager::chargerModules()
{
    m_modules.clear();
    
    // Charger les modules depuis les paramètres
    int size = m_settings.beginReadArray("modules");
    for (int i = 0; i < size; ++i) {
        m_settings.setArrayIndex(i);
        Module module;
        module.id = m_settings.value("id").toInt();
        module.nom = m_settings.value("nom").toString();
        module.description = m_settings.value("description").toString();
        module.icone = m_settings.value("icone").toString();
        module.estActif = m_settings.value("estActif", true).toBool();
        
        m_modules.append(module);
    }
    m_settings.endArray();
    
    // Si aucun module n'est chargé, ajouter des modules par défaut
    if (m_modules.isEmpty()) {
        ajouterModule(Module(1, "Théorie", "Module de théorie de la conduite", "📚"));
        ajouterModule(Module(2, "Pratique", "Module de conduite pratique", "🚗"));
        ajouterModule(Module(3, "Code de la route", "Questions et révisions du code", "🚦"));
        sauvegarderModules();
    }
}

void ModuleManager::sauvegarderModules() const
{
    m_settings.beginWriteArray("modules");
    for (int i = 0; i < m_modules.size(); ++i) {
        m_settings.setArrayIndex(i);
        m_settings.setValue("id", m_modules[i].id);
        m_settings.setValue("nom", m_modules[i].nom);
        m_settings.setValue("description", m_modules[i].description);
        m_settings.setValue("icone", m_modules[i].icone);
        m_settings.setValue("estActif", m_modules[i].estActif);
    }
    m_settings.endArray();
}

void ModuleManager::activerModule(int id, bool actif)
{
    for (auto &module : m_modules) {
        if (module.id == id) {
            module.estActif = actif;
            emit modulesModifies();
            sauvegarderModules();
            return;
        }
    }
}

bool ModuleManager::estModuleActif(int id) const
{
    for (const auto &module : m_modules) {
        if (module.id == id) {
            return module.estActif;
        }
    }
    return false;
}
