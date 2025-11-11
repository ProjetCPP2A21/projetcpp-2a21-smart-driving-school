# Guide d'Intégration du Module Paiement

## ✅ Ce qui a été fait automatiquement

1. ✅ Fichiers `paiement.h` et `paiement.cpp` copiés et adaptés
2. ✅ Code C++ intégré dans `application_integree.cpp` et `.h`
3. ✅ Fichier `.pro` mis à jour
4. ✅ Bouton "Véhicules" modifié pour ouvrir la page Paiement (index 6)

## 📋 Ce que vous devez faire dans Qt Designer

### Étape 1 : Ouvrir le fichier UI
1. Ouvrez `application_integree.ui` dans Qt Designer
2. Trouvez le `QStackedWidget` dans votre interface

### Étape 2 : Ajouter une nouvelle page
1. Dans le `QStackedWidget`, ajoutez une **nouvelle page** (index 6)
2. Cette page sera votre interface de paiement

### Étape 3 : Copier les widgets depuis mainwindow.ui du projet paiement

Vous devez copier les widgets suivants depuis `paiement/mainwindow.ui` vers la nouvelle page (index 6) :

#### Widgets à copier :

1. **QTableView** nommé `tableView_paiements` (ou `tabView`)
   - C'est le tableau qui affiche les paiements

2. **QLineEdit** nommé `ID` ou `lineEdit_id_paiement`
   - Pour l'ID du paiement

3. **QComboBox** nommé `Type` ou `comboBox_type_paiement`
   - Pour le type de paiement
   - Ajoutez les items : "modes de paiement", "visa", "paypal", "espèces"

4. **QDateEdit** nommé `Date` ou `dateEdit_date_paiement`
   - Pour la date du paiement

5. **QTimeEdit** nommé `heure` ou `timeEdit_heure_paiement`
   - Pour l'heure du paiement

6. **QLineEdit** nommé `montant` ou `lineEdit_montant_paiement`
   - Pour le montant

7. **QPushButton** nommé `ajouter` ou `pushButton_ajouter_paiement`
   - Bouton pour ajouter un paiement

8. **QPushButton** nommé `modifier` ou `pushButton_modifier_paiement`
   - Bouton pour modifier un paiement

9. **QPushButton** nommé `supprimer` ou `pushButton_supprimer_paiement`
   - Bouton pour supprimer un paiement

10. **QPushButton** nommé `Retour` ou `pushButton_retour_paiements`
    - Bouton pour retourner au menu

### Étape 4 : Nommer les widgets correctement

**IMPORTANT** : Le code supporte deux noms possibles pour chaque widget :
- Les noms originaux du projet paiement (ex: `ID`, `Type`, `Date`, `heure`, `montant`, `tabView`)
- Les noms avec préfixe (ex: `lineEdit_id_paiement`, `comboBox_type_paiement`, etc.)

**Recommandation** : Utilisez les noms originaux (`ID`, `Type`, `Date`, `heure`, `montant`, `tabView`) pour plus de simplicité.

### Étape 5 : Connecter les signaux

Les connexions se font automatiquement grâce aux noms des slots :
- `on_pushButton_ajouter_paiement_clicked()` → se connecte automatiquement si le bouton s'appelle `pushButton_ajouter_paiement`
- `on_ajouter_clicked()` → se connecte automatiquement si le bouton s'appelle `ajouter`
- `on_tableView_paiements_clicked()` → se connecte automatiquement au clic sur `tableView_paiements`

### Étape 6 : Vérifier l'index de la page

Assurez-vous que la page paiement est à l'**index 6** du QStackedWidget :
- Index 0 : Login
- Index 1 : Menu
- Index 2 : Examens
- Index 3 : Apprenants
- Index 4 : Véhicules (ancienne page)
- Index 5 : Moniteurs
- **Index 6 : Paiement** ← Votre nouvelle page

## 🔧 Configuration dans le code

Le code est déjà configuré pour :
- ✅ Utiliser la connexion par défaut (pas besoin de "oracle_connection")
- ✅ Gérer les deux systèmes de nommage des widgets
- ✅ Afficher les paiements dans le tableau
- ✅ CRUD complet (Ajouter, Modifier, Supprimer)
- ✅ Sélection dans le tableau pour modifier/supprimer

## 🧪 Test

Après avoir ajouté la page dans Qt Designer :

1. Compilez le projet
2. Lancez l'application
3. Connectez-vous
4. Cliquez sur le bouton **"Véhicules"** dans le menu
5. Vous devriez voir la page de paiement s'ouvrir

## ⚠️ Notes importantes

1. **Format de date** : Le code utilise le format `dd-MM-yyyy` (ex: 25-12-2024)
2. **Format d'heure** : Le code utilise le format `hh:mm` (ex: 14:30)
3. **Base de données** : Assurez-vous que la table `PAIEMENTS` existe avec les colonnes :
   - `ID_PAIEMENT` (INT)
   - `TYPE_PAIEMENT` (VARCHAR)
   - `DATE_PAIEMENT` (DATE)
   - `HEURE_PAIEMENT` (VARCHAR)
   - `MONTANT` (DOUBLE)
   - `ID_APPRENANT` (INT, nullable)

## 🐛 Dépannage

Si la page ne s'ouvre pas :
1. Vérifiez que la page est bien à l'index 6
2. Vérifiez que les noms des widgets correspondent
3. Vérifiez les erreurs de compilation dans Qt Creator

Si les boutons ne fonctionnent pas :
1. Vérifiez que les noms des boutons correspondent aux slots
2. Vérifiez que les connexions sont bien faites dans Qt Designer

Si le tableau est vide :
1. Vérifiez la connexion à la base de données
2. Vérifiez que la table `PAIEMENTS` existe
3. Vérifiez les logs dans la console Qt Creator

