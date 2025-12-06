#ifndef APPRENANTS_H
#define APPRENANTS_H

#include <QMainWindow>
<<<<<<< HEAD
#include "apprenant.h"
=======
#include <QPushButton>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "apprenant.h"
#include "apichatbot.h"
#include "notification.h"
>>>>>>> 4229cbb (ajout arduino)

QT_BEGIN_NAMESPACE
namespace Ui { class apprenants; }
QT_END_NAMESPACE

class apprenants : public QMainWindow
{
    Q_OBJECT

public:
    explicit apprenants(QWidget *parent = nullptr);
    ~apprenants();

<<<<<<< HEAD
=======
protected:
    void resizeEvent(QResizeEvent *event) override;

>>>>>>> 4229cbb (ajout arduino)
private slots:
    void afficherApprenants();
    bool verifierSaisie(int &id, QString &nom, QString &prenom, QString &dateNaissance,
                        QString &tel, QString &sexe, QString &adresse);
<<<<<<< HEAD
=======
    void onChatbotResponse(const QString &response);
    void onChatbotError(const QString &error);
    void onChatbotButtonClicked();
>>>>>>> 4229cbb (ajout arduino)

    void on_pushButton_ajouter_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_trier_clicked();
    void on_lineEdit_recherche_textChanged(const QString &arg1);
    void on_pushButton_exporterPDF_clicked();
    void on_pushButton_statistique_clicked();
    void on_tableView_apprenants_clicked(const QModelIndex &index);

<<<<<<< HEAD
private:
    void reinitialiserFormulaire();
    void afficherMessageControle(const QString &message, bool erreur = true);
    Ui::apprenants *ui;
=======
private slots:
    void setupArduino();
    void lireArduino();

signals:
    void rfidDetected(const QString &uid);

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
>>>>>>> 4229cbb (ajout arduino)
};

#endif // APPRENANTS_H
