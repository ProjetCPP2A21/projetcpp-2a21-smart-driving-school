# 📋 Guide d'Intégration - Projet_Louz12 → InterApp

## ✅ Fichiers Intégrés

### 1. **Gestion Biométrique (Empreinte Digitale)**
- ✅ `empriente.h` - Interface lecteur d'empreinte digitale
- ✅ `empriente.cpp` - Implémentation connexion Arduino + vérification BD
  - Détection automatique du port Arduino
  - Conversion hex → décimal
  - Vérification ID dans table `APPRENANTS`

### 2. **Gestion des Véhicules**
- ✅ `vehicule.h` - Maintenu (interface inchangée)
- ✅ `vehicule.cpp` - Maintenu
- ✅ Fichiers UI (vehicule.ui, vehicules.ui, etc.)

### 3. **Gestion de Maintenance**
- ✅ `maintenance.h` - Fonctionnalités complètes conservées
- ✅ `maintenance.cpp` - Implémentation maintenances programmées
- ✅ `update_database.sql` - Scripts BD pour tables maintenance

### 4. **Support Fichiers**
- ✅ `logo.h/cpp` - Classe logo (basique)
- ✅ `vehicules_slots_impl.cpp` - Slot implementations

### 5. **Configuration Projet**
- ✅ `interapp.pro` - Mise à jour avec tous les sources/headers

---

## 🔗 Intégrations Effectuées

### `examens.h`
```cpp
#include "empriente.h"  // ← Nouveau
private:
    Empriente *m_empreinte;  // ← Nouveau
    void afficherResultatEmpreinte(QString res);  // ← Nouveau slot
```

### `examens.cpp`
```cpp
// Dans le constructeur
m_empreinte = new Empriente(this);
if (m_empreinte->connecterArduino()) {
    connect(m_empreinte, &Empriente::fingerprintResult, 
            this, &examens::afficherResultatEmpreinte);
}

// Nouveau slot pour traiter les résultats
void examens::afficherResultatEmpreinte(QString res) { ... }
```

---

## 📱 Fonctionnalités Maintenant Disponibles

### **Biométrie**
- Lecture empreinte digitale via Arduino
- Vérification automatique en BD (table APPRENANTS)
- Détection port auto (COM3, COM4, COM5, etc.)
- Messages utilisateur (inscrit/non inscrit)

### **Véhicules**
- Gestion complète CRUD
- Filtrage avancé
- Export PDF
- Statistiques

### **Maintenance Préventive**
- Planification d'entretien
- Alertes kilométriques
- Calendrier de maintenance
- Historique

---

## 🛠️ Configuration Requise

### 1. **Port Arduino**
Le système tente automatiquement de détecter le port :
- Variable d'environnement `ARDUINO_PORT`
- Settings Qt (`Arduino/Port`)
- COM3 par défaut
- Sélection manuelle si nécessaire

### 2. **Base de Données**
```sql
-- Assurez-vous que la table APPRENANTS existe avec:
CREATE TABLE APPRENANTS (
    ID_EMPREINTE INT PRIMARY KEY,
    ...
);
```

### 3. **Modules Qt Requis**
Dans `interapp.pro` :
```
QT += serialport  # Pour communication Arduino
```

---

## 🚀 Démarrage Rapide

1. **Compiler le projet :**
   ```bash
   qmake interapp.pro
   make
   ```

2. **Connecter l'Arduino :**
   - Brancher le lecteur d'empreinte
   - L'app détectera automatiquement le port

3. **Tester :**
   - Aller à la page Examens
   - Placer doigt sur lecteur
   - Vérification automatique en BD

---

## ⚠️ Points d'Attention

### **Port COM**
- Si Arduino ne se détecte pas, changer le port dans le code ou via env variable
- Voir `empriente.cpp` ligne ~19

### **Base de Données**
- Vérifier que `APPRENANTS` a colonne `ID_EMPREINTE`
- Exécuter `update_database.sql` pour tables maintenance

### **Configuration ODBC**
- DataSource: `Source_Projet2A`
- User: `islem`
- Password: `islem`

---

## 📊 Architecture de Communication

```
Arduino → Port Série (COM3) 
    ↓ [Empriente::connecterArduino()]
    ↓ [Empriente::lirePort()]
    ↓ Signal: fingerprintResult(QString)
examens::afficherResultatEmpreinte()
    ↓ [verifierIDDansBase()] 
    ↓ SELECT ID_EMPREINTE FROM APPRENANTS
BD Oracle
```

---

## 📝 Notes

- Le projet `projet_louz12` était spécialisé **véhicules/maintenance**
- `InterApp` (arduion pull) est une plateforme **complète école de conduite**
- L'intégration combine les deux : gestion biométrique + examens + véhicules
- Tous les fichiers essentiels ont été copiés/intégrés
- Pas de régression : code existant conservé

---

## 🔄 Prochaines Étapes

1. Compiler et tester
2. Vérifier connexion Arduino
3. Tester lecture empreinte digitale
4. Valider synchronisation BD

