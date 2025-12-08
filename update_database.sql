-- Ajout des tables nécessaires pour la gestion de la maintenance
-- À exécuter sur la base de données Oracle après la création des tables de base

-- Table des types de maintenance
CREATE TABLE IF NOT EXISTS type_maintenance (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nom TEXT NOT NULL,
    description TEXT,
    intervalle_km INTEGER NOT NULL,
    intervalle_mois INTEGER NOT NULL
);

-- Table des maintenances programmées
CREATE TABLE IF NOT EXISTS maintenance (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    vehicule_id INTEGER NOT NULL,
    type_maintenance_id INTEGER NOT NULL,
    date_planifiee DATE NOT NULL,
    date_reelle DATE,
    kilometrage_planifie INTEGER NOT NULL,
    kilometrage_reel INTEGER,
    statut TEXT NOT NULL, -- 'planifiee', 'terminee', 'annulee'
    notes TEXT,
    FOREIGN KEY (vehicule_id) REFERENCES vehicule(id),
    FOREIGN KEY (type_maintenance_id) REFERENCES type_maintenance(id)
);

-- Table des créneaux de maintenance
CREATE TABLE IF NOT EXISTS creneaux_maintenance (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    jour_semaine INTEGER NOT NULL, -- 1 (lundi) à 7 (dimanche)
    heure_debut TIME NOT NULL,
    heure_fin TIME NOT NULL,
    actif BOOLEAN DEFAULT 1
);

-- Table des indisponibilités (créneaux déjà réservés)
CREATE TABLE IF NOT EXISTS indisponibilites (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    date_debut DATETIME NOT NULL,
    date_fin DATETIME NOT NULL,
    raison TEXT,
    maintenance_id INTEGER,
    FOREIGN KEY (maintenance_id) REFERENCES maintenance(id)
);

-- Table pour l'historique des alertes SMS (éviter la redondance)
CREATE TABLE IF NOT EXISTS alertes_sms (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    vehicule_id INTEGER NOT NULL,
    kilometrage REAL NOT NULL,
    date_envoi DATETIME DEFAULT CURRENT_TIMESTAMP,
    numero_destinataire TEXT,
    message TEXT,
    statut TEXT DEFAULT 'envoye', -- 'envoye', 'echeoue'
    FOREIGN KEY (vehicule_id) REFERENCES vehicules(id_vehicule)
);

-- Insertion des types de maintenance par défaut
INSERT OR IGNORE INTO type_maintenance (nom, description, intervalle_km, intervalle_mois) 
VALUES 
('Vidange', 'Vidange d''huile et changement du filtre à huile', 10000, 12),
('Révision complète', 'Révision complète du véhicule', 30000, 24),
('Freinage', 'Contrôle et remplacement des plaquettes/disques de frein', 20000, 24),
('Pneumatiques', 'Contrôle et remplacement des pneus', 50000, 36),
('Distribution', 'Changement de la courroie de distribution', 100000, 60);

-- Insertion des créneaux de maintenance par défaut (9h-12h et 14h-17h du lundi au vendredi)
INSERT OR IGNORE INTO creneaux_maintenance (jour_semaine, heure_debut, heure_fin, actif)
SELECT jour, '09:00:00', '12:00:00', 1
FROM (SELECT 1 AS jour UNION SELECT 2 UNION SELECT 3 UNION SELECT 4 UNION SELECT 5) AS jours
UNION ALL
SELECT jour, '14:00:00', '17:00:00', 1
FROM (SELECT 1 AS jour UNION SELECT 2 UNION SELECT 3 UNION SELECT 4 UNION SELECT 5) AS jours;
