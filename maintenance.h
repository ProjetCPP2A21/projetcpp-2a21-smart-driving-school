#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <QObject>
#include <QString>
#include <QDate>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QList>
#include <QMap>
#include <QVariant>

class Maintenance;

struct CreneauMaintenance {
    QDateTime debut;
    QDateTime fin;
    bool estDisponible;
};

class Maintenance : public QObject
{
    Q_OBJECT

public:
    explicit Maintenance(QObject *parent = nullptr);
    ~Maintenance();

    // Méthode pour définir la connexion à utiliser
    void setDatabaseConnection(const QSqlDatabase &db);
    
    // Getters
    int getId() const { return id; }
    int getVehiculeId() const { return vehiculeId; }
    QString getType() const { return type; }
    QDate getDateDebut() const { return dateDebut; }
    QDate getDateFin() const { return dateFin; }
    QString getStatut() const { return statut; }
    QString getDescription() const { return description; }
    
    // Setters
    void setId(int value) { id = value; }
    void setVehiculeId(int value) { vehiculeId = value; }
    void setType(const QString &value) { type = value; }
    void setDateDebut(const QDate &value) { dateDebut = value; }
    void setDateFin(const QDate &value) { dateFin = value; }
    void setStatut(const QString &value) { statut = value; }
    void setDescription(const QString &value) { description = value; }
    
    // Database operations
    bool ajouter();
    bool modifier();
    bool supprimer();
    
    // Maintenance operations
    bool planifierMaintenance(int vehiculeId, int typeMaintenanceId, const QDateTime &dateSouhaitee);
    void verifierMaintenancesRequises();
    QList<CreneauMaintenance> trouverCreneauxDisponibles(const QDate &dateDebut, const QDate &dateFin, int dureeMinutes) const;
    bool verifierDisponibiliteCreneau(const QDateTime &debut, const QDateTime &fin, int vehiculeId) const;
    bool envoyerNotificationMaintenance(const QString &message, const QStringList &destinataires);
    bool validerMaintenance(int maintenanceId, const QDateTime &dateReelle, int kilometrageReel);
    bool annulerMaintenance(int maintenanceId, const QString &raison);
    QList<QMap<QString, QVariant>> obtenirMaintenancesAVenir(int vehiculeId = -1) const;
    QList<QMap<QString, QVariant>> obtenirHistoriqueMaintenance(int vehiculeId = -1) const;
    bool reserverCreneau(const QDateTime &debut, const QDateTime &fin, int maintenanceId, const QString &raison);

    // Alertes prédictives (SMS supprimé)
    void planifierEntretienAutomatique(int vehiculeId, const QString &typeEntretien, int kilometrageDeclencheur);
    

private:
    QList<QMap<QString, QVariant>> executerRequete(const QString &requete, const QVariantList &params = QVariantList()) const;
    QDateTime calculerProchaineEcheance(int vehiculeId, int typeMaintenanceId) const;
    void creerEvenementCalendrier(const QDateTime &debut, const QDateTime &fin, const QString &titre, const QString &description);
    
    int id;
    int vehiculeId;
    QString type;
    QDate dateDebut;
    QDate dateFin;
    QString statut;
    QString description;
    QSqlDatabase m_db;
};

#endif // MAINTENANCE_H
