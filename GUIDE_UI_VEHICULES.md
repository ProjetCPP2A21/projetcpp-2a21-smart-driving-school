# Guide pour créer l'interface Véhicules dans Qt Designer

## Étape 1 : Ouvrir le projet dans Qt Creator

1. Ouvrir Qt Creator
2. File → Open File or Project
3. Naviguer vers : `application_integree/application_integree/application_integree.pro`
4. Cliquer sur "Open"

## Étape 2 : Ouvrir le fichier UI

1. Dans Qt Creator, dans l'explorateur de projet, double-cliquer sur `application_integree.ui`
2. Le fichier s'ouvre dans Qt Designer

## Étape 3 : Ajouter la page Véhicules au QStackedWidget

1. Dans Qt Designer, trouver le `QStackedWidget` dans la hiérarchie des widgets
2. Cliquer avec le bouton droit sur le QStackedWidget
3. Sélectionner "Insert Page" ou "Add Page"
4. Une nouvelle page (index 4) sera créée

## Étape 4 : Ajouter tous les widgets nécessaires sur la page Véhicules

Sur la page 4 (Véhicules), ajouter les widgets suivants avec les noms EXACTS :

### Champs de saisie (QLineEdit) :
- `lineEdit_marque_vehicule` - pour la marque
- `lineEdit_immatriculation_vehicule` - pour l'immatriculation
- `lineEdit_kilometrage_vehicule` - pour le kilométrage
- `lineEdit_capacite_vehicule` - pour la capacité
- `lineEdit_recherche_vehicule` - pour la recherche

### ComboBox :
- `comboBox_type_vehicule` - pour le type (Berline manuelle, Berline automatique, SUV manuel, SUV automatique)
- `comboBox_etat_vehicule` - pour l'état (Bon, Moyen, A reviser)
- `comboBox_disponibilite_vehicule` - pour la disponibilité (Disponible, Reserve, En maintenance)

### TableView :
- `tableView_vehicules` - pour afficher la liste des véhicules

### Boutons (QPushButton) :
- `pushButton_ajouter_vehicule` - pour ajouter un véhicule
- `pushButton_modifier_vehicule` - pour modifier un véhicule
- `pushButton_supprimer_vehicule` - pour supprimer un véhicule
- `pushButton_trier_vehicule` - pour trier les véhicules
- `pushButton_exporterPDF_vehicule` - pour exporter en PDF
- `pushButton_statistique_vehicule` - pour afficher les statistiques
- `pushButton_retour_vehicules` - pour retourner au menu

## Étape 5 : Ajouter le bouton Véhicules dans le Menu

1. Aller sur la page 1 (Menu) du QStackedWidget
2. Ajouter un QPushButton
3. Le nommer : `pushButton_vehicules`
4. Mettre le texte : "Véhicules"

## Étape 6 : Sauvegarder et compiler

1. Sauvegarder le fichier UI (Ctrl+S)
2. Dans Qt Creator, cliquer sur "Build" → "Rebuild Project"
3. Les erreurs devraient disparaître

## Structure finale du QStackedWidget :

- Page 0 : Login
- Page 1 : Menu (avec pushButton_apprenants, pushButton_examens, pushButton_vehicules)
- Page 2 : Examens
- Page 3 : Apprenants
- Page 4 : Véhicules (NOUVELLE PAGE)

## Notes importantes :

- Les noms des widgets DOIVENT être EXACTEMENT comme indiqué ci-dessus
- Respecter la casse (majuscules/minuscules)
- Le tableView_vehicules doit être un QTableView
- Tous les lineEdit doivent être des QLineEdit
- Tous les comboBox doivent être des QComboBox
- Tous les boutons doivent être des QPushButton

## Si vous avez déjà un fichier vehicule.ui :

Vous pouvez copier les widgets de vehicule.ui et les renommer selon la liste ci-dessus.

