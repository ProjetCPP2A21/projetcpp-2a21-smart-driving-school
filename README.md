# Application Intégrée - Apprenants et Examens

Cette application combine les fonctionnalités de gestion des apprenants et des examens en une seule application Qt.

## Structure

L'application utilise un QStackedWidget avec 4 pages :
- Page 0 : Login
- Page 1 : Menu principal
- Page 2 : Page Apprenants
- Page 3 : Page Examens

## Création du fichier UI

Pour créer le fichier `application_integree.ui`, vous devez :

1. Ouvrir Qt Designer
2. Créer un nouveau MainWindow
3. Ajouter un QStackedWidget dans le centralWidget
4. Ajouter 4 pages au QStackedWidget :
   - Page 0 (Login) : Copier les widgets de la page login de examens.ui
   - Page 1 (Menu) : Copier les widgets de la page menu de examens.ui
   - Page 2 (Apprenants) : Copier les widgets de apprenants.ui
   - Page 3 (Examens) : Copier les widgets de la page examens de examens.ui

5. Nommer les widgets selon les noms utilisés dans application_integree.cpp

## Widgets nécessaires

### Page Login (stackedWidget index 0)
- lineEdit_email
- lineEdit_password
- pushButton_login

### Page Menu (stackedWidget index 1)
- pushButton_apprenants
- pushButton_examens

### Page Apprenants (stackedWidget index 2)
- lineEdit_id
- lineEdit_nom
- lineEdit_prenom
- dateEdit_naissance
- lineEdit_telephone
- comboBox_sexe
- lineEdit_adresse
- pushButton_ajouter_apprenant
- pushButton_modifier_apprenant
- pushButton_supprimer_apprenant
- pushButton_trier_apprenant
- lineEdit_recherche_apprenant
- pushButton_exporterPDF_apprenant
- pushButton_statistique_apprenant
- tableView_apprenants
- pushButton_retour_apprenants

### Page Examens (stackedWidget index 3)
- lineEdit_id_examen
- comboBox_type
- dateEdit_date
- timeEdit_heure
- lineEdit_lieu
- comboBox_vehicule
- comboBox_resultat
- pushButton_ajouter_examen
- pushButton_modifier_examen
- pushButton_supprimer_examen
- pushButton_exporterPDF_examen
- lineEdit_rechercheType
- comboBox_triDate
- pushButton_stats
- tableView_examens
- pushButton_retour_examens


