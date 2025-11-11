# 🎨 Guide Qt Designer - Modifications Nécessaires

## ✅ Code C++ : DÉJÀ PRÊT - Ne Rien Changer !

Le code C++ est **100% fonctionnel**. Vous n'avez **RIEN à modifier** dans les fichiers `.cpp` et `.h`.

---

## 📋 Ce qu'il faut faire DANS QT DESIGNER SEULEMENT

### Étape 1 : Ouvrir le Fichier UI

1. Ouvrez Qt Creator
2. Ouvrez le projet `application_integree.pro`
3. Double-cliquez sur `application_integree.ui` pour ouvrir Qt Designer

---

### Étape 2 : Vérifier/Créer les Boutons du Menu

1. **Sélectionnez** le `QStackedWidget` dans la hiérarchie
2. **Allez sur la page Index 1** (Menu principal)
3. **Vérifiez** que ces 5 boutons existent :

#### Liste des Boutons à Vérifier/Créer :

| # | Nom du Widget (Object Name) | Texte du Bouton |
|---|----------------------------|-----------------|
| 1 | `pushButton_apprenants` | Apprenants |
| 2 | `pushButton_examens` | Examens |
| 3 | `pushButton_vehicules` | Véhicules |
| 4 | `pushButton_moniteurs` | Moniteurs |
| 5 | `pushButton_paiements` | Paiements |

#### Comment Créer un Bouton :

1. **Glissez** un `QPushButton` depuis la palette
2. **Cliquez droit** sur le bouton → **Change objectName...**
3. **Tapez** le nom exact (ex: `pushButton_paiements`)
4. Dans **Propriétés** → **text**, mettez le texte (ex: "Paiements")

---

### Étape 3 : Créer la Page Paiements (Index 6)

1. **Sélectionnez** le `QStackedWidget`
2. **Cliquez** sur "Add Page" ou "Ajouter une page"
3. **Vérifiez** que c'est bien la page **Index 6**
4. **Copiez** les widgets depuis `paiement/mainwindow.ui` :

#### Widgets à Copier :

| Widget | Nom (Object Name) | Type |
|--------|------------------|------|
| Tableau | `tabView` | QTableView |
| ID | `ID` | QLineEdit |
| Type | `Type` | QComboBox |
| Date | `Date` | QDateEdit |
| Heure | `heure` | QTimeEdit |
| Montant | `montant` | QLineEdit |
| Ajouter | `ajouter` | QPushButton |
| Modifier | `modifier` | QPushButton |
| Supprimer | `supprimer` | QPushButton |
| Retour | `Retour` | QPushButton |

#### Configuration du ComboBox Type :

1. **Sélectionnez** le `QComboBox` nommé `Type`
2. Dans **Propriétés** → **Items**, ajoutez :
   - "modes de paiement"
   - "visa"
   - "paypal"
   - "espèces"

---

### Étape 4 : Vérifier les Index des Pages

Assurez-vous que les pages sont dans cet ordre :

```
QStackedWidget
├── Page 0 : Login
├── Page 1 : Menu
├── Page 2 : Examens
├── Page 3 : Apprenants
├── Page 4 : Véhicules
├── Page 5 : Moniteurs
└── Page 6 : Paiements ← À CRÉER
```

**Comment vérifier l'index** :
- Sélectionnez le `QStackedWidget`
- Dans la liste des pages, l'index est affiché

---

### Étape 5 : Sauvegarder

1. **Ctrl + S** pour sauvegarder
2. **Fermez** Qt Designer
3. **Retournez** dans Qt Creator

---

## ✅ Checklist Qt Designer

### Page Menu (Index 1)
- [ ] `pushButton_apprenants` existe
- [ ] `pushButton_examens` existe
- [ ] `pushButton_vehicules` existe
- [ ] `pushButton_moniteurs` existe
- [ ] `pushButton_paiements` existe

### Page Paiements (Index 6)
- [ ] Page créée
- [ ] `tabView` (QTableView) existe
- [ ] `ID` (QLineEdit) existe
- [ ] `Type` (QComboBox) avec items configurés
- [ ] `Date` (QDateEdit) existe
- [ ] `heure` (QTimeEdit) existe
- [ ] `montant` (QLineEdit) existe
- [ ] `ajouter` (QPushButton) existe
- [ ] `modifier` (QPushButton) existe
- [ ] `supprimer` (QPushButton) existe
- [ ] `Retour` (QPushButton) existe

---

## 🧪 Test Final

1. **Compilez** le projet (Build → Rebuild Project)
2. **Lancez** l'application (Run)
3. **Connectez-vous** (aaaa / 0000)
4. **Testez chaque bouton** :
   - ✅ Apprenants → Page 3
   - ✅ Examens → Page 2
   - ✅ Véhicules → Page 4
   - ✅ Moniteurs → Page 5
   - ✅ Paiements → Page 6

---

## ⚠️ Points Importants

1. **Ne modifiez PAS** les fichiers `.cpp` et `.h`
2. **Respectez EXACTEMENT** les noms des widgets (casse, underscores)
3. **Vérifiez** que les index des pages sont corrects
4. **Sauvegardez** avant de compiler

---

## 🎯 Résumé

**Code C++** : ✅ Prêt - Ne rien changer  
**Qt Designer** : ⚠️ À faire - Créer les boutons et la page paiements

**C'est tout !** 🚀

