# 📋 Liste Complète des Boutons du Menu - Noms Exactes

## 🎯 Boutons à Créer dans Qt Designer (Page Menu - Index 1)

### ✅ Noms EXACTS des Boutons (OBLIGATOIRES)

| Texte du Bouton | Nom du Widget (Object Name) | Page Cible | Index |
|-----------------|----------------------------|------------|-------|
| **Apprenants** | `pushButton_apprenants` | Page Apprenants | 3 |
| **Examens** | `pushButton_examens` | Page Examens | 2 |
| **Véhicules** | `pushButton_vehicules` | Page Véhicules | 4 |
| **Moniteurs** | `pushButton_moniteurs` | Page Moniteurs | 5 |
| **Paiements** | `pushButton_paiements` | Page Paiements | 6 |

---

## 📝 Instructions pour Qt Designer

### Étape 1 : Aller sur la Page Menu
1. Ouvrez `application_integree.ui` dans Qt Designer
2. Sélectionnez le `QStackedWidget`
3. Allez sur la **page 1** (Menu principal)

### Étape 2 : Créer/Ajouter les Boutons

Pour chaque bouton :

1. **Glissez un QPushButton** sur la page Menu
2. **Cliquez droit** sur le bouton → **Change objectName**
3. **Donnez le nom EXACT** de la colonne "Nom du Widget"
4. **Changez le texte** du bouton (colonne "Texte du Bouton")

### Exemple pour le bouton Paiements :

```
1. Glisser QPushButton
2. Object Name: pushButton_paiements
3. Text: "Paiements"
```

---

## ✅ Code Déjà Implémenté

Tous ces boutons sont **déjà connectés** dans le code :

### 1. Bouton Apprenants
```cpp
void application_integree::on_pushButton_apprenants_clicked()
{
    ui->stackedWidget->setCurrentIndex(3); // Page Apprenants
    afficherApprenants();
}
```

### 2. Bouton Examens
```cpp
void application_integree::on_pushButton_examens_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); // Page Examens
    ui->tableView_examens->setModel(Examen().afficher());
    ui->tableView_examens->clearSelection();
}
```

### 3. Bouton Véhicules
```cpp
void application_integree::on_pushButton_vehicules_clicked()
{
    ui->stackedWidget->setCurrentIndex(4); // Page Véhicules
    afficherVehicules();
    ui->tableView_vehicules->clearSelection();
}
```

### 4. Bouton Moniteurs
```cpp
void application_integree::on_pushButton_moniteurs_clicked()
{
    ui->stackedWidget->setCurrentIndex(5); // Page Moniteurs
    afficherMoniteurs();
    ui->table->clearSelection();
}
```

### 5. Bouton Paiements
```cpp
void application_integree::on_pushButton_paiements_clicked()
{
    ui->stackedWidget->setCurrentIndex(6); // Page Paiements
    afficherPaiements();
    // ... nettoyage
}
```

---

## 🎨 Interface Visuelle du Menu

```
┌─────────────────────────────────────────┐
│         MENU PRINCIPAL                  │
│         (Page Index 1)                  │
├─────────────────────────────────────────┤
│                                         │
│  ┌─────────────┐  ┌─────────────┐     │
│  │ Apprenants  │  │   Examens   │     │
│  │             │  │             │     │
│  └─────────────┘  └─────────────┘     │
│                                         │
│  ┌─────────────┐  ┌─────────────┐     │
│  │  Véhicules  │  │  Moniteurs  │     │
│  │             │  │             │     │
│  └─────────────┘  └─────────────┘     │
│                                         │
│  ┌─────────────┐                       │
│  │  Paiements  │                       │
│  │             │                       │
│  └─────────────┘                       │
│                                         │
└─────────────────────────────────────────┘
```

---

## ⚠️ Points Importants

### 1. Respecter la Casse
- ✅ `pushButton_paiements` (correct)
- ❌ `PushButton_Paiements` (incorrect)
- ❌ `pushbutton_paiements` (incorrect)

### 2. Pas d'Espaces
- ✅ `pushButton_apprenants` (correct)
- ❌ `pushButton apprenants` (incorrect)

### 3. Connexion Automatique
Qt connecte automatiquement les slots basés sur le nom :
- Bouton nommé `pushButton_paiements` → Slot `on_pushButton_paiements_clicked()`
- **Pas besoin de connexion manuelle !**

---

## 🧪 Test de Chaque Bouton

### Test 1 : Apprenants
1. Lancer l'application
2. Se connecter
3. Cliquer sur "Apprenants"
4. ✅ Page Apprenants s'ouvre (index 3)

### Test 2 : Examens
1. Retour au menu
2. Cliquer sur "Examens"
3. ✅ Page Examens s'ouvre (index 2)

### Test 3 : Véhicules
1. Retour au menu
2. Cliquer sur "Véhicules"
3. ✅ Page Véhicules s'ouvre (index 4)

### Test 4 : Moniteurs
1. Retour au menu
2. Cliquer sur "Moniteurs"
3. ✅ Page Moniteurs s'ouvre (index 5)

### Test 5 : Paiements
1. Retour au menu
2. Cliquer sur "Paiements"
3. ✅ Page Paiements s'ouvre (index 6)

---

## 📋 Checklist Finale

Dans Qt Designer, sur la **Page Menu (Index 1)** :

- [ ] `pushButton_apprenants` existe
- [ ] `pushButton_examens` existe
- [ ] `pushButton_vehicules` existe
- [ ] `pushButton_moniteurs` existe
- [ ] `pushButton_paiements` existe

**Tous les noms sont EXACTEMENT comme indiqué ci-dessus !**

---

## 🎯 Résumé

**5 boutons** dans le menu :
1. `pushButton_apprenants` → Page 3
2. `pushButton_examens` → Page 2
3. `pushButton_vehicules` → Page 4
4. `pushButton_moniteurs` → Page 5
5. `pushButton_paiements` → Page 6

**Tous les slots sont déjà implémentés dans le code !**

Il suffit de créer les boutons avec les bons noms dans Qt Designer. ✅

