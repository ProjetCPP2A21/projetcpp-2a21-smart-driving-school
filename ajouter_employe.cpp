#include "ajouter_employe.h"
#include "ui_ajouter_employe.h"
#include "employe.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

ajouter_employe::ajouter_employe(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ajouter_employe)
{
    ui->setupUi(this);
    
    // Configuration des validateurs
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    QRegularExpressionValidator *emailValidator = new QRegularExpressionValidator(emailRegex, this);
    ui->lineEdit_email->setValidator(emailValidator);
    
    QRegularExpression phoneRegex("^[0-9]{2,3}[ ]?[0-9]{3}[ ]?[0-9]{3}$");
    QRegularExpressionValidator *phoneValidator = new QRegularExpressionValidator(phoneRegex, this);
    ui->lineEdit_telephone->setValidator(phoneValidator);
    
    QRegularExpression idRegex("^[0-9]+$");
    QRegularExpressionValidator *idValidator = new QRegularExpressionValidator(idRegex, this);
    ui->lineEdit_id->setValidator(idValidator);
    
    // Configuration de la date par défaut
    ui->dateEdit_naissance->setDate(QDate::currentDate().addYears(-25));
    
    // Connexion des signaux
    connect(ui->pushButton_ajouter, &QPushButton::clicked, this, &ajouter_employe::on_pushButton_ajouter_clicked);
    connect(ui->pushButton_annuler, &QPushButton::clicked, this, &ajouter_employe::on_pushButton_annuler_clicked);
    connect(ui->pushButton_vider, &QPushButton::clicked, this, &ajouter_employe::on_pushButton_vider_clicked);
    connect(ui->BretourAjouterEmploye, &QPushButton::clicked, this, &ajouter_employe::on_BretourAjouterEmploye_clicked);
}

ajouter_employe::~ajouter_employe()
{
    delete ui;
}

void ajouter_employe::on_pushButton_ajouter_clicked()
{
    if (validerFormulaire()) {
        if (ajouterEmploye()) {
            QMessageBox::information(this, "Succès", "Employé ajouté avec succès !");
            viderChamps();
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout de l'employé.");
        }
    }
}

void ajouter_employe::on_pushButton_annuler_clicked()
{
    this->close();
}

void ajouter_employe::on_pushButton_vider_clicked()
{
    viderChamps();
}

void ajouter_employe::on_BretourAjouterEmploye_clicked()
{
    // Retourner à la page employé
    employe *employePage = qobject_cast<employe*>(parent());
    if (employePage) {
        employePage->show();
    }
    this->close();
}

bool ajouter_employe::validerFormulaire()
{
    // Vérification de l'ID
    if (ui->lineEdit_id->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez saisir l'ID de l'employé.");
        ui->lineEdit_id->setFocus();
        return false;
    }
    
    // Vérification du nom
    if (ui->lineEdit_nom->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez saisir le nom de l'employé.");
        ui->lineEdit_nom->setFocus();
        return false;
    }
    
    // Vérification du prénom
    if (ui->lineEdit_prenom->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez saisir le prénom de l'employé.");
        ui->lineEdit_prenom->setFocus();
        return false;
    }
    
    // Vérification de l'email
    if (ui->lineEdit_email->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez saisir l'email de l'employé.");
        ui->lineEdit_email->setFocus();
        return false;
    }
    
    if (!ui->lineEdit_email->hasAcceptableInput()) {
        QMessageBox::warning(this, "Attention", "Format d'email invalide.");
        ui->lineEdit_email->setFocus();
        return false;
    }
    
    // Vérification du téléphone
    if (ui->lineEdit_telephone->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez saisir le numéro de téléphone.");
        ui->lineEdit_telephone->setFocus();
        return false;
    }
    
    if (!ui->lineEdit_telephone->hasAcceptableInput()) {
        QMessageBox::warning(this, "Attention", "Format de téléphone invalide (ex: 58 588 255).");
        ui->lineEdit_telephone->setFocus();
        return false;
    }
    
    // Vérification du poste
    if (ui->lineEdit_poste->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez saisir le poste de l'employé.");
        ui->lineEdit_poste->setFocus();
        return false;
    }
    
    // Vérification du mot de passe
    if (ui->lineEdit_motdepasse->text().isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez saisir le mot de passe.");
        ui->lineEdit_motdepasse->setFocus();
        return false;
    }
    
    if (ui->lineEdit_motdepasse->text().length() < 6) {
        QMessageBox::warning(this, "Attention", "Le mot de passe doit contenir au moins 6 caractères.");
        ui->lineEdit_motdepasse->setFocus();
        return false;
    }
    
    // Vérification de l'unicité de l'ID
    if (!verifierIdUnique(ui->lineEdit_id->text())) {
        QMessageBox::warning(this, "Attention", "Cet ID d'employé existe déjà.");
        ui->lineEdit_id->setFocus();
        return false;
    }
    
    // Vérification de l'unicité de l'email
    if (!verifierEmailUnique(ui->lineEdit_email->text())) {
        QMessageBox::warning(this, "Attention", "Cet email est déjà utilisé.");
        ui->lineEdit_email->setFocus();
        return false;
    }
    
    return true;
}

void ajouter_employe::viderChamps()
{
    ui->lineEdit_id->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_email->clear();
    ui->lineEdit_telephone->clear();
    ui->lineEdit_poste->clear();
    ui->lineEdit_motdepasse->clear();
    ui->dateEdit_naissance->setDate(QDate::currentDate().addYears(-25));
}

bool ajouter_employe::ajouterEmploye()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Erreur", "Connexion à la base de données échouée.");
        return false;
    }
    
    QSqlQuery query;
    query.prepare("INSERT INTO employes (id, nom, prenom, email, telephone, poste, date_naissance, mot_de_passe) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
    
    query.addBindValue(ui->lineEdit_id->text());
    query.addBindValue(ui->lineEdit_nom->text());
    query.addBindValue(ui->lineEdit_prenom->text());
    query.addBindValue(ui->lineEdit_email->text());
    query.addBindValue(ui->lineEdit_telephone->text());
    query.addBindValue(ui->lineEdit_poste->text());
    query.addBindValue(ui->dateEdit_naissance->date());
    query.addBindValue(ui->lineEdit_motdepasse->text());
    
    if (query.exec()) {
        return true;
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout : " + query.lastError().text());
        return false;
    }
}

bool ajouter_employe::verifierEmailUnique(const QString &email)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        return false;
    }
    
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM employes WHERE email = ?");
    query.addBindValue(email);
    
    if (query.exec() && query.next()) {
        return query.value(0).toInt() == 0;
    }
    
    return false;
}

bool ajouter_employe::verifierIdUnique(const QString &id)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        return false;
    }
    
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM employes WHERE id = ?");
    query.addBindValue(id);
    
    if (query.exec() && query.next()) {
        return query.value(0).toInt() == 0;
    }
    
    return false;
}
