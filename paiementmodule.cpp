#include "paiementmodule.h"
#include <QMessageBox>

PaiementModule::PaiementModule(QObject *parent)
    : QObject(parent), m_estActif(false), m_mainWindow(nullptr)
{
}

PaiementModule::~PaiementModule()
{
    if (m_mainWindow) {
        delete m_mainWindow;
    }
}

void PaiementModule::afficherInterface(QWidget *parent)
{
    if (!m_mainWindow) {
        m_mainWindow = new MainWindow();
    }
    
    if (m_mainWindow) {
        m_mainWindow->show();
        m_mainWindow->raise();
        m_mainWindow->activateWindow();
    }
}

void PaiementModule::masquerInterface()
{
    if (m_mainWindow) {
        m_mainWindow->hide();
    }
}
