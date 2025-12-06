#ifndef APPRENANTS_H
#define APPRENANTS_H

#include <QMainWindow>
#include <QPushButton>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "apprenant.h"
#include "apichatbot.h"
#include "notification.h"

QT_BEGIN_NAMESPACE
namespace Ui { class apprenants; }
QT_END_NAMESPACE

class apprenants : public QMainWindow
{
    Q_OBJECT

public:
    explicit apprenants(QWidget *parent = nullptr);
    ~apprenants();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void afficherApprenants();
    bool verifierSaisie(int &id, QString &nom, QString &prenom, QString &dateNaissance,
                        QString &tel, QString &sexe, QString &adresse, bool estModification = false);
    void onChatbotResponse(const QString &response);
    void onChatbotError(const QString &error);
    void onChatbotButtonClicked();

    void on_pushButton_ajouter_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_trier_clicked();
    void on_lineEdit_recherche_textChanged(const QString &arg1);
    void on_pushButton_exporterPDF_clicked();
    void on_pushButton_statistique_clicked();
    void on_tableView_apprenants_clicked(const QModelIndex &index);

private slots:
    void on_Retour_clicked();  // Slot pour le bouton Retour
    void setupArduino();
    void lireArduino();

signals:
    void rfidDetected(const QString &uid);
    void returnRequested();

private:
    void reinitialiserFormulaire();
    void afficherMessageControle(const QString &message, bool erreur = true);
    void afficherNotification(const QString &titre, const QString &message, NotificationType type, int dureeAffichage = 5000);
    void nettoyerNotifications();

    QSerialPort *arduino;
    Ui::apprenants *ui;
    ApiChatBot *m_chatbot;
    QPushButton *chatbotButton;  // Bouton de l'assistant
    QList<Notification*> m_notifications;  // Liste des notifications actives
};

#endif // APPRENANTS_H
